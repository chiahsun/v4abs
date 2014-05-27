#include "PExpr.h"

std::string PExpr::toString() const
{
    std::stringstream ss;
    ss << "not ok";
    return ss.str();
}

PExprSourceText::PExprSourceText(PExprStateStatementHandle pStateStatement)
{
    _vecStateStatement.push_back(pStateStatement);
}

PExprSourceTextHandle PExprSourceText::makeHandle(PExprStateStatementHandle pStateStatement)
{
    return PExprSourceTextHandle(PExprSourceText(pStateStatement));
}

PExprSourceTextHandle PExprSourceText::makeHandle(std::vector<PExprStateStatementHandle>& vecStateStatement)
{
    PExprSourceTextHandle pSource = PExprSourceTextHandle(PExprSourceText(vecStateStatement[0]));
    for(unsigned int i = 1 ; i < vecStateStatement.size() ; ++i)
        pSource->pushState(vecStateStatement[i]);
    return pSource;
}

void PExprSourceText::pushState(PExprStateStatementHandle pState)
{
    _vecStateStatement.push_back(pState);
}

const std::vector<PExprStateStatementHandle>& PExprSourceText::getStateStatementContainer() const
{
    return _vecStateStatement;
}

std::vector<PExprStateStatementHandle>& PExprSourceText::getStateStatementContainer()
{
    return _vecStateStatement;
}
std::string PExprSourceText::toString() const
{
    std::stringstream ss;
    ss << "(source_text";
    FOR_EACH(pState, getStateStatementContainer()){
        ss << " ";
        ss << pState->toString();
    }
    ss << ")";
    return ss.str();
}

PExprStateStatement::PExprStateStatement(PExprStateLabelHandle pStateLabel, PExprTransitionStatementHandle pTrans)
    : _pStateLabel(pStateLabel), _pTrans(pTrans)
{}

PExprStateStatementHandle PExprStateStatement::makeHandle(PExprStateLabelHandle pStateLabel, PExprTransitionStatementHandle pTrans)
{
    return PExprStateStatementHandle(PExprStateStatement(pStateLabel, pTrans));
}

PExprStateLabelHandle PExprStateStatement::getStateLabel() const
{
    return _pStateLabel;
}

PExprTransitionStatementHandle PExprStateStatement::getTrans() const
{
    return _pTrans;
}

std::string PExprStateStatement::toString() const
{
    std::stringstream ss;
    ss << "(state_statement " << getStateLabel()->toString() << " " << getTrans()->toString() << ")";
    return ss.str();
}

PExprTransitionStatement::PExprTransitionStatement(std::vector<PExprEdgeStatementHandle> vecEdgeStatement)
{
    for(unsigned int i = 0 ; i < vecEdgeStatement.size() ; ++i)
        pushEdge(vecEdgeStatement[i]);
}

PExprTransitionStatementHandle PExprTransitionStatement::makeHandle(std::vector<PExprEdgeStatementHandle> vecEdgeStatement)
{
    return PExprTransitionStatementHandle(PExprTransitionStatement(vecEdgeStatement));
}

const std::vector<PExprEdgeStatementHandle>& PExprTransitionStatement::getEdgeContainer() const
{
    return _vecEdgeStatement;
}

std::vector<PExprEdgeStatementHandle>& PExprTransitionStatement::getEdgeContainer()
{
    return _vecEdgeStatement;
}

unsigned int PExprTransitionStatement::getEdgeSize() const
{
    return getEdgeContainer().size();
}

std::string PExprTransitionStatement::toString() const
{
    std::stringstream ss;
    ss << "(transition_statement";
    FOR_EACH(pEdgeStatement, getEdgeContainer()){
        ss << " " << pEdgeStatement->toString();
    }
    ss << ")";
    return ss.str();
}

void PExprTransitionStatement::pushEdge(PExprEdgeStatementHandle pEdgeStatement)
{
    _vecEdgeStatement.push_back(pEdgeStatement);
}

PExprEdgeStatement::PExprEdgeStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, PExprIfStatementWithGotoHandle pWithGoto)
    : _pWithGoto(pWithGoto)
{
    for(unsigned int i = 0 ; i < vecAllUpdateStatement.size() ; ++i)
        pushAll(vecAllUpdateStatement[i]);
}

