`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 01:34:16 PM
// Design Name: 
// Module Name: ledWalker
// Project Name: 
// Target Devices: Digilent Basys 3
// Tool Versions:  Vivado 2020.2
// Description: LED Walker that uses a shift register
// Uses 8 LEDs, each getting dimmer than the previous one
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none

module ledWalker( i_clk, o_led ) ;
	parameter CLK_RATE_HZ = 100_000_000 ;
	input wire i_clk ;
//	input wire i_btnC ;
	output reg [7:0] o_led ;

`ifdef concatenationOperator
	// The concatenation operator composes a new bit-vecor from other
	// pieces. This one shifts o_led's bits  left with wrap!
	always @( posedge i_clk ) begin
		o_led <= { o_led[6:0], o_led[7] } ;
		/**
		* This is equivalent to the following:
		* oled[0] <= o_led[7] ;
		* oled[1] <= o_led[0] ;
		* oled[2] <= o_led[1] ;
		* oled[3] <= o_led[2] ;
		* oled[4] <= o_led[3] ;
		* oled[5] <= o_led[4] ;
		* oled[6] <= o_led[5] ;
		* oled[7] <= o_led[6] ;
		*/
	end
`endif /* concatenationOperator */

`ifdef shiftRegister
	always @( posedge i_clk ) begin
		o_led <= o_led[6:0], i_btnC } ;					// LSB to MSB
		// o_led <= { i_btnC, o_led[7:1] } ;				// MSB to LSB
`endif /* shiftRegister */

`ifdef strobe
	/**
	* We can create an LED display by mixing the shfit register with
	* a counter to slow it down
	*/
	reg [26:0] counter ;
	reg stb ;								// Strobe signal
	initial { stb, counter } = 0 ;
	always @( posedge i_clk ) begin
		{ stb, counter } <= counter + 1'b1 ;
	end

	initial o_led = 8'h1 ;
	always @( posedge i_clk ) begin
		if ( stb ) begin
			o_led <= { o_led[6:0], o_led[7] } ;
		end
	end
`endif /* strobe */
//////////////////////////////////////////////////////////////////////////////////
//				LED Walker FSM					//
//////////////////////////////////////////////////////////////////////////////////

// inputs and outputs are already declared
	reg [26:0] wait_counter ;
	reg [3:0] led_index ;
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
			if ( led_index > 4'd12 ) begin
				led_index <= 0 ;					// Reload counter
			end
			else begin
				led_index <= led_index + 1'b1 ;
			end
		end // else nothing changes
		// Wait for stb to be true before changing state
	end /* led_counter */

	initial o_led = 8'h01 ;
	always @( posedge i_clk ) begin
		case ( led_index )
			4'h0    : o_led <= 8'h01 ;				// Notice: These are One-Hot-Encoded!
			4'h1    : o_led <= 8'h02 ;
			4'h2    : o_led <= 8'h04 ;
			4'h3    : o_led <= 8'h08 ;
			//
			4'h4    : o_led <= 8'h10 ;
			4'h5    : o_led <= 8'h20 ;
			4'h6    : o_led <= 8'h40 ;
			4'h7    : o_led <= 8'h80 ;
			//
			4'h8    : o_led <= 8'h40 ;
			4'h9    : o_led <= 8'h20 ;
			4'ha    : o_led <= 8'h10 ;
			4'hb    : o_led <= 8'h08 ;
			//
			4'hc    : o_led <= 8'h04 ;
			4'hd    : o_led <= 8'h02 ;
			default : o_led <= 8'h01 ;
		endcase
	end /* Driver/FSM */


//////////////////////////////////////////////////////////////////////////////////
//				Formal Verification				//
//////////////////////////////////////////////////////////////////////////////////
`ifdef FORMAL

	reg [3:0] led_state ;
	initial led_state = 0 ;
	always @( * ) begin
		assert( led_state <= 4'd12 ) ;
	end

	// All registers (or wires) used in formal verification will have f_
	// prefixed to them for the rest of the project
	reg f_valid_output ;

	// Check the output of the LED
	always @( * ) begin
		f_valid_output = 0 ;						// Provided a default value so we do not create a latch!
		case ( o_led )
			8'h01: f_valid_output = 1'b1 ;
			8'h02: f_valid_output = 1'b1 ;
			8'h04: f_valid_output = 1'b1 ;
			8'h08: f_valid_output = 1'b1 ;
			8'h10: f_valid_output = 1'b1 ;
			8'h20: f_valid_output = 1'b1 ;
			8'h40: f_valid_output = 1'b1 ;
			8'h80: f_valid_output = 1'b1 ;
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

