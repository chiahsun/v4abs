#ifndef CONVERT_AST_TO_VEXPR_H
#define CONVERT_AST_TO_VEXPR_H 

#include "nstl/for_each/ForEach.h"
#include "verilog/vast/Ast.h"
#include "verilog/vexpr/VExpr.h"
#include "ConvertUtil.h"

/**
 * Reference
 *  1. Why not use specialized function templates
 *  http://www.gotw.ca/publications/mill17.htm
 */

class ConvertAst2VExpr {
public:
    
    static VExprUnsignedNumberHandle convert(const AstUnsignedNumberHandle & pAst);
    
    static VExprBinaryNumberHandle convert(const AstBinaryNumberHandle & pBinaryNumber); 
    static VExprOctalNumberHandle convert(const AstOctalNumberHandle & pOctalNumber);
    static VExprDecimalNumberHandle convert(const AstDecimalNumberHandle & pDecimalNumber);
    static VExprHexNumberHandle convert(const AstHeximalNumberHandle & pHexNumber);
    static VExprNumberHandle convert(const AstNumberHandle & pNumber);
    static VExprSingleIdentifierHandle convert(const AstSimpleIdentifierHandle & pAstSimpleIdentifier);
    static VExprSingleIdentifierHandle convert(const AstSingleIdentifierHandle & pAstSingleIdentifier);
    static VExprHierIdentifierHandle convert(const AstMultiIdentifierHandle & pAstMultiIdentifier);
    static VExprIdentifierHandle convert(const AstIdentifierHandle & pAstIdentifier);

    static VExprPrimaryHandle convert(const AstPrimaryHandle & pAstPrimary);
    static VExprUnaryHandle convert(const AstUnaryExpressionHandle & pAstUnaryExpression);
    static VExprExpressionHandle convert(const AstExpressionHandle & pExpression);
    static VExprBinaryHandle convert(const AstBinaryExpressionHandle & pAstBinaryExpression);
    static VExprTernaryHandle convert(const AstTernaryExpressionHandle & pAstTernaryExpression);


    static VExprBitSelectHandle convert(const AstBitSelectHandle & pBitSelect);
    static VExprRangeSelectHandle convert(const AstRangeSelectHandle & pRangeSelect);
    static VExprSelectHandle convert(const AstSelectHandle & pSelect);
   
    static VExprSelectIdentifierHandle convert(const AstSelectIdentifierHandle & pAstSelectIdentifier);
    static VExprConcatenationHandle convert(const AstConcatenationHandle & pAstConcatenation);
    static VExprMultipleConcatenationHandle convert(const AstMultipleConcatenationHandle & pAstMultipleConcatenation);
    static VExprConstantPrimaryHandle convert(const AstConstantPrimaryHandle & pAstConstantPrimary);

    static VExprConstantUnaryHandle convert(const AstUnaryConstantExpressionHandle & pAstUnaryConstantExpression);
    static VExprConstantBinaryHandle convert(const AstBinaryConstantExpressionHandle & pAstBinaryConstantExpression);
    static VExprConstantExpressionHandle convert(const AstConstantExpressionHandle & pAstConstantExpression);
    static VExprConstantTernaryHandle convert(const AstTernaryConstantExpressionHandle & pAstTernaryConstantExpression);
    
    static VExprRangeHandle convert(const AstRangeHandle & pRange);
    static VExprNetLvalueHandle convert(const AstNetLvalueHandle & pAstNetLvalue);
    static VExprNetAssignmentHandle convert(const AstNetAssignmentHandle & pAstNetAssignment);
    static std::vector<VExprNetAssignmentHandle> convert(const AstListOfNetAssignmentsHandle & pAstListOfNetAssignment);
    static VExprContinuousAssignmentHandle convert(const AstContinuousAssignHandle & pAstContinuousAssign);

