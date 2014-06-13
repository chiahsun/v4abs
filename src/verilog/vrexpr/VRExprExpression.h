#ifndef VREXPR_EXPRESSION_H
#define VREXPR_EXPRESSION_H

#include "VRExprInterface.h"

#include "VRExprSelectInterface.h"

#include <vector>
#include "VRExprPrimaryInterface.h"

#include "VRExprTypes.h"
#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"
#include "verilog/vexpr/VExprOpTypes.h"
#include "VRExprExpressionInterface.h"
#include "VRExprIdentifier.h"
#include "VRExprNumber.h"

class VRExprExpression;
class VRExprConcatenation;
class VRExprMultConcatentation;
class VRExprIte;
class VRExprIt;
class VRExprIe;


class VRExprSelect {
    Variant2<VRExprBitSelect, VRExprRangeSelect, VRExprSelectInterface> _variant;
public:
    VRExprSelect(const VRExprBitSelect & bitSelect);
    VRExprSelect(const VRExprRangeSelect & rangeSelect);

    std::string toString() const;
    friend VRExprSelect makeBitSelect(const VRExprExpression & expr);
    friend VRExprSelect makeRangeSelect(const VRExprExpression & exprFst, const VRExprExpression & exprSnd);
    friend VRExprSelect makeBitSelect(const VRExprBitSelect & bitSelect);
    friend VRExprSelect makeRangeSelect(const VRExprRangeSelect & rangeSelect);
};

VRExprSelect makeBitSelect(const VRExprExpression & expr);
VRExprSelect makeRangeSelect(const VRExprExpression & exprFst, const VRExprExpression & exprSnd);
VRExprSelect makeBitSelect(const VRExprBitSelect & bitSelect);
VRExprSelect makeRangeSelect(const VRExprRangeSelect & rangeSelect);

class VRExprSelectIdentifier : public VRExprPrimaryInterface {
    class Impl {
        VRExprIdentifier _identifier;
        std::vector<VRExprSelect> _vecSelect;
    public:
        Impl(VRExprIdentifier identifier, VRExprSelect select);
        Impl(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect);

        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select);
    VRExprSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect);
    std::string toString() const;
    VRExprSelectIdentifier makeSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select); 
    VRExprSelectIdentifier makeSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect);
};


class VRExprPrimary : public VRExprExpressionInterface {
    struct Impl : public VRExprExpressionInterface {
       Variant5<VRExprIdentifier, VRExprNumber, VRExprSelectIdentifier, VRExprConcatenation, VRExprMultConcatentation, VRExprPrimaryInterface> _variant; 
    public:
       Impl(VRExprIdentifier identifier);
       Impl(VRExprNumber number);
       Impl(VRExprSelectIdentifier select_identifier);
       Impl(VRExprConcatenation concat);
       Impl(VRExprMultConcatentation mult_concat);
       std::string toString() const;
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprPrimary(VRExprIdentifier identifier);
    VRExprPrimary(VRExprNumber number);
    VRExprPrimary(VRExprSelectIdentifier select_identifier);
    VRExprPrimary(VRExprConcatenation concat);
    VRExprPrimary(VRExprMultConcatentation mult_concat);
    std::string toString() const;

    friend VRExprPrimary makeBinaryNumber(std::string numberLiterals);
    friend VRExprPrimary makeOctalNumber(std::string numberLiterals);
    friend VRExprPrimary makeDecimalNumber(std::string numberLiterals);
    friend VRExprPrimary makeHexNumber(std::string numberLiterals);
    friend VRExprPrimary makeUnsignedNumber(unsigned int x);
    friend VRExprPrimary makeIdentifier(std::string name);
    friend VRExprPrimary makeSelectIdentifier(std::string name, VRExprSelect select);
    friend VRExprPrimary makeConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd);
    friend VRExprPrimary makeConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd);
    friend VRExprPrimary makeConcatenation(std::vector<VRExprExpression> vecExpr);
    friend VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, VRExprExpression expr);
    friend VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd);
    friend VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr);
};
    
VRExprPrimary makeBinaryNumber(std::string numberLiterals);
VRExprPrimary makeOctalNumber(std::string numberLiterals);
VRExprPrimary makeDecimalNumber(std::string numberLiterals);
VRExprPrimary makeHexNumber(std::string numberLiterals);
VRExprPrimary makeUnsignedNumber(unsigned int x);
VRExprPrimary makeIdentifier(std::string name);

/**
 * Note: binary expression and unary expression has to be in the same header as expression (cross reference), DON'T try to split them, or you would see the error message "class X has incomplete type"
 */

