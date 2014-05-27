import config

class acceptor_base():
    def __init__(self, token_name, handle_name, ctor_name):
        self.token_name = token_name
        self.handle_name = handle_name
        self.ctor_name = ctor_name
    
    def get_token_name(self):
        return self.token_name
    
    def get_token_name_with_pos(self, pos):
        return ("%s%d") %(self.token_name, pos)

    def get_acceptor_name(self):
        return "base_should_be_overriden"

    def get_handle_type_name(self):
        return self.get_ctor_name() + "Handle";

    def get_handle_name(self):
        return self.handle_name

    def get_handle_name_with_pos(self, pos):
        return ("%s%d") %(self.get_handle_name(), pos)

    def get_flag_name(self):
        return "is_" + self.get_acceptor_name() + "_" + self.get_handle_name()
    
    def get_flag_name_with_pos(self, pos):
        return ("%s%d") %(self.get_flag_name(), pos) 
    
    
    def get_ctor_name(self):
        return self.ctor_name

    def get_parser_name(self):
        return self.get_ctor_name() + "Parser"

    def generate_guard(self):
        return ( "    if (getTokenName() != getToken()->name())\n"
                 "        return false;\n")

    def string_of_accept_flag(self):
        return ("%s") %(self.get_flag_name())
    
    def string_of_accept_flag_with_pos(self, pos):
        return ("%s%d") %(self.get_flag_name(), pos)
    
    def string_of_accept_handle(self):
        return ("%s %s") %(self.get_handle_type_name(), self.get_handle_name())
    
    def string_of_accept_handle_with_pos(self, pos):
        return ("%s %s") %(self.get_handle_type_name(), self.get_handle_name_with_pos(pos))
    
    
    def get_parser_name(self):
        return self.get_ctor_name() + "Parser"
    
    def generate_parser_header(self):
        if self.has_name():
            return self.generate_parser_header_without_pos()
        else:
            return self.generate_parser_header_with_pos()

    def generate_parser_header_without_pos(self):
        return ("class %sParser : public %sBase<%s> {\n"
                "public:\n"
                "    %sParser() { }\n"
                "    %sParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)\n"
                "      { initFromToken(pTokenStructure, pToken); }\n\n"
                "    bool parse(%s &  %s);\n"
                "    std::string getTokenName() const\n"
                "      { return \"%s\"; }\n"
                "};\n\n") % (self.get_ctor_name(), config.name_ast_parser, self.get_handle_type_name()
                , self.get_ctor_name()
                , self.get_ctor_name()
                , self.get_handle_type_name(), self.get_handle_name()
                , self.get_token_name())

    def generate_parser_header_with_pos(self):
        return ("class %sParser : public %sBase<%s> {\n"
                "public:\n"
                "    %sParser() { }\n"
                "    %sParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)\n"
                "      { initFromToken(pTokenStructure, pToken); }\n\n"
                "    bool parsePos(%s &  %s, unsigned int & pos);\n"
                "    std::string getTokenName() const\n"
                "      { return \"%s\"; }\n"
                "};\n\n") % (self.get_ctor_name(), config.name_ast_parser, self.get_handle_type_name()
                , self.get_ctor_name()
                , self.get_ctor_name()
                , self.get_handle_type_name(), self.get_handle_name()
                , self.get_token_name())


    def generate_ast_header_handle_declaration(self):
        return ("class %s;\n"
                "typedef SharedPtr<%s> %sHandle;\n") % ( self.get_ctor_name()
                                                    , self.get_ctor_name(), self.get_ctor_name())

    def generate_parser_cpp(self):
        return "/* Not implemented yet */"

    def generate_ast_header(self):
        return ( "class %s : public %s {\n"
                 "    std::string _%s;\n" 
                 "public:\n"
                 "    %s(const std::string & s);\n"
                 "    std::string %s() const;\n"
                 "    std::string toString() const;\n"
                 "};\n\n" ) % ( self.get_ctor_name(), config.name_ast
                            , self.get_token_name()
                 , self.get_ctor_name()
                 , self.get_token_name())
    
    def generate_ast_cpp(self):
        return ("%s::%s(const std::string & s)\n"
                "  : _%s(s)\n"
                "  { }\n"
                "std::string %s::%s() const\n"
                "  { return _%s; }\n"
                "std::string %s::toString() const\n"
                "  { return \"(%s \" + %s() + \")\";}\n") % ( self.get_ctor_name(), self.get_ctor_name()
                             , self.get_token_name()
                             , self.get_ctor_name(), self.get_token_name()
                             , self.get_token_name()
                             , self.get_ctor_name()
                             , self.get_token_name(), self.get_token_name())

    def has_name(self):
        raise "Should be overriden"

    def accept_by_parse_pos(self, handle_name, ctor_name, pos):
        "Since we want to accept zero or more / question as well, we cannot check if pos is end"
#        return ("    if (%s(getTokenStructure(), getToken()).parsePos(%s, pos) || getTokenChildSize() > pos) {\n"
        return ("    if (getTokenChildSize() > pos && %s(getTokenStructure(), getToken()).parsePos(%s, pos)) {\n"
                "        /* do nothing */\n"
               "") %(self.get_parser_name(), self.get_handle_name_with_pos(pos))
    
    def accept_by_parse(self, handle_name, ctor_name, pos):
#        return ("    if (%s(getTokenStructure(), getTokenChild(pos)).parse(%s) || getTokenChildSize() > pos) {\n"
        return ("    if (getTokenChildSize() > pos && %s(getTokenStructure(), getTokenChild(pos)).parse(%s)) {\n"
                "        ++pos;\n"
               "") %(self.get_parser_name(), self.get_handle_name_with_pos(pos))
    
    def accept_by(self, handle_name, ctor_name, pos):
        if self.has_name():
            return self.accept_by_parse(handle_name, ctor_name, pos)
        else:
            return self.accept_by_parse_pos(handle_name, ctor_name, pos)


def string_of_ast_header_element_method_declaration():
    content = ""
    content += ("    std::vector<ElementType>& container();\n")
    content += ("    const std::vector<ElementType>& container() const;\n")
    content += ("    ElementType element(unsigned int pos) const;\n")
    content += ("    unsigned int element_size() const;\n")
    content += ("    std::string toString() const;\n"
                "};\n" )
    return content

def string_of_ast_cpp_element_method_implementation(ctor_name, token_name):
    content = ""
    content += ("std::vector<%s::ElementType>& %s::container() {\n"
                "    return _vecElements;\n"
                "}\n") %(ctor_name, ctor_name)
    content += ("const std::vector<%s::ElementType>& %s::container() const {\n"
                "    return _vecElements;\n"
                "}\n") %(ctor_name, ctor_name)
    content += ("%s::ElementType %s::element(unsigned int pos) const {\n"
                "    assert(pos < element_size());\n" 
                "    return _vecElements[pos];\n"
                "}\n") %(ctor_name, ctor_name)
    content += ("unsigned int %s::element_size() const\n"
                "  { return _vecElements.size(); }\n") %(ctor_name)
       
    content += ("std::string %s::toString() const {\n"
                "    std::string s = \"(%s\";\n") %(ctor_name, token_name)
    content += "    for (unsigned int i = 0; i < element_size(); ++i) {\n"
    return  content



