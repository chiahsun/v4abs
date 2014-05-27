#ifndef VEXPR_CONSTANT_PRIMARY_INTERFACE_H
#define VEXPR_CONSTANT_PRIMARY_INTERFACE_H

#include "nstl/shared_ptr/SharedPtr.h"

class VExprConstantPrimaryInterface {
public:
    virtual ~VExprConstantPrimaryInterface();
    virtual std::string getString() const;
    virtual size_t getSize() const;
};

#endif // VEXPR_CONSTANT_PRIMARY_INTERFACE_H
