parser grammar Statement ;

// import BlockingAssignment, ConditionalStatement, CaseStatement ;
import BlockingAssignment
     , NonBlockingAssignment
     , ConditionalStatement
     , CaseStatement
     , ProceduralContinuousAssignment
     , ProceduralTimingControlStatement
     , LoopStatement
     , SeqBlock ;

statement : blocking_assignment PUNC_SEMICOLON
          | non_blocking_assignment PUNC_SEMICOLON
          | procedural_continuous_assignment PUNC_SEMICOLON
          | procedural_timing_control_statement 
          | conditional_statement
          | case_statement 
          | loop_statement
    //   | wait_statement
    //   | disable_statement
    //   | event_trigger
          | seq_block 
    //   | par_block
    //   | task_enable
    //   | system_task_enable 
          ;
