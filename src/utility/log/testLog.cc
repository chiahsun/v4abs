#include "Log.h"

void test_set_handler() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, false);
    LOG_HANDLER_SET_ABORT(ERROR, false);
    LOG_HANDLER_SET_ABORT(FATAL, false);
    LOG(ERROR) << "Hello " << (2 + 3);
    int x = 10;
    LOG(FATAL) << "sdad" << x << "asda" << ")\n";
    LOG(ERROR) << "Hello " << (2 + 3);
    LOG(WARNING) << "OOASkdpadk ";
    LOG(FATAL) << "Go home\n";
}

void test_match_for_pass_macro_or_not() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, false);
    LOG_HANDLER_SET_ABORT(ERROR, false);
    LOG_HANDLER_SET_ABORT(FATAL, false);
   
    LOG(INFO) << "This is info test"; 
    LOG(WARNING) << "This is warning test"; 
    LOG(ERROR) << "This is error test"; 
    LOG(FATAL) << "This is fatal test"; 
    
    LOG_INFO << "This is info test"; 
    LOG_WARNING << "This is warning test"; 
    LOG_ERROR << "This is error test"; 
    LOG_FATAL << "This is fatal test"; 
}

#if 0
void test_abort() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, false);
    LOG_HANDLER_SET_ABORT(ERROR, true);
    LOG_HANDLER_SET_ABORT(FATAL, true);

    int x = 10;
    LOG(INFO) << "sdad" << x << "asda" << ")\n";
    LOG(WARNING) << "OOASkdpadk ";
    LOG(ERROR) << "Hello " << (2 + 3);
    LOG(FATAL) << "Go home\n";
}

void test_set_abort_level() {
    int x = 10;
    // LOG_HANDLER_SET_ABORT_LEVEL_INFO();
    LOG_HANDLER_SET_ABORT_LEVEL_FATAL();
    LOG(INFO) << "sdad" << x << "asda" << ")\n";
    LOG(WARNING) << "OOASkdpadk ";
    LOG(ERROR) << "Hello " << (2 + 3);
    LOG(FATAL) << "Go home\n";
}
#endif

void test_manipulator() {
#if 0
    LOG_INFO << "Hello " << std::endl;
    LOG_INFO << "World" << std::endl;
    LOG_INFO << "!" << std::endl;
#endif
}


void test_tmp() {
    LOG_INFO << "Hello" << std::endl;
}

int main() {
    test_set_handler();
    test_match_for_pass_macro_or_not();
    test_manipulator();

    test_tmp();
    // test_abort();

    //test_set_abort_level();
    return 0;
}
