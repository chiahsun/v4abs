module CTE(clk, reset, op_mode, in_en, yuv_in, rgb_in, busy, out_valid, rgb_out, yuv_out);
input clk, reset, op_mode, in_en;
input [7:0] yuv_in;
input [23:0] rgb_in;
output busy, out_valid;
output [23:0] rgb_out;
output [7:0] yuv_out;

wire yuv_to_rgb_in_en;
assign yuv_to_rgb_in_en = in_en;
wire yuv_to_rgb_busy;
wire yuv_to_rgb_out_valid;

assign busy = !op_mode ? yuv_to_rgb_busy : 1'b1;
assign out_valid = !op_mode ? yuv_to_rgb_out_valid : 1'b0;
assign yuv_out = 8'b0;

YUV_TO_RGB yuv_to_rgb_inst0(
    .clk(clk), 
    .reset(reset),
    .in_en(yuv_to_rgb_in_en), 
    .yuv_in(yuv_in),
    .busy(yuv_to_rgb_busy),
    .out_valid(yuv_to_rgb_out_valid),
    .rgb_out(rgb_out)
    );

endmodule

module YUV_TO_RGB(clk, reset, in_en, yuv_in, busy, out_valid, rgb_out);
input clk, reset, in_en;
input [7:0] yuv_in;
output busy, out_valid;
output [23:0] rgb_out;

reg [3:0] state;
reg [3:0] state_next;
parameter S_U      = 4'b0000; // first use
parameter S_Y1     = 4'b0001; 
parameter S_V      = 4'b0010;
parameter S_BUSY1  = 4'b0011;
parameter S_Y2     = 4'b0100;
parameter S_BUSY2  = 4'b0101;
assign busy = (state == S_BUSY1) || (state == S_BUSY2);
always @ (*) begin
    if(state == S_U) state_next <= S_Y1;
    else if(state == S_Y1) state_next <= S_V;
    else if(state == S_V) state_next <= S_BUSY1;
    else if(state == S_BUSY1) state_next <= S_Y2;
    else if(state == S_Y2) state_next <= S_BUSY2;
    else if(state == S_BUSY2) state_next <= S_U;
    else state_next <= state;
end

assign out_valid = (state == S_BUSY1) || (state == S_BUSY2);
reg [7:0] reg_U, reg_Y1, reg_V, reg_Y2;
wire [7:0] reg_U_next, reg_Y1_next, reg_V_next, reg_Y2_next;
assign reg_U_next = (state == S_U) ? yuv_in : reg_U;
assign reg_Y1_next = (state == S_Y1) ? yuv_in : reg_Y1;
assign reg_V_next = (state == S_V) ? yuv_in : reg_V;
assign reg_Y2_next = (state == S_Y2) ? yuv_in : reg_Y2;

// 8*6 -> 8+6-1+2(overflow)=15 bits
// 6+9-1 = 14 bits
wire [15:0] R_ext, G_ext, B_ext;
// Y U V with sign extension
wire [15:0] U_ext, Y_ext, V_ext;
assign U_ext = {{8{reg_U[7]}}, reg_U};
assign Y_ext = (state == S_BUSY1) ? {8'b0, reg_Y1} : {8'b0, reg_Y2};
assign V_ext = {{8{reg_V[7]}}, reg_V};
// R     1  0      1.625   Y
// G = [ 1  -0.25  -0.75 ] U
// B     1  2      0       V
//         v        v        v
// R   [0] 1000 [0] 0000 [0] 1101 - constants - 6 bits
// G = [0] 1000 [1] 1110 [1] 1010
// B   [0] 1000 [0]10000 [0] 0000
assign R_ext = 16'b1000 * Y_ext                     + 16'b1101 * V_ext;
assign G_ext = 16'b1000 * Y_ext + 16'hfffe * U_ext  + 16'hfffa * V_ext;
assign B_ext = 16'b1000 * Y_ext + 16'b10000 * U_ext;

wire [7:0] R_out, G_out, B_out;

assign R_out = R_ext[15] ? 8'b0 
               : ( R_ext[14:11] != 4'b0 ? 8'd255 : ((R_ext[2]) ? ((R_ext[10:3] == 8'd255) ? 8'd255 : (R_ext[10:3] + 8'd1))
                                                  : R_ext[10:3]));

assign G_out = G_ext[15] ? 8'b0 
               : ( G_ext[14:11] != 4'b0 ? 8'd255 : ((G_ext[2]) ? ((G_ext[10:3] == 8'd255) ? 8'd255 : (G_ext[10:3] + 8'd1))
                                                  : G_ext[10:3]));

assign B_out = B_ext[15] ? 8'b0 
               : ( B_ext[14:11] != 4'b0 ? 8'd255 : ((B_ext[2]) ? ((B_ext[10:3] == 8'd255) ? 8'd255 : (B_ext[10:3] + 8'd1))
                                                  : B_ext[10:3]));

assign rgb_out = {R_out, G_out, B_out};

always @ (posedge clk) begin
    if(reset || !in_en) begin
        state <= S_U;
        reg_U <= 8'b0; 
        reg_Y1 <= 8'b0;
        reg_V <= 8'b0;
        reg_Y2 <= 8'b0;
    end
    else begin
        state <= state_next;
        reg_U <= reg_U_next;
        reg_Y1 <= reg_Y1_next;
        reg_V <= reg_V_next;
        reg_Y2 <= reg_Y2_next;
    end
end

endmodule

