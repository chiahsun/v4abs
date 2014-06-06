#include "VExprEventStatement.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
    
VExprEventStatement::VExprEventStatement(VExprEventExpressionHandle pEventExpression, VExprStatementOrNullHandle pStatementOrNull)
  : _pEventExpression(pEventExpression)
  , _pStatementOrNull(pStatementOrNull)
  { }
    
VExprEventStatement::VExprEventStatement(VExprStatementOrNullHandle pStatementOrNull)
  : _pEventExpression(VExprEventExpression::getEmptyEventExpressionHandle())
  , _pStatementOrNull(pStatementOrNull)
  { }

VExprEventExpressionHandle VExprEventStatement::getEventExpressionHandle() const
  { return _pEventExpression; }

VExprStatementOrNullHandle VExprEventStatement::getStatementOrNullHandle() const
  { return _pStatementOrNull; }

std::string VExprEventStatement::getString() const
  { return getString(0); }

std::string VExprEventStatement::getString(unsigned int indentLevel) const {
    std::string s = indent(indentLevel) + "always @ (";
    s += getEventExpressionHandle()->getString();
    s += ")\n";
    s += getStatementOrNullHandle()->getString(indentLevel+1);
    return s;
}
    
VExprEventStatementHandle VExprEventStatement::flatten(VExprIdentifierHandle pInstName) const {
    return VExprEventStatementHandle(VExprEventStatement(
                getEventExpressionHandle()->flatten(pInstName)
              , getStatementOrNullHandle()->flatten(pInstName)
            ));
}
    
VExprEventExpression::VExprEventExpression() { }
    
VExprEventExpression::VExprEventExpression(VExprEventHandle pEvent) {
    push_back(pEvent);
}
    
VExprEventExpression::VExprEventExpression(std::vector<VExprEventHandle> vecEvent)
  : _vecEvent(vecEvent)
  { }
    
VExprEventExpression::VExprEventExpression(VExprEventExpressionHandle pFst, VExprEventExpressionHandle pSnd) {
    CONST_FOR_EACH(x, pFst->_vecEvent) {
        push_back(x);
    }

    CONST_FOR_EACH(x, pSnd->_vecEvent) {
        push_back(x);
    }
}
    
VExprEventExpressionHandle VExprEventExpression::getEmptyEventExpressionHandle() 
  { return VExprEventExpressionHandle(VExprEventExpression()); }

void VExprEventExpression::push_back(VExprEventHandle pEvent)
  { _vecEvent.push_back(pEvent); }

unsigned int VExprEventExpression::getEventHandleSize() const
  { return _vecEvent.size(); }

VExprEventHandle VExprEventExpression::getEventHandle(unsigned int pos) const {
    assert(pos < getEventHandleSize());
    return _vecEvent[pos];
}
    
const std::vector<VExprEventHandle> & VExprEventExpression::getEventHandleContainer() const {
    return _vecEvent;
}

std::string VExprEventExpression::getString() const {
    if (getEventHandleSize() == 0)
        return "*";
    std::string s = getEventHandle(0)->getString();
    for (unsigned int i = 1; i < getEventHandleSize(); ++i) {
        s = s + " or " + getEventHandle(i)->getString();
    }
    return s;
}
    
VExprEventExpressionHandle VExprEventExpression::flatten(VExprIdentifierHandle pInstName) const {
    std::vector<VExprEventHandle> vecFlatEvent;

    CONST_FOR_EACH(pEvent, getEventHandleContainer()) {
        vecFlatEvent.push_back(pEvent->flatten(pInstName));
    }

    return VExprEventExpressionHandle(VExprEventExpression(vecFlatEvent));
}
    
VExprEvent::VExprEvent(VExprExpressionHandle pExpr)
  : _pInterface(shared_ptr_cast<VExprEventInterface>(pExpr))
  , _pExpr(pExpr)
  { }

VExprEvent::VExprEvent(VExprIdentifierHandle pIdentifier)
  : _pInterface(shared_ptr_cast<VExprEventInterface>(pIdentifier))
  , _pIdentifier(pIdentifier)
  { }
    
VExprEvent::VExprEvent(VExprPosedgeEventHandle pPosedgeEvent)
  : _pInterface(shared_ptr_cast<VExprEventInterface>(pPosedgeEvent))
  , _pPosedgeEvent(pPosedgeEvent)
  { }
    
VExprEvent::VExprEvent(VExprNegedgeEventHandle pNegedgeEvent)
  : _pInterface(shared_ptr_cast<VExprEventInterface>(pNegedgeEvent))
  , _pNegedgeEvent(pNegedgeEvent)
  { }

VExprExpressionHandle VExprEvent::getExpressionHandle() const
  { return _pExpr; }
    
VExprIdentifierHandle VExprEvent::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprPosedgeEventHandle VExprEvent::getPosedgeEventHandle() const
  { return _pPosedgeEvent; }
    
VExprNegedgeEventHandle VExprEvent::getNegedgeEventHandle() const
  { return _pNegedgeEvent; } 

std::string VExprEvent::getString() const
  { return _pInterface->getString(); }
    
VExprEventHandle VExprEvent::flatten(VExprIdentifierHandle pInstName) const {
    if (getExpressionHandle().valid()) {
        return VExprEventHandle(VExprEvent(getExpressionHandle()->flatten(pInstName)));
    } else if (getIdentifierHandle().valid()) {
        return VExprEventHandle(VExprEvent(getIdentifierHandle()->flatten(pInstName)));
    } else if (getPosedgeEventHandle().valid()) {
        return VExprEventHandle(VExprEvent(getPosedgeEventHandle()->flatten(pInstName)));
    } else if (getNegedgeEventHandle().valid()) {
        return VExprEventHandle(VExprEvent(getNegedgeEventHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

VExprPosedgeEvent::VExprPosedgeEvent(VExprExpressionHandle pExpr)
  : _pExpr(pExpr)
  { }

VExprExpressionHandle VExprPosedgeEvent::getExpr() const
  { return _pExpr; }

std::string VExprPosedgeEvent::getString() const {
    return "posedge " + getExpr()->getString();
}
    
VExprPosedgeEventHandle VExprPosedgeEvent::flatten(VExprIdentifierHandle pInstName) const {
    return VExprPosedgeEventHandle(VExprPosedgeEvent(getExpr()->flatten(pInstName)));
}

VExprNegedgeEvent::VExprNegedgeEvent(VExprExpressionHandle pExpr)
  : _pExpr(pExpr)
  { }

VExprExpressionHandle VExprNegedgeEvent::getExpr() const
  { return _pExpr; }

std::string VExprNegedgeEvent::getString() const {
    return "negedge " + getExpr()->getString();
}
    
VExprNegedgeEventHandle VExprNegedgeEvent::flatten(VExprIdentifierHandle pInstName) const {
    return VExprNegedgeEventHandle(VExprNegedgeEvent(getExpr()->flatten(pInstName)));
}
