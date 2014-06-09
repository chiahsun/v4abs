#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "nstl/hash_map/HashMap.h"
#include "nstl/hash/HashTable.h"
#include "UnionFindImpl.h"

template <class T>
class UnionFind {
    typedef T key_type;
    typedef UnionFindImpl impl_type;
    typedef typename impl_type::id_type id_type;

    typedef HashTable<key_type> key_hash_map_type;
    typedef HashMap<key_type, id_type> key_id_hash_map_type;
    typedef HashMap<id_type, key_type> id_key_hash_map_type;

    key_hash_map_type _hashKey;
    key_id_hash_map_type _hashKeyId;
    id_key_hash_map_type _hashIdKey;
    impl_type _unionFindImpl;

    typedef typename key_hash_map_type::const_iterator const_iterator;
    typedef typename key_hash_map_type::iterator iterator;
public:
    UnionFind()
      : _unionFindImpl(0)
      { }
    
    iterator begin() { return _hashKey.begin(); }
    iterator end() { return _hashKey.end(); }
    const_iterator begin() const { return _hashKey.begin(); }
    const_iterator end() const { return _hashKey.end(); }


    key_type find(key_type key) {
        id_type id = findHelper(key);
        return _hashIdKey.find(id)->second;
    }

    key_type unite(key_type kx, key_type ky) {
        id_type id = uniteHelper(kx, ky);
        return _hashIdKey.find(id)->second;
    }
    
    id_type addElement(key_type key) {
        id_type newId = _unionFindImpl.addElement();
        _hashKey.insert(key);
        _hashKeyId.insert(std::make_pair(key, newId));
        _hashIdKey.insert(std::make_pair(newId, key));
 
        return newId;
    }
private:
    id_type findHelper(key_type key) {
        id_type id = 0;
        if (_hashKeyId.find(key) == _hashKeyId.end()) 
            id = addElement(key);
        else
            id = _hashKeyId.find(key)->second;
        return _unionFindImpl.find(id);
    }

    id_type uniteHelper(key_type kx, key_type ky) {
        id_type idx = 0, idy = 0;
        if (_hashKeyId.find(kx) == _hashKeyId.end())
            idx = addElement(kx);
        else
            idx = _hashKeyId.find(kx)->second;

        if (_hashKeyId.find(ky) == _hashKeyId.end())
            idy = addElement(ky);
        else
            idy = _hashKeyId.find(ky)->second;

        return _unionFindImpl.unite(idx, idy);
    }

};

#endif // UNION_FIND_H
