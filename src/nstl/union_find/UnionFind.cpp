#include "UnionFind.h"

#include <cassert>

UnionFind::UnionFind(unsigned int nElement) {
    for (unsigned int i = 0; i < nElement; ++i) {
        _vecItsParent.push_back(i);
        _vecWeight.push_back(1);
    }
}
    
UnionFind::id_type UnionFind::find(id_type id) {
    return findAndLinkedUp(id);
}
 
UnionFind::id_type UnionFind::unite(id_type idx, id_type idy) {
    // Already the same root
    id_type idRoot = 0;
    if ((idRoot = findAndLinkedUp(idx)) == findAndLinkedUp(idy))
        return idRoot;

    id_type idxRoot = find(idx);
    id_type idyRoot = find(idy);
    if (_vecWeight[idxRoot] > _vecWeight[idyRoot]) {
        _vecItsParent[idyRoot] = idxRoot;
        _vecWeight[idxRoot] = weight(idxRoot)  + weight(idyRoot);
        return idxRoot;
    } else {
        _vecItsParent[idxRoot] = idyRoot;
        _vecWeight[idyRoot] = weight(idyRoot) + weight(idxRoot);
        return find(idyRoot);
    }

    assert(0);
}
    
UnionFind::id_type UnionFind::findAndLinkedUp(id_type id) {
    id_type idChild = id;
    id_type idParent = parent(idChild);
    while(idParent != idChild) {
        _vecItsParent[idChild] = parent(idParent);
        idChild = idParent;
        idParent = parent(idParent);
    }

    return idParent;
}
    
UnionFind::id_type UnionFind::parent(id_type id) const {
    assert(id < _vecItsParent.size());
    return _vecItsParent[id];
}

UnionFind::id_type UnionFind::weight(id_type id) const {
    assert(id < _vecWeight.size());
    return _vecWeight[id];
}
