#ifndef HASH_TABLE_INTERFACE_H
#define HASH_TABLE_INTERFACE_H

template <class _HashType>
class HashTableGeneric {
public:
    typedef _HashType container_type;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    typedef HashTableGeneric<_HashType> this_type;
private:
    container_type _container;

public:
    HashTableGeneric() { }
    HashTableGeneric(const this_type & rhs) : _container(rhs._container) {
    }

    bool hasValue(const value_type & val) const {
        return _container.hasValue(val);
    }
    void insert(const value_type & val) {
        return _container.insert(val);
    }
    size_t size() const {
        return _container.size();
    }
    const_iterator cbegin() const {
        return _container.cbegin();
    }
    const_iterator cend() const {
        return _container.cend();
    }
    const_iterator begin() const {
        return _container.cbegin();
    }
    const_iterator end() const {
        return _container.cend();
    }
    iterator begin() {
        return _container.begin();
    }
    iterator end() {
        return _container.end();
    }
    const_iterator find(const value_type & val) const {
        return _container.cfind(val);
    }
    iterator find(const value_type & val) {
        return _container.find(val);
    }
    void erase(const value_type & val) {
        _container.erase(val);
    }
    void printBalance() const {
        return _container.printBalance();
    }
    void clear() {
        _container.clear();
    }
};

#endif // HASH_TABLE_INTERFACE_H
