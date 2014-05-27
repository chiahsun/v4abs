#ifndef ASTPARSER_H
#define ASTPARSER_H
#include "utility/parser/StringParser.h"
#include "Ast.h"


#include "exception/Exception.h"


template <class _HandleType>
class AstParserBase {
private:
    TokenStructureHandle _pTokenStructure;
    TokenHandle          _pToken;
public:
    AstParserBase() { }

    virtual ~AstParserBase() {}

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

class AstListOfPortIdentifiersParser : public AstParserBase<AstListOfPortIdentifiersHandle> {
public:
    AstListOfPortIdentifiersParser() { }
    AstListOfPortIdentifiersParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfPortIdentifiersHandle &  pListOfPortIdentifiers);
    std::string getTokenName() const
      { return "list_of_port_identifiers"; }
};

class AstZeroOrOneListOfModuleConnectionsParser : public AstParserBase<AstZeroOrOneListOfModuleConnectionsHandle> {
public:
    AstZeroOrOneListOfModuleConnectionsParser() { }
    AstZeroOrOneListOfModuleConnectionsParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneListOfModuleConnectionsHandle &  pZeroOrOneListOfModuleConnections, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_list_of_module_connections"; }
};

class AstZeroOrOneNameOfGateInstanceParser : public AstParserBase<AstZeroOrOneNameOfGateInstanceHandle> {
public:
    AstZeroOrOneNameOfGateInstanceParser() { }
    AstZeroOrOneNameOfGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneNameOfGateInstanceHandle &  pZeroOrOneNameOfGateInstance, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_name_of_gate_instance"; }
};

class AstBinaryOperatorNotEqualParser : public AstParserBase<AstBinaryOperatorNotEqualHandle> {
public:
    AstBinaryOperatorNotEqualParser() { }
    AstBinaryOperatorNotEqualParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorNotEqualHandle &  pBinaryOperatorNotEqual, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_not_equal"; }
};

class AstBinaryOperatorXorParser : public AstParserBase<AstBinaryOperatorXorHandle> {
public:
    AstBinaryOperatorXorParser() { }
    AstBinaryOperatorXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorXorHandle &  pBinaryOperatorXor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_xor"; }
};

class AstBinaryExpressionMinusParser : public AstParserBase<AstBinaryExpressionMinusHandle> {
public:
    AstBinaryExpressionMinusParser() { }
    AstBinaryExpressionMinusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionMinusHandle &  pBinaryExpressionMinus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_minus"; }
};

class AstUnaryExpressionParser : public AstParserBase<AstUnaryExpressionHandle> {
public:
    AstUnaryExpressionParser() { }
    AstUnaryExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryExpressionHandle &  pUnaryExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_expression"; }
};

class AstBinaryOperatorLeqParser : public AstParserBase<AstBinaryOperatorLeqHandle> {
public:
    AstBinaryOperatorLeqParser() { }
    AstBinaryOperatorLeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorLeqHandle &  pBinaryOperatorLeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_leq"; }
};

class AstKeywordParameterParser : public AstParserBase<AstKeywordParameterHandle> {
public:
    AstKeywordParameterParser() { }
    AstKeywordParameterParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordParameterHandle &  pKeywordParameter);
    std::string getTokenName() const
      { return "keyword_parameter"; }
};

class AstKeywordMacroModuleParser : public AstParserBase<AstKeywordMacroModuleHandle> {
public:
    AstKeywordMacroModuleParser() { }
    AstKeywordMacroModuleParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordMacroModuleHandle &  pKeywordMacroModule);
    std::string getTokenName() const
      { return "keyword_macro_module"; }
};

class AstBinaryExpressionGeqParser : public AstParserBase<AstBinaryExpressionGeqHandle> {
public:
    AstBinaryExpressionGeqParser() { }
    AstBinaryExpressionGeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionGeqHandle &  pBinaryExpressionGeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_geq"; }
};

class AstUnaryOperatorNotParser : public AstParserBase<AstUnaryOperatorNotHandle> {
public:
    AstUnaryOperatorNotParser() { }
    AstUnaryOperatorNotParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorNotHandle &  pUnaryOperatorNot, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_not"; }
};

class AstZeroOrMoreCommaNetAssignmentParser : public AstParserBase<AstZeroOrMoreCommaNetAssignmentHandle> {
public:
    AstZeroOrMoreCommaNetAssignmentParser() { }
    AstZeroOrMoreCommaNetAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaNetAssignmentHandle &  pZeroOrMoreCommaNetAssignment, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_net_assignment"; }
};

class AstEventExpressionParser : public AstParserBase<AstEventExpressionHandle> {
public:
    AstEventExpressionParser() { }
    AstEventExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstEventExpressionHandle &  pEventExpression);
    std::string getTokenName() const
      { return "event_expression"; }
};

class AstZeroOrMoreCommaNamedPortConnectionParser : public AstParserBase<AstZeroOrMoreCommaNamedPortConnectionHandle> {
public:
    AstZeroOrMoreCommaNamedPortConnectionParser() { }
    AstZeroOrMoreCommaNamedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaNamedPortConnectionHandle &  pZeroOrMoreCommaNamedPortConnection, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_named_port_connection"; }
};

class AstCaseItemParser : public AstParserBase<AstCaseItemHandle> {
public:
    AstCaseItemParser() { }
    AstCaseItemParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstCaseItemHandle &  pCaseItem);
    std::string getTokenName() const
      { return "case_item"; }
};

class AstBinaryExpressionBwAndParser : public AstParserBase<AstBinaryExpressionBwAndHandle> {
public:
    AstBinaryExpressionBwAndParser() { }
    AstBinaryExpressionBwAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionBwAndHandle &  pBinaryExpressionBwAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_bw_and"; }
};

class AstIdentifierParser : public AstParserBase<AstIdentifierHandle> {
public:
    AstIdentifierParser() { }
    AstIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstIdentifierHandle &  pIdentifier);
    std::string getTokenName() const
      { return "identifier"; }
};

class AstContinuousAssignParser : public AstParserBase<AstContinuousAssignHandle> {
public:
    AstContinuousAssignParser() { }
    AstContinuousAssignParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstContinuousAssignHandle &  pContinuousAssign);
    std::string getTokenName() const
      { return "continuous_assign"; }
};

class AstNumberParser : public AstParserBase<AstNumberHandle> {
public:
    AstNumberParser() { }
    AstNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNumberHandle &  pNumber);
    std::string getTokenName() const
      { return "number"; }
};

class AstNetLvalueBitSelectParser : public AstParserBase<AstNetLvalueBitSelectHandle> {
public:
    AstNetLvalueBitSelectParser() { }
    AstNetLvalueBitSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstNetLvalueBitSelectHandle &  pNetLvalueBitSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "net_lvalue_bit_select"; }
};

class AstExpressionParser : public AstParserBase<AstExpressionHandle> {
public:
    AstExpressionParser() { }
    AstExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstExpressionHandle &  pExpression);
    std::string getTokenName() const
      { return "expression"; }
};

class AstNamedPortExpressionParser : public AstParserBase<AstNamedPortExpressionHandle> {
public:
    AstNamedPortExpressionParser() { }
    AstNamedPortExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNamedPortExpressionHandle &  pNamedPortExpression);
    std::string getTokenName() const
      { return "named_port_expression"; }
};

class AstStatementParser : public AstParserBase<AstStatementHandle> {
public:
    AstStatementParser() { }
    AstStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstStatementHandle &  pStatement);
    std::string getTokenName() const
      { return "statement"; }
};

class AstBinaryConstantExpressionEqParser : public AstParserBase<AstBinaryConstantExpressionEqHandle> {
public:
    AstBinaryConstantExpressionEqParser() { }
    AstBinaryConstantExpressionEqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionEqHandle &  pBinaryConstantExpressionEq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_eq"; }
};

class AstCaseStatementParser : public AstParserBase<AstCaseStatementHandle> {
public:
    AstCaseStatementParser() { }
    AstCaseStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstCaseStatementHandle &  pCaseStatement);
    std::string getTokenName() const
      { return "case_statement"; }
};

class AstListOfRegisterIdentifiersParser : public AstParserBase<AstListOfRegisterIdentifiersHandle> {
public:
    AstListOfRegisterIdentifiersParser() { }
    AstListOfRegisterIdentifiersParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfRegisterIdentifiersHandle &  pListOfRegisterIdentifiers);
    std::string getTokenName() const
      { return "list_of_register_identifiers"; }
};

class AstRangeParser : public AstParserBase<AstRangeHandle> {
public:
    AstRangeParser() { }
    AstRangeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstRangeHandle &  pRange);
    std::string getTokenName() const
      { return "range"; }
};

class AstBinaryOperatorSlashParser : public AstParserBase<AstBinaryOperatorSlashHandle> {
public:
    AstBinaryOperatorSlashParser() { }
    AstBinaryOperatorSlashParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorSlashHandle &  pBinaryOperatorSlash, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_slash"; }
};

class AstProceduralContinuousAssignmentParser : public AstParserBase<AstProceduralContinuousAssignmentHandle> {
public:
    AstProceduralContinuousAssignmentParser() { }
    AstProceduralContinuousAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstProceduralContinuousAssignmentHandle &  pProceduralContinuousAssignment);
    std::string getTokenName() const
      { return "procedural_continuous_assignment"; }
};

class AstSelectParser : public AstParserBase<AstSelectHandle> {
public:
    AstSelectParser() { }
    AstSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstSelectHandle &  pSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "select"; }
};

