#ifndef WDD_MANAGER_H
#define WDD_MANAGER_H

#include <cassert>
#include <map>

#include "formal/bdd/BddManager.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"


template <class _TermHandle>
class WddNode;

template <class _TermHandle>
class WddManager;

template <class _TermHandle>
class WddNode {
    typedef _TermHandle term_handle_type;
    typedef SharedPtrE<WddNode<term_handle_type> > WddNodeHandle;

    BddNodeHandle _pBddNode;
    term_handle_type _pTerm;
public:
    WddNode(BddNodeHandle pBddNode) 
      : _pBddNode(pBddNode) 
      { }
    
    WddNode(BddNodeHandle pBddNode, term_handle_type pTerm) 
      : _pBddNode(pBddNode) 
      , _pTerm(pTerm) { 
          assert(pBddNode->getPosHandle()->isTerminal());
          assert(pBddNode->getNegHandle()->isTerminal());
      }

    WddNodeHandle getPosHandle(const WddManager<_TermHandle> & wddManager) const {
        if (isTerm()) {
            std::cerr << "Already a term" << std::endl;
            assert(0);
        }

        BddNodeHandle pBddNode = _pBddNode->getPosHandle();
        return makeWddNodeHandle(wddManager, pBddNode);
    }
    
    WddNodeHandle getNegHandle(const WddManager<_TermHandle> & wddManager) const {
        if (isTerm()) {
            std::cerr << "Already a term" << std::endl;
            assert(0);
        }

        BddNodeHandle pBddNode = _pBddNode->getNegHandle();
        return makeWddNodeHandle(wddManager, pBddNode);

    }

    static WddNodeHandle makeWddNodeHandle(const WddManager<_TermHandle> & wddManager, BddNodeHandle pBddNode) {
        if (pBddNode->isTerminal())
            return WddNodeHandle(WddNode(pBddNode));
//            return WddNodeHandle();

        if ( pBddNode->getPosHandle()->isTerminal()
          && pBddNode->getNegHandle()->isTerminal()) {
            int curLevelId = pBddNode->getCurDecisionLevel();
            term_handle_type pTerm = wddManager.getTermHandleFromId(curLevelId);
            WddNodeHandle pWddNode = WddNodeHandle(WddNode(pBddNode, pTerm));
            return pWddNode;
        } else {
            return WddNodeHandle(WddNode(pBddNode));
        }
    }


    BddNodeHandle getBddNodeHandle() const { return _pBddNode; }
    term_handle_type getTermHandle() const { return _pTerm; }
    bool isTerm() const { return _pTerm.valid(); }

    std::string toString(const WddManager<_TermHandle>& wddManager) const {
        if (getTermHandle().valid()) { 
            if (getBddNodeHandle()->getPosHandle()->getBool())
                return _pTerm->toString();
            else
                return "not " + _pTerm->toString();
        }

        int curLevelId = getBddNodeHandle()->getCurDecisionLevel();
        if (curLevelId == 0) {
            if (getBddNodeHandle()->getBool())
                return "TRUE";
            else
                return "FALSE";
        }
        term_handle_type pTerm = wddManager.getTermHandleFromId(curLevelId);
        std::string curLevelName = pTerm->toString(); 
//        assert(0);
//        return "";
        WddNodeHandle pPos = getPosHandle(wddManager);
        WddNodeHandle pNeg = getNegHandle(wddManager);
        std::string s = "ite(" + curLevelName;
        if (pPos.valid())
            s += ", " + pPos->toString(wddManager);
        else
            s += ", FALSE";
        if (pNeg.valid())
            s += ", " + pNeg->toString(wddManager);
        else
            s += ", FALSE";
        return s += ")";
           
    }
   
