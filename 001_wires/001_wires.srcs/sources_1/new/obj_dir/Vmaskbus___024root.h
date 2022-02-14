// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmaskbus.h for the primary calling header

#ifndef VERILATED_VMASKBUS___024ROOT_H_
#define VERILATED_VMASKBUS___024ROOT_H_  // guard

#include "verilated.h"

class Vmaskbus__Syms;
VL_MODULE(Vmaskbus___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN16(i_sw,8,0);
    VL_OUT16(o_led,8,0);

    // INTERNAL VARIABLES
    Vmaskbus__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vmaskbus___024root(const char* name);
    ~Vmaskbus___024root();
    VL_UNCOPYABLE(Vmaskbus___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vmaskbus__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
