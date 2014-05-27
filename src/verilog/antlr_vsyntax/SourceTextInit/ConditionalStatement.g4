parser grammar ConditionalStatement ;

keyword_if : VerilogKeyword_if ;

keyword_else : VerilogKeyword_else ;

conditional_statement : keyword_if PUNC_PARENTHESIS_LEFT expression PUNC_PARENTHESIS_RIGHT statement_or_null (keyword_else statement_or_null)? ;

statement_or_null : statement 
                  | PUNC_SEMICOLON ;
