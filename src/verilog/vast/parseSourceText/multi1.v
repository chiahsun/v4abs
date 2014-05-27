module multi1 (in1, in2, out1, out2) ;

input [3:0] in1, in2;
output [3:0] out1, out2;

wire [3:0] out1;
wire [1:0] out2;

assign out1 = in1 & in;
assign out2[1:0] = in1[3:2] ^ in2[1:0];
assign out2[3:2] = in1[1:0] | in2[3:2];

endmodule
