#ifndef VEXPR_CASE_STATEMENT_H
#define VEXPR_CASE_STATEMENT_H

#include "VExprStatementInterface.h"
#include "VExprExpression.h"


class VExprCaseStatement : public VExprStatementInterface {
    VExprExpressionHandle _pExpr;
    std::vector<VExprCaseItemHandle> _vecCaseItem;
public:
    VExprCaseStatement(VExprExpressionHandle pExpr);
    VExprCaseStatement(VExprExpressionHandle pExpr, const std::vector<VExprCaseItemHandle> & vecCaseItem);



    const VExprExpressionHandle& getConstExpressionHandle() const;
    VExprExpressionHandle& getExpressionHandle();
    const std::vector<VExprCaseItemHandle>& getConstCaseItemContainer() const;
    std::vector<VExprCaseItemHandle>& getCaseItemContainer();

    void push_back(VExprCaseItemHandle pCaseItem);

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

    VExprStatementHandle toStatemetHandle() const;
    VExprStatementOrNullHandle toStatemetOrNullHandle() const;
};

class VExprCaseItem {
    std::vector<VExprExpressionHandle> _vecExpression;
    VExprStatementOrNullHandle _pStatementOrNull;
public:
    VExprCaseItem(VExprExpressionHandle pExpr, VExprStatementOrNullHandle pStatementOrNull);
    VExprCaseItem(const std::vector<VExprExpressionHandle> & vecExpr, VExprStatementOrNullHandle pStatementOrNull);
    // Default case
    VExprCaseItem(VExprStatementOrNullHandle pStatementOrNull);

    const std::vector<VExprExpressionHandle>& getExpressionHandleContainer() const;
    std::vector<VExprExpressionHandle>& getExpressionHandleContainer();

    const VExprStatementOrNullHandle& getStatementOrNullHandle() const;
    VExprStatementOrNullHandle& getStatementOrNullHandle();

    std::string getString() const; 
    std::string getString(unsigned int indentLevel) const; 
};

#endif // VEXPR_CASE_STATEMENT_H
