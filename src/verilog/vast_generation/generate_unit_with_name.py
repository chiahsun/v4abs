#!/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python

import sys
import argparse 
import utility
import acceptor
import config

def get_acceptor_from_file(tcl_filename):
    with open(tcl_filename) as f:
        content = utility.readlines_strip_end_line(f)
        python_file_name = content[0] 
        token_name = content[1]
        handle_name = content[2]
        ctor_name = content[3]
    return unit_acceptor(token_name, handle_name, ctor_name)


class unit_acceptor(acceptor.acceptor_base):

    def __init__(self, token_name, handle_name, ctor_name):
        acceptor.acceptor_base.__init__(self, token_name = token_name, handle_name = handle_name, ctor_name = ctor_name)

    def get_acceptor_name(self):
        return "unit_acceptor"

    def has_name(self):
        return True

    def generate_parser_cpp(self):
        return ( "bool %s::parse(%s & %s) {\n"
                 "    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {\n"
                 "        %s = %s(%s(getTokenChild(0)->name()));\n"
                 "        return true;\n"
                 "    }\n"
                 "    return false;\n"
#                "    reportChild();\n"
#                "    throw InvalidFormatException(\"Unknown structure\");\n"
                "}") %(self.get_parser_name(), self.get_handle_type_name(), self.get_handle_name()
                , self.get_handle_name(), self.get_handle_type_name(), self.get_ctor_name()
                )

    def generate_header(self):
        return ( "class %s: public %sBase<%s> {\n"
                 "public:\n"
                 "    %s() { }\n"
                 "    %s(TokenStructureHandle pTokenStructure, TokenHandle pToken)\n"
                 "      { initFromToken(pTokenStructure, pToken); }\n"
                 "    bool parse(%s & %s);\n"
                 "    std::string getTokenName() const\n"
                 "      { return \"%s\"};\n}" ) % (self.get_parser_name(), config.name_ast_parser
                         , self.get_ctor_name(), self.get_handle_name(), self.get_parser_name(), self.get_handle_type_name(), self.get_handle_name(), self.get_token_name())

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

