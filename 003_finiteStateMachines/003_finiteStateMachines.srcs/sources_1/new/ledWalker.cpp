/**
 * File Name		: ledWalker.cpp
 * Purpose		: Testbench for ledWalker.v
 * Author		: Michael Ly
 * Date			: Feb 15, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "VledWalker.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick( int tick_count, VledWalker *tb, VerilatedVcdC *tfp ) ;

int main( int argc, char**argv ) {
	int last_led {} ;
	unsigned tick_count {} ;

	// Call commandArgs first!
	Verilated::commandArgs( argc, argv ) ;
	// Instantiate our design
	VledWalker *tb = new VledWalker ;
	// Generate a trace
	Verilated::traceEverOn( true ) ;
	VerilatedVcdC *tfp = new VerilatedVcdC ;
	tb -> trace( tfp, 99 ) ;
	tfp -> open( "ledWalker.vcd" ) ;

	last_led = tb -> o_led ;
	for ( int k = 0 ; k < ( 1 << 10 ) ; k++ ) {
		tick( ++tick_count, tb, tfp ) ;

		// Print our results
		if ( last_led != tb -> o_led ) {
			printf( "k   = %7d\t", k ) ;
			printf( "LED = %02x\t", tb -> o_led ) ;
			for ( int j = 0 ; j < 8 ; j++ ) {
				if ( tb -> o_led & ( 1 << j ) ) {
					printf( "O" ) ;
				}
				else {
					printf( "-" ) ;
				}
			} /* j */
			printf( "\n" ) ;
			last_led = tb -> o_led ;
		} /* outer-if */
	} /* k */
}

void tick( int tick_count, VledWalker *tb, VerilatedVcdC *tfp ) {
	tb -> eval() ;
	if ( tfp ) {
		tfp -> dump( ( 10*tick_count - 2 ) ) ;
	}
	tb -> i_clk = 1 ;
	tb -> eval() ;
	if ( tfp ) {
		tfp -> dump( 10*tick_count ) ;
	}
	tb -> i_clk = 0 ;
	tb -> eval() ;
	if ( tfp ) {
		tfp -> dump( 10*tick_count + 5 ) ;
		tfp -> flush() ;
	}
}

