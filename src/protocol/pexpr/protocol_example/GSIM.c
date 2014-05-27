s0:
    if (reset)
        goto s1;
    goto s0;
    
s1:
    if (!reset)
        goto s2;
    goto s1;
    
s2:
    if (!reset && in_en){
        read(b_in);
        goto s3;
    }
    goto s2;
    
s3:
    if (!reset && in_en){
        read(b_in);
        goto s4;
    }
    assert(0);
        
s4:
    if (!reset && in_en){
        read(b_in);
        goto s5;
    }
    assert(0);
    
s5:
    if (!reset && in_en){
        read(b_in);
        goto s6;
    }
    assert(0);
        
s6:
    if (!reset && in_en){
        read(b_in);
        goto s7;
    }
    assert(0);
    
s7:
    if (!reset && in_en){
        read(b_in);
        goto s8;
    }
    assert(0);
        
s8:
    if (!reset && in_en){
        read(b_in);
        goto s9;
    }
    assert(0);
    
s9:
    if (!reset && in_en){
        read(b_in);
        goto s10;
    }
    assert(0);
        
s10:
    if (!reset && in_en){
        read(b_in);
        goto s11;
    }
    assert(0);
    
s11:
    if (!reset && in_en){
        read(b_in);
        goto s12;
    }
    assert(0);
        
s12:
    if (!reset && in_en){
        read(b_in);
        goto s13;
    }
    assert(0);
    
s13:
    if (!reset && in_en){
        read(b_in);
        goto s14;
    }
    assert(0);
        
s14:
    if (!reset && in_en){
        read(b_in);
        goto s15;
    }
    assert(0);
    
s15:
    if (!reset && in_en){
        read(b_in);
        goto s16;
    }
    assert(0);
        
s16:
    if (!reset && in_en){
        read(b_in);
        goto s17;
    }
    assert(0);
    
s17:
    if (!reset && in_en){
        read(b_in);
        goto s18;
    }
    assert(0);
    
s18:
    if (!reset && out_valid){
        write(x_out);
        goto s19;
    }
    goto s18;
    
s19:
    if (!reset && out_valid){
        write(x_out);
        goto s20;
    }
    assert(0);
    
s20:
    if (!reset && out_valid){
        write(x_out);
        goto s21;
    }
    assert(0);
    
s21:
    if (!reset && out_valid){
        write(x_out);
        goto s22;
    }
    assert(0);
    
s22:
    if (!reset && out_valid){
        write(x_out);
        goto s23;
    }
    assert(0);
    
s23:
    if (!reset && out_valid){
        write(x_out);
        goto s24;
    }
    assert(0);
    
s24:
    if (!reset && out_valid){
        write(x_out);
        goto s25;
    }
    assert(0);
    
s25:
    if (!reset && out_valid){
        write(x_out);
        goto s26;
    }
    assert(0);
    
s26:
    if (!reset && out_valid){
        write(x_out);
        goto s27;
    }
    assert(0);
    
s27:
    if (!reset && out_valid){
        write(x_out);
        goto s28;
    }
    assert(0);
    
s28:
    if (!reset && out_valid){
        write(x_out);
        goto s29;
    }
    assert(0);
    
s29:
    if (!reset && out_valid){
        write(x_out);
        goto s30;
    }
    assert(0);
    
s30:
    if (!reset && out_valid){
        write(x_out);
        goto s31;
    }
    assert(0);
    
s31:
    if (!reset && out_valid){
        write(x_out);
        goto s32;
    }
    assert(0);

s32:
    if (!reset && out_valid){
        write(x_out);
        goto s33;
    }
    assert(0);
    
s33:
    if (!reset && out_valid){
        write(x_out);
        goto s34;
    }
    assert(0);
    
s34:
    if (!reset && out_valid){
        write(x_out);
        goto s1;
    }
    assert(0);

