parser grammar ModuleInstantiation ;

import Expression ;

module_instantiation :
    identifier  /* (parameter_value_assignment) */ module_instance (PUNC_COMMA module_instance)* PUNC_SEMICOLON ;

module_instance : name_of_instance PUNC_PARENTHESIS_LEFT (list_of_module_connections)? PUNC_PARENTHESIS_RIGHT ;

name_of_instance : identifier (range)? ;

list_of_module_connections : ordered_port_connection (PUNC_COMMA ordered_port_connection)*
                           | named_port_connection (PUNC_COMMA named_port_connection)* ;
                           
ordered_port_connection : (expression)? ;

named_port_connection : PUNC_DOT identifier PUNC_PARENTHESIS_LEFT (expression)? PUNC_PARENTHESIS_RIGHT ;
