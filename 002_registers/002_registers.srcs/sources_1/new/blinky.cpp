// blinky.cpp

#include <stdio.h>
#include <stdlib.h>
#include "Vblinky.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick( int tick_count, Vblinky *tb, VerilatedVcdC *tfp ) ;

int main( int argc, char **argv ) {
	
	// Setup
	Verilated::commandArgs( argc, argv ) ;					// Call commandArgs first
	Vblinky *tb = new Vblinky ;						// Instantiate our design
	// Generate a trace
	Verilated::traceEverOn( true ) ;
	VerilatedVcdC *tfp = new VerilatedVcdC ;				// Allocate memory for trace file ptr
	tb -> trace( tfp, 99 ) ;
	tfp -> open( "blinkytrace.vcd" ) ;

	int last_led ;
	unsigned tick_count  {0} ;

	last_led = tb -> o_led ;
	for ( int k = 0 ; k < ( 1 << 20 ) ; k++ ) {
		// Toggle the clock
		tick( ++tick_count, tb, tfp ) ;

		// How let's print the LED's value
		// any time it changes
		if (last_led != tb -> o_led ) {
			printf( "k = %7d, ", k ) ;
			printf( "LED = %d\n ", tb -> o_led ) ;
		}

		last_led = tb -> o_led ;
    }
}

// Simulating our blinky design requires a clock:
void tick( int tick_count, Vblinky *tb, VerilatedVcdC *tfp ) {

	/**
	 * We need to toggle the clock input for anything to happen.
	 * This operation is so common, it desrves its own function,
	 * tick()
	 */

	// The following eval() looks redundant...
	// it is not, however.
	// Let's write trace data on every clock
	tb -> eval() ;
	if ( tfp ) {								// Dump 2ns before the tick
		tfp -> dump( ( 10*tick_count ) - 2 ) ;
	}
	tb -> i_clk = 1 ;
	tb -> eval() ;
	if ( tfp ) {								// Tick every 10ns 
		tfp -> dump( 10*tick_count ) ;
	}
	tb -> i_clk = 0 ;
	tb -> eval() ;
	if ( tfp ) {								// Trailing edge dump
		tfp -> dump( ( 10*tick_count ) + 5 ) ;
		tfp -> flush() ;
	}
}

