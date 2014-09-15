// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCTE.h for the primary calling header

#include "VCTE.h"              // For This
#include "VCTE__Syms.h"

//--------------------
// STATIC VARIABLES

VL_ST_SIG8(VCTE::__Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[16],3,0);

//--------------------

VL_CTOR_IMP(VCTE) {
    VCTE__Syms* __restrict vlSymsp = __VlSymsp = new VCTE__Syms(this, name());
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    op_mode = VL_RAND_RESET_I(1);
    in_en = VL_RAND_RESET_I(1);
    yuv_in = VL_RAND_RESET_I(8);
    rgb_in = VL_RAND_RESET_I(24);
    busy = VL_RAND_RESET_I(1);
    out_valid = VL_RAND_RESET_I(1);
    rgb_out = VL_RAND_RESET_I(24);
    yuv_out = VL_RAND_RESET_I(8);
    v__DOT__yuv_to_rgb_inst0__DOT__state = VL_RAND_RESET_I(4);
    v__DOT__yuv_to_rgb_inst0__DOT__state_next = VL_RAND_RESET_I(4);
    v__DOT__yuv_to_rgb_inst0__DOT__reg_U = VL_RAND_RESET_I(8);
    v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1 = VL_RAND_RESET_I(8);
    v__DOT__yuv_to_rgb_inst0__DOT__reg_V = VL_RAND_RESET_I(8);
    v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2 = VL_RAND_RESET_I(8);
    v__DOT__yuv_to_rgb_inst0__DOT__R_ext = VL_RAND_RESET_I(16);
    v__DOT__yuv_to_rgb_inst0__DOT__G_ext = VL_RAND_RESET_I(16);
    v__DOT__yuv_to_rgb_inst0__DOT__B_ext = VL_RAND_RESET_I(16);
    v__DOT__yuv_to_rgb_inst0__DOT__U_ext = VL_RAND_RESET_I(16);
    v__DOT__yuv_to_rgb_inst0__DOT__Y_ext = VL_RAND_RESET_I(16);
    v__DOT__yuv_to_rgb_inst0__DOT__V_ext = VL_RAND_RESET_I(16);
    __Vtableidx1 = VL_RAND_RESET_I(4);
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[0] = 1U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[1] = 2U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[2] = 3U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[3] = 4U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[4] = 5U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[5] = 0U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[6] = 6U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[7] = 7U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[8] = 8U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[9] = 9U;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[10] = 0xaU;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[11] = 0xbU;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[12] = 0xcU;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[13] = 0xdU;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[14] = 0xeU;
    __Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next[15] = 0xfU;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}

void VCTE::__Vconfigure(VCTE__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VCTE::~VCTE() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VCTE::eval() {
    VCTE__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VCTE::eval\n"); );
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

void VCTE::_eval_initial_loop(VCTE__Syms* __restrict vlSymsp) {
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

void VCTE::_initial__TOP__1(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_initial__TOP__1\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../CTE.v:16
    vlTOPp->yuv_out = 0U;
}

void VCTE::_sequent__TOP__2(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_sequent__TOP__2\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__state,3,0);
    VL_SIG8(__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_U,7,0);
    VL_SIG8(__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1,7,0);
    VL_SIG8(__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_V,7,0);
    VL_SIG8(__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2,7,0);
    //char	__VpadToAlign29[3];
    // Body
    __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_U = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U;
    __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_V = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V;
    __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1 = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1;
    __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2 = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2;
    __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__state = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state;
    // ALWAYS at ../CTE.v:98
    if ((1U & ((IData)(vlTOPp->reset) | (~ (IData)(vlTOPp->in_en))))) {
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__state = 0U;
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_U = 0U;
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1 = 0U;
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_V = 0U;
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2 = 0U;
    } else {
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_U 
	    = ((0U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	        ? (IData)(vlTOPp->yuv_in) : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U));
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1 
	    = ((1U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	        ? (IData)(vlTOPp->yuv_in) : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1));
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_V 
	    = ((2U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	        ? (IData)(vlTOPp->yuv_in) : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V));
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2 
	    = ((4U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	        ? (IData)(vlTOPp->yuv_in) : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2));
	__Vdly__v__DOT__yuv_to_rgb_inst0__DOT__state 
	    = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state_next;
    }
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U = __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_U;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V = __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_V;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1 = __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2 = __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state = __Vdly__v__DOT__yuv_to_rgb_inst0__DOT__state;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext = 
	((0xff00U & (VL_NEGATE_I((IData)((1U & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U) 
						>> 7U)))) 
		     << 8U)) | (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext = 
	((0xff00U & (VL_NEGATE_I((IData)((1U & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V) 
						>> 7U)))) 
		     << 8U)) | (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V));
    // ALWAYS at ../CTE.v:45
    vlTOPp->__Vtableidx1 = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state_next 
	= (IData)(vlTOPp->__Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next)
	[(IData)(vlTOPp->__Vtableidx1)];
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext = 
	((3U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	  ? (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1)
	  : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2));
}

