`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/14/2022 04:19:01 PM
// Design Name: 
// Module Name: blinky
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none
//
module blinky( i_clk, o_led ) ;
`ifdef	VERILATOR
	parameter WIDTH = 12;
`else
	parameter WIDTH = 27;
`endif
	input wire i_clk;
	output wire	o_led;

	reg	[WIDTH-1:0]	counter;

	always @(posedge i_clk)
		counter <= counter + 1'b1;

	assign	o_led = counter[WIDTH-1];
endmodule
