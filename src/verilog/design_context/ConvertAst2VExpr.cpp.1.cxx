#include "ConvertAst2VExpr.h"

VExprUnsignedNumberHandle ConvertAst2VExpr::convert(const AstUnsignedNumberHandle & pAstUnsignedNumber) {
    unsigned int val = unsigned_int_of_string(pAstUnsignedNumber->unsigned_number());
    return VExprUnsignedNumberHandle(VExprUnsignedNumber(val));
}

VExprBinaryNumberHandle ConvertAst2VExpr::convert(const AstBinaryNumberHandle & pBinaryNumber) {
    return VExprBinaryNumberHandle(VExprBinaryNumber(pBinaryNumber->binary_number()));
}

VExprOctalNumberHandle ConvertAst2VExpr::convert(const AstOctalNumberHandle & pOctalNumber) {
    return VExprOctalNumberHandle(VExprOctalNumber(pOctalNumber->octal_number()));
}

VExprDecimalNumberHandle ConvertAst2VExpr::convert(const AstDecimalNumberHandle & pDecimalNumber) {
    return VExprDecimalNumberHandle(VExprDecimalNumber(pDecimalNumber->decimal_number()));
}

VExprHexNumberHandle ConvertAst2VExpr::convert(const AstHeximalNumberHandle & pHexNumber) {
    return VExprHexNumberHandle(VExprHexNumber(pHexNumber->heximal_number()));
}

VExprNumberHandle ConvertAst2VExpr::convert(const AstNumberHandle & pNumber) {
    if (pNumber->unsigned_number().valid()) {
        VExprUnsignedNumberHandle pUnsignedNumber = ConvertAst2VExpr::convert(pNumber->unsigned_number());
        return VExprNumberHandle(VExprNumber(pUnsignedNumber));
    } else if (pNumber->binary_number().valid()) {
        VExprBinaryNumberHandle pBinaryNumber = ConvertAst2VExpr::convert(pNumber->binary_number());
        return VExprNumberHandle(VExprNumber(pBinaryNumber));
    } else if (pNumber->octal_number().valid()) {
        VExprOctalNumberHandle pOctalNumber = ConvertAst2VExpr::convert(pNumber->octal_number());
        return VExprNumberHandle(VExprNumber(pOctalNumber));
    } else if (pNumber->decimal_number().valid()) {
        VExprDecimalNumberHandle pDecimalNumber = ConvertAst2VExpr::convert(pNumber->decimal_number());
        return VExprNumberHandle(VExprNumber(pDecimalNumber));
    } else if (pNumber->heximal_number().valid()) {
        VExprHexNumberHandle pHeximalNumber = ConvertAst2VExpr::convert(pNumber->heximal_number());
        return VExprNumberHandle(VExprNumber(pHeximalNumber));
    }
    assert(0);
}

VExprSingleIdentifierHandle ConvertAst2VExpr::convert(const AstSimpleIdentifierHandle & pAstSimpleIdentifier) {
    return VExprSingleIdentifierHandle(VExprSingleIdentifier(pAstSimpleIdentifier->simple_identifier()));
}

VExprSingleIdentifierHandle ConvertAst2VExpr::convert(const AstSingleIdentifierHandle & pAstSingleIdentifier) {
    return ConvertAst2VExpr::convert(pAstSingleIdentifier->simple_identifier());
}

VExprHierIdentifierHandle ConvertAst2VExpr::convert(const AstMultiIdentifierHandle & pAstMultiIdentifier) {
    std::vector<AstSingleIdentifierHandle> vecSingleIdentifier;
    AstSingleIdentifierHandle pAstSingleIdentifier = pAstMultiIdentifier->element(0)._pSingleIdentifier0;
    vecSingleIdentifier.push_back(pAstSingleIdentifier);

    CONST_FOR_EACH(elem, pAstMultiIdentifier->element(0)._pZeroOrMoreDotSingleIdentifier1->container()) {
        vecSingleIdentifier.push_back(elem._pSingleIdentifier);
    }

    std::vector<std::string> vecString;

    CONST_FOR_EACH(x, vecSingleIdentifier) {
        vecString.push_back(x->simple_identifier()->simple_identifier());
    }

    return VExprHierIdentifierHandle(VExprHierIdentifier(vecString));

}

VExprIdentifierHandle ConvertAst2VExpr::convert(const AstIdentifierHandle & pAstIdentifier) {
    if (pAstIdentifier->single_identifier().valid()) {
        VExprSingleIdentifierHandle pSingleIdentifier = ConvertAst2VExpr::convert(pAstIdentifier->single_identifier());
        return VExprIdentifierHandle(VExprIdentifier(pSingleIdentifier));
    } else if (pAstIdentifier->multi_identifier().valid()) {
        VExprHierIdentifierHandle pHierIdentifier = ConvertAst2VExpr::convert(pAstIdentifier->multi_identifier());
        return VExprIdentifierHandle(VExprIdentifierHandle(pHierIdentifier));
    }
    assert(0);
}

VExprPrimaryHandle ConvertAst2VExpr::convert(const AstPrimaryHandle & pAstPrimary) {
    if (pAstPrimary->select_identifier().valid()) {
        VExprSelectIdentifierHandle pSelectIdentifier =
            ConvertAst2VExpr::convert(pAstPrimary->select_identifier());
        return VExprPrimaryHandle(VExprPrimary(pSelectIdentifier));
    } else if (pAstPrimary->identifier().valid()) {
        VExprIdentifierHandle pIdentifier = ConvertAst2VExpr::convert(pAstPrimary->identifier());
        return VExprPrimaryHandle(VExprPrimary(pIdentifier));
    } else if (pAstPrimary->number().valid()) {
        VExprNumberHandle pNumber = ConvertAst2VExpr::convert(pAstPrimary->number());
        return VExprPrimaryHandle(VExprPrimary(pNumber));
    } else if (pAstPrimary->concatenation().valid()) {
        VExprConcatenationHandle pConcatenation =
            ConvertAst2VExpr::convert(pAstPrimary->concatenation());
        return VExprPrimaryHandle(VExprPrimary(pConcatenation));
    } else if (pAstPrimary->multiple_concatenation().valid()) {
        VExprMultipleConcatenationHandle pMultipleConcatenation =
            ConvertAst2VExpr::convert(pAstPrimary->multiple_concatenation());
        return VExprPrimaryHandle(VExprPrimary(pMultipleConcatenation));
    }
    assert(0);
}
    
