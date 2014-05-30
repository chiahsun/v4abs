#ifndef VREXPR_PRIMARY_INTERFACE_H
#define VREXPR_PRIMARY_INTERFACE_H

#include <string>

class VRExprPrimaryInterface {
public:
    VRExprPrimaryInterface() { }
    virtual ~VRExprPrimaryInterface() { }
    virtual std::string toString() const = 0;
};

#endif // VREXPR_PRIMARY_INTERFACE_H