class AstBinaryOperatorNegXorParser : public AstParserBase<AstBinaryOperatorNegXorHandle> {
public:
    AstBinaryOperatorNegXorParser() { }
    AstBinaryOperatorNegXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorNegXorHandle &  pBinaryOperatorNegXor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_neg_xor"; }
};

class AstBinaryOperatorOrOrParser : public AstParserBase<AstBinaryOperatorOrOrHandle> {
public:
    AstBinaryOperatorOrOrParser() { }
    AstBinaryOperatorOrOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorOrOrHandle &  pBinaryOperatorOrOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_or_or"; }
};

class AstSeqBlockParser : public AstParserBase<AstSeqBlockHandle> {
public:
    AstSeqBlockParser() { }
    AstSeqBlockParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstSeqBlockHandle &  pSeqBlock);
    std::string getTokenName() const
      { return "seq_block"; }
};

class AstBlockingAssignmentParser : public AstParserBase<AstBlockingAssignmentHandle> {
public:
    AstBlockingAssignmentParser() { }
    AstBlockingAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstBlockingAssignmentHandle &  pBlockingAssignment);
    std::string getTokenName() const
      { return "blocking_assignment"; }
};

class AstZeroOrMoreStatementParser : public AstParserBase<AstZeroOrMoreStatementHandle> {
public:
    AstZeroOrMoreStatementParser() { }
    AstZeroOrMoreStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreStatementHandle &  pZeroOrMoreStatement, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_statement"; }
};

class AstBinaryConstantExpressionGeqParser : public AstParserBase<AstBinaryConstantExpressionGeqHandle> {
public:
    AstBinaryConstantExpressionGeqParser() { }
    AstBinaryConstantExpressionGeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionGeqHandle &  pBinaryConstantExpressionGeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_geq"; }
};

class AstTernaryExpressionParser : public AstParserBase<AstTernaryExpressionHandle> {
public:
    AstTernaryExpressionParser() { }
    AstTernaryExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstTernaryExpressionHandle &  pTernaryExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "ternary_expression"; }
};

class AstZeroOrMoreCommaParamAssignmentParser : public AstParserBase<AstZeroOrMoreCommaParamAssignmentHandle> {
public:
    AstZeroOrMoreCommaParamAssignmentParser() { }
    AstZeroOrMoreCommaParamAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaParamAssignmentHandle &  pZeroOrMoreCommaParamAssignment, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_param_assignment"; }
};

class AstDescriptionParser : public AstParserBase<AstDescriptionHandle> {
public:
    AstDescriptionParser() { }
    AstDescriptionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstDescriptionHandle &  pDescription);
    std::string getTokenName() const
      { return "description"; }
};

class AstKeywordOutputParser : public AstParserBase<AstKeywordOutputHandle> {
public:
    AstKeywordOutputParser() { }
    AstKeywordOutputParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordOutputHandle &  pKeywordOutput);
    std::string getTokenName() const
      { return "keyword_output"; }
};

class AstBinaryConstantExpressionShiftRightParser : public AstParserBase<AstBinaryConstantExpressionShiftRightHandle> {
public:
    AstBinaryConstantExpressionShiftRightParser() { }
    AstBinaryConstantExpressionShiftRightParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionShiftRightHandle &  pBinaryConstantExpressionShiftRight, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_shift_right"; }
};

class AstProceduralTimingControlStatementParser : public AstParserBase<AstProceduralTimingControlStatementHandle> {
public:
    AstProceduralTimingControlStatementParser() { }
    AstProceduralTimingControlStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstProceduralTimingControlStatementHandle &  pProceduralTimingControlStatement);
    std::string getTokenName() const
      { return "procedural_timing_control_statement"; }
};

class AstInoutDeclarationParser : public AstParserBase<AstInoutDeclarationHandle> {
public:
    AstInoutDeclarationParser() { }
    AstInoutDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstInoutDeclarationHandle &  pInoutDeclaration);
    std::string getTokenName() const
      { return "inout_declaration"; }
};

class AstBinaryExpressionBwOrParser : public AstParserBase<AstBinaryExpressionBwOrHandle> {
public:
    AstBinaryExpressionBwOrParser() { }
    AstBinaryExpressionBwOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionBwOrHandle &  pBinaryExpressionBwOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_bw_or"; }
};

class AstListOfNetIdentifierParser : public AstParserBase<AstListOfNetIdentifierHandle> {
public:
    AstListOfNetIdentifierParser() { }
    AstListOfNetIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfNetIdentifierHandle &  pListOfNetIdentifier);
    std::string getTokenName() const
      { return "list_of_net_identifier"; }
};

class AstModuleItemParser : public AstParserBase<AstModuleItemHandle> {
public:
    AstModuleItemParser() { }
    AstModuleItemParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleItemHandle &  pModuleItem);
    std::string getTokenName() const
      { return "module_item"; }
};

class AstKeywordBeginParser : public AstParserBase<AstKeywordBeginHandle> {
public:
    AstKeywordBeginParser() { }
    AstKeywordBeginParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordBeginHandle &  pKeywordBegin);
    std::string getTokenName() const
      { return "keyword_begin"; }
};

class AstKeywordAlwaysParser : public AstParserBase<AstKeywordAlwaysHandle> {
public:
    AstKeywordAlwaysParser() { }
    AstKeywordAlwaysParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordAlwaysHandle &  pKeywordAlways);
    std::string getTokenName() const
      { return "keyword_always"; }
};

class AstCaseItemDefaultParser : public AstParserBase<AstCaseItemDefaultHandle> {
public:
    AstCaseItemDefaultParser() { }
    AstCaseItemDefaultParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstCaseItemDefaultHandle &  pCaseItemDefault, unsigned int & pos);
    std::string getTokenName() const
      { return "case_item_default"; }
};

class AstBlockingAssingmentSemicolonParser : public AstParserBase<AstBlockingAssingmentSemicolonHandle> {
public:
    AstBlockingAssingmentSemicolonParser() { }
    AstBlockingAssingmentSemicolonParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBlockingAssingmentSemicolonHandle &  pBlockingAssignmentSemicolon, unsigned int & pos);
    std::string getTokenName() const
      { return "blocking_assignment_semicolon"; }
};

class AstKeywordForParser : public AstParserBase<AstKeywordForHandle> {
public:
    AstKeywordForParser() { }
    AstKeywordForParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordForHandle &  pKeywordFor);
    std::string getTokenName() const
      { return "keyword_for"; }
};

class AstZeroOrMoreCommaPortReferenceParser : public AstParserBase<AstZeroOrMoreCommaPortReferenceHandle> {
public:
    AstZeroOrMoreCommaPortReferenceParser() { }
    AstZeroOrMoreCommaPortReferenceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaPortReferenceHandle &  pZeroOrMoreCommaPortReference, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_port_reference"; }
};

class AstRangeSelectParser : public AstParserBase<AstRangeSelectHandle> {
public:
    AstRangeSelectParser() { }
    AstRangeSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstRangeSelectHandle &  pRangeSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "range_select"; }
};

class AstZeroOrMoreCommaIdentifierParser : public AstParserBase<AstZeroOrMoreCommaIdentifierHandle> {
public:
    AstZeroOrMoreCommaIdentifierParser() { }
    AstZeroOrMoreCommaIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaIdentifierHandle &  pZeroOrMoreCommaIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_identifier"; }
};

class AstBinaryConstantExpressionShiftLeftParser : public AstParserBase<AstBinaryConstantExpressionShiftLeftHandle> {
public:
    AstBinaryConstantExpressionShiftLeftParser() { }
    AstBinaryConstantExpressionShiftLeftParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionShiftLeftHandle &  pBinaryConstantExpressionShiftLeft, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_shift_left"; }
};

class AstTernaryConstantExpressionParser : public AstParserBase<AstTernaryConstantExpressionHandle> {
public:
    AstTernaryConstantExpressionParser() { }
    AstTernaryConstantExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstTernaryConstantExpressionHandle &  pTernaryConstantExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "ternary_constant_expression"; }
};

class AstUnaryOperatorMinusParser : public AstParserBase<AstUnaryOperatorMinusHandle> {
public:
    AstUnaryOperatorMinusParser() { }
    AstUnaryOperatorMinusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorMinusHandle &  pUnaryOperatorMinus, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_minus"; }
};

class AstInputDeclarationParser : public AstParserBase<AstInputDeclarationHandle> {
public:
    AstInputDeclarationParser() { }
    AstInputDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstInputDeclarationHandle &  pInputDeclaration);
    std::string getTokenName() const
      { return "input_declaration"; }
};

class AstZeroOrMoreCommaNInputGateInstanceParser : public AstParserBase<AstZeroOrMoreCommaNInputGateInstanceHandle> {
public:
    AstZeroOrMoreCommaNInputGateInstanceParser() { }
    AstZeroOrMoreCommaNInputGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaNInputGateInstanceHandle &  pZeroOrMoreCommaNInputGateInstance, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_n_input_gate_instance"; }
};

class BracedConstantExpressionParser : public AstParserBase<BracedConstantExpressionHandle> {
public:
    BracedConstantExpressionParser() { }
    BracedConstantExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(BracedConstantExpressionHandle &  pBracedConstantExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "braced_constant_expression"; }
};

class AstKeywordWireParser : public AstParserBase<AstKeywordWireHandle> {
public:
    AstKeywordWireParser() { }
    AstKeywordWireParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordWireHandle &  pKeywordWire);
    std::string getTokenName() const
      { return "keyword_wire"; }
};

