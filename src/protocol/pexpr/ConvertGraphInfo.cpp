#include "ConvertGraphInfo.h"

SigExpressionHandle ConvertGraphInfo::convert(const PExprBoolExpressionHandle & pBoolExpression, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map){
    if(pBoolExpression->getConstant().valid()){
        std::string constant = pBoolExpression->getConstant()->getName();
        std::string identifier = pBoolExpression->getName();
        int num = ASCII_index(_map[identifier]);

        return SigExpression::makeHandle(1, &_vecSig[num], constant);
    }
    else if(pBoolExpression->getFst().valid() && pBoolExpression->getSnd().valid()){
        PExprBoolExpressionHandle pFst = pBoolExpression->getFst();
        PExprBoolExpressionHandle pSnd = pBoolExpression->getSnd();
        if (pBoolExpression->getOp() == 0)
            return SigExpression::makeHandle(6, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == 1)
            return SigExpression::makeHandle(5, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == 2)
            return SigExpression::makeHandle(7, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == 3)
            return SigExpression::makeHandle(4, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else 
            assert(0);
    }
    else if(pBoolExpression->getFst().valid() && !pBoolExpression->getSnd().valid()){ 
        PExprBoolExpressionHandle pFst = pBoolExpression->getFst();
        if( pBoolExpression->getOp() == 4){
            return SigExpression::makeHandle(3, ConvertGraphInfo::convert(pFst, _vecSig, _map));
        }
        else
            return SigExpression::makeHandle(2, ConvertGraphInfo::convert(pFst, _vecSig, _map));
    }
    else{ 
        std::string identifier = pBoolExpression->getName();
        int num = ASCII_index(_map[identifier]);

        return SigExpression::makeHandle(0, &_vecSig[num]);
    }
}

SigExpressionHandle ConvertGraphInfo::convert(const PExprUpdateStatementHandle & pUpdateStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map) {
    for(int i = 0 ; i < pUpdateStatement->getAllContainer().size() ; ++i) {
        if(pUpdateStatement->getAllContainer()[i]->getRWC().valid()){
        }
        else if(pUpdateStatement->getAllContainer()[i]->getWithoutGoto().valid()){
        }
        else
            assert(0);
    }
    for(int i = 0 ; i < pUpdateStatement->getSpecificContainer().size() ; ++i){
        if(pUpdateStatement->getSpecificContainer()[i]->getRWC().valid()){
        }
        else if(pUpdateStatement->getSpecificContainer()[i]->getWithoutGoto().valid()){
        }
        else
            assert(0);
    }
}

SigExpressionHandle ConvertGraphInfo::convert(const PExprCheckStatementHandle & pCheckStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map) {
    return ConvertGraphInfo::convert(pCheckStatement->getBool(), _vecSig, _map);
}

SigExpressionHandle ConvertGraphInfo::convert(const PExprReadOrWriteOrCheckStatementHandle & pReadOrWriteOrCheckStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map) {
    if(pReadOrWriteOrCheckStatement->getRead().valid()){
        return SigExpression::makeHandle(8);
    }
    else if(pReadOrWriteOrCheckStatement->getWrite().valid()){
        return SigExpression::makeHandle(8);
    }
    else if(pReadOrWriteOrCheckStatement->getCheck().valid()){
        return ConvertGraphInfo::convert(pReadOrWriteOrCheckStatement->getCheck(), _vecSig, _map);
    }
    else
        assert(0);
}

SigExpressionHandle ConvertGraphInfo::convert(const PExprIfStatementPrefixHandle & pIfStatementPrefix, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map) {
    return ConvertGraphInfo::convert(pIfStatementPrefix->getBoolExpressionHandle(), _vecSig, _map);
}

SigExpressionHandle ConvertGraphInfo::convert(const PExprIfStatementWithoutGotoHandle & pIfStatementWithoutGoto, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map) {

    SigExpressionHandle sig;
    SigExpressionHandle sig_pre = ConvertGraphInfo::convert(pIfStatementWithoutGoto->getIfStatementPrefix(), _vecSig, _map);
    sig = sig_pre;

    std::vector<PExprReadOrWriteOrCheckStatementHandle> _vecRWC = pIfStatementWithoutGoto->getRWCContainer();
    std::vector<PExprIfStatementWithoutGotoHandle> _vecWithout = pIfStatementWithoutGoto->getIfStatementWithoutGotoContainer();

    for(int i = 0 ; i < _vecRWC.size() ; ++i){
        if(_vecRWC[i]->getRead().valid()){
        }
        else if(_vecRWC[i]->getWrite().valid()){
        }
        else if(_vecRWC[i]->getCheck().valid()){
            sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(_vecRWC[i]->getCheck(), _vecSig, _map));
        }
        else
            assert(0);
    }

    for(int i = 0 ; i < _vecWithout.size() ; ++i){
        sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(_vecWithout[i], _vecSig, _map));
    }

    return sig;

}
