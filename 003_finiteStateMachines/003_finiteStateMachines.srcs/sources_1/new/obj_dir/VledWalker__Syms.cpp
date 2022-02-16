// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VledWalker__Syms.h"
#include "VledWalker.h"
#include "VledWalker___024root.h"

// FUNCTIONS
VledWalker__Syms::~VledWalker__Syms()
{
}

VledWalker__Syms::VledWalker__Syms(VerilatedContext* contextp, const char* namep,VledWalker* modelp)
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
