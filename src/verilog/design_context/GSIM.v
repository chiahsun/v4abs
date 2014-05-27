
module GAUSS_ITER(clk, reset, en, packed_B, valid, X_out);
input clk;
input reset;
input en;
input [255:0] packed_B;

output valid;
output [31:0] X_out;

reg [15:0] B [0:15];

reg [15:0] A [0:15][0:15];


reg [3:0] output_cnt;
reg [3:0] next_output_cnt;

wire [31:0] X_out;
reg [31:0] next_X_out;

reg [7:0] reg_i;
reg [7:0] next_reg_i;
reg [3:0] reg_k;
reg [3:0] next_reg_k;

reg [15:0] C;
reg [15:0] next_C;

parameter X_WIDTH = 48; // 16 + 16 + 16
reg [X_WIDTH-1:0] X[0:15];
reg [X_WIDTH-1:0] next_X[0:15];
integer i, k;

wire [15:0] debug_B0;
wire [15:0] debug_B1;
wire [15:0] debug_B14;
wire [15:0] debug_B15;

assign debug_B0 = B[0];
assign debug_B1 = B[1];
assign debug_B14 = B[14];
assign debug_B15 = B[15];

wire [31:0] debug_X0, debug_X1, debug_X2, debug_X3
          , debug_X12, debug_X13, debug_X14, debug_X15;

assign debug_X0 = X[0][X_WIDTH-1:X_WIDTH-32];
assign debug_X1 = X[1][X_WIDTH-1:X_WIDTH-32];
assign debug_X2 = X[2][X_WIDTH-1:X_WIDTH-32];
assign debug_X3 = X[3][X_WIDTH-1:X_WIDTH-32];
assign debug_X12 = X[12][X_WIDTH-1:X_WIDTH-32];
assign debug_X13 = X[13][X_WIDTH-1:X_WIDTH-32];
assign debug_X14 = X[14][X_WIDTH-1:X_WIDTH-32];
assign debug_X15 = X[15][X_WIDTH-1:X_WIDTH-32];

always @ (*) begin
    B[0]  = packed_B[15:0];
    B[1]  = packed_B[31:16];
    B[2]  = packed_B[47:32];
    B[3]  = packed_B[63:48];
    B[4]  = packed_B[79:64];
    B[5]  = packed_B[95:80];
    B[6]  = packed_B[111:96];
    B[7]  = packed_B[127:112];
    B[8]  = packed_B[143:128];
    B[9]  = packed_B[159:144];
    B[10] = packed_B[175:160];
    B[11] = packed_B[191:176];
    B[12] = packed_B[207:192];
    B[13] = packed_B[223:208];
    B[14] = packed_B[239:224];
    B[15] = packed_B[255:240];
end

