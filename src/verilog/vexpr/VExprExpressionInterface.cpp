#include "exception/Exception.h"
#include "VExprExpressionInterface.h"
#include "VExprExpression.h"

VExprExpressionInterface::~VExprExpressionInterface()
  { }

std::string VExprExpressionInterface::getString() const
  { throw NotOverridenException(); }

size_t VExprExpressionInterface::getSize() const
  { throw NotOverridenException(); }


