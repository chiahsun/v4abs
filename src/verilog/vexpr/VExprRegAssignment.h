#ifndef VEXPR_REG_ASSIGNMENT_H
#define VEXPR_REG_ASSIGNMENT_H

#include "VExprRegLvalue.h"
#include "VExprExpression.h"

class VExprRegAssignment {
    VExprRegLvalueHandle _pRegLvalue;
    VExprExpressionHandle _pExpression;
public:
    VExprRegAssignment(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpression);

    VExprRegLvalueHandle& getRegLvalueHandle();
    VExprExpressionHandle& getExpressionHandle();

    const VExprRegLvalueHandle& getRegLvalueHandle() const;
    const VExprExpressionHandle& getExpressionHandle() const;

    std::string getString() const;
};


#endif // VEXPR_REG_ASSIGNMENT_H
