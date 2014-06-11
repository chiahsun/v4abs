#ifndef CONVERT_VEXPR_TO_VREXPR_H
#define CONVERT_VEXPR_TO_VREXPR_H

#include "VRExprModule.h"
#include "verilog/vexpr/VExpr.h"

class ConvertVExpr2VRExpr {
public:
    static VRExprModule convert(VExprFlatModuleHandle pFlatModule);

    static std::vector<VRExprAssignment> convert(VExprContinuousAssignmentHandle pContinuousAssignment);
    static std::vector<VRExprAssignment> convert(VExprInitialHandle pInitial);
    static VRExprAssignment convert(VExprNetAssignmentHandle pNetAssignment);
    static std::vector<VRExprAssignment> convert(VExprAlwaysHandle pAlways);

    static std::vector<VRExprAssignment> convert(VExprStatementOrNullHandle pStatementOrNull);
    static std::vector<VRExprAssignment> convert(VExprStatementHandle pStatement);

    static std::vector<VRExprAssignment> convert(VExprBlockingAssignmentHandle pBlockingAssignment);
    static std::vector<VRExprAssignment> convert(VExprNonBlockingAssignmentHandle pNonBlockingAssignment);
    static std::vector<VRExprAssignment> convert(VExprSeqBlockHandle pSeqBlock);
    static std::vector<VRExprAssignment> convert(VExprConditionalStatementHandle pConditional);
    static std::vector<VRExprAssignment> convert(VExprCaseStatementHandle pCaseStatement);
    static std::vector<VRExprAssignment> convert(VExprProceduralContinuousAssignmentHandle pProceduralAssignemnt);
    static VRExprAssignment convert(VExprRegAssignmentHandle pRegAssignment);
    static std::vector<VRExprAssignment> convert(VExprEventStatementHandle pEventStatement);
    static VRExprExpression convert(VExprPosedgeEventHandle pPosedgeEvent);
    static VRExprExpression convert(VExprNegedgeEventHandle pNegedgeEvent);

    static VRExprExpression convert(VExprNetLvalueHandle pNetLvalue); 

   
    static VRExprExpression convert(VExprExpressionHandle pExpression);
    static VRExprPrimary convert(VExprPrimaryHandle pPrimary);

    static VRExprMultConcatentation convert(VExprMultipleConcatenationHandle pMultipleConcatenation);
    static VRExprConcatenation convert(VExprConcatenationHandle pConcatenation);
     
    static VRExprSelectIdentifier convert(VExprSelectIdentifierHandle pSelectIdentifier);
    static VRExprSelect convert(VExprSelectHandle pSelect);
    static VRExprRangeSelect convert(VExprRangeSelectHandle pRangeSelect);
    static VRExprBitSelect convert(VExprBitSelectHandle pBitSelect);

    static VRExprIdentifier convert(VExprIdentifierHandle pIdentifier);

    static VRExprNumber convert(VExprNumberHandle pNumber);
    static VRExprUnsignedNumber convert(VExprUnsignedNumberHandle pUnsignedNumber);
    static VRExprBinaryNumber convert(VExprBinaryNumberHandle pBinaryNumber);
    static VRExprOctalNumber convert(VExprOctalNumberHandle pOctalNumber);
    static VRExprDecimalNumber convert(VExprDecimalNumberHandle pDecimalNumber);
    static VRExprHexNumber convert(VExprHexNumberHandle pHexNumber);

};


#endif // CONVERT_VEXPR_TO_VREXPR_H
