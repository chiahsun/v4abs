module CTE(clk, reset, op_mode, in_en, yuv_in, rgb_in, busy, out_valid, rgb_out, yuv_out);

input clk;
input reset;
input op_mode;
input in_en;
input [7:0] yuv_in;
input [23:0] rgb_in;

output busy;
output out_valid;
output [23:0] rgb_out;
output [7:0] yuv_out;

parameter yuv_to_rgb_inst0.S_U = 4'b0000;
parameter yuv_to_rgb_inst0.S_Y1 = 4'b0001;
parameter yuv_to_rgb_inst0.S_V = 4'b0010;
parameter yuv_to_rgb_inst0.S_BUSY1 = 4'b0011;
parameter yuv_to_rgb_inst0.S_Y2 = 4'b0100;
parameter yuv_to_rgb_inst0.S_BUSY2 = 4'b0101;

wire yuv_to_rgb_in_en;
wire yuv_to_rgb_busy;
wire yuv_to_rgb_out_valid;
wire yuv_to_rgb_inst0.clk;
wire yuv_to_rgb_inst0.reset;
wire yuv_to_rgb_inst0.in_en;
wire [7:0] yuv_to_rgb_inst0.yuv_in;
wire yuv_to_rgb_inst0.busy;
wire yuv_to_rgb_inst0.out_valid;
wire [23:0] yuv_to_rgb_inst0.rgb_out;
wire [7:0] yuv_to_rgb_inst0.reg_U_next;
wire [7:0] yuv_to_rgb_inst0.reg_Y1_next;
wire [7:0] yuv_to_rgb_inst0.reg_V_next;
wire [7:0] yuv_to_rgb_inst0.reg_Y2_next;
wire [15:0] yuv_to_rgb_inst0.R_ext;
wire [15:0] yuv_to_rgb_inst0.G_ext;
wire [15:0] yuv_to_rgb_inst0.B_ext;
wire [15:0] yuv_to_rgb_inst0.U_ext;
wire [15:0] yuv_to_rgb_inst0.Y_ext;
wire [15:0] yuv_to_rgb_inst0.V_ext;
wire [7:0] yuv_to_rgb_inst0.R_out;
wire [7:0] yuv_to_rgb_inst0.G_out;
wire [7:0] yuv_to_rgb_inst0.B_out;

reg [3:0] yuv_to_rgb_inst0.state;
reg [3:0] yuv_to_rgb_inst0.state_next;
reg [7:0] yuv_to_rgb_inst0.reg_U;
reg [7:0] yuv_to_rgb_inst0.reg_Y1;
reg [7:0] yuv_to_rgb_inst0.reg_V;
reg [7:0] yuv_to_rgb_inst0.reg_Y2;

