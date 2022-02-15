`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 12:34:41 AM
// Design Name: 
// Module Name: stretch
// Project Name: 
// Target Devices: Basys 3
// Tool Versions: Vivado 2020.2
// Description: FPGA signals are often too fast to see, so this
// design slows those signals down to eye speed. It only works for
// a single event, though: multiple events would overlap
// and no longer be distinct.
//
// The concept is simple: The FPGA will ONLY blink the LED ONCE, and
// that is when the user presses the center button on the Basys 3.
// Why is that? That is because the counter is not set until the
// user presses  the button. At which point, it sets all bits
// in the vector to zero. The next positive clock edge will catch
// the zero-array and then increment the counter. In the time it takes
// to increment the counter to set the 26th bit, we see the LED light
// up because the 26th bit is 0 up until that point. We thus
// "stretch out the LED signal."
//
// This design uses LED0, the 100MHz clock, and the center button, btnC
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`default_nettype	none
module stretch( i_clk, i_event, o_led ) ;
	input wire i_clk ;
	input wire i_event ;
	output wire o_led ;

	reg [26:0] counter ;

	always @( posedge i_clk ) begin
		if ( i_event ) begin
			counter <= 0 ;
		end
		else if ( !counter[26] ) begin
			counter <= counter + 1 ;
		end
	end

	assign o_led = !counter[26] ;
endmodule
