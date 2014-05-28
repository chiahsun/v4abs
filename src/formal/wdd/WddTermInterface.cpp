#include "WddTermInterface.h"


#define ERROR_LOG(msg) do { std::cerr << "*Error: " << (msg) << " @ " << __FILE__ << " : " << __LINE__ << std::endl; assert(0); } while(0) 

WddTermInterface::~WddTermInterface() 
  { }

WddTermInterface::hash_id WddTermInterface::getTermHashId() {
    ERROR_LOG("This is a abstract class -> should be overriden by implementation/derived class");
}

std::string WddTermInterface::toString() const {
    ERROR_LOG("This is a abstract class -> should be overriden by implementation/derived class");
}
   
/*
bool WddTermInterface::operator < (const WddTermInterface & rhs) const {
    ERROR_LOG("This is a abstract class -> should be overriden by implementation/derived class");
}
*/

    
WddTermInterface::hash_id WddTermInterface::getNextTermHashId() {
    static hash_id id = 1;
    return id++;
}