    static VExprRegLvalueHandle convert(const AstRegLvalueHandle & pAstRegLvalue);
    static VExprBlockingAssignmentHandle convert(const AstBlockingAssignmentHandle & pAstBlockingAssignment);
    static VExprNonBlockingAssignmentHandle convert(const AstNonBlockingAssignmentHandle & pAstNonBlockingAssignment);
    static VExprStatementHandle convert(const AstStatementHandle & pAstStatement);

    static VExprRegAssignmentHandle convert(const AstRegAssignmentHandle & pAstRegAssignment);
    static VExprProceduralContinuousAssignmentHandle convert(const AstProceduralContinuousAssignmentHandle & pAstProceduralContinuousAssignment);
    static VExprStatementOrNullHandle convert(const AstElseStatementOrNullHandle & pAstElseStatementOrNull);
    static VExprStatementOrNullHandle convert(const AstStatementOrNullHandle & pAstStatementOrNull);
    static VExprStatementOrNullHandle convert(const AstZeroOrOneElseStatementOrNullHandle & pAstZeroOrOneElseStatementOrNull);
    static VExprConditionalStatementHandle convert(const AstConditionalStatementHandle & pAstConditionalStatement);

    static VExprCaseItemHandle convert(const AstCaseItemHandle & pAstCaseItem);
    static VExprCaseStatementHandle convert(const AstCaseStatementHandle & pAstCaseStatement);
    static VExprLoopStatementHandle convert(const AstLoopStatementHandle & pAstLoopStatement);
    static VExprSeqBlockHandle convert(const AstSeqBlockHandle & pAstSeqBlock);

    static VExprPosedgeEventHandle convert(const AstPosedgeExpressionHandle & pAstPosedgeExpression);
    static VExprNegedgeEventHandle convert(const AstNegedgeExpressionHandle & pAstNegedgeExpression);
    static VExprEventExpressionHandle convert(const AstEventExpressionHandle & pAstEventExpression);
    static VExprEventExpressionHandle convert(const AstEventControlHandle & pAstEventControl);
    static VExprEventExpressionHandle convert(const AstDelayOrEventControlHandle & pAstDelayOrEventControl);
    static VExprEventStatementHandle convert(const AstProceduralTimingControlStatementHandle & pAstProceduralTimingControlStatement);


    static VExprParamAssignmentHandle convert(const AstParamAssignmentHandle & pAstParamAssignment);
    static VExprParameterDeclarationHandle convert(const AstParameterDeclarationHandle & pAstParameterDeclaration);

    static VExprInputDeclarationHandle convert(const AstInputDeclarationHandle & pAstInputDeclaration);
    static VExprOutputDeclarationHandle convert(const AstOutputDeclarationHandle & pAstOutputDeclaration);
    static VExprInoutDeclarationHandle convert(const AstInoutDeclarationHandle & pAstInoutDeclaration);

    static VExprNetDeclarationHandle convert(const AstNetDeclarationHandle & pAstNetDeclaration);

    static VExprRegisterNameHandle convert(const AstRegisterNameHandle & pAstRegisterName);
    static std::vector<VExprRegisterNameHandle> convert(const AstListOfRegisterIdentifiersHandle & pAstListOfRegisterNameIdentifiers);
    static VExprRegDeclarationHandle convert(const AstRegDeclarationHandle & pAstRegDeclaration);

    static VExprIntegerDeclarationHandle convert(const AstIntegerDeclarationHandle & pIntegerDeclaration);

    static VExprModuleItemDeclarationHandle convert(const AstModuleItemDeclarationHandle& pAstModuleItemDeclaration);

