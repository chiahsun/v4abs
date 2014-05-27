module decode1(in1, sel, out1);

input  [1:0]   in1;
input  [2:0]   sel;
output [13:0]  out1;

reg [15:0] out1;

integer i;

always @ (in1 or sel) begin
    out2 = 14'h0; /* default = 00 */
    for (i = 0; i <= 7; i=i+1)
        if (i == sel) begin
            out1[i] = in1[0];
            out1[i+1] = in1[1];
        end
end

endmodule