    // TODO case by case simplification of ITE 
    std::string toPureString(const WddManager<_TermHandle>& wddManager) const {
        if (getTermHandle().valid()) { 
            if (getBddNodeHandle()->getPosHandle()->getBool())
                return _pTerm->toString();
            else
                return "!(" + _pTerm->toString() + ")";
        }

        int curLevelId = getBddNodeHandle()->getCurDecisionLevel();
        if (curLevelId == 0) {
            if (getBddNodeHandle()->getBool())
                return "true";
            else
                return "false";
        }
        term_handle_type pTerm = wddManager.getTermHandleFromId(curLevelId);
        std::string curLevelName = pTerm->toString(); 
//        assert(0);
//        return "";
        WddNodeHandle pPos = getPosHandle(wddManager);
        WddNodeHandle pNeg = getNegHandle(wddManager);
        std::string posString = pPos->toPureString(wddManager);
        std::string negString = pNeg->toPureString(wddManager);

        // ite(a, 1, b) = a + b
        // ite(a, 0, b) = !ab
        if (posString == "true") {
            return "(" + curLevelName + "||" + negString + ")";
        } else if (posString == "false") {
            return "(!" + curLevelName + "&&" + negString + ")";
        }

        // ite(a, b, 0) = ab
        // ite(a, b, 1) = !a + b
        if (negString == "true") {
            return "(!" + curLevelName + "||" + posString + ")";
        } else if (negString == "false") {
            return "(" + curLevelName + "&&" + posString + ")";
        }
        
        std::string s = "(" + curLevelName + " ? ";
        s += posString; 
        s += " : ";
        s += negString; 
        return s += ")";
    }


    void writeDotFile(const std::string & filename) const {
        return _pBddNode->writeDotFile(filename);
    }

    bool operator < (const WddNode & rhs) const {
        return _pBddNode->operator < (*(rhs._pBddNode));
    }

    bool operator < (const WddNodeHandle & rhs) const {
        return _pBddNode->operator < (*(rhs->_pBddNode));
    }


};

//typedef BddNodeHandle WddNodeHandle;


template <class _TermHandle>
class WddManager {
public:
    typedef _TermHandle term_handle_type;
    typedef SharedPtrE<WddNode<term_handle_type> > WddNodeHandle;


    typedef int term_id_type;

private:
    BddManager _bddManager;

    typedef std::map<term_handle_type, term_id_type> TermIdMap;
    TermIdMap _mapTermId;
    typedef std::map<term_id_type, term_handle_type> IdTermMap;

    typedef std::map<WddNodeHandle, term_handle_type> NodeTermMap;
    NodeTermMap _mapNodeTerm;

    IdTermMap _mapIdTerm;

public:
    WddManager() {
    }

    term_handle_type getTermHandleFromId(term_id_type id) const {
        typename IdTermMap::const_iterator it;
        if ((it = _mapIdTerm.find(id)) == _mapIdTerm.end()) { 
           std::cerr << "No such term for this id : " << id << std::endl;
           assert(0);
        }
        return it->second;
    }

    std::string stringOfNode(const WddNodeHandle & pNode) const {
        return pNode->toString(*this);
    }


    WddNodeHandle addTerm(const term_handle_type & pTerm) {
        typename TermIdMap::const_iterator it;
        
        if ((it = _mapTermId.find(pTerm)) == _mapTermId.end()) {
            int id = _mapTermId.size() + 1;
            assert(id > 0);
            _mapTermId.insert(std::make_pair(pTerm, id));
            _mapIdTerm.insert(std::make_pair(id, pTerm));
            BddNodeHandle pBddNode = _bddManager.makeBddNode(id);
            WddNode<term_handle_type> wddNode(pBddNode, pTerm);
            WddNodeHandle pWddNode = WddNodeHandle(wddNode);
            _mapNodeTerm.insert(std::make_pair(pWddNode, pTerm));
            return pWddNode; 
        } else {
            return findTerm(pTerm);
        }

        assert(0);
    }



