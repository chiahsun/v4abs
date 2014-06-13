#include "VRExprTerm.h"

    
VRExprTerm::VRExprTerm(VRExprExpression expr)
  : _expr(expr)
  { }
    
std::string VRExprTerm::toString() const
  { return _expr.toString(); }

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
