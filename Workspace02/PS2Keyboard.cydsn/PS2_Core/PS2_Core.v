
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
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
module PS2_Core (
	output reg [7:0] data_out,
    output reg error,
    output reg done,
	output reg   ps2_data_out,
    input [7:0] data,
	input   ps2_clock,
	input   ps2_data,
	output reg [7:0] state,
	input   wr
);

//`#start body` -- edit after this line, do not edit this line
    localparam IDLE = 0, READ_START = 1, READ_BIT_1 = 2, READ_BIT_2 = 3, READ_BIT_3 = 4, READ_BIT_4 = 5, 
               READ_BIT_5 = 6, READ_BIT_6 = 7, READ_BIT_7 = 8, READ_BIT_8 = 9, READ_PARITY = 10, READ_STOP = 11,
               WRITE_START = 12, WRITE_BIT_1 = 13, WRITE_BIT_2 = 14, WRITE_BIT_3 = 15, WRITE_BIT_4 = 16, 
               WRITE_BIT_5 = 17, WRITE_BIT_6 = 18, WRITE_BIT_7 = 19, WRITE_BIT_8 = 20, WRITE_PARITY = 21, WRITE_STOP = 22, WRITE_ACK = 23;
                     
    reg parity;
    
    always @(negedge ps2_clock) begin
        if (!error) begin
            case (state)
                IDLE: begin
                    parity <= 1'b1;
                    error <= 1'b0;
                    done <= 1'b0;
                    
                    if (wr == 1'b1) begin    // Clock line is being held low for 100uS, the next low will be a bit out
                        state <= WRITE_BIT_1;
                    end                    else begin
                        if (data == 1'b0) begin
                            state <= READ_BIT_1;
                        end
                        else begin
                            error <= 1'b1;
                        end
                    end
                end
                            
                READ_BIT_1: begin data_out[0] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_2; end
                READ_BIT_2: begin data_out[1] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_3; end
                READ_BIT_3: begin data_out[2] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_4; end
                READ_BIT_4: begin data_out[3] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_5; end
                READ_BIT_5: begin data_out[4] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_6; end
                READ_BIT_6: begin data_out[5] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_7; end
                READ_BIT_7: begin data_out[6] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_BIT_8; end
                READ_BIT_8: begin data_out[7] <= ps2_data; parity <= parity ^ ps2_data; state <= READ_PARITY; end
                READ_PARITY: begin parity <= parity ^ ps2_data; state <= READ_STOP; end
                            
                READ_STOP: begin
                    if (ps2_data == 1'b1 && parity) begin
                        state <= IDLE;
                        done <= 1'b1;
                    end
                    else begin
                        error <= 1'b1;
                    end
                    end
                
                WRITE_BIT_1: begin ps2_data_out = data[0]; parity <= parity ^ data[0]; state <= WRITE_BIT_2; end
                WRITE_BIT_2: begin ps2_data_out = data[1]; parity <= parity ^ data[1]; state <= WRITE_BIT_3; end
                WRITE_BIT_3: begin ps2_data_out = data[2]; parity <= parity ^ data[2]; state <= WRITE_BIT_4; end
                WRITE_BIT_4: begin ps2_data_out = data[3]; parity <= parity ^ data[3]; state <= WRITE_BIT_5; end
                WRITE_BIT_5: begin ps2_data_out = data[4]; parity <= parity ^ data[4]; state <= WRITE_BIT_6; end
                WRITE_BIT_6: begin ps2_data_out = data[5]; parity <= parity ^ data[5]; state <= WRITE_BIT_7; end
                WRITE_BIT_7: begin ps2_data_out = data[6]; parity <= parity ^ data[6]; state <= WRITE_BIT_8; end
                WRITE_BIT_8: begin ps2_data_out = data[7]; parity <= parity ^ data[7]; state <= WRITE_PARITY; end
                WRITE_PARITY: begin ps2_data_out = parity; state <= WRITE_STOP; end
                WRITE_STOP: begin ps2_data_out = 1'b1; state <= WRITE_ACK; end
                WRITE_ACK: begin
                    if (ps2_data <= 1'b0) begin
                        state <= IDLE;
                        done <= 1'b1;
                    end
                    else begin
                        error <= 1'b1;
                    end
                end
            endcase
        end
    end
    
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
