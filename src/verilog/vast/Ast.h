#ifndef AST_H
#define AST_H

#include <vector>

#include <string>

#include "nstl/shared_ptr/SharedPtr.h"
#include "exception/Exception.h"

class Ast;
typedef SharedPtr<Ast> AstHandle;


class Ast {
public:
    virtual ~Ast();
    virtual std::string toString() const;
    virtual AstHandle base_handle() const;
};
class AstListOfPortIdentifiers;
typedef SharedPtr<AstListOfPortIdentifiers> AstListOfPortIdentifiersHandle;
class AstZeroOrOneListOfModuleConnections;
typedef SharedPtr<AstZeroOrOneListOfModuleConnections> AstZeroOrOneListOfModuleConnectionsHandle;
class AstZeroOrOneNameOfGateInstance;
typedef SharedPtr<AstZeroOrOneNameOfGateInstance> AstZeroOrOneNameOfGateInstanceHandle;
class AstBinaryOperatorNotEqual;
typedef SharedPtr<AstBinaryOperatorNotEqual> AstBinaryOperatorNotEqualHandle;
class AstBinaryOperatorXor;
typedef SharedPtr<AstBinaryOperatorXor> AstBinaryOperatorXorHandle;
class AstBinaryExpressionMinus;
typedef SharedPtr<AstBinaryExpressionMinus> AstBinaryExpressionMinusHandle;
class AstUnaryExpression;
typedef SharedPtr<AstUnaryExpression> AstUnaryExpressionHandle;
class AstBinaryOperatorLeq;
typedef SharedPtr<AstBinaryOperatorLeq> AstBinaryOperatorLeqHandle;
class AstKeywordParameter;
typedef SharedPtr<AstKeywordParameter> AstKeywordParameterHandle;
class AstKeywordMacroModule;
typedef SharedPtr<AstKeywordMacroModule> AstKeywordMacroModuleHandle;
class AstBinaryExpressionGeq;
typedef SharedPtr<AstBinaryExpressionGeq> AstBinaryExpressionGeqHandle;
class AstUnaryOperatorNot;
typedef SharedPtr<AstUnaryOperatorNot> AstUnaryOperatorNotHandle;
class AstZeroOrMoreCommaNetAssignment;
typedef SharedPtr<AstZeroOrMoreCommaNetAssignment> AstZeroOrMoreCommaNetAssignmentHandle;
class AstEventExpression;
typedef SharedPtr<AstEventExpression> AstEventExpressionHandle;
class AstZeroOrMoreCommaNamedPortConnection;
typedef SharedPtr<AstZeroOrMoreCommaNamedPortConnection> AstZeroOrMoreCommaNamedPortConnectionHandle;
class AstCaseItem;
typedef SharedPtr<AstCaseItem> AstCaseItemHandle;
class AstBinaryExpressionBwAnd;
typedef SharedPtr<AstBinaryExpressionBwAnd> AstBinaryExpressionBwAndHandle;
class AstIdentifier;
typedef SharedPtr<AstIdentifier> AstIdentifierHandle;
class AstContinuousAssign;
typedef SharedPtr<AstContinuousAssign> AstContinuousAssignHandle;
class AstNumber;
typedef SharedPtr<AstNumber> AstNumberHandle;
class AstNetLvalueBitSelect;
typedef SharedPtr<AstNetLvalueBitSelect> AstNetLvalueBitSelectHandle;
class AstExpression;
typedef SharedPtr<AstExpression> AstExpressionHandle;
class AstNamedPortExpression;
typedef SharedPtr<AstNamedPortExpression> AstNamedPortExpressionHandle;
class AstStatement;
typedef SharedPtr<AstStatement> AstStatementHandle;
class AstBinaryConstantExpressionEq;
typedef SharedPtr<AstBinaryConstantExpressionEq> AstBinaryConstantExpressionEqHandle;
class AstCaseStatement;
typedef SharedPtr<AstCaseStatement> AstCaseStatementHandle;
class AstListOfRegisterIdentifiers;
typedef SharedPtr<AstListOfRegisterIdentifiers> AstListOfRegisterIdentifiersHandle;
class AstRange;
typedef SharedPtr<AstRange> AstRangeHandle;
class AstBinaryOperatorSlash;
typedef SharedPtr<AstBinaryOperatorSlash> AstBinaryOperatorSlashHandle;
class AstProceduralContinuousAssignment;
typedef SharedPtr<AstProceduralContinuousAssignment> AstProceduralContinuousAssignmentHandle;
class AstSelect;
typedef SharedPtr<AstSelect> AstSelectHandle;
class AstBinaryOperatorNegXor;
typedef SharedPtr<AstBinaryOperatorNegXor> AstBinaryOperatorNegXorHandle;
class AstBinaryOperatorOrOr;
typedef SharedPtr<AstBinaryOperatorOrOr> AstBinaryOperatorOrOrHandle;
class AstSeqBlock;
typedef SharedPtr<AstSeqBlock> AstSeqBlockHandle;
class AstBlockingAssignment;
typedef SharedPtr<AstBlockingAssignment> AstBlockingAssignmentHandle;
class AstZeroOrMoreStatement;
typedef SharedPtr<AstZeroOrMoreStatement> AstZeroOrMoreStatementHandle;
class AstBinaryConstantExpressionGeq;
typedef SharedPtr<AstBinaryConstantExpressionGeq> AstBinaryConstantExpressionGeqHandle;
class AstTernaryExpression;
typedef SharedPtr<AstTernaryExpression> AstTernaryExpressionHandle;
class AstZeroOrMoreCommaParamAssignment;
typedef SharedPtr<AstZeroOrMoreCommaParamAssignment> AstZeroOrMoreCommaParamAssignmentHandle;
class AstDescription;
typedef SharedPtr<AstDescription> AstDescriptionHandle;
class AstKeywordOutput;
typedef SharedPtr<AstKeywordOutput> AstKeywordOutputHandle;
class AstBinaryConstantExpressionShiftRight;
typedef SharedPtr<AstBinaryConstantExpressionShiftRight> AstBinaryConstantExpressionShiftRightHandle;
class AstProceduralTimingControlStatement;
typedef SharedPtr<AstProceduralTimingControlStatement> AstProceduralTimingControlStatementHandle;
class AstInoutDeclaration;
typedef SharedPtr<AstInoutDeclaration> AstInoutDeclarationHandle;
class AstBinaryExpressionBwOr;
typedef SharedPtr<AstBinaryExpressionBwOr> AstBinaryExpressionBwOrHandle;
class AstListOfNetIdentifier;
typedef SharedPtr<AstListOfNetIdentifier> AstListOfNetIdentifierHandle;
class AstModuleItem;
typedef SharedPtr<AstModuleItem> AstModuleItemHandle;
class AstKeywordBegin;
typedef SharedPtr<AstKeywordBegin> AstKeywordBeginHandle;
class AstKeywordAlways;
typedef SharedPtr<AstKeywordAlways> AstKeywordAlwaysHandle;
class AstCaseItemDefault;
typedef SharedPtr<AstCaseItemDefault> AstCaseItemDefaultHandle;
class AstBlockingAssingmentSemicolon;
typedef SharedPtr<AstBlockingAssingmentSemicolon> AstBlockingAssingmentSemicolonHandle;
class AstKeywordFor;
typedef SharedPtr<AstKeywordFor> AstKeywordForHandle;
class AstZeroOrMoreCommaPortReference;
typedef SharedPtr<AstZeroOrMoreCommaPortReference> AstZeroOrMoreCommaPortReferenceHandle;
class AstRangeSelect;
typedef SharedPtr<AstRangeSelect> AstRangeSelectHandle;
class AstZeroOrMoreCommaIdentifier;
typedef SharedPtr<AstZeroOrMoreCommaIdentifier> AstZeroOrMoreCommaIdentifierHandle;
class AstBinaryConstantExpressionShiftLeft;
typedef SharedPtr<AstBinaryConstantExpressionShiftLeft> AstBinaryConstantExpressionShiftLeftHandle;
class AstTernaryConstantExpression;
typedef SharedPtr<AstTernaryConstantExpression> AstTernaryConstantExpressionHandle;
class AstUnaryOperatorMinus;
typedef SharedPtr<AstUnaryOperatorMinus> AstUnaryOperatorMinusHandle;
class AstInputDeclaration;
typedef SharedPtr<AstInputDeclaration> AstInputDeclarationHandle;
class AstZeroOrMoreCommaNInputGateInstance;
typedef SharedPtr<AstZeroOrMoreCommaNInputGateInstance> AstZeroOrMoreCommaNInputGateInstanceHandle;
class BracedConstantExpression;
typedef SharedPtr<BracedConstantExpression> BracedConstantExpressionHandle;
class AstKeywordWire;
typedef SharedPtr<AstKeywordWire> AstKeywordWireHandle;
class AstSimpleIdentifier;
typedef SharedPtr<AstSimpleIdentifier> AstSimpleIdentifierHandle;
class AstUnsignedNumber;
typedef SharedPtr<AstUnsignedNumber> AstUnsignedNumberHandle;
class AstKeywordEnd;
typedef SharedPtr<AstKeywordEnd> AstKeywordEndHandle;
class AstSelectIdentifier;
typedef SharedPtr<AstSelectIdentifier> AstSelectIdentifierHandle;
class AstBinaryExpressionEq;
typedef SharedPtr<AstBinaryExpressionEq> AstBinaryExpressionEqHandle;
class AstUnaryOperatorPlus;
typedef SharedPtr<AstUnaryOperatorPlus> AstUnaryOperatorPlusHandle;
class AstConstantRangeSelect;
typedef SharedPtr<AstConstantRangeSelect> AstConstantRangeSelectHandle;
class AstNetAssignment;
typedef SharedPtr<AstNetAssignment> AstNetAssignmentHandle;
class AstBinaryExpressionBwXor;
typedef SharedPtr<AstBinaryExpressionBwXor> AstBinaryExpressionBwXorHandle;
class AstUnaryOperatorXorNeg;
typedef SharedPtr<AstUnaryOperatorXorNeg> AstUnaryOperatorXorNegHandle;
class AstModuleInstance;
typedef SharedPtr<AstModuleInstance> AstModuleInstanceHandle;
class AstBinaryOperatorNotEqualEqual;
typedef SharedPtr<AstBinaryOperatorNotEqualEqual> AstBinaryOperatorNotEqualEqualHandle;
class AstProceduralContinuousAssignmentSemicolon;
typedef SharedPtr<AstProceduralContinuousAssignmentSemicolon> AstProceduralContinuousAssignmentSemicolonHandle;
class AstBinaryOperatorPlus;
typedef SharedPtr<AstBinaryOperatorPlus> AstBinaryOperatorPlusHandle;
class AstEventControl;
typedef SharedPtr<AstEventControl> AstEventControlHandle;
class AstZeroOrOneRange;
typedef SharedPtr<AstZeroOrOneRange> AstZeroOrOneRangeHandle;
class AstBinaryExpressionNeq;
typedef SharedPtr<AstBinaryExpressionNeq> AstBinaryExpressionNeqHandle;
class AstStatementOrNull;
typedef SharedPtr<AstStatementOrNull> AstStatementOrNullHandle;
class AstLoopStatement;
typedef SharedPtr<AstLoopStatement> AstLoopStatementHandle;
class AstBinaryConstantExpressionBwAnd;
typedef SharedPtr<AstBinaryConstantExpressionBwAnd> AstBinaryConstantExpressionBwAndHandle;
class AstNInputGateType;
typedef SharedPtr<AstNInputGateType> AstNInputGateTypeHandle;
class AstKeywordModule;
typedef SharedPtr<AstKeywordModule> AstKeywordModuleHandle;
class AstKeywordOr;
typedef SharedPtr<AstKeywordOr> AstKeywordOrHandle;
class AstConstantBitSelect;
typedef SharedPtr<AstConstantBitSelect> AstConstantBitSelectHandle;
class AstListOfParamAssignment;
typedef SharedPtr<AstListOfParamAssignment> AstListOfParamAssignmentHandle;
class AstGateInstantiationInput;
typedef SharedPtr<AstGateInstantiationInput> AstGateInstantiationInputHandle;
class AstZeroOrMoreModuleItem;
typedef SharedPtr<AstZeroOrMoreModuleItem> AstZeroOrMoreModuleItemHandle;
class AstParameterDeclaration;
typedef SharedPtr<AstParameterDeclaration> AstParameterDeclarationHandle;
class AstOneOrMoreSelect;
typedef SharedPtr<AstOneOrMoreSelect> AstOneOrMoreSelectHandle;
class AstBinaryConstantExpressionLt;
typedef SharedPtr<AstBinaryConstantExpressionLt> AstBinaryConstantExpressionLtHandle;
class AstKeywordInteger;
typedef SharedPtr<AstKeywordInteger> AstKeywordIntegerHandle;
class AstKeywordEndCase;
typedef SharedPtr<AstKeywordEndCase> AstKeywordEndCaseHandle;
class AstZeroOrMoreCommaOrderedPortConnection;
typedef SharedPtr<AstZeroOrMoreCommaOrderedPortConnection> AstZeroOrMoreCommaOrderedPortConnectionHandle;
class AstEventOrAsterisk;
typedef SharedPtr<AstEventOrAsterisk> AstEventOrAsteriskHandle;
class AstBinaryOperatorShr;
typedef SharedPtr<AstBinaryOperatorShr> AstBinaryOperatorShrHandle;
class AstUnaryOperatorNeg;
typedef SharedPtr<AstUnaryOperatorNeg> AstUnaryOperatorNegHandle;
class AstUnaryConstantExpression;
typedef SharedPtr<AstUnaryConstantExpression> AstUnaryConstantExpressionHandle;
class AstZeroOrMoreCommaInputTerminal;
typedef SharedPtr<AstZeroOrMoreCommaInputTerminal> AstZeroOrMoreCommaInputTerminalHandle;
class AstNegedgeExpression;
typedef SharedPtr<AstNegedgeExpression> AstNegedgeExpressionHandle;
class AstRegDeclaration;
typedef SharedPtr<AstRegDeclaration> AstRegDeclarationHandle;
class AstBinaryConstantExpressionLgAnd;
typedef SharedPtr<AstBinaryConstantExpressionLgAnd> AstBinaryConstantExpressionLgAndHandle;
class AstOneOrMoreCaseItem;
typedef SharedPtr<AstOneOrMoreCaseItem> AstOneOrMoreCaseItemHandle;
class AstKeywordInitial;
typedef SharedPtr<AstKeywordInitial> AstKeywordInitialHandle;
class AstBinaryExpressionBwNxor;
typedef SharedPtr<AstBinaryExpressionBwNxor> AstBinaryExpressionBwNxorHandle;
class AstListOfNetAssignments;
typedef SharedPtr<AstListOfNetAssignments> AstListOfNetAssignmentsHandle;
class AstSingleIdentifier;
typedef SharedPtr<AstSingleIdentifier> AstSingleIdentifierHandle;
class AstConstantExpression;
typedef SharedPtr<AstConstantExpression> AstConstantExpressionHandle;
class AstBinaryConstantExpressionMultiply;
typedef SharedPtr<AstBinaryConstantExpressionMultiply> AstBinaryConstantExpressionMultiplyHandle;
class AstOutputDeclaration;
typedef SharedPtr<AstOutputDeclaration> AstOutputDeclarationHandle;
class AstModuleKeyword;
typedef SharedPtr<AstModuleKeyword> AstModuleKeywordHandle;
class AstBinaryOperatorLt;
typedef SharedPtr<AstBinaryOperatorLt> AstBinaryOperatorLtHandle;
class AstNOutputGateType;
typedef SharedPtr<AstNOutputGateType> AstNOutputGateTypeHandle;
class AstDecimalNumber;
typedef SharedPtr<AstDecimalNumber> AstDecimalNumberHandle;
class AstBinaryOperatorTripleEqual;
typedef SharedPtr<AstBinaryOperatorTripleEqual> AstBinaryOperatorTripleEqualHandle;
class AstKeywordElse;
typedef SharedPtr<AstKeywordElse> AstKeywordElseHandle;
class AstBinaryConstantExpressionMinus;
typedef SharedPtr<AstBinaryConstantExpressionMinus> AstBinaryConstantExpressionMinusHandle;
class AstNameOfGateInstance;
typedef SharedPtr<AstNameOfGateInstance> AstNameOfGateInstanceHandle;
class AstUnaryOperatorNegAnd;
typedef SharedPtr<AstUnaryOperatorNegAnd> AstUnaryOperatorNegAndHandle;
class AstAlwaysConstruct;
typedef SharedPtr<AstAlwaysConstruct> AstAlwaysConstructHandle;
class AstOctalNumber;
typedef SharedPtr<AstOctalNumber> AstOctalNumberHandle;
class AstBinaryConstantExpression;
typedef SharedPtr<AstBinaryConstantExpression> AstBinaryConstantExpressionHandle;
class AstBinaryExpressionLgOr;
typedef SharedPtr<AstBinaryExpressionLgOr> AstBinaryExpressionLgOrHandle;
class AstBinaryOperatorEqualEqual;
typedef SharedPtr<AstBinaryOperatorEqualEqual> AstBinaryOperatorEqualEqualHandle;
class AstHeximalNumber;
typedef SharedPtr<AstHeximalNumber> AstHeximalNumberHandle;
class AstListOfPortReferences;
typedef SharedPtr<AstListOfPortReferences> AstListOfPortReferencesHandle;
class AstNetLvalue;
typedef SharedPtr<AstNetLvalue> AstNetLvalueHandle;
class AstBinaryOperatorAndAnd;
typedef SharedPtr<AstBinaryOperatorAndAnd> AstBinaryOperatorAndAndHandle;
class AstNInputGateInstance;
typedef SharedPtr<AstNInputGateInstance> AstNInputGateInstanceHandle;
class AstListOfPorts;
typedef SharedPtr<AstListOfPorts> AstListOfPortsHandle;
class AstOneOrMoreCommaExpression;
typedef SharedPtr<AstOneOrMoreCommaExpression> AstOneOrMoreCommaExpressionHandle;
class AstNamedPortConnection;
typedef SharedPtr<AstNamedPortConnection> AstNamedPortConnectionHandle;
class AstModuleItemDeclaration;
typedef SharedPtr<AstModuleItemDeclaration> AstModuleItemDeclarationHandle;
class AstBinaryConstantExpressionLeq;
typedef SharedPtr<AstBinaryConstantExpressionLeq> AstBinaryConstantExpressionLeqHandle;
class AstBinaryExpressionDivide;
typedef SharedPtr<AstBinaryExpressionDivide> AstBinaryExpressionDivideHandle;
class AstBinaryExpressionLt;
typedef SharedPtr<AstBinaryExpressionLt> AstBinaryExpressionLtHandle;
class AstRegisterName;
typedef SharedPtr<AstRegisterName> AstRegisterNameHandle;
class AstModuleInstantiation;
typedef SharedPtr<AstModuleInstantiation> AstModuleInstantiationHandle;
class AstBinaryConstantExpressionBwNxor;
typedef SharedPtr<AstBinaryConstantExpressionBwNxor> AstBinaryConstantExpressionBwNxorHandle;
class AstZeroOrMoreCommaPort;
typedef SharedPtr<AstZeroOrMoreCommaPort> AstZeroOrMoreCommaPortHandle;
class AstUnaryOperator;
typedef SharedPtr<AstUnaryOperator> AstUnaryOperatorHandle;
class AstNonBlockingAssignmentSemicolon;
typedef SharedPtr<AstNonBlockingAssignmentSemicolon> AstNonBlockingAssignmentSemicolonHandle;
class AstKeywordIf;
typedef SharedPtr<AstKeywordIf> AstKeywordIfHandle;
class AstBinaryExpressionMultiply;
typedef SharedPtr<AstBinaryExpressionMultiply> AstBinaryExpressionMultiplyHandle;
class AstNonBlockingAssignment;
typedef SharedPtr<AstNonBlockingAssignment> AstNonBlockingAssignmentHandle;
class AstZeroOrMoreCommaOutputTerminal;
typedef SharedPtr<AstZeroOrMoreCommaOutputTerminal> AstZeroOrMoreCommaOutputTerminalHandle;
class AstGateInstantiation;
typedef SharedPtr<AstGateInstantiation> AstGateInstantiationHandle;
class AstBinaryConstantExpressionModulus;
typedef SharedPtr<AstBinaryConstantExpressionModulus> AstBinaryConstantExpressionModulusHandle;
class AstBinaryConstantExpressionBwXnor;
typedef SharedPtr<AstBinaryConstantExpressionBwXnor> AstBinaryConstantExpressionBwXnorHandle;
class AstBinaryExpressionBwXnor;
typedef SharedPtr<AstBinaryExpressionBwXnor> AstBinaryExpressionBwXnorHandle;
class AstNetLvalueRangeSelect;
typedef SharedPtr<AstNetLvalueRangeSelect> AstNetLvalueRangeSelectHandle;
class AstBracedExpression;
typedef SharedPtr<AstBracedExpression> AstBracedExpressionHandle;
class AstBinaryOperator;
typedef SharedPtr<AstBinaryOperator> AstBinaryOperatorHandle;
class AstZeroOrMoreCommaRegisterName;
typedef SharedPtr<AstZeroOrMoreCommaRegisterName> AstZeroOrMoreCommaRegisterNameHandle;
class AstBinaryExpressionModulus;
typedef SharedPtr<AstBinaryExpressionModulus> AstBinaryExpressionModulusHandle;
class AstBinaryExpressionGt;
typedef SharedPtr<AstBinaryExpressionGt> AstBinaryExpressionGtHandle;
class AstUnaryOperatorAnd;
typedef SharedPtr<AstUnaryOperatorAnd> AstUnaryOperatorAndHandle;
class AstZeroOrOneElseStatementOrNull;
typedef SharedPtr<AstZeroOrOneElseStatementOrNull> AstZeroOrOneElseStatementOrNullHandle;
class AstBinaryConstantExpressionCaseNeq;
typedef SharedPtr<AstBinaryConstantExpressionCaseNeq> AstBinaryConstantExpressionCaseNeqHandle;
class AstSourceText;
typedef SharedPtr<AstSourceText> AstSourceTextHandle;
class AstEventOrEvent;
typedef SharedPtr<AstEventOrEvent> AstEventOrEventHandle;
class AstBinaryExpressionCaseEq;
typedef SharedPtr<AstBinaryExpressionCaseEq> AstBinaryExpressionCaseEqHandle;
class AstBinaryExpressionLgAnd;
typedef SharedPtr<AstBinaryExpressionLgAnd> AstBinaryExpressionLgAndHandle;
class AstZeroOrOneExpression;
typedef SharedPtr<AstZeroOrOneExpression> AstZeroOrOneExpressionHandle;
class AstBinaryNumber;
typedef SharedPtr<AstBinaryNumber> AstBinaryNumberHandle;
class AstMultipleConcatenation;
typedef SharedPtr<AstMultipleConcatenation> AstMultipleConcatenationHandle;
class AstBinaryConstantExpressionPlus;
typedef SharedPtr<AstBinaryConstantExpressionPlus> AstBinaryConstantExpressionPlusHandle;
class AstListOfOrderedPortConnection;
typedef SharedPtr<AstListOfOrderedPortConnection> AstListOfOrderedPortConnectionHandle;
class AstMultiIdentifier;
typedef SharedPtr<AstMultiIdentifier> AstMultiIdentifierHandle;
class AstKeywordPosedge;
typedef SharedPtr<AstKeywordPosedge> AstKeywordPosedgeHandle;
class AstBinaryExpressionPlus;
typedef SharedPtr<AstBinaryExpressionPlus> AstBinaryExpressionPlusHandle;
class AstUnaryOperatorNegXor;
typedef SharedPtr<AstUnaryOperatorNegXor> AstUnaryOperatorNegXorHandle;
class AstOutputTerminal;
typedef SharedPtr<AstOutputTerminal> AstOutputTerminalHandle;
class AstUnaryOperatorXor;
typedef SharedPtr<AstUnaryOperatorXor> AstUnaryOperatorXorHandle;
class AstKeywordReg;
typedef SharedPtr<AstKeywordReg> AstKeywordRegHandle;
class AstZeroOrMoreCommaNOutputGateInstance;
typedef SharedPtr<AstZeroOrMoreCommaNOutputGateInstance> AstZeroOrMoreCommaNOutputGateInstanceHandle;
class AstAtEventExpression;
typedef SharedPtr<AstAtEventExpression> AstAtEventExpressionHandle;
class AstInitialConstruct;
typedef SharedPtr<AstInitialConstruct> AstInitialConstructHandle;
class AstBinaryOperatorMinus;
typedef SharedPtr<AstBinaryOperatorMinus> AstBinaryOperatorMinusHandle;
class AstBinaryConstantExpressionDivide;
typedef SharedPtr<AstBinaryConstantExpressionDivide> AstBinaryConstantExpressionDivideHandle;
class AstKeywordAssign;
typedef SharedPtr<AstKeywordAssign> AstKeywordAssignHandle;
class AstIntegerDeclaration;
typedef SharedPtr<AstIntegerDeclaration> AstIntegerDeclarationHandle;
class AstBinaryConstantExpressionLgOr;
typedef SharedPtr<AstBinaryConstantExpressionLgOr> AstBinaryConstantExpressionLgOrHandle;
class AstBinaryConstantExpressionBwOr;
typedef SharedPtr<AstBinaryConstantExpressionBwOr> AstBinaryConstantExpressionBwOrHandle;
class AstNetType;
typedef SharedPtr<AstNetType> AstNetTypeHandle;
class AstDelayOrEventControl;
typedef SharedPtr<AstDelayOrEventControl> AstDelayOrEventControlHandle;
class AstNOutputGateInstance;
typedef SharedPtr<AstNOutputGateInstance> AstNOutputGateInstanceHandle;
class AstConditionalStatement;
typedef SharedPtr<AstConditionalStatement> AstConditionalStatementHandle;
class AstBinaryConstantExpressionGt;
typedef SharedPtr<AstBinaryConstantExpressionGt> AstBinaryConstantExpressionGtHandle;
class AstZeroOrOnePortExpression;
typedef SharedPtr<AstZeroOrOnePortExpression> AstZeroOrOnePortExpressionHandle;
class AstZeroOrOneConstantBitSelect;
typedef SharedPtr<AstZeroOrOneConstantBitSelect> AstZeroOrOneConstantBitSelectHandle;
class AstKeywordCase;
typedef SharedPtr<AstKeywordCase> AstKeywordCaseHandle;
class AstZeroOrMoreRegisterNameRange;
typedef SharedPtr<AstZeroOrMoreRegisterNameRange> AstZeroOrMoreRegisterNameRangeHandle;
class AstBinaryOperatorOr;
typedef SharedPtr<AstBinaryOperatorOr> AstBinaryOperatorOrHandle;
class AstCaseItemItem;
typedef SharedPtr<AstCaseItemItem> AstCaseItemItemHandle;
class AstUnaryOperatorNegOr;
typedef SharedPtr<AstUnaryOperatorNegOr> AstUnaryOperatorNegOrHandle;
class AstModuleDeclaration;
typedef SharedPtr<AstModuleDeclaration> AstModuleDeclarationHandle;
class AstBinaryConstantExpressionBwXor;
typedef SharedPtr<AstBinaryConstantExpressionBwXor> AstBinaryConstantExpressionBwXorHandle;
class AstConstantPrimary;
typedef SharedPtr<AstConstantPrimary> AstConstantPrimaryHandle;
class AstPosedgeExpression;
typedef SharedPtr<AstPosedgeExpression> AstPosedgeExpressionHandle;
class AstListOfModuleConnections;
typedef SharedPtr<AstListOfModuleConnections> AstListOfModuleConnectionsHandle;
class AstRegAssignment;
typedef SharedPtr<AstRegAssignment> AstRegAssignmentHandle;
class AstBinaryOperatorGeq;
typedef SharedPtr<AstBinaryOperatorGeq> AstBinaryOperatorGeqHandle;
class AstBinaryExpressionLeq;
typedef SharedPtr<AstBinaryExpressionLeq> AstBinaryExpressionLeqHandle;
class AstAtAsterisk;
typedef SharedPtr<AstAtAsterisk> AstAtAsteriskHandle;
class AstRegLvalue;
typedef SharedPtr<AstRegLvalue> AstRegLvalueHandle;
class AstBinaryOperatorAnd;
typedef SharedPtr<AstBinaryOperatorAnd> AstBinaryOperatorAndHandle;
class AstAtEventOrAsterisk;
typedef SharedPtr<AstAtEventOrAsterisk> AstAtEventOrAsteriskHandle;
class AstKeywordDefault;
typedef SharedPtr<AstKeywordDefault> AstKeywordDefaultHandle;
class AstBinaryExpressionShiftRight;
typedef SharedPtr<AstBinaryExpressionShiftRight> AstBinaryExpressionShiftRightHandle;
class AstListOfNamedPortConnection;
typedef SharedPtr<AstListOfNamedPortConnection> AstListOfNamedPortConnectionHandle;
class AstBinaryOperatorShl;
typedef SharedPtr<AstBinaryOperatorShl> AstBinaryOperatorShlHandle;
class AstKeywordEndmodule;
typedef SharedPtr<AstKeywordEndmodule> AstKeywordEndmoduleHandle;
class AstBinaryExpression;
typedef SharedPtr<AstBinaryExpression> AstBinaryExpressionHandle;
class AstBinaryConstantExpressionNeq;
typedef SharedPtr<AstBinaryConstantExpressionNeq> AstBinaryConstantExpressionNeqHandle;
class AstNameOfInstance;
typedef SharedPtr<AstNameOfInstance> AstNameOfInstanceHandle;
class AstConcatenation;
typedef SharedPtr<AstConcatenation> AstConcatenationHandle;
class AstConstantBitSelectIdentifier;
typedef SharedPtr<AstConstantBitSelectIdentifier> AstConstantBitSelectIdentifierHandle;
class AstBinaryOperatorPercent;
typedef SharedPtr<AstBinaryOperatorPercent> AstBinaryOperatorPercentHandle;
class AstZeroOrMoreCommaModuleInstance;
typedef SharedPtr<AstZeroOrMoreCommaModuleInstance> AstZeroOrMoreCommaModuleInstanceHandle;
class AstPortExpression;
typedef SharedPtr<AstPortExpression> AstPortExpressionHandle;
class AstGateInstantiationOutput;
typedef SharedPtr<AstGateInstantiationOutput> AstGateInstantiationOutputHandle;
class AstEventCommaEvent;
typedef SharedPtr<AstEventCommaEvent> AstEventCommaEventHandle;
class AstBinaryConstantExpressionCaseEq;
typedef SharedPtr<AstBinaryConstantExpressionCaseEq> AstBinaryConstantExpressionCaseEqHandle;
class AstPortReference;
typedef SharedPtr<AstPortReference> AstPortReferenceHandle;
class AstElseStatementOrNull;
typedef SharedPtr<AstElseStatementOrNull> AstElseStatementOrNullHandle;
class AstBinaryExpressionShiftLeft;
typedef SharedPtr<AstBinaryExpressionShiftLeft> AstBinaryExpressionShiftLeftHandle;
class AstPrimary;
typedef SharedPtr<AstPrimary> AstPrimaryHandle;
class AstBinaryExpressionCaseNeq;
typedef SharedPtr<AstBinaryExpressionCaseNeq> AstBinaryExpressionCaseNeqHandle;
class AstOrderedPortConnection;
typedef SharedPtr<AstOrderedPortConnection> AstOrderedPortConnectionHandle;
class AstParamAssignment;
typedef SharedPtr<AstParamAssignment> AstParamAssignmentHandle;
class AstKeywordInOut;
typedef SharedPtr<AstKeywordInOut> AstKeywordInOutHandle;
class AstConstantRangeSelectIdentifier;
typedef SharedPtr<AstConstantRangeSelectIdentifier> AstConstantRangeSelectIdentifierHandle;
class AstBitSelect;
typedef SharedPtr<AstBitSelect> AstBitSelectHandle;
class AstKetwordNegedge;
typedef SharedPtr<AstKetwordNegedge> AstKetwordNegedgeHandle;
class AstInputTerminal;
typedef SharedPtr<AstInputTerminal> AstInputTerminalHandle;
class AstZeroOrOneListOfPorts;
typedef SharedPtr<AstZeroOrOneListOfPorts> AstZeroOrOneListOfPortsHandle;
class AstPort;
typedef SharedPtr<AstPort> AstPortHandle;
class AstOneOrMoreDescription;
typedef SharedPtr<AstOneOrMoreDescription> AstOneOrMoreDescriptionHandle;
class AstBinaryOperatorAsterisk;
typedef SharedPtr<AstBinaryOperatorAsterisk> AstBinaryOperatorAsteriskHandle;
class AstZeroOrMoreCommaExpression;
typedef SharedPtr<AstZeroOrMoreCommaExpression> AstZeroOrMoreCommaExpressionHandle;
class AstAtIdentifier;
typedef SharedPtr<AstAtIdentifier> AstAtIdentifierHandle;
class AstKeywordInput;
typedef SharedPtr<AstKeywordInput> AstKeywordInputHandle;
class AstBinaryOperatorXorNeg;
typedef SharedPtr<AstBinaryOperatorXorNeg> AstBinaryOperatorXorNegHandle;
class AstZeroOrMoreDotSingleIdentifier;
typedef SharedPtr<AstZeroOrMoreDotSingleIdentifier> AstZeroOrMoreDotSingleIdentifierHandle;
class AstUnaryOperatorOr;
typedef SharedPtr<AstUnaryOperatorOr> AstUnaryOperatorOrHandle;
class AstBinaryOperatorGt;
typedef SharedPtr<AstBinaryOperatorGt> AstBinaryOperatorGtHandle;
class AstNetDeclaration;
typedef SharedPtr<AstNetDeclaration> AstNetDeclarationHandle;
class AstListOfPortIdentifiers
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrMoreCommaIdentifierHandle _pZeroOrMoreCommaIdentifier1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrMoreCommaIdentifier1 = pZeroOrMoreCommaIdentifier1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfPortIdentifiers();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOneListOfModuleConnections
  : public Ast {
    struct ElementType {
        AstListOfModuleConnectionsHandle _pListOfModuleConnections;
        ElementType(AstListOfModuleConnectionsHandle pListOfModuleConnections) {
            _pListOfModuleConnections = pListOfModuleConnections;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneListOfModuleConnections();
    void push_back(AstListOfModuleConnectionsHandle pListOfModuleConnections);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOneNameOfGateInstance
  : public Ast {
    struct ElementType {
        AstNameOfGateInstanceHandle _pNameOfGateInstance;
        ElementType(AstNameOfGateInstanceHandle pNameOfGateInstance) {
            _pNameOfGateInstance = pNameOfGateInstance;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneNameOfGateInstance();
    void push_back(AstNameOfGateInstanceHandle pNameOfGateInstance);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorNotEqual
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorNotEqual();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorXor
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorXor();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionMinus
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionMinus();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryExpression
  : public Ast {
    struct ElementType {
        AstUnaryOperatorHandle _pUnaryOperator0;
        AstPrimaryHandle _pPrimary1;
        ElementType(AstUnaryOperatorHandle pUnaryOperator0, AstPrimaryHandle pPrimary1) {
            _pUnaryOperator0 = pUnaryOperator0;
            _pPrimary1 = pPrimary1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryExpression();
    void push_back(AstUnaryOperatorHandle pUnaryOperator0, AstPrimaryHandle pPrimary1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorLeq
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorLeq();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordParameter : public Ast {
    std::string _keyword_parameter;
public:
    AstKeywordParameter(const std::string & s);
    std::string keyword_parameter() const;
    std::string toString() const;
};

class AstKeywordMacroModule : public Ast {
    std::string _keyword_macro_module;
public:
    AstKeywordMacroModule(const std::string & s);
    std::string keyword_macro_module() const;
    std::string toString() const;
};

class AstBinaryExpressionGeq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionGeq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorNot
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorNot();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaNetAssignment
  : public Ast {
    struct ElementType {
        AstNetAssignmentHandle _pNetAssignment;
        ElementType(AstNetAssignmentHandle pNetAssignment) {
            _pNetAssignment = pNetAssignment;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaNetAssignment();
    void push_back(AstNetAssignmentHandle pNetAssignment);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstEventExpression : public Ast {
    AstExpressionHandle _pExpression;
public:
    AstEventExpression(AstExpressionHandle pExpression);
    AstIdentifierHandle _pIdentifier;
public:
    AstEventExpression(AstIdentifierHandle pIdentifier);
    AstPosedgeExpressionHandle _pPosedgeExpression;
public:
    AstEventExpression(AstPosedgeExpressionHandle pPosedgeExpression);
    AstNegedgeExpressionHandle _pNegedgeExpression;
public:
    AstEventExpression(AstNegedgeExpressionHandle pNegedgeExpression);
    AstEventCommaEventHandle _pEventCommaEvent;
public:
    AstEventExpression(AstEventCommaEventHandle pEventCommaEvent);
    AstEventOrEventHandle _pEventOrEvent;
public:
    AstEventExpression(AstEventOrEventHandle pEventOrEvent);
    AstExpressionHandle expression() const;
    AstIdentifierHandle identifier() const;
    AstPosedgeExpressionHandle posedge_expression() const;
    AstNegedgeExpressionHandle negedge_expression() const;
    AstEventCommaEventHandle event_comma_event() const;
    AstEventOrEventHandle event_or_event() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaNamedPortConnection
  : public Ast {
    struct ElementType {
        AstNamedPortConnectionHandle _pNamedPortConnection;
        ElementType(AstNamedPortConnectionHandle pNamedPortConnection) {
            _pNamedPortConnection = pNamedPortConnection;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaNamedPortConnection();
    void push_back(AstNamedPortConnectionHandle pNamedPortConnection);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstCaseItem : public Ast {
    AstCaseItemItemHandle _pCaseItemItem;
public:
    AstCaseItem(AstCaseItemItemHandle pCaseItemItem);
    AstCaseItemDefaultHandle _pCaseItemDefault;
public:
    AstCaseItem(AstCaseItemDefaultHandle pCaseItemDefault);
    AstCaseItemItemHandle case_item_item() const;
    AstCaseItemDefaultHandle case_item_default() const;
    std::string toString() const;
};
class AstBinaryExpressionBwAnd
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionBwAnd();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstIdentifier : public Ast {
    AstSingleIdentifierHandle _pSingleIdentifier;
public:
    AstIdentifier(AstSingleIdentifierHandle pSingleIdentifier);
    AstMultiIdentifierHandle _pMultiIdentifier;
public:
    AstIdentifier(AstMultiIdentifierHandle pMultiIdentifier);
    AstSingleIdentifierHandle single_identifier() const;
    AstMultiIdentifierHandle multi_identifier() const;
    std::string toString() const;
};
class AstContinuousAssign
  : public Ast {
    struct ElementType {
        AstKeywordAssignHandle _pKeywordAssign0;
        AstListOfNetAssignmentsHandle _pListOfNetAssignments1;
        ElementType(AstKeywordAssignHandle pKeywordAssign0, AstListOfNetAssignmentsHandle pListOfNetAssignments1) {
            _pKeywordAssign0 = pKeywordAssign0;
            _pListOfNetAssignments1 = pListOfNetAssignments1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstContinuousAssign();
    void push_back(AstKeywordAssignHandle pKeywordAssign0, AstListOfNetAssignmentsHandle pListOfNetAssignments1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNumber : public Ast {
    AstUnsignedNumberHandle _pUnsignedNumber;
public:
    AstNumber(AstUnsignedNumberHandle pUnsignedNumber);
    AstBinaryNumberHandle _pBinaryNumber;
public:
    AstNumber(AstBinaryNumberHandle pBinaryNumber);
    AstOctalNumberHandle _pOctalNumber;
public:
    AstNumber(AstOctalNumberHandle pOctalNumber);
    AstDecimalNumberHandle _pDecimalNumber;
public:
    AstNumber(AstDecimalNumberHandle pDecimalNumber);
    AstHeximalNumberHandle _pHeximalNumber;
public:
    AstNumber(AstHeximalNumberHandle pHeximalNumber);
    AstUnsignedNumberHandle unsigned_number() const;
    AstBinaryNumberHandle binary_number() const;
    AstOctalNumberHandle octal_number() const;
    AstDecimalNumberHandle decimal_number() const;
    AstHeximalNumberHandle heximal_number() const;
    std::string toString() const;
};
class AstNetLvalueBitSelect
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstExpressionHandle _pExpression1;
        ElementType(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1) {
            _pIdentifier0 = pIdentifier0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNetLvalueBitSelect();
    void push_back(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstExpression : public Ast {
    AstPrimaryHandle _pPrimary;
public:
    AstExpression(AstPrimaryHandle pPrimary);
    AstBracedExpressionHandle _pBracedExpression;
public:
    AstExpression(AstBracedExpressionHandle pBracedExpression);
    AstUnaryExpressionHandle _pUnaryExpression;
public:
    AstExpression(AstUnaryExpressionHandle pUnaryExpression);
    AstTernaryExpressionHandle _pTernaryExpression;
public:
    AstExpression(AstTernaryExpressionHandle pTernaryExpression);
    AstBinaryExpressionHandle _pBinaryExpression;
public:
    AstExpression(AstBinaryExpressionHandle pBinaryExpression);
    AstPrimaryHandle primary() const;
    AstBracedExpressionHandle braced_expression() const;
    AstUnaryExpressionHandle unary_expression() const;
    AstTernaryExpressionHandle ternary_expression() const;
    AstBinaryExpressionHandle binary_expression() const;
    std::string toString() const;
};
class AstNamedPortExpression
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrOnePortExpressionHandle _pZeroOrOnePortExpression1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrOnePortExpressionHandle pZeroOrOnePortExpression1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrOnePortExpression1 = pZeroOrOnePortExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNamedPortExpression();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOnePortExpressionHandle pZeroOrOnePortExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstStatement : public Ast {
    AstBlockingAssingmentSemicolonHandle _pBlockingAssignmentSemicolon;
public:
    AstStatement(AstBlockingAssingmentSemicolonHandle pBlockingAssignmentSemicolon);
    AstNonBlockingAssignmentSemicolonHandle _pNonBlockingAssignmentSemicolon;
public:
    AstStatement(AstNonBlockingAssignmentSemicolonHandle pNonBlockingAssignmentSemicolon);
    AstProceduralContinuousAssignmentSemicolonHandle _pProceduralContinuousAssignmentSemicoln;
public:
    AstStatement(AstProceduralContinuousAssignmentSemicolonHandle pProceduralContinuousAssignmentSemicoln);
    AstProceduralTimingControlStatementHandle _pProceduralTimingControlStatement;
public:
    AstStatement(AstProceduralTimingControlStatementHandle pProceduralTimingControlStatement);
    AstConditionalStatementHandle _pConditionalStatement;
public:
    AstStatement(AstConditionalStatementHandle pConditionalStatement);
    AstCaseStatementHandle _pCaseStatement;
public:
    AstStatement(AstCaseStatementHandle pCaseStatement);
    AstLoopStatementHandle _pLoopStatement;
public:
    AstStatement(AstLoopStatementHandle pLoopStatement);
    AstSeqBlockHandle _pSeqBlock;
public:
    AstStatement(AstSeqBlockHandle pSeqBlock);
    AstBlockingAssingmentSemicolonHandle blocking_assignment_semicolon() const;
    AstNonBlockingAssignmentSemicolonHandle non_blocking_assignment_semicolon() const;
    AstProceduralContinuousAssignmentSemicolonHandle procedural_continuous_assignment_semicolon() const;
    AstProceduralTimingControlStatementHandle procedural_timing_control_statement() const;
    AstConditionalStatementHandle conditional_statement() const;
    AstCaseStatementHandle case_statement() const;
    AstLoopStatementHandle loop_statement() const;
    AstSeqBlockHandle seq_block() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionEq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionEq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstCaseStatement
  : public Ast {
    struct ElementType {
        AstKeywordCaseHandle _pKeywordCase0;
        AstExpressionHandle _pExpression1;
        AstOneOrMoreCaseItemHandle _pOneOrMoreCaseItem2;
        AstKeywordEndCaseHandle _pKeywordEndCase3;
        ElementType(AstKeywordCaseHandle pKeywordCase0, AstExpressionHandle pExpression1, AstOneOrMoreCaseItemHandle pOneOrMoreCaseItem2, AstKeywordEndCaseHandle pKeywordEndCase3) {
            _pKeywordCase0 = pKeywordCase0;
            _pExpression1 = pExpression1;
            _pOneOrMoreCaseItem2 = pOneOrMoreCaseItem2;
            _pKeywordEndCase3 = pKeywordEndCase3;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstCaseStatement();
    void push_back(AstKeywordCaseHandle pKeywordCase0, AstExpressionHandle pExpression1, AstOneOrMoreCaseItemHandle pOneOrMoreCaseItem2, AstKeywordEndCaseHandle pKeywordEndCase3);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfRegisterIdentifiers
  : public Ast {
    struct ElementType {
        AstRegisterNameHandle _pRegisterName0;
        AstZeroOrMoreCommaRegisterNameHandle _pZeroOrMoreCommaRegisterName1;
        ElementType(AstRegisterNameHandle pRegisterName0, AstZeroOrMoreCommaRegisterNameHandle pZeroOrMoreCommaRegisterName1) {
            _pRegisterName0 = pRegisterName0;
            _pZeroOrMoreCommaRegisterName1 = pZeroOrMoreCommaRegisterName1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfRegisterIdentifiers();
    void push_back(AstRegisterNameHandle pRegisterName0, AstZeroOrMoreCommaRegisterNameHandle pZeroOrMoreCommaRegisterName1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstRange
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstRange();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorSlash
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorSlash();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstProceduralContinuousAssignment
  : public Ast {
    struct ElementType {
        AstKeywordAssignHandle _pKeywordAssign0;
        AstRegAssignmentHandle _pRegAssignment1;
        ElementType(AstKeywordAssignHandle pKeywordAssign0, AstRegAssignmentHandle pRegAssignment1) {
            _pKeywordAssign0 = pKeywordAssign0;
            _pRegAssignment1 = pRegAssignment1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstProceduralContinuousAssignment();
    void push_back(AstKeywordAssignHandle pKeywordAssign0, AstRegAssignmentHandle pRegAssignment1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstSelect : public Ast {
    AstRangeSelectHandle _pRangeSelect;
public:
    AstSelect(AstRangeSelectHandle pRangeSelect);
    AstBitSelectHandle _pBitSelect;
public:
    AstSelect(AstBitSelectHandle pBitSelect);
    AstRangeSelectHandle range_select() const;
    AstBitSelectHandle bit_select() const;
    std::string toString() const;
};
class AstBinaryOperatorNegXor
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorNegXor();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorOrOr
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorOrOr();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstSeqBlock
  : public Ast {
    struct ElementType {
        AstKeywordBeginHandle _pKeywordBegin0;
        AstZeroOrMoreStatementHandle _pZeroOrMoreStatement1;
        AstKeywordEndHandle _pKeywordEnd2;
        ElementType(AstKeywordBeginHandle pKeywordBegin0, AstZeroOrMoreStatementHandle pZeroOrMoreStatement1, AstKeywordEndHandle pKeywordEnd2) {
            _pKeywordBegin0 = pKeywordBegin0;
            _pZeroOrMoreStatement1 = pZeroOrMoreStatement1;
            _pKeywordEnd2 = pKeywordEnd2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstSeqBlock();
    void push_back(AstKeywordBeginHandle pKeywordBegin0, AstZeroOrMoreStatementHandle pZeroOrMoreStatement1, AstKeywordEndHandle pKeywordEnd2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBlockingAssignment
  : public Ast {
    struct ElementType {
        AstRegLvalueHandle _pRegLvalue0;
        AstExpressionHandle _pExpression1;
        ElementType(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
            _pRegLvalue0 = pRegLvalue0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBlockingAssignment();
    void push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreStatement
  : public Ast {
    struct ElementType {
        AstStatementHandle _pStatement;
        ElementType(AstStatementHandle pStatement) {
            _pStatement = pStatement;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreStatement();
    void push_back(AstStatementHandle pStatement);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionGeq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionGeq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstTernaryExpression
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        AstExpressionHandle _pExpression2;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstExpressionHandle pExpression2) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
            _pExpression2 = pExpression2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstTernaryExpression();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstExpressionHandle pExpression2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaParamAssignment
  : public Ast {
    struct ElementType {
        AstParamAssignmentHandle _pParamAssignment;
        ElementType(AstParamAssignmentHandle pParamAssignment) {
            _pParamAssignment = pParamAssignment;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaParamAssignment();
    void push_back(AstParamAssignmentHandle pParamAssignment);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstDescription : public Ast {
    AstModuleDeclarationHandle _pModuleDeclaration;
public:
    AstDescription(AstModuleDeclarationHandle pModuleDeclaration);
    AstModuleDeclarationHandle module_declaration() const;
    std::string toString() const;
};
class AstKeywordOutput : public Ast {
    std::string _keyword_output;
public:
    AstKeywordOutput(const std::string & s);
    std::string keyword_output() const;
    std::string toString() const;
};

class AstBinaryConstantExpressionShiftRight
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionShiftRight();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstProceduralTimingControlStatement
  : public Ast {
    struct ElementType {
        AstDelayOrEventControlHandle _pDelayOrEventControl0;
        AstStatementOrNullHandle _pStatementOrNull1;
        ElementType(AstDelayOrEventControlHandle pDelayOrEventControl0, AstStatementOrNullHandle pStatementOrNull1) {
            _pDelayOrEventControl0 = pDelayOrEventControl0;
            _pStatementOrNull1 = pStatementOrNull1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstProceduralTimingControlStatement();
    void push_back(AstDelayOrEventControlHandle pDelayOrEventControl0, AstStatementOrNullHandle pStatementOrNull1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstInoutDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordInOutHandle _pKeywordInOut0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        AstListOfPortIdentifiersHandle _pListOfPortIdentifiers2;
        ElementType(AstKeywordInOutHandle pKeywordInOut0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
            _pKeywordInOut0 = pKeywordInOut0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
            _pListOfPortIdentifiers2 = pListOfPortIdentifiers2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstInoutDeclaration();
    void push_back(AstKeywordInOutHandle pKeywordInOut0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionBwOr
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionBwOr();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfNetIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrMoreCommaIdentifierHandle _pZeroOrMoreCommaIdentifier1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrMoreCommaIdentifier1 = pZeroOrMoreCommaIdentifier1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfNetIdentifier();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleItem : public Ast {
    AstAlwaysConstructHandle _pAlwaysConstruct;
public:
    AstModuleItem(AstAlwaysConstructHandle pAlwaysConstruct);
    AstInitialConstructHandle _pInitialConstruct;
public:
    AstModuleItem(AstInitialConstructHandle pInitialConstruct);
    AstModuleItemDeclarationHandle _pModuleItemDeclaration;
public:
    AstModuleItem(AstModuleItemDeclarationHandle pModuleItemDeclaration);
    AstContinuousAssignHandle _pContinuousAssign;
public:
    AstModuleItem(AstContinuousAssignHandle pContinuousAssign);
    AstGateInstantiationHandle _pGateInstantiation;
public:
    AstModuleItem(AstGateInstantiationHandle pGateInstantiation);
    AstModuleInstantiationHandle _pModuleInstantiation;
public:
    AstModuleItem(AstModuleInstantiationHandle pModuleInstantiation);
    AstAlwaysConstructHandle always_construct() const;
    AstInitialConstructHandle initial_construct() const;
    AstModuleItemDeclarationHandle module_item_declaration() const;
    AstContinuousAssignHandle continuous_assign() const;
    AstGateInstantiationHandle gate_instantiation() const;
    AstModuleInstantiationHandle module_instantiation() const;
    std::string toString() const;
};
class AstKeywordBegin : public Ast {
    std::string _keyword_begin;
public:
    AstKeywordBegin(const std::string & s);
    std::string keyword_begin() const;
    std::string toString() const;
};

class AstKeywordAlways : public Ast {
    std::string _keyword_always;
public:
    AstKeywordAlways(const std::string & s);
    std::string keyword_always() const;
    std::string toString() const;
};

class AstCaseItemDefault
  : public Ast {
    struct ElementType {
        AstKeywordDefaultHandle _pKeywordDefault0;
        AstStatementOrNullHandle _pStatementOrNull1;
        ElementType(AstKeywordDefaultHandle pKeywordDefault0, AstStatementOrNullHandle pStatementOrNull1) {
            _pKeywordDefault0 = pKeywordDefault0;
            _pStatementOrNull1 = pStatementOrNull1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstCaseItemDefault();
    void push_back(AstKeywordDefaultHandle pKeywordDefault0, AstStatementOrNullHandle pStatementOrNull1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBlockingAssingmentSemicolon
  : public Ast {
    struct ElementType {
        AstBlockingAssignmentHandle _pBlockingAssignment0;
        ElementType(AstBlockingAssignmentHandle pBlockingAssignment0) {
            _pBlockingAssignment0 = pBlockingAssignment0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBlockingAssingmentSemicolon();
    void push_back(AstBlockingAssignmentHandle pBlockingAssignment0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordFor : public Ast {
    std::string _keyword_for;
public:
    AstKeywordFor(const std::string & s);
    std::string keyword_for() const;
    std::string toString() const;
};

class AstZeroOrMoreCommaPortReference
  : public Ast {
    struct ElementType {
        AstPortReferenceHandle _pPortReference;
        ElementType(AstPortReferenceHandle pPortReference) {
            _pPortReference = pPortReference;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaPortReference();
    void push_back(AstPortReferenceHandle pPortReference);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstRangeSelect
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstRangeSelect();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier;
        ElementType(AstIdentifierHandle pIdentifier) {
            _pIdentifier = pIdentifier;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaIdentifier();
    void push_back(AstIdentifierHandle pIdentifier);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionShiftLeft
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionShiftLeft();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstTernaryConstantExpression
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        AstConstantExpressionHandle _pConstantExpression2;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
            _pConstantExpression2 = pConstantExpression2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstTernaryConstantExpression();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorMinus
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorMinus();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstInputDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordInputHandle _pKeywordInput0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        AstListOfPortIdentifiersHandle _pListOfPortIdentifiers2;
        ElementType(AstKeywordInputHandle pKeywordInput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
            _pKeywordInput0 = pKeywordInput0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
            _pListOfPortIdentifiers2 = pListOfPortIdentifiers2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstInputDeclaration();
    void push_back(AstKeywordInputHandle pKeywordInput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaNInputGateInstance
  : public Ast {
    struct ElementType {
        AstNInputGateInstanceHandle _pNInputGateInstance;
        ElementType(AstNInputGateInstanceHandle pNInputGateInstance) {
            _pNInputGateInstance = pNInputGateInstance;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaNInputGateInstance();
    void push_back(AstNInputGateInstanceHandle pNInputGateInstance);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class BracedConstantExpression
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        ElementType(AstConstantExpressionHandle pConstantExpression0) {
            _pConstantExpression0 = pConstantExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    BracedConstantExpression();
    void push_back(AstConstantExpressionHandle pConstantExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordWire : public Ast {
    std::string _keyword_wire;
public:
    AstKeywordWire(const std::string & s);
    std::string keyword_wire() const;
    std::string toString() const;
};

class AstSimpleIdentifier : public Ast {
    std::string _simple_identifier;
public:
    AstSimpleIdentifier(const std::string & s);
    std::string simple_identifier() const;
    std::string toString() const;
};

class AstUnsignedNumber : public Ast {
    std::string _unsigned_number;
public:
    AstUnsignedNumber(const std::string & s);
    std::string unsigned_number() const;
    std::string toString() const;
};

class AstKeywordEnd : public Ast {
    std::string _keyword_end;
public:
    AstKeywordEnd(const std::string & s);
    std::string keyword_end() const;
    std::string toString() const;
};

class AstSelectIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstOneOrMoreSelectHandle _pOneOrMoreSelect1;
        ElementType(AstIdentifierHandle pIdentifier0, AstOneOrMoreSelectHandle pOneOrMoreSelect1) {
            _pIdentifier0 = pIdentifier0;
            _pOneOrMoreSelect1 = pOneOrMoreSelect1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstSelectIdentifier();
    void push_back(AstIdentifierHandle pIdentifier0, AstOneOrMoreSelectHandle pOneOrMoreSelect1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionEq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionEq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorPlus
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorPlus();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstConstantRangeSelect
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConstantRangeSelect();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNetAssignment
  : public Ast {
    struct ElementType {
        AstNetLvalueHandle _pNetLvalue0;
        AstExpressionHandle _pExpression1;
        ElementType(AstNetLvalueHandle pNetLvalue0, AstExpressionHandle pExpression1) {
            _pNetLvalue0 = pNetLvalue0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNetAssignment();
    void push_back(AstNetLvalueHandle pNetLvalue0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionBwXor
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionBwXor();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorXorNeg
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorXorNeg();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleInstance
  : public Ast {
    struct ElementType {
        AstNameOfInstanceHandle _pNameOfInstance0;
        AstListOfModuleConnectionsHandle _pListOfModuleConnections1;
        ElementType(AstNameOfInstanceHandle pNameOfInstance0, AstListOfModuleConnectionsHandle pListOfModuleConnections1) {
            _pNameOfInstance0 = pNameOfInstance0;
            _pListOfModuleConnections1 = pListOfModuleConnections1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstModuleInstance();
    void push_back(AstNameOfInstanceHandle pNameOfInstance0, AstListOfModuleConnectionsHandle pListOfModuleConnections1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorNotEqualEqual
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorNotEqualEqual();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstProceduralContinuousAssignmentSemicolon
  : public Ast {
    struct ElementType {
        AstProceduralContinuousAssignmentHandle _pProceduralContinuousAssignment0;
        ElementType(AstProceduralContinuousAssignmentHandle pProceduralContinuousAssignment0) {
            _pProceduralContinuousAssignment0 = pProceduralContinuousAssignment0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstProceduralContinuousAssignmentSemicolon();
    void push_back(AstProceduralContinuousAssignmentHandle pProceduralContinuousAssignment0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorPlus
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorPlus();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstEventControl : public Ast {
    AstAtIdentifierHandle _pAtIdentifier;
public:
    AstEventControl(AstAtIdentifierHandle pAtIdentifier);
    AstAtEventExpressionHandle _pAstEventExpression;
public:
    AstEventControl(AstAtEventExpressionHandle pAstEventExpression);
    AstAtAsteriskHandle _pAtAsterisk;
public:
    AstEventControl(AstAtAsteriskHandle pAtAsterisk);
    AstAtIdentifierHandle at_identifier() const;
    AstAtEventExpressionHandle at_event_expression() const;
    AstAtAsteriskHandle at_asterisk() const;
    std::string toString() const;
};
class AstZeroOrOneRange
  : public Ast {
    struct ElementType {
        AstRangeHandle _pRange;
        ElementType(AstRangeHandle pRange) {
            _pRange = pRange;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneRange();
    void push_back(AstRangeHandle pRange);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionNeq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionNeq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstStatementOrNull : public Ast {
    AstStatementHandle _pStatement;
public:
    AstStatementOrNull(AstStatementHandle pStatement);
    AstStatementHandle statement() const;
    std::string toString() const;
};
class AstLoopStatement
  : public Ast {
    struct ElementType {
        AstKeywordForHandle _pKeywordFor0;
        AstRegAssignmentHandle _pRegAssignment1;
        AstExpressionHandle _pExpression2;
        AstRegAssignmentHandle _pRegAssignment3;
        AstStatementHandle _pStatement4;
        ElementType(AstKeywordForHandle pKeywordFor0, AstRegAssignmentHandle pRegAssignment1, AstExpressionHandle pExpression2, AstRegAssignmentHandle pRegAssignment3, AstStatementHandle pStatement4) {
            _pKeywordFor0 = pKeywordFor0;
            _pRegAssignment1 = pRegAssignment1;
            _pExpression2 = pExpression2;
            _pRegAssignment3 = pRegAssignment3;
            _pStatement4 = pStatement4;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstLoopStatement();
    void push_back(AstKeywordForHandle pKeywordFor0, AstRegAssignmentHandle pRegAssignment1, AstExpressionHandle pExpression2, AstRegAssignmentHandle pRegAssignment3, AstStatementHandle pStatement4);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionBwAnd
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionBwAnd();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNInputGateType : public Ast {
    std::string _n_input_gatetype;
public:
    AstNInputGateType(const std::string & s);
    std::string n_input_gatetype() const;
    std::string toString() const;
};

class AstKeywordModule : public Ast {
    std::string _keyword_module;
public:
    AstKeywordModule(const std::string & s);
    std::string keyword_module() const;
    std::string toString() const;
};

class AstKeywordOr : public Ast {
    std::string _keyword_or;
public:
    AstKeywordOr(const std::string & s);
    std::string keyword_or() const;
    std::string toString() const;
};

class AstConstantBitSelect
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        ElementType(AstConstantExpressionHandle pConstantExpression0) {
            _pConstantExpression0 = pConstantExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConstantBitSelect();
    void push_back(AstConstantExpressionHandle pConstantExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfParamAssignment
  : public Ast {
    struct ElementType {
        AstParamAssignmentHandle _pParamAssignment0;
        AstZeroOrMoreCommaParamAssignmentHandle _pZeroOrMoreCommaParamAssignment1;
        ElementType(AstParamAssignmentHandle pParamAssignment0, AstZeroOrMoreCommaParamAssignmentHandle pZeroOrMoreCommaParamAssignment1) {
            _pParamAssignment0 = pParamAssignment0;
            _pZeroOrMoreCommaParamAssignment1 = pZeroOrMoreCommaParamAssignment1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfParamAssignment();
    void push_back(AstParamAssignmentHandle pParamAssignment0, AstZeroOrMoreCommaParamAssignmentHandle pZeroOrMoreCommaParamAssignment1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstGateInstantiationInput
  : public Ast {
    struct ElementType {
        AstNInputGateTypeHandle _pNInputGateType0;
        AstNInputGateInstanceHandle _pNInputGateInstance1;
        AstZeroOrMoreCommaNInputGateInstanceHandle _pZeroOrMoreCommaNInputGateInstance2;
        ElementType(AstNInputGateTypeHandle pNInputGateType0, AstNInputGateInstanceHandle pNInputGateInstance1, AstZeroOrMoreCommaNInputGateInstanceHandle pZeroOrMoreCommaNInputGateInstance2) {
            _pNInputGateType0 = pNInputGateType0;
            _pNInputGateInstance1 = pNInputGateInstance1;
            _pZeroOrMoreCommaNInputGateInstance2 = pZeroOrMoreCommaNInputGateInstance2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstGateInstantiationInput();
    void push_back(AstNInputGateTypeHandle pNInputGateType0, AstNInputGateInstanceHandle pNInputGateInstance1, AstZeroOrMoreCommaNInputGateInstanceHandle pZeroOrMoreCommaNInputGateInstance2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreModuleItem
  : public Ast {
    struct ElementType {
        AstModuleItemHandle _pModuleItem;
        ElementType(AstModuleItemHandle pModuleItem) {
            _pModuleItem = pModuleItem;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreModuleItem();
    void push_back(AstModuleItemHandle pModuleItem);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstParameterDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordParameterHandle _pKeywordParameter0;
        AstListOfParamAssignmentHandle _pListOfParamAssignment1;
        ElementType(AstKeywordParameterHandle pKeywordParameter0, AstListOfParamAssignmentHandle pListOfParamAssignment1) {
            _pKeywordParameter0 = pKeywordParameter0;
            _pListOfParamAssignment1 = pListOfParamAssignment1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstParameterDeclaration();
    void push_back(AstKeywordParameterHandle pKeywordParameter0, AstListOfParamAssignmentHandle pListOfParamAssignment1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOneOrMoreSelect
  : public Ast {
    struct ElementType {
        AstSelectHandle _pSelect0;
        ElementType(AstSelectHandle pSelect0) {
            _pSelect0 = pSelect0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOneOrMoreSelect();
    void push_back(AstSelectHandle pSelect0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionLt
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionLt();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordInteger : public Ast {
    std::string _keyword_integer;
public:
    AstKeywordInteger(const std::string & s);
    std::string keyword_integer() const;
    std::string toString() const;
};

class AstKeywordEndCase : public Ast {
    std::string _keyword_endcase;
public:
    AstKeywordEndCase(const std::string & s);
    std::string keyword_endcase() const;
    std::string toString() const;
};

class AstZeroOrMoreCommaOrderedPortConnection
  : public Ast {
    struct ElementType {
        AstOrderedPortConnectionHandle _pOrderedPortConnection;
        ElementType(AstOrderedPortConnectionHandle pOrderedPortConnection) {
            _pOrderedPortConnection = pOrderedPortConnection;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaOrderedPortConnection();
    void push_back(AstOrderedPortConnectionHandle pOrderedPortConnection);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstEventOrAsterisk : public Ast {
    AstEventExpressionHandle _pEventExpression;
public:
    AstEventOrAsterisk(AstEventExpressionHandle pEventExpression);
    AstEventExpressionHandle event_expression() const;
    std::string toString() const;
};
class AstBinaryOperatorShr
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorShr();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorNeg
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorNeg();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryConstantExpression
  : public Ast {
    struct ElementType {
        AstUnaryOperatorHandle _pUnaryOperator0;
        AstConstantPrimaryHandle _pConstantPrimary1;
        ElementType(AstUnaryOperatorHandle pUnaryOperator0, AstConstantPrimaryHandle pConstantPrimary1) {
            _pUnaryOperator0 = pUnaryOperator0;
            _pConstantPrimary1 = pConstantPrimary1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryConstantExpression();
    void push_back(AstUnaryOperatorHandle pUnaryOperator0, AstConstantPrimaryHandle pConstantPrimary1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaInputTerminal
  : public Ast {
    struct ElementType {
        AstInputTerminalHandle _pInputTerminal;
        ElementType(AstInputTerminalHandle pInputTerminal) {
            _pInputTerminal = pInputTerminal;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaInputTerminal();
    void push_back(AstInputTerminalHandle pInputTerminal);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNegedgeExpression
  : public Ast {
    struct ElementType {
        AstKetwordNegedgeHandle _pKeywordNegedge0;
        AstExpressionHandle _pExpression1;
        ElementType(AstKetwordNegedgeHandle pKeywordNegedge0, AstExpressionHandle pExpression1) {
            _pKeywordNegedge0 = pKeywordNegedge0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNegedgeExpression();
    void push_back(AstKetwordNegedgeHandle pKeywordNegedge0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstRegDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordRegHandle _pKeywordReg0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        AstListOfRegisterIdentifiersHandle _pListOfRegisterIdentifiers2;
        ElementType(AstKeywordRegHandle pKeywordReg0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers2) {
            _pKeywordReg0 = pKeywordReg0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
            _pListOfRegisterIdentifiers2 = pListOfRegisterIdentifiers2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstRegDeclaration();
    void push_back(AstKeywordRegHandle pKeywordReg0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionLgAnd
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionLgAnd();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOneOrMoreCaseItem
  : public Ast {
    struct ElementType {
        AstCaseItemHandle _pCaseItem0;
        ElementType(AstCaseItemHandle pCaseItem0) {
            _pCaseItem0 = pCaseItem0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOneOrMoreCaseItem();
    void push_back(AstCaseItemHandle pCaseItem0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordInitial : public Ast {
    std::string _keyword_initial;
public:
    AstKeywordInitial(const std::string & s);
    std::string keyword_initial() const;
    std::string toString() const;
};

class AstBinaryExpressionBwNxor
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionBwNxor();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfNetAssignments
  : public Ast {
    struct ElementType {
        AstNetAssignmentHandle _pNetAssignment0;
        AstZeroOrMoreCommaNetAssignmentHandle _pZeroOrMoreCommaNetAssignment1;
        ElementType(AstNetAssignmentHandle pNetAssignment0, AstZeroOrMoreCommaNetAssignmentHandle pZeroOrMoreCommaNetAssignment1) {
            _pNetAssignment0 = pNetAssignment0;
            _pZeroOrMoreCommaNetAssignment1 = pZeroOrMoreCommaNetAssignment1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfNetAssignments();
    void push_back(AstNetAssignmentHandle pNetAssignment0, AstZeroOrMoreCommaNetAssignmentHandle pZeroOrMoreCommaNetAssignment1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstSingleIdentifier : public Ast {
    AstSimpleIdentifierHandle _pSimpleIdentifier;
public:
    AstSingleIdentifier(AstSimpleIdentifierHandle pSimpleIdentifier);
    AstSimpleIdentifierHandle simple_identifier() const;
    std::string toString() const;
};
class AstConstantExpression : public Ast {
    BracedConstantExpressionHandle _pBracedConstantExpression;
public:
    AstConstantExpression(BracedConstantExpressionHandle pBracedConstantExpression);
    AstConstantPrimaryHandle _pConstantPrimary;
public:
    AstConstantExpression(AstConstantPrimaryHandle pConstantPrimary);
    AstUnaryConstantExpressionHandle _pUnaryConstantExpression;
public:
    AstConstantExpression(AstUnaryConstantExpressionHandle pUnaryConstantExpression);
    AstTernaryConstantExpressionHandle _pTernaryConstantExpression;
public:
    AstConstantExpression(AstTernaryConstantExpressionHandle pTernaryConstantExpression);
    AstBinaryConstantExpressionHandle _pBinaryConstantExpression;
public:
    AstConstantExpression(AstBinaryConstantExpressionHandle pBinaryConstantExpression);
    BracedConstantExpressionHandle braced_constant_expression() const;
    AstConstantPrimaryHandle constant_primary() const;
    AstUnaryConstantExpressionHandle unary_constant_expression() const;
    AstTernaryConstantExpressionHandle ternary_constant_expression() const;
    AstBinaryConstantExpressionHandle binary_constant_expression() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionMultiply
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionMultiply();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOutputDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordOutputHandle _pKeywordOutput0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        AstListOfPortIdentifiersHandle _pListOfPortIdentifiers2;
        ElementType(AstKeywordOutputHandle pKeywordOutput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
            _pKeywordOutput0 = pKeywordOutput0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
            _pListOfPortIdentifiers2 = pListOfPortIdentifiers2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOutputDeclaration();
    void push_back(AstKeywordOutputHandle pKeywordOutput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleKeyword : public Ast {
    AstKeywordModuleHandle _pKeywordModule;
public:
    AstModuleKeyword(AstKeywordModuleHandle pKeywordModule);
    AstKeywordMacroModuleHandle _pKeywordMacroModule;
public:
    AstModuleKeyword(AstKeywordMacroModuleHandle pKeywordMacroModule);
    AstKeywordModuleHandle keyword_module() const;
    AstKeywordMacroModuleHandle keyword_macro_module() const;
    std::string toString() const;
};
class AstBinaryOperatorLt
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorLt();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNOutputGateType : public Ast {
    std::string _n_output_gatetype;
public:
    AstNOutputGateType(const std::string & s);
    std::string n_output_gatetype() const;
    std::string toString() const;
};

class AstDecimalNumber : public Ast {
    std::string _decimal_number;
public:
    AstDecimalNumber(const std::string & s);
    std::string decimal_number() const;
    std::string toString() const;
};

class AstBinaryOperatorTripleEqual
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorTripleEqual();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordElse : public Ast {
    std::string _keyword_else;
public:
    AstKeywordElse(const std::string & s);
    std::string keyword_else() const;
    std::string toString() const;
};

class AstBinaryConstantExpressionMinus
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionMinus();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNameOfGateInstance
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNameOfGateInstance();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorNegAnd
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorNegAnd();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstAlwaysConstruct
  : public Ast {
    struct ElementType {
        AstKeywordAlwaysHandle _pKeywordAlways0;
        AstStatementHandle _pStatement1;
        ElementType(AstKeywordAlwaysHandle pKeywordAlways0, AstStatementHandle pStatement1) {
            _pKeywordAlways0 = pKeywordAlways0;
            _pStatement1 = pStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstAlwaysConstruct();
    void push_back(AstKeywordAlwaysHandle pKeywordAlways0, AstStatementHandle pStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOctalNumber : public Ast {
    std::string _octal_number;
public:
    AstOctalNumber(const std::string & s);
    std::string octal_number() const;
    std::string toString() const;
};

class AstBinaryConstantExpression : public Ast {
    AstBinaryConstantExpressionMultiplyHandle _pBinaryConstantExpressionMultiply;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionMultiplyHandle pBinaryConstantExpressionMultiply);
    AstBinaryConstantExpressionDivideHandle _pBinaryConstantExpressionDivide;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionDivideHandle pBinaryConstantExpressionDivide);
    AstBinaryConstantExpressionModulusHandle _pBinaryConstantExpressionModulus;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionModulusHandle pBinaryConstantExpressionModulus);
    AstBinaryConstantExpressionPlusHandle _pBinaryConstantExpressionPlus;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionPlusHandle pBinaryConstantExpressionPlus);
    AstBinaryConstantExpressionMinusHandle _pBinaryConstantExpressionMinus;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionMinusHandle pBinaryConstantExpressionMinus);
    AstBinaryConstantExpressionShiftRightHandle _pBinaryConstantExpressionShiftRight;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionShiftRightHandle pBinaryConstantExpressionShiftRight);
    AstBinaryConstantExpressionShiftLeftHandle _pBinaryConstantExpressionShiftLeft;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionShiftLeftHandle pBinaryConstantExpressionShiftLeft);
    AstBinaryConstantExpressionGtHandle _pBinaryConstantExpressionGt;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionGtHandle pBinaryConstantExpressionGt);
    AstBinaryConstantExpressionGeqHandle _pBinaryConstantExpressionGeq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionGeqHandle pBinaryConstantExpressionGeq);
    AstBinaryConstantExpressionLtHandle _pBinaryConstantExpressionLt;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionLtHandle pBinaryConstantExpressionLt);
    AstBinaryConstantExpressionLeqHandle _pBinaryConstantExpressionLeq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionLeqHandle pBinaryConstantExpressionLeq);
    AstBinaryConstantExpressionEqHandle _pBinaryConstantExpressionEq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionEqHandle pBinaryConstantExpressionEq);
    AstBinaryConstantExpressionNeqHandle _pBinaryConstantExpressionNeq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionNeqHandle pBinaryConstantExpressionNeq);
    AstBinaryConstantExpressionCaseEqHandle _pBinaryConstantExpressionCaseEq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionCaseEqHandle pBinaryConstantExpressionCaseEq);
    AstBinaryConstantExpressionCaseNeqHandle _pBinaryConstantExpressionCaseNeq;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionCaseNeqHandle pBinaryConstantExpressionCaseNeq);
    AstBinaryConstantExpressionBwAndHandle _pBinaryConstantExpressionBwAnd;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionBwAndHandle pBinaryConstantExpressionBwAnd);
    AstBinaryConstantExpressionBwXorHandle _pBinaryConstantExpressionBwXor;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionBwXorHandle pBinaryConstantExpressionBwXor);
    AstBinaryConstantExpressionBwXnorHandle _pBinaryConstantExpressionBwXnor;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionBwXnorHandle pBinaryConstantExpressionBwXnor);
    AstBinaryConstantExpressionBwNxorHandle _pBinaryConstantExpressionBwNxor;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionBwNxorHandle pBinaryConstantExpressionBwNxor);
    AstBinaryConstantExpressionBwOrHandle _pBinaryConstantExpressionBwOr;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionBwOrHandle pBinaryConstantExpressionBwOr);
    AstBinaryConstantExpressionLgAndHandle _pBinaryConstantExpressionLgAnd;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionLgAndHandle pBinaryConstantExpressionLgAnd);
    AstBinaryConstantExpressionLgOrHandle _pBinaryConstantExpressionLgOr;
public:
    AstBinaryConstantExpression(AstBinaryConstantExpressionLgOrHandle pBinaryConstantExpressionLgOr);
    AstBinaryConstantExpressionMultiplyHandle binary_constant_expression_multiply() const;
    AstBinaryConstantExpressionDivideHandle binary_constant_expression_divide() const;
    AstBinaryConstantExpressionModulusHandle binary_constant_expression_modulus() const;
    AstBinaryConstantExpressionPlusHandle binary_constant_expression_plus() const;
    AstBinaryConstantExpressionMinusHandle binary_constant_expression_minus() const;
    AstBinaryConstantExpressionShiftRightHandle binary_constant_expression_shift_right() const;
    AstBinaryConstantExpressionShiftLeftHandle binary_constant_expression_shift_left() const;
    AstBinaryConstantExpressionGtHandle binary_constant_expression_gt() const;
    AstBinaryConstantExpressionGeqHandle binary_constant_expression_geq() const;
    AstBinaryConstantExpressionLtHandle binary_constant_expression_lt() const;
    AstBinaryConstantExpressionLeqHandle binary_constant_expression_leq() const;
    AstBinaryConstantExpressionEqHandle binary_constant_expression_eq() const;
    AstBinaryConstantExpressionNeqHandle binary_constant_expression_neq() const;
    AstBinaryConstantExpressionCaseEqHandle binary_constant_expression_case_eq() const;
    AstBinaryConstantExpressionCaseNeqHandle binary_constant_expression_case_neq() const;
    AstBinaryConstantExpressionBwAndHandle binary_constant_expression_bw_and() const;
    AstBinaryConstantExpressionBwXorHandle binary_constant_expression_bw_xor() const;
    AstBinaryConstantExpressionBwXnorHandle binary_constant_expression_bw_xnor() const;
    AstBinaryConstantExpressionBwNxorHandle binary_constant_expression_bw_nxor() const;
    AstBinaryConstantExpressionBwOrHandle binary_constant_expression_bw_or() const;
    AstBinaryConstantExpressionLgAndHandle binary_constant_expression_lg_and() const;
    AstBinaryConstantExpressionLgOrHandle binary_constant_expression_lg_or() const;
    std::string toString() const;
};
class AstBinaryExpressionLgOr
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionLgOr();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorEqualEqual
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorEqualEqual();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstHeximalNumber : public Ast {
    std::string _heximal_number;
public:
    AstHeximalNumber(const std::string & s);
    std::string heximal_number() const;
    std::string toString() const;
};

class AstListOfPortReferences
  : public Ast {
    struct ElementType {
        AstPortReferenceHandle _pPortReference0;
        AstZeroOrMoreCommaPortReferenceHandle _pZeroOrMoreCommaPortReference1;
        ElementType(AstPortReferenceHandle pPortReference0, AstZeroOrMoreCommaPortReferenceHandle pZeroOrMoreCommaPortReference1) {
            _pPortReference0 = pPortReference0;
            _pZeroOrMoreCommaPortReference1 = pZeroOrMoreCommaPortReference1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfPortReferences();
    void push_back(AstPortReferenceHandle pPortReference0, AstZeroOrMoreCommaPortReferenceHandle pZeroOrMoreCommaPortReference1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNetLvalue : public Ast {
    AstIdentifierHandle _pIdentifier;
public:
    AstNetLvalue(AstIdentifierHandle pIdentifier);
    AstNetLvalueBitSelectHandle _pNetLvalueBitSelect;
public:
    AstNetLvalue(AstNetLvalueBitSelectHandle pNetLvalueBitSelect);
    AstNetLvalueRangeSelectHandle _pNetLvalueRangeSelect;
public:
    AstNetLvalue(AstNetLvalueRangeSelectHandle pNetLvalueRangeSelect);
    AstConcatenationHandle _pAstConcatenation;
public:
    AstNetLvalue(AstConcatenationHandle pAstConcatenation);
    AstIdentifierHandle identifier() const;
    AstNetLvalueBitSelectHandle net_lvalue_bit_select() const;
    AstNetLvalueRangeSelectHandle net_lvalue_range_select() const;
    AstConcatenationHandle concatenation() const;
    std::string toString() const;
};
class AstBinaryOperatorAndAnd
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorAndAnd();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNInputGateInstance
  : public Ast {
    struct ElementType {
        AstZeroOrOneNameOfGateInstanceHandle _pZeroOrOneNameOfGateInstance0;
        AstOutputTerminalHandle _pOutputTerminal1;
        AstInputTerminalHandle _pInputTerminal2;
        AstZeroOrMoreCommaInputTerminalHandle _pZeroOrMoreCommaInputTerminal3;
        ElementType(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstInputTerminalHandle pInputTerminal2, AstZeroOrMoreCommaInputTerminalHandle pZeroOrMoreCommaInputTerminal3) {
            _pZeroOrOneNameOfGateInstance0 = pZeroOrOneNameOfGateInstance0;
            _pOutputTerminal1 = pOutputTerminal1;
            _pInputTerminal2 = pInputTerminal2;
            _pZeroOrMoreCommaInputTerminal3 = pZeroOrMoreCommaInputTerminal3;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNInputGateInstance();
    void push_back(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstInputTerminalHandle pInputTerminal2, AstZeroOrMoreCommaInputTerminalHandle pZeroOrMoreCommaInputTerminal3);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfPorts
  : public Ast {
    struct ElementType {
        AstPortHandle _pPort0;
        AstZeroOrMoreCommaPortHandle _pZeroOrMoreCommaPort1;
        ElementType(AstPortHandle pPort0, AstZeroOrMoreCommaPortHandle pZeroOrMoreCommaPort1) {
            _pPort0 = pPort0;
            _pZeroOrMoreCommaPort1 = pZeroOrMoreCommaPort1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfPorts();
    void push_back(AstPortHandle pPort0, AstZeroOrMoreCommaPortHandle pZeroOrMoreCommaPort1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOneOrMoreCommaExpression
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        ElementType(AstExpressionHandle pExpression0) {
            _pExpression0 = pExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOneOrMoreCommaExpression();
    void push_back(AstExpressionHandle pExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNamedPortConnection
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrOneExpressionHandle _pZeroOrOneExpression1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrOneExpressionHandle pZeroOrOneExpression1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrOneExpression1 = pZeroOrOneExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNamedPortConnection();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneExpressionHandle pZeroOrOneExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleItemDeclaration : public Ast {
    AstParameterDeclarationHandle _pParameterDeclaration;
public:
    AstModuleItemDeclaration(AstParameterDeclarationHandle pParameterDeclaration);
    AstInputDeclarationHandle _pInputDeclaration;
public:
    AstModuleItemDeclaration(AstInputDeclarationHandle pInputDeclaration);
    AstOutputDeclarationHandle _pOutputDeclaration;
public:
    AstModuleItemDeclaration(AstOutputDeclarationHandle pOutputDeclaration);
    AstInoutDeclarationHandle _pInoutDeclaration;
public:
    AstModuleItemDeclaration(AstInoutDeclarationHandle pInoutDeclaration);
    AstNetDeclarationHandle _pNetDeclaration;
public:
    AstModuleItemDeclaration(AstNetDeclarationHandle pNetDeclaration);
    AstRegDeclarationHandle _pRegDeclaration;
public:
    AstModuleItemDeclaration(AstRegDeclarationHandle pRegDeclaration);
    AstIntegerDeclarationHandle _pIntegerDeclaration;
public:
    AstModuleItemDeclaration(AstIntegerDeclarationHandle pIntegerDeclaration);
    AstParameterDeclarationHandle parameter_declaration() const;
    AstInputDeclarationHandle input_declaration() const;
    AstOutputDeclarationHandle output_declaration() const;
    AstInoutDeclarationHandle inout_declaration() const;
    AstNetDeclarationHandle net_declaration() const;
    AstRegDeclarationHandle reg_declaration() const;
    AstIntegerDeclarationHandle integer_declaration() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionLeq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionLeq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionDivide
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionDivide();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionLt
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionLt();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstRegisterName
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrMoreRegisterNameRangeHandle _pZeroOrMoreRegisterNameRange1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrMoreRegisterNameRangeHandle pZeroOrMoreRegisterNameRange1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrMoreRegisterNameRange1 = pZeroOrMoreRegisterNameRange1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstRegisterName();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreRegisterNameRangeHandle pZeroOrMoreRegisterNameRange1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleInstantiation
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstModuleInstanceHandle _pModuleInstance1;
        AstZeroOrMoreCommaModuleInstanceHandle _pZeroOrMoreCommaModuleInstance2;
        ElementType(AstIdentifierHandle pIdentifier0, AstModuleInstanceHandle pModuleInstance1, AstZeroOrMoreCommaModuleInstanceHandle pZeroOrMoreCommaModuleInstance2) {
            _pIdentifier0 = pIdentifier0;
            _pModuleInstance1 = pModuleInstance1;
            _pZeroOrMoreCommaModuleInstance2 = pZeroOrMoreCommaModuleInstance2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstModuleInstantiation();
    void push_back(AstIdentifierHandle pIdentifier0, AstModuleInstanceHandle pModuleInstance1, AstZeroOrMoreCommaModuleInstanceHandle pZeroOrMoreCommaModuleInstance2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionBwNxor
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionBwNxor();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaPort
  : public Ast {
    struct ElementType {
        AstPortHandle _pPort;
        ElementType(AstPortHandle pPort) {
            _pPort = pPort;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaPort();
    void push_back(AstPortHandle pPort);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperator : public Ast {
    AstUnaryOperatorPlusHandle _pUnaryOperatorPlus;
public:
    AstUnaryOperator(AstUnaryOperatorPlusHandle pUnaryOperatorPlus);
    AstUnaryOperatorMinusHandle _pUnaryOperatorMinus;
public:
    AstUnaryOperator(AstUnaryOperatorMinusHandle pUnaryOperatorMinus);
    AstUnaryOperatorNotHandle _pUnaryOperatorNot;
public:
    AstUnaryOperator(AstUnaryOperatorNotHandle pUnaryOperatorNot);
    AstUnaryOperatorNegHandle _pUnaryOperatorNeg;
public:
    AstUnaryOperator(AstUnaryOperatorNegHandle pUnaryOperatorNeg);
    AstUnaryOperatorAndHandle _pUnaryOperatorAnd;
public:
    AstUnaryOperator(AstUnaryOperatorAndHandle pUnaryOperatorAnd);
    AstUnaryOperatorNegAndHandle _pUnaryOperatorNegAnd;
public:
    AstUnaryOperator(AstUnaryOperatorNegAndHandle pUnaryOperatorNegAnd);
    AstUnaryOperatorOrHandle _pUnaryOperatorOr;
public:
    AstUnaryOperator(AstUnaryOperatorOrHandle pUnaryOperatorOr);
    AstUnaryOperatorNegOrHandle _pUnaryOperatorNegOr;
public:
    AstUnaryOperator(AstUnaryOperatorNegOrHandle pUnaryOperatorNegOr);
    AstUnaryOperatorXorHandle _pUnaryOperatorXor;
public:
    AstUnaryOperator(AstUnaryOperatorXorHandle pUnaryOperatorXor);
    AstUnaryOperatorNegXorHandle _pUnaryOperatorNegXor;
public:
    AstUnaryOperator(AstUnaryOperatorNegXorHandle pUnaryOperatorNegXor);
    AstUnaryOperatorXorNegHandle _pUnaryOperatorXorNeg;
public:
    AstUnaryOperator(AstUnaryOperatorXorNegHandle pUnaryOperatorXorNeg);
    AstUnaryOperatorPlusHandle unary_operator_plus() const;
    AstUnaryOperatorMinusHandle unary_operator_minus() const;
    AstUnaryOperatorNotHandle unary_operator_not() const;
    AstUnaryOperatorNegHandle unary_operator_neg() const;
    AstUnaryOperatorAndHandle unary_operator_and() const;
    AstUnaryOperatorNegAndHandle unary_operator_neg_and() const;
    AstUnaryOperatorOrHandle unary_operator_or() const;
    AstUnaryOperatorNegOrHandle unary_operator_neg_or() const;
    AstUnaryOperatorXorHandle unary_operator_xor() const;
    AstUnaryOperatorNegXorHandle unary_operator_neg_xor() const;
    AstUnaryOperatorXorNegHandle unary_operator_xor_neg() const;
    std::string toString() const;
};
class AstNonBlockingAssignmentSemicolon
  : public Ast {
    struct ElementType {
        AstNonBlockingAssignmentHandle _pNonBlockingAssignment0;
        ElementType(AstNonBlockingAssignmentHandle pNonBlockingAssignment0) {
            _pNonBlockingAssignment0 = pNonBlockingAssignment0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNonBlockingAssignmentSemicolon();
    void push_back(AstNonBlockingAssignmentHandle pNonBlockingAssignment0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordIf : public Ast {
    std::string _keyword_if;
public:
    AstKeywordIf(const std::string & s);
    std::string keyword_if() const;
    std::string toString() const;
};

class AstBinaryExpressionMultiply
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionMultiply();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNonBlockingAssignment
  : public Ast {
    struct ElementType {
        AstRegLvalueHandle _pRegLvalue0;
        AstExpressionHandle _pExpression1;
        ElementType(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
            _pRegLvalue0 = pRegLvalue0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNonBlockingAssignment();
    void push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaOutputTerminal
  : public Ast {
    struct ElementType {
        AstOutputTerminalHandle _pOutputTerminal;
        ElementType(AstOutputTerminalHandle pOutputTerminal) {
            _pOutputTerminal = pOutputTerminal;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaOutputTerminal();
    void push_back(AstOutputTerminalHandle pOutputTerminal);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstGateInstantiation : public Ast {
    AstGateInstantiationInputHandle _pGateInstantiationInput;
public:
    AstGateInstantiation(AstGateInstantiationInputHandle pGateInstantiationInput);
    AstGateInstantiationOutputHandle _pGateInstantiationOutput;
public:
    AstGateInstantiation(AstGateInstantiationOutputHandle pGateInstantiationOutput);
    AstGateInstantiationInputHandle gate_instantiation_input() const;
    AstGateInstantiationOutputHandle gate_instantiation_output() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionModulus
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionModulus();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionBwXnor
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionBwXnor();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionBwXnor
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionBwXnor();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNetLvalueRangeSelect
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstConstantExpressionHandle _pConstantExpression1;
        AstConstantExpressionHandle _pConstantExpression2;
        ElementType(AstIdentifierHandle pIdentifier0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2) {
            _pIdentifier0 = pIdentifier0;
            _pConstantExpression1 = pConstantExpression1;
            _pConstantExpression2 = pConstantExpression2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNetLvalueRangeSelect();
    void push_back(AstIdentifierHandle pIdentifier0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBracedExpression
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        ElementType(AstExpressionHandle pExpression0) {
            _pExpression0 = pExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBracedExpression();
    void push_back(AstExpressionHandle pExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperator : public Ast {
    AstBinaryOperatorPlusHandle _pBinaryOperatorPlus;
public:
    AstBinaryOperator(AstBinaryOperatorPlusHandle pBinaryOperatorPlus);
    AstBinaryOperatorMinusHandle _pBinaryOperatorMinus;
public:
    AstBinaryOperator(AstBinaryOperatorMinusHandle pBinaryOperatorMinus);
    AstBinaryOperatorAsteriskHandle _pBinaryOperatorAsterisk;
public:
    AstBinaryOperator(AstBinaryOperatorAsteriskHandle pBinaryOperatorAsterisk);
    AstBinaryOperatorSlashHandle _pBinaryOperatorSlash;
public:
    AstBinaryOperator(AstBinaryOperatorSlashHandle pBinaryOperatorSlash);
    AstBinaryOperatorPercentHandle _pBinaryOperatorPercent;
public:
    AstBinaryOperator(AstBinaryOperatorPercentHandle pBinaryOperatorPercent);
    AstBinaryOperatorEqualEqualHandle _pBinaryOperatorEqualEqual;
public:
    AstBinaryOperator(AstBinaryOperatorEqualEqualHandle pBinaryOperatorEqualEqual);
    AstBinaryOperatorNotEqualHandle _pBinaryOperatorNotEqual;
public:
    AstBinaryOperator(AstBinaryOperatorNotEqualHandle pBinaryOperatorNotEqual);
    AstBinaryOperatorTripleEqualHandle _pBinaryOperatorTripleEqual;
public:
    AstBinaryOperator(AstBinaryOperatorTripleEqualHandle pBinaryOperatorTripleEqual);
    AstBinaryOperatorNotEqualEqualHandle _pBinaryOperatorNotEqualEqual;
public:
    AstBinaryOperator(AstBinaryOperatorNotEqualEqualHandle pBinaryOperatorNotEqualEqual);
    AstBinaryOperatorAndAndHandle _pBinaryOperatorAndAnd;
public:
    AstBinaryOperator(AstBinaryOperatorAndAndHandle pBinaryOperatorAndAnd);
    AstBinaryOperatorOrOrHandle _pBinaryOperatorOrOr;
public:
    AstBinaryOperator(AstBinaryOperatorOrOrHandle pBinaryOperatorOrOr);
    AstBinaryOperatorLtHandle _pBinaryOperatorLt;
public:
    AstBinaryOperator(AstBinaryOperatorLtHandle pBinaryOperatorLt);
    AstBinaryOperatorLeqHandle _pBinaryOperatorLeq;
public:
    AstBinaryOperator(AstBinaryOperatorLeqHandle pBinaryOperatorLeq);
    AstBinaryOperatorGtHandle _pBinaryOperatorGt;
public:
    AstBinaryOperator(AstBinaryOperatorGtHandle pBinaryOperatorGt);
    AstBinaryOperatorGeqHandle _pBinaryOperatorGeq;
public:
    AstBinaryOperator(AstBinaryOperatorGeqHandle pBinaryOperatorGeq);
    AstBinaryOperatorAndHandle _pBinaryOperatorAnd;
public:
    AstBinaryOperator(AstBinaryOperatorAndHandle pBinaryOperatorAnd);
    AstBinaryOperatorOrHandle _pBinaryOperatorOr;
public:
    AstBinaryOperator(AstBinaryOperatorOrHandle pBinaryOperatorOr);
    AstBinaryOperatorXorHandle _pBinaryOperatorXor;
public:
    AstBinaryOperator(AstBinaryOperatorXorHandle pBinaryOperatorXor);
    AstBinaryOperatorXorNegHandle _pBinaryOperatorXorNeg;
public:
    AstBinaryOperator(AstBinaryOperatorXorNegHandle pBinaryOperatorXorNeg);
    AstBinaryOperatorNegXorHandle _pBinaryOperatorNegXor;
public:
    AstBinaryOperator(AstBinaryOperatorNegXorHandle pBinaryOperatorNegXor);
    AstBinaryOperatorShrHandle _pBinaryOperatorShr;
public:
    AstBinaryOperator(AstBinaryOperatorShrHandle pBinaryOperatorShr);
    AstBinaryOperatorShlHandle _pBinaryOperatorShl;
public:
    AstBinaryOperator(AstBinaryOperatorShlHandle pBinaryOperatorShl);
    AstBinaryOperatorPlusHandle binary_operator_plus() const;
    AstBinaryOperatorMinusHandle binary_operator_minus() const;
    AstBinaryOperatorAsteriskHandle binary_operator_asterisk() const;
    AstBinaryOperatorSlashHandle binary_operator_slash() const;
    AstBinaryOperatorPercentHandle binary_operator_percent() const;
    AstBinaryOperatorEqualEqualHandle binary_operator_equal_equal() const;
    AstBinaryOperatorNotEqualHandle binary_operator_not_equal() const;
    AstBinaryOperatorTripleEqualHandle binary_operator_triple_equal() const;
    AstBinaryOperatorNotEqualEqualHandle binary_operator_not_equal_equal() const;
    AstBinaryOperatorAndAndHandle binary_operator_and_and() const;
    AstBinaryOperatorOrOrHandle binary_operator_or_or() const;
    AstBinaryOperatorLtHandle binary_operator_lt() const;
    AstBinaryOperatorLeqHandle binary_operator_leq() const;
    AstBinaryOperatorGtHandle binary_operator_gt() const;
    AstBinaryOperatorGeqHandle binary_operator_geq() const;
    AstBinaryOperatorAndHandle binary_operator_and() const;
    AstBinaryOperatorOrHandle binary_operator_or() const;
    AstBinaryOperatorXorHandle binary_operator_xor() const;
    AstBinaryOperatorXorNegHandle binary_operator_xor_neg() const;
    AstBinaryOperatorNegXorHandle binary_operator_neg_xor() const;
    AstBinaryOperatorShrHandle binary_operator_shr() const;
    AstBinaryOperatorShlHandle binary_operator_shl() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaRegisterName
  : public Ast {
    struct ElementType {
        AstRegisterNameHandle _pRegisterName;
        ElementType(AstRegisterNameHandle pRegisterName) {
            _pRegisterName = pRegisterName;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaRegisterName();
    void push_back(AstRegisterNameHandle pRegisterName);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionModulus
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionModulus();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionGt
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionGt();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorAnd
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorAnd();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOneElseStatementOrNull
  : public Ast {
    struct ElementType {
        AstElseStatementOrNullHandle _pElseStatementOrNull;
        ElementType(AstElseStatementOrNullHandle pElseStatementOrNull) {
            _pElseStatementOrNull = pElseStatementOrNull;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneElseStatementOrNull();
    void push_back(AstElseStatementOrNullHandle pElseStatementOrNull);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionCaseNeq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionCaseNeq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstSourceText : public Ast {
    AstOneOrMoreDescriptionHandle _pOneOrMoreDescription;
public:
    AstSourceText(AstOneOrMoreDescriptionHandle pOneOrMoreDescription);
    AstOneOrMoreDescriptionHandle one_or_more_description() const;
    std::string toString() const;
};
class AstEventOrEvent
  : public Ast {
    struct ElementType {
        AstEventExpressionHandle _pEventExpression0;
        AstKeywordOrHandle _pKeywordOr1;
        AstEventExpressionHandle _pEventExpression2;
        ElementType(AstEventExpressionHandle pEventExpression0, AstKeywordOrHandle pKeywordOr1, AstEventExpressionHandle pEventExpression2) {
            _pEventExpression0 = pEventExpression0;
            _pKeywordOr1 = pKeywordOr1;
            _pEventExpression2 = pEventExpression2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstEventOrEvent();
    void push_back(AstEventExpressionHandle pEventExpression0, AstKeywordOrHandle pKeywordOr1, AstEventExpressionHandle pEventExpression2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionCaseEq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionCaseEq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionLgAnd
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionLgAnd();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOneExpression
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression;
        ElementType(AstExpressionHandle pExpression) {
            _pExpression = pExpression;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneExpression();
    void push_back(AstExpressionHandle pExpression);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryNumber : public Ast {
    std::string _binary_number;
public:
    AstBinaryNumber(const std::string & s);
    std::string binary_number() const;
    std::string toString() const;
};

class AstMultipleConcatenation
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        AstZeroOrMoreCommaExpressionHandle _pZeroOrMoreCommaExpression2;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression2) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
            _pZeroOrMoreCommaExpression2 = pZeroOrMoreCommaExpression2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstMultipleConcatenation();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionPlus
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionPlus();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfOrderedPortConnection
  : public Ast {
    struct ElementType {
        AstOrderedPortConnectionHandle _pOrderedPortConnection0;
        AstZeroOrMoreCommaOrderedPortConnectionHandle _pZeroOrMoreCommaOrderedPortConnection1;
        ElementType(AstOrderedPortConnectionHandle pOrderedPortConnection0, AstZeroOrMoreCommaOrderedPortConnectionHandle pZeroOrMoreCommaOrderedPortConnection1) {
            _pOrderedPortConnection0 = pOrderedPortConnection0;
            _pZeroOrMoreCommaOrderedPortConnection1 = pZeroOrMoreCommaOrderedPortConnection1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfOrderedPortConnection();
    void push_back(AstOrderedPortConnectionHandle pOrderedPortConnection0, AstZeroOrMoreCommaOrderedPortConnectionHandle pZeroOrMoreCommaOrderedPortConnection1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstMultiIdentifier
  : public Ast {
    struct ElementType {
        AstSingleIdentifierHandle _pSingleIdentifier0;
        AstZeroOrMoreDotSingleIdentifierHandle _pZeroOrMoreDotSingleIdentifier1;
        ElementType(AstSingleIdentifierHandle pSingleIdentifier0, AstZeroOrMoreDotSingleIdentifierHandle pZeroOrMoreDotSingleIdentifier1) {
            _pSingleIdentifier0 = pSingleIdentifier0;
            _pZeroOrMoreDotSingleIdentifier1 = pZeroOrMoreDotSingleIdentifier1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstMultiIdentifier();
    void push_back(AstSingleIdentifierHandle pSingleIdentifier0, AstZeroOrMoreDotSingleIdentifierHandle pZeroOrMoreDotSingleIdentifier1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordPosedge : public Ast {
    std::string _keyword_posedge;
public:
    AstKeywordPosedge(const std::string & s);
    std::string keyword_posedge() const;
    std::string toString() const;
};

class AstBinaryExpressionPlus
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionPlus();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorNegXor
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorNegXor();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOutputTerminal
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrOneConstantBitSelectHandle _pAstZeroOrOneConstantBitSelect1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrOneConstantBitSelectHandle pAstZeroOrOneConstantBitSelect1) {
            _pIdentifier0 = pIdentifier0;
            _pAstZeroOrOneConstantBitSelect1 = pAstZeroOrOneConstantBitSelect1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOutputTerminal();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneConstantBitSelectHandle pAstZeroOrOneConstantBitSelect1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorXor
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorXor();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordReg : public Ast {
    std::string _keyword_reg;
public:
    AstKeywordReg(const std::string & s);
    std::string keyword_reg() const;
    std::string toString() const;
};

class AstZeroOrMoreCommaNOutputGateInstance
  : public Ast {
    struct ElementType {
        AstNOutputGateInstanceHandle _pNOutputGateInstance;
        ElementType(AstNOutputGateInstanceHandle pNOutputGateInstance) {
            _pNOutputGateInstance = pNOutputGateInstance;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaNOutputGateInstance();
    void push_back(AstNOutputGateInstanceHandle pNOutputGateInstance);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstAtEventExpression
  : public Ast {
    struct ElementType {
        AstEventExpressionHandle _pEventExpression0;
        ElementType(AstEventExpressionHandle pEventExpression0) {
            _pEventExpression0 = pEventExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstAtEventExpression();
    void push_back(AstEventExpressionHandle pEventExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstInitialConstruct
  : public Ast {
    struct ElementType {
        AstKeywordInitialHandle _pKeywordInitial0;
        AstStatementHandle _pStatement1;
        ElementType(AstKeywordInitialHandle pKeywordInitial0, AstStatementHandle pStatement1) {
            _pKeywordInitial0 = pKeywordInitial0;
            _pStatement1 = pStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstInitialConstruct();
    void push_back(AstKeywordInitialHandle pKeywordInitial0, AstStatementHandle pStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorMinus
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorMinus();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionDivide
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionDivide();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordAssign : public Ast {
    std::string _keyword_assign;
public:
    AstKeywordAssign(const std::string & s);
    std::string keyword_assign() const;
    std::string toString() const;
};

class AstIntegerDeclaration
  : public Ast {
    struct ElementType {
        AstKeywordIntegerHandle _pKeywordInteger0;
        AstListOfRegisterIdentifiersHandle _pListOfRegisterIdentifiers1;
        ElementType(AstKeywordIntegerHandle pKeywordInteger0, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers1) {
            _pKeywordInteger0 = pKeywordInteger0;
            _pListOfRegisterIdentifiers1 = pListOfRegisterIdentifiers1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstIntegerDeclaration();
    void push_back(AstKeywordIntegerHandle pKeywordInteger0, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionLgOr
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionLgOr();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionBwOr
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionBwOr();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNetType : public Ast {
    AstKeywordWireHandle _pKeywordWire;
public:
    AstNetType(AstKeywordWireHandle pKeywordWire);
    AstKeywordWireHandle keyword_wire() const;
    std::string toString() const;
};
class AstDelayOrEventControl
  : public Ast {
    struct ElementType {
        AstEventControlHandle _pEventControl0;
        ElementType(AstEventControlHandle pEventControl0) {
            _pEventControl0 = pEventControl0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstDelayOrEventControl();
    void push_back(AstEventControlHandle pEventControl0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNOutputGateInstance
  : public Ast {
    struct ElementType {
        AstZeroOrOneNameOfGateInstanceHandle _pZeroOrOneNameOfGateInstance0;
        AstOutputTerminalHandle _pOutputTerminal1;
        AstZeroOrMoreCommaOutputTerminalHandle _pZeroOrMoreCommaOutputTerminal2;
        AstInputTerminalHandle _pInputTerminal3;
        ElementType(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstZeroOrMoreCommaOutputTerminalHandle pZeroOrMoreCommaOutputTerminal2, AstInputTerminalHandle pInputTerminal3) {
            _pZeroOrOneNameOfGateInstance0 = pZeroOrOneNameOfGateInstance0;
            _pOutputTerminal1 = pOutputTerminal1;
            _pZeroOrMoreCommaOutputTerminal2 = pZeroOrMoreCommaOutputTerminal2;
            _pInputTerminal3 = pInputTerminal3;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNOutputGateInstance();
    void push_back(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstZeroOrMoreCommaOutputTerminalHandle pZeroOrMoreCommaOutputTerminal2, AstInputTerminalHandle pInputTerminal3);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstConditionalStatement
  : public Ast {
    struct ElementType {
        AstKeywordIfHandle _pKeywordIf0;
        AstExpressionHandle _pExpression1;
        AstStatementOrNullHandle _pStatementOrNull2;
        AstZeroOrOneElseStatementOrNullHandle _pZeroOrOneElseStatementOrNull3;
        ElementType(AstKeywordIfHandle pKeywordIf0, AstExpressionHandle pExpression1, AstStatementOrNullHandle pStatementOrNull2, AstZeroOrOneElseStatementOrNullHandle pZeroOrOneElseStatementOrNull3) {
            _pKeywordIf0 = pKeywordIf0;
            _pExpression1 = pExpression1;
            _pStatementOrNull2 = pStatementOrNull2;
            _pZeroOrOneElseStatementOrNull3 = pZeroOrOneElseStatementOrNull3;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConditionalStatement();
    void push_back(AstKeywordIfHandle pKeywordIf0, AstExpressionHandle pExpression1, AstStatementOrNullHandle pStatementOrNull2, AstZeroOrOneElseStatementOrNullHandle pZeroOrOneElseStatementOrNull3);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionGt
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionGt();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOnePortExpression
  : public Ast {
    struct ElementType {
        AstPortExpressionHandle _pPortExpression;
        ElementType(AstPortExpressionHandle pPortExpression) {
            _pPortExpression = pPortExpression;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOnePortExpression();
    void push_back(AstPortExpressionHandle pPortExpression);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrOneConstantBitSelect
  : public Ast {
    struct ElementType {
        AstConstantBitSelectHandle _pConstantBitSelect;
        ElementType(AstConstantBitSelectHandle pConstantBitSelect) {
            _pConstantBitSelect = pConstantBitSelect;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneConstantBitSelect();
    void push_back(AstConstantBitSelectHandle pConstantBitSelect);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordCase : public Ast {
    std::string _keyword_case;
public:
    AstKeywordCase(const std::string & s);
    std::string keyword_case() const;
    std::string toString() const;
};

class AstZeroOrMoreRegisterNameRange
  : public Ast {
    struct ElementType {
        AstRangeHandle _pRange;
        ElementType(AstRangeHandle pRange) {
            _pRange = pRange;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreRegisterNameRange();
    void push_back(AstRangeHandle pRange);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorOr
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorOr();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstCaseItemItem
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstZeroOrMoreCommaExpressionHandle _pZeroOrMoreCommaExpression1;
        AstStatementOrNullHandle _pStatementOrNull2;
        ElementType(AstExpressionHandle pExpression0, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression1, AstStatementOrNullHandle pStatementOrNull2) {
            _pExpression0 = pExpression0;
            _pZeroOrMoreCommaExpression1 = pZeroOrMoreCommaExpression1;
            _pStatementOrNull2 = pStatementOrNull2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstCaseItemItem();
    void push_back(AstExpressionHandle pExpression0, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression1, AstStatementOrNullHandle pStatementOrNull2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorNegOr
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorNegOr();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstModuleDeclaration
  : public Ast {
    struct ElementType {
        AstModuleKeywordHandle _pModuleKeyword0;
        AstIdentifierHandle _pIdentifier1;
        AstZeroOrOneListOfPortsHandle _pZeroOrOneListOfPorts2;
        AstZeroOrMoreModuleItemHandle _pZeroOrMoreModuleItem3;
        AstKeywordEndmoduleHandle _pKeywordEndmodule4;
        ElementType(AstModuleKeywordHandle pModuleKeyword0, AstIdentifierHandle pIdentifier1, AstZeroOrOneListOfPortsHandle pZeroOrOneListOfPorts2, AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem3, AstKeywordEndmoduleHandle pKeywordEndmodule4) {
            _pModuleKeyword0 = pModuleKeyword0;
            _pIdentifier1 = pIdentifier1;
            _pZeroOrOneListOfPorts2 = pZeroOrOneListOfPorts2;
            _pZeroOrMoreModuleItem3 = pZeroOrMoreModuleItem3;
            _pKeywordEndmodule4 = pKeywordEndmodule4;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstModuleDeclaration();
    void push_back(AstModuleKeywordHandle pModuleKeyword0, AstIdentifierHandle pIdentifier1, AstZeroOrOneListOfPortsHandle pZeroOrOneListOfPorts2, AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem3, AstKeywordEndmoduleHandle pKeywordEndmodule4);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionBwXor
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionBwXor();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstConstantPrimary : public Ast {
    AstNumberHandle _pNumber;
public:
    AstConstantPrimary(AstNumberHandle pNumber);
    AstIdentifierHandle _pIdentifier;
public:
    AstConstantPrimary(AstIdentifierHandle pIdentifier);
    AstConcatenationHandle _pAstConcatenation;
public:
    AstConstantPrimary(AstConcatenationHandle pAstConcatenation);
    AstMultipleConcatenationHandle _pMulitpleConcatenation;
public:
    AstConstantPrimary(AstMultipleConcatenationHandle pMulitpleConcatenation);
    AstNumberHandle number() const;
    AstIdentifierHandle identifier() const;
    AstConcatenationHandle concatenation() const;
    AstMultipleConcatenationHandle multiple_concatenation() const;
    std::string toString() const;
};
class AstPosedgeExpression
  : public Ast {
    struct ElementType {
        AstKeywordPosedgeHandle _pKeywordPosedge0;
        AstExpressionHandle _pExpression1;
        ElementType(AstKeywordPosedgeHandle pKeywordPosedge0, AstExpressionHandle pExpression1) {
            _pKeywordPosedge0 = pKeywordPosedge0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstPosedgeExpression();
    void push_back(AstKeywordPosedgeHandle pKeywordPosedge0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfModuleConnections : public Ast {
    AstListOfOrderedPortConnectionHandle _pListOfOrderedPortConnection;
public:
    AstListOfModuleConnections(AstListOfOrderedPortConnectionHandle pListOfOrderedPortConnection);
    AstListOfNamedPortConnectionHandle _pListOfNamedPortConnection;
public:
    AstListOfModuleConnections(AstListOfNamedPortConnectionHandle pListOfNamedPortConnection);
    AstListOfOrderedPortConnectionHandle list_of_ordered_port_connection() const;
    AstListOfNamedPortConnectionHandle list_of_named_port_connection() const;
    std::string toString() const;
};
class AstRegAssignment
  : public Ast {
    struct ElementType {
        AstRegLvalueHandle _pRegLvalue0;
        AstExpressionHandle _pExpression1;
        ElementType(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
            _pRegLvalue0 = pRegLvalue0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstRegAssignment();
    void push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorGeq
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorGeq();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionLeq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionLeq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstAtAsterisk
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstAtAsterisk();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstRegLvalue : public Ast {
    AstIdentifierHandle _pIdentifier;
public:
    AstRegLvalue(AstIdentifierHandle pIdentifier);
    AstSelectIdentifierHandle _pSelectIdentifier;
public:
    AstRegLvalue(AstSelectIdentifierHandle pSelectIdentifier);
    AstConcatenationHandle _pAstConcatenation;
public:
    AstRegLvalue(AstConcatenationHandle pAstConcatenation);
    AstIdentifierHandle identifier() const;
    AstSelectIdentifierHandle select_identifier() const;
    AstConcatenationHandle concatenation() const;
    std::string toString() const;
};
class AstBinaryOperatorAnd
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorAnd();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstAtEventOrAsterisk
  : public Ast {
    struct ElementType {
        AstEventOrAsteriskHandle _pEventOrAsterisk0;
        ElementType(AstEventOrAsteriskHandle pEventOrAsterisk0) {
            _pEventOrAsterisk0 = pEventOrAsterisk0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstAtEventOrAsterisk();
    void push_back(AstEventOrAsteriskHandle pEventOrAsterisk0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordDefault : public Ast {
    std::string _keyword_default;
public:
    AstKeywordDefault(const std::string & s);
    std::string keyword_default() const;
    std::string toString() const;
};

class AstBinaryExpressionShiftRight
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionShiftRight();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstListOfNamedPortConnection
  : public Ast {
    struct ElementType {
        AstNamedPortConnectionHandle _pNamedPortConnection0;
        AstZeroOrMoreCommaNamedPortConnectionHandle _pZeroOrMoreCommaNamedPortConnection1;
        ElementType(AstNamedPortConnectionHandle pNamedPortConnection0, AstZeroOrMoreCommaNamedPortConnectionHandle pZeroOrMoreCommaNamedPortConnection1) {
            _pNamedPortConnection0 = pNamedPortConnection0;
            _pZeroOrMoreCommaNamedPortConnection1 = pZeroOrMoreCommaNamedPortConnection1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstListOfNamedPortConnection();
    void push_back(AstNamedPortConnectionHandle pNamedPortConnection0, AstZeroOrMoreCommaNamedPortConnectionHandle pZeroOrMoreCommaNamedPortConnection1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorShl
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorShl();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordEndmodule : public Ast {
    std::string _keyword_endmodule;
public:
    AstKeywordEndmodule(const std::string & s);
    std::string keyword_endmodule() const;
    std::string toString() const;
};

class AstBinaryExpression : public Ast {
    AstBinaryExpressionMultiplyHandle _pBinaryExpressionMultiply;
public:
    AstBinaryExpression(AstBinaryExpressionMultiplyHandle pBinaryExpressionMultiply);
    AstBinaryExpressionDivideHandle _pBinaryExpressionDivide;
public:
    AstBinaryExpression(AstBinaryExpressionDivideHandle pBinaryExpressionDivide);
    AstBinaryExpressionModulusHandle _pBinaryExpressionModulus;
public:
    AstBinaryExpression(AstBinaryExpressionModulusHandle pBinaryExpressionModulus);
    AstBinaryExpressionPlusHandle _pBinaryExpressionPlus;
public:
    AstBinaryExpression(AstBinaryExpressionPlusHandle pBinaryExpressionPlus);
    AstBinaryExpressionMinusHandle _pBinaryExpressionMinus;
public:
    AstBinaryExpression(AstBinaryExpressionMinusHandle pBinaryExpressionMinus);
    AstBinaryExpressionShiftRightHandle _pBinaryExpressionShiftRight;
public:
    AstBinaryExpression(AstBinaryExpressionShiftRightHandle pBinaryExpressionShiftRight);
    AstBinaryExpressionShiftLeftHandle _pBinaryExpressionShiftLeft;
public:
    AstBinaryExpression(AstBinaryExpressionShiftLeftHandle pBinaryExpressionShiftLeft);
    AstBinaryExpressionGtHandle _pBinaryExpressionGt;
public:
    AstBinaryExpression(AstBinaryExpressionGtHandle pBinaryExpressionGt);
    AstBinaryExpressionGeqHandle _pBinaryExpressionGeq;
public:
    AstBinaryExpression(AstBinaryExpressionGeqHandle pBinaryExpressionGeq);
    AstBinaryExpressionLtHandle _pBinaryExpressionLt;
public:
    AstBinaryExpression(AstBinaryExpressionLtHandle pBinaryExpressionLt);
    AstBinaryExpressionLeqHandle _pBinaryExpressionLeq;
public:
    AstBinaryExpression(AstBinaryExpressionLeqHandle pBinaryExpressionLeq);
    AstBinaryExpressionEqHandle _pBinaryExpressionEq;
public:
    AstBinaryExpression(AstBinaryExpressionEqHandle pBinaryExpressionEq);
    AstBinaryExpressionNeqHandle _pBinaryExpressionNeq;
public:
    AstBinaryExpression(AstBinaryExpressionNeqHandle pBinaryExpressionNeq);
    AstBinaryExpressionCaseEqHandle _pBinaryExpressionCaseEq;
public:
    AstBinaryExpression(AstBinaryExpressionCaseEqHandle pBinaryExpressionCaseEq);
    AstBinaryExpressionCaseNeqHandle _pBinaryExpressionCaseNeq;
public:
    AstBinaryExpression(AstBinaryExpressionCaseNeqHandle pBinaryExpressionCaseNeq);
    AstBinaryExpressionBwAndHandle _pBinaryExpressionBwAnd;
public:
    AstBinaryExpression(AstBinaryExpressionBwAndHandle pBinaryExpressionBwAnd);
    AstBinaryExpressionBwXorHandle _pBinaryExpressionBwXor;
public:
    AstBinaryExpression(AstBinaryExpressionBwXorHandle pBinaryExpressionBwXor);
    AstBinaryExpressionBwXnorHandle _pBinaryExpressionBwXnor;
public:
    AstBinaryExpression(AstBinaryExpressionBwXnorHandle pBinaryExpressionBwXnor);
    AstBinaryExpressionBwNxorHandle _pBinaryExpressionBwNxor;
public:
    AstBinaryExpression(AstBinaryExpressionBwNxorHandle pBinaryExpressionBwNxor);
    AstBinaryExpressionBwOrHandle _pBinaryExpressionBwOr;
public:
    AstBinaryExpression(AstBinaryExpressionBwOrHandle pBinaryExpressionBwOr);
    AstBinaryExpressionLgAndHandle _pBinaryExpressionLgAnd;
public:
    AstBinaryExpression(AstBinaryExpressionLgAndHandle pBinaryExpressionLgAnd);
    AstBinaryExpressionLgOrHandle _pBinaryExpressionLgOr;
public:
    AstBinaryExpression(AstBinaryExpressionLgOrHandle pBinaryExpressionLgOr);
    AstBinaryExpressionMultiplyHandle binary_expression_multiply() const;
    AstBinaryExpressionDivideHandle binary_expression_divide() const;
    AstBinaryExpressionModulusHandle binary_expression_modulus() const;
    AstBinaryExpressionPlusHandle binary_expression_plus() const;
    AstBinaryExpressionMinusHandle binary_expression_minus() const;
    AstBinaryExpressionShiftRightHandle binary_expression_shift_right() const;
    AstBinaryExpressionShiftLeftHandle binary_expression_shift_left() const;
    AstBinaryExpressionGtHandle binary_expression_gt() const;
    AstBinaryExpressionGeqHandle binary_expression_geq() const;
    AstBinaryExpressionLtHandle binary_expression_lt() const;
    AstBinaryExpressionLeqHandle binary_expression_leq() const;
    AstBinaryExpressionEqHandle binary_expression_eq() const;
    AstBinaryExpressionNeqHandle binary_expression_neq() const;
    AstBinaryExpressionCaseEqHandle binary_expression_case_eq() const;
    AstBinaryExpressionCaseNeqHandle binary_expression_case_neq() const;
    AstBinaryExpressionBwAndHandle binary_expression_bw_and() const;
    AstBinaryExpressionBwXorHandle binary_expression_bw_xor() const;
    AstBinaryExpressionBwXnorHandle binary_expression_bw_xnor() const;
    AstBinaryExpressionBwNxorHandle binary_expression_bw_nxor() const;
    AstBinaryExpressionBwOrHandle binary_expression_bw_or() const;
    AstBinaryExpressionLgAndHandle binary_expression_lg_and() const;
    AstBinaryExpressionLgOrHandle binary_expression_lg_or() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionNeq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionNeq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNameOfInstance
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        ElementType(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1) {
            _pIdentifier0 = pIdentifier0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNameOfInstance();
    void push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstConcatenation
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstOneOrMoreCommaExpressionHandle _pOneOrMoreCommaExpression1;
        ElementType(AstExpressionHandle pExpression0, AstOneOrMoreCommaExpressionHandle pOneOrMoreCommaExpression1) {
            _pExpression0 = pExpression0;
            _pOneOrMoreCommaExpression1 = pOneOrMoreCommaExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConcatenation();
    void push_back(AstExpressionHandle pExpression0, AstOneOrMoreCommaExpressionHandle pOneOrMoreCommaExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstConstantBitSelectIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstConstantBitSelectHandle _pConstantBitSelect1;
        ElementType(AstIdentifierHandle pIdentifier0, AstConstantBitSelectHandle pConstantBitSelect1) {
            _pIdentifier0 = pIdentifier0;
            _pConstantBitSelect1 = pConstantBitSelect1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConstantBitSelectIdentifier();
    void push_back(AstIdentifierHandle pIdentifier0, AstConstantBitSelectHandle pConstantBitSelect1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorPercent
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorPercent();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaModuleInstance
  : public Ast {
    struct ElementType {
        AstModuleInstanceHandle _pModuleInstance;
        ElementType(AstModuleInstanceHandle pModuleInstance) {
            _pModuleInstance = pModuleInstance;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaModuleInstance();
    void push_back(AstModuleInstanceHandle pModuleInstance);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstPortExpression : public Ast {
    AstPortReferenceHandle _pPortReference;
public:
    AstPortExpression(AstPortReferenceHandle pPortReference);
    AstListOfPortReferencesHandle _pListOfPortReferences;
public:
    AstPortExpression(AstListOfPortReferencesHandle pListOfPortReferences);
    AstPortReferenceHandle port_reference() const;
    AstListOfPortReferencesHandle list_of_port_references() const;
    std::string toString() const;
};
class AstGateInstantiationOutput
  : public Ast {
    struct ElementType {
        AstNOutputGateTypeHandle _pNOutputGateType0;
        AstNOutputGateInstanceHandle _pNOutputGateInstance1;
        AstZeroOrMoreCommaNOutputGateInstanceHandle _pZeroOrMoreCommaNOutputGateInstance2;
        ElementType(AstNOutputGateTypeHandle pNOutputGateType0, AstNOutputGateInstanceHandle pNOutputGateInstance1, AstZeroOrMoreCommaNOutputGateInstanceHandle pZeroOrMoreCommaNOutputGateInstance2) {
            _pNOutputGateType0 = pNOutputGateType0;
            _pNOutputGateInstance1 = pNOutputGateInstance1;
            _pZeroOrMoreCommaNOutputGateInstance2 = pZeroOrMoreCommaNOutputGateInstance2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstGateInstantiationOutput();
    void push_back(AstNOutputGateTypeHandle pNOutputGateType0, AstNOutputGateInstanceHandle pNOutputGateInstance1, AstZeroOrMoreCommaNOutputGateInstanceHandle pZeroOrMoreCommaNOutputGateInstance2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstEventCommaEvent
  : public Ast {
    struct ElementType {
        AstEventExpressionHandle _pEventExpression0;
        AstEventExpressionHandle _pEventExpression1;
        ElementType(AstEventExpressionHandle pEventExpression0, AstEventExpressionHandle pEventExpression1) {
            _pEventExpression0 = pEventExpression0;
            _pEventExpression1 = pEventExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstEventCommaEvent();
    void push_back(AstEventExpressionHandle pEventExpression0, AstEventExpressionHandle pEventExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryConstantExpressionCaseEq
  : public Ast {
    struct ElementType {
        AstConstantExpressionHandle _pConstantExpression0;
        AstConstantExpressionHandle _pConstantExpression1;
        ElementType(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
            _pConstantExpression0 = pConstantExpression0;
            _pConstantExpression1 = pConstantExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryConstantExpressionCaseEq();
    void push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstPortReference : public Ast {
    AstIdentifierHandle _pIdentifier;
public:
    AstPortReference(AstIdentifierHandle pIdentifier);
    AstConstantBitSelectIdentifierHandle _pConstantBitSelectIdentifier;
public:
    AstPortReference(AstConstantBitSelectIdentifierHandle pConstantBitSelectIdentifier);
    AstConstantRangeSelectIdentifierHandle _pConstantRangeSelectIdentifier;
public:
    AstPortReference(AstConstantRangeSelectIdentifierHandle pConstantRangeSelectIdentifier);
    AstIdentifierHandle identifier() const;
    AstConstantBitSelectIdentifierHandle constant_bit_select_identifier() const;
    AstConstantRangeSelectIdentifierHandle constant_range_select_identifier() const;
    std::string toString() const;
};
class AstElseStatementOrNull
  : public Ast {
    struct ElementType {
        AstKeywordElseHandle _pKeywordElse0;
        AstStatementOrNullHandle _pStatementOrNull1;
        ElementType(AstKeywordElseHandle pKeywordElse0, AstStatementOrNullHandle pStatementOrNull1) {
            _pKeywordElse0 = pKeywordElse0;
            _pStatementOrNull1 = pStatementOrNull1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstElseStatementOrNull();
    void push_back(AstKeywordElseHandle pKeywordElse0, AstStatementOrNullHandle pStatementOrNull1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryExpressionShiftLeft
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionShiftLeft();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstPrimary : public Ast {
    AstSelectIdentifierHandle _pSelectIdentifier;
public:
    AstPrimary(AstSelectIdentifierHandle pSelectIdentifier);
    AstIdentifierHandle _pIdentifier;
public:
    AstPrimary(AstIdentifierHandle pIdentifier);
    AstNumberHandle _pNumber;
public:
    AstPrimary(AstNumberHandle pNumber);
    AstConcatenationHandle _pAstConcatenation;
public:
    AstPrimary(AstConcatenationHandle pAstConcatenation);
    AstMultipleConcatenationHandle _pMulitpleConcatenation;
public:
    AstPrimary(AstMultipleConcatenationHandle pMulitpleConcatenation);
    AstSelectIdentifierHandle select_identifier() const;
    AstIdentifierHandle identifier() const;
    AstNumberHandle number() const;
    AstConcatenationHandle concatenation() const;
    AstMultipleConcatenationHandle multiple_concatenation() const;
    std::string toString() const;
};
class AstBinaryExpressionCaseNeq
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        AstExpressionHandle _pExpression1;
        ElementType(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
            _pExpression0 = pExpression0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryExpressionCaseNeq();
    void push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstOrderedPortConnection : public Ast {
    AstZeroOrOneExpressionHandle _pZeroOrOneExpression;
public:
    AstOrderedPortConnection(AstZeroOrOneExpressionHandle pZeroOrOneExpression);
    AstZeroOrOneExpressionHandle zero_or_one_expression() const;
    std::string toString() const;
};
class AstParamAssignment
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstExpressionHandle _pExpression1;
        ElementType(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1) {
            _pIdentifier0 = pIdentifier0;
            _pExpression1 = pExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstParamAssignment();
    void push_back(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordInOut : public Ast {
    std::string _keyword_inout;
public:
    AstKeywordInOut(const std::string & s);
    std::string keyword_inout() const;
    std::string toString() const;
};

class AstConstantRangeSelectIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        AstConstantRangeSelectHandle _pConstantRangeSelect1;
        ElementType(AstIdentifierHandle pIdentifier0, AstConstantRangeSelectHandle pConstantRangeSelect1) {
            _pIdentifier0 = pIdentifier0;
            _pConstantRangeSelect1 = pConstantRangeSelect1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstConstantRangeSelectIdentifier();
    void push_back(AstIdentifierHandle pIdentifier0, AstConstantRangeSelectHandle pConstantRangeSelect1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBitSelect
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression0;
        ElementType(AstExpressionHandle pExpression0) {
            _pExpression0 = pExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBitSelect();
    void push_back(AstExpressionHandle pExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKetwordNegedge : public Ast {
    std::string _keyword_negedge;
public:
    AstKetwordNegedge(const std::string & s);
    std::string keyword_negedge() const;
    std::string toString() const;
};

class AstInputTerminal : public Ast {
    AstExpressionHandle _pExpression;
public:
    AstInputTerminal(AstExpressionHandle pExpression);
    AstExpressionHandle expression() const;
    std::string toString() const;
};
class AstZeroOrOneListOfPorts
  : public Ast {
    struct ElementType {
        AstListOfPortsHandle _pListOfPorts;
        ElementType(AstListOfPortsHandle pListOfPorts) {
            _pListOfPorts = pListOfPorts;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrOneListOfPorts();
    void push_back(AstListOfPortsHandle pListOfPorts);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstPort : public Ast {
    AstPortExpressionHandle _pPortExpression;
public:
    AstPort(AstPortExpressionHandle pPortExpression);
    AstNamedPortExpressionHandle _pNamedPortExpression;
public:
    AstPort(AstNamedPortExpressionHandle pNamedPortExpression);
    AstPortExpressionHandle port_expression() const;
    AstNamedPortExpressionHandle named_port_expression() const;
    std::string toString() const;
};
class AstOneOrMoreDescription
  : public Ast {
    struct ElementType {
        AstDescriptionHandle _pDescription0;
        ElementType(AstDescriptionHandle pDescription0) {
            _pDescription0 = pDescription0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstOneOrMoreDescription();
    void push_back(AstDescriptionHandle pDescription0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorAsterisk
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorAsterisk();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreCommaExpression
  : public Ast {
    struct ElementType {
        AstExpressionHandle _pExpression;
        ElementType(AstExpressionHandle pExpression) {
            _pExpression = pExpression;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreCommaExpression();
    void push_back(AstExpressionHandle pExpression);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstAtIdentifier
  : public Ast {
    struct ElementType {
        AstIdentifierHandle _pIdentifier0;
        ElementType(AstIdentifierHandle pIdentifier0) {
            _pIdentifier0 = pIdentifier0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstAtIdentifier();
    void push_back(AstIdentifierHandle pIdentifier0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstKeywordInput : public Ast {
    std::string _keyword_input;
public:
    AstKeywordInput(const std::string & s);
    std::string keyword_input() const;
    std::string toString() const;
};

class AstBinaryOperatorXorNeg
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorXorNeg();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstZeroOrMoreDotSingleIdentifier
  : public Ast {
    struct ElementType {
        AstSingleIdentifierHandle _pSingleIdentifier;
        ElementType(AstSingleIdentifierHandle pSingleIdentifier) {
            _pSingleIdentifier = pSingleIdentifier;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstZeroOrMoreDotSingleIdentifier();
    void push_back(AstSingleIdentifierHandle pSingleIdentifier);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstUnaryOperatorOr
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstUnaryOperatorOr();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstBinaryOperatorGt
  : public Ast {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstBinaryOperatorGt();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class AstNetDeclaration
  : public Ast {
    struct ElementType {
        AstNetTypeHandle _pNetType0;
        AstZeroOrOneRangeHandle _pZeroOrOneRange1;
        AstListOfNetIdentifierHandle _pListOfNetIdentifier2;
        ElementType(AstNetTypeHandle pNetType0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfNetIdentifierHandle pListOfNetIdentifier2) {
            _pNetType0 = pNetType0;
            _pZeroOrOneRange1 = pZeroOrOneRange1;
            _pListOfNetIdentifier2 = pListOfNetIdentifier2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    AstNetDeclaration();
    void push_back(AstNetTypeHandle pNetType0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfNetIdentifierHandle pListOfNetIdentifier2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
#endif // AST_H
