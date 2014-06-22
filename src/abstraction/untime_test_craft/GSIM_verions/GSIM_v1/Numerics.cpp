#include "Numerics.h"

#include <iostream>
#define DEBUG_EXPR(expr) do { std::cerr << #expr << " : " << (expr) << std::endl; } while(0)

unsigned int uint_to_char(unsigned int val) {
    switch(val) {
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        case 10 : return 'A';
        case 11 : return 'B';
        case 12 : return 'C';
        case 13 : return 'D';
        case 14 : return 'E';
        case 15 : return 'F';
        default : break;
    }

    throw InvalidFormatException("Overflow for input");
}

unsigned int char_to_uint(char c) {
    switch(c) {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case 'a' :
        case 'A' :
            return 10;
        case 'b' : 
        case 'B' : 
            return 11;
        case 'c' : 
        case 'C' : 
            return 12;
        case 'd' : 
        case 'D' : 
            return 13;
        case 'e' : 
        case 'E' : 
            return 14;
        case 'f' : 
        case 'F' : 
            return 15;
        default:
            break; 
    }
    throw InvalidFormatException("Character not one of the choices");
}

unsigned int hex_to_uint(std::string s) {
    if (s.size() == 0)
        throw InvalidFormatException("Should at least one char, e.g. 0");
    
    unsigned int sum = 0;
    unsigned int mul = 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        sum += mul*char_to_uint(s[i]);
        mul *= 16;
    }
    return sum;
}
unsigned int binary_to_uint(std::string s) {
    if (s.size() == 0)
        throw InvalidFormatException("Should at least one char, e.g. 0");
   
    unsigned int sum = 0;
    unsigned int mul = 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != '0' && s[i] != '1') 
            throw InvalidFormatException("binary literal should be 0 or 1");
        sum += mul*char_to_uint(s[i]);
        mul *= 2;
    }
    return sum;

}


std::string uint_to_hex(unsigned int val) {
    if (val == 0) return "0";
    if (val == 1) return "1";

    std::string s;
    for (; val != 0; val>>= 4) 
        s += uint_to_char(val & 0x0f);
    std::string ret;
    for (int i = s.size()-1; i >= 0; --i)
        ret += s[i];
    return ret;
}

