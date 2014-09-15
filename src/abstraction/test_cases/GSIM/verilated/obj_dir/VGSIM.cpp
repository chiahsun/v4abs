// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGSIM.h for the primary calling header

#include "VGSIM.h"             // For This
#include "VGSIM__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VGSIM) {
    VGSIM__Syms* __restrict vlSymsp = __VlSymsp = new VGSIM__Syms(this, name());
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    in_en = VL_RAND_RESET_I(1);
    out_valid = VL_RAND_RESET_I(1);
    b_in = VL_RAND_RESET_I(16);
    x_out = VL_RAND_RESET_I(32);
    v__DOT__count = VL_RAND_RESET_I(4);
    v__DOT__loop = VL_RAND_RESET_I(10);
    v__DOT__next_count = VL_RAND_RESET_I(4);
    v__DOT__next_loop = VL_RAND_RESET_I(10);
    v__DOT__inb_0 = VL_RAND_RESET_I(16);
    v__DOT__inb_1 = VL_RAND_RESET_I(16);
    v__DOT__inb_2 = VL_RAND_RESET_I(16);
    v__DOT__inb_3 = VL_RAND_RESET_I(16);
    v__DOT__inb_4 = VL_RAND_RESET_I(16);
    v__DOT__inb_5 = VL_RAND_RESET_I(16);
    v__DOT__inb_6 = VL_RAND_RESET_I(16);
    v__DOT__inb_7 = VL_RAND_RESET_I(16);
    v__DOT__inb_8 = VL_RAND_RESET_I(16);
    v__DOT__inb_9 = VL_RAND_RESET_I(16);
    v__DOT__inb_10 = VL_RAND_RESET_I(16);
    v__DOT__inb_11 = VL_RAND_RESET_I(16);
    v__DOT__inb_12 = VL_RAND_RESET_I(16);
    v__DOT__inb_13 = VL_RAND_RESET_I(16);
    v__DOT__inb_14 = VL_RAND_RESET_I(16);
    v__DOT__inb_15 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_0 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_1 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_2 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_3 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_4 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_5 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_6 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_7 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_8 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_9 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_10 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_11 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_12 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_13 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_14 = VL_RAND_RESET_I(16);
    v__DOT__next_inb_15 = VL_RAND_RESET_I(16);
    v__DOT__out_0 = VL_RAND_RESET_Q(64);
    v__DOT__out_1 = VL_RAND_RESET_Q(64);
    v__DOT__out_2 = VL_RAND_RESET_Q(64);
    v__DOT__out_3 = VL_RAND_RESET_Q(64);
    v__DOT__out_4 = VL_RAND_RESET_Q(64);
    v__DOT__out_5 = VL_RAND_RESET_Q(64);
    v__DOT__out_6 = VL_RAND_RESET_Q(64);
    v__DOT__out_7 = VL_RAND_RESET_Q(64);
    v__DOT__out_8 = VL_RAND_RESET_Q(64);
    v__DOT__out_9 = VL_RAND_RESET_Q(64);
    v__DOT__out_10 = VL_RAND_RESET_Q(64);
    v__DOT__out_11 = VL_RAND_RESET_Q(64);
    v__DOT__out_12 = VL_RAND_RESET_Q(64);
    v__DOT__out_13 = VL_RAND_RESET_Q(64);
    v__DOT__out_14 = VL_RAND_RESET_Q(64);
    v__DOT__out_15 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_0 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_1 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_2 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_3 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_4 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_5 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_6 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_7 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_8 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_9 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_10 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_11 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_12 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_13 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_14 = VL_RAND_RESET_Q(64);
    v__DOT__next_out_15 = VL_RAND_RESET_Q(64);
    v__DOT__par_0 = VL_RAND_RESET_Q(64);
    v__DOT__par_1 = VL_RAND_RESET_Q(64);
    v__DOT__par_2 = VL_RAND_RESET_Q(64);
    v__DOT__par_3 = VL_RAND_RESET_Q(64);
    v__DOT__par_4 = VL_RAND_RESET_Q(64);
    v__DOT__par_5 = VL_RAND_RESET_Q(64);
    v__DOT__par_b = VL_RAND_RESET_I(16);
    v__DOT__cal0__DOT__comb_1 = VL_RAND_RESET_Q(64);
    v__DOT__cal0__DOT__comb_2 = VL_RAND_RESET_Q(64);
    v__DOT__cal0__DOT__add_tmp = VL_RAND_RESET_Q(64);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__cal0__DOT__add_tmp = VL_RAND_RESET_Q(64);
}

