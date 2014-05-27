#ifndef SHARED_PTR_EXCEPTION_H
#define SHARED_PTR_EXCEPTION_H
#if 0
struct InvalidRhsNullPointerException {
    const char* what() const { return "SharedPtr right hand side is null pointer"; }
};

struct InvalidSharedPtrCastException {
    const char* what() const { return "Please check if your type can be cast from that type to this type"; }
};
#endif
class Count {
    size_t _count;
public:
    Count() { _count = 1; }
    inline void incrCount() { ++_count; }
    inline void decrCount() { --_count; }
    inline size_t count() const { return _count; }
};
    
static const bool EnableCallCountReport = false;

template <class _Value>
class CallCountReport {
    size_t _callNewCount;
    size_t _shallowCopyCount;
    size_t _copyOnWriteCount;
    size_t _dynamicCastCount;
public:
    CallCountReport() { _callNewCount = 0; _shallowCopyCount = 0; _copyOnWriteCount = 0; _dynamicCastCount = 0; }
    ~CallCountReport() { 
        if (EnableCallCountReport)
        std::cout << "*SharedPtrE(" << typeid(_Value).name() << ") : " << std::endl
                  << "    Call new function   : " << _callNewCount << " times " << std::endl
                  << "    Shallow copy count  : " << _shallowCopyCount << " times " << std::endl
                  << "    Copy on write count : " << _copyOnWriteCount << " times " << std::endl
                  << "    Dynamic cast count  : " << _dynamicCastCount << " times " << std::endl; 
    }
    inline void incrCallNewCount() { ++_callNewCount; }
    inline void incrShallowCopyCount() { ++_shallowCopyCount; }
    inline void incrCopyOnWriteCount() { ++_copyOnWriteCount; }
    inline void incrDynamicCastCount() { ++_dynamicCastCount; }
};


#define SHARED_PTR_ERROR_MSG(msg) do { std::cerr << "*SharedPtr Error: " << msg << " @(" << __FILE__ << ":" << __LINE__ << ")" << std::endl; assert(0); } while(0)
#define SHARED_PTR_ERROR_INVALID_RHS_NILL_POINTER() SHARED_PTR_ERROR_MSG("SharedPtr right hand side is null pointer")
#define SHARED_PTR_ERROR_INVALID_CAST() SHARED_PTR_ERROR_MSG("Please check if your type can be cast from that ype to this type")


#endif // SHARED_PTR_EXCEPTION_H
