// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinky.h for the primary calling header

#include "verilated.h"

#include "Vblinky__Syms.h"
#include "Vblinky___024root.h"

void Vblinky___024root___ctor_var_reset(Vblinky___024root* vlSelf);

Vblinky___024root::Vblinky___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vblinky___024root___ctor_var_reset(this);
}

void Vblinky___024root::__Vconfigure(Vblinky__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vblinky___024root::~Vblinky___024root() {
}
