parser grammar SourceText;
import Literal;

source_text : // done
    state_statement+
  ;

state_statement : // done
    state_label transition_statement
  ;

transition_statement :
    edge_statement+
//    block_update_statement* specific_update_statement* end_statement
  ;
/*
block_update_statement :
    all_update_statement* if_statement_with_goto
  ;
*/
edge_statement :
    all_update_statement* if_statement_with_goto
  | specific_update_statement* end_statement
  ;

all_update_statement :
    read_or_write_or_check_statement
  | if_statement_without_goto
  ;

specific_update_statement :
    read_or_write_or_check_statement
  | if_statement_without_goto
  ;

state_label : // done
    identifier Punc_Colon
  ;

read_or_write_or_check_statement : // done
    read_statement
  | write_statement
  | check_statement
  ;

read_statement : // done
    CKeyword_read Punc_Parenthesis_Left identifier Punc_Parenthesis_Right Punc_Semicolon
  ;

write_statement : // done
    CKeyword_write Punc_Parenthesis_Left identifier Punc_Parenthesis_Right Punc_Semicolon
  ;

check_statement : // done
    CKeyword_check Punc_Parenthesis_Left bool_expression Punc_Parenthesis_Right Punc_Semicolon
  ;

end_statement :
    goto_statement
  | assert_statement
  ;

if_statement_with_goto :
    if_statement_prefix end_statement // only one statement
  | if_statement_prefix Punc_Braces_Left specific_update_statement* end_statement Punc_Braces_Right
  ;

if_statement_without_goto :
    if_statement_prefix read_or_write_or_check_statement // only one statement
  | if_statement_prefix if_statement_without_goto // only one statement
  | if_statement_prefix Punc_Braces_Left (read_or_write_or_check_statement|if_statement_without_goto)* Punc_Braces_Right
  ;

if_statement_prefix :
    CKeyword_if Punc_Parenthesis_Left bool_expression Punc_Parenthesis_Right
  ;

goto_statement : // done
    CKeyword_goto identifier Punc_Semicolon
  ;

bool_expression : // done
    Punc_Parenthesis_Left bool_expression Punc_Parenthesis_Right // issue
  | Punc_Exclamation bool_expression
  | bool_expression Punc_Ampersand Punc_Ampersand bool_expression
  | bool_expression Punc_Vertical_Bar Punc_Vertical_Bar bool_expression
  | bool_expression Punc_Caret bool_expression
  //| Punc_Exclamation bool_expression
  | identifier Punc_Equal constant
  | identifier
  ;

constant : // done
    integer_literal
  | floating_literal
  | bit_literal
  ;

assert_statement : // done
    CKeyword_assert Punc_Parenthesis_Left integer_literal Punc_Parenthesis_Right Punc_Semicolon
  ;

identifier : // done
    Identifier
  ;
