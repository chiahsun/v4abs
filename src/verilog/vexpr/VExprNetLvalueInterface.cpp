#include "VExprNetLvalueInterface.h"
#include "exception/Exception.h"

VExprNetLvalueInterface::~VExprNetLvalueInterface() { }

std::string VExprNetLvalueInterface::getString() const
  { throw NotOverridenException(); }
