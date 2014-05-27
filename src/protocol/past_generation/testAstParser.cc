#include "CAstParser.h"
#include "test/UnitTest.h"

void test_parse_integer_literal() {
    CAstIntegerLiteralParser parser;

    assertEqual("(integer_literal 0)", parser.parseString("(integer_literal 0)")->toString(), "Test parse integer literal");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();   
}

void test_parse_floating_literal() {
    CAstFloatingLiteralParser parser;

    assertEqual("(floating_literal 10.1)", parser.parseString("(floating_literal 10.1)")->toString(), "Test parse floating literal");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_bit_literal() {
    CAstBitLiteralParser parser;

    assertEqual("(bit_literal 2'b11)", parser.parseString("(bit_literal 2'b11)")->toString(), "Test parse bit literal");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_constant() {
    CAstConstantParser parser;

    assertEqual("(constant (integer_literal 0))", parser.parseString("(constant (integer_literal 0))")->toString(), "Test parse constant");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(constant (floating_literal 0.1))", parser.parseString("(constant (floating_literal 0.1))")->toString(), "Test parse constant");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(constant (bit_literal 2'b11))", parser.parseString("(constant (bit_literal 2'b11))")->toString(), "Test parse constant");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_assert_statement() {
    CAstAssertStatementParser parser;

    assertEqual("(assert_statement (integer_literal 0))", parser.parseString("(assert_statement assert ( (integer_literal 0) ) ;)")->toString(), "Test assert statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_state_label() {
    CAstStateLabelParser parser;

    assertEqual("(state_label (identifier s0))", parser.parseString("(state_label (identifier s0) :)")->toString(), "Test state label");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_goto_statement() {
    CAstGotoStatementParser parser;

    assertEqual("(goto_statement (identifier s1))", parser.parseString("(goto_statement goto  (identifier s1) ;)")->toString(), "Test goto statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_read_statement() {
    CAstReadStatementParser parser;

    assertEqual("(read_statement (identifier y))", parser.parseString("(read_statement read ( (identifier y) ) ;)")->toString(), "Test read statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_write_statement() {
    CAstWriteStatementParser parser;
    
    assertEqual("(write_statement (identifier y))", parser.parseString("(write_statement write ( (identifier y) ) ;)")->toString(), "Test write statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_bool_expression() {
    CAstBoolExpressionParser parser;

    assertEqual("(bool_expression (bool_with_parenthesis (bool_expression (identifier reset))))", parser.parseString("(bool_expression ( (bool_expression (identifier reset)) ))")->toString(), "TEST");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (bool_and (bool_expression (identifier a)) (bool_expression (identifier b))))", parser.parseString("(bool_expression (bool_expression (identifier a)) & & (bool_expression (identifier b)))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (bool_or (bool_expression (identifier a)) (bool_expression (identifier b))))", parser.parseString("(bool_expression (bool_expression (identifier a)) | | (bool_expression (identifier b)))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (bool_xor (bool_expression (identifier a)) (bool_expression (identifier b))))", parser.parseString("(bool_expression (bool_expression (identifier a)) ^ (bool_expression (identifier b)))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (bool_not (bool_expression (identifier a))))", parser.parseString("(bool_expression ! (bool_expression (identifier a)))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (bool_constant (identifier a) (constant (integer_literal 0))))", parser.parseString("(bool_expression (identifier a) = (constant (integer_literal 0)))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(bool_expression (identifier reset))", parser.parseString("(bool_expression (identifier reset))")->toString(), "Test bool expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_check_statement() {
    CAstCheckStatementParser parser;

    assertEqual("(check_statement (bool_expression (bool_not (bool_expression (identifier in_en)))))", parser.parseString("(check_statement check  ( (bool_expression ! (bool_expression (identifier in_en))) ) ;)")->toString(), "Test check statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_rwc_statement() {
    CAstReadOrWriteOrCheckStatementParser parser;

    assertEqual("(read_or_write_or_check_statement (read_statement (identifier Din)))", parser.parseString("(read_or_write_or_check_statement (read_statement read  ( (identifier Din) ) ;))")->toString(), "Test read or write or check statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(read_or_write_or_check_statement (write_statement (identifier Dout)))", parser.parseString("(read_or_write_or_check_statement (write_statement write  ( (identifier Dout) ) ;))")->toString(), "Test read or write or check statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
    assertEqual("(read_or_write_or_check_statement (check_statement (bool_expression (bool_not (bool_expression (identifier in_en))))))", parser.parseString("(read_or_write_or_check_statement (check_statement check  ( (bool_expression ! (bool_expression (identifier in_en))) ) ;))")->toString(), "Test read or write or check statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_if_statement_prefix() {
    CAstIfStatementPrefixParser parser;

    assertEqual("(if_statement_prefix (bool_expression (identifier reset)))", parser.parseString("(if_statement_prefix if ( (bool_expression (identifier reset)) ))")->toString(), "Test if statement prefix");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_if_statement_without_goto() {
    CAstIfStatementWithoutGotoParser parser;

    assertEqual("(if_statement_without_goto (only_rwc_without_goto (if_statement_prefix (bool_expression (identifier y_valid))) (read_or_write_or_check_statement (write_statement (identifier y)))))", parser.parseString("(if_statement_without_goto (if_statement_prefix if ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))")->toString(), "Test if statement without goto");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_end_statement() {
    CAstEndStatementParser parser;

    assertEqual("(end_statement (goto_statement (identifier s1)))", parser.parseString("(end_statement (goto_statement goto  (identifier s1) ;))")->toString(), "Test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_all_update_statement() {
    CAstAllUpdateStatementParser parser;

    assertEqual("(all_update_statement (if_statement_without_goto (only_rwc_without_goto (if_statement_prefix (bool_expression (identifier y_valid))) (read_or_write_or_check_statement (write_statement (identifier y))))))", parser.parseString("(all_update_statement (if_statement_without_goto (if_statement_prefix if ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;))))")->toString(), "Test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_specific_update_statement() {
    CAstSpecificUpdateStatementParser parser;

    assertEqual("(specific_update_statement (read_or_write_or_check_statement (read_statement (identifier yuv_in))))", parser.parseString("(specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;)))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_if_statement_with_goto() {
    CAstIfStatementWithGotoParser parser;

    assertEqual("(if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1)))))", parser.parseString("(if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_edge_statement() {
    CAstEdgeStatementParser parser;

    assertEqual("(edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1)))))))", parser.parseString("(edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;))))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_transition_statement() {
    CAstTransitionStatementParser parser;

    assertEqual("(transition_statement (one_or_more_edge (edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1))))))) (edge_statement (specific_end (zero_or_more_specific) (end_statement (goto_statement (identifier s2)))))))", parser.parseString("(transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier s2) ;))))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_state_statement() {
# if 1
    CAstStateStatementParser parser;

    assertEqual("(state_statement (state_label (identifier s0)) (transition_statement (one_or_more_edge (edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1))))))) (edge_statement (specific_end (zero_or_more_specific) (end_statement (goto_statement (identifier s0))))))))", parser.parseString("(state_statement (state_label (identifier s0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier s0) ;)))))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
# endif
}

void test_parse_source_text() {
# if 1
    CAstSourceTextParser parser;

    assertEqual("(source_text (one_or_more_state (state_statement (state_label (identifier s0)) (transition_statement (one_or_more_edge (edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1))))))) (edge_statement (specific_end (zero_or_more_specific) (end_statement (goto_statement (identifier s0)))))))) (state_statement (state_label (identifier s1)) (transition_statement (one_or_more_edge (edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1))))))) (edge_statement (specific_end (zero_or_more_specific) (end_statement (goto_statement (identifier s2)))))))) (state_statement (state_label (identifier s2)) (transition_statement (one_or_more_edge (edge_statement (all_if_with_goto (zero_or_more_all) (if_statement_with_goto (only_end_with_goto (if_statement_prefix (bool_expression (identifier reset))) (end_statement (goto_statement (identifier s1))))))) (edge_statement (specific_end (zero_or_more_specific (specific_update_statement (if_statement_without_goto (only_rwc_without_goto (if_statement_prefix (bool_expression (identifier y_valid))) (read_or_write_or_check_statement (write_statement (identifier y)))))) (specific_update_statement (if_statement_without_goto (only_rwc_without_goto (if_statement_prefix (bool_expression (identifier z_valid))) (read_or_write_or_check_statement (write_statement (identifier z))))))) (end_statement (goto_statement (identifier s2))))))))))", parser.parseString("(source_text (state_statement (state_label (identifier s0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier s0) ;))))) (state_statement (state_label (identifier s1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier s2) ;))))) (state_statement (state_label (identifier s2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier s1) ;)))) (edge_statement (specific_update_statement (if_statement_without_goto (if_statement_prefix if ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))) (specific_update_statement (if_statement_without_goto (if_statement_prefix if ( (bool_expression (identifier z_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier z) ) ;)))) (end_statement (goto_statement goto  (identifier s2) ;))))))")->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
# endif
}

int main() {
    test_parse_integer_literal();
    test_parse_floating_literal();
    test_parse_bit_literal();
    test_parse_constant();
    test_parse_assert_statement();
    test_parse_state_label();
    test_parse_goto_statement();
    test_parse_read_statement();
    test_parse_write_statement();
    test_parse_bool_expression();
    test_parse_check_statement();
    test_parse_rwc_statement();
    test_parse_if_statement_prefix();
    test_parse_if_statement_without_goto();
    test_parse_end_statement();
    test_parse_all_update_statement();
    test_parse_specific_update_statement();
    test_parse_if_statement_with_goto();
    test_parse_edge_statement();
    test_parse_transition_statement();
    test_parse_state_statement();
    test_parse_source_text();

    return 0;
}
