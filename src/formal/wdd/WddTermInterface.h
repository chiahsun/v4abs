#ifndef WDD_NODE_INTERFACE_H
#define WDD_NODE_INTERFACE_H

#include <cassert>
#include <string>

#include "nstl/shared_ptr/SharedPtr.h"
#include "WddTypes.h"

/**
 * 1.
 * A term is a node with pos edge to T and pos edge to F.
 *     term
 *     / \
 *    T    F
 * A negation of term is also a term
 *    !term
 *     / \
 *    F    T
 *
 * 2.
 * The semantic of a expression is the traversal stop right at term (not T or F in tranditional BDD)
 *  
 *   expression pTerm1TransferFunction = term1.getTransferFunction();
 *          
 *         rst
 *       /     \
 *     0       a+1
 *    / \      /  \
 *   T   F    T    F
 *   
 *   terms = {term1, a+1, 0}
 *
 *   if (rst)
 *       term1 = 0
 *   else
 *       term1 = a+1
 *
 * 3. Note the there might be dependencies between terms
 *      
 *      term1 : type1 
 *      term2 : type1
 * 
 *    If term1 strictly depends on term2, then term1 = G(term2)
 *
 *       i.e. ONSET ^ OFFSET = UNSAT
 *
 *
 */



class WddTermInterface {
    
public:
    typedef int term_id;
    typedef int hash_id;


    virtual ~WddTermInterface(); 


    virtual hash_id getTermHashId();
    virtual std::string toString() const;

protected:
        
    static hash_id getNextTermHashId();
};

#endif // WDD_NODE_INTERFACE_H
