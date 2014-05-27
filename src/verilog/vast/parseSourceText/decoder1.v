module decode1 (op, funct, sel, B);

input    [1:0]   op;
input    [4:0]   funct;
output   [1:0]   sel;
output           B;

always @ (op or funct)
    casex ({op, funct})
        {2'b01, 5'bx} : begin
            sel = 2'b11;
            B = 1'b1;
        end
        {2'b11, 5'b00011} : begin
            sel = 2'b01;
            B = 1'b1;
        end
        {2'b11, 5'b00001} : begin
            sel = 2'b10;
            B = 1'b1;
        end
        default : begin
            sel = 2'bxx;
            B = 1'bx;
        end
    endcase

endmodule
