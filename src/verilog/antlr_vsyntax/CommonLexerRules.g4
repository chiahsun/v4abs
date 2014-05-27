lexer grammar CommonLexerRules;

// Since lexer will match these first ...
// We CANNOT put these in lexer rules first

fragment
SpacingChar : (~[1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-`~+=,./]) ;

fragment
Delimitor : ['\n''\t''\r' ] ;


DocCommet : '/**' .*? '*/' -> skip;

BlockComment : '/*' .*? '*/' -> skip;

LineComment : '//' ~[\r\n]* -> skip ;

VerilogKeyword_endmodule      : Delimitor? 'endmodule' Delimitor ;

VerilogKeyword_module         : Delimitor? 'module' Delimitor ;

VerilogKeyword_macromodule    : Delimitor? 'macromodule' Delimitor ;

VerilogKeyword_reg            : Delimitor? 'reg' Delimitor ;

VerilogKeyword_if             : Delimitor? 'if' ;

VerilogKeyword_else           : Delimitor? 'else' ;

VerilogKeyword_begin          : Delimitor? 'begin' Delimitor ;

VerilogKeyword_end            : Delimitor? 'end' Delimitor ;

VerilogKeyword_assign         : Delimitor? 'assign' Delimitor ;

VerilogKeyword_case           : Delimitor? 'case' Delimitor ;

VerilogKeyword_casex          : Delimitor? 'casex' Delimitor ;

VerilogKeyword_endcase        : Delimitor? 'endcase' Delimitor ;

VerilogKeyword_default        : Delimitor? 'default' Delimitor ;

VerilogKeyword_posedge        : Delimitor? 'posedge' Delimitor ;

VerilogKeyword_negedge        : Delimitor? 'negedge' Delimitor ;

VerilogKeyword_or             : Delimitor? 'or' Delimitor ;

VerilogKeyword_for            : Delimitor? 'for' Delimitor ;

VerilogKeyword_always         : Delimitor? 'always' Delimitor ;

VerilogKeyword_initial        : Delimitor? 'initial' Delimitor ;

VerilogKeyword_parameter      : Delimitor? 'parameter' Delimitor ;

VerilogKeyword_input          : Delimitor? 'input' Delimitor ;

VerilogKeyword_output         : Delimitor? 'output' Delimitor ;

VerilogKeyword_inout          : Delimitor? 'inout' Delimitor ;

VerilogKeyword_wire           : Delimitor? 'wire' Delimitor ;

VerilogKeyword_integer        : Delimitor? 'integer' Delimitor ;

VerilogKeyword_and            : Delimitor? 'and' Delimitor ;

VerilogKeyword_nand           : Delimitor? 'nand' Delimitor ;

VerilogKeyword_or             : Delimitor? 'or' Delimitor ;

VerilogKeyword_nor            : Delimitor? 'nor' Delimitor ;

VerilogKeyword_xor            : Delimitor? 'xor' Delimitor ;

VerilogKeyword_xnor           : Delimitor? 'xnor' Delimitor ;

VerilogKeyword_buf            : Delimitor? 'buf' Delimitor ;

VerilogKeyword_not            : Delimitor? 'not' Delimitor ;



VerilogMacro_define           : '`define' ;
VerilogMacro_timescale        : '`timescale' ;
VerilogMacro_include          : '`include' ;

VerilogTerm_BinaryBase : '\'b' | '\'B' ;
VerilogTerm_OctalBase : '\'o' | '\'O' ;
VerilogTerm_DecimalBase : '\'d' | '\'D' ;
VerilogTerm_HeximalBase : '\'h' | '\'H' ; 

// NAME        : [a-zA-z][a-zA-z0-9_-]* ;
// INT         : [0-9]+;
// IntLiteral  : ('0' | '1'..'9' '0'..'9'*) ; 
// INT         : '0' .. '9' + ;
// NEWLINE     : '\r'? '\n' -> skip ;
// INT_DIGIT   : ('0'..'9');
// INT         : INT_DIGIT+;
WS          : [ \t\r\n\f]+ -> skip ;
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
PUNC_AT           : '@' ;

fragment
Alphanum : Alpha
         | Num ;

fragment
Alpha : AlphaUppercase
      | AlphaLowerCase ;

fragment 
AlphaUppercase : 'A'..'Z' ;

fragment
AlphaLowerCase : 'a'..'z' ;

fragment
Num : '0'..'9' ;

fragment
Heximal_Digit : [xXzZ0-9a-fA-F] ;

fragment
Decimal_Digit : [xXzZ0-9] ;

fragment
Octal_Digit : [xXzZ0-7] ;

fragment
Binary_Digit : [xXzZ01];

BinaryNumber : Num+ VerilogTerm_BinaryBase (Binary_Digit | PUNC_UNDERSCORE)+ ;

OctalNumber : Num+ VerilogTerm_OctalBase (Octal_Digit | PUNC_UNDERSCORE)+ ;

DecimalNumber : Num+ VerilogTerm_DecimalBase (Decimal_Digit | PUNC_UNDERSCORE)+ ;

HeximalNumber : Num+ VerilogTerm_HeximalBase (Heximal_Digit | PUNC_UNDERSCORE)+ ; 

UnsignedNumber : Num+ ;

DefinedIdentifier : PUNC_BACK_QUOTE AlphaUppercase (AlphaUppercase | Num | PUNC_UNDERSCORE)* ;

SimpleIdentifier : Alpha (Alphanum | PUNC_UNDERSCORE | PUNC_DOLLAR)* ; 
