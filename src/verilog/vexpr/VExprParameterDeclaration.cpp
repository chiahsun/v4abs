#include "VExprParameterDeclaration.h"
#include "nstl/for_each/ForEach.h"

VExprParameterDeclaration::VExprParameterDeclaration()
  { }
    
VExprParameterDeclaration::VExprParameterDeclaration(const std::vector<VExprParamAssignmentHandle> & vecParamAssignment)
  : _vecParaAssignment(vecParamAssignment)
  { }

std::vector<VExprParamAssignmentHandle>& VExprParameterDeclaration::getParaAssignmentHandleContainer()
  { return _vecParaAssignment; }

const std::vector<VExprParamAssignmentHandle>& VExprParameterDeclaration::getParaAssignmentHandleContainer() const
  { return _vecParaAssignment; }

void VExprParameterDeclaration::push_back(VExprParamAssignmentHandle pParaAssignment)
  { _vecParaAssignment.push_back(pParaAssignment); }

std::string VExprParameterDeclaration::getString() const {
    std::string s;
    CONST_FOR_EACH(x, getParaAssignmentHandleContainer()) {
    s += ("parameter " + x->getString() + ";\n");
}
    return s;
}
    
VExprParamAssignment::VExprParamAssignment(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpression)
  : _pIdentifier(pIdentifier)
  , _pExpression(pExpression)
  { }

VExprIdentifierHandle& VExprParamAssignment::getIdentifierHandle() 
  { return _pIdentifier; }

VExprExpressionHandle& VExprParamAssignment::getExpressionHandle()
  { return _pExpression; }
    
const VExprIdentifierHandle& VExprParamAssignment::getIdentifierHandle() const
  { return _pIdentifier; }
    
const VExprExpressionHandle& VExprParamAssignment::getExpressionHandle() const 
  { return _pExpression; }

std::string VExprParamAssignment::getString() const
  { return getIdentifierHandle()->getString() + " = " + getExpressionHandle()->getString(); }
