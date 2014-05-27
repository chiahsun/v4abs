#include "VExprStatementOrNullInterface.h"
#include "exception/Exception.h"

VExprStatementOrNullInterface::~VExprStatementOrNullInterface() { }

std::string VExprStatementOrNullInterface::getString() const { throw NotOverridenException(); }
    
std::string VExprStatementOrNullInterface::getString(unsigned int pos) const {
    throw NotOverridenException();
}
