parser grammar ContinuousAssign ;
import Expression ;

keyword_assign : VerilogKeyword_assign ;

continuous_assign :  keyword_assign /* drive_strength delay3 */ list_of_net_assignments PUNC_SEMICOLON ;

list_of_net_assignments : net_assignment (PUNC_COMMA net_assignment)* ;

net_assignment : net_lvalue PUNC_EQUAL expression ;

net_lvalue : identifier 
           | identifier PUNC_BRACKET_LEFT expression PUNC_BRACKET_RIGHT
           | identifier PUNC_BRACKET_LEFT constant_expression PUNC_COLON constant_expression PUNC_BRACKET_RIGHT
           | concatenation ;

