#include "test/UnitTest.h"
#include "DesignCTE.h"

void test_print() {
    std::cout << statement_handle_state_next()->getString() << std::endl;
    std::cout << continuous_assignment_handle_out_valid()->getString() << std::endl;
    std::cout << continuous_assignment_handle_reg_U_next()->getString() << std::endl;
    std::cout << continuous_assignment_handle_reg_Y1_next()->getString() << std::endl;
    std::cout << continuous_assignment_handle_reg_V_next()->getString() << std::endl;
    std::cout << continuous_assignment_handle_reg_Y2_next()->getString() << std::endl;
    std::cout << continuous_assignment_handle_U_ext()->getString() << std::endl;
    std::cout << continuous_assignment_handle_Y_ext()->getString() << std::endl;
    std::cout << continuous_assignment_handle_V_ext()->getString() << std::endl;
    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_print();
    return 0;
}
