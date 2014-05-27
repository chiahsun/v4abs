#ifndef VEXPR_OP_TYPES_H
#define VEXPR_OP_TYPES_H

#include <string>

enum UnaryOpType {
    UNARY_PLUS = 0
  , UNARY_MINUS
  , UNARY_NOT
  , UNARY_NEG
  , UNARY_AND
  , UNARY_NEG_AND
  , UNARY_OR
  , UNARY_NEG_OR
  , UNARY_XOR
  , UNARY_NEG_XOR
  , UNARY_XOR_NEG
};

enum BinaryOpType {
    BINARY_PLUS = 0
  , BINARY_MINUS
  , BINARY_MULT
  , BINARY_DIV
  , BINARY_MOD
  , BINARY_EQ
  , BINARY_NEQ
  , BINARY_XEQ
  , BINARY_XNEQ
  , BINARY_LOGICAL_AND
  , BINARY_LOGICAL_OR
  , BINARY_GT
  , BINARY_LT
  , BINARY_GEQ
  , BINARY_LEQ
  , BINARY_BITWISE_AND
  , BINARY_BITWISE_OR
  , BINARY_BITWISE_XOR
  , BINARY_BITWISE_XOR_NEG
  , BINARY_BITWISE_NEG_XOR
  , BINARY_SHIFT_RIGHT
  , BINARY_SHIFT_LEFT

};

std::string vexpr_get_unary_op_symbol(UnaryOpType opType);
std::string vexpr_get_binary_op_symbol(BinaryOpType opType);

#endif // VEXPR_OP_TYPES_H
