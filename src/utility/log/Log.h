#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdlib>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << "          @ ( " << __FILE__ << ":" << __LINE__ << " )" << std::endl; } while (0)

#define LOG_STREAM_INSTANCE(log_level) log_get_LOG_##log_level##_STREAM()
// This preprocessing has __LINE__ and __FILE__ into number and literals
#define FILE_LINE_CONCAT(x, y) FILE_LINE_CONCAT_PRE(x, y)
// We deal number and literals here
#define FILE_LINE_CONCAT_PRE(x, y) "      (" x " : " #y ")\n"

#define AUTOMATIC_ASSERT_CREATE(log_level) __ASSERT__ ##log_level

#define LOG(log_level) for(int ___i=0; ___i==0; ++___i) if(LOG_STREAM_INSTANCE(log_level).is_verbose()) for(MsgBuffer ___msg___(FILE_LINE_CONCAT(__FILE__, __LINE__)); ___i==0; ++___i, LOG_STREAM_INSTANCE(log_level).try_flush(), ___msg___.flush(), LOG_STREAM_INSTANCE(log_level).try_abort())  LOG_STREAM_INSTANCE(log_level) << LOG_STREAM_INSTANCE(log_level).info()

struct MsgBuffer {
    std::string _msg;
    MsgBuffer( std::string msg) : _msg(msg) { }
    void flush() {
        std::cerr << _msg;
        std::cerr.flush(); 
    }
};

class log_msg_t : public std::ostream {
public:
    log_msg_t(std::ostream & os, std::string the_info, bool abort = false, bool verbose = true)
      : std::ostream(&_buffer)
      , _buffer(os)
      , _is_abort(abort)
      , _is_verbose(verbose) { _info = the_info + " : "; }
    ~log_msg_t () {}
    
    void try_abort() {
        if(_is_abort) {
            assert(0);
            abort(); // if assert fails at O3 mode
        }
    }

    inline std::string info() const { return _info; }
    void set_abort(bool abort) { _is_abort = abort; }
    void set_verbose(bool verbose) { _is_verbose = verbose; }
    inline bool is_verbose() const { return _is_verbose; }
    inline void try_flush() { _buffer.sync(); } 
    class MyStreamBuf : public std::stringbuf {
    public:
        std::ostream & _os;
        MyStreamBuf(std::ostream & os) : _os(os) { }

        virtual int sync() {
            _os << str();
            str("");
            _os.flush();
            return 0;
        }
    };
    
private:
    MyStreamBuf _buffer;
    std::string _info;
    bool _is_abort;
    bool _is_verbose;
#if 0
    template <class T>
    log_msg_t& operator << (const T & rhs) {
        std::cerr << rhs;
        return *this;
    }
#endif
#if 0 
    template <class T>
    friend log_msg_t& operator<< (log_msg_t & os, const T & rhs) { 
        return os << rhs;
    }
#endif


#if 0
    template <class T>
    friend log_msg_t& operator<< (log_msg_t & os, const T & rhs) {
        std::cerr << rhs;
        return os;
    }
#endif

    /*
    template <class charT, class traits>
    friend log_msg_t& operator<< (log_msg_t & os, std::basic_ostream<charT, traits> & rhs) {
        std::cerr << rhs;
        return os;
    } */
};

struct log_msg_set_handler {
   void set(log_msg_t & msg, bool is_assert) { 
   }
};

#define LOG_HANDLER_SET_ABORT(log_level, abort) do { LOG_STREAM_INSTANCE(log_level).set_abort(abort); } while(0)
#define LOG_HANDLER_SET_VERBOSE(log_level, verbose) do { LOG_STREAM_INSTANCE(log_level).set_verbose(verbose); } while(0)


log_msg_t& log_call(log_msg_t & os);


log_msg_t& log_get_LOG_INFO_STREAM();
log_msg_t& log_get_LOG_WARNING_STREAM();
log_msg_t& log_get_LOG_ERROR_STREAM();
log_msg_t& log_get_LOG_FATAL_STREAM();
/*
extern log_msg_t LOG_INFO_STREAM;
extern log_msg_t LOG_WARNING_STREAM;
extern log_msg_t LOG_ERROR_STREAM;
extern log_msg_t LOG_FATAL_STREAM;
*/


void log_handler_set_verbose_level_info();
void log_handler_set_verbose_level_warning();
void log_handler_set_verbose_level_error();
void log_handler_set_verbose_level_fatal();

void log_handler_set_abort_level_info();
void log_handler_set_abort_level_warning();
void log_handler_set_abort_level_error();
void log_handler_set_abort_level_fatal();

#define LOG_HANDLER_SET_ABORT_LEVEL_INFO() do { log_handler_set_abort_level_info(); } while (0)
#define LOG_HANDLER_SET_ABORT_LEVEL_WARNING() do { log_handler_set_abort_level_warning(); } while (0)
#define LOG_HANDLER_SET_ABORT_LEVEL_ERROR() do { log_handler_set_abort_level_error(); } while (0)
#define LOG_HANDLER_SET_ABORT_LEVEL_FATAL() do { log_handler_set_abort_level_fatal(); } while (0)

#define LOG_HANDLER_SET_VERBOSE_LEVEL_INFO() do { log_handler_set_verbose_level_info(); } while (0)
#define LOG_HANDLER_SET_VERBOSE_LEVEL_WARNING() do { log_handler_set_verbose_level_warning(); } while (0)
#define LOG_HANDLER_SET_VERBOSE_LEVEL_ERROR() do { log_handler_set_verbose_level_error(); } while (0)
#define LOG_HANDLER_SET_VERBOSE_LEVEL_FATAL() do { log_handler_set_verbose_level_fatal(); } while (0)

#define LOG_INFO LOG(INFO)
#define LOG_WARNING LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#endif // LOG_H
