// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vthruwire.h for the primary calling header

#ifndef VERILATED_VTHRUWIRE___024ROOT_H_
#define VERILATED_VTHRUWIRE___024ROOT_H_  // guard

#include "verilated.h"

class Vthruwire__Syms;
VL_MODULE(Vthruwire___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_sw,0,0);
    VL_OUT8(o_led,0,0);

    // INTERNAL VARIABLES
    Vthruwire__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vthruwire___024root(const char* name);
    ~Vthruwire___024root();
    VL_UNCOPYABLE(Vthruwire___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vthruwire__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
