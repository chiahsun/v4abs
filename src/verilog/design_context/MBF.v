
module ROMC(clk, reset, data, data_valid, data_last);

input clk;
input reset;
output [7:0] data;
output data_last;
output data_valid;

wire [3:0] Q;
wire CEN;
wire [9:0] A;

rom_1024x4_t13 rom1(.Q(Q), .CLK(!clk), .CEN(CEN), .A(A));

reg [1:0] next_state;
reg [9:0] next_cnt;

reg [7:0] next_data;

reg next_data_valid;
reg next_data_last;


reg [1:0] state;
reg [9:0] cnt;

reg [7:0] data;

reg data_valid;
reg data_last;

parameter FIRST_DATA = 2'b00
        , SECOND_DATA = 2'b01
        , END = 2'b10;

assign CEN = 1'b0;
assign A = cnt;
parameter CNT_END = 10'd1023;
always @ (*) begin
    next_state = state;
    next_cnt = cnt;
    next_data = data;
    next_data_valid = data_valid;
    next_data_last = data_last;
    case (state) 
        FIRST_DATA: begin
            next_state = SECOND_DATA;
            next_cnt = cnt + 1'b1;
            next_data = {4'h0, Q};
            next_data_valid = 1'b0;
            next_data_last = 1'b0;
        end
        SECOND_DATA: begin
            next_state = (cnt == CNT_END ? END : FIRST_DATA);
            next_cnt = cnt + 1'b1;
            next_data = {Q, data[3:0]};
            next_data_valid = 1'b1;
            next_data_last = (cnt == CNT_END ? 1'b1 : 1'b0);
        end
        END: begin
            next_state = END;
            next_data_valid = 1'b1;
            next_data_last = 1'b1;
        end
    endcase
end

always @ (posedge clk or negedge reset) begin
    if(reset) begin
        state <= FIRST_DATA;
        cnt <= 10'h0;
        data <= 8'b0;
        data_valid <= 1'b0;
        data_last <= 1'b0;
    end
    else begin
        state <= next_state;
        cnt <= next_cnt;
        data <= next_data;
        data_valid <= next_data_valid;
        data_last <= next_data_last;
    end
end

endmodule


module LPF(clk, reset, data_in, data_in_valid, out_valid, data_out);
    input clk;
    input reset;
    input [7:0] data_in;
    input data_in_valid;
    output out_valid;
    output [7:0] data_out;

    parameter WIDTH_DATA_LENGTH = 22;
    parameter WIDTH_DATA = WIDTH_DATA_LENGTH-1;
    parameter WIDTH_EXT = (WIDTH_DATA_LENGTH-9-1);
    // 7 + 1
    // 9 + 1
    // 4
    // 8 + 10 + 4 = 22
    // we need sign extension to 22 bits
                     // sn nnnn nnnn
    // I should complement than plus 1 = =
    /*parameter H0  = 10'b11_1111_1110
            , H1  = 10'b11_1111_1101
            , H2  = 10'b01_1111_1011
            , H3  = 10'b01_1111_0011
            , H4  = 10'b11_1110_0111
            , H5  = 10'b11_1101_0111
            , H6  = 10'b00_0101_0000
            , H7  = 10'b01_0000_0000*/
    //                  s               1 2345 6789
    parameter H0  = 22'b11_1111_1111_1111_1111_1111
            , H1  = 22'b11_1111_1111_1111_1111_1110
            , H2  = 22'b00_0000_0000_0000_0000_0100
            , H3  = 22'b00_0000_0000_0000_0000_1100
            , H4  = 22'b11_1111_1111_1111_1110_1000
            , H5  = 22'b11_1111_1111_1111_1101_1000
            , H6  = 22'b00_0000_0000_0000_0101_0000
            , H7  = 22'b00_0000_0000_0001_0000_0000
            , H8  = H7 
            , H9  = H6
            , H10 = H5
            , H11 = H4
            , H12 = H3
            , H13 = H2
            , H14 = H1
            , H15 = H0;

    parameter DATA_DEFAULT = 22'b0;    
     
    reg out_valid;
    reg next_out_valid;
    reg en;
    reg next_en;
    reg [3:0] cnt;
    reg [3:0] next_cnt;
    reg [WIDTH_DATA:0] data, d1, d2, d3, d4
             , d5, d6, d7, d8, d9
             , d10, d11, d12, d13, d14
             , d15;

    reg [WIDTH_DATA:0] next_data, next_d1, next_d2, next_d3
             , next_d4, next_d5, next_d6, next_d7
             , next_d8, next_d9, next_d10, next_d11
             , next_d12, next_d13, next_d14, next_d15;

    reg [13:0] debug_d1, debug_d2, debug_d3, debug_d4, debug_d5, debug_d6, debug_d7, debug_d8
            , debug_d9, debug_d10, debug_d11, debug_d12, debug_d13, debug_d14, debug_d15;

    wire [WIDTH_DATA:0] mult;
    assign mult = data * H0 + d1;
    wire [7:0] data_int;
    
    assign data_int = (!mult[WIDTH_DATA]) ? (mult[8] ? (mult[WIDTH_DATA:9] + 1'b1) : mult[WIDTH_DATA:9])
                                  : (mult[8] ? (mult[WIDTH_DATA:9] + 1'b1) : mult[WIDTH_DATA:9] );
    assign data_out = data_int;

    always @ (*) begin
        // debug_d1 = d1[`WIDTH_DATA:`WIDTH_DATA-11];
        debug_d1 = d1[21:9];
        debug_d2 = d2[21:9];
        debug_d3 = d3[21:9];
        debug_d4 = d4[21:9];
        debug_d5 = d5[21:9];
        debug_d6 = d6[21:9];
        debug_d7 = d7[21:9];
        debug_d8 = d8[21:9];
        debug_d9 = d9[21:9];
        debug_d10 = d10[21:9];
        debug_d11 = d11[21:9];
        debug_d12 = d12[21:9];
        debug_d13 = d13[21:9];
        debug_d14 = d14[21:9];
        debug_d15 = d15[21:9];
    end

    always @ (*) begin
        next_data = data;
        next_d1 = d1;
        next_d2 = d2;
        next_d3 = d3;
        next_d4 = d4;
        next_d5 = d5;
        next_d6 = d6;
        next_d7 = d7;
        next_d8 = d8;
        next_d9 = d9;
        next_d10 = d10;
        next_d11 = d11;
        next_d12 = d12;
        next_d13 = d13;
        next_d14 = d14;
        next_d15 = d15;
        next_en = en;
        next_out_valid = out_valid;
        if(data_in_valid) begin
            // next_data = {{`WIDTH_EXT{data_in[7]}}, data_in};
            // next_data = {{6{data_in[7]}}, data_in, 9'b0};
            next_data = {{14{data_in[7]}}, data_in};
            next_d1 = data * H1 + d2;
            next_d2 = data * H2 + d3; 
            next_d3 = data * H3 + d4; 
            next_d4 = data * H4 + d5; 
            next_d5 = data * H5 + d6; 
            next_d6 = data * H6 + d7; 
            next_d7 = data * H7 + d8; 
            next_d8 = data * H8 + d9; 
            next_d9 = data * H9 + d10; 
            next_d10 = data * H10 + d11; 
            next_d11 = data * H11 + d12; 
            next_d12 = data * H12 + d13; 
            next_d13 = data * H13 + d14; 
            next_d14 = data * H14 + d15; 
            next_d15 = data * H15;
            next_en = 1'b1; 
            next_out_valid = (next_en) ? 1'b1 : 1'b0;
        end
        else begin
            next_out_valid = 1'b0;
        end
    end

    always @ (posedge clk) begin
        if(reset) begin
            data <= DATA_DEFAULT;
            d1 <= DATA_DEFAULT;
            d2 <= DATA_DEFAULT;
            d3 <= DATA_DEFAULT;
            d4 <= DATA_DEFAULT;
            d5 <= DATA_DEFAULT;
            d6 <= DATA_DEFAULT;
            d7 <= DATA_DEFAULT;
            d8 <= DATA_DEFAULT;
            d9 <= DATA_DEFAULT;
            d10 <= DATA_DEFAULT;
            d11 <= DATA_DEFAULT;
            d12 <= DATA_DEFAULT;
            d13 <= DATA_DEFAULT;
            d14 <= DATA_DEFAULT;
            d15 <= DATA_DEFAULT;
            en <= 1'b0;
            cnt <= 4'b0;
            out_valid <= 1'b0;
        end
        else begin
            data <= next_data;
            d1 <= next_d1;
            d2 <= next_d2;
            d3 <= next_d3;
            d4 <= next_d4;
            d5 <= next_d5;
            d6 <= next_d6;
            d7 <= next_d7;
            d8 <= next_d8;
            d9 <= next_d9;
            d10 <= next_d10;
            d11 <= next_d11;
            d12 <= next_d12;
            d13 <= next_d13;
            d14 <= next_d14;
            d15 <= next_d15;
            en <= next_en;
            cnt <= next_cnt;
            out_valid <= next_out_valid;
        end
    end
endmodule 

module HPF(clk, reset, data_in, data_in_valid, out_valid, data_out);
    input clk;
    input reset;
    input [7:0] data_in;
    input data_in_valid;
    output out_valid;
    output [7:0] data_out;
    // 7 + 1
    // 9 + 1
    // 4
    // 8 + 10 + 4 = 22
    // we need sign extension to 22 bits
                     // sn nnnn nnnn
    // I should complement than plus 1 = =
    /*parameter H0  = 10'b11_1111_1110
            , H1  = 10'b11_1111_1101
            , H2  = 10'b01_1111_1011
            , H3  = 10'b01_1111_0011
            , H4  = 10'b11_1110_0111
            , H5  = 10'b11_1101_0111
            , H6  = 10'b00_0101_0000
            , H7  = 10'b01_0000_0000*/
    //                  s               1 2345 6789
    parameter H0  = 22'b11_1111_1111_1111_1111_1111
            , H1  = 22'b00_0000_0000_0000_0000_0010
            , H2  = 22'b00_0000_0000_0000_0000_0100
            , H3  = 22'b11_1111_1111_1111_1111_0100
            , H4  = 22'b11_1111_1111_1111_1110_1000
            , H5  = 22'b00_0000_0000_0000_0010_1000
            , H6  = 22'b00_0000_0000_0000_0101_0000
            , H7  = 22'b11_1111_1111_1111_0000_0000
            , H8  = (~H7+1'b1) 
            , H9  = (~H6+1'b1)
            , H10 = (~H5+1'b1)
            , H11 = (~H4+1'b1)
            , H12 = (~H3+1'b1)
            , H13 = (~H2+1'b1)
            , H14 = (~H1+1'b1)
            , H15 = (~H0+1'b1);

    parameter DATA_DEFAULT = 22'b0;    
     
    reg out_valid;
    reg next_out_valid;
    reg en;
    reg next_en;
    reg [3:0] cnt;
    reg [3:0] next_cnt;
    reg [WIDTH_DATA:0] data, d1, d2, d3, d4
             , d5, d6, d7, d8, d9
             , d10, d11, d12, d13, d14
             , d15;

    reg [WIDTH_DATA:0] next_data, next_d1, next_d2, next_d3
             , next_d4, next_d5, next_d6, next_d7
             , next_d8, next_d9, next_d10, next_d11
             , next_d12, next_d13, next_d14, next_d15;

    reg [13:0] debug_d1, debug_d2, debug_d3, debug_d4, debug_d5, debug_d6, debug_d7, debug_d8
            , debug_d9, debug_d10, debug_d11, debug_d12, debug_d13, debug_d14, debug_d15;

    wire [WIDTH_DATA:0] mult;
    assign mult = data * H0 + d1;
    wire [7:0] data_int;
    
    assign data_int = (!mult[WIDTH_DATA]) ? (mult[8] ? (mult[WIDTH_DATA:9] + 1'b1) : mult[WIDTH_DATA:9])
                                  : (mult[8] ? (mult[WIDTH_DATA:9] + 1'b1) : mult[WIDTH_DATA:9] );
    assign data_out = data_int;

    always @ (*) begin
        // debug_d1 = d1[`WIDTH_DATA:`WIDTH_DATA-11];
        debug_d1 = d1[21:9];
        debug_d2 = d2[21:9];
        debug_d3 = d3[21:9];
        debug_d4 = d4[21:9];
        debug_d5 = d5[21:9];
        debug_d6 = d6[21:9];
        debug_d7 = d7[21:9];
        debug_d8 = d8[21:9];
        debug_d9 = d9[21:9];
        debug_d10 = d10[21:9];
        debug_d11 = d11[21:9];
        debug_d12 = d12[21:9];
        debug_d13 = d13[21:9];
        debug_d14 = d14[21:9];
        debug_d15 = d15[21:9];
    end

    always @ (*) begin
        next_data = data;
        next_d1 = d1;
        next_d2 = d2;
        next_d3 = d3;
        next_d4 = d4;
        next_d5 = d5;
        next_d6 = d6;
        next_d7 = d7;
        next_d8 = d8;
        next_d9 = d9;
        next_d10 = d10;
        next_d11 = d11;
        next_d12 = d12;
        next_d13 = d13;
        next_d14 = d14;
        next_d15 = d15;
        next_en = en;
        next_out_valid = out_valid;
        if(data_in_valid) begin
            // next_data = {{`WIDTH_EXT{data_in[7]}}, data_in};
            // next_data = {{6{data_in[7]}}, data_in, 9'b0};
            next_data = {{14{data_in[7]}}, data_in};
            next_d1 = data * H1 + d2;
            next_d2 = data * H2 + d3; 
            next_d3 = data * H3 + d4; 
            next_d4 = data * H4 + d5; 
            next_d5 = data * H5 + d6; 
            next_d6 = data * H6 + d7; 
            next_d7 = data * H7 + d8; 
            next_d8 = data * H8 + d9; 
            next_d9 = data * H9 + d10; 
            next_d10 = data * H10 + d11; 
            next_d11 = data * H11 + d12; 
            next_d12 = data * H12 + d13; 
            next_d13 = data * H13 + d14; 
            next_d14 = data * H14 + d15; 
            next_d15 = data * H15;
            next_en = 1'b1; 
            next_out_valid = (next_en) ? 1'b1 : 1'b0;
        end
        else begin
            next_out_valid = 1'b0;
        end
    end

    always @ (posedge clk) begin
        if(reset) begin
            data <= DATA_DEFAULT;
            d1 <= DATA_DEFAULT;
            d2 <= DATA_DEFAULT;
            d3 <= DATA_DEFAULT;
            d4 <= DATA_DEFAULT;
            d5 <= DATA_DEFAULT;
            d6 <= DATA_DEFAULT;
            d7 <= DATA_DEFAULT;
            d8 <= DATA_DEFAULT;
            d9 <= DATA_DEFAULT;
            d10 <= DATA_DEFAULT;
            d11 <= DATA_DEFAULT;
            d12 <= DATA_DEFAULT;
            d13 <= DATA_DEFAULT;
            d14 <= DATA_DEFAULT;
            d15 <= DATA_DEFAULT;
            en <= 1'b0;
            cnt <= 4'b0;
            out_valid <= 1'b0;
        end
        else begin
            data <= next_data;
            d1 <= next_d1;
            d2 <= next_d2;
            d3 <= next_d3;
            d4 <= next_d4;
            d5 <= next_d5;
            d6 <= next_d6;
            d7 <= next_d7;
            d8 <= next_d8;
            d9 <= next_d9;
            d10 <= next_d10;
            d11 <= next_d11;
            d12 <= next_d12;
            d13 <= next_d13;
            d14 <= next_d14;
            d15 <= next_d15;
            en <= next_en;
            cnt <= next_cnt;
            out_valid <= next_out_valid;
        end
    end
endmodule 


module MBF(clk, reset, y_valid, z_valid, y, z);
input   clk;
input   reset;
output  y_valid;
output  z_valid;
output  [7:0]  y;
output  [7:0]  z;


wire [7:0] data_in;
wire data_valid;
ROMC romc(.clk(clk), .reset(reset), .data(data_in), .data_valid(data_valid), .data_last(last));
LPF lpf(.clk(clk), .reset(reset), .data_in(data_in), .data_in_valid(data_valid), .out_valid(y_valid), .data_out(y));
HPF hpf(.clk(clk), .reset(reset), .data_in(data_in), .data_in_valid(data_valid), .out_valid(z_valid), .data_out(z));

endmodule
