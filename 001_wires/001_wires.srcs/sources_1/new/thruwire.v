`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/13/2022 10:09:45 PM
// Design Name: 
// Module Name: thruwire
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


module thruwire( i_sw, o_led );
	input wire i_sw ;
	output wire o_led ;
	
	assign o_led = i_sw ;
endmodule
