#ifndef CONVERT_UTIL_H 
#define CONVERT_UTIL_H 

#include <string>
#include <sstream>

#include "utility/log/Log.h"

class  ConvertUtil {
public:
    template <class _From, class _To>
    static _To convert(const _From & from);

};


template <>
std::string ConvertUtil::convert<bool, std::string>(const bool & x);

template <>
std::string ConvertUtil::convert<int, std::string>(const int & x);

template <>
unsigned int ConvertUtil::convert<std::string, unsigned int>(const std::string & x);

template <>
unsigned int ConvertUtil::convert<char, unsigned int>(const char & x);
#endif // CONVERT_UTIL_H 
