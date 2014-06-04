module Ite(clk);

reg reg_b, reg_c, reg_d;

wire [1:0] a;
assign a = reg_b ? 2'b00
         : reg_c ? 2'b01
         : reg_d ? 2'b10
         : 2'b11;

endmodule
