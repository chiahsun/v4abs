module regfile(clock, reset, write_enable, dest, source, data_in, data_out);

parameter WIDTH = 16;
parameter DEPTH = 3;
parameter ADDRESSWIDTH = 5;

integer i, k;

input clock, reset, write_enable;
input    [ADDRESSWIDTH-1 : 0]   dest;
input    [ADDRESSWIDTH-1 : 0]   source;
input    [WIDTH-1 : 0]          data_in;
output   [WIDTH-1 : 0]          data_out;

reg [WIDTH-1 : 0] data_out;
reg [WIDTH-1 : 0] rf [DEPTH-1 : 0];
wire [DEPTH-1 : 0] write_enable_decoded;

assign write_enable_decoded = (write_enable << dest);

always @ (posedge clock) begin
    if (!reset) data_out <= 0;
    else        data_out <= rf[source];
end

always @ (posedge clock) begin
    if (!reset) begin
        for (i = 0; i < DEPTH; i=i+1)
            rf[i] <= 0;
    end
    else begin
        for (k = 0; k < DEPTH; k = k+1)
            if (write_enable_decoded[k]) rf[k] <= data_in;
    end
end



endmodule