PExprEdgeStatement::PExprEdgeStatement(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement, PExprEndStatementHandle pEndStatement)
    : _pEndStatement(pEndStatement)
{
    for(unsigned int i = 0 ; i < vecSpecificUpdateStatement.size() ; ++i)
        pushSpecific(vecSpecificUpdateStatement[i]);
}


PExprEdgeStatementHandle PExprEdgeStatement::makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, PExprIfStatementWithGotoHandle pWithGoto)
{
    return PExprEdgeStatementHandle(PExprEdgeStatement(vecAllUpdateStatement, pWithGoto));
}

PExprEdgeStatementHandle PExprEdgeStatement::makeHandle(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement, PExprEndStatementHandle pEndStatement)
{
    return PExprEdgeStatementHandle(PExprEdgeStatement(vecSpecificUpdateStatement, pEndStatement));
}

PExprIfStatementWithGotoHandle PExprEdgeStatement::getWithGoto() const
{
    return _pWithGoto;
}

PExprEndStatementHandle PExprEdgeStatement::getEndStatement() const
{
    return _pEndStatement;
}

const std::vector<PExprAllUpdateStatementHandle>& PExprEdgeStatement::getAllContainer() const
{
    return _vecAllUpdateStatement;
}

std::vector<PExprAllUpdateStatementHandle>& PExprEdgeStatement::getAllContainer()
{
    return _vecAllUpdateStatement;
}

const std::vector<PExprSpecificUpdateStatementHandle>& PExprEdgeStatement::getSpecificContainer() const
{
    return _vecSpecificUpdateStatement;
}

std::vector<PExprSpecificUpdateStatementHandle>& PExprEdgeStatement::getSpecificContainer()
{
    return _vecSpecificUpdateStatement;
}

unsigned int PExprEdgeStatement::getAllSize() const
{
    return getAllContainer().size();
}

unsigned int PExprEdgeStatement::getSpecificSize() const
{
    return getSpecificContainer().size();
}

std::string PExprEdgeStatement::toString() const
{
    std::stringstream ss;
    ss << "(edge_statement ";
    if(getWithGoto().valid()){
        FOR_EACH(pAllUpdateStatement, getAllContainer()){
            ss << pAllUpdateStatement->toString() << " ";
        }
        ss << getWithGoto()->toString();
    }
    else if(getEndStatement().valid()){
        FOR_EACH(pSpecific, getSpecificContainer()){
            ss << pSpecific->toString() << " ";
        }
        ss << getEndStatement()->toString();
    }
    else
        assert(0);
    ss << ")";
    return ss.str();
}

void PExprEdgeStatement::pushAll(PExprAllUpdateStatementHandle pAllUpdateStatement)
{
    _vecAllUpdateStatement.push_back(pAllUpdateStatement);
}

void PExprEdgeStatement::pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement)
{
    _vecSpecificUpdateStatement.push_back(pSpecificUpdateStatement);
}

PExprUpdateStatement::PExprUpdateStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
{
    for(unsigned int i = 0 ; i < vecAllUpdateStatement.size() ; ++i)
        pushAll(vecAllUpdateStatement[i]);
    for(unsigned int i = 0 ; i < vecSpecificUpdateStatement.size() ; ++i)
        pushSpecific(vecSpecificUpdateStatement[i]);
}

PExprUpdateStatement::PExprUpdateStatement(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement)
{
    for(unsigned int i = 0 ; i < vecAllUpdateStatement.size() ; ++i)
        pushAll(vecAllUpdateStatement[i]);
}

