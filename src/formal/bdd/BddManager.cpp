#include "BddManager.h"

#include <cassert>

#include "nstl/for_each/ForEach.h"

#include "utility/log/Log.h"
// #define USE_AND_MAP

// const bool verbose = true;
const bool verbose = false;
BddNodeHandle BddManager::BDD_TRUE = BddNode::getConstOneHandle();
BddNodeHandle BddManager::BDD_FALSE = BddNode::getConstZeroHandle();
/**
 * Reference
 * 1. Write Bdd dot with the same rank
 *    http://www.cs.uc.edu/~weaversa/BDD_Visualizer.html
 * 2. Bdd on javascript
 *    http://blog.vjeux.com/2011/project/javascript-binary-decision-diagram.html
 */

/**
 * // TODO
 * //   makeBddNode(cur, pPos, pNeg)
 * //   but this node will not rewrite pPos pNeg 
 */

template <class T>
inline T max(const T & x, const T & y) {
    return (x > y) ? x : y;
}

    
void BddManager::addBddNode(BddNodeHandle pBddNode) {
    _hashBddNode.insert(pBddNode);
}
    
BddNodeHandle BddManager::makeBddNode(int curDecisionLevel) {
    if (!(curDecisionLevel > 0)) {
        LOG(ERROR) << "curDecisionLevel : " << curDecisionLevel;
    }
    assert(curDecisionLevel > 0);
    BddNodeHandle pBddNode = BddNode::makeBddNode(curDecisionLevel);
    
    return find_or_insert(pBddNode);
}
    
BddNodeHandle BddManager::makeBddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg) {
    if (!(curDecisionLevel > 0)) {
        LOG(ERROR) << "curDecisionLevel : " << curDecisionLevel;
    }
    assert(curDecisionLevel > 0);
    BddNodeHandle pBddNode = BddNode::makeBddNode(curDecisionLevel, pPos, pNeg);

    return find_or_insert(pBddNode);
}
    
    
BddNodeHandle BddManager::findHandleInPairMap(BddNodeAndPairMap  & m, BddNodeHandle pFst, BddNodeHandle pSnd) const {
    BddNodeAndPairMap::const_iterator it;

    if ((it = m.find(std::make_pair(pFst, pSnd))) != m.end())
        return it->second;
    if ((it = m.find(std::make_pair(pSnd, pFst))) != m.end())
        return it->second;

    return BddNodeHandle();
}
    
BddNodeHandle BddManager::makeAnd(BddNodeHandle pFst, BddNodeHandle pSnd) {
    if (pFst == BDD_TRUE)
        return pSnd;
    if (pSnd == BDD_TRUE)
        return pFst;
    if (pFst == BDD_FALSE || pSnd == BDD_FALSE)
        return BDD_FALSE;

    BddNodeHandle pBddNode;
#ifdef USE_AND_MAP
    if ((pBddNode = findHandleInPairMap(_mapAnd, pFst, pSnd)).valid())
        return pBddNode;
#endif

    assert(!pFst->isTerminal());
    assert(!pSnd->isTerminal());

    int topVar = max(pFst->getCurDecisionLevel(), pSnd->getCurDecisionLevel());

    BddNodeHandle fp = pFst->getPosCofactor(pFst, topVar);
    BddNodeHandle fn = pFst->getNegCofactor(pFst, topVar);

    BddNodeHandle gp = pSnd->getPosCofactor(pSnd, topVar);
    BddNodeHandle gn = pSnd->getNegCofactor(pSnd, topVar);

    BddNodeHandle pT = makeAnd(fp
                              ,gp);

    BddNodeHandle pE = makeAnd(fn
                              ,gn);

    if (pT->isStructureEqual(pE)) {
#ifdef USE_AND_MAP
        insertHandlePairInPairMap(_mapAnd, pFst, pSnd, pT);
#endif

        return pT;
    }

    BddNodeHandle pR = makeBddNode(topVar, pT, pE);
#ifdef USE_AND_MAP
    insertHandlePairInPairMap(_mapAnd, pFst, pSnd, pR);
#endif
    return pR;
}
    
void BddManager::insertHandlePairInPairMap(BddNodeAndPairMap & m, BddNodeHandle pPos, BddNodeHandle pNeg, BddNodeHandle pBddNode) {
    m.insert(std::make_pair( std::make_pair(pPos, pNeg)
                           , pBddNode));
}

    
BddManager::BddManager() {
    _hashBddNode.insert(BddNode::getConstOneHandle());
    _hashBddNode.insert(BddNode::getConstZeroHandle());
}


