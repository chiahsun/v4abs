#include "Ast.h"
#include "exception/Exception.h"
#include <sstream>
#include <algorithm>

Ast::~Ast() { }
std::string Ast::toString() const {
    throw NotOverridenException();
}
AstHandle Ast::base_handle() const {
    throw NotOverridenException();
}
AstListOfPortIdentifiers::AstListOfPortIdentifiers() { }
void AstListOfPortIdentifiers::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrMoreCommaIdentifier1));
}
std::vector<AstListOfPortIdentifiers::ElementType>& AstListOfPortIdentifiers::container() {
    return _vecElements;
}
const std::vector<AstListOfPortIdentifiers::ElementType>& AstListOfPortIdentifiers::container() const {
    return _vecElements;
}
AstListOfPortIdentifiers::ElementType AstListOfPortIdentifiers::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfPortIdentifiers::element_size() const
  { return _vecElements.size(); }
std::string AstListOfPortIdentifiers::toString() const {
    std::string s = "(list_of_port_identifiers";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaIdentifier1->toString();
    }
        s += ")";    return s;
}
AstZeroOrOneListOfModuleConnections::AstZeroOrOneListOfModuleConnections() { }
void AstZeroOrOneListOfModuleConnections::push_back(AstListOfModuleConnectionsHandle pListOfModuleConnections) {
    _vecElements.push_back(ElementType(pListOfModuleConnections));
}
std::vector<AstZeroOrOneListOfModuleConnections::ElementType>& AstZeroOrOneListOfModuleConnections::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneListOfModuleConnections::ElementType>& AstZeroOrOneListOfModuleConnections::container() const {
    return _vecElements;
}
AstZeroOrOneListOfModuleConnections::ElementType AstZeroOrOneListOfModuleConnections::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneListOfModuleConnections::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneListOfModuleConnections::toString() const {
    std::string s = "(zero_or_one_list_of_module_connections";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pListOfModuleConnections->toString();
    }
        s += ")";    return s;
}
AstZeroOrOneNameOfGateInstance::AstZeroOrOneNameOfGateInstance() { }
void AstZeroOrOneNameOfGateInstance::push_back(AstNameOfGateInstanceHandle pNameOfGateInstance) {
    _vecElements.push_back(ElementType(pNameOfGateInstance));
}
std::vector<AstZeroOrOneNameOfGateInstance::ElementType>& AstZeroOrOneNameOfGateInstance::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneNameOfGateInstance::ElementType>& AstZeroOrOneNameOfGateInstance::container() const {
    return _vecElements;
}
AstZeroOrOneNameOfGateInstance::ElementType AstZeroOrOneNameOfGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneNameOfGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneNameOfGateInstance::toString() const {
    std::string s = "(zero_or_one_name_of_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNameOfGateInstance->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorNotEqual::AstBinaryOperatorNotEqual() { }
void AstBinaryOperatorNotEqual::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorNotEqual::ElementType>& AstBinaryOperatorNotEqual::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorNotEqual::ElementType>& AstBinaryOperatorNotEqual::container() const {
    return _vecElements;
}
AstBinaryOperatorNotEqual::ElementType AstBinaryOperatorNotEqual::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorNotEqual::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorNotEqual::toString() const {
    std::string s = "(binary_operator_not_equal";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryOperatorXor::AstBinaryOperatorXor() { }
void AstBinaryOperatorXor::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorXor::ElementType>& AstBinaryOperatorXor::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorXor::ElementType>& AstBinaryOperatorXor::container() const {
    return _vecElements;
}
AstBinaryOperatorXor::ElementType AstBinaryOperatorXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorXor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorXor::toString() const {
    std::string s = "(binary_operator_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryExpressionMinus::AstBinaryExpressionMinus() { }
void AstBinaryExpressionMinus::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionMinus::ElementType>& AstBinaryExpressionMinus::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionMinus::ElementType>& AstBinaryExpressionMinus::container() const {
    return _vecElements;
}
AstBinaryExpressionMinus::ElementType AstBinaryExpressionMinus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionMinus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionMinus::toString() const {
    std::string s = "(binary_expression_minus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryExpression::AstUnaryExpression() { }
void AstUnaryExpression::push_back(AstUnaryOperatorHandle pUnaryOperator0, AstPrimaryHandle pPrimary1) {
    _vecElements.push_back(ElementType(pUnaryOperator0, pPrimary1));
}
std::vector<AstUnaryExpression::ElementType>& AstUnaryExpression::container() {
    return _vecElements;
}
const std::vector<AstUnaryExpression::ElementType>& AstUnaryExpression::container() const {
    return _vecElements;
}
AstUnaryExpression::ElementType AstUnaryExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryExpression::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryExpression::toString() const {
    std::string s = "(unary_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pUnaryOperator0->toString();
        s = s + " " + _vecElements[i]._pPrimary1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorLeq::AstBinaryOperatorLeq() { }
void AstBinaryOperatorLeq::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorLeq::ElementType>& AstBinaryOperatorLeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorLeq::ElementType>& AstBinaryOperatorLeq::container() const {
    return _vecElements;
}
AstBinaryOperatorLeq::ElementType AstBinaryOperatorLeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorLeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorLeq::toString() const {
    std::string s = "(binary_operator_leq";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstKeywordParameter::AstKeywordParameter(const std::string & s)
  : _keyword_parameter(s)
  { }
std::string AstKeywordParameter::keyword_parameter() const
  { return _keyword_parameter; }
std::string AstKeywordParameter::toString() const
  { return "(keyword_parameter " + keyword_parameter() + ")";}
AstKeywordMacroModule::AstKeywordMacroModule(const std::string & s)
  : _keyword_macro_module(s)
  { }
std::string AstKeywordMacroModule::keyword_macro_module() const
  { return _keyword_macro_module; }
std::string AstKeywordMacroModule::toString() const
  { return "(keyword_macro_module " + keyword_macro_module() + ")";}
AstBinaryExpressionGeq::AstBinaryExpressionGeq() { }
void AstBinaryExpressionGeq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionGeq::ElementType>& AstBinaryExpressionGeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionGeq::ElementType>& AstBinaryExpressionGeq::container() const {
    return _vecElements;
}
AstBinaryExpressionGeq::ElementType AstBinaryExpressionGeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionGeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionGeq::toString() const {
    std::string s = "(binary_expression_geq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorNot::AstUnaryOperatorNot() { }
void AstUnaryOperatorNot::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorNot::ElementType>& AstUnaryOperatorNot::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorNot::ElementType>& AstUnaryOperatorNot::container() const {
    return _vecElements;
}
AstUnaryOperatorNot::ElementType AstUnaryOperatorNot::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorNot::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorNot::toString() const {
    std::string s = "(unary_operator_not";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaNetAssignment::AstZeroOrMoreCommaNetAssignment() { }
void AstZeroOrMoreCommaNetAssignment::push_back(AstNetAssignmentHandle pNetAssignment) {
    _vecElements.push_back(ElementType(pNetAssignment));
}
std::vector<AstZeroOrMoreCommaNetAssignment::ElementType>& AstZeroOrMoreCommaNetAssignment::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaNetAssignment::ElementType>& AstZeroOrMoreCommaNetAssignment::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaNetAssignment::ElementType AstZeroOrMoreCommaNetAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaNetAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaNetAssignment::toString() const {
    std::string s = "(zero_or_more_comma_net_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNetAssignment->toString();
    }
        s += ")";    return s;
}
AstEventExpression::AstEventExpression(AstExpressionHandle pExpression)
  : _pExpression(pExpression)
  { }
AstEventExpression::AstEventExpression(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstEventExpression::AstEventExpression(AstPosedgeExpressionHandle pPosedgeExpression)
  : _pPosedgeExpression(pPosedgeExpression)
  { }
AstEventExpression::AstEventExpression(AstNegedgeExpressionHandle pNegedgeExpression)
  : _pNegedgeExpression(pNegedgeExpression)
  { }
AstEventExpression::AstEventExpression(AstEventCommaEventHandle pEventCommaEvent)
  : _pEventCommaEvent(pEventCommaEvent)
  { }
AstEventExpression::AstEventExpression(AstEventOrEventHandle pEventOrEvent)
  : _pEventOrEvent(pEventOrEvent)
  { }
AstExpressionHandle AstEventExpression::expression() const
  { return _pExpression; }
AstIdentifierHandle AstEventExpression::identifier() const
  { return _pIdentifier; }
AstPosedgeExpressionHandle AstEventExpression::posedge_expression() const
  { return _pPosedgeExpression; }
AstNegedgeExpressionHandle AstEventExpression::negedge_expression() const
  { return _pNegedgeExpression; }
AstEventCommaEventHandle AstEventExpression::event_comma_event() const
  { return _pEventCommaEvent; }
AstEventOrEventHandle AstEventExpression::event_or_event() const
  { return _pEventOrEvent; }
std::string AstEventExpression::toString() const {
    std::string s = "(event_expression";
    if (expression().valid())
        s = s + " " + expression()->toString();
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (posedge_expression().valid())
        s = s + " " + posedge_expression()->toString();
    if (negedge_expression().valid())
        s = s + " " + negedge_expression()->toString();
    if (event_comma_event().valid())
        s = s + " " + event_comma_event()->toString();
    if (event_or_event().valid())
        s = s + " " + event_or_event()->toString();
        s += ")";    return s;
}
AstZeroOrMoreCommaNamedPortConnection::AstZeroOrMoreCommaNamedPortConnection() { }
void AstZeroOrMoreCommaNamedPortConnection::push_back(AstNamedPortConnectionHandle pNamedPortConnection) {
    _vecElements.push_back(ElementType(pNamedPortConnection));
}
std::vector<AstZeroOrMoreCommaNamedPortConnection::ElementType>& AstZeroOrMoreCommaNamedPortConnection::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaNamedPortConnection::ElementType>& AstZeroOrMoreCommaNamedPortConnection::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaNamedPortConnection::ElementType AstZeroOrMoreCommaNamedPortConnection::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaNamedPortConnection::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaNamedPortConnection::toString() const {
    std::string s = "(zero_or_more_comma_named_port_connection";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNamedPortConnection->toString();
    }
        s += ")";    return s;
}
AstCaseItem::AstCaseItem(AstCaseItemItemHandle pCaseItemItem)
  : _pCaseItemItem(pCaseItemItem)
  { }
AstCaseItem::AstCaseItem(AstCaseItemDefaultHandle pCaseItemDefault)
  : _pCaseItemDefault(pCaseItemDefault)
  { }
AstCaseItemItemHandle AstCaseItem::case_item_item() const
  { return _pCaseItemItem; }
AstCaseItemDefaultHandle AstCaseItem::case_item_default() const
  { return _pCaseItemDefault; }
std::string AstCaseItem::toString() const {
    std::string s = "(case_item";
    if (case_item_item().valid())
        s = s + " " + case_item_item()->toString();
    if (case_item_default().valid())
        s = s + " " + case_item_default()->toString();
        s += ")";    return s;
}
AstBinaryExpressionBwAnd::AstBinaryExpressionBwAnd() { }
void AstBinaryExpressionBwAnd::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionBwAnd::ElementType>& AstBinaryExpressionBwAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionBwAnd::ElementType>& AstBinaryExpressionBwAnd::container() const {
    return _vecElements;
}
AstBinaryExpressionBwAnd::ElementType AstBinaryExpressionBwAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionBwAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionBwAnd::toString() const {
    std::string s = "(binary_expression_bw_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstIdentifier::AstIdentifier(AstSingleIdentifierHandle pSingleIdentifier)
  : _pSingleIdentifier(pSingleIdentifier)
  { }
AstIdentifier::AstIdentifier(AstMultiIdentifierHandle pMultiIdentifier)
  : _pMultiIdentifier(pMultiIdentifier)
  { }
AstSingleIdentifierHandle AstIdentifier::single_identifier() const
  { return _pSingleIdentifier; }
AstMultiIdentifierHandle AstIdentifier::multi_identifier() const
  { return _pMultiIdentifier; }
std::string AstIdentifier::toString() const {
    std::string s = "(identifier";
    if (single_identifier().valid())
        s = s + " " + single_identifier()->toString();
    if (multi_identifier().valid())
        s = s + " " + multi_identifier()->toString();
        s += ")";    return s;
}
AstContinuousAssign::AstContinuousAssign() { }
void AstContinuousAssign::push_back(AstKeywordAssignHandle pKeywordAssign0, AstListOfNetAssignmentsHandle pListOfNetAssignments1) {
    _vecElements.push_back(ElementType(pKeywordAssign0, pListOfNetAssignments1));
}
std::vector<AstContinuousAssign::ElementType>& AstContinuousAssign::container() {
    return _vecElements;
}
const std::vector<AstContinuousAssign::ElementType>& AstContinuousAssign::container() const {
    return _vecElements;
}
AstContinuousAssign::ElementType AstContinuousAssign::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstContinuousAssign::element_size() const
  { return _vecElements.size(); }
std::string AstContinuousAssign::toString() const {
    std::string s = "(continuous_assign";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordAssign0->toString();
        s = s + " " + _vecElements[i]._pListOfNetAssignments1->toString();
    }
        s += ")";    return s;
}
AstNumber::AstNumber(AstUnsignedNumberHandle pUnsignedNumber)
  : _pUnsignedNumber(pUnsignedNumber)
  { }
AstNumber::AstNumber(AstBinaryNumberHandle pBinaryNumber)
  : _pBinaryNumber(pBinaryNumber)
  { }
AstNumber::AstNumber(AstOctalNumberHandle pOctalNumber)
  : _pOctalNumber(pOctalNumber)
  { }
AstNumber::AstNumber(AstDecimalNumberHandle pDecimalNumber)
  : _pDecimalNumber(pDecimalNumber)
  { }
AstNumber::AstNumber(AstHeximalNumberHandle pHeximalNumber)
  : _pHeximalNumber(pHeximalNumber)
  { }
AstUnsignedNumberHandle AstNumber::unsigned_number() const
  { return _pUnsignedNumber; }
AstBinaryNumberHandle AstNumber::binary_number() const
  { return _pBinaryNumber; }
AstOctalNumberHandle AstNumber::octal_number() const
  { return _pOctalNumber; }
AstDecimalNumberHandle AstNumber::decimal_number() const
  { return _pDecimalNumber; }
AstHeximalNumberHandle AstNumber::heximal_number() const
  { return _pHeximalNumber; }
std::string AstNumber::toString() const {
    std::string s = "(number";
    if (unsigned_number().valid())
        s = s + " " + unsigned_number()->toString();
    if (binary_number().valid())
        s = s + " " + binary_number()->toString();
    if (octal_number().valid())
        s = s + " " + octal_number()->toString();
    if (decimal_number().valid())
        s = s + " " + decimal_number()->toString();
    if (heximal_number().valid())
        s = s + " " + heximal_number()->toString();
        s += ")";    return s;
}
AstNetLvalueBitSelect::AstNetLvalueBitSelect() { }
void AstNetLvalueBitSelect::push_back(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pIdentifier0, pExpression1));
}
std::vector<AstNetLvalueBitSelect::ElementType>& AstNetLvalueBitSelect::container() {
    return _vecElements;
}
const std::vector<AstNetLvalueBitSelect::ElementType>& AstNetLvalueBitSelect::container() const {
    return _vecElements;
}
AstNetLvalueBitSelect::ElementType AstNetLvalueBitSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNetLvalueBitSelect::element_size() const
  { return _vecElements.size(); }
std::string AstNetLvalueBitSelect::toString() const {
    std::string s = "(net_lvalue_bit_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstExpression::AstExpression(AstPrimaryHandle pPrimary)
  : _pPrimary(pPrimary)
  { }
AstExpression::AstExpression(AstBracedExpressionHandle pBracedExpression)
  : _pBracedExpression(pBracedExpression)
  { }
AstExpression::AstExpression(AstUnaryExpressionHandle pUnaryExpression)
  : _pUnaryExpression(pUnaryExpression)
  { }
AstExpression::AstExpression(AstTernaryExpressionHandle pTernaryExpression)
  : _pTernaryExpression(pTernaryExpression)
  { }
AstExpression::AstExpression(AstBinaryExpressionHandle pBinaryExpression)
  : _pBinaryExpression(pBinaryExpression)
  { }
AstPrimaryHandle AstExpression::primary() const
  { return _pPrimary; }
AstBracedExpressionHandle AstExpression::braced_expression() const
  { return _pBracedExpression; }
AstUnaryExpressionHandle AstExpression::unary_expression() const
  { return _pUnaryExpression; }
AstTernaryExpressionHandle AstExpression::ternary_expression() const
  { return _pTernaryExpression; }
AstBinaryExpressionHandle AstExpression::binary_expression() const
  { return _pBinaryExpression; }
std::string AstExpression::toString() const {
    std::string s = "(expression";
    if (primary().valid())
        s = s + " " + primary()->toString();
    if (braced_expression().valid())
        s = s + " " + braced_expression()->toString();
    if (unary_expression().valid())
        s = s + " " + unary_expression()->toString();
    if (ternary_expression().valid())
        s = s + " " + ternary_expression()->toString();
    if (binary_expression().valid())
        s = s + " " + binary_expression()->toString();
        s += ")";    return s;
}
AstNamedPortExpression::AstNamedPortExpression() { }
void AstNamedPortExpression::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOnePortExpressionHandle pZeroOrOnePortExpression1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrOnePortExpression1));
}
std::vector<AstNamedPortExpression::ElementType>& AstNamedPortExpression::container() {
    return _vecElements;
}
const std::vector<AstNamedPortExpression::ElementType>& AstNamedPortExpression::container() const {
    return _vecElements;
}
AstNamedPortExpression::ElementType AstNamedPortExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNamedPortExpression::element_size() const
  { return _vecElements.size(); }
std::string AstNamedPortExpression::toString() const {
    std::string s = "(named_port_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOnePortExpression1->toString();
    }
        s += ")";    return s;
}
AstStatement::AstStatement(AstBlockingAssingmentSemicolonHandle pBlockingAssignmentSemicolon)
  : _pBlockingAssignmentSemicolon(pBlockingAssignmentSemicolon)
  { }
AstStatement::AstStatement(AstNonBlockingAssignmentSemicolonHandle pNonBlockingAssignmentSemicolon)
  : _pNonBlockingAssignmentSemicolon(pNonBlockingAssignmentSemicolon)
  { }
AstStatement::AstStatement(AstProceduralContinuousAssignmentSemicolonHandle pProceduralContinuousAssignmentSemicoln)
  : _pProceduralContinuousAssignmentSemicoln(pProceduralContinuousAssignmentSemicoln)
  { }
AstStatement::AstStatement(AstProceduralTimingControlStatementHandle pProceduralTimingControlStatement)
  : _pProceduralTimingControlStatement(pProceduralTimingControlStatement)
  { }
AstStatement::AstStatement(AstConditionalStatementHandle pConditionalStatement)
  : _pConditionalStatement(pConditionalStatement)
  { }
AstStatement::AstStatement(AstCaseStatementHandle pCaseStatement)
  : _pCaseStatement(pCaseStatement)
  { }
AstStatement::AstStatement(AstLoopStatementHandle pLoopStatement)
  : _pLoopStatement(pLoopStatement)
  { }
AstStatement::AstStatement(AstSeqBlockHandle pSeqBlock)
  : _pSeqBlock(pSeqBlock)
  { }
AstBlockingAssingmentSemicolonHandle AstStatement::blocking_assignment_semicolon() const
  { return _pBlockingAssignmentSemicolon; }
AstNonBlockingAssignmentSemicolonHandle AstStatement::non_blocking_assignment_semicolon() const
  { return _pNonBlockingAssignmentSemicolon; }
AstProceduralContinuousAssignmentSemicolonHandle AstStatement::procedural_continuous_assignment_semicolon() const
  { return _pProceduralContinuousAssignmentSemicoln; }
AstProceduralTimingControlStatementHandle AstStatement::procedural_timing_control_statement() const
  { return _pProceduralTimingControlStatement; }
AstConditionalStatementHandle AstStatement::conditional_statement() const
  { return _pConditionalStatement; }
AstCaseStatementHandle AstStatement::case_statement() const
  { return _pCaseStatement; }
AstLoopStatementHandle AstStatement::loop_statement() const
  { return _pLoopStatement; }
AstSeqBlockHandle AstStatement::seq_block() const
  { return _pSeqBlock; }
std::string AstStatement::toString() const {
    std::string s = "(statement";
    if (blocking_assignment_semicolon().valid())
        s = s + " " + blocking_assignment_semicolon()->toString();
    if (non_blocking_assignment_semicolon().valid())
        s = s + " " + non_blocking_assignment_semicolon()->toString();
    if (procedural_continuous_assignment_semicolon().valid())
        s = s + " " + procedural_continuous_assignment_semicolon()->toString();
    if (procedural_timing_control_statement().valid())
        s = s + " " + procedural_timing_control_statement()->toString();
    if (conditional_statement().valid())
        s = s + " " + conditional_statement()->toString();
    if (case_statement().valid())
        s = s + " " + case_statement()->toString();
    if (loop_statement().valid())
        s = s + " " + loop_statement()->toString();
    if (seq_block().valid())
        s = s + " " + seq_block()->toString();
        s += ")";    return s;
}
AstBinaryConstantExpressionEq::AstBinaryConstantExpressionEq() { }
void AstBinaryConstantExpressionEq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionEq::ElementType>& AstBinaryConstantExpressionEq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionEq::ElementType>& AstBinaryConstantExpressionEq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionEq::ElementType AstBinaryConstantExpressionEq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionEq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionEq::toString() const {
    std::string s = "(binary_constant_expression_eq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstCaseStatement::AstCaseStatement() { }
void AstCaseStatement::push_back(AstKeywordCaseHandle pKeywordCase0, AstExpressionHandle pExpression1, AstOneOrMoreCaseItemHandle pOneOrMoreCaseItem2, AstKeywordEndCaseHandle pKeywordEndCase3) {
    _vecElements.push_back(ElementType(pKeywordCase0, pExpression1, pOneOrMoreCaseItem2, pKeywordEndCase3));
}
std::vector<AstCaseStatement::ElementType>& AstCaseStatement::container() {
    return _vecElements;
}
const std::vector<AstCaseStatement::ElementType>& AstCaseStatement::container() const {
    return _vecElements;
}
AstCaseStatement::ElementType AstCaseStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstCaseStatement::element_size() const
  { return _vecElements.size(); }
std::string AstCaseStatement::toString() const {
    std::string s = "(case_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordCase0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
        s = s + " " + _vecElements[i]._pOneOrMoreCaseItem2->toString();
        s = s + " " + _vecElements[i]._pKeywordEndCase3->toString();
    }
        s += ")";    return s;
}
AstListOfRegisterIdentifiers::AstListOfRegisterIdentifiers() { }
void AstListOfRegisterIdentifiers::push_back(AstRegisterNameHandle pRegisterName0, AstZeroOrMoreCommaRegisterNameHandle pZeroOrMoreCommaRegisterName1) {
    _vecElements.push_back(ElementType(pRegisterName0, pZeroOrMoreCommaRegisterName1));
}
std::vector<AstListOfRegisterIdentifiers::ElementType>& AstListOfRegisterIdentifiers::container() {
    return _vecElements;
}
const std::vector<AstListOfRegisterIdentifiers::ElementType>& AstListOfRegisterIdentifiers::container() const {
    return _vecElements;
}
AstListOfRegisterIdentifiers::ElementType AstListOfRegisterIdentifiers::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfRegisterIdentifiers::element_size() const
  { return _vecElements.size(); }
std::string AstListOfRegisterIdentifiers::toString() const {
    std::string s = "(list_of_register_identifiers";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRegisterName0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaRegisterName1->toString();
    }
        s += ")";    return s;
}
AstRange::AstRange() { }
void AstRange::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstRange::ElementType>& AstRange::container() {
    return _vecElements;
}
const std::vector<AstRange::ElementType>& AstRange::container() const {
    return _vecElements;
}
AstRange::ElementType AstRange::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstRange::element_size() const
  { return _vecElements.size(); }
std::string AstRange::toString() const {
    std::string s = "(range";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorSlash::AstBinaryOperatorSlash() { }
void AstBinaryOperatorSlash::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorSlash::ElementType>& AstBinaryOperatorSlash::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorSlash::ElementType>& AstBinaryOperatorSlash::container() const {
    return _vecElements;
}
AstBinaryOperatorSlash::ElementType AstBinaryOperatorSlash::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorSlash::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorSlash::toString() const {
    std::string s = "(binary_operator_slash";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstProceduralContinuousAssignment::AstProceduralContinuousAssignment() { }
void AstProceduralContinuousAssignment::push_back(AstKeywordAssignHandle pKeywordAssign0, AstRegAssignmentHandle pRegAssignment1) {
    _vecElements.push_back(ElementType(pKeywordAssign0, pRegAssignment1));
}
std::vector<AstProceduralContinuousAssignment::ElementType>& AstProceduralContinuousAssignment::container() {
    return _vecElements;
}
const std::vector<AstProceduralContinuousAssignment::ElementType>& AstProceduralContinuousAssignment::container() const {
    return _vecElements;
}
AstProceduralContinuousAssignment::ElementType AstProceduralContinuousAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstProceduralContinuousAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstProceduralContinuousAssignment::toString() const {
    std::string s = "(procedural_continuous_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordAssign0->toString();
        s = s + " " + _vecElements[i]._pRegAssignment1->toString();
    }
        s += ")";    return s;
}
AstSelect::AstSelect(AstRangeSelectHandle pRangeSelect)
  : _pRangeSelect(pRangeSelect)
  { }
AstSelect::AstSelect(AstBitSelectHandle pBitSelect)
  : _pBitSelect(pBitSelect)
  { }
AstRangeSelectHandle AstSelect::range_select() const
  { return _pRangeSelect; }
AstBitSelectHandle AstSelect::bit_select() const
  { return _pBitSelect; }
std::string AstSelect::toString() const {
    std::string s = "(select";
    if (range_select().valid())
        s = s + " " + range_select()->toString();
    if (bit_select().valid())
        s = s + " " + bit_select()->toString();
        s += ")";    return s;
}
AstBinaryOperatorNegXor::AstBinaryOperatorNegXor() { }
void AstBinaryOperatorNegXor::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorNegXor::ElementType>& AstBinaryOperatorNegXor::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorNegXor::ElementType>& AstBinaryOperatorNegXor::container() const {
    return _vecElements;
}
AstBinaryOperatorNegXor::ElementType AstBinaryOperatorNegXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorNegXor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorNegXor::toString() const {
    std::string s = "(binary_operator_neg_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryOperatorOrOr::AstBinaryOperatorOrOr() { }
void AstBinaryOperatorOrOr::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorOrOr::ElementType>& AstBinaryOperatorOrOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorOrOr::ElementType>& AstBinaryOperatorOrOr::container() const {
    return _vecElements;
}
AstBinaryOperatorOrOr::ElementType AstBinaryOperatorOrOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorOrOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorOrOr::toString() const {
    std::string s = "(binary_operator_or_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstSeqBlock::AstSeqBlock() { }
void AstSeqBlock::push_back(AstKeywordBeginHandle pKeywordBegin0, AstZeroOrMoreStatementHandle pZeroOrMoreStatement1, AstKeywordEndHandle pKeywordEnd2) {
    _vecElements.push_back(ElementType(pKeywordBegin0, pZeroOrMoreStatement1, pKeywordEnd2));
}
std::vector<AstSeqBlock::ElementType>& AstSeqBlock::container() {
    return _vecElements;
}
const std::vector<AstSeqBlock::ElementType>& AstSeqBlock::container() const {
    return _vecElements;
}
AstSeqBlock::ElementType AstSeqBlock::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstSeqBlock::element_size() const
  { return _vecElements.size(); }
std::string AstSeqBlock::toString() const {
    std::string s = "(seq_block";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordBegin0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreStatement1->toString();
        s = s + " " + _vecElements[i]._pKeywordEnd2->toString();
    }
        s += ")";    return s;
}
AstBlockingAssignment::AstBlockingAssignment() { }
void AstBlockingAssignment::push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pRegLvalue0, pExpression1));
}
std::vector<AstBlockingAssignment::ElementType>& AstBlockingAssignment::container() {
    return _vecElements;
}
const std::vector<AstBlockingAssignment::ElementType>& AstBlockingAssignment::container() const {
    return _vecElements;
}
AstBlockingAssignment::ElementType AstBlockingAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBlockingAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstBlockingAssignment::toString() const {
    std::string s = "(blocking_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRegLvalue0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreStatement::AstZeroOrMoreStatement() { }
void AstZeroOrMoreStatement::push_back(AstStatementHandle pStatement) {
    _vecElements.push_back(ElementType(pStatement));
}
std::vector<AstZeroOrMoreStatement::ElementType>& AstZeroOrMoreStatement::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreStatement::ElementType>& AstZeroOrMoreStatement::container() const {
    return _vecElements;
}
AstZeroOrMoreStatement::ElementType AstZeroOrMoreStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreStatement::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreStatement::toString() const {
    std::string s = "(zero_or_more_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pStatement->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionGeq::AstBinaryConstantExpressionGeq() { }
void AstBinaryConstantExpressionGeq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionGeq::ElementType>& AstBinaryConstantExpressionGeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionGeq::ElementType>& AstBinaryConstantExpressionGeq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionGeq::ElementType AstBinaryConstantExpressionGeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionGeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionGeq::toString() const {
    std::string s = "(binary_constant_expression_geq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstTernaryExpression::AstTernaryExpression() { }
void AstTernaryExpression::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstExpressionHandle pExpression2) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1, pExpression2));
}
std::vector<AstTernaryExpression::ElementType>& AstTernaryExpression::container() {
    return _vecElements;
}
const std::vector<AstTernaryExpression::ElementType>& AstTernaryExpression::container() const {
    return _vecElements;
}
AstTernaryExpression::ElementType AstTernaryExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstTernaryExpression::element_size() const
  { return _vecElements.size(); }
