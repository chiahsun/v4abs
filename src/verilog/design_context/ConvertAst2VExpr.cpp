#include "ConvertAst2VExpr.h"

UnaryOpType getUnaryOpTypeFromAst(AstUnaryOperatorHandle pAstUnaryOperator) {

    if (pAstUnaryOperator->unary_operator_plus().valid()) {
        return UNARY_PLUS;
    } else if (pAstUnaryOperator->unary_operator_minus().valid()) {
        return UNARY_MINUS;
    } else if (pAstUnaryOperator->unary_operator_not().valid()) {
        return UNARY_NOT;
    } else if (pAstUnaryOperator->unary_operator_neg().valid()) {
        return UNARY_NEG;
    } else if (pAstUnaryOperator->unary_operator_and().valid()) {
        return UNARY_AND;
    } else if (pAstUnaryOperator->unary_operator_neg_and().valid()) {
        return UNARY_NEG_AND;
    } else if (pAstUnaryOperator->unary_operator_or().valid()) {
        return UNARY_OR;
    } else if (pAstUnaryOperator->unary_operator_neg_or().valid()) {
        return UNARY_NEG_OR;
    } else if (pAstUnaryOperator->unary_operator_xor().valid()) {
        return UNARY_XOR;
    } else if (pAstUnaryOperator->unary_operator_neg_xor().valid()) {
        return UNARY_NEG_XOR;
    } else if (pAstUnaryOperator->unary_operator_xor_neg().valid()) {
        return UNARY_XOR_NEG;
    }

    std::cerr << "*Error: No such unary op type" << std::endl;
    assert(0);
}

BinaryOpType getBinaryOpTypeFromAst(AstBinaryOperatorHandle pAstBinaryOp) {
    if (pAstBinaryOp->binary_operator_plus().valid()) {
        return BINARY_PLUS;
    } else if (pAstBinaryOp->binary_operator_minus().valid()) {
        return BINARY_MINUS;
    } else if (pAstBinaryOp->binary_operator_asterisk().valid()) {
        return BINARY_MULT;
    } else if (pAstBinaryOp->binary_operator_slash().valid()) {
        return BINARY_DIV;
    } else if (pAstBinaryOp->binary_operator_percent().valid()) {
        return BINARY_MOD;
    } else if (pAstBinaryOp->binary_operator_equal_equal().valid()) {
        return BINARY_EQ;
    } else if (pAstBinaryOp->binary_operator_not_equal().valid()) {
        return BINARY_NEQ;
    } else if (pAstBinaryOp->binary_operator_triple_equal().valid()) {
        return BINARY_XEQ;
    } else if (pAstBinaryOp->binary_operator_not_equal_equal().valid()) {
        return BINARY_XNEQ;
    } else if (pAstBinaryOp->binary_operator_and_and().valid()) {
        return BINARY_LOGICAL_AND;
    } else if (pAstBinaryOp->binary_operator_or_or().valid()) {
        return BINARY_LOGICAL_OR;
    } else if (pAstBinaryOp->binary_operator_lt().valid()) {
        return BINARY_LT;
    } else if (pAstBinaryOp->binary_operator_leq().valid()) {
        return BINARY_LEQ;
    } else if (pAstBinaryOp->binary_operator_gt().valid()) {
        return BINARY_GT;
    } else if (pAstBinaryOp->binary_operator_geq().valid()) {
        return BINARY_GEQ;
    } else if (pAstBinaryOp->binary_operator_and().valid()) {
        return BINARY_BITWISE_AND;
    } else if (pAstBinaryOp->binary_operator_or().valid()) {
        return BINARY_BITWISE_OR;
    } else if (pAstBinaryOp->binary_operator_xor().valid()) {
        return BINARY_BITWISE_XOR;
    } else if (pAstBinaryOp->binary_operator_xor_neg().valid()) {
        return BINARY_BITWISE_XOR_NEG;
    } else if (pAstBinaryOp->binary_operator_neg_xor().valid()) {
        return BINARY_BITWISE_NEG_XOR;
    } else if (pAstBinaryOp->binary_operator_shr().valid()) {
        return BINARY_SHIFT_RIGHT;
    } else if (pAstBinaryOp->binary_operator_shl().valid()) {
        return BINARY_SHIFT_LEFT;
    }

    std::cerr << "*Error: No such binary op type" << std::endl;
    assert(0);
}

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

    UnaryOpType opType = getUnaryOpTypeFromAst(pAstUnaryOperator);

    return VExprUnaryHandle(VExprUnary(opType, pPrimary));
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

