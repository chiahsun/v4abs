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

enum ProtocolState {
    ProtocolState_s0 // s0
  , ProtocolState_s1 // s1
  , ProtocolState_s2 // s2
  , ProtocolState_s3 // s3
  , ProtocolState_s4 // assert(0)
  , ProtocolState_s5 // s4
  , ProtocolState_s6 // s5
  , ProtocolState_s7 // s7
  , ProtocolState_s8 // s8
  , ProtocolState_s9 // s10
};

enum ProtocolEvent {
    ProtocolEvent5 // !(busy)
  , ProtocolEvent1 // !(reset)
  , ProtocolEvent3 // (!in_en&&!(reset))
  , ProtocolEvent4 // (!in_en||reset)
  , ProtocolEvent2 // (in_en&&!(reset))
  , ProtocolEvent6 // busy
  , ProtocolEvent7 // false
  , ProtocolEvent0 // reset
};

#endif // CTE_H



#include "CTE.h"

void CTE::run(ProtocolEvent e) {

    switch(_protocolState) {
        case ProtocolState_s0/*s0*/:
S0:
            if (e == ProtocolEvent0/*reset*/) {
                _protocolState = ProtocolState_s1/*s1*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent1/*!(reset)*/) {
                _protocolState = ProtocolState_s0/*s0*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s1/*s1*/:
S1:
            if (e == ProtocolEvent0/*reset*/) {
                _protocolState = ProtocolState_s1/*s1*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent1/*!(reset)*/) {
                _protocolState = ProtocolState_s2/*s2*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s2/*s2*/:
S2:
            if (e == ProtocolEvent2/*(in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s3/*s3*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent3/*(!in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s2/*s2*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent0/*reset*/) {
                _protocolState = ProtocolState_s4/*assert(0)*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s3/*s3*/:
S3:
            if (e == ProtocolEvent2/*(in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s5/*s4*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent4/*(!in_en||reset)*/) {
                _protocolState = ProtocolState_s4/*assert(0)*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s4/*assert(0)*/:
S4:
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s5/*s4*/:
S5:
            if (e == ProtocolEvent2/*(in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s6/*s5*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent4/*(!in_en||reset)*/) {
                _protocolState = ProtocolState_s4/*assert(0)*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s6/*s5*/:
S6:
            if (e == ProtocolEvent5/*!(busy)*/) {
                _protocolState = ProtocolState_s7/*s7*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent6/*busy*/) {
                _protocolState = ProtocolState_s6/*s5*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s7/*s7*/:
S7:
            if (e == ProtocolEvent2/*(in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s8/*s8*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent4/*(!in_en||reset)*/) {
                _protocolState = ProtocolState_s4/*assert(0)*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s8/*s8*/:
S8:
            if (e == ProtocolEvent5/*!(busy)*/) {
                _protocolState = ProtocolState_s9/*s10*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent6/*busy*/) {
                _protocolState = ProtocolState_s8/*s8*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
        case ProtocolState_s9/*s10*/:
S9:
            if (e == ProtocolEvent2/*(in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s3/*s3*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent0/*reset*/) {
                _protocolState = ProtocolState_s1/*s1*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent7/*false*/) {
                _protocolState = ProtocolState_s2/*s2*/;
                // TODO
                break;
            };
            if (e == ProtocolEvent3/*(!in_en&&!(reset))*/) {
                _protocolState = ProtocolState_s4/*assert(0)*/;
                // TODO
                break;
            };
            LOG_ERROR("No Such branch");
            break;
}
// Function calls
void CTE::func_number_0() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_Y1;
} else
 {if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_V;
} else
 {if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_BUSY1;
} else
 {if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_Y2;
} else
 {if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_BUSY2;
} else
 {if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)) {
yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.S_U;
} else
 {yuv_to_rgb_inst0.state_next = yuv_to_rgb_inst0.state;}}}}}}
}

void CTE::func_number_1() {
    if ((reset || (!in_en))) {
yuv_to_rgb_inst0.reg_U = sc_uint<8>(0);
} else
 {yuv_to_rgb_inst0.reg_U = yuv_to_rgb_inst0.reg_U_next;}
}

void CTE::func_number_2() {
    if ((reset || (!in_en))) {
yuv_to_rgb_inst0.reg_V = sc_uint<8>(0);
} else
 {yuv_to_rgb_inst0.reg_V = yuv_to_rgb_inst0.reg_V_next;}
}

void CTE::func_number_3() {
    if ((reset || (!in_en))) {
yuv_to_rgb_inst0.reg_Y1 = sc_uint<8>(0);
} else
 {yuv_to_rgb_inst0.reg_Y1 = yuv_to_rgb_inst0.reg_Y1_next;}
}

void CTE::func_number_4() {
    if ((reset || (!in_en))) {
yuv_to_rgb_inst0.reg_Y2 = sc_uint<8>(0);
} else
 {yuv_to_rgb_inst0.reg_Y2 = yuv_to_rgb_inst0.reg_Y2_next;}
}

void CTE::func_number_5() {
    if ((reset || (!in_en))) {
yuv_to_rgb_inst0.state = yuv_to_rgb_inst0.S_U;
} else
 {yuv_to_rgb_inst0.state = yuv_to_rgb_inst0.state_next;}
}

void CTE::func_number_6() {
    if ((!op_mode)) {
busy = yuv_to_rgb_busy;
} else
 {busy = 1;}
}

void CTE::func_number_7() {
    if ((!op_mode)) {
out_valid = yuv_to_rgb_out_valid;
} else
 {out_valid = 0;}
}

void CTE::func_number_8() {
    yuv_out = sc_uint<8>(0);
}

void CTE::func_number_9() {
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_10() {
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_11() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)) {
yuv_to_rgb_inst0.reg_U_next = yuv_in;
} else
 {yuv_to_rgb_inst0.reg_U_next = yuv_to_rgb_inst0.reg_U;}
}

