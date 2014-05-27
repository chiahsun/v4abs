#ifndef VEXPR_REG_LVALUE_INTERFACE_H
#define VEXPR_REG_LVALUE_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"

class VExprRegLvalueInterface;
typedef SharedPtr<VExprRegLvalueInterface> VExprRegLvalueInterfaceHandle;


class VExprRegLvalueInterface {
public:
    virtual ~VExprRegLvalueInterface();
    virtual std::string getString() const;
};

#endif // VEXPR_REG_LVALUE_INTERFACE_H
