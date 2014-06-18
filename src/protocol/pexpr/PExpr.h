#ifndef PEXPR_H
#define PEXPR_H

#include <vector>

#include "PExprType.h"
#include "exception/Exception.h"
#include "nstl/for_each/ForEach.h"

class PExpr {
public:
    PExpr() {}
    virtual ~PExpr() {}
    std::string toString() const;
    friend std::ostream & operator << (std::ostream & os, const PExpr & rhs) { assert(0); }
};

class PExprSourceText {
    std::vector<PExprStateStatementHandle> _vecStateStatement;
public:
    PExprSourceText(PExprStateStatementHandle pStateStatement);
    static PExprSourceTextHandle makeHandle(PExprStateStatementHandle pStateStatement);
    static PExprSourceTextHandle makeHandle(std::vector<PExprStateStatementHandle>& vecStateStatement);
    const std::vector<PExprStateStatementHandle>& getStateStatementContainer() const;
    std::vector<PExprStateStatementHandle>& getStateStatementContainer();
    std::string toString() const;
private:
    void pushState(PExprStateStatementHandle pState);
};

class PExprStateStatement {
    PExprStateLabelHandle _pStateLabel;
    PExprTransitionStatementHandle _pTrans;
public:
    PExprStateStatement(PExprStateLabelHandle pStateLabel, PExprTransitionStatementHandle pTrans);
    static PExprStateStatementHandle makeHandle(PExprStateLabelHandle pStateLabel, PExprTransitionStatementHandle pTrans);
    PExprStateLabelHandle getStateLabel() const;
    PExprTransitionStatementHandle getTrans() const;
    std::string toString() const;
};

class PExprTransitionStatement {
    std::vector<PExprEdgeStatementHandle> _vecEdgeStatement;
public:
    PExprTransitionStatement(std::vector<PExprEdgeStatementHandle> vecEdgeStatement);
    static PExprTransitionStatementHandle makeHandle(std::vector<PExprEdgeStatementHandle> vecEdgeStatement);

    std::vector<PExprEdgeStatementHandle>& getEdgeContainer();
    const std::vector<PExprEdgeStatementHandle>& getEdgeContainer() const;

    unsigned int getEdgeSize() const;
    std::string toString() const;
private:
    void pushEdge(PExprEdgeStatementHandle pEdgeStatement);
};

class PExprEdgeStatement {
    PExprIfStatementWithGotoHandle _pWithGoto;
    PExprEndStatementHandle _pEndStatement;
    std::vector<PExprAllUpdateStatementHandle> _vecAllUpdateStatement;
    std::vector<PExprSpecificUpdateStatementHandle> _vecSpecificUpdateStatement;
public:
    PExprEdgeStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, PExprIfStatementWithGotoHandle pWithGoto);
    PExprEdgeStatement(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement, PExprEndStatementHandle pEndStatement);
    static PExprEdgeStatementHandle makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, PExprIfStatementWithGotoHandle pWithGoto);
    static PExprEdgeStatementHandle makeHandle(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement, PExprEndStatementHandle pEndStatement);

    PExprIfStatementWithGotoHandle getWithGoto() const;
    PExprEndStatementHandle getEndStatement() const;
    const std::vector<PExprAllUpdateStatementHandle>& getAllContainer() const;
    std::vector<PExprAllUpdateStatementHandle>& getAllContainer();
    const std::vector<PExprSpecificUpdateStatementHandle>& getSpecificContainer() const;
    std::vector<PExprSpecificUpdateStatementHandle>& getSpecificContainer();

    unsigned int getAllSize() const;
    unsigned int getSpecificSize() const;
    std::string toString() const;
private:
    void pushAll(PExprAllUpdateStatementHandle pAllUpdateStatement);
    void pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement);
};

class PExprUpdateStatement {
    std::vector<PExprAllUpdateStatementHandle> _vecAllUpdateStatement;
    std::vector<PExprSpecificUpdateStatementHandle> _vecSpecificUpdateStatement;
public:
    PExprUpdateStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);
    PExprUpdateStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement);
    PExprUpdateStatement(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);
    static PExprUpdateStatementHandle makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);
    static PExprUpdateStatementHandle makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement);
    static PExprUpdateStatementHandle makeHandle(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);

    const std::vector<PExprAllUpdateStatementHandle> getAllContainer() const;
    std::vector<PExprAllUpdateStatementHandle> getAllContainer();
    const std::vector<PExprSpecificUpdateStatementHandle> getSpecificContainer() const;
    std::vector<PExprSpecificUpdateStatementHandle> getSpecificContainer(); 
    std::string toString() const;
    std::string toString_2() const;
