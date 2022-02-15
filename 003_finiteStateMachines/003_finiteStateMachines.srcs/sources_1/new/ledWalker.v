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
	output reg [7:0] o_led ;
	
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
endmodule
