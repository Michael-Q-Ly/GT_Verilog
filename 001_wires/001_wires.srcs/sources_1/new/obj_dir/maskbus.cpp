#include <stdio.h>
#include <stdlib.h>
#include "Vthruwire.h"
#include "verilated.h"

int main( int argc, char **argv ) {
	// Call comandArgs first!
	Verilated::commandArgs( argc, argv ) ;

	// Instantiate our design
	Vthruwire *tb = new Vthruwire ;

	// Now run the design through 20 timesteps
	for ( int k = 0 ; k < 20 ; k++ ) {
		// Bottom 9 bits of counter
		tb -> i_sw = k & 0x1FF ;

		tb -> eval() ;

		// Now, let's print our results
		printf( "k = %2d, ", k ) ;
		printf( "sw = %3x, ", tb -> i_sw ) ;
		printf( "led = %3x\n", tb -> o_led ) ;
	}

}