VExprUnaryHandle ConvertAst2VExpr::convert(const AstUnaryExpressionHandle & pAstUnaryExpression) {
    AstUnaryOperatorHandle pAstUnaryOperator =
        pAstUnaryExpression->element(0)._pUnaryOperator0;
    AstPrimaryHandle pAstPrimary =
        pAstUnaryExpression->element(0)._pPrimary1;

    VExprPrimaryHandle pPrimary =
        ConvertAst2VExpr::convert(pAstPrimary);

    if (pAstUnaryOperator->unary_operator_plus().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_PLUS, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_minus().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_MINUS, pPrimary));

    } else if (pAstUnaryOperator->unary_operator_not().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_NOT, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_NEG, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_and().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_AND, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_and().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_NEG_AND, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_or().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_OR, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_or().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_NEG_OR, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_xor().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_XOR, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_xor().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_NEG_XOR, pPrimary));
    } else if (pAstUnaryOperator->unary_operator_xor_neg().valid()) {
        return VExprUnaryHandle(VExprUnary(UNARY_XOR_NEG, pPrimary));
    }

    assert(0);
}
    
VExprExpressionHandle ConvertAst2VExpr::convert(const AstExpressionHandle & pExpression) {
    if (pExpression->primary().valid()) {
        VExprPrimaryHandle pPrimary = 
            ConvertAst2VExpr::convert(pExpression->primary());
        return VExprExpressionHandle(VExprExpression(pPrimary));
    } else if (pExpression->unary_expression().valid()) {
        VExprUnaryHandle pUnary =
            ConvertAst2VExpr::convert(pExpression->unary_expression());
        return VExprExpressionHandle(VExprExpression(pUnary));
    } else if (pExpression->binary_expression().valid()) {
        VExprBinaryHandle pBinary =
            ConvertAst2VExpr::convert(pExpression->binary_expression());
        return VExprExpressionHandle(VExprExpression(pBinary));
    } else if (pExpression->braced_expression().valid()) {
        
        return ConvertAst2VExpr::convert(pExpression->braced_expression()->element(0)._pExpression0);
    } else if (pExpression->ternary_expression().valid()) {
        VExprTernaryHandle pTernary = 
            ConvertAst2VExpr::convert(pExpression->ternary_expression());
        return VExprExpressionHandle(VExprExpression(pTernary));
    }
    assert(0);
}

VExprBinaryHandle ConvertAst2VExpr::convert(const AstBinaryExpressionHandle & pAstBinaryExpression) {
    AstExpressionHandle pAstFst =
        pAstBinaryExpression->element(0)._pExpression0;
    AstBinaryOperatorHandle pAstBinaryOp =
        pAstBinaryExpression->element(0)._pBinaryOperator1;
    AstExpressionHandle pAstSnd =
        pAstBinaryExpression->element(0)._pExpression2;

    VExprExpressionHandle pFst =
        ConvertAst2VExpr::convert(pAstFst);
    VExprExpressionHandle pSnd =
        ConvertAst2VExpr::convert(pAstSnd);

    if (pAstBinaryOp->binary_operator_plus().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_PLUS, pSnd));
    } else if (pAstBinaryOp->binary_operator_minus().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_MINUS, pSnd));
    } else if (pAstBinaryOp->binary_operator_asterisk().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_MULT, pSnd));
    } else if (pAstBinaryOp->binary_operator_slash().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_DIV, pSnd));
    } else if (pAstBinaryOp->binary_operator_percent().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_MOD, pSnd));
    } else if (pAstBinaryOp->binary_operator_equal_equal().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_EQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_not_equal().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_NEQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_triple_equal().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_XEQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_not_equal_equal().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_XNEQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_and_and().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_LOGICAL_AND, pSnd));
    } else if (pAstBinaryOp->binary_operator_or_or().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_LOGICAL_OR, pSnd));
    } else if (pAstBinaryOp->binary_operator_lt().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_LT, pSnd));
    } else if (pAstBinaryOp->binary_operator_leq().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_LEQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_gt().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_GT, pSnd));
    } else if (pAstBinaryOp->binary_operator_geq().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_GEQ, pSnd));
    } else if (pAstBinaryOp->binary_operator_and().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_BITWISE_AND, pSnd));
    } else if (pAstBinaryOp->binary_operator_or().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_BITWISE_OR, pSnd));
    } else if (pAstBinaryOp->binary_operator_xor().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_BITWISE_XOR, pSnd));
    } else if (pAstBinaryOp->binary_operator_xor_neg().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_BITWISE_XOR_NEG, pSnd));
    } else if (pAstBinaryOp->binary_operator_neg_xor().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_BITWISE_NEG_XOR, pSnd));
    } else if (pAstBinaryOp->binary_operator_shr().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_SHIFT_RIGHT, pSnd));
    } else if (pAstBinaryOp->binary_operator_shl().valid()) {
        return VExprBinaryHandle(VExprBinary(pFst, BINARY_SHIFT_LEFT, pSnd));
    }

    assert(0);
}
    
VExprTernaryHandle ConvertAst2VExpr::convert(const AstTernaryExpressionHandle & pAstTernaryExpression) {
    VExprExpressionHandle pFst =
        ConvertAst2VExpr::convert(pAstTernaryExpression->element(0)._pExpression0);
    VExprExpressionHandle pSnd =
        ConvertAst2VExpr::convert(pAstTernaryExpression->element(0)._pExpression1);
    VExprExpressionHandle pTrd =
        ConvertAst2VExpr::convert(pAstTernaryExpression->element(0)._pExpression2);

    return VExprTernaryHandle(VExprTernary(pFst, pSnd, pTrd));
}
    
VExprBitSelectHandle ConvertAst2VExpr::convert(const AstBitSelectHandle & pBitSelect) {
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pBitSelect->element(0)._pExpression0);
    
    return VExprBitSelectHandle(VExprBitSelect(pExpression));
}
    