#define BINARY_CONVERT(access_function, op_type) if (pAstBinaryExpression->access_function().valid()) {\
        VExprExpressionHandle pExprFst = \
            ConvertAst2VExpr::convert(pAstBinaryExpression->access_function()->element(0)._pExpression0);\
        VExprExpressionHandle pExprSnd = \
            ConvertAst2VExpr::convert(pAstBinaryExpression->access_function()->element(0)._pExpression1);\
        return VExprBinaryHandle(VExprBinary(pExprFst, op_type, pExprSnd));\
    }


VExprBinaryHandle ConvertAst2VExpr::convert(const AstBinaryExpressionHandle & pAstBinaryExpression) {
    BINARY_CONVERT(binary_expression_multiply, BINARY_MULT);
    BINARY_CONVERT(binary_expression_divide, BINARY_DIV);
    BINARY_CONVERT(binary_expression_modulus, BINARY_MOD);
    BINARY_CONVERT(binary_expression_plus, BINARY_PLUS);
    BINARY_CONVERT(binary_expression_minus, BINARY_MINUS);
    BINARY_CONVERT(binary_expression_shift_right, BINARY_SHIFT_RIGHT);
    BINARY_CONVERT(binary_expression_shift_left, BINARY_SHIFT_LEFT);
    BINARY_CONVERT(binary_expression_gt, BINARY_GT);
    BINARY_CONVERT(binary_expression_geq, BINARY_GEQ);
    BINARY_CONVERT(binary_expression_lt, BINARY_LT);
    BINARY_CONVERT(binary_expression_leq, BINARY_LEQ);
    BINARY_CONVERT(binary_expression_eq, BINARY_EQ);
    BINARY_CONVERT(binary_expression_neq, BINARY_NEQ);
    BINARY_CONVERT(binary_expression_case_eq, BINARY_XEQ);
    BINARY_CONVERT(binary_expression_case_neq, BINARY_XNEQ);
    BINARY_CONVERT(binary_expression_bw_and, BINARY_BITWISE_AND);
    BINARY_CONVERT(binary_expression_bw_xor, BINARY_BITWISE_XOR);
    BINARY_CONVERT(binary_expression_bw_xnor, BINARY_BITWISE_XOR_NEG);
    BINARY_CONVERT(binary_expression_bw_nxor, BINARY_BITWISE_NEG_XOR);
    BINARY_CONVERT(binary_expression_bw_or, BINARY_BITWISE_OR);
    BINARY_CONVERT(binary_expression_lg_and, BINARY_LOGICAL_AND);
    BINARY_CONVERT(binary_expression_lg_or, BINARY_LOGICAL_OR);
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
   
    UnaryOpType opType = getUnaryOpTypeFromAst(pAstUnaryOperator);
    return VExprConstantUnaryHandle(VExprConstantUnary(opType, pConstantPrimary));
}

#define CONSTANT_BINARY_CONVERT(access_function, op_type) if (pAstBinaryConstantExpression->access_function().valid()) {\
        VExprConstantExpressionHandle pExprFst = \
            ConvertAst2VExpr::convert(pAstBinaryConstantExpression->access_function()->element(0)._pConstantExpression0);\
        VExprConstantExpressionHandle pExprSnd = \
            ConvertAst2VExpr::convert(pAstBinaryConstantExpression->access_function()->element(0)._pConstantExpression1);\
        return VExprConstantBinaryHandle(VExprConstantBinary(pExprFst, op_type, pExprSnd));\
    }

    
