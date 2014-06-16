#include "CAst.h"
#include "exception/Exception.h"
#include <sstream>
#include <algorithm>

CAst::~CAst() { }
std::string CAst::toString() const {
    throw NotOverridenException();
}
CAstHandle CAst::base_handle() const {
    throw NotOverridenException();
}
CAstBoolConstant::CAstBoolConstant() { }
void CAstBoolConstant::push_back(CAstIdentifierHandle pIdentifier0, CAstConstantHandle pConstant1) {
    _vecElements.push_back(ElementType(pIdentifier0, pConstant1));
}
std::vector<CAstBoolConstant::ElementType>& CAstBoolConstant::container() {
    return _vecElements;
}
const std::vector<CAstBoolConstant::ElementType>& CAstBoolConstant::container() const {
    return _vecElements;
}
CAstBoolConstant::ElementType CAstBoolConstant::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolConstant::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolConstant::toString() const {
    std::string s = "(bool_constant";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
        s = s + " " + _vecElements[i]._pConstant1->toString();
    }
        s += ")";    return s;
}
CAstOnlyRWCWithoutGoto::CAstOnlyRWCWithoutGoto() { }
void CAstOnlyRWCWithoutGoto::push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement1) {
    _vecElements.push_back(ElementType(pIfStatementPrefix0, pReadOrWriteOrCheckStatement1));
}
std::vector<CAstOnlyRWCWithoutGoto::ElementType>& CAstOnlyRWCWithoutGoto::container() {
    return _vecElements;
}
const std::vector<CAstOnlyRWCWithoutGoto::ElementType>& CAstOnlyRWCWithoutGoto::container() const {
    return _vecElements;
}
CAstOnlyRWCWithoutGoto::ElementType CAstOnlyRWCWithoutGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstOnlyRWCWithoutGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstOnlyRWCWithoutGoto::toString() const {
    std::string s = "(only_rwc_without_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIfStatementPrefix0->toString();
        s = s + " " + _vecElements[i]._pReadOrWriteOrCheckStatement1->toString();
    }
        s += ")";    return s;
}
CAstBoolWithParenthesis::CAstBoolWithParenthesis() { }
void CAstBoolWithParenthesis::push_back(CAstBoolExpressionHandle pBoolExpression0) {
    _vecElements.push_back(ElementType(pBoolExpression0));
}
std::vector<CAstBoolWithParenthesis::ElementType>& CAstBoolWithParenthesis::container() {
    return _vecElements;
}
const std::vector<CAstBoolWithParenthesis::ElementType>& CAstBoolWithParenthesis::container() const {
    return _vecElements;
}
CAstBoolWithParenthesis::ElementType CAstBoolWithParenthesis::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolWithParenthesis::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolWithParenthesis::toString() const {
    std::string s = "(bool_with_parenthesis";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
    }
        s += ")";    return s;
}
CAstZeroOrMoreAll::CAstZeroOrMoreAll() { }
void CAstZeroOrMoreAll::push_back(CAstAllUpdateStatementHandle pAllUpdateStatement) {
    _vecElements.push_back(ElementType(pAllUpdateStatement));
}
std::vector<CAstZeroOrMoreAll::ElementType>& CAstZeroOrMoreAll::container() {
    return _vecElements;
}
const std::vector<CAstZeroOrMoreAll::ElementType>& CAstZeroOrMoreAll::container() const {
    return _vecElements;
}
CAstZeroOrMoreAll::ElementType CAstZeroOrMoreAll::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstZeroOrMoreAll::element_size() const
  { return _vecElements.size(); }
std::string CAstZeroOrMoreAll::toString() const {
    std::string s = "(zero_or_more_all";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pAllUpdateStatement->toString();
    }
        s += ")";    return s;
}
CAstReadStatement::CAstReadStatement() { }
void CAstReadStatement::push_back(CAstIdentifierHandle pIdentifier0) {
    _vecElements.push_back(ElementType(pIdentifier0));
}
std::vector<CAstReadStatement::ElementType>& CAstReadStatement::container() {
    return _vecElements;
}
const std::vector<CAstReadStatement::ElementType>& CAstReadStatement::container() const {
    return _vecElements;
}
CAstReadStatement::ElementType CAstReadStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstReadStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstReadStatement::toString() const {
    std::string s = "(read_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
    }
        s += ")";    return s;
}
CAstBoolNot::CAstBoolNot() { }
void CAstBoolNot::push_back(CAstBoolExpressionHandle pBoolExpression0) {
    _vecElements.push_back(ElementType(pBoolExpression0));
}
std::vector<CAstBoolNot::ElementType>& CAstBoolNot::container() {
    return _vecElements;
}
const std::vector<CAstBoolNot::ElementType>& CAstBoolNot::container() const {
    return _vecElements;
}
CAstBoolNot::ElementType CAstBoolNot::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolNot::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolNot::toString() const {
    std::string s = "(bool_not";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
    }
        s += ")";    return s;
}
CAstBitLiteral::CAstBitLiteral(const std::string & s)
  : _bit_literal(s)
  { }
std::string CAstBitLiteral::bit_literal() const
  { return _bit_literal; }
std::string CAstBitLiteral::toString() const
  { return "(bit_literal " + bit_literal() + ")";}
