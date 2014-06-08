#ifndef VEXPR_NET_ASSIGNMENT_H
#define VEXPR_NET_ASSIGNMENT_H

#include "VExprNetLvalue.h"
#include "VExprExpression.h" 

VExprNetAssignmentHandle vexpr_net_assignment_mk(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr);

class VExprNetAssignment {
    VExprNetLvalueHandle _pNetLvalue;
    VExprExpressionHandle _pExpr;
public:
    VExprNetAssignment(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr);

    VExprNetLvalueHandle getNetLvalueHandle() const;
    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;

    VExprNetAssignmentHandle flatten(VExprIdentifierHandle pInstName) const;
    int hashFunction() const;
};

#endif // VEXPR_NET_ASSIGNMENT_H