BddNodeHandle BddManager::find_or_insert(BddNodeHandle pBddNode) {
    assert(pBddNode.valid());
    if (pBddNode->isTerminal())
        return pBddNode;

    hash_type::iterator it = _hashBddNode.end();
    if ((it = try_find(pBddNode)) != _hashBddNode.end()) {
        return *it;
    }

    BddNodeHandle pPos = pBddNode->getPosHandle();
    BddNodeHandle pNeg = pBddNode->getNegHandle();
    BddNodeHandle pNewPos = find_or_insert(pPos);
    BddNodeHandle pNewNeg = find_or_insert(pNeg);

    BddNodeHandle pNew = BddNode::makeBddNode(pBddNode->getCurDecisionLevel(), pNewPos, pNewNeg);

    if ((it = try_find(pNew)) != _hashBddNode.end()) {
        return *it;
    }
    else {
        _hashBddNode.insert(pNew);
        if (verbose) {
            DEBUG_EXPR(pNew->toString());
            DEBUG_EXPR(pNew->hashFunction());
            std::cerr << std::endl;
        }
        assert(try_find(pNew) != _hashBddNode.end());
        return pNew;
    }
}
    
BddManager::hash_type::iterator BddManager::try_find(BddNodeHandle pBddNode) {
    hash_type::iterator it = _hashBddNode.end();
   
    if (verbose)
        DEBUG_EXPR(_hashBddNode.size());
    if ((it = _hashBddNode.find(pBddNode)) != _hashBddNode.end()) { 
        if (verbose)
            std::cerr << "Try find (OK): " << pBddNode->toString() << std::endl;
        return it;
    }
    if (verbose)
        std::cerr << "Try find (Fail): " << pBddNode->toString() << std::endl;
        
    return _hashBddNode.end();
}

bool BddNodeAndPairCompareFunctor::operator () (const BddNodeAndPair & x, const BddNodeAndPair & y) const
{
    if (x.first->isLess(y.first)) return true;
    if (y.first->isLess(x.first)) return false;
    return x.second->isLess(y.second);
}

    
BddNodeHandle BddManager::makeNeg(BddNodeHandle pBddNode) {
    if (pBddNode->isStructureEqual(BddNode::getConstOneHandle()))
        return BddNode::getConstZeroHandle();
    if (pBddNode->isStructureEqual(BddNode::getConstZeroHandle()))
        return BddNode::getConstOneHandle();

    BddNodeHandle pNewPos = makeNeg(pBddNode->getPosHandle());
    BddNodeHandle pNewNeg = makeNeg(pBddNode->getNegHandle());

    return makeBddNode( pBddNode->getCurDecisionLevel()
                      , pNewPos
                      , pNewNeg);
}


BddNodeHandle BddManager::ite(BddNodeHandle pIf, BddNodeHandle pThen, BddNodeHandle pElse) {


    // !g = ite(g, 0, 1)
    if (pThen->isStructureEqual(BddNode::getConstZeroHandle()) && pElse ->isStructureEqual(BddNode::getConstOneHandle()))
        return makeNeg(pIf);

    // ite(A, B, C) = ite(!A, C, B)
#if 1

    // ite(f, g, 0)
    if (pElse->isStructureEqual(BddNode::getConstZeroHandle()))
        return makeAnd(pIf, pThen);
//        return apply(OP_AND, pIf, pThen);

    // ite(f, 0, g)
    if (pThen->isStructureEqual(BddNode::getConstZeroHandle())) {
        return ite(makeNeg(pIf), BddNode::getConstZeroHandle(), pElse);
    }

    // ite(f, 1, g)
    if (pThen->isStructureEqual(BddNode::getConstOneHandle())) {
        return makeNeg(ite(makeNeg(pIf), makeNeg(pElse), BddNode::getConstZeroHandle()));
    }
    
    // ite(f, g, 1)
    // ite(!f, 1, g)
    if (pElse->isStructureEqual(BddNode::getConstOneHandle())) {
        return ite(makeNeg(pIf), BddNode::getConstOneHandle(), pThen);
    }

    // ite(f, g, h) =
    //     fg + f'h
    //     ite(fg, 1, f'h)
#endif

    return ite( makeAnd(pIf, pThen)
              , BddNode::getConstOneHandle()
              , makeAnd(makeNeg(pIf), pElse));
}

BddNodeHandle BddManager::makeOr(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return ite(pFst, BddNode::getConstOneHandle(), pSnd);
}
    
BddNodeHandle BddManager::makeImply(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return makeOr(makeNeg(pFst), pSnd);
}

    
BddNodeHandle BddManager::makeEq(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return makeAnd(makeImply(pFst, pSnd), makeImply(pSnd, pFst));
}
    
BddNodeHandle BddManager::makeXor(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return makeOr(makeAnd(pFst, makeNeg(pSnd)), makeAnd(makeNeg(pFst), pSnd));
}

BddNodeHandle BddManager::makeXnor(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return makeNeg(makeXor(pFst, pSnd));
}
    
