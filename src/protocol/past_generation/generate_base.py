#!/home/chiahsun/tools-common/build/leda/python_versions/path/bin/python

import sys
import argparse 
import config

def strip_end_line(str):
    if (str[len(str)-1] == '\n'):
        return str[:len(str)-1:]

def readlines_strip_end_line(f):
    lines = []
    for line in f:
        lines.append(strip_end_line(line))
    return lines

def print_header_top():
    print string_of_header_top()

def string_of_header_top():
    return ("#ifndef %s_H\n"
            "#define %s_H\n"
            "#include \"utility/parser/StringParser.h\"\n"
            "#include \"%s.h\"\n\n\n"
            "#include \"exception/Exception.h\"\n\n\n"
            "template <class _HandleType>\n"
            "class %sBase {\n"
            "private:\n"
            "    TokenStructureHandle _pTokenStructure;\n"
            "    TokenHandle          _pToken;\n"
            "public:\n"
            "    %sBase() { }\n\n"
            "    virtual ~%sBase() {}\n\n"
            "    _HandleType parseString(const std::string & s) {\n"
            "        initFromString(s);\n"
            "        _HandleType pHandle;\n"
            "        if (parse(pHandle))\n"
            "            return pHandle;\n"
            "        reportChild();\n"
            "        throw InvalidFormatException(\"Unknown structure\");\n"
            "    }\n"
            "    _HandleType parseStringPos(const std::string & s) {\n"
            "        initFromString(s);\n"
            "        _HandleType pHandle;\n"
            "        unsigned int pos = 0;\n"
            "        if (parsePos(pHandle, pos))\n"
            "            return pHandle;\n"
            "        reportChild();\n"
            "        throw InvalidFormatException(\"Unknown structure\");\n"
            "    }\n"
            "    void reportChild() const {\n"
            "        getToken()->printChilds(getTokenStructure());"
            "    }\n"
            "    void reportChildFrom(unsigned int from) const {\n"
            "        for (unsigned int pos = from; pos < getTokenChildSize(); ++pos)\n"
            "            std::cout << \"Child(\" << pos << \") : \" << getTokenChild(pos)->name() << std::endl;\n"
            "    }\n"
            "    virtual bool parse(_HandleType & pHandle) {\n"
            "        unsigned int pos = 0;\n"
            "        return parsePos(pHandle, pos);\n"
            "    }\n"
            "    virtual bool parsePos(_HandleType & pHandle, unsigned int & pos) { throw \"Not implemented\"; }\n"
            "protected:\n"
            "    TokenStructureHandle getTokenStructure() const\n"
            "      { return _pTokenStructure; }\n"
            "    TokenHandle getToken() const\n"
            "      { return _pToken;}\n"
            "    unsigned int getTokenChildSize() const\n"
            "      { return getToken()->childSize(); }\n"
            "    TokenHandle getTokenChild(unsigned int pos) const\n"
            "      { return getToken()->child(getTokenStructure(), pos); }\n\n" 
            "    void initFromToken(TokenStructureHandle pTokenStructure, TokenHandle pToken) {\n"
            "        _pTokenStructure = pTokenStructure;\n"
            "        _pToken = pToken;\n"
            "    }\n"
            "    void initFromString(const std::string & s) {\n"
            "        StringParser string_parser;\n"
            "        _pTokenStructure = string_parser.parseString(s);\n"
            "        initToken();\n"
            "    }\n\n"
            "private:\n"
            "    void initToken() {\n"
            "        if (getTokenStructure()->vecToken().size() == 0)\n"
            "            throw InvalidFormatException(\"Not child\");\n"
            "        _pToken = getTokenStructure()->vecToken()[0];\n"
            "    }\n\n\n"
            "public:\n"
            "    virtual std::string getTokenName() const = 0;\n};\n\n") %( config.name_ast_parser_upper
   , config.name_ast_parser_upper
   , config.name_ast
   , config.name_ast_parser
   , config.name_ast_parser
   , config.name_ast_parser
   ) 

def string_of_header_bottom():
    return ("#endif // %s_H\n") %(config.name_ast_parser_upper) 

def print_header_bottom():
    print string_of_header_bottom()

def string_of_cpp_top():
    return ( "#include \"%s.h\"\n"
             "#include <sstream>\n"
             "#include <iostream>\n\n"
             "#define DEBUG_EXPR(expr) do { std::cerr << \"*Debug: \" << #expr << \" : \" << (expr) << std::endl; } while(0)\n\n") %(config.name_ast_parser)
 

def print_cpp_top():
    print string_of_cpp_top()

def string_of_ast_header_top():

    return ("#ifndef %s_H\n"
           "#define %s_H\n\n"
           "#include <vector>\n\n"
           "#include <string>\n\n"
           "#include \"nstl/shared_ptr/SharedPtr.h\"\n"
           "#include \"exception/Exception.h\"\n\n"
           "class %s;\n"
           "typedef SharedPtr<%s> %sHandle;\n\n\n"
           "class %s {\n"
           "public:\n"
           "    virtual ~%s();\n"
           "    virtual std::string toString() const;\n"
           "    virtual %sHandle base_handle() const;\n"
           "};\n") %(config.name_ast_upper
                   , config.name_ast_upper
                   , config.name_ast
                   , config.name_ast, config.name_ast
                   , config.name_ast
                   , config.name_ast
                   , config.name_ast)

def print_ast_header_top():
    print string_of_ast_header_top()

def string_of_ast_header_bottom():
    return ("#endif // %s_H\n") %(config.name_ast_upper)


def print_ast_header_bottom():
    print string_of_ast_header_bottom()

def string_of_ast_cpp_top():

    return ( "#include \"%s.h\"\n"
            "#include \"exception/Exception.h\"\n"
            "#include <sstream>\n"
            "#include <algorithm>\n\n"
            "%s::~%s() { }\n"
            "std::string %s::toString() const {\n"
            "    throw NotOverridenException();\n"
            "}\n"
            "%sHandle %s::base_handle() const {\n"
            "    throw NotOverridenException();\n"
            "}\n") %( config.name_ast
                    , config.name_ast, config.name_ast
                    , config.name_ast
                    , config.name_ast, config.name_ast)

def print_ast_cpp_top():
    print string_of_ast_cpp_top()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Ast parser generator")
    parser.add_argument('-ht', '--header-top', action='store_true', help="Print header top content", required=False)
    parser.add_argument('-hb', '--header-bottom', action='store_true', help="Print header bottom content", required=False)
    parser.add_argument('-ct', '--cpp-top', action='store_true', help="Print cpp top content", required=False)
    parser.add_argument('-aht', '--ast-header-top', action='store_true', help='Print ast header top', required=False)
    parser.add_argument('-ahb', '--ast-header-bottom', action='store_true', help='Print ast header bottom', required=False)
    parser.add_argument('-act', '--ast-cpp-top', action='store_true', help='Print ast cpp top', required=False)
    
    args = vars(parser.parse_args())

    if args['header_top']:
        print_header_top()
    if args['header_bottom']:
        print_header_bottom()
    if args['cpp_top']: 
        print_cpp_top()
    if args['ast_header_top']:
        print_ast_header_top()
    if args['ast_header_bottom']:
        print_ast_header_bottom()
    if args['ast_cpp_top']:
        print_ast_cpp_top()

