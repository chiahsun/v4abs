#ifndef CONVERT_CAST_TO_PEXPR_H
#define CONVERT_CAST_TO_PEXPR_H

#include "PExpr.h"
#include "nstl/for_each/ForEach.h"
#include "protocol/past/CAst.h"

class ConvertCAst2PExpr {
public:
    static PExprConstantHandle convert(const CAstConstantHandle & pConstant);
    static PExprAssertStatementHandle convert(const CAstAssertStatementHandle & pAssertStatement);
    static PExprReadStatementHandle convert(const CAstReadStatementHandle & pReadStatement);
    static PExprWriteStatementHandle convert(const CAstWriteStatementHandle & pWriteStatement);
    static PExprStateLabelHandle convert(const CAstStateLabelHandle & pStateLabel);
    static PExprGotoStatementHandle convert(const CAstGotoStatementHandle & pGotoStatement);
    static PExprBoolExpressionHandle convert(const CAstBoolExpressionHandle & pBoolExpression);
    static PExprCheckStatementHandle convert(const CAstCheckStatementHandle & pCheckStatement);
    static PExprReadOrWriteOrCheckStatementHandle convert(const CAstReadOrWriteOrCheckStatementHandle & pReadOrWriteOrCheckStatement);
    static PExprIfStatementPrefixHandle convert(const CAstIfStatementPrefixHandle & pIfStatementPrefix);
    static PExprIfStatementWithoutGotoHandle convert(const CAstIfStatementWithoutGotoHandle & pIfStatementWithoutGoto);
    static PExprIfStatementWithGotoHandle convert(const CAstIfStatementWithGotoHandle & pIfStatementWithGoto);
    static PExprEndStatementHandle convert(const CAstEndStatementHandle & pEndStatement);
    static PExprSpecificUpdateStatementHandle convert(const CAstSpecificUpdateStatementHandle & pSpecificUpdateStatement);
    static PExprAllUpdateStatementHandle convert(const CAstAllUpdateStatementHandle & pAllUpdateStatement);
    static PExprEdgeStatementHandle convert(const CAstEdgeStatementHandle & pEdgeStatement);
    static PExprTransitionStatementHandle convert(const CAstTransitionStatementHandle & pTransitionStatement);
    static PExprStateStatementHandle convert(const CAstStateStatementHandle & pStateStatement);
    static PExprSourceTextHandle convert(const CAstSourceTextHandle & pSourceText);
};


#endif // CONVERT_CAST_TO_PEXPR_H
