#ifndef BDD_MANAGER_H
#define BDD_MANAGER_H

#include "BddTypes.h"
#include "nstl/hash/HashTable.h"
#include "BddNode.h"

/**
 * Reference
 * 1. Binary Decision Diagrams
 *    Fabio Somenzi
 *    (1) AND(f, g) : conjunction algorithm
 */

/**
 * NOTE:
 *  1. negation on BDD
 *     it is change the root node of const0 and const1
 *     *NOT* change edge of pos and neg only
 */

#include <map>

struct BddNodeAndPairCompareFunctor {
    bool operator () (const BddNodeAndPair & x, const BddNodeAndPair & y);
};



class BddManager {

    typedef HashTable<BddNodeHandle> hash_type;
    hash_type _hashBddNode;

    
    typedef std::map<BddNodeAndPair, BddNodeHandle, BddNodeAndPairCompareFunctor> BddNodeAndPairMap;
    BddNodeAndPairMap _mapAnd;


public:
    static BddNodeHandle BDD_TRUE;
    static BddNodeHandle BDD_FALSE;

    BddManager();


    int size() const { return _hashBddNode.size(); }

    BddNodeHandle makeBddNode(int curDecisionLevel);
    BddNodeHandle makeBddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg);

    // Primitive functions
    BddNodeHandle makeAnd(BddNodeHandle pFst, BddNodeHandle pSnd);
    BddNodeHandle makeNeg(BddNodeHandle pBddNode);
    BddNodeHandle ite(BddNodeHandle pIf, BddNodeHandle pThen, BddNodeHandle pElse);

    BddNodeHandle makeOr(BddNodeHandle pFst, BddNodeHandle pSnd);
    BddNodeHandle makeImply(BddNodeHandle pFst, BddNodeHandle pSnd);
    BddNodeHandle makeEq(BddNodeHandle pFst, BddNodeHandle pSnd);
    BddNodeHandle makeXor(BddNodeHandle pFst, BddNodeHandle pSnd);
    BddNodeHandle makeXnor(BddNodeHandle pFst, BddNodeHandle pSnd);

    bool isNeg(BddNodeHandle pFst, BddNodeHandle pSnd);
private:
//    bool findBddNode(int curDecisionLevel, BddNodeHandle pPos, BddNodeHandle pNeg);


    BddNodeHandle find_or_insert(BddNodeHandle pBddNode);
    hash_type::iterator try_find(BddNodeHandle pBddNode);

//    BddNodeHandle restrict(BddNodeHandle pFst, BddNodeHandle pSnd);

    // It should be communitive for OPs, so imply is invalid
    enum OpType {
        OP_OR
      , OP_AND
    };

//    BddNodeHandle apply(OpType op, BddNodeHandle pFst, BddNodeHandle pSnd);

    BddNodeHandle findHandleInPairMap(BddNodeAndPairMap  & m, BddNodeHandle pFst, BddNodeHandle pSnd) const;
    void insertHandlePairInPairMap(BddNodeAndPairMap & m, BddNodeHandle pPos, BddNodeHandle pNeg, BddNodeHandle pBddNode); 

public:
 //   bool checkHash() const;
    void addBddNode(BddNodeHandle pBddNode);
};


#endif // BDD_MANAGER_H
