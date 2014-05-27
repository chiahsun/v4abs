always @ (posedge clk) begin
    if (reset) begin
        state <= STATE_INIT;
        reg_i <= REG_I_DEFAULT;
    end
    else begin
        state <= next_state;
        reg_i <= next_reg_i;
    end
end