class AstSimpleIdentifierParser : public AstParserBase<AstSimpleIdentifierHandle> {
public:
    AstSimpleIdentifierParser() { }
    AstSimpleIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstSimpleIdentifierHandle &  pSimpleIdentifier);
    std::string getTokenName() const
      { return "simple_identifier"; }
};

class AstUnsignedNumberParser : public AstParserBase<AstUnsignedNumberHandle> {
public:
    AstUnsignedNumberParser() { }
    AstUnsignedNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstUnsignedNumberHandle &  pUnsignedNumber);
    std::string getTokenName() const
      { return "unsigned_number"; }
};

class AstKeywordEndParser : public AstParserBase<AstKeywordEndHandle> {
public:
    AstKeywordEndParser() { }
    AstKeywordEndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordEndHandle &  pKeywordEnd);
    std::string getTokenName() const
      { return "keyword_end"; }
};

class AstSelectIdentifierParser : public AstParserBase<AstSelectIdentifierHandle> {
public:
    AstSelectIdentifierParser() { }
    AstSelectIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstSelectIdentifierHandle &  pSelectIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "select_identifier"; }
};

class AstBinaryExpressionEqParser : public AstParserBase<AstBinaryExpressionEqHandle> {
public:
    AstBinaryExpressionEqParser() { }
    AstBinaryExpressionEqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionEqHandle &  pBinaryExpressionEq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_eq"; }
};

class AstUnaryOperatorPlusParser : public AstParserBase<AstUnaryOperatorPlusHandle> {
public:
    AstUnaryOperatorPlusParser() { }
    AstUnaryOperatorPlusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorPlusHandle &  pUnaryOperatorPlus, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_plus"; }
};

class AstConstantRangeSelectParser : public AstParserBase<AstConstantRangeSelectHandle> {
public:
    AstConstantRangeSelectParser() { }
    AstConstantRangeSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstConstantRangeSelectHandle &  pConstantRangeSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "constant_range_select"; }
};

class AstNetAssignmentParser : public AstParserBase<AstNetAssignmentHandle> {
public:
    AstNetAssignmentParser() { }
    AstNetAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNetAssignmentHandle &  pNetAssignment);
    std::string getTokenName() const
      { return "net_assignment"; }
};

class AstBinaryExpressionBwXorParser : public AstParserBase<AstBinaryExpressionBwXorHandle> {
public:
    AstBinaryExpressionBwXorParser() { }
    AstBinaryExpressionBwXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionBwXorHandle &  pBinaryExpressionBwXor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_bw_xor"; }
};

class AstUnaryOperatorXorNegParser : public AstParserBase<AstUnaryOperatorXorNegHandle> {
public:
    AstUnaryOperatorXorNegParser() { }
    AstUnaryOperatorXorNegParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorXorNegHandle &  pUnaryOperatorXorNeg, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_xor_neg"; }
};

class AstModuleInstanceParser : public AstParserBase<AstModuleInstanceHandle> {
public:
    AstModuleInstanceParser() { }
    AstModuleInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleInstanceHandle &  pModuleInstance);
    std::string getTokenName() const
      { return "module_instance"; }
};

class AstBinaryOperatorNotEqualEqualParser : public AstParserBase<AstBinaryOperatorNotEqualEqualHandle> {
public:
    AstBinaryOperatorNotEqualEqualParser() { }
    AstBinaryOperatorNotEqualEqualParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorNotEqualEqualHandle &  pBinaryOperatorNotEqualEqual, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_not_equal_equal"; }
};

class AstProceduralContinuousAssignmentSemicolonParser : public AstParserBase<AstProceduralContinuousAssignmentSemicolonHandle> {
public:
    AstProceduralContinuousAssignmentSemicolonParser() { }
    AstProceduralContinuousAssignmentSemicolonParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstProceduralContinuousAssignmentSemicolonHandle &  pProceduralContinuousAssignmentSemicoln, unsigned int & pos);
    std::string getTokenName() const
      { return "procedural_continuous_assignment_semicolon"; }
};

class AstBinaryOperatorPlusParser : public AstParserBase<AstBinaryOperatorPlusHandle> {
public:
    AstBinaryOperatorPlusParser() { }
    AstBinaryOperatorPlusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorPlusHandle &  pBinaryOperatorPlus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_plus"; }
};

class AstEventControlParser : public AstParserBase<AstEventControlHandle> {
public:
    AstEventControlParser() { }
    AstEventControlParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstEventControlHandle &  pEventControl);
    std::string getTokenName() const
      { return "event_control"; }
};

class AstZeroOrOneRangeParser : public AstParserBase<AstZeroOrOneRangeHandle> {
public:
    AstZeroOrOneRangeParser() { }
    AstZeroOrOneRangeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneRangeHandle &  pZeroOrOneRange, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_range"; }
};

class AstBinaryExpressionNeqParser : public AstParserBase<AstBinaryExpressionNeqHandle> {
public:
    AstBinaryExpressionNeqParser() { }
    AstBinaryExpressionNeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionNeqHandle &  pBinaryExpressionNeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_neq"; }
};

class AstStatementOrNullParser : public AstParserBase<AstStatementOrNullHandle> {
public:
    AstStatementOrNullParser() { }
    AstStatementOrNullParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstStatementOrNullHandle &  pStatementOrNull);
    std::string getTokenName() const
      { return "statement_or_null"; }
};

class AstLoopStatementParser : public AstParserBase<AstLoopStatementHandle> {
public:
    AstLoopStatementParser() { }
    AstLoopStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstLoopStatementHandle &  pLoopStatement);
    std::string getTokenName() const
      { return "loop_statement"; }
};

class AstBinaryConstantExpressionBwAndParser : public AstParserBase<AstBinaryConstantExpressionBwAndHandle> {
public:
    AstBinaryConstantExpressionBwAndParser() { }
    AstBinaryConstantExpressionBwAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionBwAndHandle &  pBinaryConstantExpressionBwAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_bw_and"; }
};

class AstNInputGateTypeParser : public AstParserBase<AstNInputGateTypeHandle> {
public:
    AstNInputGateTypeParser() { }
    AstNInputGateTypeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNInputGateTypeHandle &  pNInputGateType);
    std::string getTokenName() const
      { return "n_input_gatetype"; }
};

class AstKeywordModuleParser : public AstParserBase<AstKeywordModuleHandle> {
public:
    AstKeywordModuleParser() { }
    AstKeywordModuleParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordModuleHandle &  pKeywordModule);
    std::string getTokenName() const
      { return "keyword_module"; }
};

class AstKeywordOrParser : public AstParserBase<AstKeywordOrHandle> {
public:
    AstKeywordOrParser() { }
    AstKeywordOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordOrHandle &  pKeywordOr);
    std::string getTokenName() const
      { return "keyword_or"; }
};

class AstConstantBitSelectParser : public AstParserBase<AstConstantBitSelectHandle> {
public:
    AstConstantBitSelectParser() { }
    AstConstantBitSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstConstantBitSelectHandle &  pConstantBitSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "constant_bit_select"; }
};

class AstListOfParamAssignmentParser : public AstParserBase<AstListOfParamAssignmentHandle> {
public:
    AstListOfParamAssignmentParser() { }
    AstListOfParamAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfParamAssignmentHandle &  pListOfParamAssignment);
    std::string getTokenName() const
      { return "list_of_param_assignments"; }
};

class AstGateInstantiationInputParser : public AstParserBase<AstGateInstantiationInputHandle> {
public:
    AstGateInstantiationInputParser() { }
    AstGateInstantiationInputParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstGateInstantiationInputHandle &  pGateInstantiationInput, unsigned int & pos);
    std::string getTokenName() const
      { return "gate_instantiation_input"; }
};

class AstZeroOrMoreModuleItemParser : public AstParserBase<AstZeroOrMoreModuleItemHandle> {
public:
    AstZeroOrMoreModuleItemParser() { }
    AstZeroOrMoreModuleItemParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreModuleItemHandle &  pZeroOrMoreModuleItem, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_module_item"; }
};

class AstParameterDeclarationParser : public AstParserBase<AstParameterDeclarationHandle> {
public:
    AstParameterDeclarationParser() { }
    AstParameterDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstParameterDeclarationHandle &  pParameterDeclaration);
    std::string getTokenName() const
      { return "parameter_declaration"; }
};

class AstOneOrMoreSelectParser : public AstParserBase<AstOneOrMoreSelectHandle> {
public:
    AstOneOrMoreSelectParser() { }
    AstOneOrMoreSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstOneOrMoreSelectHandle &  pOneOrMoreSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_select"; }
};

class AstBinaryConstantExpressionLtParser : public AstParserBase<AstBinaryConstantExpressionLtHandle> {
public:
    AstBinaryConstantExpressionLtParser() { }
    AstBinaryConstantExpressionLtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionLtHandle &  pBinaryConstantExpressionLt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_lt"; }
};

class AstKeywordIntegerParser : public AstParserBase<AstKeywordIntegerHandle> {
public:
    AstKeywordIntegerParser() { }
    AstKeywordIntegerParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordIntegerHandle &  pKeywordInteger);
    std::string getTokenName() const
      { return "keyword_integer"; }
};

class AstKeywordEndCaseParser : public AstParserBase<AstKeywordEndCaseHandle> {
public:
    AstKeywordEndCaseParser() { }
    AstKeywordEndCaseParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordEndCaseHandle &  pKeywordEndCase);
    std::string getTokenName() const
      { return "keyword_endcase"; }
};

class AstZeroOrMoreCommaOrderedPortConnectionParser : public AstParserBase<AstZeroOrMoreCommaOrderedPortConnectionHandle> {
public:
    AstZeroOrMoreCommaOrderedPortConnectionParser() { }
    AstZeroOrMoreCommaOrderedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaOrderedPortConnectionHandle &  pZeroOrMoreCommaOrderedPortConnection, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_ordered_port_connection"; }
};

