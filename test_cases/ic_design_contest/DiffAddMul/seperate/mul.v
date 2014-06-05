module mul(pclP1, pclP2, stateIn, stateOut, pclN1, pclN2, done);

input [15:0] pclP1;
input  [7:0] pclP2;
input  [2:0] stateIn;

output [2:0] stateOut;
output [7:0] pclN1;
output [7:0] pclN2;
output       done;

reg  [2:0] stateOut;
reg  [7:0] pclN1;
reg  [7:0] pclN2;
reg        done;

wire [3:0] a;
wire [3:0] b;
wire [3:0] c;
wire [3:0] d;
wire [7:0] a_mult_d;
wire [7:0] a_mult_c;
wire [7:0] b_mult_c;
wire [7:0] a_mult_d_high;
wire [7:0] b_mult_c_high;

assign a = pclP1[11: 8];
assign b = pclP1[15:12];
assign c = pclP1[ 3: 0];
assign d = pclP1[ 7: 4];

assign a_mult_d = a * d;
assign a_mult_c = a * c;
assign b_mult_c = b * c;
assign a_mult_d_high = {a_mult_d[3:0], 4'b0};
assign b_mult_c_high = {b_mult_c[3:0], 4'b0};

always @ (*) begin
    case (stateIn) 
        3'b000 : stateOut = (a == 4'h0) ? 3'b001 : 3'b010;
        3'b001 : stateOut = (b == 4'h0) ? 3'b111 : 3'b111;
        3'b010 : stateOut = (b == 4'h0) ? 3'b011 : 3'b100;
        3'b011 : stateOut = 3'b111;
        3'b100 : stateOut = (d == 4'h0) ? 3'b111 : 3'b110;
        3'b110 : stateOut = 3'b111;
        3'b111 : stateOut = 3'b000;
        default: stateOut = 3'b111;
    endcase
end

always @ (*) begin
    case (stateIn) 
        3'b111 : pclN1 = pclP2;
        default: pclN1 = 8'h0;
    endcase
end

always @ (*) begin
    case (stateIn)
        3'b000 : pclN2 = (a == 4'h0) ? b_mult_c      : a_mult_c;
        3'b001 : pclN2 = (b == 4'h0) ? 8'h0          : pclP2;
        3'b010 : pclN2 =((b == 4'h0) ? a_mult_d_high : b_mult_c_high) + pclP2;
        3'b011 : pclN2 = pclP2;
        3'b100 : pclN2 =((d == 4'h0) ? 8'h0          : a_mult_d_high) + pclP2;
        3'b110 : pclN2 = pclP2;
        default: pclN2 = 8'h0;
    endcase
end

always @ (*) begin
    case (stateIn) 
        3'b111 : done = 1'b1;
        default: done = 1'b0;
    endcase
end

endmodule
