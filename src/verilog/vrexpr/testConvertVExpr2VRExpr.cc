#include "test/UnitTest.h"
#include "ConvertVExpr2VRExpr.h"
#include "utility/log/Log.h"

void test_convert_identifier() {
    VExprIdentifierHandle a = vexpr_identifier_mk_single_identifier("a", 4); 
    VExprIdentifierHandle b = vexpr_identifier_mk_hier_identifier("inst_c", "reg_b", 2); 
    assertEqual("a", a->getString(), "Test get string");
    assertEqual("inst_c.reg_b", b->getString(), "Test get string");
    
    VRExprIdentifier ra = ConvertVExpr2VRExpr::convert(a);
    assertEqual("a", ra.toString(), "Test get string");
    VRExprIdentifier rb = ConvertVExpr2VRExpr::convert(b);
    assertEqual("inst_c.reg_b", rb.toString(), "Test get string");
    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_number() {
     VExprNumberHandle pNumber = vexpr_number_mk_unsigned_number(100);

     assertEqual("100", pNumber->getString(), "Test get string");

     VRExprNumber number = ConvertVExpr2VRExpr::convert(pNumber);
     assertEqual("100", number.toString(), "Test get string");

     UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_convert_identifier();
    test_convert_number();
    return 0;
}
