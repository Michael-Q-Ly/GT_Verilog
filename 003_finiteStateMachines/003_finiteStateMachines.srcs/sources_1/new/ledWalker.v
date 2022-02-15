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

	/**
	* We can create an LED display by mixing the shfit register with
	* a counter to slow it down
	*/
	reg [26:0] counter ;
	reg stb ;								// Strobe signal
	initial { stb, counter } = 0 ;
	always @( posedge i_clk ) begin
		{ stb, counter } = counter + 1'b1 ;
	end
`ifdef strobe
	initial o_led = 8'h1 ;
	always @( posedge i_clk ) begin
		if ( stb ) begin
			o_led <= { o_led[6:0], o_led[7] } ;
		end
	end
`endif /* strobe */
//////////////////////////////////////////////////////////////////////////
//				LED Walker FSM				//
//////////////////////////////////////////////////////////////////////////

// inputs and outputs are already declared

	reg [3:0] led_index ;
	initial led_index = 0 ;
	always @( posedge i_clk ) begin
		if ( led_index > 4'd13 ) begin
			led_index <= 0 ;					// Reload counter
		end
		else begin
			led_index <= led_index + 1'b1 ;
		end
	end /* led_counter */

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
endmodule
