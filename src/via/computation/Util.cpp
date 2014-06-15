#include "Util.h"

float str2float(std::string s){
    return atof(s.c_str());
}

int str2int(std::string s){
    return atoi(s.c_str());
}

std::string char2str(char* c){
    std::string s(c);
    return s;
}

std::string int2str(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}

char* str2char(std::string str){
    char* cstr = new char [str.length()+1];
    std::strcpy(cstr, str.c_str());
    
    return cstr;
}

int ASCII_index(std::string s){
    char* cstr = str2char(s);
    int total = 0;
    for( unsigned int i = 0 ; i < s.length() ; ++i ){
        int ascii_num = int(cstr[i]) - 32;
        if( i == 0)
            total = total + ascii_num - 1;
        else
            total = total + static_cast<int>(ascii_num*pow(94, i));
    }
    return total;
}

