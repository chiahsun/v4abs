#include "ConvertPExpr2VRExpr.h"
#include "utility/log/Log.h"
    
void ConvertPExpr2VRExpr::convert
  ( PExprUpdateStatementHandle pUpdateStatement
  , std::vector<VRExprExpression> & vecRead
  , std::vector<VRExprExpression> & vecWrite
  , std::vector<VRExprExpression> & vecCheck) {

    std::vector<PExprAllUpdateStatementHandle> vecUpdate = pUpdateStatement->getAllContainer();

    FOR_EACH(pAllUpdateStatement, vecUpdate) 
      { convert(pAllUpdateStatement, vecRead, vecWrite, vecCheck); }

    std::vector<PExprSpecificUpdateStatementHandle> vecSpecific = pUpdateStatement->getSpecificContainer();

    FOR_EACH(pSpecificUpdateStatement, vecSpecific)
      { convert(pSpecificUpdateStatement, vecRead, vecWrite, vecCheck); }

}
    
void ConvertPExpr2VRExpr::convert
  ( PExprAllUpdateStatementHandle pAllUpdateStatement
  , std::vector<VRExprExpression> & vecRead
  , std::vector<VRExprExpression> & vecWrite
  , std::vector<VRExprExpression> & vecCheck) {
    PExprReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement = pAllUpdateStatement->getRWC();
    PExprIfStatementWithoutGotoHandle pIfStatmentWithoutGoto = pAllUpdateStatement->getWithoutGoto();

    if (pReadOrWriteOrCheckStatement.valid()) {
        convert(pReadOrWriteOrCheckStatement, vecRead, vecWrite, vecCheck);
    } else if (pIfStatmentWithoutGoto.valid()) {
        convert(pIfStatmentWithoutGoto, vecRead, vecWrite, vecCheck);
    } else {
        LOG(ERROR) << "No such branch";
    }
}
    
void ConvertPExpr2VRExpr::convert
  ( PExprSpecificUpdateStatementHandle pSpecificUpdateStatement
  , std::vector<VRExprExpression> & vecRead
  , std::vector<VRExprExpression> & vecWrite
  , std::vector<VRExprExpression> & vecCheck) {
    PExprReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement = pSpecificUpdateStatement->getRWC();
    PExprIfStatementWithoutGotoHandle pIfStatmentWithoutGoto = pSpecificUpdateStatement->getWithoutGoto();
    if (pReadOrWriteOrCheckStatement.valid()) {
        convert(pReadOrWriteOrCheckStatement, vecRead, vecWrite, vecCheck);
    } else if (pIfStatmentWithoutGoto.valid()) {
        convert(pIfStatmentWithoutGoto, vecRead, vecWrite, vecCheck);
    } else {
        LOG(ERROR) << "No such branch";
    }
}
    
    
void ConvertPExpr2VRExpr::convert
  ( PExprReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement
  , std::vector<VRExprExpression> & vecRead
  , std::vector<VRExprExpression> & vecWrite
  , std::vector<VRExprExpression> & vecCheck) {
    PExprReadStatementHandle pRead = pReadOrWriteOrCheckStatement->getRead();
    PExprWriteStatementHandle pWrite = pReadOrWriteOrCheckStatement->getWrite();
    PExprCheckStatementHandle pCheck = pReadOrWriteOrCheckStatement->getCheck();

    if (pRead.valid()) {
        vecRead.push_back(makeIdentifier(pRead->getName()));
    } else if (pWrite.valid()) {
        vecWrite.push_back(makeIdentifier(pWrite->getName()));
    } else if (pCheck.valid()) {
        vecCheck.push_back(convert(pCheck));
    } else {
        LOG(ERROR) << "No such branch";
    }
}

VRExprExpression ConvertPExpr2VRExpr::convert(PExprCheckStatementHandle pCheck) {
    return convert(pCheck->getBool());
}
                      
    
void ConvertPExpr2VRExpr::convert
  ( PExprIfStatementWithGotoHandle pIfStatement
  , std::vector<VRExprExpression> & vecReadAll
  , std::vector<VRExprExpression> & vecWriteAll
  , std::vector<VRExprExpression> & vecCheckAll) {
    std::vector<VRExprExpression> vecRead, vecWrite, vecCheck;

    VRExprExpression pIf = convert(pIfStatement->getIfStatementPrefix());
    PExprEndStatementHandle pEnd = pIfStatement->getEndStatement();
    CONST_FOR_EACH(pSpecificUpdateStatement, pIfStatement->getSpecificContainer()) {
        convert(pSpecificUpdateStatement, vecRead, vecWrite, vecCheck);
    }

    appendIf(vecRead, pIf);
    appendIf(vecWrite, pIf);
    appendIf(vecCheck, pIf);
    appendVec(vecReadAll, vecRead);
    appendVec(vecWriteAll, vecWrite);
    appendVec(vecCheckAll, vecCheck);
}
    