class AstEventOrAsteriskParser : public AstParserBase<AstEventOrAsteriskHandle> {
public:
    AstEventOrAsteriskParser() { }
    AstEventOrAsteriskParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstEventOrAsteriskHandle &  pEventOrAsterisk, unsigned int & pos);
    std::string getTokenName() const
      { return "event_or_asterisk"; }
};

class AstBinaryOperatorShrParser : public AstParserBase<AstBinaryOperatorShrHandle> {
public:
    AstBinaryOperatorShrParser() { }
    AstBinaryOperatorShrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorShrHandle &  pBinaryOperatorShr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_shr"; }
};

class AstUnaryOperatorNegParser : public AstParserBase<AstUnaryOperatorNegHandle> {
public:
    AstUnaryOperatorNegParser() { }
    AstUnaryOperatorNegParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorNegHandle &  pUnaryOperatorNeg, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_neg"; }
};

class AstUnaryConstantExpressionParser : public AstParserBase<AstUnaryConstantExpressionHandle> {
public:
    AstUnaryConstantExpressionParser() { }
    AstUnaryConstantExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryConstantExpressionHandle &  pUnaryConstantExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_constant_expression"; }
};

class AstZeroOrMoreCommaInputTerminalParser : public AstParserBase<AstZeroOrMoreCommaInputTerminalHandle> {
public:
    AstZeroOrMoreCommaInputTerminalParser() { }
    AstZeroOrMoreCommaInputTerminalParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaInputTerminalHandle &  pZeroOrMoreCommaInputTerminal, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_input_terminal"; }
};

class AstNegedgeExpressionParser : public AstParserBase<AstNegedgeExpressionHandle> {
public:
    AstNegedgeExpressionParser() { }
    AstNegedgeExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstNegedgeExpressionHandle &  pNegedgeExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "negedge_expression"; }
};

class AstRegDeclarationParser : public AstParserBase<AstRegDeclarationHandle> {
public:
    AstRegDeclarationParser() { }
    AstRegDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstRegDeclarationHandle &  pRegDeclaration);
    std::string getTokenName() const
      { return "reg_declaration"; }
};

class AstBinaryConstantExpressionLgAndParser : public AstParserBase<AstBinaryConstantExpressionLgAndHandle> {
public:
    AstBinaryConstantExpressionLgAndParser() { }
    AstBinaryConstantExpressionLgAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionLgAndHandle &  pBinaryConstantExpressionLgAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_lg_and"; }
};

class AstOneOrMoreCaseItemParser : public AstParserBase<AstOneOrMoreCaseItemHandle> {
public:
    AstOneOrMoreCaseItemParser() { }
    AstOneOrMoreCaseItemParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstOneOrMoreCaseItemHandle &  pOneOrMoreCaseItem, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_case_item"; }
};

class AstKeywordInitialParser : public AstParserBase<AstKeywordInitialHandle> {
public:
    AstKeywordInitialParser() { }
    AstKeywordInitialParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordInitialHandle &  pKeywordInitial);
    std::string getTokenName() const
      { return "keyword_initial"; }
};

class AstBinaryExpressionBwNxorParser : public AstParserBase<AstBinaryExpressionBwNxorHandle> {
public:
    AstBinaryExpressionBwNxorParser() { }
    AstBinaryExpressionBwNxorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionBwNxorHandle &  pBinaryExpressionBwNxor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_bw_nxor"; }
};

class AstListOfNetAssignmentsParser : public AstParserBase<AstListOfNetAssignmentsHandle> {
public:
    AstListOfNetAssignmentsParser() { }
    AstListOfNetAssignmentsParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfNetAssignmentsHandle &  pListOfNetAssignments);
    std::string getTokenName() const
      { return "list_of_net_assignments"; }
};

class AstSingleIdentifierParser : public AstParserBase<AstSingleIdentifierHandle> {
public:
    AstSingleIdentifierParser() { }
    AstSingleIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstSingleIdentifierHandle &  pSingleIdentifier);
    std::string getTokenName() const
      { return "single_identifier"; }
};

class AstConstantExpressionParser : public AstParserBase<AstConstantExpressionHandle> {
public:
    AstConstantExpressionParser() { }
    AstConstantExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstConstantExpressionHandle &  pConstantExpression);
    std::string getTokenName() const
      { return "constant_expression"; }
};

class AstBinaryConstantExpressionMultiplyParser : public AstParserBase<AstBinaryConstantExpressionMultiplyHandle> {
public:
    AstBinaryConstantExpressionMultiplyParser() { }
    AstBinaryConstantExpressionMultiplyParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionMultiplyHandle &  pBinaryConstantExpressionMultiply, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_multiply"; }
};

class AstOutputDeclarationParser : public AstParserBase<AstOutputDeclarationHandle> {
public:
    AstOutputDeclarationParser() { }
    AstOutputDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstOutputDeclarationHandle &  pOutputDeclaration);
    std::string getTokenName() const
      { return "output_declaration"; }
};

class AstModuleKeywordParser : public AstParserBase<AstModuleKeywordHandle> {
public:
    AstModuleKeywordParser() { }
    AstModuleKeywordParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleKeywordHandle &  pModuleKeyword);
    std::string getTokenName() const
      { return "module_keyword"; }
};

class AstBinaryOperatorLtParser : public AstParserBase<AstBinaryOperatorLtHandle> {
public:
    AstBinaryOperatorLtParser() { }
    AstBinaryOperatorLtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorLtHandle &  pBinaryOperatorLt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_lt"; }
};

class AstNOutputGateTypeParser : public AstParserBase<AstNOutputGateTypeHandle> {
public:
    AstNOutputGateTypeParser() { }
    AstNOutputGateTypeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNOutputGateTypeHandle &  pNOutputGateType);
    std::string getTokenName() const
      { return "n_output_gatetype"; }
};

class AstDecimalNumberParser : public AstParserBase<AstDecimalNumberHandle> {
public:
    AstDecimalNumberParser() { }
    AstDecimalNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstDecimalNumberHandle &  pDecimalNumber);
    std::string getTokenName() const
      { return "decimal_number"; }
};

class AstBinaryOperatorTripleEqualParser : public AstParserBase<AstBinaryOperatorTripleEqualHandle> {
public:
    AstBinaryOperatorTripleEqualParser() { }
    AstBinaryOperatorTripleEqualParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorTripleEqualHandle &  pBinaryOperatorTripleEqual, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_triple_equal"; }
};

class AstKeywordElseParser : public AstParserBase<AstKeywordElseHandle> {
public:
    AstKeywordElseParser() { }
    AstKeywordElseParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordElseHandle &  pKeywordElse);
    std::string getTokenName() const
      { return "keyword_else"; }
};

class AstBinaryConstantExpressionMinusParser : public AstParserBase<AstBinaryConstantExpressionMinusHandle> {
public:
    AstBinaryConstantExpressionMinusParser() { }
    AstBinaryConstantExpressionMinusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionMinusHandle &  pBinaryConstantExpressionMinus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_minus"; }
};

class AstNameOfGateInstanceParser : public AstParserBase<AstNameOfGateInstanceHandle> {
public:
    AstNameOfGateInstanceParser() { }
    AstNameOfGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNameOfGateInstanceHandle &  pNameOfGateInstance);
    std::string getTokenName() const
      { return "name_of_gate_instance"; }
};

class AstUnaryOperatorNegAndParser : public AstParserBase<AstUnaryOperatorNegAndHandle> {
public:
    AstUnaryOperatorNegAndParser() { }
    AstUnaryOperatorNegAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorNegAndHandle &  pUnaryOperatorNegAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_neg_and"; }
};

class AstAlwaysConstructParser : public AstParserBase<AstAlwaysConstructHandle> {
public:
    AstAlwaysConstructParser() { }
    AstAlwaysConstructParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstAlwaysConstructHandle &  pAlwaysConstruct);
    std::string getTokenName() const
      { return "always_construct"; }
};

class AstOctalNumberParser : public AstParserBase<AstOctalNumberHandle> {
public:
    AstOctalNumberParser() { }
    AstOctalNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstOctalNumberHandle &  pOctalNumber);
    std::string getTokenName() const
      { return "octal_number"; }
};

class AstBinaryConstantExpressionParser : public AstParserBase<AstBinaryConstantExpressionHandle> {
public:
    AstBinaryConstantExpressionParser() { }
    AstBinaryConstantExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionHandle &  pBinaryConstantExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression"; }
};

class AstBinaryExpressionLgOrParser : public AstParserBase<AstBinaryExpressionLgOrHandle> {
public:
    AstBinaryExpressionLgOrParser() { }
    AstBinaryExpressionLgOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionLgOrHandle &  pBinaryExpressionLgOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_lg_or"; }
};

class AstBinaryOperatorEqualEqualParser : public AstParserBase<AstBinaryOperatorEqualEqualHandle> {
public:
    AstBinaryOperatorEqualEqualParser() { }
    AstBinaryOperatorEqualEqualParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorEqualEqualHandle &  pBinaryOperatorEqualEqual, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_equal_equal"; }
};

class AstHeximalNumberParser : public AstParserBase<AstHeximalNumberHandle> {
public:
    AstHeximalNumberParser() { }
    AstHeximalNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstHeximalNumberHandle &  pHeximalNumber);
    std::string getTokenName() const
      { return "heximal_number"; }
};

