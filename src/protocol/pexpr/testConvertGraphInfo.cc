#include "ConvertGraphInfo.h"
#include "PExpr.h"
#include "test/UnitTest.h"

int main() {
    Signal sig("!", "a");
    sig.addTimeValue(0, "0");
    std::vector<Signal> _vec;
    std::map<std::string, std::string> _map;
    _vec.push_back(sig);
    _map["a"] = "!";

    PExprBoolExpressionHandle pBool_1 = PExprBoolExpression::makeIdentifierHandle("a"); // identifier
    PExprBoolExpressionHandle pBool_2 = PExprBoolExpression::makeUnaryNotHandle(pBool_1); // not
    PExprBoolExpressionHandle pBool_3 = PExprBoolExpression::makeBinaryOrHandle(pBool_1, pBool_2); // or
    PExprBoolExpressionHandle pBool_4 = PExprBoolExpression::makeBinaryXorHandle(pBool_2, pBool_3);

    SigExpressionHandle pSig_1 = ConvertGraphInfo::convert(pBool_1, _vec, _map);
    SigExpressionHandle pSig_2 = ConvertGraphInfo::convert(pBool_2, _vec, _map);
    SigExpressionHandle pSig_3 = ConvertGraphInfo::convert(pBool_3, _vec, _map);
    SigExpressionHandle pSig_4 = ConvertGraphInfo::convert(pBool_4, _vec, _map);
    std::cout << pSig_1->calculate() << std::endl;
    std::cout << pSig_2->calculate() << std::endl;
    std::cout << pSig_3->calculate() << std::endl;
    std::cout << pSig_4->calculate() << std::endl;

    return 0;
}
