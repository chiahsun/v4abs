#include "Exception.h"

const char* NotOverridenException::what() const { return "This base class is not overriden by child class"; }

const char* NotImplementedException::what() const { return "This function segment is not implemented yet"; }

const char* InvalidTypeException::what() const { return "Invalid type for this function"; }

const char* CheckFailException::what() const { return "Fail to pass the check procedure"; }
    
CheckFailException::CheckFailException() 
  : _msg("Empty fail message")
  { }
CheckFailException::CheckFailException(const char* itsMsg)
  : _msg(itsMsg)
  { }

const char* CheckFailException::msg() const
  { return _msg; }
    
const char* NoSuchBranchException::what() const { return "This branch drops through default branch, check if there is branch available or create a branch to accept this branch"; }

