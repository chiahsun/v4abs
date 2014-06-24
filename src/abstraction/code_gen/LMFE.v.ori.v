module sram_8192x8_t13 (
   Q,
   CLK,
   CEN,
   WEN,
   A,
   D
);
   
output [7:0] Q;
input CLK;
input CEN;
input WEN;
input [12:0] A;
input [7:0] D;
   
reg [7:0]	   mem [8191:0];
reg [7:0] out_data;

assign Q = out_data;

always @ (posedge CLK) begin
    if (!CEN) begin
        if (WEN) begin
            out_data <= mem[A];
        end
        else begin
            mem[A] <= D;
        end
    end
end

endmodule

module median_three (a0, a1, a2, s_out);
input  [7:0] a0, a1, a2;
output [7:0] s_out;

wire  [8:0] cond1, cond2, cond3;
reg   [7:0] s_out;

assign cond1 = {1'b0, a0} - {1'b0, a1};
assign cond2 = {1'b0, a0} - {1'b0, a2};
assign cond3 = {1'b0, a1} - {1'b0, a2};

always @ (*) begin
    case ({cond1[8], cond2[8], cond3[8]})
        3'b111:  s_out = a1;
        3'b110:  s_out = a2;
        3'b100:  s_out = a0;
        3'b011:  s_out = a0;
        3'b001:  s_out = a2;
        3'b000:  s_out = a1;
    endcase
end

endmodule

module max_min_five (a0, a1, a2, a3, a4, s_max, s_min);
input  [7:0] a0, a1, a2, a3, a4;
output [7:0] s_max, s_min;

wire  [8:0] cond1, cond2, cond3, cond4, cond5, cond6;
reg   [7:0] tmp_max1, tmp_max2, tmp_max3, tmp_min1, tmp_min2, tmp_min3;
reg   [7:0] s_max, s_min;

assign cond1 = {1'b0, a0} - {1'b0, a1};
assign cond2 = {1'b0, a2} - {1'b0, a3};
assign cond3 = {1'b0, tmp_max1} - {1'b0, tmp_max2};
assign cond4 = {1'b0, tmp_min1} - {1'b0, tmp_min2};
assign cond5 = {1'b0, tmp_max3} - {1'b0, a4};
assign cond6 = {1'b0, tmp_min3} - {1'b0, a4};

always @ (*) begin
    tmp_max1 = (cond1[8])? a1 : a0;
    tmp_min1 = (cond1[8])? a0 : a1;

    tmp_max2 = (cond2[8])? a3 : a2;
    tmp_min2 = (cond2[8])? a2 : a3;

    tmp_max3 = (cond3[8])? tmp_max2 : tmp_max1;
    tmp_min3 = (cond4[8])? tmp_min1 : tmp_min2;

    s_max    = (cond5[8])? a4       : tmp_max3;
    s_min    = (cond6[8])? tmp_min3 : a4;
end

endmodule

module sorting_seven (a0, a1, a2, a3, a4, a5, a6, b0, b1, b2, b3, b4, b5, b6);

input  [7:0] a0, a1, a2, a3, a4, a5, a6;
output [7:0] b0, b1, b2, b3, b4, b5, b6;

reg  [7:0] A[0:7][0:6];
wire [7:0] b0, b1, b2, b3, b4 ,b5 ,b6;

integer i, j;

assign {b0, b1, b2, b3} = {A[7][0], A[7][1], A[7][2], A[7][3]};
assign {b4, b5, b6}     = {A[7][4], A[7][5], A[7][6]};

