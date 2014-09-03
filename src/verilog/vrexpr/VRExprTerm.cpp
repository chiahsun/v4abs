#include "VRExprTerm.h"
#include "VRExprExpression.h"

template <class T>
void swap(T & x, T & y) {
    T tmp = x;
    x = y;
    y = tmp;
}

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
    
VRExprTermManager::WddNodeHandle VRExprTermManager::makeEq(WddNodeHandle pFst, WddNodeHandle pSnd)
  { return _wddManager.makeEq(pFst, pSnd); }

VRExprTermManager::WddNodeHandle VRExprTermManager::makeNeq(WddNodeHandle pFst, WddNodeHandle pSnd)
  { return _wddManager.makeNeq(pFst, pSnd); }


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
    
VRExprExpression VRExprTermManager::toVRExprExpression(WddNodeHandle pWddNode) {
    if (pWddNode->getTermHandle().valid()) {
        if (pWddNode->getBddNodeHandle()->getPosHandle()->getBool())
            return makeIdentifier(pWddNode->getTermHandle()->toString());
        else
            return makeUnaryExpression(UNARY_NOT, makeIdentifier(pWddNode->getTermHandle()->toString()));
    }

    int curLevelId = pWddNode->getBddNodeHandle()->getCurDecisionLevel();
    if (curLevelId == 0) {
        if (pWddNode->getBddNodeHandle()->getBool())
            return makeIdentifier("true");
        else
            return makeIdentifier("false");
    }

    VRExprTermManager::WddNodeHandle pCur = _wddManager.makeWddNode(_wddManager.getTermHandleFromId(curLevelId));
    std::string curLevelName = pCur->toString(_wddManager);
    VRExprExpression curExpr = toVRExprExpression(pCur);
    VRExprExpression negatedCurExpr = makeUnaryExpression(UNARY_NOT, toVRExprPrimary(pCur));
    if (!pCur->getBddNodeHandle()->getPosHandle()->getBool())
        swap(curExpr, negatedCurExpr);

    WddNodeHandle pPos = pWddNode->getPosHandle(_wddManager);
    WddNodeHandle pNeg = pWddNode->getNegHandle(_wddManager);

    VRExprExpression posExpr = toVRExprExpression(pPos);
    VRExprExpression negExpr = toVRExprExpression(pNeg);

    std::string posString = posExpr.toString();
    std::string negString = negExpr.toString();

    // ite(a, 1, b) = a + b
    // ite(a, 0, b) = !ab
    if (posString == "true") {
        return makeBinaryExpression(curExpr, BINARY_LOGICAL_OR, negExpr);
    } else if (posString == "false") {
        return makeBinaryExpression(negatedCurExpr, BINARY_LOGICAL_AND, negExpr);
    }

    // ite(a, b, 0) = ab
    // ite(a, b, 1) = !a + b
    if (negString == "true") {
        return makeBinaryExpression(negatedCurExpr, BINARY_LOGICAL_OR, posExpr);
    } else if (negString == "false") {
        return makeBinaryExpression(curExpr, BINARY_LOGICAL_AND, posExpr);
    }

    return VRExprIte(curExpr, posExpr, negExpr);

}
    
VRExprPrimary VRExprTermManager::toVRExprPrimary(WddNodeHandle pWddNode) {
    assert(pWddNode->getTermHandle().valid());
    return makeIdentifier(pWddNode->getTermHandle()->toString());
}
