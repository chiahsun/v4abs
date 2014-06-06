#include "VExprRegAssignment.h"

    VExprRegAssignment::VExprRegAssignment(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpression)
  : _pRegLvalue(pRegLvalue)
  , _pExpression(pExpression)
  { }

VExprRegLvalueHandle& VExprRegAssignment::getRegLvalueHandle()
  { return _pRegLvalue; }
    
VExprExpressionHandle& VExprRegAssignment::getExpressionHandle()
  { return _pExpression; }

const VExprRegLvalueHandle& VExprRegAssignment::getRegLvalueHandle() const
  { return _pRegLvalue; }

const VExprExpressionHandle& VExprRegAssignment::getExpressionHandle() const
  { return _pExpression; }

// Here followes from:
//   even it reg assignment 
//   in always(*)
//       reg_assignment
//   or for(reg_assignment;; reg_assignment)
std::string VExprRegAssignment::getString() const
  { return getRegLvalueHandle()->getString() + " = " + getExpressionHandle()->getString(); }
    
VExprRegAssignmentHandle VExprRegAssignment::flatten(VExprIdentifierHandle pInstName) const {
    return VExprRegAssignmentHandle(VExprRegAssignment(getRegLvalueHandle()->flatten(pInstName), getExpressionHandle()->flatten(pInstName)));
}