void VGSIM::__Vconfigure(VGSIM__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VGSIM::~VGSIM() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VGSIM::eval() {
    VGSIM__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VGSIM::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VGSIM::_eval_initial_loop(VGSIM__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void VGSIM::_sequent__TOP__1(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_sequent__TOP__1\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../GSIM.v:244
    if (vlTOPp->reset) {
	vlTOPp->v__DOT__count = 0U;
	vlTOPp->v__DOT__loop = 0U;
	vlTOPp->v__DOT__inb_0 = 0U;
	vlTOPp->v__DOT__inb_1 = 0U;
	vlTOPp->v__DOT__inb_2 = 0U;
	vlTOPp->v__DOT__inb_3 = 0U;
	vlTOPp->v__DOT__inb_4 = 0U;
	vlTOPp->v__DOT__inb_5 = 0U;
	vlTOPp->v__DOT__inb_6 = 0U;
	vlTOPp->v__DOT__inb_7 = 0U;
	vlTOPp->v__DOT__inb_8 = 0U;
	vlTOPp->v__DOT__inb_9 = 0U;
	vlTOPp->v__DOT__inb_10 = 0U;
	vlTOPp->v__DOT__inb_11 = 0U;
	vlTOPp->v__DOT__inb_12 = 0U;
	vlTOPp->v__DOT__inb_13 = 0U;
	vlTOPp->v__DOT__inb_14 = 0U;
	vlTOPp->v__DOT__inb_15 = 0U;
	vlTOPp->v__DOT__out_0 = VL_ULL(0);
	vlTOPp->v__DOT__out_1 = VL_ULL(0);
	vlTOPp->v__DOT__out_2 = VL_ULL(0);
	vlTOPp->v__DOT__out_3 = VL_ULL(0);
	vlTOPp->v__DOT__out_4 = VL_ULL(0);
	vlTOPp->v__DOT__out_5 = VL_ULL(0);
	vlTOPp->v__DOT__out_6 = VL_ULL(0);
	vlTOPp->v__DOT__out_7 = VL_ULL(0);
	vlTOPp->v__DOT__out_8 = VL_ULL(0);
	vlTOPp->v__DOT__out_9 = VL_ULL(0);
	vlTOPp->v__DOT__out_10 = VL_ULL(0);
	vlTOPp->v__DOT__out_11 = VL_ULL(0);
	vlTOPp->v__DOT__out_12 = VL_ULL(0);
	vlTOPp->v__DOT__out_13 = VL_ULL(0);
	vlTOPp->v__DOT__out_14 = VL_ULL(0);
	vlTOPp->v__DOT__out_15 = VL_ULL(0);
    } else {
	vlTOPp->v__DOT__count = vlTOPp->v__DOT__next_count;
	vlTOPp->v__DOT__loop = vlTOPp->v__DOT__next_loop;
	vlTOPp->v__DOT__inb_0 = vlTOPp->v__DOT__next_inb_0;
	vlTOPp->v__DOT__inb_1 = vlTOPp->v__DOT__next_inb_1;
	vlTOPp->v__DOT__inb_2 = vlTOPp->v__DOT__next_inb_2;
	vlTOPp->v__DOT__inb_3 = vlTOPp->v__DOT__next_inb_3;
	vlTOPp->v__DOT__inb_4 = vlTOPp->v__DOT__next_inb_4;
	vlTOPp->v__DOT__inb_5 = vlTOPp->v__DOT__next_inb_5;
	vlTOPp->v__DOT__inb_6 = vlTOPp->v__DOT__next_inb_6;
	vlTOPp->v__DOT__inb_7 = vlTOPp->v__DOT__next_inb_7;
	vlTOPp->v__DOT__inb_8 = vlTOPp->v__DOT__next_inb_8;
	vlTOPp->v__DOT__inb_9 = vlTOPp->v__DOT__next_inb_9;
	vlTOPp->v__DOT__inb_10 = vlTOPp->v__DOT__next_inb_10;
	vlTOPp->v__DOT__inb_11 = vlTOPp->v__DOT__next_inb_11;
	vlTOPp->v__DOT__inb_12 = vlTOPp->v__DOT__next_inb_12;
	vlTOPp->v__DOT__inb_13 = vlTOPp->v__DOT__next_inb_13;
	vlTOPp->v__DOT__inb_14 = vlTOPp->v__DOT__next_inb_14;
	vlTOPp->v__DOT__inb_15 = vlTOPp->v__DOT__next_inb_15;
	vlTOPp->v__DOT__out_0 = vlTOPp->v__DOT__next_out_0;
	vlTOPp->v__DOT__out_1 = vlTOPp->v__DOT__next_out_1;
	vlTOPp->v__DOT__out_2 = vlTOPp->v__DOT__next_out_2;
	vlTOPp->v__DOT__out_3 = vlTOPp->v__DOT__next_out_3;
	vlTOPp->v__DOT__out_4 = vlTOPp->v__DOT__next_out_4;
	vlTOPp->v__DOT__out_5 = vlTOPp->v__DOT__next_out_5;
	vlTOPp->v__DOT__out_6 = vlTOPp->v__DOT__next_out_6;
	vlTOPp->v__DOT__out_7 = vlTOPp->v__DOT__next_out_7;
	vlTOPp->v__DOT__out_8 = vlTOPp->v__DOT__next_out_8;
	vlTOPp->v__DOT__out_9 = vlTOPp->v__DOT__next_out_9;
	vlTOPp->v__DOT__out_10 = vlTOPp->v__DOT__next_out_10;
	vlTOPp->v__DOT__out_11 = vlTOPp->v__DOT__next_out_11;
	vlTOPp->v__DOT__out_12 = vlTOPp->v__DOT__next_out_12;
	vlTOPp->v__DOT__out_13 = vlTOPp->v__DOT__next_out_13;
	vlTOPp->v__DOT__out_14 = vlTOPp->v__DOT__next_out_14;
	vlTOPp->v__DOT__out_15 = vlTOPp->v__DOT__next_out_15;
    }
}

void VGSIM::_combo__TOP__2(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_combo__TOP__2\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,95,0,3);
    //char	__VpadToAlign36[4];
    VL_SIGW(__Vtemp3,95,0,3);
    //char	__VpadToAlign52[4];
    VL_SIGW(__Vtemp5,95,0,3);
    //char	__VpadToAlign68[4];
    VL_SIGW(__Vtemp6,95,0,3);
    //char	__VpadToAlign84[4];
    VL_SIGW(__Vtemp7,95,0,3);
    //char	__VpadToAlign100[4];
    VL_SIGW(__Vtemp9,95,0,3);
    //char	__VpadToAlign116[4];
    VL_SIGW(__Vtemp11,95,0,3);
    //char	__VpadToAlign132[4];
    VL_SIGW(__Vtemp12,95,0,3);
    //char	__VpadToAlign148[4];
    VL_SIGW(__Vtemp13,95,0,3);
    //char	__VpadToAlign164[4];
    VL_SIGW(__Vtemp15,95,0,3);
    //char	__VpadToAlign180[4];
    VL_SIGW(__Vtemp17,95,0,3);
    //char	__VpadToAlign196[4];
    VL_SIGW(__Vtemp18,95,0,3);
    //char	__VpadToAlign212[4];
    VL_SIGW(__Vtemp19,95,0,3);
    //char	__VpadToAlign228[4];
    VL_SIGW(__Vtemp21,95,0,3);
    //char	__VpadToAlign244[4];
    VL_SIGW(__Vtemp23,95,0,3);
    //char	__VpadToAlign260[4];
    VL_SIGW(__Vtemp24,95,0,3);
    //char	__VpadToAlign276[4];
    VL_SIGW(__Vtemp25,95,0,3);
    //char	__VpadToAlign292[4];
    VL_SIGW(__Vtemp27,95,0,3);
    //char	__VpadToAlign308[4];
    VL_SIGW(__Vtemp29,95,0,3);
    //char	__VpadToAlign324[4];
    VL_SIGW(__Vtemp30,95,0,3);
    //char	__VpadToAlign340[4];
    VL_SIGW(__Vtemp31,95,0,3);
    //char	__VpadToAlign356[4];
    VL_SIGW(__Vtemp33,95,0,3);
    //char	__VpadToAlign372[4];
    VL_SIGW(__Vtemp35,95,0,3);
    //char	__VpadToAlign388[4];
    VL_SIGW(__Vtemp36,95,0,3);
    //char	__VpadToAlign404[4];
    VL_SIGW(__Vtemp37,95,0,3);
    //char	__VpadToAlign420[4];
    VL_SIGW(__Vtemp39,95,0,3);
    //char	__VpadToAlign436[4];
    VL_SIGW(__Vtemp41,95,0,3);
    //char	__VpadToAlign452[4];
    VL_SIGW(__Vtemp42,95,0,3);
    //char	__VpadToAlign468[4];
    VL_SIGW(__Vtemp43,95,0,3);
    //char	__VpadToAlign484[4];
    VL_SIGW(__Vtemp45,95,0,3);
    //char	__VpadToAlign500[4];
    VL_SIGW(__Vtemp47,95,0,3);
    //char	__VpadToAlign516[4];
    VL_SIGW(__Vtemp48,95,0,3);
    //char	__VpadToAlign532[4];
    VL_SIGW(__Vtemp49,95,0,3);
    //char	__VpadToAlign548[4];
    VL_SIGW(__Vtemp51,95,0,3);
    //char	__VpadToAlign564[4];
    VL_SIGW(__Vtemp53,95,0,3);
    //char	__VpadToAlign580[4];
    VL_SIGW(__Vtemp54,95,0,3);
    //char	__VpadToAlign596[4];
    VL_SIGW(__Vtemp55,95,0,3);
    //char	__VpadToAlign612[4];
    VL_SIGW(__Vtemp57,95,0,3);
    //char	__VpadToAlign628[4];
    VL_SIGW(__Vtemp59,95,0,3);
    //char	__VpadToAlign644[4];
    VL_SIGW(__Vtemp60,95,0,3);
    //char	__VpadToAlign660[4];
    VL_SIGW(__Vtemp61,95,0,3);
    //char	__VpadToAlign676[4];
    VL_SIGW(__Vtemp63,95,0,3);
    //char	__VpadToAlign692[4];
    VL_SIGW(__Vtemp65,95,0,3);
    //char	__VpadToAlign708[4];
    VL_SIGW(__Vtemp66,95,0,3);
    //char	__VpadToAlign724[4];
    VL_SIGW(__Vtemp67,95,0,3);
    //char	__VpadToAlign740[4];
    VL_SIGW(__Vtemp69,95,0,3);
    //char	__VpadToAlign756[4];
    VL_SIGW(__Vtemp71,95,0,3);
    //char	__VpadToAlign772[4];
    VL_SIGW(__Vtemp72,95,0,3);
    //char	__VpadToAlign788[4];
    VL_SIGW(__Vtemp73,95,0,3);
    //char	__VpadToAlign804[4];
    VL_SIGW(__Vtemp75,95,0,3);
    //char	__VpadToAlign820[4];
    VL_SIGW(__Vtemp77,95,0,3);
    //char	__VpadToAlign836[4];
    VL_SIGW(__Vtemp78,95,0,3);
    //char	__VpadToAlign852[4];
    VL_SIGW(__Vtemp79,95,0,3);
    //char	__VpadToAlign868[4];
    VL_SIGW(__Vtemp81,95,0,3);
    //char	__VpadToAlign884[4];
    VL_SIGW(__Vtemp83,95,0,3);
    //char	__VpadToAlign900[4];
    VL_SIGW(__Vtemp84,95,0,3);
    //char	__VpadToAlign916[4];
    VL_SIGW(__Vtemp85,95,0,3);
    //char	__VpadToAlign932[4];
    VL_SIGW(__Vtemp87,95,0,3);
    //char	__VpadToAlign948[4];
    VL_SIGW(__Vtemp89,95,0,3);
    //char	__VpadToAlign964[4];
    VL_SIGW(__Vtemp90,95,0,3);
    //char	__VpadToAlign980[4];
    VL_SIGW(__Vtemp91,95,0,3);
    //char	__VpadToAlign996[4];
    VL_SIGW(__Vtemp93,95,0,3);
    //char	__VpadToAlign1012[4];
    VL_SIGW(__Vtemp95,95,0,3);
    //char	__VpadToAlign1028[4];
    VL_SIGW(__Vtemp96,95,0,3);
    // Body
    // ALWAYS at ../GSIM.v:137
    if (vlTOPp->reset) {
	vlTOPp->v__DOT__next_count = 0U;
	vlTOPp->v__DOT__next_loop = 0U;
	vlTOPp->v__DOT__next_inb_0 = 0U;
	vlTOPp->v__DOT__next_inb_1 = 0U;
	vlTOPp->v__DOT__next_inb_2 = 0U;
	vlTOPp->v__DOT__next_inb_3 = 0U;
	vlTOPp->v__DOT__next_inb_4 = 0U;
	vlTOPp->v__DOT__next_inb_5 = 0U;
	vlTOPp->v__DOT__next_inb_6 = 0U;
	vlTOPp->v__DOT__next_inb_7 = 0U;
	vlTOPp->v__DOT__next_inb_8 = 0U;
	vlTOPp->v__DOT__next_inb_9 = 0U;
	vlTOPp->v__DOT__next_inb_10 = 0U;
	vlTOPp->v__DOT__next_inb_11 = 0U;
	vlTOPp->v__DOT__next_inb_12 = 0U;
	vlTOPp->v__DOT__next_inb_13 = 0U;
	vlTOPp->v__DOT__next_inb_14 = 0U;
	vlTOPp->v__DOT__next_inb_15 = 0U;
	vlTOPp->v__DOT__next_out_0 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_1 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_2 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_3 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_4 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_5 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_6 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_7 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_8 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_9 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_10 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_11 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_12 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_13 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_14 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_15 = VL_ULL(0);
	vlTOPp->v__DOT__par_0 = VL_ULL(0);
	vlTOPp->v__DOT__par_1 = VL_ULL(0);
	vlTOPp->v__DOT__par_2 = VL_ULL(0);
	vlTOPp->v__DOT__par_3 = VL_ULL(0);
	vlTOPp->v__DOT__par_4 = VL_ULL(0);
	vlTOPp->v__DOT__par_5 = VL_ULL(0);
	vlTOPp->v__DOT__par_b = 0U;
	vlTOPp->out_valid = 0U;
	vlTOPp->x_out = 0U;
    } else {
	vlTOPp->v__DOT__next_count = (0xfU & ((IData)(vlTOPp->in_en)
					       ? 0U
					       : ((IData)(1U) 
						  + (IData)(vlTOPp->v__DOT__count))));
	vlTOPp->v__DOT__next_loop = (0x3ffU & ((0xfU 
						== (IData)(vlTOPp->v__DOT__count))
					        ? ((IData)(1U) 
						   + (IData)(vlTOPp->v__DOT__loop))
					        : (IData)(vlTOPp->v__DOT__loop)));
	vlTOPp->v__DOT__next_inb_0 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_1)
				       : (IData)(vlTOPp->v__DOT__inb_0));
	vlTOPp->v__DOT__next_inb_1 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_2)
				       : (IData)(vlTOPp->v__DOT__inb_1));
	vlTOPp->v__DOT__next_inb_2 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_3)
				       : (IData)(vlTOPp->v__DOT__inb_2));
	vlTOPp->v__DOT__next_inb_3 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_4)
				       : (IData)(vlTOPp->v__DOT__inb_3));
	vlTOPp->v__DOT__next_inb_4 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_5)
				       : (IData)(vlTOPp->v__DOT__inb_4));
	vlTOPp->v__DOT__next_inb_5 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_6)
				       : (IData)(vlTOPp->v__DOT__inb_5));
	vlTOPp->v__DOT__next_inb_6 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_7)
				       : (IData)(vlTOPp->v__DOT__inb_6));
	vlTOPp->v__DOT__next_inb_7 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_8)
				       : (IData)(vlTOPp->v__DOT__inb_7));
	vlTOPp->v__DOT__next_inb_8 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_9)
				       : (IData)(vlTOPp->v__DOT__inb_8));
	vlTOPp->v__DOT__next_inb_9 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_10)
				       : (IData)(vlTOPp->v__DOT__inb_9));
	vlTOPp->v__DOT__next_inb_10 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_11)
				        : (IData)(vlTOPp->v__DOT__inb_10));
	vlTOPp->v__DOT__next_inb_11 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_12)
				        : (IData)(vlTOPp->v__DOT__inb_11));
	vlTOPp->v__DOT__next_inb_12 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_13)
				        : (IData)(vlTOPp->v__DOT__inb_12));
	vlTOPp->v__DOT__next_inb_13 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_14)
				        : (IData)(vlTOPp->v__DOT__inb_13));
	vlTOPp->v__DOT__next_inb_14 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_15)
				        : (IData)(vlTOPp->v__DOT__inb_14));
	vlTOPp->v__DOT__next_inb_15 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->b_in)
				        : (IData)(vlTOPp->v__DOT__inb_15));
	__Vtemp1[0U] = 0xccccccdU;
	__Vtemp1[1U] = 0U;
	__Vtemp1[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp3, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp5[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				       >> 0x3fU))) ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			 : __Vtemp3[0U]);
	__Vtemp5[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				       >> 0x3fU))) ? (IData)(
							     (vlTOPp->v__DOT__cal0__DOT__add_tmp 
							      >> 0x20U))
			 : __Vtemp3[1U]);
	__Vtemp5[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				       >> 0x3fU))) ? 0xffffffffU
			 : __Vtemp3[2U]);
	VL_MUL_W(3, __Vtemp6, __Vtemp1, __Vtemp5);
	vlTOPp->v__DOT__next_out_0 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_1
				       : ((0U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp6[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp6[1U])))
					   : vlTOPp->v__DOT__out_0));
	__Vtemp7[0U] = 0xccccccdU;
	__Vtemp7[1U] = 0U;
	__Vtemp7[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp9, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp11[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp9[0U]);
	__Vtemp11[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp9[1U]);
	__Vtemp11[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp9[2U]);
	VL_MUL_W(3, __Vtemp12, __Vtemp7, __Vtemp11);
	vlTOPp->v__DOT__next_out_1 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_2
				       : ((1U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp12[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp12[1U])))
					   : vlTOPp->v__DOT__out_1));
	__Vtemp13[0U] = 0xccccccdU;
	__Vtemp13[1U] = 0U;
	__Vtemp13[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp15, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp17[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp15[0U]);
	__Vtemp17[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp15[1U]);
	__Vtemp17[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp15[2U]);
	VL_MUL_W(3, __Vtemp18, __Vtemp13, __Vtemp17);
	vlTOPp->v__DOT__next_out_2 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_3
				       : ((2U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp18[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp18[1U])))
					   : vlTOPp->v__DOT__out_2));
	__Vtemp19[0U] = 0xccccccdU;
	__Vtemp19[1U] = 0U;
	__Vtemp19[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp21, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp23[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp21[0U]);
	__Vtemp23[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp21[1U]);
	__Vtemp23[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp21[2U]);
	VL_MUL_W(3, __Vtemp24, __Vtemp19, __Vtemp23);
	vlTOPp->v__DOT__next_out_3 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_4
				       : ((3U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp24[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp24[1U])))
					   : vlTOPp->v__DOT__out_3));
	__Vtemp25[0U] = 0xccccccdU;
	__Vtemp25[1U] = 0U;
	__Vtemp25[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp27, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp29[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp27[0U]);
	__Vtemp29[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp27[1U]);
	__Vtemp29[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp27[2U]);
	VL_MUL_W(3, __Vtemp30, __Vtemp25, __Vtemp29);
	vlTOPp->v__DOT__next_out_4 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_5
				       : ((4U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp30[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp30[1U])))
					   : vlTOPp->v__DOT__out_4));
	__Vtemp31[0U] = 0xccccccdU;
	__Vtemp31[1U] = 0U;
	__Vtemp31[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp33, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp35[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp33[0U]);
	__Vtemp35[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp33[1U]);
	__Vtemp35[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp33[2U]);
	VL_MUL_W(3, __Vtemp36, __Vtemp31, __Vtemp35);
	vlTOPp->v__DOT__next_out_5 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_6
				       : ((5U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp36[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp36[1U])))
					   : vlTOPp->v__DOT__out_5));
	__Vtemp37[0U] = 0xccccccdU;
	__Vtemp37[1U] = 0U;
	__Vtemp37[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp39, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp41[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp39[0U]);
	__Vtemp41[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp39[1U]);
	__Vtemp41[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp39[2U]);
	VL_MUL_W(3, __Vtemp42, __Vtemp37, __Vtemp41);
	vlTOPp->v__DOT__next_out_6 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_7
				       : ((6U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp42[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp42[1U])))
					   : vlTOPp->v__DOT__out_6));
	__Vtemp43[0U] = 0xccccccdU;
	__Vtemp43[1U] = 0U;
	__Vtemp43[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp45, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp47[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp45[0U]);
	__Vtemp47[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp45[1U]);
	__Vtemp47[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp45[2U]);
	VL_MUL_W(3, __Vtemp48, __Vtemp43, __Vtemp47);
	vlTOPp->v__DOT__next_out_7 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_8
				       : ((7U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp48[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp48[1U])))
					   : vlTOPp->v__DOT__out_7));
	__Vtemp49[0U] = 0xccccccdU;
	__Vtemp49[1U] = 0U;
	__Vtemp49[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp51, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp53[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp51[0U]);
	__Vtemp53[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp51[1U]);
	__Vtemp53[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp51[2U]);
	VL_MUL_W(3, __Vtemp54, __Vtemp49, __Vtemp53);
	vlTOPp->v__DOT__next_out_8 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_9
				       : ((8U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp54[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp54[1U])))
					   : vlTOPp->v__DOT__out_8));
	__Vtemp55[0U] = 0xccccccdU;
	__Vtemp55[1U] = 0U;
	__Vtemp55[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp57, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp59[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp57[0U]);
	__Vtemp59[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp57[1U]);
	__Vtemp59[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp57[2U]);
	VL_MUL_W(3, __Vtemp60, __Vtemp55, __Vtemp59);
	vlTOPp->v__DOT__next_out_9 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_10
				       : ((9U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp60[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp60[1U])))
					   : vlTOPp->v__DOT__out_9));
	__Vtemp61[0U] = 0xccccccdU;
	__Vtemp61[1U] = 0U;
	__Vtemp61[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp63, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp65[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp63[0U]);
	__Vtemp65[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp63[1U]);
	__Vtemp65[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp63[2U]);
	VL_MUL_W(3, __Vtemp66, __Vtemp61, __Vtemp65);
	vlTOPp->v__DOT__next_out_10 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_11
				        : ((0xaU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp66[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp66[1U])))
					    : vlTOPp->v__DOT__out_10));
	__Vtemp67[0U] = 0xccccccdU;
	__Vtemp67[1U] = 0U;
	__Vtemp67[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp69, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp71[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp69[0U]);
	__Vtemp71[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp69[1U]);
	__Vtemp71[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp69[2U]);
	VL_MUL_W(3, __Vtemp72, __Vtemp67, __Vtemp71);
	vlTOPp->v__DOT__next_out_11 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_12
				        : ((0xbU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp72[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp72[1U])))
					    : vlTOPp->v__DOT__out_11));
	__Vtemp73[0U] = 0xccccccdU;
	__Vtemp73[1U] = 0U;
	__Vtemp73[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp75, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp77[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp75[0U]);
	__Vtemp77[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp75[1U]);
	__Vtemp77[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp75[2U]);
	VL_MUL_W(3, __Vtemp78, __Vtemp73, __Vtemp77);
	vlTOPp->v__DOT__next_out_12 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_13
				        : ((0xcU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp78[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp78[1U])))
					    : vlTOPp->v__DOT__out_12));
	__Vtemp79[0U] = 0xccccccdU;
	__Vtemp79[1U] = 0U;
	__Vtemp79[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp81, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp83[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp81[0U]);
	__Vtemp83[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp81[1U]);
	__Vtemp83[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp81[2U]);
	VL_MUL_W(3, __Vtemp84, __Vtemp79, __Vtemp83);
	vlTOPp->v__DOT__next_out_13 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_14
				        : ((0xdU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp84[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp84[1U])))
					    : vlTOPp->v__DOT__out_13));
	__Vtemp85[0U] = 0xccccccdU;
	__Vtemp85[1U] = 0U;
	__Vtemp85[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp87, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp89[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp87[0U]);
	__Vtemp89[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp87[1U]);
	__Vtemp89[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp87[2U]);
	VL_MUL_W(3, __Vtemp90, __Vtemp85, __Vtemp89);
	vlTOPp->v__DOT__next_out_14 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_15
				        : ((0xeU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp90[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp90[1U])))
					    : vlTOPp->v__DOT__out_14));
	__Vtemp91[0U] = 0xccccccdU;
	__Vtemp91[1U] = 0U;
	__Vtemp91[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp93, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp95[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			  : __Vtemp93[0U]);
	__Vtemp95[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				     >> 0x20U)) : __Vtemp93[1U]);
	__Vtemp95[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					>> 0x3fU)))
			  ? 0xffffffffU : __Vtemp93[2U]);
	VL_MUL_W(3, __Vtemp96, __Vtemp91, __Vtemp95);
	vlTOPp->v__DOT__next_out_15 = ((IData)(vlTOPp->in_en)
				        ? ((0x8000U 
					    & (IData)(vlTOPp->b_in))
					    ? ((QData)((IData)(
							       (0xfffff000U 
								| (0xfffU 
								   & ((IData)(vlTOPp->b_in) 
								      >> 4U))))) 
					       << 0x20U)
					    : ((QData)((IData)(
							       (0xfffU 
								& ((IData)(vlTOPp->b_in) 
								   >> 4U)))) 
					       << 0x20U))
				        : ((0xfU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp96[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp96[1U])))
					    : vlTOPp->v__DOT__out_15));
	if ((8U & (IData)(vlTOPp->v__DOT__count))) {
	    if ((4U & (IData)(vlTOPp->v__DOT__count))) {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_3 = VL_ULL(0);
			vlTOPp->v__DOT__par_4 = VL_ULL(0);
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_15;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_15 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_4 = VL_ULL(0);
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_14;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_14 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_13;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_13 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_12;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_12 
						 >> 0x10U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_11;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_11 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_10;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_10 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_9;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_9 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_8;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_8 
						 >> 0x10U));
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->v__DOT__count))) {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_7;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_7 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_6;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_6 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_5;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_5 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_4;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_4 
						 >> 0x10U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_3;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_3 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_2;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_2 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = VL_ULL(0);
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_1;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_1 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = VL_ULL(0);
			vlTOPp->v__DOT__par_2 = VL_ULL(0);
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_0;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_0 
						 >> 0x10U));
		    }
		}
	    }
	}
	vlTOPp->out_valid = (1U & ((IData)(vlTOPp->v__DOT__loop) 
				   >> 9U));
    }
}

