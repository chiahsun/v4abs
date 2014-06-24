#ifndef GSIM_H
#define GSIM_H

#include <systemc.h>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

struct calvalue {

    // Inputs 
    sc_biguint<64> in_0;
    sc_biguint<64> in_1;
    sc_biguint<64> in_2;
    sc_biguint<64> in_3;
    sc_biguint<64> in_4;
    sc_biguint<64> in_5;
    sc_uint<16> in_b;

    // Outputs 
    sc_biguint<64> out_ans;

    // Inouts 

    // Parameters

    // Registers

    // Wires
    sc_biguint<64> comb_0;
    sc_biguint<64> comb_1;
    sc_biguint<64> comb_2;
    sc_biguint<64> comb_3;
    sc_biguint<64> shi_11;
    sc_biguint<64> shi_12;
    sc_biguint<64> shi_22;
    sc_biguint<64> shi_23;
    sc_biguint<64> add_tmp;
    sc_biguint<96> add_ext;
    sc_biguint<96> tmp_ans;

    // Module instances

    // Function calls
};



enum ProtocolEvent {
    ProtocolEvent_reset
  , ProtocolEvent_not_reset
  , ProtocolEvent_not_reset_and_in_en
  , ProtocolEvent_not_reset_and_not_in_en
};

enum ProtocolState {
    ProtocolState_s0
  , ProtocolState_s1
  , ProtocolState_s2
  , ProtocolState_s3
  , ProtocolState_s4
  , ProtocolState_s5
  , ProtocolState_s6
  , ProtocolState_s7
  , ProtocolState_s8
  , ProtocolState_s9
  , ProtocolState_s10
  , ProtocolState_s11
  , ProtocolState_s12
  , ProtocolState_s13
  , ProtocolState_s14
  , ProtocolState_s15
  , ProtocolState_s16
  , ProtocolState_s17
  , ProtocolState_s18
  , ProtocolState_s19
  , ProtocolState_s20
  , ProtocolState_s21
  , ProtocolState_s22
  , ProtocolState_s23
  , ProtocolState_s24
  , ProtocolState_s25
  , ProtocolState_s26
  , ProtocolState_s27
  , ProtocolState_s28
  , ProtocolState_s29
  , ProtocolState_s30
  , ProtocolState_s31
  , ProtocolState_s32
  , ProtocolState_s33
};


struct GSIM {
    sc_uint<16>* _pData_b_in;
    sc_uint<32>* _pData_x_out;

    unsigned int _cycleCount;
    void register_data_pointer( sc_uint<16>* pData_b_in
                              , sc_uint<32>* pData_x_out) {
        _pData_b_in = pData_b_in;
        _pData_x_out = pData_x_out;
    }
    void init() {
        _protocolState = ProtocolState_s0;
        _cycleCount = 0;
    }
    void compute_all();
    void compute_seq();
    void compute_combinational();
    void compute_reset();
    void compute_not_reset();
    void compute_not_reset_and_not_in_en();
    void compute_not_reset_and_in_en();

    void run(ProtocolEvent e);
    void read_b_in()
      { b_in = *_pData_b_in; }
    void write_x_out() {
        std::cout << "x_out " << x_out << " @ " << _cycleCount << std::endl;
//        DEBUG_EXPR(x_out);
        *_pData_x_out = x_out; 
    }

    ProtocolState _protocolState;


    // Inputs 
    bool clk;
    bool reset;
    bool in_en;
    sc_uint<16> b_in;

    // Outputs 
    bool out_valid;
    sc_uint<32> x_out;

    // Inouts 

    // Parameters

