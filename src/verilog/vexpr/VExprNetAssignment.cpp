#include "VExprNetAssignment.h"
#include "nstl/hash/HashFunction.h"

VExprNetAssignmentHandle vexpr_net_assignment_mk(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr) {
    return VExprNetAssignmentHandle(VExprNetAssignment(pNetLvalue, pExpr));
}

VExprNetAssignment::VExprNetAssignment(VExprNetLvalueHandle pNetLvalue, VExprExpressionHandle pExpr)
  : _pNetLvalue(pNetLvalue)
  , _pExpr(pExpr)
  { }

VExprNetLvalueHandle VExprNetAssignment::getNetLvalueHandle() const
  { return _pNetLvalue; }

VExprExpressionHandle VExprNetAssignment::getExpressionHandle() const
  { return _pExpr; }

std::string VExprNetAssignment::getString() const {
    return "assign " + getNetLvalueHandle()->getString()
         + "=" + getExpressionHandle()->getString() + ";\n";
}
    
VExprNetAssignmentHandle VExprNetAssignment::flatten(VExprIdentifierHandle pInstName) const {
    return VExprNetAssignmentHandle(VExprNetAssignment(
                getNetLvalueHandle()->flatten(pInstName)
              , getExpressionHandle()->flatten(pInstName)
            ));
}
    
VExprNetAssignmentHandle VExprNetAssignment::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprNetAssignmentHandle(VExprNetAssignment(
                getNetLvalueHandle()->substitute(pDst, hashSrc)
              , getExpressionHandle()->substitute(pDst, hashSrc)
            ));
}

int VExprNetAssignment::hashFunction() const
  { return HashFunction<std::string>::hashFunction(getString()); }
