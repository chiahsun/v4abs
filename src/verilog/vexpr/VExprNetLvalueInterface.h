#ifndef VEXPR_NET_LVALUE_INTERFACE_H
#define VEXPR_NET_LVALUE_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"

class VExprNetLvalueInterface;
typedef SharedPtr<VExprNetLvalueInterface> VExprNetLvalueInterfaceHandle;

class VExprNetLvalueInterface {
public:
    virtual ~VExprNetLvalueInterface();
    virtual std::string getString() const;
};

#endif // VEXPR_NET_LVALUE_INTERFACE_H
