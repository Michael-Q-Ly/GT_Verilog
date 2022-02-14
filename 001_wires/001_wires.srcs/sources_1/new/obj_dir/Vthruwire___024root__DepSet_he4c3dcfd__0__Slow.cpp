// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vthruwire.h for the primary calling header

#include "verilated.h"

#include "Vthruwire___024root.h"

VL_ATTR_COLD void Vthruwire___024root___eval_initial(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___eval_initial\n"); );
}

void Vthruwire___024root___combo__TOP__1(Vthruwire___024root* vlSelf);

VL_ATTR_COLD void Vthruwire___024root___eval_settle(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___eval_settle\n"); );
    // Body
    Vthruwire___024root___combo__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vthruwire___024root___final(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___final\n"); );
}

VL_ATTR_COLD void Vthruwire___024root___ctor_var_reset(Vthruwire___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vthruwire__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthruwire___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_sw = VL_RAND_RESET_I(1);
    vlSelf->o_led = VL_RAND_RESET_I(1);
}