VExprConstantBinaryHandle ConvertAst2VExpr::convert(const AstBinaryConstantExpressionHandle & pAstBinaryConstantExpression) {
    CONSTANT_BINARY_CONVERT(binary_constant_expression_multiply, BINARY_MULT);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_divide, BINARY_DIV);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_modulus, BINARY_MOD);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_plus, BINARY_PLUS);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_minus, BINARY_MINUS);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_shift_right, BINARY_SHIFT_RIGHT);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_shift_left, BINARY_SHIFT_LEFT);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_gt, BINARY_GT);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_geq, BINARY_GEQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_lt, BINARY_LT);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_leq, BINARY_LEQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_eq, BINARY_EQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_neq, BINARY_NEQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_case_eq, BINARY_XEQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_case_neq, BINARY_XNEQ);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_bw_and, BINARY_BITWISE_AND);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_bw_xor, BINARY_BITWISE_XOR);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_bw_xnor, BINARY_BITWISE_XOR_NEG);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_bw_nxor, BINARY_BITWISE_NEG_XOR);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_bw_or, BINARY_BITWISE_OR);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_lg_and, BINARY_LOGICAL_AND);
    CONSTANT_BINARY_CONVERT(binary_constant_expression_lg_or, BINARY_LOGICAL_OR);
    assert(0);
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

VExprInputDeclarationHandle ConvertAst2VExpr::convert(const AstInputDeclarationHandle & pAstInputDeclaration) {
    return convertIOAst2VExpr<VExprInputDeclaration, AstInputDeclarationHandle, VExprInputDecl>(pAstInputDeclaration);
}
    
VExprOutputDeclarationHandle ConvertAst2VExpr::convert(const AstOutputDeclarationHandle & pAstOutputDeclaration) {
    return convertIOAst2VExpr<VExprOutputDeclaration, AstOutputDeclarationHandle, VExprOutputDecl>(pAstOutputDeclaration);
}

VExprInoutDeclarationHandle ConvertAst2VExpr::convert(const AstInoutDeclarationHandle & pAstInoutDeclaration) {
    return convertIOAst2VExpr<VExprInoutDeclaration, AstInoutDeclarationHandle, VExprInoutDecl>(pAstInoutDeclaration);
}
    
VExprNetDeclarationHandle ConvertAst2VExpr::convert(const AstNetDeclarationHandle & pAstNetDeclaration) {
    AstZeroOrOneRangeHandle pAstZeroOrOneRange = pAstNetDeclaration->element(0)._pZeroOrOneRange1;
    
    AstListOfNetIdentifierHandle pAstListOfNetIdentifier = pAstNetDeclaration->element(0)._pListOfNetIdentifier2;

    std::vector<VExprIdentifierHandle> vecIdentifier;
    vecIdentifier.push_back(ConvertAst2VExpr::convert(pAstListOfNetIdentifier->element(0)._pIdentifier0));

    AstZeroOrMoreCommaIdentifierHandle pAstZeroOreMoreCommaIdentifier = pAstListOfNetIdentifier->element(0)._pZeroOrMoreCommaIdentifier1;

    CONST_FOR_EACH(elem, pAstZeroOreMoreCommaIdentifier->container()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstZeroOreMoreCommaIdentifier->element(0)._pIdentifier);
        vecIdentifier.push_back(pIdentifier);
    }


    std::vector<VExprNetDeclHandle> vecInputDecl;
    if (pAstZeroOrOneRange->element_size() == 0) {
        CONST_FOR_EACH(x, vecIdentifier) {
            vecInputDecl.push_back(VExprNetDeclHandle(VExprNetDecl(x)));
        }
    } else if (pAstZeroOrOneRange->element_size() == 1) {
        VExprRangeHandle pRange =
            ConvertAst2VExpr::convert(pAstZeroOrOneRange->element(0)._pRange);
        CONST_FOR_EACH(x, vecIdentifier) {
            vecInputDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pRange, x)));
        }
    } else {
        assert(0);
    }

    return VExprNetDeclarationHandle(VExprNetDeclaration(vecInputDecl));
//    return convertIOAst2VExpr<VExprNetDeclaration, AstNetDeclarationHandle, VExprNetDecl>(pAstNetDeclaration);
}
    
