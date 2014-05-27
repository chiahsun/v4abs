#ifndef VEXPR_REGISTER_NAME_H
#define VEXPR_REGISTER_NAME_H

#include "VExprIdentifier.h"
#include "VExprRange.h"

class VExprRegisterName {
    VExprIdentifierHandle _pIdentifier;
    std::vector<VExprRangeHandle> _vecRange;

public:
    VExprRegisterName(VExprIdentifierHandle pIdentifier);
    VExprRegisterName(VExprIdentifierHandle pIdentifier, VExprRangeHandle pRange);
    VExprRegisterName(VExprIdentifierHandle pIdentifier, const std::vector<VExprRangeHandle> & vecRange);
    
    VExprIdentifierHandle& getIdentifierHandle();
    std::vector<VExprRangeHandle>& getRangeHandleContainer();

    const VExprIdentifierHandle& getIdentifierHandle() const;
    const std::vector<VExprRangeHandle>& getRangeHandleContainer() const;

    void addRange(VExprRangeHandle pRange);
    std::string getString() const;
};

#endif // VEXPR_REGISTER_NAME_H
