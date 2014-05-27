parser grammar GateInstantiation ;

import Expression ;

gate_instantiation :
    n_input_gatetype n_input_gate_instance (PUNC_COMMA n_input_gate_instance)* PUNC_SEMICOLON 
  | n_output_gatetype n_output_gate_instance (PUNC_COMMA n_output_gate_instance)* PUNC_SEMICOLON ;

n_input_gatetype :
    VerilogKeyword_and
  | VerilogKeyword_nand
  | VerilogKeyword_or
  | VerilogKeyword_nor
  | VerilogKeyword_xor
  | VerilogKeyword_xnor ;

n_output_gatetype :
    VerilogKeyword_buf
  | VerilogKeyword_not ;

n_input_gate_instance :
    (name_of_gate_instance)? PUNC_PARENTHESIS_LEFT output_terminal PUNC_COMMA input_terminal (PUNC_COMMA input_terminal)* PUNC_PARENTHESIS_RIGHT ;

name_of_gate_instance :
    identifier (range)? ;

output_terminal : identifier (PUNC_BRACKET_LEFT constant_expression PUNC_BRACKET_RIGHT)? ;

input_terminal : expression ;

n_output_gate_instance : (name_of_gate_instance)? PUNC_PARENTHESIS_LEFT output_terminal (PUNC_COMMA output_terminal)* PUNC_COMMA input_terminal PUNC_PARENTHESIS_RIGHT ; 