std::string AstTernaryExpression::toString() const {
    std::string s = "(ternary_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
        s = s + " " + _vecElements[i]._pExpression2->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaParamAssignment::AstZeroOrMoreCommaParamAssignment() { }
void AstZeroOrMoreCommaParamAssignment::push_back(AstParamAssignmentHandle pParamAssignment) {
    _vecElements.push_back(ElementType(pParamAssignment));
}
std::vector<AstZeroOrMoreCommaParamAssignment::ElementType>& AstZeroOrMoreCommaParamAssignment::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaParamAssignment::ElementType>& AstZeroOrMoreCommaParamAssignment::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaParamAssignment::ElementType AstZeroOrMoreCommaParamAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaParamAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaParamAssignment::toString() const {
    std::string s = "(zero_or_more_comma_param_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pParamAssignment->toString();
    }
        s += ")";    return s;
}
AstDescription::AstDescription(AstModuleDeclarationHandle pModuleDeclaration)
  : _pModuleDeclaration(pModuleDeclaration)
  { }
AstModuleDeclarationHandle AstDescription::module_declaration() const
  { return _pModuleDeclaration; }
std::string AstDescription::toString() const {
    std::string s = "(description";
    if (module_declaration().valid())
        s = s + " " + module_declaration()->toString();
        s += ")";    return s;
}
AstKeywordOutput::AstKeywordOutput(const std::string & s)
  : _keyword_output(s)
  { }
std::string AstKeywordOutput::keyword_output() const
  { return _keyword_output; }
std::string AstKeywordOutput::toString() const
  { return "(keyword_output " + keyword_output() + ")";}
AstBinaryConstantExpressionShiftRight::AstBinaryConstantExpressionShiftRight() { }
void AstBinaryConstantExpressionShiftRight::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionShiftRight::ElementType>& AstBinaryConstantExpressionShiftRight::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionShiftRight::ElementType>& AstBinaryConstantExpressionShiftRight::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionShiftRight::ElementType AstBinaryConstantExpressionShiftRight::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionShiftRight::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionShiftRight::toString() const {
    std::string s = "(binary_constant_expression_shift_right";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstProceduralTimingControlStatement::AstProceduralTimingControlStatement() { }
void AstProceduralTimingControlStatement::push_back(AstDelayOrEventControlHandle pDelayOrEventControl0, AstStatementOrNullHandle pStatementOrNull1) {
    _vecElements.push_back(ElementType(pDelayOrEventControl0, pStatementOrNull1));
}
std::vector<AstProceduralTimingControlStatement::ElementType>& AstProceduralTimingControlStatement::container() {
    return _vecElements;
}
const std::vector<AstProceduralTimingControlStatement::ElementType>& AstProceduralTimingControlStatement::container() const {
    return _vecElements;
}
AstProceduralTimingControlStatement::ElementType AstProceduralTimingControlStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstProceduralTimingControlStatement::element_size() const
  { return _vecElements.size(); }
std::string AstProceduralTimingControlStatement::toString() const {
    std::string s = "(procedural_timing_control_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pDelayOrEventControl0->toString();
        s = s + " " + _vecElements[i]._pStatementOrNull1->toString();
    }
        s += ")";    return s;
}
AstInoutDeclaration::AstInoutDeclaration() { }
void AstInoutDeclaration::push_back(AstKeywordInOutHandle pKeywordInOut0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
    _vecElements.push_back(ElementType(pKeywordInOut0, pZeroOrOneRange1, pListOfPortIdentifiers2));
}
std::vector<AstInoutDeclaration::ElementType>& AstInoutDeclaration::container() {
    return _vecElements;
}
const std::vector<AstInoutDeclaration::ElementType>& AstInoutDeclaration::container() const {
    return _vecElements;
}
AstInoutDeclaration::ElementType AstInoutDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstInoutDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstInoutDeclaration::toString() const {
    std::string s = "(inout_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordInOut0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
        s = s + " " + _vecElements[i]._pListOfPortIdentifiers2->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionBwOr::AstBinaryExpressionBwOr() { }
void AstBinaryExpressionBwOr::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionBwOr::ElementType>& AstBinaryExpressionBwOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionBwOr::ElementType>& AstBinaryExpressionBwOr::container() const {
    return _vecElements;
}
AstBinaryExpressionBwOr::ElementType AstBinaryExpressionBwOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionBwOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionBwOr::toString() const {
    std::string s = "(binary_expression_bw_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstListOfNetIdentifier::AstListOfNetIdentifier() { }
void AstListOfNetIdentifier::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreCommaIdentifierHandle pZeroOrMoreCommaIdentifier1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrMoreCommaIdentifier1));
}
std::vector<AstListOfNetIdentifier::ElementType>& AstListOfNetIdentifier::container() {
    return _vecElements;
}
const std::vector<AstListOfNetIdentifier::ElementType>& AstListOfNetIdentifier::container() const {
    return _vecElements;
}
AstListOfNetIdentifier::ElementType AstListOfNetIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfNetIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstListOfNetIdentifier::toString() const {
    std::string s = "(list_of_net_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaIdentifier1->toString();
    }
        s += ")";    return s;
}
AstModuleItem::AstModuleItem(AstAlwaysConstructHandle pAlwaysConstruct)
  : _pAlwaysConstruct(pAlwaysConstruct)
  { }
AstModuleItem::AstModuleItem(AstInitialConstructHandle pInitialConstruct)
  : _pInitialConstruct(pInitialConstruct)
  { }
AstModuleItem::AstModuleItem(AstModuleItemDeclarationHandle pModuleItemDeclaration)
  : _pModuleItemDeclaration(pModuleItemDeclaration)
  { }
AstModuleItem::AstModuleItem(AstContinuousAssignHandle pContinuousAssign)
  : _pContinuousAssign(pContinuousAssign)
  { }
AstModuleItem::AstModuleItem(AstGateInstantiationHandle pGateInstantiation)
  : _pGateInstantiation(pGateInstantiation)
  { }
AstModuleItem::AstModuleItem(AstModuleInstantiationHandle pModuleInstantiation)
  : _pModuleInstantiation(pModuleInstantiation)
  { }
AstAlwaysConstructHandle AstModuleItem::always_construct() const
  { return _pAlwaysConstruct; }
AstInitialConstructHandle AstModuleItem::initial_construct() const
  { return _pInitialConstruct; }
AstModuleItemDeclarationHandle AstModuleItem::module_item_declaration() const
  { return _pModuleItemDeclaration; }
AstContinuousAssignHandle AstModuleItem::continuous_assign() const
  { return _pContinuousAssign; }
AstGateInstantiationHandle AstModuleItem::gate_instantiation() const
  { return _pGateInstantiation; }
AstModuleInstantiationHandle AstModuleItem::module_instantiation() const
  { return _pModuleInstantiation; }
std::string AstModuleItem::toString() const {
    std::string s = "(module_item";
    if (always_construct().valid())
        s = s + " " + always_construct()->toString();
    if (initial_construct().valid())
        s = s + " " + initial_construct()->toString();
    if (module_item_declaration().valid())
        s = s + " " + module_item_declaration()->toString();
    if (continuous_assign().valid())
        s = s + " " + continuous_assign()->toString();
    if (gate_instantiation().valid())
        s = s + " " + gate_instantiation()->toString();
    if (module_instantiation().valid())
        s = s + " " + module_instantiation()->toString();
        s += ")";    return s;
}
AstKeywordBegin::AstKeywordBegin(const std::string & s)
  : _keyword_begin(s)
  { }
std::string AstKeywordBegin::keyword_begin() const
  { return _keyword_begin; }
std::string AstKeywordBegin::toString() const
  { return "(keyword_begin " + keyword_begin() + ")";}
AstKeywordAlways::AstKeywordAlways(const std::string & s)
  : _keyword_always(s)
  { }
std::string AstKeywordAlways::keyword_always() const
  { return _keyword_always; }
std::string AstKeywordAlways::toString() const
  { return "(keyword_always " + keyword_always() + ")";}
AstCaseItemDefault::AstCaseItemDefault() { }
void AstCaseItemDefault::push_back(AstKeywordDefaultHandle pKeywordDefault0, AstStatementOrNullHandle pStatementOrNull1) {
    _vecElements.push_back(ElementType(pKeywordDefault0, pStatementOrNull1));
}
std::vector<AstCaseItemDefault::ElementType>& AstCaseItemDefault::container() {
    return _vecElements;
}
const std::vector<AstCaseItemDefault::ElementType>& AstCaseItemDefault::container() const {
    return _vecElements;
}
AstCaseItemDefault::ElementType AstCaseItemDefault::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstCaseItemDefault::element_size() const
  { return _vecElements.size(); }
std::string AstCaseItemDefault::toString() const {
    std::string s = "(case_item_default";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordDefault0->toString();
        s = s + " " + _vecElements[i]._pStatementOrNull1->toString();
    }
        s += ")";    return s;
}
AstBlockingAssingmentSemicolon::AstBlockingAssingmentSemicolon() { }
void AstBlockingAssingmentSemicolon::push_back(AstBlockingAssignmentHandle pBlockingAssignment0) {
    _vecElements.push_back(ElementType(pBlockingAssignment0));
}
std::vector<AstBlockingAssingmentSemicolon::ElementType>& AstBlockingAssingmentSemicolon::container() {
    return _vecElements;
}
const std::vector<AstBlockingAssingmentSemicolon::ElementType>& AstBlockingAssingmentSemicolon::container() const {
    return _vecElements;
}
AstBlockingAssingmentSemicolon::ElementType AstBlockingAssingmentSemicolon::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBlockingAssingmentSemicolon::element_size() const
  { return _vecElements.size(); }
std::string AstBlockingAssingmentSemicolon::toString() const {
    std::string s = "(blocking_assignment_semicolon";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBlockingAssignment0->toString();
    }
        s += ")";    return s;
}
AstKeywordFor::AstKeywordFor(const std::string & s)
  : _keyword_for(s)
  { }
std::string AstKeywordFor::keyword_for() const
  { return _keyword_for; }
std::string AstKeywordFor::toString() const
  { return "(keyword_for " + keyword_for() + ")";}
AstZeroOrMoreCommaPortReference::AstZeroOrMoreCommaPortReference() { }
void AstZeroOrMoreCommaPortReference::push_back(AstPortReferenceHandle pPortReference) {
    _vecElements.push_back(ElementType(pPortReference));
}
std::vector<AstZeroOrMoreCommaPortReference::ElementType>& AstZeroOrMoreCommaPortReference::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaPortReference::ElementType>& AstZeroOrMoreCommaPortReference::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaPortReference::ElementType AstZeroOrMoreCommaPortReference::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaPortReference::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaPortReference::toString() const {
    std::string s = "(zero_or_more_comma_port_reference";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pPortReference->toString();
    }
        s += ")";    return s;
}
AstRangeSelect::AstRangeSelect() { }
void AstRangeSelect::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstRangeSelect::ElementType>& AstRangeSelect::container() {
    return _vecElements;
}
const std::vector<AstRangeSelect::ElementType>& AstRangeSelect::container() const {
    return _vecElements;
}
AstRangeSelect::ElementType AstRangeSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstRangeSelect::element_size() const
  { return _vecElements.size(); }
std::string AstRangeSelect::toString() const {
    std::string s = "(range_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaIdentifier::AstZeroOrMoreCommaIdentifier() { }
void AstZeroOrMoreCommaIdentifier::push_back(AstIdentifierHandle pIdentifier) {
    _vecElements.push_back(ElementType(pIdentifier));
}
std::vector<AstZeroOrMoreCommaIdentifier::ElementType>& AstZeroOrMoreCommaIdentifier::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaIdentifier::ElementType>& AstZeroOrMoreCommaIdentifier::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaIdentifier::ElementType AstZeroOrMoreCommaIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaIdentifier::toString() const {
    std::string s = "(zero_or_more_comma_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionShiftLeft::AstBinaryConstantExpressionShiftLeft() { }
void AstBinaryConstantExpressionShiftLeft::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionShiftLeft::ElementType>& AstBinaryConstantExpressionShiftLeft::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionShiftLeft::ElementType>& AstBinaryConstantExpressionShiftLeft::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionShiftLeft::ElementType AstBinaryConstantExpressionShiftLeft::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionShiftLeft::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionShiftLeft::toString() const {
    std::string s = "(binary_constant_expression_shift_left";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstTernaryConstantExpression::AstTernaryConstantExpression() { }
void AstTernaryConstantExpression::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1, pConstantExpression2));
}
std::vector<AstTernaryConstantExpression::ElementType>& AstTernaryConstantExpression::container() {
    return _vecElements;
}
const std::vector<AstTernaryConstantExpression::ElementType>& AstTernaryConstantExpression::container() const {
    return _vecElements;
}
AstTernaryConstantExpression::ElementType AstTernaryConstantExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstTernaryConstantExpression::element_size() const
  { return _vecElements.size(); }
