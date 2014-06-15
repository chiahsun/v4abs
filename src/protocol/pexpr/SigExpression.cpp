#include "SigExpression.h"

SigExpression::SigExpression(int type, Signal* pSig)
    : _type(type), _pSig(pSig) {}

SigExpression::SigExpression(int type, Signal* pSig, std::string constant)
    : _type(type), _pSig(pSig), _constant(constant) {}

SigExpression::SigExpression(int type, SigExpressionHandle pFst)
    : _type(type), _pFst(pFst) {}

SigExpression::SigExpression(int type, SigExpressionHandle pFst, SigExpressionHandle pSnd)
    : _type(type), _pFst(pFst), _pSnd(pSnd) {}

SigExpression::SigExpression(int type)
    : _type(type) {}

SigExpressionHandle SigExpression::makeHandle(int type, Signal* pSig) {
    return SigExpressionHandle(SigExpression(type, pSig));
}

SigExpressionHandle SigExpression::makeHandle(int type, Signal* pSig, std::string constant) {
    return SigExpressionHandle(SigExpression(type, pSig, constant));
}

SigExpressionHandle SigExpression::makeHandle(int type, SigExpressionHandle pFst){
    return SigExpressionHandle(SigExpression(type, pFst));
}

SigExpressionHandle SigExpression::makeHandle(int type, SigExpressionHandle pFst, SigExpressionHandle pSnd){
    return SigExpressionHandle(SigExpression(type, pFst, pSnd));
}

SigExpressionHandle SigExpression::makeHandle(int type) {
    return SigExpressionHandle(SigExpression(type));
}

int SigExpression::getType() {
    return _type;
}

Signal* SigExpression::getSignal() {
    return _pSig;
}

std::string SigExpression::getConstant() {
    return _constant;
}

SigExpressionHandle SigExpression::getFst() {
    return _pFst;
}

SigExpressionHandle SigExpression::getSnd() {
    return _pSnd;
}

std::string SigExpression::calculate() {
    std::string s;

    if (_type == 0) {
        s = _pSig -> value();
    }
    else if (_type == 1) {
        if(_pSig->value() == _constant)
            s = "1";
        else
            s = "0";
    }
    else if (_type == 2) {
        s = _pFst->calculate();
    }
    else if (_type == 3) {
        s = LOGICAL_NOT(_pFst->calculate());
    }
    else if (_type == 4) {
        s = LOGICAL_EQUAL(_pFst->calculate(), _pSnd->calculate());
    }
    else if (_type == 5) {
        s = LOGICAL_OR(_pFst->calculate(), _pSnd->calculate());
    }
    else if (_type == 6) {
        s = LOGICAL_AND(_pFst->calculate(), _pSnd->calculate());
    }
    else if (_type == 7) {
        s = LOGICAL_XOR(_pFst->calculate(), _pSnd->calculate());
    }
    else if (_type == 8) { // for always true
        s = "1";
    }
    else if (_type == 9) { // for alaways false
        s = "0";
    }

    return s;
}
