#ifndef VEXPR_NET_DECLARATION_H
#define VEXPR_NET_DECLARATION_H

#include "VExprRange.h"
#include "VExprIdentifier.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprNetDecl;

class VExprNetDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprNetDeclHandle> _vecNetDecl;
public:
    VExprNetDeclaration(const std::vector<VExprNetDeclHandle> & vecNetDecl);

    const std::vector<VExprNetDeclHandle>& getContainer() const;
    std::vector<VExprNetDeclHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};


class VExprNetDecl {
    VExprRangeHandle _pRange;
    VExprIdentifierHandle _pIdentifier;

public:
    VExprNetDecl(VExprIdentifierHandle pIdentifier);
    VExprNetDecl(VExprRangeHandle pRange, VExprIdentifierHandle pIdentifier);

    VExprRangeHandle& getRangeHandle();
    VExprIdentifierHandle& getIdentifierHandle();
    
    const VExprRangeHandle& getRangeHandle() const;
    const VExprIdentifierHandle& getIdentifierHandle() const;

    std::string getString() const;
};

#endif // VEXPR_NET_DECLARATION_H
