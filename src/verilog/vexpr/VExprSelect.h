#ifndef VEXPR_SELECT_H
#define VEXPR_SELECT_H

#include "nstl/shared_ptr/SharedPtr.h"

#include "VExprTypes.h"
#include "VExprSelectInterface.h"
#include "VExprRangeSelect.h"


class VExprSelect {
    VExprSelectInterfaceHandle _pInterface;

    VExprRangeSelectHandle _pRangeSelect;
    VExprBitSelectHandle _pBitSelect;
public:
    VExprSelect(VExprRangeSelectHandle pRangeSelect);
    VExprSelect(VExprBitSelectHandle pBitSelect);

    VExprRangeSelectHandle getRangeSelectHandle() const;
    VExprBitSelectHandle getBitSelectHandle() const;
    
    std::string getString() const;
    size_t getSize() const;

    VExprSelectHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_SELECT_H

