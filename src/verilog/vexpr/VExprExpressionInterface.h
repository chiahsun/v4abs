#ifndef VEXPR_EXPRESSION_INTERFACE_H
#define VEXPR_EXPRESSION_INTERFACE_H

#include "nstl/shared_ptr/SharedPtr.h"

class VExprExpressionInterface;
typedef SharedPtr<VExprExpressionInterface> VExprExpressionInterfaceHandle;

class VExprExpressionInterface {
public:
    virtual ~VExprExpressionInterface();
    virtual std::string getString() const;
    virtual size_t getSize() const;
};


#endif // VEXPR_EXPRESSION_INTERFACE_H
