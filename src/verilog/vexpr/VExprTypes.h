#ifndef VEXPR_TYPES_H
#define VEXPR_TYPES_H

#include "nstl/shared_ptr/SharedPtr.h"


class VExprIdentifierInterface;
typedef SharedPtr<VExprIdentifierInterface> VExprIdentifierInterfaceHandle;

class VExprIdentifier;
typedef SharedPtr<VExprIdentifier> VExprIdentifierHandle;

class VExprSingleIdentifier;
typedef SharedPtr<VExprSingleIdentifier> VExprSingleIdentifierHandle;

class VExprHierIdentifier;
typedef SharedPtr<VExprHierIdentifier> VExprHierIdentifierHandle;


class VExprNumberInterface;
typedef SharedPtr<VExprNumberInterface> VExprNumberInterfaceHandle;

class VExprNumber;
typedef SharedPtr<VExprNumber> VExprNumberHandle;

class VExprUnsignedNumber;
typedef SharedPtr<VExprUnsignedNumber> VExprUnsignedNumberHandle;

class VExprBinaryNumber;
typedef SharedPtr<VExprBinaryNumber> VExprBinaryNumberHandle;

class VExprOctalNumber;
typedef SharedPtr<VExprOctalNumber> VExprOctalNumberHandle;

class VExprDecimalNumber;
typedef SharedPtr<VExprDecimalNumber> VExprDecimalNumberHandle;

class VExprHexNumber;
typedef SharedPtr<VExprHexNumber> VExprHexNumberHandle;


class VExprExpression;
typedef SharedPtr<VExprExpression> VExprExpressionHandle;

class VExprUnary;
typedef SharedPtr<VExprUnary> VExprUnaryHandle;

class VExprBinary;
typedef SharedPtr<VExprBinary> VExprBinaryHandle;

class VExprTernary;
typedef SharedPtr<VExprTernary> VExprTernaryHandle;

class VExprBool;
typedef SharedPtr<VExprBool> VExprBoolHandle;

class VExprRangeSelect;
typedef SharedPtr<VExprRangeSelect> VExprRangeSelectHandle;
class VExprBitSelect;
typedef SharedPtr<VExprBitSelect> VExprBitSelectHandle;

class VExprPrimary;
typedef SharedPtr<VExprPrimary> VExprPrimaryHandle;

class VExprSelect;
typedef SharedPtr<VExprSelect> VExprSelectHandle;

class VExprRangeSelect;
typedef SharedPtr<VExprRangeSelect> VExprRangeSelectHandle;

class VExprBitSelect;
typedef SharedPtr<VExprBitSelect> VExprBitSelectHandle;


class VExprSelect;
typedef SharedPtr<VExprSelect> VExprSelectHandle;

class VExprSelectIdentifier;
typedef SharedPtr<VExprSelectIdentifier> VExprSelectIdentifierHandle;


class VExprConcatenation;
typedef SharedPtr<VExprConcatenation> VExprConcatenationHandle;

class VExprMultipleConcatenation;
typedef SharedPtr<VExprMultipleConcatenation> VExprMultipleConcatenationHandle;

class VExprConstantPrimary;
typedef SharedPtr<VExprConstantPrimary> VExprConstantPrimaryHandle;

class VExprConstantExpressionInterface;
typedef SharedPtr<VExprConstantExpressionInterface> VExprConstantExpressionInterfaceHandle;

class VExprConstantPrimaryInterface;
typedef SharedPtr<VExprConstantPrimaryInterface> VExprConstantPrimaryInterfaceHandle;

class VExprConstantExpression;
typedef SharedPtr<VExprConstantExpression> VExprConstantExpressionHandle;

class VExprConstantUnary;
typedef SharedPtr<VExprConstantUnary> VExprConstantUnaryHandle;

class VExprConstantBinary;
typedef SharedPtr<VExprConstantBinary> VExprConstantBinaryHandle;

class VExprConstantTernary;
typedef SharedPtr<VExprConstantTernary> VExprConstantTernaryHandle;

class VExprRange;
typedef SharedPtr<VExprRange> VExprRangeHandle;

class VExprRegLvalue;
typedef SharedPtr<VExprRegLvalue> VExprRegLvalueHandle;

class VExprBlockingAssignment;
typedef SharedPtr<VExprBlockingAssignment> VExprBlockingAssignmentHandle;

class VExprNonBlockingAssignment;
typedef SharedPtr<VExprNonBlockingAssignment> VExprNonBlockingAssignmentHandle;

class VExprNetLvalue;
typedef SharedPtr<VExprNetLvalue> VExprNetLvalueHandle;

class VExprNetLvalueBitSelect;
typedef SharedPtr<VExprNetLvalueBitSelect> VExprNetLvalueBitSelectHandle;

class VExprNetLvalueRangeSelect;
typedef SharedPtr<VExprNetLvalueRangeSelect> VExprNetLvalueRangeSelectHandle;

class VExprNetAssignment;
typedef SharedPtr<VExprNetAssignment> VExprNetAssignmentHandle;

class VExprContinuousAssignment;
typedef SharedPtr<VExprContinuousAssignment> VExprContinuousAssignmentHandle;

class VExprStatement;
typedef SharedPtr<VExprStatement> VExprStatementHandle;

