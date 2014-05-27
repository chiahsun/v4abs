#ifndef VEXPR_OUTPUT_DECLARATION_H
#define VEXPR_OUTPUT_DECLARATION_H

#include "VExprPortDeclaration.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprOutputDecl;

class VExprOutputDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprOutputDeclHandle> _vecOutputDecl;
public:
    VExprOutputDeclaration(const std::vector<VExprOutputDeclHandle> & vecOutputDecl);

    const std::vector<VExprOutputDeclHandle>& getContainer() const;
    std::vector<VExprOutputDeclHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

};

class VExprOutputDecl {
    VExprPortDeclarationHandle _pPortDeclaration;
public:
    VExprOutputDecl(VExprPortDeclarationHandle pPortDeclaration);

    VExprPortDeclarationHandle& getPortDeclarationHandle();
    const VExprPortDeclarationHandle& getPortDeclarationHandle() const;

    std::string getString() const;
};

#endif // VEXPR_OUTPUT_DECLARATION_H
