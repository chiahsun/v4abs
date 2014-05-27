#include "test/UnitTest.h"
#include "VExprIdentifier.h"

void test_identifier() {
    {
        VExprIdentifierHandle pSingleIdentifier = vexpr_identifier_mk_single_identifier("reg_a", 4);
        assertEqual("reg_a", pSingleIdentifier->getString(), "Test single identifier get string");
        assertEqual(4, pSingleIdentifier->getSize(), "Test single identifier get size");
    }
    {
        VExprIdentifierHandle pHierIdentifier = vexpr_identifier_mk_hier_identifier("mod_a", "reg_a", 2);
        assertEqual("mod_a.reg_a", pHierIdentifier->getString(), "Test hier identifier get string");
        assertEqual(2, pHierIdentifier->getSize(), "Test hier identifier get size");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_identifier();
}