VExprRangeSelectHandle ConvertAst2VExpr::convert(const AstRangeSelectHandle & pRangeSelect) {
    VExprExpressionHandle pFst =
        ConvertAst2VExpr::convert(pRangeSelect->element(0)._pExpression0);
    VExprExpressionHandle pSnd =
        ConvertAst2VExpr::convert(pRangeSelect->element(0)._pExpression1);

    return VExprRangeSelectHandle(VExprRangeSelect(pFst, pSnd));
}
    
VExprSelectHandle ConvertAst2VExpr::convert(const AstSelectHandle & pSelect) {
    if (pSelect->range_select().valid()) {
        VExprRangeSelectHandle pRangeSelect =
            ConvertAst2VExpr::convert(pSelect->range_select());
        return VExprSelectHandle(VExprSelect(pRangeSelect));
    } else if (pSelect->bit_select().valid()) {
        VExprBitSelectHandle pBitSelect =
            ConvertAst2VExpr::convert(pSelect->bit_select());
        return VExprSelectHandle(VExprSelect(pBitSelect));
    }
    assert(0);
}
    
VExprSelectIdentifierHandle ConvertAst2VExpr::convert(const AstSelectIdentifierHandle & pAstSelectIdentifier) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstSelectIdentifier->element(0)._pIdentifier0);
    
    AstOneOrMoreSelectHandle pAstOneOrMoreSelect =
        pAstSelectIdentifier->element(0)._pOneOrMoreSelect1;

    std::vector<VExprSelectHandle> vecSelect;

    CONST_FOR_EACH(elem, pAstOneOrMoreSelect->container()) {
        VExprSelectHandle pSelect =
            ConvertAst2VExpr::convert(elem._pSelect0);
        vecSelect.push_back(pSelect);
    }

    return VExprSelectIdentifierHandle(VExprSelectIdentifier(pIdentifier, vecSelect));
}

VExprConcatenationHandle ConvertAst2VExpr::convert(const AstConcatenationHandle & pAstConcatenation) {
    std::vector<VExprExpressionHandle> vecExpression;
    VExprExpressionHandle pFst = ConvertAst2VExpr::convert(pAstConcatenation->element(0)._pExpression0);
    vecExpression.push_back(pFst);

    AstOneOrMoreCommaExpressionHandle pAstOneOrMoreCommaExpression =
        pAstConcatenation->element(0)._pOneOrMoreCommaExpression1;

    CONST_FOR_EACH(elem, pAstOneOrMoreCommaExpression->container()) {
        VExprExpressionHandle pExpr = ConvertAst2VExpr::convert(elem._pExpression0);
        vecExpression.push_back(pExpr);
    }

    return VExprConcatenationHandle(VExprConcatenation(vecExpression));

}
    
VExprMultipleConcatenationHandle ConvertAst2VExpr::convert(const AstMultipleConcatenationHandle & pAstMultipleConcatenation) {
    VExprExpressionHandle pRepeat =
        ConvertAst2VExpr::convert(pAstMultipleConcatenation->element(0)._pExpression0);

    std::vector<VExprExpressionHandle> vecExpression;

    VExprExpressionHandle pFst =
        ConvertAst2VExpr::convert(pAstMultipleConcatenation->element(0)._pExpression1);
    vecExpression.push_back(pFst);

    AstZeroOrMoreCommaExpressionHandle pAstZeroOrMoreCommaExpression =
        pAstMultipleConcatenation->element(0)._pZeroOrMoreCommaExpression2;

    CONST_FOR_EACH(elem, pAstZeroOrMoreCommaExpression->container()) {
        VExprExpressionHandle pExpression =
            ConvertAst2VExpr::convert(elem._pExpression);
        vecExpression.push_back(pExpression);
    }

    return VExprMultipleConcatenationHandle(VExprMultipleConcatenation(pRepeat, vecExpression));
}
    
VExprConstantPrimaryHandle ConvertAst2VExpr::convert(const AstConstantPrimaryHandle & pAstConstantPrimary) {
    if (pAstConstantPrimary->number().valid()) {
        VExprNumberHandle pNumber =
            ConvertAst2VExpr::convert(pAstConstantPrimary->number());
        return VExprConstantPrimaryHandle(VExprConstantPrimary(pNumber));
    } else if (pAstConstantPrimary->identifier().valid()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstConstantPrimary->identifier());
        return VExprConstantPrimaryHandle(VExprConstantPrimary(pIdentifier));
    } else if (pAstConstantPrimary->concatenation().valid()) {
        VExprConcatenationHandle pConcatenation =
            ConvertAst2VExpr::convert(pAstConstantPrimary->concatenation());
        return VExprConstantPrimaryHandle(VExprConstantPrimary(pConcatenation));
    } else if (pAstConstantPrimary->multiple_concatenation().valid()) {
        VExprMultipleConcatenationHandle pMultipleConcatenation =
            ConvertAst2VExpr::convert(pAstConstantPrimary->multiple_concatenation());
        return VExprConstantPrimaryHandle(VExprConstantPrimary(pMultipleConcatenation));
    }

    assert(0);
}
    
VExprConstantUnaryHandle ConvertAst2VExpr::convert(const AstUnaryConstantExpressionHandle & pAstUnaryConstantExpression) {
    AstUnaryOperatorHandle pAstUnaryOperator =
        pAstUnaryConstantExpression->element(0)._pUnaryOperator0;
    AstConstantPrimaryHandle pAstConstantPrimary =
        pAstUnaryConstantExpression->element(0)._pConstantPrimary1;

    VExprConstantPrimaryHandle pConstantPrimary =
        ConvertAst2VExpr::convert(pAstConstantPrimary);
    
    if (pAstUnaryOperator->unary_operator_plus().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_PLUS, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_minus().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_MINUS, pConstantPrimary));

    } else if (pAstUnaryOperator->unary_operator_not().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_NOT, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_NEG, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_and().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_AND, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_and().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_NEG_AND, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_or().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_OR, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_or().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_NEG_OR, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_xor().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_XOR, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_neg_xor().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_NEG_XOR, pConstantPrimary));
    } else if (pAstUnaryOperator->unary_operator_xor_neg().valid()) {
        return VExprConstantUnaryHandle(VExprConstantUnary(UNARY_XOR_NEG, pConstantPrimary));
    }

    assert(0);
}
    
