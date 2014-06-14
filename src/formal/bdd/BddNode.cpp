#include "BddNode.h"

#include <fstream>

#include "utility/convert/ConvertUtil.h"
#include "nstl/for_each/ForEach.h"



static std::string indent(unsigned int indentLevel = 0) {
    std::string s = "";
    for (unsigned int i = 0; i < indentLevel; ++i)
        s += " ";
    return s;
}

int getNextUniqueId() {
    static int id = 2;
    return id++;
}

BddNode::BddNode(int curDecisionLevel)
  : _curDecisionLevel(curDecisionLevel)
  , _pPos(getConstOneHandle())
  , _pNeg(getConstZeroHandle()) 
  , _hashValue(computeHashFunction()) 
  , _uniqueId(getNextUniqueId()) { 
      assert(!isTerminal());
      assert(getCurDecisionLevel() > 0);
}
    
BddNode::BddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg)
  : _curDecisionLevel((pPos == pNeg) ? pPos->getCurDecisionLevel() : curDecisionLevel)
  , _pPos((pPos == pNeg) ? pPos->getPosHandle() : pPos)
  , _pNeg((pPos == pNeg) ? pPos->getNegHandle() : pNeg) 
  , _hashValue((pPos == pNeg) ? pPos->computeHashFunction() : computeHashFunction())  
  , _uniqueId((pPos == pNeg) ? pPos->getUniqueId() : getNextUniqueId()) {
    if (!(pPos == pNeg)) {
        assert(getCurDecisionLevel() > pPos->getCurDecisionLevel());
        assert(getCurDecisionLevel() > pNeg->getCurDecisionLevel());
    }
}

    
BddNode::BddNode(bool val)
  : _curDecisionLevel(0)
  , _pBool(BoolHandle(Bool(val)))
  , _hashValue(computeHashFunction())
  , _uniqueId(getBool() ? 1 : 0)
  { }


BddNodeHandle BddNode::getConstOneHandle() {
    static BddNodeHandle pTrue = BddNodeHandle(BddNode(true));
    return pTrue;
}

BddNodeHandle BddNode::getConstZeroHandle() {
    static BddNodeHandle pFalse = BddNodeHandle(BddNode(false));
    return pFalse;
}
    
int BddNode::getCurDecisionLevel() const
  { return _curDecisionLevel; }
    

BddNodeHandle BddNode::getPosHandle() const { 
    assert(!isTerminal());
    return _pPos; 
}

BddNodeHandle BddNode::getNegHandle() const { 
    assert(!isTerminal());
    return _pNeg; 
}

bool BddNode::getBool() const {
    assert(isTerminal());
    return _pBool->_bool;
}

bool BddNode::isTerminal() const {
    return _pBool.valid();
}
    
std::string BddNode::toString() const {
    return toString(0, 0);
}
    
std::string BddNode::toString(int curId, int indentLevel) const {
    if (isTerminal()) {
        if (indentLevel != 0)
            return "";
        else
            return indent(indentLevel) + ConvertUtil::convert<int, std::string>(getCurDecisionLevel()) + " Bdd(" + getSymboltoString(0) + ")\n";
    } else {
        int posId = 2 * curId + 1;
        int negId = 2 * curId + 2;

        return
            indent(indentLevel) + ConvertUtil::convert<int, std::string>(getCurDecisionLevel()) + " Bdd(" + getPosHandle()->getSymboltoString(posId) + ", "
                   + getSymboltoString(curId) + ", "
                   + getNegHandle()->getSymboltoString(negId) + ")" + "\n"
                   + getPosHandle()->toString(posId, indentLevel+1)
                   + getNegHandle()->toString(negId, indentLevel+1);
    }
}
   
#if 0
std::string BddNode::toString() const {
    
    if (isTerminal()) {
        return "Bdd(" + ConvertUtil::convert<bool, std::string>(_pBool->_bool) + ")"; 
    } else {
        return "Bdd(" + ConvertUtil::convert<int, std::string>(getPosHandle()->getBddId()) + ", " + ConvertUtil::convert<int, std::string>(getBddId()) + ", " + ConvertUtil::convert<int, std::string>(getNegHandle()->getBddId()) + ")";
    }

    assert(0);
}
#endif
    
