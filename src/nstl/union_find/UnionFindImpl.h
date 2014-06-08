#ifndef UNION_FIND_IMPL_H
#define UNION_FIND_IMPL_H

#include <vector>

class UnionFindImpl {
public:
    typedef unsigned int id_type;
private:
    std::vector<id_type> _vecItsParent;
    std::vector<unsigned int> _vecWeight;
public:
    UnionFindImpl(unsigned int nElement);
    id_type find(id_type id);
    id_type unite(id_type idx, id_type idy);
    id_type addElement();
      
private:
    id_type findAndLinkedUp(id_type id);
    id_type parent(id_type id) const;
    id_type weight(id_type id) const;
};


#endif // UNION_FIND_IMPL_H
