`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/14/2022 09:58:03 PM
// Design Name: 
// Module Name: strobe
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
module strobe( i_clk, o_led ) ;
	input wire i_clk ;
	output wire o_led ;

	reg [26:0] counter ;

	always @( posedge i_clk ) begin
		counter <= counter + 1'b1 ;
	end

	assign o_led = &counter[26:24] ;
endmodule
