module neg(pclP, pclN, selN);

input [16:0] pclP;  // [16:9] is i, [8:1] is j, [0] is operation.

output [15:0] pclN; // [15:8] is i, [7:0] is j
output  [1:0] selN;

wire [15:0] pclN;
wire  [1:0] selN;
wire  [7:0] abs;

assign abs = 8'b0 - pclP[16:9];
assign pclN = {abs, pclP[8:1]};
assign selN = (pclP[16])? ((pclP[0])? 2'b01 : 2'b10) : 2'b0;

endmodule
