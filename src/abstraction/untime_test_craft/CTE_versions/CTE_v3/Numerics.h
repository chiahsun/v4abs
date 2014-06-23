#ifndef NUMERICS_H
#define NUMERICS_H

#include <string>

struct InvalidFormatException {
    const char* _msg;
    InvalidFormatException(const char* msg) { _msg = msg; }
    const char* what() const { return "Invalid format "; }
};

unsigned int hex_to_uint(std::string s);
unsigned int binary_to_uint(std::string s);

std::string uint_to_hex(unsigned int val);

#endif 
