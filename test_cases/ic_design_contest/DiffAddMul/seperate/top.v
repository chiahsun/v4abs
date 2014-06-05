module top(clk, rst, i, j, k, operation, vo1, vo2, valid);

input        clk;
input        rst;
input  [7:0] i;
input  [7:0] j;
input  [7:0] k;
input        operation;
output [7:0] vo1; // vo1 is for add output
output [7:0] vo2; // vo2 is for mul output
output       valid; // Control the input 

// register
reg  [24:0] next_rSub;
reg  [16:0] next_rNeg;
reg  [15:0] next_rAdd;
reg  [15:0] next_rMul1;
reg   [7:0] next_rMul2;
reg   [2:0] next_stateIn;

// This is for SUB
reg  [24:0] rSub;
wire [16:0] sub_out1; // [16:9] is i, [8:1] is j, [0] is operation.
wire [15:0] sub_out2; // [15:8] is i, [7:0] is j
wire  [2:0] sub_sel;

// This is for NEG
reg  [16:0] rNeg;     // [16:9] is i, [8:1] is j, [0] is operation.
wire [15:0] neg_out;  // [15:8] is i, [7:0] is j
wire  [1:0] neg_sel;

// This is for ADD
reg  [15:0] rAdd;     // [15:8] is i, [7:0] is j
wire  [7:0] out_Add;

// This is for MULT
reg  [15:0] rMul1;    // [15:8] is i, [7:0] is j
reg   [7:0] rMul2;
reg   [2:0] stateIn;
wire  [2:0] stateOut;
wire  [7:0] out_Mul;
wire  [7:0] mul_out2;
wire        done;

// This is for top design
reg         op_Add;
reg         op_Mul;
reg         next_op_Add;
reg         next_op_Mul;
reg         valid;
wire        stall_Add;
wire        stall_Mul;

reg         c_done;
reg         next_c_done;

reg   [7:0] vo1;
reg   [7:0] vo2;

assign stall_Mul   = (sub_sel == 3'b100 && neg_sel != 2'b0);
assign stall_Add   = (sub_sel == 3'b010 && neg_sel != 2'b0);

// This is for modulo
sub sub_inst0(.pclP(rSub), .pclN1(sub_out1), .pclN2(sub_out2), .selN(sub_sel));
neg neg_inst1(.pclP(rNeg), .pclN(neg_out), .selN(neg_sel));
add add_inst2(.pclP(rAdd), .pclN(out_Add));
mul mul_inst2(.pclP1(rMul1), .pclP2(rMul2), .stateIn(stateIn), 
              .stateOut(stateOut), .pclN1(out_Mul), .pclN2(mul_out2), .done(done));

always @ (*) begin
    if (rst) begin
        next_op_Add  =  1'b0;
        next_op_Mul  =  1'b0;
        valid        =  1'b1;
        next_rSub    = 25'b1;
        next_rNeg    = 17'b0;
        next_rAdd    = 16'b0;
        next_rMul1   =  8'b0;
        next_rMul2   =  8'b0;
        next_stateIn =  3'b111;
        vo1          =  8'hz;
        vo2          =  8'hz;
        next_c_done  =  1'b0;
    end
    else begin
        next_op_Add  = (stall_Add)? neg_sel[0] : (sub_sel[1] || neg_sel[0]);
        next_op_Mul  = (stall_Mul)? neg_sel[1] : (sub_sel[2] || neg_sel[1]);
        valid        = (!done)?          1'b0  : (!stall_Mul && !stall_Add);

        next_rSub    = (!valid)?         rSub  : {i, j, k, operation};
        next_rNeg    = (!done)?          rNeg  : sub_out1;
        next_rAdd    = (!done)?          rAdd  :
                       (!next_op_Add)?   16'hz : (neg_sel == 2'b0)? sub_out2 : neg_out;
        next_rMul1   = (!done)?          rMul1 : 
                       (!next_op_Mul)?   16'hz : (neg_sel == 2'b0)? sub_out2 : neg_out;
        next_rMul2   = (done)?           rMul2 : mul_out2;
        next_stateIn = (done && !op_Mul && !next_op_Mul)? 3'b111 : stateOut;

        vo1          = (op_Add && done && !c_done)?  out_Add : 8'hz;
        vo2          = (c_done)?                     out_Mul : 8'hz;

        next_c_done  = (stateOut == 3'b111)? 1'b1 : 1'b0;
    end
end

always @ (posedge clk) begin
    if (rst) begin
        rSub    <= 25'b1;
        rNeg    <= 17'b0;
        rAdd    <= 16'b0;
        rMul1   <=  8'b0;
        rMul2   <=  8'b0;
        stateIn <=  3'b111;
        op_Add  <=  1'b0;
        op_Mul  <=  1'b0;
        c_done  <=  1'b0;
    end
    else begin
        rSub    <= next_rSub;
        rNeg    <= next_rNeg;
        rAdd    <= next_rAdd;
        rMul1   <= next_rMul1;
        rMul2   <= next_rMul2;
        stateIn <= next_stateIn;
        op_Add  <= next_op_Add;
        op_Mul  <= next_op_Mul;
        c_done  <= next_c_done;
    end
end

endmodule
