#ifndef VREXPR_H
#define VREXPR_H

#include <string>

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"

#include "VRExprExpression.h"
#include "VRExprIte.h"

/**
 * Guideline to used shared_ptr
 * Always construct new values from constructor
 * if you intend to modify some attribute of that value
 */

class VRExpr {
    Variant2<VRExprExpression, VRExprIte, VRExprInterface> _variant; 
public:
    VRExpr(VRExprExpression expr);
    VRExpr(VRExprIte ite);
    std::string toString() const;
};


#endif 