PExprUpdateStatement::PExprUpdateStatement(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
{
    for(unsigned int i = 0 ; i < vecSpecificUpdateStatement.size() ; ++i)
        pushSpecific(vecSpecificUpdateStatement[i]);
}

PExprUpdateStatementHandle PExprUpdateStatement::makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
{
    return PExprUpdateStatementHandle(PExprUpdateStatement(vecAllUpdateStatement, vecSpecificUpdateStatement));
}

PExprUpdateStatementHandle PExprUpdateStatement::makeHandle(std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement)
{
    return PExprUpdateStatementHandle(PExprUpdateStatement(vecAllUpdateStatement));
}

PExprUpdateStatementHandle PExprUpdateStatement::makeHandle(std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
{
    return PExprUpdateStatementHandle(PExprUpdateStatement(vecSpecificUpdateStatement));
}

const std::vector<PExprAllUpdateStatementHandle> PExprUpdateStatement::getAllContainer() const
{
    return _vecAllUpdateStatement;
}

std::vector<PExprAllUpdateStatementHandle> PExprUpdateStatement::getAllContainer()
{
    return _vecAllUpdateStatement;
}

const std::vector<PExprSpecificUpdateStatementHandle> PExprUpdateStatement::getSpecificContainer() const
{
    return _vecSpecificUpdateStatement;
}

std::vector<PExprSpecificUpdateStatementHandle> PExprUpdateStatement::getSpecificContainer()
{
    return _vecSpecificUpdateStatement;
}

std::string PExprUpdateStatement::toString() const
{
    std::stringstream ss;
    for(unsigned int i = 0 ; i < _vecAllUpdateStatement.size() ; ++i)
        ss << _vecAllUpdateStatement[i]->toString();
    //FOR_EACH(p, getAllContainer())
    //    ss << p->toString();
    for(unsigned int i = 0 ; i < _vecSpecificUpdateStatement.size() ; ++i)
        ss << _vecSpecificUpdateStatement[i]->toString();
    //FOR_EACH(p, getSpecificContainer())
    //    ss << p->toString();
    return ss.str();
}

std::string PExprUpdateStatement::toString_2() const
{
    std::stringstream ss;
    for(unsigned int i = 0 ; i < _vecAllUpdateStatement.size() ; ++i)
        ss << _vecAllUpdateStatement[i]->toString_2();
    for(unsigned int i = 0 ; i < _vecSpecificUpdateStatement.size() ; ++i)
        ss << _vecSpecificUpdateStatement[i]->toString_2();
    return ss.str();
}

void PExprUpdateStatement::pushAll(PExprAllUpdateStatementHandle pAllUpdateStatement)
{
    _vecAllUpdateStatement.push_back(pAllUpdateStatement);
}

void PExprUpdateStatement::pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement)
{
    _vecSpecificUpdateStatement.push_back(pSpecificUpdateStatement);
}

PExprAllUpdateStatement::PExprAllUpdateStatement(PExprReadOrWriteOrCheckStatementHandle pRWC)
    : _pRWC(pRWC)
{}

PExprAllUpdateStatement::PExprAllUpdateStatement(PExprIfStatementWithoutGotoHandle pWithoutGoto)
    : _pWithoutGoto(pWithoutGoto)
{}

PExprAllUpdateStatementHandle PExprAllUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatementHandle pRWC)
{
    return PExprAllUpdateStatementHandle(PExprAllUpdateStatement(pRWC));
}

PExprAllUpdateStatementHandle PExprAllUpdateStatement::makeHandle(PExprIfStatementWithoutGotoHandle pWithoutGoto)
{
    return PExprAllUpdateStatementHandle(PExprAllUpdateStatement(pWithoutGoto));
}

PExprReadOrWriteOrCheckStatementHandle PExprAllUpdateStatement::getRWC() const
{
    return _pRWC;
}

PExprIfStatementWithoutGotoHandle PExprAllUpdateStatement::getWithoutGoto() const
{
    return _pWithoutGoto;
}

std::string PExprAllUpdateStatement::toString() const
{
    std::stringstream ss;
    ss << "(all_update_statement ";
    if(getRWC().valid())
        ss << getRWC()->toString();
    else if(getWithoutGoto().valid())
        ss << getWithoutGoto()->toString();
    ss << ")";
    return ss.str();
}

std::string PExprAllUpdateStatement::toString_2() const
{
    std::stringstream ss;
    if(getRWC().valid())
        ss << getRWC()->toString_2();
    else if(getWithoutGoto().valid())
        ss << getWithoutGoto()->toString_2();
    return ss.str();
}

PExprSpecificUpdateStatement::PExprSpecificUpdateStatement(PExprReadOrWriteOrCheckStatementHandle pRWC)
    : _pRWC(pRWC)
{}

