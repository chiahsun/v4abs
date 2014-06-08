#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "nstl/hash_map/HashMap.h"
#include "UnionFindImpl.h"

template <class T>
class UnionFind {
    typedef T key_type;
    typedef UnionFindImpl impl_type;
    typedef typename impl_type::id_type id_type;

    typedef HashMap<key_type, id_type> hash_map_type;
    typedef HashMap<id_type, key_type> reverse_hash_map_type;

    hash_map_type _hashMap;
    reverse_hash_map_type _reverseHashMap;
    impl_type _unionFindImpl;
public:
    UnionFind()
      : _unionFindImpl(0)
      { }

    key_type find(key_type key) {
        id_type id = findHelper(key);
        return _reverseHashMap.find(id)->second;
    }

    key_type unite(key_type kx, key_type ky) {
        id_type id = uniteHelper(kx, ky);
        return _reverseHashMap.find(id)->second;
    }
    
    id_type addElement(key_type key) {
        id_type newId = _unionFindImpl.addElement();
        _hashMap.insert(std::make_pair(key, newId));
        _reverseHashMap.insert(std::make_pair(newId, key));
 
        return newId;
    }
private:
    id_type findHelper(key_type key) {
        id_type id = 0;
        if (_hashMap.find(key) == _hashMap.end()) 
            id = addElement(key);
        else
            id = _hashMap.find(key)->second;
        return _unionFindImpl.find(id);
    }

    id_type uniteHelper(key_type kx, key_type ky) {
        id_type idx = 0, idy = 0;
        if (_hashMap.find(kx) == _hashMap.end())
            idx = addElement(kx);
        else
            idx = _hashMap.find(kx)->second;

        if (_hashMap.find(ky) == _hashMap.end())
            idy = addElement(ky);
        else
            idy = _hashMap.find(ky)->second;

        return _unionFindImpl.unite(idx, idy);
    }

};

#endif // UNION_FIND_H
