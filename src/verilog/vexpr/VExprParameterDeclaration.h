#ifndef VEXPR_PARAMETER_DECLARATION_H
#define VEXPR_PARAMETER_DECLARATION_H

#include "VExprModuleItemDeclarationInterface.h"
#include "VExprIdentifier.h"
#include "VExprExpression.h"



class VExprParameterDeclaration : public VExprModuleItemDeclarationInterface {
    std::vector<VExprParamAssignmentHandle> _vecParaAssignment;
public:
    VExprParameterDeclaration();
    VExprParameterDeclaration(const std::vector<VExprParamAssignmentHandle> & vecParamAssignment);

    std::vector<VExprParamAssignmentHandle>& getParaAssignmentHandleContainer();
    const std::vector<VExprParamAssignmentHandle>& getParaAssignmentHandleContainer() const;

    void push_back(VExprParamAssignmentHandle pParaAssignment);

    std::string getString() const;

    VExprParameterDeclarationHandle flatten(VExprIdentifierHandle pInstName) const;
};

class VExprParamAssignment {
    VExprIdentifierHandle _pIdentifier;
    VExprExpressionHandle _pExpression;
public:
    VExprParamAssignment(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpression);

    VExprIdentifierHandle& getIdentifierHandle();
    VExprExpressionHandle& getExpressionHandle();
    const VExprIdentifierHandle& getIdentifierHandle() const;
    const VExprExpressionHandle& getExpressionHandle() const;

    std::string getString() const;

    VExprParamAssignmentHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_PARAMETER_DECLARATION_H