class VExprNull;
typedef SharedPtr<VExprNull> VExprNullHandle;

class VExprStatementOrNull;
typedef SharedPtr<VExprStatementOrNull> VExprStatementOrNullHandle;

class VExprStatementOrNullInterface;
typedef SharedPtr<VExprStatementOrNullInterface> VExprStatementOrNullInterfaceHandle;

class VExprConditionalStatement;
typedef SharedPtr<VExprConditionalStatement> VExprConditionalStatementHandle;

class VExprSeqBlock;
typedef SharedPtr<VExprSeqBlock> VExprSeqBlockHandle;

class VExprEventStatement;
typedef SharedPtr<VExprEventStatement> VExprEventStatementHandle;

class VExprEventExpression;
typedef SharedPtr<VExprEventExpression> VExprEventExpressionHandle;

class VExprEvent;
typedef SharedPtr<VExprEvent> VExprEventHandle;

class VExprPosedgeEvent;
typedef SharedPtr<VExprPosedgeEvent> VExprPosedgeEventHandle;

class VExprNegedgeEvent;
typedef SharedPtr<VExprNegedgeEvent> VExprNegedgeEventHandle;

class VExprCaseStatement;
typedef SharedPtr<VExprCaseStatement> VExprCaseStatementHandle;
class VExprCaseItem;
typedef SharedPtr<VExprCaseItem> VExprCaseItemHandle;

class VExprProceduralContinuousAssignment;
typedef SharedPtr<VExprProceduralContinuousAssignment> VExprProceduralContinuousAssignmentHandle;

class VExprRegAssignment;
typedef SharedPtr<VExprRegAssignment> VExprRegAssignmentHandle;

class VExprLoopStatement;
typedef SharedPtr<VExprLoopStatement> VExprLoopStatementHandle;

class VExprParamAssignment;
typedef SharedPtr<VExprParamAssignment> VExprParamAssignmentHandle;

class VExprParameterDeclaration;
typedef SharedPtr<VExprParameterDeclaration> VExprParameterDeclarationHandle;

class VExprModuleDeclarationInterface;
typedef SharedPtr<VExprModuleDeclarationInterface> VExprModuleDeclarationInterfaceHandle;

class VExprPortDeclaration;
typedef SharedPtr<VExprPortDeclaration> VExprPortDeclarationHandle;

class VExprInputDeclaration;
typedef SharedPtr<VExprInputDeclaration> VExprInputDeclarationHandle;

class VExprInputDecl;
typedef SharedPtr<VExprInputDecl> VExprInputDeclHandle;

class VExprOutputDeclaration;
typedef SharedPtr<VExprOutputDeclaration> VExprOutputDeclarationHandle;

class VExprOutputDecl;
typedef SharedPtr<VExprOutputDecl> VExprOutputDeclHandle;

class VExprInoutDeclaration;
typedef SharedPtr<VExprInoutDeclaration> VExprInoutDeclarationHandle;

class VExprRegisterName;
typedef SharedPtr<VExprRegisterName> VExprRegisterNameHandle;

class VExprNetDeclaration;
typedef SharedPtr<VExprNetDeclaration> VExprNetDeclarationHandle;

class VExprNetDecl;
typedef SharedPtr<VExprNetDecl> VExprNetDeclHandle;

class VExprRegDeclaration;
typedef SharedPtr<VExprRegDeclaration> VExprRegDeclarationHandle;

class VExprRegDecl;
typedef SharedPtr<VExprRegDecl> VExprRegDeclHandle;

class VExprInoutDeclaration;
typedef SharedPtr<VExprInoutDeclaration> VExprInoutDeclarationHandle;

class VExprInoutDecl;
typedef SharedPtr<VExprInoutDecl> VExprInoutDeclHandle;

class VExprIntegerDeclaration;
typedef SharedPtr<VExprIntegerDeclaration> VExprIntegerDeclarationHandle;

class VExprModule;
typedef SharedPtr<VExprModule> VExprModuleHandle;

class VExprModuleItemDeclaration;
typedef SharedPtr<VExprModuleItemDeclaration> VExprModuleItemDeclarationHandle;

class VExprModuleInstance;
typedef SharedPtr<VExprModuleInstance> VExprModuleInstanceHandle;

class VExprNameOfInstance;
typedef SharedPtr<VExprNameOfInstance> VExprNameOfInstanceHandle;

class VExprOrderedPortConnection;
typedef SharedPtr<VExprOrderedPortConnection> VExprOrderedPortConnectionHandle;

class VExprNamedPortConnection;
typedef SharedPtr<VExprNamedPortConnection> VExprNamedPortConnectionHandle;

class VExprListOfModuleConnections;
typedef SharedPtr<VExprListOfModuleConnections> VExprListOfModuleConnectionsHandle;

class VExprModuleInstantiation;
typedef SharedPtr<VExprModuleInstantiation> VExprModuleInstantiationHandle;

class VExprAlways;
typedef SharedPtr<VExprAlways> VExprAlwaysHandle;

class VExprInitial;
typedef SharedPtr<VExprInitial> VExprInitialHandle;

class VExprModuleItem;
typedef SharedPtr<VExprModuleItem> VExprModuleItemHandle;

class VExprModuleItemList;
typedef SharedPtr<VExprModuleItemList> VExprModuleItemListHandle;

#endif 