class AstListOfPortReferencesParser : public AstParserBase<AstListOfPortReferencesHandle> {
public:
    AstListOfPortReferencesParser() { }
    AstListOfPortReferencesParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstListOfPortReferencesHandle &  pListOfPortReferences, unsigned int & pos);
    std::string getTokenName() const
      { return "list_of_port_references"; }
};

class AstNetLvalueParser : public AstParserBase<AstNetLvalueHandle> {
public:
    AstNetLvalueParser() { }
    AstNetLvalueParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNetLvalueHandle &  pNetLvalue);
    std::string getTokenName() const
      { return "net_lvalue"; }
};

class AstBinaryOperatorAndAndParser : public AstParserBase<AstBinaryOperatorAndAndHandle> {
public:
    AstBinaryOperatorAndAndParser() { }
    AstBinaryOperatorAndAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorAndAndHandle &  pBinaryOperatorAndAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_and_and"; }
};

class AstNInputGateInstanceParser : public AstParserBase<AstNInputGateInstanceHandle> {
public:
    AstNInputGateInstanceParser() { }
    AstNInputGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNInputGateInstanceHandle &  pNInputGateInstance);
    std::string getTokenName() const
      { return "n_input_gate_instance"; }
};

class AstListOfPortsParser : public AstParserBase<AstListOfPortsHandle> {
public:
    AstListOfPortsParser() { }
    AstListOfPortsParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfPortsHandle &  pListOfPorts);
    std::string getTokenName() const
      { return "list_of_ports"; }
};

class AstOneOrMoreCommaExpressionParser : public AstParserBase<AstOneOrMoreCommaExpressionHandle> {
public:
    AstOneOrMoreCommaExpressionParser() { }
    AstOneOrMoreCommaExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstOneOrMoreCommaExpressionHandle &  pOneOrMoreCommaExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_comma_expression"; }
};

class AstNamedPortConnectionParser : public AstParserBase<AstNamedPortConnectionHandle> {
public:
    AstNamedPortConnectionParser() { }
    AstNamedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNamedPortConnectionHandle &  pNamedPortConnection);
    std::string getTokenName() const
      { return "named_port_connection"; }
};

class AstModuleItemDeclarationParser : public AstParserBase<AstModuleItemDeclarationHandle> {
public:
    AstModuleItemDeclarationParser() { }
    AstModuleItemDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleItemDeclarationHandle &  pModuleItemDeclaration);
    std::string getTokenName() const
      { return "module_item_declaration"; }
};

class AstBinaryConstantExpressionLeqParser : public AstParserBase<AstBinaryConstantExpressionLeqHandle> {
public:
    AstBinaryConstantExpressionLeqParser() { }
    AstBinaryConstantExpressionLeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionLeqHandle &  pBinaryConstantExpressionLeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_leq"; }
};

class AstBinaryExpressionDivideParser : public AstParserBase<AstBinaryExpressionDivideHandle> {
public:
    AstBinaryExpressionDivideParser() { }
    AstBinaryExpressionDivideParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionDivideHandle &  pBinaryExpressionDivide, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_divide"; }
};

class AstBinaryExpressionLtParser : public AstParserBase<AstBinaryExpressionLtHandle> {
public:
    AstBinaryExpressionLtParser() { }
    AstBinaryExpressionLtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionLtHandle &  pBinaryExpressionLt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_lt"; }
};

class AstRegisterNameParser : public AstParserBase<AstRegisterNameHandle> {
public:
    AstRegisterNameParser() { }
    AstRegisterNameParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstRegisterNameHandle &  pRegisterName);
    std::string getTokenName() const
      { return "register_name"; }
};

class AstModuleInstantiationParser : public AstParserBase<AstModuleInstantiationHandle> {
public:
    AstModuleInstantiationParser() { }
    AstModuleInstantiationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleInstantiationHandle &  pModuleInstantiation);
    std::string getTokenName() const
      { return "module_instantiation"; }
};

class AstBinaryConstantExpressionBwNxorParser : public AstParserBase<AstBinaryConstantExpressionBwNxorHandle> {
public:
    AstBinaryConstantExpressionBwNxorParser() { }
    AstBinaryConstantExpressionBwNxorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionBwNxorHandle &  pBinaryConstantExpressionBwNxor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_bw_nxor"; }
};

class AstZeroOrMoreCommaPortParser : public AstParserBase<AstZeroOrMoreCommaPortHandle> {
public:
    AstZeroOrMoreCommaPortParser() { }
    AstZeroOrMoreCommaPortParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaPortHandle &  pZeroOrMoreCommaPort, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_port"; }
};

class AstUnaryOperatorParser : public AstParserBase<AstUnaryOperatorHandle> {
public:
    AstUnaryOperatorParser() { }
    AstUnaryOperatorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstUnaryOperatorHandle &  pUnaryOperator);
    std::string getTokenName() const
      { return "unary_operator"; }
};

class AstNonBlockingAssignmentSemicolonParser : public AstParserBase<AstNonBlockingAssignmentSemicolonHandle> {
public:
    AstNonBlockingAssignmentSemicolonParser() { }
    AstNonBlockingAssignmentSemicolonParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstNonBlockingAssignmentSemicolonHandle &  pNonBlockingAssignmentSemicolon, unsigned int & pos);
    std::string getTokenName() const
      { return "non_blocking_assignment_semicolon"; }
};

class AstKeywordIfParser : public AstParserBase<AstKeywordIfHandle> {
public:
    AstKeywordIfParser() { }
    AstKeywordIfParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordIfHandle &  pKeywordIf);
    std::string getTokenName() const
      { return "keyword_if"; }
};

class AstBinaryExpressionMultiplyParser : public AstParserBase<AstBinaryExpressionMultiplyHandle> {
public:
    AstBinaryExpressionMultiplyParser() { }
    AstBinaryExpressionMultiplyParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionMultiplyHandle &  pBinaryExpressionMultiply, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_multiply"; }
};

class AstNonBlockingAssignmentParser : public AstParserBase<AstNonBlockingAssignmentHandle> {
public:
    AstNonBlockingAssignmentParser() { }
    AstNonBlockingAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNonBlockingAssignmentHandle &  pNonBlockingAssignment);
    std::string getTokenName() const
      { return "non_blocking_assignment"; }
};

class AstZeroOrMoreCommaOutputTerminalParser : public AstParserBase<AstZeroOrMoreCommaOutputTerminalHandle> {
public:
    AstZeroOrMoreCommaOutputTerminalParser() { }
    AstZeroOrMoreCommaOutputTerminalParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaOutputTerminalHandle &  pZeroOrMoreCommaOutputTerminal, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_output_terminal"; }
};

class AstGateInstantiationParser : public AstParserBase<AstGateInstantiationHandle> {
public:
    AstGateInstantiationParser() { }
    AstGateInstantiationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstGateInstantiationHandle &  pGateInstantiation);
    std::string getTokenName() const
      { return "gate_instantiation"; }
};

class AstBinaryConstantExpressionModulusParser : public AstParserBase<AstBinaryConstantExpressionModulusHandle> {
public:
    AstBinaryConstantExpressionModulusParser() { }
    AstBinaryConstantExpressionModulusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionModulusHandle &  pBinaryConstantExpressionModulus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_modulus"; }
};

class AstBinaryConstantExpressionBwXnorParser : public AstParserBase<AstBinaryConstantExpressionBwXnorHandle> {
public:
    AstBinaryConstantExpressionBwXnorParser() { }
    AstBinaryConstantExpressionBwXnorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionBwXnorHandle &  pBinaryConstantExpressionBwXnor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_bw_xnor"; }
};

class AstBinaryExpressionBwXnorParser : public AstParserBase<AstBinaryExpressionBwXnorHandle> {
public:
    AstBinaryExpressionBwXnorParser() { }
    AstBinaryExpressionBwXnorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionBwXnorHandle &  pBinaryExpressionBwXnor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_bw_xnor"; }
};

class AstNetLvalueRangeSelectParser : public AstParserBase<AstNetLvalueRangeSelectHandle> {
public:
    AstNetLvalueRangeSelectParser() { }
    AstNetLvalueRangeSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstNetLvalueRangeSelectHandle &  pNetLvalueRangeSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "net_lvalue_range_select"; }
};

class AstBracedExpressionParser : public AstParserBase<AstBracedExpressionHandle> {
public:
    AstBracedExpressionParser() { }
    AstBracedExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBracedExpressionHandle &  pBracedExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "braced_expression"; }
};

class AstBinaryOperatorParser : public AstParserBase<AstBinaryOperatorHandle> {
public:
    AstBinaryOperatorParser() { }
    AstBinaryOperatorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstBinaryOperatorHandle &  pBinaryOperator);
    std::string getTokenName() const
      { return "binary_operator"; }
};

class AstZeroOrMoreCommaRegisterNameParser : public AstParserBase<AstZeroOrMoreCommaRegisterNameHandle> {
public:
    AstZeroOrMoreCommaRegisterNameParser() { }
    AstZeroOrMoreCommaRegisterNameParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaRegisterNameHandle &  pZeroOrMoreCommaRegisterName, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_register_name"; }
};

class AstBinaryExpressionModulusParser : public AstParserBase<AstBinaryExpressionModulusHandle> {
public:
    AstBinaryExpressionModulusParser() { }
    AstBinaryExpressionModulusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionModulusHandle &  pBinaryExpressionModulus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_modulus"; }
};

class AstBinaryExpressionGtParser : public AstParserBase<AstBinaryExpressionGtHandle> {
public:
    AstBinaryExpressionGtParser() { }
    AstBinaryExpressionGtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionGtHandle &  pBinaryExpressionGt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_gt"; }
};

