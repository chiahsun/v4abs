#include "VExprStatementInterface.h"
#include "exception/Exception.h"

VExprStatementInterface::~VExprStatementInterface() { }

std::string VExprStatementInterface::getString() const {
    throw NotOverridenException();
}
    
std::string VExprStatementInterface::getString(unsigned int indentLevel) const {
    throw NotOverridenException();
}
