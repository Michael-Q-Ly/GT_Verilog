// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLEDWALKER__SYMS_H_
#define VERILATED_VLEDWALKER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VledWalker.h"

// INCLUDE MODULE CLASSES
#include "VledWalker___024root.h"

// SYMS CLASS (contains all model state)
class VledWalker__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VledWalker* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VledWalker___024root           TOP;

    // CONSTRUCTORS
    VledWalker__Syms(VerilatedContext* contextp, const char* namep, VledWalker* modelp);
    ~VledWalker__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
