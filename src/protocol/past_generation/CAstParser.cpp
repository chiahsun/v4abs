#include "CAstParser.h"
#include <sstream>
#include <iostream>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

bool CAstBoolConstantParser::parsePos(
    CAstBoolConstantHandle & pBoolConstant
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolConstant = CAstBoolConstantHandle(CAstBoolConstant());

    CAstIdentifierHandle pIdentifier0;
    CAstConstantHandle pConstant1;
    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstConstantParser(getTokenStructure(), getTokenChild(pos)).parse(pConstant1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolConstant->push_back(pIdentifier0, pConstant1);
    return true;
}
bool CAstOnlyRWCWithoutGotoParser::parsePos(
    CAstOnlyRWCWithoutGotoHandle & pOnlyRWCWithoutGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pOnlyRWCWithoutGoto = CAstOnlyRWCWithoutGotoHandle(CAstOnlyRWCWithoutGoto());

    CAstIfStatementPrefixHandle pIfStatementPrefix0;
    CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement1;
    if (getTokenChildSize() > pos && CAstIfStatementPrefixParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementPrefix0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstReadOrWriteOrCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadOrWriteOrCheckStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pOnlyRWCWithoutGoto->push_back(pIfStatementPrefix0, pReadOrWriteOrCheckStatement1);
    return true;
}
bool CAstBoolWithParenthesisParser::parsePos(
    CAstBoolWithParenthesisHandle & pBoolWithParenthesis
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolWithParenthesis = CAstBoolWithParenthesisHandle(CAstBoolWithParenthesis());

    CAstBoolExpressionHandle pBoolExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolWithParenthesis->push_back(pBoolExpression0);
    return true;
}
bool CAstZeroOrMoreAllParser::parsePos(
    CAstZeroOrMoreAllHandle & pZeroOrMoreAll
  , unsigned int & pos) 
{
    pZeroOrMoreAll = CAstZeroOrMoreAllHandle(CAstZeroOrMoreAll());

    CAstAllUpdateStatementHandle pAllUpdateStatement0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstAllUpdateStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pAllUpdateStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreAll->push_back(pAllUpdateStatement0);
    }

    return true;
}
bool CAstReadStatementParser::parse(
    CAstReadStatementHandle & pReadStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pReadStatement = CAstReadStatementHandle(CAstReadStatement());

    CAstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "read") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pReadStatement->push_back(pIdentifier0);
    return true;
}
bool CAstBoolNotParser::parsePos(
    CAstBoolNotHandle & pBoolNot
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolNot = CAstBoolNotHandle(CAstBoolNot());

    CAstBoolExpressionHandle pBoolExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolNot->push_back(pBoolExpression0);
    return true;
}
bool CAstBitLiteralParser::parse(CAstBitLiteralHandle & pBitLiteral) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pBitLiteral = CAstBitLiteralHandle(CAstBitLiteral(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool CAstMultuWithoutGotoParser::parse(
    CAstMultuWithoutGotoHandle & pMultiWithoutGoto)
{
    unsigned int pos = 0, old_pos = 0;
    pMultiWithoutGoto = CAstMultuWithoutGotoHandle(CAstMultuWithoutGoto());

    CAstIfStatementPrefixHandle pIfStatementPrefix0;
    CAstZeroOrMoreRWCOrWithoutGotoHandle pZeroOrMoreRWCOrWithoutGoto1 = CAstZeroOrMoreRWCOrWithoutGotoHandle(CAstZeroOrMoreRWCOrWithoutGoto())
;
    if (getTokenChildSize() > pos && CAstIfStatementPrefixParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementPrefix0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "{") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (CAstZeroOrMoreRWCOrWithoutGotoParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreRWCOrWithoutGoto1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "}") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pMultiWithoutGoto->push_back(pIfStatementPrefix0, pZeroOrMoreRWCOrWithoutGoto1);
    return true;
}
bool CAstIdentifierParser::parse(CAstIdentifierHandle & pIdentifier) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pIdentifier = CAstIdentifierHandle(CAstIdentifier(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool CAstIfStatementPrefixParser::parse(
    CAstIfStatementPrefixHandle & pIfStatementPrefix)
{
    unsigned int pos = 0, old_pos = 0;
    pIfStatementPrefix = CAstIfStatementPrefixHandle(CAstIfStatementPrefix());

    CAstBoolExpressionHandle pBoolExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "if") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pIfStatementPrefix->push_back(pBoolExpression0);
    return true;
}
bool CAstKeywordWriteParser::parsePos(
    CAstKeywordWriteHandle & pKeywordWrite
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordWrite = CAstKeywordWriteHandle(CAstKeywordWrite());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "write") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordWrite->push_back();
    return true;
}
bool CAstEdgeStatementParser::parse(CAstEdgeStatementHandle & pEdgeStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstAllIfWithGotoHandle pAllIfWithGoto0;
    if (getTokenChildSize() > pos && CAstAllIfWithGotoParser(getTokenStructure(), getToken()).parsePos(pAllIfWithGoto0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEdgeStatement = CAstEdgeStatementHandle(CAstEdgeStatement(pAllIfWithGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstSpecificEndHandle pSpecificEnd0;
    if (getTokenChildSize() > pos && CAstSpecificEndParser(getTokenStructure(), getToken()).parsePos(pSpecificEnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEdgeStatement = CAstEdgeStatementHandle(CAstEdgeStatement(pSpecificEnd0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstOnlyWithoutGotoWithoutGotoParser::parsePos(
    CAstOnlyWithoutGotoWithoutGotoHandle & pOnlyWithoutGotoWithoutGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pOnlyWithoutGotoWithoutGoto = CAstOnlyWithoutGotoWithoutGotoHandle(CAstOnlyWithoutGotoWithoutGoto());

    CAstIfStatementPrefixHandle pIfStatementPrefix0;
    CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto1;
    if (getTokenChildSize() > pos && CAstIfStatementPrefixParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementPrefix0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIfStatementWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementWithoutGoto1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pOnlyWithoutGotoWithoutGoto->push_back(pIfStatementPrefix0, pIfStatementWithoutGoto1);
    return true;
}
bool CAstFloatingLiteralParser::parse(CAstFloatingLiteralHandle & pFloatingLiteral) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pFloatingLiteral = CAstFloatingLiteralHandle(CAstFloatingLiteral(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool CAstCheckStatementParser::parse(
    CAstCheckStatementHandle & pCheckStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pCheckStatement = CAstCheckStatementHandle(CAstCheckStatement());

    CAstBoolExpressionHandle pBoolExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "check") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pCheckStatement->push_back(pBoolExpression0);
    return true;
}
bool CAstKeywordTrueParser::parsePos(
    CAstKeywordTrueHandle & pKeywordTrue
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordTrue = CAstKeywordTrueHandle(CAstKeywordTrue());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "true") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordTrue->push_back();
    return true;
}
bool CAstRWCOrWithoutGotoParser::parse(CAstRWCOrWithoutGotoHandle & pRWCOrWithoutGoto) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement0;
    if (getTokenChildSize() > pos && CAstReadOrWriteOrCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadOrWriteOrCheckStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pRWCOrWithoutGoto = CAstRWCOrWithoutGotoHandle(CAstRWCOrWithoutGoto(pReadOrWriteOrCheckStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto0;
    if (getTokenChildSize() > pos && CAstIfStatementWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementWithoutGoto0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pRWCOrWithoutGoto = CAstRWCOrWithoutGotoHandle(CAstRWCOrWithoutGoto(pIfStatementWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstBoolExpressionParser::parse(CAstBoolExpressionHandle & pBoolExpression) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstBoolWithParenthesisHandle pBoolWithParenthesis0;
    if (getTokenChildSize() > pos && CAstBoolWithParenthesisParser(getTokenStructure(), getToken()).parsePos(pBoolWithParenthesis0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolWithParenthesis0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBoolAndHandle pBoolAnd0;
    if (getTokenChildSize() > pos && CAstBoolAndParser(getTokenStructure(), getToken()).parsePos(pBoolAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolAnd0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBoolOrHandle pBoolOr0;
    if (getTokenChildSize() > pos && CAstBoolOrParser(getTokenStructure(), getToken()).parsePos(pBoolOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolOr0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBoolXorHandle pBoolXor0;
    if (getTokenChildSize() > pos && CAstBoolXorParser(getTokenStructure(), getToken()).parsePos(pBoolXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolXor0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBoolNotHandle pBoolNot0;
    if (getTokenChildSize() > pos && CAstBoolNotParser(getTokenStructure(), getToken()).parsePos(pBoolNot0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolNot0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBoolConstantHandle pBoolConstant0;
    if (getTokenChildSize() > pos && CAstBoolConstantParser(getTokenStructure(), getToken()).parsePos(pBoolConstant0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pBoolConstant0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBoolExpression = CAstBoolExpressionHandle(CAstBoolExpression(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstWriteStatementParser::parse(
    CAstWriteStatementHandle & pWriteStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pWriteStatement = CAstWriteStatementHandle(CAstWriteStatement());

    CAstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "write") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pWriteStatement->push_back(pIdentifier0);
    return true;
}
bool CAstStateLabelParser::parse(
    CAstStateLabelHandle & pStateLabel)
{
    unsigned int pos = 0, old_pos = 0;
    pStateLabel = CAstStateLabelHandle(CAstStateLabel());

    CAstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ":") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pStateLabel->push_back(pIdentifier0);
    return true;
}
bool CAstKeywordGotoParser::parsePos(
    CAstKeywordGotoHandle & pKeywordGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordGoto = CAstKeywordGotoHandle(CAstKeywordGoto());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "goto") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordGoto->push_back();
    return true;
}
bool CAstConstantParser::parse(CAstConstantHandle & pConstant) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstIntegerLiteralHandle pIntegerLiteral0;
    if (getTokenChildSize() > pos && CAstIntegerLiteralParser(getTokenStructure(), getTokenChild(pos)).parse(pIntegerLiteral0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstant = CAstConstantHandle(CAstConstant(pIntegerLiteral0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstFloatingLiteralHandle pFloatingLiteral0;
    if (getTokenChildSize() > pos && CAstFloatingLiteralParser(getTokenStructure(), getTokenChild(pos)).parse(pFloatingLiteral0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstant = CAstConstantHandle(CAstConstant(pFloatingLiteral0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstBitLiteralHandle pBitLiteral0;
    if (getTokenChildSize() > pos && CAstBitLiteralParser(getTokenStructure(), getTokenChild(pos)).parse(pBitLiteral0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstant = CAstConstantHandle(CAstConstant(pBitLiteral0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstTransitionStatementParser::parse(CAstTransitionStatementHandle & pTransitionStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstOneOrMoreEdgeHandle pOneOrMoreEdge0;
    if (getTokenChildSize() > pos && CAstOneOrMoreEdgeParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreEdge0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pTransitionStatement = CAstTransitionStatementHandle(CAstTransitionStatement(pOneOrMoreEdge0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstSpecificEndParser::parsePos(
    CAstSpecificEndHandle & pSpecificEnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pSpecificEnd = CAstSpecificEndHandle(CAstSpecificEnd());

    CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific0 = CAstZeroOrMoreSpecificHandle(CAstZeroOrMoreSpecific())
;
    CAstEndStatementHandle pEndStatement1;
    if (CAstZeroOrMoreSpecificParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreSpecific0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstEndStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pEndStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pSpecificEnd->push_back(pZeroOrMoreSpecific0, pEndStatement1);
    return true;
}
bool CAstAllOrEdgeParser::parsePos(
    CAstAllOrEdgeHandle & pAllOrEdge
  , unsigned int & pos)
 {

    unsigned int old_pos = pos;

    CAstAllUpdateStatementHandle pAllUpdateStatement0;
    if (getTokenChildSize() > pos && CAstAllUpdateStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pAllUpdateStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pAllOrEdge = CAstAllOrEdgeHandle(CAstAllOrEdge(pAllUpdateStatement0));
        return true;
    }
    CAstEdgeStatementHandle pEdgeStatement0;
    if (getTokenChildSize() > pos && CAstEdgeStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pEdgeStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pAllOrEdge = CAstAllOrEdgeHandle(CAstAllOrEdge(pEdgeStatement0));
        return true;
    }
    reportChild();
    throw InvalidFormatException("Not valid option in composite rule without name");
}

bool CAstOneOrMoreStateParser::parsePos(
    CAstOneOrMoreStateHandle & pOneOrMoreState
  , unsigned int & pos) {

    pOneOrMoreState = CAstOneOrMoreStateHandle(CAstOneOrMoreState());

    CAstStateStatementHandle pStateStatement0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstStateStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStateStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreState->push_back(pStateStatement0);
    }

    return pos != initial_pos;
}

bool CAstZeroOrMoreRWCOrWithoutGotoParser::parsePos(
    CAstZeroOrMoreRWCOrWithoutGotoHandle & pZeroOrMoreRWCOrWithoutGoto
  , unsigned int & pos) 
{
    pZeroOrMoreRWCOrWithoutGoto = CAstZeroOrMoreRWCOrWithoutGotoHandle(CAstZeroOrMoreRWCOrWithoutGoto());

    CAstRWCOrWithoutGotoHandle pRWCOrWithoutGoto0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstRWCOrWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pRWCOrWithoutGoto0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreRWCOrWithoutGoto->push_back(pRWCOrWithoutGoto0);
    }

    return true;
}
bool CAstEndStatementParser::parse(CAstEndStatementHandle & pEndStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstGotoStatementHandle pGotoStatement0;
    if (getTokenChildSize() > pos && CAstGotoStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pGotoStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEndStatement = CAstEndStatementHandle(CAstEndStatement(pGotoStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstAssertStatementHandle pAssertStatement0;
    if (getTokenChildSize() > pos && CAstAssertStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pAssertStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEndStatement = CAstEndStatementHandle(CAstEndStatement(pAssertStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstZeroOrMoreRWCParser::parsePos(
    CAstZeroOrMoreRWCHandle & pZeroOrMoreRWC
  , unsigned int & pos) 
{
    pZeroOrMoreRWC = CAstZeroOrMoreRWCHandle(CAstZeroOrMoreRWC());

    CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstReadOrWriteOrCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadOrWriteOrCheckStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreRWC->push_back(pReadOrWriteOrCheckStatement0);
    }

    return true;
}
bool CAstIfStatementWithoutGotoParser::parse(CAstIfStatementWithoutGotoHandle & pIfStatementWithoutGoto) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstOnlyRWCWithoutGotoHandle pOnlyRWCWithoutGoto0;
    if (getTokenChildSize() > pos && CAstOnlyRWCWithoutGotoParser(getTokenStructure(), getToken()).parsePos(pOnlyRWCWithoutGoto0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIfStatementWithoutGoto = CAstIfStatementWithoutGotoHandle(CAstIfStatementWithoutGoto(pOnlyRWCWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstOnlyWithoutGotoWithoutGotoHandle pOnlyWithoutGotoWithoutGoto0;
    if (getTokenChildSize() > pos && CAstOnlyWithoutGotoWithoutGotoParser(getTokenStructure(), getToken()).parsePos(pOnlyWithoutGotoWithoutGoto0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIfStatementWithoutGoto = CAstIfStatementWithoutGotoHandle(CAstIfStatementWithoutGoto(pOnlyWithoutGotoWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstMultuWithoutGotoHandle pMultiWithoutGoto0;
    if (getTokenChildSize() > pos && CAstMultuWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pMultiWithoutGoto0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIfStatementWithoutGoto = CAstIfStatementWithoutGotoHandle(CAstIfStatementWithoutGoto(pMultiWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstSourceTextParser::parse(CAstSourceTextHandle & pSourceText) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstOneOrMoreStateHandle pOneOrMoreState0;
    if (getTokenChildSize() > pos && CAstOneOrMoreStateParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreState0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pSourceText = CAstSourceTextHandle(CAstSourceText(pOneOrMoreState0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstIfStatementWithGotoParser::parse(CAstIfStatementWithGotoHandle & pIfStatementWithGoto) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstOnlyEndWithGotoHandle pOnlyEndWithGoto0;
    if (getTokenChildSize() > pos && CAstOnlyEndWithGotoParser(getTokenStructure(), getToken()).parsePos(pOnlyEndWithGoto0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIfStatementWithGoto = CAstIfStatementWithGotoHandle(CAstIfStatementWithGoto(pOnlyEndWithGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstMultiWithGotoHandle pMultiWithGoto0;
    if (getTokenChildSize() > pos && CAstMultiWithGotoParser(getTokenStructure(), getToken()).parsePos(pMultiWithGoto0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIfStatementWithGoto = CAstIfStatementWithGotoHandle(CAstIfStatementWithGoto(pMultiWithGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstGotoStatementParser::parse(
    CAstGotoStatementHandle & pGotoStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pGotoStatement = CAstGotoStatementHandle(CAstGotoStatement());

    CAstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "goto") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pGotoStatement->push_back(pIdentifier0);
    return true;
}
bool CAstZeroOrMoreAllOrEdgeParser::parsePos(
    CAstZeroOrMoreAllOrEdgeHandle & pZeroOrMoreAllOrEdge
  , unsigned int & pos) 
{
    pZeroOrMoreAllOrEdge = CAstZeroOrMoreAllOrEdgeHandle(CAstZeroOrMoreAllOrEdge());

    CAstAllOrEdgeHandle pAllOrEdge0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstAllOrEdgeParser(getTokenStructure(), getToken()).parsePos(pAllOrEdge0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreAllOrEdge->push_back(pAllOrEdge0);
    }

    return true;
}
bool CAstOnlyEndWithGotoParser::parsePos(
    CAstOnlyEndWithGotoHandle & pOnlyEndWithGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pOnlyEndWithGoto = CAstOnlyEndWithGotoHandle(CAstOnlyEndWithGoto());

    CAstIfStatementPrefixHandle pIfStatementPrefix0;
    CAstEndStatementHandle pEndStatement1;
    if (getTokenChildSize() > pos && CAstIfStatementPrefixParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementPrefix0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstEndStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pEndStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pOnlyEndWithGoto->push_back(pIfStatementPrefix0, pEndStatement1);
    return true;
}
bool CAstKeywordIfParser::parsePos(
    CAstKeywordIfHandle & pKeywordIf
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordIf = CAstKeywordIfHandle(CAstKeywordIf());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "if") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordIf->push_back();
    return true;
}
bool CAstBoolAndParser::parsePos(
    CAstBoolAndHandle & pBoolAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolAnd = CAstBoolAndHandle(CAstBoolAnd());

    CAstBoolExpressionHandle pBoolExpression0;
    CAstBoolExpressionHandle pBoolExpression1;
    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "&") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "&") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolAnd->push_back(pBoolExpression0, pBoolExpression1);
    return true;
}
bool CAstStateStatementParser::parse(
    CAstStateStatementHandle & pStateStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pStateStatement = CAstStateStatementHandle(CAstStateStatement());

    CAstStateLabelHandle pStateLabel0;
    CAstTransitionStatementHandle pTransitionStatement1;
    if (getTokenChildSize() > pos && CAstStateLabelParser(getTokenStructure(), getTokenChild(pos)).parse(pStateLabel0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstTransitionStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pTransitionStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pStateStatement->push_back(pStateLabel0, pTransitionStatement1);
    return true;
}
bool CAstKeywordElseParser::parsePos(
    CAstKeywordElseHandle & pKeywordElse
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordElse = CAstKeywordElseHandle(CAstKeywordElse());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "else") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordElse->push_back();
    return true;
}
bool CAstKeywordCheckParser::parsePos(
    CAstKeywordCheckHandle & pKeywordCheck
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordCheck = CAstKeywordCheckHandle(CAstKeywordCheck());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "check") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordCheck->push_back();
    return true;
}
bool CAstReadOrWriteOrCheckStatementParser::parse(CAstReadOrWriteOrCheckStatementHandle & pReadOrWriteOrCheckStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstReadStatementHandle pReadStatement0;
    if (getTokenChildSize() > pos && CAstReadStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pReadOrWriteOrCheckStatement = CAstReadOrWriteOrCheckStatementHandle(CAstReadOrWriteOrCheckStatement(pReadStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstWriteStatementHandle pWriteStatement0;
    if (getTokenChildSize() > pos && CAstWriteStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pWriteStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pReadOrWriteOrCheckStatement = CAstReadOrWriteOrCheckStatementHandle(CAstReadOrWriteOrCheckStatement(pWriteStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstCheckStatementHandle pCheckStatement0;
    if (getTokenChildSize() > pos && CAstCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pCheckStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pReadOrWriteOrCheckStatement = CAstReadOrWriteOrCheckStatementHandle(CAstReadOrWriteOrCheckStatement(pCheckStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstZeroOrMoreSpecificParser::parsePos(
    CAstZeroOrMoreSpecificHandle & pZeroOrMoreSpecific
  , unsigned int & pos) 
{
    pZeroOrMoreSpecific = CAstZeroOrMoreSpecificHandle(CAstZeroOrMoreSpecific());

    CAstSpecificUpdateStatementHandle pSpecificUpdateStatement0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstSpecificUpdateStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pSpecificUpdateStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreSpecific->push_back(pSpecificUpdateStatement0);
    }

    return true;
}
bool CAstKeywordFalseParser::parsePos(
    CAstKeywordFalseHandle & pKeywordFalse
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordFalse = CAstKeywordFalseHandle(CAstKeywordFalse());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "false") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordFalse->push_back();
    return true;
}
bool CAstBoolOrParser::parsePos(
    CAstBoolOrHandle & pBoolOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolOr = CAstBoolOrHandle(CAstBoolOr());

    CAstBoolExpressionHandle pBoolExpression0;
    CAstBoolExpressionHandle pBoolExpression1;
    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "|") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "|") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolOr->push_back(pBoolExpression0, pBoolExpression1);
    return true;
}
bool CAstKeywordAssertParser::parsePos(
    CAstKeywordAssertHandle & pKeywordAssert
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordAssert = CAstKeywordAssertHandle(CAstKeywordAssert());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "assert") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordAssert->push_back();
    return true;
}
bool CAstMultiWithGotoParser::parsePos(
    CAstMultiWithGotoHandle & pMultiWithGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pMultiWithGoto = CAstMultiWithGotoHandle(CAstMultiWithGoto());

    CAstIfStatementPrefixHandle pIfStatementPrefix0;
    CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific1 = CAstZeroOrMoreSpecificHandle(CAstZeroOrMoreSpecific())
;
    CAstEndStatementHandle pEndStatement2;
    if (getTokenChildSize() > pos && CAstIfStatementPrefixParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementPrefix0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "{") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (CAstZeroOrMoreSpecificParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreSpecific1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstEndStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pEndStatement2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "}") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pMultiWithGoto->push_back(pIfStatementPrefix0, pZeroOrMoreSpecific1, pEndStatement2);
    return true;
}
bool CAstBoolXorParser::parsePos(
    CAstBoolXorHandle & pBoolXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBoolXor = CAstBoolXorHandle(CAstBoolXor());

    CAstBoolExpressionHandle pBoolExpression0;
    CAstBoolExpressionHandle pBoolExpression1;
    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "^") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstBoolExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pBoolExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBoolXor->push_back(pBoolExpression0, pBoolExpression1);
    return true;
}
bool CAstAssertStatementParser::parse(
    CAstAssertStatementHandle & pAssertStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pAssertStatement = CAstAssertStatementHandle(CAstAssertStatement());

    CAstIntegerLiteralHandle pIntegerLiteral0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "assert") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIntegerLiteralParser(getTokenStructure(), getTokenChild(pos)).parse(pIntegerLiteral0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ")") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pAssertStatement->push_back(pIntegerLiteral0);
    return true;
}
bool CAstSpecificUpdateStatementParser::parse(CAstSpecificUpdateStatementHandle & pSpecificUpdateStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement0;
    if (getTokenChildSize() > pos && CAstReadOrWriteOrCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadOrWriteOrCheckStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pSpecificUpdateStatement = CAstSpecificUpdateStatementHandle(CAstSpecificUpdateStatement(pReadOrWriteOrCheckStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto0;
    if (getTokenChildSize() > pos && CAstIfStatementWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementWithoutGoto0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pSpecificUpdateStatement = CAstSpecificUpdateStatementHandle(CAstSpecificUpdateStatement(pIfStatementWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstAllIfWithGotoParser::parsePos(
    CAstAllIfWithGotoHandle & pAllIfWithGoto
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pAllIfWithGoto = CAstAllIfWithGotoHandle(CAstAllIfWithGoto());

    CAstZeroOrMoreAllHandle pZeroOrMoreAll0 = CAstZeroOrMoreAllHandle(CAstZeroOrMoreAll())
;
    CAstIfStatementWithGotoHandle pIfStatementWithGoto1;
    if (CAstZeroOrMoreAllParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreAll0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && CAstIfStatementWithGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementWithGoto1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pAllIfWithGoto->push_back(pZeroOrMoreAll0, pIfStatementWithGoto1);
    return true;
}
bool CAstIntegerLiteralParser::parse(CAstIntegerLiteralHandle & pIntegerLiteral) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pIntegerLiteral = CAstIntegerLiteralHandle(CAstIntegerLiteral(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool CAstOneOrMoreEdgeParser::parsePos(
    CAstOneOrMoreEdgeHandle & pOneOrMoreEdge
  , unsigned int & pos) {

    pOneOrMoreEdge = CAstOneOrMoreEdgeHandle(CAstOneOrMoreEdge());

    CAstEdgeStatementHandle pEdgeStatement0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && CAstEdgeStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pEdgeStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreEdge->push_back(pEdgeStatement0);
    }

    return pos != initial_pos;
}

bool CAstAllUpdateStatementParser::parse(CAstAllUpdateStatementHandle & pAllUpdateStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement0;
    if (getTokenChildSize() > pos && CAstReadOrWriteOrCheckStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pReadOrWriteOrCheckStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pAllUpdateStatement = CAstAllUpdateStatementHandle(CAstAllUpdateStatement(pReadOrWriteOrCheckStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto0;
    if (getTokenChildSize() > pos && CAstIfStatementWithoutGotoParser(getTokenStructure(), getTokenChild(pos)).parse(pIfStatementWithoutGoto0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pAllUpdateStatement = CAstAllUpdateStatementHandle(CAstAllUpdateStatement(pIfStatementWithoutGoto0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool CAstKeywordReadParser::parsePos(
    CAstKeywordReadHandle & pKeywordRead
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pKeywordRead = CAstKeywordReadHandle(CAstKeywordRead());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "read") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pKeywordRead->push_back();
    return true;
}
