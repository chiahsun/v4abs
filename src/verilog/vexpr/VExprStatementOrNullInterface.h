#ifndef VEXPR_STATEMENT_OR_NULL_INTERFACE_H
#define VEXPR_STATEMENT_OR_NULL_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"


class VExprStatementOrNullInterface {
public:
    virtual ~VExprStatementOrNullInterface();
    virtual std::string getString() const;
    virtual std::string getString(unsigned int pos) const;
};

#endif // VEXPR_STATEMENT_OR_NULL_INTERFACE_H
