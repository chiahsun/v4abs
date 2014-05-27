#ifndef PEXPR_TYPE_H
#define PEXPR_TYPE_H

class PExpr;
typedef SharedPtr<PExpr> PExprHandle;

class PExprIdentifier;
typedef SharedPtr<PExpr> PExprIdentifierHandle;

class PExprSourceText;
typedef SharedPtr<PExprSourceText> PExprSourceTextHandle;

class PExprStateStatement;
typedef SharedPtr<PExprStateStatement> PExprStateStatementHandle;

class PExprTransitionStatement;
typedef SharedPtr<PExprTransitionStatement> PExprTransitionStatementHandle;

class PExprStateLabel;
typedef SharedPtr<PExprStateLabel> PExprStateLabelHandle;

class PExprEdgeStatement;
typedef SharedPtr<PExprEdgeStatement> PExprEdgeStatementHandle;

class PExprUpdateStatement;
typedef SharedPtr<PExprUpdateStatement> PExprUpdateStatementHandle;

class PExprAllUpdateStatement;
typedef SharedPtr<PExprAllUpdateStatement> PExprAllUpdateStatementHandle;

class PExprSpecificUpdateStatement;
typedef SharedPtr<PExprSpecificUpdateStatement> PExprSpecificUpdateStatementHandle;

class PExprReadOrWriteOrCheckStatement;
typedef SharedPtr<PExprReadOrWriteOrCheckStatement> PExprReadOrWriteOrCheckStatementHandle;

class PExprReadStatement;
typedef SharedPtr<PExprReadStatement> PExprReadStatementHandle;

class PExprWriteStatement;
typedef SharedPtr<PExprWriteStatement> PExprWriteStatementHandle;

class PExprCheckStatement;
typedef SharedPtr<PExprCheckStatement> PExprCheckStatementHandle;

class PExprEndStatement;
typedef SharedPtr<PExprEndStatement> PExprEndStatementHandle;

class PExprIfStatementWithGoto;
typedef SharedPtr<PExprIfStatementWithGoto> PExprIfStatementWithGotoHandle;

class PExprIfStatementWithoutGoto;
typedef SharedPtr<PExprIfStatementWithoutGoto> PExprIfStatementWithoutGotoHandle;

class PExprIfStatementPrefix;
typedef SharedPtr<PExprIfStatementPrefix> PExprIfStatementPrefixHandle;

class PExprGotoStatement;
typedef SharedPtr<PExprGotoStatement> PExprGotoStatementHandle;

class PExprExpression;
typedef SharedPtr<PExprExpression> PExprExpressionHandle;

class PExprBoolExpression;
typedef SharedPtr<PExprBoolExpression> PExprBoolExpressionHandle;

class PExprConstant;
typedef SharedPtr<PExprConstant> PExprConstantHandle;

class PExprAssertStatement;
typedef SharedPtr<PExprAssertStatement> PExprAssertStatementHandle;


#endif // PEXPR_TYPE_H
