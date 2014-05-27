#include "VExprPrimaryInterface.h"
#include "exception/Exception.h"
VExprPrimaryInterface::~VExprPrimaryInterface() { }

std::string VExprPrimaryInterface::getString() const
  { throw NotOverridenException(); }

size_t VExprPrimaryInterface::getSize() const
  { throw NotOverridenException(); }