VExprConstantBinaryHandle ConvertAst2VExpr::convert(const AstBinaryConstantExpressionHandle & pAstBinaryConstantExpression) {
    assert(0);
//    AstConstantE
}
    
VExprConstantExpressionHandle ConvertAst2VExpr::convert(const AstConstantExpressionHandle & pAstConstantExpression) {
    if (pAstConstantExpression->constant_primary().valid()) {
        VExprConstantPrimaryHandle pConstantPrimary = 
            ConvertAst2VExpr::convert(pAstConstantExpression->constant_primary());
        return VExprConstantExpressionHandle(VExprConstantExpression(pConstantPrimary));
    } else if (pAstConstantExpression->unary_constant_expression().valid()) {
        VExprConstantUnaryHandle pConstantUnary =
            ConvertAst2VExpr::convert(pAstConstantExpression->unary_constant_expression());
        return VExprConstantExpressionHandle(VExprConstantExpression(pConstantUnary));
    } else if (pAstConstantExpression->binary_constant_expression().valid()) {
        VExprConstantBinaryHandle pConstantBinary =
            ConvertAst2VExpr::convert(pAstConstantExpression->binary_constant_expression());
        return VExprConstantExpressionHandle(VExprConstantExpression(pConstantBinary));
    } else if (pAstConstantExpression->braced_constant_expression().valid()) {
        return ConvertAst2VExpr::convert(pAstConstantExpression->braced_constant_expression()->element(0)._pConstantExpression0);
    } else if (pAstConstantExpression->ternary_constant_expression().valid()) {
        VExprConstantTernaryHandle pConstantTernary =
            ConvertAst2VExpr::convert(pAstConstantExpression->ternary_constant_expression());
        return VExprConstantExpressionHandle(VExprConstantExpression(pConstantTernary));
    }
    assert(0);
}

VExprConstantTernaryHandle ConvertAst2VExpr::convert(const AstTernaryConstantExpressionHandle & pAstTernaryConstantExpression) {
    VExprConstantExpressionHandle pFst =
        ConvertAst2VExpr::convert(pAstTernaryConstantExpression->element(0)._pConstantExpression0);
    VExprConstantExpressionHandle pSnd =
        ConvertAst2VExpr::convert(pAstTernaryConstantExpression->element(0)._pConstantExpression1);
    VExprConstantExpressionHandle pTrd =
        ConvertAst2VExpr::convert(pAstTernaryConstantExpression->element(0)._pConstantExpression2);

    return VExprConstantTernaryHandle(VExprConstantTernary(pFst, pSnd, pTrd));
    
}
    
VExprRangeHandle ConvertAst2VExpr::convert(const AstRangeHandle & pRange) {
    VExprConstantExpressionHandle pFst =
        ConvertAst2VExpr::convert(pRange->element(0)._pConstantExpression0);
    VExprConstantExpressionHandle pSnd =
        ConvertAst2VExpr::convert(pRange->element(0)._pConstantExpression1);

    return VExprRangeHandle(VExprRange(pFst, pSnd));
}
    
VExprNetLvalueHandle ConvertAst2VExpr::convert(const AstNetLvalueHandle & pAstNetLvalue) {
    if (pAstNetLvalue->identifier().valid()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstNetLvalue->identifier());
        return VExprNetLvalueHandle(VExprNetLvalue(pIdentifier));
    } else if (pAstNetLvalue->net_lvalue_bit_select().valid()) {

        AstNetLvalueBitSelectHandle pAstNetLvalueBitSelect = pAstNetLvalue->net_lvalue_bit_select();

        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstNetLvalueBitSelect->element(0)._pIdentifier0);
        VExprExpressionHandle pExpression =
            ConvertAst2VExpr::convert(pAstNetLvalueBitSelect->element(0)._pExpression1);

        VExprNetLvalueBitSelectHandle pBitSelect =
            VExprNetLvalueBitSelectHandle(VExprNetLvalueBitSelect(pIdentifier, pExpression));
        return VExprNetLvalueHandle(VExprNetLvalue(pBitSelect));
    } else if (pAstNetLvalue->net_lvalue_range_select().valid())  {
        AstNetLvalueRangeSelectHandle pAstNetLvalueRangeSelect =
            pAstNetLvalue->net_lvalue_range_select();

        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstNetLvalueRangeSelect->element(0)._pIdentifier0);
        VExprConstantExpressionHandle pFst =
            ConvertAst2VExpr::convert(pAstNetLvalueRangeSelect->element(0)._pConstantExpression1);
        VExprConstantExpressionHandle pSnd =
            ConvertAst2VExpr::convert(pAstNetLvalueRangeSelect->element(1)._pConstantExpression2);

        VExprNetLvalueRangeSelectHandle pRangeSelect =
            VExprNetLvalueRangeSelectHandle(VExprNetLvalueRangeSelect(pIdentifier, pFst, pSnd));

        return VExprNetLvalueHandle(VExprNetLvalue(pRangeSelect));
    } else if (pAstNetLvalue->concatenation().valid()) {
        VExprConcatenationHandle pConcatenation =
            ConvertAst2VExpr::convert(pAstNetLvalue->concatenation());
        return VExprNetLvalueHandle(VExprNetLvalue(pConcatenation));
    }
    assert(0);
}
    
VExprNetAssignmentHandle ConvertAst2VExpr::convert(const AstNetAssignmentHandle & pAstNetAssignment) {
    VExprNetLvalueHandle pNetLvalue =
        ConvertAst2VExpr::convert(pAstNetAssignment->element(0)._pNetLvalue0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstNetAssignment->element(0)._pExpression1);

    return VExprNetAssignmentHandle(VExprNetAssignment(pNetLvalue, pExpression));
}
    