VExprRegisterNameHandle ConvertAst2VExpr::convert(const AstRegisterNameHandle & pAstRegisterName) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstRegisterName->element(0)._pIdentifier0);

    AstZeroOrMoreRegisterNameRangeHandle pZeroOrMoreRegisterNameRange = pAstRegisterName->element(0)._pZeroOrMoreRegisterNameRange1;

    std::vector<VExprRangeHandle> vecRange;

    CONST_FOR_EACH(elem, pZeroOrMoreRegisterNameRange->container()) {
        VExprRangeHandle pRange =
            ConvertAst2VExpr::convert(elem._pRange);
        vecRange.push_back(pRange);
    }

    return VExprRegisterNameHandle(VExprRegisterName(pIdentifier, vecRange));

}

std::vector<VExprRegisterNameHandle> ConvertAst2VExpr::convert(const AstListOfRegisterIdentifiersHandle & pAstListOfRegisterIdentifiers) {
    std::vector<VExprRegisterNameHandle> vecRegisterName;

    vecRegisterName.push_back(ConvertAst2VExpr::convert(pAstListOfRegisterIdentifiers->element(0)._pRegisterName0));

    AstZeroOrMoreCommaRegisterNameHandle pAstZeroOrMoreCommaRegisterName = pAstListOfRegisterIdentifiers->element(0)._pZeroOrMoreCommaRegisterName1;
    CONST_FOR_EACH(elem, pAstZeroOrMoreCommaRegisterName->container()) {
        VExprRegisterNameHandle pRegisterName =
            ConvertAst2VExpr::convert(elem._pRegisterName);
        vecRegisterName.push_back(pRegisterName);
    }
    return  vecRegisterName;
}
    
VExprRegDeclarationHandle ConvertAst2VExpr::convert(const AstRegDeclarationHandle & pAstRegDeclaration) {
    AstZeroOrOneRangeHandle pAstZeroOrOneRange =
        pAstRegDeclaration->element(0)._pZeroOrOneRange1;

    AstListOfRegisterIdentifiersHandle pAstListOfRegisterIdentifiers = pAstRegDeclaration->element(0)._pListOfRegisterIdentifiers2;
    
    std::vector<VExprRegisterNameHandle> vecRegisterName = ConvertAst2VExpr::convert(pAstListOfRegisterIdentifiers);

    std::vector<VExprRegDeclHandle> vecRegDecl;
    if (pAstZeroOrOneRange->element_size() == 0) {
        CONST_FOR_EACH(x, vecRegisterName) {
            VExprRegDeclHandle pRegDecl = VExprRegDeclHandle(VExprRegDecl(x));
            vecRegDecl.push_back(pRegDecl);
        }
    } else {
        VExprRangeHandle pRange = ConvertAst2VExpr::convert(pAstZeroOrOneRange->element(0)._pRange);
        CONST_FOR_EACH(x, vecRegisterName) {
            VExprRegDeclHandle pRegDecl = VExprRegDeclHandle(VExprRegDecl(pRange, x));
            vecRegDecl.push_back(pRegDecl);
        }
    }

    return VExprRegDeclarationHandle(VExprRegDeclaration(vecRegDecl));
}

VExprIntegerDeclarationHandle ConvertAst2VExpr::convert(const AstIntegerDeclarationHandle & pIntegerDeclaration) {
    AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers = pIntegerDeclaration->element(0)._pListOfRegisterIdentifiers1;

    std::vector<VExprRegisterNameHandle> vecRegisterName =
        ConvertAst2VExpr::convert(pListOfRegisterIdentifiers);

    return VExprIntegerDeclarationHandle(VExprIntegerDeclaration(vecRegisterName));
}

