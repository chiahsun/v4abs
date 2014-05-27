#ifndef CAST_H
#define CAST_H

#include <vector>

#include <string>

#include "nstl/shared_ptr/SharedPtr.h"
#include "exception/Exception.h"

class CAst;
typedef SharedPtr<CAst> CAstHandle;


class CAst {
public:
    virtual ~CAst();
    virtual std::string toString() const;
    virtual CAstHandle base_handle() const;
};
class CAstBoolConstant;
typedef SharedPtr<CAstBoolConstant> CAstBoolConstantHandle;
class CAstOnlyRWCWithoutGoto;
typedef SharedPtr<CAstOnlyRWCWithoutGoto> CAstOnlyRWCWithoutGotoHandle;
class CAstBoolWithParenthesis;
typedef SharedPtr<CAstBoolWithParenthesis> CAstBoolWithParenthesisHandle;
class CAstZeroOrMoreAll;
typedef SharedPtr<CAstZeroOrMoreAll> CAstZeroOrMoreAllHandle;
class CAstReadStatement;
typedef SharedPtr<CAstReadStatement> CAstReadStatementHandle;
class CAstBoolNot;
typedef SharedPtr<CAstBoolNot> CAstBoolNotHandle;
class CAstBitLiteral;
typedef SharedPtr<CAstBitLiteral> CAstBitLiteralHandle;
class CAstMultuWithoutGoto;
typedef SharedPtr<CAstMultuWithoutGoto> CAstMultuWithoutGotoHandle;
class CAstIdentifier;
typedef SharedPtr<CAstIdentifier> CAstIdentifierHandle;
class CAstIfStatementPrefix;
typedef SharedPtr<CAstIfStatementPrefix> CAstIfStatementPrefixHandle;
class CAstKeywordWrite;
typedef SharedPtr<CAstKeywordWrite> CAstKeywordWriteHandle;
class CAstEdgeStatement;
typedef SharedPtr<CAstEdgeStatement> CAstEdgeStatementHandle;
class CAstOnlyWithoutGotoWithoutGoto;
typedef SharedPtr<CAstOnlyWithoutGotoWithoutGoto> CAstOnlyWithoutGotoWithoutGotoHandle;
class CAstFloatingLiteral;
typedef SharedPtr<CAstFloatingLiteral> CAstFloatingLiteralHandle;
class CAstCheckStatement;
typedef SharedPtr<CAstCheckStatement> CAstCheckStatementHandle;
class CAstKeywordTrue;
typedef SharedPtr<CAstKeywordTrue> CAstKeywordTrueHandle;
class CAstRWCOrWithoutGoto;
typedef SharedPtr<CAstRWCOrWithoutGoto> CAstRWCOrWithoutGotoHandle;
class CAstBoolExpression;
typedef SharedPtr<CAstBoolExpression> CAstBoolExpressionHandle;
class CAstWriteStatement;
typedef SharedPtr<CAstWriteStatement> CAstWriteStatementHandle;
class CAstStateLabel;
typedef SharedPtr<CAstStateLabel> CAstStateLabelHandle;
class CAstKeywordGoto;
typedef SharedPtr<CAstKeywordGoto> CAstKeywordGotoHandle;
class CAstConstant;
typedef SharedPtr<CAstConstant> CAstConstantHandle;
class CAstTransitionStatement;
typedef SharedPtr<CAstTransitionStatement> CAstTransitionStatementHandle;
class CAstSpecificEnd;
typedef SharedPtr<CAstSpecificEnd> CAstSpecificEndHandle;
class CAstAllOrEdge;
typedef SharedPtr<CAstAllOrEdge> CAstAllOrEdgeHandle;
class CAstOneOrMoreState;
typedef SharedPtr<CAstOneOrMoreState> CAstOneOrMoreStateHandle;
class CAstZeroOrMoreRWCOrWithoutGoto;
typedef SharedPtr<CAstZeroOrMoreRWCOrWithoutGoto> CAstZeroOrMoreRWCOrWithoutGotoHandle;
class CAstEndStatement;
typedef SharedPtr<CAstEndStatement> CAstEndStatementHandle;
class CAstZeroOrMoreRWC;
typedef SharedPtr<CAstZeroOrMoreRWC> CAstZeroOrMoreRWCHandle;
class CAstIfStatementWithoutGoto;
typedef SharedPtr<CAstIfStatementWithoutGoto> CAstIfStatementWithoutGotoHandle;
class CAstSourceText;
typedef SharedPtr<CAstSourceText> CAstSourceTextHandle;
class CAstIfStatementWithGoto;
typedef SharedPtr<CAstIfStatementWithGoto> CAstIfStatementWithGotoHandle;
class CAstGotoStatement;
typedef SharedPtr<CAstGotoStatement> CAstGotoStatementHandle;
class CAstZeroOrMoreAllOrEdge;
typedef SharedPtr<CAstZeroOrMoreAllOrEdge> CAstZeroOrMoreAllOrEdgeHandle;
class CAstOnlyEndWithGoto;
typedef SharedPtr<CAstOnlyEndWithGoto> CAstOnlyEndWithGotoHandle;
class CAstKeywordIf;
typedef SharedPtr<CAstKeywordIf> CAstKeywordIfHandle;
class CAstBoolAnd;
typedef SharedPtr<CAstBoolAnd> CAstBoolAndHandle;
class CAstStateStatement;
typedef SharedPtr<CAstStateStatement> CAstStateStatementHandle;
class CAstKeywordElse;
typedef SharedPtr<CAstKeywordElse> CAstKeywordElseHandle;
class CAstKeywordCheck;
typedef SharedPtr<CAstKeywordCheck> CAstKeywordCheckHandle;
class CAstReadOrWriteOrCheckStatement;
typedef SharedPtr<CAstReadOrWriteOrCheckStatement> CAstReadOrWriteOrCheckStatementHandle;
class CAstZeroOrMoreSpecific;
typedef SharedPtr<CAstZeroOrMoreSpecific> CAstZeroOrMoreSpecificHandle;
class CAstKeywordFalse;
typedef SharedPtr<CAstKeywordFalse> CAstKeywordFalseHandle;
class CAstBoolOr;
typedef SharedPtr<CAstBoolOr> CAstBoolOrHandle;
class CAstKeywordAssert;
typedef SharedPtr<CAstKeywordAssert> CAstKeywordAssertHandle;
class CAstMultiWithGoto;
typedef SharedPtr<CAstMultiWithGoto> CAstMultiWithGotoHandle;
class CAstBoolXor;
typedef SharedPtr<CAstBoolXor> CAstBoolXorHandle;
class CAstAssertStatement;
typedef SharedPtr<CAstAssertStatement> CAstAssertStatementHandle;
class CAstSpecificUpdateStatement;
typedef SharedPtr<CAstSpecificUpdateStatement> CAstSpecificUpdateStatementHandle;
class CAstAllIfWithGoto;
typedef SharedPtr<CAstAllIfWithGoto> CAstAllIfWithGotoHandle;
class CAstIntegerLiteral;
typedef SharedPtr<CAstIntegerLiteral> CAstIntegerLiteralHandle;
class CAstOneOrMoreEdge;
typedef SharedPtr<CAstOneOrMoreEdge> CAstOneOrMoreEdgeHandle;
class CAstAllUpdateStatement;
typedef SharedPtr<CAstAllUpdateStatement> CAstAllUpdateStatementHandle;
class CAstKeywordRead;
typedef SharedPtr<CAstKeywordRead> CAstKeywordReadHandle;
class CAstBoolConstant
  : public CAst {
    struct ElementType {
        CAstIdentifierHandle _pIdentifier0;
        CAstConstantHandle _pConstant1;
        ElementType(CAstIdentifierHandle pIdentifier0, CAstConstantHandle pConstant1) {
            _pIdentifier0 = pIdentifier0;
            _pConstant1 = pConstant1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolConstant();
    void push_back(CAstIdentifierHandle pIdentifier0, CAstConstantHandle pConstant1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstOnlyRWCWithoutGoto
  : public CAst {
    struct ElementType {
        CAstIfStatementPrefixHandle _pIfStatementPrefix0;
        CAstReadOrWriteOrCheckStatementHandle _pReadOrWriteOrCheckStatement1;
        ElementType(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement1) {
            _pIfStatementPrefix0 = pIfStatementPrefix0;
            _pReadOrWriteOrCheckStatement1 = pReadOrWriteOrCheckStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstOnlyRWCWithoutGoto();
    void push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBoolWithParenthesis
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        ElementType(CAstBoolExpressionHandle pBoolExpression0) {
            _pBoolExpression0 = pBoolExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolWithParenthesis();
    void push_back(CAstBoolExpressionHandle pBoolExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstZeroOrMoreAll
  : public CAst {
    struct ElementType {
        CAstAllUpdateStatementHandle _pAllUpdateStatement;
        ElementType(CAstAllUpdateStatementHandle pAllUpdateStatement) {
            _pAllUpdateStatement = pAllUpdateStatement;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstZeroOrMoreAll();
    void push_back(CAstAllUpdateStatementHandle pAllUpdateStatement);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstReadStatement
  : public CAst {
    struct ElementType {
        CAstIdentifierHandle _pIdentifier0;
        ElementType(CAstIdentifierHandle pIdentifier0) {
            _pIdentifier0 = pIdentifier0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstReadStatement();
    void push_back(CAstIdentifierHandle pIdentifier0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBoolNot
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        ElementType(CAstBoolExpressionHandle pBoolExpression0) {
            _pBoolExpression0 = pBoolExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolNot();
    void push_back(CAstBoolExpressionHandle pBoolExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBitLiteral : public CAst {
    std::string _bit_literal;
public:
    CAstBitLiteral(const std::string & s);
    std::string bit_literal() const;
    std::string toString() const;
};

class CAstMultuWithoutGoto
  : public CAst {
    struct ElementType {
        CAstIfStatementPrefixHandle _pIfStatementPrefix0;
        CAstZeroOrMoreRWCOrWithoutGotoHandle _pZeroOrMoreRWCOrWithoutGoto1;
        ElementType(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreRWCOrWithoutGotoHandle pZeroOrMoreRWCOrWithoutGoto1) {
            _pIfStatementPrefix0 = pIfStatementPrefix0;
            _pZeroOrMoreRWCOrWithoutGoto1 = pZeroOrMoreRWCOrWithoutGoto1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstMultuWithoutGoto();
    void push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreRWCOrWithoutGotoHandle pZeroOrMoreRWCOrWithoutGoto1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstIdentifier : public CAst {
    std::string _identifier;
public:
    CAstIdentifier(const std::string & s);
    std::string identifier() const;
    std::string toString() const;
};

class CAstIfStatementPrefix
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        ElementType(CAstBoolExpressionHandle pBoolExpression0) {
            _pBoolExpression0 = pBoolExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstIfStatementPrefix();
    void push_back(CAstBoolExpressionHandle pBoolExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordWrite
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordWrite();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstEdgeStatement : public CAst {
    CAstAllIfWithGotoHandle _pAllIfWithGoto;
public:
    CAstEdgeStatement(CAstAllIfWithGotoHandle pAllIfWithGoto);
    CAstSpecificEndHandle _pSpecificEnd;
public:
    CAstEdgeStatement(CAstSpecificEndHandle pSpecificEnd);
    CAstAllIfWithGotoHandle all_if_with_goto() const;
    CAstSpecificEndHandle specific_end() const;
    std::string toString() const;
};
class CAstOnlyWithoutGotoWithoutGoto
  : public CAst {
    struct ElementType {
        CAstIfStatementPrefixHandle _pIfStatementPrefix0;
        CAstIfStatementWithoutGotoHandle _pIfStatementWithoutGoto1;
        ElementType(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto1) {
            _pIfStatementPrefix0 = pIfStatementPrefix0;
            _pIfStatementWithoutGoto1 = pIfStatementWithoutGoto1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstOnlyWithoutGotoWithoutGoto();
    void push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstFloatingLiteral : public CAst {
    std::string _floating_literal;
public:
    CAstFloatingLiteral(const std::string & s);
    std::string floating_literal() const;
    std::string toString() const;
};

class CAstCheckStatement
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        ElementType(CAstBoolExpressionHandle pBoolExpression0) {
            _pBoolExpression0 = pBoolExpression0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstCheckStatement();
    void push_back(CAstBoolExpressionHandle pBoolExpression0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordTrue
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordTrue();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstRWCOrWithoutGoto : public CAst {
    CAstReadOrWriteOrCheckStatementHandle _pReadOrWriteOrCheckStatement;
public:
    CAstRWCOrWithoutGoto(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement);
    CAstIfStatementWithoutGotoHandle _pIfStatementWithoutGoto;
public:
    CAstRWCOrWithoutGoto(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto);
    CAstReadOrWriteOrCheckStatementHandle read_or_write_or_check_statement() const;
    CAstIfStatementWithoutGotoHandle if_statement_without_goto() const;
    std::string toString() const;
};
class CAstBoolExpression : public CAst {
    CAstBoolWithParenthesisHandle _pBoolWithParenthesis;
public:
    CAstBoolExpression(CAstBoolWithParenthesisHandle pBoolWithParenthesis);
    CAstBoolAndHandle _pBoolAnd;
public:
    CAstBoolExpression(CAstBoolAndHandle pBoolAnd);
    CAstBoolOrHandle _pBoolOr;
public:
    CAstBoolExpression(CAstBoolOrHandle pBoolOr);
    CAstBoolXorHandle _pBoolXor;
public:
    CAstBoolExpression(CAstBoolXorHandle pBoolXor);
    CAstBoolNotHandle _pBoolNot;
public:
    CAstBoolExpression(CAstBoolNotHandle pBoolNot);
    CAstBoolConstantHandle _pBoolConstant;
public:
    CAstBoolExpression(CAstBoolConstantHandle pBoolConstant);
    CAstIdentifierHandle _pIdentifier;
public:
    CAstBoolExpression(CAstIdentifierHandle pIdentifier);
    CAstBoolWithParenthesisHandle bool_with_parenthesis() const;
    CAstBoolAndHandle bool_and() const;
    CAstBoolOrHandle bool_or() const;
    CAstBoolXorHandle bool_xor() const;
    CAstBoolNotHandle bool_not() const;
    CAstBoolConstantHandle bool_constant() const;
    CAstIdentifierHandle identifier() const;
    std::string toString() const;
};
class CAstWriteStatement
  : public CAst {
    struct ElementType {
        CAstIdentifierHandle _pIdentifier0;
        ElementType(CAstIdentifierHandle pIdentifier0) {
            _pIdentifier0 = pIdentifier0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstWriteStatement();
    void push_back(CAstIdentifierHandle pIdentifier0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstStateLabel
  : public CAst {
    struct ElementType {
        CAstIdentifierHandle _pIdentifier0;
        ElementType(CAstIdentifierHandle pIdentifier0) {
            _pIdentifier0 = pIdentifier0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstStateLabel();
    void push_back(CAstIdentifierHandle pIdentifier0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordGoto
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordGoto();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstConstant : public CAst {
    CAstIntegerLiteralHandle _pIntegerLiteral;
public:
    CAstConstant(CAstIntegerLiteralHandle pIntegerLiteral);
    CAstFloatingLiteralHandle _pFloatingLiteral;
public:
    CAstConstant(CAstFloatingLiteralHandle pFloatingLiteral);
    CAstBitLiteralHandle _pBitLiteral;
public:
    CAstConstant(CAstBitLiteralHandle pBitLiteral);
    CAstIntegerLiteralHandle integer_literal() const;
    CAstFloatingLiteralHandle floating_literal() const;
    CAstBitLiteralHandle bit_literal() const;
    std::string toString() const;
};
class CAstTransitionStatement : public CAst {
    CAstOneOrMoreEdgeHandle _pOneOrMoreEdge;
public:
    CAstTransitionStatement(CAstOneOrMoreEdgeHandle pOneOrMoreEdge);
    CAstOneOrMoreEdgeHandle one_or_more_edge() const;
    std::string toString() const;
};
class CAstSpecificEnd
  : public CAst {
    struct ElementType {
        CAstZeroOrMoreSpecificHandle _pZeroOrMoreSpecific0;
        CAstEndStatementHandle _pEndStatement1;
        ElementType(CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific0, CAstEndStatementHandle pEndStatement1) {
            _pZeroOrMoreSpecific0 = pZeroOrMoreSpecific0;
            _pEndStatement1 = pEndStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstSpecificEnd();
    void push_back(CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific0, CAstEndStatementHandle pEndStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstAllOrEdge : public CAst {
    CAstAllUpdateStatementHandle _pAllUpdateStatement;
public:
    CAstAllOrEdge(CAstAllUpdateStatementHandle pAllUpdateStatement);
    CAstEdgeStatementHandle _pEdgeStatement;
public:
    CAstAllOrEdge(CAstEdgeStatementHandle pEdgeStatement);
    CAstAllUpdateStatementHandle all_update_statement() const;
    CAstEdgeStatementHandle edge_statement() const;
    std::string toString() const;
};
class CAstOneOrMoreState
  : public CAst {
    struct ElementType {
        CAstStateStatementHandle _pStateStatement0;
        ElementType(CAstStateStatementHandle pStateStatement0) {
            _pStateStatement0 = pStateStatement0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstOneOrMoreState();
    void push_back(CAstStateStatementHandle pStateStatement0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstZeroOrMoreRWCOrWithoutGoto
  : public CAst {
    struct ElementType {
        CAstRWCOrWithoutGotoHandle _pRWCOrWithoutGoto;
        ElementType(CAstRWCOrWithoutGotoHandle pRWCOrWithoutGoto) {
            _pRWCOrWithoutGoto = pRWCOrWithoutGoto;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstZeroOrMoreRWCOrWithoutGoto();
    void push_back(CAstRWCOrWithoutGotoHandle pRWCOrWithoutGoto);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstEndStatement : public CAst {
    CAstGotoStatementHandle _pGotoStatement;
public:
    CAstEndStatement(CAstGotoStatementHandle pGotoStatement);
    CAstAssertStatementHandle _pAssertStatement;
public:
    CAstEndStatement(CAstAssertStatementHandle pAssertStatement);
    CAstGotoStatementHandle goto_statement() const;
    CAstAssertStatementHandle assert_statement() const;
    std::string toString() const;
};
class CAstZeroOrMoreRWC
  : public CAst {
    struct ElementType {
        CAstReadOrWriteOrCheckStatementHandle _pReadOrWriteOrCheckStatement;
        ElementType(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement) {
            _pReadOrWriteOrCheckStatement = pReadOrWriteOrCheckStatement;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstZeroOrMoreRWC();
    void push_back(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstIfStatementWithoutGoto : public CAst {
    CAstOnlyRWCWithoutGotoHandle _pOnlyRWCWithoutGoto;
public:
    CAstIfStatementWithoutGoto(CAstOnlyRWCWithoutGotoHandle pOnlyRWCWithoutGoto);
    CAstOnlyWithoutGotoWithoutGotoHandle _pOnlyWithoutGotoWithoutGoto;
public:
    CAstIfStatementWithoutGoto(CAstOnlyWithoutGotoWithoutGotoHandle pOnlyWithoutGotoWithoutGoto);
    CAstMultuWithoutGotoHandle _pMultiWithoutGoto;
public:
    CAstIfStatementWithoutGoto(CAstMultuWithoutGotoHandle pMultiWithoutGoto);
    CAstOnlyRWCWithoutGotoHandle only_rwc_without_goto() const;
    CAstOnlyWithoutGotoWithoutGotoHandle only_without_goto_without_goto() const;
    CAstMultuWithoutGotoHandle multi_without_goto() const;
    std::string toString() const;
};
class CAstSourceText : public CAst {
    CAstOneOrMoreStateHandle _pOneOrMoreState;
public:
    CAstSourceText(CAstOneOrMoreStateHandle pOneOrMoreState);
    CAstOneOrMoreStateHandle one_or_more_state() const;
    std::string toString() const;
};
class CAstIfStatementWithGoto : public CAst {
    CAstOnlyEndWithGotoHandle _pOnlyEndWithGoto;
public:
    CAstIfStatementWithGoto(CAstOnlyEndWithGotoHandle pOnlyEndWithGoto);
    CAstMultiWithGotoHandle _pMultiWithGoto;
public:
    CAstIfStatementWithGoto(CAstMultiWithGotoHandle pMultiWithGoto);
    CAstOnlyEndWithGotoHandle only_end_with_goto() const;
    CAstMultiWithGotoHandle multi_with_goto() const;
    std::string toString() const;
};
class CAstGotoStatement
  : public CAst {
    struct ElementType {
        CAstIdentifierHandle _pIdentifier0;
        ElementType(CAstIdentifierHandle pIdentifier0) {
            _pIdentifier0 = pIdentifier0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstGotoStatement();
    void push_back(CAstIdentifierHandle pIdentifier0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstZeroOrMoreAllOrEdge
  : public CAst {
    struct ElementType {
        CAstAllOrEdgeHandle _pAllOrEdge;
        ElementType(CAstAllOrEdgeHandle pAllOrEdge) {
            _pAllOrEdge = pAllOrEdge;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstZeroOrMoreAllOrEdge();
    void push_back(CAstAllOrEdgeHandle pAllOrEdge);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstOnlyEndWithGoto
  : public CAst {
    struct ElementType {
        CAstIfStatementPrefixHandle _pIfStatementPrefix0;
        CAstEndStatementHandle _pEndStatement1;
        ElementType(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstEndStatementHandle pEndStatement1) {
            _pIfStatementPrefix0 = pIfStatementPrefix0;
            _pEndStatement1 = pEndStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstOnlyEndWithGoto();
    void push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstEndStatementHandle pEndStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordIf
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordIf();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBoolAnd
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        CAstBoolExpressionHandle _pBoolExpression1;
        ElementType(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
            _pBoolExpression0 = pBoolExpression0;
            _pBoolExpression1 = pBoolExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolAnd();
    void push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstStateStatement
  : public CAst {
    struct ElementType {
        CAstStateLabelHandle _pStateLabel0;
        CAstTransitionStatementHandle _pTransitionStatement1;
        ElementType(CAstStateLabelHandle pStateLabel0, CAstTransitionStatementHandle pTransitionStatement1) {
            _pStateLabel0 = pStateLabel0;
            _pTransitionStatement1 = pTransitionStatement1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstStateStatement();
    void push_back(CAstStateLabelHandle pStateLabel0, CAstTransitionStatementHandle pTransitionStatement1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordElse
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordElse();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordCheck
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordCheck();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstReadOrWriteOrCheckStatement : public CAst {
    CAstReadStatementHandle _pReadStatement;
public:
    CAstReadOrWriteOrCheckStatement(CAstReadStatementHandle pReadStatement);
    CAstWriteStatementHandle _pWriteStatement;
public:
    CAstReadOrWriteOrCheckStatement(CAstWriteStatementHandle pWriteStatement);
    CAstCheckStatementHandle _pCheckStatement;
public:
    CAstReadOrWriteOrCheckStatement(CAstCheckStatementHandle pCheckStatement);
    CAstReadStatementHandle read_statement() const;
    CAstWriteStatementHandle write_statement() const;
    CAstCheckStatementHandle check_statement() const;
    std::string toString() const;
};
class CAstZeroOrMoreSpecific
  : public CAst {
    struct ElementType {
        CAstSpecificUpdateStatementHandle _pSpecificUpdateStatement;
        ElementType(CAstSpecificUpdateStatementHandle pSpecificUpdateStatement) {
            _pSpecificUpdateStatement = pSpecificUpdateStatement;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstZeroOrMoreSpecific();
    void push_back(CAstSpecificUpdateStatementHandle pSpecificUpdateStatement);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordFalse
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordFalse();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBoolOr
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        CAstBoolExpressionHandle _pBoolExpression1;
        ElementType(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
            _pBoolExpression0 = pBoolExpression0;
            _pBoolExpression1 = pBoolExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolOr();
    void push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstKeywordAssert
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordAssert();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstMultiWithGoto
  : public CAst {
    struct ElementType {
        CAstIfStatementPrefixHandle _pIfStatementPrefix0;
        CAstZeroOrMoreSpecificHandle _pZeroOrMoreSpecific1;
        CAstEndStatementHandle _pEndStatement2;
        ElementType(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific1, CAstEndStatementHandle pEndStatement2) {
            _pIfStatementPrefix0 = pIfStatementPrefix0;
            _pZeroOrMoreSpecific1 = pZeroOrMoreSpecific1;
            _pEndStatement2 = pEndStatement2;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstMultiWithGoto();
    void push_back(CAstIfStatementPrefixHandle pIfStatementPrefix0, CAstZeroOrMoreSpecificHandle pZeroOrMoreSpecific1, CAstEndStatementHandle pEndStatement2);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstBoolXor
  : public CAst {
    struct ElementType {
        CAstBoolExpressionHandle _pBoolExpression0;
        CAstBoolExpressionHandle _pBoolExpression1;
        ElementType(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1) {
            _pBoolExpression0 = pBoolExpression0;
            _pBoolExpression1 = pBoolExpression1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstBoolXor();
    void push_back(CAstBoolExpressionHandle pBoolExpression0, CAstBoolExpressionHandle pBoolExpression1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstAssertStatement
  : public CAst {
    struct ElementType {
        CAstIntegerLiteralHandle _pIntegerLiteral0;
        ElementType(CAstIntegerLiteralHandle pIntegerLiteral0) {
            _pIntegerLiteral0 = pIntegerLiteral0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstAssertStatement();
    void push_back(CAstIntegerLiteralHandle pIntegerLiteral0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstSpecificUpdateStatement : public CAst {
    CAstReadOrWriteOrCheckStatementHandle _pReadOrWriteOrCheckStatement;
public:
    CAstSpecificUpdateStatement(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement);
    CAstIfStatementWithoutGotoHandle _pIfStatementWithoutGoto;
public:
    CAstSpecificUpdateStatement(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto);
    CAstReadOrWriteOrCheckStatementHandle read_or_write_or_check_statement() const;
    CAstIfStatementWithoutGotoHandle if_statement_without_goto() const;
    std::string toString() const;
};
class CAstAllIfWithGoto
  : public CAst {
    struct ElementType {
        CAstZeroOrMoreAllHandle _pZeroOrMoreAll0;
        CAstIfStatementWithGotoHandle _pIfStatementWithGoto1;
        ElementType(CAstZeroOrMoreAllHandle pZeroOrMoreAll0, CAstIfStatementWithGotoHandle pIfStatementWithGoto1) {
            _pZeroOrMoreAll0 = pZeroOrMoreAll0;
            _pIfStatementWithGoto1 = pIfStatementWithGoto1;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstAllIfWithGoto();
    void push_back(CAstZeroOrMoreAllHandle pZeroOrMoreAll0, CAstIfStatementWithGotoHandle pIfStatementWithGoto1);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstIntegerLiteral : public CAst {
    std::string _integer_literal;
public:
    CAstIntegerLiteral(const std::string & s);
    std::string integer_literal() const;
    std::string toString() const;
};

class CAstOneOrMoreEdge
  : public CAst {
    struct ElementType {
        CAstEdgeStatementHandle _pEdgeStatement0;
        ElementType(CAstEdgeStatementHandle pEdgeStatement0) {
            _pEdgeStatement0 = pEdgeStatement0;
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstOneOrMoreEdge();
    void push_back(CAstEdgeStatementHandle pEdgeStatement0);
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
class CAstAllUpdateStatement : public CAst {
    CAstReadOrWriteOrCheckStatementHandle _pReadOrWriteOrCheckStatement;
public:
    CAstAllUpdateStatement(CAstReadOrWriteOrCheckStatementHandle pReadOrWriteOrCheckStatement);
    CAstIfStatementWithoutGotoHandle _pIfStatementWithoutGoto;
public:
    CAstAllUpdateStatement(CAstIfStatementWithoutGotoHandle pIfStatementWithoutGoto);
    CAstReadOrWriteOrCheckStatementHandle read_or_write_or_check_statement() const;
    CAstIfStatementWithoutGotoHandle if_statement_without_goto() const;
    std::string toString() const;
};
class CAstKeywordRead
  : public CAst {
    struct ElementType {
        ElementType() {
        }
    };
    std::vector<ElementType> _vecElements;
public:
    CAstKeywordRead();
    void push_back();
    std::vector<ElementType>& container();
    const std::vector<ElementType>& container() const;
    ElementType element(unsigned int pos) const;
    unsigned int element_size() const;
    std::string toString() const;
};
#endif // CAST_H