class AstUnaryOperatorAndParser : public AstParserBase<AstUnaryOperatorAndHandle> {
public:
    AstUnaryOperatorAndParser() { }
    AstUnaryOperatorAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorAndHandle &  pUnaryOperatorAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_and"; }
};

class AstZeroOrOneElseStatementOrNullParser : public AstParserBase<AstZeroOrOneElseStatementOrNullHandle> {
public:
    AstZeroOrOneElseStatementOrNullParser() { }
    AstZeroOrOneElseStatementOrNullParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneElseStatementOrNullHandle &  pZeroOrOneElseStatementOrNull, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_else_statement_or_null"; }
};

class AstBinaryConstantExpressionCaseNeqParser : public AstParserBase<AstBinaryConstantExpressionCaseNeqHandle> {
public:
    AstBinaryConstantExpressionCaseNeqParser() { }
    AstBinaryConstantExpressionCaseNeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionCaseNeqHandle &  pBinaryConstantExpressionCaseNeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_case_neq"; }
};

class AstSourceTextParser : public AstParserBase<AstSourceTextHandle> {
public:
    AstSourceTextParser() { }
    AstSourceTextParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstSourceTextHandle &  pSourceText);
    std::string getTokenName() const
      { return "source_text"; }
};

class AstEventOrEventParser : public AstParserBase<AstEventOrEventHandle> {
public:
    AstEventOrEventParser() { }
    AstEventOrEventParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstEventOrEventHandle &  pEventOrEvent, unsigned int & pos);
    std::string getTokenName() const
      { return "event_or_event"; }
};

class AstBinaryExpressionCaseEqParser : public AstParserBase<AstBinaryExpressionCaseEqHandle> {
public:
    AstBinaryExpressionCaseEqParser() { }
    AstBinaryExpressionCaseEqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionCaseEqHandle &  pBinaryExpressionCaseEq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_case_eq"; }
};

class AstBinaryExpressionLgAndParser : public AstParserBase<AstBinaryExpressionLgAndHandle> {
public:
    AstBinaryExpressionLgAndParser() { }
    AstBinaryExpressionLgAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionLgAndHandle &  pBinaryExpressionLgAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_lg_and"; }
};

class AstZeroOrOneExpressionParser : public AstParserBase<AstZeroOrOneExpressionHandle> {
public:
    AstZeroOrOneExpressionParser() { }
    AstZeroOrOneExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneExpressionHandle &  pZeroOrOneExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_expression"; }
};

class AstBinaryNumberParser : public AstParserBase<AstBinaryNumberHandle> {
public:
    AstBinaryNumberParser() { }
    AstBinaryNumberParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstBinaryNumberHandle &  pBinaryNumber);
    std::string getTokenName() const
      { return "binary_number"; }
};

class AstMultipleConcatenationParser : public AstParserBase<AstMultipleConcatenationHandle> {
public:
    AstMultipleConcatenationParser() { }
    AstMultipleConcatenationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstMultipleConcatenationHandle &  pMulitpleConcatenation);
    std::string getTokenName() const
      { return "multiple_concatenation"; }
};

class AstBinaryConstantExpressionPlusParser : public AstParserBase<AstBinaryConstantExpressionPlusHandle> {
public:
    AstBinaryConstantExpressionPlusParser() { }
    AstBinaryConstantExpressionPlusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionPlusHandle &  pBinaryConstantExpressionPlus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_plus"; }
};

class AstListOfOrderedPortConnectionParser : public AstParserBase<AstListOfOrderedPortConnectionHandle> {
public:
    AstListOfOrderedPortConnectionParser() { }
    AstListOfOrderedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstListOfOrderedPortConnectionHandle &  pListOfOrderedPortConnection, unsigned int & pos);
    std::string getTokenName() const
      { return "list_of_ordered_port_connection"; }
};

class AstMultiIdentifierParser : public AstParserBase<AstMultiIdentifierHandle> {
public:
    AstMultiIdentifierParser() { }
    AstMultiIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstMultiIdentifierHandle &  pMultiIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "multi_identifier"; }
};

class AstKeywordPosedgeParser : public AstParserBase<AstKeywordPosedgeHandle> {
public:
    AstKeywordPosedgeParser() { }
    AstKeywordPosedgeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordPosedgeHandle &  pKeywordPosedge);
    std::string getTokenName() const
      { return "keyword_posedge"; }
};

class AstBinaryExpressionPlusParser : public AstParserBase<AstBinaryExpressionPlusHandle> {
public:
    AstBinaryExpressionPlusParser() { }
    AstBinaryExpressionPlusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionPlusHandle &  pBinaryExpressionPlus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_plus"; }
};

class AstUnaryOperatorNegXorParser : public AstParserBase<AstUnaryOperatorNegXorHandle> {
public:
    AstUnaryOperatorNegXorParser() { }
    AstUnaryOperatorNegXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorNegXorHandle &  pUnaryOperatorNegXor, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_neg_xor"; }
};

class AstOutputTerminalParser : public AstParserBase<AstOutputTerminalHandle> {
public:
    AstOutputTerminalParser() { }
    AstOutputTerminalParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstOutputTerminalHandle &  pOutputTerminal);
    std::string getTokenName() const
      { return "output_terminal"; }
};

class AstUnaryOperatorXorParser : public AstParserBase<AstUnaryOperatorXorHandle> {
public:
    AstUnaryOperatorXorParser() { }
    AstUnaryOperatorXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorXorHandle &  pUnaryOperatorXor, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_xor"; }
};

class AstKeywordRegParser : public AstParserBase<AstKeywordRegHandle> {
public:
    AstKeywordRegParser() { }
    AstKeywordRegParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordRegHandle &  pKeywordReg);
    std::string getTokenName() const
      { return "keyword_reg"; }
};

class AstZeroOrMoreCommaNOutputGateInstanceParser : public AstParserBase<AstZeroOrMoreCommaNOutputGateInstanceHandle> {
public:
    AstZeroOrMoreCommaNOutputGateInstanceParser() { }
    AstZeroOrMoreCommaNOutputGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaNOutputGateInstanceHandle &  pZeroOrMoreCommaNOutputGateInstance, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_n_output_gate_instance"; }
};

class AstAtEventExpressionParser : public AstParserBase<AstAtEventExpressionHandle> {
public:
    AstAtEventExpressionParser() { }
    AstAtEventExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstAtEventExpressionHandle &  pAstEventExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "at_event_expression"; }
};

class AstInitialConstructParser : public AstParserBase<AstInitialConstructHandle> {
public:
    AstInitialConstructParser() { }
    AstInitialConstructParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstInitialConstructHandle &  pInitialConstruct);
    std::string getTokenName() const
      { return "initial_construct"; }
};

class AstBinaryOperatorMinusParser : public AstParserBase<AstBinaryOperatorMinusHandle> {
public:
    AstBinaryOperatorMinusParser() { }
    AstBinaryOperatorMinusParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorMinusHandle &  pBinaryOperatorMinus, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_minus"; }
};

class AstBinaryConstantExpressionDivideParser : public AstParserBase<AstBinaryConstantExpressionDivideHandle> {
public:
    AstBinaryConstantExpressionDivideParser() { }
    AstBinaryConstantExpressionDivideParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionDivideHandle &  pBinaryConstantExpressionDivide, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_divide"; }
};

class AstKeywordAssignParser : public AstParserBase<AstKeywordAssignHandle> {
public:
    AstKeywordAssignParser() { }
    AstKeywordAssignParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordAssignHandle &  pKeywordAssign);
    std::string getTokenName() const
      { return "keyword_assign"; }
};

class AstIntegerDeclarationParser : public AstParserBase<AstIntegerDeclarationHandle> {
public:
    AstIntegerDeclarationParser() { }
    AstIntegerDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstIntegerDeclarationHandle &  pIntegerDeclaration);
    std::string getTokenName() const
      { return "integer_declaration"; }
};

class AstBinaryConstantExpressionLgOrParser : public AstParserBase<AstBinaryConstantExpressionLgOrHandle> {
public:
    AstBinaryConstantExpressionLgOrParser() { }
    AstBinaryConstantExpressionLgOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionLgOrHandle &  pBinaryConstantExpressionLgOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_lg_or"; }
};

class AstBinaryConstantExpressionBwOrParser : public AstParserBase<AstBinaryConstantExpressionBwOrHandle> {
public:
    AstBinaryConstantExpressionBwOrParser() { }
    AstBinaryConstantExpressionBwOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionBwOrHandle &  pBinaryConstantExpressionBwOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_bw_or"; }
};

class AstNetTypeParser : public AstParserBase<AstNetTypeHandle> {
public:
    AstNetTypeParser() { }
    AstNetTypeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNetTypeHandle &  pNetType);
    std::string getTokenName() const
      { return "net_type"; }
};

class AstDelayOrEventControlParser : public AstParserBase<AstDelayOrEventControlHandle> {
public:
    AstDelayOrEventControlParser() { }
    AstDelayOrEventControlParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstDelayOrEventControlHandle &  pDelayOrEventControl);
    std::string getTokenName() const
      { return "delay_or_event_control"; }
};

class AstNOutputGateInstanceParser : public AstParserBase<AstNOutputGateInstanceHandle> {
public:
    AstNOutputGateInstanceParser() { }
    AstNOutputGateInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNOutputGateInstanceHandle &  pNOutputGateInstance);
    std::string getTokenName() const
      { return "n_output_gate_instance"; }
};