void VGSIM::_settle__TOP__3(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_settle__TOP__3\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp97,95,0,3);
    //char	__VpadToAlign1076[4];
    VL_SIGW(__Vtemp99,95,0,3);
    //char	__VpadToAlign1092[4];
    VL_SIGW(__Vtemp101,95,0,3);
    //char	__VpadToAlign1108[4];
    VL_SIGW(__Vtemp102,95,0,3);
    //char	__VpadToAlign1124[4];
    VL_SIGW(__Vtemp103,95,0,3);
    //char	__VpadToAlign1140[4];
    VL_SIGW(__Vtemp105,95,0,3);
    //char	__VpadToAlign1156[4];
    VL_SIGW(__Vtemp107,95,0,3);
    //char	__VpadToAlign1172[4];
    VL_SIGW(__Vtemp108,95,0,3);
    //char	__VpadToAlign1188[4];
    VL_SIGW(__Vtemp109,95,0,3);
    //char	__VpadToAlign1204[4];
    VL_SIGW(__Vtemp111,95,0,3);
    //char	__VpadToAlign1220[4];
    VL_SIGW(__Vtemp113,95,0,3);
    //char	__VpadToAlign1236[4];
    VL_SIGW(__Vtemp114,95,0,3);
    //char	__VpadToAlign1252[4];
    VL_SIGW(__Vtemp115,95,0,3);
    //char	__VpadToAlign1268[4];
    VL_SIGW(__Vtemp117,95,0,3);
    //char	__VpadToAlign1284[4];
    VL_SIGW(__Vtemp119,95,0,3);
    //char	__VpadToAlign1300[4];
    VL_SIGW(__Vtemp120,95,0,3);
    //char	__VpadToAlign1316[4];
    VL_SIGW(__Vtemp121,95,0,3);
    //char	__VpadToAlign1332[4];
    VL_SIGW(__Vtemp123,95,0,3);
    //char	__VpadToAlign1348[4];
    VL_SIGW(__Vtemp125,95,0,3);
    //char	__VpadToAlign1364[4];
    VL_SIGW(__Vtemp126,95,0,3);
    //char	__VpadToAlign1380[4];
    VL_SIGW(__Vtemp127,95,0,3);
    //char	__VpadToAlign1396[4];
    VL_SIGW(__Vtemp129,95,0,3);
    //char	__VpadToAlign1412[4];
    VL_SIGW(__Vtemp131,95,0,3);
    //char	__VpadToAlign1428[4];
    VL_SIGW(__Vtemp132,95,0,3);
    //char	__VpadToAlign1444[4];
    VL_SIGW(__Vtemp133,95,0,3);
    //char	__VpadToAlign1460[4];
    VL_SIGW(__Vtemp135,95,0,3);
    //char	__VpadToAlign1476[4];
    VL_SIGW(__Vtemp137,95,0,3);
    //char	__VpadToAlign1492[4];
    VL_SIGW(__Vtemp138,95,0,3);
    //char	__VpadToAlign1508[4];
    VL_SIGW(__Vtemp139,95,0,3);
    //char	__VpadToAlign1524[4];
    VL_SIGW(__Vtemp141,95,0,3);
    //char	__VpadToAlign1540[4];
    VL_SIGW(__Vtemp143,95,0,3);
    //char	__VpadToAlign1556[4];
    VL_SIGW(__Vtemp144,95,0,3);
    //char	__VpadToAlign1572[4];
    VL_SIGW(__Vtemp145,95,0,3);
    //char	__VpadToAlign1588[4];
    VL_SIGW(__Vtemp147,95,0,3);
    //char	__VpadToAlign1604[4];
    VL_SIGW(__Vtemp149,95,0,3);
    //char	__VpadToAlign1620[4];
    VL_SIGW(__Vtemp150,95,0,3);
    //char	__VpadToAlign1636[4];
    VL_SIGW(__Vtemp151,95,0,3);
    //char	__VpadToAlign1652[4];
    VL_SIGW(__Vtemp153,95,0,3);
    //char	__VpadToAlign1668[4];
    VL_SIGW(__Vtemp155,95,0,3);
    //char	__VpadToAlign1684[4];
    VL_SIGW(__Vtemp156,95,0,3);
    //char	__VpadToAlign1700[4];
    VL_SIGW(__Vtemp157,95,0,3);
    //char	__VpadToAlign1716[4];
    VL_SIGW(__Vtemp159,95,0,3);
    //char	__VpadToAlign1732[4];
    VL_SIGW(__Vtemp161,95,0,3);
    //char	__VpadToAlign1748[4];
    VL_SIGW(__Vtemp162,95,0,3);
    //char	__VpadToAlign1764[4];
    VL_SIGW(__Vtemp163,95,0,3);
    //char	__VpadToAlign1780[4];
    VL_SIGW(__Vtemp165,95,0,3);
    //char	__VpadToAlign1796[4];
    VL_SIGW(__Vtemp167,95,0,3);
    //char	__VpadToAlign1812[4];
    VL_SIGW(__Vtemp168,95,0,3);
    //char	__VpadToAlign1828[4];
    VL_SIGW(__Vtemp169,95,0,3);
    //char	__VpadToAlign1844[4];
    VL_SIGW(__Vtemp171,95,0,3);
    //char	__VpadToAlign1860[4];
    VL_SIGW(__Vtemp173,95,0,3);
    //char	__VpadToAlign1876[4];
    VL_SIGW(__Vtemp174,95,0,3);
    //char	__VpadToAlign1892[4];
    VL_SIGW(__Vtemp175,95,0,3);
    //char	__VpadToAlign1908[4];
    VL_SIGW(__Vtemp177,95,0,3);
    //char	__VpadToAlign1924[4];
    VL_SIGW(__Vtemp179,95,0,3);
    //char	__VpadToAlign1940[4];
    VL_SIGW(__Vtemp180,95,0,3);
    //char	__VpadToAlign1956[4];
    VL_SIGW(__Vtemp181,95,0,3);
    //char	__VpadToAlign1972[4];
    VL_SIGW(__Vtemp183,95,0,3);
    //char	__VpadToAlign1988[4];
    VL_SIGW(__Vtemp185,95,0,3);
    //char	__VpadToAlign2004[4];
    VL_SIGW(__Vtemp186,95,0,3);
    //char	__VpadToAlign2020[4];
    VL_SIGW(__Vtemp187,95,0,3);
    //char	__VpadToAlign2036[4];
    VL_SIGW(__Vtemp189,95,0,3);
    //char	__VpadToAlign2052[4];
    VL_SIGW(__Vtemp191,95,0,3);
    //char	__VpadToAlign2068[4];
    VL_SIGW(__Vtemp192,95,0,3);
    // Body
    // ALWAYS at ../GSIM.v:137
    if (vlTOPp->reset) {
	vlTOPp->v__DOT__next_count = 0U;
	vlTOPp->v__DOT__next_loop = 0U;
	vlTOPp->v__DOT__next_inb_0 = 0U;
	vlTOPp->v__DOT__next_inb_1 = 0U;
	vlTOPp->v__DOT__next_inb_2 = 0U;
	vlTOPp->v__DOT__next_inb_3 = 0U;
	vlTOPp->v__DOT__next_inb_4 = 0U;
	vlTOPp->v__DOT__next_inb_5 = 0U;
	vlTOPp->v__DOT__next_inb_6 = 0U;
	vlTOPp->v__DOT__next_inb_7 = 0U;
	vlTOPp->v__DOT__next_inb_8 = 0U;
	vlTOPp->v__DOT__next_inb_9 = 0U;
	vlTOPp->v__DOT__next_inb_10 = 0U;
	vlTOPp->v__DOT__next_inb_11 = 0U;
	vlTOPp->v__DOT__next_inb_12 = 0U;
	vlTOPp->v__DOT__next_inb_13 = 0U;
	vlTOPp->v__DOT__next_inb_14 = 0U;
	vlTOPp->v__DOT__next_inb_15 = 0U;
	vlTOPp->v__DOT__next_out_0 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_1 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_2 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_3 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_4 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_5 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_6 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_7 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_8 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_9 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_10 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_11 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_12 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_13 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_14 = VL_ULL(0);
	vlTOPp->v__DOT__next_out_15 = VL_ULL(0);
	vlTOPp->v__DOT__par_0 = VL_ULL(0);
	vlTOPp->v__DOT__par_1 = VL_ULL(0);
	vlTOPp->v__DOT__par_2 = VL_ULL(0);
	vlTOPp->v__DOT__par_3 = VL_ULL(0);
	vlTOPp->v__DOT__par_4 = VL_ULL(0);
	vlTOPp->v__DOT__par_5 = VL_ULL(0);
	vlTOPp->v__DOT__par_b = 0U;
	vlTOPp->out_valid = 0U;
	vlTOPp->x_out = 0U;
    } else {
	vlTOPp->v__DOT__next_count = (0xfU & ((IData)(vlTOPp->in_en)
					       ? 0U
					       : ((IData)(1U) 
						  + (IData)(vlTOPp->v__DOT__count))));
	vlTOPp->v__DOT__next_loop = (0x3ffU & ((0xfU 
						== (IData)(vlTOPp->v__DOT__count))
					        ? ((IData)(1U) 
						   + (IData)(vlTOPp->v__DOT__loop))
					        : (IData)(vlTOPp->v__DOT__loop)));
	vlTOPp->v__DOT__next_inb_0 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_1)
				       : (IData)(vlTOPp->v__DOT__inb_0));
	vlTOPp->v__DOT__next_inb_1 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_2)
				       : (IData)(vlTOPp->v__DOT__inb_1));
	vlTOPp->v__DOT__next_inb_2 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_3)
				       : (IData)(vlTOPp->v__DOT__inb_2));
	vlTOPp->v__DOT__next_inb_3 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_4)
				       : (IData)(vlTOPp->v__DOT__inb_3));
	vlTOPp->v__DOT__next_inb_4 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_5)
				       : (IData)(vlTOPp->v__DOT__inb_4));
	vlTOPp->v__DOT__next_inb_5 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_6)
				       : (IData)(vlTOPp->v__DOT__inb_5));
	vlTOPp->v__DOT__next_inb_6 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_7)
				       : (IData)(vlTOPp->v__DOT__inb_6));
	vlTOPp->v__DOT__next_inb_7 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_8)
				       : (IData)(vlTOPp->v__DOT__inb_7));
	vlTOPp->v__DOT__next_inb_8 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_9)
				       : (IData)(vlTOPp->v__DOT__inb_8));
	vlTOPp->v__DOT__next_inb_9 = ((IData)(vlTOPp->in_en)
				       ? (IData)(vlTOPp->v__DOT__inb_10)
				       : (IData)(vlTOPp->v__DOT__inb_9));
	vlTOPp->v__DOT__next_inb_10 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_11)
				        : (IData)(vlTOPp->v__DOT__inb_10));
	vlTOPp->v__DOT__next_inb_11 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_12)
				        : (IData)(vlTOPp->v__DOT__inb_11));
	vlTOPp->v__DOT__next_inb_12 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_13)
				        : (IData)(vlTOPp->v__DOT__inb_12));
	vlTOPp->v__DOT__next_inb_13 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_14)
				        : (IData)(vlTOPp->v__DOT__inb_13));
	vlTOPp->v__DOT__next_inb_14 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->v__DOT__inb_15)
				        : (IData)(vlTOPp->v__DOT__inb_14));
	vlTOPp->v__DOT__next_inb_15 = ((IData)(vlTOPp->in_en)
				        ? (IData)(vlTOPp->b_in)
				        : (IData)(vlTOPp->v__DOT__inb_15));
	__Vtemp97[0U] = 0xccccccdU;
	__Vtemp97[1U] = 0U;
	__Vtemp97[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp99, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp101[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp99[0U]);
	__Vtemp101[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp99[1U]);
	__Vtemp101[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp99[2U]);
	VL_MUL_W(3, __Vtemp102, __Vtemp97, __Vtemp101);
	vlTOPp->v__DOT__next_out_0 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_1
				       : ((0U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp102[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp102[1U])))
					   : vlTOPp->v__DOT__out_0));
	__Vtemp103[0U] = 0xccccccdU;
	__Vtemp103[1U] = 0U;
	__Vtemp103[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp105, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp107[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp105[0U]);
	__Vtemp107[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp105[1U]);
	__Vtemp107[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp105[2U]);
	VL_MUL_W(3, __Vtemp108, __Vtemp103, __Vtemp107);
	vlTOPp->v__DOT__next_out_1 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_2
				       : ((1U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp108[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp108[1U])))
					   : vlTOPp->v__DOT__out_1));
	__Vtemp109[0U] = 0xccccccdU;
	__Vtemp109[1U] = 0U;
	__Vtemp109[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp111, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp113[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp111[0U]);
	__Vtemp113[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp111[1U]);
	__Vtemp113[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp111[2U]);
	VL_MUL_W(3, __Vtemp114, __Vtemp109, __Vtemp113);
	vlTOPp->v__DOT__next_out_2 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_3
				       : ((2U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp114[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp114[1U])))
					   : vlTOPp->v__DOT__out_2));
	__Vtemp115[0U] = 0xccccccdU;
	__Vtemp115[1U] = 0U;
	__Vtemp115[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp117, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp119[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp117[0U]);
	__Vtemp119[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp117[1U]);
	__Vtemp119[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp117[2U]);
	VL_MUL_W(3, __Vtemp120, __Vtemp115, __Vtemp119);
	vlTOPp->v__DOT__next_out_3 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_4
				       : ((3U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp120[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp120[1U])))
					   : vlTOPp->v__DOT__out_3));
	__Vtemp121[0U] = 0xccccccdU;
	__Vtemp121[1U] = 0U;
	__Vtemp121[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp123, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp125[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp123[0U]);
	__Vtemp125[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp123[1U]);
	__Vtemp125[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp123[2U]);
	VL_MUL_W(3, __Vtemp126, __Vtemp121, __Vtemp125);
	vlTOPp->v__DOT__next_out_4 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_5
				       : ((4U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp126[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp126[1U])))
					   : vlTOPp->v__DOT__out_4));
	__Vtemp127[0U] = 0xccccccdU;
	__Vtemp127[1U] = 0U;
	__Vtemp127[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp129, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp131[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp129[0U]);
	__Vtemp131[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp129[1U]);
	__Vtemp131[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp129[2U]);
	VL_MUL_W(3, __Vtemp132, __Vtemp127, __Vtemp131);
	vlTOPp->v__DOT__next_out_5 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_6
				       : ((5U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp132[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp132[1U])))
					   : vlTOPp->v__DOT__out_5));
	__Vtemp133[0U] = 0xccccccdU;
	__Vtemp133[1U] = 0U;
	__Vtemp133[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp135, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp137[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp135[0U]);
	__Vtemp137[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp135[1U]);
	__Vtemp137[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp135[2U]);
	VL_MUL_W(3, __Vtemp138, __Vtemp133, __Vtemp137);
	vlTOPp->v__DOT__next_out_6 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_7
				       : ((6U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp138[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp138[1U])))
					   : vlTOPp->v__DOT__out_6));
	__Vtemp139[0U] = 0xccccccdU;
	__Vtemp139[1U] = 0U;
	__Vtemp139[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp141, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp143[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp141[0U]);
	__Vtemp143[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp141[1U]);
	__Vtemp143[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp141[2U]);
	VL_MUL_W(3, __Vtemp144, __Vtemp139, __Vtemp143);
	vlTOPp->v__DOT__next_out_7 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_8
				       : ((7U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp144[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp144[1U])))
					   : vlTOPp->v__DOT__out_7));
	__Vtemp145[0U] = 0xccccccdU;
	__Vtemp145[1U] = 0U;
	__Vtemp145[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp147, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp149[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp147[0U]);
	__Vtemp149[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp147[1U]);
	__Vtemp149[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp147[2U]);
	VL_MUL_W(3, __Vtemp150, __Vtemp145, __Vtemp149);
	vlTOPp->v__DOT__next_out_8 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_9
				       : ((8U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp150[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp150[1U])))
					   : vlTOPp->v__DOT__out_8));
	__Vtemp151[0U] = 0xccccccdU;
	__Vtemp151[1U] = 0U;
	__Vtemp151[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp153, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp155[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp153[0U]);
	__Vtemp155[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp153[1U]);
	__Vtemp155[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp153[2U]);
	VL_MUL_W(3, __Vtemp156, __Vtemp151, __Vtemp155);
	vlTOPp->v__DOT__next_out_9 = ((IData)(vlTOPp->in_en)
				       ? vlTOPp->v__DOT__out_10
				       : ((9U == (IData)(vlTOPp->v__DOT__count))
					   ? (((QData)((IData)(
							       __Vtemp156[2U])) 
					       << 0x20U) 
					      | (QData)((IData)(
								__Vtemp156[1U])))
					   : vlTOPp->v__DOT__out_9));
	__Vtemp157[0U] = 0xccccccdU;
	__Vtemp157[1U] = 0U;
	__Vtemp157[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp159, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp161[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp159[0U]);
	__Vtemp161[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp159[1U]);
	__Vtemp161[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp159[2U]);
	VL_MUL_W(3, __Vtemp162, __Vtemp157, __Vtemp161);
	vlTOPp->v__DOT__next_out_10 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_11
				        : ((0xaU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp162[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp162[1U])))
					    : vlTOPp->v__DOT__out_10));
	__Vtemp163[0U] = 0xccccccdU;
	__Vtemp163[1U] = 0U;
	__Vtemp163[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp165, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp167[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp165[0U]);
	__Vtemp167[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp165[1U]);
	__Vtemp167[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp165[2U]);
	VL_MUL_W(3, __Vtemp168, __Vtemp163, __Vtemp167);
	vlTOPp->v__DOT__next_out_11 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_12
				        : ((0xbU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp168[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp168[1U])))
					    : vlTOPp->v__DOT__out_11));
	__Vtemp169[0U] = 0xccccccdU;
	__Vtemp169[1U] = 0U;
	__Vtemp169[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp171, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp173[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp171[0U]);
	__Vtemp173[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp171[1U]);
	__Vtemp173[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp171[2U]);
	VL_MUL_W(3, __Vtemp174, __Vtemp169, __Vtemp173);
	vlTOPp->v__DOT__next_out_12 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_13
				        : ((0xcU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp174[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp174[1U])))
					    : vlTOPp->v__DOT__out_12));
	__Vtemp175[0U] = 0xccccccdU;
	__Vtemp175[1U] = 0U;
	__Vtemp175[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp177, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp179[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp177[0U]);
	__Vtemp179[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp177[1U]);
	__Vtemp179[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp177[2U]);
	VL_MUL_W(3, __Vtemp180, __Vtemp175, __Vtemp179);
	vlTOPp->v__DOT__next_out_13 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_14
				        : ((0xdU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp180[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp180[1U])))
					    : vlTOPp->v__DOT__out_13));
	__Vtemp181[0U] = 0xccccccdU;
	__Vtemp181[1U] = 0U;
	__Vtemp181[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp183, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp185[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp183[0U]);
	__Vtemp185[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp183[1U]);
	__Vtemp185[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp183[2U]);
	VL_MUL_W(3, __Vtemp186, __Vtemp181, __Vtemp185);
	vlTOPp->v__DOT__next_out_14 = ((IData)(vlTOPp->in_en)
				        ? vlTOPp->v__DOT__out_15
				        : ((0xeU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp186[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp186[1U])))
					    : vlTOPp->v__DOT__out_14));
	__Vtemp187[0U] = 0xccccccdU;
	__Vtemp187[1U] = 0U;
	__Vtemp187[2U] = 0U;
	VL_EXTEND_WQ(96,64, __Vtemp189, vlTOPp->v__DOT__cal0__DOT__add_tmp);
	__Vtemp191[0U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)(vlTOPp->v__DOT__cal0__DOT__add_tmp)
			   : __Vtemp189[0U]);
	__Vtemp191[1U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
				      >> 0x20U)) : 
			  __Vtemp189[1U]);
	__Vtemp191[2U] = ((1U & (IData)((vlTOPp->v__DOT__cal0__DOT__add_tmp 
					 >> 0x3fU)))
			   ? 0xffffffffU : __Vtemp189[2U]);
	VL_MUL_W(3, __Vtemp192, __Vtemp187, __Vtemp191);
	vlTOPp->v__DOT__next_out_15 = ((IData)(vlTOPp->in_en)
				        ? ((0x8000U 
					    & (IData)(vlTOPp->b_in))
					    ? ((QData)((IData)(
							       (0xfffff000U 
								| (0xfffU 
								   & ((IData)(vlTOPp->b_in) 
								      >> 4U))))) 
					       << 0x20U)
					    : ((QData)((IData)(
							       (0xfffU 
								& ((IData)(vlTOPp->b_in) 
								   >> 4U)))) 
					       << 0x20U))
				        : ((0xfU == (IData)(vlTOPp->v__DOT__count))
					    ? (((QData)((IData)(
								__Vtemp192[2U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 __Vtemp192[1U])))
					    : vlTOPp->v__DOT__out_15));
	if ((8U & (IData)(vlTOPp->v__DOT__count))) {
	    if ((4U & (IData)(vlTOPp->v__DOT__count))) {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_3 = VL_ULL(0);
			vlTOPp->v__DOT__par_4 = VL_ULL(0);
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_15;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_15 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_4 = VL_ULL(0);
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_14;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_14 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_5 = VL_ULL(0);
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_13;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_13 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_15;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_12;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_12 
						 >> 0x10U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_14;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_11;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_11 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_13;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_10;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_10 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_12;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_9;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_9 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_11;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_8;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_8 
						 >> 0x10U));
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->v__DOT__count))) {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_10;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_7;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_7 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_9;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_6;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_6 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_8;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_5;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_5 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_7;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_4;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_4 
						 >> 0x10U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__count))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_6;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_3;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_3 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_5;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_2;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_2 
						 >> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__count))) {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = VL_ULL(0);
			vlTOPp->v__DOT__par_2 = vlTOPp->v__DOT__out_0;
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_4;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_1;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_1 
						 >> 0x10U));
		    } else {
			vlTOPp->v__DOT__par_0 = VL_ULL(0);
			vlTOPp->v__DOT__par_1 = VL_ULL(0);
			vlTOPp->v__DOT__par_2 = VL_ULL(0);
			vlTOPp->v__DOT__par_3 = vlTOPp->v__DOT__out_1;
			vlTOPp->v__DOT__par_4 = vlTOPp->v__DOT__out_2;
			vlTOPp->v__DOT__par_5 = vlTOPp->v__DOT__out_3;
			vlTOPp->v__DOT__par_b = vlTOPp->v__DOT__inb_0;
			vlTOPp->x_out = (IData)((vlTOPp->v__DOT__out_0 
						 >> 0x10U));
		    }
		}
	    }
	}
	vlTOPp->out_valid = (1U & ((IData)(vlTOPp->v__DOT__loop) 
				   >> 9U));
    }
    vlTOPp->v__DOT__cal0__DOT__comb_1 = (vlTOPp->v__DOT__par_1 
					 + vlTOPp->v__DOT__par_4);
    vlTOPp->v__DOT__cal0__DOT__comb_2 = (vlTOPp->v__DOT__par_2 
					 + vlTOPp->v__DOT__par_3);
}

