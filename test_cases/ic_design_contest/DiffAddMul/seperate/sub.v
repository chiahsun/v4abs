module sub(pclP, pclN1, pclN2, selN);

input [24:0] pclP; // [24:17] is i, [16:9] is j, [8:1] is k, [0] is operation.

output [16:0] pclN1; // [16:9] is i, [8:1] is j, [0] is operation.
output [15:0] pclN2; // [15:8] is i, [7:0] is j
output  [2:0] selN;

wire [16:0] pclN1;
wire [15:0] pclN2;
wire  [8:0] diff;
reg   [2:0] selN;

assign diff  = {1'b0, pclP[24:17]} - {1'b0, pclP[16:9]};
assign pclN1 = {diff[7:0], pclP[8:0]};
assign pclN2 = {diff[7:0], pclP[8:1]};

always @ (*) begin
    selN  = (diff[8])? 3'b001 : 
            (pclP[0])? 3'b010 : 3'b100;
end

endmodule
