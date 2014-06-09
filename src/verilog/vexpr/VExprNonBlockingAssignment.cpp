#include "VExprNonBlockingAssignment.h"
#include "Indent.h"
#include "VExprStatement.h"
#include "VExprStatementOrNull.h"


VExprNonBlockingAssignmentHandle vexpr_non_blocking_assignment_mk(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr) {
    return VExprNonBlockingAssignmentHandle(VExprNonBlockingAssignment(pRegLvalue, pExpr));
}

VExprNonBlockingAssignment::VExprNonBlockingAssignment(VExprRegLvalueHandle pRegLvalue, VExprExpressionHandle pExpr)
  : _pRegLvalue(pRegLvalue)
  , _pExpr(pExpr)
  { }

VExprRegLvalueHandle VExprNonBlockingAssignment::getRegLvalueHandle() const
  { return _pRegLvalue; }

VExprExpressionHandle VExprNonBlockingAssignment::getExpressionHandle() const
  { return _pExpr; }

std::string VExprNonBlockingAssignment::getString() const 
  { return getString(0); }
std::string VExprNonBlockingAssignment::getString(unsigned int indentLevel) const {
    return indent(indentLevel) + getRegLvalueHandle()->getString()
         + " <= "
         + getExpressionHandle()->getString();
}
    
VExprStatementHandle VExprNonBlockingAssignment::toStatementHandle() const {
    return VExprStatementHandle(VExprStatement(VExprNonBlockingAssignmentHandle(*this)));
}
    
VExprStatementOrNullHandle VExprNonBlockingAssignment::toStatementOrNullHandle() const {
    return VExprStatementOrNullHandle(VExprStatementOrNull(toStatementHandle()));
}
    
VExprNonBlockingAssignmentHandle VExprNonBlockingAssignment::flatten(VExprIdentifierHandle pInstName) const {
    return VExprNonBlockingAssignmentHandle(VExprNonBlockingAssignment(
                getRegLvalueHandle()->flatten(pInstName)
              , getExpressionHandle()->flatten(pInstName)
            ));
}
    
VExprNonBlockingAssignmentHandle VExprNonBlockingAssignment::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprNonBlockingAssignmentHandle(VExprNonBlockingAssignment(
                getRegLvalueHandle()->substitute(pDst, hashSrc)
              , getExpressionHandle()->substitute(pDst, hashSrc)
            ));
}
