#ifndef VEXPR_REG_DECLARATION_H
#define VEXPR_REG_DECLARATION_H

#include "VExprRange.h"
#include "VExprRegisterName.h"
#include "VExprIdentifier.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprRegDecl;

class VExprRegDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprRegDeclHandle> _vecRegDecl;
public:
    VExprRegDeclaration(const std::vector<VExprRegDeclHandle> & vecRegDecl);

    const std::vector<VExprRegDeclHandle>& getContainer() const;
    std::vector<VExprRegDeclHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

};

class VExprRegDecl {
    VExprRangeHandle _pRange;
    VExprRegisterNameHandle _pRegisterName;

public:
    VExprRegDecl(VExprRegisterNameHandle pRegisterName);
    VExprRegDecl(VExprRangeHandle pRange, VExprRegisterNameHandle pRegisterName);


    VExprRangeHandle& getRangeHandle();
    VExprRegisterNameHandle& getRegisterNameHandle();
    
    const VExprRangeHandle& getRangeHandle() const;
    const VExprRegisterNameHandle& getRegisterNameHandle() const;

    std::string getString() const;
};

#endif // VEXPR_REG_DECLARATION_H
