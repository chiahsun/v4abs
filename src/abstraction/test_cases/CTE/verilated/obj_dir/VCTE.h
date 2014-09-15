// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCTE_H_
#define _VCTE_H_

#include "verilated.h"
class VCTE__Syms;

//----------

VL_MODULE(VCTE) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(op_mode,0,0);
    VL_IN8(in_en,0,0);
    VL_IN8(yuv_in,7,0);
    VL_OUT8(busy,0,0);
    VL_OUT8(out_valid,0,0);
    VL_OUT8(yuv_out,7,0);
    VL_IN(rgb_in,23,0);
    VL_OUT(rgb_out,23,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__state,3,0);
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__state_next,3,0);
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__reg_U,7,0);
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1,7,0);
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__reg_V,7,0);
    VL_SIG8(v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2,7,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__R_ext,15,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__G_ext,15,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__B_ext,15,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__U_ext,15,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__Y_ext,15,0);
    VL_SIG16(v__DOT__yuv_to_rgb_inst0__DOT__V_ext,15,0);
    //char	__VpadToAlign38[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG8(__Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[16],3,0);
    VL_SIG8(__Vtableidx1,3,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign46[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign52[4];
    VCTE__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VCTE& operator= (const VCTE&);	///< Copying not allowed
    VCTE(const VCTE&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VCTE(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VCTE();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VCTE__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VCTE__Syms* symsp, bool first);
  private:
    static QData	_change_request(VCTE__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__4(VCTE__Syms* __restrict vlSymsp);
    static void	_eval(VCTE__Syms* __restrict vlSymsp);
    static void	_eval_initial(VCTE__Syms* __restrict vlSymsp);
    static void	_eval_settle(VCTE__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(VCTE__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(VCTE__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(VCTE__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(VCTE__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(VCTE__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
