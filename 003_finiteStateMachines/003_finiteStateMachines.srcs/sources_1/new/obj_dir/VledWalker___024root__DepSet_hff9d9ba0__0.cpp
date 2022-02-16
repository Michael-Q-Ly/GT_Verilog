// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VledWalker.h for the primary calling header

#include "verilated.h"

#include "VledWalker___024root.h"

extern const VlUnpacked<CData/*7:0*/, 16> VledWalker__ConstPool__TABLE_hcfa2f0f9_0;

VL_INLINE_OPT void VledWalker___024root___sequent__TOP__1(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___sequent__TOP__1\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    CData/*3:0*/ __Vdly__ledWalker__DOT__led_index;
    // Body
    __Vdly__ledWalker__DOT__led_index = vlSelf->ledWalker__DOT__led_index;
    __Vdly__ledWalker__DOT__led_index = ((0xdU < (IData)(vlSelf->ledWalker__DOT__led_index))
                                          ? 0U : (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->ledWalker__DOT__led_index))));
    __Vtableidx1 = vlSelf->ledWalker__DOT__led_index;
    vlSelf->o_led = VledWalker__ConstPool__TABLE_hcfa2f0f9_0
        [__Vtableidx1];
    vlSelf->ledWalker__DOT__led_index = __Vdly__ledWalker__DOT__led_index;
}

void VledWalker___024root___eval(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->i_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__i_clk)))) {
        VledWalker___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
}

#ifdef VL_DEBUG
void VledWalker___024root___eval_debug_assertions(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
}
#endif  // VL_DEBUG
