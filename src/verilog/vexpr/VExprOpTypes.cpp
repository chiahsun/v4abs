#include "VExprOpTypes.h"
#include "exception/Exception.h"

#include <iostream>

std::string vexpr_get_unary_op_symbol(UnaryOpType opType) {
    switch(opType) {
        case UNARY_PLUS : return "+";
        case UNARY_MINUS : return "-";
        case UNARY_NOT : return "!";
        case UNARY_NEG : return "~";
        case UNARY_AND : return "&";
        case UNARY_NEG_AND : return "~&";
        case UNARY_OR : return "|";
        case UNARY_NEG_OR : return "~|";
        case UNARY_XOR : return "^";
        case UNARY_NEG_XOR : return "~^";
        case UNARY_XOR_NEG : return "^~";
        default: throw NotImplementedException();
    }
    throw NoSuchBranchException();
}


std::string vexpr_get_binary_op_symbol(BinaryOpType opType) {
    switch(opType) {
        case BINARY_PLUS : return "+";
        case BINARY_MINUS : return "-";
        case BINARY_MULT : return "*";
        case BINARY_DIV : return "/";
        case BINARY_MOD : return "%";
        case BINARY_EQ : return "=";
        case BINARY_NEQ : return "!=";
        case BINARY_XEQ : return "===";
        case BINARY_XNEQ : return "!===";
        case BINARY_LOGICAL_AND : return "&&";
        case BINARY_LOGICAL_OR : return "||";
        case BINARY_GT : return ">";
        case BINARY_LT : return "<";
        case BINARY_GEQ : return ">=";
        case BINARY_LEQ : return "<=";
        case BINARY_BITWISE_AND : return "&";
        case BINARY_BITWISE_OR : return "|";
        case BINARY_BITWISE_XOR : return "^";
        case BINARY_BITWISE_XOR_NEG : return "^~";
        case BINARY_BITWISE_NEG_XOR : return "^~";
        case BINARY_SHIFT_RIGHT : return ">>";
        case BINARY_SHIFT_LEFT : return "<<";
        default: 
            std::cerr << "Unknown op type: " << opType << std::endl;
            throw NotImplementedException();
    }
    throw NoSuchBranchException();
}

