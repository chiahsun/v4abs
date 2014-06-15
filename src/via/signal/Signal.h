#ifndef SIGNAL_H
#define SIGNAL_H

#include "via/computation/Util.h"
#include <vector>
#include <iostream>

struct TimeValuePair {
    int _time;
    std::string _value;
    TimeValuePair(int t, std::string& v) : _time(t), _value(v) {}
};

class Signal {
public:
    Signal(std::string c, std::string n);
    Signal(){}
    ~Signal(){ }

    void addTimeValue(int time, std::string v); 
    std::string value(); 
    TimeValuePair find(unsigned int pos) const; 
    TimeValuePair now() const; 
    TimeValuePair next() const ;
    TimeValuePair pre();
    int now_time(); 
    int next_time();
    int pre_time();
    bool end();
    void move_next();
    void move_pre(); 
    void move_on(int t);
    unsigned int size() const; 
    std::string name() const ; 
    std::string code();
    bool operator == (const Signal& sig) const ;
    bool operator != (const Signal& sig) const ;

private:
    unsigned int _pos;
    float _value; 
    std::string _code; 
    std::string _name; 
    std::vector<TimeValuePair> _vecTimeValuePair;
};

#endif // SIGNAL_H
