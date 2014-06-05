`include "./bsort.v"


module bsort_49(data_in, data_out);


input   [391:0] data_in;
output  [7:0] data_out;

wire    [511:0] c_in;
wire    [511:0] c_out;

assign  c_in[391:0]   = data_in;
assign  c_in[511:392] = 0;

assign  data_out[3:0] = c_out[315:312];
assign  data_out[7:4] = c_out[319:316];
bsort b1(.data_in(c_in), .data_out(c_out));


endmodule
