grammar Keyword ;

import CommonLexerRules ;

init : keywords ;

keywords : VerilogKeyword_reg
         | VerilogKeyword_if
         | VerilogKeyword_else
         | VerilogKeyword_begin
         | VerilogKeyword_end
         | VerilogMacro_define
         | VerilogMacro_timescale ;
