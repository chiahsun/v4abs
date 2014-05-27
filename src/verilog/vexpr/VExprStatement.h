#ifndef VEXPR_STATEMENT_H
#define VEXPR_STATEMENT_H

#include "VExprBlockingAssignment.h"
#include "VExprNonBlockingAssignment.h"
#include "VExprStatementOrNullInterface.h"
#include "VExprSeqBlock.h"
#include "VExprConditionalStatement.h"
#include "VExprCaseStatement.h"
#include "VExprProceduralContinuousAssignment.h"
#include "VExprLoopStatement.h"
#include "VExprEventStatement.h"

VExprStatementHandle vexpr_statement_mk_blocking_assignment(VExprBlockingAssignmentHandle pBlockingAssign);
VExprStatementHandle vexpr_statement_mk_non_blocking_assignment(VExprNonBlockingAssignmentHandle pNonBlockingAssign);
VExprStatementHandle vexpr_statement_mk_seq_block();
VExprStatementHandle vexpr_statement_mk_seq_block(VExprSeqBlockHandle pSeqBlock);

VExprStatementHandle vexpr_statement_mk_conditional(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen);
VExprStatementHandle vexpr_statement_mk_conditional(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse);

class VExprStatement : public VExprStatementOrNullInterface {
    VExprStatementInterfaceHandle _pInterface;

    VExprBlockingAssignmentHandle _pBlockingAssign;
    VExprNonBlockingAssignmentHandle _pNonBlockingAssign;
    VExprSeqBlockHandle _pSeqBlock;
    VExprConditionalStatementHandle _pConditional;
    VExprCaseStatementHandle _pCaseStatement;
    VExprProceduralContinuousAssignmentHandle _pProceduralContinuousAssignment;
    VExprLoopStatementHandle _pLoopStatement;
    VExprEventStatementHandle _pEventStatement;

public:
    VExprStatement(VExprBlockingAssignmentHandle pBlockingAssign);
    VExprStatement(VExprNonBlockingAssignmentHandle pNonBlockingAssign);
    VExprStatement(VExprSeqBlockHandle pSeqBlock);
    VExprStatement(VExprConditionalStatementHandle pConditional);
    VExprStatement(VExprCaseStatementHandle pCaseStatement);
    VExprStatement(VExprProceduralContinuousAssignmentHandle pProceduralContinuousAssignment);
    VExprStatement(VExprLoopStatementHandle pLoopStatement);
    VExprStatement(VExprEventStatementHandle pEventStatement);

    const VExprBlockingAssignmentHandle& getBlockingAssignHandle() const;
    const VExprNonBlockingAssignmentHandle& getNonBlockingAssignHandle() const;
    const VExprSeqBlockHandle& getSeqBlockHandle() const;
    const VExprConditionalStatementHandle& getConditionalHandle() const;
    const VExprCaseStatementHandle& getCaseStatementHandle() const;
    const VExprProceduralContinuousAssignmentHandle& getProceduralContinuousAssignmentHandle() const;
    const VExprLoopStatementHandle& getLoopStatementHandle() const;
    const VExprEventStatementHandle& getEventStatementHandle() const;
    
    VExprBlockingAssignmentHandle& getBlockingAssignHandle();
    VExprNonBlockingAssignmentHandle& getNonBlockingAssignHandle();
    VExprSeqBlockHandle& getSeqBlockHandle();
    VExprConditionalStatementHandle& getConditionalHandle();
    VExprCaseStatementHandle& getCaseStatementHandle();
    VExprProceduralContinuousAssignmentHandle& getProceduralContinuousAssignmentHandle();
    VExprLoopStatementHandle& getLoopStatementHandle();
    VExprEventStatementHandle& getEventStatementHandle();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprStatementOrNullHandle toStatementOrNullHandle() const;
};

#endif // VEXPR_STATEMENT_H
