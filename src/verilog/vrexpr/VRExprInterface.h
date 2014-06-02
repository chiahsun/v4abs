#ifndef VREXPR_INTERFACE_H
#define VREXPR_INTERFACE_H

#include <string>

class VRExprInterface {
public:
    VRExprInterface() { }
    virtual ~VRExprInterface() { }
    virtual std::string toString() const = 0;
};


#endif // VREXPR_INTERFACE_H