private:
    void pushAll(PExprAllUpdateStatementHandle pAllUpdateStatement);
    void pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement);
};

class PExprAllUpdateStatement {
    PExprReadOrWriteOrCheckStatementHandle _pRWC;
    PExprIfStatementWithoutGotoHandle _pWithoutGoto;
public:
    PExprAllUpdateStatement(PExprReadOrWriteOrCheckStatementHandle pRWC);
    PExprAllUpdateStatement(PExprIfStatementWithoutGotoHandle pWithoutGoto);
    static PExprAllUpdateStatementHandle makeHandle(PExprReadOrWriteOrCheckStatementHandle pRWC);
    static PExprAllUpdateStatementHandle makeHandle(PExprIfStatementWithoutGotoHandle pWithoutGoto);

    PExprReadOrWriteOrCheckStatementHandle getRWC() const;
    PExprIfStatementWithoutGotoHandle getWithoutGoto() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprSpecificUpdateStatement {
    PExprReadOrWriteOrCheckStatementHandle _pRWC;
    PExprIfStatementWithoutGotoHandle _pWithoutGoto;
public:
    PExprSpecificUpdateStatement(PExprReadOrWriteOrCheckStatementHandle pRWC);
    PExprSpecificUpdateStatement(PExprIfStatementWithoutGotoHandle pWithoutGoto);
    static PExprSpecificUpdateStatementHandle makeHandle(PExprReadOrWriteOrCheckStatementHandle pRWC);
    static PExprSpecificUpdateStatementHandle makeHandle(PExprIfStatementWithoutGotoHandle pWithoutGoto);

    PExprReadOrWriteOrCheckStatementHandle getRWC() const;
    PExprIfStatementWithoutGotoHandle getWithoutGoto() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprStateLabel {
    std::string _StateLabel;
public:
    PExprStateLabel(const std::string& s);
    static PExprStateLabelHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;
};

class PExprReadOrWriteOrCheckStatement {
    PExprReadStatementHandle _pRead;
    PExprWriteStatementHandle _pWrite;
    PExprCheckStatementHandle _pCheck;
public:
    PExprReadOrWriteOrCheckStatement(PExprReadStatementHandle pRead);
    PExprReadOrWriteOrCheckStatement(PExprWriteStatementHandle pWrite);
    PExprReadOrWriteOrCheckStatement(PExprCheckStatementHandle pCheck);

    static PExprReadOrWriteOrCheckStatementHandle makeHandle(PExprReadStatementHandle pRead);
    static PExprReadOrWriteOrCheckStatementHandle makeHandle(PExprWriteStatementHandle pWrite);
    static PExprReadOrWriteOrCheckStatementHandle makeHandle(PExprCheckStatementHandle pCheck);

    PExprReadStatementHandle getRead() const;
    PExprWriteStatementHandle getWrite() const;
    PExprCheckStatementHandle getCheck() const;

    std::string toString() const;
    std::string toString_2() const;
};

class PExprReadStatement {
    std::string _read;
public:
    PExprReadStatement(const std::string& s);
    static PExprReadStatementHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprWriteStatement {
    std::string _write;
public:
    PExprWriteStatement(const std::string& s);
    static PExprWriteStatementHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprCheckStatement {
    PExprBoolExpressionHandle _pBool;
public:
    PExprCheckStatement(PExprBoolExpressionHandle pBool);
    static PExprCheckStatementHandle makeHandle(PExprBoolExpressionHandle pBool);
    PExprBoolExpressionHandle getBool() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprEndStatement {
    PExprGotoStatementHandle _pGotoStatement;
    PExprAssertStatementHandle _pAssertStatement;
public:
    PExprEndStatement(PExprGotoStatementHandle pGotoStatement);
    PExprEndStatement(PExprAssertStatementHandle pAssertStatement);
    static PExprEndStatementHandle makeHandle(PExprGotoStatementHandle pGotoStatement); 
    static PExprEndStatementHandle makeHandle(PExprAssertStatementHandle pAssertStatement);

    PExprGotoStatementHandle getGotoStatement() const;
    PExprAssertStatementHandle getAssertStatement() const;

    std::string toString() const;
};

class PExprIfStatementWithGoto {
    PExprIfStatementPrefixHandle _pIfStatementPrefix;
    PExprEndStatementHandle _pEndStatement;
    std::vector<PExprSpecificUpdateStatementHandle> _vecSpecificUpdateStatement;
public:
    PExprIfStatementWithGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement);
    PExprIfStatementWithGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);
    static PExprIfStatementWithGotoHandle makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement);
    static PExprIfStatementWithGotoHandle makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement);

    PExprIfStatementPrefixHandle getIfStatementPrefix() const;
    PExprEndStatementHandle getEndStatement() const;
    const std::vector<PExprSpecificUpdateStatementHandle>& getSpecificContainer() const;
    std::vector<PExprSpecificUpdateStatementHandle>& getSpecificContainer();

    unsigned int getSpecificSize() const;
    std::string toString() const;
private:
    void pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement);
};