// always @ (*) begin
initial begin
    for (i = 0; i < 16; i = i + 1)
        for (k = 0; k < 16; k = k + 1)
            A[k][i] = 0;
    A[0][0] = 20;
    A[0][1] = -13;
    A[0][2] = 6;
    A[0][3] = -1;
    A[1][0] = -13;
    A[1][1] = A[0][0];
    A[1][2] = A[0][1];
    A[1][3] = A[0][2];
    A[1][4] = A[0][3];
    A[2][0] = 6;
    A[2][1] = A[1][0];
    A[2][2] = A[1][1];
    A[2][3] = A[1][2];
    A[2][4] = A[1][3];
    A[2][5] = A[1][4];
    A[3][0] = -1;
    A[3][1] = A[2][0];
    A[3][2] = A[2][1];
    A[3][3] = A[2][2];
    A[3][4] = A[2][3];
    A[3][5] = A[2][4];
    A[3][6] = A[2][5];
    A[4][1] = A[3][0];
    A[4][2] = A[3][1];
    A[4][3] = A[3][2];
    A[4][4] = A[3][3];
    A[4][5] = A[3][4];
    A[4][6] = A[3][5];
    A[4][7] = A[3][6];
    A[5][2] = A[3][0];
    A[5][3] = A[3][1];
    A[5][4] = A[3][2];
    A[5][5] = A[3][3];
    A[5][6] = A[3][4];
    A[5][7] = A[3][5];
    A[5][8] = A[3][6];
    A[6][3] = A[3][0];
    A[6][4] = A[3][1];
    A[6][5] = A[3][2];
    A[6][6] = A[3][3];
    A[6][7] = A[3][4];
    A[6][8] = A[3][5];
    A[6][9] = A[3][6];
    A[7][4] = A[3][0];
    A[7][5] = A[3][1];
    A[7][6] = A[3][2];
    A[7][7] = A[3][3];
    A[7][8] = A[3][4];
    A[7][9] = A[3][5];
    A[7][10] = A[3][6];
    A[8][5] = A[3][0];
    A[8][6] = A[3][1];
    A[8][7] = A[3][2];
    A[8][8] = A[3][3];
    A[8][9] = A[3][4];
    A[8][10] = A[3][5];
    A[8][11] = A[3][6];
    A[9][6] = A[3][0];
    A[9][7] = A[3][1];
    A[9][8] = A[3][2];
    A[9][9] = A[3][3];
    A[9][10] = A[3][4];
    A[9][11] = A[3][5];
    A[9][12] = A[3][6];
    A[10][7] = A[3][0];
    A[10][8] = A[3][1];
    A[10][9] = A[3][2];
    A[10][10] = A[3][3];
    A[10][11] = A[3][4];
    A[10][12] = A[3][5];
    A[10][13] = A[3][6];
    A[11][8] = A[3][0];
    A[11][9] = A[3][1];
    A[11][10] = A[3][2];
    A[11][11] = A[3][3];
    A[11][12] = A[3][4];
    A[11][13] = A[3][5];
    A[11][14] = A[3][6];
    A[12][9] = A[3][0];
    A[12][10] = A[3][1];
    A[12][11] = A[3][2];
    A[12][12] = A[3][3];
    A[12][13] = A[3][4];
    A[12][14] = A[3][5];
    A[12][15] = A[3][6];
    A[13][10] = A[3][0];
    A[13][11] = A[3][1];
    A[13][12] = A[3][2];
    A[13][13] = A[3][3];
    A[13][14] = A[3][4];
    A[13][15] = A[3][5];
    A[14][11] = A[3][0];
    A[14][12] = A[3][1];
    A[14][13] = A[3][2];
    A[14][14] = A[3][3];
    A[14][15] = A[3][4];
    A[15][12] = A[3][0];
    A[15][13] = A[3][1];
    A[15][14] = A[3][2];
    A[15][15] = A[3][3]; 
end

wire [31:0] debug_A0_0;
wire [31:0] debug_A0_1;
wire [31:0] debug_A15_14;
wire [31:0] debug_A15_15;
assign debug_A0_0 = A[0][0];
assign debug_A0_1 = A[0][1];
assign debug_A15_14 = A[15][14];
assign debug_A15_15 = A[15][15];

reg [2:0] state;
reg [2:0] next_state;

parameter STATE_BEGIN = 3'b000
        , STATE_OUT_ITER = STATE_BEGIN + 1
        , STATE_INNER_ITER = STATE_OUT_ITER + 1
        , STATE_OUTPUT = STATE_INNER_ITER + 1
        , STATE_END = STATE_OUTPUT + 1;
parameter STATE_INIT = STATE_BEGIN
        , OUTPUT_CNT_INIT = 0
        , X_OUT_INIT = 0
        , C_DEFAULT = 16'b1111_1111_1111_1110
        , REG_I_DEFAULT = 6'b0
        , REG_K_DEFAULT = 4'b0;

assign valid = (state == STATE_OUTPUT);

always @ (posedge clk) begin
    for (i = 0; i < 16; i = i + 1) begin
        X[i] <= next_X[i];
    end
end

