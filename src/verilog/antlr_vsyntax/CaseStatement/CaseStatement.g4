parser grammar CaseStatement ;


keyword_case : VerilogKeyword_case | VerilogKeyword_casex;

keyword_endcase : VerilogKeyword_endcase ;

keyword_default : VerilogKeyword_default ;

case_statement : keyword_case PUNC_PARENTHESIS_LEFT expression PUNC_PARENTHESIS_RIGHT case_item+ keyword_endcase ;

// TODO : check default BNF
case_item : expression (PUNC_COMMA expression)* PUNC_COLON statement_or_null 
          | keyword_default PUNC_COLON statement_or_null ;
