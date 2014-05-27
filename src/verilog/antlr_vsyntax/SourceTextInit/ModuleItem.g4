parser grammar ModuleItem ;

import Statement, ModuleItemDeclaration, ContinuousAssign, GateInstantiation, ModuleInstantiation  ;

module_item :
    always_construct   
  | module_item_declaration
//  | parameter_override
  | continuous_assign
  | gate_instantiation
//  | udp_instantiation
  | module_instantiation
//  | specify_block
  | initial_construct
  ;


keyword_always : VerilogKeyword_always ;

keyword_initial : VerilogKeyword_initial ;

always_construct : keyword_always statement ;


initial_construct : keyword_initial statement ;
