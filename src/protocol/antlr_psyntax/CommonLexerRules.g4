lexer grammar CommonLexerRules ;

fragment
Delimitor : ['\n''\t''\r' ] ;

DocComment : '/**' .*? '*/' -> skip;
BlockComment : '/*' .*? '*/' -> skip;
LineComment : '//' ~[\r\n]* ->skip;

CKeyword_read      : Delimitor? 'read'      Delimitor?;
CKeyword_write     : Delimitor? 'write'     Delimitor?;
CKeyword_check     : Delimitor? 'check'     Delimitor?;
CKeyword_assert    : Delimitor? 'assert'    Delimitor?;
CKeyword_else      : Delimitor? 'else'      Delimitor?;
CKeyword_goto      : Delimitor? 'goto'      Delimitor?;
CKeyword_if        : Delimitor? 'if'        Delimitor?;
CKeyword_false     : Delimitor? 'false'     Delimitor?;
CKeyword_true      : Delimitor? 'true'      Delimitor?;

CTerm_Hexadecimal  : '0x' | '0X' ;

WS     : [ \t\r\n\f]+ -> skip ;

Punc_Apostrophe        : '\'' ;
Punc_Bracket_Left      : '['  ;
Punc_Bracket_Right     : ']'  ;
Punc_Parenthesis_Left  : '('  ;
Punc_Parenthesis_Right : ')'  ;
Punc_Braces_Left       : '{'  ;
Punc_Braces_Right      : '}'  ;
Punc_Plus              : '+'  ;
Punc_Minus             : '-'  ;
Punc_Exclamation       : '!'  ;
Punc_Tilde             : '~'  ;
Punc_Vertical_Bar      : '|'  ;
Punc_Ampersand         : '&'  ;
Punc_Caret             : '^'  ;
Punc_Semicolon         : ';'  ;
Punc_Colon             : ':'  ;
Punc_Comma             : ','  ;
Punc_Back_Quote        : '`'  ;
Punc_Underscore        : '_'  ;
Punc_Dot               : '.'  ;
Punc_Dollar            : '$'  ;
Punc_Question_Mark     : '?'  ;
Punc_Asterisk          : '*'  ;
Punc_Slash             : '/'  ;
Punc_Back_Slash        : '\\' ;
Punc_Percent           : '%'  ;
Punc_Equal             : '='  ;
Punc_Less_Than         : '<'  ;
Punc_Greater_Than      : '>'  ;
Punc_At                : '@'  ;
Punc_Quote             : '\'' ;
Punc_Double_Quote      : '"'  ;
Punc_Pound_Sign        : '#'  ;

/*
fragment
Num : '0'..'9' ;
*/
fragment NonzeroNum : '1'..'9' ;
fragment Num_0 : '0' ;
fragment AlphaUppercase : 'A'..'Z' ;
fragment AlphaLowercase : 'a'..'z' ;
fragment CTerm_Hexadecimal : '0x'|'0X' ;
fragment Hexadecimal_Digit : [0-9a-fA-F] ;

fragment Letter_b : 'b' ;
fragment Letter_B : 'B' ;
fragment Letter_e : 'e' ;
fragment Letter_E : 'E' ;
fragment Letter_f : 'f' ;
fragment Letter_F : 'F' ;
fragment Letter_u : 'u' ;
fragment Letter_U : 'U' ;
fragment Letter_l : 'l' ;
fragment Letter_L : 'L' ;
fragment
Char :
    '\x' Hexadecimal_Digit+
  | '\''
  | '\"'
  | '\?'
  | '\\'
  | '\a'
  | '\b'
  | '\f'
  | '\n'
  | '\r'
  | '\t'
  | '\v'
  | ' '
  | Num_0
  | NonzeroNum
  | AlphaUppercase
  | AlphaLowercase
  | Punc_Apostrophe
  | Punc_Bracket_Left
  | Punc_Bracket_Right
  | Punc_Parenthesis_Left
  | Punc_Parenthesis_Right
  | Punc_Braces_Left
  | Punc_Braces_Right
  | Punc_Plus
  | Punc_Minus
  | Punc_Exclamation
  | Punc_Tilde
  | Punc_Vertical_Bar
  | Punc_Ampersand
  | Punc_Caret
  | Punc_Semicolon
  | Punc_Colon
  | Punc_Comma
  | Punc_Back_Quote
  | Punc_Underscore
  | Punc_Dot
  | Punc_Dollar
  | Punc_Question_Mark
  | Punc_Asterisk
  | Punc_Slash
  | Punc_Percent
  | Punc_Equal
  | Punc_Less_Than
  | Punc_Greater_Than
  | Punc_At
  ;

/*
Assert_Statement :
    CKeyword_assert Punc_Parenthesis_Left Num_0 Punc_Parenthesis_Right Punc_Semicolon
  ;
*/
Bit_Literal :
    NonzeroNum Punc_Quote Letter_b (Num_0|NonzeroNum)+
  ;

Character_Literal :
    Punc_Quote (Char|Punc_Double_Quote)+ Punc_Quote
  | Letter_L Punc_Quote (Char|Punc_Double_Quote)+ Punc_Quote
  ;

String_Literal :
    Punc_Double_Quote (Char|Punc_Quote)+ Punc_Double_Quote
  | Letter_L Punc_Double_Quote (Char|Punc_Quote)+ Punc_Double_Quote
  ;

Decimal_Literal :
    Num_0 // ???
  | NonzeroNum (Num_0|NonzeroNum)*
  ;

Signed_Decimal_Literal :
    Punc_Minus Decimal_Literal
  | Punc_Plus Decimal_Literal
  ;

Hexadecimal_Literal :
    CTerm_Hexadecimal Hexadecimal_Digit+
  ;

Floating_Literal :
    (Num_0|NonzeroNum)+ (Letter_e|Letter_E) (Punc_Plus|Punc_Minus)? (Num_0|NonzeroNum)+ (Letter_f|Letter_F|Letter_l|Letter_L)?
  | ((Num_0|NonzeroNum)+)? Punc_Dot (Num_0|NonzeroNum)+ ((Letter_e|Letter_E) (Punc_Plus|Punc_Minus)? (Num_0|NonzeroNum)+)? (Letter_f|Letter_F|Letter_l|Letter_L)?
  | (Num_0|NonzeroNum)+ Punc_Dot ((Letter_e|Letter_E) (Punc_Plus|Punc_Minus)? (Num_0|NonzeroNum)+)? (Letter_f|Letter_F|Letter_l|Letter_L)?
  ;

/*
Pure_Specifier :
    Punc_Equal Num_0
  ;
*/
Integer_Suffix :
    Letter_l Letter_u
  | Letter_l Letter_U
  | Letter_L Letter_u
  | Letter_L Letter_U
  | Letter_u Letter_l
  | Letter_u Letter_L
  | Letter_U Letter_l
  | Letter_U Letter_L
  ;

Identifier :
    (AlphaUppercase|AlphaLowercase|Punc_Underscore) (AlphaUppercase|AlphaLowercase|Punc_Underscore|Num_0|NonzeroNum)*
  ;

PPNumber : (Num_0|NonzeroNum) + Punc_Dot? (Num_0|NonzeroNum)*
         | (Num_0|NonzeroNum)* Punc_Dot? (Num_0|NonzeroNum)+
         ;// will wrong
