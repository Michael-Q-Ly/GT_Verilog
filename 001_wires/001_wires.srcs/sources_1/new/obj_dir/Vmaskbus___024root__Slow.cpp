// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaskbus.h for the primary calling header

#include "verilated.h"

#include "Vmaskbus__Syms.h"
#include "Vmaskbus___024root.h"

void Vmaskbus___024root___ctor_var_reset(Vmaskbus___024root* vlSelf);

Vmaskbus___024root::Vmaskbus___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vmaskbus___024root___ctor_var_reset(this);
}

void Vmaskbus___024root::__Vconfigure(Vmaskbus__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vmaskbus___024root::~Vmaskbus___024root() {
}
