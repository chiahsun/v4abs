#ifndef VEXPR_MODULE_ITEM_DECLARATION_INTERFACE_H
#define VEXPR_MODULE_ITEM_DECLARATION_INTERFACE_H

#include <string>
#include "nstl/shared_ptr/SharedPtr.h"

class VExprModuleItemDeclarationInterface;
typedef SharedPtr<VExprModuleItemDeclarationInterface> VExprModuleItemDeclarationInterfaceHandle;

class VExprModuleItemDeclarationInterface {
public:
    virtual ~VExprModuleItemDeclarationInterface() {}
    virtual std::string getString() const = 0;
};

#endif // VEXPR_MODULE_ITEM_DECLARATION_INTERFACE_H
