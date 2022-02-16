// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VledWalker.h for the primary calling header

#include "verilated.h"

#include "VledWalker__Syms.h"
#include "VledWalker___024root.h"

void VledWalker___024root___ctor_var_reset(VledWalker___024root* vlSelf);

VledWalker___024root::VledWalker___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VledWalker___024root___ctor_var_reset(this);
}

void VledWalker___024root::__Vconfigure(VledWalker__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VledWalker___024root::~VledWalker___024root() {
}
