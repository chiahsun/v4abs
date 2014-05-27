#include "AstParser.h"
#include "test/UnitTest.h"
		

void test_parse_unsigned_number() {
    {
		AstUnsignedNumberParser parser;
		assertEqual("(unsigned_number 121)", parser.parseString("(unsigned_number 121)")->toString(), "Test parse unsigned number");
	}
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_binary_number() {
	AstBinaryNumberParser parser;
	assertEqual("(binary_number 2'b11)", parser.parseString("(binary_number 2'b11)")->toString(), "Test parse binary number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_octal_number() {
	AstOctalNumberParser parser;
	assertEqual("(octal_number 3'o2)", parser.parseString("(octal_number 3'o2)")->toString(), "Test parse octal number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_decimal_number() {
	AstDecimalNumberParser parser;
	assertEqual("(decimal_number 20'd921)", parser.parseString("(decimal_number 20'd921)")->toString(), "Test parse decimal number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_heximal_number() {
	AstHeximalNumberParser parser;
	assertEqual("(heximal_number 16'hffff)", parser.parseString("(heximal_number 16'hffff)")->toString(), "Test parse heximal number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_number_unsigned_number() {
	AstNumberParser parser;
	assertEqual("(number (unsigned_number 123))", parser.parseString("(number (unsigned_number 123))")->toString(), "Test parse number unsigned number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_number_binary_number() {
	AstNumberParser parser;
	assertEqual("(number (binary_number 2'b11))", parser.parseString("(number (binary_number 2'b11))")->toString(), "Test parse number binary number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_number_octal_number() {
	AstNumberParser parser;
	assertEqual("(number (octal_number 3'o2))", parser.parseString("(number (octal_number 3'o2))")->toString(), "Test parse number octal number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_number_decimal_number() {
    AstNumberParser parser;
	assertEqual("(number (decimal_number 4'd3))", parser.parseString("(number (decimal_number 4'd3))")->toString(), "Test parse number decimal number");

	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_number_heximal_number() {
	AstNumberParser parser;
	assertEqual("(number (heximal_number 12'hFFF))", parser.parseString("(number (heximal_number 12'hFFF)")->toString(), "Test parse number heximal number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_simple_identifier() {
	AstSimpleIdentifierParser parser;
	assertEqual("(simple_identifier reg_a)", parser.parseString("(simple_identifier reg_a)")->toString(), "Test parse simple identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_single_identifier_simple_identifier() {
	AstSingleIdentifierParser parser;
	assertEqual("(single_identifier (simple_identifier reg_a))", parser.parseString("(single_identifier (simple_identifier reg_a))")->toString(), "Test parse single identifier simple identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_zero_or_more_dot_single_identifier() {
    AstZeroOrMoreDotSingleIdentifierParser parser;
    assertEqual("(zero_or_more_dot_single_identifier (single_identifier (simple_identifier A)))", parser.parseString("(zero_or_more_dot_single_identifier . (single_identifier (simple_identifier A)))")->toString(), "Test parse star dot single identifier");
    assertEqual("(zero_or_more_dot_single_identifier (single_identifier (simple_identifier A)) (single_identifier (simple_identifier B)))", parser.parseString("(zero_or_more_dot_single_identifier . (single_identifier (simple_identifier A)) . (single_identifier (simple_identifier B)))")->toString(), "Test parse star dot single identifier");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_multi_identifier() {
    AstMultiIdentifierParser parser;
    assertEqual("(multi_identifier (single_identifier (simple_identifier A)) (zero_or_more_dot_single_identifier (single_identifier (simple_identifier B))))", parser.parseString("(multi_identifier (single_identifier (simple_identifier A)) . (single_identifier (simple_identifier B)))")->toString(), "Test parse multi identifer");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_identifer() {
	AstIdentifierParser parser;

	assertEqual("(identifier (single_identifier (simple_identifier reg_a)))", parser.parseString("(identifier (single_identifier (simple_identifier reg_a)))")->toString(), "Test parse identifier single identifier");

	assertEqual("(identifier (multi_identifier (single_identifier (simple_identifier moda)) (zero_or_more_dot_single_identifier (single_identifier (simple_identifier reg_a)))))", parser.parseString("(identifier (single_identifier (simple_identifier moda)) . (single_identifier (simple_identifier reg_a)))")->toString(), "Test parse identifier multipler single identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_primary_number() {
	AstPrimaryParser parser;
	assertEqual("(primary (number (unsigned_number 20)))", parser.parseString("(primary (number (unsigned_number 20)))")->toString(), "Test parse primary number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_primary_identifier() {
	AstPrimaryParser parser;
	assertEqual("(primary (identifier (single_identifier (simple_identifier reg_a))))", parser.parseString("(primary (identifier (single_identifier (simple_identifier reg_a))))")->toString(), "Test parse primary identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_expression_primary() {
	AstExpressionParser parser;
	assertEqual("(expression (primary (identifier (single_identifier (simple_identifier reg_a)))))", parser.parseString("(expression (primary (identifier (single_identifier (simple_identifier reg_a)))))")->toString(), "Test parse expression primary");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_expression_primary_select_identifier() {
	AstExpressionParser parser;
	assertEqual("(expression (binary_expression (binary_expression_shift_right (expression (primary (select_identifier (identifier (single_identifier (simple_identifier a))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0)))))))))) (expression (primary (number (unsigned_number 2)))))))", parser.parseString("(expression (expression (primary (identifier (single_identifier (simple_identifier a    ))) [ (expression (primary (number (unsigned_number 0)))) ])) > > (expression (primary (number (unsigned_number 2))))) ")->toString(), "Test parse expression primary");
    assertEqual("(expression (binary_expression (binary_expression_gt (expression (primary (select_identifier (identifier (single_identifier (simple_identifier a2))) (one_or_more_select (select (range_select (expression (primary (number (unsigned_number 1)))) (expression (primary (number (unsigned_number 0)))))))))) (expression (primary (number (binary_number 2'b11)))))))", parser.parseString("(expression (expression (primary (identifier (single_identifier (simple_identifier a2))) [ (expression (primary (number (unsigned_number 1)))) : (expression (primary (number (unsigned_number 0)))) ])) > (expression (primary (number (binary_number 2'b11)))))")->toString(), "TEst parse expression binary");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_unary_expression() {
    AstUnaryExpressionParser parser;
    assertEqual("(unary_expression (unary_operator (unary_operator_not)) (primary (identifier (single_identifier (simple_identifier abc)))))", parser.parseString("(unary_expression (unary_operator !) (primary (identifier (single_identifier (simple_identifier abc)))))")->toString(), "Test parse unary expression");
}

void test_parse_expression_unary_expression() {
	AstExpressionParser parser;
	assertEqual("(expression (unary_expression (unary_operator (unary_operator_not)) (primary (identifier (single_identifier (simple_identifier A))))))", parser.parseString("(expression (unary_operator !) (primary (identifier (single_identifier (simple_identifier A)))))")->toString(), "Test parse expression unary op");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_expression_binary_expression() {
	AstExpressionParser parser;
	assertEqual("(expression (binary_expression (binary_expression_plus (expression (primary (identifier (single_identifier (simple_identifier wire_a))))) (expression (primary (number (binary_number 2'b11)))))))", parser.parseString("(expression (expression (primary (identifier (single_identifier (simple_identifier wire_a))))) + (expression (primary (number (binary_number 2'b11)))))")->toString(), "Test parse expression binary op");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_braced_expression() {
	AstBracedExpressionParser parser;
	assertEqual("(braced_expression (expression (primary (number (unsigned_number 20)))))", parser.parseString("(braced_expression ( (expression (primary (number (unsigned_number 20)))) ))")->toString(), "Test parse expression expression");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_expression_braced_expression() {
	AstExpressionParser parser;
	assertEqual("(expression (braced_expression (expression (primary (number (unsigned_number 20))))))", parser.parseString("(expression ( (expression (primary (number (unsigned_number 20)))) ))")->toString(), "Test parse expression expression");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_expression_ternary_expression() {
	AstExpressionParser parser;
	assertEqual("(expression (ternary_expression (expression (primary (number (binary_number 1'b1)))) (expression (primary (number (binary_number 2'b00)))) (expression (primary (number (binary_number 2'b11))))))", parser.parseString("(expression (expression (primary (number (binary_number 1'b1)))) ? (expression (primary (number (binary_number 2'b00)))) : (expression (primary (number (binary_number 2'b11)))))")->toString(), "Test parse expression ternary op");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_bit_select() {
    AstBitSelectParser parser;
    assertEqual("(bit_select (expression (primary (number (unsigned_number 2)))))", parser.parseString("(bit_select [ (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse bit select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_range_select() {
    AstRangeSelectParser parser;
    assertEqual("(range_select (expression (primary (number (unsigned_number 2)))) (expression (primary (number (unsigned_number 2)))))", parser.parseString("(range_select [ (expression (primary (number (unsigned_number 2)))) : (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse range select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_select() {
    AstSelectParser parser;
    assertEqual("(select (bit_select (expression (primary (number (unsigned_number 2))))))", parser.parseString("(select [ (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse bit select");

    assertEqual("(select (range_select (expression (primary (number (unsigned_number 2)))) (expression (primary (number (unsigned_number 2))))))", parser.parseString("(select [ (expression (primary (number (unsigned_number 2)))) : (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse range select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_one_or_more_select() {
    AstOneOrMoreSelectParser parser;
    assertEqual("(one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 2)))))))", parser.parseString("(one_or_more_select [ (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse bit select");
   assertEqual("(one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 2)))))) (select (range_select (expression (primary (number (unsigned_number 1)))) (expression (primary (number (unsigned_number 2)))))))", parser.parseString("(one_or_more_select [ (expression (primary (number (unsigned_number 2)))) ] [ (expression (primary (number (unsigned_number 1)))) : (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse one or more select");
   // assertEqual("(one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 2)))))) (select (range_select (expression (primary (number (unsigned_number 1)))) (expression (primary (number (unsigned_number 2)))))))", parser.parseString("(one_or_more_select [ (expression (primary (number (unsigned_number 2)))) ] [ (expression (primary (number (unsigned_number 1)))) : (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse one or more select");
}

void test_parse_select_identifier() {
    AstSelectIdentifierParser parser;
    assertEqual("(select_identifier (identifier (single_identifier (simple_identifier A))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 2))))))))", parser.parseString("(select_identifier (identifier (single_identifier (simple_identifier A))) [ (expression (primary (number (unsigned_number 2)))) ])")->toString(), "Test parse bit select");

}

void test_parse_primary_select_identifier() {
	AstPrimaryParser parser;
	assertEqual("(primary (select_identifier (identifier (single_identifier (simple_identifier reg_a))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0)))))))))", parser.parseString("(primary (identifier (single_identifier (simple_identifier reg_a))) [ (expression (primary (number (unsigned_number 0)))) ])")->toString(), "Test parse primary select identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_one_or_more_comma_expression() {
    AstOneOrMoreCommaExpressionParser parser;
    assertEqual("(one_or_more_comma_expression (expression (primary (identifier (single_identifier (simple_identifier A))))))", parser.parseString("(one_or_more_comma_expression , (expression (primary (identifier (single_identifier (simple_identifier A))))))")->toString(), "Test parse one or more comma expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_concatenation() {
	AstConcatenationParser parser;

	assertEqual("(concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00))))))", parser.parseString("(concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) })")->toString(), "Test parse concatenation");
	
	assertEqual("(concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))) (expression (primary (number (binary_number 1'b1))))))", parser.parseString("(concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) , (expression (primary (number (binary_number 1'b1)))) })")->toString(), "Test parse concatenation");

	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_multiple_concatenation() {

	AstMultipleConcatenationParser parser;
	assertEqual("(multiple_concatenation (expression (primary (number (unsigned_number 4)))) (expression (primary (number (binary_number 1'b1)))) (zero_or_more_comma_expression))", parser.parseString("(multiple_concatenation { (expression (primary (number (unsigned_number 4)))) { (expression (primary (number (binary_number 1'b1)))) } })")->toString(), "Test parse multiple concatenation");

	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_primary_concatenation() {
	AstPrimaryParser parser;
	assertEqual("(primary (concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))) (expression (primary (number (binary_number 1'b1)))))))", parser.parseString("(primary (concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) , (expression (primary (number (binary_number 1'b1)))) }))")->toString(), "Test parse primary concatenation");
	assertEqual("(primary (concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))))))", parser.parseString("(primary (concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) }))")->toString(), "Test parse primary concatenation");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_primary_multiple_concatenation() {

	AstPrimaryParser parser;
	assertEqual("(primary (multiple_concatenation (expression (primary (number (unsigned_number 4)))) (expression (primary (number (binary_number 1'b1)))) (zero_or_more_comma_expression)))", parser.parseString("(primary (multiple_concatenation { (expression (primary (number (unsigned_number 4)))) { (expression (primary (number (binary_number 1'b1)))) } }))")->toString(), "Test parse primary multiple concatenation");

	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_primary_identifier() {
	AstConstantPrimaryParser parser;
	assertEqual("(constant_primary (identifier (single_identifier (simple_identifier reg_a))))", parser.parseString("(constant_primary (identifier (single_identifier (simple_identifier reg_a))))")->toString(), "Test parse constant primary identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_primary_concatenation() {
	AstConstantPrimaryParser parser;
	assertEqual("(constant_primary (concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))))))", parser.parseString("(constant_primary (concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) }))")->toString(), "Test parse constant primary concatenation");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_primary_multiple_concatenation() {
	AstConstantPrimaryParser parser;

	assertEqual("(constant_primary (multiple_concatenation (expression (primary (number (unsigned_number 4)))) (expression (primary (number (binary_number 1'b1)))) (zero_or_more_comma_expression)))", parser.parseString("(constant_primary (multiple_concatenation { (expression (primary (number (unsigned_number 4)))) { (expression (primary (number (binary_number 1'b1)))) } }))")->toString(), "Test parse constant primary multiple concatenation");

	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_constant_primary_number() {
	AstConstantPrimaryParser parser;
	assertEqual("(constant_primary (number (unsigned_number 20)))", parser.parseString("(constant_primary (number (unsigned_number 20)))")->toString(), "Test parse primary number");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_expression_primary() {
	AstConstantExpressionParser parser;
	assertEqual("(constant_expression (constant_primary (identifier (single_identifier (simple_identifier reg_a)))))", parser.parseString("(constant_expression (constant_primary (identifier (single_identifier (simple_identifier reg_a)))))")->toString(), "Test parse expression primary");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_expression_expression() {
	AstConstantExpressionParser parser;
	assertEqual("(constant_expression (braced_constant_expression (constant_expression (constant_primary (number (unsigned_number 20))))))", parser.parseString("(constant_expression ( (constant_expression (constant_primary (number (unsigned_number 20)))) ))")->toString(), "Test parse expression expression");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_expression_unary_constant_expression() {
	AstConstantExpressionParser parser;
	assertEqual("(constant_expression (unary_constant_expression (unary_operator (unary_operator_not)) (constant_primary (identifier (single_identifier (simple_identifier abc))))))", parser.parseString("(constant_expression (unary_operator !) (constant_primary (identifier (single_identifier (simple_identifier abc)))))")->toString(), "Test parse expression unary op");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_expression_binary_op() {
	AstConstantExpressionParser parser;
	assertEqual("(constant_expression (binary_constant_expression (binary_constant_expression_plus (constant_expression (constant_primary (identifier (single_identifier (simple_identifier wire_a))))) (constant_expression (constant_primary (number (binary_number 2'b11)))))))", parser.parseString("(constant_expression (constant_expression (constant_primary (identifier (single_identifier (simple_identifier wire_a))))) + (constant_expression (constant_primary (number (binary_number 2'b11)))))")->toString(), "Test parse expression binary op");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant_expression_ternary_op() {
	AstConstantExpressionParser parser;
	assertEqual("(constant_expression (ternary_constant_expression (constant_expression (constant_primary (number (binary_number 1'b1)))) (constant_expression (constant_primary (number (binary_number 2'b00)))) (constant_expression (constant_primary (number (binary_number 2'b11))))))", parser.parseString("(constant_expression (constant_expression (constant_primary (number (binary_number 1'b1)))) ? (constant_expression (constant_primary (number (binary_number 2'b00)))) : (constant_expression (constant_primary (number (binary_number 2'b11)))))")->toString(), "Test parse expression ternary op");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_range() {
	AstRangeParser parser;
	assertEqual("(range (constant_expression (constant_primary (number (unsigned_number 5)))) (constant_expression (constant_primary (number (unsigned_number 2)))))", parser.parseString("(range [ (constant_expression (constant_primary (number (unsigned_number 5)))) : (constant_expression (constant_primary (number (unsigned_number 2)))) ])")->toString(), "Test parse range");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
	

void test_parse_net_lvalue_identifier() {
	AstNetLvalueParser parser;
	assertEqual("(net_lvalue (identifier (single_identifier (simple_identifier A))))", parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))))")->toString(), "Test parse net lvalue identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
void test_parse_net_lvalue_bit_select() {
	AstNetLvalueParser parser;
	assertEqual("(net_lvalue (net_lvalue_bit_select (identifier (single_identifier (simple_identifier A))) (expression (primary (number (unsigned_number 1))))))", parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))) [ (expression (primary (number (unsigned_number 1)))) ])")->toString(), "Test parse net lvalue identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
void test_parse_net_lvalue_range_select() {
	AstNetLvalueParser parser;
	assertEqual("(net_lvalue (net_lvalue_range_select (identifier (single_identifier (simple_identifier A))) (constant_expression (constant_primary (number (unsigned_number 1)))) (constant_expression (constant_primary (number (unsigned_number 0))))))", parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))) [ (constant_expression (constant_primary (number (unsigned_number 1)))) : (constant_expression (constant_primary (number (unsigned_number 0)))) ])")->toString(), "Test parse net lvalue identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
void test_parse_net_lvaue_concatenation() {
	AstNetLvalueParser parser;
	assertEqual("(net_lvalue (concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))))))", parser.parseString("(net_lvalue (concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) }))")->toString(), "Test parse concatenation");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


// TODO zero_or_more_net_assignment fail

void test_parse_net_assignment() {
	AstNetAssignmentParser parser;
	assertEqual("(net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) (expression (primary (number (binary_number 1'b1)))))", parser.parseString("(net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1)))))")->toString(), "Test parse continuous assign");
    assertEqual("(net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier B))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0)))))))))))", parser.parseString("(net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) = (expression (primary (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ])))")->toString(), "Test parse zero or more comma net assignment");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_zero_or_more_comma_net_assignment() {
    AstZeroOrMoreCommaNetAssignmentParser parser;
    assertEqual("(zero_or_more_comma_net_assignment (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier A)))) (expression (primary (number (binary_number 1'b1))))))", parser.parseString("(zero_or_more_comma_net_assignment , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier (A))))) = (expression (primary (number (binary_number (1'b1)))))))")->toString(), "Test parse zero or more comma net assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_list_of_net_assignment() {
	AstListOfNetAssignmentsParser parser;
    
    assertEqual("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) (expression (primary (number (binary_number 1'b1))))) (zero_or_more_comma_net_assignment))", parser.parseString("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))))")->toString(), "Test parse list of net assignment");

    assertEqual("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier B))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0))))))))))) (zero_or_more_comma_net_assignment))", parser.parseString("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) = (expression (primary (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ]))))")->toString(), "Test parse list of net assignment");
  //  assertEqual("", parser.parseString("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))) , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))))")->toString(), "Test parse list of net assignment");
//	assertEqual("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a))))) (expression (primary (number (binary_number 1'b1)))) (zero_or_more_net_assignment (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b))))) (expression (primary (number (binary_number 2'b11))))))", parser.parseString("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))) , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b)))) = (expression (primary (number (binary_number 2'b11))))))")->toString(), "Test parse list of net assignment");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_continuous_assign() {
	AstContinuousAssignParser parser;
	assertEqual("(continuous_assign (keyword_assign assign) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier B))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0))))))))))) (zero_or_more_comma_net_assignment)))", parser.parseString("(continuous_assign (keyword_assign assign ) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) = (expression (primary (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ])))) ;)")->toString(), "Test parse continuous assign");
	assertEqual("(continuous_assign (keyword_assign assign) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) (expression (primary (number (binary_number 1'b1))))) (zero_or_more_comma_net_assignment (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b)))) (expression (primary (number (binary_number 2'b11))))))))", parser.parseString("(continuous_assign (keyword_assign assign ) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))) , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b)))) = (expression (primary (number (binary_number 2'b11)))))) ;)")->toString(), "Test parse continuous assign");
//	assertEqual("", parser.parseString("(continuous_assign (keyword_assign assign ) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a))))) = (expression (primary (number (binary_number 1'b1))))) ;)")->toString(), "Test parse continuous assign");
//	assertEqual("", parser.parseString("(continuous_assign (keyword_assign assign ) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))) , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b)))) = (expression (primary (number (binary_number 2'b11)))))) ;)")->toString(), "Test parse continuous assign");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}



void test_parse_reg_lvalue_identifier() {
    AstRegLvalueParser parser;
	assertEqual("(reg_lvalue (identifier (single_identifier (simple_identifier reg_a))))", parser.parseString("(reg_lvalue (identifier (single_identifier (simple_identifier reg_a))))")->toString(), "Test parse reg_lvalue identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_reg_lvalue_select_identifier() {
    AstRegLvalueParser parser;
	assertEqual("(reg_lvalue (select_identifier (identifier (single_identifier (simple_identifier reg_a))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0)))))))))", parser.parseString("(reg_lvalue (identifier (single_identifier (simple_identifier reg_a))) [ (expression (primary (number (unsigned_number 0)))) ] )")->toString(), "Test parse reg_lvalue select identifier");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_reg_lvalue_concatenation() {
    AstRegLvalueParser parser;
	assertEqual("(reg_lvalue (concatenation (expression (primary (number (binary_number 2'b11)))) (one_or_more_comma_expression (expression (primary (number (binary_number 2'b00)))))))", parser.parseString("(reg_lvalue (concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) }))")->toString(), "Test parse reg_lvalue concatenation");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();	
}

void test_parse_blocking_assignment() {
    AstBlockingAssignmentParser parser;

	assertEqual("(blocking_assignment (reg_lvalue (select_identifier (identifier (single_identifier (simple_identifier B))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0))))))))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier packed_B))) (one_or_more_select (select (range_select (expression (primary (number (unsigned_number 15)))) (expression (primary (number (unsigned_number 0)))))))))))", parser.parseString("(blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ]) = (expression (primary (identifier (single_identifier (simple_identifier packed_B))) [ (expression (primary (number (unsigned_number 15)))) : (expression (primary (number (unsigned_number 0)))) ])))")->toString(), "Test parse blocking assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_name_of_gate_instance() {
    AstNameOfGateInstanceParser parser;
    
    assertEqual("(name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1))) (zero_or_one_range))", parser.parseString("(name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1))))")->toString(), "Test parse name of gate instance");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_input_terminal() {
    AstInputTerminalParser parser;
    assertEqual("(input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1))))))", parser.parseString("(input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1))))))")->toString(), "Test parse input terminal");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_output_terminal() {
    AstOutputTerminalParser parser;
    assertEqual("(output_terminal (identifier (single_identifier (simple_identifier N118))) (zero_or_one_constant_bit_select))", parser.parseString("(output_terminal (identifier (single_identifier (simple_identifier N118))))")->toString(), "Test parse output terminal");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_n_input_gate_instance() {
    AstNInputGateInstanceParser parser;
    assertEqual("(n_input_gate_instance (zero_or_one_name_of_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NAND2_1))) (zero_or_one_range))) (output_terminal (identifier (single_identifier (simple_identifier N10))) (zero_or_one_constant_bit_select)) (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) (zero_or_more_comma_input_terminal (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N3))))))))", parser.parseString("(n_input_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NAND2_1)))) ( (output_terminal (identifier (single_identifier (simple_identifier N10)))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N3)))))) ))")->toString(), "Test parse n input gate instance");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_n_output_gate_instance() {
    AstNOutputGateInstanceParser parser;
    assertEqual("(n_output_gate_instance (zero_or_one_name_of_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1))) (zero_or_one_range))) (output_terminal (identifier (single_identifier (simple_identifier N118))) (zero_or_one_constant_bit_select)) (zero_or_more_comma_output_terminal) (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))))", parser.parseString("(n_output_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1)))) ( (output_terminal (identifier (single_identifier (simple_identifier N118)))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) ))")->toString(), "Test parse n output gate instance");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_gate_instantiation() {
    AstGateInstantiationParser parser;
    assertEqual("(gate_instantiation (gate_instantiation_output (n_output_gatetype not) (n_output_gate_instance (zero_or_one_name_of_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1))) (zero_or_one_range))) (output_terminal (identifier (single_identifier (simple_identifier N118))) (zero_or_one_constant_bit_select)) (zero_or_more_comma_output_terminal) (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1))))))) (zero_or_more_comma_n_output_gate_instance)))", parser.parseString("(gate_instantiation (n_output_gatetype not ) (n_output_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1)))) ( (output_terminal (identifier (single_identifier (simple_identifier N118)))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) )) ;)")->toString(), "Test parse gate instantiation");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_non_blocking_assignment() {
    AstNonBlockingAssignmentParser parser;
    assertEqual("(non_blocking_assignment (reg_lvalue (select_identifier (identifier (single_identifier (simple_identifier B))) (one_or_more_select (select (bit_select (expression (primary (number (unsigned_number 0))))))))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier packed_B))) (one_or_more_select (select (range_select (expression (primary (number (unsigned_number 15)))) (expression (primary (number (unsigned_number 0)))))))))))", parser.parseString("(non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ]) < = (expression (primary (identifier (single_identifier (simple_identifier packed_B))) [ (expression (primary (number (unsigned_number 15)))) : (expression (primary (number (unsigned_number 0)))) ])))")->toString(), "Test parse non blocking assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_statement_blocking_assignment() {
    AstStatementParser parser;
    assertEqual("(statement (blocking_assignment_semicolon (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) (expression (primary (identifier (single_identifier (simple_identifier B))))))))", parser.parseString("(statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) = (expression (primary (identifier (single_identifier (simple_identifier B)))))) ;)")->toString(), "Test parse statement blocking assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_statement_non_blocking_assignment() {
    AstStatementParser parser;
    assertEqual("(statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) (expression (primary (identifier (single_identifier (simple_identifier B))))))))", parser.parseString("(statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) < = (expression (primary (identifier (single_identifier (simple_identifier B)))))) ;)")->toString(), "Test parse statement non blocking assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_statement_procedural_continuous_assignment() {
    AstStatementParser parser;
    assertEqual("(statement (procedural_continuous_assignment_semicolon (procedural_continuous_assignment (keyword_assign assign) (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier reg_A)))) (expression (binary_expression (binary_expression_bw_and (expression (primary (number (binary_number 8'b1001_1101)))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier A))) (one_or_more_select (select (range_select (expression (binary_expression (binary_expression_plus (expression (primary (number (unsigned_number 5)))) (expression (primary (number (unsigned_number 3))))))) (expression (primary (number (unsigned_number 1)))))))))))))))))", parser.parseString("(statement (procedural_continuous_assignment (keyword_assign assign ) (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier reg_A)))) = (expression (expression (primary (number (binary_number 8'b1001_1101)))) & (expression (primary (identifier (single_identifier (simple_identifier A))) [ (expression (expression (primary (number (unsigned_number 5)))) + (expression (primary (number (unsigned_number 3))))) : (expression (primary (number (unsigned_number 1)))) ])))) ;) ;)")->toString(), "Test parse statement procedural continuous assignment");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_procedural_timing_control_statement() {
    AstStatementParser parser;
    assertEqual("(statement (procedural_timing_control_statement (delay_or_event_control (event_control (at_event_expression (event_expression (event_or_event (event_expression (posedge_expression (keyword_posedge posedge) (expression (primary (identifier (single_identifier (simple_identifier clk))))))) (keyword_or or) (event_expression (negedge_expression (keyword_negedge negedge) (expression (primary (identifier (single_identifier (simple_identifier reset)))))))))))) (statement_or_null (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) (expression (primary (number (unsigned_number 0))))))))))", parser.parseString("(statement (procedural_timing_control_statement (delay_or_event_control (event_control @ ( (event_expression (event_expression (keyword_posedge posedge ) (expression (primary (identifier (single_identifier (simple_identifier clk)))))) (keyword_or  or ) (event_expression (keyword_negedge negedge ) (expression (primary (identifier (single_identifier (simple_identifier reset))))))) ))) (statement_or_null (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) < = (expression (primary (number (unsigned_number 0))))) ;))))")->toString(), "Test parse statement procedural timing control statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_condtional_statement() {
    AstConditionalStatementParser parser;
    assertEqual("(conditional_statement (keyword_if if) (expression (primary (identifier (single_identifier (simple_identifier reset))))) (statement_or_null (statement (seq_block (keyword_begin begin) (zero_or_more_statement (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) (expression (primary (identifier (single_identifier (simple_identifier STATE_INIT)))))))) (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier latch_cnt)))) (expression (primary (identifier (single_identifier (simple_identifier LATCH_CNT_INIT)))))))) (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier gauss_iter_en)))) (expression (primary (identifier (single_identifier (simple_identifier GAUSS_ITER_EN_INIT))))))))) (keyword_end end)))) (zero_or_one_else_statement_or_null (else_statement_or_null (keyword_else else) (statement_or_null (statement (seq_block (keyword_begin begin) (zero_or_more_statement (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) (expression (primary (identifier (single_identifier (simple_identifier next_state)))))))) (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier latch_cnt)))) (expression (primary (identifier (single_identifier (simple_identifier next_latch_cnt)))))))) (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier gauss_iter_en)))) (expression (primary (identifier (single_identifier (simple_identifier next_gauss_iter_en))))))))) (keyword_end end)))))))", parser.parseString("(conditional_statement (keyword_if if ) ( (expression (primary (identifier (single_identifier (simple_identifier reset))))) ) (statement_or_null (statement (seq_block (keyword_begin  begin\n) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) < = (expression (primary (identifier (single_identifier (simple_identifier STATE_INIT)))))) ;) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier latch_cnt)))) < = (expression (primary (identifier (single_identifier (simple_identifier LATCH_CNT_INIT)))))) ;) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier gauss_iter_en)))) < = (expression (primary (identifier (single_identifier (simple_identifier GAUSS_ITER_EN_INIT)))))) ;) (keyword_end \nend\n)))) (keyword_else else ) (statement_or_null (statement (seq_block (keyword_begin begin\n) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) < = (expression (primary (identifier (single_identifier (simple_identifier next_state)))))) ;) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier latch_cnt)))) < = (expression (primary (identifier (single_identifier (simple_identifier next_latch_cnt)))))) ;) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier gauss_iter_en)))) < = (expression (primary (identifier (single_identifier (simple_identifier next_gauss_iter_en)))))) ;) (keyword_end \nend\n)))))")->toString(), "Test parse conditional statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_case_statement() {
    AstCaseStatementParser parser;

    assertEqual("(case_statement (keyword_case case) (expression (primary (identifier (single_identifier (simple_identifier state))))) (one_or_more_case_item (case_item (case_item_item (expression (primary (identifier (single_identifier (simple_identifier STATE_BEGIN))))) (zero_or_more_comma_expression) (statement_or_null (statement (blocking_assignment_semicolon (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) (expression (primary (identifier (single_identifier (simple_identifier state))))))))))) (case_item (case_item_item (expression (primary (identifier (single_identifier (simple_identifier STATE_OUT_ITER))))) (zero_or_more_comma_expression) (statement_or_null (statement (blocking_assignment_semicolon (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) (expression (primary (identifier (single_identifier (simple_identifier STATE_OUTPUT)))))))))))) (keyword_endcase endcase))", parser.parseString("(case_statement (keyword_case case ) ( (expression (primary (identifier (single_identifier (simple_identifier state))))) ) (case_item (expression (primary (identifier (single_identifier (simple_identifier STATE_BEGIN))))) : (statement_or_null (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier state)))))) ;))) (case_item (expression (primary (identifier (single_identifier (simple_identifier STATE_OUT_ITER))))) : (statement_or_null (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier STATE_OUTPUT)))))) ;))) (keyword_endcase \nendcase\n))")->toString(), "Test parse case statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_loop_statement() {
    AstLoopStatementParser parser;

    assertEqual("(loop_statement (keyword_for for) (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) (expression (primary (number (unsigned_number 0))))) (expression (binary_expression (binary_expression_lt (expression (primary (identifier (single_identifier (simple_identifier i))))) (expression (primary (number (unsigned_number 16))))))) (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) (expression (binary_expression (binary_expression_plus (expression (primary (identifier (single_identifier (simple_identifier i))))) (expression (primary (number (unsigned_number 1)))))))) (statement (seq_block (keyword_begin begin) (zero_or_more_statement (statement (non_blocking_assignment_semicolon (non_blocking_assignment (reg_lvalue (select_identifier (identifier (single_identifier (simple_identifier X))) (one_or_more_select (select (bit_select (expression (primary (identifier (single_identifier (simple_identifier i)))))))))) (expression (primary (select_identifier (identifier (single_identifier (simple_identifier next_X))) (one_or_more_select (select (bit_select (expression (primary (identifier (single_identifier (simple_identifier i))))))))))))))) (keyword_end end))))", parser.parseString("(loop_statement (keyword_for for ) ( (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) = (expression (primary (number (unsigned_number 0))))) ; (expression (expression (primary (identifier (single_identifier (simple_identifier i))))) < (expression (primary (number (unsigned_number 16))))) ; (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) = (expression (expression (primary (identifier (single_identifier (simple_identifier i))))) + (expression (primary (number (unsigned_number 1)))))) ) (statement (seq_block (keyword_begin  begin\n) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier X))) [ (expression (primary (identifier (single_identifier (simple_identifier i))))) ]) < = (expression (primary (identifier (single_identifier (simple_identifier next_X))) [ (expression (primary (identifier (single_identifier (simple_identifier i))))) ]))) ;) (keyword_end \nend\n))))")->toString(), "Test parse loop statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_instantiation() {
    AstModuleInstantiationParser parser;

    assertEqual("(module_instantiation (identifier (single_identifier (simple_identifier ADD))) (module_instance (name_of_instance (identifier (single_identifier (simple_identifier add1))) (zero_or_one_range)) (list_of_module_connections (list_of_named_port_connection (named_port_connection (identifier (single_identifier (simple_identifier clk))) (zero_or_one_expression (expression (primary (identifier (single_identifier (simple_identifier clk))))))) (zero_or_more_comma_named_port_connection (named_port_connection (identifier (single_identifier (simple_identifier rst))) (zero_or_one_expression (expression (primary (identifier (single_identifier (simple_identifier rst))))))) (named_port_connection (identifier (single_identifier (simple_identifier A))) (zero_or_one_expression (expression (primary (identifier (single_identifier (simple_identifier A))))))) (named_port_connection (identifier (single_identifier (simple_identifier B))) (zero_or_one_expression (expression (primary (identifier (single_identifier (simple_identifier B))))))) (named_port_connection (identifier (single_identifier (simple_identifier O))) (zero_or_one_expression (expression (primary (identifier (single_identifier (simple_identifier O))))))))))) (zero_or_more_comma_module_instance))", parser.parseString("(module_instantiation (identifier (single_identifier (simple_identifier ADD))) (module_instance (name_of_instance (identifier (single_identifier (simple_identifier add1)))) ( (list_of_module_connections (named_port_connection . (identifier (single_identifier (simple_identifier clk))) ( (expression (primary (identifier (single_identifier (simple_identifier clk))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier rst))) ( (expression (primary (identifier (single_identifier (simple_identifier rst))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier A))) ( (expression (primary (identifier (single_identifier (simple_identifier A))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier B))) ( (expression (primary (identifier (single_identifier (simple_identifier B))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier O))) ( (expression (primary (identifier (single_identifier (simple_identifier O))))) ))) )) ;)")->toString(), "Test parse module instantiation");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_item_declaration() {
    AstModuleItemDeclarationParser parser;
    assertEqual("(module_item_declaration (net_declaration (net_type (keyword_wire wire)) (zero_or_one_range (range (constant_expression (constant_primary (number (unsigned_number 31)))) (constant_expression (constant_primary (number (unsigned_number 0)))))) (list_of_net_identifier (identifier (single_identifier (simple_identifier X_out))) (zero_or_more_comma_identifier))))", parser.parseString("(module_item_declaration (net_declaration (net_type (keyword_wire wire )) (range [ (constant_expression (constant_primary (number (unsigned_number 31)))) : (constant_expression (constant_primary (number (unsigned_number 0)))) ]) (list_of_net_identifiers (identifier (single_identifier (simple_identifier X_out)))) ;))")->toString(), "Test parse module item declaration");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_item() {
    AstModuleItemParser parser;
    assertEqual("(module_item (always_construct (keyword_always always) (statement (procedural_timing_control_statement (delay_or_event_control (event_control (at_asterisk))) (statement_or_null (statement (seq_block (keyword_begin begin) (zero_or_more_statement (statement (blocking_assignment_semicolon (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) (expression (primary (identifier (single_identifier (simple_identifier state)))))))) (statement (blocking_assignment_semicolon (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_reg_i)))) (expression (primary (identifier (single_identifier (simple_identifier reg_i))))))))) (keyword_end end))))))))", parser.parseString("(module_item (always_construct (keyword_always always ) (statement (procedural_timing_control_statement (delay_or_event_control (event_control @ ( * ))) (statement_or_null (statement (seq_block (keyword_begin  begin\n) (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier state)))))) ;) (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_reg_i)))) = (expression (primary (identifier (single_identifier (simple_identifier reg_i)))))) ;) (keyword_end \nend\n))))))))")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_declaration() {
    AstModuleDeclarationParser parser;
    assertEqual("(module_declaration (module_keyword (keyword_module module)) (identifier (single_identifier (simple_identifier A))) (zero_or_one_list_of_ports (list_of_ports (port (port_expression (port_reference (identifier (single_identifier (simple_identifier reset)))))) (zero_or_more_comma_port))) (zero_or_more_module_item (module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier A))) (expression (primary (number (unsigned_number 10))))) (zero_or_more_comma_param_assignment)))))) (keyword_endmodule endmodule))", parser.parseString("(module_declaration (module_keyword (keyword_module module )) (identifier (single_identifier (simple_identifier A))) (list_of_ports ( (port (port_expression (port_reference (identifier (single_identifier (simple_identifier reset)))))) )) ; (module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter ) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier A))) = (expression (primary (number (unsigned_number 10)))))) ;))) (keyword_endmodule \nendmodule\n))")->toString(), "Test parse module declaration");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

#if 0
void test_parse_name_of_gate_instance_identifier() {
	AstNameOfGateInstanceParser parser;
	assertEqual("(name_of_gate_instance (identifier (single_identifier (simple_identifier A))))", parser.parseString("(name_of_gate_instance (identifier (single_identifier (simple_identifier A))))")->toString(), "Test parse range");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
void test_parse_name_of_gate_instance_identifier_range() {
	AstNameOfGateInstanceParser parser;
	assertEqual("(name_of_gate_instance (identifier (single_identifier (simple_identifier A))) (range (constant_expression (constant_primary (number (unsigned_number 5)))) (constant_expression (constant_primary (number (unsigned_number 2))))))", parser.parseString("(name_of_gate_instance (identifier (single_identifier (simple_identifier A)))(range [ (constant_expression (constant_primary (number (unsigned_number 5)))) : (constant_expression (constant_primary (number (unsigned_number 2)))) ])")->toString(), "Test parse range");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
	
void test_parse_output_terminal_identifier() {
	AstOutputTerminalParser parser;
	assertEqual("(output_terminal (identifier (single_identifier (simple_identifier A))))", parser.parseString("(output_terminal (identifier (single_identifier (simple_identifier A))))")->toString(), "Test parse output terminal");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
void test_parse_output_terminal_identifier_constant_expression() {
	AstOutputTerminalParser parser;
	assertEqual("(output_terminal (identifier (single_identifier (simple_identifier A))) (constant_expression (constant_primary (number (unsigned_number 2)))))", parser.parseString("(output_terminal (identifier (single_identifier (simple_identifier A))) [(constant_expression (constant_primary (number (unsigned_number 2)))) ])")->toString(), "Test parse output terminal");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
	
void test_parse_input_terminal_expression() {
	AstInputTerminalParser parser;
	assertEqual("(input_terminal (expression (primary (identifier (single_identifier (simple_identifier B))))))", parser.parseString("(input_terminal (expression (primary (identifier (single_identifier (simple_identifier B))))))")->toString(), "Test parse input terminal expression");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
	
void test_parse_n_input_gate_instance_output_terminal_input_terminal() {
}

void test_parse_n_input_gate_instance_output_terminal_input_terminal_star() {
}
void test_parse_n_input_gate_instance_name_of_gate_instance_output_terminal_input_terminal() {
}
void test_parse_n_input_gate_instance_name_of_gate_instance_output_terminal_input_terminal_star() {
	AstNInputGateInstanceParser parser;
    assertEqual("(n_input_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NAND2_1)))) (output_terminal (identifier (single_identifier (simple_identifier N10)))) (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N3)))))))", parser.parseString("(n_input_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NAND2_1)))) ( (output_terminal (identifier (single_identifier (simple_identifier N10)))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N1)))))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N3)))))) ))")->toString(), "Test parse n input gate instance");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

#endif

#if 0
void test_parse_n_output_gate_instance_name_of_gate_instance_output_terminal_star_input_terminal() {
	assertEqual("(n_output_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1)))) (output_terminal (identifier (single_identifier (simple_identifier N118)))) (output_terminal (identifier (single_identifier (simple_identifier N1)))) (output_terminal (identifier (single_identifier (simple_identifier N2)))) (input_terminal (identifier (single_identifier (simple_identifier N3)))))", parser.parseString("(n_output_gate_instance (name_of_gate_instance (identifier (single_identifier (simple_identifier NOT1_1)))) ( (o    utput_terminal (identifier (single_identifier (simple_identifier N118)))) , (output_terminal (identifier (single_identifier (simple_identifier N1)))) , (output_ter    minal (identifier (single_identifier (simple_identifier N2)))) , (input_terminal (expression (primary (identifier (single_identifier (simple_identifier N3)))))) ))")->toString(), "Test parse n output gate instance");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
#endif


int main() {
	test_parse_unsigned_number();
	test_parse_binary_number();
	test_parse_octal_number();
    test_parse_decimal_number();
	test_parse_heximal_number();


	test_parse_number_unsigned_number();
    test_parse_number_binary_number();
	test_parse_number_octal_number();
	test_parse_number_decimal_number();
	test_parse_number_heximal_number();


	test_parse_simple_identifier();
	test_parse_single_identifier_simple_identifier();
    test_parse_zero_or_more_dot_single_identifier();
    test_parse_multi_identifier();
	test_parse_identifer();
	
    test_parse_primary_number();
	test_parse_primary_identifier();
	test_parse_expression_primary();
	test_parse_expression_primary_select_identifier();

    test_parse_unary_expression();
	test_parse_expression_unary_expression();
	test_parse_expression_binary_expression();
	test_parse_braced_expression();
    test_parse_expression_braced_expression();
	test_parse_expression_ternary_expression();

    test_parse_bit_select();
    test_parse_range_select();
    test_parse_select();
    test_parse_one_or_more_select();
    test_parse_select_identifier();

	test_parse_primary_select_identifier();
    test_parse_one_or_more_comma_expression();
	test_parse_concatenation();
	test_parse_multiple_concatenation();
	test_parse_primary_concatenation();
    test_parse_primary_multiple_concatenation();
	
    test_parse_constant_primary_number();
	test_parse_constant_primary_identifier();
	test_parse_constant_primary_concatenation();
	test_parse_constant_primary_multiple_concatenation();


	test_parse_constant_expression_primary();
	test_parse_constant_expression_expression();
	test_parse_constant_expression_unary_constant_expression();
	test_parse_constant_expression_binary_op();
	test_parse_constant_expression_ternary_op();
	
    test_parse_range();

	test_parse_net_lvalue_identifier();
	test_parse_net_lvalue_bit_select();
	test_parse_net_lvalue_range_select();
	test_parse_net_lvaue_concatenation();

	test_parse_net_assignment();
    test_parse_zero_or_more_comma_net_assignment();
	test_parse_list_of_net_assignment(); 
    test_parse_continuous_assign();

	test_parse_reg_lvalue_identifier();
	test_parse_reg_lvalue_select_identifier();
	test_parse_reg_lvalue_concatenation();
	test_parse_blocking_assignment();

    test_parse_name_of_gate_instance();
    test_parse_input_terminal();
    test_parse_output_terminal();
    test_parse_n_input_gate_instance();
    test_parse_n_output_gate_instance();
    test_parse_gate_instantiation();

    test_parse_non_blocking_assignment();

    test_parse_statement_blocking_assignment();
    test_parse_statement_non_blocking_assignment();
    test_parse_statement_procedural_continuous_assignment();

    test_parse_procedural_timing_control_statement();
    test_parse_condtional_statement();
    test_parse_case_statement();
    test_parse_loop_statement();
    test_parse_module_instantiation();
    test_parse_module_item_declaration();
    test_parse_module_item();
    test_parse_module_declaration();
#if 0

	test_parse_name_of_gate_instance_identifier();
	test_parse_name_of_gate_instance_identifier_range();
	
	test_parse_output_terminal_identifier();
	test_parse_output_terminal_identifier_constant_expression();
	
	test_parse_input_terminal_expression();

	// TODO (chiahsun) Unfinished test case
    // test_parse_n_input_gate_instance_output_terminal_input_terminal();
    // test_parse_n_input_gate_instance_output_terminal_input_terminal_star();
    // test_parse_n_input_gate_instance_name_of_gate_instance_output_terminal_input_terminal();
	
	test_parse_n_input_gate_instance_name_of_gate_instance_output_terminal_input_terminal_star();
#endif
//	test_parse_n_output_gate_instance_name_of_gate_instance_output_terminal_star_input_terminal();
#if 0
	test_parse_n_output_gate_instance();
#endif

	return 0;
}
#if 0

void test_parse_colon_expression() {
    AstColonExpressionParser parser;
    assertEqual("(color_expression (expression (primary (identifier (single_identifier (simple_identifier reg_a))))))", parser.parseString("(none : (expression (primary (identifier (single_identifier (simple_identifier reg_a))))))")->toString(), "Test parse colon expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

#endif

	
// bad ([ ( 
// good ( [(
// assertEqual("(net_lvalue (net_lvalue_range_select (identifier (single_identifier (simple_identifier A)))(identifier A) (constant_expression (constant_primary (number (unsigned_number 1)))) (constant_expression (constant_primary (number (unsigned_number 0))))))", parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))) [ (constant_expression (constant_primary (number (unsigned_number 1)))) : (constant_expression (constant_primary (number (unsigned_number 0)))) ])")->toString(), "Test parse net lvalue identifier");
// assertEqual("(net_lvalue (net_lvalue_range_select (identifier (single_identifier (simple_identifier A)))(identifier A) (constant_expression (constant_primary (number (unsigned_number 1)))) (constant_expression (constant_primary (number (unsigned_number 0))))))", parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))) [ (constant_expression (constant_primary (number (unsigned_number 1)))) : (constant_expression (constant_primary (number (unsigned_number 0))))] )")->toString(), "Test parse net lvalue identifier");
