@ (posedge clk or negedge reset) begin
    if (reset) begin
        state <= STATE_INT;
    end
    else begin
        state <= next_state;
    end
end
