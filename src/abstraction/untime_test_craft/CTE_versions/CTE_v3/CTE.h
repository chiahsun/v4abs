#ifndef CTE_H
#define CTE_H

#include <iostream>
#include <systemc.h>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << " @ (" << __FILE__ << " : " << __LINE__ << ")" << std::endl; } while(0)

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
    sc_uint<4> S_U;
    sc_uint<4> S_Y1;
    sc_uint<4> S_V;
    sc_uint<4> S_BUSY1;
    sc_uint<4> S_Y2;
    sc_uint<4> S_BUSY2;

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

enum ProtocolEvent {
    ProtocolEvent_none
  , ProtocolEvent_reset
  , ProtocolEvent_not_reset_and_in_en
  , ProtocolEvent_not_reset // and not in_en
  , ProtocolEvent_in_en
  , ProtocolEvent_write_rgb_out
};

enum ProtocolState {
    ProtocolState_s0
  , ProtocolState_s1
  , ProtocolState_s2
  , ProtocolState_s3
  , ProtocolState_s4
  , ProtocolState_s5
  , ProtocolState_s7
  , ProtocolState_s8
  , ProtocolState_s10
};

struct CTE {
   
    // Protocol controls
    sc_uint<8>* _pData_yuv_in;
    sc_uint<24>* _pData_rgb_out;
    void register_data_pointer( sc_uint<8>* pData_yuv_in
                              , sc_uint<24>* pData_rgb_out) {
        _pData_yuv_in = pData_yuv_in;
        _pData_rgb_out = pData_rgb_out;
    }
    void init();
    void run(ProtocolEvent e);
    ProtocolState _protocolState;
    void read_yuv_in()
      { yuv_in = *_pData_yuv_in; }
    void write_rgb_out() { 
        *_pData_rgb_out = rgb_out;
//        std::cout << rgb_out << std::endl; 
    }
    void print() const; 
    void compute_all(); 
    void compute_not_reset_and_in_en_and_write_rgb_out();
    void compute_reset(); 
    void compute_not_reset(); 
    void compute_not_reset_and_in_en();
    

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



