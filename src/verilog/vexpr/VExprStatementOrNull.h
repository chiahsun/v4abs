#ifndef VEXPR_STATEMENT_OR_NULL_H
#define VEXPR_STATEMENT_OR_NULL_H

#include "VExprStatement.h"
#include "VExprStatementOrNullInterface.h"

VExprStatementOrNullHandle vexpr_statement_or_null_mk_null();
VExprStatementOrNullHandle vexpr_statement_or_null_mk_statement(VExprStatementHandle pStatement);

class VExprStatementOrNull {
    VExprStatementOrNullInterfaceHandle _pInterface;

    VExprStatementHandle _pStatement;
    VExprNullHandle _pNull;

public:
    VExprStatementOrNull(VExprStatementHandle pStatement);
    VExprStatementOrNull(VExprNullHandle pNull);

    VExprStatementHandle getStatementHandle() const;
    VExprNullHandle getNullHandle() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprStatementOrNullHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprStatementOrNullHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

class VExprNull : public VExprStatementOrNullInterface {
public:
    VExprNull() { }
    static VExprNullHandle getNull();
    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

#endif // VEXPR_STATEMENT_OR_NULL_H
