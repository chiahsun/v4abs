#include "BoolExpression.h"

int main(){
    Signal sig_1("!", "clk");
    Signal sig_2("#", "rst");
    sig_1.addTimeValue(0, "011");
    sig_2.addTimeValue(1, "101");

    BoolExpressionIdentifier bool_1(&sig_1);
    BoolExpressionIdentifier bool_s(&sig_2);
    std::cout << "1: " << bool_1.calculate() << std::endl;

    BoolExpressionEqual bool_2(&sig_1, "0");
    BoolExpressionEqual bool_3(&sig_1, "1");
    std::cout << "2: " << bool_2.calculate() << std::endl;
    std::cout << "3: " << bool_3.calculate() << std::endl;

    BoolExpressionUnary bool_4(0, &bool_1);
    BoolExpressionUnary bool_5(1, &bool_1);
    std::cout << "4: " << bool_4.calculate() << std::endl;
    std::cout << "5: " << bool_5.calculate() << std::endl;

    BoolExpressionBinary bool_6(0, &bool_1, &bool_s);
    BoolExpressionBinary bool_7(1, &bool_1, &bool_s);
    BoolExpressionBinary bool_8(2, &bool_1, &bool_7);
    BoolExpressionBinary bool_9(3, &bool_1, &bool_8);
    std::cout << "6: " << bool_6.calculate() <<std::endl;
    std::cout << "7: " << bool_7.calculate() <<std::endl;
    std::cout << "8: " << bool_8.calculate() <<std::endl;
    std::cout << "9: " << bool_9.calculate() <<std::endl;

    return 0;
}
