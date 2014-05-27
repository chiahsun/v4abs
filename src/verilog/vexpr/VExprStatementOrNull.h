#ifndef VEXPR_STATEMENT_OR_NULL_H
#define VEXPR_STATEMENT_OR_NULL_H

#include "VExprStatement.h"
#include "VExprStatementOrNullInterface.h"

VExprStatementOrNullHandle vexpr_statement_or_null_mk_null();
VExprStatementOrNullHandle vexpr_statement_or_null_mk_statement(VExprStatementHandle pStatement);

class VExprStatementOrNull {
    const VExprStatementOrNullInterfaceHandle _pInterface;

    const VExprStatementHandle _pStatement;
    const VExprNullHandle _pNull;

public:
    VExprStatementOrNull(VExprStatementHandle pStatement);
    VExprStatementOrNull(VExprNullHandle pNull);

    VExprStatementHandle getStatementHandle() const;
    VExprNullHandle getNullHandle() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

class VExprNull : public VExprStatementOrNullInterface {
public:
    VExprNull() { }
    static VExprNullHandle getNull();
    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

#endif // VEXPR_STATEMENT_OR_NULL_H
