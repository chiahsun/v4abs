#ifndef VEXPR_EXPRESSION_H
#define VEXPR_EXPRESSION_H

#include "VExprTypes.h"
#include "VExprOpTypes.h"
#include "VExprExpressionInterface.h"
#include "VExprEventInterface.h"
#include "VExprPrimary.h"
#include "VExprBool.h"

#include <string>


VExprExpressionHandle vexpr_expression_mk_unsigned_number(unsigned int unsignedNumber);
VExprExpressionHandle vexpr_expression_mk_binary_number(std::string s);
VExprExpressionHandle vexpr_expression_mk_octal_number(std::string s);
VExprExpressionHandle vexpr_expression_mk_decimal_number(std::string s);
VExprExpressionHandle vexpr_expression_mk_hex_number(std::string s);

VExprExpressionHandle vexpr_expression_mk_single_identifier(std::string identifier, size_t size = 1);
VExprExpressionHandle vexpr_expression_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprExpressionHandle vexpr_expression_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);

VExprExpressionHandle vexpr_expression_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect);
VExprExpressionHandle vexpr_expression_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect);
VExprExpressionHandle vexpr_expression_mk_select(VExprIdentifierHandle pIdentifier, const std::vector<VExprSelectHandle> & vecSelect);


VExprExpressionHandle vexpr_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
VExprExpressionHandle vexpr_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
VExprExpressionHandle vexpr_expression_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr);

VExprExpressionHandle vexpr_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr);
VExprExpressionHandle vexpr_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr);


VExprExpressionHandle vexpr_expression_mk_unary(UnaryOpType opType, VExprPrimaryHandle pPrimary);
VExprExpressionHandle vexpr_expression_mk_binary(VExprExpressionHandle pFst, BinaryOpType opType, VExprExpressionHandle pSnd);
VExprExpressionHandle vexpr_expression_mk_ternary(VExprExpressionHandle pIf, VExprExpressionHandle pThen, VExprExpressionHandle pElse);

VExprExpressionHandle vexpr_expression_mk_true();
VExprExpressionHandle vexpr_expression_mk_false();

class VExprExpression : public VExprEventInterface {
    VExprExpressionInterfaceHandle _pInterface;

    VExprPrimaryHandle _pPrimary;
    VExprUnaryHandle _pUnary;
    VExprBinaryHandle _pBinary;
    VExprTernaryHandle _pTernary;
    VExprBoolHandle _pBool;

public:
    VExprExpression(VExprPrimaryHandle pPrimary);
    VExprExpression(VExprUnaryHandle pUnary);
    VExprExpression(VExprBinaryHandle pBinary);
    VExprExpression(VExprTernaryHandle pTernary);
    VExprExpression(VExprBoolHandle pBool);

    VExprPrimaryHandle getPrimaryHandle() const;
    VExprUnaryHandle getUnaryHandle() const;
    VExprBinaryHandle getBinaryHandle() const;
    VExprTernaryHandle getTernaryHandle() const;
    VExprBoolHandle getBoolHandle() const;

    std::string getString() const;
    size_t getSize() const;

    VExprExpressionHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprNetLvalueHandle toNetLvalueHandle() const;
    VExprConstantExpressionHandle toConstantExpressionHandle() const;
};

class VExprUnary : public VExprExpressionInterface {
    UnaryOpType _opType;
    VExprPrimaryHandle _pPrimary;
public:
    VExprUnary(UnaryOpType opType, VExprPrimaryHandle pPrimary);
    
    VExprPrimaryHandle getPrimaryHandle() const;
    UnaryOpType getOpType() const;

    std::string getString() const;
    size_t getSize() const;

    VExprUnaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprConstantUnaryHandle toConstantUnaryHandle() const;
private:
    std::string getOpTypeSymbol() const;
};

class VExprBinary : public VExprExpressionInterface {
    VExprExpressionHandle _pExprFst;
    BinaryOpType _opType;
    VExprExpressionHandle _pExprSnd;
public:
    VExprBinary(VExprExpressionHandle pExprFst, BinaryOpType opType, VExprExpressionHandle pExprSnd);

    VExprExpressionHandle getFst() const;
    VExprExpressionHandle getSnd() const;
    BinaryOpType getOpType() const;

    std::string getString() const;
    size_t getSize() const;
    VExprBinaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprConstantBinaryHandle toConstantBinaryHandle() const;
private:
    std::string getOpTypeSymbol() const;
};

class VExprTernary : public VExprExpressionInterface {
    VExprExpressionHandle _pExprIf;
    VExprExpressionHandle _pExprThen;
    VExprExpressionHandle _pExprElse;
public:
    VExprTernary(VExprExpressionHandle pExprIf, VExprExpressionHandle pExprThen, VExprExpressionHandle pExprElse);

    VExprExpressionHandle getIf() const;
    VExprExpressionHandle getThen() const;
    VExprExpressionHandle getElse() const;

    std::string getString() const;
    size_t getSize() const;
    VExprTernaryHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprConstantTernaryHandle toConstantTernaryHandle() const;
};


#endif // VEXPR_EXPRESSION_H
