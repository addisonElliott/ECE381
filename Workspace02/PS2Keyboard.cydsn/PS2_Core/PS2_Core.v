
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright Addison Elliott, 2016
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 04/21/2016 at 01:25
// Component: PS2_Core
//
// This module reads and writes from the device using the PS/2 protocol.
module PS2_Core (
	output reg [7:0] data_out,		// Data received by the module
    output reg ps2_data_out,		// PS/2 data line(output)
    output reg error,				// Error condition, 1 = error, 0 = none
    output reg done,				// Done condition, 1 = done, 0 = none
    output reg [7:0] state,			// Current state of the machine
    input clock,					// The master clock for the machine
    input reset,					// Resets state machine back to IDLE
    input [7:0] data,				// Byte to be written to device
	input ps2_clock,				// PS/2 clock line(input)
	input ps2_data,					// PS/2 data line(input)
	input wr						// W/~R condition, Write = 1, Read = 0
);

//`#start body` -- edit after this line, do not edit this line
    // States
    localparam IDLE = 0;
    localparam READ_BIT_1 = 1; 
    localparam READ_BIT_2 = 2; 
    localparam READ_BIT_3 = 3; 
    localparam READ_BIT_4 = 4; 
    localparam READ_BIT_5 = 5; 
    localparam READ_BIT_6 = 6; 
    localparam READ_BIT_7 = 7; 
    localparam READ_BIT_8 = 8;
    localparam READ_PARITY = 9; 
    localparam READ_STOP = 10;
	
    localparam WRITE_BIT_1 = 11; 
    localparam WRITE_BIT_2 = 12; 
    localparam WRITE_BIT_3 = 13; 
    localparam WRITE_BIT_4 = 14; 
    localparam WRITE_BIT_5 = 15; 
    localparam WRITE_BIT_6 = 16; 
    localparam WRITE_BIT_7 = 17; 
    localparam WRITE_BIT_8 = 18;
    localparam WRITE_PARITY = 19; 
    localparam WRITE_STOP = 20; 
    localparam WRITE_ACK = 21;
    
	// Note: These states do nothing. The API is expected to reset the machine to go back to IDLE state
    localparam DONE = 22;
    localparam ERROR = 23;
    
    // Internal registers
    reg parity;
    reg last_ps2_clock;
    reg ps2_clock_neg_edge;
	
	// Since the PS/2 clock is only generated when there is an action,
	// we cannot use it in this always statement because we need to be
	// able to reset the state machine at any point
	//
	// Multiple always statements do not work, so we are stuck with storing
	// the previous value of the ps2_clock and then indicating when it has
	// changed from high to low.
    always @(posedge clock) begin
        ps2_clock_neg_edge <= (last_ps2_clock & ~ps2_clock);
        last_ps2_clock <= ps2_clock;

        if (reset) begin // Reset the state machine
            state <= IDLE;
            done <= 1'b0;
            error <= 1'b0;
            parity <= 1'b1; // Odd parity, so XOR with 1 will be 1 for an odd number of zeros, and 0 for an even number
			
			// ps2_data_out is only connected to the ps2_data line when it is in the write state.
			// When initiating a write, there is a point where it switches over from software data to ps2_data_out
			// At that point, the data line needs to be LOW however until another ps2_clock neg edge comes
			// That is why this is 0
			ps2_data_out <= 1'b0;
        end
        else if (ps2_clock_neg_edge) begin // Change data on the negative edge of the ps2_clock
            case (state)
                IDLE: begin
                    if (wr == 1'b1) begin    // Clock line is being held low for 100uS, the next low will be a bit out
                        state <= WRITE_BIT_1;
                    end                    
                    else begin
                        if (ps2_data == 1'b0) begin // If the start bit isnt a 0, there must be an error
                            state <= READ_BIT_1;
                        end
                        else begin
                            error <= 1'b1;
                            state <= ERROR;
                        end
                    end
                end
                            
				// For reading, each bit from ps2_data is transferred into data_out. The parity is XORed with it
				// and the state is changed
                READ_BIT_1: begin data_out[0] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_2; end
                READ_BIT_2: begin data_out[1] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_3; end
                READ_BIT_3: begin data_out[2] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_4; end
                READ_BIT_4: begin data_out[3] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_5; end
                READ_BIT_5: begin data_out[4] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_6; end
                READ_BIT_6: begin data_out[5] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_7; end
                READ_BIT_7: begin data_out[6] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_8; end
                READ_BIT_8: begin data_out[7] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_PARITY; end
                
				// By XORing the parity bit with the parity, the resulting parity SHOULD ALWAYS be zero
				READ_PARITY: begin parity <= parity ^ ps2_data; state <= READ_STOP; end
                
				// If the stop bit isnt a 1 or if the parity is incorrect(parity == 1), there is an error
                READ_STOP: begin
                    if (ps2_data == 1'b1 && !parity) begin
                        state <= DONE;
                        done <= 1'b1;
                    end
                    else begin
                        error <= 1'b1;
                        state <= ERROR;
                    end
                    end
					
				// For writing, each bit from data is transferred to ps2_data_out. The parity is XORed with it
				// and the state is changed
                WRITE_BIT_1: begin ps2_data_out <= data[0]; parity <= parity ^ data[0]; state <= WRITE_BIT_2; end
                WRITE_BIT_2: begin ps2_data_out <= data[1]; parity <= parity ^ data[1]; state <= WRITE_BIT_3; end
                WRITE_BIT_3: begin ps2_data_out <= data[2]; parity <= parity ^ data[2]; state <= WRITE_BIT_4; end
                WRITE_BIT_4: begin ps2_data_out <= data[3]; parity <= parity ^ data[3]; state <= WRITE_BIT_5; end
                WRITE_BIT_5: begin ps2_data_out <= data[4]; parity <= parity ^ data[4]; state <= WRITE_BIT_6; end
                WRITE_BIT_6: begin ps2_data_out <= data[5]; parity <= parity ^ data[5]; state <= WRITE_BIT_7; end
                WRITE_BIT_7: begin ps2_data_out <= data[6]; parity <= parity ^ data[6]; state <= WRITE_BIT_8; end
                WRITE_BIT_8: begin ps2_data_out <= data[7]; parity <= parity ^ data[7]; state <= WRITE_PARITY; end
                
				// Transmit the resulting parity
				WRITE_PARITY: begin ps2_data_out <= parity; state <= WRITE_STOP; end
                
				// A stop bit is a 1
				WRITE_STOP: begin ps2_data_out <= 1'b1; state <= WRITE_ACK; end
                
				// If the transmission was received, the device will pull the data line LOW on next clock cycle
				WRITE_ACK: begin
                    if (ps2_data == 1'b0) begin // ACK received
                        state <= DONE;
                        done <= 1'b1;
                    end
                    else begin // No ACK
                        error <= 1'b1;
                        state <= ERROR;
                    end
                end
                
                DONE: begin
					// These are just dummy loops so that the state machine doesnt do anything else until it is reset
					// XXX - Is this needed? Could we go back to IDLE instead?
                end
                
                ERROR: begin
					// These are just dummy loops so that the state machine doesnt do anything else until it is reset
					// XXX - Is this needed? Could we go back to IDLE instead?
                end
            endcase
        end
    end
    
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
