#ifndef CONVERT_PEXPR_TO_VREXPR_H
#define CONVERT_PEXPR_TO_VREXPR_H

#include "verilog/vrexpr/VRExpr.h"
#include "protocol/pexpr/PExpr.h"

class ConvertPExpr2VRExpr {
public:
    static void convert( PExprUpdateStatementHandle pUpdateStatement 
                       , std::vector<VRExprExpression> & vecRead
                       , std::vector<VRExprExpression> & vecWrite
                       , std::vector<VRExprExpression> & vecCheck);

    static void convert( PExprAllUpdateStatementHandle pAllUpdateStatement
                       , std::vector<VRExprExpression> & vecRead
                       , std::vector<VRExprExpression> & vecWrite
                       , std::vector<VRExprExpression> & vecCheck);

    static void convert( PExprSpecificUpdateStatementHandle pSpecificUpdateStatement
                       , std::vector<VRExprExpression> & vecRead
                       , std::vector<VRExprExpression> & vecWrite
                       , std::vector<VRExprExpression> & vecCheck);

    static void convert( PExprReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement
                       , std::vector<VRExprExpression> & vecRead
                       , std::vector<VRExprExpression> & vecWrite
                       , std::vector<VRExprExpression> & vecCheck);

    static void convert(PExprIfStatementWithoutGotoHandle pIfStatement
                       , std::vector<VRExprExpression> & vecReadAll
                       , std::vector<VRExprExpression> & vecWriteAll
                       , std::vector<VRExprExpression> & vecCheckAll);

    static VRExprExpression convert(PExprCheckStatementHandle pCheck);
                      

    static void convert( PExprIfStatementWithGotoHandle pIfStatement
                       , std::vector<VRExprExpression> & vecReadAll
                       , std::vector<VRExprExpression> & vecWriteAll
                       , std::vector<VRExprExpression> & vecCheckAll);

    static VRExprExpression convert(PExprIfStatementPrefixHandle pIfStatementPrefix);


    static VRExprExpression convert(PExprBoolExpressionHandle pBoolExpression);

    static VRExprPrimary convertToPrimary(PExprBoolExpressionHandle pBoolExpression);
    static VRExprIdentifier convertIdentifier(PExprBoolExpressionHandle pBoolExpression);
    static VRExprNumber convertConstant(PExprBoolExpressionHandle pBoolExpression);
    static VRExprExpression convertUnary(PExprBoolExpressionHandle  pBoolExpression);
    static VRExprExpression convertBinary(PExprBoolExpressionHandle pBoolExpression);

    static VRExprNumber convert(PExprConstantHandle pConstant);

    static void appendIf( std::vector<VRExprExpression> & vecExpr
                      , VRExprExpression pIf);
    static void appendVec( std::vector<VRExprExpression> & vec
                         , const std::vector<VRExprExpression> & vecOther);
};

#endif // CONVERT_PEXPR_TO_VREXPR_H
