#ifndef SIGEXPRESSION_H
#define SIGEXPRESSION_H

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/for_each/ForEach.h"
#include "via/signal/Signal.h"
#include "via/computation/Value.h"

class SignalExpression;
typedef SharedPtr<SignalExpression> SignalExpressionHandle;

class SignalExpression {
public:
    int getType();
private:
    std::string identifier;
    std::string constant;
    SignalExpressionHandle _pFst;
    SignalExpressionHandle _pSnd;
    int _type;
};

class SigExpression {
public:
    SigExpression(){}
    virtual ~SigExpression(){}
    virtual std::string calculate() = 0;
};

class SigExpressionIdentifier : public SigExpression {
public:
    SigExpressionIdentifier(Signal* pSig);
    std::string calculate();

private:
    Signal* _pSig;
};

class SigExpressionConstant : public SigExpression {
public:
    SigExpressionConstant(Signal* pSig, std::string constant);
    std::string calculate();

private:
    Signal* _pSig;
    std::string _constant;
};

class SigExpressionUnary : public SigExpression {
public:
    SigExpressionUnary(int type, SigExpression* pSExp);
    std::string calculate();

private:
    int _type;
    SigExpression* _pSExp;
};

class SigExpressionBinary : public SigExpression {
public:
    SigExpressionBinary(int type, SigExpression* pFst, SigExpression* pSnd);
    std::string calculate();

private:
    int _type;
    SigExpression* _pFst;
    SigExpression* _pSnd;
};

#endif // SIGEXPRESSION_H
