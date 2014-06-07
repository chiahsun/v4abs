#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include "HashTableInterface.h"
#include "LinearProbingHash.h"

template <class T>
class HashTable {
    typedef LinearProbingHash<T> hash_impl_type;
    typedef HashTableGeneric<hash_impl_type> hash_type;
    typedef T value_type;
//    typedef hash_type::value_type value_type;
public:
    typedef typename hash_impl_type::iterator iterator;
    typedef typename hash_impl_type::const_iterator const_iterator;
private:
    typedef HashTable<value_type> this_type;

    hash_type _hash;

public:
    HashTable() { }
    HashTable(const this_type & rhs) : _hash(rhs._hash) 
      { }

    bool hasValue(const value_type & val) const
      { return _hash.hasValue(val); }

    void insert(const value_type & val)
      { _hash.insert(val); }

    size_t size() const
      { return _hash.size(); }
    
    const_iterator cbegin() const
      { return _hash.cbegin(); }

    const_iterator cend() const
      { return _hash.cend(); }

    const_iterator begin() const
      { return _hash.cbegin(); }

    const_iterator end() const
      { return _hash.cend(); }

    iterator begin() 
      { return _hash.begin(); }

    iterator end() 
      { return _hash.end(); }

    const_iterator find(const value_type & val) const
      { return _hash.cfind(val); }

    iterator find(const value_type & val) 
      { return _hash.find(val); }
    
    void erase(const value_type & val)
      { _hash.erase(val); }

    void printBalance() const
      { _hash.printBalance(); }

    void clear()
      { _hash.clear(); }
};

#endif // HASH_TABLE_H
