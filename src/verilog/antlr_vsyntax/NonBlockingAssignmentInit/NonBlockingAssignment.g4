parser grammar NonBlockingAssignment ;

import BlockingAssignment ;

non_blocking_assignment : reg_lvalue (PUNC_LESS_THAN PUNC_EQUAL) /* delay_or_event_control TODO */ expression ;

           
            