    // Registers
    sc_uint<4> count;
    sc_uint<10> loop;
    sc_uint<4> next_count;
    sc_uint<10> next_loop;
    sc_uint<16> inb_0;
    sc_uint<16> inb_1;
    sc_uint<16> inb_2;
    sc_uint<16> inb_3;
    sc_uint<16> inb_4;
    sc_uint<16> inb_5;
    sc_uint<16> inb_6;
    sc_uint<16> inb_7;
    sc_uint<16> inb_8;
    sc_uint<16> inb_9;
    sc_uint<16> inb_10;
    sc_uint<16> inb_11;
    sc_uint<16> inb_12;
    sc_uint<16> inb_13;
    sc_uint<16> inb_14;
    sc_uint<16> inb_15;
    sc_uint<16> next_inb_0;
    sc_uint<16> next_inb_1;
    sc_uint<16> next_inb_2;
    sc_uint<16> next_inb_3;
    sc_uint<16> next_inb_4;
    sc_uint<16> next_inb_5;
    sc_uint<16> next_inb_6;
    sc_uint<16> next_inb_7;
    sc_uint<16> next_inb_8;
    sc_uint<16> next_inb_9;
    sc_uint<16> next_inb_10;
    sc_uint<16> next_inb_11;
    sc_uint<16> next_inb_12;
    sc_uint<16> next_inb_13;
    sc_uint<16> next_inb_14;
    sc_uint<16> next_inb_15;
    sc_biguint<64> out_0;
    sc_biguint<64> out_1;
    sc_biguint<64> out_2;
    sc_biguint<64> out_3;
    sc_biguint<64> out_4;
    sc_biguint<64> out_5;
    sc_biguint<64> out_6;
    sc_biguint<64> out_7;
    sc_biguint<64> out_8;
    sc_biguint<64> out_9;
    sc_biguint<64> out_10;
    sc_biguint<64> out_11;
    sc_biguint<64> out_12;
    sc_biguint<64> out_13;
    sc_biguint<64> out_14;
    sc_biguint<64> out_15;
    sc_biguint<64> next_out_0;
    sc_biguint<64> next_out_1;
    sc_biguint<64> next_out_2;
    sc_biguint<64> next_out_3;
    sc_biguint<64> next_out_4;
    sc_biguint<64> next_out_5;
    sc_biguint<64> next_out_6;
    sc_biguint<64> next_out_7;
    sc_biguint<64> next_out_8;
    sc_biguint<64> next_out_9;
    sc_biguint<64> next_out_10;
    sc_biguint<64> next_out_11;
    sc_biguint<64> next_out_12;
    sc_biguint<64> next_out_13;
    sc_biguint<64> next_out_14;
    sc_biguint<64> next_out_15;
    sc_biguint<64> par_0;
    sc_biguint<64> par_1;
    sc_biguint<64> par_2;
    sc_biguint<64> par_3;
    sc_biguint<64> par_4;
    sc_biguint<64> par_5;
    sc_uint<16> par_b;

    // Wires
    sc_biguint<64> tmp_out;

    // Module instances
    calvalue cal0;

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
    void func_number_25();
    void func_number_26();
    void func_number_27();
    void func_number_28();
    void func_number_29();
    void func_number_30();
    void func_number_31();
    void func_number_32();
    void func_number_33();
    void func_number_34();
    void func_number_35();
    void func_number_36();
    void func_number_37();
    void func_number_38();
    void func_number_39();
    void func_number_40();
    void func_number_41();
    void func_number_42();
    void func_number_43();
    void func_number_44();
    void func_number_45();
    void func_number_46();
    void func_number_47();
    void func_number_48();
    void func_number_49();
    void func_number_50();
    void func_number_51();
    void func_number_52();
    void func_number_53();
    void func_number_54();
    void func_number_55();
    void func_number_56();
    void func_number_57();
    void func_number_58();
    void func_number_59();
    void func_number_60();
    void func_number_61();
    void func_number_62();
    void func_number_63();
    void func_number_64();
    void func_number_65();
    void func_number_66();
    void func_number_67();
    void func_number_68();
    void func_number_69();
    void func_number_70();
    void func_number_71();
    void func_number_72();
    void func_number_73();
    void func_number_74();
    void func_number_75();
    void func_number_76();
    void func_number_77();
    void func_number_78();
    void func_number_79();
    void func_number_80();
    void func_number_81();
    void func_number_82();
    void func_number_83();
    void func_number_84();
    void func_number_85();
    void func_number_86();
    void func_number_87();
    void func_number_88();


};

#endif // GSIM_H