std::string AstTernaryConstantExpression::toString() const {
    std::string s = "(ternary_constant_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
        s = s + " " + _vecElements[i]._pConstantExpression2->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorMinus::AstUnaryOperatorMinus() { }
void AstUnaryOperatorMinus::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorMinus::ElementType>& AstUnaryOperatorMinus::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorMinus::ElementType>& AstUnaryOperatorMinus::container() const {
    return _vecElements;
}
AstUnaryOperatorMinus::ElementType AstUnaryOperatorMinus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorMinus::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorMinus::toString() const {
    std::string s = "(unary_operator_minus";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstInputDeclaration::AstInputDeclaration() { }
void AstInputDeclaration::push_back(AstKeywordInputHandle pKeywordInput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
    _vecElements.push_back(ElementType(pKeywordInput0, pZeroOrOneRange1, pListOfPortIdentifiers2));
}
std::vector<AstInputDeclaration::ElementType>& AstInputDeclaration::container() {
    return _vecElements;
}
const std::vector<AstInputDeclaration::ElementType>& AstInputDeclaration::container() const {
    return _vecElements;
}
AstInputDeclaration::ElementType AstInputDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstInputDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstInputDeclaration::toString() const {
    std::string s = "(input_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordInput0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
        s = s + " " + _vecElements[i]._pListOfPortIdentifiers2->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaNInputGateInstance::AstZeroOrMoreCommaNInputGateInstance() { }
void AstZeroOrMoreCommaNInputGateInstance::push_back(AstNInputGateInstanceHandle pNInputGateInstance) {
    _vecElements.push_back(ElementType(pNInputGateInstance));
}
std::vector<AstZeroOrMoreCommaNInputGateInstance::ElementType>& AstZeroOrMoreCommaNInputGateInstance::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaNInputGateInstance::ElementType>& AstZeroOrMoreCommaNInputGateInstance::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaNInputGateInstance::ElementType AstZeroOrMoreCommaNInputGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaNInputGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaNInputGateInstance::toString() const {
    std::string s = "(zero_or_more_comma_n_input_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNInputGateInstance->toString();
    }
        s += ")";    return s;
}
BracedConstantExpression::BracedConstantExpression() { }
void BracedConstantExpression::push_back(AstConstantExpressionHandle pConstantExpression0) {
    _vecElements.push_back(ElementType(pConstantExpression0));
}
std::vector<BracedConstantExpression::ElementType>& BracedConstantExpression::container() {
    return _vecElements;
}
const std::vector<BracedConstantExpression::ElementType>& BracedConstantExpression::container() const {
    return _vecElements;
}
BracedConstantExpression::ElementType BracedConstantExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int BracedConstantExpression::element_size() const
  { return _vecElements.size(); }
std::string BracedConstantExpression::toString() const {
    std::string s = "(braced_constant_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
    }
        s += ")";    return s;
}
AstKeywordWire::AstKeywordWire(const std::string & s)
  : _keyword_wire(s)
  { }
std::string AstKeywordWire::keyword_wire() const
  { return _keyword_wire; }
std::string AstKeywordWire::toString() const
  { return "(keyword_wire " + keyword_wire() + ")";}
AstSimpleIdentifier::AstSimpleIdentifier(const std::string & s)
  : _simple_identifier(s)
  { }
std::string AstSimpleIdentifier::simple_identifier() const
  { return _simple_identifier; }
std::string AstSimpleIdentifier::toString() const
  { return "(simple_identifier " + simple_identifier() + ")";}
AstUnsignedNumber::AstUnsignedNumber(const std::string & s)
  : _unsigned_number(s)
  { }
std::string AstUnsignedNumber::unsigned_number() const
  { return _unsigned_number; }
std::string AstUnsignedNumber::toString() const
  { return "(unsigned_number " + unsigned_number() + ")";}
AstKeywordEnd::AstKeywordEnd(const std::string & s)
  : _keyword_end(s)
  { }
std::string AstKeywordEnd::keyword_end() const
  { return _keyword_end; }
std::string AstKeywordEnd::toString() const
  { return "(keyword_end " + keyword_end() + ")";}
AstSelectIdentifier::AstSelectIdentifier() { }
void AstSelectIdentifier::push_back(AstIdentifierHandle pIdentifier0, AstOneOrMoreSelectHandle pOneOrMoreSelect1) {
    _vecElements.push_back(ElementType(pIdentifier0, pOneOrMoreSelect1));
}
std::vector<AstSelectIdentifier::ElementType>& AstSelectIdentifier::container() {
    return _vecElements;
}
const std::vector<AstSelectIdentifier::ElementType>& AstSelectIdentifier::container() const {
    return _vecElements;
}
AstSelectIdentifier::ElementType AstSelectIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstSelectIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstSelectIdentifier::toString() const {
    std::string s = "(select_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pOneOrMoreSelect1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionEq::AstBinaryExpressionEq() { }
void AstBinaryExpressionEq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionEq::ElementType>& AstBinaryExpressionEq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionEq::ElementType>& AstBinaryExpressionEq::container() const {
    return _vecElements;
}
AstBinaryExpressionEq::ElementType AstBinaryExpressionEq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionEq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionEq::toString() const {
    std::string s = "(binary_expression_eq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorPlus::AstUnaryOperatorPlus() { }
void AstUnaryOperatorPlus::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorPlus::ElementType>& AstUnaryOperatorPlus::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorPlus::ElementType>& AstUnaryOperatorPlus::container() const {
    return _vecElements;
}
AstUnaryOperatorPlus::ElementType AstUnaryOperatorPlus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorPlus::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorPlus::toString() const {
    std::string s = "(unary_operator_plus";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstConstantRangeSelect::AstConstantRangeSelect() { }
void AstConstantRangeSelect::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstConstantRangeSelect::ElementType>& AstConstantRangeSelect::container() {
    return _vecElements;
}
const std::vector<AstConstantRangeSelect::ElementType>& AstConstantRangeSelect::container() const {
    return _vecElements;
}
AstConstantRangeSelect::ElementType AstConstantRangeSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConstantRangeSelect::element_size() const
  { return _vecElements.size(); }
std::string AstConstantRangeSelect::toString() const {
    std::string s = "(constant_range_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstNetAssignment::AstNetAssignment() { }
void AstNetAssignment::push_back(AstNetLvalueHandle pNetLvalue0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pNetLvalue0, pExpression1));
}
std::vector<AstNetAssignment::ElementType>& AstNetAssignment::container() {
    return _vecElements;
}
const std::vector<AstNetAssignment::ElementType>& AstNetAssignment::container() const {
    return _vecElements;
}
AstNetAssignment::ElementType AstNetAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNetAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstNetAssignment::toString() const {
    std::string s = "(net_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNetLvalue0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionBwXor::AstBinaryExpressionBwXor() { }
void AstBinaryExpressionBwXor::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionBwXor::ElementType>& AstBinaryExpressionBwXor::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionBwXor::ElementType>& AstBinaryExpressionBwXor::container() const {
    return _vecElements;
}
AstBinaryExpressionBwXor::ElementType AstBinaryExpressionBwXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionBwXor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionBwXor::toString() const {
    std::string s = "(binary_expression_bw_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorXorNeg::AstUnaryOperatorXorNeg() { }
void AstUnaryOperatorXorNeg::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorXorNeg::ElementType>& AstUnaryOperatorXorNeg::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorXorNeg::ElementType>& AstUnaryOperatorXorNeg::container() const {
    return _vecElements;
}
AstUnaryOperatorXorNeg::ElementType AstUnaryOperatorXorNeg::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorXorNeg::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorXorNeg::toString() const {
    std::string s = "(unary_operator_xor_neg";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstModuleInstance::AstModuleInstance() { }
void AstModuleInstance::push_back(AstNameOfInstanceHandle pNameOfInstance0, AstListOfModuleConnectionsHandle pListOfModuleConnections1) {
    _vecElements.push_back(ElementType(pNameOfInstance0, pListOfModuleConnections1));
}
std::vector<AstModuleInstance::ElementType>& AstModuleInstance::container() {
    return _vecElements;
}
const std::vector<AstModuleInstance::ElementType>& AstModuleInstance::container() const {
    return _vecElements;
}
AstModuleInstance::ElementType AstModuleInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstModuleInstance::element_size() const
  { return _vecElements.size(); }
std::string AstModuleInstance::toString() const {
    std::string s = "(module_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNameOfInstance0->toString();
        s = s + " " + _vecElements[i]._pListOfModuleConnections1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorNotEqualEqual::AstBinaryOperatorNotEqualEqual() { }
void AstBinaryOperatorNotEqualEqual::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorNotEqualEqual::ElementType>& AstBinaryOperatorNotEqualEqual::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorNotEqualEqual::ElementType>& AstBinaryOperatorNotEqualEqual::container() const {
    return _vecElements;
}
AstBinaryOperatorNotEqualEqual::ElementType AstBinaryOperatorNotEqualEqual::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorNotEqualEqual::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorNotEqualEqual::toString() const {
    std::string s = "(binary_operator_not_equal_equal";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstProceduralContinuousAssignmentSemicolon::AstProceduralContinuousAssignmentSemicolon() { }
void AstProceduralContinuousAssignmentSemicolon::push_back(AstProceduralContinuousAssignmentHandle pProceduralContinuousAssignment0) {
    _vecElements.push_back(ElementType(pProceduralContinuousAssignment0));
}
std::vector<AstProceduralContinuousAssignmentSemicolon::ElementType>& AstProceduralContinuousAssignmentSemicolon::container() {
    return _vecElements;
}
const std::vector<AstProceduralContinuousAssignmentSemicolon::ElementType>& AstProceduralContinuousAssignmentSemicolon::container() const {
    return _vecElements;
}
AstProceduralContinuousAssignmentSemicolon::ElementType AstProceduralContinuousAssignmentSemicolon::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstProceduralContinuousAssignmentSemicolon::element_size() const
  { return _vecElements.size(); }
std::string AstProceduralContinuousAssignmentSemicolon::toString() const {
    std::string s = "(procedural_continuous_assignment_semicolon";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pProceduralContinuousAssignment0->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorPlus::AstBinaryOperatorPlus() { }
void AstBinaryOperatorPlus::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorPlus::ElementType>& AstBinaryOperatorPlus::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorPlus::ElementType>& AstBinaryOperatorPlus::container() const {
    return _vecElements;
}
AstBinaryOperatorPlus::ElementType AstBinaryOperatorPlus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorPlus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorPlus::toString() const {
    std::string s = "(binary_operator_plus";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstEventControl::AstEventControl(AstAtIdentifierHandle pAtIdentifier)
  : _pAtIdentifier(pAtIdentifier)
  { }
AstEventControl::AstEventControl(AstAtEventExpressionHandle pAstEventExpression)
  : _pAstEventExpression(pAstEventExpression)
  { }
AstEventControl::AstEventControl(AstAtAsteriskHandle pAtAsterisk)
  : _pAtAsterisk(pAtAsterisk)
  { }
AstAtIdentifierHandle AstEventControl::at_identifier() const
  { return _pAtIdentifier; }
AstAtEventExpressionHandle AstEventControl::at_event_expression() const
  { return _pAstEventExpression; }
AstAtAsteriskHandle AstEventControl::at_asterisk() const
  { return _pAtAsterisk; }
std::string AstEventControl::toString() const {
    std::string s = "(event_control";
    if (at_identifier().valid())
        s = s + " " + at_identifier()->toString();
    if (at_event_expression().valid())
        s = s + " " + at_event_expression()->toString();
    if (at_asterisk().valid())
        s = s + " " + at_asterisk()->toString();
        s += ")";    return s;
}
AstZeroOrOneRange::AstZeroOrOneRange() { }
void AstZeroOrOneRange::push_back(AstRangeHandle pRange) {
    _vecElements.push_back(ElementType(pRange));
}
std::vector<AstZeroOrOneRange::ElementType>& AstZeroOrOneRange::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneRange::ElementType>& AstZeroOrOneRange::container() const {
    return _vecElements;
}
AstZeroOrOneRange::ElementType AstZeroOrOneRange::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneRange::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneRange::toString() const {
    std::string s = "(zero_or_one_range";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRange->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionNeq::AstBinaryExpressionNeq() { }
void AstBinaryExpressionNeq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionNeq::ElementType>& AstBinaryExpressionNeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionNeq::ElementType>& AstBinaryExpressionNeq::container() const {
    return _vecElements;
}
AstBinaryExpressionNeq::ElementType AstBinaryExpressionNeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionNeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionNeq::toString() const {
    std::string s = "(binary_expression_neq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstStatementOrNull::AstStatementOrNull(AstStatementHandle pStatement)
  : _pStatement(pStatement)
  { }
AstStatementHandle AstStatementOrNull::statement() const
  { return _pStatement; }
std::string AstStatementOrNull::toString() const {
    std::string s = "(statement_or_null";
    if (statement().valid())
        s = s + " " + statement()->toString();
        s += ")";    return s;
}
AstLoopStatement::AstLoopStatement() { }
void AstLoopStatement::push_back(AstKeywordForHandle pKeywordFor0, AstRegAssignmentHandle pRegAssignment1, AstExpressionHandle pExpression2, AstRegAssignmentHandle pRegAssignment3, AstStatementHandle pStatement4) {
    _vecElements.push_back(ElementType(pKeywordFor0, pRegAssignment1, pExpression2, pRegAssignment3, pStatement4));
}
std::vector<AstLoopStatement::ElementType>& AstLoopStatement::container() {
    return _vecElements;
}
const std::vector<AstLoopStatement::ElementType>& AstLoopStatement::container() const {
    return _vecElements;
}
AstLoopStatement::ElementType AstLoopStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstLoopStatement::element_size() const
  { return _vecElements.size(); }
std::string AstLoopStatement::toString() const {
    std::string s = "(loop_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordFor0->toString();
        s = s + " " + _vecElements[i]._pRegAssignment1->toString();
        s = s + " " + _vecElements[i]._pExpression2->toString();
        s = s + " " + _vecElements[i]._pRegAssignment3->toString();
        s = s + " " + _vecElements[i]._pStatement4->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionBwAnd::AstBinaryConstantExpressionBwAnd() { }
void AstBinaryConstantExpressionBwAnd::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionBwAnd::ElementType>& AstBinaryConstantExpressionBwAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionBwAnd::ElementType>& AstBinaryConstantExpressionBwAnd::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionBwAnd::ElementType AstBinaryConstantExpressionBwAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionBwAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionBwAnd::toString() const {
    std::string s = "(binary_constant_expression_bw_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstNInputGateType::AstNInputGateType(const std::string & s)
  : _n_input_gatetype(s)
  { }
std::string AstNInputGateType::n_input_gatetype() const
  { return _n_input_gatetype; }
std::string AstNInputGateType::toString() const
  { return "(n_input_gatetype " + n_input_gatetype() + ")";}
AstKeywordModule::AstKeywordModule(const std::string & s)
  : _keyword_module(s)
  { }
std::string AstKeywordModule::keyword_module() const
  { return _keyword_module; }
std::string AstKeywordModule::toString() const
  { return "(keyword_module " + keyword_module() + ")";}
AstKeywordOr::AstKeywordOr(const std::string & s)
  : _keyword_or(s)
  { }
std::string AstKeywordOr::keyword_or() const
  { return _keyword_or; }
std::string AstKeywordOr::toString() const
  { return "(keyword_or " + keyword_or() + ")";}
AstConstantBitSelect::AstConstantBitSelect() { }
void AstConstantBitSelect::push_back(AstConstantExpressionHandle pConstantExpression0) {
    _vecElements.push_back(ElementType(pConstantExpression0));
}
std::vector<AstConstantBitSelect::ElementType>& AstConstantBitSelect::container() {
    return _vecElements;
}
const std::vector<AstConstantBitSelect::ElementType>& AstConstantBitSelect::container() const {
    return _vecElements;
}
AstConstantBitSelect::ElementType AstConstantBitSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConstantBitSelect::element_size() const
  { return _vecElements.size(); }
std::string AstConstantBitSelect::toString() const {
    std::string s = "(constant_bit_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
    }
        s += ")";    return s;
}
AstListOfParamAssignment::AstListOfParamAssignment() { }
void AstListOfParamAssignment::push_back(AstParamAssignmentHandle pParamAssignment0, AstZeroOrMoreCommaParamAssignmentHandle pZeroOrMoreCommaParamAssignment1) {
    _vecElements.push_back(ElementType(pParamAssignment0, pZeroOrMoreCommaParamAssignment1));
}
std::vector<AstListOfParamAssignment::ElementType>& AstListOfParamAssignment::container() {
    return _vecElements;
}
const std::vector<AstListOfParamAssignment::ElementType>& AstListOfParamAssignment::container() const {
    return _vecElements;
}
AstListOfParamAssignment::ElementType AstListOfParamAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfParamAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstListOfParamAssignment::toString() const {
    std::string s = "(list_of_param_assignments";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pParamAssignment0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaParamAssignment1->toString();
    }
        s += ")";    return s;
}
AstGateInstantiationInput::AstGateInstantiationInput() { }
void AstGateInstantiationInput::push_back(AstNInputGateTypeHandle pNInputGateType0, AstNInputGateInstanceHandle pNInputGateInstance1, AstZeroOrMoreCommaNInputGateInstanceHandle pZeroOrMoreCommaNInputGateInstance2) {
    _vecElements.push_back(ElementType(pNInputGateType0, pNInputGateInstance1, pZeroOrMoreCommaNInputGateInstance2));
}
std::vector<AstGateInstantiationInput::ElementType>& AstGateInstantiationInput::container() {
    return _vecElements;
}
const std::vector<AstGateInstantiationInput::ElementType>& AstGateInstantiationInput::container() const {
    return _vecElements;
}
AstGateInstantiationInput::ElementType AstGateInstantiationInput::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstGateInstantiationInput::element_size() const
  { return _vecElements.size(); }
std::string AstGateInstantiationInput::toString() const {
    std::string s = "(gate_instantiation_input";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNInputGateType0->toString();
        s = s + " " + _vecElements[i]._pNInputGateInstance1->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaNInputGateInstance2->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreModuleItem::AstZeroOrMoreModuleItem() { }
void AstZeroOrMoreModuleItem::push_back(AstModuleItemHandle pModuleItem) {
    _vecElements.push_back(ElementType(pModuleItem));
}
std::vector<AstZeroOrMoreModuleItem::ElementType>& AstZeroOrMoreModuleItem::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreModuleItem::ElementType>& AstZeroOrMoreModuleItem::container() const {
    return _vecElements;
}
AstZeroOrMoreModuleItem::ElementType AstZeroOrMoreModuleItem::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreModuleItem::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreModuleItem::toString() const {
    std::string s = "(zero_or_more_module_item";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pModuleItem->toString();
    }
        s += ")";    return s;
}
AstParameterDeclaration::AstParameterDeclaration() { }
void AstParameterDeclaration::push_back(AstKeywordParameterHandle pKeywordParameter0, AstListOfParamAssignmentHandle pListOfParamAssignment1) {
    _vecElements.push_back(ElementType(pKeywordParameter0, pListOfParamAssignment1));
}
std::vector<AstParameterDeclaration::ElementType>& AstParameterDeclaration::container() {
    return _vecElements;
}
const std::vector<AstParameterDeclaration::ElementType>& AstParameterDeclaration::container() const {
    return _vecElements;
}
AstParameterDeclaration::ElementType AstParameterDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstParameterDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstParameterDeclaration::toString() const {
    std::string s = "(parameter_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordParameter0->toString();
        s = s + " " + _vecElements[i]._pListOfParamAssignment1->toString();
    }
        s += ")";    return s;
}
AstOneOrMoreSelect::AstOneOrMoreSelect() { }
void AstOneOrMoreSelect::push_back(AstSelectHandle pSelect0) {
    _vecElements.push_back(ElementType(pSelect0));
}
std::vector<AstOneOrMoreSelect::ElementType>& AstOneOrMoreSelect::container() {
    return _vecElements;
}
const std::vector<AstOneOrMoreSelect::ElementType>& AstOneOrMoreSelect::container() const {
    return _vecElements;
}
AstOneOrMoreSelect::ElementType AstOneOrMoreSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOneOrMoreSelect::element_size() const
  { return _vecElements.size(); }
std::string AstOneOrMoreSelect::toString() const {
    std::string s = "(one_or_more_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pSelect0->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionLt::AstBinaryConstantExpressionLt() { }
void AstBinaryConstantExpressionLt::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionLt::ElementType>& AstBinaryConstantExpressionLt::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionLt::ElementType>& AstBinaryConstantExpressionLt::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionLt::ElementType AstBinaryConstantExpressionLt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionLt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionLt::toString() const {
    std::string s = "(binary_constant_expression_lt";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstKeywordInteger::AstKeywordInteger(const std::string & s)
  : _keyword_integer(s)
  { }
std::string AstKeywordInteger::keyword_integer() const
  { return _keyword_integer; }
std::string AstKeywordInteger::toString() const
  { return "(keyword_integer " + keyword_integer() + ")";}
AstKeywordEndCase::AstKeywordEndCase(const std::string & s)
  : _keyword_endcase(s)
  { }
std::string AstKeywordEndCase::keyword_endcase() const
  { return _keyword_endcase; }
std::string AstKeywordEndCase::toString() const
  { return "(keyword_endcase " + keyword_endcase() + ")";}
AstZeroOrMoreCommaOrderedPortConnection::AstZeroOrMoreCommaOrderedPortConnection() { }
void AstZeroOrMoreCommaOrderedPortConnection::push_back(AstOrderedPortConnectionHandle pOrderedPortConnection) {
    _vecElements.push_back(ElementType(pOrderedPortConnection));
}
std::vector<AstZeroOrMoreCommaOrderedPortConnection::ElementType>& AstZeroOrMoreCommaOrderedPortConnection::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaOrderedPortConnection::ElementType>& AstZeroOrMoreCommaOrderedPortConnection::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaOrderedPortConnection::ElementType AstZeroOrMoreCommaOrderedPortConnection::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaOrderedPortConnection::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaOrderedPortConnection::toString() const {
    std::string s = "(zero_or_more_comma_ordered_port_connection";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pOrderedPortConnection->toString();
    }
        s += ")";    return s;
}
AstEventOrAsterisk::AstEventOrAsterisk(AstEventExpressionHandle pEventExpression)
  : _pEventExpression(pEventExpression)
  { }
AstEventExpressionHandle AstEventOrAsterisk::event_expression() const
  { return _pEventExpression; }
std::string AstEventOrAsterisk::toString() const {
    std::string s = "(event_or_asterisk";
    if (event_expression().valid())
        s = s + " " + event_expression()->toString();
        s += ")";    return s;
}
AstBinaryOperatorShr::AstBinaryOperatorShr() { }
void AstBinaryOperatorShr::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorShr::ElementType>& AstBinaryOperatorShr::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorShr::ElementType>& AstBinaryOperatorShr::container() const {
    return _vecElements;
}
AstBinaryOperatorShr::ElementType AstBinaryOperatorShr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorShr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorShr::toString() const {
    std::string s = "(binary_operator_shr";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstUnaryOperatorNeg::AstUnaryOperatorNeg() { }
void AstUnaryOperatorNeg::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorNeg::ElementType>& AstUnaryOperatorNeg::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorNeg::ElementType>& AstUnaryOperatorNeg::container() const {
    return _vecElements;
}
AstUnaryOperatorNeg::ElementType AstUnaryOperatorNeg::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorNeg::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorNeg::toString() const {
    std::string s = "(unary_operator_neg";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstUnaryConstantExpression::AstUnaryConstantExpression() { }
void AstUnaryConstantExpression::push_back(AstUnaryOperatorHandle pUnaryOperator0, AstConstantPrimaryHandle pConstantPrimary1) {
    _vecElements.push_back(ElementType(pUnaryOperator0, pConstantPrimary1));
}
std::vector<AstUnaryConstantExpression::ElementType>& AstUnaryConstantExpression::container() {
    return _vecElements;
}
const std::vector<AstUnaryConstantExpression::ElementType>& AstUnaryConstantExpression::container() const {
    return _vecElements;
}
AstUnaryConstantExpression::ElementType AstUnaryConstantExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryConstantExpression::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryConstantExpression::toString() const {
    std::string s = "(unary_constant_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pUnaryOperator0->toString();
        s = s + " " + _vecElements[i]._pConstantPrimary1->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaInputTerminal::AstZeroOrMoreCommaInputTerminal() { }
void AstZeroOrMoreCommaInputTerminal::push_back(AstInputTerminalHandle pInputTerminal) {
    _vecElements.push_back(ElementType(pInputTerminal));
}
std::vector<AstZeroOrMoreCommaInputTerminal::ElementType>& AstZeroOrMoreCommaInputTerminal::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaInputTerminal::ElementType>& AstZeroOrMoreCommaInputTerminal::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaInputTerminal::ElementType AstZeroOrMoreCommaInputTerminal::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaInputTerminal::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaInputTerminal::toString() const {
    std::string s = "(zero_or_more_comma_input_terminal";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pInputTerminal->toString();
    }
        s += ")";    return s;
}
AstNegedgeExpression::AstNegedgeExpression() { }
void AstNegedgeExpression::push_back(AstKetwordNegedgeHandle pKeywordNegedge0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pKeywordNegedge0, pExpression1));
}
std::vector<AstNegedgeExpression::ElementType>& AstNegedgeExpression::container() {
    return _vecElements;
}
const std::vector<AstNegedgeExpression::ElementType>& AstNegedgeExpression::container() const {
    return _vecElements;
}
AstNegedgeExpression::ElementType AstNegedgeExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNegedgeExpression::element_size() const
  { return _vecElements.size(); }
std::string AstNegedgeExpression::toString() const {
    std::string s = "(negedge_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordNegedge0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstRegDeclaration::AstRegDeclaration() { }
void AstRegDeclaration::push_back(AstKeywordRegHandle pKeywordReg0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers2) {
    _vecElements.push_back(ElementType(pKeywordReg0, pZeroOrOneRange1, pListOfRegisterIdentifiers2));
}
std::vector<AstRegDeclaration::ElementType>& AstRegDeclaration::container() {
    return _vecElements;
}
const std::vector<AstRegDeclaration::ElementType>& AstRegDeclaration::container() const {
    return _vecElements;
}
AstRegDeclaration::ElementType AstRegDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstRegDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstRegDeclaration::toString() const {
    std::string s = "(reg_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordReg0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
        s = s + " " + _vecElements[i]._pListOfRegisterIdentifiers2->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionLgAnd::AstBinaryConstantExpressionLgAnd() { }
void AstBinaryConstantExpressionLgAnd::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionLgAnd::ElementType>& AstBinaryConstantExpressionLgAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionLgAnd::ElementType>& AstBinaryConstantExpressionLgAnd::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionLgAnd::ElementType AstBinaryConstantExpressionLgAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionLgAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionLgAnd::toString() const {
    std::string s = "(binary_constant_expression_lg_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstOneOrMoreCaseItem::AstOneOrMoreCaseItem() { }
void AstOneOrMoreCaseItem::push_back(AstCaseItemHandle pCaseItem0) {
    _vecElements.push_back(ElementType(pCaseItem0));
}
std::vector<AstOneOrMoreCaseItem::ElementType>& AstOneOrMoreCaseItem::container() {
    return _vecElements;
}
const std::vector<AstOneOrMoreCaseItem::ElementType>& AstOneOrMoreCaseItem::container() const {
    return _vecElements;
}
AstOneOrMoreCaseItem::ElementType AstOneOrMoreCaseItem::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOneOrMoreCaseItem::element_size() const
  { return _vecElements.size(); }
std::string AstOneOrMoreCaseItem::toString() const {
    std::string s = "(one_or_more_case_item";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pCaseItem0->toString();
    }
        s += ")";    return s;
}
AstKeywordInitial::AstKeywordInitial(const std::string & s)
  : _keyword_initial(s)
  { }
std::string AstKeywordInitial::keyword_initial() const
  { return _keyword_initial; }
std::string AstKeywordInitial::toString() const
  { return "(keyword_initial " + keyword_initial() + ")";}
AstBinaryExpressionBwNxor::AstBinaryExpressionBwNxor() { }
void AstBinaryExpressionBwNxor::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionBwNxor::ElementType>& AstBinaryExpressionBwNxor::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionBwNxor::ElementType>& AstBinaryExpressionBwNxor::container() const {
    return _vecElements;
}
AstBinaryExpressionBwNxor::ElementType AstBinaryExpressionBwNxor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionBwNxor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionBwNxor::toString() const {
    std::string s = "(binary_expression_bw_nxor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstListOfNetAssignments::AstListOfNetAssignments() { }
void AstListOfNetAssignments::push_back(AstNetAssignmentHandle pNetAssignment0, AstZeroOrMoreCommaNetAssignmentHandle pZeroOrMoreCommaNetAssignment1) {
    _vecElements.push_back(ElementType(pNetAssignment0, pZeroOrMoreCommaNetAssignment1));
}
std::vector<AstListOfNetAssignments::ElementType>& AstListOfNetAssignments::container() {
    return _vecElements;
}
const std::vector<AstListOfNetAssignments::ElementType>& AstListOfNetAssignments::container() const {
    return _vecElements;
}
AstListOfNetAssignments::ElementType AstListOfNetAssignments::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfNetAssignments::element_size() const
  { return _vecElements.size(); }
std::string AstListOfNetAssignments::toString() const {
    std::string s = "(list_of_net_assignments";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNetAssignment0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaNetAssignment1->toString();
    }
        s += ")";    return s;
}
AstSingleIdentifier::AstSingleIdentifier(AstSimpleIdentifierHandle pSimpleIdentifier)
  : _pSimpleIdentifier(pSimpleIdentifier)
  { }
AstSimpleIdentifierHandle AstSingleIdentifier::simple_identifier() const
  { return _pSimpleIdentifier; }
std::string AstSingleIdentifier::toString() const {
    std::string s = "(single_identifier";
    if (simple_identifier().valid())
        s = s + " " + simple_identifier()->toString();
        s += ")";    return s;
}
AstConstantExpression::AstConstantExpression(BracedConstantExpressionHandle pBracedConstantExpression)
  : _pBracedConstantExpression(pBracedConstantExpression)
  { }
AstConstantExpression::AstConstantExpression(AstConstantPrimaryHandle pConstantPrimary)
  : _pConstantPrimary(pConstantPrimary)
  { }
AstConstantExpression::AstConstantExpression(AstUnaryConstantExpressionHandle pUnaryConstantExpression)
  : _pUnaryConstantExpression(pUnaryConstantExpression)
  { }
AstConstantExpression::AstConstantExpression(AstTernaryConstantExpressionHandle pTernaryConstantExpression)
  : _pTernaryConstantExpression(pTernaryConstantExpression)
  { }
AstConstantExpression::AstConstantExpression(AstBinaryConstantExpressionHandle pBinaryConstantExpression)
  : _pBinaryConstantExpression(pBinaryConstantExpression)
  { }
BracedConstantExpressionHandle AstConstantExpression::braced_constant_expression() const
  { return _pBracedConstantExpression; }
AstConstantPrimaryHandle AstConstantExpression::constant_primary() const
  { return _pConstantPrimary; }
AstUnaryConstantExpressionHandle AstConstantExpression::unary_constant_expression() const
  { return _pUnaryConstantExpression; }
AstTernaryConstantExpressionHandle AstConstantExpression::ternary_constant_expression() const
  { return _pTernaryConstantExpression; }
AstBinaryConstantExpressionHandle AstConstantExpression::binary_constant_expression() const
  { return _pBinaryConstantExpression; }
std::string AstConstantExpression::toString() const {
    std::string s = "(constant_expression";
    if (braced_constant_expression().valid())
        s = s + " " + braced_constant_expression()->toString();
    if (constant_primary().valid())
        s = s + " " + constant_primary()->toString();
    if (unary_constant_expression().valid())
        s = s + " " + unary_constant_expression()->toString();
    if (ternary_constant_expression().valid())
        s = s + " " + ternary_constant_expression()->toString();
    if (binary_constant_expression().valid())
        s = s + " " + binary_constant_expression()->toString();
        s += ")";    return s;
}
AstBinaryConstantExpressionMultiply::AstBinaryConstantExpressionMultiply() { }
void AstBinaryConstantExpressionMultiply::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionMultiply::ElementType>& AstBinaryConstantExpressionMultiply::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionMultiply::ElementType>& AstBinaryConstantExpressionMultiply::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionMultiply::ElementType AstBinaryConstantExpressionMultiply::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionMultiply::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionMultiply::toString() const {
    std::string s = "(binary_constant_expression_multiply";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstOutputDeclaration::AstOutputDeclaration() { }
void AstOutputDeclaration::push_back(AstKeywordOutputHandle pKeywordOutput0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfPortIdentifiersHandle pListOfPortIdentifiers2) {
    _vecElements.push_back(ElementType(pKeywordOutput0, pZeroOrOneRange1, pListOfPortIdentifiers2));
}
std::vector<AstOutputDeclaration::ElementType>& AstOutputDeclaration::container() {
    return _vecElements;
}
const std::vector<AstOutputDeclaration::ElementType>& AstOutputDeclaration::container() const {
    return _vecElements;
}
AstOutputDeclaration::ElementType AstOutputDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOutputDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstOutputDeclaration::toString() const {
    std::string s = "(output_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordOutput0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
        s = s + " " + _vecElements[i]._pListOfPortIdentifiers2->toString();
    }
        s += ")";    return s;
}
AstModuleKeyword::AstModuleKeyword(AstKeywordModuleHandle pKeywordModule)
  : _pKeywordModule(pKeywordModule)
  { }
AstModuleKeyword::AstModuleKeyword(AstKeywordMacroModuleHandle pKeywordMacroModule)
  : _pKeywordMacroModule(pKeywordMacroModule)
  { }
AstKeywordModuleHandle AstModuleKeyword::keyword_module() const
  { return _pKeywordModule; }
AstKeywordMacroModuleHandle AstModuleKeyword::keyword_macro_module() const
  { return _pKeywordMacroModule; }
std::string AstModuleKeyword::toString() const {
    std::string s = "(module_keyword";
    if (keyword_module().valid())
        s = s + " " + keyword_module()->toString();
    if (keyword_macro_module().valid())
        s = s + " " + keyword_macro_module()->toString();
        s += ")";    return s;
}
AstBinaryOperatorLt::AstBinaryOperatorLt() { }
void AstBinaryOperatorLt::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorLt::ElementType>& AstBinaryOperatorLt::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorLt::ElementType>& AstBinaryOperatorLt::container() const {
    return _vecElements;
}
AstBinaryOperatorLt::ElementType AstBinaryOperatorLt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorLt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorLt::toString() const {
    std::string s = "(binary_operator_lt";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstNOutputGateType::AstNOutputGateType(const std::string & s)
  : _n_output_gatetype(s)
  { }
std::string AstNOutputGateType::n_output_gatetype() const
  { return _n_output_gatetype; }
std::string AstNOutputGateType::toString() const
  { return "(n_output_gatetype " + n_output_gatetype() + ")";}
AstDecimalNumber::AstDecimalNumber(const std::string & s)
  : _decimal_number(s)
  { }
std::string AstDecimalNumber::decimal_number() const
  { return _decimal_number; }
std::string AstDecimalNumber::toString() const
  { return "(decimal_number " + decimal_number() + ")";}
AstBinaryOperatorTripleEqual::AstBinaryOperatorTripleEqual() { }
void AstBinaryOperatorTripleEqual::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorTripleEqual::ElementType>& AstBinaryOperatorTripleEqual::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorTripleEqual::ElementType>& AstBinaryOperatorTripleEqual::container() const {
    return _vecElements;
}
AstBinaryOperatorTripleEqual::ElementType AstBinaryOperatorTripleEqual::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorTripleEqual::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorTripleEqual::toString() const {
    std::string s = "(binary_operator_triple_equal";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstKeywordElse::AstKeywordElse(const std::string & s)
  : _keyword_else(s)
  { }
std::string AstKeywordElse::keyword_else() const
  { return _keyword_else; }
std::string AstKeywordElse::toString() const
  { return "(keyword_else " + keyword_else() + ")";}
AstBinaryConstantExpressionMinus::AstBinaryConstantExpressionMinus() { }
void AstBinaryConstantExpressionMinus::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionMinus::ElementType>& AstBinaryConstantExpressionMinus::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionMinus::ElementType>& AstBinaryConstantExpressionMinus::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionMinus::ElementType AstBinaryConstantExpressionMinus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionMinus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionMinus::toString() const {
    std::string s = "(binary_constant_expression_minus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstNameOfGateInstance::AstNameOfGateInstance() { }
void AstNameOfGateInstance::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrOneRange1));
}
std::vector<AstNameOfGateInstance::ElementType>& AstNameOfGateInstance::container() {
    return _vecElements;
}
const std::vector<AstNameOfGateInstance::ElementType>& AstNameOfGateInstance::container() const {
    return _vecElements;
}
AstNameOfGateInstance::ElementType AstNameOfGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNameOfGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstNameOfGateInstance::toString() const {
    std::string s = "(name_of_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorNegAnd::AstUnaryOperatorNegAnd() { }
void AstUnaryOperatorNegAnd::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorNegAnd::ElementType>& AstUnaryOperatorNegAnd::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorNegAnd::ElementType>& AstUnaryOperatorNegAnd::container() const {
    return _vecElements;
}
AstUnaryOperatorNegAnd::ElementType AstUnaryOperatorNegAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorNegAnd::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorNegAnd::toString() const {
    std::string s = "(unary_operator_neg_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstAlwaysConstruct::AstAlwaysConstruct() { }
void AstAlwaysConstruct::push_back(AstKeywordAlwaysHandle pKeywordAlways0, AstStatementHandle pStatement1) {
    _vecElements.push_back(ElementType(pKeywordAlways0, pStatement1));
}
std::vector<AstAlwaysConstruct::ElementType>& AstAlwaysConstruct::container() {
    return _vecElements;
}
const std::vector<AstAlwaysConstruct::ElementType>& AstAlwaysConstruct::container() const {
    return _vecElements;
}
AstAlwaysConstruct::ElementType AstAlwaysConstruct::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstAlwaysConstruct::element_size() const
  { return _vecElements.size(); }
std::string AstAlwaysConstruct::toString() const {
    std::string s = "(always_construct";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordAlways0->toString();
        s = s + " " + _vecElements[i]._pStatement1->toString();
    }
        s += ")";    return s;
}
AstOctalNumber::AstOctalNumber(const std::string & s)
  : _octal_number(s)
  { }
std::string AstOctalNumber::octal_number() const
  { return _octal_number; }
std::string AstOctalNumber::toString() const
  { return "(octal_number " + octal_number() + ")";}
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionMultiplyHandle pBinaryConstantExpressionMultiply)
  : _pBinaryConstantExpressionMultiply(pBinaryConstantExpressionMultiply)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionDivideHandle pBinaryConstantExpressionDivide)
  : _pBinaryConstantExpressionDivide(pBinaryConstantExpressionDivide)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionModulusHandle pBinaryConstantExpressionModulus)
  : _pBinaryConstantExpressionModulus(pBinaryConstantExpressionModulus)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionPlusHandle pBinaryConstantExpressionPlus)
  : _pBinaryConstantExpressionPlus(pBinaryConstantExpressionPlus)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionMinusHandle pBinaryConstantExpressionMinus)
  : _pBinaryConstantExpressionMinus(pBinaryConstantExpressionMinus)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionShiftRightHandle pBinaryConstantExpressionShiftRight)
  : _pBinaryConstantExpressionShiftRight(pBinaryConstantExpressionShiftRight)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionShiftLeftHandle pBinaryConstantExpressionShiftLeft)
  : _pBinaryConstantExpressionShiftLeft(pBinaryConstantExpressionShiftLeft)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionGtHandle pBinaryConstantExpressionGt)
  : _pBinaryConstantExpressionGt(pBinaryConstantExpressionGt)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionGeqHandle pBinaryConstantExpressionGeq)
  : _pBinaryConstantExpressionGeq(pBinaryConstantExpressionGeq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionLtHandle pBinaryConstantExpressionLt)
  : _pBinaryConstantExpressionLt(pBinaryConstantExpressionLt)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionLeqHandle pBinaryConstantExpressionLeq)
  : _pBinaryConstantExpressionLeq(pBinaryConstantExpressionLeq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionEqHandle pBinaryConstantExpressionEq)
  : _pBinaryConstantExpressionEq(pBinaryConstantExpressionEq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionNeqHandle pBinaryConstantExpressionNeq)
  : _pBinaryConstantExpressionNeq(pBinaryConstantExpressionNeq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionCaseEqHandle pBinaryConstantExpressionCaseEq)
  : _pBinaryConstantExpressionCaseEq(pBinaryConstantExpressionCaseEq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionCaseNeqHandle pBinaryConstantExpressionCaseNeq)
  : _pBinaryConstantExpressionCaseNeq(pBinaryConstantExpressionCaseNeq)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionBwAndHandle pBinaryConstantExpressionBwAnd)
  : _pBinaryConstantExpressionBwAnd(pBinaryConstantExpressionBwAnd)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionBwXorHandle pBinaryConstantExpressionBwXor)
  : _pBinaryConstantExpressionBwXor(pBinaryConstantExpressionBwXor)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionBwXnorHandle pBinaryConstantExpressionBwXnor)
  : _pBinaryConstantExpressionBwXnor(pBinaryConstantExpressionBwXnor)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionBwNxorHandle pBinaryConstantExpressionBwNxor)
  : _pBinaryConstantExpressionBwNxor(pBinaryConstantExpressionBwNxor)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionBwOrHandle pBinaryConstantExpressionBwOr)
  : _pBinaryConstantExpressionBwOr(pBinaryConstantExpressionBwOr)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionLgAndHandle pBinaryConstantExpressionLgAnd)
  : _pBinaryConstantExpressionLgAnd(pBinaryConstantExpressionLgAnd)
  { }
