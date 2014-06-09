#ifndef VEXPR_REG_LVALUE_H
#define VEXPR_REG_LVALUE_H

#include "VExprIdentifier.h"
#include "VExprSelectIdentifier.h"
#include "VExprConcatenation.h"
#include "VExprRegLvalueInterface.h"

VExprRegLvalueHandle vexpr_reg_lvalue_mk_identifier(VExprIdentifierHandle pIdentifier);
VExprRegLvalueHandle vexpr_reg_lvalue_mk_single_identifier(std::string identifier, size_t size = 1);
VExprRegLvalueHandle vexpr_reg_lvalue_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprRegLvalueHandle vexpr_reg_lvalue_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);




VExprRegLvalueHandle vexpr_reg_lvalue_mk_select_identifer(VExprSelectIdentifierHandle pSelectIdentifier);
VExprRegLvalueHandle vexpr_reg_lvalue_mk_concatenation(VExprConcatenationHandle pConcatenation);

class VExprRegLvalue {
    VExprRegLvalueInterfaceHandle _pInterface;

    VExprIdentifierHandle _pIdentifier;
    VExprSelectIdentifierHandle _pSelectIdentifier;
    VExprConcatenationHandle _pConcatenation;
public:
    VExprRegLvalue(VExprIdentifierHandle pIdentifier);
    VExprRegLvalue(VExprSelectIdentifierHandle pSelectIdentifier);
    VExprRegLvalue(VExprConcatenationHandle pConcatenation);

    VExprIdentifierHandle getIdentifierHandle() const;
    VExprSelectIdentifierHandle getSelectIdentifierHandle() const;
    VExprConcatenationHandle getConcatenationHandle() const;

    std::string getString() const;
    VExprRegLvalueHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprRegLvalueHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

#endif // VEXPR_REG_LVALUE_H
