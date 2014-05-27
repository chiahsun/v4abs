#include "AstParser.h"
#include "test/UnitTest.h"

void test_parse_module_keyword() {
    AstModuleKeywordParser parser;
    assertEqual("(module_keyword (keyword_module module))",parser.parseString("(module_keyword (keyword_module module )")->toString(), "Test parse module keyword");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_list_of_ports() {
    AstListOfPortsParser parser;
    assertEqual("(list_of_ports (port (port_expression (port_reference (identifier (single_identifier (simple_identifier clock)))))) (zero_or_more_comma_port (port (port_expression (port_reference (identifier (single_identifier (simple_identifier reset)))))) (port (port_expression (port_reference (identifier (single_identifier (simple_identifier round_or_priority)))))) (port (port_expression (port_reference (identifier (single_identifier (simple_identifier request)))))) (port (port_expression (port_reference (identifier (single_identifier (simple_identifier priority)))))) (port (port_expression (port_reference (identifier (single_identifier (simple_identifier grant))))))))", parser.parseString("(list_of_ports ( (port (port_expression (port_reference (identifier (single_identifier     (simple_identifier clock)))))) , (port (port_expression (port_reference (identifier (single_identifier (simple_identifier     reset)))))) , (port (port_expression (port_reference (identifier (single_identifier (simple_identifier round_or_priority    )))))) , (port (port_expression (port_reference (identifier (single_identifier (simple_identifier request)))))) , (port (    port_expression (port_reference (identifier (single_identifier (simple_identifier priority)))))) , (port (port_expression     (port_reference (identifier (single_identifier (simple_identifier grant)))))) ))")->toString(), "Test parse list of ports");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_item1() {
    AstModuleItemParser parser;
    assertEqual("(module_item (module_item_declaration (integer_declaration (keyword_integer integer) (list_of_register_identifiers (register_name (identifier (single_identifier (simple_identifier i))) (zero_or_more_register_name_range)) (zero_or_more_comma_register_name (register_name (identifier (single_identifier (simple_identifier k))) (zero_or_more_register_name_range)))))))", parser.parseString("(module_item (module_item_declaration (integer_declaration (keyword_integer integer ) (list_of_register_identifiers (register_name (identifier (single_identifier (simple_identifier i)))) , (register_name (identifier (single_identifier (simple_identifier k))))) ;)))")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_module_item2() {
    AstModuleItemParser parser;
    assertEqual("(module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier NUMUNITS))) (expression (primary (number (unsigned_number 9))))) (zero_or_more_comma_param_assignment)))))", parser.parseString("(module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter ) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier NUMUNITS))) = (expression (primary (number (unsigned_number 9)))))) ;)))")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_zero_or_more_module_item() {
    AstZeroOrMoreModuleItemParser parser;
    assertEqual("(zero_or_more_module_item (module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier NUMUNITS))) (expression (primary (number (unsigned_number 9))))) (zero_or_more_comma_param_assignment))))))", parser.parseString("(zero_or_more_module_item (module_item (module_item_declaration (parameter_declaration (keyword_parameter parameter ) (list_of_param_assignments (param_assignment (identifier (single_identifier (simple_identifier NUMUNITS))) = (expression (primary (number (unsigned_number 9)))))) ;))))")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_parse_endmodule() {
    AstKeywordEndmoduleParser parser;
    assertEqual("(keyword_endmodule endmodule)", parser.parseString("(keyword_endmodule \nendmodule\n)")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
/*
void test_parse_module_item2() {
    AstModuleItemParser parser;
    assertEqual("", parser.parseString("")->toString(), "Test parse module item");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
*/

int main() {
    test_parse_module_keyword();
    test_parse_list_of_ports();
    test_parse_module_item1();
    test_parse_module_item2();
    test_parse_zero_or_more_module_item();
    test_parse_endmodule();

    return 0;
}