void ConvertPExpr2VRExpr::convert
  (PExprIfStatementWithoutGotoHandle pIfStatement
  , std::vector<VRExprExpression> & vecReadAll
  , std::vector<VRExprExpression> & vecWriteAll
  , std::vector<VRExprExpression> & vecCheckAll) {

    VRExprExpression pIf = convert(pIfStatement->getIfStatementPrefix());

    {
    std::vector<VRExprExpression> vecRead, vecWrite, vecCheck;
    CONST_FOR_EACH(pIfStatementInner, pIfStatement->getIfStatementWithoutGotoContainer()) {
        convert(pIfStatementInner, vecRead, vecWrite, vecCheck);
    }
    appendIf(vecRead, pIf);
    appendIf(vecWrite, pIf);
    appendIf(vecCheck, pIf);
    appendVec(vecReadAll, vecRead);
    appendVec(vecWriteAll, vecWrite);
    appendVec(vecCheckAll, vecCheck);
  }

    {
    std::vector<VRExprExpression> vecRead, vecWrite, vecCheck;
    CONST_FOR_EACH(pReadOrWriteOrCheckStatement, pIfStatement->getRWCContainer()) {
        convert(pReadOrWriteOrCheckStatement, vecRead, vecWrite, vecCheck);
    }
    appendIf(vecRead, pIf);
    appendIf(vecWrite, pIf);
    appendIf(vecCheck, pIf);
    appendVec(vecReadAll, vecRead);
    appendVec(vecWriteAll, vecWrite);
    appendVec(vecCheckAll, vecCheck);
    }
}
    
VRExprExpression ConvertPExpr2VRExpr::convert(PExprIfStatementPrefixHandle pIfStatementPrefix) {
    return convert(pIfStatementPrefix->getBoolExpressionHandle());
}


VRExprExpression ConvertPExpr2VRExpr::convert(PExprBoolExpressionHandle pBoolExpression) {
    switch(pBoolExpression->getOp()) {
        case PExprBoolExpression::IDENTIFIER:
        case PExprBoolExpression::CONSTANT:
            return VRExprExpression(convertToPrimary(pBoolExpression));
        case PExprBoolExpression::LOGICAL_AND:
        case PExprBoolExpression::LOGICAL_OR:
        case PExprBoolExpression::LOGICAL_XOR:
        case PExprBoolExpression::LOGICAL_EQUAL:
            return convertBinary(pBoolExpression);
        case PExprBoolExpression::LOGICAL_NOT:
            return convertUnary(pBoolExpression);
        default:
            LOG(ERROR) << "Not implemented branch, please check";
    }
    assert(0);
}

VRExprPrimary ConvertPExpr2VRExpr::convertToPrimary(PExprBoolExpressionHandle pBoolExpression) {
    switch(pBoolExpression->getOp()) {
        case PExprBoolExpression::IDENTIFIER:
            return VRExprPrimary(convertIdentifier(pBoolExpression));
        case PExprBoolExpression::CONSTANT:
            return VRExprPrimary(convertConstant(pBoolExpression));
        default:
            LOG(ERROR) << "Not implemented branch, please check " << pBoolExpression->toString();
    }
    assert(0);
}

VRExprIdentifier ConvertPExpr2VRExpr::convertIdentifier(PExprBoolExpressionHandle pBoolExpression) {
    assert(pBoolExpression->getOp() == PExprBoolExpression::IDENTIFIER);
    return VRExprIdentifier(pBoolExpression->getName());
}

VRExprNumber ConvertPExpr2VRExpr::convertConstant(PExprBoolExpressionHandle pBoolExpression) {
    assert(pBoolExpression->getOp() == PExprBoolExpression::CONSTANT);
    return convert(pBoolExpression->getConstant());
}

