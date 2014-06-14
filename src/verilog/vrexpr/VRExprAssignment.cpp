#include "VRExprAssignment.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
    
VRExprAssignment::VRExprAssignment()
  : _exprLhs(makeIdentifier("default"))
  , _exprRhs(makeIdentifier("default"))
  { }

VRExprAssignment::VRExprAssignment(VRExprExpression lhs, VRExprExpression rhs)
  : _exprLhs(lhs)
  , _exprRhs(rhs) { 
    initStaticSensitivity();
    initTerminalExpressions();
    initMuxExpressions();
    initTermManager();
}

VRExprExpression VRExprAssignment::getExprLhs() const
  { return _exprLhs; }

VRExprExpression VRExprAssignment::getExprRhs() const
  { return _exprRhs; }
    
void VRExprAssignment::addStaticSensitivity(VRExprExpression expr)
  { _hashStaticSensitivity.insert(expr); }

void VRExprAssignment::addPosedgeSensitivity(VRExprExpression expr)
  { _hashPosedgeSensitivity.insert(expr); }

void VRExprAssignment::addNegedgeSensitivity(VRExprExpression expr)
  { _hashNegedgeSensitivity.insert(expr); }
    
void VRExprAssignment::addStaticSensitivity(VRExprIdentifier identifier) {
    return addStaticSensitivity(VRExprExpression(VRExprPrimary(identifier)));
}

void VRExprAssignment::addPosedgeSensitivity(VRExprIdentifier identifier) {
    return addPosedgeSensitivity(VRExprExpression(VRExprPrimary(identifier)));
}

void VRExprAssignment::addNegedgeSensitivity(VRExprIdentifier identifier) {
    return addNegedgeSensitivity(VRExprExpression(VRExprPrimary(identifier)));
}
    

std::string VRExprAssignment::toString() const {
    bool begin = false;
    std::string s = "always @ (";
    CONST_FOR_EACH(posSens, _hashPosedgeSensitivity) {
        if (begin) 
            s += " or ";
        s = s + "posedge " + posSens.toString();
        begin = true;
    }
    if (_hashPosedgeSensitivity.size() != 0) 
        s += ") @ (";
    begin = false;
    CONST_FOR_EACH(negSens, _hashNegedgeSensitivity) {
        if (begin) 
            s += " or ";
        s = s + "negedge " + negSens.toString();
        begin = true;
    }
    if (_hashNegedgeSensitivity.size() != 0)
        s += ") @ (";
    begin = false;
    CONST_FOR_EACH(staticSens, _hashStaticSensitivity) {
        if (begin) 
            s += " or ";
        s = s + staticSens.toString();
        begin = true;
    }
    s += ")\n";
    s = s + "       => (rhs_terminals ";
    unsigned int pos = 0;
    CONST_FOR_EACH(terminal, _hashTerminals) {
        if (pos++ != 0)
            s += ", ";
        s += terminal.toString();
    }
    s += ")\n";
    
    s = s + "       => (mux_terminals ";
    pos = 0;
    CONST_FOR_EACH(mux, _vecMux) {
        if (pos++ != 0)
            s += ", ";
        s += mux.toString();
    }
    s += ")\n";
    s = s + _exprLhs.toString() + " = " ;
    s += _exprRhs.toString();
    return s;
}
    
void VRExprAssignment::initStaticSensitivity() {
    _hashStaticSensitivity = _exprRhs.getStaticSensitivity();
}

void VRExprAssignment::initTerminalExpressions() {
    _hashTerminals = _exprRhs.getTerminalExpressions();
}

void VRExprAssignment::initMuxExpressions() {
    _vecMux = _exprRhs.getMuxExpressions();
}

void VRExprAssignment::initTermManager() {
    CONST_FOR_EACH(terminal, _hashTerminals) {
        _termManager.addExpr(terminal);
    }

    for (int i = static_cast<int>(_vecMux.size())-1; i >= 0; --i)
        _termManager.addExpr(_vecMux[i]);

    WddNodeHandle pRhs = _exprRhs.buildWddNode(_termManager);
    DEBUG_EXPR(_termManager.stringOfNode(pRhs));
}
