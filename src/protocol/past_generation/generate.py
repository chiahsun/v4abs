#!/usr/bin/env python
#  !/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python
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

tcl_list = [ 'keyword_read.tcl',
             'keyword_write.tcl',
             'keyword_check.tcl',
             'keyword_assert.tcl',
             'keyword_else.tcl',
             'keyword_goto.tcl',
             'keyword_if.tcl',
             'keyword_false.tcl',
             'keyword_true.tcl',
             'identifier.tcl',
             'bit_literal.tcl',
             'integer_literal.tcl',
             'floating_literal.tcl',
             'assert_statement.tcl',
             'constant.tcl',
             'state_label.tcl',
             'goto_statement.tcl',
             'read_statement.tcl',
             'write_statement.tcl',
             'bool_with_parenthesis.tcl',
             'bool_and.tcl',
             'bool_or.tcl',
             'bool_xor.tcl',
             'bool_not.tcl',
             'bool_constant.tcl',
             'bool_expression.tcl',
             'check_statement.tcl',
             'read_or_write_or_check_statement.tcl',
             'zero_or_more_rwc.tcl',
             'if_statement_prefix.tcl',
             'end_statement.tcl',
             'only_rwc_without_goto.tcl',
             'only_without_goto_without_goto.tcl',
             'rwc_or_without_goto.tcl',
             'zero_or_more_rwc_or_without_goto.tcl',
             'specific_update_statement.tcl',
             'all_update_statement.tcl',
             'multi_without_goto.tcl',
             'if_statement_without_goto.tcl',
             'only_end_with_goto.tcl',
             'zero_or_more_specific.tcl',
             'multi_with_goto.tcl',
             'if_statement_with_goto.tcl',
             'specific_end.tcl',
             'zero_or_more_all.tcl',
             'all_if_with_goto.tcl',
             'edge_statement.tcl',
             'all_or_edge.tcl',
             'zero_or_more_all_or_edge.tcl',
             'one_or_more_edge.tcl',
             'transition_statement.tcl',
             'state_statement.tcl',
             'one_or_more_state.tcl',
             'source_text.tcl',
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