std::vector<VExprNetAssignmentHandle> ConvertAst2VExpr::convert(const AstListOfNetAssignmentsHandle & pAstListOfNetAssignment) {
    std::vector<VExprNetAssignmentHandle> vec;
    
    VExprNetAssignmentHandle pNetAssignment =
        ConvertAst2VExpr::convert(pAstListOfNetAssignment->element(0)._pNetAssignment0);
    vec.push_back(pNetAssignment);

    AstZeroOrMoreCommaNetAssignmentHandle pAstZeroOrMoreCommaNetAssignment = pAstListOfNetAssignment->element(0)._pZeroOrMoreCommaNetAssignment1;

    CONST_FOR_EACH(elem, pAstZeroOrMoreCommaNetAssignment->container()) {
        VExprNetAssignmentHandle p =
            ConvertAst2VExpr::convert(elem._pNetAssignment);
        vec.push_back(p);
    }
    return vec;
}
    
VExprContinuousAssignmentHandle ConvertAst2VExpr::convert(const AstContinuousAssignHandle & pAstContinuousAssign) {
    std::vector<VExprNetAssignmentHandle> vec =
        ConvertAst2VExpr::convert(pAstContinuousAssign->element(0)._pListOfNetAssignments1);
    return VExprContinuousAssignmentHandle(VExprContinuousAssignment(vec));
}
    
VExprRegLvalueHandle ConvertAst2VExpr::convert(const AstRegLvalueHandle & pAstRegLvalue) {

    if (pAstRegLvalue->identifier().valid()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstRegLvalue->identifier());
        return VExprRegLvalueHandle(VExprRegLvalue(pIdentifier));
    } else if (pAstRegLvalue->select_identifier().valid()) {
        VExprSelectIdentifierHandle pSelectIdentifier =
            ConvertAst2VExpr::convert(pAstRegLvalue->select_identifier());
        return VExprRegLvalueHandle(VExprRegLvalue(pSelectIdentifier));
    } else if (pAstRegLvalue->concatenation().valid()) {
        VExprConcatenationHandle pConcatenation =
            ConvertAst2VExpr::convert(pAstRegLvalue->concatenation());
        return VExprRegLvalueHandle(VExprRegLvalue(pConcatenation));
    }
    assert(0);
}
    
VExprBlockingAssignmentHandle ConvertAst2VExpr::convert(const AstBlockingAssignmentHandle & pAstBlockingAssignment) {
    VExprRegLvalueHandle pRegLvalue =
        ConvertAst2VExpr::convert(pAstBlockingAssignment->element(0)._pRegLvalue0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstBlockingAssignment->element(0)._pExpression1);
    return VExprBlockingAssignmentHandle(VExprBlockingAssignment(pRegLvalue, pExpression));
}

VExprNonBlockingAssignmentHandle ConvertAst2VExpr::convert(const AstNonBlockingAssignmentHandle & pAstNonBlockingAssignment) {
    VExprRegLvalueHandle pRegLvalue =
        ConvertAst2VExpr::convert(pAstNonBlockingAssignment->element(0)._pRegLvalue0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstNonBlockingAssignment->element(0)._pExpression1);

    return VExprNonBlockingAssignmentHandle(VExprNonBlockingAssignment(pRegLvalue, pExpression));
}
    
VExprStatementHandle ConvertAst2VExpr::convert(const AstStatementHandle & pAstStatement) {
    if (pAstStatement->blocking_assignment_semicolon().valid()) {
        AstBlockingAssignmentHandle pAstBlockingAssignment =
            pAstStatement->blocking_assignment_semicolon()->element(0)._pBlockingAssignment0;
        VExprBlockingAssignmentHandle pBlockingAssignment =
            ConvertAst2VExpr::convert(pAstBlockingAssignment);
        return VExprStatementHandle(VExprStatement(pBlockingAssignment));
    } else if (pAstStatement->non_blocking_assignment_semicolon().valid()) {
        AstNonBlockingAssignmentHandle pAstNonBlockingAssignment =
            pAstStatement->non_blocking_assignment_semicolon()->element(0)._pNonBlockingAssignment0;
        VExprNonBlockingAssignmentHandle pNonBlockingAssignment =
            ConvertAst2VExpr::convert(pAstNonBlockingAssignment);
        return VExprStatementHandle(VExprStatement(pNonBlockingAssignment));
    } else if (pAstStatement->procedural_continuous_assignment_semicolon().valid()) {
        VExprProceduralContinuousAssignmentHandle pProceduralContinuousAssignment = ConvertAst2VExpr::convert(pAstStatement->procedural_continuous_assignment_semicolon()->element(0)._pProceduralContinuousAssignment0);
        return VExprStatementHandle(VExprStatement(pProceduralContinuousAssignment));
    } else if (pAstStatement->procedural_timing_control_statement().valid()) {
        VExprEventStatementHandle pEventStatement =
            ConvertAst2VExpr::convert(pAstStatement->procedural_timing_control_statement());
        return VExprStatementHandle(VExprStatement(pEventStatement));
    } else if (pAstStatement->conditional_statement().valid()) {
        VExprConditionalStatementHandle pConditionalStatement =
            ConvertAst2VExpr::convert(pAstStatement->conditional_statement());
        return VExprStatementHandle(VExprStatement(pConditionalStatement));
    } else if (pAstStatement->case_statement().valid()) {
        VExprCaseStatementHandle pCaseStatement =
            ConvertAst2VExpr::convert(pAstStatement->case_statement());
        return VExprStatementHandle(VExprStatement(pCaseStatement));
    } else if (pAstStatement->loop_statement().valid()) {
        VExprLoopStatementHandle pLoopStatement =
            ConvertAst2VExpr::convert(pAstStatement->loop_statement());
        return VExprStatementHandle(VExprStatement(pLoopStatement));
    } else if (pAstStatement->seq_block().valid()) {
        VExprSeqBlockHandle pSeqBlock =
            ConvertAst2VExpr::convert(pAstStatement->seq_block());
        return VExprStatementHandle(VExprStatement(pSeqBlock));
    }

    assert(0);
}
    
VExprRegAssignmentHandle ConvertAst2VExpr::convert(const AstRegAssignmentHandle & pAstRegAssignment) {
    VExprRegLvalueHandle pRegLvalue =
        ConvertAst2VExpr::convert(pAstRegAssignment->element(0)._pRegLvalue0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstRegAssignment->element(0)._pExpression1);
    return VExprRegAssignmentHandle(VExprRegAssignment(pRegLvalue, pExpression));
}
    
