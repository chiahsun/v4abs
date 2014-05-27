#ifndef VEXPR_PRIMARY_INTERFACE_H
#define VEXPR_PRIMARY_INTERFACE_H

#include "nstl/shared_ptr/SharedPtr.h"

class VExprPrimaryInterface;
typedef SharedPtr<VExprPrimaryInterface> VExprPrimaryInterfaceHandle;

class VExprPrimaryInterface {
public:
    virtual ~VExprPrimaryInterface();
    virtual std::string getString() const;
    virtual size_t getSize() const;
};

#endif // VEXPR_PRIMARY_INTERFACE_H
