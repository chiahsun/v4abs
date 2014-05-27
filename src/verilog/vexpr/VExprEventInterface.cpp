#include "VExprEventInterface.h"
#include "exception/Exception.h"

VExprEventInterface::~VExprEventInterface() { }

std::string VExprEventInterface::getString() const
  { throw NotOverridenException(); }
