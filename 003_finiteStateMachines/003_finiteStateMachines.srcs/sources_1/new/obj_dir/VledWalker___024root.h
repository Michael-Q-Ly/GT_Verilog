// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VledWalker.h for the primary calling header

#ifndef VERILATED_VLEDWALKER___024ROOT_H_
#define VERILATED_VLEDWALKER___024ROOT_H_  // guard

#include "verilated.h"

class VledWalker__Syms;
VL_MODULE(VledWalker___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_OUT8(o_led,7,0);
    CData/*3:0*/ ledWalker__DOT__led_index;
    CData/*0:0*/ __Vclklast__TOP__i_clk;

    // INTERNAL VARIABLES
    VledWalker__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VledWalker___024root(const char* name);
    ~VledWalker___024root();
    VL_UNCOPYABLE(VledWalker___024root);

    // INTERNAL METHODS
    void __Vconfigure(VledWalker__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
