#include "ConvertUtil.h"


template <>
std::string ConvertUtil::convert<bool, std::string>(const bool & x)
  { return (x ? "true" : false); }

template <>
std::string ConvertUtil::convert<int, std::string>(const int & x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <>
std::string ConvertUtil::convert<unsigned int, std::string>(const unsigned int & x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}


template <>
unsigned int ConvertUtil::convert<std::string, unsigned int>(const std::string & x) {
    std::stringstream ss;
    ss << x;
    unsigned int i;
    ss >> i;
    return i;
}

template <>
unsigned int ConvertUtil::convert<char, unsigned int>(const char & x) {
    std::stringstream ss;
    ss << x;
    int valx = static_cast<int>(x);
    const int val0 = static_cast<int>('0');
    if ((valx - val0) >= 0 && (valx - val0) < 10) {
        unsigned int i;
        ss >> i;
        return i;
    }
    switch(x) {
        case 'a':
        case 'A':
            return 10;
        case 'b':
        case 'B':
            return 11;
        case 'c':
        case 'C':
            return 12;
        case 'd':
        case 'D':
            return 13;
        case 'e':
        case 'E':
            return 14;
        case 'f':
        case 'F':
            return 15;
        default:
            break;
    }

    LOG(ERROR) << "fail to convert char(" << x << ") to unsigned number";
    return 0;
}