always @ (*) begin
    {A[0][0], A[0][1], A[0][2], A[0][3]} = {a0, a1, a2, a3};
    {A[0][4], A[0][5], A[0][6]}          = {a4, a5, a6};

    for (i = 0 ; i < 5 ; i = i + 2) begin
        for (j = 0 ; j < 6 ; j = j + 2) begin
            if (A[i][j] > A[i][j+1]) begin
                A[i+1][j]   = A[i][j+1];
                A[i+1][j+1] = A[i][j];
            end
            else begin
                A[i+1][j]   = A[i][j];
                A[i+1][j+1] = A[i][j+1];
            end
        end
        A[i+1][6] = A[i][6];
        A[i+2][0] = A[i+1][0];
        for (j = 1 ; j < 7 ; j = j+2) begin
            if (A[i+1][j] > A[i+1][j+1]) begin
                A[i+2][j]   = A[i+1][j+1];
                A[i+2][j+1] = A[i+1][j];
            end
            else begin
                A[i+2][j]   = A[i+1][j];
                A[i+2][j+1] = A[i+1][j+1];
            end
        end
    end
    A[7][6] = A[6][6];
    for (j = 0 ; j < 6 ; j = j + 2) begin
        if (A[6][j] > A[6][j+1]) begin
            A[7][j]   = A[6][j+1];
            A[7][j+1] = A[6][j];
        end
        else begin
            A[7][j]   = A[6][j];
            A[7][j+1] = A[6][j+1];
        end
    end
 
end

endmodule

module median_seven( clk, reset, s_in, s_valid, o_valid, m_out);
input        clk;
input        reset;
input  [7:0] s_in;
input        s_valid;
input        o_valid;
output [7:0] m_out;

reg          s_valid_next;
reg    [7:0] m_inp [0:6][0:6];
reg    [7:0] m_tmp [0:6][0:6];
reg    [7:0] p_one [0:6][0:6];
reg    [7:0] p_two [0:6][0:6];
reg    [7:0] p_thr [0:13];
reg    [7:0] p_gar [0:15];
wire   [7:0] out_tmp;
wire   [7:0] m_out;

