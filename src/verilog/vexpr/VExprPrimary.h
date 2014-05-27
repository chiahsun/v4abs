#ifndef VEXPR_PRIMARY_H
#define VEXPR_PRIMARY_H

#include "nstl/shared_ptr/SharedPtr.h"

#include "VExprTypes.h"
#include "VExprExpressionInterface.h"
#include "VExprPrimaryInterface.h"
#include "VExprNumber.h"
#include "VExprIdentifier.h"
#include "VExprSelectIdentifier.h"
#include "VExprConcatenation.h"
#include "VExprMultipleConcatenation.h"



VExprPrimaryHandle vexpr_primary_mk_unsigned_number(unsigned int unsignedNumber);
VExprPrimaryHandle vexpr_primary_mk_binary_number(std::string s);
VExprPrimaryHandle vexpr_primary_mk_octal_number(std::string s);
VExprPrimaryHandle vexpr_primary_mk_decimal_number(std::string s);
VExprPrimaryHandle vexpr_primary_mk_hex_number(std::string s);

VExprPrimaryHandle vexpr_primary_mk_single_identifier(std::string identifier, size_t size = 1);
VExprPrimaryHandle vexpr_primary_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprPrimaryHandle vexpr_primary_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);

VExprPrimaryHandle vexpr_primary_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect);
VExprPrimaryHandle vexpr_primary_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect);
VExprPrimaryHandle vexpr_primary_mk_select(VExprIdentifierHandle pIdentifier, const std::vector<VExprSelectHandle> & vecSelect);


VExprPrimaryHandle vexpr_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
VExprPrimaryHandle vexpr_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
VExprPrimaryHandle vexpr_primary_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr);

VExprPrimaryHandle vexpr_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr);
VExprPrimaryHandle vexpr_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr);


class VExprPrimary : public VExprExpressionInterface {
    VExprPrimaryInterfaceHandle _pInterface;

    VExprNumberHandle _pNumber;
    VExprIdentifierHandle _pIdentifier;
    VExprSelectIdentifierHandle _pSelectIdentifier;
    VExprConcatenationHandle _pConcatenation;
    VExprMultipleConcatenationHandle _pMultipleConcatenation;
public:
    VExprPrimary(VExprNumberHandle pNumber);
    VExprPrimary(VExprIdentifierHandle pIdentifier);
    VExprPrimary(VExprSelectIdentifierHandle pSelectIdentifier);
    VExprPrimary(VExprConcatenationHandle pConcatenation);
    VExprPrimary(VExprMultipleConcatenationHandle pMultipleConcatenation);

    VExprNumberHandle getNumberHandle() const;
    VExprIdentifierHandle getIdentifierHandle() const;
    VExprSelectIdentifierHandle getSelectIdentifierHandle() const;
    VExprConcatenationHandle getConcatenationHandle() const;
    VExprMultipleConcatenationHandle getMultipleConcatenationHandle() const;

    size_t getSize() const;
    std::string getString() const;
};


#endif // VEXPR_PRIMARY_H
