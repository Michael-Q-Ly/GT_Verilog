// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VledWalker.h"
#include "VledWalker__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VledWalker::VledWalker(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VledWalker__Syms(_vcontextp__, _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , o_led{vlSymsp->TOP.o_led}
    , rootp{&(vlSymsp->TOP)}
{
}

VledWalker::VledWalker(const char* _vcname__)
    : VledWalker(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VledWalker::~VledWalker() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VledWalker___024root___eval_initial(VledWalker___024root* vlSelf);
void VledWalker___024root___eval_settle(VledWalker___024root* vlSelf);
void VledWalker___024root___eval(VledWalker___024root* vlSelf);
#ifdef VL_DEBUG
void VledWalker___024root___eval_debug_assertions(VledWalker___024root* vlSelf);
#endif  // VL_DEBUG
void VledWalker___024root___final(VledWalker___024root* vlSelf);

static void _eval_initial_loop(VledWalker__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VledWalker___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VledWalker___024root___eval_settle(&(vlSymsp->TOP));
        VledWalker___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VledWalker::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VledWalker::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VledWalker___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VledWalker___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VledWalker::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VledWalker::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VledWalker::final() {
    VledWalker___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void VledWalker___024root__trace_init_top(VledWalker___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VledWalker___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VledWalker___024root*>(voidSelf);
    VledWalker__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VledWalker___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VledWalker___024root__trace_register(VledWalker___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VledWalker::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VledWalker___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