AstBinaryConstantExpression::AstBinaryConstantExpression(AstBinaryConstantExpressionLgOrHandle pBinaryConstantExpressionLgOr)
  : _pBinaryConstantExpressionLgOr(pBinaryConstantExpressionLgOr)
  { }
AstBinaryConstantExpressionMultiplyHandle AstBinaryConstantExpression::binary_constant_expression_multiply() const
  { return _pBinaryConstantExpressionMultiply; }
AstBinaryConstantExpressionDivideHandle AstBinaryConstantExpression::binary_constant_expression_divide() const
  { return _pBinaryConstantExpressionDivide; }
AstBinaryConstantExpressionModulusHandle AstBinaryConstantExpression::binary_constant_expression_modulus() const
  { return _pBinaryConstantExpressionModulus; }
AstBinaryConstantExpressionPlusHandle AstBinaryConstantExpression::binary_constant_expression_plus() const
  { return _pBinaryConstantExpressionPlus; }
AstBinaryConstantExpressionMinusHandle AstBinaryConstantExpression::binary_constant_expression_minus() const
  { return _pBinaryConstantExpressionMinus; }
AstBinaryConstantExpressionShiftRightHandle AstBinaryConstantExpression::binary_constant_expression_shift_right() const
  { return _pBinaryConstantExpressionShiftRight; }
AstBinaryConstantExpressionShiftLeftHandle AstBinaryConstantExpression::binary_constant_expression_shift_left() const
  { return _pBinaryConstantExpressionShiftLeft; }
AstBinaryConstantExpressionGtHandle AstBinaryConstantExpression::binary_constant_expression_gt() const
  { return _pBinaryConstantExpressionGt; }
AstBinaryConstantExpressionGeqHandle AstBinaryConstantExpression::binary_constant_expression_geq() const
  { return _pBinaryConstantExpressionGeq; }
AstBinaryConstantExpressionLtHandle AstBinaryConstantExpression::binary_constant_expression_lt() const
  { return _pBinaryConstantExpressionLt; }
AstBinaryConstantExpressionLeqHandle AstBinaryConstantExpression::binary_constant_expression_leq() const
  { return _pBinaryConstantExpressionLeq; }
AstBinaryConstantExpressionEqHandle AstBinaryConstantExpression::binary_constant_expression_eq() const
  { return _pBinaryConstantExpressionEq; }
AstBinaryConstantExpressionNeqHandle AstBinaryConstantExpression::binary_constant_expression_neq() const
  { return _pBinaryConstantExpressionNeq; }
AstBinaryConstantExpressionCaseEqHandle AstBinaryConstantExpression::binary_constant_expression_case_eq() const
  { return _pBinaryConstantExpressionCaseEq; }
AstBinaryConstantExpressionCaseNeqHandle AstBinaryConstantExpression::binary_constant_expression_case_neq() const
  { return _pBinaryConstantExpressionCaseNeq; }
AstBinaryConstantExpressionBwAndHandle AstBinaryConstantExpression::binary_constant_expression_bw_and() const
  { return _pBinaryConstantExpressionBwAnd; }
AstBinaryConstantExpressionBwXorHandle AstBinaryConstantExpression::binary_constant_expression_bw_xor() const
  { return _pBinaryConstantExpressionBwXor; }
AstBinaryConstantExpressionBwXnorHandle AstBinaryConstantExpression::binary_constant_expression_bw_xnor() const
  { return _pBinaryConstantExpressionBwXnor; }
AstBinaryConstantExpressionBwNxorHandle AstBinaryConstantExpression::binary_constant_expression_bw_nxor() const
  { return _pBinaryConstantExpressionBwNxor; }
AstBinaryConstantExpressionBwOrHandle AstBinaryConstantExpression::binary_constant_expression_bw_or() const
  { return _pBinaryConstantExpressionBwOr; }
AstBinaryConstantExpressionLgAndHandle AstBinaryConstantExpression::binary_constant_expression_lg_and() const
  { return _pBinaryConstantExpressionLgAnd; }
AstBinaryConstantExpressionLgOrHandle AstBinaryConstantExpression::binary_constant_expression_lg_or() const
  { return _pBinaryConstantExpressionLgOr; }
std::string AstBinaryConstantExpression::toString() const {
    std::string s = "(binary_constant_expression";
    if (binary_constant_expression_multiply().valid())
        s = s + " " + binary_constant_expression_multiply()->toString();
    if (binary_constant_expression_divide().valid())
        s = s + " " + binary_constant_expression_divide()->toString();
    if (binary_constant_expression_modulus().valid())
        s = s + " " + binary_constant_expression_modulus()->toString();
    if (binary_constant_expression_plus().valid())
        s = s + " " + binary_constant_expression_plus()->toString();
    if (binary_constant_expression_minus().valid())
        s = s + " " + binary_constant_expression_minus()->toString();
    if (binary_constant_expression_shift_right().valid())
        s = s + " " + binary_constant_expression_shift_right()->toString();
    if (binary_constant_expression_shift_left().valid())
        s = s + " " + binary_constant_expression_shift_left()->toString();
    if (binary_constant_expression_gt().valid())
        s = s + " " + binary_constant_expression_gt()->toString();
    if (binary_constant_expression_geq().valid())
        s = s + " " + binary_constant_expression_geq()->toString();
    if (binary_constant_expression_lt().valid())
        s = s + " " + binary_constant_expression_lt()->toString();
    if (binary_constant_expression_leq().valid())
        s = s + " " + binary_constant_expression_leq()->toString();
    if (binary_constant_expression_eq().valid())
        s = s + " " + binary_constant_expression_eq()->toString();
    if (binary_constant_expression_neq().valid())
        s = s + " " + binary_constant_expression_neq()->toString();
    if (binary_constant_expression_case_eq().valid())
        s = s + " " + binary_constant_expression_case_eq()->toString();
    if (binary_constant_expression_case_neq().valid())
        s = s + " " + binary_constant_expression_case_neq()->toString();
    if (binary_constant_expression_bw_and().valid())
        s = s + " " + binary_constant_expression_bw_and()->toString();
    if (binary_constant_expression_bw_xor().valid())
        s = s + " " + binary_constant_expression_bw_xor()->toString();
    if (binary_constant_expression_bw_xnor().valid())
        s = s + " " + binary_constant_expression_bw_xnor()->toString();
    if (binary_constant_expression_bw_nxor().valid())
        s = s + " " + binary_constant_expression_bw_nxor()->toString();
    if (binary_constant_expression_bw_or().valid())
        s = s + " " + binary_constant_expression_bw_or()->toString();
    if (binary_constant_expression_lg_and().valid())
        s = s + " " + binary_constant_expression_lg_and()->toString();
    if (binary_constant_expression_lg_or().valid())
        s = s + " " + binary_constant_expression_lg_or()->toString();
        s += ")";    return s;
}
AstBinaryExpressionLgOr::AstBinaryExpressionLgOr() { }
void AstBinaryExpressionLgOr::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionLgOr::ElementType>& AstBinaryExpressionLgOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionLgOr::ElementType>& AstBinaryExpressionLgOr::container() const {
    return _vecElements;
}
AstBinaryExpressionLgOr::ElementType AstBinaryExpressionLgOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionLgOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionLgOr::toString() const {
    std::string s = "(binary_expression_lg_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorEqualEqual::AstBinaryOperatorEqualEqual() { }
void AstBinaryOperatorEqualEqual::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorEqualEqual::ElementType>& AstBinaryOperatorEqualEqual::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorEqualEqual::ElementType>& AstBinaryOperatorEqualEqual::container() const {
    return _vecElements;
}
AstBinaryOperatorEqualEqual::ElementType AstBinaryOperatorEqualEqual::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorEqualEqual::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorEqualEqual::toString() const {
    std::string s = "(binary_operator_equal_equal";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstHeximalNumber::AstHeximalNumber(const std::string & s)
  : _heximal_number(s)
  { }
std::string AstHeximalNumber::heximal_number() const
  { return _heximal_number; }
std::string AstHeximalNumber::toString() const
  { return "(heximal_number " + heximal_number() + ")";}
AstListOfPortReferences::AstListOfPortReferences() { }
void AstListOfPortReferences::push_back(AstPortReferenceHandle pPortReference0, AstZeroOrMoreCommaPortReferenceHandle pZeroOrMoreCommaPortReference1) {
    _vecElements.push_back(ElementType(pPortReference0, pZeroOrMoreCommaPortReference1));
}
std::vector<AstListOfPortReferences::ElementType>& AstListOfPortReferences::container() {
    return _vecElements;
}
const std::vector<AstListOfPortReferences::ElementType>& AstListOfPortReferences::container() const {
    return _vecElements;
}
AstListOfPortReferences::ElementType AstListOfPortReferences::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfPortReferences::element_size() const
  { return _vecElements.size(); }
std::string AstListOfPortReferences::toString() const {
    std::string s = "(list_of_port_references";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pPortReference0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaPortReference1->toString();
    }
        s += ")";    return s;
}
AstNetLvalue::AstNetLvalue(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstNetLvalue::AstNetLvalue(AstNetLvalueBitSelectHandle pNetLvalueBitSelect)
  : _pNetLvalueBitSelect(pNetLvalueBitSelect)
  { }
AstNetLvalue::AstNetLvalue(AstNetLvalueRangeSelectHandle pNetLvalueRangeSelect)
  : _pNetLvalueRangeSelect(pNetLvalueRangeSelect)
  { }
AstNetLvalue::AstNetLvalue(AstConcatenationHandle pAstConcatenation)
  : _pAstConcatenation(pAstConcatenation)
  { }
AstIdentifierHandle AstNetLvalue::identifier() const
  { return _pIdentifier; }
AstNetLvalueBitSelectHandle AstNetLvalue::net_lvalue_bit_select() const
  { return _pNetLvalueBitSelect; }
AstNetLvalueRangeSelectHandle AstNetLvalue::net_lvalue_range_select() const
  { return _pNetLvalueRangeSelect; }
AstConcatenationHandle AstNetLvalue::concatenation() const
  { return _pAstConcatenation; }
std::string AstNetLvalue::toString() const {
    std::string s = "(net_lvalue";
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (net_lvalue_bit_select().valid())
        s = s + " " + net_lvalue_bit_select()->toString();
    if (net_lvalue_range_select().valid())
        s = s + " " + net_lvalue_range_select()->toString();
    if (concatenation().valid())
        s = s + " " + concatenation()->toString();
        s += ")";    return s;
}
AstBinaryOperatorAndAnd::AstBinaryOperatorAndAnd() { }
void AstBinaryOperatorAndAnd::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorAndAnd::ElementType>& AstBinaryOperatorAndAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorAndAnd::ElementType>& AstBinaryOperatorAndAnd::container() const {
    return _vecElements;
}
AstBinaryOperatorAndAnd::ElementType AstBinaryOperatorAndAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorAndAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorAndAnd::toString() const {
    std::string s = "(binary_operator_and_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstNInputGateInstance::AstNInputGateInstance() { }
void AstNInputGateInstance::push_back(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstInputTerminalHandle pInputTerminal2, AstZeroOrMoreCommaInputTerminalHandle pZeroOrMoreCommaInputTerminal3) {
    _vecElements.push_back(ElementType(pZeroOrOneNameOfGateInstance0, pOutputTerminal1, pInputTerminal2, pZeroOrMoreCommaInputTerminal3));
}
std::vector<AstNInputGateInstance::ElementType>& AstNInputGateInstance::container() {
    return _vecElements;
}
const std::vector<AstNInputGateInstance::ElementType>& AstNInputGateInstance::container() const {
    return _vecElements;
}
AstNInputGateInstance::ElementType AstNInputGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNInputGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstNInputGateInstance::toString() const {
    std::string s = "(n_input_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pZeroOrOneNameOfGateInstance0->toString();
        s = s + " " + _vecElements[i]._pOutputTerminal1->toString();
        s = s + " " + _vecElements[i]._pInputTerminal2->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaInputTerminal3->toString();
    }
        s += ")";    return s;
}
AstListOfPorts::AstListOfPorts() { }
void AstListOfPorts::push_back(AstPortHandle pPort0, AstZeroOrMoreCommaPortHandle pZeroOrMoreCommaPort1) {
    _vecElements.push_back(ElementType(pPort0, pZeroOrMoreCommaPort1));
}
std::vector<AstListOfPorts::ElementType>& AstListOfPorts::container() {
    return _vecElements;
}
const std::vector<AstListOfPorts::ElementType>& AstListOfPorts::container() const {
    return _vecElements;
}
AstListOfPorts::ElementType AstListOfPorts::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfPorts::element_size() const
  { return _vecElements.size(); }
std::string AstListOfPorts::toString() const {
    std::string s = "(list_of_ports";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pPort0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaPort1->toString();
    }
        s += ")";    return s;
}
AstOneOrMoreCommaExpression::AstOneOrMoreCommaExpression() { }
void AstOneOrMoreCommaExpression::push_back(AstExpressionHandle pExpression0) {
    _vecElements.push_back(ElementType(pExpression0));
}
std::vector<AstOneOrMoreCommaExpression::ElementType>& AstOneOrMoreCommaExpression::container() {
    return _vecElements;
}
const std::vector<AstOneOrMoreCommaExpression::ElementType>& AstOneOrMoreCommaExpression::container() const {
    return _vecElements;
}
AstOneOrMoreCommaExpression::ElementType AstOneOrMoreCommaExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOneOrMoreCommaExpression::element_size() const
  { return _vecElements.size(); }
std::string AstOneOrMoreCommaExpression::toString() const {
    std::string s = "(one_or_more_comma_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
    }
        s += ")";    return s;
}
AstNamedPortConnection::AstNamedPortConnection() { }
void AstNamedPortConnection::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneExpressionHandle pZeroOrOneExpression1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrOneExpression1));
}
std::vector<AstNamedPortConnection::ElementType>& AstNamedPortConnection::container() {
    return _vecElements;
}
const std::vector<AstNamedPortConnection::ElementType>& AstNamedPortConnection::container() const {
    return _vecElements;
}
AstNamedPortConnection::ElementType AstNamedPortConnection::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNamedPortConnection::element_size() const
  { return _vecElements.size(); }