VRExprExpression ConvertPExpr2VRExpr::convertUnary(PExprBoolExpressionHandle pBoolExpression) {
    assert(pBoolExpression->getOp() == PExprBoolExpression::LOGICAL_NOT);
    PExprBoolExpressionHandle pInner = pBoolExpression->getFst();
    if (pInner->getOp() == PExprBoolExpression::IDENTIFIER) {
       return makeUnaryExpression(UNARY_NOT, convertIdentifier(pInner));
    } else if (pInner->getOp() == PExprBoolExpression::LOGICAL_NOT) {
        return convert(pInner->getFst());
    } else if (pInner->getOp() == PExprBoolExpression::LOGICAL_AND
            || pInner->getOp() == PExprBoolExpression::LOGICAL_OR
            ) {
        PExprBoolExpressionHandle pInnerFst = PExprBoolExpression::makeUnaryNotHandle(pInner->getFst());
        PExprBoolExpressionHandle pInnerSnd = PExprBoolExpression::makeUnaryNotHandle(pInner->getSnd());

        VRExprExpression pFst = convert(pInnerFst);
        VRExprExpression pSnd = convert(pInnerSnd);
        if (pInner->getOp() == PExprBoolExpression::LOGICAL_AND) {
            return makeBinaryExpression(pFst, BINARY_LOGICAL_OR, pSnd);
        } else if (pInner->getOp() == PExprBoolExpression::LOGICAL_OR) {
            return makeBinaryExpression(pFst, BINARY_LOGICAL_AND, pSnd);
        } else {
            assert(0);
        }
    } else if ( pInner->getOp() == PExprBoolExpression::LOGICAL_EQUAL
            || pInner->getOp() == PExprBoolExpression::LOGICAL_XOR ) {
        LOG(ERROR) << "Invalid eq or xor convert to unary bool expression: "  << pBoolExpression->getFst()->toString() << " in " << pBoolExpression->toString();
    } else {
        LOG(ERROR) << "Unknown convert to unary bool expression: "  << pBoolExpression->getFst()->toString() << " in " << pBoolExpression->toString();
    }

    assert(0);
}

VRExprExpression ConvertPExpr2VRExpr::convertBinary(PExprBoolExpressionHandle pBoolExpression) {
    BinaryOpType opType = BINARY_LOGICAL_AND;
    assert(pBoolExpression->getFst().valid());
    assert(pBoolExpression->getSnd().valid());
    VRExprExpression pFst = convert(pBoolExpression->getFst());
    VRExprExpression pSnd = convert(pBoolExpression->getSnd());
    switch(pBoolExpression->getOp()) {
        case PExprBoolExpression::IDENTIFIER:
        case PExprBoolExpression::CONSTANT:
        case PExprBoolExpression::LOGICAL_NOT:
            LOG(ERROR) << "Invalid type";
        case PExprBoolExpression::LOGICAL_AND:
            opType = BINARY_LOGICAL_AND;
            return makeBinaryExpression(pFst, opType, pSnd);
        case PExprBoolExpression::LOGICAL_OR:
            opType = BINARY_LOGICAL_OR;
            return makeBinaryExpression(pFst, opType, pSnd);
        case PExprBoolExpression::LOGICAL_XOR:
            opType = BINARY_BITWISE_XOR;
            return makeBinaryExpression(pFst, opType, pSnd);
        case PExprBoolExpression::LOGICAL_EQUAL:
            opType = BINARY_EQ;
            return makeBinaryExpression(pFst, opType, pSnd);
        default:
            LOG(ERROR) << "No such branch";
    }
    assert(0);
}

VRExprNumber ConvertPExpr2VRExpr::convert(PExprConstantHandle pConstant) {
    std::string numberLiterals = pConstant->getName();

    bool isBaseUsed = false;
    int base = 2;

    for (unsigned int i = 0; i < numberLiterals.size(); ++i) {
        if (numberLiterals[i] == '\'')
            isBaseUsed = true;
        assert(i+1 < numberLiterals.size());
        char baseChar = numberLiterals[i+1];
        if (baseChar == 'b' || baseChar == 'B')
            base = 2;
        else if (baseChar == 'o' || baseChar == 'O')
            base = 8;
        else if (baseChar == 'd' || baseChar == 'D')
            base = 10;
        else if (baseChar == 'h' || baseChar == 'H')
            base = 16;
        else 
            LOG(ERROR) << "No such base in " << numberLiterals;
    }

    if (!isBaseUsed) {
        return VRExprNumber(VRExprUnsignedNumber(numberLiterals));
    } else {
        if (base == 2)
            return VRExprNumber(VRExprBinaryNumber(numberLiterals));
        else if (base == 8)
            return VRExprNumber(VRExprOctalNumber(numberLiterals));
        else if (base == 10)
            return VRExprNumber(VRExprDecimalNumber(numberLiterals));
        else if (base == 16)
            return VRExprNumber(VRExprHexNumber(numberLiterals));
    }

    assert(0);
}

void ConvertPExpr2VRExpr::appendIf
  ( std::vector<VRExprExpression> & vecExpr
  , VRExprExpression pIf) {
    FOR_EACH(expr, vecExpr) {
        expr.appendIfByThen(pIf);
    }
}
    
void ConvertPExpr2VRExpr::appendVec
  ( std::vector<VRExprExpression> & vec
  , const std::vector<VRExprExpression> & vecOther) {
    vec.insert(vec.end(), vecOther.begin(), vecOther.end());
}

