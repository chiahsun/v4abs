#ifndef VEXPR_LOOP_STATEMENT_H
#define VEXPR_LOOP_STATEMENT_H

#include "VExprRegAssignment.h"
#include "VExprStatementInterface.h"

class VExprLoopStatement : public VExprStatementInterface {
    VExprRegAssignmentHandle _pForInit;
    VExprExpressionHandle _pForCond;
    VExprRegAssignmentHandle _pForAssign;

    VExprStatementHandle _pStatement;
public:
    VExprLoopStatement( VExprRegAssignmentHandle pForInit
                      , VExprExpressionHandle pForCond
                      , VExprRegAssignmentHandle pForAssign
                      , VExprStatementHandle pStatement);

    VExprRegAssignmentHandle& getForInitHandle();
    VExprExpressionHandle& getForCondHandle();
    VExprRegAssignmentHandle& getForAssignHandle();
    VExprStatementHandle& getStatementHandle();

    const VExprRegAssignmentHandle& getForInitHandle() const;
    const VExprExpressionHandle& getForCondHandle() const;
    const VExprRegAssignmentHandle& getForAssignHandle() const;
    const VExprStatementHandle& getStatementHandle() const;


    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprLoopStatementHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_LOOP_STATEMENT_H
