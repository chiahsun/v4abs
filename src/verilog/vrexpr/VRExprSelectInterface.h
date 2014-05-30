#ifndef VREXPR_SELECT_INTERFACE_H
#define VREXPR_SELECT_INTERFACE_H

#include <string>

class VRExprSelectInterface {

public:
    virtual ~VRExprSelectInterface() { }
    virtual std::string toString() const = 0;
};

#endif // VREXPR_SELECT_INTERFACE_H
