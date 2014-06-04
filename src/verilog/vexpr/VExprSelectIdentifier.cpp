#include "VExprSelectIdentifier.h"
#include "exception/Exception.h"
#include "nstl/for_each/ForEach.h"

VExprSelectIdentifierHandle vexpr_select_identifier_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect) {
    return VExprSelectIdentifierHandle(VExprSelectIdentifier(pIdentifier, pBitSelect));
}

VExprSelectIdentifierHandle vexpr_select_identifier_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect) {
    return VExprSelectIdentifierHandle(VExprSelectIdentifier(pIdentifier, pRangeSelect));
}


VExprSelectIdentifier::VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect) {
    _pIdentifier = pIdentifier;
    _vecSelect.push_back(VExprSelectHandle(VExprSelect(pBitSelect)));
}
    
VExprSelectIdentifier::VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect) {
    _pIdentifier = pIdentifier;
    _vecSelect.push_back(VExprSelectHandle(VExprSelect(pRangeSelect)));
}

VExprSelectIdentifier::VExprSelectIdentifier(VExprIdentifierHandle pIdentifier, std::vector<VExprSelectHandle> vecSelect) {
    _pIdentifier = pIdentifier;
    _vecSelect = vecSelect;
}

VExprIdentifierHandle VExprSelectIdentifier::getIdentifierHandle() const 
  { return _pIdentifier; }
    
unsigned int VExprSelectIdentifier::getSelectSize() const
  { return _vecSelect.size(); }
    
VExprSelectHandle VExprSelectIdentifier::getSelect(unsigned int pos) const { 
    assert(pos < getSelectSize());
    return _vecSelect[pos]; 
}

size_t VExprSelectIdentifier::getSize() const {
    throw NotImplementedException();
}

std::string VExprSelectIdentifier::getString() const {
    std::string s;
    s = getIdentifierHandle()->getString();
    for (unsigned int i = 0; i < getSelectSize(); ++i)
        s += getSelect(i)->getString();
    return s;
}
    
VExprSelectIdentifierHandle VExprSelectIdentifier::flatten(VExprIdentifierHandle pInstName) const {
    VExprIdentifierHandle pFlatIdentifier = _pIdentifier->flatten(pInstName);
    std::vector<VExprSelectHandle> vecFlatSelect;
    CONST_FOR_EACH(pSelect, _vecSelect)
        vecFlatSelect.push_back(pSelect->flatten(pInstName));
    return VExprSelectIdentifierHandle(VExprSelectIdentifier(pFlatIdentifier, vecFlatSelect));
}