class PExprIfStatementWithoutGoto {
    PExprIfStatementPrefixHandle _pIfStatementPrefix;
    std::vector<PExprReadOrWriteOrCheckStatementHandle> _vecRWC;
    std::vector<PExprIfStatementWithoutGotoHandle> _vecIfStatementWithoutGoto;
public:
    PExprIfStatementWithoutGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC, std::vector<PExprIfStatementWithoutGotoHandle> vecIfStatementWithoutGoto);
    static PExprIfStatementWithoutGotoHandle makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC, std::vector<PExprIfStatementWithoutGotoHandle> vecIfStatementWithoutGoto);

    PExprIfStatementPrefixHandle getIfStatementPrefix() const;
    const std::vector<PExprReadOrWriteOrCheckStatementHandle>& getRWCContainer() const;
    std::vector<PExprReadOrWriteOrCheckStatementHandle>& getRWCContainer();
    const std::vector<PExprIfStatementWithoutGotoHandle>& getIfStatementWithoutGotoContainer() const;
    std::vector<PExprIfStatementWithoutGotoHandle>& getIfStatementWithoutGotoContainer();

    unsigned int getRWCSize() const;
    unsigned int getIfSize() const;
    std::string toString() const;
    std::string toString_2() const;
private:
    void pushRWC(PExprReadOrWriteOrCheckStatementHandle pRWC);
    void pushIfStatementWithoutGoto(PExprIfStatementWithoutGotoHandle pIfStatementWithoutGoto);

};

class PExprIfStatementPrefix {
    PExprBoolExpressionHandle _pBoolExpression;
public:
    PExprIfStatementPrefix(PExprBoolExpressionHandle pBoolExpression);
    static PExprIfStatementPrefixHandle makeHandle(PExprBoolExpressionHandle pBoolExpression);
    PExprBoolExpressionHandle getBoolExpressionHandle() const;
    std::string toString() const;
    std::string toString_2() const;
};

class PExprGotoStatement {
    std::string _goto;
public:
    PExprGotoStatement(const std::string& s);
    static PExprGotoStatementHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;
};

class PExprBoolExpression {
public:
    enum OP_TYPE {
        IDENTIFIER,
        CONSTANT,
        LOGICAL_AND,
        LOGICAL_OR,
        LOGICAL_XOR,
        LOGICAL_EQUAL,
        LOGICAL_NOT
    };
private:
    std::string _identifier;
    PExprConstantHandle _pConstant;
    PExprBoolExpressionHandle _pFst;
    PExprBoolExpressionHandle _pSnd;
    OP_TYPE _Op;
public:
    PExprBoolExpression(const std::string& s);
    PExprBoolExpression(const std::string& s1, PExprConstantHandle pConstant);
    PExprBoolExpression(PExprBoolExpressionHandle pFst, OP_TYPE Op);
    PExprBoolExpression(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd, OP_TYPE Op);

    static PExprBoolExpressionHandle makeIdentifierHandle(const std::string& s);
    static PExprBoolExpressionHandle makeConstantHandle(const std::string& s1, PExprConstantHandle pConstant);
    static PExprBoolExpressionHandle makeBinaryAndHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd);
    static PExprBoolExpressionHandle makeBinaryOrHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd);
    static PExprBoolExpressionHandle makeBinaryXorHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd);
    static PExprBoolExpressionHandle makeBinaryEqualHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd);
    static PExprBoolExpressionHandle makeUnaryNotHandle(PExprBoolExpressionHandle pFst);


    std::string getName() const;
    PExprConstantHandle getConstant() const;
    PExprBoolExpressionHandle getFst() const;
    PExprBoolExpressionHandle getSnd() const;
    OP_TYPE getOp() const;

    std::string toString() const;
    std::string toString_2() const;
private:
    // PEXPR_OP_TYPE
    static PExprBoolExpressionHandle makeBinaryHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd, OP_TYPE Op);
};

class PExprConstant {
    std::string _const;
public:
    PExprConstant(const std::string& s);
    static PExprConstantHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;

};

class PExprAssertStatement {
    std::string _assert;
public:
    PExprAssertStatement(const std::string& s);
    static PExprAssertStatementHandle makeHandle(const std::string& s);
    std::string getName() const;
    std::string toString() const;
};
#endif // PEXPR_H
