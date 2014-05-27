parser grammar Literal;
import CommonLexerRules;

literal :
    integer_literal
  | bit_literal
  | character_literal
  | floating_literal
  | string_literal
  | boolean_literal
  ;

integer_literal :
    Decimal_Literal Integer_Suffix?
  | Signed_Decimal_Literal
//  | Punc_Minus Decimal_Literal Integer_Suffix?
  | Hexadecimal_Literal Integer_Suffix?
  ;

bit_literal :
    Bit_Literal
  ;

character_literal :
    Character_Literal
  ;

floating_literal :
    Floating_Literal
  ;

string_literal :
    String_Literal
  ;

boolean_literal :
    CKeyword_false 
  | CKeyword_true
  ;