void CTE::func_number_12() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)) {
yuv_to_rgb_inst0.reg_Y1_next = yuv_in;
} else
 {yuv_to_rgb_inst0.reg_Y1_next = yuv_to_rgb_inst0.reg_Y1;}
}

void CTE::func_number_13() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)) {
yuv_to_rgb_inst0.reg_V_next = yuv_in;
} else
 {yuv_to_rgb_inst0.reg_V_next = yuv_to_rgb_inst0.reg_V;}
}

void CTE::func_number_14() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)) {
yuv_to_rgb_inst0.reg_Y2_next = yuv_in;
} else
 {yuv_to_rgb_inst0.reg_Y2_next = yuv_to_rgb_inst0.reg_Y2;}
}

void CTE::func_number_15() {
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_U[sc_uint<32>(7)])), yuv_to_rgb_inst0.reg_U);
}

void CTE::func_number_16() {
    if ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)) {
yuv_to_rgb_inst0.Y_ext = (sc_uint<8>(0), yuv_to_rgb_inst0.reg_Y1);
} else
 {yuv_to_rgb_inst0.Y_ext = (sc_uint<8>(0), yuv_to_rgb_inst0.reg_Y2);}
}

void CTE::func_number_17() {
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)]), (yuv_to_rgb_inst0.reg_V[sc_uint<32>(7)])), yuv_to_rgb_inst0.reg_V);
}

void CTE::func_number_18() {
    yuv_to_rgb_inst0.R_ext = ((sc_uint<16>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<16>(13) * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_19() {
    yuv_to_rgb_inst0.G_ext = (((sc_uint<16>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<16>(65534) * yuv_to_rgb_inst0.U_ext)) + (sc_uint<16>(65530) * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_20() {
    yuv_to_rgb_inst0.B_ext = ((sc_uint<16>(8) * yuv_to_rgb_inst0.Y_ext) + (sc_uint<16>(16) * yuv_to_rgb_inst0.U_ext));
}

void CTE::func_number_21() {
    if (yuv_to_rgb_inst0.R_ext[sc_uint<32>(15)]) {
yuv_to_rgb_inst0.R_out = sc_uint<8>(0);
} else
 {if ((yuv_to_rgb_inst0.R_ext.range(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))) {
yuv_to_rgb_inst0.R_out = sc_uint<8>(255);
} else
 {if (yuv_to_rgb_inst0.R_ext[sc_uint<32>(2)]) {
if ((yuv_to_rgb_inst0.R_ext.range(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))) {
yuv_to_rgb_inst0.R_out = sc_uint<8>(255);
} else
 {yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext.range(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1));}
} else
 {yuv_to_rgb_inst0.R_out = yuv_to_rgb_inst0.R_ext.range(sc_uint<32>(10), sc_uint<32>(3));}}}
}

void CTE::func_number_22() {
    if (yuv_to_rgb_inst0.G_ext[sc_uint<32>(15)]) {
yuv_to_rgb_inst0.G_out = sc_uint<8>(0);
} else
 {if ((yuv_to_rgb_inst0.G_ext.range(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))) {
yuv_to_rgb_inst0.G_out = sc_uint<8>(255);
} else
 {if (yuv_to_rgb_inst0.G_ext[sc_uint<32>(2)]) {
if ((yuv_to_rgb_inst0.G_ext.range(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))) {
yuv_to_rgb_inst0.G_out = sc_uint<8>(255);
} else
 {yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext.range(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1));}
} else
 {yuv_to_rgb_inst0.G_out = yuv_to_rgb_inst0.G_ext.range(sc_uint<32>(10), sc_uint<32>(3));}}}
}

void CTE::func_number_23() {
    if (yuv_to_rgb_inst0.B_ext[sc_uint<32>(15)]) {
yuv_to_rgb_inst0.B_out = sc_uint<8>(0);
} else
 {if ((yuv_to_rgb_inst0.B_ext.range(sc_uint<32>(14), sc_uint<32>(11)) != sc_uint<4>(0))) {
yuv_to_rgb_inst0.B_out = sc_uint<8>(255);
} else
 {if (yuv_to_rgb_inst0.B_ext[sc_uint<32>(2)]) {
if ((yuv_to_rgb_inst0.B_ext.range(sc_uint<32>(10), sc_uint<32>(3)) == sc_uint<8>(255))) {
yuv_to_rgb_inst0.B_out = sc_uint<8>(255);
} else
 {yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext.range(sc_uint<32>(10), sc_uint<32>(3)) + sc_uint<8>(1));}
} else
 {yuv_to_rgb_inst0.B_out = yuv_to_rgb_inst0.B_ext.range(sc_uint<32>(10), sc_uint<32>(3));}}}
}

void CTE::func_number_24() {
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}


