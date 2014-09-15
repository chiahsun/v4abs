#include "GSIM.h"


#define LOG_ERROR(msg) do { std::cerr << "LOG(ERROR): " << msg << " @ (" << __FILE__ << " : " << __LINE__ << ")" << std::endl; assert(0); } while(0)

static const bool verbose = false;

void GSIM::run(ProtocolEvent e) {
    switch(_protocolState) {
        case ProtocolState_s0:
            if (e == ProtocolEvent_reset) {
                compute_reset();
                _protocolState = ProtocolState_s1;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s1:
            if (e == ProtocolEvent_not_reset) {
                compute_not_reset();
                _protocolState = ProtocolState_s2;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s2:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s3;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s3:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s4;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s4:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s5;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s5:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s6;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s6:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s7;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s7:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s8;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s8:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s9;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s9:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s10;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s10:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s11;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s11:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s12;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s12:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s13;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s13:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s14;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s14:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s15;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s15:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s16;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s16:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s17;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s17:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_b_in();
                compute_not_reset_and_in_en();
                _protocolState = ProtocolState_s18;
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s18:
S18:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s19;
                } else {
                    goto S18;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s19:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s20;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s20:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s21;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s21:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s22;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s22:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s23;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s23:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s24;
                } 
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s24:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s25;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s25:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s26;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s26:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s27;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s27:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s28;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s28:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s29;
                } 
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s29:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s30;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s30:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s31;
                } 
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s31:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s32;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s32:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s33;
                }
            } else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s33:
            if (e == ProtocolEvent_not_reset_and_not_in_en) {
                compute_not_reset_and_not_in_en();
                if (out_valid) {
                    write_x_out();
                    _protocolState = ProtocolState_s1;
                } 
            } else
                LOG_ERROR("No such branch");
            break;
    }
}

void GSIM::compute_combinational() {
    // par_0 ~ par_b
    func_number_19();
    func_number_20();
    func_number_21();
    func_number_22();
    func_number_23();
    func_number_24();
    func_number_36();
    // cal0
    func_number_77();
    func_number_78();
    func_number_79();
    func_number_80();
    func_number_81();
    func_number_82();
    func_number_83();
    func_number_84();
    func_number_85();
    func_number_86();
    func_number_87();
    func_number_88();
    

    // next_inb_0 ~ next_inb_15
    func_number_2();
    func_number_3();
    func_number_4();
    func_number_5();
    func_number_6();
    func_number_7();
    func_number_8();
    func_number_9();
    func_number_10();
    func_number_11();
    func_number_13();
    func_number_14();
    func_number_15();
    func_number_16();
    func_number_17();
    func_number_18();
    // next_out_0 ~ next_out_15
    func_number_25();
    func_number_26();
    func_number_27();
    func_number_28();
    func_number_29();
    func_number_30();
    func_number_31();
    func_number_32();
    func_number_33();
    func_number_34();
    func_number_39();
    func_number_40();
    func_number_41();
    func_number_42();
    func_number_0();
    func_number_1();

    // next_count
    func_number_35();
    // next_loop
    func_number_38();

    // out_valid
    func_number_37();
    // x_out
    func_number_12();

}

