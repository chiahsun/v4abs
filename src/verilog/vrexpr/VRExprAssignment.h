#ifndef VREXPR_ASSIGNMENT_H
#define VREXPR_ASSIGNMENT_H

#include "VRExprExpression.h"
#include "nstl/hash/HashTable.h"
#include "VRExprTerm.h"

class VRExprAssignment {
    VRExprExpression _exprLhs;
    VRExprExpression _exprRhs;

    HashTable<VRExprExpression> _hashStaticSensitivity;
    HashTable<VRExprExpression> _hashPosedgeSensitivity;
    HashTable<VRExprExpression> _hashNegedgeSensitivity;

    HashTable<VRExprExpression> _hashTerminals;
    std::vector<VRExprExpression> _vecMux;

    typedef VRExprTermManager::VRExprTermHandle VRExprTermHandle;
    typedef VRExprTermManager::WddNodeHandle WddNodeHandle;

    VRExprTermManager _termManager;
    WddNodeHandle _wddNode;
public:
    VRExprAssignment();
    VRExprAssignment(VRExprExpression lhs, VRExprExpression rhs);
    
    VRExprExpression getExprLhs() const;
    VRExprExpression getExprRhs() const;

    void addStaticSensitivity(VRExprExpression expr);
    void addPosedgeSensitivity(VRExprExpression expr);
    void addNegedgeSensitivity(VRExprExpression expr);

    void addStaticSensitivity(VRExprIdentifier identifier);
    void addPosedgeSensitivity(VRExprIdentifier identifier);
    void addNegedgeSensitivity(VRExprIdentifier identifier);

    std::string toString() const;

private:
    void initStaticSensitivity();
    void initTerminalExpressions();
    void initMuxExpressions();
    void buildWddNode(); 
};


#endif // VREXPR_ASSIGNMENT_H
