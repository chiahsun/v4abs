#ifndef VEXPR_SELECT_IDENTIFIER_H
#define VEXPR_SELECT_IDENTIFIER_H

#include "VExprTypes.h"
#include "VExprPrimaryInterface.h"
#include "VExprRegLvalueInterface.h"
#include "VExprSelect.h"

VExprSelectIdentifierHandle vexpr_select_identifier_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect);
VExprSelectIdentifierHandle vexpr_select_identifier_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect);


class VExprSelectIdentifier : public VExprPrimaryInterface, public VExprRegLvalueInterface {
    VExprIdentifierHandle _pIdentifier;

    std::vector<VExprSelectHandle> _vecSelect;
public:
    VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect);
    VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect);
    VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, std::vector<VExprSelectHandle> vecSelect);

    const std::vector<VExprSelectHandle> & getSelectContainer() const;

    VExprIdentifierHandle getIdentifierHandle() const;
    unsigned int getSelectSize() const;
    VExprSelectHandle getSelect(unsigned int pos) const;

    size_t getSize() const;
    std::string getString() const;

    VExprSelectIdentifierHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprSelectIdentifierHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;

    VExprExpressionHandle toExpressionHandle() const;
};



#endif // VEXPR_SELECT_IDENTIFIER_H