wire [15:0] C_shift_left;
assign C_shift_left = {C[14:0], 1'b1};

reg [X_WIDTH-1+16:0] cax_sum;

        
always @ (*) begin
    cax_sum = (C[0] ? ({{48{A[reg_k][0][15]}}, A[reg_k][0]} * 64'h0CCCCCCD* {{32{X[0][47]}}, X[0][47:16]}) : 0)
                   + (C[1] ? ({{48{A[reg_k][1][15]}}, A[reg_k][1]} * 64'h0CCCCCCD* {{32{X[1][47]}}, X[1][47:16]}) : 0) 
                   + (C[2] ? ({{48{A[reg_k][2][15]}}, A[reg_k][2]} * 64'h0CCCCCCD* {{32{X[2][47]}}, X[2][47:16]}) : 0) 
                   + (C[3] ? ({{48{A[reg_k][3][15]}}, A[reg_k][3]} * 64'h0CCCCCCD* {{32{X[3][47]}}, X[3][47:16]}) : 0)
                   + (C[4] ? ({{48{A[reg_k][4][15]}}, A[reg_k][4]} * 64'h0CCCCCCD* {{32{X[4][47]}}, X[4][47:16]}) : 0) 
                   + (C[5] ? ({{48{A[reg_k][5][15]}}, A[reg_k][5]} * 64'h0CCCCCCD* {{32{X[5][47]}}, X[5][47:16]}) : 0) 
                   + (C[6] ? ({{48{A[reg_k][6][15]}}, A[reg_k][6]} * 64'h0CCCCCCD* {{32{X[6][47]}}, X[6][47:16]}) : 0) 
                   + (C[7] ? ({{48{A[reg_k][7][15]}}, A[reg_k][7]} * 64'h0CCCCCCD* {{32{X[7][47]}}, X[7][47:16]}) : 0) 
                   + (C[8] ? ({{48{A[reg_k][8][15]}}, A[reg_k][8]} * 64'h0CCCCCCD* {{32{X[8][47]}}, X[8][47:16]}) : 0) 
                   + (C[9] ? ({{48{A[reg_k][9][15]}}, A[reg_k][9]} * 64'h0CCCCCCD* {{32{X[9][47]}}, X[9][47:16]}) : 0) 
                   + (C[10] ? ({{48{A[reg_k][10][15]}}, A[reg_k][10]} * 64'h0CCCCCCD* {{32{X[10][47]}}, X[10][47:16]}) : 0) 
                   + (C[11] ? ({{48{A[reg_k][11][15]}}, A[reg_k][11]} * 64'h0CCCCCCD* {{32{X[11][47]}}, X[11][47:16]}) : 0) 
                   + (C[12] ? ({{48{A[reg_k][12][15]}}, A[reg_k][12]} * 64'h0CCCCCCD* {{32{X[12][47]}}, X[12][47:16]}) : 0) 
                   + (C[13] ? ({{48{A[reg_k][13][15]}}, A[reg_k][13]} * 64'h0CCCCCCD* {{32{X[13][47]}}, X[13][47:16]}) : 0) 
                   + (C[14] ? ({{48{A[reg_k][14][15]}}, A[reg_k][14]} * 64'h0CCCCCCD* {{32{X[14][47]}}, X[14][47:16]}) : 0) 
                   + (C[15] ? ({{48{A[reg_k][15][15]}}, A[reg_k][15]} * 64'h0CCCCCCD* {{32{X[15][47]}}, X[15][47:16]}) : 0); 
  
end

always @ (*) begin
    next_state = state;
    next_output_cnt = output_cnt;
    next_X_out = X_out;
    next_C = C;
    next_reg_i = reg_i;
    next_reg_k = reg_k;
    for (i = 0; i < 16; i = i + 1)
        next_X[i] = X[i];
    case (state)
        STATE_BEGIN: begin
            next_state = (en) ? STATE_OUT_ITER : state;
            for (i = 0; i < 16; i = i + 1)
                next_X[i] = {{32{B[i][15]}}, B[i]} * 48'h00000CCCCCCD; 
// 1.
//            for (i = 0; i < 16; i = i + 1)
  //              next_X[i] = {{(ADDITIONAL_WIDTH+16){B[i][15]}}, B[i]} * CONSTANT;
// 2.    
            // next_X[i] = {{16{B[15]}}, B[i]} * 32'h0000_0CCC;
        end
        STATE_OUT_ITER: begin
            next_reg_i = reg_i + 1;
            next_state = (reg_i == 120) ? STATE_OUTPUT : STATE_INNER_ITER;
            next_C = C_DEFAULT;
            next_reg_k = REG_K_DEFAULT;
        end
        STATE_INNER_ITER: begin
            next_reg_k = reg_k + 1;
            next_state = (reg_k == 15) ? STATE_OUT_ITER : state;
            next_C = C_shift_left;
            // next_X[reg_k] = {{16{B[reg_k][15]}}, B[reg_k], 16'b0} - cax_sum;
            next_X[reg_k] = {{32{B[reg_k][15]}}, B[reg_k]} * 48'h00000CCCCCCD - cax_sum[(47+16):(0+16)];
    //        next_X[reg_k] = mult;
        end
        STATE_OUTPUT: begin
            next_output_cnt = next_output_cnt + 1;    
            next_state = (output_cnt == 15) ? STATE_END : state;
        end
        STATE_END: begin
            
        end
    endcase
end

assign X_out = X[output_cnt][47:16];

always @ (posedge clk) begin
    if (reset) begin
        state <= STATE_INIT;
        output_cnt <= OUTPUT_CNT_INIT;
        C <= C_DEFAULT;
        reg_i <= REG_I_DEFAULT;
        reg_k <= REG_K_DEFAULT;
    end
    else begin
        state <= next_state;
        output_cnt <= next_output_cnt;
        C <= next_C;
        reg_i <= next_reg_i;
        reg_k <= next_reg_k;
    end
end


endmodule

module GSIM (clk, reset, in_en, b_in, out_valid, x_out);
input   clk ;
input   reset ;
input   in_en;
output  out_valid;
input   [15:0]  b_in;
output  [31:0]  x_out;


reg [3:0] state;
reg [3:0] next_state;

wire [15:0] debug_B0;
wire [15:0] debug_B1;
wire [15:0] debug_B14;
wire [15:0] debug_B15;

reg [15:0] B [0:15];

assign debug_B0 = B[0];
assign debug_B1 = B[1];
assign debug_B14 = B[14];
assign debug_B15 = B[15];


reg [15:0] next_B [0:15];

reg [255:0] packed_B;

reg [3:0] latch_cnt;
reg [3:0] next_latch_cnt;

reg gauss_iter_en;
reg next_gauss_iter_en;

parameter STATE_INIT = 3'b000
        , STATE_LATCH = STATE_INIT + 1
        , STATE_ITERATION = STATE_LATCH + 1;

parameter LATCH_CNT_INIT = 4'h0
        , GAUSS_ITER_EN_INIT = 1'b0;

integer i;

always @ (posedge clk) begin
    for (i = 0; i < 16; i = i + 1)
        B[i] <= next_B[i];
end


always @ (*) begin
    packed_B[15:0]    = B[0];
    packed_B[31:16]   = B[1];
    packed_B[47:32]   = B[2];
    packed_B[63:48]   = B[3];
    packed_B[79:64]   = B[4];
    packed_B[95:80]   = B[5];
    packed_B[111:96]  = B[6];
    packed_B[127:112] = B[7];
    packed_B[143:128] = B[8];
    packed_B[159:144] = B[9];
    packed_B[175:160] = B[10];
    packed_B[191:176] = B[11];
    packed_B[207:192] = B[12];
    packed_B[223:208] = B[13];
    packed_B[239:224] = B[14];
    packed_B[255:240] = B[15];
end

always @ (*) begin
    for (i = 0; i < 16; i = i + 1)
        next_B[i] = B[i];
        if (reset) begin
            next_B[i] = 0;
        end
        else begin
            case (state)
                STATE_LATCH: begin
                    next_B[latch_cnt] = (in_en) ? b_in : next_B[latch_cnt];
                end
            endcase 
        end
end

always @ (*) begin
    next_state = state;
    next_latch_cnt = latch_cnt;
    next_gauss_iter_en = gauss_iter_en;
    case (state)
        STATE_INIT: begin
            next_state = STATE_LATCH;
        end
        STATE_LATCH: begin
            next_state = (latch_cnt == 15) ? STATE_ITERATION : STATE_LATCH;
            next_latch_cnt = (in_en) ? (latch_cnt + 1) : latch_cnt;
        end
        STATE_ITERATION: begin
            next_gauss_iter_en = 1'b1;
        end
    endcase
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        state <= STATE_INIT;
        latch_cnt <= LATCH_CNT_INIT;
        gauss_iter_en <= GAUSS_ITER_EN_INIT;
    end
    else begin
        state <= next_state;
        latch_cnt <= next_latch_cnt;
        gauss_iter_en <= next_gauss_iter_en;
    end
end


GAUSS_ITER gauss_iter(.clk(clk), .reset(reset), .en(gauss_iter_en), .packed_B(packed_B), .valid(out_valid), .X_out(x_out));

endmodule
