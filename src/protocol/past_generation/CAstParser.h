#ifndef CASTPARSER_H
#define CASTPARSER_H
#include "utility/parser/StringParser.h"
#include "CAst.h"


#include "exception/Exception.h"


template <class _HandleType>
class CAstParserBase {
private:
    TokenStructureHandle _pTokenStructure;
    TokenHandle          _pToken;
public:
    CAstParserBase() { }

    virtual ~CAstParserBase() {}

    _HandleType parseString(const std::string & s) {
        initFromString(s);
        _HandleType pHandle;
        if (parse(pHandle))
            return pHandle;
        reportChild();
        throw InvalidFormatException("Unknown structure");
    }
    _HandleType parseStringPos(const std::string & s) {
        initFromString(s);
        _HandleType pHandle;
        unsigned int pos = 0;
        if (parsePos(pHandle, pos))
            return pHandle;
        reportChild();
        throw InvalidFormatException("Unknown structure");
    }
    void reportChild() const {
        getToken()->printChilds(getTokenStructure());    }
    void reportChildFrom(unsigned int from) const {
        for (unsigned int pos = from; pos < getTokenChildSize(); ++pos)
            std::cout << "Child(" << pos << ") : " << getTokenChild(pos)->name() << std::endl;
    }
    virtual bool parse(_HandleType & pHandle) {
        unsigned int pos = 0;
        return parsePos(pHandle, pos);
    }
    virtual bool parsePos(_HandleType & pHandle, unsigned int & pos) { throw "Not implemented"; }
protected:
    TokenStructureHandle getTokenStructure() const
      { return _pTokenStructure; }
    TokenHandle getToken() const
      { return _pToken;}
    unsigned int getTokenChildSize() const
      { return getToken()->childSize(); }
    TokenHandle getTokenChild(unsigned int pos) const
      { return getToken()->child(getTokenStructure(), pos); }

    void initFromToken(TokenStructureHandle pTokenStructure, TokenHandle pToken) {
        _pTokenStructure = pTokenStructure;
        _pToken = pToken;
    }
    void initFromString(const std::string & s) {
        StringParser string_parser;
        _pTokenStructure = string_parser.parseString(s);
        initToken();
    }

private:
    void initToken() {
        if (getTokenStructure()->vecToken().size() == 0)
            throw InvalidFormatException("Not child");
        _pToken = getTokenStructure()->vecToken()[0];
    }


public:
    virtual std::string getTokenName() const = 0;
};

class CAstBoolConstantParser : public CAstParserBase<CAstBoolConstantHandle> {
public:
    CAstBoolConstantParser() { }
    CAstBoolConstantParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolConstantHandle &  pBoolConstant, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_constant"; }
};

class CAstOnlyRWCWithoutGotoParser : public CAstParserBase<CAstOnlyRWCWithoutGotoHandle> {
public:
    CAstOnlyRWCWithoutGotoParser() { }
    CAstOnlyRWCWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstOnlyRWCWithoutGotoHandle &  pOnlyRWCWithoutGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "only_rwc_without_goto"; }
};

class CAstBoolWithParenthesisParser : public CAstParserBase<CAstBoolWithParenthesisHandle> {
public:
    CAstBoolWithParenthesisParser() { }
    CAstBoolWithParenthesisParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolWithParenthesisHandle &  pBoolWithParenthesis, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_with_parenthesis"; }
};

class CAstZeroOrMoreAllParser : public CAstParserBase<CAstZeroOrMoreAllHandle> {
public:
    CAstZeroOrMoreAllParser() { }
    CAstZeroOrMoreAllParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstZeroOrMoreAllHandle &  pZeroOrMoreAll, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_all"; }
};

class CAstReadStatementParser : public CAstParserBase<CAstReadStatementHandle> {
public:
    CAstReadStatementParser() { }
    CAstReadStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstReadStatementHandle &  pReadStatement);
    std::string getTokenName() const
      { return "read_statement"; }
};

class CAstBoolNotParser : public CAstParserBase<CAstBoolNotHandle> {
public:
    CAstBoolNotParser() { }
    CAstBoolNotParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolNotHandle &  pBoolNot, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_not"; }
};

class CAstBitLiteralParser : public CAstParserBase<CAstBitLiteralHandle> {
public:
    CAstBitLiteralParser() { }
    CAstBitLiteralParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstBitLiteralHandle &  pBitLiteral);
    std::string getTokenName() const
      { return "bit_literal"; }
};

class CAstMultuWithoutGotoParser : public CAstParserBase<CAstMultuWithoutGotoHandle> {
public:
    CAstMultuWithoutGotoParser() { }
    CAstMultuWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstMultuWithoutGotoHandle &  pMultiWithoutGoto);
    std::string getTokenName() const
      { return "multi_without_goto"; }
};

