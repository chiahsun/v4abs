#include "test/UnitTest.h"
#include "VRExprIdentifier.h"
#include "VRExprNumber.h"
#include "VRExprExpression.h"
#include "VRExpr.h"

void test_vrexpr_identifier() {
    VRExprIdentifier identifier1("reg_a");
    VRExprIdentifier identifier2("out1");

    assertEqual("reg_a", identifier1.getName(), "Test get name");
    assertEqual("out1", identifier2.getName(), "Test get name");

    identifier1 = identifier2;
    
    assertEqual("out1", identifier1.getName(), "Test get name");
    assertEqual("out1", identifier2.getName(), "Test get name");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_binary_number() {
    VRExprBinaryNumber binary1("3'b100");
    assertEqual(3, binary1.getSize(), "Test get size");
    assertEqual(4, binary1.getUnsignedNumber(), "Test get unsigned number");

    VRExprBinaryNumber binary2("5'b1_0100");
    assertEqual(5, binary2.getSize(), "Test get size");
    assertEqual(20, binary2.getUnsignedNumber(), "Test get unsigned number");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_number() {
    {
        VRExprBinaryNumber binary1("2'b10");
        VRExprNumber number1(binary1);
        assertEqual(2, number1.getSize(), "Test get size");
        assertEqual(2, number1.getUnsignedNumber(), "Test get unsigned number");
        {
            VRExprNumber other = number1;
        }

        VRExprOctalNumber octal1("3'o001");
        VRExprNumber number2(octal1);
        assertEqual(3, number2.getSize(), "Test get size");
        assertEqual(1, number2.getUnsignedNumber(), "Test get unsigned number");
        {
            VRExprNumber other = number2;
        }

        VRExprDecimalNumber decimal1("5'd20");
        VRExprNumber number3(decimal1);
        assertEqual(5, number3.getSize(), "Test get size");
        assertEqual(20, number3.getUnsignedNumber(), "Test get unsigned number");
        {
            VRExprNumber other = number3;
        }
        VRExprHexNumber hex1("8'hff");
        VRExprNumber number4(hex1);
        assertEqual(8, number4.getSize(), "Test get size");
        assertEqual(255, number4.getUnsignedNumber(), "Test get unsigned number");

        VRExprUnsignedNumber unsigned1(20);
        VRExprNumber number5(unsigned1);
        assertEqual(32, number5.getSize(), "Test get size");
        assertEqual(20, number5.getUnsignedNumber(), "Test get unsigned number");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_select() {
    {
        VRExprSelect select = makeBitSelect(makeUnsignedNumber(2));
        assertEqual("[2]", select.toString(), "Test to string");
    }
    {
        VRExprSelect select = makeRangeSelect(makeUnsignedNumber(2), makeUnsignedNumber(0));
        assertEqual("[2:0]", select.toString(), "Test to string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_concatenation() {
    {
        VRExprConcatenation concat = VRExprConcatenation(makeIdentifier("a"), makeBinaryNumber("2'b11"));
        assertEqual("{a,2'b11}", concat.toString(), "Test to string");
    }
    {
        VRExprConcatenation concat = VRExprConcatenation(makeIdentifier("a"), makeBinaryNumber("2'b11"), makeIdentifier("reg_b"));
        assertEqual("{a,2'b11,reg_b}", concat.toString(), "Test to string");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_mult_concatenation() {
    {
        VRExprMultConcatentation mult_concat = VRExprMultConcatentation(makeUnsignedNumber(3), makeIdentifier("a"));
        assertEqual("{3{a}}", mult_concat.toString(), "Test to string");
    }
    {
        VRExprMultConcatentation mult_concat = VRExprMultConcatentation(makeUnsignedNumber(3), makeIdentifier("a"), makeIdentifier("b"));
        assertEqual("{3{a,b}}", mult_concat.toString(), "Test to string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_expression() {
    {
        VRExprPrimary a = makeIdentifier("a");
        assertEqual("a", a.toString(), "Test to string");
        VRExprExpression ea = a; 
    }
    {
        VRExprExpression not_a = makeUnaryExpression(UNARY_NOT, makeIdentifier("a"));
        assertEqual("!a", not_a.toString(), "Test to string");
    }
    {
        VRExprExpression a_plus_b = makeBinaryExpression(makeIdentifier("a"), BINARY_PLUS, makeIdentifier("b"));
        assertEqual("(a+b)", a_plus_b.toString(), "Test to string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr() {
    {
        VRExpr expr = makeIte(makeBinaryExpression(makeIdentifier("a"), BINARY_GT, makeIdentifier("b")), makeBinaryNumber("1'b1"), makeBinaryNumber("1'b0"));
        assertEqual("ite((a>b), 1'b1, 1'b0)", expr.toString(), "Test to string");
    }
    {
        VRExpr expr = makeIte(makeBinaryExpression(makeIdentifier("a"), BINARY_GT, makeIdentifier("b")), makeBinaryNumber("1'b1"));
        assertEqual("ite((a>b), 1'b1, null)", expr.toString(), "Test to string");
    }
    {
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_vrexpr_identifier();
    test_vrexpr_binary_number();
    test_vrexpr_number();
    test_vrexpr_select();
    test_vrexpr_concatenation();
    test_vrexpr_mult_concatenation();
    test_vrexpr_expression();
    test_vrexpr();
    return 0;
}
