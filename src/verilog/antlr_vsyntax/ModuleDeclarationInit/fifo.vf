`include "regfile.v"

module fifo(clock, reset, in_data, new_data, out_data_valid, out_data, full);

input clock, reset;
input [WIDTH-1 : 0] in_data;
input new_data;
input out_data_valid;

parameter WIDTH = 16;
parameter DEPTH = 16;
parameter ADDRESSWIDTH = 5;

integer k;

output [WIDTH-1 : 0] out_data;
output full;

reg full;
wire next_full;

reg [ADDRESSWIDTH-1 : 0] rear;
reg [ADDRESSWIDTH-1 : 0] front;

always @ (posedge clock) begin
    if (!reset) rear <= 0;
    else if (new_data) begin
        if (rear == DEPTH) rear <= 0;
        else rear <= rear + 1;
    end
end

always @ (posedge clock) begin
    if (!reset) front <= 0;
    else if (out_data_valid) begin
        if (front == DEPTH) front <= 0;
        else front <= front + 1;
    end
end

always @ (posedge clock) begin
    if (!reset) full <= 0;
    else full <= next_full;
end

assign next_full = (front == ((rear == DEPTH) ? 0 : (rear + 1)));

regfile u1 (clock, reset, new_data, rear, front, in_data, out_data);

endmodule
