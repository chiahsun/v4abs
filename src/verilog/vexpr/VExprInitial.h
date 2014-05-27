#ifndef VEXPR_INITIAL_H
#define VEXPR_INITIAL_H

#include "VExprStatement.h"

class VExprInitial {
    VExprStatementHandle _pStatement;
public:
    VExprInitial(VExprStatementHandle pStatement);
    VExprStatementHandle getStatementHandle() const;
    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

};

#endif // VEXPR_INITIAL_H
