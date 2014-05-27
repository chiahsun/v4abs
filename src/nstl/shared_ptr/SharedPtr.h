#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <cassert>
#include <sstream>
#include <iostream>
#include <typeinfo>

#include "SharedPtrException.h"


template <class _Value>
class SharedPtr; 

template <class _To, class _From>
SharedPtr<_To> shared_ptr_cast(SharedPtr<_From> & rhs);

template <class _Value>
class SharedPtr {
    static CallCountReport<_Value> myCallCountReport;

    typedef _Value value_type;
    typedef value_type* pointer_type;
    typedef const value_type * pointer_to_const_type;
    typedef value_type & reference_type;
    typedef SharedPtr<value_type> handle_type;

public:
    pointer_type _pStorage;
    Count* _pCount;

    explicit SharedPtr() { _pStorage = 0; _pCount = 0; }
    
    explicit SharedPtr(value_type value) {
        init(value);
    }
    inline void init(value_type value) {
        _pStorage = new value_type(value);
        myCallCountReport.incrCallNewCount();
        _pCount = new Count();
    }
    SharedPtr(const SharedPtr<_Value> & rhs) {
        shallow_copy(rhs);
    }

    inline void incrDynamicCastCount() {
        myCallCountReport.incrDynamicCastCount();
    }
    /*
    template <class _Derived>
    SharedPtr(SharedPtr<_Derived> rhs) {
        *this = shared_ptr_cast<_Value>(rhs);    
    }
    */
    /*
    explicit SharedPtr(const handle_type & rhs) {
        shallow_copy(rhs);
    }
    */
    ~SharedPtr() {
        destroy();
    }

    inline bool valid() const { return _pStorage && _pCount; }
    inline size_t count() const { assert(_pCount); return _pCount->count(); }
    
    handle_type& operator = (handle_type rhs) {
        if(!rhs.valid()) {
            destroy();
            return *this;
        }

        if (this == &rhs) 
            return *this;
       
        destroy();
        shallow_copy(rhs);
        return *this;
    }

    bool operator == (const handle_type & rhs) const {
        return (valid() == rhs.valid())
//            && (!valid() || *(_pStorage)==*(rhs._pStorage));
//            && (!valid() || _pStorage->operator=(*rhs._pStorage));
              && (!valid() || _pStorage == rhs._pStorage);
    }

    bool operator != (const handle_type & rhs) const {
        return !this->operator==(rhs);
    }

    int hashFunction() const {
        return _pStorage->hashFunction();
    }
#if 0
    const handle_type& operator = (const handle_type & rhs) const {
        if(!rhs.valid()) {
            destroy();
            return *this;
        }

        if (this == &rhs) 
            return *this;
       
        destroy();
        shallow_copy(rhs);
        return *this;
    }
#endif
/*
    handle_type& operator = (handle_type & rhs) {
        if(!rhs.valid()) {
            destroy();
            return *this;
        }

        if (this == &rhs) 
            return *this;
       
        destroy();
        shallow_copy(rhs);
        return *this;
    }
    */

    inline pointer_to_const_type operator -> () const {
        assert(valid());
        return _pStorage;
    }
    /*
    inline pointer_to_const_type operator -> () const {
        assert(valid());
        return _pStorage;
    }*/
    
    inline pointer_type operator -> () {
        assert(valid());
//        copy_before_write();
        return _pStorage;
    }

    inline void copy_before_write() {
        if (count() != 1) {
            pointer_type pValue = _pStorage;
            destroy();
            myCallCountReport.incrCopyOnWriteCount();
            init(*pValue);
        }
    }
    /*
    inline const pointer_type operator -> () const {
        assert(valid());
        return _pStorage;
    }
*/
/*
    */
    
    inline reference_type operator * () {
        assert(valid());
        copy_before_write();
        return *_pStorage;
    }

    inline const reference_type operator * () const {
        assert(valid());
        return *_pStorage;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << constPointer() << " (" << count() << ")";
        return ss.str();
    }




private:
    void shallow_copy(const handle_type & rhs) {
        if(!rhs.valid()) {
            _pStorage = 0;
            _pCount = 0;
            return;
        }
        myCallCountReport.incrShallowCopyCount();
//            throw InvalidRhsNullPointerException();
        _pStorage = rhs._pStorage;
        _pCount = rhs._pCount;
        _pCount->incrCount();
    }

    void destroy() {
        if (valid()) {
            assert(count() != 0);
            decrCount();
            if (count() == 0) {
                delete _pStorage; _pStorage = 0;
                delete _pCount; _pCount = 0;
            }
        }
    }

    SharedPtr(pointer_type pValue, Count* pCount) {
        assert(pValue);
        assert(pCount);

        _pStorage = pValue;
        _pCount = pCount;
        _pCount->incrCount();
    }
    

    inline Count* countPointer() { return _pCount; }
    inline pointer_type pointer() { return _pStorage; }
    inline pointer_to_const_type constPointer() const { return _pStorage; }
    inline void incrCount() { assert(_pCount); _pCount->incrCount(); }
    inline void decrCount() { assert(_pCount); _pCount->decrCount(); }

    template <class _To, class _From>
    friend SharedPtr<_To> shared_ptr_dynamic_cast(SharedPtr<_From> & rhs);
};

template <class _Value>
CallCountReport<_Value> SharedPtr<_Value>::myCallCountReport
= CallCountReport<_Value>();

template <class _To, class _From>
SharedPtr<_To> shared_ptr_dynamic_cast(SharedPtr<_From> & rhs) {
    if (!rhs.valid()) {
        SHARED_PTR_ERROR_INVALID_RHS_NILL_POINTER();
     //   throw InvalidRhsNullPointerException();
    }
     
    _To* pTo = 0;
    try {
        pTo = dynamic_cast<_To*>(rhs.pointer());
    } catch (std::bad_cast & e) {
        SHARED_PTR_ERROR_INVALID_CAST();
    //    throw InvalidSharedPtrCastException(); 
    }

    SharedPtr<_To> pThis(pTo, rhs.countPointer());
    pThis.incrDynamicCastCount();
    return pThis;
}

template <class _To, class _From>
SharedPtr<_To> shared_ptr_cast(SharedPtr<_From> & rhs) {
    return shared_ptr_dynamic_cast<_To, _From>(rhs);
}

#endif // SHARED_PTR_H