CAstMultiWithoutGoto::CAstMultiWithoutGoto() { }
void CAstMultiWithoutGoto::push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific1) {
    _vecElements.push_back(ElementType(pIfStatementPrefix0, pZeroOrMoreSpecific1));
}
std::vector<CAstMultiWithoutGoto::ElementType>& CAstMultiWithoutGoto::container() {
    return _vecElements;
}
const std::vector<CAstMultiWithoutGoto::ElementType>& CAstMultiWithoutGoto::container() const {
    return _vecElements;
}
CAstMultiWithoutGoto::ElementType CAstMultiWithoutGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstMultiWithoutGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstMultiWithoutGoto::toString() const {
    std::string s = "(multi_without_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIfStatementPrefix0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreSpecific1->toString();
    }
        s += ")";    return s;
}
CAstIdentifier::CAstIdentifier(const std::string & s)
  : _identifier(s)
  { }
std::string CAstIdentifier::identifier() const
  { return _identifier; }
std::string CAstIdentifier::toString() const
  { return "(identifier " + identifier() + ")";}
CAstIfStatementPrefix::CAstIfStatementPrefix() { }
void CAstIfStatementPrefix::push_back(CAstBoolExpressionHandle pBoolExpression0) {
    _vecElements.push_back(ElementType(pBoolExpression0));
}
std::vector<CAstIfStatementPrefix::ElementType>& CAstIfStatementPrefix::container() {
    return _vecElements;
}
const std::vector<CAstIfStatementPrefix::ElementType>& CAstIfStatementPrefix::container() const {
    return _vecElements;
}
CAstIfStatementPrefix::ElementType CAstIfStatementPrefix::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstIfStatementPrefix::element_size() const
  { return _vecElements.size(); }
std::string CAstIfStatementPrefix::toString() const {
    std::string s = "(if_statement_prefix";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
    }
        s += ")";    return s;
}
CAstKeywordWrite::CAstKeywordWrite() { }
void CAstKeywordWrite::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordWrite::ElementType>& CAstKeywordWrite::container() {
    return _vecElements;
}
const std::vector<CAstKeywordWrite::ElementType>& CAstKeywordWrite::container() const {
    return _vecElements;
}
CAstKeywordWrite::ElementType CAstKeywordWrite::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordWrite::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordWrite::toString() const {
    std::string s = "(keyword_write";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstEdgeStatement::CAstEdgeStatement(CAstAllIfWithGotoHandle pAllIfWithGoto)
  : _pAllIfWithGoto(pAllIfWithGoto)
  { }
CAstEdgeStatement::CAstEdgeStatement(CAstSpecificEndHandle pSpecificEnd)
  : _pSpecificEnd(pSpecificEnd)
  { }
CAstAllIfWithGotoHandle CAstEdgeStatement::all_if_with_goto() const
  { return _pAllIfWithGoto; }
CAstSpecificEndHandle CAstEdgeStatement::specific_end() const
  { return _pSpecificEnd; }
std::string CAstEdgeStatement::toString() const {
    std::string s = "(edge_statement";
    if (all_if_with_goto().valid())
        s = s + " " + all_if_with_goto()->toString();
    if (specific_end().valid())
        s = s + " " + specific_end()->toString();
        s += ")";    return s;
}
CAstOnlyWithoutGotoWithoutGoto::CAstOnlyWithoutGotoWithoutGoto() { }
void CAstOnlyWithoutGotoWithoutGoto::push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto1) {
    _vecElements.push_back(ElementType(pIfStatementPrefix0, pIfStatementWithoutGoto1));
}
std::vector<CAstOnlyWithoutGotoWithoutGoto::ElementType>& CAstOnlyWithoutGotoWithoutGoto::container() {
    return _vecElements;
}
const std::vector<CAstOnlyWithoutGotoWithoutGoto::ElementType>& CAstOnlyWithoutGotoWithoutGoto::container() const {
    return _vecElements;
}
CAstOnlyWithoutGotoWithoutGoto::ElementType CAstOnlyWithoutGotoWithoutGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstOnlyWithoutGotoWithoutGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstOnlyWithoutGotoWithoutGoto::toString() const {
    std::string s = "(only_without_goto_without_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIfStatementPrefix0->toString();
        s = s + " " + _vecElements[i]._pIfStatementWithoutGoto1->toString();
    }
        s += ")";    return s;
}
CAstFloatingLiteral::CAstFloatingLiteral(const std::string & s)
  : _floating_literal(s)
  { }
std::string CAstFloatingLiteral::floating_literal() const
  { return _floating_literal; }
std::string CAstFloatingLiteral::toString() const
  { return "(floating_literal " + floating_literal() + ")";}
