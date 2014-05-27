parser grammar SeqBlock ;

keyword_begin : VerilogKeyword_begin ;

keyword_end : VerilogKeyword_end ;

seq_block : keyword_begin statement* keyword_end ;
