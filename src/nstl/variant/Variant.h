#ifndef VARIANT_H
#define VARIANT_H


/***
 * XXX: TODO copy constructor for 3..7
 *  NOTE!!: assignment operator will fail if not implemented
 *
 *
 */
template <class T, class Interface>
void allocPtr(T* & p, Interface* & pInterface,  const T & x) {
    p = new T(x);
    pInterface = static_cast<Interface*>(p);
}

template < class T1, class T2, class Interface >
class Variant2 {
    T1* _p1;
    T2* _p2;
    Interface* _pInterface;
public:
    Variant2(T1 x) : _p1(0), _p2(0), _pInterface(0) {
        allocPtr(_p1, _pInterface, x);
    }
    Variant2(T2 x) : _p1(0), _p2(0), _pInterface(0) {
        allocPtr(_p2, _pInterface, x);
    }
    Variant2(Interface* pInterface)
      : _p1(0)
      , _p2(0)
      , _pInterface(pInterface)
      { }
    Variant2(const Variant2 & rhs) {
        copy(rhs);
    }
    Variant2& operator = (const Variant2 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }

    void copy(const Variant2 & rhs) {
        _p1 = 0;
        _p2 = 0;
        _pInterface = 0;
        if (rhs._p1)
            allocPtr(_p1, _pInterface, *(rhs._p1));
        else if (rhs._p2)
            allocPtr(_p2, _pInterface, *(rhs._p2));
        else
            _pInterface = rhs._pInterface;
    }
    ~Variant2() {
        destroy();
    }
    void destroy() {
        delete _p1; _p1 = 0;
        delete _p2; _p2 = 0;
        _pInterface = 0;
    }

    T1* getFstHandle() { 
        return _p1; 
    }
    T2* getSndHandle() { 
        return _p2; 
    }
    
    Interface* getInterfacePointer() const
      { return _pInterface; }

    Interface* operator -> () const 
      { return getInterfacePointer(); }
    
    Variant2() : _p1(0), _p2(0), _pInterface(0) { }
private:
//    Variant2& operator = (const T1 & x); 
  //  Variant2& operator = (const T2 & x); 
};

