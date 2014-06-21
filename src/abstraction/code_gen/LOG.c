.:../../../src/verilog/antlr_vsyntax/SourceTextInit:../../../ext_libs/antlr-4.0-complete.jar:
../../../src/verilog/vast/parseSourceText/javaParseSourceText.sh CTE.v &> CTE.v.ast
.:../../../src/protocol/antlr_psyntax/SourceTextInit:../../../ext_libs/antlr-4.0-complete.jar:
../../../src/protocol/past/parseSourceText/javaParseSourceText.sh CTE.c &> CTE.c.ast
./generateCode.out CTE.v.ast CTE.c.ast CTE
#ifndef CTE_H
#define CTE_H

#include <systemc.h>


struct YUV_TO_RGB {

    // Inputs 
    bool clk;
    bool reset;
    bool in_en;
    sc_uint<8> yuv_in;

    // Outputs 
    bool busy;
    bool out_valid;
    sc_uint<24> rgb_out;

    // Inouts 

    // Parameters
    const static sc_uint<4> S_U = 0;
    const static sc_uint<4> S_Y1 = 1;
    const static sc_uint<4> S_V = 2;
    const static sc_uint<4> S_BUSY1 = 3;
    const static sc_uint<4> S_Y2 = 4;
    const static sc_uint<4> S_BUSY2 = 5;

    // Registers
    sc_uint<4> state;
    sc_uint<4> state_next;
    sc_uint<8> reg_U;
    sc_uint<8> reg_Y1;
    sc_uint<8> reg_V;
    sc_uint<8> reg_Y2;

    // Wires
    sc_uint<8> reg_U_next;
    sc_uint<8> reg_Y1_next;
    sc_uint<8> reg_V_next;
    sc_uint<8> reg_Y2_next;
    sc_uint<16> R_ext;
    sc_uint<16> G_ext;
    sc_uint<16> B_ext;
    sc_uint<16> U_ext;
    sc_uint<16> Y_ext;
    sc_uint<16> V_ext;
    sc_uint<8> R_out;
    sc_uint<8> G_out;
    sc_uint<8> B_out;

    // Module instances

    // Function calls
};

struct CTE {

    // Inputs 
    bool clk;
    bool reset;
    bool op_mode;
    bool in_en;
    sc_uint<8> yuv_in;
    sc_uint<24> rgb_in;

    // Outputs 
    bool busy;
    bool out_valid;
    sc_uint<24> rgb_out;
    sc_uint<8> yuv_out;

    // Inouts 

    // Parameters

    // Registers

    // Wires
    bool yuv_to_rgb_in_en;
    bool yuv_to_rgb_busy;
    bool yuv_to_rgb_out_valid;

    // Module instances
    YUV_TO_RGB yuv_to_rgb_inst0;

    // Function calls
    void func_number_0();
    void func_number_1();
    void func_number_2();
    void func_number_3();
    void func_number_4();
    void func_number_5();
    void func_number_6();
    void func_number_7();
    void func_number_8();
    void func_number_9();
    void func_number_10();
    void func_number_11();
    void func_number_12();
    void func_number_13();
    void func_number_14();
    void func_number_15();
    void func_number_16();
    void func_number_17();
    void func_number_18();
    void func_number_19();
    void func_number_20();
    void func_number_21();
    void func_number_22();
    void func_number_23();
    void func_number_24();
};

#endif // CTE_H



#include "CTE.h"


// Function calls
void CTE::func_number_0() {
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
}

void CTE::func_number_1() {
    yuv_to_rgb_inst0.reg_U = ((reset || (!in_en))?0:yuv_to_rgb_inst0.reg_U_next);
}

void CTE::func_number_2() {
    yuv_to_rgb_inst0.reg_V = ((reset || (!in_en))?0:yuv_to_rgb_inst0.reg_V_next);
}

void CTE::func_number_3() {
    yuv_to_rgb_inst0.reg_Y1 = ((reset || (!in_en))?0:yuv_to_rgb_inst0.reg_Y1_next);
}

void CTE::func_number_4() {
    yuv_to_rgb_inst0.reg_Y2 = ((reset || (!in_en))?0:yuv_to_rgb_inst0.reg_Y2_next);
}

void CTE::func_number_5() {
    yuv_to_rgb_inst0.state = ((reset || (!in_en))?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state_next);
}

void CTE::func_number_6() {
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
}

void CTE::func_number_7() {
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
}

void CTE::func_number_8() {
    yuv_out = 0;
}

void CTE::func_number_9() {
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_10() {
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_11() {
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
}

void CTE::func_number_12() {
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
}

void CTE::func_number_13() {
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
}

void CTE::func_number_14() {
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
}

void CTE::func_number_15() {
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
}

void CTE::func_number_16() {
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
}

void CTE::func_number_17() {
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
}

void CTE::func_number_18() {
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_19() {
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_20() {
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
}

void CTE::func_number_21() {
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
}

void CTE::func_number_22() {
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
}

void CTE::func_number_23() {
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
}

void CTE::func_number_24() {
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}