class AstConditionalStatementParser : public AstParserBase<AstConditionalStatementHandle> {
public:
    AstConditionalStatementParser() { }
    AstConditionalStatementParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstConditionalStatementHandle &  pConditionalStatement);
    std::string getTokenName() const
      { return "conditional_statement"; }
};

class AstBinaryConstantExpressionGtParser : public AstParserBase<AstBinaryConstantExpressionGtHandle> {
public:
    AstBinaryConstantExpressionGtParser() { }
    AstBinaryConstantExpressionGtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionGtHandle &  pBinaryConstantExpressionGt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_gt"; }
};

class AstZeroOrOnePortExpressionParser : public AstParserBase<AstZeroOrOnePortExpressionHandle> {
public:
    AstZeroOrOnePortExpressionParser() { }
    AstZeroOrOnePortExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOnePortExpressionHandle &  pZeroOrOnePortExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_port_expression"; }
};

class AstZeroOrOneConstantBitSelectParser : public AstParserBase<AstZeroOrOneConstantBitSelectHandle> {
public:
    AstZeroOrOneConstantBitSelectParser() { }
    AstZeroOrOneConstantBitSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneConstantBitSelectHandle &  pAstZeroOrOneConstantBitSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_constant_bit_select"; }
};

class AstKeywordCaseParser : public AstParserBase<AstKeywordCaseHandle> {
public:
    AstKeywordCaseParser() { }
    AstKeywordCaseParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordCaseHandle &  pKeywordCase);
    std::string getTokenName() const
      { return "keyword_case"; }
};

class AstZeroOrMoreRegisterNameRangeParser : public AstParserBase<AstZeroOrMoreRegisterNameRangeHandle> {
public:
    AstZeroOrMoreRegisterNameRangeParser() { }
    AstZeroOrMoreRegisterNameRangeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreRegisterNameRangeHandle &  pZeroOrMoreRegisterNameRange, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_register_name_range"; }
};

class AstBinaryOperatorOrParser : public AstParserBase<AstBinaryOperatorOrHandle> {
public:
    AstBinaryOperatorOrParser() { }
    AstBinaryOperatorOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorOrHandle &  pBinaryOperatorOr, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_or"; }
};

class AstCaseItemItemParser : public AstParserBase<AstCaseItemItemHandle> {
public:
    AstCaseItemItemParser() { }
    AstCaseItemItemParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstCaseItemItemHandle &  pCaseItemItem, unsigned int & pos);
    std::string getTokenName() const
      { return "case_item_item"; }
};

class AstUnaryOperatorNegOrParser : public AstParserBase<AstUnaryOperatorNegOrHandle> {
public:
    AstUnaryOperatorNegOrParser() { }
    AstUnaryOperatorNegOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorNegOrHandle &  pUnaryOperatorNegOr, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_neg_or"; }
};

class AstModuleDeclarationParser : public AstParserBase<AstModuleDeclarationHandle> {
public:
    AstModuleDeclarationParser() { }
    AstModuleDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstModuleDeclarationHandle &  pModuleDeclaration);
    std::string getTokenName() const
      { return "module_declaration"; }
};

class AstBinaryConstantExpressionBwXorParser : public AstParserBase<AstBinaryConstantExpressionBwXorHandle> {
public:
    AstBinaryConstantExpressionBwXorParser() { }
    AstBinaryConstantExpressionBwXorParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionBwXorHandle &  pBinaryConstantExpressionBwXor, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_bw_xor"; }
};

class AstConstantPrimaryParser : public AstParserBase<AstConstantPrimaryHandle> {
public:
    AstConstantPrimaryParser() { }
    AstConstantPrimaryParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstConstantPrimaryHandle &  pConstantPrimary);
    std::string getTokenName() const
      { return "constant_primary"; }
};

class AstPosedgeExpressionParser : public AstParserBase<AstPosedgeExpressionHandle> {
public:
    AstPosedgeExpressionParser() { }
    AstPosedgeExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstPosedgeExpressionHandle &  pPosedgeExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "posedge_expression"; }
};

class AstListOfModuleConnectionsParser : public AstParserBase<AstListOfModuleConnectionsHandle> {
public:
    AstListOfModuleConnectionsParser() { }
    AstListOfModuleConnectionsParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstListOfModuleConnectionsHandle &  pListOfModuleConnections);
    std::string getTokenName() const
      { return "list_of_module_connections"; }
};

class AstRegAssignmentParser : public AstParserBase<AstRegAssignmentHandle> {
public:
    AstRegAssignmentParser() { }
    AstRegAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstRegAssignmentHandle &  pRegAssignment);
    std::string getTokenName() const
      { return "reg_assignment"; }
};

class AstBinaryOperatorGeqParser : public AstParserBase<AstBinaryOperatorGeqHandle> {
public:
    AstBinaryOperatorGeqParser() { }
    AstBinaryOperatorGeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorGeqHandle &  pBinaryOperatorGeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_geq"; }
};

class AstBinaryExpressionLeqParser : public AstParserBase<AstBinaryExpressionLeqHandle> {
public:
    AstBinaryExpressionLeqParser() { }
    AstBinaryExpressionLeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionLeqHandle &  pBinaryExpressionLeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_leq"; }
};

class AstAtAsteriskParser : public AstParserBase<AstAtAsteriskHandle> {
public:
    AstAtAsteriskParser() { }
    AstAtAsteriskParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstAtAsteriskHandle &  pAtAsterisk, unsigned int & pos);
    std::string getTokenName() const
      { return "at_asterisk"; }
};

class AstRegLvalueParser : public AstParserBase<AstRegLvalueHandle> {
public:
    AstRegLvalueParser() { }
    AstRegLvalueParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstRegLvalueHandle &  pRegLvalue);
    std::string getTokenName() const
      { return "reg_lvalue"; }
};

class AstBinaryOperatorAndParser : public AstParserBase<AstBinaryOperatorAndHandle> {
public:
    AstBinaryOperatorAndParser() { }
    AstBinaryOperatorAndParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorAndHandle &  pBinaryOperatorAnd, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_and"; }
};

class AstAtEventOrAsteriskParser : public AstParserBase<AstAtEventOrAsteriskHandle> {
public:
    AstAtEventOrAsteriskParser() { }
    AstAtEventOrAsteriskParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstAtEventOrAsteriskHandle &  pAstEventOrAsterisk, unsigned int & pos);
    std::string getTokenName() const
      { return "at_event_or_asterisk"; }
};

class AstKeywordDefaultParser : public AstParserBase<AstKeywordDefaultHandle> {
public:
    AstKeywordDefaultParser() { }
    AstKeywordDefaultParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordDefaultHandle &  pKeywordDefault);
    std::string getTokenName() const
      { return "keyword_default"; }
};

class AstBinaryExpressionShiftRightParser : public AstParserBase<AstBinaryExpressionShiftRightHandle> {
public:
    AstBinaryExpressionShiftRightParser() { }
    AstBinaryExpressionShiftRightParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionShiftRightHandle &  pBinaryExpressionShiftRight, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_shift_right"; }
};

class AstListOfNamedPortConnectionParser : public AstParserBase<AstListOfNamedPortConnectionHandle> {
public:
    AstListOfNamedPortConnectionParser() { }
    AstListOfNamedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstListOfNamedPortConnectionHandle &  pListOfNamedPortConnection, unsigned int & pos);
    std::string getTokenName() const
      { return "list_of_named_port_connection"; }
};

class AstBinaryOperatorShlParser : public AstParserBase<AstBinaryOperatorShlHandle> {
public:
    AstBinaryOperatorShlParser() { }
    AstBinaryOperatorShlParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorShlHandle &  pBinaryOperatorShl, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_shl"; }
};

class AstKeywordEndmoduleParser : public AstParserBase<AstKeywordEndmoduleHandle> {
public:
    AstKeywordEndmoduleParser() { }
    AstKeywordEndmoduleParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordEndmoduleHandle &  pKeywordEndmodule);
    std::string getTokenName() const
      { return "keyword_endmodule"; }
};

class AstBinaryExpressionParser : public AstParserBase<AstBinaryExpressionHandle> {
public:
    AstBinaryExpressionParser() { }
    AstBinaryExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionHandle &  pBinaryExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression"; }
};

class AstBinaryConstantExpressionNeqParser : public AstParserBase<AstBinaryConstantExpressionNeqHandle> {
public:
    AstBinaryConstantExpressionNeqParser() { }
    AstBinaryConstantExpressionNeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionNeqHandle &  pBinaryConstantExpressionNeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_neq"; }
};

class AstNameOfInstanceParser : public AstParserBase<AstNameOfInstanceHandle> {
public:
    AstNameOfInstanceParser() { }
    AstNameOfInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNameOfInstanceHandle &  pNameOfInstance);
    std::string getTokenName() const
      { return "name_of_instance"; }
};

class AstConcatenationParser : public AstParserBase<AstConcatenationHandle> {
public:
    AstConcatenationParser() { }
    AstConcatenationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstConcatenationHandle &  pAstConcatenation);
    std::string getTokenName() const
      { return "concatenation"; }
};

class AstConstantBitSelectIdentifierParser : public AstParserBase<AstConstantBitSelectIdentifierHandle> {
public:
    AstConstantBitSelectIdentifierParser() { }
    AstConstantBitSelectIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstConstantBitSelectIdentifierHandle &  pConstantBitSelectIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "constant_bit_select_identifier"; }
};

class AstBinaryOperatorPercentParser : public AstParserBase<AstBinaryOperatorPercentHandle> {
public:
    AstBinaryOperatorPercentParser() { }
    AstBinaryOperatorPercentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorPercentHandle &  pBinaryOperatorPercent, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_percent"; }
};

