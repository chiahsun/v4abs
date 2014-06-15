#include "Signal.h"

Signal::Signal(std::string c, std::string n) 
    : _code(c), _name(n) { _pos = 0; }

void Signal::addTimeValue(int time, std::string v) {
    _vecTimeValuePair.push_back(TimeValuePair(time, v));
}

std::string Signal::value() {
    return now()._value;
}

TimeValuePair Signal::find(unsigned int pos) const {
    return _vecTimeValuePair[pos];
}

TimeValuePair Signal::now() const {
    //std::cout << _pos << std::endl;
    return _vecTimeValuePair[_pos];
}
    

TimeValuePair Signal::next() const {
    if( _pos + 1 > size() )
        return now();
    else
        return _vecTimeValuePair[_pos+1];
}

TimeValuePair Signal::pre() {
    if ( _pos == 0 )
        return now();
    else
        return _vecTimeValuePair[_pos-1];
}

int Signal::now_time() {
    return _vecTimeValuePair[_pos]._time;
}

int Signal::next_time() { //std::cout<<"\n---"<<_pos<<" "<<size()<<"---\n";
    if( _pos+1 >= size() )
        return -1 ;
    else
        return _vecTimeValuePair[_pos+1]._time;
}

int Signal::pre_time() {
    if ( _pos == 0 )
        return -1 ;
    else
        return _vecTimeValuePair[_pos-1]._time;
}

bool Signal::end() {
    if ( _pos == size()-1 )
        return true;
    else
        return false;
}

void Signal::move_next() {
    _pos ++;
}

void Signal::move_pre() {
    _pos --;
}

void Signal::move_on(int t){//std::cout<<"---"<<t<<" "<<now_time()<<" "<<pre_time()<<std::endl;
    while(true){
        if( t < now_time() && pre_time() != -1 )
            move_pre();
        else if( t >= next_time() && next_time() != -1 )
            move_next();
        else 
            break;
    }
}

unsigned int Signal::size() const {
    return _vecTimeValuePair.size();
}

std::string Signal::name() const {
    return _name;
}

std::string Signal::code(){
    return _code;
}

bool Signal::operator == (const Signal& sig) const { return (_value == sig._value) ; }
bool Signal::operator != (const Signal& sig) const { return (_value != sig._value) ; }
