#include "VExprSelectInterface.h"
#include "exception/Exception.h"

VExprSelectInterface::~VExprSelectInterface() { }

std::string VExprSelectInterface::getString() const {
    throw NotOverridenException();
}

size_t VExprSelectInterface::getSize() const {
    throw NotOverridenException();
}
