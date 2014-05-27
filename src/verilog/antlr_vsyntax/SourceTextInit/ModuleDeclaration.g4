parser grammar ModuleDeclaration ;

import ModuleItem ;

module_declaration : module_keyword identifier (list_of_ports)? PUNC_SEMICOLON (module_item)* keyword_endmodule ;

module_keyword : keyword_module 
               | keyword_macro_module ;

keyword_endmodule : VerilogKeyword_endmodule ;

keyword_module : VerilogKeyword_module ;

keyword_macro_module : VerilogKeyword_macromodule;

list_of_ports : PUNC_PARENTHESIS_LEFT port (PUNC_COMMA port)* PUNC_PARENTHESIS_RIGHT ;

port : port_expression
     | PUNC_DOT identifier PUNC_PARENTHESIS_LEFT (port_expression)? PUNC_PARENTHESIS_RIGHT ;

port_expression : port_reference
                | PUNC_PARENTHESIS_LEFT port_reference (PUNC_COMMA port_reference)* PUNC_PARENTHESIS_RIGHT ;

port_reference : identifier
               | identifier PUNC_BRACKET_LEFT constant_expression PUNC_BRACKET_RIGHT 
               | identifier PUNC_BRACKET_LEFT constant_expression PUNC_COLON constant_expression PUNC_BRACKET_RIGHT ; 

