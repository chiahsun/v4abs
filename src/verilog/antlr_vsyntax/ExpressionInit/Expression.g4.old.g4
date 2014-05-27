parser grammar Expression;
import CommonLexerRules;


expression : // Not in rule
             PUNC_PARENTHESIS_LEFT ( ~(PUNC_PARENTHESIS_LEFT | PUNC_PARENTHESIS_RIGHT) | expression) PUNC_PARENTHESIS_RIGHT 
           | primary 
           | unary_operator primary
           | expression binary_operator expression
           | expression PUNC_QUEATION_MARK expression PUNC_COLON expression
//           | string // TODO
           ;
       
alpha_upper_case : Letter_A | Letter_B | Letter_C | Letter_D | Letter_E 
                  | Letter_F | Letter_G | Letter_H | Letter_I | Letter_J 
                  | Letter_K | Letter_L | Letter_M | Letter_N | Letter_O 
                  | Letter_P | Letter_Q | Letter_R | Letter_S | Letter_T 
                  | Letter_U | Letter_V | Letter_W | Letter_X | Letter_Y 
                  | Letter_Z ; 
        
alpha : Letter_A | Letter_B | Letter_C | Letter_D | Letter_E 
                  | Letter_F | Letter_G | Letter_H | Letter_I | Letter_J 
                  | Letter_K | Letter_L | Letter_M | Letter_N | Letter_O 
                  | Letter_P | Letter_Q | Letter_R | Letter_S | Letter_T 
                  | Letter_U | Letter_V | Letter_W | Letter_X | Letter_Y 
                  | Letter_Z 

| Letter_a | Letter_b | Letter_c | Letter_d | Letter_e
                  | Letter_f | Letter_g | Letter_h | Letter_i | Letter_j
                  | Letter_k | Letter_l | Letter_m | Letter_n | Letter_o
                  | Letter_p | Letter_q | Letter_r | Letter_s | Letter_t
                  | Letter_u | Letter_v | Letter_w | Letter_x | Letter_y
                  | Letter_z ;

// Use fragment
alphanum : Letter_A | Letter_B | Letter_C | Letter_D | Letter_E 
                  | Letter_F | Letter_G | Letter_H | Letter_I | Letter_J 
                  | Letter_K | Letter_L | Letter_M | Letter_N | Letter_O 
                  | Letter_P | Letter_Q | Letter_R | Letter_S | Letter_T 
                  | Letter_U | Letter_V | Letter_W | Letter_X | Letter_Y 
                  | Letter_Z 

| Letter_a | Letter_b | Letter_c | Letter_d | Letter_e
                  | Letter_f | Letter_g | Letter_h | Letter_i | Letter_j
                  | Letter_k | Letter_l | Letter_m | Letter_n | Letter_o
                  | Letter_p | Letter_q | Letter_r | Letter_s | Letter_t
                  | Letter_u | Letter_v | Letter_w | Letter_x | Letter_y
                  | Letter_z | Digit_0 | Digit_1 | Digit_2 | Digit_3 | Digit_4 | Digit_5 | Digit_6 | Digit_7 | Digit_8 | Digit_9 ;

           
primary : number
        | identifier
        | identifier (PUNC_BRACKET_LEFT expression PUNC_BRACKET_RIGHT)+
        | identifier (PUNC_BRACKET_LEFT constant_expression PUNC_COLON constant_expression PUNC_BRACKET_RIGHT)+
        | concatenation
        | multiple_concatenation
//        | function_call 
//        | mintypmax_expression
        ;    

constant_expression : constant_primary
                    | unary_operator constant_primary
                    | constant_expression binary_operator constant_expression
                    | constant_expression PUNC_QUEATION_MARK constant_expression PUNC_COLON constant_expression
// TODO             | string
                    ;

constant_primary : number
                 | identifier
                 | concatenation
                 | multiple_concatenation 
                 ;

concatenation : PUNC_BRACES_LEFT expression (PUNC_COMMA expression)+ PUNC_BRACES_RIGHT ;

multiple_concatenation : PUNC_BRACES_LEFT expression PUNC_BRACES_LEFT expression (PUNC_COMMA expression)+ PUNC_BRACES_RIGHT ;

identifier : single_identifier (PUNC_DOT single_identifier)* ; 

single_identifier : simple_identifier
                  | defined_identifier
//                  | escaped_identifier 
                  ;

simple_identifier : alpha (alphanum | PUNC_UNDERSCORE | PUNC_DOLLAR)* ;

defined_identifier : PUNC_BACK_QUOTE alpha_upper_case (alpha_upper_case | digit | PUNC_UNDERSCORE)* ; 

number : unsigned_number
       | binary_number
       | octal_number
       | decimal_number
       | heximal_number
       ;

binary_number : unsigned_number VerilogTerm_BinaryBase (binary_digit | PUNC_UNDERSCORE)+ ;

octal_number : unsigned_number VerilogTerm_OctalBase (octal_digit | PUNC_UNDERSCORE)+ ;

decimal_number : unsigned_number VerilogTerm_DecimalBase (decimal_digit | PUNC_UNDERSCORE)+ ; 

heximal_number : unsigned_number VerilogTerm_HeximalBase (heximal_digit | PUNC_UNDERSCORE)+ ;