class CAstIdentifierParser : public CAstParserBase<CAstIdentifierHandle> {
public:
    CAstIdentifierParser() { }
    CAstIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstIdentifierHandle &  pIdentifier);
    std::string getTokenName() const
      { return "identifier"; }
};

class CAstIfStatementPrefixParser : public CAstParserBase<CAstIfStatementPrefixHandle> {
public:
    CAstIfStatementPrefixParser() { }
    CAstIfStatementPrefixParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstIfStatementPrefixHandle &  pIfStatementPrefix);
    std::string getTokenName() const
      { return "if_statement_prefix"; }
};

class CAstKeywordWriteParser : public CAstParserBase<CAstKeywordWriteHandle> {
public:
    CAstKeywordWriteParser() { }
    CAstKeywordWriteParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordWriteHandle &  pKeywordWrite, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_write"; }
};

class CAstEdgeStatementParser : public CAstParserBase<CAstEdgeStatementHandle> {
public:
    CAstEdgeStatementParser() { }
    CAstEdgeStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstEdgeStatementHandle &  pEdgeStatement);
    std::string getTokenName() const
      { return "edge_statement"; }
};

class CAstOnlyWithoutGotoWithoutGotoParser : public CAstParserBase<CAstOnlyWithoutGotoWithoutGotoHandle> {
public:
    CAstOnlyWithoutGotoWithoutGotoParser() { }
    CAstOnlyWithoutGotoWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstOnlyWithoutGotoWithoutGotoHandle &  pOnlyWithoutGotoWithoutGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "only_without_goto_without_goto"; }
};

class CAstFloatingLiteralParser : public CAstParserBase<CAstFloatingLiteralHandle> {
public:
    CAstFloatingLiteralParser() { }
    CAstFloatingLiteralParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstFloatingLiteralHandle &  pFloatingLiteral);
    std::string getTokenName() const
      { return "floating_literal"; }
};

class CAstCheckStatementParser : public CAstParserBase<CAstCheckStatementHandle> {
public:
    CAstCheckStatementParser() { }
    CAstCheckStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstCheckStatementHandle &  pCheckStatement);
    std::string getTokenName() const
      { return "check_statement"; }
};

class CAstKeywordTrueParser : public CAstParserBase<CAstKeywordTrueHandle> {
public:
    CAstKeywordTrueParser() { }
    CAstKeywordTrueParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordTrueHandle &  pKeywordTrue, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_true"; }
};

class CAstRWCOrWithoutGotoParser : public CAstParserBase<CAstRWCOrWithoutGotoHandle> {
public:
    CAstRWCOrWithoutGotoParser() { }
    CAstRWCOrWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstRWCOrWithoutGotoHandle &  pRWCOrWithoutGoto);
    std::string getTokenName() const
      { return "rwc_or_without_goto"; }
};

class CAstBoolExpressionParser : public CAstParserBase<CAstBoolExpressionHandle> {
public:
    CAstBoolExpressionParser() { }
    CAstBoolExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstBoolExpressionHandle &  pBoolExpression);
    std::string getTokenName() const
      { return "bool_expression"; }
};

class CAstWriteStatementParser : public CAstParserBase<CAstWriteStatementHandle> {
public:
    CAstWriteStatementParser() { }
    CAstWriteStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstWriteStatementHandle &  pWriteStatement);
    std::string getTokenName() const
      { return "write_statement"; }
};

class CAstStateLabelParser : public CAstParserBase<CAstStateLabelHandle> {
public:
    CAstStateLabelParser() { }
    CAstStateLabelParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstStateLabelHandle &  pStateLabel);
    std::string getTokenName() const
      { return "state_label"; }
};

class CAstKeywordGotoParser : public CAstParserBase<CAstKeywordGotoHandle> {
public:
    CAstKeywordGotoParser() { }
    CAstKeywordGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordGotoHandle &  pKeywordGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_goto"; }
};

class CAstConstantParser : public CAstParserBase<CAstConstantHandle> {
public:
    CAstConstantParser() { }
    CAstConstantParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstConstantHandle &  pConstant);
    std::string getTokenName() const
      { return "constant"; }
};

class CAstTransitionStatementParser : public CAstParserBase<CAstTransitionStatementHandle> {
public:
    CAstTransitionStatementParser() { }
    CAstTransitionStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstTransitionStatementHandle &  pTransitionStatement);
    std::string getTokenName() const
      { return "transition_statement"; }
};

class CAstSpecificEndParser : public CAstParserBase<CAstSpecificEndHandle> {
public:
    CAstSpecificEndParser() { }
    CAstSpecificEndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstSpecificEndHandle &  pSpecificEnd, unsigned int & pos);
    std::string getTokenName() const
      { return "specific_end"; }
};

