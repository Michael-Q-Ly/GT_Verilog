// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vblinky.h"
#include "Vblinky__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vblinky::Vblinky(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vblinky__Syms(_vcontextp__, _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , o_led{vlSymsp->TOP.o_led}
    , rootp{&(vlSymsp->TOP)}
{
}

Vblinky::Vblinky(const char* _vcname__)
    : Vblinky(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vblinky::~Vblinky() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vblinky___024root___eval_initial(Vblinky___024root* vlSelf);
void Vblinky___024root___eval_settle(Vblinky___024root* vlSelf);
void Vblinky___024root___eval(Vblinky___024root* vlSelf);
#ifdef VL_DEBUG
void Vblinky___024root___eval_debug_assertions(Vblinky___024root* vlSelf);
#endif  // VL_DEBUG
void Vblinky___024root___final(Vblinky___024root* vlSelf);

static void _eval_initial_loop(Vblinky__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vblinky___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vblinky___024root___eval_settle(&(vlSymsp->TOP));
        Vblinky___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vblinky::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vblinky::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vblinky___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vblinky___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vblinky::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vblinky::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vblinky::final() {
    Vblinky___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vblinky___024root__trace_init_top(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vblinky___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinky___024root*>(voidSelf);
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vblinky___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vblinky___024root__trace_register(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vblinky::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vblinky___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
