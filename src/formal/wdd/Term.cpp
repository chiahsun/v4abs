#include "Term.h"
#include <cstring>

Term::Term(const std::string& nm)
  : _name(nm)
  { }

std::string Term::toString() const {
    return _name;
}
    
bool Term::operator < (const Term & rhs) const {
    return _name < rhs._name;
//    return strcmp(_name.c_str(), rhs._name.c_str());
}
