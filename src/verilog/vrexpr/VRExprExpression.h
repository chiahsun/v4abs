#ifndef VREXPR_EXPRESSION_H
#define VREXPR_EXPRESSION_H

#include "VRExprTypes.h"
#include "VRExprInterface.h"

#include "VRExprSelectInterface.h"

#include <vector>
#include "VRExprPrimaryInterface.h"

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"
#include "nstl/hash/HashTable.h"

#include "verilog/vexpr/VExprOpTypes.h"
#include "VRExprExpressionInterface.h"
#include "VRExprIdentifier.h"
#include "VRExprNumber.h"
#include "VRExprTerm.h"

class VRExprExpression;
class VRExprConcatenation;
class VRExprMultConcatenation;
class VRExprIte;
class VRExprIt;
class VRExprIe;


class VRExprSelect {
    Variant2<VRExprBitSelect, VRExprRangeSelect, VRExprSelectInterface> _variant;
public:
    VRExprSelect(const VRExprBitSelect & bitSelect);
    VRExprSelect(const VRExprRangeSelect & rangeSelect);
       
    const VRExprBitSelect* getBitSelectHandle() const
      { return _variant.getFstHandle(); }

    const VRExprRangeSelect* getRangeSelectHandle() const
      { return _variant.getSndHandle(); }

    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
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

        VRExprIdentifier getIdentifier() const
          { return _identifier; }
        const std::vector<VRExprSelect>& getSelectContainer() const
          { return _vecSelect; }
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select);
    VRExprSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect);
    VRExprIdentifier getIdentifier() const
      { return _pImpl->getIdentifier(); }
    const std::vector<VRExprSelect>& getSelectContainer() const
      { return _pImpl->getSelectContainer(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    
    VRExprSelectIdentifier makeSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select); 
    VRExprSelectIdentifier makeSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect);
};


class VRExprPrimary : public VRExprExpressionInterface {
    struct Impl {
       Variant5<VRExprIdentifier, VRExprNumber, VRExprSelectIdentifier, VRExprConcatenation, VRExprMultConcatenation, VRExprPrimaryInterface> _variant; 
    public:
       Impl(VRExprIdentifier identifier);
       Impl(VRExprNumber number);
       Impl(VRExprSelectIdentifier select_identifier);
       Impl(VRExprConcatenation concat);
       Impl(VRExprMultConcatenation mult_concat);
       std::string toString() const;

