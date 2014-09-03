#ifndef BDD_NODE_H
#define BDD_NODE_H

#include <string>
#include <set>
#include <map>

#include "BddTypes.h"
#include "BddManager.h"



class BddNode {
    const int _curDecisionLevel;
    const BddNodeHandle _pPos;
    const BddNodeHandle _pNeg;

    struct Bool {
        bool _bool;
        Bool(bool v) : _bool(v) { }
    };
    typedef SharedPtrE<Bool> BoolHandle;

    const BoolHandle _pBool;

public:

private:
    const int _hashValue;
    const int _uniqueId;
public:

    BddNode(int curDecisionLevel);
    BddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg);
    BddNode(bool val);


    BddNodeHandle getPosHandle() const;
    BddNodeHandle getNegHandle() const;

    BddNodeHandle reduce1(int varDecisionLevel) const;
    BddNodeHandle reduce0(int varDecisionLevel) const;

    int getCurDecisionLevel() const;
    bdd_id_type getBddId() const;
    int getUniqueId() const { return _uniqueId; }

    bool getBool() const;
    bool isTerminal() const;
    bool isDecisionLevel() const;

    static BddNodeHandle getPosCofactor(BddNodeHandle pBddNode, int curDecisionLevel);
    static BddNodeHandle getNegCofactor(BddNodeHandle pBddNode, int curDecisionLevel);

    
    static BddNodeHandle makeBddNode(int curDecisionLevel);
    static BddNodeHandle makeBddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg);

    static BddNodeHandle getConstOneHandle();
    static BddNodeHandle getConstZeroHandle();

    
    std::string toString() const;
    std::string toString(int curId, int indentLevel) const;
    void writeDotFile(const std::string & filename) const;

    int hashFunction() const;
    int computeHashFunction(BddNodeHandle pPos, BddNodeHandle pNeg) const;
    int computeHashFunction() const;


    bool operator < (const BddNode & rhs) const;
    bool operator < (const BddNodeHandle & rhs) const;
    bool isLess(const BddNode & rhs) const;
    bool isLess(const BddNodeHandle & pBddNode) const;

    bool equal(BddNodeHandle pBddNode) const;
    bool equal(const BddNode & rhs) const;

    bool isStructureEqual(BddNodeHandle pBddNode) const; 
    bool isStructureEqual(const BddNode & rhs) const; 
private:

    std::string toDotFormat() const;
    void collectLink(int curId, std::map<BddNode, std::string> & mapBddName, std::map<BddNode, std::string> & mapArrowString) const;
    std::string getSymboltoString(int pos) const;
    std::string getBddSymbolOnDotFormat(int curId = 0) const;

    std::string getBddName(int curId, std::map<BddNode, std::string> & mapBddName) const;

    std::set<BddNodeHandle> collectFromNode(BddNodeHandle pBddNode) const; 

    std::set<BddNodeHandle> collectFromNodeHelper(BddNodeHandle pBddNode) const; 
   
public:
    bool operator == (const BddNode& rhs) const {
        return equal(rhs);
    }
    bool operator == (const BddNodeHandle& pBddNode) const {
        return this->operator==(*pBddNode);
    }
};


/** 
 * Referece
 * 1. Define less for user-defined type
 *    http://stackoverflow.com/questions/1102392/stl-maps-with-user-defined-objects
 */

#endif // BDD_NODE_H
