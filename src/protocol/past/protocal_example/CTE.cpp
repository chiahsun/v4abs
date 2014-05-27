s0:
    if(reset)
        goto s1;    
    goto s0;
s1:
    if(reset)
        goto s1;
    goto s2;
    
s2:
    if(!reset&&in_en){
        read(yuv_in);
        goto s3;
    }
    if (!reset)
        goto S2;
    assert(0);
s3:
    if(!reset && in_en) {
        read(yuv_in);
        goto s4;
    }
    assert(0);
s4:
    if(!reset && in_en) {
        read(yuv_in);
        goto s5;
    }
    assert(0);
    
s5:
    if(!reset && in_en) {
        check(busy);
        goto s6;
    }
    assert(0);
    
s6:
    if(!reset&& busy)
        goto s6;
    if(!reset&& !busy){
        check(out_valid);
        write(rgb_out);
        goto s7;
    }
    assert(0);
    
s7:
    if(!reset&& in_en){
        read(yuv_in);
        goto s8;
    }
    assert(0);
    
s8:
    if(!reset){
        check(busy);
        goto s9;
    }
    assert(0);
    
s9:
    if(!reset && busy)
        goto s9;
    if(!reset&& !busy){
        check(out_valid);
        write(rgb_out);
        goto s10;
    }
    assert(0);
    
s10:
    if(!reset && en_in) {
        read(yuv_in);
        goto s3;
    }
    if(!reset && !en_in )
        goto s2;
    assert(0);