void GSIM::compute_seq() {
    // register
    // count
    func_number_52();
    // loop
    func_number_53();
    // inb_0 ~ inb_15
    func_number_66();
    func_number_67();
    func_number_68();
    func_number_69();
    func_number_70();
    func_number_71();
    func_number_72();
    func_number_73();
    func_number_74();
    func_number_75();
    func_number_60();
    func_number_61();
    func_number_62();
    func_number_63();
    func_number_64();
    func_number_65();
    // out_0 ~ out_15
    func_number_76();
    func_number_43();
    func_number_44();
    func_number_45();
    func_number_46();
    func_number_47();
    func_number_48();
    func_number_49();
    func_number_50();
    func_number_51();
    func_number_54();
    func_number_55();
    func_number_56();
    func_number_57();
    func_number_58();
    func_number_59();

}
#if 0
void GSIM::compute_all() {
    compute_combinational();
    compute_seq();
    compute_combinational();
    ++_cycleCount;
    if (_cycleCount % 100 == 0) {
        DEBUG_EXPR(_protocolState);
        DEBUG_EXPR(_cycleCount);
    }
}
#else
void GSIM::compute_all() {
    // par_0 ~ par_b
    func_number_19();
    func_number_20();
    func_number_21();
    func_number_22();
    func_number_23();
    func_number_24();
    func_number_36();
    // cal0
    func_number_77();
    func_number_78();
    func_number_79();
    func_number_80();
    func_number_81();
    func_number_82();
    func_number_83();
    func_number_84();
    func_number_85();
    func_number_86();
    func_number_87();
    func_number_88();
    

    // next_inb_0 ~ next_inb_15
    func_number_2();
    func_number_3();
    func_number_4();
    func_number_5();
    func_number_6();
    func_number_7();
    func_number_8();
    func_number_9();
    func_number_10();
    func_number_11();
    func_number_13();
    func_number_14();
    func_number_15();
    func_number_16();
    func_number_17();
    func_number_18();
    // next_out_0 ~ next_out_15
    func_number_25();
    func_number_26();
    func_number_27();
    func_number_28();
    func_number_29();
    func_number_30();
    func_number_31();
    func_number_32();
    func_number_33();
    func_number_34();
    func_number_39();
    func_number_40();
    func_number_41();
    func_number_42();
    func_number_0();
    func_number_1();

    // next_count
    func_number_35();
    // next_loop
    func_number_38();

    // register
    // count
    func_number_52();
    // loop
    func_number_53();
    // inb_0 ~ inb_15
    func_number_66();
    func_number_67();
    func_number_68();
    func_number_69();
    func_number_70();
    func_number_71();
    func_number_72();
    func_number_73();
    func_number_74();
    func_number_75();
    func_number_60();
    func_number_61();
    func_number_62();
    func_number_63();
    func_number_64();
    func_number_65();
    // out_0 ~ out_15
    func_number_76();
    func_number_43();
    func_number_44();
    func_number_45();
    func_number_46();
    func_number_47();
    func_number_48();
    func_number_49();
    func_number_50();
    func_number_51();
    func_number_54();
    func_number_55();
    func_number_56();
    func_number_57();
    func_number_58();
    func_number_59();

    // out_valid
    func_number_37();
    // x_out
    func_number_12();
    ++_cycleCount;
if (verbose) {
    if (_cycleCount % 100 == 0) {
        DEBUG_EXPR(_protocolState);
        DEBUG_EXPR(_cycleCount);
    }
}
}
#endif

void GSIM::compute_reset() {
    reset = 1;
    compute_all();
}

void GSIM::compute_not_reset() {
    reset = 0;
    compute_all();
}

void GSIM::compute_not_reset_and_in_en() {
    reset = 0;
    in_en = 1;
    compute_all();
}
void GSIM::compute_not_reset_and_not_in_en() {
    reset = 0;
    in_en = 0;
    compute_all();
}


// Function calls
void GSIM::func_number_0() {
    if (reset) {
next_out_14 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_14 = out_15;
} else
 {if ((count == sc_uint<4>(14))) {
next_out_14 = tmp_out;
} else
 {next_out_14 = out_14;}}}
}

void GSIM::func_number_1() {
    if (reset) {
next_out_15 = sc_biguint<64>(0);
} else
 {if (in_en) {
if (b_in[sc_uint<32>(15)]) {
next_out_15 = (sc_uint<20>(1048575), b_in.range(sc_uint<32>(15), sc_uint<32>(4)), sc_uint<32>(0));
} else
 {next_out_15 = (sc_uint<20>(0), b_in.range(sc_uint<32>(15), sc_uint<32>(4)), sc_uint<32>(0));}
} else
 {if ((count == sc_uint<4>(15))) {
next_out_15 = tmp_out;
} else
 {next_out_15 = out_15;}}}
}

void GSIM::func_number_2() {
    if (reset) {
next_inb_0 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_0 = inb_1;
} else
 {next_inb_0 = inb_0;}}
}

