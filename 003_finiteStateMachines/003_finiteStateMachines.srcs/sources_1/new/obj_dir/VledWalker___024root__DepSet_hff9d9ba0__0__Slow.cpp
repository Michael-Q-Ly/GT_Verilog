// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VledWalker.h for the primary calling header

#include "verilated.h"

#include "VledWalker___024root.h"

VL_ATTR_COLD void VledWalker___024root___initial__TOP__2(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___initial__TOP__2\n"); );
    // Body
    vlSelf->ledWalker__DOT__led_index = 0U;
    vlSelf->ledWalker__DOT__stb = 0U;
    vlSelf->ledWalker__DOT__wait_counter = 0U;
}

VL_ATTR_COLD void VledWalker___024root___eval_initial(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
    VledWalker___024root___initial__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void VledWalker___024root___eval_settle(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___eval_settle\n"); );
}

VL_ATTR_COLD void VledWalker___024root___final(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___final\n"); );
}

VL_ATTR_COLD void VledWalker___024root___ctor_var_reset(VledWalker___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->o_led = VL_RAND_RESET_I(8);
    vlSelf->ledWalker__DOT__wait_counter = VL_RAND_RESET_I(27);
    vlSelf->ledWalker__DOT__led_index = VL_RAND_RESET_I(4);
    vlSelf->ledWalker__DOT__stb = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
