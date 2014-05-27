#ifndef VEXPR_PROCEDURAL_CONTINUOUS_ASSIGNMENT_H
#define VEXPR_PROCEDURAL_CONTINUOUS_ASSIGNMENT_H

#include "VExprRegAssignment.h"
#include "VExprStatementInterface.h"


class VExprProceduralContinuousAssignment : public VExprStatementInterface {
    VExprRegAssignmentHandle _pRegAssignment;
public:
    VExprProceduralContinuousAssignment(VExprRegAssignmentHandle pRegAssignment);

    VExprRegAssignmentHandle& getRegAssignment();
    const VExprRegAssignmentHandle& getRegAssignment() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

#endif // VEXPR_PROCEDURAL_CONTINUOUS_ASSIGNMENT_H
