// SUB MODULE ===============================
module sub(pclP, pclN1, pclN2, selN);

input [24:0] pclP; // [24:17] is i, [16:9] is j, [8:1] is k, [0] is operation.

output [17:0] pclN1; // [16:9] is i, [8:1] is j, [0] is operation.
output [15:0] pclN2; // [15:8] is i, [7:0] is j
output  [2:0] selN;

wire [17:0] pclN1;
wire [15:0] pclN2;
wire  [8:0] diff;
wire  [2:0] selN;

assign diff  = {1'b0, pclP[24:17]} - {1'b0, pclP[16:9]};
assign pclN1 = {diff, pclP[8:0]};
assign pclN2 = {diff[7:0], pclP[8:1]};
assign selN  = (diff[8])? 3'b001 : ((pclP[0])? 3'b010 : 3'b100);

endmodule

// NEG MODULE ===============================
module neg(pclP, pclN, selN);

input [17:0] pclP;  // [16:9] is i, [8:1] is j, [0] is operation.

output [15:0] pclN; // [15:8] is i, [7:0] is j
output  [1:0] selN;

wire [15:0] pclN;
wire  [1:0] selN;
wire  [7:0] abs;

assign abs = 8'b0 - pclP[16:9];
assign pclN = {abs, pclP[8:1]};
assign selN = (pclP[17])? ((pclP[0])? 2'b01 : 2'b10) : 2'b0;

endmodule

// MUL MODULE ===============================
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

assign a_mult_d = {4'b0, a} * {4'b0, d};
assign a_mult_c = {4'b0, a} * {4'b0, c};
assign b_mult_c = {4'b0, b} * {4'b0, c};
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

// ADD MODULE ===============================
module add(pclP, pclN);

input [15:0] pclP; // [15:8] is i, [7:0] is j
output [7:0] pclN;

wire [7:0] pclN;
assign pclN = pclP[15:8] + pclP[7:0];

endmodule

// TOP MODULE ===============================
module top(clk, rst, i, j, k, operation, vo, in_valid, out_valid);

input        clk;
input        rst;
input  [7:0] i;
input  [7:0] j;
input  [7:0] k;
input        operation;
output [7:0] vo;
output       in_valid;  // Control the input 
output       out_valid; // Control the output

// This is for SUB
wire [24:0] rSub;
wire [17:0] sub_out1; // [16:9] is i, [8:1] is j, [0] is operation.
wire [15:0] sub_out2; // [15:8] is i, [7:0] is j
wire  [2:0] sub_sel;

// This is for NEG
wire [17:0] rNeg;
wire [15:0] neg_out;  // [15:8] is i, [7:0] is j
wire  [1:0] neg_sel;

// This is for ADD
wire [15:0] rAdd;
wire  [7:0] out_Add;

// This is for MULT
wire [15:0] rMul1;    // [15:8] is i, [7:0] is j
wire  [2:0] mul_stateOut1, mul_stateOut2, mul_stateOut3, mul_stateOut4, mul_stateOut5, mul_stateOut6;
wire  [7:0] out_Mul1,  out_Mul2,  out_Mul3,  out_Mul4,  out_Mul5;
wire  [7:0] mul_out1,  mul_out2,  mul_out3,  mul_out4,  mul_out5;
wire        mul_done1, mul_done2, mul_done3, mul_done4, mul_done5;

// This is for top design
wire  [7:0] vo;
wire        in_valid;
wire        out_valid;
wire        op_Add;
wire        op_Mul;

reg   [7:0] v3_1399283769_output_next_vo;
reg         v3_1399283769_output_next_in_valid;
reg         v3_1399283769_output_next_out_valid;

// Output Net Assignments
assign vo = v3_1399283769_output_next_vo;
assign in_valid = v3_1399283769_output_next_in_valid;
assign out_valid = v3_1399283769_output_next_out_valid;

// This is for modulo
sub sub_inst0(.pclP(rSub), .pclN1(sub_out1), .pclN2(sub_out2), .selN(sub_sel));
neg neg_inst1(.pclP(rNeg), .pclN(neg_out), .selN(neg_sel));
add add_inst2(.pclP(rAdd), .pclN(out_Add));

mul mul_inst1(.pclP1(rMul1), .pclP2(8'b0), .stateIn(3'b000), 
              .stateOut(mul_stateOut1), .pclN1(out_Mul1), .pclN2(mul_out1), .done(mul_done1));

mul mul_inst2(.pclP1(rMul1), .pclP2(mul_out1), .stateIn(mul_stateOut1), 
              .stateOut(mul_stateOut2), .pclN1(out_Mul2), .pclN2(mul_out2), .done(mul_done2));

mul mul_inst3(.pclP1(rMul1), .pclP2(mul_out2), .stateIn(mul_stateOut2), 
              .stateOut(mul_stateOut3), .pclN1(out_Mul3), .pclN2(mul_out3), .done(mul_done3));

mul mul_inst4(.pclP1(rMul1), .pclP2(mul_out3), .stateIn(mul_stateOut3), 
              .stateOut(mul_stateOut4), .pclN1(out_Mul4), .pclN2(mul_out4), .done(mul_done4));

mul mul_inst5(.pclP1(rMul1), .pclP2(mul_out4), .stateIn(mul_stateOut4), 
              .stateOut(mul_stateOut5), .pclN1(out_Mul5), .pclN2(mul_out5), .done(mul_done5));
/*
mul mul_inst6(.pclP1(rMul1), .pclP2(mul_out5), .stateIn(mul_stateOut5), 
              .stateOut(mul_stateOut6), .pclN1(out_Mul6), .pclN2(mul_out6), .done(mul_done6));
*/
assign rSub   = (rst)? 25'b1 : {i, j, k, operation};
assign rNeg   = (rst)? 18'b0 : sub_out1;
assign rAdd   = (rst)? 16'b0 : (!op_Add)? 16'h0 : ((neg_sel == 2'b0)? sub_out2 : neg_out);
assign rMul1  = (rst)? 16'b0 : (!op_Mul)? 16'h0 : ((neg_sel == 2'b0)? sub_out2 : neg_out);
assign op_Add = sub_sel[1] || neg_sel[0];
assign op_Mul = sub_sel[2] || neg_sel[1];
 
   // Non-blocking Assignments
   always @ (posedge clk) begin
      v3_1399283769_output_next_vo <=        (rst)?                     8'b0 :
                                             (op_Add)?               out_Add :
                                             (op_Mul && mul_done1)?     8'b0 :
                                             (op_Mul && mul_done2)? mul_out1 :
                                             (op_Mul && mul_done3)? mul_out2 :
                                             (op_Mul && mul_done4)? mul_out3 :
                                             (op_Mul && mul_done5)? mul_out4 : 8'b0;
      v3_1399283769_output_next_in_valid  <= 1'b1;
      v3_1399283769_output_next_out_valid <= (rst)?                     1'b0 :
                                             (op_Add)?                  1'b1 :
                                             (op_Mul && mul_done1)?     1'b1 :
                                             (op_Mul && mul_done2)?     1'b1 :
                                             (op_Mul && mul_done3)?     1'b1 :
                                             (op_Mul && mul_done4)?     1'b1 :
                                             (op_Mul && mul_done5)?     1'b1 : 1'b0;
   end

endmodule