CAstCheckStatement::CAstCheckStatement() { }
void CAstCheckStatement::push_back(CAstBoolExpressionHandle pBoolExpression0) {
    _vecElements.push_back(ElementType(pBoolExpression0));
}
std::vector<CAstCheckStatement::ElementType>& CAstCheckStatement::container() {
    return _vecElements;
}
const std::vector<CAstCheckStatement::ElementType>& CAstCheckStatement::container() const {
    return _vecElements;
}
CAstCheckStatement::ElementType CAstCheckStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstCheckStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstCheckStatement::toString() const {
    std::string s = "(check_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
    }
        s += ")";    return s;
}
CAstKeywordTrue::CAstKeywordTrue() { }
void CAstKeywordTrue::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordTrue::ElementType>& CAstKeywordTrue::container() {
    return _vecElements;
}
const std::vector<CAstKeywordTrue::ElementType>& CAstKeywordTrue::container() const {
    return _vecElements;
}
CAstKeywordTrue::ElementType CAstKeywordTrue::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordTrue::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordTrue::toString() const {
    std::string s = "(keyword_true";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstRWCOrWithoutGoto::CAstRWCOrWithoutGoto(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement)
  : _pReadOrWriteOrCheckStatement(pReadOrWriteOrCheckStatement)
  { }
CAstRWCOrWithoutGoto::CAstRWCOrWithoutGoto(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto)
  : _pIfStatementWithoutGoto(pIfStatementWithoutGoto)
  { }
CAstReadOrWriteOrCheckStatementHandle CAstRWCOrWithoutGoto::read_or_write_or_check_statement() const
  { return _pReadOrWriteOrCheckStatement; }
CAstIfStatementWithoutGotoHandle CAstRWCOrWithoutGoto::if_statement_without_goto() const
  { return _pIfStatementWithoutGoto; }
std::string CAstRWCOrWithoutGoto::toString() const {
    std::string s = "(rwc_or_without_goto";
    if (read_or_write_or_check_statement().valid())
        s = s + " " + read_or_write_or_check_statement()->toString();
    if (if_statement_without_goto().valid())
        s = s + " " + if_statement_without_goto()->toString();
        s += ")";    return s;
}
CAstBoolExpression::CAstBoolExpression(CAstBoolWithParenthesisHandle pBoolWithParenthesis)
  : _pBoolWithParenthesis(pBoolWithParenthesis)
  { }
CAstBoolExpression::CAstBoolExpression(CAstBoolAndHandle pBoolAnd)
  : _pBoolAnd(pBoolAnd)
  { }
CAstBoolExpression::CAstBoolExpression(CAstBoolOrHandle pBoolOr)
  : _pBoolOr(pBoolOr)
  { }
CAstBoolExpression::CAstBoolExpression(CAstBoolXorHandle pBoolXor)
  : _pBoolXor(pBoolXor)
  { }
CAstBoolExpression::CAstBoolExpression(CAstBoolNotHandle pBoolNot)
  : _pBoolNot(pBoolNot)
  { }
CAstBoolExpression::CAstBoolExpression(CAstBoolConstantHandle pBoolConstant)
  : _pBoolConstant(pBoolConstant)
  { }
CAstBoolExpression::CAstBoolExpression(CAstIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
CAstBoolWithParenthesisHandle CAstBoolExpression::bool_with_parenthesis() const
  { return _pBoolWithParenthesis; }
CAstBoolAndHandle CAstBoolExpression::bool_and() const
  { return _pBoolAnd; }
CAstBoolOrHandle CAstBoolExpression::bool_or() const
  { return _pBoolOr; }
CAstBoolXorHandle CAstBoolExpression::bool_xor() const
  { return _pBoolXor; }
CAstBoolNotHandle CAstBoolExpression::bool_not() const
  { return _pBoolNot; }
CAstBoolConstantHandle CAstBoolExpression::bool_constant() const
  { return _pBoolConstant; }
CAstIdentifierHandle CAstBoolExpression::identifier() const
  { return _pIdentifier; }
std::string CAstBoolExpression::toString() const {
    std::string s = "(bool_expression";
    if (bool_with_parenthesis().valid())
        s = s + " " + bool_with_parenthesis()->toString();
    if (bool_and().valid())
        s = s + " " + bool_and()->toString();
    if (bool_or().valid())
        s = s + " " + bool_or()->toString();
    if (bool_xor().valid())
        s = s + " " + bool_xor()->toString();
    if (bool_not().valid())
        s = s + " " + bool_not()->toString();
    if (bool_constant().valid())
        s = s + " " + bool_constant()->toString();
    if (identifier().valid())
        s = s + " " + identifier()->toString();
        s += ")";    return s;
}
CAstWriteStatement::CAstWriteStatement() { }
void CAstWriteStatement::push_back(CAstIdentifierHandle pIdentifier0) {
    _vecElements.push_back(ElementType(pIdentifier0));
}
std::vector<CAstWriteStatement::ElementType>& CAstWriteStatement::container() {
    return _vecElements;
}
const std::vector<CAstWriteStatement::ElementType>& CAstWriteStatement::container() const {
    return _vecElements;
}
CAstWriteStatement::ElementType CAstWriteStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstWriteStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstWriteStatement::toString() const {
    std::string s = "(write_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
    }
        s += ")";    return s;
}
CAstStateLabel::CAstStateLabel() { }
void CAstStateLabel::push_back(CAstIdentifierHandle pIdentifier0) {
    _vecElements.push_back(ElementType(pIdentifier0));
}
std::vector<CAstStateLabel::ElementType>& CAstStateLabel::container() {
    return _vecElements;
}
const std::vector<CAstStateLabel::ElementType>& CAstStateLabel::container() const {
    return _vecElements;
}
CAstStateLabel::ElementType CAstStateLabel::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstStateLabel::element_size() const
  { return _vecElements.size(); }
std::string CAstStateLabel::toString() const {
    std::string s = "(state_label";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
    }
        s += ")";    return s;
}
CAstKeywordGoto::CAstKeywordGoto() { }
void CAstKeywordGoto::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordGoto::ElementType>& CAstKeywordGoto::container() {
    return _vecElements;
}
const std::vector<CAstKeywordGoto::ElementType>& CAstKeywordGoto::container() const {
    return _vecElements;
}
CAstKeywordGoto::ElementType CAstKeywordGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordGoto::toString() const {
    std::string s = "(keyword_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstConstant::CAstConstant(CAstIntegerLiteralHandle pIntegerLiteral)
  : _pIntegerLiteral(pIntegerLiteral)
  { }
CAstConstant::CAstConstant(CAstFloatingLiteralHandle pFloatingLiteral)
  : _pFloatingLiteral(pFloatingLiteral)
  { }
CAstConstant::CAstConstant(CAstBitLiteralHandle pBitLiteral)
  : _pBitLiteral(pBitLiteral)
  { }
CAstIntegerLiteralHandle CAstConstant::integer_literal() const
  { return _pIntegerLiteral; }
CAstFloatingLiteralHandle CAstConstant::floating_literal() const
  { return _pFloatingLiteral; }
CAstBitLiteralHandle CAstConstant::bit_literal() const
  { return _pBitLiteral; }
std::string CAstConstant::toString() const {
    std::string s = "(constant";
    if (integer_literal().valid())
        s = s + " " + integer_literal()->toString();
    if (floating_literal().valid())
        s = s + " " + floating_literal()->toString();
    if (bit_literal().valid())
        s = s + " " + bit_literal()->toString();
        s += ")";    return s;
}
CAstTransitionStatement::CAstTransitionStatement(CAstOneOrMoreEdgeHandle pOneOrMoreEdge)
  : _pOneOrMoreEdge(pOneOrMoreEdge)
  { }
CAstOneOrMoreEdgeHandle CAstTransitionStatement::one_or_more_edge() const
  { return _pOneOrMoreEdge; }
std::string CAstTransitionStatement::toString() const {
    std::string s = "(transition_statement";
    if (one_or_more_edge().valid())
        s = s + " " + one_or_more_edge()->toString();
        s += ")";    return s;
}
CAstSpecificEnd::CAstSpecificEnd() { }
void CAstSpecificEnd::push_back(CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific0, CAstEndStatementHandle pEndStatement1) {
    _vecElements.push_back(ElementType(pZeroOrMoreSpecific0, pEndStatement1));
}
std::vector<CAstSpecificEnd::ElementType>& CAstSpecificEnd::container() {
    return _vecElements;
}
const std::vector<CAstSpecificEnd::ElementType>& CAstSpecificEnd::container() const {
    return _vecElements;
}
CAstSpecificEnd::ElementType CAstSpecificEnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstSpecificEnd::element_size() const
  { return _vecElements.size(); }
std::string CAstSpecificEnd::toString() const {
    std::string s = "(specific_end";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pZeroOrMoreSpecific0->toString();
        s = s + " " + _vecElements[i]._pEndStatement1->toString();
    }
        s += ")";    return s;
}
CAstAllOrEdge::CAstAllOrEdge(CAstAllUpdateStatementHandle pAllUpdateStatement)
  : _pAllUpdateStatement(pAllUpdateStatement)
  { }
