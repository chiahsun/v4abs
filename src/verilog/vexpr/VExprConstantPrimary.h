#ifndef VEXPR_CONSTANT_PRIMARY_H
#define VEXPR_CONSTANT_PRIMARY_H

#include "VExprTypes.h"

#include "VExprNumber.h"
#include "VExprIdentifier.h"
#include "VExprConcatenation.h"
#include "VExprMultipleConcatenation.h"
#include "VExprConstantExpressionInterface.h"


VExprConstantPrimaryHandle vexpr_constant_primary_mk_unsigned_number(unsigned int num);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_binary_number(std::string s);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_octal_number(std::string s);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_decimal_number(std::string s);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_hex_number(std::string s);

VExprConstantPrimaryHandle vexpr_constant_primary_mk_single_identifier(std::string identifier, size_t size = 1);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);



VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr);

VExprConstantPrimaryHandle vexpr_constant_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr);
VExprConstantPrimaryHandle vexpr_constant_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr);


class VExprConstantPrimary : public VExprConstantExpressionInterface {
    VExprConstantPrimaryInterfaceHandle _pInterface;

    VExprNumberHandle _pNumber;
    VExprIdentifierHandle _pIdentifier;
    VExprConcatenationHandle _pConcatenation;
    VExprMultipleConcatenationHandle _pMultipleConcatenation;
public:
    VExprConstantPrimary(VExprNumberHandle pNumber);
    VExprConstantPrimary(VExprIdentifierHandle pIdentifier);
    VExprConstantPrimary(VExprConcatenationHandle pConcatenation);
    VExprConstantPrimary(VExprMultipleConcatenationHandle pMultipleConcatenation);
     
    VExprNumberHandle getNumberHandle() const;
    VExprIdentifierHandle getIdentifierHandle() const;
    VExprConcatenationHandle getConcatenationHandle() const;
    VExprMultipleConcatenationHandle getMultipleConcatenationHandle() const;

    std::string getString() const;
    size_t getSize() const;
};

#endif // VEXPR_CONSTANT_PRIMARY_H