PExprSpecificUpdateStatement::PExprSpecificUpdateStatement(PExprIfStatementWithoutGotoHandle pWithoutGoto)
    : _pWithoutGoto(pWithoutGoto)
{}

PExprSpecificUpdateStatementHandle PExprSpecificUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatementHandle pRWC)
{
    return PExprSpecificUpdateStatementHandle(PExprSpecificUpdateStatement(pRWC));
}

PExprSpecificUpdateStatementHandle PExprSpecificUpdateStatement::makeHandle(PExprIfStatementWithoutGotoHandle pWithoutGoto)
{
    return PExprSpecificUpdateStatementHandle(PExprSpecificUpdateStatement(pWithoutGoto));
}

PExprReadOrWriteOrCheckStatementHandle PExprSpecificUpdateStatement::getRWC() const
{
    return _pRWC;
}

PExprIfStatementWithoutGotoHandle PExprSpecificUpdateStatement::getWithoutGoto() const
{
    return _pWithoutGoto;
}

std::string PExprSpecificUpdateStatement::toString() const
{
    std::stringstream ss;
    ss << "(specific_update_statement ";
    if(getRWC().valid())
        ss << getRWC()->toString();
    else if(getWithoutGoto().valid())
        ss << getWithoutGoto()->toString();
    ss << ")";
    return ss.str();
}

std::string PExprSpecificUpdateStatement::toString_2() const
{
    std::stringstream ss;
    if(getRWC().valid())
        ss << getRWC()->toString_2();
    else if(getWithoutGoto().valid())
        ss << getWithoutGoto()->toString_2();
    return ss.str();
}

PExprStateLabel::PExprStateLabel(const std::string& s)
    : _StateLabel(s)
{}

PExprStateLabelHandle PExprStateLabel::makeHandle(const std::string& s)
{
    return PExprStateLabelHandle(PExprStateLabel(s));
}

std::string PExprStateLabel::getName() const
{
    return _StateLabel;
}

std::string PExprStateLabel::toString() const
{
    std::stringstream ss;
    ss << "(state_label " << getName() << ")";
    return ss.str();
}

PExprReadOrWriteOrCheckStatement::PExprReadOrWriteOrCheckStatement(PExprReadStatementHandle pRead)
    : _pRead(pRead)
{}

PExprReadOrWriteOrCheckStatement::PExprReadOrWriteOrCheckStatement(PExprWriteStatementHandle pWrite)
    : _pWrite(pWrite)
{}

PExprReadOrWriteOrCheckStatement::PExprReadOrWriteOrCheckStatement(PExprCheckStatementHandle pCheck)
    : _pCheck(pCheck)
{}

PExprReadOrWriteOrCheckStatementHandle PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatementHandle pRead)
{
    return PExprReadOrWriteOrCheckStatementHandle(PExprReadOrWriteOrCheckStatement(pRead));
}

PExprReadOrWriteOrCheckStatementHandle PExprReadOrWriteOrCheckStatement::makeHandle(PExprWriteStatementHandle pWrite)
{
    return PExprReadOrWriteOrCheckStatementHandle(PExprReadOrWriteOrCheckStatement(pWrite));
}

PExprReadOrWriteOrCheckStatementHandle PExprReadOrWriteOrCheckStatement::makeHandle(PExprCheckStatementHandle pCheck)
{
    return PExprReadOrWriteOrCheckStatementHandle(PExprReadOrWriteOrCheckStatement(pCheck));
}

PExprReadStatementHandle PExprReadOrWriteOrCheckStatement::getRead() const
{
    return _pRead;
}

PExprWriteStatementHandle PExprReadOrWriteOrCheckStatement::getWrite() const
{
    return _pWrite;
}

PExprCheckStatementHandle PExprReadOrWriteOrCheckStatement::getCheck() const
{
    return _pCheck;
}

std::string PExprReadOrWriteOrCheckStatement::toString() const
{
    std::stringstream ss;
    ss << "(read_or_write_or_check_statement ";
    if(getRead().valid())
        ss << getRead()->toString();
    else if(getWrite().valid())
        ss << getWrite()->toString();
    else if(getCheck().valid())
        ss << getCheck()->toString();
    else
        throw NoSuchBranchException(); 
    ss << ")";
    return ss.str();
}