std::string AstNamedPortConnection::toString() const {
    std::string s = "(named_port_connection";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneExpression1->toString();
    }
        s += ")";    return s;
}
AstModuleItemDeclaration::AstModuleItemDeclaration(AstParameterDeclarationHandle pParameterDeclaration)
  : _pParameterDeclaration(pParameterDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstInputDeclarationHandle pInputDeclaration)
  : _pInputDeclaration(pInputDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstOutputDeclarationHandle pOutputDeclaration)
  : _pOutputDeclaration(pOutputDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstInoutDeclarationHandle pInoutDeclaration)
  : _pInoutDeclaration(pInoutDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstNetDeclarationHandle pNetDeclaration)
  : _pNetDeclaration(pNetDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstRegDeclarationHandle pRegDeclaration)
  : _pRegDeclaration(pRegDeclaration)
  { }
AstModuleItemDeclaration::AstModuleItemDeclaration(AstIntegerDeclarationHandle pIntegerDeclaration)
  : _pIntegerDeclaration(pIntegerDeclaration)
  { }
AstParameterDeclarationHandle AstModuleItemDeclaration::parameter_declaration() const
  { return _pParameterDeclaration; }
AstInputDeclarationHandle AstModuleItemDeclaration::input_declaration() const
  { return _pInputDeclaration; }
AstOutputDeclarationHandle AstModuleItemDeclaration::output_declaration() const
  { return _pOutputDeclaration; }
AstInoutDeclarationHandle AstModuleItemDeclaration::inout_declaration() const
  { return _pInoutDeclaration; }
AstNetDeclarationHandle AstModuleItemDeclaration::net_declaration() const
  { return _pNetDeclaration; }
AstRegDeclarationHandle AstModuleItemDeclaration::reg_declaration() const
  { return _pRegDeclaration; }
AstIntegerDeclarationHandle AstModuleItemDeclaration::integer_declaration() const
  { return _pIntegerDeclaration; }
std::string AstModuleItemDeclaration::toString() const {
    std::string s = "(module_item_declaration";
    if (parameter_declaration().valid())
        s = s + " " + parameter_declaration()->toString();
    if (input_declaration().valid())
        s = s + " " + input_declaration()->toString();
    if (output_declaration().valid())
        s = s + " " + output_declaration()->toString();
    if (inout_declaration().valid())
        s = s + " " + inout_declaration()->toString();
    if (net_declaration().valid())
        s = s + " " + net_declaration()->toString();
    if (reg_declaration().valid())
        s = s + " " + reg_declaration()->toString();
    if (integer_declaration().valid())
        s = s + " " + integer_declaration()->toString();
        s += ")";    return s;
}
AstBinaryConstantExpressionLeq::AstBinaryConstantExpressionLeq() { }
void AstBinaryConstantExpressionLeq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionLeq::ElementType>& AstBinaryConstantExpressionLeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionLeq::ElementType>& AstBinaryConstantExpressionLeq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionLeq::ElementType AstBinaryConstantExpressionLeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionLeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionLeq::toString() const {
    std::string s = "(binary_constant_expression_leq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionDivide::AstBinaryExpressionDivide() { }
void AstBinaryExpressionDivide::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionDivide::ElementType>& AstBinaryExpressionDivide::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionDivide::ElementType>& AstBinaryExpressionDivide::container() const {
    return _vecElements;
}
AstBinaryExpressionDivide::ElementType AstBinaryExpressionDivide::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionDivide::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionDivide::toString() const {
    std::string s = "(binary_expression_divide";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionLt::AstBinaryExpressionLt() { }
void AstBinaryExpressionLt::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionLt::ElementType>& AstBinaryExpressionLt::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionLt::ElementType>& AstBinaryExpressionLt::container() const {
    return _vecElements;
}
AstBinaryExpressionLt::ElementType AstBinaryExpressionLt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionLt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionLt::toString() const {
    std::string s = "(binary_expression_lt";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstRegisterName::AstRegisterName() { }
void AstRegisterName::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrMoreRegisterNameRangeHandle pZeroOrMoreRegisterNameRange1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrMoreRegisterNameRange1));
}
std::vector<AstRegisterName::ElementType>& AstRegisterName::container() {
    return _vecElements;
}
const std::vector<AstRegisterName::ElementType>& AstRegisterName::container() const {
    return _vecElements;
}
AstRegisterName::ElementType AstRegisterName::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstRegisterName::element_size() const
  { return _vecElements.size(); }
std::string AstRegisterName::toString() const {
    std::string s = "(register_name";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreRegisterNameRange1->toString();
    }
        s += ")";    return s;
}
AstModuleInstantiation::AstModuleInstantiation() { }
void AstModuleInstantiation::push_back(AstIdentifierHandle pIdentifier0, AstModuleInstanceHandle pModuleInstance1, AstZeroOrMoreCommaModuleInstanceHandle pZeroOrMoreCommaModuleInstance2) {
    _vecElements.push_back(ElementType(pIdentifier0, pModuleInstance1, pZeroOrMoreCommaModuleInstance2));
}
std::vector<AstModuleInstantiation::ElementType>& AstModuleInstantiation::container() {
    return _vecElements;
}
const std::vector<AstModuleInstantiation::ElementType>& AstModuleInstantiation::container() const {
    return _vecElements;
}
AstModuleInstantiation::ElementType AstModuleInstantiation::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstModuleInstantiation::element_size() const
  { return _vecElements.size(); }
std::string AstModuleInstantiation::toString() const {
    std::string s = "(module_instantiation";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pModuleInstance1->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaModuleInstance2->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionBwNxor::AstBinaryConstantExpressionBwNxor() { }
void AstBinaryConstantExpressionBwNxor::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionBwNxor::ElementType>& AstBinaryConstantExpressionBwNxor::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionBwNxor::ElementType>& AstBinaryConstantExpressionBwNxor::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionBwNxor::ElementType AstBinaryConstantExpressionBwNxor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionBwNxor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionBwNxor::toString() const {
    std::string s = "(binary_constant_expression_bw_nxor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaPort::AstZeroOrMoreCommaPort() { }
void AstZeroOrMoreCommaPort::push_back(AstPortHandle pPort) {
    _vecElements.push_back(ElementType(pPort));
}
std::vector<AstZeroOrMoreCommaPort::ElementType>& AstZeroOrMoreCommaPort::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaPort::ElementType>& AstZeroOrMoreCommaPort::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaPort::ElementType AstZeroOrMoreCommaPort::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaPort::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaPort::toString() const {
    std::string s = "(zero_or_more_comma_port";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pPort->toString();
    }
        s += ")";    return s;
}
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorPlusHandle pUnaryOperatorPlus)
  : _pUnaryOperatorPlus(pUnaryOperatorPlus)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorMinusHandle pUnaryOperatorMinus)
  : _pUnaryOperatorMinus(pUnaryOperatorMinus)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorNotHandle pUnaryOperatorNot)
  : _pUnaryOperatorNot(pUnaryOperatorNot)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorNegHandle pUnaryOperatorNeg)
  : _pUnaryOperatorNeg(pUnaryOperatorNeg)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorAndHandle pUnaryOperatorAnd)
  : _pUnaryOperatorAnd(pUnaryOperatorAnd)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorNegAndHandle pUnaryOperatorNegAnd)
  : _pUnaryOperatorNegAnd(pUnaryOperatorNegAnd)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorOrHandle pUnaryOperatorOr)
  : _pUnaryOperatorOr(pUnaryOperatorOr)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorNegOrHandle pUnaryOperatorNegOr)
  : _pUnaryOperatorNegOr(pUnaryOperatorNegOr)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorXorHandle pUnaryOperatorXor)
  : _pUnaryOperatorXor(pUnaryOperatorXor)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorNegXorHandle pUnaryOperatorNegXor)
  : _pUnaryOperatorNegXor(pUnaryOperatorNegXor)
  { }
AstUnaryOperator::AstUnaryOperator(AstUnaryOperatorXorNegHandle pUnaryOperatorXorNeg)
  : _pUnaryOperatorXorNeg(pUnaryOperatorXorNeg)
  { }
AstUnaryOperatorPlusHandle AstUnaryOperator::unary_operator_plus() const
  { return _pUnaryOperatorPlus; }
AstUnaryOperatorMinusHandle AstUnaryOperator::unary_operator_minus() const
  { return _pUnaryOperatorMinus; }
AstUnaryOperatorNotHandle AstUnaryOperator::unary_operator_not() const
  { return _pUnaryOperatorNot; }
AstUnaryOperatorNegHandle AstUnaryOperator::unary_operator_neg() const
  { return _pUnaryOperatorNeg; }
AstUnaryOperatorAndHandle AstUnaryOperator::unary_operator_and() const
  { return _pUnaryOperatorAnd; }
AstUnaryOperatorNegAndHandle AstUnaryOperator::unary_operator_neg_and() const
  { return _pUnaryOperatorNegAnd; }
AstUnaryOperatorOrHandle AstUnaryOperator::unary_operator_or() const
  { return _pUnaryOperatorOr; }
AstUnaryOperatorNegOrHandle AstUnaryOperator::unary_operator_neg_or() const
  { return _pUnaryOperatorNegOr; }
AstUnaryOperatorXorHandle AstUnaryOperator::unary_operator_xor() const
  { return _pUnaryOperatorXor; }
AstUnaryOperatorNegXorHandle AstUnaryOperator::unary_operator_neg_xor() const
  { return _pUnaryOperatorNegXor; }
AstUnaryOperatorXorNegHandle AstUnaryOperator::unary_operator_xor_neg() const
  { return _pUnaryOperatorXorNeg; }
std::string AstUnaryOperator::toString() const {
    std::string s = "(unary_operator";
    if (unary_operator_plus().valid())
        s = s + " " + unary_operator_plus()->toString();
    if (unary_operator_minus().valid())
        s = s + " " + unary_operator_minus()->toString();
    if (unary_operator_not().valid())
        s = s + " " + unary_operator_not()->toString();
    if (unary_operator_neg().valid())
        s = s + " " + unary_operator_neg()->toString();
    if (unary_operator_and().valid())
        s = s + " " + unary_operator_and()->toString();
    if (unary_operator_neg_and().valid())
        s = s + " " + unary_operator_neg_and()->toString();
    if (unary_operator_or().valid())
        s = s + " " + unary_operator_or()->toString();
    if (unary_operator_neg_or().valid())
        s = s + " " + unary_operator_neg_or()->toString();
    if (unary_operator_xor().valid())
        s = s + " " + unary_operator_xor()->toString();
    if (unary_operator_neg_xor().valid())
        s = s + " " + unary_operator_neg_xor()->toString();
    if (unary_operator_xor_neg().valid())
        s = s + " " + unary_operator_xor_neg()->toString();
        s += ")";    return s;
}
AstNonBlockingAssignmentSemicolon::AstNonBlockingAssignmentSemicolon() { }
void AstNonBlockingAssignmentSemicolon::push_back(AstNonBlockingAssignmentHandle pNonBlockingAssignment0) {
    _vecElements.push_back(ElementType(pNonBlockingAssignment0));
}
std::vector<AstNonBlockingAssignmentSemicolon::ElementType>& AstNonBlockingAssignmentSemicolon::container() {
    return _vecElements;
}
const std::vector<AstNonBlockingAssignmentSemicolon::ElementType>& AstNonBlockingAssignmentSemicolon::container() const {
    return _vecElements;
}
AstNonBlockingAssignmentSemicolon::ElementType AstNonBlockingAssignmentSemicolon::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNonBlockingAssignmentSemicolon::element_size() const
  { return _vecElements.size(); }
std::string AstNonBlockingAssignmentSemicolon::toString() const {
    std::string s = "(non_blocking_assignment_semicolon";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNonBlockingAssignment0->toString();
    }
        s += ")";    return s;
}
AstKeywordIf::AstKeywordIf(const std::string & s)
  : _keyword_if(s)
  { }
std::string AstKeywordIf::keyword_if() const
  { return _keyword_if; }
std::string AstKeywordIf::toString() const
  { return "(keyword_if " + keyword_if() + ")";}
AstBinaryExpressionMultiply::AstBinaryExpressionMultiply() { }
void AstBinaryExpressionMultiply::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionMultiply::ElementType>& AstBinaryExpressionMultiply::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionMultiply::ElementType>& AstBinaryExpressionMultiply::container() const {
    return _vecElements;
}
AstBinaryExpressionMultiply::ElementType AstBinaryExpressionMultiply::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionMultiply::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionMultiply::toString() const {
    std::string s = "(binary_expression_multiply";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstNonBlockingAssignment::AstNonBlockingAssignment() { }
void AstNonBlockingAssignment::push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pRegLvalue0, pExpression1));
}
std::vector<AstNonBlockingAssignment::ElementType>& AstNonBlockingAssignment::container() {
    return _vecElements;
}
const std::vector<AstNonBlockingAssignment::ElementType>& AstNonBlockingAssignment::container() const {
    return _vecElements;
}
AstNonBlockingAssignment::ElementType AstNonBlockingAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNonBlockingAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstNonBlockingAssignment::toString() const {
    std::string s = "(non_blocking_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRegLvalue0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaOutputTerminal::AstZeroOrMoreCommaOutputTerminal() { }
void AstZeroOrMoreCommaOutputTerminal::push_back(AstOutputTerminalHandle pOutputTerminal) {
    _vecElements.push_back(ElementType(pOutputTerminal));
}
std::vector<AstZeroOrMoreCommaOutputTerminal::ElementType>& AstZeroOrMoreCommaOutputTerminal::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaOutputTerminal::ElementType>& AstZeroOrMoreCommaOutputTerminal::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaOutputTerminal::ElementType AstZeroOrMoreCommaOutputTerminal::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaOutputTerminal::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaOutputTerminal::toString() const {
    std::string s = "(zero_or_more_comma_output_terminal";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pOutputTerminal->toString();
    }
        s += ")";    return s;
}
AstGateInstantiation::AstGateInstantiation(AstGateInstantiationInputHandle pGateInstantiationInput)
  : _pGateInstantiationInput(pGateInstantiationInput)
  { }
AstGateInstantiation::AstGateInstantiation(AstGateInstantiationOutputHandle pGateInstantiationOutput)
  : _pGateInstantiationOutput(pGateInstantiationOutput)
  { }
AstGateInstantiationInputHandle AstGateInstantiation::gate_instantiation_input() const
  { return _pGateInstantiationInput; }
AstGateInstantiationOutputHandle AstGateInstantiation::gate_instantiation_output() const
  { return _pGateInstantiationOutput; }
std::string AstGateInstantiation::toString() const {
    std::string s = "(gate_instantiation";
    if (gate_instantiation_input().valid())
        s = s + " " + gate_instantiation_input()->toString();
    if (gate_instantiation_output().valid())
        s = s + " " + gate_instantiation_output()->toString();
        s += ")";    return s;
}
AstBinaryConstantExpressionModulus::AstBinaryConstantExpressionModulus() { }
void AstBinaryConstantExpressionModulus::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionModulus::ElementType>& AstBinaryConstantExpressionModulus::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionModulus::ElementType>& AstBinaryConstantExpressionModulus::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionModulus::ElementType AstBinaryConstantExpressionModulus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionModulus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionModulus::toString() const {
    std::string s = "(binary_constant_expression_modulus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionBwXnor::AstBinaryConstantExpressionBwXnor() { }
void AstBinaryConstantExpressionBwXnor::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionBwXnor::ElementType>& AstBinaryConstantExpressionBwXnor::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionBwXnor::ElementType>& AstBinaryConstantExpressionBwXnor::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionBwXnor::ElementType AstBinaryConstantExpressionBwXnor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionBwXnor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionBwXnor::toString() const {
    std::string s = "(binary_constant_expression_bw_xnor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionBwXnor::AstBinaryExpressionBwXnor() { }
void AstBinaryExpressionBwXnor::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionBwXnor::ElementType>& AstBinaryExpressionBwXnor::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionBwXnor::ElementType>& AstBinaryExpressionBwXnor::container() const {
    return _vecElements;
}
AstBinaryExpressionBwXnor::ElementType AstBinaryExpressionBwXnor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionBwXnor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionBwXnor::toString() const {
    std::string s = "(binary_expression_bw_xnor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstNetLvalueRangeSelect::AstNetLvalueRangeSelect() { }
void AstNetLvalueRangeSelect::push_back(AstIdentifierHandle pIdentifier0, AstConstantExpressionHandle pConstantExpression1, AstConstantExpressionHandle pConstantExpression2) {
    _vecElements.push_back(ElementType(pIdentifier0, pConstantExpression1, pConstantExpression2));
}
std::vector<AstNetLvalueRangeSelect::ElementType>& AstNetLvalueRangeSelect::container() {
    return _vecElements;
}
const std::vector<AstNetLvalueRangeSelect::ElementType>& AstNetLvalueRangeSelect::container() const {
    return _vecElements;
}
AstNetLvalueRangeSelect::ElementType AstNetLvalueRangeSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNetLvalueRangeSelect::element_size() const
  { return _vecElements.size(); }
std::string AstNetLvalueRangeSelect::toString() const {
    std::string s = "(net_lvalue_range_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
        s = s + " " + _vecElements[i]._pConstantExpression2->toString();
    }
        s += ")";    return s;
}
AstBracedExpression::AstBracedExpression() { }
void AstBracedExpression::push_back(AstExpressionHandle pExpression0) {
    _vecElements.push_back(ElementType(pExpression0));
}
std::vector<AstBracedExpression::ElementType>& AstBracedExpression::container() {
    return _vecElements;
}
const std::vector<AstBracedExpression::ElementType>& AstBracedExpression::container() const {
    return _vecElements;
}
AstBracedExpression::ElementType AstBracedExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBracedExpression::element_size() const
  { return _vecElements.size(); }
std::string AstBracedExpression::toString() const {
    std::string s = "(braced_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
    }
        s += ")";    return s;
}
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorPlusHandle pBinaryOperatorPlus)
  : _pBinaryOperatorPlus(pBinaryOperatorPlus)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorMinusHandle pBinaryOperatorMinus)
  : _pBinaryOperatorMinus(pBinaryOperatorMinus)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorAsteriskHandle pBinaryOperatorAsterisk)
  : _pBinaryOperatorAsterisk(pBinaryOperatorAsterisk)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorSlashHandle pBinaryOperatorSlash)
  : _pBinaryOperatorSlash(pBinaryOperatorSlash)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorPercentHandle pBinaryOperatorPercent)
  : _pBinaryOperatorPercent(pBinaryOperatorPercent)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorEqualEqualHandle pBinaryOperatorEqualEqual)
  : _pBinaryOperatorEqualEqual(pBinaryOperatorEqualEqual)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorNotEqualHandle pBinaryOperatorNotEqual)
  : _pBinaryOperatorNotEqual(pBinaryOperatorNotEqual)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorTripleEqualHandle pBinaryOperatorTripleEqual)
  : _pBinaryOperatorTripleEqual(pBinaryOperatorTripleEqual)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorNotEqualEqualHandle pBinaryOperatorNotEqualEqual)
  : _pBinaryOperatorNotEqualEqual(pBinaryOperatorNotEqualEqual)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorAndAndHandle pBinaryOperatorAndAnd)
  : _pBinaryOperatorAndAnd(pBinaryOperatorAndAnd)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorOrOrHandle pBinaryOperatorOrOr)
  : _pBinaryOperatorOrOr(pBinaryOperatorOrOr)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorLtHandle pBinaryOperatorLt)
  : _pBinaryOperatorLt(pBinaryOperatorLt)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorLeqHandle pBinaryOperatorLeq)
  : _pBinaryOperatorLeq(pBinaryOperatorLeq)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorGtHandle pBinaryOperatorGt)
  : _pBinaryOperatorGt(pBinaryOperatorGt)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorGeqHandle pBinaryOperatorGeq)
  : _pBinaryOperatorGeq(pBinaryOperatorGeq)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorAndHandle pBinaryOperatorAnd)
  : _pBinaryOperatorAnd(pBinaryOperatorAnd)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorOrHandle pBinaryOperatorOr)
  : _pBinaryOperatorOr(pBinaryOperatorOr)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorXorHandle pBinaryOperatorXor)
  : _pBinaryOperatorXor(pBinaryOperatorXor)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorXorNegHandle pBinaryOperatorXorNeg)
  : _pBinaryOperatorXorNeg(pBinaryOperatorXorNeg)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorNegXorHandle pBinaryOperatorNegXor)
  : _pBinaryOperatorNegXor(pBinaryOperatorNegXor)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorShrHandle pBinaryOperatorShr)
  : _pBinaryOperatorShr(pBinaryOperatorShr)
  { }
AstBinaryOperator::AstBinaryOperator(AstBinaryOperatorShlHandle pBinaryOperatorShl)
  : _pBinaryOperatorShl(pBinaryOperatorShl)
  { }
AstBinaryOperatorPlusHandle AstBinaryOperator::binary_operator_plus() const
  { return _pBinaryOperatorPlus; }
AstBinaryOperatorMinusHandle AstBinaryOperator::binary_operator_minus() const
  { return _pBinaryOperatorMinus; }
AstBinaryOperatorAsteriskHandle AstBinaryOperator::binary_operator_asterisk() const
  { return _pBinaryOperatorAsterisk; }
AstBinaryOperatorSlashHandle AstBinaryOperator::binary_operator_slash() const
  { return _pBinaryOperatorSlash; }
AstBinaryOperatorPercentHandle AstBinaryOperator::binary_operator_percent() const
  { return _pBinaryOperatorPercent; }
AstBinaryOperatorEqualEqualHandle AstBinaryOperator::binary_operator_equal_equal() const
  { return _pBinaryOperatorEqualEqual; }
AstBinaryOperatorNotEqualHandle AstBinaryOperator::binary_operator_not_equal() const
  { return _pBinaryOperatorNotEqual; }
AstBinaryOperatorTripleEqualHandle AstBinaryOperator::binary_operator_triple_equal() const
  { return _pBinaryOperatorTripleEqual; }
AstBinaryOperatorNotEqualEqualHandle AstBinaryOperator::binary_operator_not_equal_equal() const
  { return _pBinaryOperatorNotEqualEqual; }
AstBinaryOperatorAndAndHandle AstBinaryOperator::binary_operator_and_and() const
  { return _pBinaryOperatorAndAnd; }
AstBinaryOperatorOrOrHandle AstBinaryOperator::binary_operator_or_or() const
  { return _pBinaryOperatorOrOr; }
AstBinaryOperatorLtHandle AstBinaryOperator::binary_operator_lt() const
  { return _pBinaryOperatorLt; }
AstBinaryOperatorLeqHandle AstBinaryOperator::binary_operator_leq() const
  { return _pBinaryOperatorLeq; }
AstBinaryOperatorGtHandle AstBinaryOperator::binary_operator_gt() const
  { return _pBinaryOperatorGt; }
AstBinaryOperatorGeqHandle AstBinaryOperator::binary_operator_geq() const
  { return _pBinaryOperatorGeq; }
AstBinaryOperatorAndHandle AstBinaryOperator::binary_operator_and() const
  { return _pBinaryOperatorAnd; }
AstBinaryOperatorOrHandle AstBinaryOperator::binary_operator_or() const
  { return _pBinaryOperatorOr; }
