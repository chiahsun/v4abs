#include "VExprRegLvalueInterface.h"
#include "exception/Exception.h"

VExprRegLvalueInterface::~VExprRegLvalueInterface() { }

std::string VExprRegLvalueInterface::getString() const {
    throw NotOverridenException();
}
