#ifndef VREXPR_TERM_H
#define VREXPR_TERM_H

#include "VRExprTypes.h"
#include "formal/wdd/WddManager.h"
#include "formal/wdd/WddTermInterface.h"
#include "nstl/shared_ptr/SharedPtrE.h"

class VRExprTerm;
class VRExprTermManager;

class VRExprTermManager {
public:
    typedef SharedPtrE<VRExprTerm> VRExprTermHandle;
    typedef WddManager<VRExprTermHandle>::WddNodeHandle WddNodeHandle;
private:
    WddManager<VRExprTermHandle> _wddManager;
public:
    VRExprTermManager();
    WddNodeHandle addExpr(VRExprExpression expr);
    WddNodeHandle ite(VRExprExpression eIf, VRExprExpression eThen, VRExprExpression eElse);

    WddNodeHandle ite(WddNodeHandle pIf, WddNodeHandle pThen, WddNodeHandle pElse);
    WddNodeHandle makeAnd(WddNodeHandle pFst, WddNodeHandle pSnd);
    WddNodeHandle makeOr(WddNodeHandle pFst, WddNodeHandle pSnd);
    WddNodeHandle makeImply(WddNodeHandle pFst, WddNodeHandle pSnd);
    WddNodeHandle makeNeg(WddNodeHandle pNode);
    WddNodeHandle makeEq(WddNodeHandle pFst, WddNodeHandle pSnd);
    WddNodeHandle makeNeq(WddNodeHandle pFst, WddNodeHandle pSnd);

    WddNodeHandle makeBasicBlockIfThen(WddNodeHandle pIf, WddNodeHandle pThen);
    WddNodeHandle makeBasicBlockIfElse(WddNodeHandle pIf, WddNodeHandle pElse);
    WddNodeHandle makeBasicBlockIfThenElse(WddNodeHandle pIf, WddNodeHandle pThen, WddNodeHandle pElse);

    const WddManager<VRExprTermHandle> & getWddManager() const
      { return _wddManager; }

    std::string stringOfNode(const WddNodeHandle & pNode) const {
        return _wddManager.stringOfNode(pNode);
    }
};

class VRExprTerm : public WddTermInterface {
    typedef SharedPtrE<VRExprExpression> VRExprExpressionHandle;
    VRExprExpressionHandle _pExpr;
public:
    VRExprTerm(VRExprExpression expr);
    std::string toString() const;
    bool operator < (const VRExprTerm & rhs) const;
};


#endif // VREXPR_TERM_H