CAstAllOrEdge::CAstAllOrEdge(CAstEdgeStatementHandle pEdgeStatement)
  : _pEdgeStatement(pEdgeStatement)
  { }
CAstAllUpdateStatementHandle CAstAllOrEdge::all_update_statement() const
  { return _pAllUpdateStatement; }
CAstEdgeStatementHandle CAstAllOrEdge::edge_statement() const
  { return _pEdgeStatement; }
std::string CAstAllOrEdge::toString() const {
    std::string s = "(all_or_edge";
    if (all_update_statement().valid())
        s = s + " " + all_update_statement()->toString();
    if (edge_statement().valid())
        s = s + " " + edge_statement()->toString();
        s += ")";    return s;
}
CAstOneOrMoreState::CAstOneOrMoreState() { }
void CAstOneOrMoreState::push_back(CAstStateStatementHandle pStateStatement0) {
    _vecElements.push_back(ElementType(pStateStatement0));
}
std::vector<CAstOneOrMoreState::ElementType>& CAstOneOrMoreState::container() {
    return _vecElements;
}
const std::vector<CAstOneOrMoreState::ElementType>& CAstOneOrMoreState::container() const {
    return _vecElements;
}
CAstOneOrMoreState::ElementType CAstOneOrMoreState::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstOneOrMoreState::element_size() const
  { return _vecElements.size(); }
std::string CAstOneOrMoreState::toString() const {
    std::string s = "(one_or_more_state";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pStateStatement0->toString();
    }
        s += ")";    return s;
}
CAstZeroOrMoreRWCOrWithoutGoto::CAstZeroOrMoreRWCOrWithoutGoto() { }
void CAstZeroOrMoreRWCOrWithoutGoto::push_back(CAstRWCOrWithoutGotoHandle pRWCOrWithoutGoto) {
    _vecElements.push_back(ElementType(pRWCOrWithoutGoto));
}
std::vector<CAstZeroOrMoreRWCOrWithoutGoto::ElementType>& CAstZeroOrMoreRWCOrWithoutGoto::container() {
    return _vecElements;
}
const std::vector<CAstZeroOrMoreRWCOrWithoutGoto::ElementType>& CAstZeroOrMoreRWCOrWithoutGoto::container() const {
    return _vecElements;
}
CAstZeroOrMoreRWCOrWithoutGoto::ElementType CAstZeroOrMoreRWCOrWithoutGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstZeroOrMoreRWCOrWithoutGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstZeroOrMoreRWCOrWithoutGoto::toString() const {
    std::string s = "(zero_or_more_rwc_or_without_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pRWCOrWithoutGoto->toString();
    }
        s += ")";    return s;
}
CAstEndStatement::CAstEndStatement(CAstGotoStatementHandle pGotoStatement)
  : _pGotoStatement(pGotoStatement)
  { }
