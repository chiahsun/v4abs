#ifndef VEXPR_ALWAYS_H
#define VEXPR_ALWAYS_H

#include "VExprStatement.h"

class VExprAlways {
    VExprStatementHandle _pStatement;
public:
    VExprAlways(VExprStatementHandle pStatement);
    VExprStatementHandle getStatementHandle() const;
    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprAlwaysHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_ALWAYS_H