AstBinaryOperatorXorHandle AstBinaryOperator::binary_operator_xor() const
  { return _pBinaryOperatorXor; }
AstBinaryOperatorXorNegHandle AstBinaryOperator::binary_operator_xor_neg() const
  { return _pBinaryOperatorXorNeg; }
AstBinaryOperatorNegXorHandle AstBinaryOperator::binary_operator_neg_xor() const
  { return _pBinaryOperatorNegXor; }
AstBinaryOperatorShrHandle AstBinaryOperator::binary_operator_shr() const
  { return _pBinaryOperatorShr; }
AstBinaryOperatorShlHandle AstBinaryOperator::binary_operator_shl() const
  { return _pBinaryOperatorShl; }
std::string AstBinaryOperator::toString() const {
    std::string s = "(binary_operator";
    if (binary_operator_plus().valid())
        s = s + " " + binary_operator_plus()->toString();
    if (binary_operator_minus().valid())
        s = s + " " + binary_operator_minus()->toString();
    if (binary_operator_asterisk().valid())
        s = s + " " + binary_operator_asterisk()->toString();
    if (binary_operator_slash().valid())
        s = s + " " + binary_operator_slash()->toString();
    if (binary_operator_percent().valid())
        s = s + " " + binary_operator_percent()->toString();
    if (binary_operator_equal_equal().valid())
        s = s + " " + binary_operator_equal_equal()->toString();
    if (binary_operator_not_equal().valid())
        s = s + " " + binary_operator_not_equal()->toString();
    if (binary_operator_triple_equal().valid())
        s = s + " " + binary_operator_triple_equal()->toString();
    if (binary_operator_not_equal_equal().valid())
        s = s + " " + binary_operator_not_equal_equal()->toString();
    if (binary_operator_and_and().valid())
        s = s + " " + binary_operator_and_and()->toString();
    if (binary_operator_or_or().valid())
        s = s + " " + binary_operator_or_or()->toString();
    if (binary_operator_lt().valid())
        s = s + " " + binary_operator_lt()->toString();
    if (binary_operator_leq().valid())
        s = s + " " + binary_operator_leq()->toString();
    if (binary_operator_gt().valid())
        s = s + " " + binary_operator_gt()->toString();
    if (binary_operator_geq().valid())
        s = s + " " + binary_operator_geq()->toString();
    if (binary_operator_and().valid())
        s = s + " " + binary_operator_and()->toString();
    if (binary_operator_or().valid())
        s = s + " " + binary_operator_or()->toString();
    if (binary_operator_xor().valid())
        s = s + " " + binary_operator_xor()->toString();
    if (binary_operator_xor_neg().valid())
        s = s + " " + binary_operator_xor_neg()->toString();
    if (binary_operator_neg_xor().valid())
        s = s + " " + binary_operator_neg_xor()->toString();
    if (binary_operator_shr().valid())
        s = s + " " + binary_operator_shr()->toString();
    if (binary_operator_shl().valid())
        s = s + " " + binary_operator_shl()->toString();
        s += ")";    return s;
}
AstZeroOrMoreCommaRegisterName::AstZeroOrMoreCommaRegisterName() { }
void AstZeroOrMoreCommaRegisterName::push_back(AstRegisterNameHandle pRegisterName) {
    _vecElements.push_back(ElementType(pRegisterName));
}
std::vector<AstZeroOrMoreCommaRegisterName::ElementType>& AstZeroOrMoreCommaRegisterName::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaRegisterName::ElementType>& AstZeroOrMoreCommaRegisterName::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaRegisterName::ElementType AstZeroOrMoreCommaRegisterName::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaRegisterName::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaRegisterName::toString() const {
    std::string s = "(zero_or_more_comma_register_name";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRegisterName->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionModulus::AstBinaryExpressionModulus() { }
void AstBinaryExpressionModulus::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionModulus::ElementType>& AstBinaryExpressionModulus::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionModulus::ElementType>& AstBinaryExpressionModulus::container() const {
    return _vecElements;
}
AstBinaryExpressionModulus::ElementType AstBinaryExpressionModulus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionModulus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionModulus::toString() const {
    std::string s = "(binary_expression_modulus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionGt::AstBinaryExpressionGt() { }
void AstBinaryExpressionGt::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionGt::ElementType>& AstBinaryExpressionGt::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionGt::ElementType>& AstBinaryExpressionGt::container() const {
    return _vecElements;
}
AstBinaryExpressionGt::ElementType AstBinaryExpressionGt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionGt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionGt::toString() const {
    std::string s = "(binary_expression_gt";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorAnd::AstUnaryOperatorAnd() { }
void AstUnaryOperatorAnd::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorAnd::ElementType>& AstUnaryOperatorAnd::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorAnd::ElementType>& AstUnaryOperatorAnd::container() const {
    return _vecElements;
}
AstUnaryOperatorAnd::ElementType AstUnaryOperatorAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorAnd::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorAnd::toString() const {
    std::string s = "(unary_operator_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstZeroOrOneElseStatementOrNull::AstZeroOrOneElseStatementOrNull() { }
void AstZeroOrOneElseStatementOrNull::push_back(AstElseStatementOrNullHandle pElseStatementOrNull) {
    _vecElements.push_back(ElementType(pElseStatementOrNull));
}
std::vector<AstZeroOrOneElseStatementOrNull::ElementType>& AstZeroOrOneElseStatementOrNull::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneElseStatementOrNull::ElementType>& AstZeroOrOneElseStatementOrNull::container() const {
    return _vecElements;
}
AstZeroOrOneElseStatementOrNull::ElementType AstZeroOrOneElseStatementOrNull::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneElseStatementOrNull::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneElseStatementOrNull::toString() const {
    std::string s = "(zero_or_one_else_statement_or_null";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pElseStatementOrNull->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionCaseNeq::AstBinaryConstantExpressionCaseNeq() { }
void AstBinaryConstantExpressionCaseNeq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionCaseNeq::ElementType>& AstBinaryConstantExpressionCaseNeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionCaseNeq::ElementType>& AstBinaryConstantExpressionCaseNeq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionCaseNeq::ElementType AstBinaryConstantExpressionCaseNeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionCaseNeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionCaseNeq::toString() const {
    std::string s = "(binary_constant_expression_case_neq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstSourceText::AstSourceText(AstOneOrMoreDescriptionHandle pOneOrMoreDescription)
  : _pOneOrMoreDescription(pOneOrMoreDescription)
  { }
AstOneOrMoreDescriptionHandle AstSourceText::one_or_more_description() const
  { return _pOneOrMoreDescription; }
std::string AstSourceText::toString() const {
    std::string s = "(source_text";
    if (one_or_more_description().valid())
        s = s + " " + one_or_more_description()->toString();
        s += ")";    return s;
}
AstEventOrEvent::AstEventOrEvent() { }
void AstEventOrEvent::push_back(AstEventExpressionHandle pEventExpression0, AstKeywordOrHandle pKeywordOr1, AstEventExpressionHandle pEventExpression2) {
    _vecElements.push_back(ElementType(pEventExpression0, pKeywordOr1, pEventExpression2));
}
std::vector<AstEventOrEvent::ElementType>& AstEventOrEvent::container() {
    return _vecElements;
}
const std::vector<AstEventOrEvent::ElementType>& AstEventOrEvent::container() const {
    return _vecElements;
}
AstEventOrEvent::ElementType AstEventOrEvent::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstEventOrEvent::element_size() const
  { return _vecElements.size(); }
std::string AstEventOrEvent::toString() const {
    std::string s = "(event_or_event";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEventExpression0->toString();
        s = s + " " + _vecElements[i]._pKeywordOr1->toString();
        s = s + " " + _vecElements[i]._pEventExpression2->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionCaseEq::AstBinaryExpressionCaseEq() { }
void AstBinaryExpressionCaseEq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionCaseEq::ElementType>& AstBinaryExpressionCaseEq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionCaseEq::ElementType>& AstBinaryExpressionCaseEq::container() const {
    return _vecElements;
}
AstBinaryExpressionCaseEq::ElementType AstBinaryExpressionCaseEq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionCaseEq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionCaseEq::toString() const {
    std::string s = "(binary_expression_case_eq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionLgAnd::AstBinaryExpressionLgAnd() { }
void AstBinaryExpressionLgAnd::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionLgAnd::ElementType>& AstBinaryExpressionLgAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionLgAnd::ElementType>& AstBinaryExpressionLgAnd::container() const {
    return _vecElements;
}
AstBinaryExpressionLgAnd::ElementType AstBinaryExpressionLgAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionLgAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionLgAnd::toString() const {
    std::string s = "(binary_expression_lg_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrOneExpression::AstZeroOrOneExpression() { }
void AstZeroOrOneExpression::push_back(AstExpressionHandle pExpression) {
    _vecElements.push_back(ElementType(pExpression));
}
std::vector<AstZeroOrOneExpression::ElementType>& AstZeroOrOneExpression::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneExpression::ElementType>& AstZeroOrOneExpression::container() const {
    return _vecElements;
}
AstZeroOrOneExpression::ElementType AstZeroOrOneExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneExpression::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneExpression::toString() const {
    std::string s = "(zero_or_one_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression->toString();
    }
        s += ")";    return s;
}
AstBinaryNumber::AstBinaryNumber(const std::string & s)
  : _binary_number(s)
  { }
std::string AstBinaryNumber::binary_number() const
  { return _binary_number; }
std::string AstBinaryNumber::toString() const
  { return "(binary_number " + binary_number() + ")";}
AstMultipleConcatenation::AstMultipleConcatenation() { }
void AstMultipleConcatenation::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression2) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1, pZeroOrMoreCommaExpression2));
}
std::vector<AstMultipleConcatenation::ElementType>& AstMultipleConcatenation::container() {
    return _vecElements;
}
const std::vector<AstMultipleConcatenation::ElementType>& AstMultipleConcatenation::container() const {
    return _vecElements;
}
AstMultipleConcatenation::ElementType AstMultipleConcatenation::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstMultipleConcatenation::element_size() const
  { return _vecElements.size(); }
std::string AstMultipleConcatenation::toString() const {
    std::string s = "(multiple_concatenation";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaExpression2->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionPlus::AstBinaryConstantExpressionPlus() { }
void AstBinaryConstantExpressionPlus::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionPlus::ElementType>& AstBinaryConstantExpressionPlus::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionPlus::ElementType>& AstBinaryConstantExpressionPlus::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionPlus::ElementType AstBinaryConstantExpressionPlus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionPlus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionPlus::toString() const {
    std::string s = "(binary_constant_expression_plus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstListOfOrderedPortConnection::AstListOfOrderedPortConnection() { }
void AstListOfOrderedPortConnection::push_back(AstOrderedPortConnectionHandle pOrderedPortConnection0, AstZeroOrMoreCommaOrderedPortConnectionHandle pZeroOrMoreCommaOrderedPortConnection1) {
    _vecElements.push_back(ElementType(pOrderedPortConnection0, pZeroOrMoreCommaOrderedPortConnection1));
}
std::vector<AstListOfOrderedPortConnection::ElementType>& AstListOfOrderedPortConnection::container() {
    return _vecElements;
}
const std::vector<AstListOfOrderedPortConnection::ElementType>& AstListOfOrderedPortConnection::container() const {
    return _vecElements;
}
AstListOfOrderedPortConnection::ElementType AstListOfOrderedPortConnection::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfOrderedPortConnection::element_size() const
  { return _vecElements.size(); }
std::string AstListOfOrderedPortConnection::toString() const {
    std::string s = "(list_of_ordered_port_connection";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pOrderedPortConnection0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaOrderedPortConnection1->toString();
    }
        s += ")";    return s;
}
AstMultiIdentifier::AstMultiIdentifier() { }
void AstMultiIdentifier::push_back(AstSingleIdentifierHandle pSingleIdentifier0, AstZeroOrMoreDotSingleIdentifierHandle pZeroOrMoreDotSingleIdentifier1) {
    _vecElements.push_back(ElementType(pSingleIdentifier0, pZeroOrMoreDotSingleIdentifier1));
}
std::vector<AstMultiIdentifier::ElementType>& AstMultiIdentifier::container() {
    return _vecElements;
}
const std::vector<AstMultiIdentifier::ElementType>& AstMultiIdentifier::container() const {
    return _vecElements;
}
AstMultiIdentifier::ElementType AstMultiIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstMultiIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstMultiIdentifier::toString() const {
    std::string s = "(multi_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pSingleIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreDotSingleIdentifier1->toString();
    }
        s += ")";    return s;
}
AstKeywordPosedge::AstKeywordPosedge(const std::string & s)
  : _keyword_posedge(s)
  { }
std::string AstKeywordPosedge::keyword_posedge() const
  { return _keyword_posedge; }
std::string AstKeywordPosedge::toString() const
  { return "(keyword_posedge " + keyword_posedge() + ")";}
AstBinaryExpressionPlus::AstBinaryExpressionPlus() { }
void AstBinaryExpressionPlus::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionPlus::ElementType>& AstBinaryExpressionPlus::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionPlus::ElementType>& AstBinaryExpressionPlus::container() const {
    return _vecElements;
}
AstBinaryExpressionPlus::ElementType AstBinaryExpressionPlus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionPlus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionPlus::toString() const {
    std::string s = "(binary_expression_plus";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorNegXor::AstUnaryOperatorNegXor() { }
void AstUnaryOperatorNegXor::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorNegXor::ElementType>& AstUnaryOperatorNegXor::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorNegXor::ElementType>& AstUnaryOperatorNegXor::container() const {
    return _vecElements;
}
AstUnaryOperatorNegXor::ElementType AstUnaryOperatorNegXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorNegXor::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorNegXor::toString() const {
    std::string s = "(unary_operator_neg_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstOutputTerminal::AstOutputTerminal() { }
void AstOutputTerminal::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneConstantBitSelectHandle pAstZeroOrOneConstantBitSelect1) {
    _vecElements.push_back(ElementType(pIdentifier0, pAstZeroOrOneConstantBitSelect1));
}
std::vector<AstOutputTerminal::ElementType>& AstOutputTerminal::container() {
    return _vecElements;
}
const std::vector<AstOutputTerminal::ElementType>& AstOutputTerminal::container() const {
    return _vecElements;
}
AstOutputTerminal::ElementType AstOutputTerminal::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOutputTerminal::element_size() const
  { return _vecElements.size(); }
std::string AstOutputTerminal::toString() const {
    std::string s = "(output_terminal";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pAstZeroOrOneConstantBitSelect1->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorXor::AstUnaryOperatorXor() { }
void AstUnaryOperatorXor::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorXor::ElementType>& AstUnaryOperatorXor::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorXor::ElementType>& AstUnaryOperatorXor::container() const {
    return _vecElements;
}
AstUnaryOperatorXor::ElementType AstUnaryOperatorXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorXor::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorXor::toString() const {
    std::string s = "(unary_operator_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstKeywordReg::AstKeywordReg(const std::string & s)
  : _keyword_reg(s)
  { }
std::string AstKeywordReg::keyword_reg() const
  { return _keyword_reg; }
std::string AstKeywordReg::toString() const
  { return "(keyword_reg " + keyword_reg() + ")";}
AstZeroOrMoreCommaNOutputGateInstance::AstZeroOrMoreCommaNOutputGateInstance() { }
void AstZeroOrMoreCommaNOutputGateInstance::push_back(AstNOutputGateInstanceHandle pNOutputGateInstance) {
    _vecElements.push_back(ElementType(pNOutputGateInstance));
}
std::vector<AstZeroOrMoreCommaNOutputGateInstance::ElementType>& AstZeroOrMoreCommaNOutputGateInstance::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaNOutputGateInstance::ElementType>& AstZeroOrMoreCommaNOutputGateInstance::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaNOutputGateInstance::ElementType AstZeroOrMoreCommaNOutputGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaNOutputGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaNOutputGateInstance::toString() const {
    std::string s = "(zero_or_more_comma_n_output_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNOutputGateInstance->toString();
    }
        s += ")";    return s;
}
AstAtEventExpression::AstAtEventExpression() { }
void AstAtEventExpression::push_back(AstEventExpressionHandle pEventExpression0) {
    _vecElements.push_back(ElementType(pEventExpression0));
}
std::vector<AstAtEventExpression::ElementType>& AstAtEventExpression::container() {
    return _vecElements;
}
const std::vector<AstAtEventExpression::ElementType>& AstAtEventExpression::container() const {
    return _vecElements;
}
AstAtEventExpression::ElementType AstAtEventExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstAtEventExpression::element_size() const
  { return _vecElements.size(); }
std::string AstAtEventExpression::toString() const {
    std::string s = "(at_event_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEventExpression0->toString();
    }
        s += ")";    return s;
}
AstInitialConstruct::AstInitialConstruct() { }
void AstInitialConstruct::push_back(AstKeywordInitialHandle pKeywordInitial0, AstStatementHandle pStatement1) {
    _vecElements.push_back(ElementType(pKeywordInitial0, pStatement1));
}
std::vector<AstInitialConstruct::ElementType>& AstInitialConstruct::container() {
    return _vecElements;
}
const std::vector<AstInitialConstruct::ElementType>& AstInitialConstruct::container() const {
    return _vecElements;
}
AstInitialConstruct::ElementType AstInitialConstruct::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstInitialConstruct::element_size() const
  { return _vecElements.size(); }
std::string AstInitialConstruct::toString() const {
    std::string s = "(initial_construct";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordInitial0->toString();
        s = s + " " + _vecElements[i]._pStatement1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorMinus::AstBinaryOperatorMinus() { }
void AstBinaryOperatorMinus::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorMinus::ElementType>& AstBinaryOperatorMinus::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorMinus::ElementType>& AstBinaryOperatorMinus::container() const {
    return _vecElements;
}
AstBinaryOperatorMinus::ElementType AstBinaryOperatorMinus::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorMinus::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorMinus::toString() const {
    std::string s = "(binary_operator_minus";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionDivide::AstBinaryConstantExpressionDivide() { }
void AstBinaryConstantExpressionDivide::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionDivide::ElementType>& AstBinaryConstantExpressionDivide::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionDivide::ElementType>& AstBinaryConstantExpressionDivide::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionDivide::ElementType AstBinaryConstantExpressionDivide::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionDivide::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionDivide::toString() const {
    std::string s = "(binary_constant_expression_divide";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstKeywordAssign::AstKeywordAssign(const std::string & s)
  : _keyword_assign(s)
  { }
std::string AstKeywordAssign::keyword_assign() const
  { return _keyword_assign; }
std::string AstKeywordAssign::toString() const
  { return "(keyword_assign " + keyword_assign() + ")";}
AstIntegerDeclaration::AstIntegerDeclaration() { }
void AstIntegerDeclaration::push_back(AstKeywordIntegerHandle pKeywordInteger0, AstListOfRegisterIdentifiersHandle pListOfRegisterIdentifiers1) {
    _vecElements.push_back(ElementType(pKeywordInteger0, pListOfRegisterIdentifiers1));
}
std::vector<AstIntegerDeclaration::ElementType>& AstIntegerDeclaration::container() {
    return _vecElements;
}
const std::vector<AstIntegerDeclaration::ElementType>& AstIntegerDeclaration::container() const {
    return _vecElements;
}
AstIntegerDeclaration::ElementType AstIntegerDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstIntegerDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstIntegerDeclaration::toString() const {
    std::string s = "(integer_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordInteger0->toString();
        s = s + " " + _vecElements[i]._pListOfRegisterIdentifiers1->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionLgOr::AstBinaryConstantExpressionLgOr() { }
void AstBinaryConstantExpressionLgOr::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionLgOr::ElementType>& AstBinaryConstantExpressionLgOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionLgOr::ElementType>& AstBinaryConstantExpressionLgOr::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionLgOr::ElementType AstBinaryConstantExpressionLgOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionLgOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionLgOr::toString() const {
    std::string s = "(binary_constant_expression_lg_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionBwOr::AstBinaryConstantExpressionBwOr() { }
void AstBinaryConstantExpressionBwOr::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionBwOr::ElementType>& AstBinaryConstantExpressionBwOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionBwOr::ElementType>& AstBinaryConstantExpressionBwOr::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionBwOr::ElementType AstBinaryConstantExpressionBwOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionBwOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionBwOr::toString() const {
    std::string s = "(binary_constant_expression_bw_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstNetType::AstNetType(AstKeywordWireHandle pKeywordWire)
  : _pKeywordWire(pKeywordWire)
  { }
AstKeywordWireHandle AstNetType::keyword_wire() const
  { return _pKeywordWire; }
std::string AstNetType::toString() const {
    std::string s = "(net_type";
    if (keyword_wire().valid())
        s = s + " " + keyword_wire()->toString();
        s += ")";    return s;
}
AstDelayOrEventControl::AstDelayOrEventControl() { }
void AstDelayOrEventControl::push_back(AstEventControlHandle pEventControl0) {
    _vecElements.push_back(ElementType(pEventControl0));
}
std::vector<AstDelayOrEventControl::ElementType>& AstDelayOrEventControl::container() {
    return _vecElements;
}
const std::vector<AstDelayOrEventControl::ElementType>& AstDelayOrEventControl::container() const {
    return _vecElements;
}
AstDelayOrEventControl::ElementType AstDelayOrEventControl::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstDelayOrEventControl::element_size() const
  { return _vecElements.size(); }
std::string AstDelayOrEventControl::toString() const {
    std::string s = "(delay_or_event_control";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEventControl0->toString();
    }
        s += ")";    return s;
}
AstNOutputGateInstance::AstNOutputGateInstance() { }
void AstNOutputGateInstance::push_back(AstZeroOrOneNameOfGateInstanceHandle pZeroOrOneNameOfGateInstance0, AstOutputTerminalHandle pOutputTerminal1, AstZeroOrMoreCommaOutputTerminalHandle pZeroOrMoreCommaOutputTerminal2, AstInputTerminalHandle pInputTerminal3) {
    _vecElements.push_back(ElementType(pZeroOrOneNameOfGateInstance0, pOutputTerminal1, pZeroOrMoreCommaOutputTerminal2, pInputTerminal3));
}
std::vector<AstNOutputGateInstance::ElementType>& AstNOutputGateInstance::container() {
    return _vecElements;
}
const std::vector<AstNOutputGateInstance::ElementType>& AstNOutputGateInstance::container() const {
    return _vecElements;
}
AstNOutputGateInstance::ElementType AstNOutputGateInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNOutputGateInstance::element_size() const
  { return _vecElements.size(); }
std::string AstNOutputGateInstance::toString() const {
    std::string s = "(n_output_gate_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pZeroOrOneNameOfGateInstance0->toString();
        s = s + " " + _vecElements[i]._pOutputTerminal1->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaOutputTerminal2->toString();
        s = s + " " + _vecElements[i]._pInputTerminal3->toString();
    }
        s += ")";    return s;
}
AstConditionalStatement::AstConditionalStatement() { }
void AstConditionalStatement::push_back(AstKeywordIfHandle pKeywordIf0, AstExpressionHandle pExpression1, AstStatementOrNullHandle pStatementOrNull2, AstZeroOrOneElseStatementOrNullHandle pZeroOrOneElseStatementOrNull3) {
    _vecElements.push_back(ElementType(pKeywordIf0, pExpression1, pStatementOrNull2, pZeroOrOneElseStatementOrNull3));
}
std::vector<AstConditionalStatement::ElementType>& AstConditionalStatement::container() {
    return _vecElements;
}
const std::vector<AstConditionalStatement::ElementType>& AstConditionalStatement::container() const {
    return _vecElements;
}
AstConditionalStatement::ElementType AstConditionalStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConditionalStatement::element_size() const
  { return _vecElements.size(); }
std::string AstConditionalStatement::toString() const {
    std::string s = "(conditional_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordIf0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
        s = s + " " + _vecElements[i]._pStatementOrNull2->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneElseStatementOrNull3->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionGt::AstBinaryConstantExpressionGt() { }
void AstBinaryConstantExpressionGt::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionGt::ElementType>& AstBinaryConstantExpressionGt::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionGt::ElementType>& AstBinaryConstantExpressionGt::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionGt::ElementType AstBinaryConstantExpressionGt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionGt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionGt::toString() const {
    std::string s = "(binary_constant_expression_gt";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstZeroOrOnePortExpression::AstZeroOrOnePortExpression() { }
void AstZeroOrOnePortExpression::push_back(AstPortExpressionHandle pPortExpression) {
    _vecElements.push_back(ElementType(pPortExpression));
}
std::vector<AstZeroOrOnePortExpression::ElementType>& AstZeroOrOnePortExpression::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOnePortExpression::ElementType>& AstZeroOrOnePortExpression::container() const {
    return _vecElements;
}
AstZeroOrOnePortExpression::ElementType AstZeroOrOnePortExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOnePortExpression::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOnePortExpression::toString() const {
    std::string s = "(zero_or_one_port_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pPortExpression->toString();
    }
        s += ")";    return s;
}
AstZeroOrOneConstantBitSelect::AstZeroOrOneConstantBitSelect() { }
void AstZeroOrOneConstantBitSelect::push_back(AstConstantBitSelectHandle pConstantBitSelect) {
    _vecElements.push_back(ElementType(pConstantBitSelect));
}
std::vector<AstZeroOrOneConstantBitSelect::ElementType>& AstZeroOrOneConstantBitSelect::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneConstantBitSelect::ElementType>& AstZeroOrOneConstantBitSelect::container() const {
    return _vecElements;
}
AstZeroOrOneConstantBitSelect::ElementType AstZeroOrOneConstantBitSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneConstantBitSelect::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneConstantBitSelect::toString() const {
    std::string s = "(zero_or_one_constant_bit_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantBitSelect->toString();
    }
        s += ")";    return s;
}
AstKeywordCase::AstKeywordCase(const std::string & s)
  : _keyword_case(s)
  { }
std::string AstKeywordCase::keyword_case() const
  { return _keyword_case; }
std::string AstKeywordCase::toString() const
  { return "(keyword_case " + keyword_case() + ")";}
AstZeroOrMoreRegisterNameRange::AstZeroOrMoreRegisterNameRange() { }
void AstZeroOrMoreRegisterNameRange::push_back(AstRangeHandle pRange) {
    _vecElements.push_back(ElementType(pRange));
}
std::vector<AstZeroOrMoreRegisterNameRange::ElementType>& AstZeroOrMoreRegisterNameRange::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreRegisterNameRange::ElementType>& AstZeroOrMoreRegisterNameRange::container() const {
    return _vecElements;
}
AstZeroOrMoreRegisterNameRange::ElementType AstZeroOrMoreRegisterNameRange::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreRegisterNameRange::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreRegisterNameRange::toString() const {
    std::string s = "(zero_or_more_register_name_range";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRange->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorOr::AstBinaryOperatorOr() { }
void AstBinaryOperatorOr::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorOr::ElementType>& AstBinaryOperatorOr::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorOr::ElementType>& AstBinaryOperatorOr::container() const {
    return _vecElements;
}
AstBinaryOperatorOr::ElementType AstBinaryOperatorOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorOr::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorOr::toString() const {
    std::string s = "(binary_operator_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstCaseItemItem::AstCaseItemItem() { }
void AstCaseItemItem::push_back(AstExpressionHandle pExpression0, AstZeroOrMoreCommaExpressionHandle pZeroOrMoreCommaExpression1, AstStatementOrNullHandle pStatementOrNull2) {
    _vecElements.push_back(ElementType(pExpression0, pZeroOrMoreCommaExpression1, pStatementOrNull2));
}
std::vector<AstCaseItemItem::ElementType>& AstCaseItemItem::container() {
    return _vecElements;
}
const std::vector<AstCaseItemItem::ElementType>& AstCaseItemItem::container() const {
    return _vecElements;
}
AstCaseItemItem::ElementType AstCaseItemItem::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstCaseItemItem::element_size() const
  { return _vecElements.size(); }
std::string AstCaseItemItem::toString() const {
    std::string s = "(case_item_item";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaExpression1->toString();
        s = s + " " + _vecElements[i]._pStatementOrNull2->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorNegOr::AstUnaryOperatorNegOr() { }
void AstUnaryOperatorNegOr::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorNegOr::ElementType>& AstUnaryOperatorNegOr::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorNegOr::ElementType>& AstUnaryOperatorNegOr::container() const {
    return _vecElements;
}
AstUnaryOperatorNegOr::ElementType AstUnaryOperatorNegOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorNegOr::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorNegOr::toString() const {
    std::string s = "(unary_operator_neg_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstModuleDeclaration::AstModuleDeclaration() { }
void AstModuleDeclaration::push_back(AstModuleKeywordHandle pModuleKeyword0, AstIdentifierHandle pIdentifier1, AstZeroOrOneListOfPortsHandle pZeroOrOneListOfPorts2, AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem3, AstKeywordEndmoduleHandle pKeywordEndmodule4) {
    _vecElements.push_back(ElementType(pModuleKeyword0, pIdentifier1, pZeroOrOneListOfPorts2, pZeroOrMoreModuleItem3, pKeywordEndmodule4));
}
std::vector<AstModuleDeclaration::ElementType>& AstModuleDeclaration::container() {
    return _vecElements;
}
const std::vector<AstModuleDeclaration::ElementType>& AstModuleDeclaration::container() const {
    return _vecElements;
}
AstModuleDeclaration::ElementType AstModuleDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstModuleDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstModuleDeclaration::toString() const {
    std::string s = "(module_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pModuleKeyword0->toString();
        s = s + " " + _vecElements[i]._pIdentifier1->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneListOfPorts2->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreModuleItem3->toString();
        s = s + " " + _vecElements[i]._pKeywordEndmodule4->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionBwXor::AstBinaryConstantExpressionBwXor() { }
void AstBinaryConstantExpressionBwXor::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionBwXor::ElementType>& AstBinaryConstantExpressionBwXor::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionBwXor::ElementType>& AstBinaryConstantExpressionBwXor::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionBwXor::ElementType AstBinaryConstantExpressionBwXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionBwXor::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionBwXor::toString() const {
    std::string s = "(binary_constant_expression_bw_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstConstantPrimary::AstConstantPrimary(AstNumberHandle pNumber)
  : _pNumber(pNumber)
  { }
AstConstantPrimary::AstConstantPrimary(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstConstantPrimary::AstConstantPrimary(AstConcatenationHandle pAstConcatenation)
  : _pAstConcatenation(pAstConcatenation)
  { }
AstConstantPrimary::AstConstantPrimary(AstMultipleConcatenationHandle pMulitpleConcatenation)
  : _pMulitpleConcatenation(pMulitpleConcatenation)
  { }
AstNumberHandle AstConstantPrimary::number() const
  { return _pNumber; }
AstIdentifierHandle AstConstantPrimary::identifier() const
  { return _pIdentifier; }
AstConcatenationHandle AstConstantPrimary::concatenation() const
  { return _pAstConcatenation; }
AstMultipleConcatenationHandle AstConstantPrimary::multiple_concatenation() const
  { return _pMulitpleConcatenation; }
std::string AstConstantPrimary::toString() const {
    std::string s = "(constant_primary";
    if (number().valid())
        s = s + " " + number()->toString();
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (concatenation().valid())
        s = s + " " + concatenation()->toString();
    if (multiple_concatenation().valid())
        s = s + " " + multiple_concatenation()->toString();
        s += ")";    return s;
}
AstPosedgeExpression::AstPosedgeExpression() { }
void AstPosedgeExpression::push_back(AstKeywordPosedgeHandle pKeywordPosedge0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pKeywordPosedge0, pExpression1));
}
std::vector<AstPosedgeExpression::ElementType>& AstPosedgeExpression::container() {
    return _vecElements;
}
const std::vector<AstPosedgeExpression::ElementType>& AstPosedgeExpression::container() const {
    return _vecElements;
}
AstPosedgeExpression::ElementType AstPosedgeExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstPosedgeExpression::element_size() const
  { return _vecElements.size(); }
std::string AstPosedgeExpression::toString() const {
    std::string s = "(posedge_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordPosedge0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstListOfModuleConnections::AstListOfModuleConnections(AstListOfOrderedPortConnectionHandle pListOfOrderedPortConnection)
  : _pListOfOrderedPortConnection(pListOfOrderedPortConnection)
  { }
AstListOfModuleConnections::AstListOfModuleConnections(AstListOfNamedPortConnectionHandle pListOfNamedPortConnection)
  : _pListOfNamedPortConnection(pListOfNamedPortConnection)
  { }
AstListOfOrderedPortConnectionHandle AstListOfModuleConnections::list_of_ordered_port_connection() const
  { return _pListOfOrderedPortConnection; }
AstListOfNamedPortConnectionHandle AstListOfModuleConnections::list_of_named_port_connection() const
  { return _pListOfNamedPortConnection; }
std::string AstListOfModuleConnections::toString() const {
    std::string s = "(list_of_module_connections";
    if (list_of_ordered_port_connection().valid())
        s = s + " " + list_of_ordered_port_connection()->toString();
    if (list_of_named_port_connection().valid())
        s = s + " " + list_of_named_port_connection()->toString();
        s += ")";    return s;
}
AstRegAssignment::AstRegAssignment() { }
void AstRegAssignment::push_back(AstRegLvalueHandle pRegLvalue0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pRegLvalue0, pExpression1));
}
std::vector<AstRegAssignment::ElementType>& AstRegAssignment::container() {
    return _vecElements;
}
const std::vector<AstRegAssignment::ElementType>& AstRegAssignment::container() const {
    return _vecElements;
}
AstRegAssignment::ElementType AstRegAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstRegAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstRegAssignment::toString() const {
    std::string s = "(reg_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRegLvalue0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorGeq::AstBinaryOperatorGeq() { }
void AstBinaryOperatorGeq::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorGeq::ElementType>& AstBinaryOperatorGeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorGeq::ElementType>& AstBinaryOperatorGeq::container() const {
    return _vecElements;
}
AstBinaryOperatorGeq::ElementType AstBinaryOperatorGeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorGeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorGeq::toString() const {
    std::string s = "(binary_operator_geq";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryExpressionLeq::AstBinaryExpressionLeq() { }
void AstBinaryExpressionLeq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionLeq::ElementType>& AstBinaryExpressionLeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionLeq::ElementType>& AstBinaryExpressionLeq::container() const {
    return _vecElements;
}
AstBinaryExpressionLeq::ElementType AstBinaryExpressionLeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionLeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionLeq::toString() const {
    std::string s = "(binary_expression_leq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstAtAsterisk::AstAtAsterisk() { }
void AstAtAsterisk::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstAtAsterisk::ElementType>& AstAtAsterisk::container() {
    return _vecElements;
}
const std::vector<AstAtAsterisk::ElementType>& AstAtAsterisk::container() const {
    return _vecElements;
}
AstAtAsterisk::ElementType AstAtAsterisk::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstAtAsterisk::element_size() const
  { return _vecElements.size(); }
std::string AstAtAsterisk::toString() const {
    std::string s = "(at_asterisk";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstRegLvalue::AstRegLvalue(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstRegLvalue::AstRegLvalue(AstSelectIdentifierHandle pSelectIdentifier)
  : _pSelectIdentifier(pSelectIdentifier)
  { }
AstRegLvalue::AstRegLvalue(AstConcatenationHandle pAstConcatenation)
  : _pAstConcatenation(pAstConcatenation)
  { }
AstIdentifierHandle AstRegLvalue::identifier() const
  { return _pIdentifier; }
AstSelectIdentifierHandle AstRegLvalue::select_identifier() const
  { return _pSelectIdentifier; }
AstConcatenationHandle AstRegLvalue::concatenation() const
  { return _pAstConcatenation; }
std::string AstRegLvalue::toString() const {
    std::string s = "(reg_lvalue";
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (select_identifier().valid())
        s = s + " " + select_identifier()->toString();
    if (concatenation().valid())
        s = s + " " + concatenation()->toString();
        s += ")";    return s;
}
AstBinaryOperatorAnd::AstBinaryOperatorAnd() { }
void AstBinaryOperatorAnd::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorAnd::ElementType>& AstBinaryOperatorAnd::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorAnd::ElementType>& AstBinaryOperatorAnd::container() const {
    return _vecElements;
}
AstBinaryOperatorAnd::ElementType AstBinaryOperatorAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorAnd::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorAnd::toString() const {
    std::string s = "(binary_operator_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstAtEventOrAsterisk::AstAtEventOrAsterisk() { }
void AstAtEventOrAsterisk::push_back(AstEventOrAsteriskHandle pEventOrAsterisk0) {
    _vecElements.push_back(ElementType(pEventOrAsterisk0));
}
std::vector<AstAtEventOrAsterisk::ElementType>& AstAtEventOrAsterisk::container() {
    return _vecElements;
}
const std::vector<AstAtEventOrAsterisk::ElementType>& AstAtEventOrAsterisk::container() const {
    return _vecElements;
}
AstAtEventOrAsterisk::ElementType AstAtEventOrAsterisk::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstAtEventOrAsterisk::element_size() const
  { return _vecElements.size(); }
std::string AstAtEventOrAsterisk::toString() const {
    std::string s = "(at_event_or_asterisk";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEventOrAsterisk0->toString();
    }
        s += ")";    return s;
}
AstKeywordDefault::AstKeywordDefault(const std::string & s)
  : _keyword_default(s)
  { }
std::string AstKeywordDefault::keyword_default() const
  { return _keyword_default; }
std::string AstKeywordDefault::toString() const
  { return "(keyword_default " + keyword_default() + ")";}
AstBinaryExpressionShiftRight::AstBinaryExpressionShiftRight() { }
void AstBinaryExpressionShiftRight::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionShiftRight::ElementType>& AstBinaryExpressionShiftRight::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionShiftRight::ElementType>& AstBinaryExpressionShiftRight::container() const {
    return _vecElements;
}
AstBinaryExpressionShiftRight::ElementType AstBinaryExpressionShiftRight::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionShiftRight::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionShiftRight::toString() const {
    std::string s = "(binary_expression_shift_right";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstListOfNamedPortConnection::AstListOfNamedPortConnection() { }
void AstListOfNamedPortConnection::push_back(AstNamedPortConnectionHandle pNamedPortConnection0, AstZeroOrMoreCommaNamedPortConnectionHandle pZeroOrMoreCommaNamedPortConnection1) {
    _vecElements.push_back(ElementType(pNamedPortConnection0, pZeroOrMoreCommaNamedPortConnection1));
}
std::vector<AstListOfNamedPortConnection::ElementType>& AstListOfNamedPortConnection::container() {
    return _vecElements;
}
const std::vector<AstListOfNamedPortConnection::ElementType>& AstListOfNamedPortConnection::container() const {
    return _vecElements;
}
AstListOfNamedPortConnection::ElementType AstListOfNamedPortConnection::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstListOfNamedPortConnection::element_size() const
  { return _vecElements.size(); }
std::string AstListOfNamedPortConnection::toString() const {
    std::string s = "(list_of_named_port_connection";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNamedPortConnection0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaNamedPortConnection1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorShl::AstBinaryOperatorShl() { }
void AstBinaryOperatorShl::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorShl::ElementType>& AstBinaryOperatorShl::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorShl::ElementType>& AstBinaryOperatorShl::container() const {
    return _vecElements;
}
AstBinaryOperatorShl::ElementType AstBinaryOperatorShl::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorShl::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorShl::toString() const {
    std::string s = "(binary_operator_shl";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstKeywordEndmodule::AstKeywordEndmodule(const std::string & s)
  : _keyword_endmodule(s)
  { }
std::string AstKeywordEndmodule::keyword_endmodule() const
  { return _keyword_endmodule; }
std::string AstKeywordEndmodule::toString() const
  { return "(keyword_endmodule " + keyword_endmodule() + ")";}
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionMultiplyHandle pBinaryExpressionMultiply)
  : _pBinaryExpressionMultiply(pBinaryExpressionMultiply)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionDivideHandle pBinaryExpressionDivide)
  : _pBinaryExpressionDivide(pBinaryExpressionDivide)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionModulusHandle pBinaryExpressionModulus)
  : _pBinaryExpressionModulus(pBinaryExpressionModulus)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionPlusHandle pBinaryExpressionPlus)
  : _pBinaryExpressionPlus(pBinaryExpressionPlus)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionMinusHandle pBinaryExpressionMinus)
  : _pBinaryExpressionMinus(pBinaryExpressionMinus)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionShiftRightHandle pBinaryExpressionShiftRight)
  : _pBinaryExpressionShiftRight(pBinaryExpressionShiftRight)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionShiftLeftHandle pBinaryExpressionShiftLeft)
  : _pBinaryExpressionShiftLeft(pBinaryExpressionShiftLeft)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionGtHandle pBinaryExpressionGt)
  : _pBinaryExpressionGt(pBinaryExpressionGt)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionGeqHandle pBinaryExpressionGeq)
  : _pBinaryExpressionGeq(pBinaryExpressionGeq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionLtHandle pBinaryExpressionLt)
  : _pBinaryExpressionLt(pBinaryExpressionLt)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionLeqHandle pBinaryExpressionLeq)
  : _pBinaryExpressionLeq(pBinaryExpressionLeq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionEqHandle pBinaryExpressionEq)
  : _pBinaryExpressionEq(pBinaryExpressionEq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionNeqHandle pBinaryExpressionNeq)
  : _pBinaryExpressionNeq(pBinaryExpressionNeq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionCaseEqHandle pBinaryExpressionCaseEq)
  : _pBinaryExpressionCaseEq(pBinaryExpressionCaseEq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionCaseNeqHandle pBinaryExpressionCaseNeq)
  : _pBinaryExpressionCaseNeq(pBinaryExpressionCaseNeq)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionBwAndHandle pBinaryExpressionBwAnd)
  : _pBinaryExpressionBwAnd(pBinaryExpressionBwAnd)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionBwXorHandle pBinaryExpressionBwXor)
  : _pBinaryExpressionBwXor(pBinaryExpressionBwXor)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionBwXnorHandle pBinaryExpressionBwXnor)
  : _pBinaryExpressionBwXnor(pBinaryExpressionBwXnor)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionBwNxorHandle pBinaryExpressionBwNxor)
  : _pBinaryExpressionBwNxor(pBinaryExpressionBwNxor)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionBwOrHandle pBinaryExpressionBwOr)
  : _pBinaryExpressionBwOr(pBinaryExpressionBwOr)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionLgAndHandle pBinaryExpressionLgAnd)
  : _pBinaryExpressionLgAnd(pBinaryExpressionLgAnd)
  { }
AstBinaryExpression::AstBinaryExpression(AstBinaryExpressionLgOrHandle pBinaryExpressionLgOr)
  : _pBinaryExpressionLgOr(pBinaryExpressionLgOr)
  { }
AstBinaryExpressionMultiplyHandle AstBinaryExpression::binary_expression_multiply() const
  { return _pBinaryExpressionMultiply; }
AstBinaryExpressionDivideHandle AstBinaryExpression::binary_expression_divide() const
  { return _pBinaryExpressionDivide; }
AstBinaryExpressionModulusHandle AstBinaryExpression::binary_expression_modulus() const
  { return _pBinaryExpressionModulus; }
AstBinaryExpressionPlusHandle AstBinaryExpression::binary_expression_plus() const
  { return _pBinaryExpressionPlus; }
AstBinaryExpressionMinusHandle AstBinaryExpression::binary_expression_minus() const
  { return _pBinaryExpressionMinus; }
AstBinaryExpressionShiftRightHandle AstBinaryExpression::binary_expression_shift_right() const
  { return _pBinaryExpressionShiftRight; }
AstBinaryExpressionShiftLeftHandle AstBinaryExpression::binary_expression_shift_left() const
  { return _pBinaryExpressionShiftLeft; }
AstBinaryExpressionGtHandle AstBinaryExpression::binary_expression_gt() const
  { return _pBinaryExpressionGt; }
AstBinaryExpressionGeqHandle AstBinaryExpression::binary_expression_geq() const
  { return _pBinaryExpressionGeq; }
AstBinaryExpressionLtHandle AstBinaryExpression::binary_expression_lt() const
  { return _pBinaryExpressionLt; }
AstBinaryExpressionLeqHandle AstBinaryExpression::binary_expression_leq() const
  { return _pBinaryExpressionLeq; }
AstBinaryExpressionEqHandle AstBinaryExpression::binary_expression_eq() const
  { return _pBinaryExpressionEq; }
AstBinaryExpressionNeqHandle AstBinaryExpression::binary_expression_neq() const
  { return _pBinaryExpressionNeq; }
AstBinaryExpressionCaseEqHandle AstBinaryExpression::binary_expression_case_eq() const
  { return _pBinaryExpressionCaseEq; }
AstBinaryExpressionCaseNeqHandle AstBinaryExpression::binary_expression_case_neq() const
  { return _pBinaryExpressionCaseNeq; }
AstBinaryExpressionBwAndHandle AstBinaryExpression::binary_expression_bw_and() const
  { return _pBinaryExpressionBwAnd; }
AstBinaryExpressionBwXorHandle AstBinaryExpression::binary_expression_bw_xor() const
  { return _pBinaryExpressionBwXor; }
AstBinaryExpressionBwXnorHandle AstBinaryExpression::binary_expression_bw_xnor() const
  { return _pBinaryExpressionBwXnor; }
AstBinaryExpressionBwNxorHandle AstBinaryExpression::binary_expression_bw_nxor() const
  { return _pBinaryExpressionBwNxor; }
AstBinaryExpressionBwOrHandle AstBinaryExpression::binary_expression_bw_or() const
  { return _pBinaryExpressionBwOr; }
AstBinaryExpressionLgAndHandle AstBinaryExpression::binary_expression_lg_and() const
  { return _pBinaryExpressionLgAnd; }
AstBinaryExpressionLgOrHandle AstBinaryExpression::binary_expression_lg_or() const
  { return _pBinaryExpressionLgOr; }
std::string AstBinaryExpression::toString() const {
    std::string s = "(binary_expression";
    if (binary_expression_multiply().valid())
        s = s + " " + binary_expression_multiply()->toString();
    if (binary_expression_divide().valid())
        s = s + " " + binary_expression_divide()->toString();
    if (binary_expression_modulus().valid())
        s = s + " " + binary_expression_modulus()->toString();
    if (binary_expression_plus().valid())
        s = s + " " + binary_expression_plus()->toString();
    if (binary_expression_minus().valid())
        s = s + " " + binary_expression_minus()->toString();
    if (binary_expression_shift_right().valid())
        s = s + " " + binary_expression_shift_right()->toString();
    if (binary_expression_shift_left().valid())
        s = s + " " + binary_expression_shift_left()->toString();
    if (binary_expression_gt().valid())
        s = s + " " + binary_expression_gt()->toString();
    if (binary_expression_geq().valid())
        s = s + " " + binary_expression_geq()->toString();
    if (binary_expression_lt().valid())
        s = s + " " + binary_expression_lt()->toString();
    if (binary_expression_leq().valid())
        s = s + " " + binary_expression_leq()->toString();
    if (binary_expression_eq().valid())
        s = s + " " + binary_expression_eq()->toString();
    if (binary_expression_neq().valid())
        s = s + " " + binary_expression_neq()->toString();
    if (binary_expression_case_eq().valid())
        s = s + " " + binary_expression_case_eq()->toString();
    if (binary_expression_case_neq().valid())
        s = s + " " + binary_expression_case_neq()->toString();
    if (binary_expression_bw_and().valid())
        s = s + " " + binary_expression_bw_and()->toString();
    if (binary_expression_bw_xor().valid())
        s = s + " " + binary_expression_bw_xor()->toString();
    if (binary_expression_bw_xnor().valid())
        s = s + " " + binary_expression_bw_xnor()->toString();
    if (binary_expression_bw_nxor().valid())
        s = s + " " + binary_expression_bw_nxor()->toString();
    if (binary_expression_bw_or().valid())
        s = s + " " + binary_expression_bw_or()->toString();
    if (binary_expression_lg_and().valid())
        s = s + " " + binary_expression_lg_and()->toString();
    if (binary_expression_lg_or().valid())
        s = s + " " + binary_expression_lg_or()->toString();
        s += ")";    return s;
}
AstBinaryConstantExpressionNeq::AstBinaryConstantExpressionNeq() { }
void AstBinaryConstantExpressionNeq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionNeq::ElementType>& AstBinaryConstantExpressionNeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionNeq::ElementType>& AstBinaryConstantExpressionNeq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionNeq::ElementType AstBinaryConstantExpressionNeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionNeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionNeq::toString() const {
    std::string s = "(binary_constant_expression_neq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstNameOfInstance::AstNameOfInstance() { }
void AstNameOfInstance::push_back(AstIdentifierHandle pIdentifier0, AstZeroOrOneRangeHandle pZeroOrOneRange1) {
    _vecElements.push_back(ElementType(pIdentifier0, pZeroOrOneRange1));
}
std::vector<AstNameOfInstance::ElementType>& AstNameOfInstance::container() {
    return _vecElements;
}
const std::vector<AstNameOfInstance::ElementType>& AstNameOfInstance::container() const {
    return _vecElements;
}
AstNameOfInstance::ElementType AstNameOfInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNameOfInstance::element_size() const
  { return _vecElements.size(); }
std::string AstNameOfInstance::toString() const {
    std::string s = "(name_of_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
    }
        s += ")";    return s;
}
AstConcatenation::AstConcatenation() { }
void AstConcatenation::push_back(AstExpressionHandle pExpression0, AstOneOrMoreCommaExpressionHandle pOneOrMoreCommaExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pOneOrMoreCommaExpression1));
}
std::vector<AstConcatenation::ElementType>& AstConcatenation::container() {
    return _vecElements;
}
const std::vector<AstConcatenation::ElementType>& AstConcatenation::container() const {
    return _vecElements;
}
AstConcatenation::ElementType AstConcatenation::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConcatenation::element_size() const
  { return _vecElements.size(); }
std::string AstConcatenation::toString() const {
    std::string s = "(concatenation";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pOneOrMoreCommaExpression1->toString();
    }
        s += ")";    return s;
}
AstConstantBitSelectIdentifier::AstConstantBitSelectIdentifier() { }
void AstConstantBitSelectIdentifier::push_back(AstIdentifierHandle pIdentifier0, AstConstantBitSelectHandle pConstantBitSelect1) {
    _vecElements.push_back(ElementType(pIdentifier0, pConstantBitSelect1));
}
std::vector<AstConstantBitSelectIdentifier::ElementType>& AstConstantBitSelectIdentifier::container() {
    return _vecElements;
}
const std::vector<AstConstantBitSelectIdentifier::ElementType>& AstConstantBitSelectIdentifier::container() const {
    return _vecElements;
}
AstConstantBitSelectIdentifier::ElementType AstConstantBitSelectIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConstantBitSelectIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstConstantBitSelectIdentifier::toString() const {
    std::string s = "(constant_bit_select_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pConstantBitSelect1->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorPercent::AstBinaryOperatorPercent() { }
void AstBinaryOperatorPercent::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorPercent::ElementType>& AstBinaryOperatorPercent::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorPercent::ElementType>& AstBinaryOperatorPercent::container() const {
    return _vecElements;
}
AstBinaryOperatorPercent::ElementType AstBinaryOperatorPercent::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorPercent::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorPercent::toString() const {
    std::string s = "(binary_operator_percent";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaModuleInstance::AstZeroOrMoreCommaModuleInstance() { }
void AstZeroOrMoreCommaModuleInstance::push_back(AstModuleInstanceHandle pModuleInstance) {
    _vecElements.push_back(ElementType(pModuleInstance));
}
std::vector<AstZeroOrMoreCommaModuleInstance::ElementType>& AstZeroOrMoreCommaModuleInstance::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaModuleInstance::ElementType>& AstZeroOrMoreCommaModuleInstance::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaModuleInstance::ElementType AstZeroOrMoreCommaModuleInstance::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaModuleInstance::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaModuleInstance::toString() const {
    std::string s = "(zero_or_more_comma_module_instance";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pModuleInstance->toString();
    }
        s += ")";    return s;
}
AstPortExpression::AstPortExpression(AstPortReferenceHandle pPortReference)
  : _pPortReference(pPortReference)
  { }
AstPortExpression::AstPortExpression(AstListOfPortReferencesHandle pListOfPortReferences)
  : _pListOfPortReferences(pListOfPortReferences)
  { }
AstPortReferenceHandle AstPortExpression::port_reference() const
  { return _pPortReference; }
AstListOfPortReferencesHandle AstPortExpression::list_of_port_references() const
  { return _pListOfPortReferences; }
std::string AstPortExpression::toString() const {
    std::string s = "(port_expression";
    if (port_reference().valid())
        s = s + " " + port_reference()->toString();
    if (list_of_port_references().valid())
        s = s + " " + list_of_port_references()->toString();
        s += ")";    return s;
}
AstGateInstantiationOutput::AstGateInstantiationOutput() { }
void AstGateInstantiationOutput::push_back(AstNOutputGateTypeHandle pNOutputGateType0, AstNOutputGateInstanceHandle pNOutputGateInstance1, AstZeroOrMoreCommaNOutputGateInstanceHandle pZeroOrMoreCommaNOutputGateInstance2) {
    _vecElements.push_back(ElementType(pNOutputGateType0, pNOutputGateInstance1, pZeroOrMoreCommaNOutputGateInstance2));
}
std::vector<AstGateInstantiationOutput::ElementType>& AstGateInstantiationOutput::container() {
    return _vecElements;
}
const std::vector<AstGateInstantiationOutput::ElementType>& AstGateInstantiationOutput::container() const {
    return _vecElements;
}
AstGateInstantiationOutput::ElementType AstGateInstantiationOutput::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstGateInstantiationOutput::element_size() const
  { return _vecElements.size(); }
std::string AstGateInstantiationOutput::toString() const {
    std::string s = "(gate_instantiation_output";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNOutputGateType0->toString();
        s = s + " " + _vecElements[i]._pNOutputGateInstance1->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreCommaNOutputGateInstance2->toString();
    }
        s += ")";    return s;
}
AstEventCommaEvent::AstEventCommaEvent() { }
void AstEventCommaEvent::push_back(AstEventExpressionHandle pEventExpression0, AstEventExpressionHandle pEventExpression1) {
    _vecElements.push_back(ElementType(pEventExpression0, pEventExpression1));
}
std::vector<AstEventCommaEvent::ElementType>& AstEventCommaEvent::container() {
    return _vecElements;
}
const std::vector<AstEventCommaEvent::ElementType>& AstEventCommaEvent::container() const {
    return _vecElements;
}
AstEventCommaEvent::ElementType AstEventCommaEvent::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstEventCommaEvent::element_size() const
  { return _vecElements.size(); }
std::string AstEventCommaEvent::toString() const {
    std::string s = "(event_comma_event";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEventExpression0->toString();
        s = s + " " + _vecElements[i]._pEventExpression1->toString();
    }
        s += ")";    return s;
}
AstBinaryConstantExpressionCaseEq::AstBinaryConstantExpressionCaseEq() { }
void AstBinaryConstantExpressionCaseEq::push_back(AstConstantExpressionHandle pConstantExpression0, AstConstantExpressionHandle pConstantExpression1) {
    _vecElements.push_back(ElementType(pConstantExpression0, pConstantExpression1));
}
std::vector<AstBinaryConstantExpressionCaseEq::ElementType>& AstBinaryConstantExpressionCaseEq::container() {
    return _vecElements;
}
const std::vector<AstBinaryConstantExpressionCaseEq::ElementType>& AstBinaryConstantExpressionCaseEq::container() const {
    return _vecElements;
}
AstBinaryConstantExpressionCaseEq::ElementType AstBinaryConstantExpressionCaseEq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryConstantExpressionCaseEq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryConstantExpressionCaseEq::toString() const {
    std::string s = "(binary_constant_expression_case_eq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pConstantExpression0->toString();
        s = s + " " + _vecElements[i]._pConstantExpression1->toString();
    }
        s += ")";    return s;
}
AstPortReference::AstPortReference(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstPortReference::AstPortReference(AstConstantBitSelectIdentifierHandle pConstantBitSelectIdentifier)
  : _pConstantBitSelectIdentifier(pConstantBitSelectIdentifier)
  { }
AstPortReference::AstPortReference(AstConstantRangeSelectIdentifierHandle pConstantRangeSelectIdentifier)
  : _pConstantRangeSelectIdentifier(pConstantRangeSelectIdentifier)
  { }
AstIdentifierHandle AstPortReference::identifier() const
  { return _pIdentifier; }
AstConstantBitSelectIdentifierHandle AstPortReference::constant_bit_select_identifier() const
  { return _pConstantBitSelectIdentifier; }
AstConstantRangeSelectIdentifierHandle AstPortReference::constant_range_select_identifier() const
  { return _pConstantRangeSelectIdentifier; }
std::string AstPortReference::toString() const {
    std::string s = "(port_reference";
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (constant_bit_select_identifier().valid())
        s = s + " " + constant_bit_select_identifier()->toString();
    if (constant_range_select_identifier().valid())
        s = s + " " + constant_range_select_identifier()->toString();
        s += ")";    return s;
}
AstElseStatementOrNull::AstElseStatementOrNull() { }
void AstElseStatementOrNull::push_back(AstKeywordElseHandle pKeywordElse0, AstStatementOrNullHandle pStatementOrNull1) {
    _vecElements.push_back(ElementType(pKeywordElse0, pStatementOrNull1));
}
std::vector<AstElseStatementOrNull::ElementType>& AstElseStatementOrNull::container() {
    return _vecElements;
}
const std::vector<AstElseStatementOrNull::ElementType>& AstElseStatementOrNull::container() const {
    return _vecElements;
}
AstElseStatementOrNull::ElementType AstElseStatementOrNull::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstElseStatementOrNull::element_size() const
  { return _vecElements.size(); }
std::string AstElseStatementOrNull::toString() const {
    std::string s = "(else_statement_or_null";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pKeywordElse0->toString();
        s = s + " " + _vecElements[i]._pStatementOrNull1->toString();
    }
        s += ")";    return s;
}
AstBinaryExpressionShiftLeft::AstBinaryExpressionShiftLeft() { }
void AstBinaryExpressionShiftLeft::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionShiftLeft::ElementType>& AstBinaryExpressionShiftLeft::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionShiftLeft::ElementType>& AstBinaryExpressionShiftLeft::container() const {
    return _vecElements;
}
AstBinaryExpressionShiftLeft::ElementType AstBinaryExpressionShiftLeft::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionShiftLeft::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionShiftLeft::toString() const {
    std::string s = "(binary_expression_shift_left";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstPrimary::AstPrimary(AstSelectIdentifierHandle pSelectIdentifier)
  : _pSelectIdentifier(pSelectIdentifier)
  { }
AstPrimary::AstPrimary(AstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
AstPrimary::AstPrimary(AstNumberHandle pNumber)
  : _pNumber(pNumber)
  { }
AstPrimary::AstPrimary(AstConcatenationHandle pAstConcatenation)
  : _pAstConcatenation(pAstConcatenation)
  { }
AstPrimary::AstPrimary(AstMultipleConcatenationHandle pMulitpleConcatenation)
  : _pMulitpleConcatenation(pMulitpleConcatenation)
  { }
AstSelectIdentifierHandle AstPrimary::select_identifier() const
  { return _pSelectIdentifier; }
AstIdentifierHandle AstPrimary::identifier() const
  { return _pIdentifier; }
AstNumberHandle AstPrimary::number() const
  { return _pNumber; }
AstConcatenationHandle AstPrimary::concatenation() const
  { return _pAstConcatenation; }
AstMultipleConcatenationHandle AstPrimary::multiple_concatenation() const
  { return _pMulitpleConcatenation; }
std::string AstPrimary::toString() const {
    std::string s = "(primary";
    if (select_identifier().valid())
        s = s + " " + select_identifier()->toString();
    if (identifier().valid())
        s = s + " " + identifier()->toString();
    if (number().valid())
        s = s + " " + number()->toString();
    if (concatenation().valid())
        s = s + " " + concatenation()->toString();
    if (multiple_concatenation().valid())
        s = s + " " + multiple_concatenation()->toString();
        s += ")";    return s;
}
AstBinaryExpressionCaseNeq::AstBinaryExpressionCaseNeq() { }
void AstBinaryExpressionCaseNeq::push_back(AstExpressionHandle pExpression0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pExpression0, pExpression1));
}
std::vector<AstBinaryExpressionCaseNeq::ElementType>& AstBinaryExpressionCaseNeq::container() {
    return _vecElements;
}
const std::vector<AstBinaryExpressionCaseNeq::ElementType>& AstBinaryExpressionCaseNeq::container() const {
    return _vecElements;
}
AstBinaryExpressionCaseNeq::ElementType AstBinaryExpressionCaseNeq::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryExpressionCaseNeq::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryExpressionCaseNeq::toString() const {
    std::string s = "(binary_expression_case_neq";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstOrderedPortConnection::AstOrderedPortConnection(AstZeroOrOneExpressionHandle pZeroOrOneExpression)
  : _pZeroOrOneExpression(pZeroOrOneExpression)
  { }
AstZeroOrOneExpressionHandle AstOrderedPortConnection::zero_or_one_expression() const
  { return _pZeroOrOneExpression; }
std::string AstOrderedPortConnection::toString() const {
    std::string s = "(ordered_port_connection";
    if (zero_or_one_expression().valid())
        s = s + " " + zero_or_one_expression()->toString();
        s += ")";    return s;
}
AstParamAssignment::AstParamAssignment() { }
void AstParamAssignment::push_back(AstIdentifierHandle pIdentifier0, AstExpressionHandle pExpression1) {
    _vecElements.push_back(ElementType(pIdentifier0, pExpression1));
}
std::vector<AstParamAssignment::ElementType>& AstParamAssignment::container() {
    return _vecElements;
}
const std::vector<AstParamAssignment::ElementType>& AstParamAssignment::container() const {
    return _vecElements;
}
AstParamAssignment::ElementType AstParamAssignment::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstParamAssignment::element_size() const
  { return _vecElements.size(); }
std::string AstParamAssignment::toString() const {
    std::string s = "(param_assignment";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pExpression1->toString();
    }
        s += ")";    return s;
}
AstKeywordInOut::AstKeywordInOut(const std::string & s)
  : _keyword_inout(s)
  { }
