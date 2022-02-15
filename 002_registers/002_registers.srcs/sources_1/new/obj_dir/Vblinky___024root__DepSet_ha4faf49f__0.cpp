// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinky.h for the primary calling header

#include "verilated.h"

#include "Vblinky___024root.h"

VL_INLINE_OPT void Vblinky___024root___sequent__TOP__1(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->blinky__DOT__counter = (0xfffU & ((IData)(1U) 
                                              + (IData)(vlSelf->blinky__DOT__counter)));
    vlSelf->o_led = (1U & ((IData)(vlSelf->blinky__DOT__counter) 
                           >> 0xbU));
}

void Vblinky___024root___eval(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->i_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__i_clk)))) {
        Vblinky___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
}

#ifdef VL_DEBUG
void Vblinky___024root___eval_debug_assertions(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
}
#endif  // VL_DEBUG