    static VExprNameOfInstanceHandle convert(const AstNameOfInstanceHandle& pAstNameOfInstance);
    static VExprExpressionHandle convert(const AstZeroOrOneExpressionHandle & pAstZeroOrOneExpression);
    static VExprOrderedPortConnectionHandle convert(const AstOrderedPortConnectionHandle & pAstOrderedPortConnection);
    static VExprNamedPortConnectionHandle convert(const AstNamedPortConnectionHandle & pAstNamedPortConnection);
    static VExprListOfModuleConnectionsHandle convert(const AstListOfModuleConnectionsHandle & pAstListOfModuleConnections);
    static VExprModuleInstanceHandle convert(const AstModuleInstanceHandle & pModuleInstance);
    static VExprModuleInstantiationHandle convert(const AstModuleInstantiationHandle & pAstModuleInstantiation);

    static VExprAlwaysHandle convert(const AstAlwaysConstructHandle & pAstAlwaysConstruct);
    static VExprInitialHandle convert(const AstInitialConstructHandle & pAstInitialConstruct);

    static VExprModuleItemHandle convert(const AstModuleItemHandle & pAstModuleItem);
    static std::vector<VExprModuleItemHandle> convert(const AstZeroOrMoreModuleItemHandle & pAstZeroOrMoreModuletItem);

    static VExprIdentifierHandle convert(const AstPortReferenceHandle & pPortReference);
    static std::vector<VExprIdentifierHandle> convert(const AstPortExpressionHandle & pAstPortExpression);
    static std::vector<VExprIdentifierHandle> convert(const AstPortHandle & pAstPort);
    static std::vector<VExprIdentifierHandle> convert(const AstListOfPortsHandle & pAstListOfPorts);

    static VExprModuleHandle convert(const AstModuleDeclarationHandle & pAstModuleDeclaration);

    static std::vector<VExprModuleHandle> convert(const AstSourceTextHandle & pSourceText); 
};

template <class _IODeclaration, class _AstDeclaration, class _IODecl>
SharedPtr<_IODeclaration> convertIOAst2VExpr(const _AstDeclaration & pAstIoDeclaration) {
    AstZeroOrOneRangeHandle pAstZeroOrOneRange = pAstIoDeclaration->element(0)._pZeroOrOneRange1;
    
    AstListOfPortIdentifiersHandle pAstListOfPortIdentifiers = pAstIoDeclaration->element(0)._pListOfPortIdentifiers2;

    std::vector<VExprIdentifierHandle> vecIdentifier;
    vecIdentifier.push_back(ConvertAst2VExpr::convert(pAstListOfPortIdentifiers->element(0)._pIdentifier0));

    AstZeroOrMoreCommaIdentifierHandle pAstZeroOreMoreCommaIdentifier = pAstListOfPortIdentifiers->element(0)._pZeroOrMoreCommaIdentifier1;

    CONST_FOR_EACH(elem, pAstZeroOreMoreCommaIdentifier->container()) {
        VExprIdentifierHandle pIdentifier =
            ConvertAst2VExpr::convert(elem._pIdentifier);
        vecIdentifier.push_back(pIdentifier);
    }


    std::vector<SharedPtr<_IODecl> > vecInputDecl;
    if (pAstZeroOrOneRange->element_size() == 0) {
        CONST_FOR_EACH(x, vecIdentifier) {
            VExprPortDeclarationHandle pPortDeclaration =
                VExprPortDeclarationHandle(VExprPortDeclaration(x));
            vecInputDecl.push_back(SharedPtr<_IODecl>(_IODecl(pPortDeclaration)));
        }
    } else if (pAstZeroOrOneRange->element_size() == 1) {
        VExprRangeHandle pRange =
            ConvertAst2VExpr::convert(pAstZeroOrOneRange->element(0)._pRange);
        CONST_FOR_EACH(x, vecIdentifier) {
            VExprPortDeclarationHandle pPortDeclaration =
                VExprPortDeclarationHandle(VExprPortDeclaration(pRange, x));
            vecInputDecl.push_back(SharedPtr<_IODecl>(_IODecl(pPortDeclaration)));
        }
    } else {
        assert(0);
    }

    return SharedPtr<_IODeclaration>(_IODeclaration(vecInputDecl));
}
    

#endif // CONVERT_AST_TO_VEXPR_H
