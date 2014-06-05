module add(pclP, pclN);

input [15:0] pclP; // [15:8] is i, [7:0] is j
output [7:0] pclN;

wire [7:0] pclN;
assign pclN = pclP[15:8] + pclP[7:0];

endmodule
