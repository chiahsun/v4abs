#include "VExprConstantPrimaryInterface.h"
#include "exception/Exception.h"

VExprConstantPrimaryInterface::~VExprConstantPrimaryInterface() { }

std::string VExprConstantPrimaryInterface::getString() const {
    throw NotOverridenException();
}

size_t VExprConstantPrimaryInterface::getSize() const {
    throw NotOverridenException();
}
