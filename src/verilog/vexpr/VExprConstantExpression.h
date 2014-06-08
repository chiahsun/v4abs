#ifndef VEXPR_CONSTANT_EXPRESSION_H
#define VEXPR_CONSTANT_EXPRESSION_H

#include "VExprTypes.h"
#include "VExprOpTypes.h"
#include "VExprConstantExpressionInterface.h"
#include "VExprConstantPrimary.h"

VExprConstantExpressionHandle vexpr_constant_expression_mk_unsigned_number(unsigned int unsignedNumber);
VExprConstantExpressionHandle vexpr_constant_expression_mk_binary_number(std::string s);
VExprConstantExpressionHandle vexpr_constant_expression_mk_octal_number(std::string s);
VExprConstantExpressionHandle vexpr_constant_expression_mk_decimal_number(std::string s);
VExprConstantExpressionHandle vexpr_constant_expression_mk_hex_number(std::string s);

VExprConstantExpressionHandle vexpr_constant_expression_mk_single_identifier(std::string identifier, size_t size = 1);
VExprConstantExpressionHandle vexpr_constant_expression_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprConstantExpressionHandle vexpr_constant_expression_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);



VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr);

VExprConstantExpressionHandle vexpr_constant_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr);
VExprConstantExpressionHandle vexpr_constant_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr);


VExprConstantExpressionHandle vexpr_constant_expression_mk_unary(UnaryOpType opType, VExprConstantPrimaryHandle pPrimary);
VExprConstantExpressionHandle vexpr_constant_expression_mk_binary(VExprConstantExpressionHandle pFst, BinaryOpType opType, VExprConstantExpressionHandle pSnd);
VExprConstantExpressionHandle vexpr_constant_expression_mk_ternary(VExprConstantExpressionHandle pIf, VExprConstantExpressionHandle pThen, VExprConstantExpressionHandle pElse);

VExprConstantExpressionHandle vexpr_constant_expression_mk_true();
VExprConstantExpressionHandle vexpr_constant_expression_mk_false();


class VExprConstantExpression {
    VExprConstantExpressionInterfaceHandle _pInterface;

    VExprConstantPrimaryHandle _pPrimary;
    VExprConstantUnaryHandle _pUnary;
    VExprConstantBinaryHandle _pBinary;
    VExprConstantTernaryHandle _pTernary;
    VExprBoolHandle _pBool;
public:
    VExprConstantExpression(VExprConstantPrimaryHandle pPrimary);
    VExprConstantExpression(VExprConstantUnaryHandle pUnary);
    VExprConstantExpression(VExprConstantBinaryHandle pBinary);
    VExprConstantExpression(VExprConstantTernaryHandle pTernary);
    VExprConstantExpression(VExprBoolHandle pBool);

    VExprConstantPrimaryHandle getConstantPrimaryHandle() const;
    VExprConstantUnaryHandle getConstantUnaryhandle() const;
    VExprConstantBinaryHandle getConstantBinaryHandle() const;
    VExprConstantTernaryHandle getConstantTernaryHandle() const;
    VExprBoolHandle getBoolHandle() const;

    std::string getString() const;

    VExprConstantExpressionHandle flatten(VExprIdentifierHandle pInstName) const;

    VExprExpressionHandle toExpressionHandle() const;
//    size_t getSize() const;
};

class VExprConstantUnary : public VExprConstantExpressionInterface {
    UnaryOpType _opType;
    VExprConstantPrimaryHandle _pConstantPrimary;
public:
    VExprConstantUnary(UnaryOpType opType, VExprConstantPrimaryHandle pConstantPrimary);

    VExprConstantPrimaryHandle getConstantPrimaryHandle() const;
    UnaryOpType getOpType() const;
    std::string getOpTypeSymbol() const;

    std::string getString() const;
    VExprConstantUnaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprUnaryHandle toUnaryHandle() const;
};

class VExprConstantBinary : public VExprConstantExpressionInterface {
    VExprConstantExpressionHandle _pExprFst;
    BinaryOpType _opType;
    VExprConstantExpressionHandle _pExprSnd;
public:
    VExprConstantBinary(VExprConstantExpressionHandle pExprFst, BinaryOpType opType, VExprConstantExpressionHandle pExprSnd);

    VExprConstantExpressionHandle getExprFst() const;
    VExprConstantExpressionHandle getExprSnd() const;
    BinaryOpType getOpType() const;
    std::string getOpTypeSymbol() const;

    std::string getString() const;
    VExprConstantBinaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprBinaryHandle toBinaryHandle() const;
};


class VExprConstantTernary : public VExprConstantExpressionInterface {
    VExprConstantExpressionHandle _pIf;
    VExprConstantExpressionHandle _pThen;
    VExprConstantExpressionHandle _pElse;
public:
    VExprConstantTernary(VExprConstantExpressionHandle pIf, VExprConstantExpressionHandle pThen, VExprConstantExpressionHandle pElse);
 
    VExprConstantExpressionHandle getIf() const;
    VExprConstantExpressionHandle getThen() const;
    VExprConstantExpressionHandle getElse() const;

    std::string getString() const;
    VExprConstantTernaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprTernaryHandle toTernaryHandle() const;
};

#endif // VEXPR_CONSTANT_EXPRESSION_H
