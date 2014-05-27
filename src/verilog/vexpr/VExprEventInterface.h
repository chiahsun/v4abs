#ifndef VEXPR_EVENT_INTERFACE_H
#define VEXPR_EVENT_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"

class VExprEventInterface;
typedef SharedPtr<VExprEventInterface> VExprEventInterfaceHandle;

class VExprEventInterface {
public:
    virtual ~VExprEventInterface();
    virtual std::string getString() const;
};


#endif 
