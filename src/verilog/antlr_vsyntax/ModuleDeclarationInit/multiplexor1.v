module multiplexor1(in1, in2, out1);

input [7:0] in1;
input [2:0] in2;

output      out1;


always @ (in1 or in2)
    case (in2)
        3'b000 : out1 = in1[0];
        3'b001 : out1 = in1[1];
        3'b010 : out1 = in1[2];
        3'b011 : out1 = in1[3];
        3'b100 : out1 = in1[4];
        3'b101 : out1 = in1[5];
        3'b110 : out1 = in1[6];
        3'b111 : out1 = in1[7];
    endcase

endmodule
