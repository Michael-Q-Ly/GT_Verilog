`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/14/2022 11:46:03 PM
// Design Name: 
// Module Name: fractionalClockDivider
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: After CLOCK_RATE_HZ clock edges, the counter will
// roll over.
// The divide by four is just to keep this iwthin 32-bit arithmatic
// INCREMENT = 2^^32 / CLOCK_RATE_HZ
//
// The division isn't exact, but it's often good enough
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none

module fractionalClockDivider( i_clk, o_led ) ;
	parameter CLOCK_RATE_HZ = 100_000_000 ;
	parameter [31:0] INCREMENT = ( 1 << 30 ) / ( CLOCK_RATE_HZ / 4 ) ;

	input wire i_clk ;
	output wire o_led ;

	reg [31:0] counter ;
	
	initial counter = 0 ;
	always @( posedge i_clk ) begin
		counter <= counter + INCREMENT ;
	end
	
	assign o_led = counter[31] ;
endmodule
