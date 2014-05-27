#!/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python

import acceptor_types
import generate_base
import config

def try_open_file_desciptor(filename):
    try:
        f = open(filename, 'w')
        return f 
    except:
        print 'Error : Fail open %s to write' %(filename)
        exit(2)


name_parser_header = config.name_parser_header 
name_parser_cpp = config.name_parser_cpp
name_ast_header = config.name_ast_header
name_ast_cpp = config.name_ast_cpp
name_generate_base = config.name_generate_base
name_generate_unit = config.name_generate_unit

file_parser_header = try_open_file_desciptor(name_parser_header)
file_parser_cpp = try_open_file_desciptor(name_parser_cpp)
file_ast_header = try_open_file_desciptor(name_ast_header)
file_ast_cpp = try_open_file_desciptor(name_ast_cpp)



def get_python_file_from_tcl(tcl_filename):
    try:
        with open(tcl_filename, 'r') as f:
            str = f.readline()
            return "./" + str[:len(str)-1:]
    except:
        print "Error: Fail to open %s" %(tcl_filename)
        exit(2)


tcl_list = [ 'unsigned_number.tcl'
           , 'binary_number.tcl'
           , 'octal_number.tcl'
           , 'decimal_number.tcl'
           , 'heximal_number.tcl'
           , 'number.tcl'
           , 'simple_identifier.tcl'
           , 'single_identifier.tcl'
           , 'zero_or_more_dot_single_identifier.tcl'
           , 'multi_identifier.tcl'
           , 'identifier.tcl'
           , 'primary.tcl'
           , 'expression.tcl'
           , 'unary_operator.tcl'
           
           , 'unary_operator_plus.tcl'
           , 'unary_operator_minus.tcl'
           , 'unary_operator_not.tcl'
           , 'unary_operator_neg.tcl'
           , 'unary_operator_and.tcl'
           , 'unary_operator_neg_and.tcl'
           , 'unary_operator_or.tcl'
           , 'unary_operator_neg_or.tcl'
           , 'unary_operator_xor.tcl'
           , 'unary_operator_neg_xor.tcl'
           , 'unary_operator_xor_neg.tcl'

           , 'unary_expression.tcl'
           , 'braced_expression.tcl'
           , 'binary_operator.tcl'

           , 'binary_operator_plus.tcl'
           , 'binary_operator_minus.tcl'
           , 'binary_operator_asterisk.tcl'
           , 'binary_operator_slash.tcl'
           , 'binary_operator_percent.tcl'
           , 'binary_operator_equal_equal.tcl'
           , 'binary_operator_not_equal.tcl'
           , 'binary_operator_triple_equal.tcl'
           , 'binary_operator_not_equal_equal.tcl'
           , 'binary_operator_and_and.tcl'
           , 'binary_operator_or_or.tcl'
           , 'binary_operator_lt.tcl'
           , 'binary_operator_leq.tcl'
           , 'binary_operator_gt.tcl'
           , 'binary_operator_geq.tcl'
           , 'binary_operator_and.tcl'
           , 'binary_operator_or.tcl'
           , 'binary_operator_xor.tcl'
           , 'binary_operator_xor_neg.tcl'
           , 'binary_operator_neg_xor.tcl'
           , 'binary_operator_shr.tcl'
           , 'binary_operator_shl.tcl'

           , 'binary_expression_multiply.tcl'
           , 'binary_expression_divide.tcl'
           , 'binary_expression_modulus.tcl'
           , 'binary_expression_plus.tcl'
           , 'binary_expression_minus.tcl'
           , 'binary_expression_shift_left.tcl'
           , 'binary_expression_shift_right.tcl'
           , 'binary_expression_gt.tcl'
           , 'binary_expression_geq.tcl'
           , 'binary_expression_lt.tcl'
           , 'binary_expression_leq.tcl'
           , 'binary_expression_eq.tcl'
           , 'binary_expression_neq.tcl'
           , 'binary_expression_case_eq.tcl'
           , 'binary_expression_case_neq.tcl'
           , 'binary_expression_bw_and.tcl'
           , 'binary_expression_bw_xor.tcl'
           , 'binary_expression_bw_xnor.tcl'
           , 'binary_expression_bw_nxor.tcl'
           , 'binary_expression_bw_or.tcl'
           , 'binary_expression_lg_or.tcl'
           , 'binary_expression_lg_and.tcl'
           , 'binary_expression.tcl'
           , 'binary_constant_expression_multiply.tcl'
           , 'binary_constant_expression_divide.tcl'
           , 'binary_constant_expression_modulus.tcl'
           , 'binary_constant_expression_plus.tcl'
           , 'binary_constant_expression_minus.tcl'
           , 'binary_constant_expression_shift_left.tcl'
           , 'binary_constant_expression_shift_right.tcl'
           , 'binary_constant_expression_gt.tcl'
           , 'binary_constant_expression_geq.tcl'
           , 'binary_constant_expression_lt.tcl'
           , 'binary_constant_expression_leq.tcl'
           , 'binary_constant_expression_eq.tcl'
           , 'binary_constant_expression_neq.tcl'
           , 'binary_constant_expression_case_eq.tcl'
           , 'binary_constant_expression_case_neq.tcl'
           , 'binary_constant_expression_bw_and.tcl'
           , 'binary_constant_expression_bw_xor.tcl'
           , 'binary_constant_expression_bw_xnor.tcl'
           , 'binary_constant_expression_bw_nxor.tcl'
           , 'binary_constant_expression_bw_or.tcl'
           , 'binary_constant_expression_lg_or.tcl'
           , 'binary_constant_expression_lg_and.tcl'
           , 'ternary_expression.tcl'
           , 'bit_select.tcl'
           , 'range_select.tcl'
           , 'select.tcl'
           , 'one_or_more_select.tcl'
           , 'select_identifier.tcl'
           , 'one_or_more_comma_expression.tcl'
           , 'concatenation.tcl'
           , 'multiple_concatenation.tcl'
           , 'zero_or_more_comma_expression.tcl'
           , 'constant_primary.tcl'
           , 'braced_constant_expression.tcl'
           , 'unary_constant_expression.tcl'
           , 'binary_constant_expression.tcl'
           , 'ternary_constant_expression.tcl'
           , 'constant_expression.tcl'
#           , 'zero_or_one_colon_expression.tcl'
           , 'range.tcl'
           , 'net_lvalue_range_select.tcl'
           , 'net_lvalue_bit_select.tcl'
           , 'net_lvalue.tcl'
           , 'keyword_assign.tcl'
           , 'net_assignment.tcl'
           , 'zero_or_more_comma_net_assignment.tcl'
           , 'list_of_net_assignments.tcl'
           , 'continuous_assign.tcl'
           , 'reg_lvalue.tcl'
           , 'blocking_assignment.tcl'
           , 'zero_or_one_range.tcl'
           , 'name_of_gate_instance.tcl'
           , 'zero_or_one_name_of_gate_instance.tcl'

           , 'zero_or_one_constant_bit_select.tcl'
           , 'constant_bit_select.tcl'
           , 'output_terminal.tcl'
           , 'input_terminal.tcl'
           , 'zero_or_more_comma_input_terminal.tcl'
           , 'n_input_gate_instance.tcl'
           , 'zero_or_more_comma_output_terminal.tcl'
           , 'n_output_gate_instance.tcl'
           , 'zero_or_more_comma_n_input_gate_instance.tcl'
           , 'zero_or_more_comma_n_output_gate_instance.tcl'
           , 'gate_instantiation_input.tcl'
           , 'n_input_gatetype.tcl'
           , 'n_output_gatetype.tcl'
           , 'gate_instantiation_output.tcl'
           , 'gate_instantiation.tcl'

           , 'non_blocking_assignment.tcl'

           , 'statement.tcl'
           , 'blocking_assignment_semicolon.tcl'
           , 'non_blocking_assignment_semicolon.tcl'

           , 'reg_assignment.tcl'
           , 'procedural_continuous_assignment.tcl'
           , 'procedural_continuous_assignment_semicolon.tcl'

           , 'keyword_or.tcl'
           , 'keyword_negedge.tcl'
           , 'keyword_posedge.tcl'
           , 'statement_or_null.tcl'
           , 'event_expression.tcl'
           , 'event_or_asterisk.tcl'
           , 'event_or_event.tcl'
           , 'event_comma_event.tcl'
           , 'posedge_expression.tcl'
           , 'negedge_expression.tcl'
           , 'at_event_or_asterisk.tcl'
           , 'at_identifier.tcl'
           , 'at_event_expression.tcl'
           , 'at_asterisk.tcl'
           , 'event_control.tcl'
           , 'statement_or_null.tcl'
           , 'delay_or_event_control.tcl'
           , 'procedural_timing_control_statement.tcl'
          
           , 'keyword_if.tcl'
           , 'keyword_else.tcl'
           , 'else_statement_or_null.tcl'
           , 'zero_or_one_else_statement_or_null.tcl'
           , 'conditional_statement.tcl'

           , 'keyword_begin.tcl'
           , 'keyword_end.tcl'
           , 'zero_or_more_statement.tcl'
           , 'seq_block.tcl'

           , 'keyword_case.tcl'
           , 'keyword_endcase.tcl'
           , 'keyword_default.tcl'
           , 'case_item_item.tcl'
           , 'case_item_default.tcl'
           , 'case_item.tcl'
           , 'one_or_more_case_item.tcl'
           , 'case_statement.tcl'

           , 'keyword_for.tcl'
           , 'loop_statement.tcl'

           , 'zero_or_one_expression.tcl'
           , 'named_port_connection.tcl'
           , 'ordered_port_connection.tcl'
           , 'zero_or_more_comma_named_port_connection.tcl'
           , 'zero_or_more_comma_ordered_port_connection.tcl'
           , 'list_of_named_port_connection.tcl'
           , 'list_of_ordered_port_connection.tcl'
           , 'list_of_module_connections.tcl'
           , 'name_of_instance.tcl'
           , 'zero_or_one_list_of_module_connections.tcl'
           , 'module_instance.tcl'
           , 'zero_or_more_comma_module_instance.tcl'
           , 'module_instantiation.tcl'

           , 'zero_or_more_register_name_range.tcl'
           , 'register_name.tcl'
           , 'zero_or_more_comma_register_name.tcl'
           , 'list_of_register_identifiers.tcl'

           , 'keyword_parameter.tcl'
           , 'keyword_input.tcl'
           , 'keyword_output.tcl'
           , 'keyword_inout.tcl'
           , 'keyword_wire.tcl'
           , 'keyword_reg.tcl'
           , 'keyword_integer.tcl'
           , 'reg_declaration.tcl'
           , 'integer_declaration.tcl'

           , 'zero_or_more_comma_identifier.tcl'
           , 'list_of_net_identifier.tcl'
           , 'net_type.tcl'
           , 'net_declaration.tcl'
           , 'list_of_port_identifiers.tcl'
           , 'input_declaration.tcl'
           , 'output_declaration.tcl'
           , 'inout_declaration.tcl'

           , 'param_assignment.tcl'
           , 'list_of_param_assignments.tcl'
           , 'parameter_declaration.tcl'
           , 'zero_or_more_comma_param_assignment.tcl'
           , 'module_item_declaration.tcl'

           , 'keyword_always.tcl'
           , 'keyword_initial.tcl'
           , 'initial_construct.tcl'
           , 'always_construct.tcl'
           , 'module_item.tcl'

           , 'keyword_module.tcl'
           , 'keyword_macro_module.tcl'
           , 'keyword_endmodule.tcl'

           , 'zero_or_more_module_item.tcl'
           , 'zero_or_one_list_of_ports.tcl'
           , 'module_keyword.tcl'
           , 'module_declaration.tcl'

           , 'constant_range_select.tcl'
           , 'constant_range_select_identifier.tcl'
           , 'constant_bit_select_identifier.tcl'
           , 'port_reference.tcl'
           , 'port.tcl'
           , 'port_expression.tcl'
           , 'zero_or_more_comma_port_reference.tcl'
           , 'zero_or_one_port_expression.tcl'
           , 'list_of_port_references.tcl'
           , 'named_port_expression.tcl'
           , 'zero_or_more_comma_port.tcl'
           , 'list_of_ports.tcl'

           , 'description.tcl'
           , 'one_or_more_description.tcl'
           , 'source_text.tcl'
           ]


acc_list = {} 

for tcl in tcl_list:
    print "tcl : ", tcl
    acc_list[tcl] = acceptor_types.get_acceptor_from_tcl_file_name(tcl) 

file_parser_header.write(generate_base.string_of_header_top())
for acc in acc_list.values():
    file_parser_header.write(acc.generate_parser_header())
file_parser_header.write(generate_base.string_of_header_bottom())

file_parser_cpp.write(generate_base.string_of_cpp_top())
for acc in acc_list.values():
    file_parser_cpp.write(acc.generate_parser_cpp())

file_ast_header.write(generate_base.string_of_ast_header_top())
for acc in acc_list.values():
    file_ast_header.write(acc.generate_ast_header_handle_declaration())
for acc in acc_list.values():
    file_ast_header.write(acc.generate_ast_header())
file_ast_header.write(generate_base.string_of_ast_header_bottom())

file_ast_cpp.write(generate_base.string_of_ast_cpp_top())
for acc in acc_list.values():
    file_ast_cpp.write(acc.generate_ast_cpp())

