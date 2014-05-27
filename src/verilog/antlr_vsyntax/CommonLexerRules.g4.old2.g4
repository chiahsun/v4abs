lexer grammar CommonLexerRules;

// Since lexer will match these first ...
// We CANNOT put these in lexer rules first
// VerilogKeyword_module       : 'module' ;
// VerilogKeyword_endmodule    : 'endmodule' ;
// VerilogKeyword_input        : 'input' ;
// VerilogKeyword_output       : 'output' ;
// VerilogKeyword_reg          : 'reg' ;
// VerilogKeyword_wire         : 'wire' ;

fragment
SpacingChar : (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]) ;

VerilogKeyword_if : SpacingChar? 'if' SpacingChar? ;

VerilogKeyword_else : (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ])? 'else' (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ])? ;

VerilogKeyword_begin : ['\r''\n''\t' ]? 'begin' ['\r''\n''\t' ] ;

VerilogKeyword_end : (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ])? 'end' (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ])? ;


VerilogMacro_define         : '`define' ;
VerilogMacro_timescale      : '`timecale' ;

VerilogTerm_BinaryBase : '\'b' | '\'B' ;
VerilogTerm_OctalBase : '\'o' | '\'O' ;
VerilogTerm_DecimalBase : '\'d' | '\'D' ;
VerilogTerm_HeximalBase : '\'h' | '\'H' ; 

// NAME        : [a-zA-z][a-zA-z0-9_-]* ;
// INT         : [0-9]+;
// IntLiteral  : ('0' | '1'..'9' '0'..'9'*) ; 
// INT         : '0' .. '9' + ;
NEWLINE     : '\r'? '\n' -> skip ;
// INT_DIGIT   : ('0'..'9');
// INT         : INT_DIGIT+;
WS          : ['\t' ]+ -> skip ;
// ARRAY_INTERVAL : '[' INT ':' INT ']';
PUNC_APOSTROPHE : '\'' ;
PUNC_BRACKET_LEFT : '[' ;
PUNC_BRACKET_RIGHT : ']' ;
PUNC_PARENTHESIS_LEFT : '(' ;
PUNC_PARENTHESIS_RIGHT : ')' ;
PUNC_BRACES_LEFT : '{' ;
PUNC_BRACES_RIGHT : '}' ;
PUNC_PLUS : '+' ;
PUNC_MINUS : '-' ;
PUNC_EXCLAMATION : '!' ;
PUNC_TILDE : '~' ;
PUNC_VERTICAL_BAR : '|' ;
PUNC_AMPERSAND : '&' ;
PUNC_CARET : '^' ;
PUNC_SEMICOLON : ';' ;
PUNC_COLON : ':' ;
PUNC_COMMA : ',' ;
PUNC_BACK_QUOTE : '`' ;
PUNC_UNDERSCORE : '_' ;
PUNC_DOT : '.' ;
PUNC_DOLLAR : '$' ;
PUNC_QUEATION_MARK : '?' ;
PUNC_ASTERISK : '*' ;
PUNC_SLASH : '/' ;
PUNC_BACK_SLASH : '\\' ;
PUNC_PERCENT : '%' ;
PUNC_EQUAL : '=' ;
PUNC_LESS_THAN : '<' ;
PUNC_GREATER_THAN : '>' ;

Letter_a : 'a' ;
Letter_A : 'A' ;
Letter_b : 'b' ;
Letter_B : 'B' ;
Letter_c : 'c' ;
Letter_C : 'C' ;
Letter_d : 'd' ;
Letter_D : 'D' ;
Letter_e : 'e' ;
Letter_E : 'E' ;
Letter_f : 'f' ;
Letter_F : 'F' ;
Letter_g : 'g' ;
Letter_G : 'G' ;
Letter_h : 'h' ;
Letter_H : 'H' ;
Letter_i : 'i' ;
Letter_I : 'I' ;
Letter_j : 'j' ;
Letter_J : 'J' ;
Letter_k : 'k' ;
Letter_K : 'K' ;
Letter_l : 'l' ;
Letter_L : 'L' ;
Letter_m : 'm' ;
Letter_M : 'M' ;
Letter_n : 'n' ;
Letter_N : 'N' ;
Letter_o : 'o' ;
Letter_O : 'O' ;
Letter_p : 'p' ;
Letter_P : 'P' ;
Letter_q : 'q' ;
Letter_Q : 'Q' ;
Letter_r : 'r' ;
Letter_R : 'R' ;
Letter_s : 's' ;
Letter_S : 'S' ;
Letter_t : 't' ;
Letter_T : 'T' ;
Letter_u : 'u' ;
Letter_U : 'U' ;
Letter_v : 'v' ;
Letter_V : 'V' ;
Letter_w : 'w' ;
Letter_W : 'W' ;
Letter_x : 'x' ;
Letter_X : 'X' ;
Letter_y : 'y' ;
Letter_Y : 'Y' ;
Letter_z : 'z' ;
Letter_Z : 'Z' ;

Digit_0 : '0' ;
Digit_1 : '1' ;
Digit_2 : '2' ;
Digit_3 : '3' ;
Digit_4 : '4' ;
Digit_5 : '5' ;
Digit_6 : '6' ;
Digit_7 : '7' ;
Digit_8 : '8' ;
Digit_9 : '9' ;
// http://www.externsoft.ch/download/verilog.html