    WddNodeHandle findTerm(const term_handle_type & pTerm) {
        typename TermIdMap::const_iterator it;
        it = _mapTermId.find(pTerm);
        assert(it != _mapTermId.end());

        int id = it->second;
        if (!(id > 0)) {
            LOG(ERROR) << pTerm->toString();
            LOG(ERROR) << id;
        }

        assert(id > 0);
        WddNode<term_handle_type> wddNode(_bddManager.makeBddNode(id), pTerm);
        return WddNodeHandle(wddNode);
    }

#if 0
    WddNodeHandle makeWddNodeFromBddNode(BddNodeHandle pBddNode) {
//        assert(!pBddNode->isTerminal()); // may be FALSE

        if (pBddNode->getPosHandle()->isTerminal() && pBddNode->getNegHandle()->isTerminal()) {
            int curDecisionLevel = pBddNode->getCurDecisionLevel();
            term_handle_type pTerm = getTermHandleFromId(curDecisionLevel);
            return WddNodeHandle(WddNode<term_handle_type>(pBddNode, pTerm));
        } else {
            return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
        }
        assert(0);
    }
#endif

//    WddNodeHandle makeWddNode(const WddManager & oriManager, WddNodeHandle pOriNode) {
    WddNodeHandle makeWddNode(WddManager & oriManager, WddNodeHandle pOriNode) {
        static const bool verbose_make_bdd_node_change_manager = false;
        if (verbose_make_bdd_node_change_manager) 
            LOG(INFO) << "ori : " << pOriNode->toPureString(oriManager);

        if (pOriNode->isTerm()) {
            WddNodeHandle pTerminalWddNode = makeWddNode(pOriNode->getTermHandle());
            if (verbose_make_bdd_node_change_manager) {
                LOG(INFO) << "terminal : " << pTerminalWddNode->toPureString(*this);
                LOG(INFO) << "terminal bdd : " << pTerminalWddNode->getBddNodeHandle()->toString();
            }
            return pTerminalWddNode;
        }
        
        BddNodeHandle pOriBddNode = pOriNode->getBddNodeHandle();
        if (pOriBddNode->isTerminal())
            return WddNode<term_handle_type>::makeWddNodeHandle(*this, pOriBddNode); 

        if (verbose_make_bdd_node_change_manager) 
            LOG(INFO) << "ori bdd : " << pOriBddNode->toString();

        WddNodeHandle pPosWddNode = makeWddNode(oriManager, pOriNode->getPosHandle(oriManager));
        WddNodeHandle pNegWddNode = makeWddNode(oriManager, pOriNode->getNegHandle(oriManager));
                                               
        if (verbose_make_bdd_node_change_manager) {
            LOG(INFO) << "ori pos : " << pOriNode->getPosHandle(oriManager)->toPureString(oriManager);
            LOG(INFO) << "ori pos bdd : " << pOriNode->getPosHandle(oriManager)->getBddNodeHandle()->toString();
            LOG(INFO) << "ori neg : " << pOriNode->getNegHandle(oriManager)->toPureString(oriManager);
            LOG(INFO) << "ori neg bdd : " << pOriNode->getNegHandle(oriManager)->getBddNodeHandle()->toString();

            LOG(INFO) << "cur pos : " << pPosWddNode->toPureString(*this);
            LOG(INFO) << "cur pos bdd : " << pPosWddNode->getBddNodeHandle()->toString();
            LOG(INFO) << "cur neg : " << pNegWddNode->toPureString(*this);
            LOG(INFO) << "cur neg bdd : " << pNegWddNode->getBddNodeHandle()->toString();
        }
        
        int oriCurLevelId = pOriBddNode->getCurDecisionLevel();
        term_handle_type pOriCurTerm = oriManager.getTermHandleFromId(oriCurLevelId);
        WddNodeHandle pCurWddNode = makeWddNode(pOriCurTerm);
        if (verbose_make_bdd_node_change_manager) {
            LOG(INFO) << "cur level : " << pCurWddNode->toPureString(*this);
            LOG(INFO) << "cur level bdd : " << pCurWddNode->getBddNodeHandle()->toString();
        }

        return ite(pCurWddNode, pPosWddNode, pNegWddNode);
    }

    WddNodeHandle makeWddNode(const term_handle_type & pTerm) {
        return addTerm(pTerm);
    }

