module multi2 (in1, in2, out1, out2);

input [7:0] in1;
input [1:0] in2;
output [1:0] out1;
output out2;

assign out1 = (in1 >> 2) | in2;
assign out2 = in1[in2];

endmodule
