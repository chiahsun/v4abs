#include "VExprProceduralContinuousAssignment.h"
#include "Indent.h"

VExprProceduralContinuousAssignment::VExprProceduralContinuousAssignment(VExprRegAssignmentHandle pRegAssignment)
  : _pRegAssignment(pRegAssignment)
  { }

VExprRegAssignmentHandle& VExprProceduralContinuousAssignment::getRegAssignment()
  { return _pRegAssignment; }

const VExprRegAssignmentHandle& VExprProceduralContinuousAssignment::getRegAssignment() const
  { return _pRegAssignment; }

std::string VExprProceduralContinuousAssignment::getString() const
  { return getString(0); }

  std::string VExprProceduralContinuousAssignment::getString(unsigned int indentLevel) const
  { return indent(indentLevel) + _pRegAssignment->getString(); }
    