    WddNodeHandle makeAnd(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeAnd(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
//        return makeWddNodeFromBddNode(pBddNode);
//        return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }

    WddNodeHandle makeNeg(WddNodeHandle pWddNode) {
        BddNodeHandle pBddNode = _bddManager.makeNeg(pWddNode->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
//        return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }

    WddNodeHandle makeOr(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeOr(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
//        return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }

    WddNodeHandle makeImply(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeImply(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
//        return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }
    WddNodeHandle makeEq(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeEq(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }

    WddNodeHandle ite(WddNodeHandle pFst, WddNodeHandle pSnd, WddNodeHandle pTrd) {
        BddNodeHandle pBddNode = _bddManager.ite(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle(), pTrd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
//        return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }

    WddNodeHandle makeNeq(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeXor(pFst->getBddNodeHandle(), pSnd->getBddNodeHandle());
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }

    WddNodeHandle makeOneNeg(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNode = _bddManager.makeOr(_bddManager.makeNeg(pFst->getBddNodeHandle()), _bddManager.makeNeg(pSnd->getBddNodeHandle()));
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }
#if 0
    WddNodeHandle makeNeq(WddNodeHandle pFst, WddNodeHandle pSnd) {
        BddNodeHandle pBddNodeFst = pFst->getBddNodeHandle();
        BddNodeHandle pBddNodeSnd = pSnd->getBddNodeHandle();
#if 0
        BddNodeHandle p1 = _bddManager.makeAnd(_bddManager.makeNeg(pBddNodeFst), pBddNodeSnd);
        BddNodeHandle p2 = _bddManager.makeAnd(pBddNodeFst, _bddManager.makeNeg(pBddNodeSnd));
        BddNodeHandle pBddNode = _bddManager.makeOr(p1, p2);
# endif
#if 0 // good
        BddNodeHandle p1 = _bddManager.makeOr(_bddManager.makeNeg(pBddNodeFst), _bddManager.makeNeg(pBddNodeSnd));
        BddNodeHandle p2 = _bddManager.makeOr(_bddManager.makeNeg(pBddNodeSnd), _bddManager.makeNeg(pBddNodeFst));

        BddNodeHandle pBddNode = _bddManager.makeAnd(p1, p2);
#endif
#if 0
        BddNodeHandle pBddNode = _bddManager.makeXor(pBddNodeFst, pBddNodeSnd);
#endif
        BddNodeHandle pBddNode = _bddManager.makeOr(_bddManager.makeNeg(pBddNodeFst), _bddManager.makeNeg(pBddNodeSnd));
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
       // return WddNodeHandle(WddNode<term_handle_type>(pBddNode));
    }
#endif

    WddNodeHandle makeBasicBlockIfThen(WddNodeHandle pIf, WddNodeHandle pThen) {
        BddNodeHandle pBddNodeIf = pIf->getBddNodeHandle();
        BddNodeHandle pBddNodeThen = pThen->getBddNodeHandle();
        BddNodeHandle pBddNode = _bddManager.makeAnd(pBddNodeIf, pBddNodeThen);
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }

    WddNodeHandle makeBasicBlockIfElse(WddNodeHandle pIf, WddNodeHandle pElse) {
        BddNodeHandle pBddNodeIf = pIf->getBddNodeHandle();
        BddNodeHandle pBddNodeElse = pElse->getBddNodeHandle();
        BddNodeHandle pBddNode = _bddManager.makeAnd(_bddManager.makeNeg(pBddNodeIf), pBddNodeElse);
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }
    
    WddNodeHandle makeBasicBlockIfThenElse(WddNodeHandle pIf, WddNodeHandle pThen, WddNodeHandle pElse) {
        BddNodeHandle pBddNodeIf = pIf->getBddNodeHandle();
        BddNodeHandle pBddNodeThen = pThen->getBddNodeHandle();
        BddNodeHandle pBddNodeElse = pElse->getBddNodeHandle();
        BddNodeHandle pBddNode = _bddManager.ite(pBddNodeIf, pBddNodeThen, pBddNodeElse);
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }

    WddNodeHandle makeBasicBlockCofactor(WddNodeHandle pExpr, WddNodeHandle pCofactor) {
        BddNodeHandle pBddNodeExpr = pExpr->getBddNodeHandle();
        BddNodeHandle pBddNodeCofactor = pCofactor->getBddNodeHandle();
        BddNodeHandle pBddNode = _bddManager.makeAnd(pBddNodeExpr, pBddNodeCofactor);
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pBddNode);
    }

#if 1 
    WddNodeHandle getPosCofactor(WddNodeHandle pWddNode, WddNodeHandle pCofactor) {
        BddNodeHandle pBddNode = pWddNode->getBddNodeHandle();

        if (!pCofactor->isTerm()) {
            std::cerr << "Try to cofactor " << pWddNode->toString(*this) << " with a non-term: " << pCofactor->toString(*this) << std::endl;
            assert(0);
        }

        int cofactorDecisionLevel = pCofactor->getBddNodeHandle()->getCurDecisionLevel();
        BddNodeHandle pCofactored = BddNode::getPosCofactor(pBddNode, cofactorDecisionLevel);
        
        return WddNode<term_handle_type>::makeWddNodeHandle(*this, pCofactored);
//        return makeWddNodeFromBddNode(pCofactored);
    }
#endif

    std::string stringOfTermOrder() const {
        std::stringstream ss;

        CONST_FOR_EACH(x, _mapIdTerm) {
            ss << x.first << " : " << x.second->toString() << std::endl;
        }

        return ss.str();
    }

    void printTermOrder() const {
        std::cout << stringOfTermOrder();
    }

};
    

#endif // WDD_MANAGER_H
