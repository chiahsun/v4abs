parser grammar ProceduralContinuousAssignment ;

keyword_assign : VerilogKeyword_assign ;

procedural_continuous_assignment : keyword_assign reg_assignment PUNC_SEMICOLON
//                               | deassign reg_lvalue PUNC_SEMICOLON
//                               | force reg_assignment PUNC_SEMICOLON
//                               | force net_assignment PUNC_SEMICOLON
//                               | release reg_lvalue PUNC_SEMICOLON
//                               | release net_lvalue PUNC_SEMICOLON
                                 ;

reg_assignment : reg_lvalue PUNC_EQUAL expression ;
