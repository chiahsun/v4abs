module encoder1 (value, gray_code);

input  [7:0] value;
output [3:0] gray_code;

always @ (value)
    case (value)
        8'b0000_0001 : gray_code = 3'b000;
        8'b0000_0010 : gray_code = 3'b001;
        8'b0000_0100 : gray_code = 3'b011;
        8'b0000_1000 : gray_code = 3'b010;
        8'b0001_0000 : gray_code = 3'b110;
        8'b0010_0000 : gray_code = 3'b111;
        8'b0100_0000 : gray_code = 3'b101;
        8'b1000_0000 : gray_code = 3'b100;
    endcase

endmodule
