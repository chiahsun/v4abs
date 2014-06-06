#include "VExprContinuousAssignment.h"
#include "nstl/for_each/ForEach.h"

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
    
const std::vector<VExprNetAssignmentHandle>& VExprContinuousAssignment::getNetAssignmentContainer() const {
    return _vecNetAssign;
}

std::string VExprContinuousAssignment::getString() const {
    std::string s;
    for (unsigned int i = 0; i < getNetAssignSize(); ++i) {
        s += getNetAssign(i)->getString();
    }
    return s;
}
    
VExprContinuousAssignmentHandle VExprContinuousAssignment::flatten(VExprIdentifierHandle pInstName) const {
    std::vector<VExprNetAssignmentHandle> vecFlatNetAssignment;

    CONST_FOR_EACH(pNetAssignment, getNetAssignmentContainer()) {
        vecFlatNetAssignment.push_back(pNetAssignment->flatten(pInstName));
    }

    return VExprContinuousAssignmentHandle(VExprContinuousAssignment(vecFlatNetAssignment));
}
