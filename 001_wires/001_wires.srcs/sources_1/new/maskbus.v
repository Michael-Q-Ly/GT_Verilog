`default_nettype		none

module maskbus( i_sw, o_led ) ;
	input wire [8:0] i_sw ;
	output wire [8:0] o_led ;

	wire [8:0] w_internal ;

	assign w_internal = 9'h87 ;
	assign o_led = i_sw ^ w_internal ;

endmodule

