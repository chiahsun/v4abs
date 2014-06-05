`timescale 1ns/10ps

module FILTER(clk, rst, r_valid, r_input, low, o_ans, o_valid);

input        clk;
input        rst;
input        r_valid;
input  [7:0] r_input;
input        low;
output [7:0] o_ans;
output       o_valid;

reg  [19:0] r_d1;
reg  [19:0] r_d2;
reg  [19:0] r_d3;
reg  [19:0] r_d4;
reg  [19:0] r_d5;
reg  [19:0] r_d6;
reg  [19:0] r_d7;
reg  [19:0] r_d8;
reg  [19:0] r_d9;
reg  [19:0] r_d10;
reg  [19:0] r_d11;
reg  [19:0] r_d12;
reg  [19:0] r_d13;
reg  [19:0] r_d14;
reg  [19:0] r_d15;
reg  [19:0] next_r_d1;
reg  [19:0] next_r_d2;
reg  [19:0] next_r_d3;
reg  [19:0] next_r_d4;
reg  [19:0] next_r_d5;
reg  [19:0] next_r_d6;
reg  [19:0] next_r_d7;
reg  [19:0] next_r_d8;
reg  [19:0] next_r_d9;
reg  [19:0] next_r_d10;
reg  [19:0] next_r_d11;
reg  [19:0] next_r_d12;
reg  [19:0] next_r_d13;
reg  [19:0] next_r_d14;
reg  [19:0] next_r_d15;

wire [19:0] r_coeff1;
wire [19:0] r_coeff2;
wire [19:0] r_coeff3;
wire [19:0] r_coeff4;
wire [19:0] r_coeff5;
wire [19:0] r_coeff6;
wire [19:0] r_coeff7;
wire [19:0] r_coeff8;

// This is for Output
wire        low;
wire [19:0] r_inputSE;
reg         o_valid;
reg   [7:0] o_ans;
reg  [19:0] tmp_sum;
reg   [7:0] next_o_ans;

assign r_coeff1  = (low)? 20'hffffe : 20'h00002;
assign r_coeff2  = (low)? 20'h0000c : 20'hffff4;
assign r_coeff3  = (low)? 20'hfffd8 : 20'h00028;
assign r_coeff4  = (low)? 20'h00100 : 20'hfff00;
assign r_coeff5  = (low)? 20'h00050 : 20'hfffb0;
assign r_coeff6  = (low)? 20'hfffe8 : 20'h00018;
assign r_coeff7  = (low)? 20'h00004 : 20'hffffc;
assign r_coeff8  = (low)? 20'hfffff : 20'h00001;
assign r_inputSE = (r_input[7])? {12'hfff, r_input} : {12'h0, r_input};

always @ (*) begin
    if (rst) begin
        next_r_d1  = 20'b0;
        next_r_d2  = 20'b0;
        next_r_d3  = 20'b0;
        next_r_d4  = 20'b0;
        next_r_d5  = 20'b0;
        next_r_d6  = 20'b0;
        next_r_d7  = 20'b0;
        next_r_d8  = 20'b0;
        next_r_d9  = 20'b0;
        next_r_d10 = 20'b0;
        next_r_d11 = 20'b0;
        next_r_d12 = 20'b0;
        next_r_d13 = 20'b0;
        next_r_d14 = 20'b0;
        next_r_d15 = 20'b0;
        tmp_sum    = 20'b0;
        next_o_ans =  8'b0;
    end
    else begin
        next_r_d1  = (r_valid)? r_inputSE : r_d1;
        next_r_d2  = (r_valid)? r_d1      : r_d2;
        next_r_d3  = (r_valid)? r_d2      : r_d3;
        next_r_d4  = (r_valid)? r_d3      : r_d4;
        next_r_d5  = (r_valid)? r_d4      : r_d5;
        next_r_d6  = (r_valid)? r_d5      : r_d6;
        next_r_d7  = (r_valid)? r_d6      : r_d7;
        next_r_d8  = (r_valid)? r_d7      : r_d8;
        next_r_d9  = (r_valid)? r_d8      : r_d9;
        next_r_d10 = (r_valid)? r_d9      : r_d10;
        next_r_d11 = (r_valid)? r_d10     : r_d11;
        next_r_d12 = (r_valid)? r_d11     : r_d12;
        next_r_d13 = (r_valid)? r_d12     : r_d13;
        next_r_d14 = (r_valid)? r_d13     : r_d14;
        next_r_d15 = (r_valid)? r_d14     : r_d15;
        tmp_sum    = 20'hfffff *r_inputSE+ r_coeff1 * r_d1  +
                     20'h00004 * r_d2    + r_coeff2 * r_d3  +
                     20'hfffe8 * r_d4    + r_coeff3 * r_d5  +
                     20'h00050 * r_d6    + r_coeff4 * r_d7  +
                     20'h00100 * r_d8    + r_coeff5 * r_d9  +
                     20'hfffd8 * r_d10   + r_coeff6 * r_d11 +
                     20'h0000c * r_d12   + r_coeff7 * r_d13 +
                     20'hffffe * r_d14   + r_coeff8 * r_d15 ;
        next_o_ans = (tmp_sum[8])? tmp_sum[16:9] + 1'b1 : tmp_sum[16:9];
                                   
    end
end

always @ (posedge clk or negedge rst) begin
    if (rst) begin
        r_d1  <= 20'b0;
        r_d2  <= 20'b0;
        r_d3  <= 20'b0;
        r_d4  <= 20'b0;
        r_d5  <= 20'b0;
        r_d6  <= 20'b0;
        r_d7  <= 20'b0;
        r_d8  <= 20'b0;
        r_d9  <= 20'b0;
        r_d10 <= 20'b0;
        r_d11 <= 20'b0;
        r_d12 <= 20'b0;
        r_d13 <= 20'b0;
        r_d14 <= 20'b0;
        r_d15 <= 20'b0;
        o_ans <=  8'b0;
        o_valid <= 1'b0;
    end
    else begin
        r_d1  <= next_r_d1;
        r_d2  <= next_r_d2;
        r_d3  <= next_r_d3;
        r_d4  <= next_r_d4;
        r_d5  <= next_r_d5;
        r_d6  <= next_r_d6;
        r_d7  <= next_r_d7;
        r_d8  <= next_r_d8;
        r_d9  <= next_r_d9;
        r_d10 <= next_r_d10;
        r_d11 <= next_r_d11;
        r_d12 <= next_r_d12;
        r_d13 <= next_r_d13;
        r_d14 <= next_r_d14;
        r_d15 <= next_r_d15;
        o_ans <= next_o_ans;
        o_valid <= r_valid;
    end
end
endmodule

// This is for ROM
module rom_MBF(clk, rst, data_valid, data_output);
input        clk;
input        rst;
output       data_valid;
output [7:0] data_output;

reg          data_valid;
reg    [7:0] data_output;
reg    [9:0] rom_input;
reg          rom_enable;
reg          rom_loop;
wire   [3:0] rom_output;

reg          next_data_valid;
reg    [7:0] next_data_output;
reg    [9:0] next_rom_input;
reg          next_rom_loop;

rom_1024x4_t13 rom_design(.Q(rom_output), .CLK(~clk), .CEN(rom_enable), .A(rom_input));

always @ (*) begin
    if (rst) begin
        next_data_valid  =  1'b0;
        next_data_output =  8'b0;
        next_rom_input   = 10'b0;
        rom_enable       =  1'b1;
        next_rom_loop    =  1'b0;
    end
    else begin
        next_data_valid  = (rom_input[0])? 1'b1 : 1'b0; 
        next_data_output = (rom_loop)?     8'b0 : ((rom_input[0])? {rom_output, data_output[3:0]} : {4'b0, rom_output});
        next_rom_input   = rom_input + 10'b1;
        rom_enable       = 1'b0;
        next_rom_loop    = rom_loop || (rom_input == 10'h3ff);
    end
end

always @ (posedge clk) begin
    if (rst) begin
        rom_input   <= 10'b0;
        data_valid  <=  1'b0;
        data_output <=  8'b0;
        rom_loop    <=  1'b0;
    end
    else begin
        rom_input   <= next_rom_input;
        data_valid  <= next_data_valid;
        data_output <= next_data_output;
        rom_loop    <= next_rom_loop;
    end
end
 
endmodule

module MBF(clk, reset, y_valid, z_valid, y, z);
input          clk;
input          reset;
output         y_valid;
output         z_valid;
output  [7:0]  y;
output  [7:0]  z;

wire    [7:0]  out;
wire           valid;

rom_MBF rom_main(.clk(clk),  .rst(reset), .data_valid(valid), .data_output(out));
FILTER  low_pf (.clk(clk), .rst(reset), .r_valid(valid), .r_input(out), .low(1'b1), .o_ans(y), .o_valid(y_valid));
FILTER  high_pf(.clk(clk), .rst(reset), .r_valid(valid), .r_input(out), .low(1'b0), .o_ans(z), .o_valid(z_valid));
endmodule