std::string AstKeywordInOut::keyword_inout() const
  { return _keyword_inout; }
std::string AstKeywordInOut::toString() const
  { return "(keyword_inout " + keyword_inout() + ")";}
AstConstantRangeSelectIdentifier::AstConstantRangeSelectIdentifier() { }
void AstConstantRangeSelectIdentifier::push_back(AstIdentifierHandle pIdentifier0, AstConstantRangeSelectHandle pConstantRangeSelect1) {
    _vecElements.push_back(ElementType(pIdentifier0, pConstantRangeSelect1));
}
std::vector<AstConstantRangeSelectIdentifier::ElementType>& AstConstantRangeSelectIdentifier::container() {
    return _vecElements;
}
const std::vector<AstConstantRangeSelectIdentifier::ElementType>& AstConstantRangeSelectIdentifier::container() const {
    return _vecElements;
}
AstConstantRangeSelectIdentifier::ElementType AstConstantRangeSelectIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstConstantRangeSelectIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstConstantRangeSelectIdentifier::toString() const {
    std::string s = "(constant_range_select_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pConstantRangeSelect1->toString();
    }
        s += ")";    return s;
}
AstBitSelect::AstBitSelect() { }
void AstBitSelect::push_back(AstExpressionHandle pExpression0) {
    _vecElements.push_back(ElementType(pExpression0));
}
std::vector<AstBitSelect::ElementType>& AstBitSelect::container() {
    return _vecElements;
}
const std::vector<AstBitSelect::ElementType>& AstBitSelect::container() const {
    return _vecElements;
}
AstBitSelect::ElementType AstBitSelect::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBitSelect::element_size() const
  { return _vecElements.size(); }