CAstEndStatement::CAstEndStatement(CAstAssertStatementHandle pAssertStatement)
  : _pAssertStatement(pAssertStatement)
  { }
CAstGotoStatementHandle CAstEndStatement::goto_statement() const
  { return _pGotoStatement; }
CAstAssertStatementHandle CAstEndStatement::assert_statement() const
  { return _pAssertStatement; }
std::string CAstEndStatement::toString() const {
    std::string s = "(end_statement";
    if (goto_statement().valid())
        s = s + " " + goto_statement()->toString();
    if (assert_statement().valid())
        s = s + " " + assert_statement()->toString();
        s += ")";    return s;
}
CAstZeroOrMoreRWC::CAstZeroOrMoreRWC() { }
void CAstZeroOrMoreRWC::push_back(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement) {
    _vecElements.push_back(ElementType(pReadOrWriteOrCheckStatement));
}
std::vector<CAstZeroOrMoreRWC::ElementType>& CAstZeroOrMoreRWC::container() {
    return _vecElements;
}
const std::vector<CAstZeroOrMoreRWC::ElementType>& CAstZeroOrMoreRWC::container() const {
    return _vecElements;
}
CAstZeroOrMoreRWC::ElementType CAstZeroOrMoreRWC::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstZeroOrMoreRWC::element_size() const
  { return _vecElements.size(); }
std::string CAstZeroOrMoreRWC::toString() const {
    std::string s = "(zero_or_more_rwc";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pReadOrWriteOrCheckStatement->toString();
    }
        s += ")";    return s;
}
CAstIfStatementWithoutGoto::CAstIfStatementWithoutGoto(CAstOnlyRWCWithoutGotoHandle pOnlyRWCWithoutGoto)
  : _pOnlyRWCWithoutGoto(pOnlyRWCWithoutGoto)
  { }
CAstIfStatementWithoutGoto::CAstIfStatementWithoutGoto(CAstOnlyWithoutGotoWithoutGotoHandle pOnlyWithoutGotoWithoutGoto)
  : _pOnlyWithoutGotoWithoutGoto(pOnlyWithoutGotoWithoutGoto)
  { }
CAstIfStatementWithoutGoto::CAstIfStatementWithoutGoto(CAstMultiWithoutGotoHandle pMultiWithoutGoto)
  : _pMultiWithoutGoto(pMultiWithoutGoto)
  { }
CAstOnlyRWCWithoutGotoHandle CAstIfStatementWithoutGoto::only_rwc_without_goto() const
  { return _pOnlyRWCWithoutGoto; }
CAstOnlyWithoutGotoWithoutGotoHandle CAstIfStatementWithoutGoto::only_without_goto_without_goto() const
  { return _pOnlyWithoutGotoWithoutGoto; }
CAstMultiWithoutGotoHandle CAstIfStatementWithoutGoto::multi_without_goto() const
  { return _pMultiWithoutGoto; }
std::string CAstIfStatementWithoutGoto::toString() const {
    std::string s = "(if_statement_without_goto";
    if (only_rwc_without_goto().valid())
        s = s + " " + only_rwc_without_goto()->toString();
    if (only_without_goto_without_goto().valid())
        s = s + " " + only_without_goto_without_goto()->toString();
    if (multi_without_goto().valid())
        s = s + " " + multi_without_goto()->toString();
        s += ")";    return s;
}
CAstSourceText::CAstSourceText(CAstOneOrMoreStateHandle pOneOrMoreState)
  : _pOneOrMoreState(pOneOrMoreState)
  { }
CAstOneOrMoreStateHandle CAstSourceText::one_or_more_state() const
  { return _pOneOrMoreState; }
std::string CAstSourceText::toString() const {
    std::string s = "(source_text";
    if (one_or_more_state().valid())
        s = s + " " + one_or_more_state()->toString();
        s += ")";    return s;
}
CAstIfStatementWithGoto::CAstIfStatementWithGoto(CAstOnlyEndWithGotoHandle pOnlyEndWithGoto)
  : _pOnlyEndWithGoto(pOnlyEndWithGoto)
  { }
CAstIfStatementWithGoto::CAstIfStatementWithGoto(CAstMultiWithGotoHandle pMultiWithGoto)
  : _pMultiWithGoto(pMultiWithGoto)
  { }
CAstOnlyEndWithGotoHandle CAstIfStatementWithGoto::only_end_with_goto() const
  { return _pOnlyEndWithGoto; }
CAstMultiWithGotoHandle CAstIfStatementWithGoto::multi_with_goto() const
  { return _pMultiWithGoto; }
std::string CAstIfStatementWithGoto::toString() const {
    std::string s = "(if_statement_with_goto";
    if (only_end_with_goto().valid())
        s = s + " " + only_end_with_goto()->toString();
    if (multi_with_goto().valid())
        s = s + " " + multi_with_goto()->toString();
        s += ")";    return s;
}
CAstGotoStatement::CAstGotoStatement() { }
void CAstGotoStatement::push_back(CAstIdentifierHandle pIdentifier0) {
    _vecElements.push_back(ElementType(pIdentifier0));
}
std::vector<CAstGotoStatement::ElementType>& CAstGotoStatement::container() {
    return _vecElements;
}
const std::vector<CAstGotoStatement::ElementType>& CAstGotoStatement::container() const {
    return _vecElements;
}
CAstGotoStatement::ElementType CAstGotoStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstGotoStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstGotoStatement::toString() const {
    std::string s = "(goto_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIdentifier0->toString();
    }
        s += ")";    return s;
}
CAstZeroOrMoreAllOrEdge::CAstZeroOrMoreAllOrEdge() { }
void CAstZeroOrMoreAllOrEdge::push_back(CAstAllOrEdgeHandle pAllOrEdge) {
    _vecElements.push_back(ElementType(pAllOrEdge));
}
std::vector<CAstZeroOrMoreAllOrEdge::ElementType>& CAstZeroOrMoreAllOrEdge::container() {
    return _vecElements;
}
const std::vector<CAstZeroOrMoreAllOrEdge::ElementType>& CAstZeroOrMoreAllOrEdge::container() const {
    return _vecElements;
}
CAstZeroOrMoreAllOrEdge::ElementType CAstZeroOrMoreAllOrEdge::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstZeroOrMoreAllOrEdge::element_size() const
  { return _vecElements.size(); }
