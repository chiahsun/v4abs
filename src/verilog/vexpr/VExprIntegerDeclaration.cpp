#include "VExprIntegerDeclaration.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"
    
VExprIntegerDeclaration::VExprIntegerDeclaration(const std::vector<VExprRegisterNameHandle> & vecRegisterName)
  : _vecRegisterName(vecRegisterName)
  { }

const std::vector<VExprRegisterNameHandle>& VExprIntegerDeclaration::getContainer() const
  { return  _vecRegisterName; }

std::vector<VExprRegisterNameHandle>& VExprIntegerDeclaration::getContainer()
  { return  _vecRegisterName; }

std::string VExprIntegerDeclaration::getString() const 
  { return getString(0); }
    
std::string VExprIntegerDeclaration::getString(unsigned int indentLevel) const {
    std::string s;
    s = indent(indentLevel) + "integer ";
    int pos = 0;
    CONST_FOR_EACH(x, getContainer()) {
        if (pos != 0)
            s += ", ";
        s = s += x->getString();
        ++pos;
    }
    s += ";\n";
    return s;
}
