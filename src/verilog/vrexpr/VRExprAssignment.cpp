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
    buildWddNode();
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
    
    unsigned int pos = 0;
    
    s = s + "       + (lhs_terminals ";
    pos = 0;
    CONST_FOR_EACH(terminal, _hashLhsTerminals) {
        if (pos++ != 0)
            s += ", ";
        s += terminal.toString();
    }
    s += ")\n";

    s = s + "       + (rhs_terminals ";
    pos = 0;
    CONST_FOR_EACH(terminal, _hashRhsTerminals) {
        if (pos++ != 0)
            s += ", ";
        s += terminal.toString();
    }
    s += ")\n";
    
    
    s = s + "       + (mux_terminals ";
    pos = 0;
    CONST_FOR_EACH(mux, _vecMux) {
        if (pos++ != 0)
            s += ", ";
        s += mux.toString();
    }
    s += ")\n";

    s = s + "       + (rhs_wdd_format ";
    s += _termManager.stringOfNode(_wddNode);
    s += ")\n";

    s = s + "       - " + _exprLhs.toString() + " = " ;
    s += _exprRhs.toString();
    return s;
}
    
bool VRExprAssignment::operator == (const VRExprAssignment & rhs) const 
  { return (toString() == rhs.toString()); }
    
int VRExprAssignment::hashFunction() const
  { return HashFunction<std::string>::hashFunction(toString()); }
    
void VRExprAssignment::initStaticSensitivity() {
    _hashStaticSensitivity = _exprRhs.getStaticSensitivity();
}

void VRExprAssignment::initTerminalExpressions() {
    _hashRhsTerminals = _exprRhs.getTerminalExpressions();
    _hashLhsTerminals = _exprLhs.getTerminalExpressions();
}

void VRExprAssignment::initMuxExpressions() {
    _vecMux = _exprRhs.getMuxExpressions();
}

void VRExprAssignment::buildWddNode() {
    // Init term manager terminals
    CONST_FOR_EACH(terminal, _hashRhsTerminals) {
        _termManager.addExpr(terminal);
    }

    for (int i = static_cast<int>(_vecMux.size())-1; i >= 0; --i)
        _termManager.addExpr(_vecMux[i]);
    
    // Build the rhs wdd
    _wddNode = _exprRhs.buildWddNode(_termManager);
}

VRExprAssignment makeAssignment(VRExprExpression lhs, VRExprExpression rhs) {
    return VRExprAssignment(lhs, rhs);
}
    
const HashTable<VRExprExpression> & VRExprAssignment::getRhsTerminalHash() const
  { return _hashRhsTerminals; }

const HashTable<VRExprExpression> & VRExprAssignment::getLhsTerminalHash() const
  { return _hashLhsTerminals; }

const HashTable<VRExprExpression>& VRExprAssignment::getStaticSensitivity() const
  { return _hashStaticSensitivity; }

const HashTable<VRExprExpression>& VRExprAssignment::getPosedgeSensitivity() const
  { return _hashPosedgeSensitivity; }

const HashTable<VRExprExpression>& VRExprAssignment::getNegedgeSensitivity() const
  { return _hashNegedgeSensitivity; }

