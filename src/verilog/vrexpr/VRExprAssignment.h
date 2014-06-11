#ifndef VREXPR_ASSIGNMENT_H
#define VREXPR_ASSIGNMENT_H

#include "VRExprExpression.h"
#include "nstl/hash/HashTable.h"

class VRExprAssignment {
    VRExprExpression _exprLhs;
    VRExprExpression _exprRhs;

    HashTable<VRExprExpression> _hashStaticSensitivity;
    HashTable<VRExprExpression> _hashPosedgeSensitivity;
    HashTable<VRExprExpression> _hashNegedgeSensitivity;

public:
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
};


#endif // VREXPR_ASSIGNMENT_H