VExprModuleItemDeclarationHandle ConvertAst2VExpr::convert(const AstModuleItemDeclarationHandle& pAstModuleItemDeclaration) {
    if (pAstModuleItemDeclaration->parameter_declaration().valid()) {
        VExprParameterDeclarationHandle pParameterDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->parameter_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pParameterDeclaration));
    } else if (pAstModuleItemDeclaration->input_declaration().valid()) {
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
    } 
    else if (pAstModuleItemDeclaration->integer_declaration().valid()) {
        VExprIntegerDeclarationHandle pIntegerDeclartion =
            ConvertAst2VExpr::convert(pAstModuleItemDeclaration->integer_declaration());
        return VExprModuleItemDeclarationHandle(VExprModuleItemDeclaration(pIntegerDeclartion));
    }

    assert(0);
}
    
VExprNameOfInstanceHandle ConvertAst2VExpr::convert(const AstNameOfInstanceHandle & pAstNameOfInstance) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstNameOfInstance->element(0)._pIdentifier0);

    AstZeroOrOneRangeHandle pAstZeroOrOneRange = pAstNameOfInstance->element(0)._pZeroOrOneRange1;
    
    if (pAstZeroOrOneRange->element_size() == 0) {
        return VExprNameOfInstanceHandle(VExprNameOfInstance(pIdentifier));
    } else {
        VExprRangeHandle pRange =
            ConvertAst2VExpr::convert(pAstZeroOrOneRange->element(0)._pRange);
        return VExprNameOfInstanceHandle(VExprNameOfInstance(pIdentifier, pRange));
    }
    assert(0);
}

VExprExpressionHandle ConvertAst2VExpr::convert(const AstZeroOrOneExpressionHandle & pAstZeroOrOneExpression) {
    if (pAstZeroOrOneExpression->element_size() == 0)
        return VExprExpressionHandle();
    else {
        VExprExpressionHandle pExpression =
            ConvertAst2VExpr::convert(pAstZeroOrOneExpression->element(0)._pExpression);
        return pExpression; 
    }
    assert(0);
}


VExprOrderedPortConnectionHandle ConvertAst2VExpr::convert(const AstOrderedPortConnectionHandle & pAstOrderedPortConnection) {
    AstZeroOrOneExpressionHandle pAstZeroOrOneExpression = pAstOrderedPortConnection->zero_or_one_expression();
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstZeroOrOneExpression);

    if (pExpression.valid()) {
        return VExprOrderedPortConnectionHandle(VExprOrderedPortConnection(pExpression));
    } else {
        return VExprOrderedPortConnectionHandle(VExprOrderedPortConnection());
    }
    assert(0);
}
    
VExprNamedPortConnectionHandle ConvertAst2VExpr::convert(const AstNamedPortConnectionHandle & pAstNamedPortConnection) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstNamedPortConnection->element(0)._pIdentifier0);
    VExprExpressionHandle pExpression =
        ConvertAst2VExpr::convert(pAstNamedPortConnection->element(0)._pZeroOrOneExpression1);

    if (pExpression.valid())
        return VExprNamedPortConnectionHandle(VExprNamedPortConnection(pIdentifier, pExpression));
    else 
        return VExprNamedPortConnectionHandle(VExprNamedPortConnection(pIdentifier));

    assert(0);
}
    
