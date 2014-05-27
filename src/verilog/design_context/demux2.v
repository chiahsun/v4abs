module decode2(in1, sel, out1);

input    [1:0]  in1;
input    [2:0]  sel;
output   [15:0] out1;

reg [7:0] select;

always @ (sel)
    case (sel)
        3'b000 : select = 8'b0000_0001;
        3'b001 : select = 8'b0000_0010;
        3'b010 : select = 8'b0000_0100;
        3'b011 : select = 8'b0000_1000;
        3'b100 : select = 8'b0001_0000;
        3'b101 : select = 8'b0010_0000;
        3'b110 : select = 8'b0100_0000;
        3'b111 : select = 8'b1000_0000;
    endcase

assign out1[1:0] = in1 & select[0];
assign out1[3:2] = in1 & select[1];
assign out1[5:4] = in1 & select[2];
assign out1[7:6] = in1 & select[3];
assign out1[8:8] = in1 & select[4];
assign out1[11:10] = in1 & select[5];
assign out1[13:12] = in1 & select[6];
assign out1[15:14] = in1 & select[7];


endmodule
