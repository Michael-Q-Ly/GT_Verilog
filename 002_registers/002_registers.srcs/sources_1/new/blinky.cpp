// blinky.cpp

#include <stdio.h>
#include <stdlib.h>
#include "Vblinky.h"
#include "verilated.h"

void tick( Vblinky *tb ) ;

int main( int argc, char **argv ) {
	
	// Setup
	Verilated::commandArgs( argc, argv ) ;					// Call commandArgs first
	Vblinky *tb = new Vblinky ;						// Instantiate our design
	int last_led ;

	last_led = tb -> o_led ;
	for ( int k = 0 ; k < ( 1 << 20 ) ; k++ ) {
		// Toggle the clock
		tick( tb ) ;

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
void tick( Vblinky *tb ) {

	/**
	 * We need to toggle the clock input for anything to happen.
	 * This operation is so common, it desrves its own function,
	 * tick()
	 */

	// The following eval() looks redundant...
	// it is not, however.
	tb -> eval() ;
	tb -> i_clk = 1 ;
	tb -> eval() ;
	tb -> i_clk = 0 ;
	tb -> eval() ;
}

