// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaskbus.h for the primary calling header

#include "verilated.h"

#include "Vmaskbus___024root.h"

VL_ATTR_COLD void Vmaskbus___024root___eval_initial(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___eval_initial\n"); );
}

void Vmaskbus___024root___combo__TOP__1(Vmaskbus___024root* vlSelf);

VL_ATTR_COLD void Vmaskbus___024root___eval_settle(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___eval_settle\n"); );
    // Body
    Vmaskbus___024root___combo__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vmaskbus___024root___final(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___final\n"); );
}

VL_ATTR_COLD void Vmaskbus___024root___ctor_var_reset(Vmaskbus___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaskbus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaskbus___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_sw = VL_RAND_RESET_I(9);
    vlSelf->o_led = VL_RAND_RESET_I(9);
}
