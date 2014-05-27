#!/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python

import sys
import argparse 
import utility
import acceptor
import acceptor_types
import generate_composite_with_name

def get_acceptor_from_file(tcl_filename):
    with open(tcl_filename) as f:
        content = utility.readlines_strip_end_line(f)
        rule_name = content[0]
        token_name = content[1]
        handle_name = content[2]
        ctor_name = content[3]
        composite_rule_list = []
        for line in content[4::]:
            strings = line.split()
            if len(strings) != 1:
                print "Error: composite rule should use one single rule line in ", tcl_filename
                print strings
                exit(2)
            composite_rule_list.append(strings)

    return composite_acceptor_without_name(token_name, handle_name, ctor_name, composite_rule_list)


class composite_acceptor_without_name(generate_composite_with_name.composite_acceptor_with_name):

    def __init__(self, token_name, handle_name, ctor_name, composite_rule_list):
        generate_composite_with_name.composite_acceptor_with_name.__init__(self, token_name = token_name, handle_name = handle_name, ctor_name = ctor_name, composite_rule_list = composite_rule_list)

    def get_acceptor_name(self):
        return "composite_acceptor_without_name"
 
    def has_name(self):
        return False

    def generate_parser_cpp(self):
        content = ( "bool %s::parsePos(\n"
                    "    %s & %s\n"
                    "  , unsigned int & pos)\n {\n\n" ) %(self.get_parser_name()
                            , self.get_handle_type_name(), self.get_handle_name())

        content += "    unsigned int old_pos = pos;\n\n"

        for rule_list in self.get_composite_rule_list():
            for rule in rule_list:
                if acceptor_types.is_punct_rule(rule):
                    content += ("    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == \"%s\") {\n"
                                "        ++pos;\n"
                                "    } else {\n"
                                "        pos = old_pos;\n"
                                "    }\n\n") %(rule)

                else:
                    acc = acceptor_types.get_acceptor_from_file(rule)
                    content += ("    %s %s;\n") %(acc.get_handle_type_name(), acc.get_handle_name_with_pos(0))
                    content += acc.accept_by(self.get_handle_name(), self.get_ctor_name(), 0)
                    content += ("    } else {\n"
                                "        pos = old_pos;\n"
                                "    }\n")
                    content += ("    if (pos != old_pos) {\n"
                                "        %s = %s(%s(%s));\n"
                                "        return true;\n"
                                "    }\n") %(self.get_handle_name(), self.get_handle_type_name(), self.get_ctor_name(), acc.get_handle_name_with_pos(0))
        content += ("    reportChild();\n"
                    "    throw InvalidFormatException(\"Not valid option in composite rule without name\");\n"
                    "}\n\n")

        return content
                    
        

def print_tcl_parser_header(tcl_filename):
    acc = get_acceptor_from_file(tcl_filename) 
    print acc.generate_parser_header()

def print_tcl_ast_header_handle_declaration(tcl_filename):
    acc = get_acceptor_from_file(tcl_filename) 
    print acc.generate_ast_header_handle_declaration()

def print_tcl_parser_cpp(tcl_filename):
    acc = get_acceptor_from_file(tcl_filename) 
    print acc.generate_parser_cpp()

def print_tcl_ast_header(tcl_filename):
    acc = get_acceptor_from_file(tcl_filename) 
    print acc.generate_ast_header()

def print_tcl_ast_cpp(tcl_filename):
    acc = get_acceptor_from_file(tcl_filename) 
    print acc.generate_ast_cpp()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Ast parser generator")
    parser.add_argument('-tph', '--tcl-parser-header', help="Print parser header content from given tcl", required=False)
    parser.add_argument('-tphhd', '--tcl-ast-header-handle-declaration', help="Print parser header handle declaration from given tcl", required=False)
    parser.add_argument('-tpc', '--tcl-parser-cpp', help="Print parser cpp content from given tcl", required=False)
    parser.add_argument('-tah', '--tcl-ast-header', help='Print parser ast header content from given tcl', required=False)
    parser.add_argument('-tac', '--tcl-ast-cpp', help='Print parser ast cpp content from given tcl', required=False)

    args = vars(parser.parse_args())
    
    if args['tcl_parser_header'] is not None:
        print_tcl_parser_header(args['tcl_parser_header'])
    if args['tcl_ast_header_handle_declaration'] is not None:
        print_tcl_ast_header_handle_declaration(args['tcl_ast_header_handle_declaration'])
    if args['tcl_parser_cpp'] is not None:
        print_tcl_parser_cpp(args['tcl_parser_cpp'])
    if args['tcl_ast_header'] is not None:
        print_tcl_ast_header(args['tcl_ast_header']);
    if args['tcl_ast_cpp'] is not None:
        print_tcl_ast_cpp(args['tcl_ast_cpp']);

