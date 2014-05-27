#ifndef VEXPR_EVENT_STATEMENT_H
#define VEXPR_EVENT_STATEMENT_H

/**
 * Note: The original naming is - procedural_timing_control_statement
 */

#include "VExprStatementOrNull.h"
#include "VExprStatementInterface.h"

class VExprEventStatement : public VExprStatementInterface {
    VExprEventExpressionHandle _pEventExpression;
    VExprStatementOrNullHandle _pStatementOrNull;
public:
    VExprEventStatement(VExprEventExpressionHandle pEventExpression, VExprStatementOrNullHandle pStatementOrNull);
    VExprEventStatement(VExprStatementOrNullHandle pStatementOrNull);

    VExprEventExpressionHandle getEventExpressionHandle() const;
    VExprStatementOrNullHandle getStatementOrNullHandle() const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

class VExprEventExpression {
    std::vector<VExprEventHandle> _vecEvent;
public:
    VExprEventExpression();
    VExprEventExpression(VExprEventHandle pEvent);
    // Join two event expression
    VExprEventExpression(VExprEventExpressionHandle pFst, VExprEventExpressionHandle pSnd);
    static VExprEventExpressionHandle getEmptyEventExpressionHandle();
    void push_back(VExprEventHandle pEvent);

    unsigned int getEventHandleSize() const;
    VExprEventHandle getEventHandle(unsigned int pos) const;

    std::string getString() const;        
};

class VExprEvent {
    VExprEventInterfaceHandle _pInterface;

    VExprExpressionHandle _pExpr;
    VExprIdentifierHandle _pIdentifier;
    VExprPosedgeEventHandle _pPosedgeEvent;
    VExprNegedgeEventHandle _pNegedgeEvent;
public:
    VExprEvent(VExprExpressionHandle pExpr);
    VExprEvent(VExprIdentifierHandle pIdentifier);
    VExprEvent(VExprPosedgeEventHandle pPosedgeEvent);
    VExprEvent(VExprNegedgeEventHandle pNegedgeEvent);

    VExprExpressionHandle getExpressionHandle() const;
    VExprIdentifierHandle getIdentifierHandle() const;
    VExprPosedgeEventHandle getPosedgeEventHandle() const;
    VExprNegedgeEventHandle getNegedgeEventHandle() const;

    std::string getString() const;
};

class VExprPosedgeEvent : public VExprEventInterface {
    VExprExpressionHandle _pExpr;
public:
    VExprPosedgeEvent(VExprExpressionHandle pExpr);

    VExprExpressionHandle getExpr() const;

    std::string getString() const;
};


class VExprNegedgeEvent : public VExprEventInterface {
    VExprExpressionHandle _pExpr;
public:
    VExprNegedgeEvent(VExprExpressionHandle pExpr);

    VExprExpressionHandle getExpr() const;

    std::string getString() const;
};

#endif // VEXPR_EVENT_STATEMENT_H