class CAstAllOrEdgeParser : public CAstParserBase<CAstAllOrEdgeHandle> {
public:
    CAstAllOrEdgeParser() { }
    CAstAllOrEdgeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstAllOrEdgeHandle &  pAllOrEdge, unsigned int & pos);
    std::string getTokenName() const
      { return "all_or_edge"; }
};

class CAstOneOrMoreStateParser : public CAstParserBase<CAstOneOrMoreStateHandle> {
public:
    CAstOneOrMoreStateParser() { }
    CAstOneOrMoreStateParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstOneOrMoreStateHandle &  pOneOrMoreState, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_state"; }
};

class CAstZeroOrMoreRWCOrWithoutGotoParser : public CAstParserBase<CAstZeroOrMoreRWCOrWithoutGotoHandle> {
public:
    CAstZeroOrMoreRWCOrWithoutGotoParser() { }
    CAstZeroOrMoreRWCOrWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstZeroOrMoreRWCOrWithoutGotoHandle &  pZeroOrMoreRWCOrWithoutGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_rwc_or_without_goto"; }
};

class CAstEndStatementParser : public CAstParserBase<CAstEndStatementHandle> {
public:
    CAstEndStatementParser() { }
    CAstEndStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstEndStatementHandle &  pEndStatement);
    std::string getTokenName() const
      { return "end_statement"; }
};

class CAstZeroOrMoreRWCParser : public CAstParserBase<CAstZeroOrMoreRWCHandle> {
public:
    CAstZeroOrMoreRWCParser() { }
    CAstZeroOrMoreRWCParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstZeroOrMoreRWCHandle &  pZeroOrMoreRWC, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_rwc"; }
};

class CAstIfStatementWithoutGotoParser : public CAstParserBase<CAstIfStatementWithoutGotoHandle> {
public:
    CAstIfStatementWithoutGotoParser() { }
    CAstIfStatementWithoutGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstIfStatementWithoutGotoHandle &  pIfStatementWithoutGoto);
    std::string getTokenName() const
      { return "if_statement_without_goto"; }
};

class CAstSourceTextParser : public CAstParserBase<CAstSourceTextHandle> {
public:
    CAstSourceTextParser() { }
    CAstSourceTextParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstSourceTextHandle &  pSourceText);
    std::string getTokenName() const
      { return "source_text"; }
};

class CAstIfStatementWithGotoParser : public CAstParserBase<CAstIfStatementWithGotoHandle> {
public:
    CAstIfStatementWithGotoParser() { }
    CAstIfStatementWithGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstIfStatementWithGotoHandle &  pIfStatementWithGoto);
    std::string getTokenName() const
      { return "if_statement_with_goto"; }
};

class CAstGotoStatementParser : public CAstParserBase<CAstGotoStatementHandle> {
public:
    CAstGotoStatementParser() { }
    CAstGotoStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstGotoStatementHandle &  pGotoStatement);
    std::string getTokenName() const
      { return "goto_statement"; }
};

class CAstZeroOrMoreAllOrEdgeParser : public CAstParserBase<CAstZeroOrMoreAllOrEdgeHandle> {
public:
    CAstZeroOrMoreAllOrEdgeParser() { }
    CAstZeroOrMoreAllOrEdgeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstZeroOrMoreAllOrEdgeHandle &  pZeroOrMoreAllOrEdge, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_all_or_edge"; }
};

class CAstOnlyEndWithGotoParser : public CAstParserBase<CAstOnlyEndWithGotoHandle> {
public:
    CAstOnlyEndWithGotoParser() { }
    CAstOnlyEndWithGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstOnlyEndWithGotoHandle &  pOnlyEndWithGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "only_end_with_goto"; }
};

class CAstKeywordIfParser : public CAstParserBase<CAstKeywordIfHandle> {
public:
    CAstKeywordIfParser() { }
    CAstKeywordIfParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordIfHandle &  pKeywordIf, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_if"; }
};

class CAstBoolAndParser : public CAstParserBase<CAstBoolAndHandle> {
public:
    CAstBoolAndParser() { }
    CAstBoolAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolAndHandle &  pBoolAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_and"; }
};

class CAstStateStatementParser : public CAstParserBase<CAstStateStatementHandle> {
public:
    CAstStateStatementParser() { }
    CAstStateStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstStateStatementHandle &  pStateStatement);
    std::string getTokenName() const
      { return "state_statement"; }
};

class CAstKeywordElseParser : public CAstParserBase<CAstKeywordElseHandle> {
public:
    CAstKeywordElseParser() { }
    CAstKeywordElseParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordElseHandle &  pKeywordElse, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_else"; }
};

