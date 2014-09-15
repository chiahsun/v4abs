// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VGSIM_H_
#define _VGSIM_H_

#include "verilated.h"
class VGSIM__Syms;

//----------

VL_MODULE(VGSIM) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(in_en,0,0);
    VL_OUT8(out_valid,0,0);
    VL_IN16(b_in,15,0);
    //char	__VpadToAlign6[2];
    VL_OUT(x_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__count,3,0);
    VL_SIG8(v__DOT__next_count,3,0);
    VL_SIG16(v__DOT__loop,9,0);
    VL_SIG16(v__DOT__next_loop,9,0);
    VL_SIG16(v__DOT__inb_0,15,0);
    VL_SIG16(v__DOT__inb_1,15,0);
    VL_SIG16(v__DOT__inb_2,15,0);
    VL_SIG16(v__DOT__inb_3,15,0);
    VL_SIG16(v__DOT__inb_4,15,0);
    VL_SIG16(v__DOT__inb_5,15,0);
    VL_SIG16(v__DOT__inb_6,15,0);
    VL_SIG16(v__DOT__inb_7,15,0);
    VL_SIG16(v__DOT__inb_8,15,0);
    VL_SIG16(v__DOT__inb_9,15,0);
    VL_SIG16(v__DOT__inb_10,15,0);
    VL_SIG16(v__DOT__inb_11,15,0);
    VL_SIG16(v__DOT__inb_12,15,0);
    VL_SIG16(v__DOT__inb_13,15,0);
    VL_SIG16(v__DOT__inb_14,15,0);
    VL_SIG16(v__DOT__inb_15,15,0);
    VL_SIG16(v__DOT__next_inb_0,15,0);
    VL_SIG16(v__DOT__next_inb_1,15,0);
    VL_SIG16(v__DOT__next_inb_2,15,0);
    VL_SIG16(v__DOT__next_inb_3,15,0);
    VL_SIG16(v__DOT__next_inb_4,15,0);
    VL_SIG16(v__DOT__next_inb_5,15,0);
    VL_SIG16(v__DOT__next_inb_6,15,0);
    VL_SIG16(v__DOT__next_inb_7,15,0);
    VL_SIG16(v__DOT__next_inb_8,15,0);
    VL_SIG16(v__DOT__next_inb_9,15,0);
    VL_SIG16(v__DOT__next_inb_10,15,0);
    VL_SIG16(v__DOT__next_inb_11,15,0);
    VL_SIG16(v__DOT__next_inb_12,15,0);
    VL_SIG16(v__DOT__next_inb_13,15,0);
    VL_SIG16(v__DOT__next_inb_14,15,0);
    VL_SIG16(v__DOT__next_inb_15,15,0);
    VL_SIG16(v__DOT__par_b,15,0);
    VL_SIG64(v__DOT__out_0,63,0);
    VL_SIG64(v__DOT__out_1,63,0);
    VL_SIG64(v__DOT__out_2,63,0);
    VL_SIG64(v__DOT__out_3,63,0);
    VL_SIG64(v__DOT__out_4,63,0);
    VL_SIG64(v__DOT__out_5,63,0);
    VL_SIG64(v__DOT__out_6,63,0);
    VL_SIG64(v__DOT__out_7,63,0);
    VL_SIG64(v__DOT__out_8,63,0);
    VL_SIG64(v__DOT__out_9,63,0);
    VL_SIG64(v__DOT__out_10,63,0);
    VL_SIG64(v__DOT__out_11,63,0);
    VL_SIG64(v__DOT__out_12,63,0);
    VL_SIG64(v__DOT__out_13,63,0);
    VL_SIG64(v__DOT__out_14,63,0);
    VL_SIG64(v__DOT__out_15,63,0);
    VL_SIG64(v__DOT__next_out_0,63,0);
    VL_SIG64(v__DOT__next_out_1,63,0);
    VL_SIG64(v__DOT__next_out_2,63,0);
    VL_SIG64(v__DOT__next_out_3,63,0);
    VL_SIG64(v__DOT__next_out_4,63,0);
    VL_SIG64(v__DOT__next_out_5,63,0);
    VL_SIG64(v__DOT__next_out_6,63,0);
    VL_SIG64(v__DOT__next_out_7,63,0);
    VL_SIG64(v__DOT__next_out_8,63,0);
    VL_SIG64(v__DOT__next_out_9,63,0);
    VL_SIG64(v__DOT__next_out_10,63,0);
    VL_SIG64(v__DOT__next_out_11,63,0);
    VL_SIG64(v__DOT__next_out_12,63,0);
    VL_SIG64(v__DOT__next_out_13,63,0);
    VL_SIG64(v__DOT__next_out_14,63,0);
    VL_SIG64(v__DOT__next_out_15,63,0);
    VL_SIG64(v__DOT__par_0,63,0);
    VL_SIG64(v__DOT__par_1,63,0);
    VL_SIG64(v__DOT__par_2,63,0);
    VL_SIG64(v__DOT__par_3,63,0);
    VL_SIG64(v__DOT__par_4,63,0);
    VL_SIG64(v__DOT__par_5,63,0);
    VL_SIG64(v__DOT__cal0__DOT__comb_1,63,0);
    VL_SIG64(v__DOT__cal0__DOT__comb_2,63,0);
    VL_SIG64(v__DOT__cal0__DOT__add_tmp,63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    //char	__VpadToAlign422[2];
    VL_SIG64(__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp,63,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign436[4];
    VGSIM__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VGSIM& operator= (const VGSIM&);	///< Copying not allowed
    VGSIM(const VGSIM&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VGSIM(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VGSIM();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VGSIM__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VGSIM__Syms* symsp, bool first);
  private:
    static QData	_change_request(VGSIM__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__2(VGSIM__Syms* __restrict vlSymsp);
    static void	_combo__TOP__4(VGSIM__Syms* __restrict vlSymsp);
    static void	_eval(VGSIM__Syms* __restrict vlSymsp);
    static void	_eval_initial(VGSIM__Syms* __restrict vlSymsp);
    static void	_eval_settle(VGSIM__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VGSIM__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(VGSIM__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(VGSIM__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
