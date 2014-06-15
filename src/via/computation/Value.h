#ifndef VALUE_H
#define VALUE_H

#include "Util.h"
#include <assert.h>

std::string LOGICAL_NOT(std::string str);
std::string LOGICAL_EQUAL(std::string Fst, std::string Snd);
std::string LOGICAL_AND(std::string Fst, std::string Snd);
std::string LOGICAL_OR(std::string Fst, std::string Snd);
std::string LOGICAL_XOR(std::string Fst, std::string Snd);

#endif // VALUE_H