template < class T1, class T2, class T3, class Interface >
class Variant3 {
    T3* _p3;
    Variant2<T1, T2, Interface> _variant2;
public:
    Variant3() : _p3(0) { }
    Variant3(T1 x) : _p3(0), _variant2(x) 
      { }
    Variant3(T2 x) : _p3(0), _variant2(x) 
      { }
    Variant3(T3 x) 
      : _p3(new T3(x))
      , _variant2(static_cast<Interface*>(_p3)) 
      { }
    Variant3(Interface* pInterface)
      : _p3(0)
      , _variant2(pInterface)
      { }
    Variant3(const Variant3 & rhs) {
        copy(rhs);
    }
    Variant3& operator = (const Variant3 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    ~Variant3() 
      { destroy(); }
    T1* getFstHandle() { return _variant2.getFstHandle(); };
    T2* getSndHandle() { return _variant2.getSndHandle(); }
    T3* getTrdHandle() { return _p3; }
    Interface* operator -> () const { return getInterfacePointer(); }
    Interface* getInterfacePointer() const 
      { return _variant2.getInterfacePointer(); }

private:
    void copy(const Variant3 & rhs) {
        if (rhs._p3) {
            _p3 = new T3(*(rhs._p3));
            _variant2 = Variant2<T1, T2, Interface>(static_cast<Interface*>(_p3));
        } else {
            _p3 = 0;
            _variant2 = rhs._variant2;
        }
    }
    void destroy() {
        _variant2 = Variant2<T1, T2, Interface>();
        delete _p3; _p3 = 0;
    }
};

template < class T1, class T2, class T3, class T4, class Interface >
class Variant4 {
    T4* _p4;
    Variant3<T1, T2, T3, Interface> _variant3;
public:
    Variant4() : _p4(0) { }
    Variant4(T1 x) : _p4(0), _variant3(x) 
      { }
    Variant4(T2 x) : _p4(0), _variant3(x) 
      { }
    Variant4(T3 x) : _p4(0), _variant3(x) 
      { }
    Variant4(T4 x) 
      : _p4(new T4(x))
      , _variant3(static_cast<Interface*>(_p4)) 
      { }
    Variant4(Interface* pInterface)
      : _p4(0)
      , _variant3(pInterface)
      { }
    ~Variant4() 
      { destroy(); }
    Variant4(const Variant4 & rhs) {
        copy(rhs);
    }
    Variant4& operator = (const Variant4 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    T1* getFstHandle() { return _variant3.getFstHandle(); };
    T2* getSndHandle() { return _variant3.getSndHandle(); }
    T3* getTrdHandle() { return _variant3.getTrdHandle(); }
    T4* getForthHandle() { return _p4; }
    Interface* operator -> () const { return getInterfacePointer(); }
    Interface* getInterfacePointer() const 
      { return _variant3.getInterfacePointer(); }
private:
    void copy(const Variant4 & rhs) {
        if (rhs._p4) {
            _p4 = new T4(*(rhs._p4));
            _variant3 = Variant3<T1, T2, T3, Interface>(static_cast<Interface*>(_p4));
        } else {
            _p4 = 0;
            _variant3 = rhs._variant3;
        }
    }
    void destroy() {
        _variant3 = Variant3<T1, T2, T3, Interface>();
        delete _p4; _p4 = 0;
    }
};

template < class T1, class T2, class T3, class T4, class T5, class Interface >
class Variant5 {
    T5* _p5;
    Variant4<T1, T2, T3, T4, Interface> _variant4;
public:
    Variant5() : _p5(0) { }
    Variant5(T1 x) : _p5(0), _variant4(x) 
      { }
    Variant5(T2 x) : _p5(0), _variant4(x) 
      { }
    Variant5(T3 x) : _p5(0), _variant4(x) 
      { }
    Variant5(T4 x) : _p5(0), _variant4(x) 
      { }
    Variant5(T5 x) 
      : _p5(new T5(x))
      , _variant4(static_cast<Interface*>(_p5)) 
      { }
    Variant5(Interface* pInterface)
      : _p5(0)
      , _variant4(pInterface)
      { }
    ~Variant5() 
      { destroy(); }
    Variant5(const Variant5 & rhs) {
        copy(rhs);
    }
    Variant5 & operator = (const Variant5 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    T1* getFstHandle() { return _variant4.getFstHandle(); };
    T2* getSndHandle() { return _variant4.getSndHandle(); }
    T3* getTrdHandle() { return _variant4.getTrdHandle(); }
    T4* getForthHandle() { return _variant4.getForthHandle(); }
    T5* getFifthHandle() { return _p5; }
    Interface* operator -> () const { return getInterfacePointer(); }
    Interface* getInterfacePointer() const 
      { return _variant4.getInterfacePointer(); }
private:
    void copy(const Variant5 & rhs) {
        if (rhs._p5) {
            _p5 = new T5(*(rhs._p5));
            _variant4 = Variant4<T1, T2, T3, T4, Interface>(static_cast<Interface*>(_p5));
        } else {
            _p5 = 0;
            _variant4 = rhs._variant4;
        }
    }
    void destroy() {
        _variant4 = Variant4<T1, T2, T3, T4, Interface>();
        delete _p5; _p5 = 0;
    }
};


template < class T1, class T2, class T3, class T4, class T5, class T6, class Interface >
class Variant6 {
    T6* _p6;
    Variant5<T1, T2, T3, T4, T5, Interface> _variant5;
public:
    Variant6() : _p6(0) { }
    Variant6(T1 x) : _p6(0), _variant5(x) 
      { }
    Variant6(T2 x) : _p6(0), _variant5(x) 
      { }
    Variant6(T3 x) : _p6(0), _variant5(x) 
      { }
    Variant6(T4 x) : _p6(0), _variant5(x) 
      { }
    Variant6(T5 x) : _p6(0), _variant5(x) 
      { }
    Variant6(T6 x) 
      : _p6(new T6(x))
      , _variant5(static_cast<Interface*>(_p6)) 
      { }
    Variant6(Interface* pInterface)
      : _p6(0)
      , _variant5(pInterface)
      { }
    ~Variant6() 
      { destroy(); }
    Variant6(const Variant6 & rhs) {
        copy(rhs);
    }
    Variant6 & operator = (const Variant6 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    T1* getFstHandle() { return _variant5.getFstHandle(); };
    T2* getSndHandle() { return _variant5.getSndHandle(); }
    T3* getTrdHandle() { return _variant5.getTrdHandle(); }
    T4* getForthHandle() { return _variant5.getForthHandle(); }
    T5* getFifthHandle() { return _variant5.getFifthHandle(); }
    T6* getSixthHandle() { return _p6; }
    Interface* operator -> () const { return getInterfacePointer(); }
    Interface* getInterfacePointer() const 
      { return _variant5.getInterfacePointer(); }
private:
    void copy(const Variant6 & rhs) {
        if (rhs._p6) {
            _p6 = new T6(*(rhs._p6));
            _variant5 = Variant5<T1, T2, T3, T4, T5, Interface>(static_cast<Interface*>(_p6));
        } else {
            _p6 = 0;
            _variant5 = rhs._variant5;
        }
    }
    void destroy() {
        _variant5 = Variant5<T1, T2, T3, T4, T5, Interface>();
        delete _p6; _p6 = 0;
    }
};

template < class T1, class T2, class T3, class T4, class T5, class T6, class T7, class Interface >
class Variant7 {
    T7* _p7;
    Variant6<T1, T2, T3, T4, T5, T6, Interface> _variant6;
public:
    Variant7() : _p7(0) { }
    Variant7(T1 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T2 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T3 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T4 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T5 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T6 x) : _p7(0), _variant6(x) 
      { }
    Variant7(T7 x) 
      : _p7(new T7(x))
      , _variant6(static_cast<Interface*>(_p7)) 
      { }
    Variant7(Interface* pInterface)
      : _variant6(pInterface)
      { }
    ~Variant7() 
      { destroy(); }
    Variant7(const Variant7 & rhs) {
        copy(rhs);
    }
    Variant7 & operator = (const Variant7 & rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }
    T1* getFstHandle() { return _variant6.getFstHandle(); };
    T2* getSndHandle() { return _variant6.getSndHandle(); }
    T3* getTrdHandle() { return _variant6.getTrdHandle(); }
    T4* getForthHandle() { return _variant6.getForthHandle(); }
    T5* getFifthHandle() { return _variant6.getFifthHandle(); }
    T6* getSixthHandle() { return _variant6.getSixthHandle(); }
    T7* getSeventhHandle() { return _p7; }
    Interface* operator -> () const { return getInterfacePointer(); }
    Interface* getInterfacePointer() const 
      { return _variant6.getInterfacePointer(); }
private:    
    void copy(const Variant7 & rhs) {
        if (rhs._p7) {
            _p7 = new T7(*(rhs._p7));
            _variant6 = Variant6<T1, T2, T3, T4, T5, T6, Interface>(static_cast<Interface*>(_p7));
        } else {
            _p7 = 0;
            _variant6 = rhs._variant6;
        }
    }
    void destroy() {
        _variant6 = Variant6<T1, T2, T3, T4, T5, T6, Interface>();
        delete _p7; _p7 = 0;
    }
};




#endif // VARIANT_H
