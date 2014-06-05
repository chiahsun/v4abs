module IROM_CTRL(clk, reset, IROM_EN, IROM_A, valid, done, busy);

input clk;
input reset;
output IROM_EN;
output [5:0] IROM_A;
output valid;
output done;
output busy;

reg [5:0] reg_addr;
reg done;
reg en;
reg valid;
reg busy;

reg [5:0] next_reg_addr;
reg next_done;
reg next_en;
reg next_valid;
reg next_busy;

parameter EN_ENABLE = 1'b0
        , EN_DISABLE = 1'b1;

parameter ADDR_INIT = 6'h0
        , DONE_INIT = 1'b0
        , EN_INIT = EN_ENABLE
        , VALID_INIT = 1'b0
        , BUSY_INIT = 1'b1;

assign IROM_EN = en;
assign IROM_A = reg_addr;

always @ (*) begin
    next_reg_addr = reg_addr;
    next_done = done;
    next_en = en;
    next_valid = valid;
    next_busy = busy;
    
    if (!done) begin
        if (!valid) begin
            next_valid = 1'b1;
            next_reg_addr = ADDR_INIT;
        end
        else begin
            // we want done active high with last data valid
            if (reg_addr == 62)
                next_done = 1'b1;
            if (reg_addr == 63) 
                next_en = EN_DISABLE;
            else 
                next_reg_addr = reg_addr + 1;
        end
    end
    else begin
        next_busy = 1'b0;
    end
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        reg_addr <= ADDR_INIT;
        done <= DONE_INIT;
        en <= EN_INIT;
        valid <= VALID_INIT;
        busy <= BUSY_INIT;
    end
    else begin
        reg_addr <= next_reg_addr;
        done <= next_done;
        en <= next_en;
        valid <= next_valid;
        busy <= next_busy;
    end
end


endmodule

module IMAGE(clk, reset, IROM_Q, IROM_A, irom_valid, irom_done, cmd, cmd_valid, done, data, IRB_A, busy);

input clk;
input reset;
input [7:0] IROM_Q;
input [5:0] IROM_A;
input irom_valid;
input irom_done;
input [2:0] cmd;
input cmd_valid;
output done;
output [7:0] data;
output busy;
input [5:0] IRB_A;

reg [7:0] buffer [7:0] [7:0];
reg [7:0] next_buffer [7:0] [7:0];

reg [1:0] state;
reg [1:0] next_state; 

reg [2:0] reg_cmd;
reg [2:0] next_reg_cmd;

reg busy;
wire next_busy;

reg done;
reg next_done;

reg [2:0] op_x;
reg [2:0] op_y;

reg [2:0] next_op_x;
reg [2:0] next_op_y;

parameter STATE_READ_IROM = 2'b00
        , STATE_READ_CMD = STATE_READ_IROM + 1
        , STATE_BUSY = STATE_READ_CMD + 1
        , STATE_DONE = STATE_BUSY + 1;

parameter CMD_WRITE = 3'b000
        , CMD_SHIFT_UP = CMD_WRITE + 1
        , CMD_SHIFT_DOWN = CMD_SHIFT_UP + 1
        , CMD_SHIFT_LEFT = CMD_SHIFT_DOWN + 1
        , CMD_SHIFT_RIGHT = CMD_SHIFT_LEFT + 1
        , CMD_AVERAGE = CMD_SHIFT_RIGHT + 1
        , CMD_MIRROW_X = CMD_AVERAGE + 1
        , CMD_MIRROW_Y = CMD_MIRROW_X + 1
        , CMD_DO_NOTHING = CMD_MIRROW_Y + 1;

parameter STATE_INIT = STATE_READ_IROM
        , CMD_INIT = CMD_DO_NOTHING
        , OP_X_INIT = 4
        , OP_Y_INIT = 4
        , BUSY_INIT = 1'b0
        , DONE_INIT = 1'b0;

wire [2:0] addr_x;
wire [2:0] addr_y;

assign addr_x = IROM_A[2:0];
assign addr_y = IROM_A[5:3];

// 8 bits + 2 bits
wire [9:0] sum;
wire [7:0] average;