std::string PExprReadOrWriteOrCheckStatement::toString_2() const
{
    std::stringstream ss;
    if(getRead().valid())
        ss << getRead()->toString_2();
    else if(getWrite().valid())
        ss << getWrite()->toString_2();
    else if(getCheck().valid())
        ss << getCheck()->toString_2();
    else
        throw NoSuchBranchException(); 
    return ss.str();
}

PExprReadStatement::PExprReadStatement(const std::string& s)
    : _read(s)
{}

PExprReadStatementHandle PExprReadStatement::makeHandle(const std::string& s)
{
    return PExprReadStatementHandle(PExprReadStatement(s));
}

std::string PExprReadStatement::getName() const
{
    return _read;
}

std::string PExprReadStatement::toString() const
{
    std::stringstream ss;
    ss << "(read_statement " << _read << ")";
    return ss.str();
}

std::string PExprReadStatement::toString_2() const
{
    std::stringstream ss;
    ss << "(read (" << _read << ") )";
    return ss.str();
}

PExprWriteStatement::PExprWriteStatement(const std::string& s)
    : _write(s)
{}

PExprWriteStatementHandle PExprWriteStatement::makeHandle(const std::string& s)
{
    return PExprWriteStatementHandle(PExprWriteStatement(s));
}

std::string PExprWriteStatement::getName() const
{
    return _write;
}

std::string PExprWriteStatement::toString() const
{
    std::stringstream ss;
    ss << "(write_statement " << _write << ")";
    return ss.str();
}

std::string PExprWriteStatement::toString_2() const
{
    std::stringstream ss;
    ss << "(write (" << _write << ") )";
    return ss.str();
}

PExprCheckStatement::PExprCheckStatement(PExprBoolExpressionHandle pBool)
    : _pBool(pBool)
{}

PExprCheckStatementHandle PExprCheckStatement::makeHandle(PExprBoolExpressionHandle pBool)
{
    return PExprCheckStatementHandle(PExprCheckStatement(pBool));
}

PExprBoolExpressionHandle PExprCheckStatement::getBool() const
{
    return _pBool;
}

std::string PExprCheckStatement::toString() const
{
    std::stringstream ss;
    ss << "(check_statement " << getBool()->toString() << ")";
    return ss.str();
}

std::string PExprCheckStatement::toString_2() const
{
    std::stringstream ss;
    ss << "(check (" << getBool()->toString_2() << ") )";
    return ss.str();
}

PExprEndStatement::PExprEndStatement(PExprGotoStatementHandle pGotoStatement)
    : _pGotoStatement(pGotoStatement)
{}

PExprEndStatement::PExprEndStatement(PExprAssertStatementHandle pAssertStatement)
    : _pAssertStatement(pAssertStatement)
{}

PExprEndStatementHandle PExprEndStatement::makeHandle(PExprGotoStatementHandle pGotoStatement)
{
    return PExprEndStatementHandle(PExprEndStatement(pGotoStatement));
}

PExprEndStatementHandle PExprEndStatement::makeHandle(PExprAssertStatementHandle pAssertStatement)
{
    return PExprEndStatementHandle(PExprEndStatement(pAssertStatement));
}

PExprGotoStatementHandle PExprEndStatement::getGotoStatement() const
{
    return _pGotoStatement;
}

PExprAssertStatementHandle PExprEndStatement::getAssertStatement() const
{
    return _pAssertStatement;
}

std::string PExprEndStatement::toString() const
{
    std::stringstream ss;
    ss << "(end_statement ";
    if(getGotoStatement().valid())
        ss << getGotoStatement()->toString();
    else if(getAssertStatement().valid())
        ss << getAssertStatement()->toString();
    else
        assert(0);
    ss << ")" ;
    return ss.str();
}

PExprIfStatementWithGoto::PExprIfStatementWithGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement)
    : _pIfStatementPrefix(pIfStatementPrefix), _pEndStatement(pEndStatement)
{}

PExprIfStatementWithGoto::PExprIfStatementWithGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
    : _pIfStatementPrefix(pIfStatementPrefix), _pEndStatement(pEndStatement)
{
    for(unsigned int i = 0 ; i < vecSpecificUpdateStatement.size() ; ++i)
        pushSpecific(vecSpecificUpdateStatement[i]);
}

