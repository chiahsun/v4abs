#include "SigExpression.h"

SigExpressionIdentifier::SigExpressionIdentifier(Signal* pSig) 
    : _pSig(pSig) {}

std::string SigExpressionIdentifier::calculate() {
    return _pSig->value();
}

SigExpressionConstant::SigExpressionConstant(Signal* pSig, std::string constant)
    : _pSig(pSig), _constant(constant) {}

std::string SigExpressionConstant::calculate() {
    if(_pSig->value() == _constant)
        return "1";
    else
        return "0";
}

SigExpressionUnary::SigExpressionUnary(int type, SigExpression* pSExp)
    : _type(type), _pSExp(pSExp) {}

std::string SigExpressionUnary::calculate() {
    if(_type == 0)
        return _pSExp->calculate();
    else if(_type == 1)
        return LOGICAL_NOT(_pSExp->calculate());
    else
        assert(0);
}

SigExpressionBinary::SigExpressionBinary(int type, SigExpression* pFst, SigExpression* pSnd)
    : _type(type), _pFst(pFst), _pSnd(pSnd) {}

std::string SigExpressionBinary::calculate() {
    if(_type == 0)
        return LOGICAL_EQUAL(_pFst->calculate(), _pSnd->calculate());
    else if(_type == 1)
        return LOGICAL_OR(_pFst->calculate(), _pSnd->calculate());
    else if(_type == 2)
        return LOGICAL_AND(_pFst->calculate(), _pSnd->calculate());
    else if(_type == 3)
        return LOGICAL_XOR(_pFst->calculate(), _pSnd->calculate());
    else
        assert(0);
}
