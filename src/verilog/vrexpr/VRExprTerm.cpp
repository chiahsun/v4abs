#include "VRExprTerm.h"
#include "VRExprExpression.h"
    
VRExprTerm::VRExprTerm(VRExprExpression expr)
  : _pExpr(VRExprExpressionHandle(VRExprExpression(expr)))
  { }
    
std::string VRExprTerm::toString() const
  { return _pExpr->toString(); }

VRExprTermManager::VRExprTermManager()
  { }
    
VRExprTermManager::WddNodeHandle VRExprTermManager::addExpr(VRExprExpression expr)
  { return _wddManager.addTerm(VRExprTermHandle(VRExprTerm(expr))); }
    
VRExprTermManager::WddNodeHandle VRExprTermManager::ite(WddNodeHandle pIf, WddNodeHandle pThen, WddNodeHandle pElse)
  { return _wddManager.ite(pIf, pThen, pElse); }

VRExprTermManager::WddNodeHandle VRExprTermManager::ite(VRExprExpression eIf, VRExprExpression eThen, VRExprExpression eElse) {
    return ite(
             _wddManager.findTerm(VRExprTermHandle(VRExprTerm(eIf)))
           , _wddManager.findTerm(VRExprTermHandle(VRExprTerm(eThen)))
           , _wddManager.findTerm(VRExprTermHandle(VRExprTerm(eElse)))
           );
}
    
bool VRExprTerm::operator < (const VRExprTerm & rhs) const { 
    return (*_pExpr) < (*rhs._pExpr); 
}
