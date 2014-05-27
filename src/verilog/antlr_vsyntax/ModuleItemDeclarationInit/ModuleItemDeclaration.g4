parser grammar ModuleItemDeclaration ;

import Expression ;

module_item_declaration :
    parameter_declaration
  | input_declaration
  | output_declaration
  | inout_declaration
  | net_declaration
  | reg_declaration
  | integer_declaration
//  | real_declaration
//  | time_declaration
//  | realtime_declaration
//  | event_declaration
//  | (port_direction net_declaration)
//  | (port_direction reg_declaration)
//  | (port_direction integer_declaration)
//  | (port_direction time_declaration)
//  | task_declaration
//  | function_declaration
  ;

keyword_parameter : VerilogKeyword_parameter ;
keyword_input : VerilogKeyword_input ;
keyword_output : VerilogKeyword_output ;
keyword_inout : VerilogKeyword_inout ;
keyword_wire : VerilogKeyword_wire ;
keyword_reg : VerilogKeyword_reg ;
keyword_integer : VerilogKeyword_integer ;
// keyword_localparam : VerilogKeyword_localparam ;


parameter_declaration :
    keyword_parameter list_of_param_assignments PUNC_SEMICOLON 
//  | VerilogKeyword_localparam list_of_param_assignments PUNC_SEMICOLON
  ;

list_of_param_assignments :
    param_assignment (PUNC_COMMA param_assignment)* ;

param_assignment :
    identifier PUNC_EQUAL expression ;

input_declaration :
    keyword_input (range)? list_of_port_identifiers PUNC_SEMICOLON ;


list_of_port_identifiers : identifier (PUNC_COMMA identifier)* ;

output_declaration :
    keyword_output (range)? list_of_port_identifiers PUNC_SEMICOLON ;

inout_declaration :
    keyword_inout (range)? list_of_port_identifiers PUNC_SEMICOLON ;

net_declaration :
    net_type (range)? list_of_net_identifiers PUNC_SEMICOLON ;

net_type :
    keyword_wire ;

list_of_net_identifiers :
    identifier (PUNC_COMMA identifier)* ;

reg_declaration :
    keyword_reg (range)? list_of_register_identifiers PUNC_SEMICOLON ;

list_of_register_identifiers :
    register_name (PUNC_COMMA register_name)* ;

register_name :
    identifier (PUNC_BRACKET_LEFT constant_expression PUNC_COLON constant_expression PUNC_BRACKET_RIGHT)* ;

integer_declaration :
    keyword_integer list_of_register_identifiers PUNC_SEMICOLON ;