VExprProceduralContinuousAssignmentHandle ConvertAst2VExpr::convert(const AstProceduralContinuousAssignmentHandle & pAstProceduralContinuousAssignment) {
    VExprRegAssignmentHandle pRegAssignment =
        ConvertAst2VExpr::convert(pAstProceduralContinuousAssignment->element(0)._pRegAssignment1);

    return VExprProceduralContinuousAssignmentHandle(VExprProceduralContinuousAssignment(pRegAssignment));
}
    
VExprStatementOrNullHandle ConvertAst2VExpr::convert(const AstStatementOrNullHandle & pAstStatementOrNull) {
    if (pAstStatementOrNull->statement().valid()) {
        VExprStatementHandle pStatement =
            ConvertAst2VExpr::convert(pAstStatementOrNull->statement());
        return vexpr_statement_or_null_mk_statement(pStatement);
    } else {
        return vexpr_statement_or_null_mk_null(); 
    }
    assert(0);
}
    
VExprStatementOrNullHandle ConvertAst2VExpr::convert(const AstElseStatementOrNullHandle & pAstElseStatementOrNull) {
    VExprStatementOrNullHandle pStatementOrNull =
        ConvertAst2VExpr::convert(pAstElseStatementOrNull->element(0)._pStatementOrNull1);
    return pStatementOrNull;
}
    
VExprStatementOrNullHandle ConvertAst2VExpr::convert(const AstZeroOrOneElseStatementOrNullHandle & pAstZeroOrOneElseStatementOrNull) {
    if (pAstZeroOrOneElseStatementOrNull->element_size() == 0) {
        return vexpr_statement_or_null_mk_null();
    } else {
        VExprStatementOrNullHandle pStatementOrNull =
            ConvertAst2VExpr::convert(pAstZeroOrOneElseStatementOrNull->element(0)._pElseStatementOrNull);
        return pStatementOrNull;
    }
    assert(0);
}
    
VExprConditionalStatementHandle ConvertAst2VExpr::convert(const AstConditionalStatementHandle & pAstConditionalStatement) {
    VExprExpressionHandle pIf =
        ConvertAst2VExpr::convert(pAstConditionalStatement->element(0)._pExpression1);
    VExprStatementOrNullHandle pThen =
        ConvertAst2VExpr::convert(pAstConditionalStatement->element(0)._pStatementOrNull2);

    VExprStatementOrNullHandle pElse =
        ConvertAst2VExpr::convert(pAstConditionalStatement->element(0)._pZeroOrOneElseStatementOrNull3);

    return VExprConditionalStatementHandle(VExprConditionalStatement(pIf, pThen, pElse));
}
    
VExprCaseItemHandle ConvertAst2VExpr::convert(const AstCaseItemHandle & pAstCaseItem) {
    if (pAstCaseItem->case_item_item().valid()) {
        AstCaseItemItemHandle pAstCaseItemItem =
            pAstCaseItem->case_item_item();

        std::vector<VExprExpressionHandle> vecExpression;
        VExprExpressionHandle pExpression =
            ConvertAst2VExpr::convert(pAstCaseItemItem->element(0)._pExpression0);

        vecExpression.push_back(pExpression);

        AstZeroOrMoreCommaExpressionHandle pAstZeroOrMoreCommaExpression = pAstCaseItemItem->element(0)._pZeroOrMoreCommaExpression1;
        CONST_FOR_EACH(elem, pAstZeroOrMoreCommaExpression->container()) {
            VExprExpressionHandle p =
                ConvertAst2VExpr::convert(elem._pExpression);
            vecExpression.push_back(p);
        }


        VExprStatementOrNullHandle pStatementOrNull =
            ConvertAst2VExpr::convert(pAstCaseItemItem->element(0)._pStatementOrNull2);

        return VExprCaseItemHandle(VExprCaseItem(vecExpression, pStatementOrNull));

    } else if (pAstCaseItem->case_item_default().valid()) {
        AstCaseItemDefaultHandle pAstCaseItemDefault =
            pAstCaseItem->case_item_default();
        VExprStatementOrNullHandle pStatementOrNull =
            ConvertAst2VExpr::convert(pAstCaseItemDefault->element(0)._pStatementOrNull1);
        return VExprCaseItemHandle(VExprCaseItem(pStatementOrNull));
    }
    assert(0);
}
    
VExprCaseStatementHandle ConvertAst2VExpr::convert(const AstCaseStatementHandle & pAstCaseStatement) {

    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstCaseStatement->element(0)._pExpression1);


    AstOneOrMoreCaseItemHandle pAstOneOrMoreCaseItem =
        pAstCaseStatement->element(0)._pOneOrMoreCaseItem2;

    std::vector<VExprCaseItemHandle> vecCaseItem;

    CONST_FOR_EACH(elem, pAstOneOrMoreCaseItem->container()) {
        VExprCaseItemHandle pCaseItem =
            ConvertAst2VExpr::convert(elem._pCaseItem0);
        vecCaseItem.push_back(pCaseItem);
    }


    return VExprCaseStatementHandle(VExprCaseStatement(pExpression, vecCaseItem));
}
    
VExprSeqBlockHandle ConvertAst2VExpr::convert(const AstSeqBlockHandle & pAstSeqBlock) {
    AstZeroOrMoreStatementHandle pAstZeroOrMoreStatement =
        pAstSeqBlock->element(0)._pZeroOrMoreStatement1;

    std::vector<VExprStatementHandle> vecStatement;
    CONST_FOR_EACH(elem, pAstZeroOrMoreStatement->container()) {
        VExprStatementHandle pStatement =
            ConvertAst2VExpr::convert(elem._pStatement);
        vecStatement.push_back(pStatement);
    }

    return VExprSeqBlockHandle(VExprSeqBlock(vecStatement));
}
    
VExprPosedgeEventHandle ConvertAst2VExpr::convert(const AstPosedgeExpressionHandle & pAstPosedgeExpression) {
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstPosedgeExpression->element(0)._pExpression1);
    return VExprPosedgeEventHandle(VExprPosedgeEvent(pExpression));
}

