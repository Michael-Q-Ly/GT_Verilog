`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 01:05:51 AM
// Design Name: 
// Module Name: tooSlow
// Project Name: 
// Target Devices: Digilent Basys 3
// Tool Versions: Vivado 2020.2 
// Description: This module fails a timing check ; it is much too slow.
// Unreasonable so.
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none

module tooSlow( i_clk, o_led ) ;
	input wire i_clk ;
	output wire o_led ;

	parameter NBITS = 1024 ;
	reg [NBITS-1:0] counter ;

	always @( posedge i_clk ) begin
		counter <= counter + 1 ;
	end

	assign o_led = counter[NBITS-1] ;
endmodule
