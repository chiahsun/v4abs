#ifndef CONVERT_UTIL_H 
#define CONVERT_UTIL_H 

#include <sstream>

class  ConvertUtil {
public:
    template <class _From, class _To>
    static _To convert(const _From & from);

};


template <>
std::string ConvertUtil::convert<bool, std::string>(const bool & x)
  { return (x ? "true" : false); }

template <>
std::string ConvertUtil::convert<int, std::string>(const int & x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

#endif // UTIL_CONVERT_H