void VGSIM::_combo__TOP__4(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_combo__TOP__4\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__cal0__DOT__comb_1 = (vlTOPp->v__DOT__par_1 
					 + vlTOPp->v__DOT__par_4);
    vlTOPp->v__DOT__cal0__DOT__comb_2 = (vlTOPp->v__DOT__par_2 
					 + vlTOPp->v__DOT__par_3);
    vlTOPp->v__DOT__cal0__DOT__add_tmp = ((((vlTOPp->v__DOT__par_0 
					     + vlTOPp->v__DOT__par_5) 
					    + vlTOPp->v__DOT__cal0__DOT__comb_2) 
					   + ((((QData)((IData)(
								(1U 
								 & (IData)(
									   (vlTOPp->v__DOT__cal0__DOT__comb_2 
									    >> 0x3fU))))) 
						<< 0x3fU) 
					       | (VL_ULL(0x7ffffffffffffffc) 
						  & (vlTOPp->v__DOT__cal0__DOT__comb_2 
						     << 2U))) 
					      + (((QData)((IData)(
								  (1U 
								   & (IData)(
									     (vlTOPp->v__DOT__cal0__DOT__comb_2 
									      >> 0x3fU))))) 
						  << 0x3fU) 
						 | (VL_ULL(0x7ffffffffffffff8) 
						    & (vlTOPp->v__DOT__cal0__DOT__comb_2 
						       << 3U))))) 
					  + (((0x8000U 
					       & (IData)(vlTOPp->v__DOT__par_b))
					       ? ((QData)((IData)(
								  (0xffff0000U 
								   | (IData)(vlTOPp->v__DOT__par_b)))) 
						  << 0x20U)
					       : ((QData)((IData)(vlTOPp->v__DOT__par_b)) 
						  << 0x20U)) 
					     - ((((QData)((IData)(
								  (1U 
								   & (IData)(
									     (vlTOPp->v__DOT__cal0__DOT__comb_1 
									      >> 0x3fU))))) 
						  << 0x3fU) 
						 | (VL_ULL(0x7ffffffffffffffe) 
						    & (vlTOPp->v__DOT__cal0__DOT__comb_1 
						       << 1U))) 
						+ (
						   ((QData)((IData)(
								    (1U 
								     & (IData)(
									       (vlTOPp->v__DOT__cal0__DOT__comb_1 
										>> 0x3fU))))) 
						    << 0x3fU) 
						   | (VL_ULL(0x7ffffffffffffffc) 
						      & (vlTOPp->v__DOT__cal0__DOT__comb_1 
							 << 2U))))));
}

