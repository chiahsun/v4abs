#ifndef VREXPR_BIT_SELECT_H
#define VREXPR_BIT_SELECT_H

#include "nstl/shared_ptr/SharedPtr.h"

#include "VRExprSelectInterface.h"
#include "VRExprExpression.h"

class VRExprBitSelect : public VRExprSelectInterface {
    struct Impl : public VRExprSelectInterface {
        VRExprExpression _expr;
    public:
        Impl(VRExprExpression expr) : _expr(expr)
          { }
        std::string toString() const
          { return _expr.toString(); }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprBitSelect(VRExprExpression expr);
    std::string toString() const;
};


#endif // VREXPR_BIT_SELECT_H
