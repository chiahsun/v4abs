#ifndef VREXPR_EXPRESSION_INTERFACE_H
#define VREXPR_EXPRESSION_INTERFACE_H

#include <string>

class VRExprExpression;

template <class T>
class HashTable;

class VRExprExpressionInterface {
public:
    VRExprExpressionInterface() { }
    virtual ~VRExprExpressionInterface() { }
    virtual std::string toString() const = 0;
    virtual HashTable<VRExprExpression> getStaticSensitivity() const = 0;
};

#endif // VREXPR_EXPRESSION_INTERFACE_H
