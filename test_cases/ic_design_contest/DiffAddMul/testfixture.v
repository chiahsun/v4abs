`timescale 1ns/10ps
`define CYCLE 100           	 // clock period here
`define INPUT_PATTERN "./pattern1.dat"  // Pattern Input
`define GOLDEN_ANSWER "./golden1.dat"   // Golden Answer

module test;
parameter t_reset   = `CYCLE*2+(`CYCLE/2);
parameter t_finish  = `CYCLE*20;
parameter N_PATTERN = 192; //10 or 192

reg        clk;
reg        reset;
reg  [7:0] i;
reg  [7:0] j;
reg  [7:0] k;
reg        op;
wire [7:0] out_value;
wire       invalid;
wire       outvalid;

reg [24:0] N_mem [0:N_PATTERN-1];
reg [24:0] N_answer [0:N_PATTERN+1];
reg [24:0] N_cur;

integer    num, ans_num, error;

   top DIFFADDMULT(.clk(clk), .rst(reset),
                   .i(i), .j(j), .k(k), .operation(op), 
                   .vo(out_value), .in_valid(invalid), .out_valid(outvalid));

initial	$readmemb (`INPUT_PATTERN, N_mem);
initial	$readmemh (`GOLDEN_ANSWER, N_answer);

initial begin
   clk         = 1'b0;
   reset       = 1'b0;
   i           = 8'b0;
   j           = 8'b0;
   k           = 8'b0;
   op          = 1'b1;
   ans_num     = 0;
   error       = 0;
end

always begin #(`CYCLE/2) clk = ~clk; end

initial begin
   $dumpfile("DIFFADDMULT.vcd");
   $dumpvars;
end


initial begin
   #(`CYCLE/5)     reset = 1'b1;
   #t_reset        reset = 1'b0;
   
   @(negedge clk)    num = 0;
   for(num = 0; num < N_PATTERN; num = num + invalid) begin
       @(negedge clk) N_cur = N_mem[num];
       i  = N_cur[24:17];
       j  = N_cur[16: 9];
       k  = N_cur[ 8: 1];
       op = N_cur[0];
   end
   #t_finish       $display("\n\n Yes, Yes, Yes. All right!\n\n\n");
   $finish;
   
end

always @(posedge clk)begin
   if (outvalid) begin
       if (N_answer[ans_num] != out_value) begin
           $display("excpet: %h <-> get: %h.",N_answer[ans_num], out_value);
           error = error + 1;
           #(`CYCLE) $finish;
       end
       else begin
           ans_num = ans_num + 1;
       end
   end
end


endmodule
