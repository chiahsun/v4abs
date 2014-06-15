#include "SigExpression.h"

int main(){
    Signal sig_1("!", "clk");
    Signal sig_2("#", "rst");
    sig_1.addTimeValue(0, "011");
    sig_2.addTimeValue(1, "101");

    SigExpression bool_1(0, &sig_1);
    SigExpression bool_s(0, &sig_2);
    std::cout << "1: " << bool_1.calculate() << std::endl;

    SigExpression bool_2(1, &sig_1, "0");
    SigExpression bool_3(1, &sig_1, "1");
    std::cout << "2: " << bool_2.calculate() << std::endl;
    std::cout << "3: " << bool_3.calculate() << std::endl;

    SigExpression bool_4(2, SigExpressionHandle(bool_1));
    SigExpression bool_5(3, SigExpressionHandle(bool_1));
    std::cout << "4: " << bool_4.calculate() << std::endl;
    std::cout << "5: " << bool_5.calculate() << std::endl;

    SigExpression bool_6(4, SigExpressionHandle(bool_1), SigExpressionHandle(bool_s));
    SigExpression bool_7(5, SigExpressionHandle(bool_1), SigExpressionHandle(bool_s));
    SigExpression bool_8(6, SigExpressionHandle(bool_1), SigExpressionHandle(bool_7));
    SigExpression bool_9(7, SigExpressionHandle(bool_1), SigExpressionHandle(bool_8));
    std::cout << "6: " << bool_6.calculate() <<std::endl;
    std::cout << "7: " << bool_7.calculate() <<std::endl;
    std::cout << "8: " << bool_8.calculate() <<std::endl;
    std::cout << "9: " << bool_9.calculate() <<std::endl;

    return 0;
}