       const VRExprIdentifier* getIdentifierHandle() const
         { return _variant.getFstHandle(); }
       const VRExprNumber* getNumberHandle() const
         { return _variant.getSndHandle(); }
       const VRExprSelectIdentifier* getSelectIdentifierHandle() const
         { return _variant.getTrdHandle(); }
       const VRExprConcatenation* getConcatenationHandle() const
         { return _variant.getForthHandle(); }
       const VRExprMultConcatenation* getMultConcatenationHandle() const
         { return _variant.getFifthHandle(); }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprPrimary(VRExprIdentifier identifier);
    VRExprPrimary(VRExprNumber number);
    VRExprPrimary(VRExprSelectIdentifier select_identifier);
    VRExprPrimary(VRExprConcatenation concat);
    VRExprPrimary(VRExprMultConcatenation mult_concat);
    const VRExprIdentifier* getIdentifierHandle() const
      { return _pImpl->getIdentifierHandle(); }
    const VRExprNumber* getNumberHandle() const
      { return _pImpl->getNumberHandle(); }
    const VRExprSelectIdentifier* getSelectIdentifierHandle() const
      { return _pImpl->getSelectIdentifierHandle(); }
    const VRExprConcatenation* getConcatenationHandle() const
      { return _pImpl->getConcatenationHandle(); }
    const VRExprMultConcatenation* getMultConcatenationHandle() const
      { return _pImpl->getMultConcatenationHandle(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    HashTable<VRExprExpression> getTerminalExpressions() const;

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
    HashTable<VRExprExpression> getStaticSensitivity() const;
    const VRExprPrimary* getPrimaryHandle() const
      { return _variant.getFstHandle(); }
    const VRExprUnaryExpression* getUnaryExpressionHandle() const
      { return _variant.getSndHandle(); }
    const VRExprBinaryExpression* getBinaryExpressionHandle() const
      { return _variant.getTrdHandle(); }
    const VRExprIte* getIteHandle() const
      { return _variant.getForthHandle(); }
    const VRExprIt* getItHandle() const
      { return _variant.getFifthHandle(); }
    const VRExprIe* getIeHandle() const
      { return _variant.getSixthHandle(); }
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
    HashTable<VRExprExpression> getStaticSensitivity() const;
    HashTable<VRExprExpression> getTerminalExpressions() const;
    std::vector<VRExprExpression> getMuxExpressions() const;
    VRExprTermManager::WddNodeHandle buildWddNode(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeTerminal(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
    int hashFunction() const;
    bool operator == (const VRExprExpression & rhs) const;
    bool operator < (const VRExprExpression & rhs) const
      { return toString().compare(rhs.toString()) < 0; }

    VRExprExpression appendIfByThen(VRExprExpression exprIf) const;
    VRExprExpression appendIfByElse(VRExprExpression exprIf) const;
    const VRExprPrimary* getPrimaryHandle() const
      { return _pImpl->getPrimaryHandle(); }
    const VRExprUnaryExpression* getUnaryExpressionHandle() const
      { return _pImpl->getUnaryExpressionHandle(); }
    const VRExprBinaryExpression* getBinaryExpressionHandle() const
      { return _pImpl->getBinaryExpressionHandle(); }
    const VRExprIte* getIteHandle() const
      { return _pImpl->getIteHandle(); }
    const VRExprIt* getItHandle() const
      { return _pImpl->getItHandle(); }
    const VRExprIe* getIeHandle() const
      { return _pImpl->getIeHandle(); }


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
    VRExprPrimary getPrimary() const
      { return _primary; }
    UnaryOpType getOpType() const
      { return _opType; }
    std::string toString() const; 
};

class VRExprUnaryExpression : public VRExprExpressionInterface {
    typedef VRExprUnaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprUnaryExpression(UnaryOpType opType, VRExprPrimary primary);
    VRExprPrimary getPrimary() const
      { return _pImpl->getPrimary(); }
    UnaryOpType getOpType() const
      { return _pImpl->getOpType(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    VRExprTermManager::WddNodeHandle buildWddNodeTerminal(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
};


class VRExprBinaryExpressionImpl {
    VRExprExpression _exprFst;
    BinaryOpType _opType;
    VRExprExpression _exprSnd;
public:
    VRExprBinaryExpressionImpl(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
    std::string toString() const; 
    VRExprExpression getExprFst() const
      { return _exprFst; }
    BinaryOpType getOpType() const
      { return _opType; }
    VRExprExpression getExprSnd() const
      { return _exprSnd; }
};


class VRExprBinaryExpression : public VRExprExpressionInterface {
    typedef VRExprBinaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
    std::string toString() const; 
    HashTable<VRExprExpression> getStaticSensitivity() const;
    VRExprTermManager::WddNodeHandle buildWddNodeTerminal(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
    VRExprExpression getExprFst() const
      { return _pImpl->getExprFst(); }
    BinaryOpType getOpType() const
      { return _pImpl->getOpType(); }
    VRExprExpression getExprSnd() const
      { return _pImpl->getExprSnd(); }
};

class VRExprIte : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprThen;
        VRExprExpression _exprElse;
    public:
        Impl(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
        std::string toString() const;
        VRExprExpression getExprIf() const { return _exprIf; }
        VRExprExpression getExprThen() const { return _exprThen; }
        VRExprExpression getExprElse() const { return _exprElse; }
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:

    VRExprIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
    VRExprExpression getExprIf() const 
      { return _pImpl->getExprIf(); }
    VRExprExpression getExprThen() const 
      { return _pImpl->getExprThen(); }
    VRExprExpression getExprElse() const 
      { return _pImpl->getExprElse(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    HashTable<VRExprExpression> getTerminalExpressions() const;
    std::vector<VRExprExpression> getMuxExpressions() const;
    VRExprTermManager::WddNodeHandle buildWddNode(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
};

class VRExprIt : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprThen;
    public:
        Impl(VRExprExpression exprIf, VRExprExpression exprThen);
        VRExprExpression getExprIf() const { return _exprIf; }
        VRExprExpression getExprThen() const { return _exprThen; } 
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIt(VRExprExpression exprIf, VRExprExpression exprThen);
    VRExprExpression getExprIf() const 
      { return _pImpl->getExprIf(); }
    VRExprExpression getExprThen() const 
      { return _pImpl->getExprThen(); } 
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    HashTable<VRExprExpression> getTerminalExpressions() const;
    std::vector<VRExprExpression> getMuxExpressions() const;
    VRExprTermManager::WddNodeHandle buildWddNode(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
};

class VRExprIe : public VRExprExpressionInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprElse;
    public:
        Impl(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse);
        VRExprExpression getExprIf() const { return _exprIf; }
        VRExprExpression getExprElse() const { return _exprElse; } 
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIe(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse);
    VRExprExpression getExprIf() const 
      { return _pImpl->getExprIf(); }
    VRExprExpression getExprElse() const 
      { return _pImpl->getExprElse(); } 
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
    HashTable<VRExprExpression> getTerminalExpressions() const;
    std::vector<VRExprExpression> getMuxExpressions() const;
    VRExprTermManager::WddNodeHandle buildWddNode(VRExprTermManager & _termManager) const;
    VRExprTermManager::WddNodeHandle buildWddNodeMux(VRExprTermManager & _termManager) const;
};



class VRExprBitSelect : public VRExprSelectInterface {

    class Impl {
        VRExprExpression _expr;
    public:
        Impl(VRExprExpression expr) : _expr(expr)
          { }
        std::string toString() const
          { return "[" + _expr.toString() + "]"; }
        VRExprExpression getExpr() const { return _expr; }
    
    };
    typedef Impl impl_type;
//    typedef VRExprBitSelectImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprBitSelect(const VRExprExpression & expr);
    std::string toString() const;
    VRExprExpression getExpr() const { return _pImpl->getExpr(); }
    HashTable<VRExprExpression> getStaticSensitivity() const;
};

class VRExprRangeSelect : public VRExprSelectInterface {

    struct Impl {
        VRExprExpression _exprFst, _exprSnd;
    public:
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd) 
          : _exprFst(exprFst)
          , _exprSnd(exprSnd)
          { }
        VRExprExpression getExprFst() const { return _exprFst; }
        VRExprExpression getExprSnd() const { return _exprSnd; }
        std::string toString() const
          { return "[" + _exprFst.toString() + ":" + _exprSnd.toString() + "]"; }
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprRangeSelect(VRExprExpression exprFst, VRExprExpression exprSnd);
    std::string toString() const;
    VRExprExpression getExprFst() const 
      { return _pImpl->getExprFst(); }
    VRExprExpression getExprSnd() const 
      { return _pImpl->getExprSnd(); }
    HashTable<VRExprExpression> getStaticSensitivity() const;
    
};

class VRExprConcatenation : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        std::vector<VRExprExpression> _vecExpr;
    public:
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd);
        Impl(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd);
        Impl(std::vector<VRExprExpression> vecExpr);
        const std::vector<VRExprExpression>& getExprContainer() const
          { return _vecExpr; }
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd);
    VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd);
    VRExprConcatenation(std::vector<VRExprExpression> vecExpr);

    const std::vector<VRExprExpression>& getExprContainer() const
      { return _pImpl->getExprContainer(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;
};

class VRExprMultConcatenation : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        VRExprExpression _exprRepeat;
        std::vector<VRExprExpression> _vecExpr;
    public:
        Impl(VRExprExpression exprRepeat, VRExprExpression expr);
        Impl(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd);
        Impl(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr);
        VRExprExpression getExprRepeat() const { return _exprRepeat; }
        const std::vector<VRExprExpression> & getExprContainer() const
          { return _vecExpr; }
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprMultConcatenation(VRExprExpression exprRepeat, VRExprExpression expr);
    VRExprMultConcatenation(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd);
    VRExprMultConcatenation(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr);
    VRExprExpression getExprRepeat() const 
      { return _pImpl->getExprRepeat(); }
    const std::vector<VRExprExpression> & getExprContainer() const
      { return _pImpl->getExprContainer(); }
    std::string toString() const;
    HashTable<VRExprExpression> getStaticSensitivity() const;

};

#endif // VREXPR_EXPRESSION_H
