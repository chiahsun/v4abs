#ifndef SIGEXPRESSION_H
#define SIGEXPRESSION_H

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/for_each/ForEach.h"
#include "via/signal/Signal.h"
#include "via/computation/Value.h"

class SigExpression;
typedef SharedPtr<SigExpression> SigExpressionHandle;

class SigExpression {
public:
    SigExpression(int type, Signal* pSig);
    SigExpression(int type, Signal* pSig, std::string constant);
    SigExpression(int type, SigExpressionHandle pFst);
    SigExpression(int type, SigExpressionHandle pFst, SigExpressionHandle pSnd);
    SigExpression(int type); // for alaways true

    static SigExpressionHandle makeHandle(int type, Signal* pSig);
    static SigExpressionHandle makeHandle(int type, Signal* pSig, std::string constant);
    static SigExpressionHandle makeHandle(int type, SigExpressionHandle pFst);
    static SigExpressionHandle makeHandle(int type, SigExpressionHandle pFst, SigExpressionHandle pSnd);
    static SigExpressionHandle makeHandle(int type); // for alaways true

    int getType();
    Signal* getSignal();
    std::string getConstant();
    SigExpressionHandle getFst();
    SigExpressionHandle getSnd();
    std::string calculate();

private:
    Signal* _pSig;
    std::string _constant;
    SigExpressionHandle _pFst;
    SigExpressionHandle _pSnd;
    int _type;
#if 0
    0 --- identifier
    1 --- identifier == constant
    2 --- ( Exp )
    3 --- ! Exp
    4 --- Exp == Exp
    5 --- Exp || Exp
    6 --- Exp && Exp
    7 --- Exp ^  Exp
    8 --- alaways for true
    9 --- alaways for false
#endif
};

#endif // SIGEXPRESSION_H