std::string CAstZeroOrMoreAllOrEdge::toString() const {
    std::string s = "(zero_or_more_all_or_edge";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pAllOrEdge->toString();
    }
        s += ")";    return s;
}
CAstOnlyEndWithGoto::CAstOnlyEndWithGoto() { }
void CAstOnlyEndWithGoto::push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstEndStatementHandle pEndStatement1) {
    _vecElements.push_back(ElementType(pIfStatementPrefix0, pEndStatement1));
}
std::vector<CAstOnlyEndWithGoto::ElementType>& CAstOnlyEndWithGoto::container() {
    return _vecElements;
}
const std::vector<CAstOnlyEndWithGoto::ElementType>& CAstOnlyEndWithGoto::container() const {
    return _vecElements;
}
CAstOnlyEndWithGoto::ElementType CAstOnlyEndWithGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstOnlyEndWithGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstOnlyEndWithGoto::toString() const {
    std::string s = "(only_end_with_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIfStatementPrefix0->toString();
        s = s + " " + _vecElements[i]._pEndStatement1->toString();
    }
        s += ")";    return s;
}
CAstKeywordIf::CAstKeywordIf() { }
void CAstKeywordIf::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordIf::ElementType>& CAstKeywordIf::container() {
    return _vecElements;
}
const std::vector<CAstKeywordIf::ElementType>& CAstKeywordIf::container() const {
    return _vecElements;
}
CAstKeywordIf::ElementType CAstKeywordIf::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordIf::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordIf::toString() const {
    std::string s = "(keyword_if";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstBoolAnd::CAstBoolAnd() { }
void CAstBoolAnd::push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
    _vecElements.push_back(ElementType(pBoolExpression0, pBoolExpression1));
}
std::vector<CAstBoolAnd::ElementType>& CAstBoolAnd::container() {
    return _vecElements;
}
const std::vector<CAstBoolAnd::ElementType>& CAstBoolAnd::container() const {
    return _vecElements;
}
CAstBoolAnd::ElementType CAstBoolAnd::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolAnd::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolAnd::toString() const {
    std::string s = "(bool_and";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
        s = s + " " + _vecElements[i]._pBoolExpression1->toString();
    }
        s += ")";    return s;
}
CAstStateStatement::CAstStateStatement() { }
void CAstStateStatement::push_back(CAstStateLabelHandle pStateLabel0, CAstTransitionStatementHandle pTransitionStatement1) {
    _vecElements.push_back(ElementType(pStateLabel0, pTransitionStatement1));
}
std::vector<CAstStateStatement::ElementType>& CAstStateStatement::container() {
    return _vecElements;
}
const std::vector<CAstStateStatement::ElementType>& CAstStateStatement::container() const {
    return _vecElements;
}
CAstStateStatement::ElementType CAstStateStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstStateStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstStateStatement::toString() const {
    std::string s = "(state_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pStateLabel0->toString();
        s = s + " " + _vecElements[i]._pTransitionStatement1->toString();
    }
        s += ")";    return s;
}
CAstKeywordElse::CAstKeywordElse() { }
void CAstKeywordElse::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordElse::ElementType>& CAstKeywordElse::container() {
    return _vecElements;
}
const std::vector<CAstKeywordElse::ElementType>& CAstKeywordElse::container() const {
    return _vecElements;
}
CAstKeywordElse::ElementType CAstKeywordElse::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordElse::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordElse::toString() const {
    std::string s = "(keyword_else";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstKeywordCheck::CAstKeywordCheck() { }
void CAstKeywordCheck::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordCheck::ElementType>& CAstKeywordCheck::container() {
    return _vecElements;
}
const std::vector<CAstKeywordCheck::ElementType>& CAstKeywordCheck::container() const {
    return _vecElements;
}
CAstKeywordCheck::ElementType CAstKeywordCheck::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordCheck::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordCheck::toString() const {
    std::string s = "(keyword_check";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstReadOrWriteOrCheckStatement::CAstReadOrWriteOrCheckStatement(CAstReadStatementHandle pReadStatement)
  : _pReadStatement(pReadStatement)
  { }
CAstReadOrWriteOrCheckStatement::CAstReadOrWriteOrCheckStatement(CAstWriteStatementHandle pWriteStatement)
  : _pWriteStatement(pWriteStatement)
  { }
CAstReadOrWriteOrCheckStatement::CAstReadOrWriteOrCheckStatement(CAstCheckStatementHandle pCheckStatement)
  : _pCheckStatement(pCheckStatement)
  { }
CAstReadStatementHandle CAstReadOrWriteOrCheckStatement::read_statement() const
  { return _pReadStatement; }
CAstWriteStatementHandle CAstReadOrWriteOrCheckStatement::write_statement() const
  { return _pWriteStatement; }
CAstCheckStatementHandle CAstReadOrWriteOrCheckStatement::check_statement() const
  { return _pCheckStatement; }
std::string CAstReadOrWriteOrCheckStatement::toString() const {
    std::string s = "(read_or_write_or_check_statement";
    if (read_statement().valid())
        s = s + " " + read_statement()->toString();
    if (write_statement().valid())
        s = s + " " + write_statement()->toString();
    if (check_statement().valid())
        s = s + " " + check_statement()->toString();
        s += ")";    return s;
}
CAstZeroOrMoreSpecific::CAstZeroOrMoreSpecific() { }
void CAstZeroOrMoreSpecific::push_back(CAstSpecificUpdateStatementHandle pSpecificUpdateStatement) {
    _vecElements.push_back(ElementType(pSpecificUpdateStatement));
}
std::vector<CAstZeroOrMoreSpecific::ElementType>& CAstZeroOrMoreSpecific::container() {
    return _vecElements;
}
const std::vector<CAstZeroOrMoreSpecific::ElementType>& CAstZeroOrMoreSpecific::container() const {
    return _vecElements;
}
CAstZeroOrMoreSpecific::ElementType CAstZeroOrMoreSpecific::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstZeroOrMoreSpecific::element_size() const
  { return _vecElements.size(); }
std::string CAstZeroOrMoreSpecific::toString() const {
    std::string s = "(zero_or_more_specific";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pSpecificUpdateStatement->toString();
    }
        s += ")";    return s;
}
CAstKeywordFalse::CAstKeywordFalse() { }
void CAstKeywordFalse::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordFalse::ElementType>& CAstKeywordFalse::container() {
    return _vecElements;
}
const std::vector<CAstKeywordFalse::ElementType>& CAstKeywordFalse::container() const {
    return _vecElements;
}
CAstKeywordFalse::ElementType CAstKeywordFalse::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordFalse::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordFalse::toString() const {
    std::string s = "(keyword_false";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstBoolOr::CAstBoolOr() { }
void CAstBoolOr::push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
    _vecElements.push_back(ElementType(pBoolExpression0, pBoolExpression1));
}
std::vector<CAstBoolOr::ElementType>& CAstBoolOr::container() {
    return _vecElements;
}
const std::vector<CAstBoolOr::ElementType>& CAstBoolOr::container() const {
    return _vecElements;
}
CAstBoolOr::ElementType CAstBoolOr::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolOr::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolOr::toString() const {
    std::string s = "(bool_or";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
        s = s + " " + _vecElements[i]._pBoolExpression1->toString();
    }
        s += ")";    return s;
}
CAstKeywordAssert::CAstKeywordAssert() { }
void CAstKeywordAssert::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordAssert::ElementType>& CAstKeywordAssert::container() {
    return _vecElements;
}
const std::vector<CAstKeywordAssert::ElementType>& CAstKeywordAssert::container() const {
    return _vecElements;
}
CAstKeywordAssert::ElementType CAstKeywordAssert::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordAssert::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordAssert::toString() const {
    std::string s = "(keyword_assert";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
CAstMultiWithGoto::CAstMultiWithGoto() { }
void CAstMultiWithGoto::push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific1, CAstEndStatementHandle pEndStatement2) {
    _vecElements.push_back(ElementType(pIfStatementPrefix0, pZeroOrMoreSpecific1, pEndStatement2));
}
std::vector<CAstMultiWithGoto::ElementType>& CAstMultiWithGoto::container() {
    return _vecElements;
}
const std::vector<CAstMultiWithGoto::ElementType>& CAstMultiWithGoto::container() const {
    return _vecElements;
}
CAstMultiWithGoto::ElementType CAstMultiWithGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstMultiWithGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstMultiWithGoto::toString() const {
    std::string s = "(multi_with_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIfStatementPrefix0->toString();
        s = s + " " + _vecElements[i]._pZeroOrMoreSpecific1->toString();
        s = s + " " + _vecElements[i]._pEndStatement2->toString();
    }
        s += ")";    return s;
}
CAstBoolXor::CAstBoolXor() { }
void CAstBoolXor::push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
    _vecElements.push_back(ElementType(pBoolExpression0, pBoolExpression1));
}
std::vector<CAstBoolXor::ElementType>& CAstBoolXor::container() {
    return _vecElements;
}
const std::vector<CAstBoolXor::ElementType>& CAstBoolXor::container() const {
    return _vecElements;
}
CAstBoolXor::ElementType CAstBoolXor::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstBoolXor::element_size() const
  { return _vecElements.size(); }
