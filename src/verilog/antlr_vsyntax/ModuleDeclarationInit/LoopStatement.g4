parser grammar LoopStatement ;

keyword_for : VerilogKeyword_for ;

loop_statement : keyword_for PUNC_PARENTHESIS_LEFT reg_assignment PUNC_SEMICOLON expression PUNC_SEMICOLON reg_assignment PUNC_PARENTHESIS_RIGHT statement 
//               | 'forever' statement
//               | 'repeat' '(' expression ')' statement
//               | 'while' '(' expression ')' statement
               ; 