assign yuv_to_rgb_in_en=in_en;
assign busy=(!op_mode ? yuv_to_rgb_busy : 1'b1);
assign out_valid=(!op_mode ? yuv_to_rgb_out_valid : 1'b0);
assign yuv_out=8'b0;
assign yuv_to_rgb_inst0.clk=clk;
assign yuv_to_rgb_inst0.reset=reset;
assign yuv_to_rgb_inst0.in_en=yuv_to_rgb_in_en;
assign yuv_to_rgb_inst0.yuv_in=yuv_in;
assign yuv_to_rgb_inst0.busy=yuv_to_rgb_busy;
assign yuv_to_rgb_inst0.out_valid=yuv_to_rgb_out_valid;
assign yuv_to_rgb_inst0.rgb_out=rgb_out;
assign yuv_to_rgb_inst0.busy=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY1)||(yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY2));
assign yuv_to_rgb_inst0.out_valid=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY1)||(yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY2));
assign yuv_to_rgb_inst0.reg_U_next=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_U) ? yuv_to_rgb_inst0.yuv_in : yuv_to_rgb_inst0.reg_U);
assign yuv_to_rgb_inst0.reg_Y1_next=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_Y1) ? yuv_to_rgb_inst0.yuv_in : yuv_to_rgb_inst0.reg_Y1);
assign yuv_to_rgb_inst0.reg_V_next=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_V) ? yuv_to_rgb_inst0.yuv_in : yuv_to_rgb_inst0.reg_V);
assign yuv_to_rgb_inst0.reg_Y2_next=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_Y2) ? yuv_to_rgb_inst0.yuv_in : yuv_to_rgb_inst0.reg_Y2);
assign yuv_to_rgb_inst0.U_ext={{8{yuv_to_rgb_inst0.reg_U[7]}},yuv_to_rgb_inst0.reg_U};
assign yuv_to_rgb_inst0.Y_ext=((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY1) ? {8'b0,yuv_to_rgb_inst0.reg_Y1} : {8'b0,yuv_to_rgb_inst0.reg_Y2});
assign yuv_to_rgb_inst0.V_ext={{8{yuv_to_rgb_inst0.reg_V[7]}},yuv_to_rgb_inst0.reg_V};
assign yuv_to_rgb_inst0.R_ext=((16'b1000*yuv_to_rgb_inst0.Y_ext)+(16'b1101*yuv_to_rgb_inst0.V_ext));
assign yuv_to_rgb_inst0.G_ext=(((16'b1000*yuv_to_rgb_inst0.Y_ext)+(16'hfffe*yuv_to_rgb_inst0.U_ext))+(16'hfffa*yuv_to_rgb_inst0.V_ext));
assign yuv_to_rgb_inst0.B_ext=((16'b1000*yuv_to_rgb_inst0.Y_ext)+(16'b10000*yuv_to_rgb_inst0.U_ext));
assign yuv_to_rgb_inst0.R_out=(yuv_to_rgb_inst0.R_ext[15] ? 8'b0 : (((yuv_to_rgb_inst0.R_ext[14:11]!=4'b0) ? 8'd255 : yuv_to_rgb_inst0.R_ext[2]) ? ((yuv_to_rgb_inst0.R_ext[10:3]=8'd255) ? 8'd255 : (yuv_to_rgb_inst0.R_ext[10:3]+8'd1)) : yuv_to_rgb_inst0.R_ext[10:3]));
assign yuv_to_rgb_inst0.G_out=(yuv_to_rgb_inst0.G_ext[15] ? 8'b0 : (((yuv_to_rgb_inst0.G_ext[14:11]!=4'b0) ? 8'd255 : yuv_to_rgb_inst0.G_ext[2]) ? ((yuv_to_rgb_inst0.G_ext[10:3]=8'd255) ? 8'd255 : (yuv_to_rgb_inst0.G_ext[10:3]+8'd1)) : yuv_to_rgb_inst0.G_ext[10:3]));
assign yuv_to_rgb_inst0.B_out=(yuv_to_rgb_inst0.B_ext[15] ? 8'b0 : (((yuv_to_rgb_inst0.B_ext[14:11]!=4'b0) ? 8'd255 : yuv_to_rgb_inst0.B_ext[2]) ? ((yuv_to_rgb_inst0.B_ext[10:3]=8'd255) ? 8'd255 : (yuv_to_rgb_inst0.B_ext[10:3]+8'd1)) : yuv_to_rgb_inst0.B_ext[10:3]));
assign yuv_to_rgb_inst0.rgb_out={yuv_to_rgb_inst0.R_out,yuv_to_rgb_inst0.G_out,yuv_to_rgb_inst0.B_out};

always @ (*)
  begin
    if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_U)) begin
      yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_Y1;
    end
    else begin
      if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_Y1)) begin
        yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_V;
      end
      else begin
        if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_V)) begin
          yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_BUSY1;
        end
        else begin
          if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY1)) begin
            yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_Y2;
          end
          else begin
            if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_Y2)) begin
              yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_BUSY2;
            end
            else begin
              if ((yuv_to_rgb_inst0.state=yuv_to_rgb_inst0.S_BUSY2)) begin
                yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.S_U;
              end
              else begin
                yuv_to_rgb_inst0.state_next <= yuv_to_rgb_inst0.state;
              end
            end
          end
        end
      end
    end
  end

always @ (posedge yuv_to_rgb_inst0.clk)
  begin
    if ((yuv_to_rgb_inst0.reset||!yuv_to_rgb_inst0.in_en)) begin
      begin
        yuv_to_rgb_inst0.state <= yuv_to_rgb_inst0.S_U;
        yuv_to_rgb_inst0.reg_U <= 8'b0;
        yuv_to_rgb_inst0.reg_Y1 <= 8'b0;
        yuv_to_rgb_inst0.reg_V <= 8'b0;
        yuv_to_rgb_inst0.reg_Y2 <= 8'b0;
      end
    end
    else begin
      begin
        yuv_to_rgb_inst0.state <= yuv_to_rgb_inst0.state_next;
        yuv_to_rgb_inst0.reg_U <= yuv_to_rgb_inst0.reg_U_next;
        yuv_to_rgb_inst0.reg_Y1 <= yuv_to_rgb_inst0.reg_Y1_next;
        yuv_to_rgb_inst0.reg_V <= yuv_to_rgb_inst0.reg_V_next;
        yuv_to_rgb_inst0.reg_Y2 <= yuv_to_rgb_inst0.reg_Y2_next;
      end
    end
  end


