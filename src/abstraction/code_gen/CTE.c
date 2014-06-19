s0:
    if (reset)
        goto s1; 
    goto s0;
s1:
    if (reset)
        goto s1;
    goto s2;
    
s2:
    if (!reset&&in_en){
        read(yuv_in);
        goto s3;
    }
    if (!reset)
        goto s2;
    assert(0);
s3:
    if (!reset && in_en) {
        read(yuv_in);
        goto s4;
    }
    assert(0);
s4:
    if (!reset && in_en) {
        read(yuv_in);
        goto s5;
    }
    assert(0);
    
s5:
    if (!busy) {
        check(out_valid);
        write(rgb_out);
        goto s7;
    }
    goto s5;

    
s7:
    if (!reset&& in_en){
        read(yuv_in);
        goto s8;
    }
    assert(0);
    
s8:
    if (!busy){
        check(out_valid);
        write(rgb_out);
        goto s10;
    }
    goto s8;
    
s10:
    if (!reset && in_en) {
        read(yuv_in);
        goto s3;
    }
    if (reset)
        goto s1;
    if (in_en)
        goto s2;
    assert(0);

