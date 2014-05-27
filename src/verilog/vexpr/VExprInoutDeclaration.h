#ifndef VEXPR_INOUT_DECLARATION_H
#define VEXPR_INOUT_DECLARATION_H

#include "VExprPortDeclaration.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprInoutDecl;

class VExprInoutDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprInoutDeclHandle> _vecInoutDecl;
public:
    VExprInoutDeclaration(const std::vector<VExprInoutDeclHandle> & vecInoutDecl);

    const std::vector<VExprInoutDeclHandle>& getContainer() const;
    std::vector<VExprInoutDeclHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

class VExprInoutDecl {
    VExprPortDeclarationHandle _pPortDeclaration;
public:
    VExprInoutDecl(VExprPortDeclarationHandle pPortDeclaration);

    VExprPortDeclarationHandle& getPortDeclarationHandle();
    const VExprPortDeclarationHandle& getPortDeclarationHandle() const;

    std::string getString() const;
};

#endif // VEXPR_INOUT_DECLARATION_H
