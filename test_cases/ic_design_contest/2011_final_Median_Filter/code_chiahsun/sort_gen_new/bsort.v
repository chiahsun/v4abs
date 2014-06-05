// Before sort ----- 
// 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
// After sort ------ 
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
// # wires = 142

module comparator(d1_in, d2_in, d1_out, d2_out);
    input  [12:0] d1_in, d2_in;
    output [12:0] d1_out, d2_out;
    assign {d2_out,d1_out} = (d1_in > d2_in) ? {d1_in,d2_in} : {d2_in,d1_in};
endmodule


module bsort(data_in, data_out);


input   [207:0] data_in;
output  [207:0] data_out;

wire[12:0] a10v10, a10v11, a10v13, a10v2, a10v4, a10v5, a10v6, a10v9, a11v10, a11v5,     
a1v0, a1v1, a1v10, a1v11, a1v12, a1v13, a1v14, a1v15, a1v2, a1v3,     
a1v4, a1v5, a1v6, a1v7, a1v8, a1v9, a2v0, a2v1, a2v10, a2v11,     
a2v12, a2v13, a2v14, a2v15, a2v2, a2v3, a2v4, a2v5, a2v6, a2v7,     
a2v8, a2v9, a3v0, a3v1, a3v10, a3v11, a3v12, a3v13, a3v14, a3v15,     
a3v2, a3v3, a3v4, a3v5, a3v6, a3v7, a3v8, a3v9, a4v0, a4v1,     
a4v10, a4v11, a4v12, a4v13, a4v14, a4v15, a4v2, a4v3, a4v4, a4v5,     
a4v6, a4v7, a4v8, a4v9, a5v0, a5v1, a5v10, a5v11, a5v12, a5v13,     
a5v14, a5v15, a5v2, a5v3, a5v4, a5v5, a5v6, a5v7, a5v8, a5v9,     
a6v1, a6v10, a6v11, a6v12, a6v13, a6v14, a6v2, a6v3, a6v4, a6v5,     
a6v6, a6v7, a6v8, a6v9, a7v1, a7v10, a7v11, a7v12, a7v13, a7v14,     
a7v2, a7v3, a7v4, a7v5, a7v6, a7v7, a7v8, a7v9, a8v1, a8v10,     
a8v11, a8v12, a8v13, a8v14, a8v2, a8v3, a8v4, a8v5, a8v6, a8v7,     
a8v8, a8v9, a9v10, a9v11, a9v12, a9v13, a9v2, a9v3, a9v4, a9v5,     
a9v6, a9v9;


assign a1v0 = data_in[12:0];
assign a1v1 = data_in[25:13];
assign a1v2 = data_in[38:26];
assign a1v3 = data_in[51:39];
assign a1v4 = data_in[64:52];
assign a1v5 = data_in[77:65];
assign a1v6 = data_in[90:78];
assign a1v7 = data_in[103:91];
assign a1v8 = data_in[116:104];
assign a1v9 = data_in[129:117];
assign a1v10 = data_in[142:130];
assign a1v11 = data_in[155:143];
assign a1v12 = data_in[168:156];
assign a1v13 = data_in[181:169];
assign a1v14 = data_in[194:182];
assign a1v15 = data_in[207:195];

assign data_out[12:0] = a5v0;
assign data_out[25:13] = a8v1;
assign data_out[38:26] = a10v2;
assign data_out[51:39] = a9v3;
assign data_out[64:52] = a10v4;
assign data_out[77:65] = a11v5;
assign data_out[90:78] = a10v6;
assign data_out[103:91] = a8v7;
assign data_out[116:104] = a8v8;
assign data_out[129:117] = a10v9;
assign data_out[142:130] = a11v10;
assign data_out[155:143] = a10v11;
assign data_out[168:156] = a9v12;
assign data_out[181:169] = a10v13;
assign data_out[194:182] = a8v14;
assign data_out[207:195] = a5v15;


