#ifndef WDD_HELPER_H
#define WDD_HELPER_H

#include "formal/wdd/Term.h"
#include "formal/wdd/WddManager.h"

WddManager<TermHandle>::WddNodeHandle makeWddHandleFromPExprBoolExpression(WddManager<TermHandle> & wddManager, PExprBoolExpressionHandle pBoolExpression) {
    if (pBoolExpression->getOp() == PExprBoolExpression::IDENTIFIER) {
        return wddManager.addTerm(TermHandle(Term(pBoolExpression->getName())));
    } else if (pBoolExpression->getOp() == PExprBoolExpression::CONSTANT) {
        return wddManager.addTerm(TermHandle(Term(pBoolExpression->toString())));
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_AND) {
        WddManager<TermHandle>::WddNodeHandle pFst = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getFst());
        WddManager<TermHandle>::WddNodeHandle pSnd = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getSnd());
        return wddManager.makeAnd(pFst, pSnd);
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_OR) {
        WddManager<TermHandle>::WddNodeHandle pFst = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getFst());
        WddManager<TermHandle>::WddNodeHandle pSnd = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getSnd());
        return wddManager.makeOr(pFst, pSnd);
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_XOR) {
        WddManager<TermHandle>::WddNodeHandle pFst = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getFst());
        WddManager<TermHandle>::WddNodeHandle pSnd = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getSnd());
        return wddManager.makeNeq(pFst, pSnd);
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_EQUAL) {
        WddManager<TermHandle>::WddNodeHandle pFst = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getFst());
        WddManager<TermHandle>::WddNodeHandle pSnd = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getSnd());
        return wddManager.makeEq(pFst, pSnd);
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_NOT) {
        WddManager<TermHandle>::WddNodeHandle pFst = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression->getFst());
        return wddManager.makeNeg(pFst);
    } else {
        assert(0);
    }
}


// TODO WddTermHandle to expression

#endif // WDD_HELPER_H
