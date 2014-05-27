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
    if (y_valid)
        write(y);
    if (z_valid)
        write(z);
    goto s2;