unary_operator : // '+' | '-' | '!' | '~' 
                 PUNC_PLUS | PUNC_MINUS | PUNC_EXCLAMATION | PUNC_TILDE
                 // | '&' | '~&' 
               | PUNC_AMPERSAND | (PUNC_TILDE PUNC_AMPERSAND)
                 // | '|' | '~|' 
               | PUNC_VERTICAL_BAR | (PUNC_TILDE PUNC_VERTICAL_BAR)
                 // | '^' | '~^' | '^~' ;
               | PUNC_CARET | (PUNC_TILDE PUNC_CARET) | (PUNC_CARET PUNC_TILDE) ;


binary_operator : // '+' | '-' | '*' 
                  PUNC_PLUS | PUNC_MINUS | PUNC_ASTERISK 
                  // | '/' | '%'
                | PUNC_SLASH | PUNC_PERCENT
                  // | '==' | '!=' | '===' | '!==='
                | (PUNC_EQUAL PUNC_EQUAL) | (PUNC_EXCLAMATION PUNC_EQUAL) | (PUNC_EQUAL PUNC_EQUAL PUNC_EQUAL) | (PUNC_EXCLAMATION PUNC_EQUAL PUNC_EQUAL)
                  // | '&&' | '||' 
                | (PUNC_AMPERSAND PUNC_AMPERSAND) | (PUNC_VERTICAL_BAR PUNC_VERTICAL_BAR)  
                  // | '<' | '<=' | '>' | '>='
                | PUNC_LESS_THEN | (PUNC_LESS_THEN PUNC_EQUAL) | PUNC_GREATER_THEN | (PUNC_GREATER_THEN PUNC_EQUAL)
                  // | '&' | '|'
                | PUNC_AMPERSAND | PUNC_VERTICAL_BAR
                  // | '^' | '^~' | '~^'
                | PUNC_CARET | (PUNC_CARET PUNC_TILDE) | (PUNC_TILDE PUNC_CARET)
                  // | '>>' | '<<'
                | (PUNC_GREATER_THEN PUNC_GREATER_THEN) | (PUNC_LESS_THEN PUNC_LESS_THEN)
                  // vlog2001
                  ;
/*
term : signal_identifier 
     | defined_identifier
     | number
     | PUNC_PARENTHESIS_LEFT expression PUNC_PARENTHESIS_RIGHT
     ; 


defined_identifier : DefinedIdentifier ;


number : unsigned_number
       ;

unary_expression : unary_operator+ term ;
*/

/*



Letters_Uppercase : Letter_A | Letter_B | Letter_C | Letter_D | Letter_E 
                  | Letter_F | Letter_G | Letter_H | Letter_I | Letter_J 
                  | Letter_K | Letter_L | Letter_M | Letter_N | Letter_O 
                  | Letter_P | Letter_Q | Letter_R | Letter_S | Letter_T 
                  | Letter_U | Letter_V | Letter_W | Letter_X | Letter_Y 
                  | Letter_Z ;

Letters_Lowercase : Letter_a | Letter_b | Letter_c | Letter_d | Letter_e
                  | Letter_f | Letter_g | Letter_h | Letter_i | Letter_j
                  | Letter_k | Letter_l | Letter_m | Letter_n | Letter_o
                  | Letter_p | Letter_q | Letter_r | Letter_s | Letter_t
                  | Letter_u | Letter_v | Letter_w | Letter_x | Letter_y
                  | Letter_z ;

// [A-Z]
DefinedIdentifier_Letter : Letters_Uppercase ;

// [a-z] [A-Z]
SignalIdentifier_Letter : Letters_Uppercase | Letters_Lowercase ;

// [a-z] [A-Z] ([a-z] [A-Z] [_])
signal_identifier : SignalIdentifier ;

SignalIdentifier : SignalIdentifier_Letter (SignalIdentifier_Letter | PUNC_UNDERSCORE | Digit)* ;

//                  '`'
DefinedIdentifier : PUNC_BACK_QUOTE DefinedIdentifier_Letter (DefinedIdentifier_Letter | PUNC_UNDERSCORE | Digit)* ;

expression : term
           | unary_expression
           ;
*/


digit : Digit_0 
      | Digit_1 
      | Digit_2 
      | Digit_3 
      | Digit_4 
      | Digit_5 
      | Digit_6 
      | Digit_7 
      | Digit_8 
      | Digit_9
      ;

binary_digit : Digit_0 | Digit_1 ;

octal_digit : Digit_0 | Digit_1 | Digit_2 | Digit_3 | Digit_4
                  | Digit_5 | Digit_6 | Digit_7 ;

decimal_digit : Digit_0 | Digit_1 | Digit_2 | Digit_3 | Digit_4
                    | Digit_5 | Digit_6 | Digit_7 | Digit_8 | Digit_9 ; 

heximal_digit : Digit_0 | Digit_1 | Digit_2 | Digit_3 | Digit_4
                    | Digit_5 | Digit_6 | Digit_7 | Digit_8 | Digit_9
                    | Letter_a | Letter_A
                    | Letter_b | Letter_B
                    | Letter_c | Letter_C
                    | Letter_d | Letter_D
                    | Letter_e | Letter_E
                    | Letter_f | Letter_F
                    ; 

unsigned_number : digit+ ;