assign sum = {2'b0, buffer[op_x][op_y]}
           + {2'b0, buffer[op_x][op_y-1]}
           + {2'b0, buffer[op_x-1][op_y]}
           + {2'b0, buffer[op_x-1][op_y-1]};

assign average = sum[9:2];

wire [2:0] irb_a_x;
wire [2:0] irb_a_y;
assign irb_a_x = IRB_A[2:0];
assign irb_a_y = IRB_A[5:3];

assign data = buffer[irb_a_x][irb_a_y];

wire [7:0] d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d62, d63;
wire [7:0] nd0, nd1, nd2, nd3, nd4, nd5, nd6, nd7, nd8, nd9, nd62, nd63;

assign d0 = buffer[0][0];
assign d1 = buffer[1][0];
assign d2 = buffer[2][0];
assign d3 = buffer[3][0];
assign d4 = buffer[4][0];
assign d5 = buffer[5][0];
assign d6 = buffer[6][0];
assign d7 = buffer[7][0];
assign d8 = buffer[0][1];
assign d9 = buffer[1][1];
assign d62 = buffer[6][7];
assign d63 = buffer[7][7];

assign nd0 = next_buffer[0][0];
assign nd1 = next_buffer[1][0];
assign nd2 = next_buffer[2][0];
assign nd3 = next_buffer[3][0];
assign nd4 = next_buffer[4][0];
assign nd5 = next_buffer[5][0];
assign nd6 = next_buffer[6][0];
assign nd7 = next_buffer[7][0];
assign nd8 = next_buffer[0][1];
assign nd9 = next_buffer[1][1];
assign nd62 = next_buffer[6][7];
assign nd63 = next_buffer[7][7];



always @ (*) begin
    next_state = state;
    next_buffer = buffer;
    next_op_x = op_x;
    next_op_y = op_y;
    next_done = done;
    case (state) 
        STATE_READ_IROM : begin
            if (irom_valid)
                next_buffer[addr_x][addr_y] = IROM_Q;
            if (irom_done)
                next_state = STATE_READ_CMD;
        end
        STATE_READ_CMD : begin
            if (cmd_valid) begin
                next_reg_cmd = cmd;
                next_state = STATE_BUSY;
            end
        end
        STATE_BUSY : begin
            case (reg_cmd)
                CMD_WRITE: begin
                    next_state = STATE_DONE;
                    next_done = 1'b1;
                end 
                CMD_SHIFT_UP: begin
                    next_state = STATE_READ_CMD;
                    next_op_y = (op_y == 1) ? 1 : (op_y - 1);
                end
                CMD_SHIFT_DOWN: begin
                    next_state = STATE_READ_CMD;
                    next_op_y = (op_y == 7) ? 7 : (op_y + 1); 
                end
                CMD_SHIFT_LEFT: begin
                    next_state = STATE_READ_CMD;
                    next_op_x = (op_x == 1) ? 1 : (op_x - 1);
                end
                CMD_SHIFT_RIGHT: begin
                    next_state = STATE_READ_CMD;
                    next_op_x = (op_x == 7) ? 7 : (op_x + 1);
                end
                CMD_AVERAGE: begin
                    next_state = STATE_READ_CMD;
                    next_buffer[op_x][op_y] = average;
                    next_buffer[op_x-1][op_y] = average;
                    next_buffer[op_x][op_y-1] = average;
                    next_buffer[op_x-1][op_y-1] = average;
                end
                CMD_MIRROW_X: begin
                    next_state = STATE_READ_CMD;
                    next_buffer[op_x][op_y-1] = buffer[op_x][op_y];
                    next_buffer[op_x][op_y] = buffer[op_x][op_y-1];
                    next_buffer[op_x-1][op_y-1] = buffer[op_x-1][op_y];
                    next_buffer[op_x-1][op_y] = buffer[op_x-1][op_y-1];
                end
                CMD_MIRROW_Y: begin
                    next_state = STATE_READ_CMD;
                    next_buffer[op_x-1][op_y] = buffer[op_x][op_y];
                    next_buffer[op_x][op_y] = buffer[op_x-1][op_y];
                    next_buffer[op_x-1][op_y-1] = buffer[op_x][op_y-1];
                    next_buffer[op_x][op_y-1] = buffer[op_x-1][op_y-1];
                end
                CMD_DO_NOTHING: begin
                    next_state = STATE_READ_CMD;
                end
            endcase
        end
        STATE_DONE : begin
        end
    endcase
end

assign next_busy = (state == STATE_READ_CMD);

integer idx, idy;


always @ (posedge clk) begin
    for (idx = 0; idx < 8; idx = idx + 1)
        for (idy = 0; idy < 8; idy = idy + 1)
            buffer[idx][idy] <= next_buffer[idx][idy];
end

always @ (posedge clk or negedge reset) begin
    if (reset) begin
        state <= STATE_READ_IROM;
        reg_cmd <= CMD_INIT;
        op_x <= OP_X_INIT;
        op_y <= OP_Y_INIT;
        busy <= BUSY_INIT;
        done <= DONE_INIT;
    end
    else begin
        state <= next_state;
        reg_cmd <= next_reg_cmd;
        op_x <= next_op_x;
        op_y <= next_op_y;
        busy <= next_busy;
        done <= next_done;
    end
end

endmodule

module IRB_CTRL(clk, reset, en, IRB_A, IRB_RW, done, image_data, busy);

input clk;
input reset;
input en;
input [7:0] image_data;
output [5:0] IRB_A;
output IRB_RW;
output done;
output busy;

reg done;
reg [5:0] addr;
reg rw;
reg valid;
reg busy;

reg next_done;
reg [5:0] next_addr;
reg next_rw;
reg next_valid;
reg next_busy;

assign IRB_A = addr;
assign IRB_RW = rw;

parameter RW_ENABLE = 1'b0
        , RW_DISABLE = 1'b1;

parameter RW_INIT = RW_DISABLE
        , ADDR_INIT = 6'b0
        , DONE_INIT = 1'b0
        , VALID_INIT = 1'b0
        , BUSY_INIT = 1'b0;

always @ (*) begin
    next_done = done;
    next_addr = addr;
    next_rw = rw;
    next_valid = valid;
    next_busy = busy;
    if (!done) begin
        if (en) begin
            next_busy = 1'b1;
            if (!valid) begin
                next_addr = ADDR_INIT;
                next_rw = RW_ENABLE;
                next_valid = 1'b1;
            end
            else begin
                next_addr = addr + 1;
                if (addr == 63) begin
                    next_done = 1'b1;
                    next_rw = RW_DISABLE;
                    next_busy = 1'b0;
                end
            end
        end
    end
end

always @ (posedge clk) begin
    if (reset) begin
        done <= DONE_INIT;
        addr <= ADDR_INIT;
        rw <= RW_INIT;
        valid <= VALID_INIT;
        busy <= BUSY_INIT;
    end
    else begin
        done <= next_done;
        addr <= next_addr;
        rw <= next_rw;
        valid <= next_valid;
        busy <= next_busy;
    end
end

endmodule


module LCD_CTRL(clk, reset, IROM_Q, cmd, cmd_valid, IROM_EN, IROM_A, IRB_RW, IRB_D, IRB_A, busy, done);
input clk;
input reset;
input [7:0] IROM_Q;
input [2:0] cmd;
input cmd_valid;
output IROM_EN;
output [5:0] IROM_A;
output IRB_RW;
output [7:0] IRB_D;
output [5:0] IRB_A;
output busy;
output done;

wire irom_done;
wire irom_valid;
wire irom_busy; 
wire image_done;
wire image_busy;
wire irb_done;
wire irb_busy;

wire [7:0] image_data;

assign IRB_D = image_data;
assign busy = irom_busy || image_busy || irb_busy;

IROM_CTRL irom_ctrl(.clk(!clk), .reset(reset), .IROM_EN(IROM_EN), .IROM_A(IROM_A), .valid(irom_valid), .done(irom_done), .busy(irom_busy));

IMAGE image(.clk(!clk), .reset(reset), .IROM_Q(IROM_Q), .IROM_A(IROM_A), .irom_valid(irom_valid), .irom_done(irom_done), .cmd(cmd), .cmd_valid(cmd_valid), .done(image_done), .data(image_data), .IRB_A(IRB_A), .busy(image_busy));

IRB_CTRL irb_ctrl(.clk(!clk), .reset(reset), .en(image_done), .IRB_A(IRB_A), .IRB_RW(IRB_RW), .done(irb_done), .image_data(image_data), .busy(irb_busy));

assign done = irb_done;

endmodule