void GSIM::func_number_3() {
    if (reset) {
next_inb_1 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_1 = inb_2;
} else
 {next_inb_1 = inb_1;}}
}

void GSIM::func_number_4() {
    if (reset) {
next_inb_2 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_2 = inb_3;
} else
 {next_inb_2 = inb_2;}}
}

void GSIM::func_number_5() {
    if (reset) {
next_inb_3 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_3 = inb_4;
} else
 {next_inb_3 = inb_3;}}
}

void GSIM::func_number_6() {
    if (reset) {
next_inb_4 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_4 = inb_5;
} else
 {next_inb_4 = inb_4;}}
}

void GSIM::func_number_7() {
    if (reset) {
next_inb_5 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_5 = inb_6;
} else
 {next_inb_5 = inb_5;}}
}

void GSIM::func_number_8() {
    if (reset) {
next_inb_6 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_6 = inb_7;
} else
 {next_inb_6 = inb_6;}}
}

void GSIM::func_number_9() {
    if (reset) {
next_inb_7 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_7 = inb_8;
} else
 {next_inb_7 = inb_7;}}
}

void GSIM::func_number_10() {
    if (reset) {
next_inb_8 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_8 = inb_9;
} else
 {next_inb_8 = inb_8;}}
}

void GSIM::func_number_11() {
    if (reset) {
next_inb_9 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_9 = inb_10;
} else
 {next_inb_9 = inb_9;}}
}

void GSIM::func_number_12() {
    if (reset) {
x_out = sc_uint<32>(0);
} else
 {if ((count == sc_uint<4>(0))) {
x_out = out_0.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(1))) {
x_out = out_1.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(2))) {
x_out = out_2.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(3))) {
x_out = out_3.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(4))) {
x_out = out_4.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(5))) {
x_out = out_5.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(6))) {
x_out = out_6.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(7))) {
x_out = out_7.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(8))) {
x_out = out_8.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(9))) {
x_out = out_9.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(10))) {
x_out = out_10.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(11))) {
x_out = out_11.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(12))) {
x_out = out_12.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(13))) {
x_out = out_13.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(14))) {
x_out = out_14.range(sc_uint<32>(47), sc_uint<32>(16));
} else
 {if ((count == sc_uint<4>(15))) {
x_out = out_15.range(sc_uint<32>(47), sc_uint<32>(16));}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_13() {
    if (reset) {
next_inb_10 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_10 = inb_11;
} else
 {next_inb_10 = inb_10;}}
}

void GSIM::func_number_14() {
    if (reset) {
next_inb_11 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_11 = inb_12;
} else
 {next_inb_11 = inb_11;}}
}

void GSIM::func_number_15() {
    if (reset) {
next_inb_12 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_12 = inb_13;
} else
 {next_inb_12 = inb_12;}}
}

void GSIM::func_number_16() {
    if (reset) {
next_inb_13 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_13 = inb_14;
} else
 {next_inb_13 = inb_13;}}
}

void GSIM::func_number_17() {
    if (reset) {
next_inb_14 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_14 = inb_15;
} else
 {next_inb_14 = inb_14;}}
}

void GSIM::func_number_18() {
    if (reset) {
next_inb_15 = sc_uint<16>(0);
} else
 {if (in_en) {
next_inb_15 = b_in;
} else
 {next_inb_15 = inb_15;}}
}

