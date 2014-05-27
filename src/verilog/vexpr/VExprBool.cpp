#include "VExprBool.h"

VExprBool::VExprBool(bool boolVal)
  : _boolVal(boolVal)
  { }

VExprBoolHandle VExprBool::getTrueHandle() {
    static VExprBoolHandle pTrue =
        VExprBoolHandle(VExprBool(true));
    return pTrue;
}

VExprBoolHandle VExprBool::getFalseHandle() {
    static VExprBoolHandle pFalse =
        VExprBoolHandle(VExprBool(false));
    return pFalse;
}

bool VExprBool::getValue() const
  { return _boolVal; }
    
std::string VExprBool::getString() const {
    if (getValue()) return "true";
    else            return "false";
}
    
size_t VExprBool::getSize() const {
    return 1;
}
