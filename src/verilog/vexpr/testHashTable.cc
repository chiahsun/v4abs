#include "VExpr.h"
#include "test/UnitTest.h"
#include "nstl/hash/HashTable.h"
void test_vexpr_hash_table() {
#if 1
    {
        HashTable<VExprIdentifierHandle> ht;
        VExprIdentifierHandle pa = vexpr_identifier_mk_single_identifier("a");
        VExprIdentifierHandle pb = vexpr_identifier_mk_single_identifier("b");
        VExprIdentifierHandle pc = vexpr_identifier_mk_single_identifier("c");
        ht.insert(pa);
        ht.insert(pb);
        assertEqual(true, ht.find(pa) != ht.end(), "test find");
        assertEqual(true, ht.find(pb) != ht.end(), "test find");
        assertEqual(true, ht.find(pc) == ht.end(), "test find");
        
        assertEqual("a", pa->getString(), "Test get string");
        assertEqual("b", pb->getString(), "Test get string");
        assertEqual("c", pc->getString(), "Test get string");
    }
#endif
#if 1
    {
        HashTable<VExprExpressionHandle> ht;
        VExprExpressionHandle pa = vexpr_expression_mk_single_identifier("a");
        VExprExpressionHandle pb = vexpr_expression_mk_unsigned_number(20);
        ht.insert(pa);
        ht.insert(pb);
        assertEqual("a", pa->getString(), "Test get string");
        assertEqual("20", pb->getString(), "Test get string");
        assertEqual(true, ht.find(pa) != ht.end(), "test find");
        assertEqual(true, ht.find(pb) != ht.end(), "test find");
        assertEqual(true, ht.find(pa) != ht.find(pb), "test find");
    }
#endif
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_vexpr_hash_table();
    return 0;
}
