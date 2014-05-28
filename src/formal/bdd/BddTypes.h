#ifndef BDD_TYPES_H
#define BDD_TYPES_H

#include "nstl/shared_ptr/SharedPtrE.h"

class BddNode;
typedef SharedPtrE<BddNode> BddNodeHandle;
typedef std::pair<BddNodeHandle, BddNodeHandle> BddNodeAndPair;

class BddManager;

typedef int bdd_id_type;

#endif // BDD_TYPES_H
