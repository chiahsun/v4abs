#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

#include <string>

class StringBuffer {
    std::string _str;

    unsigned int _posBegin;
    unsigned int _posEnd;
public:
    StringBuffer(std::string str);
    std::string next();
};



#endif // STRING_BUFFER_H
