#ifndef DESIGN_CTE_H
#define DESIGN_CTE_H

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

    // Integer 
};

