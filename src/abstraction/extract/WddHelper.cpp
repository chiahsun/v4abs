#include "WddHelper.h"

static const bool verbose_make_vrexpr_expression_from_pexpr_bool_expression = false;
#if 0
VRExprExpression makeVRExprExpressionFromWddNodeHandleMux(VRExprTermManager termManager, VRExprTermManager::WddNodeHandle pWddNode) {

    if (pWddNode->getTermHandle().valid()) {
        if (pWddNode->getBddNodeHandle()->getPosHandle()->getBool())
            makeIdentifier(pWddNode->getTermHandle()->toString());
        else
            makeUnaryExpression(UNARY_NOT, makeIdentifier(pWddNode->getTermHandle()->toString()));
    }

    int curLevelId = pWddNode->getBddNodeHandle()->getCurDecisionLevel();
    if (curLevelId == 0) {
        if (pWddNode->getBddNodeHandle()->getBool())
            return makeIdentifier("true");
        else
            return makeIdentifier("false");
    }

    VRExprTermManager::WddNodeHandle pTerm = termManager.getWddManager().getTermHandleFromId(curLevelId);
    std::string curLevelName = pTerm->toString();
    VRExprExpression curExpr = makeVRExprExpressionFromWddNodeHandleMux(pTerm);
    
    WddNodeHandle pPos = getPosHandle(termManager.getWddManager());
    WddNodeHandle pNeg = getNegHandle(termManager.getWddManager());
    VRExprExpression posExpr = makeVRExprExpressionFromWddNodeHandle(pPos);
    VRExprExpression negExpr = makeVRExprExpressionFromWddNodeHandle(pNeg);
    std::string posString = posExpr->toString();
    std::string negString = negExpr->toString();

    // ite(a, 1, b) = a + b
    // ite(a, 0, b) = !ab
    if (posString == "true") {
        return makeBinaryExpression(curExpr, BINARY_LOGICAL_OR, negExpr);
    } else if (posString == "false") {
        return makeBinaryExpression(makeUnaryExpression(UNARY_NOT, curExpr), BINARY_LOGICAL_AND, negExpr);
    }

    // ite(a, b, 0) = ab
    // ite(a, b, 1) = !a + b
    if (negString == "true") {
        return makeBinaryExpression(makeUnaryExpression(UNARY_NOT, curExpr), BINARY_LOGICAL_OR, posExpr);
    } else if (negString == "false") {
        return makeBinaryExpression(curExpr, BINARY_LOGICAL_AND, posExpr);
    }

    return VRExprIte(curExpr, posExpr, negExpr); 
}
#endif

VRExprPrimary makeVRExprPrimaryFromPExprBoolExpression(PExprBoolExpressionHandle pBoolExpression) {
    if (verbose_make_vrexpr_expression_from_pexpr_bool_expression)
        LOG(INFO) << "In primary : " << pBoolExpression->toString();
    if (pBoolExpression->getOp() == PExprBoolExpression::IDENTIFIER) {
        return makeIdentifier(pBoolExpression->getName());
    } else if (pBoolExpression->getOp() == PExprBoolExpression::CONSTANT) {
        // TODO check if ok not to use makeNumber
        return makeIdentifier(pBoolExpression->toString());
    }
    LOG(ERROR) << "Fail to handle : " << pBoolExpression->toString();
    assert(0);
}

