#ifndef LINEAR_PROBING_HASH_H
#define LINEAR_PROBING_HASH_H

#include <cassert>
#include <vector>

#include "HashFunction.h"
#include "HashTableInterface.h"

template <class _Value> 
class LinearProbingHash {

public:
    typedef int key_type;
    typedef _Value value_type;
    typedef _Value* pointer_type;
    typedef _Value& reference_type;
    typedef const _Value& const_reference_type;
//    typedef pointer_type iterator;
//    typedef const _Value* const_iterator;

//    typedef std::vector<pointer_type>::iterator iterator;
//    typedef std::vector<pointer_type>::const_iterator const_iterator;
private:
    std::vector<pointer_type> _vecPointer;
    size_t _size;

    enum {
        DEFAULT_CAPCITY = 16
      , BALANCE_RATIO = 2
      , MULT_RATIO = 2
    };
public:

    class Iterator {
    public:
        std::vector<pointer_type>* _pVec;
        int _index;

        Iterator() : _pVec(0), _index(0) { }
        
        Iterator(std::vector<pointer_type>* pVec, size_t pos) { 
            _pVec = pVec;
            _index = pos;
            assert(_pVec);
            if (pos != _pVec->size())
                assert(valid());
        }

        pointer_type operator -> () {
            assert(valid());
            return (*_pVec)[_index];
        }

        Iterator& operator=(const Iterator & rhs) {
            if (this != &rhs)
                copy(rhs);
            return *this;
        }
        
        void copy(const Iterator& rhs) {
            _pVec = rhs._pVec;
            _index = rhs._index;
        }


        inline Iterator& operator++() {
            for (_index = _index + 1; static_cast<unsigned int>(_index) < _pVec->size(); ++_index) {
                if ((*_pVec)[_index]) {
                    assert(valid());
                    return *this;
                }
            }
            _index = _pVec->size();
            return *this;
        }

        inline bool operator == (const Iterator & rhs) const {
            return (_pVec == rhs._pVec)
               && (_index == rhs._index);
        }

        inline bool operator != (const Iterator & rhs) const {
            return !this->operator == (rhs);
        }

        reference_type operator * () {
            assert(valid());
            return *((*_pVec)[_index]);
        }

        bool valid() const {
            return (*_pVec)[_index];
        }

        void moveToBegin() {
            assert(_index == 0);
            for (size_t i = 0; i < _pVec->size(); ++i) {
                if ((*_pVec)[i]) {
                    _index = i;
                    return;
                }
            }
            assert(0);
        }

    };
    
    class ConstIterator {
    public:
        const std::vector<pointer_type>* _pVec;
        size_t _index;
   
        ConstIterator() : _pVec(0), _index(0) { }
        
        ConstIterator(const std::vector<pointer_type>* pVec, size_t pos) { 
            _pVec = pVec;
            _index = pos; 
            assert(_pVec);
            if (pos != _pVec->size())
                assert(valid());
        }

        pointer_type operator -> () {
            assert(valid());
            return (*_pVec)[_index];
        }

        ConstIterator& operator=(const ConstIterator & rhs) {
            if (this != &rhs)
                copy(rhs);
            return *this;
        }
        
        void copy(const ConstIterator& rhs) {
            _pVec = rhs._pVec;
            _index = rhs._index;
        }
        
        inline ConstIterator& operator++() {
            for (_index = _index + 1; static_cast<unsigned int>(_index) < _pVec->size(); ++_index) {
                if ((*_pVec)[_index]) {
                    assert(valid());
                    return *this;
                }
            }
            _index = _pVec->size();
            return *this;
        }

        


        inline bool operator == (const ConstIterator & rhs) const {
            return (_pVec == rhs._pVec)
               && (_index == rhs._index);
        }

        inline bool operator != (const ConstIterator & rhs) const {
            return !this->operator == (rhs);
        }

        const_reference_type operator * () {
            assert(valid());
            return *((*_pVec)[_index]);
        }
        
        bool valid() const {
            return ((*_pVec)[_index]);
        }


        void moveToBegin() {
            assert(_index == 0);
            for (size_t i = 0; i < _pVec->size(); ++i) {
                if ((*_pVec)[i]) {
                    _index = i;
                    return;
                }
            }
            assert(0);
        }


    };


    typedef Iterator iterator;
    typedef ConstIterator const_iterator;

