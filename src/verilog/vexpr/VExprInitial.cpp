#include "VExprInitial.h"

VExprInitial::VExprInitial(VExprStatementHandle pStatement)
  : _pStatement(pStatement)
  { }

VExprStatementHandle VExprInitial::getStatementHandle() const
  { return _pStatement; }
    
std::string VExprInitial::getString() const
  { return getString(0); }

std::string VExprInitial::getString(unsigned int indentLevel) const {
    return "initial " + getStatementHandle()->getString(indentLevel);
}
