#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <cstring>
#include <math.h>

float str2float(std::string s);
int str2int(std::string s);
std::string char2str(char* c);
std::string int2str(int i);
char* str2char(std::string str);
int ASCII_index(std::string s);

#endif // UTIL_H
