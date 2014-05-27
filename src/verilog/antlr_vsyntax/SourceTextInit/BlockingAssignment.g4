parser grammar BlockingAssignment ;

import Expression ;

blocking_assignment : reg_lvalue PUNC_EQUAL /* delay_or_event_control TODO */ expression ;

reg_lvalue : identifier 

           | identifier (PUNC_BRACKET_LEFT expression (PUNC_COLON expression)? PUNC_BRACKET_RIGHT)+
           /*
           | identifier PUNC_BRACKET_LEFT expression PUNC_BRACKET_RIGHT           
           | identifier PUNC_BRACKET_LEFT constant_expression PUNC_COLON constant_expression PUNC_BRACKET_RIGHT*/
           | concatenation ;
           
            

