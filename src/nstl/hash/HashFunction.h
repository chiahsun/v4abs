#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <string>

/**
 * Problem for multiple definition
 * Reference
 * http://stackoverflow.com/questions/4445654/multiple-definition-of-template-specialization-when-using-different-objects
 */

template <class _Value>
struct HashFunction {
    static int hashFunction(const _Value & value) {
        return value.hashFunction();
    }
    static int hashCode(const _Value & value, int size) {
        return (HashFunction<_Value>::hashFunction(value) & 0x7fffffff) % size;
    }
};

template <>
inline int HashFunction<int>::hashFunction(const int & val) {
    return val;
}

template <>
inline int HashFunction<bool>::hashFunction(const bool & val) {
    return (val ? 1231 : 1237);
}

template <>
inline int HashFunction<double>::hashFunction(const double & val) {
    long v = static_cast<long>(val);

    return static_cast<int>(v ^ (v>>32));
}

template <>
inline int HashFunction<char>::hashFunction(const char & val) {
    return static_cast<int>(val);
}

template <>
inline int HashFunction<std::string>::hashFunction(const std::string & val) {
    int hashValue = 0;
    for (size_t i = 0; i < val.size(); ++i)
        hashValue = val[i] + hashValue * 31;
    return hashValue;
}

template <>
inline int HashFunction<unsigned int>::hashFunction(const unsigned int & val) {
    return val;
}

/**
 * TODO: 
 *   1. Immutable string : cache hash code
 *   2. Each class use a nonzero constant as base value
 *
 * Reference:
 *   1. Horner's method
 *       
 */

#endif // HASH_FUNCTION_H