class VRExprExpressionImpl {
    Variant6<VRExprPrimary, VRExprUnaryExpression, VRExprBinaryExpression, VRExprIte, VRExprIt, VRExprIe, VRExprExpressionInterface> _variant;
public:
    VRExprExpressionImpl(VRExprPrimary primary);
    VRExprExpressionImpl(VRExprUnaryExpression unary_expr);
    VRExprExpressionImpl(VRExprBinaryExpression binary_expr);
    VRExprExpressionImpl(VRExprIte ite);
    VRExprExpressionImpl(VRExprIt it);
    VRExprExpressionImpl(VRExprIe ie);
    std::string toString() const;

};


class VRExprExpression : public VRExprInterface {
    typedef VRExprExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprExpression();
    VRExprExpression(VRExprPrimary primary);
    VRExprExpression(VRExprUnaryExpression unary_expr);
    VRExprExpression(VRExprBinaryExpression binary_expr);
    VRExprExpression(VRExprIte ite);
    VRExprExpression(VRExprIt it);
    VRExprExpression(VRExprIe ie);
    std::string toString() const;
    int hashFunction() const;
    bool operator == (const VRExprExpression & rhs) const;
    bool operator < (const VRExprExpression & rhs) const
      { return toString().compare(rhs.toString()) < 0; }

    VRExprExpression appendIfByThen(VRExprExpression exprIf) const;
    VRExprExpression appendIfByElse(VRExprExpression exprIf) const;

    friend VRExprExpression makePrimaryExpression(VRExprPrimary primary);
    friend VRExprExpression makeUnaryExpression(UnaryOpType opType, VRExprPrimary primary);
    friend VRExprExpression makeBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
};

VRExprExpression makeUnaryExpression(UnaryOpType opType, VRExprPrimary primary);
VRExprExpression makeBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);

class VRExprUnaryExpressionImpl {
    UnaryOpType _opType;
    VRExprPrimary _primary;
public:
    VRExprUnaryExpressionImpl(UnaryOpType opType, VRExprPrimary primary);
    std::string toString() const; 
};

class VRExprUnaryExpression : public VRExprExpressionInterface {
    typedef VRExprUnaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprUnaryExpression(UnaryOpType opType, VRExprPrimary primary);
    std::string toString() const;
};


class VRExprBinaryExpressionImpl {
    VRExprExpression _exprFst;
    BinaryOpType _opType;
    VRExprExpression _exprSnd;
public:
    VRExprBinaryExpressionImpl(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
   std::string toString() const; 
};


class VRExprBinaryExpression : public VRExprExpressionInterface {
    typedef VRExprBinaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
    std::string toString() const; 
};

class VRExprIte : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprThen;
        VRExprExpression _exprElse;
    public:
        Impl(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:

    VRExprIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
    std::string toString() const;
};

class VRExprIt : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprThen;
    public:
        Impl(VRExprExpression exprIf, VRExprExpression exprThen);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIt(VRExprExpression exprIf, VRExprExpression exprThen);
    std::string toString() const;
};

class VRExprIe : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprElse;
    public:
        Impl(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIe(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse);
    std::string toString() const;
};



class VRExprBitSelect : public VRExprSelectInterface {

    class Impl : public VRExprSelectInterface {
        VRExprExpression _expr;
    public:
        Impl(VRExprExpression expr) : _expr(expr)
          { }
        std::string toString() const
          { return "[" + _expr.toString() + "]"; }
    };
    typedef Impl impl_type;
//    typedef VRExprBitSelectImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprBitSelect(const VRExprExpression & expr);
    std::string toString() const;
};

class VRExprRangeSelect : public VRExprSelectInterface {

    struct Impl : public VRExprSelectInterface {
        VRExprExpression _exprFst, _exprSnd;
    public:
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd) 
          : _exprFst(exprFst)
          , _exprSnd(exprSnd)
          { }
        std::string toString() const
          { return "[" + _exprFst.toString() + ":" + _exprSnd.toString() + "]"; }
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprRangeSelect(VRExprExpression exprFst, VRExprExpression exprSnd);
    std::string toString() const;
    
};

class VRExprConcatenation : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        std::vector<VRExprExpression> _vecExpr;
    public:
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd);
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd);
        Impl(std::vector<VRExprExpression> vecExpr);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd);
    VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd);
    VRExprConcatenation(std::vector<VRExprExpression> vecExpr);

    std::string toString() const;
};

class VRExprMultConcatentation : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        VRExprExpression _exprRepeat;
        std::vector<VRExprExpression> _vecExpr;
    public:
        Impl(VRExprExpression exprRepeat, VRExprExpression expr);
        Impl(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd);
        Impl(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprMultConcatentation(VRExprExpression exprRepeat, VRExprExpression expr);
    VRExprMultConcatentation(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd);
    VRExprMultConcatentation(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr);
    std::string toString() const;

};

#endif // VREXPR_EXPRESSION_H