PExprIfStatementWithGotoHandle PExprIfStatementWithGoto::makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement)
{
    return PExprIfStatementWithGotoHandle(PExprIfStatementWithGoto(pIfStatementPrefix, pEndStatement));
}

PExprIfStatementWithGotoHandle PExprIfStatementWithGoto::makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, PExprEndStatementHandle pEndStatement, std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement)
{
    return PExprIfStatementWithGotoHandle(PExprIfStatementWithGoto(pIfStatementPrefix, pEndStatement, vecSpecificUpdateStatement));
}

PExprIfStatementPrefixHandle PExprIfStatementWithGoto::getIfStatementPrefix() const
{
    return _pIfStatementPrefix;
}

PExprEndStatementHandle PExprIfStatementWithGoto::getEndStatement() const
{
    return _pEndStatement;
}

const std::vector<PExprSpecificUpdateStatementHandle>& PExprIfStatementWithGoto::getSpecificContainer() const
{
    return _vecSpecificUpdateStatement;
}

std::vector<PExprSpecificUpdateStatementHandle>& PExprIfStatementWithGoto::getSpecificContainer()
{
    return _vecSpecificUpdateStatement;
}

unsigned int PExprIfStatementWithGoto::getSpecificSize() const
{
    return getSpecificContainer().size();
}

std::string PExprIfStatementWithGoto::toString() const
{
    std::stringstream ss;
    ss << "(if_statement_with_goto " << getIfStatementPrefix()->toString();
    FOR_EACH(pSpecific, getSpecificContainer()){
        ss << " " << pSpecific->toString();
    }
    ss << " " << getEndStatement()->toString() << ")";
    return ss.str();
}

void PExprIfStatementWithGoto::pushSpecific(PExprSpecificUpdateStatementHandle pSpecificUpdateStatement)
{
    _vecSpecificUpdateStatement.push_back(pSpecificUpdateStatement);
}

PExprIfStatementWithoutGoto::PExprIfStatementWithoutGoto(PExprIfStatementPrefixHandle pIfStatementPrefix, std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC, std::vector<PExprIfStatementWithoutGotoHandle> vecIfStatementWithoutGoto)
    : _pIfStatementPrefix(pIfStatementPrefix)
{
    for(unsigned int i = 0 ; i < vecRWC.size() ; ++i)
        pushRWC(vecRWC[i]);
    for(unsigned int i = 0 ; i < vecIfStatementWithoutGoto.size() ; ++i)
        pushIfStatementWithoutGoto(vecIfStatementWithoutGoto[i]);
}

PExprIfStatementWithoutGotoHandle PExprIfStatementWithoutGoto::makeHandle(PExprIfStatementPrefixHandle pIfStatementPrefix, std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC, std::vector<PExprIfStatementWithoutGotoHandle> vecIfStatementWithoutGoto)
{
    return PExprIfStatementWithoutGotoHandle(PExprIfStatementWithoutGoto(pIfStatementPrefix, vecRWC, vecIfStatementWithoutGoto));
}

PExprIfStatementPrefixHandle PExprIfStatementWithoutGoto::getIfStatementPrefix() const
{
    return _pIfStatementPrefix;
}

const std::vector<PExprReadOrWriteOrCheckStatementHandle>& PExprIfStatementWithoutGoto::getRWCContainer() const
{
    return _vecRWC;
}

std::vector<PExprReadOrWriteOrCheckStatementHandle>& PExprIfStatementWithoutGoto::getRWCContainer()
{
    return _vecRWC;
}

const std::vector<PExprIfStatementWithoutGotoHandle>& PExprIfStatementWithoutGoto::getIfStatementWithoutGotoContainer() const
{
    return _vecIfStatementWithoutGoto;
}

std::vector<PExprIfStatementWithoutGotoHandle>& PExprIfStatementWithoutGoto::getIfStatementWithoutGotoContainer()
{
    return _vecIfStatementWithoutGoto;
}

unsigned int PExprIfStatementWithoutGoto::getRWCSize() const
{
    return getRWCContainer().size();
}

