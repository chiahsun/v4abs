// Multiple Cycle MIPS: Design by R01943137 and R01943081
//=========================================================
// Input/Output Signals:
// positive-edge triggered         clk
// active low asynchronous reset   rst_n
// instruction memory interface    IR_addr, IR
// output for testing purposes     RF_writedata
//=========================================================
// Wire/Reg Specifications:
// control signals             MemToReg, MemRead, MemWrite, 
//                             RegDST, RegWrite, Branch, 
//                             Jump, ALUSrc, ALUOp
// ALU control signals         ALUctrl
// ALU input signals           ALUin1, ALUin2
// ALU output signals          ALUresult, ALUzero
// instruction specifications  r, addi, j, jal, jr, lw, sw, bne, sll, srl
// sign-extended signal        SignExtend
// MUX output signals          MUX_RegDST, MUX_Src
// registers input signals     Reg_W, WriteData 
// registers                   Register
// registers output signals    ReadData1, ReadData2
// data memory contral signals CEN, WEN
// data memory output signals  ReadDataMem
// program counter/address     PCin, PCnext, JumpAddr, BranchAddr
//=========================================================

//synopsys translate_off
`include "./sram_512x32_t13.v"
//synopsys translate_on

/*module sram_512x32_t13 ( Q, CLK, CEN, WEN, A, D );
   output [31:0] Q;
   input CLK, CEN, WEN;
   input [8:0] A;
   input [31:0] D;


endmodule
*/

module MultiCycle_MIPS( 
    clk,
    rst_n,
    IR_addr,
    IR,
    RF_writedata,
    exception
);

//==== in/out declaration =================================    
    input         clk, rst_n;
    input  [31:0] IR;
    output [31:0] IR_addr, RF_writedata;
    output [ 1:0] exception;

//==== reg/wire declaration ===============================
    wire        r, addi, j, jal, jr, lw, sw, bran, bran2, n1, n2, n3, n4, rnot, exe;
    wire        PCSrc, Flush, ForwardA, ForwardB;
    wire        Branch, Jump, Jumpjal, JumpR, Hazard;
    wire [ 4:0] ALUctrl, MUX_RegDST;
    wire [31:0] WriteData, RF_writedata;
    wire [ 1:0] ALUOp;
    wire        ALUSrc;

    wire        RegDST , RegWrite;
    wire        MemRead, MemWrite, MemToReg, CEN, WEN;
    wire [ 8:0] A;
    wire [31:0] ReadDataMem, PCin, PCnext;
    wire [31:0] ALUin1, ALUin2, ALUin3, ALUin2_neg;
    wire [31:0] SignExtend, BranchAddr, JumpAddr;

    reg  [ 4:0] Reg_W, MUX_RegDST_a;
    reg  [ 1:0] ALUOp_a, exception1;
    reg         ALUSrc_a, ALUzero, ALUzero_a, Branch_a, Branch_b, rnot_a;
    reg         Jump_a, Jump_b, JumpR_a, JumpR_b, Jumpjal_a;
    reg         MemRead_a, MemRead_b, MemWrite_a, MemWrite_b;
    reg         MemToReg_a, MemToReg_b, MemToReg_c;
    reg         RegWrite_a, RegWrite_b, RegWrite_c, RegDST_a;
    reg  [31:0] IR_a, IR_b, PCnext_a, PCnext_b, ReadDataMem_a;
    reg  [31:0] ALUresult, ALUresult_a, ALUresult_b;
    reg  [31:0] ReadData1, ReadData1_a, ReadData1_b, ReadData2, ReadData2_a, ReadData2_b;
    reg  [31:0] SignExtend_a, JumpAddr_a, JumpAddr_b, BranchAddr_a, IR_addr1, Register[31: 0];

assign IR_addr[31:2] = IR_addr1[31:2];
assign IR_addr[ 1:0] = 2'b0;
assign exception     = exception1;

//==== SRAM ===============================================
    sram_512x32_t13 sram( .Q( ReadDataMem ),
                          .CLK( ~clk ),
                          .CEN( CEN ),
                          .WEN( WEN ),
                          .A  ( A ),
                          .D  ( ReadData2_b) );

//==== combinational part =================================
    assign r        = ( IR_a[31:26] == 6'b000000 )? 1'b1: 1'b0;
    assign j        = ( IR_a[31:27] == 5'b00001  )? 1'b1: 1'b0;
    assign jal      = ( IR_a[31:26] == 6'b000011 )? 1'b1: 1'b0;
    assign jr       = ( IR_a[ 5: 0] == 6'b001000 )? 1'b1: 1'b0;
    assign bran     = ( IR_a[31:28] == 4'b0001   )? 1'b1: 1'b0; // beq, bne, blez, bgtz
    assign bran2    = ( IR_a[31:26] == 6'b000001 )? 1'b1: 1'b0; // bltz, bgez;
    assign addi     = ( IR_a[31:29] == 3'b001    )? 1'b1: 1'b0; // addi,addiu,slti,sltiu,andi,ori,xori,lui 
    assign lw       = ( IR_a[31:26] == 6'b100011 )? 1'b1: 1'b0;
    assign sw       = ( IR_a[31:26] == 6'b101011 )? 1'b1: 1'b0;
    assign n3       = ( IR_a[ 5: 2] == 4'b0100   )? 1'b1: 1'b0;
    assign n4       = ( IR_a[ 5: 2] == 4'b0110   )? 1'b1: 1'b0;
    assign n1       = ( IR_a[30]    == 1'b1      )? 1'b1: 1'b0;
    assign n2       = ( IR_a[31:30] == 2'b10     )? 1'b1: 1'b0;
    assign rnot     = ( r & ( n3|n4 )) | n1 | ( n2 & ~( lw|sw ));
   
 //=========== IF =========================================
    //-------- program counter ----------------------------
    assign PCnext[31:2] = IR_addr1[31:2] + 30'd1;
    assign PCnext[ 1:0] = 2'd0;
 //=========== ID =========================================
    //-------- control signals ----------------------------
    assign MemToReg     = lw;
    assign MemRead      = lw;
    assign MemWrite     = sw;
    assign RegDST       = ( r & ~rnot ) | jal;
    assign RegWrite     = ( r & ~jr )   | lw | addi | jal;
    assign Branch       = bran | bran2;
    assign Jump         = j    | jal;
    assign Jumpjal      = jal;
    assign JumpR        = r    & jr;
    assign ALUSrc       = sw   | lw    | addi;
    assign ALUOp[0]     = bran | bran2 | addi;
    assign ALUOp[1]     = ( r &~rnot ) | addi;
    assign WriteData    = ( ~RegWrite_c )? 1'b0 :
                          ( Reg_W==5'd0 )? 1'b0 :
                          ( MemToReg_c==1'b1 )? ReadDataMem_a : ALUresult_b;
    assign RF_writedata = WriteData;
    assign Hazard       = ( MemRead_a && ( IR_b[20:16]==IR_a[25:21] || 
                                           IR_b[20:16]==IR_a[20:16] ))? 1'b1 : 1'b0;
    assign exe          = ( exception1==2'b0 )? 1'b0 : 1'b1;
    //-------- input signals of registers -----------------
    always@( * ) begin
        if( !rst_n ) begin
            ReadData1  = 32'd0;
            ReadData2  = 32'd0;
        end begin
            case( IR_a[25:21] ) //synopsys parallel_case
                5'd0:  ReadData1 = 32'd0;
                5'd1:  ReadData1 = ( Reg_W==5'd1  )? WriteData : Register[1];
                5'd2:  ReadData1 = ( Reg_W==5'd2  )? WriteData : Register[2];
                5'd3:  ReadData1 = ( Reg_W==5'd3  )? WriteData : Register[3];
                5'd4:  ReadData1 = ( Reg_W==5'd4  )? WriteData : Register[4];
                5'd5:  ReadData1 = ( Reg_W==5'd5  )? WriteData : Register[5];
                5'd6:  ReadData1 = ( Reg_W==5'd6  )? WriteData : Register[6];
                5'd7:  ReadData1 = ( Reg_W==5'd7  )? WriteData : Register[7];
                5'd8:  ReadData1 = ( Reg_W==5'd8  )? WriteData : Register[8];
                5'd9:  ReadData1 = ( Reg_W==5'd9  )? WriteData : Register[9];
                5'd10: ReadData1 = ( Reg_W==5'd10 )? WriteData : Register[10];
                5'd11: ReadData1 = ( Reg_W==5'd11 )? WriteData : Register[11];
                5'd12: ReadData1 = ( Reg_W==5'd12 )? WriteData : Register[12];
                5'd13: ReadData1 = ( Reg_W==5'd13 )? WriteData : Register[13];
                5'd14: ReadData1 = ( Reg_W==5'd14 )? WriteData : Register[14];
                5'd15: ReadData1 = ( Reg_W==5'd15 )? WriteData : Register[15];
                5'd16: ReadData1 = ( Reg_W==5'd16 )? WriteData : Register[16];
                5'd17: ReadData1 = ( Reg_W==5'd17 )? WriteData : Register[17];
                5'd18: ReadData1 = ( Reg_W==5'd18 )? WriteData : Register[18];
                5'd19: ReadData1 = ( Reg_W==5'd19 )? WriteData : Register[19];
                5'd20: ReadData1 = ( Reg_W==5'd20 )? WriteData : Register[20];
                5'd21: ReadData1 = ( Reg_W==5'd21 )? WriteData : Register[21];
                5'd22: ReadData1 = ( Reg_W==5'd22 )? WriteData : Register[22];
                5'd23: ReadData1 = ( Reg_W==5'd23 )? WriteData : Register[23];
                5'd24: ReadData1 = ( Reg_W==5'd24 )? WriteData : Register[24];
                5'd25: ReadData1 = ( Reg_W==5'd25 )? WriteData : Register[25];
                5'd26: ReadData1 = ( Reg_W==5'd26 )? WriteData : Register[26];
                5'd27: ReadData1 = ( Reg_W==5'd27 )? WriteData : Register[27];
                5'd28: ReadData1 = ( Reg_W==5'd28 )? WriteData : Register[28];
                5'd29: ReadData1 = ( Reg_W==5'd29 )? WriteData : Register[29];
                5'd30: ReadData1 = ( Reg_W==5'd30 )? WriteData : Register[30];
                5'd31: ReadData1 = ( Reg_W==5'd31 )? WriteData : Register[31];
            endcase
            case( IR_a[20:16] ) //synopsys parallel_case
                5'd0:  ReadData2 = 32'd0;
                5'd1:  ReadData2 = ( Reg_W==5'd1  )? WriteData : Register[1];
                5'd2:  ReadData2 = ( Reg_W==5'd2  )? WriteData : Register[2];
                5'd3:  ReadData2 = ( Reg_W==5'd3  )? WriteData : Register[3];
                5'd4:  ReadData2 = ( Reg_W==5'd4  )? WriteData : Register[4];
                5'd5:  ReadData2 = ( Reg_W==5'd5  )? WriteData : Register[5];
                5'd6:  ReadData2 = ( Reg_W==5'd6  )? WriteData : Register[6];
                5'd7:  ReadData2 = ( Reg_W==5'd7  )? WriteData : Register[7];
                5'd8:  ReadData2 = ( Reg_W==5'd8  )? WriteData : Register[8];
                5'd9:  ReadData2 = ( Reg_W==5'd9  )? WriteData : Register[9];
                5'd10: ReadData2 = ( Reg_W==5'd10 )? WriteData : Register[10];
                5'd11: ReadData2 = ( Reg_W==5'd11 )? WriteData : Register[11];
                5'd12: ReadData2 = ( Reg_W==5'd12 )? WriteData : Register[12];
                5'd13: ReadData2 = ( Reg_W==5'd13 )? WriteData : Register[13];
                5'd14: ReadData2 = ( Reg_W==5'd14 )? WriteData : Register[14];
                5'd15: ReadData2 = ( Reg_W==5'd15 )? WriteData : Register[15];
                5'd16: ReadData2 = ( Reg_W==5'd16 )? WriteData : Register[16];
                5'd17: ReadData2 = ( Reg_W==5'd17 )? WriteData : Register[17];
                5'd18: ReadData2 = ( Reg_W==5'd18 )? WriteData : Register[18];
                5'd19: ReadData2 = ( Reg_W==5'd19 )? WriteData : Register[19];
                5'd20: ReadData2 = ( Reg_W==5'd20 )? WriteData : Register[20];
                5'd21: ReadData2 = ( Reg_W==5'd21 )? WriteData : Register[21];
                5'd22: ReadData2 = ( Reg_W==5'd22 )? WriteData : Register[22];
                5'd23: ReadData2 = ( Reg_W==5'd23 )? WriteData : Register[23];
                5'd24: ReadData2 = ( Reg_W==5'd24 )? WriteData : Register[24];
                5'd25: ReadData2 = ( Reg_W==5'd25 )? WriteData : Register[25];
                5'd26: ReadData2 = ( Reg_W==5'd26 )? WriteData : Register[26];
                5'd27: ReadData2 = ( Reg_W==5'd27 )? WriteData : Register[27];
                5'd28: ReadData2 = ( Reg_W==5'd28 )? WriteData : Register[28];
                5'd29: ReadData2 = ( Reg_W==5'd29 )? WriteData : Register[29];
                5'd30: ReadData2 = ( Reg_W==5'd30 )? WriteData : Register[30];
                5'd31: ReadData2 = ( Reg_W==5'd31 )? WriteData : Register[31];
            endcase
        end
    end
    //-------- jump and branch ----------------------------
    assign BranchAddr[31:2]  = PCnext_b[31:2] + SignExtend_a[29:0];
    assign BranchAddr[ 1:0]  = 2'd0;
    assign SignExtend[31:16] = ( addi && (IR_a[28] || IR_a[26]) )? 16'b0 : { 16{IR_a[15]} };
    assign SignExtend[15:0]  = IR_a[15:0];

 //=========== EX =========================================
    //-------- input signals of ALU -----------------------
    assign MUX_RegDST   = ( Jumpjal_a )?      5'd31 :
                          ( RegDST_a  )? IR_b[15:11]: IR_b[20:16];
    assign ForwardA     = ( RegWrite_b && MUX_RegDST_a!=5'd0        )? 1'b1 : 1'b0;
    assign ForwardB     = ( RegWrite_c && Reg_W       !=5'd0        )? 1'b1 : 1'b0;
    assign ALUin1       = ( ForwardA   && MUX_RegDST_a==IR_b[25:21] )? ALUresult_a :
                          ( ForwardB   && Reg_W       ==IR_b[25:21] )? WriteData   : ReadData1_a;
    assign ALUin3       = ( ForwardA   && MUX_RegDST_a==IR_b[20:16] )? ALUresult_a :
                          ( ForwardB   && Reg_W       ==IR_b[20:16] )? WriteData   : ReadData2_a;
    assign ALUin2       = ( ALUSrc_a )? SignExtend_a: ALUin3;

    //-------- control signals of ALU ---------------------
    assign ALUctrl[0]   = ( ALUOp_a[0]     )? IR_b[26]        :
                          ( ALUOp_a[1]     )? SignExtend_a[0] : 1'b1;
    assign ALUctrl[1]   = ( ALUOp_a[0]     )? IR_b[27]        :
                          ( ALUOp_a[1]     )? SignExtend_a[1] : 1'b0;
    assign ALUctrl[2]   = ( ALUOp_a[0]     )? IR_b[28]        :
                          ( ALUOp_a[1]     )? SignExtend_a[2] : 1'b0;
    assign ALUctrl[3]   = ( ALUOp_a==2'b11 && IR_b[28:27]==2'b01 )? 1'b1:
                          ( ALUOp_a==2'b10 )? SignExtend_a[3] :
                          ( ALUOp_a==2'b01 )? 1'b1            : 1'b0;
    assign ALUctrl[4]   = ( ALUOp_a==2'b10 )? SignExtend_a[5] :
                          ( RegDST_a       )? 1'b0            : 1'b1;
   //-------- ALU ----------------------------------------
    assign ALUin2_neg   = ~ALUin2+1'b1;
    always@( ALUin1 or ALUin2 or ALUctrl or IR_b or ALUin2_neg ) begin
        case( ALUctrl )
            5'b00000: ALUresult = ALUin2 << IR_b[10:6];       //sll unsigned
            5'b00010: ALUresult = ALUin2 >> IR_b[10:6];       //srl unsigned
            5'b00011: begin                                   //sra signed
                          if( ALUin2[31]==1'b1 )  ALUresult = ~(ALUin2_neg >> IR_b[10:6])+1'b1;
                          else                    ALUresult = ALUin2 >> IR_b[10:6];
                      end
            5'b00100: begin                                   //sllv unsigned
                          if(ALUin1[31:5]!=27'd0) ALUresult = 32'd0;
                          else                    ALUresult = ALUin2 << ALUin1[4:0];
                      end
            5'b00110: begin                                   //srlv unsigned
                          if(ALUin1[31:5]!=27'd0) ALUresult = 32'd0;
                          else                    ALUresult = ALUin2 >> ALUin1[4:0];
                      end
            5'b00111: begin                                   //srav signed
                          if( ALUin2[31]==1'b1 )  ALUresult = ~(ALUin2_neg >> ALUin1)+1'b1;
                          else                    ALUresult = ALUin2 >> ALUin1;
                      end
            5'b01000: ALUresult = ALUin1;                     //jr
            5'b10000,                                         //add
            5'b10001: ALUresult = ALUin1 + ALUin2;            //add unsigned
            5'b10010,                                         //sub
            5'b10011: ALUresult = ALUin1 - ALUin2;            //sub unsigned
            5'b10100: ALUresult = ALUin1 & ALUin2;            //and
            5'b10101: ALUresult = ALUin1 | ALUin2;            //or
            5'b10110: ALUresult = ALUin1 ^ ALUin2;            //xor
            5'b10111: begin
                          if( addi ) ALUresult = {ALUin2[15:0],16'b0};//lui
                          else ALUresult = ~ALUin1 & ~ALUin2; //nor
                      end
            5'b11010: begin                                   //slt
                          if(ALUin1[31]^ALUin2[31]==1'b1) ALUresult = {31'b0 , ~ALUin2[31]};
                          else ALUresult = ( ALUin2 > ALUin1 )? 32'd1 : 32'd0;
                      end
            5'b11011: ALUresult = ( ALUin2 > ALUin1 )?  32'd1 : 32'd0; //slt unsigned
            default : begin
                          if( Jumpjal_a ) begin
                               ALUresult[31:2] = PCnext_b[31:2];
                               ALUresult[ 1:0] = 2'b0;
                          end
                          else ALUresult = 32'd0;
                      end
        endcase
        case( ALUctrl )
            5'b11001: ALUzero = (ALUin1[31]^IR_b[16]==1'b1)? 1'b1: //bgez, blez
                                ( ALUin1==32'd0  )? 1'b1 : 1'b0;
            5'b11100: ALUzero = ( ALUin1==ALUin2 )? 1'b1 : 1'b0;   //beq
            5'b11101: ALUzero = ( ALUin1!=ALUin2 )? 1'b1 : 1'b0;   //bne
            5'b11110: ALUzero = (ALUin1[31]==1'b1)? 1'b1 : 
                                ( ALUin1==32'd0  )? 1'b1 : 1'd0;   //blez
            5'b11111: ALUzero = (ALUin1[31]==1'b1)? 1'b0 :         //bgtz
                                ( ALUin1==32'd0  )? 1'b0 : 1'd1;
            default : ALUzero = 1'b0;
        endcase
        case( ALUctrl )
            5'b10000: begin                                        //add
                          if(ALUin1[31]^ALUin2[31]==1'b0 &&
                             ALUin2[31]^ALUresult[31]==1'b1) exception1 = 2'd2;
                          else exception1 = 2'd0;
                      end
            5'b10010: begin                                        //sub
                          if(ALUin1[31]^ALUresult[31]==1'b1 &&
                             ALUin1[31]^ALUin2[31]   ==1'b1) exception1 = 2'd2;
                          else exception1 = 2'd0;
                      end
            5'b10001: begin
                          if( rnot_a==1'b1 ) exception1 = 2'd1;    //rnot: unsupported fun
                          else exception1 = 2'd0;
                      end
            default : exception1 = 2'd0;
        endcase
    end

//=========== MEM ========================================
    assign A               = ALUresult_a[10:2];
    assign PCSrc           = ( Branch_b==1'b1 && ALUzero_a==1'b1 )? 1'b1 : 1'b0;
    assign Flush           = PCSrc | JumpR_b | Jump_b | exe;
    assign JumpAddr[1:0]   = 2'b00;
    assign JumpAddr[27:2]  = IR_a[25:0];
    assign JumpAddr[31:28] = PCnext_a[31:28];
    assign PCin[31:2]      = ( JumpR_b )? ReadData1_b[31:2]  :
                             ( Jump_b  )? JumpAddr_b[31:2]   :
                             ( PCSrc   )? BranchAddr_a[31:2] :
                             ( Hazard  )? IR_addr1[31:2]     : IR_addr1[31:2] + 30'd1;
    assign PCin[ 1:0]      = 2'd0;

    //-------- data memory --------------------------------
    assign CEN             = ~( MemWrite_b | MemRead_b );
    assign WEN             = MemRead_b;

//==== sequential part ====================================
    //-------- program counter ---------------------------- 
    always@( posedge clk or negedge rst_n ) begin
        if( !rst_n ) begin
            IR_addr1     <= 32'd0;  ReadDataMem_a<= 32'd0;
            ALUOp_a      <=  2'd0;  ALUSrc_a     <=  1'b0;  ALUzero_a    <=  1'b0;
            Branch_a     <=  1'b0;  Branch_b     <=  1'b0;  rnot_a       <=  1'b0;
            Jump_a       <=  1'b0;  Jump_b       <=  1'b0;
            JumpR_a      <=  1'b0;  JumpR_b      <=  1'b0;  Jumpjal_a    <=  1'b0;
            MemRead_a    <=  1'b0;  MemRead_b    <=  1'b0;
            MemWrite_a   <=  1'b0;  MemWrite_b   <=  1'b0;
            MemToReg_a   <=  1'b0;  MemToReg_b   <=  1'b0;  MemToReg_c   <=  1'b0;
            RegWrite_a   <=  1'b0;  RegWrite_b   <=  1'b0;  RegWrite_c   <=  1'b0;
            RegDST_a     <=  1'b0;  MUX_RegDST_a <=  5'd0;  Reg_W        <=  5'd0;
            IR_a         <= 32'd0;  IR_b         <= 32'd0;
            PCnext_a     <= 32'd0;  PCnext_b     <= 32'd0; 
            ALUresult_a  <= 32'd0;  ALUresult_b  <= 32'd0;
            ReadData1_a  <= 32'd0;  ReadData1_b  <= 32'd0;  SignExtend_a <= 32'd0;
            ReadData2_a  <= 32'd0;  ReadData2_b  <= 32'd0;
            JumpAddr_a   <= 32'd0;  JumpAddr_b   <= 32'd0;  BranchAddr_a <= 32'd0;
        end
        else begin
            /*============ IF/ID ============*/
            IR_addr1[31:2]<= PCin[31:2];
            IR_addr1[ 1:0]<= 2'b0;
            IR_a          <= ( Hazard )? IR_a     : 
                             ( Flush  )? 1'b0     : IR;
            PCnext_a      <= ( Hazard )? PCnext-32'd8 : 
                             ( Flush  )? 32'b0        : PCnext;

            /*============ ID/EX ============*/
            IR_b          <= ( Hazard || Flush )? 32'd0 : IR_a;
            PCnext_b[31:2]<= ( Hazard || Flush )? 30'd0 : PCnext_a[31:2];
            PCnext_b[ 1:0]<= 2'b0;
            ALUSrc_a      <= ( Hazard || Flush )? 1'b0 : ALUSrc;
            ALUOp_a[0]    <= ( Hazard || Flush )? 1'b0 : ALUOp[0];
            ALUOp_a[1]    <= ( Hazard || Flush )? 1'b0 : ALUOp[1];
            RegDST_a      <= ( Hazard || Flush )? 1'b0 : RegDST;
            Branch_a      <= ( Hazard || Flush )? 1'b0 : Branch;
            MemRead_a     <= ( Hazard || Flush )? 1'b0 : MemRead;
            MemWrite_a    <= ( Hazard || Flush )? 1'b0 : MemWrite;
            MemToReg_a    <= ( Hazard || Flush )? 1'b0 : MemToReg;
            RegWrite_a    <= ( Hazard || Flush )? 1'b0 : RegWrite;
            Jump_a        <= ( Hazard || Flush )? 1'b0 : Jump;
            JumpR_a       <= ( Hazard || Flush )? 1'b0 : JumpR;
            Jumpjal_a     <= ( Hazard || Flush )? 1'b0 : Jumpjal;
            JumpAddr_a[31:2] <= (Hazard||Flush )? 1'b0 : JumpAddr[31:2];
            JumpAddr_a[ 1:0] <= 2'b0;
            ReadData1_a   <= ( Hazard || Flush )? 1'b0 : ReadData1;
            ReadData2_a   <= ( Hazard || Flush )? 1'b0 : ReadData2;
            SignExtend_a  <= ( Hazard || Flush )? 1'b0 : SignExtend;
            rnot_a        <= ( Hazard || Flush )? 1'b0 : rnot;

            /*============ EX/MEM ===========*/
            Branch_b          <= ( Flush )? 1'b0 : Branch_a;
            MemRead_b         <= ( Flush )? 1'b0 : MemRead_a;
            MemWrite_b        <= ( Flush )? 1'b0 : MemWrite_a;
            MemToReg_b        <= ( Flush )? 1'b0 : MemToReg_a;
            RegWrite_b        <= ( Flush )? 1'b0 : RegWrite_a;
            Jump_b            <= ( Flush )? 1'b0 : Jump_a;
            JumpR_b           <= ( Flush )? 1'b0 : JumpR_a;
            JumpAddr_b[31:2]  <= ( Flush )? 1'b0 : JumpAddr_a[31:2];
            JumpAddr_b[ 1:0]  <= 2'd0;
            ReadData1_b[31:2] <= ( Flush )? 1'b0 : ALUin1[31:2];
            ReadData1_b[ 1:0] <= 2'd0;
            ReadData2_b       <= ( Flush )? 1'b0 : ALUin3;

            ALUzero_a         <= ( Flush )? 1'b0 : ALUzero;
            ALUresult_a       <= ( Flush )? 1'b0 : ALUresult;
            BranchAddr_a[31:2]<= ( Flush )? 1'b0 : BranchAddr[31:2];
            BranchAddr_a[ 1:0]<= 2'd0;
            MUX_RegDST_a      <= ( Flush )? 1'b0 : MUX_RegDST;

            /*============ MEM/WB ===========*/
            MemToReg_c    <= MemToReg_b;
            RegWrite_c    <= RegWrite_b;

            ALUresult_b   <= ALUresult_a;
            Reg_W         <= MUX_RegDST_a;
            ReadDataMem_a <= ReadDataMem;
        end
    end
    //-------- registers ----------------------------------
    always@( posedge clk or negedge rst_n ) begin
        if( !rst_n ) begin
            Register[0]  <= 32'd0;
            Register[1]  <= 32'd0;
            Register[2]  <= 32'd0;
            Register[3]  <= 32'd0;
            Register[4]  <= 32'd0;
            Register[5]  <= 32'd0;
            Register[6]  <= 32'd0;
            Register[7]  <= 32'd0;
            Register[8]  <= 32'd0;
            Register[9]  <= 32'd0;
            Register[10] <= 32'd0;
            Register[11] <= 32'd0;
            Register[12] <= 32'd0;
            Register[13] <= 32'd0;
            Register[14] <= 32'd0;
            Register[15] <= 32'd0;
            Register[16] <= 32'd0;
            Register[17] <= 32'd0;
            Register[18] <= 32'd0;
            Register[19] <= 32'd0;
            Register[20] <= 32'd0;
            Register[21] <= 32'd0;
            Register[22] <= 32'd0;
            Register[23] <= 32'd0;
            Register[24] <= 32'd0;
            Register[25] <= 32'd0;
            Register[26] <= 32'd0;
            Register[27] <= 32'd0;
            Register[28] <= 32'd0;
            Register[29] <= 32'd0;
            Register[30] <= 32'd0;
            Register[31] <= 32'd0;
        end
        else begin
            Register[Reg_W] <= ( RegWrite_c )? WriteData: Register[Reg_W];
        end
    end
//=========================================================

endmodule
