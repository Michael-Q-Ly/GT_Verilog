// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaskbus.h for the primary calling header

#include "verilated.h"

#include "Vmaskbus___024root.h"

VL_INLINE_OPT void Vmaskbus___024root___combo__TOP__1(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->o_led = (0x87U ^ (IData)(vlSelf->i_sw));
}

void Vmaskbus___024root___eval(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___eval\n"); );
    // Body
    Vmaskbus___024root___combo__TOP__1(vlSelf);
}

#ifdef VL_DEBUG
void Vmaskbus___024root___eval_debug_assertions(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_sw & 0xfe00U))) {
        Verilated::overWidthError("i_sw");}
}
#endif  // VL_DEBUG
