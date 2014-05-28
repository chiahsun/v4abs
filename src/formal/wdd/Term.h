#ifndef TERM_H
#define TERM_H

#include <string>
#include "nstl/shared_ptr/SharedPtrE.h"
#include "WddTermInterface.h"

class Term;
typedef SharedPtrE<Term> TermHandle;

class Term : public WddTermInterface {
    std::string _name;

    static hash_id _hashId;
public:
    Term(const std::string& nm);
    hash_id getTermHashId();
    std::string toString() const;

    bool operator < (const Term & rhs) const;

};


#endif // TERM_H