std::string BddNode::toDotFormat() const {
    std::string arrow(" -> ");

    std::stringstream ss;
    ss << "digraph Bdd {\n"
//       << indent << "rankdir = TD;\n"
//       << indent << "node [ shape = circle, color = lightblue, fontname = \"Helvetica\"];\n";
       << indent() << "node [label=\"\\N\", color=lightblue, fontname=\"Helvetica\", fontsize=16];\n"
       << indent() << "graph [bb=\"0,0,285.28,258\"]\n";


    std::map<BddNode, std::string> mapBddName;
    std::map<BddNode, std::string> mapArrowString;
    
    collectLink(0, mapBddName, mapArrowString);

    std::string strConnect;
    CONST_FOR_EACH(x, mapArrowString) {
        strConnect += x.second;
    }

    int curLevel = -1;
    ss << indent() << "{\n"
       << indent(2) << "graph [rank=same, bb=\"\"];\n";

    if (!isTerminal() || getBool())
       ss << indent(2) << "true [shape=box];\n";
    if (!isTerminal() || !getBool())
       ss << indent(2) << "false [shape=box];\n";
    ss << indent() << "}\n";
    CONST_FOR_EACH(x, mapBddName) {
        if (x.first.getCurDecisionLevel() != 0) {
        if (curLevel != x.first.getCurDecisionLevel()) {
            if (curLevel != -1) {
                ss << indent() << "}\n";
            }
            curLevel = x.first.getCurDecisionLevel();
            ss << indent() << "{\n"
               << indent(2) << "graph[rank=same, bb=\"\"];\n";
        }
        ss << indent(2) << x.second << " [label=" << curLevel << "];\n";
        }
    }
    if (mapBddName.size() != 0)
        ss << indent() << "}\n";
    ss << strConnect;
   
    ss << "\n}\n";
    return ss.str();
}

std::set<BddNodeHandle> BddNode::collectFromNode(BddNodeHandle pBddNode) const {
    std::set<BddNodeHandle> s, s2;
    s.insert(pBddNode);
    s.insert(BddNode::getConstZeroHandle());
    s.insert(BddNode::getConstOneHandle());
    if (!pBddNode->isTerminal()) {
        s2 = collectFromNodeHelper(pBddNode);
    }

    s2.insert(s.begin(), s.end());
    return s2;
}

std::set<BddNodeHandle> BddNode::collectFromNodeHelper(BddNodeHandle pBddNode) const {
    if (pBddNode->isTerminal())
        return std::set<BddNodeHandle>();

    std::set<BddNodeHandle> posSet;
    std::set<BddNodeHandle> negSet;
    
    if (!pBddNode->getPosHandle()->isTerminal())
        posSet = collectFromNode(pBddNode->getPosHandle());
    if (!pBddNode->getNegHandle()->isTerminal())
        negSet = collectFromNode(pBddNode->getNegHandle());

    posSet.insert(pBddNode);
    posSet.insert(negSet.begin(), negSet.end());

    return posSet;
}
    
std::string BddNode::getSymboltoString(int pos) const {
    std::stringstream ss;
    if (isTerminal()) {
        ss << (getBool() ? "true" : "false");
    } else {
        ss << "n" << ConvertUtil::convert<int, std::string>(pos);
    }
    return ss.str();
}
    
std::string BddNode::getBddSymbolOnDotFormat(int curId) const {
    return getSymboltoString(curId);
}
    
std::string BddNode::getBddName(int curId, std::map<BddNode, std::string> & mapBddName) const {
    std::string curName;

    if (mapBddName.find(*this) == mapBddName.end()) {
        curName = getBddSymbolOnDotFormat(curId);
        mapBddName.insert(std::make_pair(*this, curName));
    } else {
        curName = mapBddName[*this];
    }
    return curName;
}
    
void BddNode::collectLink(int curId, std::map<BddNode, std::string> & mapBddName, std::map<BddNode, std::string> & mapArrowString) const {
    if (isTerminal()) 
        return;
    if (mapArrowString.find(*this) != mapArrowString.end())
        return;

    std::stringstream ss;
    std::string arrow(" -> ");

    int posId = 2*curId + 1;
    int negId = 2*curId + 2;

    std::string curName = getBddName(curId, mapBddName);
        
    ss << curName << arrow; 
    ss << getPosHandle()->getBddName(posId, mapBddName) << ";\n";

    ss << curName << arrow;
    ss << getNegHandle()->getBddName(negId, mapBddName) << " [style = dotted];\n";

    mapArrowString.insert(std::make_pair(*this, ss.str()));
    
    getPosHandle()->collectLink(posId, mapBddName, mapArrowString);
    getNegHandle()->collectLink(negId, mapBddName, mapArrowString);

}
    
void BddNode::writeDotFile(const std::string & filename) const {
    std::ofstream fout(filename.c_str());

    if (!fout.good()) {
        std::cerr << "*Error: open file : " << filename << std::endl;
        return;
    }

    fout << toDotFormat();
    fout.close();
}
    
BddNodeHandle BddNode::makeBddNode(int curDecisionLevel) {
    return BddNodeHandle(BddNode(curDecisionLevel));
}

    
BddNodeHandle BddNode::makeBddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg) {
    return BddNodeHandle(BddNode(curDecisionLevel, pPos, pNeg));
}
    

