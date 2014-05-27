lexer grammar CommonLexerRules;

VerilogKeyword_module       : 'module' ;
VerilogKeyword_endmodule    : 'endmodule' ;
VerilogKeyword_input        : 'input' ;
VerilogKeyword_output       : 'output' ;
VerilogKeyword_reg          : 'reg' ;
VerilogKeyword_wire         : 'wire' ;

VerilogMacro_define         : '`define' ;
VerilogMacro_timescale      : '`timecale' ;

// NAME        : [a-zA-z][a-zA-z0-9_-]* ;
// INT         : [0-9]+;
// IntLiteral  : ('0' | '1'..'9' '0'..'9'*) ; 
// INT         : '0' .. '9' + ;
NEWLINE     : '\r'? '\n' -> skip ;
// INT_DIGIT   : ('0'..'9');
// INT         : INT_DIGIT+;
WS          : ['\t' ]+ -> skip ;
// ARRAY_INTERVAL : '[' INT ':' INT ']';