class CAstKeywordCheckParser : public CAstParserBase<CAstKeywordCheckHandle> {
public:
    CAstKeywordCheckParser() { }
    CAstKeywordCheckParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordCheckHandle &  pKeywordCheck, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_check"; }
};

class CAstReadOrWriteOrCheckStatementParser : public CAstParserBase<CAstReadOrWriteOrCheckStatementHandle> {
public:
    CAstReadOrWriteOrCheckStatementParser() { }
    CAstReadOrWriteOrCheckStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstReadOrWriteOrCheckStatementHandle &  pReadOrWriteOrCheckStatement);
    std::string getTokenName() const
      { return "read_or_write_or_check_statement"; }
};

class CAstZeroOrMoreSpecificParser : public CAstParserBase<CAstZeroOrMoreSpecificHandle> {
public:
    CAstZeroOrMoreSpecificParser() { }
    CAstZeroOrMoreSpecificParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstZeroOrMoreSpecificHandle &  pZeroOrMoreSpecific, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_specific"; }
};

class CAstKeywordFalseParser : public CAstParserBase<CAstKeywordFalseHandle> {
public:
    CAstKeywordFalseParser() { }
    CAstKeywordFalseParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordFalseHandle &  pKeywordFalse, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_false"; }
};

class CAstBoolOrParser : public CAstParserBase<CAstBoolOrHandle> {
public:
    CAstBoolOrParser() { }
    CAstBoolOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolOrHandle &  pBoolOr, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_or"; }
};

class CAstKeywordAssertParser : public CAstParserBase<CAstKeywordAssertHandle> {
public:
    CAstKeywordAssertParser() { }
    CAstKeywordAssertParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordAssertHandle &  pKeywordAssert, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_assert"; }
};

class CAstMultiWithGotoParser : public CAstParserBase<CAstMultiWithGotoHandle> {
public:
    CAstMultiWithGotoParser() { }
    CAstMultiWithGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstMultiWithGotoHandle &  pMultiWithGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "multi_with_goto"; }
};

class CAstBoolXorParser : public CAstParserBase<CAstBoolXorHandle> {
public:
    CAstBoolXorParser() { }
    CAstBoolXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstBoolXorHandle &  pBoolXor, unsigned int & pos);
    std::string getTokenName() const
      { return "bool_xor"; }
};

class CAstAssertStatementParser : public CAstParserBase<CAstAssertStatementHandle> {
public:
    CAstAssertStatementParser() { }
    CAstAssertStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstAssertStatementHandle &  pAssertStatement);
    std::string getTokenName() const
      { return "assert_statement"; }
};

class CAstSpecificUpdateStatementParser : public CAstParserBase<CAstSpecificUpdateStatementHandle> {
public:
    CAstSpecificUpdateStatementParser() { }
    CAstSpecificUpdateStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstSpecificUpdateStatementHandle &  pSpecificUpdateStatement);
    std::string getTokenName() const
      { return "specific_update_statement"; }
};

class CAstAllIfWithGotoParser : public CAstParserBase<CAstAllIfWithGotoHandle> {
public:
    CAstAllIfWithGotoParser() { }
    CAstAllIfWithGotoParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstAllIfWithGotoHandle &  pAllIfWithGoto, unsigned int & pos);
    std::string getTokenName() const
      { return "all_if_with_goto"; }
};

class CAstIntegerLiteralParser : public CAstParserBase<CAstIntegerLiteralHandle> {
public:
    CAstIntegerLiteralParser() { }
    CAstIntegerLiteralParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstIntegerLiteralHandle &  pIntegerLiteral);
    std::string getTokenName() const
      { return "integer_literal"; }
};

class CAstOneOrMoreEdgeParser : public CAstParserBase<CAstOneOrMoreEdgeHandle> {
public:
    CAstOneOrMoreEdgeParser() { }
    CAstOneOrMoreEdgeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstOneOrMoreEdgeHandle &  pOneOrMoreEdge, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_edge"; }
};

class CAstAllUpdateStatementParser : public CAstParserBase<CAstAllUpdateStatementHandle> {
public:
    CAstAllUpdateStatementParser() { }
    CAstAllUpdateStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(CAstAllUpdateStatementHandle &  pAllUpdateStatement);
    std::string getTokenName() const
      { return "all_update_statement"; }
};

class CAstKeywordReadParser : public CAstParserBase<CAstKeywordReadHandle> {
public:
    CAstKeywordReadParser() { }
    CAstKeywordReadParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(CAstKeywordReadHandle &  pKeywordRead, unsigned int & pos);
    std::string getTokenName() const
      { return "keyword_read"; }
};

#endif // CASTPARSER_H
