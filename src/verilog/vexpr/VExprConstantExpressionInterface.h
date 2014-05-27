#ifndef VEXPR_CONSTANT_EXPRESSION_INTERFACE_H
#define VEXPR_CONSTANT_EXPRESSION_INTERFACE_H

#include <string>

class VExprConstantExpressionInterface {
public:
    virtual ~VExprConstantExpressionInterface();
    virtual std::string getString() const;
};

#endif // VEXPR_CONSTANT_EXPRESSION_INTERFACE_H
