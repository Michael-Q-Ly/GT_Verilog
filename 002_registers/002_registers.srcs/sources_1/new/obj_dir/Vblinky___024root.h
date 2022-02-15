// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vblinky.h for the primary calling header

#ifndef VERILATED_VBLINKY___024ROOT_H_
#define VERILATED_VBLINKY___024ROOT_H_  // guard

#include "verilated.h"

class Vblinky__Syms;
VL_MODULE(Vblinky___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_OUT8(o_led,0,0);
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    SData/*11:0*/ blinky__DOT__counter;

    // INTERNAL VARIABLES
    Vblinky__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vblinky___024root(const char* name);
    ~Vblinky___024root();
    VL_UNCOPYABLE(Vblinky___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vblinky__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