VExprNegedgeEventHandle ConvertAst2VExpr::convert(const AstNegedgeExpressionHandle & pAstNegedgeExpression) {
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstNegedgeExpression->element(0)._pExpression1);
    return VExprNegedgeEventHandle(VExprNegedgeEvent(pExpression));
}
    
    
VExprEventExpressionHandle ConvertAst2VExpr::convert(const AstEventExpressionHandle & pAstEventExpression) {
    if (pAstEventExpression->event_comma_event().valid()) {
        VExprEventExpressionHandle pFst =
            ConvertAst2VExpr::convert(pAstEventExpression->event_comma_event()->element(0)._pEventExpression0);
        VExprEventExpressionHandle pSnd =
            ConvertAst2VExpr::convert(pAstEventExpression->event_comma_event()->element(0)._pEventExpression1);
        return VExprEventExpressionHandle(VExprEventExpression(pFst, pSnd));
    } else if (pAstEventExpression->event_or_event().valid()) {
        VExprEventExpressionHandle pFst =
            ConvertAst2VExpr::convert(pAstEventExpression->event_or_event()->element(0)._pEventExpression0);
        VExprEventExpressionHandle pSnd =
            ConvertAst2VExpr::convert(pAstEventExpression->event_or_event()->element(0)._pEventExpression2);
        return VExprEventExpressionHandle(VExprEventExpression(pFst, pSnd));
    } else if (pAstEventExpression->expression().valid()) {
        VExprExpressionHandle pExpression =
            ConvertAst2VExpr::convert(pAstEventExpression->expression());
        return VExprEventExpressionHandle(VExprEventExpression(VExprEventHandle(VExprEvent(pExpression))));
    } else if (pAstEventExpression->identifier().valid()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstEventExpression->identifier());
        return VExprEventExpressionHandle(VExprEventExpression(VExprEventHandle(VExprEvent(pIdentifier))));
    } else if (pAstEventExpression->posedge_expression().valid()) {
        VExprPosedgeEventHandle pPosedgeEvent =
            ConvertAst2VExpr::convert(pAstEventExpression->posedge_expression());
        return VExprEventExpressionHandle(VExprEventExpression(VExprEventHandle(VExprEvent(pPosedgeEvent))));
    } else if (pAstEventExpression->negedge_expression().valid()) {
        VExprNegedgeEventHandle pNegedgeEvent =
            ConvertAst2VExpr::convert(pAstEventExpression->negedge_expression());
        return VExprEventExpressionHandle(VExprEventExpression(VExprEventHandle(VExprEvent(pNegedgeEvent))));
    }
    assert(0);
}
    
VExprEventExpressionHandle ConvertAst2VExpr::convert(const AstEventControlHandle & pAstEventControl) {
    if (pAstEventControl->at_identifier().valid()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstEventControl->at_identifier()->element(0)._pIdentifier0);
        return VExprEventExpressionHandle(VExprEventExpression(VExprEventHandle(VExprEvent(pIdentifier))));
    } else if (pAstEventControl->at_event_expression().valid()) {
        return ConvertAst2VExpr::convert(pAstEventControl->at_event_expression()->element(0)._pEventExpression0);
    } else if (pAstEventControl->at_asterisk().valid()) {
        return VExprEventExpressionHandle(VExprEventExpression());
    }

    assert(0);
}
    
VExprEventExpressionHandle ConvertAst2VExpr::convert(const AstDelayOrEventControlHandle & pAstDelayOrEventControl) {
    return ConvertAst2VExpr::convert(pAstDelayOrEventControl->element(0)._pEventControl0);
}
   
VExprEventStatementHandle ConvertAst2VExpr::convert(const AstProceduralTimingControlStatementHandle & pAstProceduralTimingControlStatement) {
    VExprEventExpressionHandle pEventExpression =
        ConvertAst2VExpr::convert(pAstProceduralTimingControlStatement->element(0)._pDelayOrEventControl0);
    VExprStatementOrNullHandle pStatementOrNull =
        ConvertAst2VExpr::convert(pAstProceduralTimingControlStatement->element(0)._pStatementOrNull1);

    return VExprEventStatementHandle(VExprEventStatement(pEventExpression, pStatementOrNull));
}
    
VExprLoopStatementHandle ConvertAst2VExpr::convert(const AstLoopStatementHandle & pAstLoopStatement) {
    VExprRegAssignmentHandle pRegAssign1 =
        ConvertAst2VExpr::convert(pAstLoopStatement->element(0)._pRegAssignment1);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstLoopStatement->element(0)._pExpression2);
    VExprRegAssignmentHandle pRegAssign2 =
        ConvertAst2VExpr::convert(pAstLoopStatement->element(0)._pRegAssignment3);

    VExprStatementHandle pStatement =
        ConvertAst2VExpr::convert(pAstLoopStatement->element(0)._pStatement4);

    return VExprLoopStatementHandle(VExprLoopStatement(pRegAssign1, pExpression, pRegAssign2, pStatement));
}
    
VExprParamAssignmentHandle ConvertAst2VExpr::convert(const AstParamAssignmentHandle & pAstParamAssignment) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstParamAssignment->element(0)._pIdentifier0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstParamAssignment->element(0)._pExpression1);

    return VExprParamAssignmentHandle(VExprParamAssignment(pIdentifier, pExpression));
}
    
VExprParameterDeclarationHandle ConvertAst2VExpr::convert(const AstParameterDeclarationHandle & pAstParameterDeclaration) {

    std::vector<VExprParamAssignmentHandle> vecParamAssignment;

    AstListOfParamAssignmentHandle pAstListOfParamAssignment =
        pAstParameterDeclaration->element(0)._pListOfParamAssignment1;

    vecParamAssignment.push_back(ConvertAst2VExpr::convert(pAstListOfParamAssignment->element(0)._pParamAssignment0));

    AstZeroOrMoreCommaParamAssignmentHandle pAstZeroOrMoreCommaParamAssignment = pAstListOfParamAssignment->element(0)._pZeroOrMoreCommaParamAssignment1;

    CONST_FOR_EACH(elem, pAstZeroOrMoreCommaParamAssignment->container()) {
        VExprParamAssignmentHandle pParamAssignment =
            ConvertAst2VExpr::convert(elem._pParamAssignment);
        vecParamAssignment.push_back(pParamAssignment);
    }

    return VExprParameterDeclarationHandle(VExprParameterDeclaration(vecParamAssignment));
}
   
