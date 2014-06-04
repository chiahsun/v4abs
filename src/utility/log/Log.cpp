#include "Log.h"

#if 0
log_msg_t LOG_INFO(std::cout, "LOG(INFO)", false);
log_msg_t LOG_WARNING(std::cout, "LOG(WARNING)", false);
log_msg_t LOG_ERROR(std::cout, "LOG(ERROR)", true);
log_msg_t LOG_FATAL(std::cout, "LOG(FATAL)", true);
#endif


log_msg_t& log_get_LOG_INFO_STREAM() {
    static log_msg_t LOG_INFO_STREAM(std::cerr, "LOG(INFO)", false);
    return LOG_INFO_STREAM;
}

log_msg_t& log_get_LOG_WARNING_STREAM() {
    static log_msg_t LOG_WARNING_STREAM(std::cerr, "LOG(WARNING)", false);
    return LOG_WARNING_STREAM;
}

log_msg_t& log_get_LOG_ERROR_STREAM() {
    static log_msg_t LOG_ERROR_STREAM(std::cerr, "LOG(ERROR)", true);
    return LOG_ERROR_STREAM;
}


log_msg_t& log_get_LOG_FATAL_STREAM() {
    static log_msg_t LOG_FATAL_STREAM(std::cerr, "LOG(FATAL)", true);
    return LOG_FATAL_STREAM;
}
#if 0
log_msg_t& log_call(log_msg_t & os) {
    return os << " : ";
}
#endif

void log_handler_set_verbose_level_info() {
    LOG_HANDLER_SET_VERBOSE(INFO, true);
    LOG_HANDLER_SET_VERBOSE(WARNING, true);
    LOG_HANDLER_SET_VERBOSE(ERROR, true);
    LOG_HANDLER_SET_VERBOSE(FATAL, true);
}
void log_handler_set_verbose_level_warning() {
    LOG_HANDLER_SET_VERBOSE(INFO, false);
    LOG_HANDLER_SET_VERBOSE(WARNING, true);
    LOG_HANDLER_SET_VERBOSE(ERROR, true);
    LOG_HANDLER_SET_VERBOSE(FATAL, true);
}
void log_handler_set_verbose_level_error() {
    LOG_HANDLER_SET_VERBOSE(INFO, false);
    LOG_HANDLER_SET_VERBOSE(WARNING, false);
    LOG_HANDLER_SET_VERBOSE(ERROR, true);
    LOG_HANDLER_SET_VERBOSE(FATAL, true);
}
void log_handler_set_verbose_level_fatal() {
    LOG_HANDLER_SET_VERBOSE(INFO, false);
    LOG_HANDLER_SET_VERBOSE(WARNING, false);
    LOG_HANDLER_SET_VERBOSE(ERROR, false);
    LOG_HANDLER_SET_VERBOSE(FATAL, true);
}

void log_handler_set_abort_level_info() {
    LOG_HANDLER_SET_ABORT(INFO, true);
    LOG_HANDLER_SET_ABORT(WARNING, true);
    LOG_HANDLER_SET_ABORT(ERROR, true);
    LOG_HANDLER_SET_ABORT(FATAL, true);
}
void log_handler_set_abort_level_warning() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, true);
    LOG_HANDLER_SET_ABORT(ERROR, true);
    LOG_HANDLER_SET_ABORT(FATAL, true);
}
void log_handler_set_abort_level_error() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, false);
    LOG_HANDLER_SET_ABORT(ERROR, true);
    LOG_HANDLER_SET_ABORT(FATAL, true);
}
void log_handler_set_abort_level_fatal() {
    LOG_HANDLER_SET_ABORT(INFO, false);
    LOG_HANDLER_SET_ABORT(WARNING, false);
    LOG_HANDLER_SET_ABORT(ERROR, false);
    LOG_HANDLER_SET_ABORT(FATAL, true);
}