endmodule

module YUV_TO_RGB(clk, reset, in_en, yuv_in, busy, out_valid, rgb_out);

input clk;
input reset;
input in_en;
input [7:0] yuv_in;

output busy;
output out_valid;
output [23:0] rgb_out;

parameter S_U = 4'b0000;
parameter S_Y1 = 4'b0001;
parameter S_V = 4'b0010;
parameter S_BUSY1 = 4'b0011;
parameter S_Y2 = 4'b0100;
parameter S_BUSY2 = 4'b0101;

wire [7:0] reg_U_next;
wire [7:0] reg_Y1_next;
wire [7:0] reg_V_next;
wire [7:0] reg_Y2_next;
wire [15:0] R_ext;
wire [15:0] G_ext;
wire [15:0] B_ext;
wire [15:0] U_ext;
wire [15:0] Y_ext;
wire [15:0] V_ext;
wire [7:0] R_out;
wire [7:0] G_out;
wire [7:0] B_out;

reg [3:0] state;
reg [3:0] state_next;
reg [7:0] reg_U;
reg [7:0] reg_Y1;
reg [7:0] reg_V;
reg [7:0] reg_Y2;

assign busy=((state=S_BUSY1)||(state=S_BUSY2));
assign out_valid=((state=S_BUSY1)||(state=S_BUSY2));
assign reg_U_next=((state=S_U) ? yuv_in : reg_U);
assign reg_Y1_next=((state=S_Y1) ? yuv_in : reg_Y1);
assign reg_V_next=((state=S_V) ? yuv_in : reg_V);
assign reg_Y2_next=((state=S_Y2) ? yuv_in : reg_Y2);
assign U_ext={{8{reg_U[7]}},reg_U};
assign Y_ext=((state=S_BUSY1) ? {8'b0,reg_Y1} : {8'b0,reg_Y2});
assign V_ext={{8{reg_V[7]}},reg_V};
assign R_ext=((16'b1000*Y_ext)+(16'b1101*V_ext));
assign G_ext=(((16'b1000*Y_ext)+(16'hfffe*U_ext))+(16'hfffa*V_ext));
assign B_ext=((16'b1000*Y_ext)+(16'b10000*U_ext));
assign R_out=(R_ext[15] ? 8'b0 : (((R_ext[14:11]!=4'b0) ? 8'd255 : R_ext[2]) ? ((R_ext[10:3]=8'd255) ? 8'd255 : (R_ext[10:3]+8'd1)) : R_ext[10:3]));
assign G_out=(G_ext[15] ? 8'b0 : (((G_ext[14:11]!=4'b0) ? 8'd255 : G_ext[2]) ? ((G_ext[10:3]=8'd255) ? 8'd255 : (G_ext[10:3]+8'd1)) : G_ext[10:3]));
assign B_out=(B_ext[15] ? 8'b0 : (((B_ext[14:11]!=4'b0) ? 8'd255 : B_ext[2]) ? ((B_ext[10:3]=8'd255) ? 8'd255 : (B_ext[10:3]+8'd1)) : B_ext[10:3]));
assign rgb_out={R_out,G_out,B_out};

always @ (*)
  begin
    if ((state=S_U)) begin
      state_next <= S_Y1;
    end
    else begin
      if ((state=S_Y1)) begin
        state_next <= S_V;
      end
      else begin
        if ((state=S_V)) begin
          state_next <= S_BUSY1;
        end
        else begin
          if ((state=S_BUSY1)) begin
            state_next <= S_Y2;
          end
          else begin
            if ((state=S_Y2)) begin
              state_next <= S_BUSY2;
            end
            else begin
              if ((state=S_BUSY2)) begin
                state_next <= S_U;
              end
              else begin
                state_next <= state;
              end
            end
          end
        end
      end
    end
  end

always @ (posedge clk)
  begin
    if ((reset||!in_en)) begin
      begin
        state <= S_U;
        reg_U <= 8'b0;
        reg_Y1 <= 8'b0;
        reg_V <= 8'b0;
        reg_Y2 <= 8'b0;
      end
    end
    else begin
      begin
        state <= state_next;
        reg_U <= reg_U_next;
        reg_Y1 <= reg_Y1_next;
        reg_V <= reg_V_next;
        reg_Y2 <= reg_Y2_next;
      end
    end
  end


endmodule

