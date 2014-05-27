cbegin
    next_reg_i = reg_i + 1;
    next_State = (reg_i == 120) ? STATE_OUT : STATE_INNER_ITER;
    next_C = C_DEFAULT;
    next_reg_k = REG_K_DEFAULT;
end
