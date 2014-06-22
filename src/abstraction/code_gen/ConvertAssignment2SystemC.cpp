#include "ConvertAssignment2SystemC.h"
#include "utility/log/Log.h"

ConvertAssignment2SystemC::ConvertAssignment2SystemC(const VRExprAssignment assignment)
  : _assignment(assignment)
  { }

std::string ConvertAssignment2SystemC::convert() {
    std::string lhs = convert(_assignment.getExprLhs());
    std::string rhs = convert(_assignment.getExprRhs());

    return lhs + " = " + rhs + ";";
}

std::string ConvertAssignment2SystemC::convert(const VRExprExpression & x) {
    if (x.getPrimaryHandle()) {
        return convert(*x.getPrimaryHandle());
    } else if (x.getUnaryExpressionHandle()) {
        return convert(*x.getUnaryExpressionHandle());
    } else if (x.getBinaryExpressionHandle()) {
        return convert(*x.getBinaryExpressionHandle());
    } else if (x.getIteHandle()) {
        return convert(*x.getIteHandle());
    } else if (x.getItHandle()) {
        return convert(*x.getItHandle());
    } else if (x.getIeHandle()) {
        return convert(*x.getIeHandle());
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

std::string ConvertAssignment2SystemC::convert(const VRExprPrimary & x) {
    if (x.getIdentifierHandle()) {
        return convert(*x.getIdentifierHandle());
    } else if (x.getNumberHandle()) {
        return convert(*x.getNumberHandle());
    } else if (x.getSelectIdentifierHandle()) {
        return convert(*x.getSelectIdentifierHandle());
    } else if (x.getConcatenationHandle()) {
        return convert(*x.getConcatenationHandle());
    } else if (x.getMultConcatenationHandle()) {
        return convert(*x.getMultConcatenationHandle());
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

std::string ConvertAssignment2SystemC::convert(const VRExprUnaryExpression & x) {
    std::stringstream ss;
    std::string eInner = convert(x.getPrimary());
    
    switch(x.getOpType()) {
        case UNARY_PLUS:
            ss << eInner;
            break;
        case UNARY_MINUS:
            ss << "(-" << eInner << ")";
            break;
        case UNARY_NOT:
            ss << "(!" << eInner << ")";
            break;
        case UNARY_NEG:
            ss << "(~" << eInner << ")";
            break;
        case UNARY_AND:
            ss << eInner << ".and_reduce()";
            break;
        case UNARY_NEG_AND:
            ss << "~(" << eInner << ".and_reduce())";
            break;
        case UNARY_OR:
            ss << eInner << ".or_reduce()";
            break;
        case UNARY_NEG_OR:
            ss << "~(" << eInner << ".or_reduce())";
            break;
        case UNARY_XOR:
            ss << eInner << ".xor_reduce()";
            break;
        case UNARY_NEG_XOR:
            ss << "~(" << eInner << ".xor_reduce())";
            break;
        case UNARY_XOR_NEG:
            ss << "(~" << eInner << ").xor_reduce()";
            break;
        default:
            LOG(ERROR) << "Unknown op type in" << x.toString();
    }
   
    return ss.str();
}

std::string ConvertAssignment2SystemC::convert(const VRExprBinaryExpression & x) {
    std::stringstream ss;
    std::string e1 = convert(x.getExprFst());
    std::string e2 = convert(x.getExprSnd());

    switch(x.getOpType()) {
        case BINARY_PLUS:
            ss << "(" << e1 << " + " << e2 << ")";
            break;
        case BINARY_MINUS:
            ss << "(" << e1 << " - " << e2 << ")";
            break;
        case BINARY_MULT:
            ss << "(" << e1 << " * " << e2 << ")";
            break;
        case BINARY_DIV:
            ss << "(" << e1 << " / " << e2 << ")";
            break;
        case BINARY_MOD:
            ss << "(" << e1 << " % " << e2 << ")";
            break;
        case BINARY_EQ:
            ss << "(" << e1 << " == " << e2 << ")";
            break;
        case BINARY_NEQ:
            ss << "(" << e1 << " != " << e2 << ")";
            break;
        case BINARY_XEQ:
            LOG(ERROR) << "No support 4-value logic";
            break;
        case BINARY_XNEQ:
            LOG(ERROR) << "No support 4-value logic";
            break;
        case BINARY_LOGICAL_AND:
            ss << "(" << e1 << " && " << e2 << ")";
            break;
        case BINARY_LOGICAL_OR:
            ss << "(" << e1 << " || " << e2 << ")";
            break;
        case BINARY_GT:
            ss << "(" << e1 << " > " << e2 << ")";
            break;
        case BINARY_LT:
            ss << "(" << e1 << " < " << e2 << ")";
            break;
        case BINARY_GEQ:
            ss << "(" << e1 << " >= " << e2 << ")";
            break;
        case BINARY_LEQ:
            ss << "(" << e1 << " <= " << e2 << ")";
            break;
        case BINARY_BITWISE_AND:
            ss << "(" << e1 << " & " << e2 << ")";
            break;
        case BINARY_BITWISE_OR:
            ss << "(" << e1 << " | " << e2 << ")";
            break;
        case BINARY_BITWISE_XOR:
            ss << "(" << e1 << " ^ " << e2 << ")";
            break;
        case BINARY_BITWISE_XOR_NEG:
            ss << "~(" << e1 << " ^ " << e2 << ")";
            break;
        case BINARY_BITWISE_NEG_XOR:
            ss << "~(" << e1 << " ^ " << e2 << ")";
            break;
        case BINARY_SHIFT_RIGHT:
            ss << "(" << e1 << " >> " << e2 << ".to_uint64())";
            break;
        case BINARY_SHIFT_LEFT:
            ss << "(" << e1 << " << " << e2 << ".to_uint64())";
            break;
        default:
            LOG(ERROR) << "Unknown op type in" << x.toString();
    }
    return ss.str();
}

std::string ConvertAssignment2SystemC::convert(const VRExprIte & x) {
    return "(" + convert(x.getExprIf()) 
    + "?" + convert(x.getExprThen())
    + ":" + convert(x.getExprElse())
    + ")";
}

std::string ConvertAssignment2SystemC::convert(const VRExprIt & x) {
    return "(" + convert(x.getExprIf()) 
    + "?" + convert(x.getExprThen())
    + ":" + convert(_assignment.getExprLhs())
    + ")";
}

std::string ConvertAssignment2SystemC::convert(const VRExprIe & x) {
    return "(" + convert(x.getExprIf()) 
    + "?" + convert(_assignment.getExprLhs())
    + ":" + convert(x.getExprElse())
    + ")";
}

std::string ConvertAssignment2SystemC::convert(const VRExprIdentifier & x) {
    return x.toString();
}

std::string ConvertAssignment2SystemC::convert(const VRExprNumber & x) {
    std::stringstream ss;
    assert(x.getSize() > 0);
    if (x.getSize() == 1) {
        ss << (x.getUnsignedNumber()) ? "true" : "false";
    } else if (x.getSize() <= 32) {
        ss << "sc_uint<" << x.getSize() << ">(" << x.getUnsignedNumber() << ")";
    } else {
        ss << "sc_biguint<" << x.getSize() << ">(" << x.getUnsignedNumber() << ")";
    }

//    ss << x.getUnsignedNumber();
    return ss.str();
}

std::string ConvertAssignment2SystemC::convert(const VRExprSelectIdentifier & x) {
    std::stringstream ss;
    std::string eIdentifier = convert(x.getIdentifier());
    ss << eIdentifier;
    for (unsigned int i = 0; i < x.getSelectContainer().size(); ++i) {
        ss << convert(x.getSelectContainer()[i]);
    }
    return ss.str(); 
}

std::string ConvertAssignment2SystemC::convert(const VRExprConcatenation & x) {
    std::stringstream ss;
    assert(x.getExprContainer().size() > 0);
    ss << "(" << convert(x.getExprContainer()[0]);
    for (unsigned int i = 1; i < x.getExprContainer().size(); ++i) {
        ss << ", " << convert(x.getExprContainer()[i]);
    }
    ss << ")";
    return ss.str();
}
    
std::string ConvertAssignment2SystemC::convert(const VRExprMultConcatenation & x) {
    VRExprExpression repeat = x.getExprRepeat();
    if (!repeat.getPrimaryHandle())
        LOG(ERROR) << "repeat not primary in " << x.toString();
    if (!repeat.getPrimaryHandle()->getNumberHandle())
        LOG(ERROR) << "repeat not number in " << x.toString();

    unsigned repeatTimes = repeat.getPrimaryHandle()->getNumberHandle()->getUnsignedNumber();

    std::stringstream ss;
    assert(x.getExprContainer().size() > 0);
    ss << "(" << convert(x.getExprContainer()[0]);
    for (unsigned int i = 1; i < x.getExprContainer().size(); ++i)
        ss << ", " << convert(x.getExprContainer()[i]);
    ss << ")";
    std::string eInner = ss.str();
    std::stringstream ss2;
    ss2 << "(" << eInner;
    for (unsigned int i = 1; i < repeatTimes; ++i) {
        ss2 << ", " << eInner;
    }
    ss2 << ")";
    return ss2.str();
}
    
std::string ConvertAssignment2SystemC::convert(const VRExprSelect & x) {
    if (x.getBitSelectHandle()) {
        return convert(*x.getBitSelectHandle());
    } else if (x.getRangeSelectHandle()) {
        return convert(*x.getRangeSelectHandle());
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

std::string ConvertAssignment2SystemC::convert(const VRExprBitSelect & x) {
    return "[" + convert(x.getExpr()) + "]";
}

std::string ConvertAssignment2SystemC::convert(const VRExprRangeSelect & x) {
    return ".range(" + convert(x.getExprFst()) + ", " + convert(x.getExprSnd()) + ")";
}

std::string ConvertAssignment2SystemC::convertAsIfElse() {
    return convertAsIfElse(_assignment.getExprRhs());
}
    
std::string ConvertAssignment2SystemC::convertAsIfElse(const VRExprExpression & x) {
    std::string lhs = convert(_assignment.getExprLhs());
    if (x.getPrimaryHandle()) {
        return lhs + " = " + convert(*x.getPrimaryHandle()) + ";";
    } else if (x.getUnaryExpressionHandle()) {
        return lhs + " = " + convert(*x.getUnaryExpressionHandle()) + ";";
    } else if (x.getBinaryExpressionHandle()) {
        return lhs + " = " + convert(*x.getBinaryExpressionHandle()) + ";";
    } else if (x.getIteHandle()) {
        return convertAsIfElse(*x.getIteHandle());
    } else if (x.getItHandle()) {
        return convertAsIfElse(*x.getItHandle());
    } else if (x.getIeHandle()) {
        return convertAsIfElse(*x.getIeHandle());
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

std::string ConvertAssignment2SystemC::convertAsIfElse(const VRExprIte & x) {
    std::string stringIf = convert(x.getExprIf());
    std::string stringThen = convertAsIfElse(x.getExprThen());
    std::string stringElse = convertAsIfElse(x.getExprElse());
    return "if (" + stringIf + ") {\n"
         + stringThen + "\n"
         "} else\n {"
         + stringElse +
         "}"; 
}

std::string ConvertAssignment2SystemC::convertAsIfElse(const VRExprIt & x) {
    std::string stringIf = convert(x.getExprIf());
    std::string stringThen = convertAsIfElse(x.getExprThen());
    return "if (" + stringIf + ") {\n"
         + stringThen +
         "}";
}

std::string ConvertAssignment2SystemC::convertAsIfElse(const VRExprIe & x) {
    std::string stringIf = convert(x.getExprIf());
    std::string stringElse = convertAsIfElse(x.getExprElse());
    return "if (" + stringIf + ") {\n"
         " // do nothing \n"
         "} else\n {"
         + stringElse +
         "}"; 
}


