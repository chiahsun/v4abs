#ifndef VEXPR_INTEGER_DECLARATION_H
#define VEXPR_INTEGER_DECLARATION_H

#include "VExprRegisterName.h"
#include "VExprModuleItemDeclarationInterface.h"

class VExprIntegerDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprRegisterNameHandle> _vecRegisterName;
public:
    VExprIntegerDeclaration(const std::vector<VExprRegisterNameHandle> & vecRegisterName);

    const std::vector<VExprRegisterNameHandle>& getContainer() const;
    std::vector<VExprRegisterNameHandle>& getContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

#endif 
