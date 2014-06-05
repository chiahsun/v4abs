`timescale 1ns/10ps
module calvalue(in_0, in_1, in_2, in_3, in_4, in_5, in_b, out_ans);

input  [63:0] in_0;
input  [63:0] in_1; 
input  [63:0] in_2; 
input  [63:0] in_3; 
input  [63:0] in_4; 
input  [63:0] in_5; 
input  [15:0] in_b; 
output [63:0] out_ans;

wire   [63:0] comb_0;
wire   [63:0] comb_1;
wire   [63:0] comb_2;
wire   [63:0] comb_3;

wire   [63:0] shi_11;
wire   [63:0] shi_12;
wire   [63:0] shi_22;
wire   [63:0] shi_23;
wire   [63:0] add_tmp;
wire   [95:0] add_ext;
wire   [95:0] tmp_ans;

assign comb_0 = in_0 + in_5; //+1
assign comb_1 = in_1 + in_4; //-6
assign comb_2 = in_2 + in_3; //+13
assign comb_3 = (in_b[15])? {16'hffff, in_b, 32'b0} : {16'h0, in_b, 32'b0}; //+1

assign shi_11 = {comb_1[63], comb_1[61:0], 1'b0};
assign shi_12 = {comb_1[63], comb_1[60:0], 2'b0};
assign shi_22 = {comb_2[63], comb_2[60:0], 2'b0};
assign shi_23 = {comb_2[63], comb_2[59:0], 3'b0};

assign add_tmp = ((comb_0 + comb_2) + (shi_22 + shi_23)) + (comb_3 - (shi_11 + shi_12));
assign add_ext = (add_tmp[63])? {32'hffffffff, add_tmp} : {32'h0, add_tmp};
assign tmp_ans = add_ext * {64'b0, 32'h0CCCCCCD}; //0.5
assign out_ans = tmp_ans[95:32];

endmodule

module GSIM ( clk, reset, in_en, b_in, out_valid, x_out);
input   clk ;
input   reset;
input   in_en;
output  out_valid;
input   [15:0]  b_in;
output  [31:0]  x_out;

reg   [3:0] count;
reg   [9:0] loop;
reg   [3:0] next_count;
reg   [9:0] next_loop;
reg         out_valid;
reg  [31:0] x_out;

reg  [15:0] inb_0;
reg  [15:0] inb_1;
reg  [15:0] inb_2;
reg  [15:0] inb_3;
reg  [15:0] inb_4;
reg  [15:0] inb_5;
reg  [15:0] inb_6;
reg  [15:0] inb_7;
reg  [15:0] inb_8;
reg  [15:0] inb_9;
reg  [15:0] inb_10;
reg  [15:0] inb_11;
reg  [15:0] inb_12;
reg  [15:0] inb_13;
reg  [15:0] inb_14;
reg  [15:0] inb_15;
reg  [15:0] next_inb_0;
reg  [15:0] next_inb_1;
reg  [15:0] next_inb_2;
reg  [15:0] next_inb_3;
reg  [15:0] next_inb_4;
reg  [15:0] next_inb_5;
reg  [15:0] next_inb_6;
reg  [15:0] next_inb_7;
reg  [15:0] next_inb_8;
reg  [15:0] next_inb_9;
reg  [15:0] next_inb_10;
reg  [15:0] next_inb_11;
reg  [15:0] next_inb_12;
reg  [15:0] next_inb_13;
reg  [15:0] next_inb_14;
reg  [15:0] next_inb_15;

reg  [63:0] out_0;
reg  [63:0] out_1;
reg  [63:0] out_2;
reg  [63:0] out_3;
reg  [63:0] out_4;
reg  [63:0] out_5;
reg  [63:0] out_6;
reg  [63:0] out_7;
reg  [63:0] out_8;
reg  [63:0] out_9;
reg  [63:0] out_10;
reg  [63:0] out_11;
reg  [63:0] out_12;
reg  [63:0] out_13;
reg  [63:0] out_14;
reg  [63:0] out_15;
reg  [63:0] next_out_0;
reg  [63:0] next_out_1;
reg  [63:0] next_out_2;
reg  [63:0] next_out_3;
reg  [63:0] next_out_4;
reg  [63:0] next_out_5;
reg  [63:0] next_out_6;
reg  [63:0] next_out_7;
reg  [63:0] next_out_8;
reg  [63:0] next_out_9;
reg  [63:0] next_out_10;
reg  [63:0] next_out_11;
reg  [63:0] next_out_12;
reg  [63:0] next_out_13;
reg  [63:0] next_out_14;
reg  [63:0] next_out_15;
reg  [63:0] par_0;
reg  [63:0] par_1;
reg  [63:0] par_2;
reg  [63:0] par_3;
reg  [63:0] par_4;
reg  [63:0] par_5;
reg  [15:0] par_b;

wire [63:0] tmp_out;


calvalue cal0( .in_0(par_0),  .in_1(par_1),  .in_2(par_2),  .in_3(par_3),  .in_4(par_4),  .in_5(par_5),  .in_b(par_b),  .out_ans(tmp_out));

always @ (*) begin
    if (reset) begin
        next_count  =  4'b0;
        next_loop   = 10'b0;
        next_inb_0  = 16'b0;
        next_inb_1  = 16'b0;
        next_inb_2  = 16'b0;
        next_inb_3  = 16'b0;
        next_inb_4  = 16'b0;
        next_inb_5  = 16'b0;
        next_inb_6  = 16'b0;
        next_inb_7  = 16'b0;
        next_inb_8  = 16'b0;
        next_inb_9  = 16'b0;
        next_inb_10 = 16'b0;
        next_inb_11 = 16'b0;
        next_inb_12 = 16'b0;
        next_inb_13 = 16'b0;
        next_inb_14 = 16'b0;
        next_inb_15 = 16'b0;

        next_out_0  = 64'b0;
        next_out_1  = 64'b0;
        next_out_2  = 64'b0;
        next_out_3  = 64'b0;
        next_out_4  = 64'b0;
        next_out_5  = 64'b0;
        next_out_6  = 64'b0;
        next_out_7  = 64'b0;
        next_out_8  = 64'b0;
        next_out_9  = 64'b0;
        next_out_10 = 64'b0;
        next_out_11 = 64'b0;
        next_out_12 = 64'b0;
        next_out_13 = 64'b0;
        next_out_14 = 64'b0;
        next_out_15 = 64'b0;
        par_0       = 64'b0;
        par_1       = 64'b0;
        par_2       = 64'b0;
        par_3       = 64'b0;
        par_4       = 64'b0;
        par_5       = 64'b0;
        par_b       = 16'b0;
        out_valid   =  1'b0;
        x_out       = 32'b0;
    end
    else begin
        next_count  = (in_en)? 4'b0   : count+4'b1;
        next_loop   = (count == 4'hf)?  loop+10'b1: loop;
        next_inb_0  = (in_en)? inb_1  : inb_0;
        next_inb_1  = (in_en)? inb_2  : inb_1;
        next_inb_2  = (in_en)? inb_3  : inb_2;
        next_inb_3  = (in_en)? inb_4  : inb_3;
        next_inb_4  = (in_en)? inb_5  : inb_4;
        next_inb_5  = (in_en)? inb_6  : inb_5;
        next_inb_6  = (in_en)? inb_7  : inb_6;
        next_inb_7  = (in_en)? inb_8  : inb_7;
        next_inb_8  = (in_en)? inb_9  : inb_8;
        next_inb_9  = (in_en)? inb_10 : inb_9;
        next_inb_10 = (in_en)? inb_11 : inb_10;
        next_inb_11 = (in_en)? inb_12 : inb_11;
        next_inb_12 = (in_en)? inb_13 : inb_12;
        next_inb_13 = (in_en)? inb_14 : inb_13;
        next_inb_14 = (in_en)? inb_15 : inb_14;
        next_inb_15 = (in_en)? b_in   : inb_15;

        next_out_0  = (in_en)? out_1  : ((count == 4'h0)? tmp_out : out_0);
        next_out_1  = (in_en)? out_2  : ((count == 4'h1)? tmp_out : out_1);
        next_out_2  = (in_en)? out_3  : ((count == 4'h2)? tmp_out : out_2);
        next_out_3  = (in_en)? out_4  : ((count == 4'h3)? tmp_out : out_3);
        next_out_4  = (in_en)? out_5  : ((count == 4'h4)? tmp_out : out_4);
        next_out_5  = (in_en)? out_6  : ((count == 4'h5)? tmp_out : out_5);
        next_out_6  = (in_en)? out_7  : ((count == 4'h6)? tmp_out : out_6);
        next_out_7  = (in_en)? out_8  : ((count == 4'h7)? tmp_out : out_7);
        next_out_8  = (in_en)? out_9  : ((count == 4'h8)? tmp_out : out_8);
        next_out_9  = (in_en)? out_10 : ((count == 4'h9)? tmp_out : out_9);
        next_out_10 = (in_en)? out_11 : ((count == 4'ha)? tmp_out : out_10);
        next_out_11 = (in_en)? out_12 : ((count == 4'hb)? tmp_out : out_11);
        next_out_12 = (in_en)? out_13 : ((count == 4'hc)? tmp_out : out_12);
        next_out_13 = (in_en)? out_14 : ((count == 4'hd)? tmp_out : out_13);
        next_out_14 = (in_en)? out_15 : ((count == 4'he)? tmp_out : out_14);
        next_out_15 = (in_en)? (b_in[15]? {20'hfffff, b_in[15:4], 32'b0} : {20'b0, b_in[15:4], 32'b0}) :
                     ((count == 4'hf)? tmp_out : out_15);

        case (count)
            4'h0: begin par_0 = 64'b0;  par_1 = 64'b0;  par_2 = 64'b0;  par_3 = out_1;  par_4 = out_2;  par_5 = out_3;  par_b = inb_0;  x_out = out_0[47:16];  end
            4'h1: begin par_0 = 64'b0;  par_1 = 64'b0;  par_2 = out_0;  par_3 = out_2;  par_4 = out_3;  par_5 = out_4;  par_b = inb_1;  x_out = out_1[47:16];  end
            4'h2: begin par_0 = 64'b0;  par_1 = out_0;  par_2 = out_1;  par_3 = out_3;  par_4 = out_4;  par_5 = out_5;  par_b = inb_2;  x_out = out_2[47:16];  end
            4'h3: begin par_0 = out_0;  par_1 = out_1;  par_2 = out_2;  par_3 = out_4;  par_4 = out_5;  par_5 = out_6;  par_b = inb_3;  x_out = out_3[47:16];  end
            4'h4: begin par_0 = out_1;  par_1 = out_2;  par_2 = out_3;  par_3 = out_5;  par_4 = out_6;  par_5 = out_7;  par_b = inb_4;  x_out = out_4[47:16];  end
            4'h5: begin par_0 = out_2;  par_1 = out_3;  par_2 = out_4;  par_3 = out_6;  par_4 = out_7;  par_5 = out_8;  par_b = inb_5;  x_out = out_5[47:16];  end
            4'h6: begin par_0 = out_3;  par_1 = out_4;  par_2 = out_5;  par_3 = out_7;  par_4 = out_8;  par_5 = out_9;  par_b = inb_6;  x_out = out_6[47:16];  end
            4'h7: begin par_0 = out_4;  par_1 = out_5;  par_2 = out_6;  par_3 = out_8;  par_4 = out_9;  par_5 = out_10; par_b = inb_7;  x_out = out_7[47:16];  end
            4'h8: begin par_0 = out_5;  par_1 = out_6;  par_2 = out_7;  par_3 = out_9;  par_4 = out_10; par_5 = out_11; par_b = inb_8;  x_out = out_8[47:16];  end
            4'h9: begin par_0 = out_6;  par_1 = out_7;  par_2 = out_8;  par_3 = out_10; par_4 = out_11; par_5 = out_12; par_b = inb_9;  x_out = out_9[47:16];  end
            4'ha: begin par_0 = out_7;  par_1 = out_8;  par_2 = out_9;  par_3 = out_11; par_4 = out_12; par_5 = out_13; par_b = inb_10; x_out = out_10[47:16]; end
            4'hb: begin par_0 = out_8;  par_1 = out_9;  par_2 = out_10; par_3 = out_12; par_4 = out_13; par_5 = out_14; par_b = inb_11; x_out = out_11[47:16]; end
            4'hc: begin par_0 = out_9;  par_1 = out_10; par_2 = out_11; par_3 = out_13; par_4 = out_14; par_5 = out_15; par_b = inb_12; x_out = out_12[47:16]; end
            4'hd: begin par_0 = out_10; par_1 = out_11; par_2 = out_12; par_3 = out_14; par_4 = out_15; par_5 = 64'b0;  par_b = inb_13; x_out = out_13[47:16]; end
            4'he: begin par_0 = out_11; par_1 = out_12; par_2 = out_13; par_3 = out_15; par_4 = 64'b0;  par_5 = 64'b0;  par_b = inb_14; x_out = out_14[47:16]; end
            4'hf: begin par_0 = out_12; par_1 = out_13; par_2 = out_14; par_3 = 64'b0;  par_4 = 64'b0;  par_5 = 64'b0;  par_b = inb_15; x_out = out_15[47:16]; end
        endcase
        out_valid = loop[9];
    end
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        count  <=  4'b0;
        loop   <= 10'b0;
        inb_0  <= 16'b0;
        inb_1  <= 16'b0;
        inb_2  <= 16'b0;
        inb_3  <= 16'b0;
        inb_4  <= 16'b0;
        inb_5  <= 16'b0;
        inb_6  <= 16'b0;
        inb_7  <= 16'b0;
        inb_8  <= 16'b0;
        inb_9  <= 16'b0;
        inb_10 <= 16'b0;
        inb_11 <= 16'b0;
        inb_12 <= 16'b0;
        inb_13 <= 16'b0;
        inb_14 <= 16'b0;
        inb_15 <= 16'b0;

        out_0  <= 64'b0;
        out_1  <= 64'b0;
        out_2  <= 64'b0;
        out_3  <= 64'b0;
        out_4  <= 64'b0;
        out_5  <= 64'b0;
        out_6  <= 64'b0;
        out_7  <= 64'b0;
        out_8  <= 64'b0;
        out_9  <= 64'b0;
        out_10 <= 64'b0;
        out_11 <= 64'b0;
        out_12 <= 64'b0;
        out_13 <= 64'b0;
        out_14 <= 64'b0;
        out_15 <= 64'b0;
 
    end
    else begin
        count  <= next_count;
        loop   <= next_loop;
        inb_0  <= next_inb_0;
        inb_1  <= next_inb_1;
        inb_2  <= next_inb_2;
        inb_3  <= next_inb_3;
        inb_4  <= next_inb_4;
        inb_5  <= next_inb_5;
        inb_6  <= next_inb_6;
        inb_7  <= next_inb_7;
        inb_8  <= next_inb_8;
        inb_9  <= next_inb_9;
        inb_10 <= next_inb_10;
        inb_11 <= next_inb_11;
        inb_12 <= next_inb_12;
        inb_13 <= next_inb_13;
        inb_14 <= next_inb_14;
        inb_15 <= next_inb_15;

        out_0  <= next_out_0;
        out_1  <= next_out_1;
        out_2  <= next_out_2;
        out_3  <= next_out_3;
        out_4  <= next_out_4;
        out_5  <= next_out_5;
        out_6  <= next_out_6;
        out_7  <= next_out_7;
        out_8  <= next_out_8;
        out_9  <= next_out_9;
        out_10 <= next_out_10;
        out_11 <= next_out_11;
        out_12 <= next_out_12;
        out_13 <= next_out_13;
        out_14 <= next_out_14;
        out_15 <= next_out_15;
    end
end

endmodule

