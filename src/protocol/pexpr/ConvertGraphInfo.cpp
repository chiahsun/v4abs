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
        if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_AND)
            return SigExpression::makeHandle(6, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_OR)
            return SigExpression::makeHandle(5, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_XOR)
            return SigExpression::makeHandle(7, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else if (pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_EQUAL)
            return SigExpression::makeHandle(4, ConvertGraphInfo::convert(pFst, _vecSig, _map), ConvertGraphInfo::convert(pSnd, _vecSig, _map));
        else 
            assert(0);
    }
    else if(pBoolExpression->getFst().valid() && !pBoolExpression->getSnd().valid()){ 
        PExprBoolExpressionHandle pFst = pBoolExpression->getFst();
        if( pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_NOT){
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
    SigExpressionHandle sig = SigExpression::makeHandle(8);
    for(int i = 0 ; i < pUpdateStatement->getAllContainer().size() ; ++i) {
        if(pUpdateStatement->getAllContainer()[i]->getRWC().valid()){
            if(pUpdateStatement->getAllContainer()[i]->getRWC()->getRead().valid()){
            }
            else if(pUpdateStatement->getAllContainer()[i]->getRWC()->getWrite().valid()){
            }
            else if(pUpdateStatement->getAllContainer()[i]->getRWC()->getCheck().valid()){
                sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(pUpdateStatement->getAllContainer()[i]
                                                                                                        ->getRWC()
                                                                                                        ->getCheck(), _vecSig,_map));
            }
            else
                assert(0);
        }
        else if(pUpdateStatement->getAllContainer()[i]->getWithoutGoto().valid()){
            sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(pUpdateStatement->getAllContainer()[i]
                                                                                                    ->getWithoutGoto(), _vecSig, _map));
        }
        else
            assert(0);
    }
    for(int i = 0 ; i < pUpdateStatement->getSpecificContainer().size() ; ++i){ 
        if(pUpdateStatement->getSpecificContainer()[i]->getRWC().valid()){
            if(pUpdateStatement->getSpecificContainer()[i]->getRWC()->getRead().valid()){
            }
            else if(pUpdateStatement->getSpecificContainer()[i]->getRWC()->getWrite().valid()){
            }
            else if(pUpdateStatement->getSpecificContainer()[i]->getRWC()->getCheck().valid()){
                sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(pUpdateStatement->getSpecificContainer()[i]
                                                                                                        ->getRWC()
                                                                                                        ->getCheck(), _vecSig, _map));
            }
            else
                assert(0);
        }
        else if(pUpdateStatement->getSpecificContainer()[i]->getWithoutGoto().valid()){
            sig = SigExpression::makeHandle(6, sig, ConvertGraphInfo::convert(pUpdateStatement->getSpecificContainer()[i]
                                                                                                    ->getWithoutGoto(), _vecSig, _map));
        }
        else
            assert(0);
    }
    return sig;
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
