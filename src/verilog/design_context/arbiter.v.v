module arbiter(clock, reset, round_or_priority, request, priority, grant);

input clock;
input reset;
input round_or_priority;
input [(NUMUNITS-1):0] request;
input [(ADDRESSWIDTH*(NUMUNITS-1)):0] priority;

input [(NUMUNITS-1):0] grant;

parameter NUMUNITS = 9;
parameter ADDRESSWIDTH = 3;

wire [(NUMUNITS-1):0]prioRequest
reg [(ADDRESSWIDTH-1):0] prio;
reg [(ADDRESSWIDTH-1):0] tmp_prio;
reg [(NUMUNITS-1):0] grant;
reg [(NUMUNITS-1):0] grantD;
reg [(ADDRESSWIDTH-1):0] next;
reg [(ADDRESSWIDTH-1):0] nextD;
reg [(ADDRESSWIDTH-1):0] scan;
reg [(NUMUNITS-2):0] found;
reg [(ADDRESSWIDTH-1):0] selectPrio;
reg [(ADDRESSWIDTH-1):0] min;
reg [(NUMUNITS-1):0] minPrio;
reg [(NUMUNITS-1):0] finalRequest;

integer i, k;

always always @ (priority)
  begin
for (i = 0; (i<NUMUNITS); i = (i+1))
      begin
for (k = 0; (k<ADDRESSWIDTH); k = (k+1))
          tmp_prio[k] = priority[(k*(ADDRESSWIDTH+k))];
        prio[i] = tmp_prio;
      end
  end
always always @ (posedge clock)
  begin
    if (!reset) {
      grant <= 0;
    } else {
      grant <= grantD;
  }
  end
always always @ (posedge clock)
  begin
    if (!reset) {
      next <= 0;
    } else {
      next <= nextD;
  }
  end
always always @ (*)
  begin
for (i = 0; (i<NUMUNITS); i = (i+1))
      selectPrio[i] = (request[i]?prio[i]:(NUMUNITS-1));
  end
always always @ (*)
  begin
for (i = 0; (i<NUMUNITS); i = (i+1))
      finalRequest[i] = (round_or_priority?prioRequest[i]:request[i]);
  end
always always @ (*)
  begin
    min = selectPrio[0];
for (i = 1; (i<NUMUNITS); i = (i+1))
      if ((selectPrio[i]<min)) {
        min = selectPrio[i];
      } else {
        ;  }
  end
always always @ (*)
  begin
for (i = 0; (i<NUMUNITS); i = (i+1))
      minPrio[i] = ((prio[i]=min)?1:0);
  end
always always @ (next)
  begin
for (i = 0; (i<NUMUNITS); i = (i+1))
      scan[i] = ((next+(i<NUMUNITS))?(next+i):(next+(i-NUMUNITS)));
  end
always always @ (*)
  begin
    found[0] = finalRequest[scan[0]];
for (i = 1; (i<(NUMUNITS-1)); i = (i+1))
      found[i] = (found[(i-1)]||finalRequest[scan[i]]);
  end
always always @ (*)
  begin
    grantD[scan[0]] = finalRequest[scan[0]];
for (i = 1; (i<NUMUNITS); i = (i+1))
      grantD[scan[i]] = (finalRequest[scan[i]]&&~found[(i-1)]);
  end
always always @ (grantD)
  begin
    nextD = 0;
for (i = 0; (i<(NUMUNITS-1)); i = (i+1))
      if (grantD[i]) {
        nextD = (v+1);
      } else {
        ;  }
  end

endmodule

