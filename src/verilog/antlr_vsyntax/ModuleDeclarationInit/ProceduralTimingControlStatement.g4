parser grammar ProceduralTimingControlStatement ;

procedural_timing_control_statement : delay_or_event_control statement_or_null ;

delay_or_event_control : 
                         event_control
                    //   | delay_control
                    // | 'repeat' '(' expression ')' event_control
                       ;


event_control : PUNC_AT identifier 
              | PUNC_AT PUNC_PARENTHESIS_LEFT (event_expression | PUNC_ASTERISK) PUNC_PARENTHESIS_RIGHT 
              ;

keyword_posedge : VerilogKeyword_posedge ;

keyword_negedge : VerilogKeyword_negedge ;

keyword_or : VerilogKeyword_or ;

event_expression : expression
                 | identifier
                 | keyword_posedge expression
                 | keyword_negedge expression
                 | event_expression PUNC_COMMA event_expression
                 | event_expression keyword_or event_expression ;

statement_or_null : statement
                  | PUNC_SEMICOLON 
                  ;
