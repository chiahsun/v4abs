#include "VExprContinuousAssignment.h"

VExprContinuousAssignmentHandle vexpr_continuous_assignment_mk(VExprNetAssignmentHandle pNetAssignment) {
    return VExprContinuousAssignmentHandle(VExprContinuousAssignment(pNetAssignment));
}

VExprContinuousAssignmentHandle vexpr_continuous_assignment_mk(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr) {
    return vexpr_continuous_assignment_mk(VExprNetAssignmentHandle(VExprNetAssignment(pNetLvalue, pExpr)));
}

VExprContinuousAssignment::VExprContinuousAssignment() { }
    
VExprContinuousAssignment::VExprContinuousAssignment(VExprNetAssignmentHandle pNetAssignment) {
    push_back(pNetAssignment);
}

VExprContinuousAssignment::VExprContinuousAssignment(const std::vector<VExprNetAssignmentHandle>& vecNetAssignment)
  : _vecNetAssign(vecNetAssignment)
  { }

void VExprContinuousAssignment::push_back(VExprNetAssignmentHandle pNetAssignment) {
    _vecNetAssign.push_back(pNetAssignment);
}

unsigned int VExprContinuousAssignment::getNetAssignSize() const
  { return _vecNetAssign.size(); }
    
VExprNetAssignmentHandle VExprContinuousAssignment::getNetAssign(unsigned int pos) const {
    assert(pos < getNetAssignSize());
    return _vecNetAssign[pos];
}

std::string VExprContinuousAssignment::getString() const {
    std::string s;
    for (unsigned int i = 0; i < getNetAssignSize(); ++i) {
        if (i != 0)
            s += "\n";

        s += getNetAssign(i)->getString();
    }
    return s;
}