void VGSIM::_settle__TOP__5(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_settle__TOP__5\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__cal0__DOT__add_tmp = ((((vlTOPp->v__DOT__par_0 
					     + vlTOPp->v__DOT__par_5) 
					    + vlTOPp->v__DOT__cal0__DOT__comb_2) 
					   + ((((QData)((IData)(
								(1U 
								 & (IData)(
									   (vlTOPp->v__DOT__cal0__DOT__comb_2 
									    >> 0x3fU))))) 
						<< 0x3fU) 
					       | (VL_ULL(0x7ffffffffffffffc) 
						  & (vlTOPp->v__DOT__cal0__DOT__comb_2 
						     << 2U))) 
					      + (((QData)((IData)(
								  (1U 
								   & (IData)(
									     (vlTOPp->v__DOT__cal0__DOT__comb_2 
									      >> 0x3fU))))) 
						  << 0x3fU) 
						 | (VL_ULL(0x7ffffffffffffff8) 
						    & (vlTOPp->v__DOT__cal0__DOT__comb_2 
						       << 3U))))) 
					  + (((0x8000U 
					       & (IData)(vlTOPp->v__DOT__par_b))
					       ? ((QData)((IData)(
								  (0xffff0000U 
								   | (IData)(vlTOPp->v__DOT__par_b)))) 
						  << 0x20U)
					       : ((QData)((IData)(vlTOPp->v__DOT__par_b)) 
						  << 0x20U)) 
					     - ((((QData)((IData)(
								  (1U 
								   & (IData)(
									     (vlTOPp->v__DOT__cal0__DOT__comb_1 
									      >> 0x3fU))))) 
						  << 0x3fU) 
						 | (VL_ULL(0x7ffffffffffffffe) 
						    & (vlTOPp->v__DOT__cal0__DOT__comb_1 
						       << 1U))) 
						+ (
						   ((QData)((IData)(
								    (1U 
								     & (IData)(
									       (vlTOPp->v__DOT__cal0__DOT__comb_1 
										>> 0x3fU))))) 
						    << 0x3fU) 
						   | (VL_ULL(0x7ffffffffffffffc) 
						      & (vlTOPp->v__DOT__cal0__DOT__comb_1 
							 << 2U))))));
}

void VGSIM::_eval(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_eval\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VGSIM::_eval_initial(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_eval_initial\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VGSIM::final() {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::final\n"); );
    // Variables
    VGSIM__Syms* __restrict vlSymsp = this->__VlSymsp;
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VGSIM::_eval_settle(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_eval_settle\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

QData VGSIM::_change_request(VGSIM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGSIM::_change_request\n"); );
    VGSIM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->v__DOT__cal0__DOT__add_tmp ^ vlTOPp->__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp) | (vlTOPp->v__DOT__cal0__DOT__add_tmp ^ vlTOPp->__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp));
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__cal0__DOT__add_tmp ^ vlTOPp->__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp) | (vlTOPp->v__DOT__cal0__DOT__add_tmp ^ vlTOPp->__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp))) VL_PRINTF("	CHANGE: ../GSIM.v:21: v.cal0.add_tmp\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__cal0__DOT__add_tmp 
	= vlTOPp->v__DOT__cal0__DOT__add_tmp;
    return __req;
}
