// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VledWalker__Syms.h"


void VledWalker___024root__trace_chg_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep);

void VledWalker___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_chg_top_0\n"); );
    // Init
    VledWalker___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VledWalker___024root*>(voidSelf);
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VledWalker___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VledWalker___024root__trace_chg_sub_0(VledWalker___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    tracep->chgBit(oldp+0,(vlSelf->i_clk));
    tracep->chgCData(oldp+1,(vlSelf->o_led),8);
    tracep->chgCData(oldp+2,(vlSelf->ledWalker__DOT__led_index),4);
}

void VledWalker___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VledWalker___024root__trace_cleanup\n"); );
    // Init
    VledWalker___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VledWalker___024root*>(voidSelf);
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
