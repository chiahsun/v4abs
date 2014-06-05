module LCD_CTRL(clk, reset, datain, cmd, cmd_valid, dataout, output_valid, busy);
input           clk;
input           reset;
input   [7:0]   datain;
input   [3:0]   cmd;
input           cmd_valid;

output  [7:0]   dataout;
output          output_valid;
output          busy;

integer         i,j,x,y;
reg     [7:0]   data_out;
reg     [7:0]   in [0:107];
reg     [7:0]   out [0:15];
reg     [2:0]   current_state;
reg     [2:0]   next_current_state;
reg     [3:0]   cmd_r;
reg     [3:0]   next_cmd;
reg             outputvalid;
reg             busy;
reg     [6:0]   cnt;
reg     [6:0]   next_cnt;
reg     [4:0]   cnt2;
reg     [4:0]   cnt3;
reg     [4:0]   cnt4;
reg     [4:0]   next_cnt2;
reg     [4:0]   next_cnt3;
reg     [4:0]   next_cnt4;


assign dataout = data_out;
assign output_valid = outputvalid;

parameter  S_IDLE     = 3'b000
         , S_READ     = 3'b001
         , S_FIT      = 3'b010
         , S_RIGHT    = 3'b011
         , S_LEFT     = 3'b100
         , S_INLEFT   = 3'b101
         , S_INRIGHT  = 3'b110
         , S_IN       = 3'b111;
	
  /* ============================================ */

    always @ (posedge clk or posedge reset) begin
        cmd_r <= ( reset==1'b1 ) ? 4'd0 : next_cmd;
        current_state <= ( reset==1'b1 ) ? S_IDLE : next_current_state; 
    end

  /* ============================================ */

    always @ (*) begin
        next_cmd = (cmd_valid == 1'b1) ? cmd : next_cmd;
        
        if(reset) next_current_state = S_IDLE;
        else begin
            case( current_state )
                S_IDLE : next_current_state = (cmd_r == 4'd0) ? S_READ : S_IDLE;
                S_READ : begin
                    if( cmd_r == 4'd0 && cnt < 7'd107 ) next_current_state = S_READ;
                    else if( cmd_r == 4'd0 ) next_current_state = S_FIT;
                    else next_current_state = S_IDLE;
                end
		S_FIT   : begin
                    if( cmd == 4'd0 ) next_current_state = S_READ;
                    else if( cmd_r == 4'd1 && cnt2 > 5'd17 ) next_current_state = S_RIGHT;
                    else if( cmd_r == 4'd2 && cnt2 > 5'd17 ) next_current_state = S_LEFT;
                    else if( cmd_r == 4'd3 && cnt2 > 5'd15 ) begin
                        next_current_state = S_IN;
                        x = 6;
                        y = 5;
                    end
                    else next_current_state = S_FIT;

                    if( cmd_r >= 4'd4 && cnt2 > 5'd18 ) cnt2 = 5'd0;

                end
                S_RIGHT: begin
                    if( cmd == 4'd0 ) next_current_state = S_READ;
                    else if( cmd_r == 4'd2 && cnt3 > 5'd15 ) next_current_state = S_FIT;
                    else if( cmd_r == 4'd3 && cnt3 > 5'd15 ) begin
                        next_current_state = S_INRIGHT;
                        x = 5;
                        y = 6;
                    end
                    else next_current_state = S_RIGHT;

                    if( cmd_r == 4'd1 && cnt3 > 5'd18 ) cnt3 = 5'd0;
                    else if( cmd_r >= 4'd4 && cnt3 > 5'd18 ) cnt3 = 5'd0;
                end
                S_LEFT : begin 
                    if( cmd == 4'd0 ) next_current_state = S_READ;
                    else if( cmd_r == 4'd1 && cnt4 > 5'd15 ) next_current_state = S_FIT;
                    else if( cmd_r == 4'd3 && cnt4 > 5'd15 ) begin
                        next_current_state = S_INLEFT;
                        x = 5;
                        y = 6;
                    end
                    else next_current_state = S_LEFT;

                    if( cmd_r == 4'd2 && cnt4 > 5'd18 ) cnt4 = 5'd0;
                    else if( cmd_r >= 4'd4 && cnt4 > 5'd18 ) cnt4 = 5'd0;
                end
                S_INLEFT: begin
                    if( cmd_r == 4'd4 ) next_current_state = S_LEFT;
                    else next_current_state = S_INLEFT;
 
                    if( cmd_r == 4'd5 && x < 7 && cnt3 > 5'd17 ) x = x + 1;
                    else if( cmd_r == 4'd6 && x > 2  && cnt3 > 5'd17 ) x = x - 1;
                    else if( cmd_r == 4'd7 && y < 10 && cnt3 > 5'd17 ) y = y + 1;
                    else if( cmd_r == 4'd8 && y > 2  && cnt3 > 5'd17 ) y = y - 1;

                    if( cmd_r == 4'd3 && cnt3 > 5'd18 ) cnt3 = 5'd0;
                    else if( cmd_r >= 4'd5 && cnt3 > 5'd17 ) cnt3 = 5'd0;

                end
                S_INRIGHT: begin
                    if( cmd_r == 4'd4 ) next_current_state = S_RIGHT;
                    else next_current_state = S_INRIGHT;

                    if( cmd_r == 4'd5 && x > 2 && cnt2 > 5'd17 ) x = x - 1;
                    else if( cmd_r == 4'd6 && x < 7  && cnt2 > 5'd17 ) x = x + 1;
                    else if( cmd_r == 4'd7 && y > 2  && cnt2 > 5'd17 ) y = y - 1;
                    else if( cmd_r == 4'd8 && y < 10 && cnt2 > 5'd17 ) y = y + 1;

                    if( cmd_r == 4'd3 && cnt2 > 5'd18 ) cnt2 = 5'd0;
                    else if( cmd_r >= 4'd5 && cnt2 > 5'd17 ) cnt2 = 5'd0;

                end
                S_IN  : begin
                    if( cmd_r == 4'd4 ) next_current_state = S_FIT;
                    else next_current_state = S_IN;
                    
                    if( cmd_r == 4'd5 && x < 10 && cnt4 > 5'd17 ) x = x + 1;
                    else if( cmd_r == 4'd6 && x > 2 && cnt4 > 5'd17 ) x = x - 1;
                    else if( cmd_r == 4'd7 && y > 2 && cnt4 > 5'd17 ) y = y - 1;
                    else if( cmd_r == 4'd8 && y < 7 && cnt4 > 5'd17 ) y = y + 1;

                    if( cmd_r == 4'd3 && cnt4 > 5'd18 ) cnt4 = 5'd0;
                    else if( cmd_r >= 4'd5 && cnt4 > 5'd17 ) cnt4 = 5'd0;
                end
                default: next_current_state = S_IDLE;
            endcase
        end
    end

  /* ============================================ */

    always @ (*) begin
        if( current_state == S_READ ) next_cnt = cnt + 1'b1;
        else next_cnt = 1'b0;
 
        if( current_state == S_FIT || current_state == S_INRIGHT ) next_cnt2 = cnt2 + 1'b1;
        else next_cnt2 = 1'b0;

        if( current_state == S_RIGHT || current_state == S_INLEFT ) next_cnt3 = cnt3 + 1'b1;
        else next_cnt3 = 1'b0;

        if( current_state == S_LEFT || current_state == S_IN ) next_cnt4 = cnt4 + 1'b1;
        else next_cnt4 = 1'b0;
    end

    always @ (posedge clk or posedge reset) begin
        cnt <= next_cnt;
        cnt2 <= next_cnt2;
        cnt3 <= next_cnt3;
        cnt4 <= next_cnt4;       
    end
    
  /* ============================================ */
    always @ (*) begin
        for( i = 0 ; i < 4 ; i=i+1 )
            for( j = 0 ; j < 4 ; j=j+1 ) begin
                if( current_state == S_FIT ) out[i*4+j] = in[ ((13+3*j)+24*i) ];
                else if( current_state == S_RIGHT ) out[i*4+j] = in[ ((85-24*j)+3*i) ];
                else if( current_state == S_LEFT  ) out[i*4+j] = in[ ((22+24*j)-3*i) ];
                else if( current_state == S_INRIGHT ) out[i*4+j]=in[ (x+1-j)*12+(y-2+i) ];
                else if( current_state == S_INLEFT  ) out[i*4+j]=in[ (x-2+j)*12+(y+1-i) ];
                else if( current_state == S_IN      ) out[i*4+j]=in[ (y-2+i)*12+(x-2+j) ];
            end
    end

    always @ ( posedge clk or posedge reset )
    begin
        case( current_state )
          S_IDLE: begin
              data_out <= 8'd0;
              outputvalid <= 1'b0;
              busy <= 1'b0;
          end
          S_READ: begin
              busy <= 1'b1;
              in[cnt] <= datain;
          end
          S_FIT: begin
	      data_out <= ( cnt2 <= 5'd15 ) ? out[cnt2] : 'hz;
	      outputvalid <= ( cnt2 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt2 == 5'd16 ) ? 1'b0 : 1'b1;
          end
          S_RIGHT: begin
              data_out <= ( cnt3 <= 5'd15 ) ? out[cnt3] : 'hz;
              outputvalid <= ( cnt3 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt3 == 5'd16 ) ? 1'b0 : 1'b1;
          end
          S_LEFT:  begin
              data_out <= ( cnt4 <= 5'd15 ) ? out[cnt4] : 'hz;
              outputvalid <= ( cnt4 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt4 == 5'd16 ) ? 1'b0 : 1'b1;
          end
          S_INRIGHT: begin
              data_out <= ( cnt2 <= 5'd15 ) ? out[cnt2] : 'hz;
              outputvalid <= ( cnt2 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt2 == 5'd16 ) ? 1'b0 : 1'b1;
          end
          S_INLEFT: begin
              data_out <= ( cnt3 <= 5'd15 ) ? out[cnt3] : 'hz;
              outputvalid <= ( cnt3 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt3 == 5'd16 ) ? 1'b0 : 1'b1;
          end
          S_IN: begin
              data_out <= ( cnt4 <= 5'd15 ) ? out[cnt4] : 'hz;
              outputvalid <= ( cnt4 <= 5'd15 ) ? 1'b1 : 1'b0;
              busy <= ( cnt4 == 5'd16 ) ? 1'b0 : 1'b1;
          end
        endcase
    end

endmodule

