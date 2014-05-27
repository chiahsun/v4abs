#ifndef VEXPR_PORT_DECLARATION_H
#define VEXPR_PORT_DECLARATION_H

#include "VExprRange.h"

class VExprPortDeclaration {
    VExprRangeHandle _pRange;
    VExprIdentifierHandle _pIdentifier;
public:
    VExprPortDeclaration(VExprRangeHandle pRange, VExprIdentifierHandle pIdentifier);
    VExprPortDeclaration(VExprIdentifierHandle pIdentifier);

    VExprRangeHandle& getRangeHandle();
    VExprIdentifierHandle& getIdentifierHandle();

    const VExprRangeHandle& getRangeHandle() const;
    const VExprIdentifierHandle& getIdentifierHandle() const;

    std::string getString() const;
};

#endif // VEXPR_PORT_DECLARATION_H
