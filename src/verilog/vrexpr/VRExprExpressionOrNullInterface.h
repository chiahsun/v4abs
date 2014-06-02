#ifndef VREXPR_EXPRESSION_OR_NULL_INTERFACE_H
#define VREXPR_EXPRESSION_OR_NULL_INTERFACE_H

#include <string>

class VRExprExpressionOrNullInterface {
public:
    VRExprExpressionOrNullInterface() { }
    virtual ~VRExprExpressionOrNullInterface() { }
    virtual std::string toString() const = 0;
};

#endif // VREXPR_EXPRESSION_OR_NULL_INTERFACE_H
