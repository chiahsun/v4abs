#ifndef VEXPR_NON_BLOCKING_ASSIGNMENT_H
#define VEXPR_NON_BLOCKING_ASSIGNMENT_H

#include "VExprRegLvalue.h"
#include "VExprExpression.h"
#include "VExprStatementInterface.h"

VExprNonBlockingAssignmentHandle vexpr_non_blocking_assignment_mk(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr);

class VExprNonBlockingAssignment : public VExprStatementInterface {
    const VExprRegLvalueHandle _pRegLvalue;
    const VExprExpressionHandle _pExpr;
public:
    VExprNonBlockingAssignment(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr);

    VExprRegLvalueHandle getRegLvalueHandle() const;
    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprStatementHandle toStatementHandle() const;
    VExprStatementOrNullHandle toStatementOrNullHandle() const;

    VExprNonBlockingAssignmentHandle flatten(VExprIdentifierHandle pInstName) const;
};


#endif // VEXPR_NON_BLOCKING_ASSIGNMENT_H
