#include "VRExprAssignment.h"
#include "nstl/for_each/ForEach.h"

VRExprAssignment::VRExprAssignment(VRExprExpression lhs, VRExprExpression rhs)
  : _exprLhs(lhs)
  , _exprRhs(rhs)
  { initStaticSensitivity(); }

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
    CONST_FOR_EACH(staticSens, _hashStaticSensitivity) {
        if (begin) 
            s += " or ";
        s = s + staticSens.toString();
        begin = true;
    }
    CONST_FOR_EACH(posSens, _hashPosedgeSensitivity) {
        if (begin) 
            s += " or ";
        s = s + "posedge " + posSens.toString();
        begin = true;
    }
    CONST_FOR_EACH(negSens, _hashNegedgeSensitivity) {
        if (begin) 
            s += " or ";
        s = s + "negedge " + negSens.toString();
        begin = true;
    }

    return s;
}
    
void VRExprAssignment::initStaticSensitivity() {
   // TODO
}
