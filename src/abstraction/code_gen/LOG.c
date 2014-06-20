#ifndef CTE_H
#define CTE_H

#include <systemc.h>


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
    const static     sc_uint<4> yuv_to_rgb_inst0.S_U;
    const static     sc_uint<4> yuv_to_rgb_inst0.S_Y1;
    const static     sc_uint<4> yuv_to_rgb_inst0.S_V;
    const static     sc_uint<4> yuv_to_rgb_inst0.S_BUSY1;
    const static     sc_uint<4> yuv_to_rgb_inst0.S_Y2;
    const static     sc_uint<4> yuv_to_rgb_inst0.S_BUSY2;

    // Registers
    sc_uint<4> yuv_to_rgb_inst0.state;
    sc_uint<8> yuv_to_rgb_inst0.reg_U;
    sc_uint<8> yuv_to_rgb_inst0.reg_Y1;
    sc_uint<8> yuv_to_rgb_inst0.reg_V;
    sc_uint<8> yuv_to_rgb_inst0.reg_Y2;

    // Wires
    bool yuv_to_rgb_busy;
    bool yuv_to_rgb_out_valid;
    sc_uint<8> yuv_to_rgb_inst0.reg_U_next;
    sc_uint<8> yuv_to_rgb_inst0.reg_Y1_next;
    sc_uint<8> yuv_to_rgb_inst0.reg_V_next;
    sc_uint<8> yuv_to_rgb_inst0.reg_Y2_next;
    sc_uint<16> yuv_to_rgb_inst0.R_ext;
    sc_uint<16> yuv_to_rgb_inst0.G_ext;
    sc_uint<16> yuv_to_rgb_inst0.B_ext;
    sc_uint<16> yuv_to_rgb_inst0.U_ext;
    sc_uint<16> yuv_to_rgb_inst0.Y_ext;
    sc_uint<16> yuv_to_rgb_inst0.V_ext;
    sc_uint<8> yuv_to_rgb_inst0.R_out;
    sc_uint<8> yuv_to_rgb_inst0.G_out;
    sc_uint<8> yuv_to_rgb_inst0.B_out;
    sc_uint<4> yuv_to_rgb_inst0.state_next;

    // Integer 
};

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


#include "CTE.h"


// Parameters
const static     sc_uint<4> yuv_to_rgb_inst0.S_U = sc_uint<4> (0);
const static     sc_uint<4> yuv_to_rgb_inst0.S_Y1 = sc_uint<4> (1);
const static     sc_uint<4> yuv_to_rgb_inst0.S_V = sc_uint<4> (2);
const static     sc_uint<4> yuv_to_rgb_inst0.S_BUSY1 = sc_uint<4> (3);
const static     sc_uint<4> yuv_to_rgb_inst0.S_Y2 = sc_uint<4> (4);
const static     sc_uint<4> yuv_to_rgb_inst0.S_BUSY2 = sc_uint<4> (5);

// Function calls
void func_number_0() {
yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
}

void func_number_1() {
yuv_to_rgb_inst0.reg_U = ((reset || (!in_en))?sc_uint<8>(0):yuv_to_rgb_inst0.reg_U_next);
}

void func_number_2() {
yuv_to_rgb_inst0.reg_V = ((reset || (!in_en))?sc_uint<8>(0):yuv_to_rgb_inst0.reg_V_next);
}

void func_number_3() {
yuv_to_rgb_inst0.reg_Y1 = ((reset || (!in_en))?sc_uint<8>(0):yuv_to_rgb_inst0.reg_Y1_next);
}

void func_number_4() {
yuv_to_rgb_inst0.reg_Y2 = ((reset || (!in_en))?sc_uint<8>(0):yuv_to_rgb_inst0.reg_Y2_next);
}

void func_number_5() {
yuv_to_rgb_inst0.state = ((reset || (!in_en))?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state_next);
}

void func_number_6() {
busy = ((!op_mode)?yuv_to_rgb_busy:sc_uint<1>(1));
}

void func_number_7() {
out_valid = ((!op_mode)?yuv_to_rgb_out_valid:sc_uint<1>(0));
}

void func_number_8() {
yuv_out = sc_uint<8>(0);
}

void func_number_9() {
yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void func_number_10() {
yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void func_number_11() {
yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
}

void func_number_12() {
yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
}

void func_number_13() {
yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
}

void func_number_14() {
yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
}

void func_number_15() {
yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)])), yuv_to_rgb_inst0.reg_U);
}

void func_number_16() {
yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(sc_uint<8>(0), yuv_to_rgb_inst0.reg_Y1):(sc_uint<8>(0), yuv_to_rgb_inst0.reg_Y2));
}

void func_number_17() {
yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)])), yuv_to_rgb_inst0.reg_V);
}

void func_number_18() {
yuv_to_rgb_inst0.R_ext = ((sc_uint<61>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<61>(13) * yuv_to_rgb_inst0.V_ext));
}

void func_number_19() {
yuv_to_rgb_inst0.G_ext = (((sc_uint<61>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<61>(65534) * yuv_to_rgb_inst0.U_ext)) + (sc_uint<61>(65530) * yuv_to_rgb_inst0.V_ext));
}

void func_number_20() {
yuv_to_rgb_inst0.B_ext = ((sc_uint<61>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<61>(16) * yuv_to_rgb_inst0.U_ext));
}

void func_number_21() {
yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[sc_uint<32>(15)]?sc_uint<8>(0):((yuv_to_rgb_inst0.R_extrange(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))?sc_uint<8>(255):(yuv_to_rgb_inst0.R_ext[sc_uint<32>(2)]?((yuv_to_rgb_inst0.R_extrange(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))?sc_uint<8>(255):(yuv_to_rgb_inst0.R_extrange(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1))):yuv_to_rgb_inst0.R_extrange(sc_uint<32>(10), sc_uint<32>(3)))));
}

void func_number_22() {
yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[sc_uint<32>(15)]?sc_uint<8>(0):((yuv_to_rgb_inst0.G_extrange(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))?sc_uint<8>(255):(yuv_to_rgb_inst0.G_ext[sc_uint<32>(2)]?((yuv_to_rgb_inst0.G_extrange(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))?sc_uint<8>(255):(yuv_to_rgb_inst0.G_extrange(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1))):yuv_to_rgb_inst0.G_extrange(sc_uint<32>(10), sc_uint<32>(3)))));
}

void func_number_23() {
yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[sc_uint<32>(15)]?sc_uint<8>(0):((yuv_to_rgb_inst0.B_extrange(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))?sc_uint<8>(255):(yuv_to_rgb_inst0.B_ext[sc_uint<32>(2)]?((yuv_to_rgb_inst0.B_extrange(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))?sc_uint<8>(255):(yuv_to_rgb_inst0.B_extrange(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1))):yuv_to_rgb_inst0.B_extrange(sc_uint<32>(10), sc_uint<32>(3)))));
}

void func_number_24() {
rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}


