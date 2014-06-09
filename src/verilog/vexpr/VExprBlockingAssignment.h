#ifndef VEXPR_BLOCKING_ASSIGNMENT_H
#define VEXPR_BLOCKING_ASSIGNMENT_H

#include "VExprRegLvalue.h"
#include "VExprExpression.h"
#include "VExprStatementInterface.h"

VExprBlockingAssignmentHandle vexpr_blocking_assignment_mk(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr);

class VExprBlockingAssignment : public VExprStatementInterface {
    VExprRegLvalueHandle _pRegLvalue;
    VExprExpressionHandle _pExpr;
public:
    VExprBlockingAssignment(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr);

    VExprRegLvalueHandle getRegLvalueHandle() const;
    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprBlockingAssignmentHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprBlockingAssignmentHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

#endif // VEXPR_BLOCKING_ASSIGNMENT_H
