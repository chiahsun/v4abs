s0:
    if (reset)
        goto s1;
    goto s0;
    
s1:
    if (reset)
        goto s1;
    goto s2;
    
s2:
    if (reset)
        goto s1;
    if (in_en)
        read(Din);
    if (out_valid)
        write(Dout);
    if (busy)
        goto s3;
    goto s2;
        
s3:
    check(!in_en);
    if (out_valid)
        write(Dout);
    if (busy)
        goto s3;
    goto s2;
    
    
