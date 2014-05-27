#!/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python

import sys
import argparse 
import utility
import acceptor
import acceptor_types
import config

def get_acceptor_from_file(tcl_filename):
    with open(tcl_filename) as f:
        content = utility.readlines_strip_end_line(f)
        python_file_name = content[0] 
        token_name = content[1]
        handle_name = content[2]
        ctor_name = content[3]
        rule_list = content[4].split()
        if len(content) > 5:
            print "Error: star should use only one line for its star sequence in", tcl_filename
            exit(2)
    return star_acceptor_without_name(token_name, handle_name, ctor_name, rule_list)


class star_acceptor_without_name(acceptor.acceptor_base):

    def __init__(self, token_name, handle_name, ctor_name, rule_list):
        acceptor.acceptor_base.__init__(self, token_name = token_name, handle_name = handle_name, ctor_name = ctor_name)
        self.rule_list = rule_list

    def get_acceptor_name(self):
        return "star_acceptor_without_name"

    def get_rule_list(self):
        return self.rule_list

    def has_name(self):
        return False

    def accept_by(self, handle_name, ctor_name, pos):
        return ("    if (%s(getTokenStructure(), getToken()).parsePos(%s, pos)) {\n"
                "        /* do nothing */\n") %(self.get_parser_name(), self.get_handle_name_with_pos(pos))

    def get_acc_list(self):
        acc_list = []
        for rule in self.get_rule_list():
            if not acceptor_types.is_punct_rule(rule):
                acc_list.append(acceptor_types.get_acceptor_from_file(rule))
        return acc_list

    def string_of_accept_handle_with_pos(self, pos):
        return ("%s %s = %s(%s())\n") %(self.get_handle_type_name(), self.get_handle_name_with_pos(pos), self.get_handle_type_name(), self.get_ctor_name())

    def string_of_handle_call_constructor(self):
        return ("    %s = %s(%s());\n\n") %(self.get_handle_name(), self.get_handle_type_name(), self.get_ctor_name())
    
    def string_of_handle_push_back(self):
        content = ("        %s->push_back(") % (self.get_handle_name())

        pos = 0
        for acc in self.get_acc_list(): 
            if not pos == 0:
                content += ', '
            content += acc.get_handle_name_with_pos(pos)
            pos = pos + 1


        content += ( ");\n")
        return content
    
    def generate_parser_header(self):
        return self.generate_parser_header_with_pos()
    
    def generate_parser_cpp(self):
        content = ""
        content += ( "bool %s::parsePos(\n"
                     "    %s & %s\n"
                     "  , unsigned int & pos) \n{\n") %(self.get_parser_name(), self.get_handle_type_name(), self.get_handle_name())
        content += self.string_of_handle_call_constructor()
   
        pos = 0
        for acc in self.get_acc_list():
            content += "    %s %s;\n" %(acc.get_handle_type_name(), acc.get_handle_name_with_pos(pos))
            pos = pos + 1
        content += "\n"
        content += ("    while(true) {\n")
        content += ("        unsigned int old_pos = pos;\n")

        pos = 0
        for rule in self.get_rule_list():
            if acceptor_types.is_punct_rule(rule):
                content += ("        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == \"%s\") {\n"
                            "            ++pos;\n"
                            "        } else {\n"
                            "            pos = old_pos;\n"
                            "            break;\n"
                            "        }\n\n") %(rule
                        )
            else:
                acc = acceptor_types.get_acceptor_from_file(rule)
                content += acc.accept_by(self.get_handle_name(), self.get_ctor_name(), pos)
                pos = pos + 1
                content += ( "    } else {\n"
                             "        pos = old_pos;\n"
                             "        break;\n"
                             "    }\n")


        content += self.string_of_handle_push_back()
        content += ( "    }\n\n"
                     "    return true;\n")

        content += "}\n"
        return content

    def generate_ast_header(self):
        content = ( "class %s\n"
                    "  : public %s {\n") % ( self.get_ctor_name()
                                           , config.name_ast)

        content += "    struct ElementType {\n"
        pos = 0
        for acc in self.get_acc_list():
            if pos !=0:
                content += ', '
            content += ("        %s _%s;\n") %(acc.get_handle_type_name(), acc.get_handle_name())
        content += "        ElementType("
        for acc in self.get_acc_list():
            if pos !=0:
                content += ', '
            content += ("%s %s") %(acc.get_handle_type_name(), acc.get_handle_name())
        content += ") {\n"
        for acc in self.get_acc_list():
            content += ("            _%s = %s;\n") % (acc.get_handle_name(), acc.get_handle_name())
        content += "        }\n"
        content += "    };\n"
        content += "    std::vector<ElementType> _vecElements;\n"

        content += "public:\n"
        content += ("    %s();\n") %(self.get_ctor_name())
        content += ("    void push_back(")
        pos = 0
        for acc in self.get_acc_list():
            if pos !=0:
                content += ', '
            content += ("%s %s") %(acc.get_handle_type_name(), acc.get_handle_name())

        content += (");\n")
        content += acceptor.string_of_ast_header_element_method_declaration()
        return content

    def generate_ast_cpp(self):
        content = ""
        content += ("%s::%s() { }\n") %(self.get_ctor_name(), self.get_ctor_name())
        content += ("void %s::push_back(") %(self.get_ctor_name())
        pos = 0
        for acc in self.get_acc_list():
            if pos !=0:
                content += ', '
            content += ("%s %s") %(acc.get_handle_type_name(), acc.get_handle_name())

        content += (") {\n")
        content += ("    _vecElements.push_back(ElementType(")
        pos = 0
        for acc in self.get_acc_list():
            if pos != 0:
                content += ", "
            content += acc.get_handle_name()
        content += "));\n"

        content += "}\n"
        
        content += acceptor.string_of_ast_cpp_element_method_implementation(self.get_ctor_name(), self.get_token_name())

        for acc in self.get_acc_list():
            content += ("        s = s + \" \" + _vecElements[i]._%s->toString();\n") %(acc.get_handle_name())
        content += "    }\n"
        content += "        s += \")\";" 
        content += "    return s;\n"
        content += "}\n"
       
        
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

