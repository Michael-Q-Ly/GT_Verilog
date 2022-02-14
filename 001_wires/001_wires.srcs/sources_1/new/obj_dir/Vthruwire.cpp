// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vthruwire.h"
#include "Vthruwire__Syms.h"

//============================================================
// Constructors

Vthruwire::Vthruwire(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vthruwire__Syms(_vcontextp__, _vcname__, this)}
    , i_sw{vlSymsp->TOP.i_sw}
    , o_led{vlSymsp->TOP.o_led}
    , rootp{&(vlSymsp->TOP)}
{
}

Vthruwire::Vthruwire(const char* _vcname__)
    : Vthruwire(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vthruwire::~Vthruwire() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vthruwire___024root___eval_initial(Vthruwire___024root* vlSelf);
void Vthruwire___024root___eval_settle(Vthruwire___024root* vlSelf);
void Vthruwire___024root___eval(Vthruwire___024root* vlSelf);
#ifdef VL_DEBUG
void Vthruwire___024root___eval_debug_assertions(Vthruwire___024root* vlSelf);
#endif  // VL_DEBUG
void Vthruwire___024root___final(Vthruwire___024root* vlSelf);

static void _eval_initial_loop(Vthruwire__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vthruwire___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vthruwire___024root___eval_settle(&(vlSymsp->TOP));
        Vthruwire___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vthruwire::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vthruwire::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vthruwire___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vthruwire___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vthruwire::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vthruwire::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vthruwire::final() {
    Vthruwire___024root___final(&(vlSymsp->TOP));
}
