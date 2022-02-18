`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/16/2022 03:27:34 AM
// Design Name: 
// Module Name: ledWalker
// Project Name: 
// Target Devices: Digilent Basys 3
// Tool Versions:  Vivado 2020.2
// Description: LED Walker that uses a shift register
// Uses 15 LEDs, each one lighting up one after the other. No LED can be on at
// the same time, however.
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none

module ledWalker2( i_clk, o_led ) ;
	parameter CLK_RATE_HZ = 100_000_000 ;
	parameter NUM_STATE_BITS = 5 ;
	parameter NUM_STATES = 2^^NUM_STATE_BITS - 2 ;
	parameter NUM_LEDS = 16 ;
	input wire i_clk ;
	output reg [NUM_LEDS-1:0] o_led ;

//////////////////////////////////////////////////////////////////////////////////
//				LED Walker FSM					//
//////////////////////////////////////////////////////////////////////////////////

	reg [26:0] wait_counter ;
	reg [NUM_STATE_BITS-1:0] led_index ;
	reg stb ;

	initial { stb, wait_counter } = 0 ;
	always @( posedge i_clk ) begin
		if ( wait_counter == 0 ) begin
			wait_counter <= CLK_RATE_HZ - 1 ;
		end
		else begin
			wait_counter <= wait_counter - 1'b1 ;
		end
	end /* wait_counter */

	always @( posedge i_clk ) begin
		stb <= 1'b0 ;
		if ( wait_counter == 0 ) begin
			stb <= 1'b1 ;
		end
	end /* stb */
	
	initial led_index = 0 ;
	always @( posedge i_clk ) begin
		if ( stb ) begin
			// The logic inside is just what it was before, only
			// the if(stb) changed.
			if ( led_index > NUM_STATES - 2 )  begin
				led_index <= 0 ;					// Reload counter
			end
			else begin
				led_index <= led_index + 1'b1 ;
			end
		end // else nothing changes
		// Wait for stb to be true before changing state
	end /* led_counter */

	initial o_led = 1 ;
	always @( posedge i_clk ) begin
		case ( led_index )
			5'h00	: o_led <= 16'h0001 ;				// Notice: These are One-Hot-Encoded!
			5'h01	: o_led <= 16'h0002 ;
			5'h02	: o_led <= 16'h0004 ;
			5'h03	: o_led <= 16'h0008 ;
			//
			5'h04	: o_led <= 16'h0010 ;
			5'h05	: o_led <= 16'h0020 ;
			5'h06	: o_led <= 16'h0040 ;
			5'h07	: o_led <= 16'h0080 ;
			//
			5'h08	: o_led <= 16'h0100 ;
			5'h09	: o_led <= 16'h0200 ;
			5'h0a	: o_led <= 16'h0400 ;
			5'h0b	: o_led <= 16'h0800 ;
			//
			5'h0c	: o_led <= 16'h1000 ;
			5'h0d	: o_led <= 16'h2000 ;
			5'h0e	: o_led <= 16'h4000 ;
			5'h0f	: o_led <= 16'h8000 ;
            //
			5'h10	: o_led <= 16'h4000 ;
			5'h11	: o_led <= 16'h2000 ;
			5'h12	: o_led <= 16'h1000 ;
			5'h13	: o_led <= 16'h0800 ;
            //
			5'h14	: o_led <= 16'h0400 ;
			5'h15	: o_led <= 16'h0200 ;
			5'h16	: o_led <= 16'h0100 ;
			5'h17	: o_led <= 16'h0080 ;
            //
			5'h18	: o_led <= 16'h0040 ;
			5'h19	: o_led <= 16'h0020 ;
			5'h1a	: o_led <= 16'h0010 ;
			5'h1b	: o_led <= 16'h0008 ;
            //
			5'h1c	: o_led <= 16'h0004 ;
			5'h1d	: o_led <= 16'h0002 ;
            default : o_led <= 16'h0001 ;
		endcase
	end /* Driver/FSM */


//////////////////////////////////////////////////////////////////////////////////
//				Formal Verification				//
//////////////////////////////////////////////////////////////////////////////////
`ifdef FORMAL

	reg [NUM_STATE_BITS-1:0] led_state ;
	initial led_state = 0 ;
	always @( * ) begin
		assert( led_state <= NUM_STATES - 2 ) ;
	end

	// All registers (or wires) used in formal verification will have f_
	// prefixed to them for the rest of the project
	reg f_valid_output ;

	// Check the output of the LED
	always @( * ) begin
		f_valid_output = 0 ;						// Provided a default value so we do not create a latch!
		case ( o_led )
			16'h0001    : f_valid_output = 1'b1 ;
            16'h0002    : f_valid_output = 1'b1 ;
            16'h0004    : f_valid_output = 1'b1 ;
            16'h0008    : f_valid_output = 1'b1 ;
            //
            16'h0010    : f_valid_output = 1'b1 ;
            16'h0020    : f_valid_output = 1'b1 ;
            16'h0040    : f_valid_output = 1'b1 ;
            16'h0080    : f_valid_output = 1'b1 ;
            //
            16'h0100    : f_valid_output = 1'b1 ;
            16'h0200    : f_valid_output = 1'b1 ;
            16'h0400    : f_valid_output = 1'b1 ;
            16'h0800    : f_valid_output = 1'b1 ;
            //
            16'h1000    : f_valid_output = 1'b1 ;
            16'h2000    : f_valid_output = 1'b1 ;
            16'h4000    : f_valid_output = 1'b1 ;
            16'h8000    : f_valid_output = 1'b1 ;
		endcase

		assert( f_valid_output ) ;
	end

	// Check the wait counter
	always @( posedge i_clk ) begin
		assert( wait_counter <= CLK_RATE_HZ - 1 ) ;
	end

	// Check the strobe enable
	always @( posedge i_clk ) begin
		assert ( stb == ( wait_counter == 0 ) ) ;
	end
	
	// Quick cover property
	always @( * ) begin
		cover( ( led_index = 0 ) && ( o_led == 4'h2 ) ) ;
	end
`endif
endmodule

