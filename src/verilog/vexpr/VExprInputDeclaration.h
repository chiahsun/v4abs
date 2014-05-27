#ifndef VEXPR_INPUT_DECLARATION_H
#define VEXPR_INPUT_DECLARATION_H

#include "VExprPortDeclaration.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprInputDecl;

class VExprInputDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprInputDeclHandle> _vecInputDecl;
public:
    VExprInputDeclaration(const std::vector<VExprInputDeclHandle> & vecInputDecl);

    const std::vector<VExprInputDeclHandle>& getContainer() const;
    std::vector<VExprInputDeclHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

class VExprInputDecl {
    VExprPortDeclarationHandle _pPortDeclaration;
public:
    VExprInputDecl(VExprPortDeclarationHandle pPortDeclaration);

    VExprPortDeclarationHandle& getPortDeclarationHandle();
    const VExprPortDeclarationHandle& getPortDeclarationHandle() const;

    std::string getString() const;

};

#endif // VEXPR_INPUT_DECLARATION_H
