// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vblinky__Syms.h"
#include "Vblinky.h"
#include "Vblinky___024root.h"

// FUNCTIONS
Vblinky__Syms::~Vblinky__Syms()
{
}

Vblinky__Syms::Vblinky__Syms(VerilatedContext* contextp, const char* namep,Vblinky* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