VExprListOfModuleConnectionsHandle ConvertAst2VExpr::convert(const AstListOfModuleConnectionsHandle & pAstListOfModuleConnections) {
    if (pAstListOfModuleConnections->list_of_ordered_port_connection().valid()) {
        AstListOfOrderedPortConnectionHandle pAstListOfOrderedPortConnection = pAstListOfModuleConnections->list_of_ordered_port_connection();

        std::vector<VExprOrderedPortConnectionHandle> vecOrderedPortConnection;
        AstOrderedPortConnectionHandle pAstOrderedPortConnectionFst = pAstListOfOrderedPortConnection->element(0)._pOrderedPortConnection0;
        VExprOrderedPortConnectionHandle pOrderedPortConnectionFst = 
            ConvertAst2VExpr::convert(pAstOrderedPortConnectionFst);
        vecOrderedPortConnection.push_back(pOrderedPortConnectionFst);

        AstZeroOrMoreCommaOrderedPortConnectionHandle pAstZeroOrMoreCommaOrderedPortConnection = pAstListOfOrderedPortConnection->element(0)._pZeroOrMoreCommaOrderedPortConnection1;
        CONST_FOR_EACH(x, pAstZeroOrMoreCommaOrderedPortConnection->container()) {
            AstOrderedPortConnectionHandle pAstOrderedPortConnection = x._pOrderedPortConnection;
            VExprOrderedPortConnectionHandle pOrderedPortConnection =
                ConvertAst2VExpr::convert(pAstOrderedPortConnection);
            vecOrderedPortConnection.push_back(pOrderedPortConnection);
        }

        return VExprListOfModuleConnectionsHandle(VExprListOfModuleConnections(vecOrderedPortConnection));
    } else if (pAstListOfModuleConnections->list_of_named_port_connection().valid()){
        AstListOfNamedPortConnectionHandle pAstListOfNamedPortConnection = pAstListOfModuleConnections->list_of_named_port_connection();

        AstNamedPortConnectionHandle pAstNamedPortConnectionFst = pAstListOfNamedPortConnection->element(0)._pNamedPortConnection0;
        AstZeroOrMoreCommaNamedPortConnectionHandle pAstZeroOrMoreCommaNamedPortConnection = pAstListOfNamedPortConnection->element(0)._pZeroOrMoreCommaNamedPortConnection1;

        std::vector<VExprNamedPortConnectionHandle> vecNamedPortConnection;
        VExprNamedPortConnectionHandle pNamedPortConnectionFst =
            ConvertAst2VExpr::convert(pAstNamedPortConnectionFst);

        CONST_FOR_EACH(x, pAstZeroOrMoreCommaNamedPortConnection->container()) {
            AstNamedPortConnectionHandle pAstNamedPortConnection = x._pNamedPortConnection;
            VExprNamedPortConnectionHandle pNamedPortConnection =
                ConvertAst2VExpr::convert(pAstNamedPortConnection);
            vecNamedPortConnection.push_back(pNamedPortConnection);
        }
        
        return VExprListOfModuleConnectionsHandle(VExprListOfModuleConnections(vecNamedPortConnection));

    } else {
        assert(0);
    }
    assert(0);
}
    
VExprModuleInstanceHandle ConvertAst2VExpr::convert(const AstModuleInstanceHandle & pModuleInstance) {
    VExprNameOfInstanceHandle pNameOfInstance =
        ConvertAst2VExpr::convert(pModuleInstance->element(0)._pNameOfInstance0);
    VExprListOfModuleConnectionsHandle pListOfModuleConnection =
        ConvertAst2VExpr::convert(pModuleInstance->element(0)._pListOfModuleConnections1);

    return VExprModuleInstanceHandle(VExprModuleInstance(pNameOfInstance, pListOfModuleConnection));
}
    
    
VExprModuleInstantiationHandle ConvertAst2VExpr::convert(const AstModuleInstantiationHandle & pAstModuleInstantiation) {

    std::vector<VExprModuleInstanceHandle> vecModuleInstance;

    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstModuleInstantiation->element(0)._pIdentifier0);
    VExprModuleInstanceHandle pModuleInstanceFst =
        ConvertAst2VExpr::convert(pAstModuleInstantiation->element(0)._pModuleInstance1);
    vecModuleInstance.push_back(pModuleInstanceFst);


    AstZeroOrMoreCommaModuleInstanceHandle pAstZeroOrMoreCommaModuleInstance = pAstModuleInstantiation->element(0)._pZeroOrMoreCommaModuleInstance2;

    CONST_FOR_EACH(x, pAstZeroOrMoreCommaModuleInstance->container()) {
        VExprModuleInstanceHandle pModuleInstance =
            ConvertAst2VExpr::convert(x._pModuleInstance);
        vecModuleInstance.push_back(pModuleInstance);
    }

    return VExprModuleInstantiationHandle(VExprModuleInstantiation(pIdentifier, vecModuleInstance));

}
    
VExprAlwaysHandle ConvertAst2VExpr::convert(const AstAlwaysConstructHandle & pAstAlwaysConstruct) {
    VExprStatementHandle pStatement =
        ConvertAst2VExpr::convert(pAstAlwaysConstruct->element(0)._pStatement1);

    return VExprAlwaysHandle(VExprAlways(pStatement));
}
    
