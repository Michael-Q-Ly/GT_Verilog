`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/14/2022 11:24:41 PM
// Design Name: 
// Module Name: integerClockDivider
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
module integerClockDivider( i_clk, o_led ) ;
	parameter CLOCK_RATE_HZ = 100_000_000 ;					// Basys 3 default clock pin is 100 MHz

	input wire i_clk ;
	output reg o_led ;

	reg [26:0] counter ;
	initial counter = 0 ;

	always @( posedge i_clk ) begin
		if ( counter >= CLOCK_RATE_HZ/2 - 1 ) begin
			counter <= 0 ;
			o_led <= !o_led ;
		end
		else begin
			counter <= counter + 1 ;
		end
	end
endmodule
