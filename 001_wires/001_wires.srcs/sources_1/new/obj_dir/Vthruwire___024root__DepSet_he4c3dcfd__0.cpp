// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vthruwire.h for the primary calling header

#include "verilated.h"

#include "Vthruwire___024root.h"

VL_INLINE_OPT void Vthruwire___024root___combo__TOP__1(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->o_led = vlSelf->i_sw;
}

void Vthruwire___024root___eval(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___eval\n"); );
    // Body
    Vthruwire___024root___combo__TOP__1(vlSelf);
}

#ifdef VL_DEBUG
void Vthruwire___024root___eval_debug_assertions(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_sw & 0xfeU))) {
        Verilated::overWidthError("i_sw");}
}
#endif  // VL_DEBUG
