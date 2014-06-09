#ifndef VEXPR_CONDITIONAL_STATEMENT_H
#define VEXPR_CONDITIONAL_STATEMENT_H

#include "VExprExpression.h"
#include "VExprStatementOrNull.h"
#include "VExprStatementInterface.h"

VExprConditionalStatementHandle vexpr_conditional_mk_if_then(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen);

VExprConditionalStatementHandle vexpr_conditional_mk_if_then_else(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse);


class VExprConditionalStatement : public VExprStatementInterface {
    VExprExpressionHandle _pIf;

    VExprStatementOrNullHandle _pThen;
    VExprStatementOrNullHandle _pElse;
public:
    VExprConditionalStatement(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen);
    VExprConditionalStatement(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse);

    VExprExpressionHandle getIf() const;

    VExprStatementOrNullHandle getThen() const;
    VExprStatementOrNullHandle getElse() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprConditionalStatementHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprConditionalStatementHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

#endif // VEXPR_CONDITIONAL_STATEMENT_H
