#include "VExprConstantExpressionInterface.h"
#include "exception/Exception.h"

VExprConstantExpressionInterface::~VExprConstantExpressionInterface() { }
std::string VExprConstantExpressionInterface::getString() const {
    throw NotOverridenException();
}
