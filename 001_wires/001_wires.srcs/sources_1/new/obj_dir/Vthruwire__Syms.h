// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTHRUWIRE__SYMS_H_
#define VERILATED_VTHRUWIRE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vthruwire.h"

// INCLUDE MODULE CLASSES
#include "Vthruwire___024root.h"

// SYMS CLASS (contains all model state)
class Vthruwire__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vthruwire* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vthruwire___024root            TOP;

    // CONSTRUCTORS
    Vthruwire__Syms(VerilatedContext* contextp, const char* namep, Vthruwire* modelp);
    ~Vthruwire__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