VExprInitialHandle ConvertAst2VExpr::convert(const AstInitialConstructHandle & pAstInitialConstruct) {
    VExprStatementHandle pStatement =
        ConvertAst2VExpr::convert(pAstInitialConstruct->element(0)._pStatement1);

    return VExprInitialHandle(VExprInitial(pStatement));
}
    
VExprModuleItemHandle ConvertAst2VExpr::convert(const AstModuleItemHandle & pAstModuleItem) {
    if (pAstModuleItem->always_construct().valid()) {
        VExprAlwaysHandle pAlways =
            ConvertAst2VExpr::convert(pAstModuleItem->always_construct());
        return VExprModuleItemHandle(VExprModuleItem(pAlways));
    } else if (pAstModuleItem->initial_construct().valid()) {
        VExprInitialHandle pInitial =
            ConvertAst2VExpr::convert(pAstModuleItem->initial_construct());
        return VExprModuleItemHandle(VExprModuleItem(pInitial));
    } else if (pAstModuleItem->module_item_declaration().valid()) {
        VExprModuleItemDeclarationHandle pModuleItemDeclaration =
            ConvertAst2VExpr::convert(pAstModuleItem->module_item_declaration());
        return VExprModuleItemHandle(VExprModuleItem(pModuleItemDeclaration));
    } else if (pAstModuleItem->continuous_assign().valid()) {
        VExprContinuousAssignmentHandle pContinuousAssignment =
            ConvertAst2VExpr::convert(pAstModuleItem->continuous_assign());
        return VExprModuleItemHandle(VExprModuleItem(pContinuousAssignment));
    } else if (pAstModuleItem->gate_instantiation().valid()) {
        assert(0);
//        return VExprModuleItemHandle(VExprModuleItem(pAstModuleItem->gate_instantiation()));
    } else if (pAstModuleItem->module_instantiation().valid()) {
        VExprModuleInstantiationHandle pModuleInstantiation =
            ConvertAst2VExpr::convert(pAstModuleItem->module_instantiation());
        return VExprModuleItemHandle(VExprModuleItem(pModuleInstantiation));
    }

    assert(0);
} 
    
std::vector<VExprModuleItemHandle> ConvertAst2VExpr::convert(const AstZeroOrMoreModuleItemHandle & pAstZeroOrMoreModuletItem) {
    std::vector<VExprModuleItemHandle> vecModuleItem;
    CONST_FOR_EACH(x, pAstZeroOrMoreModuletItem->container()) {
        AstModuleItemHandle pAstModuleItem = x._pModuleItem;
        VExprModuleItemHandle pModuleItem =
            ConvertAst2VExpr::convert(pAstModuleItem);
        vecModuleItem.push_back(pModuleItem);
    }
    return vecModuleItem;
}

// TODO: wrong, not identifier only
VExprIdentifierHandle ConvertAst2VExpr::convert(const AstPortReferenceHandle & pPortReference) {
    if (pPortReference->identifier().valid()) {
        return ConvertAst2VExpr::convert(pPortReference->identifier());
    } else if (pPortReference->constant_bit_select_identifier().valid()) {
    } else if (pPortReference->constant_range_select_identifier().valid()) {
    }
    assert(0);
}