    LinearProbingHash() : _pBegin(end()) { init(DEFAULT_CAPCITY); }
    LinearProbingHash(const LinearProbingHash & rhs) : _pBegin(end()) {
        copy(rhs);
    }
    LinearProbingHash& operator = (const LinearProbingHash & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    void copy(const LinearProbingHash & rhs) {
        init(rhs.capacity());
        for (const_iterator it = rhs.cbegin(); it != rhs.cend(); ++it)
            insert(*it);
    }
    void init(size_t cap) {
        assert(cap > 0);
        _size = 0;
        _vecPointer.clear();
        for (size_t i = 0; i < cap; ++i)
            _vecPointer.push_back(0);
        _pBegin = end();
    }
    ~LinearProbingHash() {
        destroy();
    }
    void clear() {
        destroy();
        init(DEFAULT_CAPCITY);
    }

    size_t capacity() const { return _vecPointer.size(); }


    void destroy() {
        for (size_t i = 0; i < _vecPointer.size(); ++i) {
            delete _vecPointer[i]; _vecPointer[i] = 0;
        }
        _vecPointer.clear();
    }

    void resize(size_t cap) {
#if 1 // not update _pBegin
        int insertPos = cap;

        std::vector<pointer_type> vecNew;

        for (size_t i = 0; i < cap; ++i)
            vecNew.push_back(0);

        for (size_t i = 0; i < capacity(); ++i) {
            if (_vecPointer[i]) {
                int newInsertPos = insert_helper(vecNew, *_vecPointer[i]);
                if (newInsertPos < insertPos)
                    insertPos = newInsertPos;
            }
        }

        destroy();

        _vecPointer = vecNew;
        _pBegin = Iterator(&_vecPointer, insertPos);
#endif 
    }

    inline size_t size() const { return _size; }

    iterator insert(const_reference_type value) {
        iterator it;
        if ((it = find(value)) != end()) {
            *(it) = (value);
        }

        int insertPos = insert_helper(_vecPointer, value);
        if (insertPos >= 0) {
            ++_size;
            if (size() == 1) {
                _pBegin = it = Iterator(&_vecPointer, insertPos);
            } else {
                if (insertPos < _pBegin._index)
                    _pBegin = it = Iterator(&_vecPointer, insertPos);
            }
        }
        
        if (size() * BALANCE_RATIO > capacity()) {
            resize(MULT_RATIO * capacity());
            it = find(value);
        }

        return find(value);
    } 

    int insert_helper(std::vector<pointer_type>& vec, const value_type& value) {
        const size_t cap = vec.size();
        const key_type keyValue = getKeyValue(value, cap);

        for (size_t i = keyValue; i != ((keyValue == 0) ? cap - 1 : keyValue-1); i = (i == (cap-1) ? 0 : i + 1)) {
            if (!vec[i]) {
                vec[i] = new value_type(value);
                return i;
//                return true;
            } else if (*vec[i] == value) {
                return -1;
//                return false;
            }
        }
        assert(0);
    }

    // TODO: erase update _pBegin issues // not tested
    void erase(const value_type & val) {
        iterator it = find(val);
        if (it == end())
            return;

        unsigned int erase_idx = it._index;
        erase_iterator(it);
        --_size;

        if (_size == 0)
            _pBegin = end();
        for (unsigned int i = erase_idx; i < capacity(); ++i)
            if (_vecPointer[i]) {
                _pBegin = Iterator(&_vecPointer, i);
                break;
            }


        unsigned begin_index = index_next(erase_idx);
        unsigned end_index = begin_index;
        for (size_t i = begin_index; i != erase_idx; i = index_next(i)) {
            if (!_vecPointer[i])
                break;
        }

        // TODO: Optimization
        //       not delete pointer, but cache removed pointer, and reinsert it
        //       but not designed from scratch, so maybe next version :D
        for (size_t i = begin_index; i != end_index; i = index_next(i)) {
            value_type oldVal = *_vecPointer[i];
            erase_index(i);
            insert(oldVal);         
        }
    }

    unsigned int index_next(unsigned int i) const {
        return (i == (capacity()-1) ? 0 : i + 1);
    }
    
    unsigned int index_prev(unsigned int i) const {
        return ((i == 0) ? (capacity() - 1) : (i-1));
    }

    const_iterator cfind(const value_type & val) const {
        const key_type keyValue = getKeyValue(val, capacity());
        for (size_t i = keyValue; i != ((keyValue == 0) ? capacity() - 1 : keyValue-1); i = index_next(i)) {
            if (!_vecPointer[i])
                return cend();
            else if (*_vecPointer[i] == val)
                return ConstIterator(&_vecPointer, i);
        }
        assert(0);
    }
    
    iterator find(const value_type & val) {
        const key_type keyValue = getKeyValue(val, capacity());
        for (size_t i = keyValue; i != ((keyValue == 0) ? capacity() - 1 : keyValue-1); i = (i == (capacity()-1) ? 0 : i + 1)) {
            if (!_vecPointer[i])
                return end();
            else if (*_vecPointer[i] == val)
                return Iterator(&_vecPointer, i);
        }
        assert(0);
    }


    iterator begin() {
        if (size() == 0) 
            return end();
        else
        return _pBegin;
//            return Iterator(&_vecPointer, 0).moveToBegin();
    }

    const_iterator cbegin() const {
        if (size() == 0) 
            return cend();
        else
            return ConstIterator(&_vecPointer, _pBegin._index);
    }

    iterator end() {
        return Iterator(&_vecPointer, capacity());
//        return 0;
//        return _vecPointer.end();
    }

    const_iterator cend() const {
//        return 0;
        return ConstIterator(&_vecPointer, capacity());
//        return _vecPointer.end();
    }

private:
    static key_type getKeyValue(const_reference_type val, size_t cap) {
       return HashFunction<value_type>::hashCode(val, cap);
    }

    void erase_iterator(iterator it) {
        int index = it._index;
        erase_index(index);
    }

    void erase_index(unsigned int index) {
        delete _vecPointer[index]; _vecPointer[index] = 0;
    }

    iterator _pBegin;


};

#endif 
