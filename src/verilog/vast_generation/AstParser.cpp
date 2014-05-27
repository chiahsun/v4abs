#include "AstParser.h"
#include <sstream>
#include <iostream>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

bool AstListOfPortIdentifiersParser::parse(
    AstListOfPortIdentifiersHandle & pListOfPortIdentifiers)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfPortIdentifiers = AstListOfPortIdentifiersHandle(AstListOfPortIdentifiers());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1 = AstZeroOrMoreCommaIdentifierHandle(AstZeroOrMoreCommaIdentifier())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaIdentifierParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaIdentifier1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfPortIdentifiers->push_back(pIdentifier0, pZeroOrMoreCommaIdentifier1);
    return true;
}
bool AstZeroOrOneListOfModuleConnectionsParser::parsePos(
    AstZeroOrOneListOfModuleConnectionsHandle & pZeroOrOneListOfModuleConnections
  , unsigned int & pos) 
{
    pZeroOrOneListOfModuleConnections = AstZeroOrOneListOfModuleConnectionsHandle(AstZeroOrOneListOfModuleConnections());

    AstListOfModuleConnectionsHandle pListOfModuleConnections0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstListOfModuleConnectionsParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfModuleConnections0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneListOfModuleConnections->push_back(pListOfModuleConnections0);


return true;
}
bool AstZeroOrOneNameOfGateInstanceParser::parsePos(
    AstZeroOrOneNameOfGateInstanceHandle & pZeroOrOneNameOfGateInstance
  , unsigned int & pos) 
{
    pZeroOrOneNameOfGateInstance = AstZeroOrOneNameOfGateInstanceHandle(AstZeroOrOneNameOfGateInstance());

    AstNameOfGateInstanceHandle pNameOfGateInstance0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstNameOfGateInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNameOfGateInstance0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneNameOfGateInstance->push_back(pNameOfGateInstance0);


return true;
}
bool AstBinaryOperatorNotEqualParser::parsePos(
    AstBinaryOperatorNotEqualHandle & pBinaryOperatorNotEqual
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorNotEqual = AstBinaryOperatorNotEqualHandle(AstBinaryOperatorNotEqual());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    pBinaryOperatorNotEqual->push_back();
    return true;
}
bool AstBinaryOperatorXorParser::parsePos(
    AstBinaryOperatorXorHandle & pBinaryOperatorXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorXor = AstBinaryOperatorXorHandle(AstBinaryOperatorXor());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "^") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorXor->push_back();
    return true;
}
bool AstBinaryExpressionMinusParser::parsePos(
    AstBinaryExpressionMinusHandle & pBinaryExpressionMinus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionMinus = AstBinaryExpressionMinusHandle(AstBinaryExpressionMinus());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "-") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionMinus->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryExpressionParser::parsePos(
    AstUnaryExpressionHandle & pUnaryExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryExpression = AstUnaryExpressionHandle(AstUnaryExpression());

    AstUnaryOperatorHandle pUnaryOperator0;
    AstPrimaryHandle pPrimary1;
    if (getTokenChildSize() > pos && AstUnaryOperatorParser(getTokenStructure(), getTokenChild(pos)).parse(pUnaryOperator0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstPrimaryParser(getTokenStructure(), getTokenChild(pos)).parse(pPrimary1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryExpression->push_back(pUnaryOperator0, pPrimary1);
    return true;
}
bool AstBinaryOperatorLeqParser::parsePos(
    AstBinaryOperatorLeqHandle & pBinaryOperatorLeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorLeq = AstBinaryOperatorLeqHandle(AstBinaryOperatorLeq());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
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

    pBinaryOperatorLeq->push_back();
    return true;
}
bool AstKeywordParameterParser::parse(AstKeywordParameterHandle & pKeywordParameter) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordParameter = AstKeywordParameterHandle(AstKeywordParameter(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordMacroModuleParser::parse(AstKeywordMacroModuleHandle & pKeywordMacroModule) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordMacroModule = AstKeywordMacroModuleHandle(AstKeywordMacroModule(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionGeqParser::parsePos(
    AstBinaryExpressionGeqHandle & pBinaryExpressionGeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionGeq = AstBinaryExpressionGeqHandle(AstBinaryExpressionGeq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionGeq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryOperatorNotParser::parsePos(
    AstUnaryOperatorNotHandle & pUnaryOperatorNot
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorNot = AstUnaryOperatorNotHandle(AstUnaryOperatorNot());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorNot->push_back();
    return true;
}
bool AstZeroOrMoreCommaNetAssignmentParser::parsePos(
    AstZeroOrMoreCommaNetAssignmentHandle & pZeroOrMoreCommaNetAssignment
  , unsigned int & pos) 
{
    pZeroOrMoreCommaNetAssignment = AstZeroOrMoreCommaNetAssignmentHandle(AstZeroOrMoreCommaNetAssignment());

    AstNetAssignmentHandle pNetAssignment0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstNetAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pNetAssignment0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaNetAssignment->push_back(pNetAssignment0);
    }

    return true;
}
bool AstEventExpressionParser::parse(AstEventExpressionHandle & pEventExpression) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstExpressionHandle pExpression0;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstPosedgeExpressionHandle pPosedgeExpression0;
    if (getTokenChildSize() > pos && AstPosedgeExpressionParser(getTokenStructure(), getToken()).parsePos(pPosedgeExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pPosedgeExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNegedgeExpressionHandle pNegedgeExpression0;
    if (getTokenChildSize() > pos && AstNegedgeExpressionParser(getTokenStructure(), getToken()).parsePos(pNegedgeExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pNegedgeExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstEventCommaEventHandle pEventCommaEvent0;
    if (getTokenChildSize() > pos && AstEventCommaEventParser(getTokenStructure(), getToken()).parsePos(pEventCommaEvent0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pEventCommaEvent0));
        return true;
    } else {
        pos = old_pos;
    }
    AstEventOrEventHandle pEventOrEvent0;
    if (getTokenChildSize() > pos && AstEventOrEventParser(getTokenStructure(), getToken()).parsePos(pEventOrEvent0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventExpression = AstEventExpressionHandle(AstEventExpression(pEventOrEvent0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstZeroOrMoreCommaNamedPortConnectionParser::parsePos(
    AstZeroOrMoreCommaNamedPortConnectionHandle & pZeroOrMoreCommaNamedPortConnection
  , unsigned int & pos) 
{
    pZeroOrMoreCommaNamedPortConnection = AstZeroOrMoreCommaNamedPortConnectionHandle(AstZeroOrMoreCommaNamedPortConnection());

    AstNamedPortConnectionHandle pNamedPortConnection0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstNamedPortConnectionParser(getTokenStructure(), getTokenChild(pos)).parse(pNamedPortConnection0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaNamedPortConnection->push_back(pNamedPortConnection0);
    }

    return true;
}
bool AstCaseItemParser::parse(AstCaseItemHandle & pCaseItem) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstCaseItemItemHandle pCaseItemItem0;
    if (getTokenChildSize() > pos && AstCaseItemItemParser(getTokenStructure(), getToken()).parsePos(pCaseItemItem0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pCaseItem = AstCaseItemHandle(AstCaseItem(pCaseItemItem0));
        return true;
    } else {
        pos = old_pos;
    }
    AstCaseItemDefaultHandle pCaseItemDefault0;
    if (getTokenChildSize() > pos && AstCaseItemDefaultParser(getTokenStructure(), getToken()).parsePos(pCaseItemDefault0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pCaseItem = AstCaseItemHandle(AstCaseItem(pCaseItemDefault0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryExpressionBwAndParser::parsePos(
    AstBinaryExpressionBwAndHandle & pBinaryExpressionBwAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionBwAnd = AstBinaryExpressionBwAndHandle(AstBinaryExpressionBwAnd());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionBwAnd->push_back(pExpression0, pExpression1);
    return true;
}
bool AstIdentifierParser::parse(AstIdentifierHandle & pIdentifier) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstSingleIdentifierHandle pSingleIdentifier0;
    if (getTokenChildSize() > pos && AstSingleIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pSingleIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIdentifier = AstIdentifierHandle(AstIdentifier(pSingleIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstMultiIdentifierHandle pMultiIdentifier0;
    if (getTokenChildSize() > pos && AstMultiIdentifierParser(getTokenStructure(), getToken()).parsePos(pMultiIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pIdentifier = AstIdentifierHandle(AstIdentifier(pMultiIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstContinuousAssignParser::parse(
    AstContinuousAssignHandle & pContinuousAssign)
{
    unsigned int pos = 0, old_pos = 0;
    pContinuousAssign = AstContinuousAssignHandle(AstContinuousAssign());

    AstKeywordAssignHandle pKeywordAssign0;
    AstListOfNetAssignmentsHandle pListOfNetAssignments1;
    if (getTokenChildSize() > pos && AstKeywordAssignParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordAssign0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfNetAssignmentsParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfNetAssignments1)) {
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

    pContinuousAssign->push_back(pKeywordAssign0, pListOfNetAssignments1);
    return true;
}
bool AstNumberParser::parse(AstNumberHandle & pNumber) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstUnsignedNumberHandle pUnsignedNumber0;
    if (getTokenChildSize() > pos && AstUnsignedNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pUnsignedNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNumber = AstNumberHandle(AstNumber(pUnsignedNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryNumberHandle pBinaryNumber0;
    if (getTokenChildSize() > pos && AstBinaryNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pBinaryNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNumber = AstNumberHandle(AstNumber(pBinaryNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstOctalNumberHandle pOctalNumber0;
    if (getTokenChildSize() > pos && AstOctalNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pOctalNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNumber = AstNumberHandle(AstNumber(pOctalNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstDecimalNumberHandle pDecimalNumber0;
    if (getTokenChildSize() > pos && AstDecimalNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pDecimalNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNumber = AstNumberHandle(AstNumber(pDecimalNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstHeximalNumberHandle pHeximalNumber0;
    if (getTokenChildSize() > pos && AstHeximalNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pHeximalNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNumber = AstNumberHandle(AstNumber(pHeximalNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstNetLvalueBitSelectParser::parsePos(
    AstNetLvalueBitSelectHandle & pNetLvalueBitSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pNetLvalueBitSelect = AstNetLvalueBitSelectHandle(AstNetLvalueBitSelect());

    AstIdentifierHandle pIdentifier0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pNetLvalueBitSelect->push_back(pIdentifier0, pExpression1);
    return true;
}
bool AstExpressionParser::parse(AstExpressionHandle & pExpression) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstPrimaryHandle pPrimary0;
    if (getTokenChildSize() > pos && AstPrimaryParser(getTokenStructure(), getTokenChild(pos)).parse(pPrimary0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pExpression = AstExpressionHandle(AstExpression(pPrimary0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBracedExpressionHandle pBracedExpression0;
    if (getTokenChildSize() > pos && AstBracedExpressionParser(getTokenStructure(), getToken()).parsePos(pBracedExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pExpression = AstExpressionHandle(AstExpression(pBracedExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryExpressionHandle pUnaryExpression0;
    if (getTokenChildSize() > pos && AstUnaryExpressionParser(getTokenStructure(), getToken()).parsePos(pUnaryExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pExpression = AstExpressionHandle(AstExpression(pUnaryExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstTernaryExpressionHandle pTernaryExpression0;
    if (getTokenChildSize() > pos && AstTernaryExpressionParser(getTokenStructure(), getToken()).parsePos(pTernaryExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pExpression = AstExpressionHandle(AstExpression(pTernaryExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryExpressionHandle pBinaryExpression0;
    if (getTokenChildSize() > pos && AstBinaryExpressionParser(getTokenStructure(), getToken()).parsePos(pBinaryExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pExpression = AstExpressionHandle(AstExpression(pBinaryExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstNamedPortExpressionParser::parse(
    AstNamedPortExpressionHandle & pNamedPortExpression)
{
    unsigned int pos = 0, old_pos = 0;
    pNamedPortExpression = AstNamedPortExpressionHandle(AstNamedPortExpression());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrOnePortExpressionHandle pZeroOrOnePortExpression1 = AstZeroOrOnePortExpressionHandle(AstZeroOrOnePortExpression())
;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ".") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
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

    if (AstZeroOrOnePortExpressionParser(getTokenStructure(), getToken()).parsePos(pZeroOrOnePortExpression1, pos)) {
        /* do nothing */
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

    pNamedPortExpression->push_back(pIdentifier0, pZeroOrOnePortExpression1);
    return true;
}
bool AstStatementParser::parse(AstStatementHandle & pStatement) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstBlockingAssingmentSemicolonHandle pBlockingAssignmentSemicolon0;
    if (getTokenChildSize() > pos && AstBlockingAssingmentSemicolonParser(getTokenStructure(), getToken()).parsePos(pBlockingAssignmentSemicolon0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pBlockingAssignmentSemicolon0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNonBlockingAssignmentSemicolonHandle pNonBlockingAssignmentSemicolon0;
    if (getTokenChildSize() > pos && AstNonBlockingAssignmentSemicolonParser(getTokenStructure(), getToken()).parsePos(pNonBlockingAssignmentSemicolon0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pNonBlockingAssignmentSemicolon0));
        return true;
    } else {
        pos = old_pos;
    }
    AstProceduralContinuousAssignmentSemicolonHandle pProceduralContinuousAssignmentSemicoln0;
    if (getTokenChildSize() > pos && AstProceduralContinuousAssignmentSemicolonParser(getTokenStructure(), getToken()).parsePos(pProceduralContinuousAssignmentSemicoln0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pProceduralContinuousAssignmentSemicoln0));
        return true;
    } else {
        pos = old_pos;
    }
    AstProceduralTimingControlStatementHandle pProceduralTimingControlStatement0;
    if (getTokenChildSize() > pos && AstProceduralTimingControlStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pProceduralTimingControlStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pProceduralTimingControlStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConditionalStatementHandle pConditionalStatement0;
    if (getTokenChildSize() > pos && AstConditionalStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pConditionalStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pConditionalStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    AstCaseStatementHandle pCaseStatement0;
    if (getTokenChildSize() > pos && AstCaseStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pCaseStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pCaseStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    AstLoopStatementHandle pLoopStatement0;
    if (getTokenChildSize() > pos && AstLoopStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pLoopStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pLoopStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    AstSeqBlockHandle pSeqBlock0;
    if (getTokenChildSize() > pos && AstSeqBlockParser(getTokenStructure(), getTokenChild(pos)).parse(pSeqBlock0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatement = AstStatementHandle(AstStatement(pSeqBlock0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryConstantExpressionEqParser::parsePos(
    AstBinaryConstantExpressionEqHandle & pBinaryConstantExpressionEq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionEq = AstBinaryConstantExpressionEqHandle(AstBinaryConstantExpressionEq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionEq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstCaseStatementParser::parse(
    AstCaseStatementHandle & pCaseStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pCaseStatement = AstCaseStatementHandle(AstCaseStatement());

    AstKeywordCaseHandle pKeywordCase0;
    AstExpressionHandle pExpression1;
    AstOneOrMoreCaseItemHandle pOneOrMoreCaseItem2;
    AstKeywordEndCaseHandle pKeywordEndCase3;
    if (getTokenChildSize() > pos && AstKeywordCaseParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordCase0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
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

    if (getTokenChildSize() > pos && AstOneOrMoreCaseItemParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreCaseItem2, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstKeywordEndCaseParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordEndCase3)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pCaseStatement->push_back(pKeywordCase0, pExpression1, pOneOrMoreCaseItem2, pKeywordEndCase3);
    return true;
}
bool AstListOfRegisterIdentifiersParser::parse(
    AstListOfRegisterIdentifiersHandle & pListOfRegisterIdentifiers)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfRegisterIdentifiers = AstListOfRegisterIdentifiersHandle(AstListOfRegisterIdentifiers());

    AstRegisterNameHandle pRegisterName0;
    AstZeroOrMoreCommaRegisterNameHandle pZeroOrMoreCommaRegisterName1 = AstZeroOrMoreCommaRegisterNameHandle(AstZeroOrMoreCommaRegisterName())
;
    if (getTokenChildSize() > pos && AstRegisterNameParser(getTokenStructure(), getTokenChild(pos)).parse(pRegisterName0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaRegisterNameParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaRegisterName1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfRegisterIdentifiers->push_back(pRegisterName0, pZeroOrMoreCommaRegisterName1);
    return true;
}
bool AstRangeParser::parse(
    AstRangeHandle & pRange)
{
    unsigned int pos = 0, old_pos = 0;
    pRange = AstRangeHandle(AstRange());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pRange->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstBinaryOperatorSlashParser::parsePos(
    AstBinaryOperatorSlashHandle & pBinaryOperatorSlash
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorSlash = AstBinaryOperatorSlashHandle(AstBinaryOperatorSlash());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "/") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorSlash->push_back();
    return true;
}
bool AstProceduralContinuousAssignmentParser::parse(
    AstProceduralContinuousAssignmentHandle & pProceduralContinuousAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pProceduralContinuousAssignment = AstProceduralContinuousAssignmentHandle(AstProceduralContinuousAssignment());

    AstKeywordAssignHandle pKeywordAssign0;
    AstRegAssignmentHandle pRegAssignment1;
    if (getTokenChildSize() > pos && AstKeywordAssignParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordAssign0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstRegAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pRegAssignment1)) {
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

    pProceduralContinuousAssignment->push_back(pKeywordAssign0, pRegAssignment1);
    return true;
}
bool AstSelectParser::parsePos(
    AstSelectHandle & pSelect
  , unsigned int & pos)
 {

    unsigned int old_pos = pos;

    AstRangeSelectHandle pRangeSelect0;
    if (getTokenChildSize() > pos && AstRangeSelectParser(getTokenStructure(), getToken()).parsePos(pRangeSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pSelect = AstSelectHandle(AstSelect(pRangeSelect0));
        return true;
    }
    AstBitSelectHandle pBitSelect0;
    if (getTokenChildSize() > pos && AstBitSelectParser(getTokenStructure(), getToken()).parsePos(pBitSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pSelect = AstSelectHandle(AstSelect(pBitSelect0));
        return true;
    }
    reportChild();
    throw InvalidFormatException("Not valid option in composite rule without name");
}

bool AstBinaryOperatorNegXorParser::parsePos(
    AstBinaryOperatorNegXorHandle & pBinaryOperatorNegXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorNegXor = AstBinaryOperatorNegXorHandle(AstBinaryOperatorNegXor());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    pBinaryOperatorNegXor->push_back();
    return true;
}
bool AstBinaryOperatorOrOrParser::parsePos(
    AstBinaryOperatorOrOrHandle & pBinaryOperatorOrOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorOrOr = AstBinaryOperatorOrOrHandle(AstBinaryOperatorOrOr());

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

    pBinaryOperatorOrOr->push_back();
    return true;
}
bool AstSeqBlockParser::parse(
    AstSeqBlockHandle & pSeqBlock)
{
    unsigned int pos = 0, old_pos = 0;
    pSeqBlock = AstSeqBlockHandle(AstSeqBlock());

    AstKeywordBeginHandle pKeywordBegin0;
    AstZeroOrMoreStatementHandle pZeroOrMoreStatement1 = AstZeroOrMoreStatementHandle(AstZeroOrMoreStatement())
;
    AstKeywordEndHandle pKeywordEnd2;
    if (getTokenChildSize() > pos && AstKeywordBeginParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordBegin0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreStatementParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreStatement1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstKeywordEndParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordEnd2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pSeqBlock->push_back(pKeywordBegin0, pZeroOrMoreStatement1, pKeywordEnd2);
    return true;
}
bool AstBlockingAssignmentParser::parse(
    AstBlockingAssignmentHandle & pBlockingAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pBlockingAssignment = AstBlockingAssignmentHandle(AstBlockingAssignment());

    AstRegLvalueHandle pRegLvalue0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstRegLvalueParser(getTokenStructure(), getTokenChild(pos)).parse(pRegLvalue0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBlockingAssignment->push_back(pRegLvalue0, pExpression1);
    return true;
}
bool AstZeroOrMoreStatementParser::parsePos(
    AstZeroOrMoreStatementHandle & pZeroOrMoreStatement
  , unsigned int & pos) 
{
    pZeroOrMoreStatement = AstZeroOrMoreStatementHandle(AstZeroOrMoreStatement());

    AstStatementHandle pStatement0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreStatement->push_back(pStatement0);
    }

    return true;
}
bool AstBinaryConstantExpressionGeqParser::parsePos(
    AstBinaryConstantExpressionGeqHandle & pBinaryConstantExpressionGeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionGeq = AstBinaryConstantExpressionGeqHandle(AstBinaryConstantExpressionGeq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionGeq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstTernaryExpressionParser::parsePos(
    AstTernaryExpressionHandle & pTernaryExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pTernaryExpression = AstTernaryExpressionHandle(AstTernaryExpression());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    AstExpressionHandle pExpression2;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "?") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pTernaryExpression->push_back(pExpression0, pExpression1, pExpression2);
    return true;
}
bool AstZeroOrMoreCommaParamAssignmentParser::parsePos(
    AstZeroOrMoreCommaParamAssignmentHandle & pZeroOrMoreCommaParamAssignment
  , unsigned int & pos) 
{
    pZeroOrMoreCommaParamAssignment = AstZeroOrMoreCommaParamAssignmentHandle(AstZeroOrMoreCommaParamAssignment());

    AstParamAssignmentHandle pParamAssignment0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstParamAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pParamAssignment0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaParamAssignment->push_back(pParamAssignment0);
    }

    return true;
}
bool AstDescriptionParser::parse(AstDescriptionHandle & pDescription) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstModuleDeclarationHandle pModuleDeclaration0;
    if (getTokenChildSize() > pos && AstModuleDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pDescription = AstDescriptionHandle(AstDescription(pModuleDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstKeywordOutputParser::parse(AstKeywordOutputHandle & pKeywordOutput) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordOutput = AstKeywordOutputHandle(AstKeywordOutput(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryConstantExpressionShiftRightParser::parsePos(
    AstBinaryConstantExpressionShiftRightHandle & pBinaryConstantExpressionShiftRight
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionShiftRight = AstBinaryConstantExpressionShiftRightHandle(AstBinaryConstantExpressionShiftRight());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionShiftRight->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstProceduralTimingControlStatementParser::parse(
    AstProceduralTimingControlStatementHandle & pProceduralTimingControlStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pProceduralTimingControlStatement = AstProceduralTimingControlStatementHandle(AstProceduralTimingControlStatement());

    AstDelayOrEventControlHandle pDelayOrEventControl0;
    AstStatementOrNullHandle pStatementOrNull1;
    if (getTokenChildSize() > pos && AstDelayOrEventControlParser(getTokenStructure(), getTokenChild(pos)).parse(pDelayOrEventControl0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstStatementOrNullParser(getTokenStructure(), getTokenChild(pos)).parse(pStatementOrNull1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pProceduralTimingControlStatement->push_back(pDelayOrEventControl0, pStatementOrNull1);
    return true;
}
bool AstInoutDeclarationParser::parse(
    AstInoutDeclarationHandle & pInoutDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pInoutDeclaration = AstInoutDeclarationHandle(AstInoutDeclaration());

    AstKeywordInOutHandle pKeywordInOut0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    AstListOfPortIdentifiersHandle pListOfPortIdentifiers2;
    if (getTokenChildSize() > pos && AstKeywordInOutParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordInOut0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfPortIdentifiersParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfPortIdentifiers2)) {
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

    pInoutDeclaration->push_back(pKeywordInOut0, pZeroOrOneRange1, pListOfPortIdentifiers2);
    return true;
}
bool AstBinaryExpressionBwOrParser::parsePos(
    AstBinaryExpressionBwOrHandle & pBinaryExpressionBwOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionBwOr = AstBinaryExpressionBwOrHandle(AstBinaryExpressionBwOr());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionBwOr->push_back(pExpression0, pExpression1);
    return true;
}
bool AstListOfNetIdentifierParser::parse(
    AstListOfNetIdentifierHandle & pListOfNetIdentifier)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfNetIdentifier = AstListOfNetIdentifierHandle(AstListOfNetIdentifier());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1 = AstZeroOrMoreCommaIdentifierHandle(AstZeroOrMoreCommaIdentifier())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaIdentifierParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaIdentifier1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfNetIdentifier->push_back(pIdentifier0, pZeroOrMoreCommaIdentifier1);
    return true;
}
bool AstModuleItemParser::parse(AstModuleItemHandle & pModuleItem) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstAlwaysConstructHandle pAlwaysConstruct0;
    if (getTokenChildSize() > pos && AstAlwaysConstructParser(getTokenStructure(), getTokenChild(pos)).parse(pAlwaysConstruct0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pAlwaysConstruct0));
        return true;
    } else {
        pos = old_pos;
    }
    AstInitialConstructHandle pInitialConstruct0;
    if (getTokenChildSize() > pos && AstInitialConstructParser(getTokenStructure(), getTokenChild(pos)).parse(pInitialConstruct0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pInitialConstruct0));
        return true;
    } else {
        pos = old_pos;
    }
    AstModuleItemDeclarationHandle pModuleItemDeclaration0;
    if (getTokenChildSize() > pos && AstModuleItemDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleItemDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pModuleItemDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstContinuousAssignHandle pContinuousAssign0;
    if (getTokenChildSize() > pos && AstContinuousAssignParser(getTokenStructure(), getTokenChild(pos)).parse(pContinuousAssign0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pContinuousAssign0));
        return true;
    } else {
        pos = old_pos;
    }
    AstGateInstantiationHandle pGateInstantiation0;
    if (getTokenChildSize() > pos && AstGateInstantiationParser(getTokenStructure(), getTokenChild(pos)).parse(pGateInstantiation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pGateInstantiation0));
        return true;
    } else {
        pos = old_pos;
    }
    AstModuleInstantiationHandle pModuleInstantiation0;
    if (getTokenChildSize() > pos && AstModuleInstantiationParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleInstantiation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItem = AstModuleItemHandle(AstModuleItem(pModuleInstantiation0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstKeywordBeginParser::parse(AstKeywordBeginHandle & pKeywordBegin) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordBegin = AstKeywordBeginHandle(AstKeywordBegin(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordAlwaysParser::parse(AstKeywordAlwaysHandle & pKeywordAlways) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordAlways = AstKeywordAlwaysHandle(AstKeywordAlways(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstCaseItemDefaultParser::parsePos(
    AstCaseItemDefaultHandle & pCaseItemDefault
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pCaseItemDefault = AstCaseItemDefaultHandle(AstCaseItemDefault());

    AstKeywordDefaultHandle pKeywordDefault0;
    AstStatementOrNullHandle pStatementOrNull1;
    if (getTokenChildSize() > pos && AstKeywordDefaultParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordDefault0)) {
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

    if (getTokenChildSize() > pos && AstStatementOrNullParser(getTokenStructure(), getTokenChild(pos)).parse(pStatementOrNull1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pCaseItemDefault->push_back(pKeywordDefault0, pStatementOrNull1);
    return true;
}
bool AstBlockingAssingmentSemicolonParser::parsePos(
    AstBlockingAssingmentSemicolonHandle & pBlockingAssignmentSemicolon
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBlockingAssignmentSemicolon = AstBlockingAssingmentSemicolonHandle(AstBlockingAssingmentSemicolon());

    AstBlockingAssignmentHandle pBlockingAssignment0;
    if (getTokenChildSize() > pos && AstBlockingAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pBlockingAssignment0)) {
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

    pBlockingAssignmentSemicolon->push_back(pBlockingAssignment0);
    return true;
}
bool AstKeywordForParser::parse(AstKeywordForHandle & pKeywordFor) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordFor = AstKeywordForHandle(AstKeywordFor(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstZeroOrMoreCommaPortReferenceParser::parsePos(
    AstZeroOrMoreCommaPortReferenceHandle & pZeroOrMoreCommaPortReference
  , unsigned int & pos) 
{
    pZeroOrMoreCommaPortReference = AstZeroOrMoreCommaPortReferenceHandle(AstZeroOrMoreCommaPortReference());

    AstPortReferenceHandle pPortReference0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstPortReferenceParser(getTokenStructure(), getTokenChild(pos)).parse(pPortReference0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaPortReference->push_back(pPortReference0);
    }

    return true;
}
bool AstRangeSelectParser::parsePos(
    AstRangeSelectHandle & pRangeSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pRangeSelect = AstRangeSelectHandle(AstRangeSelect());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pRangeSelect->push_back(pExpression0, pExpression1);
    return true;
}
bool AstZeroOrMoreCommaIdentifierParser::parsePos(
    AstZeroOrMoreCommaIdentifierHandle & pZeroOrMoreCommaIdentifier
  , unsigned int & pos) 
{
    pZeroOrMoreCommaIdentifier = AstZeroOrMoreCommaIdentifierHandle(AstZeroOrMoreCommaIdentifier());

    AstIdentifierHandle pIdentifier0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaIdentifier->push_back(pIdentifier0);
    }

    return true;
}
bool AstBinaryConstantExpressionShiftLeftParser::parsePos(
    AstBinaryConstantExpressionShiftLeftHandle & pBinaryConstantExpressionShiftLeft
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionShiftLeft = AstBinaryConstantExpressionShiftLeftHandle(AstBinaryConstantExpressionShiftLeft());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionShiftLeft->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstTernaryConstantExpressionParser::parsePos(
    AstTernaryConstantExpressionHandle & pTernaryConstantExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pTernaryConstantExpression = AstTernaryConstantExpressionHandle(AstTernaryConstantExpression());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    AstConstantExpressionHandle pConstantExpression2;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "?") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pTernaryConstantExpression->push_back(pConstantExpression0, pConstantExpression1, pConstantExpression2);
    return true;
}
bool AstUnaryOperatorMinusParser::parsePos(
    AstUnaryOperatorMinusHandle & pUnaryOperatorMinus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorMinus = AstUnaryOperatorMinusHandle(AstUnaryOperatorMinus());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "-") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorMinus->push_back();
    return true;
}
bool AstInputDeclarationParser::parse(
    AstInputDeclarationHandle & pInputDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pInputDeclaration = AstInputDeclarationHandle(AstInputDeclaration());

    AstKeywordInputHandle pKeywordInput0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    AstListOfPortIdentifiersHandle pListOfPortIdentifiers2;
    if (getTokenChildSize() > pos && AstKeywordInputParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordInput0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfPortIdentifiersParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfPortIdentifiers2)) {
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

    pInputDeclaration->push_back(pKeywordInput0, pZeroOrOneRange1, pListOfPortIdentifiers2);
    return true;
}
bool AstZeroOrMoreCommaNInputGateInstanceParser::parsePos(
    AstZeroOrMoreCommaNInputGateInstanceHandle & pZeroOrMoreCommaNInputGateInstance
  , unsigned int & pos) 
{
    pZeroOrMoreCommaNInputGateInstance = AstZeroOrMoreCommaNInputGateInstanceHandle(AstZeroOrMoreCommaNInputGateInstance());

    AstNInputGateInstanceHandle pNInputGateInstance0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstNInputGateInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNInputGateInstance0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaNInputGateInstance->push_back(pNInputGateInstance0);
    }

    return true;
}
bool BracedConstantExpressionParser::parsePos(
    BracedConstantExpressionHandle & pBracedConstantExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBracedConstantExpression = BracedConstantExpressionHandle(BracedConstantExpression());

    AstConstantExpressionHandle pConstantExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    pBracedConstantExpression->push_back(pConstantExpression0);
    return true;
}
bool AstKeywordWireParser::parse(AstKeywordWireHandle & pKeywordWire) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordWire = AstKeywordWireHandle(AstKeywordWire(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstSimpleIdentifierParser::parse(AstSimpleIdentifierHandle & pSimpleIdentifier) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pSimpleIdentifier = AstSimpleIdentifierHandle(AstSimpleIdentifier(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstUnsignedNumberParser::parse(AstUnsignedNumberHandle & pUnsignedNumber) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pUnsignedNumber = AstUnsignedNumberHandle(AstUnsignedNumber(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordEndParser::parse(AstKeywordEndHandle & pKeywordEnd) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordEnd = AstKeywordEndHandle(AstKeywordEnd(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstSelectIdentifierParser::parsePos(
    AstSelectIdentifierHandle & pSelectIdentifier
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pSelectIdentifier = AstSelectIdentifierHandle(AstSelectIdentifier());

    AstIdentifierHandle pIdentifier0;
    AstOneOrMoreSelectHandle pOneOrMoreSelect1;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstOneOrMoreSelectParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreSelect1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pSelectIdentifier->push_back(pIdentifier0, pOneOrMoreSelect1);
    return true;
}
bool AstBinaryExpressionEqParser::parsePos(
    AstBinaryExpressionEqHandle & pBinaryExpressionEq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionEq = AstBinaryExpressionEqHandle(AstBinaryExpressionEq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionEq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryOperatorPlusParser::parsePos(
    AstUnaryOperatorPlusHandle & pUnaryOperatorPlus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorPlus = AstUnaryOperatorPlusHandle(AstUnaryOperatorPlus());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "+") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorPlus->push_back();
    return true;
}
bool AstConstantRangeSelectParser::parsePos(
    AstConstantRangeSelectHandle & pConstantRangeSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pConstantRangeSelect = AstConstantRangeSelectHandle(AstConstantRangeSelect());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pConstantRangeSelect->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstNetAssignmentParser::parse(
    AstNetAssignmentHandle & pNetAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pNetAssignment = AstNetAssignmentHandle(AstNetAssignment());

    AstNetLvalueHandle pNetLvalue0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstNetLvalueParser(getTokenStructure(), getTokenChild(pos)).parse(pNetLvalue0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pNetAssignment->push_back(pNetLvalue0, pExpression1);
    return true;
}
bool AstBinaryExpressionBwXorParser::parsePos(
    AstBinaryExpressionBwXorHandle & pBinaryExpressionBwXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionBwXor = AstBinaryExpressionBwXorHandle(AstBinaryExpressionBwXor());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionBwXor->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryOperatorXorNegParser::parsePos(
    AstUnaryOperatorXorNegHandle & pUnaryOperatorXorNeg
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorXorNeg = AstUnaryOperatorXorNegHandle(AstUnaryOperatorXorNeg());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "^") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorXorNeg->push_back();
    return true;
}
bool AstModuleInstanceParser::parse(
    AstModuleInstanceHandle & pModuleInstance)
{
    unsigned int pos = 0, old_pos = 0;
    pModuleInstance = AstModuleInstanceHandle(AstModuleInstance());

    AstNameOfInstanceHandle pNameOfInstance0;
    AstListOfModuleConnectionsHandle pListOfModuleConnections1;
    if (getTokenChildSize() > pos && AstNameOfInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNameOfInstance0)) {
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

    if (getTokenChildSize() > pos && AstListOfModuleConnectionsParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfModuleConnections1)) {
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

    pModuleInstance->push_back(pNameOfInstance0, pListOfModuleConnections1);
    return true;
}
bool AstBinaryOperatorNotEqualEqualParser::parsePos(
    AstBinaryOperatorNotEqualEqualHandle & pBinaryOperatorNotEqualEqual
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorNotEqualEqual = AstBinaryOperatorNotEqualEqualHandle(AstBinaryOperatorNotEqualEqual());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorNotEqualEqual->push_back();
    return true;
}
bool AstProceduralContinuousAssignmentSemicolonParser::parsePos(
    AstProceduralContinuousAssignmentSemicolonHandle & pProceduralContinuousAssignmentSemicoln
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pProceduralContinuousAssignmentSemicoln = AstProceduralContinuousAssignmentSemicolonHandle(AstProceduralContinuousAssignmentSemicolon());

    AstProceduralContinuousAssignmentHandle pProceduralContinuousAssignment0;
    if (getTokenChildSize() > pos && AstProceduralContinuousAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pProceduralContinuousAssignment0)) {
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

    pProceduralContinuousAssignmentSemicoln->push_back(pProceduralContinuousAssignment0);
    return true;
}
bool AstBinaryOperatorPlusParser::parsePos(
    AstBinaryOperatorPlusHandle & pBinaryOperatorPlus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorPlus = AstBinaryOperatorPlusHandle(AstBinaryOperatorPlus());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "+") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorPlus->push_back();
    return true;
}
bool AstEventControlParser::parse(AstEventControlHandle & pEventControl) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstAtIdentifierHandle pAtIdentifier0;
    if (getTokenChildSize() > pos && AstAtIdentifierParser(getTokenStructure(), getToken()).parsePos(pAtIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventControl = AstEventControlHandle(AstEventControl(pAtIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstAtEventExpressionHandle pAstEventExpression0;
    if (getTokenChildSize() > pos && AstAtEventExpressionParser(getTokenStructure(), getToken()).parsePos(pAstEventExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventControl = AstEventControlHandle(AstEventControl(pAstEventExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstAtAsteriskHandle pAtAsterisk0;
    if (getTokenChildSize() > pos && AstAtAsteriskParser(getTokenStructure(), getToken()).parsePos(pAtAsterisk0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pEventControl = AstEventControlHandle(AstEventControl(pAtAsterisk0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstZeroOrOneRangeParser::parsePos(
    AstZeroOrOneRangeHandle & pZeroOrOneRange
  , unsigned int & pos) 
{
    pZeroOrOneRange = AstZeroOrOneRangeHandle(AstZeroOrOneRange());

    AstRangeHandle pRange0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstRangeParser(getTokenStructure(), getTokenChild(pos)).parse(pRange0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneRange->push_back(pRange0);


return true;
}
bool AstBinaryExpressionNeqParser::parsePos(
    AstBinaryExpressionNeqHandle & pBinaryExpressionNeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionNeq = AstBinaryExpressionNeqHandle(AstBinaryExpressionNeq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionNeq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstStatementOrNullParser::parse(AstStatementOrNullHandle & pStatementOrNull) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstStatementHandle pStatement0;
    if (getTokenChildSize() > pos && AstStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStatement0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pStatementOrNull = AstStatementOrNullHandle(AstStatementOrNull(pStatement0));
        return true;
    } else {
        pos = old_pos;
    }
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ";") {
        ++pos;
    } else {
        pos = old_pos;
    }

    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstLoopStatementParser::parse(
    AstLoopStatementHandle & pLoopStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pLoopStatement = AstLoopStatementHandle(AstLoopStatement());

    AstKeywordForHandle pKeywordFor0;
    AstRegAssignmentHandle pRegAssignment1;
    AstExpressionHandle pExpression2;
    AstRegAssignmentHandle pRegAssignment3;
    AstStatementHandle pStatement4;
    if (getTokenChildSize() > pos && AstKeywordForParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordFor0)) {
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

    if (getTokenChildSize() > pos && AstRegAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pRegAssignment1)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression2)) {
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

    if (getTokenChildSize() > pos && AstRegAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pRegAssignment3)) {
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

    if (getTokenChildSize() > pos && AstStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStatement4)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pLoopStatement->push_back(pKeywordFor0, pRegAssignment1, pExpression2, pRegAssignment3, pStatement4);
    return true;
}
bool AstBinaryConstantExpressionBwAndParser::parsePos(
    AstBinaryConstantExpressionBwAndHandle & pBinaryConstantExpressionBwAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionBwAnd = AstBinaryConstantExpressionBwAndHandle(AstBinaryConstantExpressionBwAnd());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionBwAnd->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstNInputGateTypeParser::parse(AstNInputGateTypeHandle & pNInputGateType) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pNInputGateType = AstNInputGateTypeHandle(AstNInputGateType(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordModuleParser::parse(AstKeywordModuleHandle & pKeywordModule) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordModule = AstKeywordModuleHandle(AstKeywordModule(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordOrParser::parse(AstKeywordOrHandle & pKeywordOr) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordOr = AstKeywordOrHandle(AstKeywordOr(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstConstantBitSelectParser::parsePos(
    AstConstantBitSelectHandle & pConstantBitSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pConstantBitSelect = AstConstantBitSelectHandle(AstConstantBitSelect());

    AstConstantExpressionHandle pConstantExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pConstantBitSelect->push_back(pConstantExpression0);
    return true;
}
bool AstListOfParamAssignmentParser::parse(
    AstListOfParamAssignmentHandle & pListOfParamAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfParamAssignment = AstListOfParamAssignmentHandle(AstListOfParamAssignment());

    AstParamAssignmentHandle pParamAssignment0;
    AstZeroOrMoreCommaParamAssignmentHandle pZeroOrMoreCommaParamAssignment1 = AstZeroOrMoreCommaParamAssignmentHandle(AstZeroOrMoreCommaParamAssignment())
;
    if (getTokenChildSize() > pos && AstParamAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pParamAssignment0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaParamAssignmentParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaParamAssignment1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfParamAssignment->push_back(pParamAssignment0, pZeroOrMoreCommaParamAssignment1);
    return true;
}
bool AstGateInstantiationInputParser::parsePos(
    AstGateInstantiationInputHandle & pGateInstantiationInput
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pGateInstantiationInput = AstGateInstantiationInputHandle(AstGateInstantiationInput());

    AstNInputGateTypeHandle pNInputGateType0;
    AstNInputGateInstanceHandle pNInputGateInstance1;
    AstZeroOrMoreCommaNInputGateInstanceHandle pZeroOrMoreCommaNInputGateInstance2 = AstZeroOrMoreCommaNInputGateInstanceHandle(AstZeroOrMoreCommaNInputGateInstance())
;
    if (getTokenChildSize() > pos && AstNInputGateTypeParser(getTokenStructure(), getTokenChild(pos)).parse(pNInputGateType0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstNInputGateInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNInputGateInstance1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaNInputGateInstanceParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaNInputGateInstance2, pos)) {
        /* do nothing */
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

    pGateInstantiationInput->push_back(pNInputGateType0, pNInputGateInstance1, pZeroOrMoreCommaNInputGateInstance2);
    return true;
}
bool AstZeroOrMoreModuleItemParser::parsePos(
    AstZeroOrMoreModuleItemHandle & pZeroOrMoreModuleItem
  , unsigned int & pos) 
{
    pZeroOrMoreModuleItem = AstZeroOrMoreModuleItemHandle(AstZeroOrMoreModuleItem());

    AstModuleItemHandle pModuleItem0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstModuleItemParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleItem0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreModuleItem->push_back(pModuleItem0);
    }

    return true;
}
bool AstParameterDeclarationParser::parse(
    AstParameterDeclarationHandle & pParameterDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pParameterDeclaration = AstParameterDeclarationHandle(AstParameterDeclaration());

    AstKeywordParameterHandle pKeywordParameter0;
    AstListOfParamAssignmentHandle pListOfParamAssignment1;
    if (getTokenChildSize() > pos && AstKeywordParameterParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordParameter0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfParamAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfParamAssignment1)) {
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

    pParameterDeclaration->push_back(pKeywordParameter0, pListOfParamAssignment1);
    return true;
}
bool AstOneOrMoreSelectParser::parsePos(
    AstOneOrMoreSelectHandle & pOneOrMoreSelect
  , unsigned int & pos) {

    pOneOrMoreSelect = AstOneOrMoreSelectHandle(AstOneOrMoreSelect());

    AstSelectHandle pSelect0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstSelectParser(getTokenStructure(), getToken()).parsePos(pSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreSelect->push_back(pSelect0);
    }

    return pos != initial_pos;
}

bool AstBinaryConstantExpressionLtParser::parsePos(
    AstBinaryConstantExpressionLtHandle & pBinaryConstantExpressionLt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionLt = AstBinaryConstantExpressionLtHandle(AstBinaryConstantExpressionLt());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionLt->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstKeywordIntegerParser::parse(AstKeywordIntegerHandle & pKeywordInteger) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordInteger = AstKeywordIntegerHandle(AstKeywordInteger(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstKeywordEndCaseParser::parse(AstKeywordEndCaseHandle & pKeywordEndCase) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordEndCase = AstKeywordEndCaseHandle(AstKeywordEndCase(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstZeroOrMoreCommaOrderedPortConnectionParser::parsePos(
    AstZeroOrMoreCommaOrderedPortConnectionHandle & pZeroOrMoreCommaOrderedPortConnection
  , unsigned int & pos) 
{
    pZeroOrMoreCommaOrderedPortConnection = AstZeroOrMoreCommaOrderedPortConnectionHandle(AstZeroOrMoreCommaOrderedPortConnection());

    AstOrderedPortConnectionHandle pOrderedPortConnection0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstOrderedPortConnectionParser(getTokenStructure(), getTokenChild(pos)).parse(pOrderedPortConnection0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaOrderedPortConnection->push_back(pOrderedPortConnection0);
    }

    return true;
}
bool AstEventOrAsteriskParser::parsePos(
    AstEventOrAsteriskHandle & pEventOrAsterisk
  , unsigned int & pos)
 {

    unsigned int old_pos = pos;

    AstEventExpressionHandle pEventExpression0;
    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pEventOrAsterisk = AstEventOrAsteriskHandle(AstEventOrAsterisk(pEventExpression0));
        return true;
    }
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "*") {
        ++pos;
    } else {
        pos = old_pos;
    }

    reportChild();
    throw InvalidFormatException("Not valid option in composite rule without name");
}

bool AstBinaryOperatorShrParser::parsePos(
    AstBinaryOperatorShrHandle & pBinaryOperatorShr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorShr = AstBinaryOperatorShrHandle(AstBinaryOperatorShr());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorShr->push_back();
    return true;
}
bool AstUnaryOperatorNegParser::parsePos(
    AstUnaryOperatorNegHandle & pUnaryOperatorNeg
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorNeg = AstUnaryOperatorNegHandle(AstUnaryOperatorNeg());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorNeg->push_back();
    return true;
}
bool AstUnaryConstantExpressionParser::parsePos(
    AstUnaryConstantExpressionHandle & pUnaryConstantExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryConstantExpression = AstUnaryConstantExpressionHandle(AstUnaryConstantExpression());

    AstUnaryOperatorHandle pUnaryOperator0;
    AstConstantPrimaryHandle pConstantPrimary1;
    if (getTokenChildSize() > pos && AstUnaryOperatorParser(getTokenStructure(), getTokenChild(pos)).parse(pUnaryOperator0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantPrimaryParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantPrimary1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryConstantExpression->push_back(pUnaryOperator0, pConstantPrimary1);
    return true;
}
bool AstZeroOrMoreCommaInputTerminalParser::parsePos(
    AstZeroOrMoreCommaInputTerminalHandle & pZeroOrMoreCommaInputTerminal
  , unsigned int & pos) 
{
    pZeroOrMoreCommaInputTerminal = AstZeroOrMoreCommaInputTerminalHandle(AstZeroOrMoreCommaInputTerminal());

    AstInputTerminalHandle pInputTerminal0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstInputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pInputTerminal0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaInputTerminal->push_back(pInputTerminal0);
    }

    return true;
}
bool AstNegedgeExpressionParser::parsePos(
    AstNegedgeExpressionHandle & pNegedgeExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pNegedgeExpression = AstNegedgeExpressionHandle(AstNegedgeExpression());

    AstKetwordNegedgeHandle pKeywordNegedge0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstKetwordNegedgeParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordNegedge0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pNegedgeExpression->push_back(pKeywordNegedge0, pExpression1);
    return true;
}
bool AstRegDeclarationParser::parse(
    AstRegDeclarationHandle & pRegDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pRegDeclaration = AstRegDeclarationHandle(AstRegDeclaration());

    AstKeywordRegHandle pKeywordReg0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers2;
    if (getTokenChildSize() > pos && AstKeywordRegParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordReg0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfRegisterIdentifiersParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfRegisterIdentifiers2)) {
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

    pRegDeclaration->push_back(pKeywordReg0, pZeroOrOneRange1, pListOfRegisterIdentifiers2);
    return true;
}
bool AstBinaryConstantExpressionLgAndParser::parsePos(
    AstBinaryConstantExpressionLgAndHandle & pBinaryConstantExpressionLgAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionLgAnd = AstBinaryConstantExpressionLgAndHandle(AstBinaryConstantExpressionLgAnd());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionLgAnd->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstOneOrMoreCaseItemParser::parsePos(
    AstOneOrMoreCaseItemHandle & pOneOrMoreCaseItem
  , unsigned int & pos) {

    pOneOrMoreCaseItem = AstOneOrMoreCaseItemHandle(AstOneOrMoreCaseItem());

    AstCaseItemHandle pCaseItem0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstCaseItemParser(getTokenStructure(), getTokenChild(pos)).parse(pCaseItem0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreCaseItem->push_back(pCaseItem0);
    }

    return pos != initial_pos;
}

bool AstKeywordInitialParser::parse(AstKeywordInitialHandle & pKeywordInitial) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordInitial = AstKeywordInitialHandle(AstKeywordInitial(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionBwNxorParser::parsePos(
    AstBinaryExpressionBwNxorHandle & pBinaryExpressionBwNxor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionBwNxor = AstBinaryExpressionBwNxorHandle(AstBinaryExpressionBwNxor());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionBwNxor->push_back(pExpression0, pExpression1);
    return true;
}
bool AstListOfNetAssignmentsParser::parse(
    AstListOfNetAssignmentsHandle & pListOfNetAssignments)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfNetAssignments = AstListOfNetAssignmentsHandle(AstListOfNetAssignments());

    AstNetAssignmentHandle pNetAssignment0;
    AstZeroOrMoreCommaNetAssignmentHandle pZeroOrMoreCommaNetAssignment1 = AstZeroOrMoreCommaNetAssignmentHandle(AstZeroOrMoreCommaNetAssignment())
;
    if (getTokenChildSize() > pos && AstNetAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pNetAssignment0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaNetAssignmentParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaNetAssignment1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfNetAssignments->push_back(pNetAssignment0, pZeroOrMoreCommaNetAssignment1);
    return true;
}
bool AstSingleIdentifierParser::parse(AstSingleIdentifierHandle & pSingleIdentifier) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstSimpleIdentifierHandle pSimpleIdentifier0;
    if (getTokenChildSize() > pos && AstSimpleIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pSimpleIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pSingleIdentifier = AstSingleIdentifierHandle(AstSingleIdentifier(pSimpleIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstConstantExpressionParser::parse(AstConstantExpressionHandle & pConstantExpression) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    BracedConstantExpressionHandle pBracedConstantExpression0;
    if (getTokenChildSize() > pos && BracedConstantExpressionParser(getTokenStructure(), getToken()).parsePos(pBracedConstantExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantExpression = AstConstantExpressionHandle(AstConstantExpression(pBracedConstantExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConstantPrimaryHandle pConstantPrimary0;
    if (getTokenChildSize() > pos && AstConstantPrimaryParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantPrimary0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantExpression = AstConstantExpressionHandle(AstConstantExpression(pConstantPrimary0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryConstantExpressionHandle pUnaryConstantExpression0;
    if (getTokenChildSize() > pos && AstUnaryConstantExpressionParser(getTokenStructure(), getToken()).parsePos(pUnaryConstantExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantExpression = AstConstantExpressionHandle(AstConstantExpression(pUnaryConstantExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstTernaryConstantExpressionHandle pTernaryConstantExpression0;
    if (getTokenChildSize() > pos && AstTernaryConstantExpressionParser(getTokenStructure(), getToken()).parsePos(pTernaryConstantExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantExpression = AstConstantExpressionHandle(AstConstantExpression(pTernaryConstantExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryConstantExpressionHandle pBinaryConstantExpression0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantExpression = AstConstantExpressionHandle(AstConstantExpression(pBinaryConstantExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryConstantExpressionMultiplyParser::parsePos(
    AstBinaryConstantExpressionMultiplyHandle & pBinaryConstantExpressionMultiply
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionMultiply = AstBinaryConstantExpressionMultiplyHandle(AstBinaryConstantExpressionMultiply());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "*") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionMultiply->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstOutputDeclarationParser::parse(
    AstOutputDeclarationHandle & pOutputDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pOutputDeclaration = AstOutputDeclarationHandle(AstOutputDeclaration());

    AstKeywordOutputHandle pKeywordOutput0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    AstListOfPortIdentifiersHandle pListOfPortIdentifiers2;
    if (getTokenChildSize() > pos && AstKeywordOutputParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordOutput0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfPortIdentifiersParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfPortIdentifiers2)) {
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

    pOutputDeclaration->push_back(pKeywordOutput0, pZeroOrOneRange1, pListOfPortIdentifiers2);
    return true;
}
bool AstModuleKeywordParser::parse(AstModuleKeywordHandle & pModuleKeyword) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstKeywordModuleHandle pKeywordModule0;
    if (getTokenChildSize() > pos && AstKeywordModuleParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordModule0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleKeyword = AstModuleKeywordHandle(AstModuleKeyword(pKeywordModule0));
        return true;
    } else {
        pos = old_pos;
    }
    AstKeywordMacroModuleHandle pKeywordMacroModule0;
    if (getTokenChildSize() > pos && AstKeywordMacroModuleParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordMacroModule0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleKeyword = AstModuleKeywordHandle(AstModuleKeyword(pKeywordMacroModule0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryOperatorLtParser::parsePos(
    AstBinaryOperatorLtHandle & pBinaryOperatorLt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorLt = AstBinaryOperatorLtHandle(AstBinaryOperatorLt());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorLt->push_back();
    return true;
}
bool AstNOutputGateTypeParser::parse(AstNOutputGateTypeHandle & pNOutputGateType) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pNOutputGateType = AstNOutputGateTypeHandle(AstNOutputGateType(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstDecimalNumberParser::parse(AstDecimalNumberHandle & pDecimalNumber) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pDecimalNumber = AstDecimalNumberHandle(AstDecimalNumber(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryOperatorTripleEqualParser::parsePos(
    AstBinaryOperatorTripleEqualHandle & pBinaryOperatorTripleEqual
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorTripleEqual = AstBinaryOperatorTripleEqualHandle(AstBinaryOperatorTripleEqual());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorTripleEqual->push_back();
    return true;
}
bool AstKeywordElseParser::parse(AstKeywordElseHandle & pKeywordElse) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordElse = AstKeywordElseHandle(AstKeywordElse(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryConstantExpressionMinusParser::parsePos(
    AstBinaryConstantExpressionMinusHandle & pBinaryConstantExpressionMinus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionMinus = AstBinaryConstantExpressionMinusHandle(AstBinaryConstantExpressionMinus());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "-") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionMinus->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstNameOfGateInstanceParser::parse(
    AstNameOfGateInstanceHandle & pNameOfGateInstance)
{
    unsigned int pos = 0, old_pos = 0;
    pNameOfGateInstance = AstNameOfGateInstanceHandle(AstNameOfGateInstance());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pNameOfGateInstance->push_back(pIdentifier0, pZeroOrOneRange1);
    return true;
}
bool AstUnaryOperatorNegAndParser::parsePos(
    AstUnaryOperatorNegAndHandle & pUnaryOperatorNegAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorNegAnd = AstUnaryOperatorNegAndHandle(AstUnaryOperatorNegAnd());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    pUnaryOperatorNegAnd->push_back();
    return true;
}
bool AstAlwaysConstructParser::parse(
    AstAlwaysConstructHandle & pAlwaysConstruct)
{
    unsigned int pos = 0, old_pos = 0;
    pAlwaysConstruct = AstAlwaysConstructHandle(AstAlwaysConstruct());

    AstKeywordAlwaysHandle pKeywordAlways0;
    AstStatementHandle pStatement1;
    if (getTokenChildSize() > pos && AstKeywordAlwaysParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordAlways0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pAlwaysConstruct->push_back(pKeywordAlways0, pStatement1);
    return true;
}
bool AstOctalNumberParser::parse(AstOctalNumberHandle & pOctalNumber) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pOctalNumber = AstOctalNumberHandle(AstOctalNumber(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryConstantExpressionParser::parsePos(
    AstBinaryConstantExpressionHandle & pBinaryConstantExpression
  , unsigned int & pos)
 {

    unsigned int old_pos = pos;

    AstBinaryConstantExpressionMultiplyHandle pBinaryConstantExpressionMultiply0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionMultiplyParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionMultiply0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionMultiply0));
        return true;
    }
    AstBinaryConstantExpressionDivideHandle pBinaryConstantExpressionDivide0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionDivideParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionDivide0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionDivide0));
        return true;
    }
    AstBinaryConstantExpressionModulusHandle pBinaryConstantExpressionModulus0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionModulusParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionModulus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionModulus0));
        return true;
    }
    AstBinaryConstantExpressionPlusHandle pBinaryConstantExpressionPlus0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionPlusParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionPlus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionPlus0));
        return true;
    }
    AstBinaryConstantExpressionMinusHandle pBinaryConstantExpressionMinus0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionMinusParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionMinus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionMinus0));
        return true;
    }
    AstBinaryConstantExpressionShiftRightHandle pBinaryConstantExpressionShiftRight0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionShiftRightParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionShiftRight0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionShiftRight0));
        return true;
    }
    AstBinaryConstantExpressionShiftLeftHandle pBinaryConstantExpressionShiftLeft0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionShiftLeftParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionShiftLeft0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionShiftLeft0));
        return true;
    }
    AstBinaryConstantExpressionGtHandle pBinaryConstantExpressionGt0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionGtParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionGt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionGt0));
        return true;
    }
    AstBinaryConstantExpressionGeqHandle pBinaryConstantExpressionGeq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionGeqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionGeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionGeq0));
        return true;
    }
    AstBinaryConstantExpressionLtHandle pBinaryConstantExpressionLt0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionLtParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionLt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionLt0));
        return true;
    }
    AstBinaryConstantExpressionLeqHandle pBinaryConstantExpressionLeq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionLeqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionLeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionLeq0));
        return true;
    }
    AstBinaryConstantExpressionEqHandle pBinaryConstantExpressionEq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionEqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionEq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionEq0));
        return true;
    }
    AstBinaryConstantExpressionNeqHandle pBinaryConstantExpressionNeq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionNeqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionNeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionNeq0));
        return true;
    }
    AstBinaryConstantExpressionCaseEqHandle pBinaryConstantExpressionCaseEq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionCaseEqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionCaseEq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionCaseEq0));
        return true;
    }
    AstBinaryConstantExpressionCaseNeqHandle pBinaryConstantExpressionCaseNeq0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionCaseNeqParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionCaseNeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionCaseNeq0));
        return true;
    }
    AstBinaryConstantExpressionBwAndHandle pBinaryConstantExpressionBwAnd0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionBwAndParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionBwAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionBwAnd0));
        return true;
    }
    AstBinaryConstantExpressionBwXorHandle pBinaryConstantExpressionBwXor0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionBwXorParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionBwXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionBwXor0));
        return true;
    }
    AstBinaryConstantExpressionBwXnorHandle pBinaryConstantExpressionBwXnor0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionBwXnorParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionBwXnor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionBwXnor0));
        return true;
    }
    AstBinaryConstantExpressionBwNxorHandle pBinaryConstantExpressionBwNxor0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionBwNxorParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionBwNxor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionBwNxor0));
        return true;
    }
    AstBinaryConstantExpressionBwOrHandle pBinaryConstantExpressionBwOr0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionBwOrParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionBwOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionBwOr0));
        return true;
    }
    AstBinaryConstantExpressionLgAndHandle pBinaryConstantExpressionLgAnd0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionLgAndParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionLgAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionLgAnd0));
        return true;
    }
    AstBinaryConstantExpressionLgOrHandle pBinaryConstantExpressionLgOr0;
    if (getTokenChildSize() > pos && AstBinaryConstantExpressionLgOrParser(getTokenStructure(), getToken()).parsePos(pBinaryConstantExpressionLgOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryConstantExpression = AstBinaryConstantExpressionHandle(AstBinaryConstantExpression(pBinaryConstantExpressionLgOr0));
        return true;
    }
    reportChild();
    throw InvalidFormatException("Not valid option in composite rule without name");
}

bool AstBinaryExpressionLgOrParser::parsePos(
    AstBinaryExpressionLgOrHandle & pBinaryExpressionLgOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionLgOr = AstBinaryExpressionLgOrHandle(AstBinaryExpressionLgOr());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionLgOr->push_back(pExpression0, pExpression1);
    return true;
}
bool AstBinaryOperatorEqualEqualParser::parsePos(
    AstBinaryOperatorEqualEqualHandle & pBinaryOperatorEqualEqual
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorEqualEqual = AstBinaryOperatorEqualEqualHandle(AstBinaryOperatorEqualEqual());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
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

    pBinaryOperatorEqualEqual->push_back();
    return true;
}
bool AstHeximalNumberParser::parse(AstHeximalNumberHandle & pHeximalNumber) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pHeximalNumber = AstHeximalNumberHandle(AstHeximalNumber(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstListOfPortReferencesParser::parsePos(
    AstListOfPortReferencesHandle & pListOfPortReferences
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pListOfPortReferences = AstListOfPortReferencesHandle(AstListOfPortReferences());

    AstPortReferenceHandle pPortReference0;
    AstZeroOrMoreCommaPortReferenceHandle pZeroOrMoreCommaPortReference1 = AstZeroOrMoreCommaPortReferenceHandle(AstZeroOrMoreCommaPortReference())
;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstPortReferenceParser(getTokenStructure(), getTokenChild(pos)).parse(pPortReference0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaPortReferenceParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaPortReference1, pos)) {
        /* do nothing */
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

    pListOfPortReferences->push_back(pPortReference0, pZeroOrMoreCommaPortReference1);
    return true;
}
bool AstNetLvalueParser::parse(AstNetLvalueHandle & pNetLvalue) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNetLvalue = AstNetLvalueHandle(AstNetLvalue(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNetLvalueBitSelectHandle pNetLvalueBitSelect0;
    if (getTokenChildSize() > pos && AstNetLvalueBitSelectParser(getTokenStructure(), getToken()).parsePos(pNetLvalueBitSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNetLvalue = AstNetLvalueHandle(AstNetLvalue(pNetLvalueBitSelect0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNetLvalueRangeSelectHandle pNetLvalueRangeSelect0;
    if (getTokenChildSize() > pos && AstNetLvalueRangeSelectParser(getTokenStructure(), getToken()).parsePos(pNetLvalueRangeSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNetLvalue = AstNetLvalueHandle(AstNetLvalue(pNetLvalueRangeSelect0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConcatenationHandle pAstConcatenation0;
    if (getTokenChildSize() > pos && AstConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pAstConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNetLvalue = AstNetLvalueHandle(AstNetLvalue(pAstConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryOperatorAndAndParser::parsePos(
    AstBinaryOperatorAndAndHandle & pBinaryOperatorAndAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorAndAnd = AstBinaryOperatorAndAndHandle(AstBinaryOperatorAndAnd());

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

    pBinaryOperatorAndAnd->push_back();
    return true;
}
bool AstNInputGateInstanceParser::parse(
    AstNInputGateInstanceHandle & pNInputGateInstance)
{
    unsigned int pos = 0, old_pos = 0;
    pNInputGateInstance = AstNInputGateInstanceHandle(AstNInputGateInstance());

    AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0 = AstZeroOrOneNameOfGateInstanceHandle(AstZeroOrOneNameOfGateInstance())
;
    AstOutputTerminalHandle pOutputTerminal1;
    AstInputTerminalHandle pInputTerminal2;
    AstZeroOrMoreCommaInputTerminalHandle pZeroOrMoreCommaInputTerminal3 = AstZeroOrMoreCommaInputTerminalHandle(AstZeroOrMoreCommaInputTerminal())
;
    if (AstZeroOrOneNameOfGateInstanceParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneNameOfGateInstance0, pos)) {
        /* do nothing */
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

    if (getTokenChildSize() > pos && AstOutputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pOutputTerminal1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstInputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pInputTerminal2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaInputTerminalParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaInputTerminal3, pos)) {
        /* do nothing */
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

    pNInputGateInstance->push_back(pZeroOrOneNameOfGateInstance0, pOutputTerminal1, pInputTerminal2, pZeroOrMoreCommaInputTerminal3);
    return true;
}
bool AstListOfPortsParser::parse(
    AstListOfPortsHandle & pListOfPorts)
{
    unsigned int pos = 0, old_pos = 0;
    pListOfPorts = AstListOfPortsHandle(AstListOfPorts());

    AstPortHandle pPort0;
    AstZeroOrMoreCommaPortHandle pZeroOrMoreCommaPort1 = AstZeroOrMoreCommaPortHandle(AstZeroOrMoreCommaPort())
;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstPortParser(getTokenStructure(), getTokenChild(pos)).parse(pPort0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaPortParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaPort1, pos)) {
        /* do nothing */
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

    pListOfPorts->push_back(pPort0, pZeroOrMoreCommaPort1);
    return true;
}
bool AstOneOrMoreCommaExpressionParser::parsePos(
    AstOneOrMoreCommaExpressionHandle & pOneOrMoreCommaExpression
  , unsigned int & pos) {

    pOneOrMoreCommaExpression = AstOneOrMoreCommaExpressionHandle(AstOneOrMoreCommaExpression());

    AstExpressionHandle pExpression0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreCommaExpression->push_back(pExpression0);
    }

    return pos != initial_pos;
}

bool AstNamedPortConnectionParser::parse(
    AstNamedPortConnectionHandle & pNamedPortConnection)
{
    unsigned int pos = 0, old_pos = 0;
    pNamedPortConnection = AstNamedPortConnectionHandle(AstNamedPortConnection());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrOneExpressionHandle pZeroOrOneExpression1 = AstZeroOrOneExpressionHandle(AstZeroOrOneExpression())
;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ".") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
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

    if (AstZeroOrOneExpressionParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneExpression1, pos)) {
        /* do nothing */
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

    pNamedPortConnection->push_back(pIdentifier0, pZeroOrOneExpression1);
    return true;
}
bool AstModuleItemDeclarationParser::parse(AstModuleItemDeclarationHandle & pModuleItemDeclaration) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstParameterDeclarationHandle pParameterDeclaration0;
    if (getTokenChildSize() > pos && AstParameterDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pParameterDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pParameterDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstInputDeclarationHandle pInputDeclaration0;
    if (getTokenChildSize() > pos && AstInputDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pInputDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pInputDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstOutputDeclarationHandle pOutputDeclaration0;
    if (getTokenChildSize() > pos && AstOutputDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pOutputDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pOutputDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstInoutDeclarationHandle pInoutDeclaration0;
    if (getTokenChildSize() > pos && AstInoutDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pInoutDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pInoutDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNetDeclarationHandle pNetDeclaration0;
    if (getTokenChildSize() > pos && AstNetDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pNetDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pNetDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstRegDeclarationHandle pRegDeclaration0;
    if (getTokenChildSize() > pos && AstRegDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pRegDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pRegDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    AstIntegerDeclarationHandle pIntegerDeclaration0;
    if (getTokenChildSize() > pos && AstIntegerDeclarationParser(getTokenStructure(), getTokenChild(pos)).parse(pIntegerDeclaration0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pModuleItemDeclaration = AstModuleItemDeclarationHandle(AstModuleItemDeclaration(pIntegerDeclaration0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryConstantExpressionLeqParser::parsePos(
    AstBinaryConstantExpressionLeqHandle & pBinaryConstantExpressionLeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionLeq = AstBinaryConstantExpressionLeqHandle(AstBinaryConstantExpressionLeq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionLeq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstBinaryExpressionDivideParser::parsePos(
    AstBinaryExpressionDivideHandle & pBinaryExpressionDivide
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionDivide = AstBinaryExpressionDivideHandle(AstBinaryExpressionDivide());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "/") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionDivide->push_back(pExpression0, pExpression1);
    return true;
}
bool AstBinaryExpressionLtParser::parsePos(
    AstBinaryExpressionLtHandle & pBinaryExpressionLt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionLt = AstBinaryExpressionLtHandle(AstBinaryExpressionLt());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionLt->push_back(pExpression0, pExpression1);
    return true;
}
bool AstRegisterNameParser::parse(
    AstRegisterNameHandle & pRegisterName)
{
    unsigned int pos = 0, old_pos = 0;
    pRegisterName = AstRegisterNameHandle(AstRegisterName());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrMoreRegisterNameRangeHandle pZeroOrMoreRegisterNameRange1 = AstZeroOrMoreRegisterNameRangeHandle(AstZeroOrMoreRegisterNameRange())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreRegisterNameRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreRegisterNameRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pRegisterName->push_back(pIdentifier0, pZeroOrMoreRegisterNameRange1);
    return true;
}
bool AstModuleInstantiationParser::parse(
    AstModuleInstantiationHandle & pModuleInstantiation)
{
    unsigned int pos = 0, old_pos = 0;
    pModuleInstantiation = AstModuleInstantiationHandle(AstModuleInstantiation());

    AstIdentifierHandle pIdentifier0;
    AstModuleInstanceHandle pModuleInstance1;
    AstZeroOrMoreCommaModuleInstanceHandle pZeroOrMoreCommaModuleInstance2 = AstZeroOrMoreCommaModuleInstanceHandle(AstZeroOrMoreCommaModuleInstance())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstModuleInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleInstance1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaModuleInstanceParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaModuleInstance2, pos)) {
        /* do nothing */
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

    pModuleInstantiation->push_back(pIdentifier0, pModuleInstance1, pZeroOrMoreCommaModuleInstance2);
    return true;
}
bool AstBinaryConstantExpressionBwNxorParser::parsePos(
    AstBinaryConstantExpressionBwNxorHandle & pBinaryConstantExpressionBwNxor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionBwNxor = AstBinaryConstantExpressionBwNxorHandle(AstBinaryConstantExpressionBwNxor());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionBwNxor->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstZeroOrMoreCommaPortParser::parsePos(
    AstZeroOrMoreCommaPortHandle & pZeroOrMoreCommaPort
  , unsigned int & pos) 
{
    pZeroOrMoreCommaPort = AstZeroOrMoreCommaPortHandle(AstZeroOrMoreCommaPort());

    AstPortHandle pPort0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstPortParser(getTokenStructure(), getTokenChild(pos)).parse(pPort0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaPort->push_back(pPort0);
    }

    return true;
}
bool AstUnaryOperatorParser::parse(AstUnaryOperatorHandle & pUnaryOperator) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstUnaryOperatorPlusHandle pUnaryOperatorPlus0;
    if (getTokenChildSize() > pos && AstUnaryOperatorPlusParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorPlus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorPlus0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorMinusHandle pUnaryOperatorMinus0;
    if (getTokenChildSize() > pos && AstUnaryOperatorMinusParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorMinus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorMinus0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorNotHandle pUnaryOperatorNot0;
    if (getTokenChildSize() > pos && AstUnaryOperatorNotParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorNot0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorNot0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorNegHandle pUnaryOperatorNeg0;
    if (getTokenChildSize() > pos && AstUnaryOperatorNegParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorNeg0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorNeg0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorAndHandle pUnaryOperatorAnd0;
    if (getTokenChildSize() > pos && AstUnaryOperatorAndParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorAnd0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorNegAndHandle pUnaryOperatorNegAnd0;
    if (getTokenChildSize() > pos && AstUnaryOperatorNegAndParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorNegAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorNegAnd0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorOrHandle pUnaryOperatorOr0;
    if (getTokenChildSize() > pos && AstUnaryOperatorOrParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorOr0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorNegOrHandle pUnaryOperatorNegOr0;
    if (getTokenChildSize() > pos && AstUnaryOperatorNegOrParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorNegOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorNegOr0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorXorHandle pUnaryOperatorXor0;
    if (getTokenChildSize() > pos && AstUnaryOperatorXorParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorXor0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorNegXorHandle pUnaryOperatorNegXor0;
    if (getTokenChildSize() > pos && AstUnaryOperatorNegXorParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorNegXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorNegXor0));
        return true;
    } else {
        pos = old_pos;
    }
    AstUnaryOperatorXorNegHandle pUnaryOperatorXorNeg0;
    if (getTokenChildSize() > pos && AstUnaryOperatorXorNegParser(getTokenStructure(), getToken()).parsePos(pUnaryOperatorXorNeg0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pUnaryOperator = AstUnaryOperatorHandle(AstUnaryOperator(pUnaryOperatorXorNeg0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstNonBlockingAssignmentSemicolonParser::parsePos(
    AstNonBlockingAssignmentSemicolonHandle & pNonBlockingAssignmentSemicolon
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pNonBlockingAssignmentSemicolon = AstNonBlockingAssignmentSemicolonHandle(AstNonBlockingAssignmentSemicolon());

    AstNonBlockingAssignmentHandle pNonBlockingAssignment0;
    if (getTokenChildSize() > pos && AstNonBlockingAssignmentParser(getTokenStructure(), getTokenChild(pos)).parse(pNonBlockingAssignment0)) {
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

    pNonBlockingAssignmentSemicolon->push_back(pNonBlockingAssignment0);
    return true;
}
bool AstKeywordIfParser::parse(AstKeywordIfHandle & pKeywordIf) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordIf = AstKeywordIfHandle(AstKeywordIf(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionMultiplyParser::parsePos(
    AstBinaryExpressionMultiplyHandle & pBinaryExpressionMultiply
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionMultiply = AstBinaryExpressionMultiplyHandle(AstBinaryExpressionMultiply());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "*") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionMultiply->push_back(pExpression0, pExpression1);
    return true;
}
bool AstNonBlockingAssignmentParser::parse(
    AstNonBlockingAssignmentHandle & pNonBlockingAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pNonBlockingAssignment = AstNonBlockingAssignmentHandle(AstNonBlockingAssignment());

    AstRegLvalueHandle pRegLvalue0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstRegLvalueParser(getTokenStructure(), getTokenChild(pos)).parse(pRegLvalue0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pNonBlockingAssignment->push_back(pRegLvalue0, pExpression1);
    return true;
}
bool AstZeroOrMoreCommaOutputTerminalParser::parsePos(
    AstZeroOrMoreCommaOutputTerminalHandle & pZeroOrMoreCommaOutputTerminal
  , unsigned int & pos) 
{
    pZeroOrMoreCommaOutputTerminal = AstZeroOrMoreCommaOutputTerminalHandle(AstZeroOrMoreCommaOutputTerminal());

    AstOutputTerminalHandle pOutputTerminal0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstOutputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pOutputTerminal0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaOutputTerminal->push_back(pOutputTerminal0);
    }

    return true;
}
bool AstGateInstantiationParser::parse(AstGateInstantiationHandle & pGateInstantiation) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstGateInstantiationInputHandle pGateInstantiationInput0;
    if (getTokenChildSize() > pos && AstGateInstantiationInputParser(getTokenStructure(), getToken()).parsePos(pGateInstantiationInput0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pGateInstantiation = AstGateInstantiationHandle(AstGateInstantiation(pGateInstantiationInput0));
        return true;
    } else {
        pos = old_pos;
    }
    AstGateInstantiationOutputHandle pGateInstantiationOutput0;
    if (getTokenChildSize() > pos && AstGateInstantiationOutputParser(getTokenStructure(), getToken()).parsePos(pGateInstantiationOutput0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pGateInstantiation = AstGateInstantiationHandle(AstGateInstantiation(pGateInstantiationOutput0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryConstantExpressionModulusParser::parsePos(
    AstBinaryConstantExpressionModulusHandle & pBinaryConstantExpressionModulus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionModulus = AstBinaryConstantExpressionModulusHandle(AstBinaryConstantExpressionModulus());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "%") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionModulus->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstBinaryConstantExpressionBwXnorParser::parsePos(
    AstBinaryConstantExpressionBwXnorHandle & pBinaryConstantExpressionBwXnor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionBwXnor = AstBinaryConstantExpressionBwXnorHandle(AstBinaryConstantExpressionBwXnor());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionBwXnor->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstBinaryExpressionBwXnorParser::parsePos(
    AstBinaryExpressionBwXnorHandle & pBinaryExpressionBwXnor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionBwXnor = AstBinaryExpressionBwXnorHandle(AstBinaryExpressionBwXnor());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionBwXnor->push_back(pExpression0, pExpression1);
    return true;
}
bool AstNetLvalueRangeSelectParser::parsePos(
    AstNetLvalueRangeSelectHandle & pNetLvalueRangeSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pNetLvalueRangeSelect = AstNetLvalueRangeSelectHandle(AstNetLvalueRangeSelect());

    AstIdentifierHandle pIdentifier0;
    AstConstantExpressionHandle pConstantExpression1;
    AstConstantExpressionHandle pConstantExpression2;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pNetLvalueRangeSelect->push_back(pIdentifier0, pConstantExpression1, pConstantExpression2);
    return true;
}
bool AstBracedExpressionParser::parsePos(
    AstBracedExpressionHandle & pBracedExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBracedExpression = AstBracedExpressionHandle(AstBracedExpression());

    AstExpressionHandle pExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "(") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    pBracedExpression->push_back(pExpression0);
    return true;
}
bool AstBinaryOperatorParser::parse(AstBinaryOperatorHandle & pBinaryOperator) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstBinaryOperatorPlusHandle pBinaryOperatorPlus0;
    if (getTokenChildSize() > pos && AstBinaryOperatorPlusParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorPlus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorPlus0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorMinusHandle pBinaryOperatorMinus0;
    if (getTokenChildSize() > pos && AstBinaryOperatorMinusParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorMinus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorMinus0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorAsteriskHandle pBinaryOperatorAsterisk0;
    if (getTokenChildSize() > pos && AstBinaryOperatorAsteriskParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorAsterisk0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorAsterisk0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorSlashHandle pBinaryOperatorSlash0;
    if (getTokenChildSize() > pos && AstBinaryOperatorSlashParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorSlash0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorSlash0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorPercentHandle pBinaryOperatorPercent0;
    if (getTokenChildSize() > pos && AstBinaryOperatorPercentParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorPercent0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorPercent0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorEqualEqualHandle pBinaryOperatorEqualEqual0;
    if (getTokenChildSize() > pos && AstBinaryOperatorEqualEqualParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorEqualEqual0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorEqualEqual0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorNotEqualHandle pBinaryOperatorNotEqual0;
    if (getTokenChildSize() > pos && AstBinaryOperatorNotEqualParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorNotEqual0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorNotEqual0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorTripleEqualHandle pBinaryOperatorTripleEqual0;
    if (getTokenChildSize() > pos && AstBinaryOperatorTripleEqualParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorTripleEqual0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorTripleEqual0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorNotEqualEqualHandle pBinaryOperatorNotEqualEqual0;
    if (getTokenChildSize() > pos && AstBinaryOperatorNotEqualEqualParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorNotEqualEqual0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorNotEqualEqual0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorAndAndHandle pBinaryOperatorAndAnd0;
    if (getTokenChildSize() > pos && AstBinaryOperatorAndAndParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorAndAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorAndAnd0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorOrOrHandle pBinaryOperatorOrOr0;
    if (getTokenChildSize() > pos && AstBinaryOperatorOrOrParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorOrOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorOrOr0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorLtHandle pBinaryOperatorLt0;
    if (getTokenChildSize() > pos && AstBinaryOperatorLtParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorLt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorLt0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorLeqHandle pBinaryOperatorLeq0;
    if (getTokenChildSize() > pos && AstBinaryOperatorLeqParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorLeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorLeq0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorGtHandle pBinaryOperatorGt0;
    if (getTokenChildSize() > pos && AstBinaryOperatorGtParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorGt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorGt0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorGeqHandle pBinaryOperatorGeq0;
    if (getTokenChildSize() > pos && AstBinaryOperatorGeqParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorGeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorGeq0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorAndHandle pBinaryOperatorAnd0;
    if (getTokenChildSize() > pos && AstBinaryOperatorAndParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorAnd0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorOrHandle pBinaryOperatorOr0;
    if (getTokenChildSize() > pos && AstBinaryOperatorOrParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorOr0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorXorHandle pBinaryOperatorXor0;
    if (getTokenChildSize() > pos && AstBinaryOperatorXorParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorXor0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorXorNegHandle pBinaryOperatorXorNeg0;
    if (getTokenChildSize() > pos && AstBinaryOperatorXorNegParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorXorNeg0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorXorNeg0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorNegXorHandle pBinaryOperatorNegXor0;
    if (getTokenChildSize() > pos && AstBinaryOperatorNegXorParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorNegXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorNegXor0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorShrHandle pBinaryOperatorShr0;
    if (getTokenChildSize() > pos && AstBinaryOperatorShrParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorShr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorShr0));
        return true;
    } else {
        pos = old_pos;
    }
    AstBinaryOperatorShlHandle pBinaryOperatorShl0;
    if (getTokenChildSize() > pos && AstBinaryOperatorShlParser(getTokenStructure(), getToken()).parsePos(pBinaryOperatorShl0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pBinaryOperator = AstBinaryOperatorHandle(AstBinaryOperator(pBinaryOperatorShl0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstZeroOrMoreCommaRegisterNameParser::parsePos(
    AstZeroOrMoreCommaRegisterNameHandle & pZeroOrMoreCommaRegisterName
  , unsigned int & pos) 
{
    pZeroOrMoreCommaRegisterName = AstZeroOrMoreCommaRegisterNameHandle(AstZeroOrMoreCommaRegisterName());

    AstRegisterNameHandle pRegisterName0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstRegisterNameParser(getTokenStructure(), getTokenChild(pos)).parse(pRegisterName0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaRegisterName->push_back(pRegisterName0);
    }

    return true;
}
bool AstBinaryExpressionModulusParser::parsePos(
    AstBinaryExpressionModulusHandle & pBinaryExpressionModulus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionModulus = AstBinaryExpressionModulusHandle(AstBinaryExpressionModulus());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "%") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionModulus->push_back(pExpression0, pExpression1);
    return true;
}
bool AstBinaryExpressionGtParser::parsePos(
    AstBinaryExpressionGtHandle & pBinaryExpressionGt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionGt = AstBinaryExpressionGtHandle(AstBinaryExpressionGt());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionGt->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryOperatorAndParser::parsePos(
    AstUnaryOperatorAndHandle & pUnaryOperatorAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorAnd = AstUnaryOperatorAndHandle(AstUnaryOperatorAnd());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "&") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorAnd->push_back();
    return true;
}
bool AstZeroOrOneElseStatementOrNullParser::parsePos(
    AstZeroOrOneElseStatementOrNullHandle & pZeroOrOneElseStatementOrNull
  , unsigned int & pos) 
{
    pZeroOrOneElseStatementOrNull = AstZeroOrOneElseStatementOrNullHandle(AstZeroOrOneElseStatementOrNull());

    AstElseStatementOrNullHandle pElseStatementOrNull0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstElseStatementOrNullParser(getTokenStructure(), getToken()).parsePos(pElseStatementOrNull0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneElseStatementOrNull->push_back(pElseStatementOrNull0);


return true;
}
bool AstBinaryConstantExpressionCaseNeqParser::parsePos(
    AstBinaryConstantExpressionCaseNeqHandle & pBinaryConstantExpressionCaseNeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionCaseNeq = AstBinaryConstantExpressionCaseNeqHandle(AstBinaryConstantExpressionCaseNeq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionCaseNeq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstSourceTextParser::parse(AstSourceTextHandle & pSourceText) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstOneOrMoreDescriptionHandle pOneOrMoreDescription0;
    if (getTokenChildSize() > pos && AstOneOrMoreDescriptionParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreDescription0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pSourceText = AstSourceTextHandle(AstSourceText(pOneOrMoreDescription0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstEventOrEventParser::parsePos(
    AstEventOrEventHandle & pEventOrEvent
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pEventOrEvent = AstEventOrEventHandle(AstEventOrEvent());

    AstEventExpressionHandle pEventExpression0;
    AstKeywordOrHandle pKeywordOr1;
    AstEventExpressionHandle pEventExpression2;
    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstKeywordOrParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordOr1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pEventOrEvent->push_back(pEventExpression0, pKeywordOr1, pEventExpression2);
    return true;
}
bool AstBinaryExpressionCaseEqParser::parsePos(
    AstBinaryExpressionCaseEqHandle & pBinaryExpressionCaseEq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionCaseEq = AstBinaryExpressionCaseEqHandle(AstBinaryExpressionCaseEq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionCaseEq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstBinaryExpressionLgAndParser::parsePos(
    AstBinaryExpressionLgAndHandle & pBinaryExpressionLgAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionLgAnd = AstBinaryExpressionLgAndHandle(AstBinaryExpressionLgAnd());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionLgAnd->push_back(pExpression0, pExpression1);
    return true;
}
bool AstZeroOrOneExpressionParser::parsePos(
    AstZeroOrOneExpressionHandle & pZeroOrOneExpression
  , unsigned int & pos) 
{
    pZeroOrOneExpression = AstZeroOrOneExpressionHandle(AstZeroOrOneExpression());

    AstExpressionHandle pExpression0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneExpression->push_back(pExpression0);


return true;
}
bool AstBinaryNumberParser::parse(AstBinaryNumberHandle & pBinaryNumber) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pBinaryNumber = AstBinaryNumberHandle(AstBinaryNumber(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstMultipleConcatenationParser::parse(
    AstMultipleConcatenationHandle & pMulitpleConcatenation)
{
    unsigned int pos = 0, old_pos = 0;
    pMulitpleConcatenation = AstMultipleConcatenationHandle(AstMultipleConcatenation());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression2 = AstZeroOrMoreCommaExpressionHandle(AstZeroOrMoreCommaExpression())
;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "{") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaExpressionParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaExpression2, pos)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "}") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pMulitpleConcatenation->push_back(pExpression0, pExpression1, pZeroOrMoreCommaExpression2);
    return true;
}
bool AstBinaryConstantExpressionPlusParser::parsePos(
    AstBinaryConstantExpressionPlusHandle & pBinaryConstantExpressionPlus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionPlus = AstBinaryConstantExpressionPlusHandle(AstBinaryConstantExpressionPlus());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "+") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionPlus->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstListOfOrderedPortConnectionParser::parsePos(
    AstListOfOrderedPortConnectionHandle & pListOfOrderedPortConnection
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pListOfOrderedPortConnection = AstListOfOrderedPortConnectionHandle(AstListOfOrderedPortConnection());

    AstOrderedPortConnectionHandle pOrderedPortConnection0;
    AstZeroOrMoreCommaOrderedPortConnectionHandle pZeroOrMoreCommaOrderedPortConnection1 = AstZeroOrMoreCommaOrderedPortConnectionHandle(AstZeroOrMoreCommaOrderedPortConnection())
;
    if (getTokenChildSize() > pos && AstOrderedPortConnectionParser(getTokenStructure(), getTokenChild(pos)).parse(pOrderedPortConnection0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaOrderedPortConnectionParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaOrderedPortConnection1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfOrderedPortConnection->push_back(pOrderedPortConnection0, pZeroOrMoreCommaOrderedPortConnection1);
    return true;
}
bool AstMultiIdentifierParser::parsePos(
    AstMultiIdentifierHandle & pMultiIdentifier
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pMultiIdentifier = AstMultiIdentifierHandle(AstMultiIdentifier());

    AstSingleIdentifierHandle pSingleIdentifier0;
    AstZeroOrMoreDotSingleIdentifierHandle pZeroOrMoreDotSingleIdentifier1 = AstZeroOrMoreDotSingleIdentifierHandle(AstZeroOrMoreDotSingleIdentifier())
;
    if (getTokenChildSize() > pos && AstSingleIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pSingleIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreDotSingleIdentifierParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreDotSingleIdentifier1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pMultiIdentifier->push_back(pSingleIdentifier0, pZeroOrMoreDotSingleIdentifier1);
    return true;
}
bool AstKeywordPosedgeParser::parse(AstKeywordPosedgeHandle & pKeywordPosedge) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordPosedge = AstKeywordPosedgeHandle(AstKeywordPosedge(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionPlusParser::parsePos(
    AstBinaryExpressionPlusHandle & pBinaryExpressionPlus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionPlus = AstBinaryExpressionPlusHandle(AstBinaryExpressionPlus());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "+") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionPlus->push_back(pExpression0, pExpression1);
    return true;
}
bool AstUnaryOperatorNegXorParser::parsePos(
    AstUnaryOperatorNegXorHandle & pUnaryOperatorNegXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorNegXor = AstUnaryOperatorNegXorHandle(AstUnaryOperatorNegXor());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    pUnaryOperatorNegXor->push_back();
    return true;
}
bool AstOutputTerminalParser::parse(
    AstOutputTerminalHandle & pOutputTerminal)
{
    unsigned int pos = 0, old_pos = 0;
    pOutputTerminal = AstOutputTerminalHandle(AstOutputTerminal());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrOneConstantBitSelectHandle pAstZeroOrOneConstantBitSelect1 = AstZeroOrOneConstantBitSelectHandle(AstZeroOrOneConstantBitSelect())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneConstantBitSelectParser(getTokenStructure(), getToken()).parsePos(pAstZeroOrOneConstantBitSelect1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pOutputTerminal->push_back(pIdentifier0, pAstZeroOrOneConstantBitSelect1);
    return true;
}
bool AstUnaryOperatorXorParser::parsePos(
    AstUnaryOperatorXorHandle & pUnaryOperatorXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorXor = AstUnaryOperatorXorHandle(AstUnaryOperatorXor());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "^") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorXor->push_back();
    return true;
}
bool AstKeywordRegParser::parse(AstKeywordRegHandle & pKeywordReg) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordReg = AstKeywordRegHandle(AstKeywordReg(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstZeroOrMoreCommaNOutputGateInstanceParser::parsePos(
    AstZeroOrMoreCommaNOutputGateInstanceHandle & pZeroOrMoreCommaNOutputGateInstance
  , unsigned int & pos) 
{
    pZeroOrMoreCommaNOutputGateInstance = AstZeroOrMoreCommaNOutputGateInstanceHandle(AstZeroOrMoreCommaNOutputGateInstance());

    AstNOutputGateInstanceHandle pNOutputGateInstance0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstNOutputGateInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNOutputGateInstance0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaNOutputGateInstance->push_back(pNOutputGateInstance0);
    }

    return true;
}
bool AstAtEventExpressionParser::parsePos(
    AstAtEventExpressionHandle & pAstEventExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pAstEventExpression = AstAtEventExpressionHandle(AstAtEventExpression());

    AstEventExpressionHandle pEventExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "@") {
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

    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression0)) {
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

    pAstEventExpression->push_back(pEventExpression0);
    return true;
}
bool AstInitialConstructParser::parse(
    AstInitialConstructHandle & pInitialConstruct)
{
    unsigned int pos = 0, old_pos = 0;
    pInitialConstruct = AstInitialConstructHandle(AstInitialConstruct());

    AstKeywordInitialHandle pKeywordInitial0;
    AstStatementHandle pStatement1;
    if (getTokenChildSize() > pos && AstKeywordInitialParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordInitial0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstStatementParser(getTokenStructure(), getTokenChild(pos)).parse(pStatement1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pInitialConstruct->push_back(pKeywordInitial0, pStatement1);
    return true;
}
bool AstBinaryOperatorMinusParser::parsePos(
    AstBinaryOperatorMinusHandle & pBinaryOperatorMinus
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorMinus = AstBinaryOperatorMinusHandle(AstBinaryOperatorMinus());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "-") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorMinus->push_back();
    return true;
}
bool AstBinaryConstantExpressionDivideParser::parsePos(
    AstBinaryConstantExpressionDivideHandle & pBinaryConstantExpressionDivide
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionDivide = AstBinaryConstantExpressionDivideHandle(AstBinaryConstantExpressionDivide());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "/") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionDivide->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstKeywordAssignParser::parse(AstKeywordAssignHandle & pKeywordAssign) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordAssign = AstKeywordAssignHandle(AstKeywordAssign(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstIntegerDeclarationParser::parse(
    AstIntegerDeclarationHandle & pIntegerDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pIntegerDeclaration = AstIntegerDeclarationHandle(AstIntegerDeclaration());

    AstKeywordIntegerHandle pKeywordInteger0;
    AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers1;
    if (getTokenChildSize() > pos && AstKeywordIntegerParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordInteger0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfRegisterIdentifiersParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfRegisterIdentifiers1)) {
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

    pIntegerDeclaration->push_back(pKeywordInteger0, pListOfRegisterIdentifiers1);
    return true;
}
bool AstBinaryConstantExpressionLgOrParser::parsePos(
    AstBinaryConstantExpressionLgOrHandle & pBinaryConstantExpressionLgOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionLgOr = AstBinaryConstantExpressionLgOrHandle(AstBinaryConstantExpressionLgOr());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionLgOr->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstBinaryConstantExpressionBwOrParser::parsePos(
    AstBinaryConstantExpressionBwOrHandle & pBinaryConstantExpressionBwOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionBwOr = AstBinaryConstantExpressionBwOrHandle(AstBinaryConstantExpressionBwOr());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionBwOr->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstNetTypeParser::parse(AstNetTypeHandle & pNetType) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstKeywordWireHandle pKeywordWire0;
    if (getTokenChildSize() > pos && AstKeywordWireParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordWire0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pNetType = AstNetTypeHandle(AstNetType(pKeywordWire0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstDelayOrEventControlParser::parse(
    AstDelayOrEventControlHandle & pDelayOrEventControl)
{
    unsigned int pos = 0, old_pos = 0;
    pDelayOrEventControl = AstDelayOrEventControlHandle(AstDelayOrEventControl());

    AstEventControlHandle pEventControl0;
    if (getTokenChildSize() > pos && AstEventControlParser(getTokenStructure(), getTokenChild(pos)).parse(pEventControl0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pDelayOrEventControl->push_back(pEventControl0);
    return true;
}
bool AstNOutputGateInstanceParser::parse(
    AstNOutputGateInstanceHandle & pNOutputGateInstance)
{
    unsigned int pos = 0, old_pos = 0;
    pNOutputGateInstance = AstNOutputGateInstanceHandle(AstNOutputGateInstance());

    AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0 = AstZeroOrOneNameOfGateInstanceHandle(AstZeroOrOneNameOfGateInstance())
;
    AstOutputTerminalHandle pOutputTerminal1;
    AstZeroOrMoreCommaOutputTerminalHandle pZeroOrMoreCommaOutputTerminal2 = AstZeroOrMoreCommaOutputTerminalHandle(AstZeroOrMoreCommaOutputTerminal())
;
    AstInputTerminalHandle pInputTerminal3;
    if (AstZeroOrOneNameOfGateInstanceParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneNameOfGateInstance0, pos)) {
        /* do nothing */
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

    if (getTokenChildSize() > pos && AstOutputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pOutputTerminal1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaOutputTerminalParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaOutputTerminal2, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstInputTerminalParser(getTokenStructure(), getTokenChild(pos)).parse(pInputTerminal3)) {
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

    pNOutputGateInstance->push_back(pZeroOrOneNameOfGateInstance0, pOutputTerminal1, pZeroOrMoreCommaOutputTerminal2, pInputTerminal3);
    return true;
}
bool AstConditionalStatementParser::parse(
    AstConditionalStatementHandle & pConditionalStatement)
{
    unsigned int pos = 0, old_pos = 0;
    pConditionalStatement = AstConditionalStatementHandle(AstConditionalStatement());

    AstKeywordIfHandle pKeywordIf0;
    AstExpressionHandle pExpression1;
    AstStatementOrNullHandle pStatementOrNull2;
    AstZeroOrOneElseStatementOrNullHandle pZeroOrOneElseStatementOrNull3 = AstZeroOrOneElseStatementOrNullHandle(AstZeroOrOneElseStatementOrNull())
;
    if (getTokenChildSize() > pos && AstKeywordIfParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordIf0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
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

    if (getTokenChildSize() > pos && AstStatementOrNullParser(getTokenStructure(), getTokenChild(pos)).parse(pStatementOrNull2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneElseStatementOrNullParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneElseStatementOrNull3, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pConditionalStatement->push_back(pKeywordIf0, pExpression1, pStatementOrNull2, pZeroOrOneElseStatementOrNull3);
    return true;
}
bool AstBinaryConstantExpressionGtParser::parsePos(
    AstBinaryConstantExpressionGtHandle & pBinaryConstantExpressionGt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionGt = AstBinaryConstantExpressionGtHandle(AstBinaryConstantExpressionGt());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionGt->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstZeroOrOnePortExpressionParser::parsePos(
    AstZeroOrOnePortExpressionHandle & pZeroOrOnePortExpression
  , unsigned int & pos) 
{
    pZeroOrOnePortExpression = AstZeroOrOnePortExpressionHandle(AstZeroOrOnePortExpression());

    AstPortExpressionHandle pPortExpression0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstPortExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pPortExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOnePortExpression->push_back(pPortExpression0);


return true;
}
bool AstZeroOrOneConstantBitSelectParser::parsePos(
    AstZeroOrOneConstantBitSelectHandle & pAstZeroOrOneConstantBitSelect
  , unsigned int & pos) 
{
    pAstZeroOrOneConstantBitSelect = AstZeroOrOneConstantBitSelectHandle(AstZeroOrOneConstantBitSelect());

    AstConstantBitSelectHandle pConstantBitSelect0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstConstantBitSelectParser(getTokenStructure(), getToken()).parsePos(pConstantBitSelect0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return true;
    }
    pAstZeroOrOneConstantBitSelect->push_back(pConstantBitSelect0);


return true;
}
bool AstKeywordCaseParser::parse(AstKeywordCaseHandle & pKeywordCase) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordCase = AstKeywordCaseHandle(AstKeywordCase(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstZeroOrMoreRegisterNameRangeParser::parsePos(
    AstZeroOrMoreRegisterNameRangeHandle & pZeroOrMoreRegisterNameRange
  , unsigned int & pos) 
{
    pZeroOrMoreRegisterNameRange = AstZeroOrMoreRegisterNameRangeHandle(AstZeroOrMoreRegisterNameRange());

    AstRangeHandle pRange0;

    while(true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstRangeParser(getTokenStructure(), getTokenChild(pos)).parse(pRange0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreRegisterNameRange->push_back(pRange0);
    }

    return true;
}
bool AstBinaryOperatorOrParser::parsePos(
    AstBinaryOperatorOrHandle & pBinaryOperatorOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorOr = AstBinaryOperatorOrHandle(AstBinaryOperatorOr());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "|") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorOr->push_back();
    return true;
}
bool AstCaseItemItemParser::parsePos(
    AstCaseItemItemHandle & pCaseItemItem
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pCaseItemItem = AstCaseItemItemHandle(AstCaseItemItem());

    AstExpressionHandle pExpression0;
    AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression1 = AstZeroOrMoreCommaExpressionHandle(AstZeroOrMoreCommaExpression())
;
    AstStatementOrNullHandle pStatementOrNull2;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaExpressionParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaExpression1, pos)) {
        /* do nothing */
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

    if (getTokenChildSize() > pos && AstStatementOrNullParser(getTokenStructure(), getTokenChild(pos)).parse(pStatementOrNull2)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pCaseItemItem->push_back(pExpression0, pZeroOrMoreCommaExpression1, pStatementOrNull2);
    return true;
}
bool AstUnaryOperatorNegOrParser::parsePos(
    AstUnaryOperatorNegOrHandle & pUnaryOperatorNegOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorNegOr = AstUnaryOperatorNegOrHandle(AstUnaryOperatorNegOr());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
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

    pUnaryOperatorNegOr->push_back();
    return true;
}
bool AstModuleDeclarationParser::parse(
    AstModuleDeclarationHandle & pModuleDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pModuleDeclaration = AstModuleDeclarationHandle(AstModuleDeclaration());

    AstModuleKeywordHandle pModuleKeyword0;
    AstIdentifierHandle pIdentifier1;
    AstZeroOrOneListOfPortsHandle pZeroOrOneListOfPorts2 = AstZeroOrOneListOfPortsHandle(AstZeroOrOneListOfPorts())
;
    AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem3 = AstZeroOrMoreModuleItemHandle(AstZeroOrMoreModuleItem())
;
    AstKeywordEndmoduleHandle pKeywordEndmodule4;
    if (getTokenChildSize() > pos && AstModuleKeywordParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleKeyword0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneListOfPortsParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneListOfPorts2, pos)) {
        /* do nothing */
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

    if (AstZeroOrMoreModuleItemParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreModuleItem3, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstKeywordEndmoduleParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordEndmodule4)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pModuleDeclaration->push_back(pModuleKeyword0, pIdentifier1, pZeroOrOneListOfPorts2, pZeroOrMoreModuleItem3, pKeywordEndmodule4);
    return true;
}
bool AstBinaryConstantExpressionBwXorParser::parsePos(
    AstBinaryConstantExpressionBwXorHandle & pBinaryConstantExpressionBwXor
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionBwXor = AstBinaryConstantExpressionBwXorHandle(AstBinaryConstantExpressionBwXor());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionBwXor->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstConstantPrimaryParser::parse(AstConstantPrimaryHandle & pConstantPrimary) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstNumberHandle pNumber0;
    if (getTokenChildSize() > pos && AstNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantPrimary = AstConstantPrimaryHandle(AstConstantPrimary(pNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantPrimary = AstConstantPrimaryHandle(AstConstantPrimary(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConcatenationHandle pAstConcatenation0;
    if (getTokenChildSize() > pos && AstConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pAstConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantPrimary = AstConstantPrimaryHandle(AstConstantPrimary(pAstConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    AstMultipleConcatenationHandle pMulitpleConcatenation0;
    if (getTokenChildSize() > pos && AstMultipleConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pMulitpleConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pConstantPrimary = AstConstantPrimaryHandle(AstConstantPrimary(pMulitpleConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstPosedgeExpressionParser::parsePos(
    AstPosedgeExpressionHandle & pPosedgeExpression
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pPosedgeExpression = AstPosedgeExpressionHandle(AstPosedgeExpression());

    AstKeywordPosedgeHandle pKeywordPosedge0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstKeywordPosedgeParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordPosedge0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pPosedgeExpression->push_back(pKeywordPosedge0, pExpression1);
    return true;
}
bool AstListOfModuleConnectionsParser::parse(AstListOfModuleConnectionsHandle & pListOfModuleConnections) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstListOfOrderedPortConnectionHandle pListOfOrderedPortConnection0;
    if (getTokenChildSize() > pos && AstListOfOrderedPortConnectionParser(getTokenStructure(), getToken()).parsePos(pListOfOrderedPortConnection0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pListOfModuleConnections = AstListOfModuleConnectionsHandle(AstListOfModuleConnections(pListOfOrderedPortConnection0));
        return true;
    } else {
        pos = old_pos;
    }
    AstListOfNamedPortConnectionHandle pListOfNamedPortConnection0;
    if (getTokenChildSize() > pos && AstListOfNamedPortConnectionParser(getTokenStructure(), getToken()).parsePos(pListOfNamedPortConnection0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pListOfModuleConnections = AstListOfModuleConnectionsHandle(AstListOfModuleConnections(pListOfNamedPortConnection0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstRegAssignmentParser::parse(
    AstRegAssignmentHandle & pRegAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pRegAssignment = AstRegAssignmentHandle(AstRegAssignment());

    AstRegLvalueHandle pRegLvalue0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstRegLvalueParser(getTokenStructure(), getTokenChild(pos)).parse(pRegLvalue0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pRegAssignment->push_back(pRegLvalue0, pExpression1);
    return true;
}
bool AstBinaryOperatorGeqParser::parsePos(
    AstBinaryOperatorGeqHandle & pBinaryOperatorGeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorGeq = AstBinaryOperatorGeqHandle(AstBinaryOperatorGeq());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
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

    pBinaryOperatorGeq->push_back();
    return true;
}
bool AstBinaryExpressionLeqParser::parsePos(
    AstBinaryExpressionLeqHandle & pBinaryExpressionLeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionLeq = AstBinaryExpressionLeqHandle(AstBinaryExpressionLeq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionLeq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstAtAsteriskParser::parsePos(
    AstAtAsteriskHandle & pAtAsterisk
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pAtAsterisk = AstAtAsteriskHandle(AstAtAsterisk());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "@") {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "*") {
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

    pAtAsterisk->push_back();
    return true;
}
bool AstRegLvalueParser::parse(AstRegLvalueHandle & pRegLvalue) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pRegLvalue = AstRegLvalueHandle(AstRegLvalue(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstSelectIdentifierHandle pSelectIdentifier0;
    if (getTokenChildSize() > pos && AstSelectIdentifierParser(getTokenStructure(), getToken()).parsePos(pSelectIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pRegLvalue = AstRegLvalueHandle(AstRegLvalue(pSelectIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConcatenationHandle pAstConcatenation0;
    if (getTokenChildSize() > pos && AstConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pAstConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pRegLvalue = AstRegLvalueHandle(AstRegLvalue(pAstConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryOperatorAndParser::parsePos(
    AstBinaryOperatorAndHandle & pBinaryOperatorAnd
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorAnd = AstBinaryOperatorAndHandle(AstBinaryOperatorAnd());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "&") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorAnd->push_back();
    return true;
}
bool AstAtEventOrAsteriskParser::parsePos(
    AstAtEventOrAsteriskHandle & pAstEventOrAsterisk
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pAstEventOrAsterisk = AstAtEventOrAsteriskHandle(AstAtEventOrAsterisk());

    AstEventOrAsteriskHandle pEventOrAsterisk0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "@") {
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

    if (getTokenChildSize() > pos && AstEventOrAsteriskParser(getTokenStructure(), getToken()).parsePos(pEventOrAsterisk0, pos)) {
        /* do nothing */
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

    pAstEventOrAsterisk->push_back(pEventOrAsterisk0);
    return true;
}
bool AstKeywordDefaultParser::parse(AstKeywordDefaultHandle & pKeywordDefault) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordDefault = AstKeywordDefaultHandle(AstKeywordDefault(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionShiftRightParser::parsePos(
    AstBinaryExpressionShiftRightHandle & pBinaryExpressionShiftRight
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionShiftRight = AstBinaryExpressionShiftRightHandle(AstBinaryExpressionShiftRight());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionShiftRight->push_back(pExpression0, pExpression1);
    return true;
}
bool AstListOfNamedPortConnectionParser::parsePos(
    AstListOfNamedPortConnectionHandle & pListOfNamedPortConnection
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pListOfNamedPortConnection = AstListOfNamedPortConnectionHandle(AstListOfNamedPortConnection());

    AstNamedPortConnectionHandle pNamedPortConnection0;
    AstZeroOrMoreCommaNamedPortConnectionHandle pZeroOrMoreCommaNamedPortConnection1 = AstZeroOrMoreCommaNamedPortConnectionHandle(AstZeroOrMoreCommaNamedPortConnection())
;
    if (getTokenChildSize() > pos && AstNamedPortConnectionParser(getTokenStructure(), getTokenChild(pos)).parse(pNamedPortConnection0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaNamedPortConnectionParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaNamedPortConnection1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pListOfNamedPortConnection->push_back(pNamedPortConnection0, pZeroOrMoreCommaNamedPortConnection1);
    return true;
}
bool AstBinaryOperatorShlParser::parsePos(
    AstBinaryOperatorShlHandle & pBinaryOperatorShl
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorShl = AstBinaryOperatorShlHandle(AstBinaryOperatorShl());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorShl->push_back();
    return true;
}
bool AstKeywordEndmoduleParser::parse(AstKeywordEndmoduleHandle & pKeywordEndmodule) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordEndmodule = AstKeywordEndmoduleHandle(AstKeywordEndmodule(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryExpressionParser::parsePos(
    AstBinaryExpressionHandle & pBinaryExpression
  , unsigned int & pos)
 {

    unsigned int old_pos = pos;

    AstBinaryExpressionMultiplyHandle pBinaryExpressionMultiply0;
    if (getTokenChildSize() > pos && AstBinaryExpressionMultiplyParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionMultiply0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionMultiply0));
        return true;
    }
    AstBinaryExpressionDivideHandle pBinaryExpressionDivide0;
    if (getTokenChildSize() > pos && AstBinaryExpressionDivideParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionDivide0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionDivide0));
        return true;
    }
    AstBinaryExpressionModulusHandle pBinaryExpressionModulus0;
    if (getTokenChildSize() > pos && AstBinaryExpressionModulusParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionModulus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionModulus0));
        return true;
    }
    AstBinaryExpressionPlusHandle pBinaryExpressionPlus0;
    if (getTokenChildSize() > pos && AstBinaryExpressionPlusParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionPlus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionPlus0));
        return true;
    }
    AstBinaryExpressionMinusHandle pBinaryExpressionMinus0;
    if (getTokenChildSize() > pos && AstBinaryExpressionMinusParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionMinus0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionMinus0));
        return true;
    }
    AstBinaryExpressionShiftRightHandle pBinaryExpressionShiftRight0;
    if (getTokenChildSize() > pos && AstBinaryExpressionShiftRightParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionShiftRight0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionShiftRight0));
        return true;
    }
    AstBinaryExpressionShiftLeftHandle pBinaryExpressionShiftLeft0;
    if (getTokenChildSize() > pos && AstBinaryExpressionShiftLeftParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionShiftLeft0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionShiftLeft0));
        return true;
    }
    AstBinaryExpressionGtHandle pBinaryExpressionGt0;
    if (getTokenChildSize() > pos && AstBinaryExpressionGtParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionGt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionGt0));
        return true;
    }
    AstBinaryExpressionGeqHandle pBinaryExpressionGeq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionGeqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionGeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionGeq0));
        return true;
    }
    AstBinaryExpressionLtHandle pBinaryExpressionLt0;
    if (getTokenChildSize() > pos && AstBinaryExpressionLtParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionLt0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionLt0));
        return true;
    }
    AstBinaryExpressionLeqHandle pBinaryExpressionLeq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionLeqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionLeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionLeq0));
        return true;
    }
    AstBinaryExpressionEqHandle pBinaryExpressionEq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionEqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionEq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionEq0));
        return true;
    }
    AstBinaryExpressionNeqHandle pBinaryExpressionNeq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionNeqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionNeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionNeq0));
        return true;
    }
    AstBinaryExpressionCaseEqHandle pBinaryExpressionCaseEq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionCaseEqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionCaseEq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionCaseEq0));
        return true;
    }
    AstBinaryExpressionCaseNeqHandle pBinaryExpressionCaseNeq0;
    if (getTokenChildSize() > pos && AstBinaryExpressionCaseNeqParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionCaseNeq0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionCaseNeq0));
        return true;
    }
    AstBinaryExpressionBwAndHandle pBinaryExpressionBwAnd0;
    if (getTokenChildSize() > pos && AstBinaryExpressionBwAndParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionBwAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionBwAnd0));
        return true;
    }
    AstBinaryExpressionBwXorHandle pBinaryExpressionBwXor0;
    if (getTokenChildSize() > pos && AstBinaryExpressionBwXorParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionBwXor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionBwXor0));
        return true;
    }
    AstBinaryExpressionBwXnorHandle pBinaryExpressionBwXnor0;
    if (getTokenChildSize() > pos && AstBinaryExpressionBwXnorParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionBwXnor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionBwXnor0));
        return true;
    }
    AstBinaryExpressionBwNxorHandle pBinaryExpressionBwNxor0;
    if (getTokenChildSize() > pos && AstBinaryExpressionBwNxorParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionBwNxor0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionBwNxor0));
        return true;
    }
    AstBinaryExpressionBwOrHandle pBinaryExpressionBwOr0;
    if (getTokenChildSize() > pos && AstBinaryExpressionBwOrParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionBwOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionBwOr0));
        return true;
    }
    AstBinaryExpressionLgAndHandle pBinaryExpressionLgAnd0;
    if (getTokenChildSize() > pos && AstBinaryExpressionLgAndParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionLgAnd0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionLgAnd0));
        return true;
    }
    AstBinaryExpressionLgOrHandle pBinaryExpressionLgOr0;
    if (getTokenChildSize() > pos && AstBinaryExpressionLgOrParser(getTokenStructure(), getToken()).parsePos(pBinaryExpressionLgOr0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos != old_pos) {
        pBinaryExpression = AstBinaryExpressionHandle(AstBinaryExpression(pBinaryExpressionLgOr0));
        return true;
    }
    reportChild();
    throw InvalidFormatException("Not valid option in composite rule without name");
}

bool AstBinaryConstantExpressionNeqParser::parsePos(
    AstBinaryConstantExpressionNeqHandle & pBinaryConstantExpressionNeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionNeq = AstBinaryConstantExpressionNeqHandle(AstBinaryConstantExpressionNeq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionNeq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstNameOfInstanceParser::parse(
    AstNameOfInstanceHandle & pNameOfInstance)
{
    unsigned int pos = 0, old_pos = 0;
    pNameOfInstance = AstNameOfInstanceHandle(AstNameOfInstance());

    AstIdentifierHandle pIdentifier0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pNameOfInstance->push_back(pIdentifier0, pZeroOrOneRange1);
    return true;
}
bool AstConcatenationParser::parse(
    AstConcatenationHandle & pAstConcatenation)
{
    unsigned int pos = 0, old_pos = 0;
    pAstConcatenation = AstConcatenationHandle(AstConcatenation());

    AstExpressionHandle pExpression0;
    AstOneOrMoreCommaExpressionHandle pOneOrMoreCommaExpression1;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "{") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstOneOrMoreCommaExpressionParser(getTokenStructure(), getToken()).parsePos(pOneOrMoreCommaExpression1, pos)) {
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

    pAstConcatenation->push_back(pExpression0, pOneOrMoreCommaExpression1);
    return true;
}
bool AstConstantBitSelectIdentifierParser::parsePos(
    AstConstantBitSelectIdentifierHandle & pConstantBitSelectIdentifier
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pConstantBitSelectIdentifier = AstConstantBitSelectIdentifierHandle(AstConstantBitSelectIdentifier());

    AstIdentifierHandle pIdentifier0;
    AstConstantBitSelectHandle pConstantBitSelect1;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantBitSelectParser(getTokenStructure(), getToken()).parsePos(pConstantBitSelect1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pConstantBitSelectIdentifier->push_back(pIdentifier0, pConstantBitSelect1);
    return true;
}
bool AstBinaryOperatorPercentParser::parsePos(
    AstBinaryOperatorPercentHandle & pBinaryOperatorPercent
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorPercent = AstBinaryOperatorPercentHandle(AstBinaryOperatorPercent());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "%") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorPercent->push_back();
    return true;
}
bool AstZeroOrMoreCommaModuleInstanceParser::parsePos(
    AstZeroOrMoreCommaModuleInstanceHandle & pZeroOrMoreCommaModuleInstance
  , unsigned int & pos) 
{
    pZeroOrMoreCommaModuleInstance = AstZeroOrMoreCommaModuleInstanceHandle(AstZeroOrMoreCommaModuleInstance());

    AstModuleInstanceHandle pModuleInstance0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstModuleInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pModuleInstance0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaModuleInstance->push_back(pModuleInstance0);
    }

    return true;
}
bool AstPortExpressionParser::parse(AstPortExpressionHandle & pPortExpression) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstPortReferenceHandle pPortReference0;
    if (getTokenChildSize() > pos && AstPortReferenceParser(getTokenStructure(), getTokenChild(pos)).parse(pPortReference0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPortExpression = AstPortExpressionHandle(AstPortExpression(pPortReference0));
        return true;
    } else {
        pos = old_pos;
    }
    AstListOfPortReferencesHandle pListOfPortReferences0;
    if (getTokenChildSize() > pos && AstListOfPortReferencesParser(getTokenStructure(), getToken()).parsePos(pListOfPortReferences0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPortExpression = AstPortExpressionHandle(AstPortExpression(pListOfPortReferences0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstGateInstantiationOutputParser::parsePos(
    AstGateInstantiationOutputHandle & pGateInstantiationOutput
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pGateInstantiationOutput = AstGateInstantiationOutputHandle(AstGateInstantiationOutput());

    AstNOutputGateTypeHandle pNOutputGateType0;
    AstNOutputGateInstanceHandle pNOutputGateInstance1;
    AstZeroOrMoreCommaNOutputGateInstanceHandle pZeroOrMoreCommaNOutputGateInstance2 = AstZeroOrMoreCommaNOutputGateInstanceHandle(AstZeroOrMoreCommaNOutputGateInstance())
;
    if (getTokenChildSize() > pos && AstNOutputGateTypeParser(getTokenStructure(), getTokenChild(pos)).parse(pNOutputGateType0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstNOutputGateInstanceParser(getTokenStructure(), getTokenChild(pos)).parse(pNOutputGateInstance1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrMoreCommaNOutputGateInstanceParser(getTokenStructure(), getToken()).parsePos(pZeroOrMoreCommaNOutputGateInstance2, pos)) {
        /* do nothing */
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

    pGateInstantiationOutput->push_back(pNOutputGateType0, pNOutputGateInstance1, pZeroOrMoreCommaNOutputGateInstance2);
    return true;
}
bool AstEventCommaEventParser::parsePos(
    AstEventCommaEventHandle & pEventCommaEvent
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pEventCommaEvent = AstEventCommaEventHandle(AstEventCommaEvent());

    AstEventExpressionHandle pEventExpression0;
    AstEventExpressionHandle pEventExpression1;
    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstEventExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pEventExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pEventCommaEvent->push_back(pEventExpression0, pEventExpression1);
    return true;
}
bool AstBinaryConstantExpressionCaseEqParser::parsePos(
    AstBinaryConstantExpressionCaseEqHandle & pBinaryConstantExpressionCaseEq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryConstantExpressionCaseEq = AstBinaryConstantExpressionCaseEqHandle(AstBinaryConstantExpressionCaseEq());

    AstConstantExpressionHandle pConstantExpression0;
    AstConstantExpressionHandle pConstantExpression1;
    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression0)) {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
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

    if (getTokenChildSize() > pos && AstConstantExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pConstantExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryConstantExpressionCaseEq->push_back(pConstantExpression0, pConstantExpression1);
    return true;
}
bool AstPortReferenceParser::parse(AstPortReferenceHandle & pPortReference) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPortReference = AstPortReferenceHandle(AstPortReference(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConstantBitSelectIdentifierHandle pConstantBitSelectIdentifier0;
    if (getTokenChildSize() > pos && AstConstantBitSelectIdentifierParser(getTokenStructure(), getToken()).parsePos(pConstantBitSelectIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPortReference = AstPortReferenceHandle(AstPortReference(pConstantBitSelectIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConstantRangeSelectIdentifierHandle pConstantRangeSelectIdentifier0;
    if (getTokenChildSize() > pos && AstConstantRangeSelectIdentifierParser(getTokenStructure(), getToken()).parsePos(pConstantRangeSelectIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPortReference = AstPortReferenceHandle(AstPortReference(pConstantRangeSelectIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstElseStatementOrNullParser::parsePos(
    AstElseStatementOrNullHandle & pElseStatementOrNull
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pElseStatementOrNull = AstElseStatementOrNullHandle(AstElseStatementOrNull());

    AstKeywordElseHandle pKeywordElse0;
    AstStatementOrNullHandle pStatementOrNull1;
    if (getTokenChildSize() > pos && AstKeywordElseParser(getTokenStructure(), getTokenChild(pos)).parse(pKeywordElse0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstStatementOrNullParser(getTokenStructure(), getTokenChild(pos)).parse(pStatementOrNull1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pElseStatementOrNull->push_back(pKeywordElse0, pStatementOrNull1);
    return true;
}
bool AstBinaryExpressionShiftLeftParser::parsePos(
    AstBinaryExpressionShiftLeftHandle & pBinaryExpressionShiftLeft
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionShiftLeft = AstBinaryExpressionShiftLeftHandle(AstBinaryExpressionShiftLeft());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "<") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionShiftLeft->push_back(pExpression0, pExpression1);
    return true;
}
bool AstPrimaryParser::parse(AstPrimaryHandle & pPrimary) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstSelectIdentifierHandle pSelectIdentifier0;
    if (getTokenChildSize() > pos && AstSelectIdentifierParser(getTokenStructure(), getToken()).parsePos(pSelectIdentifier0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPrimary = AstPrimaryHandle(AstPrimary(pSelectIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPrimary = AstPrimaryHandle(AstPrimary(pIdentifier0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNumberHandle pNumber0;
    if (getTokenChildSize() > pos && AstNumberParser(getTokenStructure(), getTokenChild(pos)).parse(pNumber0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPrimary = AstPrimaryHandle(AstPrimary(pNumber0));
        return true;
    } else {
        pos = old_pos;
    }
    AstConcatenationHandle pAstConcatenation0;
    if (getTokenChildSize() > pos && AstConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pAstConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPrimary = AstPrimaryHandle(AstPrimary(pAstConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    AstMultipleConcatenationHandle pMulitpleConcatenation0;
    if (getTokenChildSize() > pos && AstMultipleConcatenationParser(getTokenStructure(), getTokenChild(pos)).parse(pMulitpleConcatenation0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPrimary = AstPrimaryHandle(AstPrimary(pMulitpleConcatenation0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstBinaryExpressionCaseNeqParser::parsePos(
    AstBinaryExpressionCaseNeqHandle & pBinaryExpressionCaseNeq
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryExpressionCaseNeq = AstBinaryExpressionCaseNeqHandle(AstBinaryExpressionCaseNeq());

    AstExpressionHandle pExpression0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "!") {
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

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "=") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryExpressionCaseNeq->push_back(pExpression0, pExpression1);
    return true;
}
bool AstOrderedPortConnectionParser::parse(AstOrderedPortConnectionHandle & pOrderedPortConnection) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstZeroOrOneExpressionHandle pZeroOrOneExpression0;
    if (AstZeroOrOneExpressionParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneExpression0, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pOrderedPortConnection = AstOrderedPortConnectionHandle(AstOrderedPortConnection(pZeroOrOneExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstParamAssignmentParser::parse(
    AstParamAssignmentHandle & pParamAssignment)
{
    unsigned int pos = 0, old_pos = 0;
    pParamAssignment = AstParamAssignmentHandle(AstParamAssignment());

    AstIdentifierHandle pIdentifier0;
    AstExpressionHandle pExpression1;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
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

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression1)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pParamAssignment->push_back(pIdentifier0, pExpression1);
    return true;
}
bool AstKeywordInOutParser::parse(AstKeywordInOutHandle & pKeywordInOut) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordInOut = AstKeywordInOutHandle(AstKeywordInOut(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstConstantRangeSelectIdentifierParser::parsePos(
    AstConstantRangeSelectIdentifierHandle & pConstantRangeSelectIdentifier
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pConstantRangeSelectIdentifier = AstConstantRangeSelectIdentifierHandle(AstConstantRangeSelectIdentifier());

    AstIdentifierHandle pIdentifier0;
    AstConstantRangeSelectHandle pConstantRangeSelect1;
    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstConstantRangeSelectParser(getTokenStructure(), getToken()).parsePos(pConstantRangeSelect1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    pConstantRangeSelectIdentifier->push_back(pIdentifier0, pConstantRangeSelect1);
    return true;
}
bool AstBitSelectParser::parsePos(
    AstBitSelectHandle & pBitSelect
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBitSelect = AstBitSelectHandle(AstBitSelect());

    AstExpressionHandle pExpression0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "[") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "]") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBitSelect->push_back(pExpression0);
    return true;
}
bool AstKetwordNegedgeParser::parse(AstKetwordNegedgeHandle & pKeywordNegedge) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordNegedge = AstKetwordNegedgeHandle(AstKetwordNegedge(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstInputTerminalParser::parse(AstInputTerminalHandle & pInputTerminal) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstExpressionHandle pExpression0;
    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pInputTerminal = AstInputTerminalHandle(AstInputTerminal(pExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstZeroOrOneListOfPortsParser::parsePos(
    AstZeroOrOneListOfPortsHandle & pZeroOrOneListOfPorts
  , unsigned int & pos) 
{
    pZeroOrOneListOfPorts = AstZeroOrOneListOfPortsHandle(AstZeroOrOneListOfPorts());

    AstListOfPortsHandle pListOfPorts0;

    unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstListOfPortsParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfPorts0)) {
        ++pos;
    } else {
        pos = old_pos;
        return true;
    }
    pZeroOrOneListOfPorts->push_back(pListOfPorts0);


return true;
}
bool AstPortParser::parse(AstPortHandle & pPort) {
    if (getTokenName() != getToken()->name())
        return false;

    unsigned int pos = 0, old_pos = 0;
    AstPortExpressionHandle pPortExpression0;
    if (getTokenChildSize() > pos && AstPortExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pPortExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPort = AstPortHandle(AstPort(pPortExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    AstNamedPortExpressionHandle pNamedPortExpression0;
    if (getTokenChildSize() > pos && AstNamedPortExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pNamedPortExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
    }
    if (pos == getTokenChildSize()) {
        pPort = AstPortHandle(AstPort(pNamedPortExpression0));
        return true;
    } else {
        pos = old_pos;
    }
    reportChild();
    throw InvalidFormatException("No valid option in composite");
}

bool AstOneOrMoreDescriptionParser::parsePos(
    AstOneOrMoreDescriptionHandle & pOneOrMoreDescription
  , unsigned int & pos) {

    pOneOrMoreDescription = AstOneOrMoreDescriptionHandle(AstOneOrMoreDescription());

    AstDescriptionHandle pDescription0;
    unsigned int initial_pos = pos;


    while (true) {
        unsigned int old_pos = pos;
    if (getTokenChildSize() > pos && AstDescriptionParser(getTokenStructure(), getTokenChild(pos)).parse(pDescription0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }

    pOneOrMoreDescription->push_back(pDescription0);
    }

    return pos != initial_pos;
}

bool AstBinaryOperatorAsteriskParser::parsePos(
    AstBinaryOperatorAsteriskHandle & pBinaryOperatorAsterisk
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorAsterisk = AstBinaryOperatorAsteriskHandle(AstBinaryOperatorAsterisk());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "*") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorAsterisk->push_back();
    return true;
}
bool AstZeroOrMoreCommaExpressionParser::parsePos(
    AstZeroOrMoreCommaExpressionHandle & pZeroOrMoreCommaExpression
  , unsigned int & pos) 
{
    pZeroOrMoreCommaExpression = AstZeroOrMoreCommaExpressionHandle(AstZeroOrMoreCommaExpression());

    AstExpressionHandle pExpression0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ",") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstExpressionParser(getTokenStructure(), getTokenChild(pos)).parse(pExpression0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreCommaExpression->push_back(pExpression0);
    }

    return true;
}
bool AstAtIdentifierParser::parsePos(
    AstAtIdentifierHandle & pAtIdentifier
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pAtIdentifier = AstAtIdentifierHandle(AstAtIdentifier());

    AstIdentifierHandle pIdentifier0;
    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "@") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pAtIdentifier->push_back(pIdentifier0);
    return true;
}
bool AstKeywordInputParser::parse(AstKeywordInputHandle & pKeywordInput) {
    if (getTokenChildSize() == 1 && getToken()->name() == getTokenName()) {
        pKeywordInput = AstKeywordInputHandle(AstKeywordInput(getTokenChild(0)->name()));
        return true;
    }
    return false;
}bool AstBinaryOperatorXorNegParser::parsePos(
    AstBinaryOperatorXorNegHandle & pBinaryOperatorXorNeg
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorXorNeg = AstBinaryOperatorXorNegHandle(AstBinaryOperatorXorNeg());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "^") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "~") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorXorNeg->push_back();
    return true;
}
bool AstZeroOrMoreDotSingleIdentifierParser::parsePos(
    AstZeroOrMoreDotSingleIdentifierHandle & pZeroOrMoreDotSingleIdentifier
  , unsigned int & pos) 
{
    pZeroOrMoreDotSingleIdentifier = AstZeroOrMoreDotSingleIdentifierHandle(AstZeroOrMoreDotSingleIdentifier());

    AstSingleIdentifierHandle pSingleIdentifier0;

    while(true) {
        unsigned int old_pos = pos;
        if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ".") {
            ++pos;
        } else {
            pos = old_pos;
            break;
        }

    if (getTokenChildSize() > pos && AstSingleIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pSingleIdentifier0)) {
        ++pos;
    } else {
        pos = old_pos;
        break;
    }
        pZeroOrMoreDotSingleIdentifier->push_back(pSingleIdentifier0);
    }

    return true;
}
bool AstUnaryOperatorOrParser::parsePos(
    AstUnaryOperatorOrHandle & pUnaryOperatorOr
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pUnaryOperatorOr = AstUnaryOperatorOrHandle(AstUnaryOperatorOr());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == "|") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pUnaryOperatorOr->push_back();
    return true;
}
bool AstBinaryOperatorGtParser::parsePos(
    AstBinaryOperatorGtHandle & pBinaryOperatorGt
  , unsigned int & pos)
{
    unsigned int old_pos = pos;
    pBinaryOperatorGt = AstBinaryOperatorGtHandle(AstBinaryOperatorGt());

    if (getTokenChildSize() > pos && getTokenChild(pos)->name() == ">") {
            ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    pBinaryOperatorGt->push_back();
    return true;
}
bool AstNetDeclarationParser::parse(
    AstNetDeclarationHandle & pNetDeclaration)
{
    unsigned int pos = 0, old_pos = 0;
    pNetDeclaration = AstNetDeclarationHandle(AstNetDeclaration());

    AstNetTypeHandle pNetType0;
    AstZeroOrOneRangeHandle pZeroOrOneRange1 = AstZeroOrOneRangeHandle(AstZeroOrOneRange())
;
    AstListOfNetIdentifierHandle pListOfNetIdentifier2;
    if (getTokenChildSize() > pos && AstNetTypeParser(getTokenStructure(), getTokenChild(pos)).parse(pNetType0)) {
        ++pos;
    } else {
        pos = old_pos;
        return false;
    }

    if (AstZeroOrOneRangeParser(getTokenStructure(), getToken()).parsePos(pZeroOrOneRange1, pos)) {
        /* do nothing */
    } else {
        pos = old_pos;
        return false;
    }

    if (getTokenChildSize() > pos && AstListOfNetIdentifierParser(getTokenStructure(), getTokenChild(pos)).parse(pListOfNetIdentifier2)) {
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

    pNetDeclaration->push_back(pNetType0, pZeroOrOneRange1, pListOfNetIdentifier2);
    return true;
}
