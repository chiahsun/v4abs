#ifndef CONVERT_GRAPH_INFO_H
#define CONVERT_GRAPH_INFO_H


#include "nstl/for_each/ForEach.h"
#include "protocol/past/CAst.h"
#include "PExpr.h"
#include "ConvertCAst2PExpr.h"
#include "ProtocolGraph.h"
#include "SigExpression.h"
#include "via/computation/Util.h"

class ConvertGraphInfo {
public:
    static SigExpressionHandle convert(const PExprBoolExpressionHandle & pBoolExpression, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map);
    static SigExpressionHandle convert(const PExprUpdateStatementHandle & pUpdateStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map);
    static SigExpressionHandle convert(const PExprReadOrWriteOrCheckStatementHandle & pReadOrWriteOrCheckStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map);
    static SigExpressionHandle convert(const PExprIfStatementWithoutGotoHandle & pIfStatementWithoutGoto, std::vector<Signal> & _vec, std::map<std::string, std::string> & _map);
    static SigExpressionHandle convert(const PExprCheckStatementHandle & pCheckStatement, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map);
    static SigExpressionHandle convert(const PExprIfStatementPrefixHandle & pIfStatementPrefix, std::vector<Signal> & _vecSig, std::map<std::string, std::string> & _map);
};


#endif // CONVERT_GRAPH_INFO_H
