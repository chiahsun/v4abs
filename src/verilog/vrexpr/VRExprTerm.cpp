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
    
VRExprTermManager::WddNodeHandle VRExprTermManager::makeAnd(WddNodeHandle pFst, WddNodeHandle pSnd)
  { return _wddManager.makeAnd(pFst, pSnd); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeOr(WddNodeHandle pFst, WddNodeHandle pSnd)
  { return _wddManager.makeOr(pFst, pSnd); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeImply(WddNodeHandle pFst, WddNodeHandle pSnd)
  { return _wddManager.makeImply(pFst, pSnd); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeNeg(WddNodeHandle pNode)
  { return _wddManager.makeNeg(pNode); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeBasicBlockIfThen(WddNodeHandle pIf, WddNodeHandle pThen)
  { return _wddManager.makeBasicBlockIfThen(pIf, pThen); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeBasicBlockIfElse(WddNodeHandle pIf, WddNodeHandle pElse)
  { return _wddManager.makeBasicBlockIfElse(pIf, pElse); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeBasicBlockIfThenElse(WddNodeHandle pIf, WddNodeHandle pThen, WddNodeHandle pElse)
  { return _wddManager.makeBasicBlockIfThenElse(pIf, pThen, pElse); }

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
