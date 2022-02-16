// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VledWalker__Syms.h"


VL_ATTR_COLD void VledWalker___024root__trace_init_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VledWalker___024root__trace_init_top(VledWalker___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_init_top\n"); );
    // Body
    VledWalker___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void VledWalker___024root__trace_init_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+1,"i_clk", false,-1);
    tracep->declBus(c+2,"o_led", false,-1, 7,0);
    tracep->declBit(c+1,"ledWalker i_clk", false,-1);
    tracep->declBus(c+2,"ledWalker o_led", false,-1, 7,0);
    tracep->declBus(c+3,"ledWalker led_index", false,-1, 3,0);
}

VL_ATTR_COLD void VledWalker___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VledWalker___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VledWalker___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VledWalker___024root__trace_register(VledWalker___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VledWalker___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VledWalker___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VledWalker___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VledWalker___024root__trace_full_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VledWalker___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_full_top_0\n"); );
    // Init
    VledWalker___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VledWalker___024root*>(voidSelf);
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VledWalker___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VledWalker___024root__trace_full_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->i_clk));
    tracep->fullCData(oldp+2,(vlSelf->o_led),8);
    tracep->fullCData(oldp+3,(vlSelf->ledWalker__DOT__led_index),4);
}