std::string CAstBoolXor::toString() const {
    std::string s = "(bool_xor";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pBoolExpression0->toString();
        s = s + " " + _vecElements[i]._pBoolExpression1->toString();
    }
        s += ")";    return s;
}
CAstAssertStatement::CAstAssertStatement() { }
void CAstAssertStatement::push_back(CAstIntegerLiteralHandle pIntegerLiteral0) {
    _vecElements.push_back(ElementType(pIntegerLiteral0));
}
std::vector<CAstAssertStatement::ElementType>& CAstAssertStatement::container() {
    return _vecElements;
}
const std::vector<CAstAssertStatement::ElementType>& CAstAssertStatement::container() const {
    return _vecElements;
}
CAstAssertStatement::ElementType CAstAssertStatement::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstAssertStatement::element_size() const
  { return _vecElements.size(); }
std::string CAstAssertStatement::toString() const {
    std::string s = "(assert_statement";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pIntegerLiteral0->toString();
    }
        s += ")";    return s;
}
CAstSpecificUpdateStatement::CAstSpecificUpdateStatement(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement)
  : _pReadOrWriteOrCheckStatement(pReadOrWriteOrCheckStatement)
  { }
CAstSpecificUpdateStatement::CAstSpecificUpdateStatement(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto)
  : _pIfStatementWithoutGoto(pIfStatementWithoutGoto)
  { }
