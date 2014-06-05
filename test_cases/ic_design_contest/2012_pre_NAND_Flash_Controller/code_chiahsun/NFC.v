module FCR(clk, en, addr, write_ready, ready, data_valid, data_out, done 
           , F_IO_A, F_CLE_A, F_ALE_A, F_REN_A, F_WEN_A, F_RB_A);

input clk;
input en;
input [8:0] addr;
input write_ready;
output ready;
output data_valid;
output [7:0] data_out;
output done;

inout [7:0] F_IO_A;
output F_CLE_A;
output F_ALE_A;
output F_REN_A;
output F_WEN_A;
input F_RB_A;

wire [7:0] a0_7;
wire [7:0] a8;
wire [7:0] a9_16;

assign a0_7 = 8'h00;
assign a8 = 8'h00;
assign a9_16 = addr[7:0];
assign a17 = addr[8]; 

reg data_valid;
reg next_data_valid;

reg ready;
reg next_ready;

reg [3:0] seq;
reg [3:0] next_seq;
reg [2:0] state;
reg [2:0] next_state; 

wire cle, wen, ale, ren;
assign F_CLE_A = cle;
assign F_ALE_A = ale;
assign F_REN_A = ren;
assign F_WEN_A = wen;

reg [7:0] io;
reg [7:0] next_io;

parameter STATE_INIT = 3'b000
        , STATE_SEQ = STATE_INIT + 1
        , STATE_WAIT_RB = STATE_SEQ + 1
        , STATE_DATA_READ = STATE_WAIT_RB + 1
        , STATE_DONE = STATE_DATA_READ + 1;

/*parameter CLE_SEQ = 12'b011000000000
        , WEN_SEQ = 12'b101010101111
        , ALE_SEQ = 12'b000111111000
        , REN_SEQ = 12'b111111111101;*/

parameter CLE_SEQ = 12'b000000000110
        , WEN_SEQ = 12'b111101010101
        , ALE_SEQ = 12'b000111111000
        , REN_SEQ = 12'b101111111111;

parameter SEQ_INIT = 4'h0
        , DATA_VALID_INIT = 1'b0
        , IO_INIT = 8'h0
        , CNT_INIT = 10'h0
        , DONE_INIT = 1'b0
        , READY_INIT = 1'b0
        , DATA_OUT_INIT = 8'b0;

wire [11:0] cle_seq;
wire [11:0] wen_seq;
wire [11:0] ale_seq;
wire [11:0] ren_seq;

assign cle_seq = CLE_SEQ;
assign wen_seq = WEN_SEQ;
assign ale_seq = ALE_SEQ;
assign ren_seq = REN_SEQ;

assign cle = cle_seq[seq];
assign wen = wen_seq[seq];
assign ale = ale_seq[seq];
assign ren = ren_seq[seq];

assign F_IO_A = io;

wire [7:0] addr_part;

// since we have io as reg, and next_io = addr_part
assign addr_part = (seq == 0 || seq == 1) ? a8 
                 : (seq == 2 || seq == 3) ? a0_7
                 : (seq == 4 || seq == 5) ? a9_16
                 : (seq == 6 || seq == 7) ? a17
                 : 8'h0;

reg [9:0] cnt;
reg [9:0] next_cnt;

reg [7:0] data_out;
reg [7:0] next_data_out;

always @ (*) begin
    next_state = state;
    next_seq = seq;
    next_data_valid = data_valid;
    next_io = io;
    next_cnt = cnt;
    next_ready = ready;
    next_data_out = data_out;
    case (state)
        STATE_INIT: begin
            next_state = STATE_SEQ;
        end
        STATE_SEQ: begin
            next_state = (seq == 9) ? STATE_WAIT_RB : STATE_SEQ;
            next_seq = seq + 1;
            next_io = addr_part;
        end
        STATE_WAIT_RB: begin
            next_state = (write_ready) ? STATE_DATA_READ : state;
            next_io = 8'hzz;
            next_ready = 1'b1;
        end
        STATE_DATA_READ: begin
            next_state = (cnt == 511) ? STATE_DONE : state;
            next_data_valid = 1'b1;
            next_seq = (seq == 10) ? 11 : 10;
            next_cnt = (seq == 11) ? (cnt + 1) : cnt;
            next_data_out = (seq == 10) ? F_IO_A : data_out;
        end
        STATE_DONE: begin
        end
    endcase
end

assign done = (state == STATE_DONE);

