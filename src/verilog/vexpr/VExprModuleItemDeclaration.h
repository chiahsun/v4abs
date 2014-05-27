#ifndef MODULE_ITEM_DECLARATION_H
#define MODULE_ITEM_DECLARATION_H


#include "VExprModuleItemDeclarationInterface.h"
#include "VExprParameterDeclaration.h"
#include "VExprInputDeclaration.h"
#include "VExprOutputDeclaration.h"
#include "VExprInoutDeclaration.h"
#include "VExprNetDeclaration.h"
#include "VExprRegDeclaration.h"
#include "VExprIntegerDeclaration.h"

class VExprModuleItemDeclaration {
    VExprModuleItemDeclarationInterfaceHandle _pInterface;

    VExprParameterDeclarationHandle _pParameterDeclaration;
    VExprInputDeclarationHandle _pInputDeclaration;
    VExprOutputDeclarationHandle _pOutputDeclaration;
    VExprInoutDeclarationHandle _pInoutDeclaration;
    VExprNetDeclarationHandle _pNetDeclarartion;
    VExprRegDeclarationHandle _pRegDeclaration;
    VExprIntegerDeclarationHandle _pIntegerDeclaration;
public:
    VExprModuleItemDeclaration(VExprParameterDeclarationHandle pParameterDeclaration);
    VExprModuleItemDeclaration(VExprInputDeclarationHandle pInputDeclaration);
    VExprModuleItemDeclaration(VExprOutputDeclarationHandle pOutputDeclaration);
    VExprModuleItemDeclaration(VExprInoutDeclarationHandle pInoutDeclaration);
    VExprModuleItemDeclaration(VExprNetDeclarationHandle pNetDeclaration);
    VExprModuleItemDeclaration(VExprRegDeclarationHandle pRegDeclaration);
    VExprModuleItemDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration);

    const VExprParameterDeclarationHandle& getParameterDeclarationHandle() const;
    const VExprInputDeclarationHandle& getInputDeclarationHandle() const;
    const VExprOutputDeclarationHandle& getOutputDeclarationHandle() const;
    const VExprInoutDeclarationHandle& getInoutDeclarationHandle() const;
    const VExprNetDeclarationHandle& getNetDeclarationHandle() const;
    const VExprRegDeclarationHandle& getRegDeclarationHandle() const;
    const VExprIntegerDeclarationHandle& getIntegerDeclarationHandle() const;
    
    VExprParameterDeclarationHandle& getParameterDeclarationHandle();
    VExprInputDeclarationHandle& getInputDeclarationHandle();
    VExprOutputDeclarationHandle& getOutputDeclarationHandle();
    VExprInoutDeclarationHandle& getInoutDeclarationHandle();
    VExprNetDeclarationHandle& getNetDeclarationHandle();
    VExprRegDeclarationHandle& getRegDeclarationHandle();
    VExprIntegerDeclarationHandle& getIntegerDeclarationHandle();


    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

#endif // MODULE_ITEM_DECLARATION_H
