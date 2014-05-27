#ifndef EXCEPTION_H
#define EXCEPTION_H

class NotOverridenException {
public:
    const char* what() const;
};

class NotImplementedException {
public:
    const char* what() const;
};

class InvalidTypeException {
public:
    const char* what() const;
};

class CheckFailException {
    const char* _msg;
public:
    CheckFailException();
    CheckFailException(const char* itsMsg);
    const char* what() const;
    const char* msg() const;
};

class NoSuchBranchException { 
public:
    const char* what() const;
};

struct InvalidReadFileException {
    const char* what() { return "Error to read file"; }
};

struct InvalidFormatException {
    const char* _msg;
    InvalidFormatException(const char* msg) : _msg(msg) { }
    const char* what() { return "Invalid format while processing string"; }
};


#endif // EXCEPTION_H