comparator c0 (a1v0, a1v1, a2v0, a2v1);
comparator c1 (a1v2, a1v3, a2v2, a2v3);
comparator c2 (a2v0, a2v2, a3v0, a3v2);
comparator c3 (a2v1, a2v3, a3v1, a3v3);
comparator c4 (a3v1, a3v2, a4v1, a4v2);
comparator c5 (a1v4, a1v5, a2v4, a2v5);
comparator c6 (a1v6, a1v7, a2v6, a2v7);
comparator c7 (a2v4, a2v6, a3v4, a3v6);
comparator c8 (a2v5, a2v7, a3v5, a3v7);
comparator c9 (a3v5, a3v6, a4v5, a4v6);
comparator c10 (a3v0, a3v4, a4v0, a4v4);
comparator c11 (a4v2, a4v6, a5v2, a5v6);
comparator c12 (a5v2, a4v4, a6v2, a5v4);
comparator c13 (a4v1, a4v5, a5v1, a5v5);
comparator c14 (a3v3, a3v7, a4v3, a4v7);
comparator c15 (a4v3, a5v5, a5v3, a6v5);
comparator c16 (a5v1, a6v2, a6v1, a7v2);
comparator c17 (a5v3, a5v4, a6v3, a6v4);
comparator c18 (a6v5, a5v6, a7v5, a6v6);
comparator c19 (a1v8, a1v9, a2v8, a2v9);
comparator c20 (a1v10, a1v11, a2v10, a2v11);
comparator c21 (a2v8, a2v10, a3v8, a3v10);
comparator c22 (a2v9, a2v11, a3v9, a3v11);
comparator c23 (a3v9, a3v10, a4v9, a4v10);
comparator c24 (a1v12, a1v13, a2v12, a2v13);
comparator c25 (a1v14, a1v15, a2v14, a2v15);
comparator c26 (a2v12, a2v14, a3v12, a3v14);
comparator c27 (a2v13, a2v15, a3v13, a3v15);
comparator c28 (a3v13, a3v14, a4v13, a4v14);
comparator c29 (a3v8, a3v12, a4v8, a4v12);
comparator c30 (a4v10, a4v14, a5v10, a5v14);
comparator c31 (a5v10, a4v12, a6v10, a5v12);
comparator c32 (a4v9, a4v13, a5v9, a5v13);
comparator c33 (a3v11, a3v15, a4v11, a4v15);
comparator c34 (a4v11, a5v13, a5v11, a6v13);
comparator c35 (a5v9, a6v10, a6v9, a7v10);
comparator c36 (a5v11, a5v12, a6v11, a6v12);
comparator c37 (a6v13, a5v14, a7v13, a6v14);
comparator c38 (a4v0, a4v8, a5v0, a5v8);
comparator c39 (a6v4, a6v12, a7v4, a7v12);
comparator c40 (a7v4, a5v8, a8v4, a6v8);
comparator c41 (a7v2, a7v10, a8v2, a8v10);
comparator c42 (a6v6, a6v14, a7v6, a7v14);
comparator c43 (a7v6, a8v10, a8v6, a9v10);
comparator c44 (a8v2, a8v4, a9v2, a9v4);
comparator c45 (a8v6, a6v8, a9v6, a7v8);
comparator c46 (a9v10, a7v12, a10v10, a8v12);
comparator c47 (a6v1, a6v9, a7v1, a7v9);
comparator c48 (a7v5, a7v13, a8v5, a8v13);
comparator c49 (a8v5, a7v9, a9v5, a8v9);
comparator c50 (a6v3, a6v11, a7v3, a7v11);
comparator c51 (a4v7, a4v15, a5v7, a5v15);
comparator c52 (a5v7, a7v11, a6v7, a8v11);
comparator c53 (a7v3, a9v5, a8v3, a10v5);
comparator c54 (a6v7, a8v9, a7v7, a9v9);
comparator c55 (a8v11, a8v13, a9v11, a9v13);
comparator c56 (a7v1, a9v2, a8v1, a10v2);
comparator c57 (a8v3, a9v4, a9v3, a10v4);
comparator c58 (a10v5, a9v6, a11v5, a10v6);
comparator c59 (a7v7, a7v8, a8v7, a8v8);
comparator c60 (a9v9, a10v10, a10v9, a11v10);
comparator c61 (a9v11, a8v12, a10v11, a9v12);
comparator c62 (a9v13, a7v14, a10v13, a8v14);


endmodule
