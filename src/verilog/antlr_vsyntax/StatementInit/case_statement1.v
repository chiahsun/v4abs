case (state)
    STATE_BEGIN : 
        next_state = (en) ? STATE_OUT_ITER : state;
    STATE_OUT_ITER : 
        next_state = (reg_i == 120) ? STATE_OUTPUT : STATE_INNER_ITER ;
endcase
