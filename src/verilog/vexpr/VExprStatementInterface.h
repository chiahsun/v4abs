#ifndef VEXPR_STATEMENT_INTERFACE_H
#define VEXPR_STATEMENT_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"

class VExprStatementInterface;
typedef SharedPtr<VExprStatementInterface> VExprStatementInterfaceHandle;

class VExprStatementInterface {
public:
    virtual ~VExprStatementInterface();
    virtual std::string getString() const;
    virtual std::string getString(unsigned int indentLevel) const;
};

#endif 
