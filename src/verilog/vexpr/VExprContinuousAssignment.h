#ifndef VEXPR_CONTINUOUS_ASSIGNMENT_H
#define VEXPR_CONTINUOUS_ASSIGNMENT_H

#include "VExprNetAssignment.h"

VExprContinuousAssignmentHandle vexpr_continuous_assignment_mk(VExprNetAssignmentHandle pNetAssignment);
VExprContinuousAssignmentHandle vexpr_continuous_assignment_mk(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr);

class VExprContinuousAssignment {
    std::vector<VExprNetAssignmentHandle> _vecNetAssign;
public:
    VExprContinuousAssignment();
    VExprContinuousAssignment(VExprNetAssignmentHandle pNetAssignment);
    VExprContinuousAssignment(const std::vector<VExprNetAssignmentHandle>& vecNetAssignment);

    void push_back(VExprNetAssignmentHandle pNetAssignment);

    unsigned int getNetAssignSize() const;
    VExprNetAssignmentHandle getNetAssign(unsigned int pos) const;

    const std::vector<VExprNetAssignmentHandle>& getNetAssignmentContainer() const;

    std::string getString() const;

    VExprContinuousAssignmentHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprContinuousAssignmentHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

#endif // VEXPR_CONTINUOUS_ASSIGNMENT_H
