// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vthruwire.h for the primary calling header

#include "verilated.h"

#include "Vthruwire__Syms.h"
#include "Vthruwire___024root.h"

void Vthruwire___024root___ctor_var_reset(Vthruwire___024root* vlSelf);

Vthruwire___024root::Vthruwire___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vthruwire___024root___ctor_var_reset(this);
}

void Vthruwire___024root::__Vconfigure(Vthruwire__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vthruwire___024root::~Vthruwire___024root() {
}
