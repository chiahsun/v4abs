case (state)
    STATE_BEGIN : 
        next_state = state;
    STATE_OUT_ITER : 
        next_state = STATE_OUTPUT;
endcase
