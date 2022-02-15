// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinky.h for the primary calling header

#include "verilated.h"

#include "Vblinky___024root.h"

VL_ATTR_COLD void Vblinky___024root___settle__TOP__2(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->o_led = (1U & ((IData)(vlSelf->blinky__DOT__counter) 
                           >> 0xbU));
}

VL_ATTR_COLD void Vblinky___024root___eval_initial(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
}

VL_ATTR_COLD void Vblinky___024root___eval_settle(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_settle\n"); );
    // Body
    Vblinky___024root___settle__TOP__2(vlSelf);
}

VL_ATTR_COLD void Vblinky___024root___final(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___final\n"); );
}

VL_ATTR_COLD void Vblinky___024root___ctor_var_reset(Vblinky___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->o_led = VL_RAND_RESET_I(1);
    vlSelf->blinky__DOT__counter = VL_RAND_RESET_I(12);
}