// #define VEXPR_IO_DECLARATION_CPP_IMPLEMENTATION(nm)
VExprInputDeclarationHandle ConvertAst2VExpr::convert(const AstInputDeclarationHandle & pAstInputDeclaration) {
    AstZeroOrOneRangeHandle pAstZeroOrOneRange = pAstInputDeclaration->element(0)._pZeroOrOneRange1;
    
    AstListOfPortIdentifiersHandle pAstListOfPortIdentifiers = pAstInputDeclaration->element(0)._pListOfPortIdentifiers2;

    std::vector<VExprIdentifierHandle> vecIdentifier;
    vecIdentifier.push_back(ConvertAst2VExpr::convert(pAstListOfPortIdentifiers->element(0)._pIdentifier0));

    AstZeroOrMoreCommaIdentifierHandle pAstZeroOreMoreCommaIdentifier = pAstListOfPortIdentifiers->element(0)._pZeroOrMoreCommaIdentifier1;

    CONST_FOR_EACH(elem, pAstZeroOreMoreCommaIdentifier->container()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstZeroOreMoreCommaIdentifier->element(0)._pIdentifier);
        vecIdentifier.push_back(pIdentifier);
    }


    std::vector<VExprInputDeclHandle> vecInputDecl;
    if (pAstZeroOrOneRange->element_size() == 0) {
        CONST_FOR_EACH(x, vecIdentifier) {
            VExprPortDeclarationHandle pPortDeclaration =
                VExprPortDeclarationHandle(VExprPortDeclaration(x));
            vecInputDecl.push_back(VExprInputDeclHandle(VExprInputDecl(pPortDeclaration)));
        }
    } else if (pAstZeroOrOneRange->element_size() == 1) {
        VExprRangeHandle pRange =
            ConvertAst2VExpr::convert(pAstZeroOrOneRange->element(0)._pRange);
        CONST_FOR_EACH(x, vecIdentifier) {
            VExprPortDeclarationHandle pPortDeclaration =
                VExprPortDeclarationHandle(VExprPortDeclaration(pRange, x));
            vecInputDecl.push_back(VExprInputDeclHandle(VExprInputDecl(pPortDeclaration)));
        }
    } else {
        assert(0);
    }

    return VExprInputDeclarationHandle(VExprInputDeclaration(vecInputDecl));
}
    
VExprModuleItemDeclarationHandle ConvertAst2VExpr::convert(const AstModuleItemDeclarationHandle& pAstModuleItemDeclaration) {
    if (pAstModuleItemDeclaration->parameter_declaration().valid()) {
        VExprParameterDeclarationHandle pParameterDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->parameter_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pParameterDeclaration));
    } 
#if 0
    else if (pAstModuleItemDeclaration->input_declaration().valid()) {
        VExprInputDeclarationHandle pInputDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->input_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pInputDeclaration));
    } else if (pAstModuleItemDeclaration->output_declaration().valid()) {
        VExprOutputDeclarationHandle pOutputDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->output_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pOutputDeclaration));
    } else if (pAstModuleItemDeclaration->inout_declaration().valid()) {
        VExprInoutDeclarationHandle pInoutDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->inout_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pInoutDeclaration));
    } else if (pAstModuleItemDeclaration->net_declaration().valid()) {
        VExprNetDeclarationHandle pNetDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->net_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pNetDeclaration));
    } else if (pAstModuleItemDeclaration->reg_declaration().valid()) {
        VExprRegDeclarationHandle pRegDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->reg_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pRegDeclaration));
    } else if (pAstModuleItemDeclaration->integer_declaration().valid()) {
        VExprIntegerDeclartionHandle pIntegerDeclartion =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->integer_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pIntegerDeclartion));
    }
#endif

    assert(0);
}

VExprModuleHandle ConvertAst2VExpr::convert(const AstSourceTextHandle & pSourceText) {

    const AstOneOrMoreDescriptionHandle pOneOrMoreDescription = 
        pSourceText->one_or_more_description();
    
    assert(pOneOrMoreDescription->element_size() == 1);

    AstDescriptionHandle pDescription =
        pOneOrMoreDescription->element(0)._pDescription0;

    AstModuleDeclarationHandle pModuleDeclaration =
        pDescription->module_declaration();

    AstIdentifierHandle pIdentifier =
        pModuleDeclaration->element(0)._pIdentifier1;

    AstSingleIdentifierHandle pSingleIdentifier =
        pIdentifier->single_identifier();

    AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem =
        pModuleDeclaration->element(0)._pZeroOrMoreModuleItem3;

    VExprParameterDeclarationHandle pParameterDeclaration =
        VExprParameterDeclarationHandle(VExprParameterDeclaration());


    FOR_EACH(item, pZeroOrMoreModuleItem->container()) {
        AstModuleItemHandle pAstModuleItem = item._pModuleItem;
        if (pAstModuleItem->module_item_declaration().valid()) {
            AstModuleItemDeclarationHandle pAstModuleItemDeclaration = pAstModuleItem->module_item_declaration();
            if (pAstModuleItemDeclaration->parameter_declaration().valid()) {
                AstParameterDeclarationHandle pAstParameterDeclaration =
                    pAstModuleItemDeclaration->parameter_declaration();
                AstListOfParamAssignmentHandle pAstListOfParamAssignment =
                    pAstParameterDeclaration->element(0)._pListOfParamAssignment1;
                
                AstParamAssignmentHandle pAstParamAssignment =
                    pAstListOfParamAssignment->element(0)._pParamAssignment0;

                AstIdentifierHandle pAstIdentifier =
                    pAstParamAssignment->element(0)._pIdentifier0;
                AstExpressionHandle pAstExpression =
                    pAstParamAssignment->element(0)._pExpression1;

                VExprIdentifierHandle pParameterIdentifier =
                    ConvertAst2VExpr::convert(pAstIdentifier);


                std::cout << "*Debug: " << pParameterIdentifier->getString() << std::endl;


//                VExprParaAssignmentHandle pParaAssignment = VExprParaAssignmentHandle(VExprParamAssignment());


            }
        }
    }


    return VExprModuleHandle(VExprModule(vexpr_identifier_mk_single_identifier(pSingleIdentifier->simple_identifier()->simple_identifier())));
}

