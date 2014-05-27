if (reset) begin
    next_B[i] = 0;
end
else begin
    case (state)
        STATE_LATCH: begin
            next_B[latch_cnt] = (in_en) ? b_in : next_B[latch_cnt] ;
        end
    endcase
end