class AstZeroOrMoreCommaModuleInstanceParser : public AstParserBase<AstZeroOrMoreCommaModuleInstanceHandle> {
public:
    AstZeroOrMoreCommaModuleInstanceParser() { }
    AstZeroOrMoreCommaModuleInstanceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaModuleInstanceHandle &  pZeroOrMoreCommaModuleInstance, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_module_instance"; }
};

class AstPortExpressionParser : public AstParserBase<AstPortExpressionHandle> {
public:
    AstPortExpressionParser() { }
    AstPortExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstPortExpressionHandle &  pPortExpression);
    std::string getTokenName() const
      { return "port_expression"; }
};

class AstGateInstantiationOutputParser : public AstParserBase<AstGateInstantiationOutputHandle> {
public:
    AstGateInstantiationOutputParser() { }
    AstGateInstantiationOutputParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstGateInstantiationOutputHandle &  pGateInstantiationOutput, unsigned int & pos);
    std::string getTokenName() const
      { return "gate_instantiation_output"; }
};

class AstEventCommaEventParser : public AstParserBase<AstEventCommaEventHandle> {
public:
    AstEventCommaEventParser() { }
    AstEventCommaEventParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstEventCommaEventHandle &  pEventCommaEvent, unsigned int & pos);
    std::string getTokenName() const
      { return "event_comma_event"; }
};

class AstBinaryConstantExpressionCaseEqParser : public AstParserBase<AstBinaryConstantExpressionCaseEqHandle> {
public:
    AstBinaryConstantExpressionCaseEqParser() { }
    AstBinaryConstantExpressionCaseEqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryConstantExpressionCaseEqHandle &  pBinaryConstantExpressionCaseEq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_constant_expression_case_eq"; }
};

class AstPortReferenceParser : public AstParserBase<AstPortReferenceHandle> {
public:
    AstPortReferenceParser() { }
    AstPortReferenceParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstPortReferenceHandle &  pPortReference);
    std::string getTokenName() const
      { return "port_reference"; }
};

class AstElseStatementOrNullParser : public AstParserBase<AstElseStatementOrNullHandle> {
public:
    AstElseStatementOrNullParser() { }
    AstElseStatementOrNullParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstElseStatementOrNullHandle &  pElseStatementOrNull, unsigned int & pos);
    std::string getTokenName() const
      { return "else_statement_or_null"; }
};

class AstBinaryExpressionShiftLeftParser : public AstParserBase<AstBinaryExpressionShiftLeftHandle> {
public:
    AstBinaryExpressionShiftLeftParser() { }
    AstBinaryExpressionShiftLeftParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionShiftLeftHandle &  pBinaryExpressionShiftLeft, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_shift_left"; }
};

class AstPrimaryParser : public AstParserBase<AstPrimaryHandle> {
public:
    AstPrimaryParser() { }
    AstPrimaryParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstPrimaryHandle &  pPrimary);
    std::string getTokenName() const
      { return "primary"; }
};

class AstBinaryExpressionCaseNeqParser : public AstParserBase<AstBinaryExpressionCaseNeqHandle> {
public:
    AstBinaryExpressionCaseNeqParser() { }
    AstBinaryExpressionCaseNeqParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryExpressionCaseNeqHandle &  pBinaryExpressionCaseNeq, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_expression_case_neq"; }
};

class AstOrderedPortConnectionParser : public AstParserBase<AstOrderedPortConnectionHandle> {
public:
    AstOrderedPortConnectionParser() { }
    AstOrderedPortConnectionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstOrderedPortConnectionHandle &  pOrderedPortConnection);
    std::string getTokenName() const
      { return "ordered_port_connection"; }
};

class AstParamAssignmentParser : public AstParserBase<AstParamAssignmentHandle> {
public:
    AstParamAssignmentParser() { }
    AstParamAssignmentParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstParamAssignmentHandle &  pParamAssignment);
    std::string getTokenName() const
      { return "param_assignment"; }
};

class AstKeywordInOutParser : public AstParserBase<AstKeywordInOutHandle> {
public:
    AstKeywordInOutParser() { }
    AstKeywordInOutParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordInOutHandle &  pKeywordInOut);
    std::string getTokenName() const
      { return "keyword_inout"; }
};

class AstConstantRangeSelectIdentifierParser : public AstParserBase<AstConstantRangeSelectIdentifierHandle> {
public:
    AstConstantRangeSelectIdentifierParser() { }
    AstConstantRangeSelectIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstConstantRangeSelectIdentifierHandle &  pConstantRangeSelectIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "constant_range_select_identifier"; }
};

class AstBitSelectParser : public AstParserBase<AstBitSelectHandle> {
public:
    AstBitSelectParser() { }
    AstBitSelectParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBitSelectHandle &  pBitSelect, unsigned int & pos);
    std::string getTokenName() const
      { return "bit_select"; }
};

class AstKetwordNegedgeParser : public AstParserBase<AstKetwordNegedgeHandle> {
public:
    AstKetwordNegedgeParser() { }
    AstKetwordNegedgeParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKetwordNegedgeHandle &  pKeywordNegedge);
    std::string getTokenName() const
      { return "keyword_negedge"; }
};

class AstInputTerminalParser : public AstParserBase<AstInputTerminalHandle> {
public:
    AstInputTerminalParser() { }
    AstInputTerminalParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstInputTerminalHandle &  pInputTerminal);
    std::string getTokenName() const
      { return "input_terminal"; }
};

class AstZeroOrOneListOfPortsParser : public AstParserBase<AstZeroOrOneListOfPortsHandle> {
public:
    AstZeroOrOneListOfPortsParser() { }
    AstZeroOrOneListOfPortsParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrOneListOfPortsHandle &  pZeroOrOneListOfPorts, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_one_list_of_ports"; }
};

class AstPortParser : public AstParserBase<AstPortHandle> {
public:
    AstPortParser() { }
    AstPortParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstPortHandle &  pPort);
    std::string getTokenName() const
      { return "port"; }
};

class AstOneOrMoreDescriptionParser : public AstParserBase<AstOneOrMoreDescriptionHandle> {
public:
    AstOneOrMoreDescriptionParser() { }
    AstOneOrMoreDescriptionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstOneOrMoreDescriptionHandle &  pOneOrMoreDescription, unsigned int & pos);
    std::string getTokenName() const
      { return "one_or_more_description"; }
};

class AstBinaryOperatorAsteriskParser : public AstParserBase<AstBinaryOperatorAsteriskHandle> {
public:
    AstBinaryOperatorAsteriskParser() { }
    AstBinaryOperatorAsteriskParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorAsteriskHandle &  pBinaryOperatorAsterisk, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_asterisk"; }
};

class AstZeroOrMoreCommaExpressionParser : public AstParserBase<AstZeroOrMoreCommaExpressionHandle> {
public:
    AstZeroOrMoreCommaExpressionParser() { }
    AstZeroOrMoreCommaExpressionParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreCommaExpressionHandle &  pZeroOrMoreCommaExpression, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_comma_expression"; }
};

class AstAtIdentifierParser : public AstParserBase<AstAtIdentifierHandle> {
public:
    AstAtIdentifierParser() { }
    AstAtIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstAtIdentifierHandle &  pAtIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "at_identifier"; }
};

class AstKeywordInputParser : public AstParserBase<AstKeywordInputHandle> {
public:
    AstKeywordInputParser() { }
    AstKeywordInputParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstKeywordInputHandle &  pKeywordInput);
    std::string getTokenName() const
      { return "keyword_input"; }
};

class AstBinaryOperatorXorNegParser : public AstParserBase<AstBinaryOperatorXorNegHandle> {
public:
    AstBinaryOperatorXorNegParser() { }
    AstBinaryOperatorXorNegParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorXorNegHandle &  pBinaryOperatorXorNeg, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_xor_neg"; }
};

class AstZeroOrMoreDotSingleIdentifierParser : public AstParserBase<AstZeroOrMoreDotSingleIdentifierHandle> {
public:
    AstZeroOrMoreDotSingleIdentifierParser() { }
    AstZeroOrMoreDotSingleIdentifierParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstZeroOrMoreDotSingleIdentifierHandle &  pZeroOrMoreDotSingleIdentifier, unsigned int & pos);
    std::string getTokenName() const
      { return "zero_or_more_dot_single_identifier"; }
};

class AstUnaryOperatorOrParser : public AstParserBase<AstUnaryOperatorOrHandle> {
public:
    AstUnaryOperatorOrParser() { }
    AstUnaryOperatorOrParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstUnaryOperatorOrHandle &  pUnaryOperatorOr, unsigned int & pos);
    std::string getTokenName() const
      { return "unary_operator_or"; }
};

class AstBinaryOperatorGtParser : public AstParserBase<AstBinaryOperatorGtHandle> {
public:
    AstBinaryOperatorGtParser() { }
    AstBinaryOperatorGtParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parsePos(AstBinaryOperatorGtHandle &  pBinaryOperatorGt, unsigned int & pos);
    std::string getTokenName() const
      { return "binary_operator_gt"; }
};

class AstNetDeclarationParser : public AstParserBase<AstNetDeclarationHandle> {
public:
    AstNetDeclarationParser() { }
    AstNetDeclarationParser(TokenStructureHandle pTokenStructure, TokenHandle pToken)
      { initFromToken(pTokenStructure, pToken); }

    bool parse(AstNetDeclarationHandle &  pNetDeclaration);
    std::string getTokenName() const
      { return "net_declaration"; }
};

#endif // ASTPARSER_H
