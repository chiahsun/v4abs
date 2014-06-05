`include "./sram_1024x8_t13.v"

module sram_ctrl(clk, reset, sram_in_ctrl, sram_in, sram_out);

input        clk;
input        reset;
input  [1:0] sram_in_ctrl;
input  [7:0] sram_in;
output [7:0] sram_out;



reg   [9:0] sram_write_addr;
wire   [9:0] sram_read_addr;
wire  [9:0] sram_addr;
wire  [7:0] tmp;

reg sram_en, sram_w_r;
reg [7:0] internal_counter;

reg    [7:0] sram_data_in;
reg    [7:0] sram_data_out;
reg sram_CEB;
always @ (posedge clk) begin
    sram_data_in  <= (reset) ? 0 : sram_in;
    sram_data_out <= (reset) ? 0 : tmp;
    sram_en       <= (reset) ? 0 : sram_in_ctrl[1];
    sram_w_r      <= (reset) ? 0 : sram_in_ctrl[0];
end

assign sram_addr = (sram_w_r) ? sram_write_addr : sram_read_addr;
assign sram_read_addr = sram_write_addr -128 + internal_counter;
reg [7:0] cnt;
wire [7:0] dbg_cnt;
assign dbg_cnt = cnt;
always @ (posedge clk) begin
    if(!sram_en) cnt <= 0;
    else cnt <= (cnt == 8'h82) ? 0 : cnt+1'b1;
end
always @ (posedge clk) begin
    if(!sram_en) internal_counter <= 0;
    else
         if(!sram_w_r) 
            internal_counter <= (cnt == 8'h82) 
                             ? 0
                             : internal_counter + 1'b1;
end
always @ (posedge clk) begin
    if(reset) begin
        sram_CEB <= 1'b1;
        sram_write_addr <= 0;
    end
    else begin 
        sram_CEB <= 1'b0;
        if(sram_en && sram_w_r) 
            sram_write_addr <= sram_write_addr + 1'b1 ;
    end
end


sram_1024x8_t13 my_ram(.A(sram_addr),
                   .D(sram_data_in),
                   .CLK(~clk),
                   .CEN(sram_CEB),
                   .WEN(~sram_w_r),
                   .Q(tmp) );
assign sram_out = tmp;

endmodule