void GSIM::func_number_19() {
    if (reset) {
par_0 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_0 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(1))) {
par_0 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(2))) {
par_0 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(3))) {
par_0 = out_0;
} else
 {if ((count == sc_uint<4>(4))) {
par_0 = out_1;
} else
 {if ((count == sc_uint<4>(5))) {
par_0 = out_2;
} else
 {if ((count == sc_uint<4>(6))) {
par_0 = out_3;
} else
 {if ((count == sc_uint<4>(7))) {
par_0 = out_4;
} else
 {if ((count == sc_uint<4>(8))) {
par_0 = out_5;
} else
 {if ((count == sc_uint<4>(9))) {
par_0 = out_6;
} else
 {if ((count == sc_uint<4>(10))) {
par_0 = out_7;
} else
 {if ((count == sc_uint<4>(11))) {
par_0 = out_8;
} else
 {if ((count == sc_uint<4>(12))) {
par_0 = out_9;
} else
 {if ((count == sc_uint<4>(13))) {
par_0 = out_10;
} else
 {if ((count == sc_uint<4>(14))) {
par_0 = out_11;
} else
 {if ((count == sc_uint<4>(15))) {
par_0 = out_12;}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_20() {
    if (reset) {
par_1 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_1 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(1))) {
par_1 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(2))) {
par_1 = out_0;
} else
 {if ((count == sc_uint<4>(3))) {
par_1 = out_1;
} else
 {if ((count == sc_uint<4>(4))) {
par_1 = out_2;
} else
 {if ((count == sc_uint<4>(5))) {
par_1 = out_3;
} else
 {if ((count == sc_uint<4>(6))) {
par_1 = out_4;
} else
 {if ((count == sc_uint<4>(7))) {
par_1 = out_5;
} else
 {if ((count == sc_uint<4>(8))) {
par_1 = out_6;
} else
 {if ((count == sc_uint<4>(9))) {
par_1 = out_7;
} else
 {if ((count == sc_uint<4>(10))) {
par_1 = out_8;
} else
 {if ((count == sc_uint<4>(11))) {
par_1 = out_9;
} else
 {if ((count == sc_uint<4>(12))) {
par_1 = out_10;
} else
 {if ((count == sc_uint<4>(13))) {
par_1 = out_11;
} else
 {if ((count == sc_uint<4>(14))) {
par_1 = out_12;
} else
 {if ((count == sc_uint<4>(15))) {
par_1 = out_13;}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_21() {
    if (reset) {
par_2 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_2 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(1))) {
par_2 = out_0;
} else
 {if ((count == sc_uint<4>(2))) {
par_2 = out_1;
} else
 {if ((count == sc_uint<4>(3))) {
par_2 = out_2;
} else
 {if ((count == sc_uint<4>(4))) {
par_2 = out_3;
} else
 {if ((count == sc_uint<4>(5))) {
par_2 = out_4;
} else
 {if ((count == sc_uint<4>(6))) {
par_2 = out_5;
} else
 {if ((count == sc_uint<4>(7))) {
par_2 = out_6;
} else
 {if ((count == sc_uint<4>(8))) {
par_2 = out_7;
} else
 {if ((count == sc_uint<4>(9))) {
par_2 = out_8;
} else
 {if ((count == sc_uint<4>(10))) {
par_2 = out_9;
} else
 {if ((count == sc_uint<4>(11))) {
par_2 = out_10;
} else
 {if ((count == sc_uint<4>(12))) {
par_2 = out_11;
} else
 {if ((count == sc_uint<4>(13))) {
par_2 = out_12;
} else
 {if ((count == sc_uint<4>(14))) {
par_2 = out_13;
} else
 {if ((count == sc_uint<4>(15))) {
par_2 = out_14;}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_22() {
    if (reset) {
par_3 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_3 = out_1;
} else
 {if ((count == sc_uint<4>(1))) {
par_3 = out_2;
} else
 {if ((count == sc_uint<4>(2))) {
par_3 = out_3;
} else
 {if ((count == sc_uint<4>(3))) {
par_3 = out_4;
} else
 {if ((count == sc_uint<4>(4))) {
par_3 = out_5;
} else
 {if ((count == sc_uint<4>(5))) {
par_3 = out_6;
} else
 {if ((count == sc_uint<4>(6))) {
par_3 = out_7;
} else
 {if ((count == sc_uint<4>(7))) {
par_3 = out_8;
} else
 {if ((count == sc_uint<4>(8))) {
par_3 = out_9;
} else
 {if ((count == sc_uint<4>(9))) {
par_3 = out_10;
} else
 {if ((count == sc_uint<4>(10))) {
par_3 = out_11;
} else
 {if ((count == sc_uint<4>(11))) {
par_3 = out_12;
} else
 {if ((count == sc_uint<4>(12))) {
par_3 = out_13;
} else
 {if ((count == sc_uint<4>(13))) {
par_3 = out_14;
} else
 {if ((count == sc_uint<4>(14))) {
par_3 = out_15;
} else
 {if ((count == sc_uint<4>(15))) {
par_3 = sc_biguint<64>(0);}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_23() {
    if (reset) {
par_4 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_4 = out_2;
} else
 {if ((count == sc_uint<4>(1))) {
par_4 = out_3;
} else
 {if ((count == sc_uint<4>(2))) {
par_4 = out_4;
} else
 {if ((count == sc_uint<4>(3))) {
par_4 = out_5;
} else
 {if ((count == sc_uint<4>(4))) {
par_4 = out_6;
} else
 {if ((count == sc_uint<4>(5))) {
par_4 = out_7;
} else
 {if ((count == sc_uint<4>(6))) {
par_4 = out_8;
} else
 {if ((count == sc_uint<4>(7))) {
par_4 = out_9;
} else
 {if ((count == sc_uint<4>(8))) {
par_4 = out_10;
} else
 {if ((count == sc_uint<4>(9))) {
par_4 = out_11;
} else
 {if ((count == sc_uint<4>(10))) {
par_4 = out_12;
} else
 {if ((count == sc_uint<4>(11))) {
par_4 = out_13;
} else
 {if ((count == sc_uint<4>(12))) {
par_4 = out_14;
} else
 {if ((count == sc_uint<4>(13))) {
par_4 = out_15;
} else
 {if ((count == sc_uint<4>(14))) {
par_4 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(15))) {
par_4 = sc_biguint<64>(0);}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_24() {
    if (reset) {
par_5 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_5 = out_3;
} else
 {if ((count == sc_uint<4>(1))) {
par_5 = out_4;
} else
 {if ((count == sc_uint<4>(2))) {
par_5 = out_5;
} else
 {if ((count == sc_uint<4>(3))) {
par_5 = out_6;
} else
 {if ((count == sc_uint<4>(4))) {
par_5 = out_7;
} else
 {if ((count == sc_uint<4>(5))) {
par_5 = out_8;
} else
 {if ((count == sc_uint<4>(6))) {
par_5 = out_9;
} else
 {if ((count == sc_uint<4>(7))) {
par_5 = out_10;
} else
 {if ((count == sc_uint<4>(8))) {
par_5 = out_11;
} else
 {if ((count == sc_uint<4>(9))) {
par_5 = out_12;
} else
 {if ((count == sc_uint<4>(10))) {
par_5 = out_13;
} else
 {if ((count == sc_uint<4>(11))) {
par_5 = out_14;
} else
 {if ((count == sc_uint<4>(12))) {
par_5 = out_15;
} else
 {if ((count == sc_uint<4>(13))) {
par_5 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(14))) {
par_5 = sc_biguint<64>(0);
} else
 {if ((count == sc_uint<4>(15))) {
par_5 = sc_biguint<64>(0);}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_25() {
    if (reset) {
next_out_0 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_0 = out_1;
} else
 {if ((count == sc_uint<4>(0))) {
next_out_0 = tmp_out;
} else
 {next_out_0 = out_0;}}}
}

void GSIM::func_number_26() {
    if (reset) {
next_out_1 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_1 = out_2;
} else
 {if ((count == sc_uint<4>(1))) {
next_out_1 = tmp_out;
} else
 {next_out_1 = out_1;}}}
}

void GSIM::func_number_27() {
    if (reset) {
next_out_2 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_2 = out_3;
} else
 {if ((count == sc_uint<4>(2))) {
next_out_2 = tmp_out;
} else
 {next_out_2 = out_2;}}}
}

void GSIM::func_number_28() {
    if (reset) {
next_out_3 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_3 = out_4;
} else
 {if ((count == sc_uint<4>(3))) {
next_out_3 = tmp_out;
} else
 {next_out_3 = out_3;}}}
}

void GSIM::func_number_29() {
    if (reset) {
next_out_4 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_4 = out_5;
} else
 {if ((count == sc_uint<4>(4))) {
next_out_4 = tmp_out;
} else
 {next_out_4 = out_4;}}}
}

void GSIM::func_number_30() {
    if (reset) {
next_out_5 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_5 = out_6;
} else
 {if ((count == sc_uint<4>(5))) {
next_out_5 = tmp_out;
} else
 {next_out_5 = out_5;}}}
}

void GSIM::func_number_31() {
    if (reset) {
next_out_6 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_6 = out_7;
} else
 {if ((count == sc_uint<4>(6))) {
next_out_6 = tmp_out;
} else
 {next_out_6 = out_6;}}}
}

void GSIM::func_number_32() {
    if (reset) {
next_out_7 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_7 = out_8;
} else
 {if ((count == sc_uint<4>(7))) {
next_out_7 = tmp_out;
} else
 {next_out_7 = out_7;}}}
}

void GSIM::func_number_33() {
    if (reset) {
next_out_8 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_8 = out_9;
} else
 {if ((count == sc_uint<4>(8))) {
next_out_8 = tmp_out;
} else
 {next_out_8 = out_8;}}}
}

void GSIM::func_number_34() {
    if (reset) {
next_out_9 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_9 = out_10;
} else
 {if ((count == sc_uint<4>(9))) {
next_out_9 = tmp_out;
} else
 {next_out_9 = out_9;}}}
}

void GSIM::func_number_35() {
    if (reset) {
next_count = sc_uint<4>(0);
} else
 {if (in_en) {
next_count = sc_uint<4>(0);
} else
 {next_count = (count + sc_uint<4>(1));}}
}

void GSIM::func_number_36() {
    if (reset) {
par_b = sc_uint<16>(0);
} else
 {if ((count == sc_uint<4>(0))) {
par_b = inb_0;
} else
 {if ((count == sc_uint<4>(1))) {
par_b = inb_1;
} else
 {if ((count == sc_uint<4>(2))) {
par_b = inb_2;
} else
 {if ((count == sc_uint<4>(3))) {
par_b = inb_3;
} else
 {if ((count == sc_uint<4>(4))) {
par_b = inb_4;
} else
 {if ((count == sc_uint<4>(5))) {
par_b = inb_5;
} else
 {if ((count == sc_uint<4>(6))) {
par_b = inb_6;
} else
 {if ((count == sc_uint<4>(7))) {
par_b = inb_7;
} else
 {if ((count == sc_uint<4>(8))) {
par_b = inb_8;
} else
 {if ((count == sc_uint<4>(9))) {
par_b = inb_9;
} else
 {if ((count == sc_uint<4>(10))) {
par_b = inb_10;
} else
 {if ((count == sc_uint<4>(11))) {
par_b = inb_11;
} else
 {if ((count == sc_uint<4>(12))) {
par_b = inb_12;
} else
 {if ((count == sc_uint<4>(13))) {
par_b = inb_13;
} else
 {if ((count == sc_uint<4>(14))) {
par_b = inb_14;
} else
 {if ((count == sc_uint<4>(15))) {
par_b = inb_15;}}}}}}}}}}}}}}}}}
}

void GSIM::func_number_37() {
    if (reset) {
out_valid = 0;
} else
 {out_valid = loop[sc_uint<32>(9)];}
}

void GSIM::func_number_38() {
    if (reset) {
next_loop = sc_uint<10>(0);
} else
 {if ((count == sc_uint<4>(15))) {
next_loop = (loop + sc_uint<10>(1));
} else
 {next_loop = loop;}}
}

void GSIM::func_number_39() {
    if (reset) {
next_out_10 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_10 = out_11;
} else
 {if ((count == sc_uint<4>(10))) {
next_out_10 = tmp_out;
} else
 {next_out_10 = out_10;}}}
}

void GSIM::func_number_40() {
    if (reset) {
next_out_11 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_11 = out_12;
} else
 {if ((count == sc_uint<4>(11))) {
next_out_11 = tmp_out;
} else
 {next_out_11 = out_11;}}}
}

void GSIM::func_number_41() {
    if (reset) {
next_out_12 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_12 = out_13;
} else
 {if ((count == sc_uint<4>(12))) {
next_out_12 = tmp_out;
} else
 {next_out_12 = out_12;}}}
}

void GSIM::func_number_42() {
    if (reset) {
next_out_13 = sc_biguint<64>(0);
} else
 {if (in_en) {
next_out_13 = out_14;
} else
 {if ((count == sc_uint<4>(13))) {
next_out_13 = tmp_out;
} else
 {next_out_13 = out_13;}}}
}

void GSIM::func_number_43() {
    if (reset) {
out_1 = sc_biguint<64>(0);
} else
 {out_1 = next_out_1;}
}

void GSIM::func_number_44() {
    if (reset) {
out_2 = sc_biguint<64>(0);
} else
 {out_2 = next_out_2;}
}

void GSIM::func_number_45() {
    if (reset) {
out_3 = sc_biguint<64>(0);
} else
 {out_3 = next_out_3;}
}

void GSIM::func_number_46() {
    if (reset) {
out_4 = sc_biguint<64>(0);
} else
 {out_4 = next_out_4;}
}

void GSIM::func_number_47() {
    if (reset) {
out_5 = sc_biguint<64>(0);
} else
 {out_5 = next_out_5;}
}

void GSIM::func_number_48() {
    if (reset) {
out_6 = sc_biguint<64>(0);
} else
 {out_6 = next_out_6;}
}

void GSIM::func_number_49() {
    if (reset) {
out_7 = sc_biguint<64>(0);
} else
 {out_7 = next_out_7;}
}

void GSIM::func_number_50() {
    if (reset) {
out_8 = sc_biguint<64>(0);
} else
 {out_8 = next_out_8;}
}

void GSIM::func_number_51() {
    if (reset) {
out_9 = sc_biguint<64>(0);
} else
 {out_9 = next_out_9;}
}

void GSIM::func_number_52() {
    if (reset) {
count = sc_uint<4>(0);
} else
 {count = next_count;}
}

void GSIM::func_number_53() {
    if (reset) {
loop = sc_uint<10>(0);
} else
 {loop = next_loop;}
}

void GSIM::func_number_54() {
    if (reset) {
out_10 = sc_biguint<64>(0);
} else
 {out_10 = next_out_10;}
}

void GSIM::func_number_55() {
    if (reset) {
out_11 = sc_biguint<64>(0);
} else
 {out_11 = next_out_11;}
}

void GSIM::func_number_56() {
    if (reset) {
out_12 = sc_biguint<64>(0);
} else
 {out_12 = next_out_12;}
}

void GSIM::func_number_57() {
    if (reset) {
out_13 = sc_biguint<64>(0);
} else
 {out_13 = next_out_13;}
}

void GSIM::func_number_58() {
    if (reset) {
out_14 = sc_biguint<64>(0);
} else
 {out_14 = next_out_14;}
}

void GSIM::func_number_59() {
    if (reset) {
out_15 = sc_biguint<64>(0);
} else
 {out_15 = next_out_15;}
}

void GSIM::func_number_60() {
    if (reset) {
inb_10 = sc_uint<16>(0);
} else
 {inb_10 = next_inb_10;}
}

void GSIM::func_number_61() {
    if (reset) {
inb_11 = sc_uint<16>(0);
} else
 {inb_11 = next_inb_11;}
}

void GSIM::func_number_62() {
    if (reset) {
inb_12 = sc_uint<16>(0);
} else
 {inb_12 = next_inb_12;}
}

void GSIM::func_number_63() {
    if (reset) {
inb_13 = sc_uint<16>(0);
} else
 {inb_13 = next_inb_13;}
}

void GSIM::func_number_64() {
    if (reset) {
inb_14 = sc_uint<16>(0);
} else
 {inb_14 = next_inb_14;}
}

void GSIM::func_number_65() {
    if (reset) {
inb_15 = sc_uint<16>(0);
} else
 {inb_15 = next_inb_15;}
}

void GSIM::func_number_66() {
    if (reset) {
inb_0 = sc_uint<16>(0);
} else
 {inb_0 = next_inb_0;}
}

void GSIM::func_number_67() {
    if (reset) {
inb_1 = sc_uint<16>(0);
} else
 {inb_1 = next_inb_1;}
}

void GSIM::func_number_68() {
    if (reset) {
inb_2 = sc_uint<16>(0);
} else
 {inb_2 = next_inb_2;}
}

void GSIM::func_number_69() {
    if (reset) {
inb_3 = sc_uint<16>(0);
} else
 {inb_3 = next_inb_3;}
}

void GSIM::func_number_70() {
    if (reset) {
inb_4 = sc_uint<16>(0);
} else
 {inb_4 = next_inb_4;}
}

void GSIM::func_number_71() {
    if (reset) {
inb_5 = sc_uint<16>(0);
} else
 {inb_5 = next_inb_5;}
}

void GSIM::func_number_72() {
    if (reset) {
inb_6 = sc_uint<16>(0);
} else
 {inb_6 = next_inb_6;}
}

void GSIM::func_number_73() {
    if (reset) {
inb_7 = sc_uint<16>(0);
} else
 {inb_7 = next_inb_7;}
}

void GSIM::func_number_74() {
    if (reset) {
inb_8 = sc_uint<16>(0);
} else
 {inb_8 = next_inb_8;}
}

void GSIM::func_number_75() {
    if (reset) {
inb_9 = sc_uint<16>(0);
} else
 {inb_9 = next_inb_9;}
}

void GSIM::func_number_76() {
    if (reset) {
out_0 = sc_biguint<64>(0);
} else
 {out_0 = next_out_0;}
}

void GSIM::func_number_77() {
    cal0.comb_0 = (par_0 + par_5);
}

void GSIM::func_number_78() {
    cal0.comb_1 = (par_1 + par_4);
}

void GSIM::func_number_79() {
    cal0.comb_2 = (par_2 + par_3);
}

void GSIM::func_number_80() {
    if (par_b[sc_uint<32>(15)]) {
cal0.comb_3 = (sc_uint<16>(65535), par_b, sc_uint<32>(0));
} else
 {cal0.comb_3 = (sc_uint<16>(0), par_b, sc_uint<32>(0));}
}

void GSIM::func_number_81() {
    cal0.shi_11 = (cal0.comb_1[sc_uint<32>(63)], cal0.comb_1.range(sc_uint<32>(61), sc_uint<32>(0)), 0);
}

void GSIM::func_number_82() {
    cal0.shi_12 = (cal0.comb_1[sc_uint<32>(63)], cal0.comb_1.range(sc_uint<32>(60), sc_uint<32>(0)), sc_uint<2>(0));
}

void GSIM::func_number_83() {
    cal0.shi_22 = (cal0.comb_2[sc_uint<32>(63)], cal0.comb_2.range(sc_uint<32>(60), sc_uint<32>(0)), sc_uint<2>(0));
}

void GSIM::func_number_84() {
    cal0.shi_23 = (cal0.comb_2[sc_uint<32>(63)], cal0.comb_2.range(sc_uint<32>(59), sc_uint<32>(0)), sc_uint<3>(0));
}

void GSIM::func_number_85() {
    cal0.add_tmp = (((cal0.comb_0 + cal0.comb_2) + (cal0.shi_22 + cal0.shi_23)) + (cal0.comb_3 - (cal0.shi_11 + cal0.shi_12)));
}

void GSIM::func_number_86() {
    if (cal0.add_tmp[sc_uint<32>(63)]) {
cal0.add_ext = (sc_uint<32>(4294967295), cal0.add_tmp);
} else
 {cal0.add_ext = (sc_uint<32>(0), cal0.add_tmp);}
}

void GSIM::func_number_87() {
    cal0.tmp_ans = (cal0.add_ext * (sc_biguint<64>(0), sc_uint<32>(214748365)));
}

void GSIM::func_number_88() {
    tmp_out = cal0.tmp_ans.range(sc_uint<32>(95), sc_uint<32>(32));
}