always @ (posedge clk) begin

    if(!en) begin
        state <= STATE_INIT;
        seq <= SEQ_INIT;
        data_valid <= DATA_VALID_INIT;
        io <= IO_INIT;
        cnt <= CNT_INIT;
        ready <= READY_INIT;
        data_out <= DATA_OUT_INIT;
    end
    else begin 
        state <= next_state;
        seq <= next_seq;
        data_valid <= next_data_valid;
        io <= next_io; 
        cnt <= next_cnt;
        ready <= next_ready;
        data_out <= next_data_out;
    end
end

endmodule 

module FCW(clk, en, addr, read_ready, data, ready, done
           , F_IO_B, F_CLE_B, F_ALE_B, F_REN_B, F_WEN_B, F_RB_B);

input clk;
input en;
input [8:0] addr;
input read_ready;
input [7:0] data;
output ready;
output done;

inout [7:0] F_IO_B;
output F_CLE_B;
output F_ALE_B;
output F_REN_B;
output F_WEN_B;
input F_RB_B;

wire [7:0] a0_7;
wire [7:0] a8;
wire [7:0] a9_16;

assign a0_7 = 8'h00;
assign a8 = 8'h80;
assign a9_16 = addr[7:0];
assign a17 = addr[8]; 


reg [4:0] seq;
reg [4:0] next_seq;
reg [2:0] state;
reg [2:0] next_state; 

reg ready;
reg next_ready;

wire cle, wen, ale, ren;
assign F_CLE_B = cle;
assign F_ALE_B = ale;
assign F_REN_B = ren;
assign F_WEN_B = wen;

reg [7:0] io;
reg [7:0] next_io;

parameter STATE_INIT = 3'b000
        , STATE_SEQ = STATE_INIT + 1
        , STATE_WAIT = STATE_SEQ + 1
        , STATE_DATA_WRITE = STATE_WAIT + 1
        , STATE_WAIT_RB = STATE_DATA_WRITE + 1
        , STATE_DONE = STATE_WAIT_RB + 1;

parameter CLE_SEQ = 17'b01110000000000110
        , WEN_SEQ = 17'b11011101101010101
        , ALE_SEQ = 17'b00000000111111000
        , REN_SEQ = 17'b11111111111111111;

parameter SEQ_INIT = 4'h0
        , DATA_VALID_INIT = 1'b0
        , IO_INIT = 8'h0
        , CNT_INIT = 10'h0
        , DONE_INIT = 1'b0
        , READY_INIT = 1'b0;

wire [16:0] cle_seq;
wire [16:0] wen_seq;
wire [16:0] ale_seq;
wire [16:0] ren_seq;

assign cle_seq = CLE_SEQ;
assign wen_seq = WEN_SEQ;
assign ale_seq = ALE_SEQ;
assign ren_seq = REN_SEQ;

assign cle = cle_seq[seq];
assign wen = wen_seq[seq];
assign ale = ale_seq[seq];
assign ren = ren_seq[seq];

assign F_IO_B = (state == STATE_SEQ || state == STATE_WAIT_RB) ? io : data;

wire [7:0] addr_part;

// since we have io as reg, and next_io = addr_part
assign addr_part = (seq == 0 || seq == 1) ? a8 
                 : (seq == 2 || seq == 3) ? a0_7
                 : (seq == 4 || seq == 5) ? a9_16
                 : (seq == 6 || seq == 7) ? a17
                 : 8'h0;

reg [9:0] cnt;
reg [9:0] next_cnt;

always @ (*) begin
    next_state = state;
    next_seq = seq;
    next_io = io;
    next_cnt = cnt;
    next_ready = ready;
    case (state)
        STATE_INIT: begin
            next_state = STATE_SEQ;
        end
        STATE_SEQ: begin
            next_state = (seq == 9) ? STATE_WAIT : STATE_SEQ;
            next_seq = seq + 1;
            next_io = addr_part;
            next_ready = (seq == 9) ? 1'b1 : ready;
        end
        STATE_WAIT: begin
            next_state = (read_ready) ? STATE_DATA_WRITE : state;
        end
        STATE_DATA_WRITE: begin
            next_state = (cnt == 511) ? STATE_WAIT_RB : state;
            next_seq = (cnt == 511) ? 12 : 
                       (seq == 10) ? 11 : 10;
            next_cnt = (seq == 11) ? (cnt + 1) : cnt;
            next_io = data;
        end
        STATE_WAIT_RB: begin
            next_io = 8'h10;
            next_seq = (seq >= 16) ? 16 : (seq + 1);
            next_state = (seq == 16 && F_RB_B) ? STATE_DONE : state;
        end
        STATE_DONE: begin
        end
    endcase