std::vector<VExprIdentifierHandle> ConvertAst2VExpr::convert(const AstPortExpressionHandle & pAstPortExpression) {
    std::vector<VExprIdentifierHandle> vecIdentifier;
    if (pAstPortExpression->port_reference().valid()) {
        AstPortReferenceHandle pAstPortReference = pAstPortExpression->port_reference();
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(pAstPortReference);
        vecIdentifier.push_back(pIdentifier);
        return vecIdentifier;
    } else if (pAstPortExpression->list_of_port_references().valid()) {
        AstListOfPortReferencesHandle pAstListOfPortReferences = pAstPortExpression->list_of_port_references();
        AstPortReferenceHandle pAstPortReferenceFst = pAstListOfPortReferences->element(0)._pPortReference0;
        VExprIdentifierHandle pIdentifierFst =
            ConvertAst2VExpr::convert(pAstPortReferenceFst);
        vecIdentifier.push_back(pIdentifierFst);

        AstZeroOrMoreCommaPortReferenceHandle pAstZeroOrMoreCommaPortReference = pAstListOfPortReferences->element(0)._pZeroOrMoreCommaPortReference1;

        CONST_FOR_EACH(x, pAstZeroOrMoreCommaPortReference->container()) {
            AstPortReferenceHandle pAstPortReference = x._pPortReference;
            VExprIdentifierHandle pIdentifier =
                ConvertAst2VExpr::convert(pAstPortReference);
            vecIdentifier.push_back(pIdentifier);
        }
        return vecIdentifier;
    }

    assert(0);
}
    
std::vector<VExprIdentifierHandle> ConvertAst2VExpr::convert(const AstPortHandle & pAstPort) {
    return ConvertAst2VExpr::convert(pAstPort->port_expression());
}
    
std::vector<VExprIdentifierHandle> ConvertAst2VExpr::convert(const AstListOfPortsHandle & pAstListOfPorts) {
    std::vector<VExprIdentifierHandle> vecIdentifier;
    AstPortHandle pAstPortFst = pAstListOfPorts->element(0)._pPort0;
    std::vector<VExprIdentifierHandle> vecFst =
        ConvertAst2VExpr::convert(pAstPortFst);
    vecIdentifier.insert(vecIdentifier.end(), vecFst.begin(), vecFst.end());

    AstZeroOrMoreCommaPortHandle pAstZeroOrMoreCommaPort = pAstListOfPorts->element(0)._pZeroOrMoreCommaPort1;

    CONST_FOR_EACH(x, pAstZeroOrMoreCommaPort->container()) {
        AstPortHandle pAstPort = x._pPort;
        std::vector<VExprIdentifierHandle> vecOthers =
            ConvertAst2VExpr::convert(pAstPort);
        vecIdentifier.insert(vecIdentifier.end(), vecOthers.begin(), vecOthers.end());
    }

    return vecIdentifier;
}

    
VExprModuleHandle ConvertAst2VExpr::convert(const AstModuleDeclarationHandle & pAstModuleDeclaration) {
    VExprIdentifierHandle pIdentifier =
        ConvertAst2VExpr::convert(pAstModuleDeclaration->element(0)._pIdentifier1);

    AstZeroOrOneListOfPortsHandle pAstZeroOrOneListOfPorts = pAstModuleDeclaration->element(0)._pZeroOrOneListOfPorts2;

    std::vector<VExprIdentifierHandle> vecPortIdentifier;
    if (pAstZeroOrOneListOfPorts->element_size() != 0) {
        vecPortIdentifier = 
            ConvertAst2VExpr::convert(pAstZeroOrOneListOfPorts->element(0)._pListOfPorts);
    }
    
    AstZeroOrMoreModuleItemHandle pAstZeroOrMoreModuleItemHandle = pAstModuleDeclaration->element(0)._pZeroOrMoreModuleItem3;
    std::vector<VExprModuleItemHandle> vecModuleItem =
        ConvertAst2VExpr::convert(pAstZeroOrMoreModuleItemHandle);

    return VExprModuleHandle(VExprModule(pIdentifier, vecPortIdentifier, vecModuleItem));
}


std::vector<VExprModuleHandle> ConvertAst2VExpr::convert(const AstSourceTextHandle & pSourceText) {

    const AstOneOrMoreDescriptionHandle pOneOrMoreDescription = pSourceText->one_or_more_description();

    std::vector<VExprModuleHandle> vecModule;

    CONST_FOR_EACH(x, pOneOrMoreDescription->container()) {
        AstDescriptionHandle pDescription =x._pDescription0;
        VExprModuleHandle pModule =
            ConvertAst2VExpr::convert(pDescription->module_declaration());
        vecModule.push_back(pModule);
    }
    return vecModule;

#if 0
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
#endif
}

