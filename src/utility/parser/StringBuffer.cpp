#include "StringBuffer.h"

#include <cassert>

bool is_delimiter(char c) {
    static const unsigned int sz = 4;
    static const char carray[sz] = {' ', '\n', '\t', '\b'};
    // static const char carray[sz] = {' '};

    for (unsigned int i = 0; i < sz; ++i)
        if (c == carray[i])
            return true;
    return false;
}

StringBuffer::StringBuffer(std::string str)
  : _str(str)
  , _posBegin(0)
  , _posEnd(0)
  { }
    
std::string StringBuffer::next() {
    if (_str.size() == 0) return "";

    // Bypass first delimiters
    _posBegin = _str.size();
    for (unsigned int i = _posEnd; i < _str.size(); ++i) {
        if (!is_delimiter(_str[i])) {
            _posBegin = _posEnd = i;
            break;
        }
    }

    _posEnd = _str.size();
    for (unsigned int i = _posBegin; i < _str.size(); ++i) {
        if (is_delimiter(_str[i])) {
            _posEnd = i;
            break; 
        }
    }


    assert(_posEnd >= _posBegin);
    if (_posBegin >= _str.size())
        return "";
    else
        return _str.substr(_posBegin, _posEnd - _posBegin);

}

#if 0
std::string StringBuffer::next() {
    if (_str.size() == 0) return "";

    // Bypass first delimiters
    for (unsigned int i = _posEnd; i < _str.size(); ++i) {
        if (!is_delimiter(_str[i])) {
            _posBegin = _posEnd = i;
            break;
        }
    }

    _posEnd = _str.size();
    for (unsigned int i = _posBegin; i < _str.size(); ++i) {
        if (is_delimiter(_str[i])) {
            _posEnd = i;
            break; 
        }
    }


    assert(_posEnd >= _posBegin);
    return _str.substr(_posBegin, _posEnd - _posBegin);

}
#endif
