#include "Value.h"

std::string LOGICAL_NOT(std::string str){
    for(unsigned int i = 0 ; i < str.length() ; ++i){
        if(str[i] == '0')
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}

std::string LOGICAL_EQUAL(std::string Fst, std::string Snd){
    if(Fst == Snd)
        return "1";
    else
        return "0";
}

std::string LOGICAL_AND(std::string Fst, std::string Snd){
    assert(Fst.length() == Snd.length());
    std::string s = "";
    for(unsigned int i = 0 ; i < Fst.length() ; ++i){
        if(Fst[i] == '0' || Snd[i] == '0')
            s = s + '0';
        else
            s = s + '1';
    }
    return s;
}

std::string LOGICAL_OR(std::string Fst, std::string Snd){
    assert(Fst.length() == Snd.length());
    std::string s = "";
    for(unsigned int i = 0 ; i < Fst.length() ; ++i){
        if(Fst[i] != '0' || Snd[i] != '0')
            s = s + '1';
        else
            s = s + '0';
    }
    return s;
}

std::string LOGICAL_XOR(std::string Fst, std::string Snd){
    assert(Fst.length() == Snd.length());
    std::string s = "";
    for(unsigned int i = 0 ; i < Fst.length() ; ++i){
        if(Fst[i] == Snd[i])
            s = s + '0';
        else
            s = s + '1';
    }
    return s;
}
