`timescale 1ns/10ps
module CTE ( clk, reset, op_mode, in_en, yuv_in, rgb_in, busy, out_valid, rgb_out, yuv_out);
input   clk ;
input   reset ;
input   op_mode;
input   in_en;
output  busy;
output  out_valid;
input   [7:0]   yuv_in;
output  [23:0]  rgb_out;
input   [23:0]  rgb_in;
output  [7:0]   yuv_out;

// --------------------------------------------
// control
wire   clk_p, reset_n;
assign clk_p = clk;
assign reset_n = reset;

reg           busy_yuv_to_rgb, busy_rgb_to_yuv;	
reg           valid_yuv_to_rgd, valid_rgb_to_yuv;

assign busy = (busy_yuv_to_rgb||busy_rgb_to_yuv);
assign out_valid = valid_yuv_to_rgd || valid_rgb_to_yuv;

// --------------------------------------------
// data path YUV_to_RGB
reg     [7:0] Y_d1_1_w;
reg     [7:0] Y_d1_2_w;
reg     [7:0] U_d1_w;
reg     [7:0] V_d1_w;
wire    [7:0] Y_d1_r;
wire    [7:0] U_d1_r;
wire    [7:0] V_d1_r;


reg     [2:0] state_read_yuv;
reg           YUV_firstY_bit;
parameter STATE_READ_U          = 3'b000
        , STATE_READ_Y1         = 3'b001
	, STATE_READ_V          = 3'b010
        , STATE_COMPUTE_RGB_1   = 3'b011
        , STATE_OUT_RGB_1       = 3'b100
	, STATE_READ_Y2         = 3'b101
        , STATE_COMPUTE_RGB_2   = 3'b110
        , STATE_OUT_RGB_2       = 3'b111;

// --------------------------------------------
// data path RGB_YUV

wire    [7:0]  Y_out, U_out, V_out;
reg     [7:0]  yuv_out_tmp;
reg     [23:0] RGB_d1_w;
wire    [23:0] RGB_d1_r;
reg     [2:0]  state_read_rgb;
parameter STATE_READ_RGB_1         = 3'b000
        , STATE_COMPUTE_YUV_1      = 3'b001
        , STATE_OUT_U              = 3'b010
        , STATE_OUT_Y_1            = 3'b011
        , STATE_OUT_V              = 3'b100
        , STATE_READ_RGB_2         = 3'b101
        , STATE_COMPUTE_YUV_2      = 3'b110
        , STATE_OUT_Y_2            = 3'b111;
assign RGB_d1_r = RGB_d1_w;
assign yuv_out = yuv_out_tmp;

assign Y_d1_r = (YUV_firstY_bit == 1'b1) ? Y_d1_1_w: Y_d1_2_w;
assign U_d1_r = U_d1_w;
assign V_d1_r = V_d1_w;

always @ (posedge clk_p or negedge reset_n) begin
    if(reset_n) begin
	state_read_yuv <= STATE_READ_U;
        state_read_rgb <= STATE_READ_RGB_1;

        busy_yuv_to_rgb <= 1'b0;
        busy_rgb_to_yuv <= 1'b0;
        valid_yuv_to_rgd <= 1'b0;
        valid_rgb_to_yuv <= 1'b0;

        YUV_firstY_bit <= 1'b1;
    end
    else begin 
    // Read data signal to FF
        if(in_en) begin
            // ----------------------------------------------------------------
            if(!op_mode) begin
                case (state_read_yuv)
                    STATE_READ_U: begin
                        valid_yuv_to_rgd <= 1'b0;               
	                U_d1_w <= yuv_in;
                        state_read_yuv <= STATE_READ_Y1;
		    end
		    STATE_READ_Y1: begin
		        Y_d1_1_w <= yuv_in;
                        YUV_firstY_bit <= 1'b1;
                        state_read_yuv <= STATE_READ_V;
	   	    end
	   	    STATE_READ_V: begin
		        V_d1_w <= yuv_in;
                        busy_yuv_to_rgb <= 1'b1;
                        state_read_yuv <= STATE_COMPUTE_RGB_1;
	 	    end
                    STATE_COMPUTE_RGB_1: begin
                        state_read_yuv <= STATE_OUT_RGB_1;
                    end
                    STATE_OUT_RGB_1: begin
                        busy_yuv_to_rgb <= 1'b0;
                        valid_yuv_to_rgd <= 1'b1;

                        state_read_yuv <= STATE_READ_Y2;
                    end
		    STATE_READ_Y2: begin
                        valid_yuv_to_rgd <= 1'b0;
 		        Y_d1_2_w <= yuv_in;
                        YUV_firstY_bit <= 1'b0;

                        busy_yuv_to_rgb <= 1'b1;
                        
                        state_read_yuv <= STATE_COMPUTE_RGB_2; 
		    end
                    STATE_COMPUTE_RGB_2: begin

                        state_read_yuv <= STATE_OUT_RGB_2;
                    end
                    STATE_OUT_RGB_2: begin
                        valid_yuv_to_rgd <= 1'b1;
                        busy_yuv_to_rgb <= 1'b0;
                        state_read_yuv <= STATE_READ_U;
                    end
		    default: begin
		    end
	        endcase
            end
            // -----------------------------------------------------------
            // RGB to YUV
	    else begin
	        case (state_read_rgb)
                    STATE_READ_RGB_1: begin
                        busy_rgb_to_yuv <= 1'b1;
                        RGB_d1_w <= rgb_in;
                        state_read_rgb <= STATE_COMPUTE_YUV_1;
                    end
                    STATE_COMPUTE_YUV_1: begin
                        state_read_rgb <= STATE_OUT_U;
                    end
                    STATE_OUT_U: begin
                        state_read_rgb <= STATE_OUT_Y_1;
                    end
                    STATE_OUT_Y_1: begin
                        state_read_rgb <= STATE_OUT_V;
                    end
                    STATE_OUT_V: begin
                        busy_rgb_to_yuv <= 1'b0;
                        state_read_rgb <= STATE_READ_RGB_2;
                    end
                    STATE_READ_RGB_2: begin
                        busy_rgb_to_yuv <= 1'b1;
                        RGB_d1_w <= rgb_in;
                        state_read_rgb <= STATE_COMPUTE_YUV_2;
                    end
                    STATE_COMPUTE_YUV_2: begin
                        state_read_rgb <= STATE_OUT_Y_2;
                    end
                    STATE_OUT_Y_2: begin
                        state_read_rgb <= STATE_READ_RGB_1;
                        busy_rgb_to_yuv <= 1'b0;
                    end
                endcase
	    end
        end
	else begin // not enable
        end
    end
end

always @ (negedge clk_p) begin
    if(state_read_rgb == STATE_OUT_U) begin 
        yuv_out_tmp <= U_out;
        valid_rgb_to_yuv <= 1'b1;
    end
    else if(state_read_rgb == STATE_OUT_V)  yuv_out_tmp <= V_out;
    else if(state_read_rgb == STATE_OUT_Y_1 || state_read_rgb == STATE_OUT_Y_2) begin
        valid_rgb_to_yuv <= 1'b1;
        yuv_out_tmp <= Y_out;
    end
    else begin
        yuv_out_tmp <= 8'hzz;
        valid_rgb_to_yuv <= 1'b0;
    end
end 

// NOTE: 3 bits reserved for overflow
// signed bit  integer 
//    [10]      [9:0]
wire   [10:0]   Y_data;  
wire   [10:0]   U_data;  
wire   [10:0]   V_data;  

assign Y_data = {3'b000, Y_d1_r[7:0]};
assign U_data = {{4{U_d1_r[7]}}, U_d1_r[6:0]};
assign V_data = {{4{V_d1_r[7]}}, V_d1_r[6:0]};

// signed bit   integer  float 
//   [15]       [14:3]   [2:0]
wire   [15:0]  R_out;
wire   [15:0]  G_out; 
wire   [15:0]  B_out;

// R     1,  0      , 1.101
// G = [ 1, -0.01   , -0.11 ] [Y U V]
// B     1, 10      , 0
wire   [4:0]  R_V_co;
wire   [4:0]  G_U_co, G_V_co;
wire   [15:0] R_V_co_ext;
wire   [15:0] G_U_co_ext, G_V_co_ext;
 
// signed bit   integer  float 
//   [4]        [3]      [2:0]
assign R_V_co = 5'b0_1101;  // 1.625
assign G_U_co = 5'b1_1110;  // -0.25
assign G_V_co = 5'b1_1010;  // -0.75

assign R_V_co_ext = {{11{R_V_co[4]}}, R_V_co[3:0]};
assign G_U_co_ext = {{11{G_U_co[4]}}, G_U_co[3:0]};
assign G_V_co_ext = {{11{G_V_co[4]}}, G_V_co[3:0]};


// (10+4+1)+(1) = 16  (mul)+(sign)
wire   [15:0] m11, m13, m21, m22, m23, m31, m32;

// NOTE: (1) Only one side need to be xiao su, e.g. x*y.yyy
//       (2) Or self extend xiao su  {X. 3'b000}
assign m11 = { {2{Y_data[10]}}, Y_data[10:0], 3'b000 };
assign m13 = { {5{V_data[10]}}, V_data[9:0] } * R_V_co_ext;
assign m21 = m11;
assign m22 = { {5{U_data[10]}}, U_data[9:0] } * G_U_co_ext;
assign m23 = { {5{V_data[10]}}, V_data[9:0] } * G_V_co_ext;
assign m31 = m11;
assign m32 = { {2{U_data[10]}}, U_data[9:0], 3'b000 } << 1;

assign R_out = m11 + m13;
assign G_out = m21 + m22 + m23;
assign B_out = m31 + m32;

wire    [7:0] R_abs_out, G_abs_out, B_abs_out;
// (1) The first two bits is reserved for overflow
// (2) The second conditiona is avoid overflow when value is ff already
assign R_abs_out = (R_out[13] == 1'b1) 
                  ? 8'h00 
                  : (R_out[12:11] != 0) ?  8'hFF
                                       : (R_out[2] == 1'b1 && (R_out[10:3] != 8'hff)) ? (R_out[10:3]+1) 
                                                            : R_out[10:3];
assign G_abs_out = (G_out[13] == 1'b1) 
                  ? 8'h00 
                  : (G_out[12:11] != 0) ?  8'hFF
                                       : (G_out[2] == 1'b1 && (G_out[10:3]) != 8'hff) 
                                                            ? (G_out[10:3]+1) 
                                                            : G_out[10:3];
assign B_abs_out = (B_out[13] == 1'b1) 
                  ? 8'h00 
                  : (B_out[12:11] != 0) ?  8'hFF
                                       : (B_out[2] == 1'b1 && (B_out[10:3] != 8'hff)) ? (B_out[10:3]+1) 
                                                            : B_out[10:3];

assign rgb_out = { R_abs_out, G_abs_out, B_abs_out };

// signed bit  integer 
//    [8]      [7:0]
wire   [8:0]   R_data, G_data, B_data;  


assign R_data = {1'b0, RGB_d1_r[23:16]};
assign G_data = {1'b0, RGB_d1_r[15:8]};
assign B_data = {1'b0, RGB_d1_r[7:0]};

// Y     0.290909 , 0.6303     , 0.078
// U = [ -0.14545  , -0.315151  , 0.460606 ] [R G B]
// V     0.43636  , -0.38787    , -0.04848
wire [23:0] Y_tmp, U_tmp, V_tmp;
assign Y_tmp = R_data*24'd9533    +  G_data*24'd20654    + B_data*24'd2582; 
assign U_tmp = -(R_data*24'd4766) +  -(G_data*24'd10327) + B_data*24'd15093;
assign V_tmp = R_data*24'd14299   +  -(G_data*24'd12710) + -(B_data*24'd1589);

wire [7:0] Y_shift, U_shift, V_shift;
assign Y_shift = (Y_tmp >> 15);
assign U_shift = (U_tmp[13:0] > 0 && U_tmp[14] == 1) ? (U_tmp >> 15)+1:(U_tmp >> 15);
assign V_shift = (V_tmp[13:0] > 0 && V_tmp[14] == 1) ? (V_tmp >> 15)+1:(V_tmp >> 15);

assign Y_out = (Y_tmp[14] == 1 && Y_shift != 8'hFF) ? Y_shift+1 : Y_shift;
assign U_out = U_shift;
assign V_out = V_shift;

endmodule