end

assign done = (state == STATE_DONE);

always @ (posedge clk) begin

    if(!en) begin
        state <= STATE_INIT;
        seq <= SEQ_INIT;
        io <= IO_INIT;
        cnt <= CNT_INIT;
        ready = READY_INIT;
    end
    else begin 
        state <= next_state;
        seq <= next_seq;
        io <= next_io; 
        cnt <= next_cnt;
        ready = next_ready;
    end
end

endmodule 

module NFC(clk, rst, done, F_IO_A, F_CLE_A, F_ALE_A, F_REN_A, F_WEN_A, F_RB_A, F_IO_B, F_CLE_B, F_ALE_B, F_REN_B, F_WEN_B, F_RB_B);

  input clk;
  input rst;
  output done;
  inout [7:0] F_IO_A;
  output F_CLE_A;
  output F_ALE_A;
  output F_REN_A;
  output F_WEN_A;
  input  F_RB_A;
  inout [7:0] F_IO_B;
  output F_CLE_B;
  output F_ALE_B;
  output F_REN_B;
  output F_WEN_B;
  input  F_RB_B;

wire en;
wire [8:0] addr;
wire fcw_ready;
wire fcr_ready;
wire fcr_data_valid;
wire [7:0] fcr_data_out;
wire fcr_done;
wire fcw_done;

reg [8:0] reg_addr;
reg [8:0] next_reg_addr;

reg reg_done;
reg next_reg_done;

reg reg_en;
reg next_reg_en;

reg [2:0] state;
reg [2:0] next_state;

parameter STATE_INIT = 3'b000
        , STATE_ADDR = STATE_INIT + 1
        , STATE_ENABLE = STATE_ADDR + 1
        , STATE_ADDR_INCR = STATE_ENABLE + 1
        , STATE_DONE = STATE_ADDR_INCR + 1;

parameter ADDR_INIT = 8'h0
        , DONE_INIT = 1'b0
        , EN_INIT = 1'b0;

assign done = reg_done;

always @ (*) begin
    next_reg_done = reg_done;
    next_reg_addr = reg_addr;
    next_reg_en = reg_en;
    next_state = state;
    case (state) 
        STATE_INIT : begin
            next_reg_addr = ADDR_INIT;
            next_reg_done = DONE_INIT;
            next_reg_en = EN_INIT;
            next_state = STATE_ADDR;     
        end
        STATE_ADDR : begin
            next_state = STATE_ENABLE;
        end
        STATE_ENABLE : begin
            next_reg_en = 1'b1;
            next_state = (fcr_done && fcw_done) ? STATE_ADDR_INCR : STATE_ENABLE;
        end
        STATE_ADDR_INCR : begin
            next_reg_en = 1'b0;
            next_reg_addr = reg_addr + 1;
            next_state = (reg_addr == 511) ? STATE_DONE : STATE_ADDR;
        end
        STATE_DONE : begin
            next_reg_done = 1'b1;
        end
    endcase
end

always @ (posedge clk) begin
    if (rst) begin
        reg_done <= DONE_INIT;
        reg_addr <= ADDR_INIT;
        reg_en <= EN_INIT;
        state <= STATE_INIT;
    end
    else begin
        reg_done <= next_reg_done;
        reg_addr <= next_reg_addr;
        reg_en <= next_reg_en;
        state <= next_state;
    end  
end

assign en = reg_en;
assign addr = reg_addr;

FCR fcr(.clk(clk), .en(en), .addr(addr), .write_ready(fcw_ready), .ready(fcr_ready), .data_valid(fcr_data_valid), .data_out(fcr_data_out), .done(fcr_done), .F_IO_A(F_IO_A), .F_CLE_A(F_CLE_A), .F_ALE_A(F_ALE_A), .F_REN_A(F_REN_A), .F_WEN_A(F_WEN_A), .F_RB_A(F_RB_A));

FCW fcw(.clk(clk), .en(en), .addr(addr), .read_ready(fcr_ready), .data(fcr_data_out), .ready(fcw_ready), .done(fcw_done)
           , .F_IO_B(F_IO_B), .F_CLE_B(F_CLE_B), .F_ALE_B(F_ALE_B), .F_REN_B(F_REN_B), .F_WEN_B(F_WEN_B), .F_RB_B(F_RB_B));

endmodule
