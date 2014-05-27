if (reset) begin
    state <= STATE_INIT;
    latch_cnt <= LATCH_CNT_INIT;
    gauss_iter_en <= GAUSS_ITER_EN_INIT;
end
else begin
    state <= next_state;
    latch_cnt <= next_latch_cnt;
    gauss_iter_en <= next_gauss_iter_en;
end