BddNodeHandle BddManager::getGeneralizedCofactor(BddNodeHandle pF, BddNodeHandle pC) {
    if (pF == BDD_FALSE || pC == BDD_FALSE)
        return BDD_FALSE;
    if (pF == BDD_TRUE || pC == BDD_TRUE)
        return pF;

    int topDecisionLevel = max(pF->getCurDecisionLevel(), pC->getCurDecisionLevel());

    if (pC->reduce0(topDecisionLevel) == BDD_FALSE)
        return getGeneralizedCofactor( pF->reduce1(topDecisionLevel)
                                     , pC->reduce1(topDecisionLevel));
    if (pC->reduce1(topDecisionLevel) == BDD_FALSE)
        return getGeneralizedCofactor( pF->reduce0(topDecisionLevel)
                                     , pC->reduce0(topDecisionLevel));

    BddNodeHandle pH1 = getGeneralizedCofactor( pF->reduce1(topDecisionLevel)
                                              , pC->reduce1(topDecisionLevel));

    BddNodeHandle pH0 = getGeneralizedCofactor( pF->reduce0(topDecisionLevel)
                                              , pC->reduce0(topDecisionLevel));

    if (pH1 == pH0)
        return pH1;
    return makeBddNode(topDecisionLevel, pH1, pH0);
}
    
BddNodeHandle BddManager::exQuant(BddNodeHandle pNode, int decisionLevel) {
    if (pNode->getCurDecisionLevel() == decisionLevel)
        return makeOr(pNode->getPosHandle(), pNode->getNegHandle());

    if (decisionLevel > pNode->getCurDecisionLevel())
        return pNode;

    BddNodeHandle pF1 = exQuant(pNode->getPosHandle(), decisionLevel);
    BddNodeHandle pF2 = exQuant(pNode->getNegHandle(), decisionLevel);

    if (pF1 == pF2)
        return pF1;

    return makeBddNode(pNode->getCurDecisionLevel(), pF1, pF2);

}

    
bool BddManager::isNeg(BddNodeHandle pFst, BddNodeHandle pSnd) {
    return makeNeg(pFst) == pSnd;
}
   
#if 0
BddNodeHandle BddManager::restrict(BddNodeHandle pFst, BddNodeHandle pSnd) {
    BddNodeHandle one = BddNode::getConstOneHandle();
    BddNodeHandle zero = BddNode::getConstZeroHandle();
    if (pSnd->isStructureEqual(one)
       || pFst->isTerminal())
        return pFst;

    // TODO(chiahsun): may be complexity issue
    if (pFst->isStructureEqual(pSnd)) {
        return one;
    }

    if (pFst->isTerminal() && pSnd->isTerminal()) {
        if (pFst->getBool() != pSnd->getBool())
            return zero;
    }

    if (pSnd->isTerminal()) {
        if (!pSnd->getBool())
            return zero;
    }
    
    int topVar = max(pFst->getCurDecisionLevel(), pSnd->getCurDecisionLevel());

    BddNodeHandle fp = pFst->getPosCofactor(pFst, topVar);
    BddNodeHandle fn = pFst->getNegCofactor(pFst, topVar);

    BddNodeHandle gp = pSnd->getPosCofactor(pSnd, topVar);
    BddNodeHandle gn = pSnd->getNegCofactor(pSnd, topVar);


    if (gp->isStructureEqual(zero))
        return restrict(fn, gn);

    if (gn->isStructureEqual(zero))
        return restrict(fp, gp);


    return ite(BddNodeHandle(BddNode(topVar)), restrict(fp, gp), restrict(fn, gn));
#if 0
    BddNodeHandle pT = makeAnd(pFst->getPosCofactor(pFst, topVar)
                              ,pSnd->getPosCofactor(pSnd, topVar));

    BddNodeHandle pE = makeAnd(pFst->getNegCofactor(pFst, topVar)
                              , pSnd->getNegCofactor(pSnd, topVar));

    if (pT->equal(*this, pE)) {
        return pT;
    }
    else {
        BddNodeHandle pR = makeBddNode(topVar, pT, pE);
        return pR;
    }
#endif



    // TODO
}
#endif
    
#if 0
BddNodeHandle BddManager::apply(OpType op, BddNodeHandle pFst, BddNodeHandle pSnd) {
    BddNodeHandle one = BddNode::getConstOneHandle();
    BddNodeHandle zero = BddNode::getConstZeroHandle();

    if (pFst->isTerminal() && pSnd->isTerminal()) {
        switch(op) {
            case OP_OR:
                if (pFst->getBool() || pSnd->getBool())
                    return one;
                else
                    return zero;
            case OP_AND:
                if (pFst->getBool() && pSnd->getBool())
                    return one;
                else
                    return zero;
            default:
                assert(0);
        }
    }

    if (pFst->isTerminal()) {
        return pSnd;
    }

    // why requiring communitive
    if (pSnd->isTerminal()) {
        return apply(op, pSnd, pFst);
    }
    
    int topVar = max(pFst->getCurDecisionLevel(), pSnd->getCurDecisionLevel());

    BddNodeHandle fp = pFst->getPosCofactor(pFst, topVar);
    BddNodeHandle fn = pFst->getNegCofactor(pFst, topVar);

    BddNodeHandle gp = pSnd->getPosCofactor(pSnd, topVar);
    BddNodeHandle gn = pSnd->getNegCofactor(pSnd, topVar);
   
    return makeBddNode(topVar, apply(op, fp, gp), apply(op, fn, gn));
}

    
bool BddManager::checkHash() const {
//    CONST_FOR_EACH(px, _hashBddNode) {
//        CONST_FOR_EACH(py, _hashBddNode) {
//        }
//    }
    return false;
}
#endif