unsigned int PExprIfStatementWithoutGoto::getIfSize() const
{
    return getIfStatementWithoutGotoContainer().size();
}

std::string PExprIfStatementWithoutGoto::toString() const
{
    std::stringstream ss;
    ss << "(if_statement_without_goto " << getIfStatementPrefix()->toString();
    FOR_EACH(pRWC, getRWCContainer()){
        ss << " " << pRWC->toString();
    }
    FOR_EACH(pIf, getIfStatementWithoutGotoContainer()){
        ss << " " << pIf->toString();
    }
    ss << ")";
    return ss.str();
}

std::string PExprIfStatementWithoutGoto::toString_2() const
{
    std::stringstream ss;
    ss << "(" << getIfStatementPrefix()->toString_2();
    FOR_EACH(pRWC, getRWCContainer()){
        ss << " " << pRWC->toString_2();
    }
    FOR_EACH(pIf, getIfStatementWithoutGotoContainer()){
        ss << " " << pIf->toString_2();
    }
    ss << ")";
    return ss.str();
}

void PExprIfStatementWithoutGoto::pushRWC(PExprReadOrWriteOrCheckStatementHandle pRWC)
{
    _vecRWC.push_back(pRWC);
}

void PExprIfStatementWithoutGoto::pushIfStatementWithoutGoto(PExprIfStatementWithoutGotoHandle pIfStatementWithoutGoto)
{
    _vecIfStatementWithoutGoto.push_back(pIfStatementWithoutGoto);
}

PExprIfStatementPrefix::PExprIfStatementPrefix(PExprBoolExpressionHandle pBoolExpression)
    : _pBoolExpression(pBoolExpression)
{}

PExprIfStatementPrefixHandle PExprIfStatementPrefix::makeHandle(PExprBoolExpressionHandle pBoolExpression)
{
    return PExprIfStatementPrefixHandle(PExprIfStatementPrefix(pBoolExpression));
}

PExprBoolExpressionHandle PExprIfStatementPrefix::getBoolExpressionHandle() const
{
    return _pBoolExpression;
}

std::string PExprIfStatementPrefix::toString() const
{
    std::stringstream ss;
    ss << "(if_statement_prefix " << getBoolExpressionHandle()->toString() << ")";
    return ss.str();
}

std::string PExprIfStatementPrefix::toString_2() const
{
    std::stringstream ss;
    ss << "if (" << getBoolExpressionHandle()->toString_2() << ")";
    return ss.str();
}

PExprGotoStatement::PExprGotoStatement(const std::string& s)
    : _goto(s)
{}

PExprGotoStatementHandle PExprGotoStatement::makeHandle(const std::string& s)
{
    return PExprGotoStatementHandle(PExprGotoStatement(s));
}

std::string PExprGotoStatement::getName() const
{
    return _goto;
}

std::string PExprGotoStatement::toString() const
{
    std::stringstream ss;
    ss << "(goto_statement " << _goto << ")";
    return ss.str();
}

PExprBoolExpression::PExprBoolExpression(const std::string& s)
    : _identifier(s)
{}

PExprBoolExpression::PExprBoolExpression(const std::string& s1, PExprConstantHandle pConstant)
    : _identifier(s1), _pConstant(pConstant)
{}

PExprBoolExpression::PExprBoolExpression(PExprBoolExpressionHandle pFst, OP_TYPE Op)
    : _pFst(pFst), _Op(Op)
{}

PExprBoolExpression::PExprBoolExpression(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd, OP_TYPE Op)
    : _pFst(pFst), _pSnd(pSnd), _Op(Op)
{}

std::string PExprBoolExpression::getName() const
{
    return _identifier;
}

PExprConstantHandle PExprBoolExpression::getConstant() const
{
    return _pConstant;
}

PExprBoolExpressionHandle PExprBoolExpression::getFst() const
{
    return _pFst;
}

PExprBoolExpressionHandle PExprBoolExpression::getSnd() const
{
    return _pSnd;
}

PExprBoolExpression::OP_TYPE PExprBoolExpression::getOp() const
{
    return _Op;
}

