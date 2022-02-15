// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vblinky__Syms.h"


VL_ATTR_COLD void Vblinky___024root__trace_init_sub_0(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vblinky___024root__trace_init_top(Vblinky___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_init_top\n"); );
    // Body
    Vblinky___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vblinky___024root__trace_init_sub_0(Vblinky___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+1,"i_clk", false,-1);
    tracep->declBit(c+2,"o_led", false,-1);
    tracep->declBit(c+1,"blinky i_clk", false,-1);
    tracep->declBit(c+2,"blinky o_led", false,-1);
    tracep->declBus(c+3,"blinky counter", false,-1, 11,0);
}

VL_ATTR_COLD void Vblinky___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vblinky___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vblinky___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vblinky___024root__trace_register(Vblinky___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vblinky___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vblinky___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vblinky___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vblinky___024root__trace_full_sub_0(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vblinky___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_full_top_0\n"); );
    // Init
    Vblinky___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinky___024root*>(voidSelf);
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vblinky___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vblinky___024root__trace_full_sub_0(Vblinky___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->i_clk));
    tracep->fullBit(oldp+2,(vlSelf->o_led));
    tracep->fullSData(oldp+3,(vlSelf->blinky__DOT__counter),12);
}