VRExprExpression makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpressionHandle pBoolExpression) {
    if (verbose_make_vrexpr_expression_from_pexpr_bool_expression)
        LOG(INFO) << "In expression : " << pBoolExpression->toString();
    if (pBoolExpression->getOp() == PExprBoolExpression::IDENTIFIER) {
        return makeIdentifier(pBoolExpression->getName());
    } else if (pBoolExpression->getOp() == PExprBoolExpression::CONSTANT) {
        // TODO check if ok not to use makeNumber
        return makeIdentifier(pBoolExpression->toString());
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_NOT) {
          PExprBoolExpressionHandle inner = pBoolExpression->getFst();
//        VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(pBoolExpression->getFst());
//        VRExprPrimary fst = makeVRExprPrimaryFromPExprBoolExpression(pBoolExpression->getFst());
          // !a
          if (inner->getOp() == PExprBoolExpression::IDENTIFIER || inner->getOp() == PExprBoolExpression::CONSTANT) {
              return makeUnaryExpression(UNARY_NOT, makeVRExprPrimaryFromPExprBoolExpression(inner));
          }
          PExprBoolExpressionHandle innerFst = pBoolExpression->getFst()->getFst();
          PExprBoolExpressionHandle innerSnd = pBoolExpression->getFst()->getSnd();
          // !(a && b) = !a || !b
          if (inner->getOp() == PExprBoolExpression::LOGICAL_AND) {
              VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpression::makeUnaryNotHandle(innerFst));
              VRExprExpression snd = makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpression::makeUnaryNotHandle(innerSnd));
              return makeBinaryExpression(fst, BINARY_LOGICAL_OR, snd);
          }
          // !(a || b) = !a && !b
          if (inner->getOp() == PExprBoolExpression::LOGICAL_OR) {
              VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpression::makeUnaryNotHandle(innerFst));
              VRExprExpression snd = makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpression::makeUnaryNotHandle(innerSnd));
              return makeBinaryExpression(fst, BINARY_LOGICAL_AND, snd);
          }
          // !(a ^ b) = a == b
          if (inner->getOp() == PExprBoolExpression::LOGICAL_XOR) {
              VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(innerFst);
              VRExprExpression snd = makeVRExprExpressionFromPExprBoolExpression(innerSnd);
              return makeBinaryExpression(fst, BINARY_EQ, snd);
          }
          // !(a == b) = a ^ b
          if (inner->getOp() == PExprBoolExpression::LOGICAL_XOR) {
              VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(innerFst);
              VRExprExpression snd = makeVRExprExpressionFromPExprBoolExpression(innerSnd);
              return makeBinaryExpression(fst, BINARY_NEQ, snd);
          }
    } else {
        VRExprExpression fst = makeVRExprExpressionFromPExprBoolExpression(pBoolExpression->getFst());
        VRExprExpression snd = makeVRExprExpressionFromPExprBoolExpression(pBoolExpression->getSnd());
        if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_AND) {
            return makeBinaryExpression(fst, BINARY_LOGICAL_AND, snd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_OR) {
            return makeBinaryExpression(fst, BINARY_LOGICAL_OR, snd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_XOR) {
            return makeBinaryExpression(fst, BINARY_NEQ, snd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_EQUAL) {
        // TODO check if ok to use binary eq
            return makeBinaryExpression(fst, BINARY_EQ, snd);
        } 
    }
    LOG(ERROR) << "Fail to handle : " << pBoolExpression->toString();
    assert(0);
}

VRExprTermManager::WddNodeHandle makeTermHandleFromPExprBoolExpression(VRExprTermManager termManager, PExprBoolExpressionHandle pBoolExpression) {
    if (pBoolExpression->getOp() == PExprBoolExpression::IDENTIFIER) {
        return termManager.addExpr(makeIdentifier(pBoolExpression->getName()));
    } else if (pBoolExpression->getOp() == PExprBoolExpression::CONSTANT) {
        return termManager.addExpr(makeIdentifier(pBoolExpression->toString()));
    } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_NOT) {
        VRExprTermManager::WddNodeHandle pFst = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getFst());
        return termManager.makeNeg(pFst);
    } else {
        if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_AND) {
            VRExprTermManager::WddNodeHandle pFst = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getFst());
            VRExprTermManager::WddNodeHandle pSnd = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getSnd());
            return termManager.makeAnd(pFst, pSnd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_OR) {
            VRExprTermManager::WddNodeHandle pFst = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getFst());
            VRExprTermManager::WddNodeHandle pSnd = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getSnd());
            return termManager.makeOr(pFst, pSnd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_XOR) {
            VRExprTermManager::WddNodeHandle pFst = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getFst());
            VRExprTermManager::WddNodeHandle pSnd = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getSnd());
            return termManager.makeNeq(pFst, pSnd);
        } else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_EQUAL) {
            VRExprTermManager::WddNodeHandle pFst = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getFst());
            VRExprTermManager::WddNodeHandle pSnd = makeTermHandleFromPExprBoolExpression(termManager, pBoolExpression->getSnd());
            return termManager.makeEq(pFst, pSnd);
        } 
    }

    assert(0);
}

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