std::string PExprBoolExpression::toString() const
{
    std::stringstream ss;
    if( getConstant().valid() ){
        ss << "(bool_expression " << _identifier << " == " << getConstant()->toString() << ")";
    }
    else if( getFst().valid() && getSnd().valid() ){
        std::string Operator;
        if( getOp() == LOGICAL_AND )
            Operator = " && ";
        else if( getOp() == LOGICAL_OR )
            Operator = " || ";
        else if( getOp() == LOGICAL_XOR )
            Operator = " ^ ";

        ss << "(bool_expression " << getFst()->toString() << Operator << getSnd()->toString() << ")";
    }
    else if( getFst().valid() && !getSnd().valid() ){
        ss << "(bool_expression ! " << getFst()->toString() << ")";
    }
    else{
        ss << "(bool_expression " << _identifier << ")";
    }
    return ss.str();
}

std::string PExprBoolExpression::toString_2() const
{
    std::stringstream ss;
    if( getConstant().valid() ){
        ss << "(" << _identifier << " == " << getConstant()->toString() << ")";
    }
    else if( getFst().valid() && getSnd().valid() ){
        std::string Operator;
        if( getOp() == LOGICAL_AND )
            Operator = " && ";
        else if( getOp() == LOGICAL_OR )
            Operator = " || ";
        else if( getOp() == LOGICAL_XOR )
            Operator = " ^ ";

        ss << "(" << getFst()->toString_2() << Operator << getSnd()->toString_2() << ")";
    }
    else if( getFst().valid() && !getSnd().valid() ){
        ss << "(! " << getFst()->toString_2() << ")";
    }
    else{
        ss << "(" << _identifier << ")";
    }
    return ss.str();
}

PExprBoolExpressionHandle PExprBoolExpression::makeIdentifierHandle(const std::string& s)
{
    return PExprBoolExpressionHandle(PExprBoolExpression(s));
}

PExprBoolExpressionHandle PExprBoolExpression::makeConstantHandle(const std::string& s1, PExprConstantHandle pConstant)
{
    return PExprBoolExpressionHandle(PExprBoolExpression(s1,pConstant));
}

PExprBoolExpressionHandle PExprBoolExpression::makeBinaryAndHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd) {
    return makeBinaryHandle(pFst, pSnd, LOGICAL_AND);
}

PExprBoolExpressionHandle PExprBoolExpression::makeBinaryOrHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd) {
    return makeBinaryHandle(pFst, pSnd, LOGICAL_OR);
}

PExprBoolExpressionHandle PExprBoolExpression::makeBinaryXorHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd) {
    return makeBinaryHandle(pFst, pSnd, LOGICAL_XOR);
}

PExprBoolExpressionHandle PExprBoolExpression::makeBinaryEqualHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd) {
    return makeBinaryHandle(pFst, pSnd, LOGICAL_EQUAL);
}

PExprBoolExpressionHandle PExprBoolExpression::makeUnaryNotHandle(PExprBoolExpressionHandle pFst) {
    return PExprBoolExpressionHandle(PExprBoolExpression(pFst, LOGICAL_NOT));
}

PExprBoolExpressionHandle PExprBoolExpression::makeBinaryHandle(PExprBoolExpressionHandle pFst, PExprBoolExpressionHandle pSnd, OP_TYPE Op) {
    return PExprBoolExpressionHandle(PExprBoolExpression(pFst, pSnd, Op));
}


PExprConstant::PExprConstant(const std::string& s)
    : _const(s)
{}

PExprConstantHandle PExprConstant::makeHandle(const std::string& s)
{
    return PExprConstantHandle(PExprConstant(s));
}

std::string PExprConstant::getName() const
{
    return _const;
}

std::string PExprConstant::toString() const
{
    std::stringstream ss;
    ss << "(constant " << _const << ")";
    return ss.str();
}

PExprAssertStatement::PExprAssertStatement(const std::string& s)
    : _assert(s)
{}

PExprAssertStatementHandle PExprAssertStatement::makeHandle(const std::string& s)
{
    return PExprAssertStatementHandle(PExprAssertStatement(s));
}

std::string PExprAssertStatement::getName() const
{
    return _assert;
}

std::string PExprAssertStatement::toString() const
{
    std::stringstream ss;
    ss << "(assert_statement " << _assert << ")";
    return ss.str();
}
