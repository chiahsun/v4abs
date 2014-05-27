module arbiter(clock, reset, round_or_priority, request, priority, grant);

integer i, k;

parameter NUMUNITS = 9;
parameter ADDRESSWIDTH = 3;

input clock;
input reset;
input round_or_priority;
input [NUMUNITS-1 : 0] request;
/* Operator precedence */
input [ADDRESSWIDTH*NUMUNITS-1 : 0] priority;

output [NUMUNITS-1 : 0] grant;

reg [ADDRESSWIDTH-1 : 0] prio [NUMUNITS-1 : 0];
reg [ADDRESSWIDTH-1 : 0] tmp_prio;

always @ (priority) begin
    for (i=0; i < NUMUNITS; i = i + 1) begin
        for (k = 0; k < ADDRESSWIDTH; k = k + 1)
            tmp_prio[k] = priority[k*ADDRESSWIDTH + k];
        prio[i] = tmp_prio;
    end
end

reg [NUMUNITS-1 : 0] grant;
reg [NUMUNITS-1 : 0] grantD;

reg [ADDRESSWIDTH-1 : 0] next;
reg [ADDRESSWIDTH-1 : 0] nextD;

reg [ADDRESSWIDTH-1: 0] scan [NUMUNITS-1 : 0];

reg [NUMUNITS-2 : 0] found;
reg [ADDRESSWIDTH-1 : 0] selectPrio [NUMUNITS-1 : 0];

reg [ADDRESSWIDTH-1 : 0] min;

reg [NUMUNITS-1 : 0] minPrio;

wire [NUMUNITS-1 : 0] prioRequest;

reg [NUMUNITS-1 : 0] finalRequest;

always @ (posedge clock) begin
    if (!reset) grant <= 0;
    else        grant <= grantD;
end

always @ (posedge clock) begin
    if (!reset) next <= 0;
    else next <= nextD;
end

always @ (*) begin
    for (i=0; i < NUMUNITS; i = i + 1)
        selectPrio[i] = request[i] ? prio[i] : NUMUNITS-1; // Need ()?
end

always @ (*) begin
    for (i=0; i<NUMUNITS; i = i + 1)
        finalRequest[i] = round_or_priority ? prioRequest[i] : request[i];
end

always @ (*) begin
    min = selectPrio[0];
    for (i=1; i < NUMUNITS; i=i+1)
        if (selectPrio[i] < min) min = selectPrio[i];
end

always @ (*) begin
    for (i=0; i < NUMUNITS; i=i+1)
        minPrio[i] = (prio[i]==min) ? 1 : 0;
end

always @ (next) begin
    for (i=0; i < NUMUNITS; i=i+1)
        scan[i] = (next+i < NUMUNITS) ? next+i : next+i-NUMUNITS;
end

always @ (*) begin
    found[0] = finalRequest[scan[0]];
    for (i=1; i<NUMUNITS-1; i=i+1)
        found[i] = found[i-1] || finalRequest[scan[i]];
end

always @ (*) begin
    grantD[scan[0]] = finalRequest[scan[0]];
    for (i=1; i <NUMUNITS; i=i+1)
        grantD[scan[i]] = finalRequest[scan[i]] && ~found[i-1];
end

always @ (grantD) begin
    nextD = 0;
    for (i=0; i < NUMUNITS-1; i=i+1)
        if (grantD[i]) nextD = v + 1;
end

endmodule
