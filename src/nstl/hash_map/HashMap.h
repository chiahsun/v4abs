#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "nstl/hash/HashTable.h"
#include "nstl/for_each/ForEach.h"
#include <iostream>
#include <utility>

template <class _KeyType, class _MappedType>
class HashMap {
    typedef _KeyType key_type;
    typedef _MappedType mapped_type;
    class Pair {
    public:
        key_type first;
        mapped_type second;
        Pair(key_type itsKey, mapped_type itsMapped) 
          : first(itsKey), second(itsMapped) 
          { }
        Pair(const Pair & rhs)
          { copy(rhs); }
        Pair& operator = (const Pair & rhs) {
            first = rhs.first;
            second = rhs.second;
#if 0
            if (this != &rhs) {
                copy(rhs);
            }
#endif
            return *this;
        }
        int hashFunction() const { 
            return HashFunction<key_type>::hashFunction(first); 
        }
        // Implement the key compare function
        bool operator == (const Pair & rhs) const {
            if (this == &rhs)
                return true;
            return (first == rhs.first); 
        }
    private:
        void copy(const Pair & rhs) {
            first = rhs.first;
            second = rhs.second;
        }
    };
    typedef Pair pair_type;

    typedef HashTable<pair_type> hash_type;
    typedef HashMap<key_type, mapped_type> this_type;

    hash_type _hash;
public:
    typedef typename hash_type::iterator iterator;
    typedef typename hash_type::const_iterator const_iterator;
public:
    HashMap() { }
    HashMap(const HashMap & rhs) 
      { copy(rhs); }

    HashMap& operator=(const HashMap & rhs) {
        if (this != &rhs) {
            copy(rhs);
        }
        return *this;
    }

    void copy(const HashMap & rhs) {
        _hash = rhs._hash;
    }

    bool hasKey(const key_type & key) const
      { return _hash.hasValue(pair_type(key)); }

    iterator insert(std::pair<key_type, mapped_type> pr) {
        // TODO
        // bug for return iterator returned by insert
        // so use find again 
//        return 
          _hash.insert(pair_type(pr.first, pr.second));
          return find(pr.first);
    }

    size_t size() const
      { return _hash.size(); }

    const_iterator cbegin() const
      { return _hash.cbegin(); }

    const_iterator cend() const
      { return _hash.cend(); }

    const_iterator begin() const
      { return _hash.begin(); }

    const_iterator end() const
      { return _hash.end(); }

    iterator begin()
      { return _hash.begin(); }

    iterator end()
      { return _hash.end(); }

    const_iterator find(key_type key) const
      { return _hash.find(pair_type(key, mapped_type())); }

    iterator find(key_type key) 
      { return _hash.find(pair_type(key, mapped_type())); }
    
    void erase(key_type key)
      { return _hash.erase(key); }

    void clear()
      { _hash.clear(); }


};

#endif // HASH_MAP_H
