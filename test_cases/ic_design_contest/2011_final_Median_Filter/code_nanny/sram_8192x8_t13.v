module sram_8192x8_t13 (
   Q,
   CLK,
   CEN,
   WEN,
   A,
   D
);
   
parameter		   BITS = 8;
parameter		   word_depth = 8192;
parameter		   addr_width = 13;
   
output [7:0] Q;
input CLK;
input CEN;
input WEN;
input [12:0] A;
input [7:0] D;
   
reg [BITS-1:0]	   mem [word_depth-1:0];
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
