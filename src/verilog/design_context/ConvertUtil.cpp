#include "ConvertUtil.h"

#include <sstream>

unsigned int unsigned_int_of_string(const std::string & s) {
    std::stringstream ss;
    ss << s;
    unsigned int val = 0;
    ss >> val;
    return val;
}
