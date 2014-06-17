#include "Graph.h"

char kStateName[] = "State";
char kEdgeName[] = "Edge";

#if 0
template <>
std::string GraphComponentToString<int>::toString(const int & value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <>
std::string GraphComponentToString<std::string>::toDotString(const std::string & x) {
}



template <>
std::string GraphComponentToString<int>::toString(const int & x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <>
std::string GraphComponentToString<std::string>::toString(const std::string & x) {
    return x;
}
#endif