CAstReadOrWriteOrCheckStatementHandle CAstSpecificUpdateStatement::read_or_write_or_check_statement() const
  { return _pReadOrWriteOrCheckStatement; }
CAstIfStatementWithoutGotoHandle CAstSpecificUpdateStatement::if_statement_without_goto() const
  { return _pIfStatementWithoutGoto; }
std::string CAstSpecificUpdateStatement::toString() const {
    std::string s = "(specific_update_statement";
    if (read_or_write_or_check_statement().valid())
        s = s + " " + read_or_write_or_check_statement()->toString();
    if (if_statement_without_goto().valid())
        s = s + " " + if_statement_without_goto()->toString();
        s += ")";    return s;
}
CAstAllIfWithGoto::CAstAllIfWithGoto() { }
void CAstAllIfWithGoto::push_back(CAstZeroOrMoreAllHandle pZeroOrMoreAll0, CAstIfStatementWithGotoHandle pIfStatementWithGoto1) {
    _vecElements.push_back(ElementType(pZeroOrMoreAll0, pIfStatementWithGoto1));
}
std::vector<CAstAllIfWithGoto::ElementType>& CAstAllIfWithGoto::container() {
    return _vecElements;
}
const std::vector<CAstAllIfWithGoto::ElementType>& CAstAllIfWithGoto::container() const {
    return _vecElements;
}
CAstAllIfWithGoto::ElementType CAstAllIfWithGoto::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstAllIfWithGoto::element_size() const
  { return _vecElements.size(); }
std::string CAstAllIfWithGoto::toString() const {
    std::string s = "(all_if_with_goto";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pZeroOrMoreAll0->toString();
        s = s + " " + _vecElements[i]._pIfStatementWithGoto1->toString();
    }
        s += ")";    return s;
}
CAstIntegerLiteral::CAstIntegerLiteral(const std::string & s)
  : _integer_literal(s)
  { }
std::string CAstIntegerLiteral::integer_literal() const
  { return _integer_literal; }
std::string CAstIntegerLiteral::toString() const
  { return "(integer_literal " + integer_literal() + ")";}
CAstOneOrMoreEdge::CAstOneOrMoreEdge() { }
void CAstOneOrMoreEdge::push_back(CAstEdgeStatementHandle pEdgeStatement0) {
    _vecElements.push_back(ElementType(pEdgeStatement0));
}
std::vector<CAstOneOrMoreEdge::ElementType>& CAstOneOrMoreEdge::container() {
    return _vecElements;
}
const std::vector<CAstOneOrMoreEdge::ElementType>& CAstOneOrMoreEdge::container() const {
    return _vecElements;
}
CAstOneOrMoreEdge::ElementType CAstOneOrMoreEdge::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstOneOrMoreEdge::element_size() const
  { return _vecElements.size(); }
std::string CAstOneOrMoreEdge::toString() const {
    std::string s = "(one_or_more_edge";
    for (unsigned int i = 0; i < element_size(); ++i) {
        s = s + " " + _vecElements[i]._pEdgeStatement0->toString();
    }
        s += ")";    return s;
}
CAstAllUpdateStatement::CAstAllUpdateStatement(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement)
  : _pReadOrWriteOrCheckStatement(pReadOrWriteOrCheckStatement)
  { }
CAstAllUpdateStatement::CAstAllUpdateStatement(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto)
  : _pIfStatementWithoutGoto(pIfStatementWithoutGoto)
  { }
CAstReadOrWriteOrCheckStatementHandle CAstAllUpdateStatement::read_or_write_or_check_statement() const
  { return _pReadOrWriteOrCheckStatement; }
CAstIfStatementWithoutGotoHandle CAstAllUpdateStatement::if_statement_without_goto() const
  { return _pIfStatementWithoutGoto; }
std::string CAstAllUpdateStatement::toString() const {
    std::string s = "(all_update_statement";
    if (read_or_write_or_check_statement().valid())
        s = s + " " + read_or_write_or_check_statement()->toString();
    if (if_statement_without_goto().valid())
        s = s + " " + if_statement_without_goto()->toString();
        s += ")";    return s;
}
CAstKeywordRead::CAstKeywordRead() { }
void CAstKeywordRead::push_back() {
    _vecElements.push_back(ElementType());
}
std::vector<CAstKeywordRead::ElementType>& CAstKeywordRead::container() {
    return _vecElements;
}
const std::vector<CAstKeywordRead::ElementType>& CAstKeywordRead::container() const {
    return _vecElements;
}
CAstKeywordRead::ElementType CAstKeywordRead::element(unsigned int pos) const {
    assert(pos < element_size());
    return _vecElements[pos];
}
unsigned int CAstKeywordRead::element_size() const
  { return _vecElements.size(); }
std::string CAstKeywordRead::toString() const {
    std::string s = "(keyword_read";
    for (unsigned int i = 0; i < element_size(); ++i) {
    }
        s += ")";    return s;
}
