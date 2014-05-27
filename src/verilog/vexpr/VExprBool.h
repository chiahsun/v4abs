#ifndef VEXPR_BOOL_H
#define VEXPR_BOOL_H

#include "VExprTypes.h"
#include "VExprExpressionInterface.h"
#include "VExprConstantExpressionInterface.h"

class VExprBool : public VExprExpressionInterface, public VExprConstantExpressionInterface {
    bool _boolVal;
public:
    VExprBool(bool boolVal);
    static VExprBoolHandle getTrueHandle();
    static VExprBoolHandle getFalseHandle();
    bool getValue() const;
    std::string getString() const;
    size_t getSize() const;
};

#endif // VEXPR_BOOL_H