void VCTE::_settle__TOP__3(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_settle__TOP__3\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext = 
	((0xff00U & (VL_NEGATE_I((IData)((1U & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U) 
						>> 7U)))) 
		     << 8U)) | (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_U));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext = 
	((0xff00U & (VL_NEGATE_I((IData)((1U & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V) 
						>> 7U)))) 
		     << 8U)) | (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_V));
    vlTOPp->busy = ((IData)(vlTOPp->op_mode) | ((3U 
						 == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state)) 
						| (5U 
						   == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))));
    vlTOPp->out_valid = ((~ (IData)(vlTOPp->op_mode)) 
			 & ((3U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state)) 
			    | (5U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))));
    // ALWAYS at ../CTE.v:45
    vlTOPp->__Vtableidx1 = vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state;
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state_next 
	= (IData)(vlTOPp->__Vtable1_v__DOT__yuv_to_rgb_inst0__DOT__state_next)
	[(IData)(vlTOPp->__Vtableidx1)];
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext = 
	((3U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))
	  ? (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y1)
	  : (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__reg_Y2));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext = 
	(0xffffU & (((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		     << 3U) + ((IData)(0xdU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext))));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext = 
	(0xffffU & (((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		     << 3U) + ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext) 
			       << 4U)));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext = 
	(0xffffU & ((((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		      << 3U) + ((IData)(0xfffeU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext))) 
		    + ((IData)(0xfffaU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext))));
}

void VCTE::_combo__TOP__4(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_combo__TOP__4\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->busy = ((IData)(vlTOPp->op_mode) | ((3U 
						 == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state)) 
						| (5U 
						   == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))));
    vlTOPp->out_valid = ((~ (IData)(vlTOPp->op_mode)) 
			 & ((3U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state)) 
			    | (5U == (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__state))));
}

void VCTE::_sequent__TOP__5(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_sequent__TOP__5\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext = 
	(0xffffU & (((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		     << 3U) + ((IData)(0xdU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext))));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext = 
	(0xffffU & (((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		     << 3U) + ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext) 
			       << 4U)));
    vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext = 
	(0xffffU & ((((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__Y_ext) 
		      << 3U) + ((IData)(0xfffeU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__U_ext))) 
		    + ((IData)(0xfffaU) * (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__V_ext))));
    vlTOPp->rgb_out = ((0xff0000U & (((0x8000U & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext))
				       ? 0U : ((0U 
						!= 
						(0xfU 
						 & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						    >> 0xbU)))
					        ? 0xffU
					        : (
						   (4U 
						    & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext))
						    ? 
						   ((0xffU 
						     == 
						     (0xffU 
						      & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
							 >> 3U)))
						     ? 0xffU
						     : 
						    ((IData)(1U) 
						     + 
						     ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						      >> 3U)))
						    : 
						   ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						    >> 3U)))) 
				     << 0x10U)) | (
						   (0xff00U 
						    & (((0x8000U 
							 & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext))
							 ? 0U
							 : 
							((0U 
							  != 
							  (0xfU 
							   & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							      >> 0xbU)))
							  ? 0xffU
							  : 
							 ((4U 
							   & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext))
							   ? 
							  ((0xffU 
							    == 
							    (0xffU 
							     & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
								>> 3U)))
							    ? 0xffU
							    : 
							   ((IData)(1U) 
							    + 
							    ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							     >> 3U)))
							   : 
							  ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							   >> 3U)))) 
						       << 8U)) 
						   | (0xffU 
						      & ((0x8000U 
							  & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext))
							  ? 0U
							  : 
							 ((0U 
							   != 
							   (0xfU 
							    & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							       >> 0xbU)))
							   ? 0xffU
							   : 
							  ((4U 
							    & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext))
							    ? 
							   ((0xffU 
							     == 
							     (0xffU 
							      & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
								 >> 3U)))
							     ? 0xffU
							     : 
							    ((IData)(1U) 
							     + 
							     ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							      >> 3U)))
							    : 
							   ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							    >> 3U)))))));
}

void VCTE::_settle__TOP__6(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_settle__TOP__6\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rgb_out = ((0xff0000U & (((0x8000U & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext))
				       ? 0U : ((0U 
						!= 
						(0xfU 
						 & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						    >> 0xbU)))
					        ? 0xffU
					        : (
						   (4U 
						    & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext))
						    ? 
						   ((0xffU 
						     == 
						     (0xffU 
						      & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
							 >> 3U)))
						     ? 0xffU
						     : 
						    ((IData)(1U) 
						     + 
						     ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						      >> 3U)))
						    : 
						   ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__R_ext) 
						    >> 3U)))) 
				     << 0x10U)) | (
						   (0xff00U 
						    & (((0x8000U 
							 & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext))
							 ? 0U
							 : 
							((0U 
							  != 
							  (0xfU 
							   & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							      >> 0xbU)))
							  ? 0xffU
							  : 
							 ((4U 
							   & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext))
							   ? 
							  ((0xffU 
							    == 
							    (0xffU 
							     & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
								>> 3U)))
							    ? 0xffU
							    : 
							   ((IData)(1U) 
							    + 
							    ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							     >> 3U)))
							   : 
							  ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__G_ext) 
							   >> 3U)))) 
						       << 8U)) 
						   | (0xffU 
						      & ((0x8000U 
							  & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext))
							  ? 0U
							  : 
							 ((0U 
							   != 
							   (0xfU 
							    & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							       >> 0xbU)))
							   ? 0xffU
							   : 
							  ((4U 
							    & (IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext))
							    ? 
							   ((0xffU 
							     == 
							     (0xffU 
							      & ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
								 >> 3U)))
							     ? 0xffU
							     : 
							    ((IData)(1U) 
							     + 
							     ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							      >> 3U)))
							    : 
							   ((IData)(vlTOPp->v__DOT__yuv_to_rgb_inst0__DOT__B_ext) 
							    >> 3U)))))));
}

void VCTE::_eval(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_eval\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VCTE::_eval_initial(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_eval_initial\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VCTE::final() {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::final\n"); );
    // Variables
    VCTE__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCTE::_eval_settle(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_eval_settle\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
}

QData VCTE::_change_request(VCTE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VCTE::_change_request\n"); );
    VCTE* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
