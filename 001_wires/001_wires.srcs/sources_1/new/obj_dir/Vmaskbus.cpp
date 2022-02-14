// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmaskbus.h"
#include "Vmaskbus__Syms.h"

//============================================================
// Constructors

Vmaskbus::Vmaskbus(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vmaskbus__Syms(_vcontextp__, _vcname__, this)}
    , i_sw{vlSymsp->TOP.i_sw}
    , o_led{vlSymsp->TOP.o_led}
    , rootp{&(vlSymsp->TOP)}
{
}

Vmaskbus::Vmaskbus(const char* _vcname__)
    : Vmaskbus(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vmaskbus::~Vmaskbus() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmaskbus___024root___eval_initial(Vmaskbus___024root* vlSelf);
void Vmaskbus___024root___eval_settle(Vmaskbus___024root* vlSelf);
void Vmaskbus___024root___eval(Vmaskbus___024root* vlSelf);
#ifdef VL_DEBUG
void Vmaskbus___024root___eval_debug_assertions(Vmaskbus___024root* vlSelf);
#endif  // VL_DEBUG
void Vmaskbus___024root___final(Vmaskbus___024root* vlSelf);

static void _eval_initial_loop(Vmaskbus__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmaskbus___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmaskbus___024root___eval_settle(&(vlSymsp->TOP));
        Vmaskbus___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vmaskbus::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmaskbus::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmaskbus___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmaskbus___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vmaskbus::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vmaskbus::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmaskbus::final() {
    Vmaskbus___024root___final(&(vlSymsp->TOP));
}