integer i, j;
assign m_out = out_tmp;

    sorting_seven sort_00(.a0(m_inp[0][0]), .a1(m_inp[0][1]), .a2(m_inp[0][2]), .a3(m_inp[0][3]), .a4(m_inp[0][4]), .a5(m_inp[0][5]), .a6(m_inp[0][6]),
                          .b0(p_one[0][0]), .b1(p_one[0][1]), .b2(p_one[0][2]), .b3(p_one[0][3]), .b4(p_one[0][4]), .b5(p_one[0][5]), .b6(p_one[0][6]));
    sorting_seven sort_01(.a0(m_inp[1][0]), .a1(m_inp[1][1]), .a2(m_inp[1][2]), .a3(m_inp[1][3]), .a4(m_inp[1][4]), .a5(m_inp[1][5]), .a6(m_inp[1][6]),
                          .b0(p_one[1][0]), .b1(p_one[1][1]), .b2(p_one[1][2]), .b3(p_one[1][3]), .b4(p_one[1][4]), .b5(p_one[1][5]), .b6(p_one[1][6]));
    sorting_seven sort_02(.a0(m_inp[2][0]), .a1(m_inp[2][1]), .a2(m_inp[2][2]), .a3(m_inp[2][3]), .a4(m_inp[2][4]), .a5(m_inp[2][5]), .a6(m_inp[2][6]),
                          .b0(p_one[2][0]), .b1(p_one[2][1]), .b2(p_one[2][2]), .b3(p_one[2][3]), .b4(p_one[2][4]), .b5(p_one[2][5]), .b6(p_one[2][6]));
    sorting_seven sort_03(.a0(m_inp[3][0]), .a1(m_inp[3][1]), .a2(m_inp[3][2]), .a3(m_inp[3][3]), .a4(m_inp[3][4]), .a5(m_inp[3][5]), .a6(m_inp[3][6]),
                          .b0(p_one[3][0]), .b1(p_one[3][1]), .b2(p_one[3][2]), .b3(p_one[3][3]), .b4(p_one[3][4]), .b5(p_one[3][5]), .b6(p_one[3][6]));
    sorting_seven sort_04(.a0(m_inp[4][0]), .a1(m_inp[4][1]), .a2(m_inp[4][2]), .a3(m_inp[4][3]), .a4(m_inp[4][4]), .a5(m_inp[4][5]), .a6(m_inp[4][6]),
                          .b0(p_one[4][0]), .b1(p_one[4][1]), .b2(p_one[4][2]), .b3(p_one[4][3]), .b4(p_one[4][4]), .b5(p_one[4][5]), .b6(p_one[4][6]));
    sorting_seven sort_05(.a0(m_inp[5][0]), .a1(m_inp[5][1]), .a2(m_inp[5][2]), .a3(m_inp[5][3]), .a4(m_inp[5][4]), .a5(m_inp[5][5]), .a6(m_inp[5][6]),
                          .b0(p_one[5][0]), .b1(p_one[5][1]), .b2(p_one[5][2]), .b3(p_one[5][3]), .b4(p_one[5][4]), .b5(p_one[5][5]), .b6(p_one[5][6]));
    sorting_seven sort_06(.a0(m_inp[6][0]), .a1(m_inp[6][1]), .a2(m_inp[6][2]), .a3(m_inp[6][3]), .a4(m_inp[6][4]), .a5(m_inp[6][5]), .a6(m_inp[6][6]),
                          .b0(p_one[6][0]), .b1(p_one[6][1]), .b2(p_one[6][2]), .b3(p_one[6][3]), .b4(p_one[6][4]), .b5(p_one[6][5]), .b6(p_one[6][6]));

    sorting_seven sort_07(.a0(p_one[0][0]), .a1(p_one[1][0]), .a2(p_one[2][0]), .a3(p_one[3][0]), .a4(p_one[4][0]), .a5(p_one[5][0]), .a6(p_one[6][0]),
                          .b0(p_two[0][0]), .b1(p_two[1][0]), .b2(p_two[2][0]), .b3(p_two[3][0]), .b4(p_two[4][0]), .b5(p_two[5][0]), .b6(p_two[6][0]));
    sorting_seven sort_08(.a0(p_one[0][1]), .a1(p_one[1][1]), .a2(p_one[2][1]), .a3(p_one[3][1]), .a4(p_one[4][1]), .a5(p_one[5][1]), .a6(p_one[6][1]),
                          .b0(p_two[0][1]), .b1(p_two[1][1]), .b2(p_two[2][1]), .b3(p_two[3][1]), .b4(p_two[4][1]), .b5(p_two[5][1]), .b6(p_two[6][1]));
    sorting_seven sort_09(.a0(p_one[0][2]), .a1(p_one[1][2]), .a2(p_one[2][2]), .a3(p_one[3][2]), .a4(p_one[4][2]), .a5(p_one[5][2]), .a6(p_one[6][2]),
                          .b0(p_two[0][2]), .b1(p_two[1][2]), .b2(p_two[2][2]), .b3(p_two[3][2]), .b4(p_two[4][2]), .b5(p_two[5][2]), .b6(p_two[6][2]));
    sorting_seven sort_10(.a0(p_one[0][3]), .a1(p_one[1][3]), .a2(p_one[2][3]), .a3(p_one[3][3]), .a4(p_one[4][3]), .a5(p_one[5][3]), .a6(p_one[6][3]),
                          .b0(p_two[0][3]), .b1(p_two[1][3]), .b2(p_two[2][3]), .b3(p_two[3][3]), .b4(p_two[4][3]), .b5(p_two[5][3]), .b6(p_two[6][3]));
    sorting_seven sort_11(.a0(p_one[0][4]), .a1(p_one[1][4]), .a2(p_one[2][4]), .a3(p_one[3][4]), .a4(p_one[4][4]), .a5(p_one[5][4]), .a6(p_one[6][4]),
                          .b0(p_two[0][4]), .b1(p_two[1][4]), .b2(p_two[2][4]), .b3(p_two[3][4]), .b4(p_two[4][4]), .b5(p_two[5][4]), .b6(p_two[6][4]));
    sorting_seven sort_12(.a0(p_one[0][5]), .a1(p_one[1][5]), .a2(p_one[2][5]), .a3(p_one[3][5]), .a4(p_one[4][5]), .a5(p_one[5][5]), .a6(p_one[6][5]),
                          .b0(p_two[0][5]), .b1(p_two[1][5]), .b2(p_two[2][5]), .b3(p_two[3][5]), .b4(p_two[4][5]), .b5(p_two[5][5]), .b6(p_two[6][5]));
    sorting_seven sort_13(.a0(p_one[0][6]), .a1(p_one[1][6]), .a2(p_one[2][6]), .a3(p_one[3][6]), .a4(p_one[4][6]), .a5(p_one[5][6]), .a6(p_one[6][6]),
                          .b0(p_two[0][6]), .b1(p_two[1][6]), .b2(p_two[2][6]), .b3(p_two[3][6]), .b4(p_two[4][6]), .b5(p_two[5][6]), .b6(p_two[6][6]));

    max_min_five  maxi_14(.a0(p_two[0][4]), .a1(p_two[1][3]), .a2(p_two[2][2]), .a3(p_two[3][1]), .a4(p_two[4][0]), .s_max(p_thr[0]), .s_min(p_gar[0]));     //[4][0] -> 0
    sorting_seven sort_15(.a0(8'b0),        .a1(p_two[0][5]), .a2(p_two[1][4]), .a3(p_two[2][3]), .a4(p_two[3][2]), .a5(p_two[4][1]), .a6(p_two[5][0]),
                          .b0(p_gar[1]),    .b1(p_gar[2]),    .b2(p_gar[3]),    .b3(p_gar[4]),    .b4(p_thr[1]),    .b5(p_thr[2]),    .b6(p_thr[3]));        //[5][0] -> 3, [4][1] -> 2, [3][2] -> 1
    sorting_seven sort_16(.a0(p_two[0][6]), .a1(p_two[1][5]), .a2(p_two[2][4]), .a3(p_two[3][3]), .a4(p_two[4][2]), .a5(p_two[5][1]), .a6(p_two[6][0]),
                          .b0(p_gar[5]),    .b1(p_gar[6]),    .b2(p_thr[4]),    .b3(p_thr[5]),    .b4(p_thr[6]),    .b5(p_gar[7]),    .b6(p_gar[8])) ;       //[4][2] -> 6, [3][3] -> 5, [2][4] -> 4
    sorting_seven sort_17(.a0(8'b0),        .a1(p_two[1][6]), .a2(p_two[2][5]), .a3(p_two[3][4]), .a4(p_two[4][3]), .a5(p_two[5][2]), .a6(p_two[6][1]),
                          .b0(p_gar[9]),    .b1(p_thr[7]),    .b2(p_thr[8]),    .b3(p_thr[9]),    .b4(p_gar[10]),   .b5(p_gar[11]),   .b6(p_gar[12])) ;      //[3][4] -> 9, [2][5] -> 8, [1][6] -> 7
    max_min_five  maxi_18(.a0(p_two[2][6]), .a1(p_two[3][5]), .a2(p_two[4][4]), .a3(p_two[5][3]), .a4(p_two[6][2]), .s_max(p_gar[13]), .s_min(p_thr[10]));   //[2][6] -> 10

    max_min_five  maxi_19(.a0(8'b0),        .a1(p_thr[0]),    .a2(p_thr[1]),    .a3(p_thr[4]),    .a4(p_thr[7]),    .s_max(p_thr[11]), .s_min(p_gar[14]));   //[1][6], [2][4], [3][2], [4][0]
    median_three  medi_20(.a0(p_thr[8]),    .a1(p_thr[5]),    .a2(p_thr[2]),    .s_out(p_thr[12]));                                                          //[2][5], [3][3], [4][1]
    max_min_five  maxi_21(.a0(p_thr[3]),    .a1(p_thr[6]),    .a2(p_thr[9]),    .a3(p_thr[10]),   .a4(8'hff),       .s_max(p_gar[15]), .s_min(p_thr[13]));   //[2][6], [3][4], [4][2], [5][0]

    median_three  medi_22(.a0(p_thr[11]),   .a1(p_thr[12]),   .a2(p_thr[13]),   .s_out(out_tmp));

always @ (*) begin
    if (reset) begin
        for (i = 0 ; i < 7 ; i = i + 1) begin
            for (j = 0 ; j < 7 ; j = j + 1) begin
                m_tmp[i][j] = 8'h0;
            end
        end
    end
    else begin
        for (i = 0 ; i < 7 ; i = i + 1) begin
            for (j = 0 ; j < 6 ; j = j + 1) begin
                m_tmp[i][j+1] = (s_valid)? m_inp[i][j] : m_inp[i][j+1];
            end
        end
        m_tmp[0][0] = (s_valid)? s_in        : m_inp[0][0];
        m_tmp[1][0] = (s_valid)? m_inp[0][6] : m_inp[1][0];
        m_tmp[2][0] = (s_valid)? m_inp[1][6] : m_inp[2][0];
        m_tmp[3][0] = (s_valid)? m_inp[2][6] : m_inp[3][0];
        m_tmp[4][0] = (s_valid)? m_inp[3][6] : m_inp[4][0];
        m_tmp[5][0] = (s_valid)? m_inp[4][6] : m_inp[5][0];
        m_tmp[6][0] = (s_valid)? m_inp[5][6] : m_inp[6][0];
    end
end
always @ (posedge clk or negedge reset) begin
    if (reset) begin
        for (i = 0 ; i < 7 ; i = i + 1) begin
            for (j = 0 ; j < 7 ; j = j + 1) begin
                m_inp[i][j] <= 8'h0;
            end
        end
        s_valid_next <= 1'b0;
    end
    else begin
        for (i = 0 ; i < 7 ; i = i + 1) begin
            for (j = 0 ; j < 7 ; j = j + 1) begin
                m_inp[i][j] <= m_tmp[i][j];
            end
        end
        s_valid_next <= s_valid;
    end
end
endmodule

// SRAM
module sram_control( clk, reset, s_in, s_addr, s_write, s_out);
input        clk;
input        reset;
input  [7:0] s_in;
input [12:0] s_addr;
input        s_write;
output [7:0] s_out;   

reg        ram_enable;
reg        ram_write;
reg [12:0] ram_address;
reg  [7:0] ram_input;
reg  [7:0] s_in_next;
wire [7:0] s_out;

sram_8192x8_t13 ram_design(.Q(s_out), .CLK(~clk), .CEN(ram_enable), .WEN(ram_write), .A(ram_address), .D(ram_input));
always @ (*) begin
    if (reset) begin
        s_in_next = 8'b0;
    end
    else begin
        s_in_next = s_in;
    end
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        ram_enable  <= 1'b0;
        ram_write   <= 1'b0;
        ram_address <= 13'b0;
        ram_input   <= 8'h0;
    end
    else begin
        ram_enable  <= 1'b0;
        ram_write   <= s_write;
        ram_address <= s_addr;
        ram_input   <= s_in_next;
    end
end
endmodule

// TOP module
module LMFE ( clk, reset, Din, in_en, busy, out_valid, Dout);
input   clk;
input   reset;
input   in_en;
output  busy;
output  out_valid;
input   [7:0]  Din;
output  [7:0]  Dout;

wire  [7:0] Dout;
reg   [7:0] sram_in;
reg  [12:0] sram_addr;
reg  [12:0] count;
reg         busy;
reg         out_valid;
reg         out_valid_pre;
reg  [12:0] next_addr;
reg  [12:0] next_count;

// This is for Read 7*7 from SRAM
reg   [2:0] s_wei;
reg   [2:0] s_hei;
reg   [6:0] sta_w;
reg   [6:0] sta_h;
reg   [7:0] poi_w;
reg   [7:0] poi_h;
reg   [7:0] s_ans;
reg         calculate;
reg         calculate_one;
reg         calculate_two;
reg   [2:0] next_s_wei;
reg   [2:0] next_s_hei;
reg   [6:0] next_sta_w;
reg   [6:0] next_sta_h;
reg   [7:0] next_poi_w;
reg   [7:0] next_poi_h;
reg   [7:0] next_s_ans;

wire  [7:0] tmp_out;
wire [12:0] sta_point;
wire [12:0] read_addr;
wire        run_one_w;
wire        run_one_h;
wire        cal_first;
wire        cal_second;
wire        wri_first;
wire        wri_second;

sram_control sram_top(.clk(clk), .reset(reset), .s_in(Din), .s_addr(sram_addr), .s_write(busy), .s_out(tmp_out));

median_seven median_top(.clk(clk), .reset(reset), .s_in(s_ans), .s_valid(calculate_two), .o_valid(out_valid), .m_out(Dout));

assign sta_point   = {sta_h[5:0], sta_w};
assign read_addr   = {next_poi_h[5:0], next_poi_w[6:0]};
assign run_one_w   = s_hei == 3'h6 && s_wei == 3'h6;
assign run_one_h   = s_hei == 3'h6 && s_wei == 3'h6 && sta_w == 7'h7f;
assign cal_first   = sta_h[5:0] == 6'h04 && sta_w == 7'h0 && count == 13'h0380;
assign cal_second  = sta_h[5:0] == 6'h39 && sta_w == 7'h0 && count == 13'h1e80;
assign wri_first   = count == 13'h037f;
assign wri_second  = count == 13'h1e7f;

always @ (*) begin
    if (reset) begin
        next_count = 13'b0;
        sram_addr  = 13'b0;

        // This is for Read 7*7 from SRAM
        next_s_wei = 3'b0;
        next_s_hei = 3'b0;
        next_sta_w = 7'b0;
        next_sta_h = 7'b0;
        next_poi_w = 8'h0;
        next_poi_h = 8'h0;
        next_s_ans = 8'h0;
        calculate  = 1'b0;
    end
    else begin
        next_count = ( busy)? count : count + 13'b1;
        sram_addr  = (!busy)? count : read_addr;
 
        // This is for Read 7*7 from SRAM
        next_s_wei = (!calculate)?     3'b0 : ((s_wei ==  3'h6)? 3'b0 : s_wei + 3'b1);
        next_s_hei = (s_wei != 3'h6)? s_hei : ((s_hei ==  3'h6)? 3'b0 : s_hei + 3'b1);
        next_sta_w = (run_one_w)? sta_w + 7'b1 : sta_w;
        next_sta_h = (run_one_h)? sta_h + 7'b1 : sta_h;
        next_poi_w = ({1'b0, next_sta_w} + {1'b0, next_s_wei}) - 8'h3;
        next_poi_h = ({1'b0, next_sta_h} + {1'b0, next_s_hei}) - 8'h3;
        next_s_ans =((poi_h[7] && poi_h[6]) || poi_w[7])? 8'h0 : tmp_out;
        calculate  = (wri_first || wri_second)?  1'b1 :
                     (cal_first || cal_second)?  1'b0 : calculate;
    end
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        count         <= 13'h1ffd;
        busy          <=  1'b0;
        out_valid_pre <=  1'b0;
        out_valid     <=  1'b0;

        // This is for Read 7*7 from SRAM
        s_wei         <=  3'b0;
        s_hei         <=  3'b0;
        sta_w         <=  7'b0;
        sta_h         <=  7'b0;
        poi_w         <=  8'b0;
        poi_h         <=  8'b0;
        s_ans         <=  8'b0;
        calculate_one <=  1'b0;
        calculate_two <=  1'b0;
    end
    else begin
        count         <= next_count;
        busy          <= calculate;
        out_valid_pre <= run_one_w;
        out_valid     <= out_valid_pre;

        // This is for Read 7*7 from SRAM
        s_wei         <= next_s_wei;
        s_hei         <= next_s_hei;
        sta_w         <= next_sta_w;
        sta_h         <= next_sta_h;
        poi_w         <= next_poi_w;
        poi_h         <= next_poi_h;
        s_ans         <= next_s_ans;
        calculate_one <= calculate;
        calculate_two <= calculate_one;
    end
end

endmodule
