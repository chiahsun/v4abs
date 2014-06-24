case ({cond1[8], cond2[8], cond3[8]})
    3'b111:  s_out = a1;
    3'b110:  s_out = a2;
    3'b100:  s_out = a0;
    3'b011:  s_out = a0;
    3'b001:  s_out = a2;
    3'b000:  s_out = a1;
    default: s_out = 8'hz;
endcase
