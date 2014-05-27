#include "Indent.h"

std::string indent(unsigned int indentLevel) {
    static std::string indentString = "  ";
    std::string s = "";
    for (unsigned int i = 0; i < indentLevel; ++i)
        s += indentString;
    return s;
}
