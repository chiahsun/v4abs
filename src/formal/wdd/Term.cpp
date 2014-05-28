#include "Term.h"
#include <cstring>

Term::hash_id Term::_hashId = WddTermInterface::getNextTermHashId();

Term::Term(const std::string& nm)
  : _name(nm)
  { }


Term::hash_id Term::getTermHashId() {
    return _hashId;
}
    
std::string Term::toString() const {
    return _name;
}
    
bool Term::operator < (const Term & rhs) const {
    return strcmp(_name.c_str(), rhs._name.c_str());
}