int BddNode::hashFunction() const {
//    return computeHashFunction();
    return _hashValue;
}

int BddNode::computeHashFunction() const {
    if (isTerminal())
        return (getBool() ? 528 : 530);
    else
        return computeHashFunction(getPosHandle(), getNegHandle());
}


int BddNode::computeHashFunction(BddNodeHandle pPos, BddNodeHandle pNeg) const {
    int sum = 17;
    sum *= 31;
    sum += getCurDecisionLevel();
    sum *= 31;
    assert(pPos.valid());
    sum += pPos->hashFunction();
    sum *= 31;
    assert(pNeg.valid());
    sum += pNeg->hashFunction();
    return sum;
}

/*
bool BddNode::operator == (const BddNode& rhs) const {
    if (isTerminal()) {
        return rhs.isTerminal() && (getBool() == rhs.getBool());
    }

    return isStructureEqual(getPosHandle(), getNegHandle(), rhs);
}
*/
bool BddNode::isStructureEqual(BddNodeHandle pBddNode) const {
    return isStructureEqual(*pBddNode);
}

bool BddNode::isStructureEqual(const BddNode & rhs) const {
    if (isTerminal()) 
        return rhs.isTerminal() 
            && (getBool() == rhs.getBool());

    if (rhs.isTerminal())
        return false;

    if (getCurDecisionLevel() != rhs.getCurDecisionLevel())
        return false;
    
    return getPosHandle()->isStructureEqual(rhs.getPosHandle())
        && getNegHandle()->isStructureEqual(rhs.getNegHandle());

}
    
/*
bool BddNode::operator == (const BddNodeHandle& rhs) const {
    return this->operator == (*rhs);
}
*/

    
// bool BddNode::operator < (const BddNode & rhs) const {
bool BddNode::isLess(const BddNode & rhs) const {
    if (getCurDecisionLevel() < rhs.getCurDecisionLevel()) 
        return true;
    if (getCurDecisionLevel() > rhs.getCurDecisionLevel())
        return false;

    if (isTerminal() && rhs.isTerminal()) {
        if (getBool() == rhs.getBool())
            return false;
        if (getBool() == false)
            return true;
        return false;
    }

    if (getPosHandle()->isLess(rhs.getPosHandle()))
        return true;
    if (rhs.getPosHandle()->isLess(getPosHandle()))
        return false;
    
     return (getNegHandle()->isLess(rhs.getNegHandle()));
}
    
// bool BddNode::operator < (const BddNodeHandle & rhs) const {
bool BddNode::isLess(const BddNodeHandle & pBddNode) const {
    return isLess(*pBddNode);
}
    
BddNodeHandle BddNode::getPosCofactor(BddNodeHandle pBddNode, int curDecisionLevel) {
    if(pBddNode->isTerminal()) {
       if (pBddNode->getBool()) 
           return getConstOneHandle();
       else
           return getConstZeroHandle();
    }
    if (pBddNode->getCurDecisionLevel() < curDecisionLevel)
        return pBddNode;
    if (pBddNode->getCurDecisionLevel() == curDecisionLevel)
        return pBddNode->getPosHandle();

    std::cerr << "*Error: " << "cur decision level:" << pBddNode->getCurDecisionLevel() << " > reguster level :" << curDecisionLevel << std::endl;
    assert(0);
}
    
BddNodeHandle BddNode::getNegCofactor(BddNodeHandle pBddNode, int curDecisionLevel) {
    assert(!pBddNode->isTerminal());
    if (pBddNode->getCurDecisionLevel() < curDecisionLevel)
        return pBddNode;
    if (pBddNode->getCurDecisionLevel() == curDecisionLevel)
        return pBddNode->getNegHandle();

    std::cerr << "*Error: " << "cur decision level:" << pBddNode->getCurDecisionLevel() << " > reguster level :" << curDecisionLevel << std::endl;
    assert(0);
}
    
bool BddNode::equal(BddNodeHandle pBddNode) const {
    return equal(*pBddNode);
}

bool BddNode::equal(const BddNode & rhs) const {
    if (_uniqueId == rhs._uniqueId)
        return true;
    return isStructureEqual(rhs);
}


bool BddNode::operator < (const BddNode & rhs) const {
    return isLess(rhs);
}
    
bool BddNode::operator < (const BddNodeHandle & rhs) const {
    return isLess(rhs);
}

/*
namespace std {
    template<> struct less<BddNodeAndPair> {
        inline bool operator () (const BddNodeAndPair & x, const BddNodeAndPair & y) {
            if ((x.first)->operator < (y.first)) return true;
            if (*(y.first) < *(x.first)) return false;
            return *(x.second) < *(y.second);

        }
    };
}
*/

