#include "VExprNetLvalueInterface.h"
#include "exception/Exception.h"
#include "nstl/hash/HashFunction.h"

VExprNetLvalueInterface::~VExprNetLvalueInterface() { }

std::string VExprNetLvalueInterface::getString() const
  { throw NotOverridenException(); }
    
int VExprNetLvalueInterface::hashFunction() const
  { return HashFunction<std::string>::hashFunction(getString()); }
    