std::string AstBitSelect::toString() const {
    std::string s = "(bit_select";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression0->toString();
    }
        s += ")";    return s;
}
AstKetwordNegedge::AstKetwordNegedge(const std::string & s)
  : _keyword_negedge(s)
  { }
std::string AstKetwordNegedge::keyword_negedge() const
  { return _keyword_negedge; }
std::string AstKetwordNegedge::toString() const
  { return "(keyword_negedge " + keyword_negedge() + ")";}
AstInputTerminal::AstInputTerminal(AstExpressionHandle pExpression)
  : _pExpression(pExpression)
  { }
AstExpressionHandle AstInputTerminal::expression() const
  { return _pExpression; }
std::string AstInputTerminal::toString() const {
    std::string s = "(input_terminal";
    if (expression().valid())
        s = s + " " + expression()->toString();
        s += ")";    return s;
}
AstZeroOrOneListOfPorts::AstZeroOrOneListOfPorts() { }
void AstZeroOrOneListOfPorts::push_back(AstListOfPortsHandle pListOfPorts) {
    _vecElements.push_back(ElementType(pListOfPorts));
}
std::vector<AstZeroOrOneListOfPorts::ElementType>& AstZeroOrOneListOfPorts::container() {
    return _vecElements;
}
const std::vector<AstZeroOrOneListOfPorts::ElementType>& AstZeroOrOneListOfPorts::container() const {
    return _vecElements;
}
AstZeroOrOneListOfPorts::ElementType AstZeroOrOneListOfPorts::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrOneListOfPorts::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrOneListOfPorts::toString() const {
    std::string s = "(zero_or_one_list_of_ports";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pListOfPorts->toString();
    }
        s += ")";    return s;
}
AstPort::AstPort(AstPortExpressionHandle pPortExpression)
  : _pPortExpression(pPortExpression)
  { }
AstPort::AstPort(AstNamedPortExpressionHandle pNamedPortExpression)
  : _pNamedPortExpression(pNamedPortExpression)
  { }
AstPortExpressionHandle AstPort::port_expression() const
  { return _pPortExpression; }
AstNamedPortExpressionHandle AstPort::named_port_expression() const
  { return _pNamedPortExpression; }
std::string AstPort::toString() const {
    std::string s = "(port";
    if (port_expression().valid())
        s = s + " " + port_expression()->toString();
    if (named_port_expression().valid())
        s = s + " " + named_port_expression()->toString();
        s += ")";    return s;
}
AstOneOrMoreDescription::AstOneOrMoreDescription() { }
void AstOneOrMoreDescription::push_back(AstDescriptionHandle pDescription0) {
    _vecElements.push_back(ElementType(pDescription0));
}
std::vector<AstOneOrMoreDescription::ElementType>& AstOneOrMoreDescription::container() {
    return _vecElements;
}
const std::vector<AstOneOrMoreDescription::ElementType>& AstOneOrMoreDescription::container() const {
    return _vecElements;
}
AstOneOrMoreDescription::ElementType AstOneOrMoreDescription::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstOneOrMoreDescription::element_size() const
  { return _vecElements.size(); }
std::string AstOneOrMoreDescription::toString() const {
    std::string s = "(one_or_more_description";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pDescription0->toString();
    }
        s += ")";    return s;
}
AstBinaryOperatorAsterisk::AstBinaryOperatorAsterisk() { }
void AstBinaryOperatorAsterisk::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorAsterisk::ElementType>& AstBinaryOperatorAsterisk::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorAsterisk::ElementType>& AstBinaryOperatorAsterisk::container() const {
    return _vecElements;
}
AstBinaryOperatorAsterisk::ElementType AstBinaryOperatorAsterisk::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorAsterisk::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorAsterisk::toString() const {
    std::string s = "(binary_operator_asterisk";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstZeroOrMoreCommaExpression::AstZeroOrMoreCommaExpression() { }
void AstZeroOrMoreCommaExpression::push_back(AstExpressionHandle pExpression) {
    _vecElements.push_back(ElementType(pExpression));
}
std::vector<AstZeroOrMoreCommaExpression::ElementType>& AstZeroOrMoreCommaExpression::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreCommaExpression::ElementType>& AstZeroOrMoreCommaExpression::container() const {
    return _vecElements;
}
AstZeroOrMoreCommaExpression::ElementType AstZeroOrMoreCommaExpression::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreCommaExpression::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreCommaExpression::toString() const {
    std::string s = "(zero_or_more_comma_expression";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pExpression->toString();
    }
        s += ")";    return s;
}
AstAtIdentifier::AstAtIdentifier() { }
void AstAtIdentifier::push_back(AstIdentifierHandle pIdentifier0) {
    _vecElements.push_back(ElementType(pIdentifier0));
}
std::vector<AstAtIdentifier::ElementType>& AstAtIdentifier::container() {
    return _vecElements;
}
const std::vector<AstAtIdentifier::ElementType>& AstAtIdentifier::container() const {
    return _vecElements;
}
AstAtIdentifier::ElementType AstAtIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstAtIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstAtIdentifier::toString() const {
    std::string s = "(at_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
    }
        s += ")";    return s;
}
AstKeywordInput::AstKeywordInput(const std::string & s)
  : _keyword_input(s)
  { }
std::string AstKeywordInput::keyword_input() const
  { return _keyword_input; }
std::string AstKeywordInput::toString() const
  { return "(keyword_input " + keyword_input() + ")";}
AstBinaryOperatorXorNeg::AstBinaryOperatorXorNeg() { }
void AstBinaryOperatorXorNeg::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorXorNeg::ElementType>& AstBinaryOperatorXorNeg::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorXorNeg::ElementType>& AstBinaryOperatorXorNeg::container() const {
    return _vecElements;
}
AstBinaryOperatorXorNeg::ElementType AstBinaryOperatorXorNeg::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorXorNeg::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorXorNeg::toString() const {
    std::string s = "(binary_operator_xor_neg";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstZeroOrMoreDotSingleIdentifier::AstZeroOrMoreDotSingleIdentifier() { }
void AstZeroOrMoreDotSingleIdentifier::push_back(AstSingleIdentifierHandle pSingleIdentifier) {
    _vecElements.push_back(ElementType(pSingleIdentifier));
}
std::vector<AstZeroOrMoreDotSingleIdentifier::ElementType>& AstZeroOrMoreDotSingleIdentifier::container() {
    return _vecElements;
}
const std::vector<AstZeroOrMoreDotSingleIdentifier::ElementType>& AstZeroOrMoreDotSingleIdentifier::container() const {
    return _vecElements;
}
AstZeroOrMoreDotSingleIdentifier::ElementType AstZeroOrMoreDotSingleIdentifier::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstZeroOrMoreDotSingleIdentifier::element_size() const
  { return _vecElements.size(); }
std::string AstZeroOrMoreDotSingleIdentifier::toString() const {
    std::string s = "(zero_or_more_dot_single_identifier";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pSingleIdentifier->toString();
    }
        s += ")";    return s;
}
AstUnaryOperatorOr::AstUnaryOperatorOr() { }
void AstUnaryOperatorOr::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstUnaryOperatorOr::ElementType>& AstUnaryOperatorOr::container() {
    return _vecElements;
}
const std::vector<AstUnaryOperatorOr::ElementType>& AstUnaryOperatorOr::container() const {
    return _vecElements;
}
AstUnaryOperatorOr::ElementType AstUnaryOperatorOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstUnaryOperatorOr::element_size() const
  { return _vecElements.size(); }
std::string AstUnaryOperatorOr::toString() const {
    std::string s = "(unary_operator_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstBinaryOperatorGt::AstBinaryOperatorGt() { }
void AstBinaryOperatorGt::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<AstBinaryOperatorGt::ElementType>& AstBinaryOperatorGt::container() {
    return _vecElements;
}
const std::vector<AstBinaryOperatorGt::ElementType>& AstBinaryOperatorGt::container() const {
    return _vecElements;
}
AstBinaryOperatorGt::ElementType AstBinaryOperatorGt::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstBinaryOperatorGt::element_size() const
  { return _vecElements.size(); }
std::string AstBinaryOperatorGt::toString() const {
    std::string s = "(binary_operator_gt";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
AstNetDeclaration::AstNetDeclaration() { }
void AstNetDeclaration::push_back(AstNetTypeHandle pNetType0, AstZeroOrOneRangeHandle pZeroOrOneRange1, AstListOfNetIdentifierHandle pListOfNetIdentifier2) {
    _vecElements.push_back(ElementType(pNetType0, pZeroOrOneRange1, pListOfNetIdentifier2));
}
std::vector<AstNetDeclaration::ElementType>& AstNetDeclaration::container() {
    return _vecElements;
}
const std::vector<AstNetDeclaration::ElementType>& AstNetDeclaration::container() const {
    return _vecElements;
}
AstNetDeclaration::ElementType AstNetDeclaration::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int AstNetDeclaration::element_size() const
  { return _vecElements.size(); }
std::string AstNetDeclaration::toString() const {
    std::string s = "(net_declaration";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pNetType0->toString();
        s = s + " " + _vecElements[i]._pZeroOrOneRange1->toString();
        s = s + " " + _vecElements[i]._pListOfNetIdentifier2->toString();
    }
        s += ")";    return s;
}
