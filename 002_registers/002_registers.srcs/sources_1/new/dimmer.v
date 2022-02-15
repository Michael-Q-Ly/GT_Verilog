`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 01:56:58 AM
// Design Name: 
// Module Name: dimmer
// Project Name: 
// Target Devices: Digilent Basys 3
// Tool Versions: Vivado 2020.2
// Description: Tasked with finding out what the given design does.
// My guess, based off the module name, is that it creates an LED
// that is dimmer than usual. How? The answer lies within the assign
// statement at the very bottom. We see that so long as the LSB is smaller
// than the MSB, then the output LED will be HIGH. But every 8 bits, the LSB
// will have to reset. Perhaps this is like a PWM circuit? Since the FPGA
// signals are much too fast for the human eye, the switching frequency
// of the LED makes the LED appear dimmer!
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none

module dimmer( i_clk, o_led ) ;
	input wire i_clk ;
	output wire o_led ;

	reg [27:0] counter ;

	always @( posedge i_clk ) begin
		counter <= counter + 1 ;
	end

	assign o_led = ( counter[7:0] < counter[27:0] ) ;
endmodule
