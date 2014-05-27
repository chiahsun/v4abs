#ifndef VEXPR_SELECT_INTERFACE_H
#define VEXPR_SELECT_INTERFACE_H

#include <string>

#include "nstl/shared_ptr/SharedPtr.h"

class VExprSelectInterface;
typedef SharedPtr<VExprSelectInterface> VExprSelectInterfaceHandle;

class VExprSelectInterface {
public:
    virtual ~VExprSelectInterface();
    virtual std::string getString() const;
    virtual size_t getSize() const; 
};


#endif // VEXPR_SELECT_INTERFACE_H
