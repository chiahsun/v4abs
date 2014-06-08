#include "VExpr.h"
#include "test/UnitTest.h"
#include "nstl/hash/HashTable.h"

void test_vexpr_hash_table() {
    {
        HashTable<VExprIdentifierHandle> ht;
        VExprIdentifierHandle pa = vexpr_identifier_mk_single_identifier("a");
        VExprIdentifierHandle pb = vexpr_identifier_mk_single_identifier("b");
        VExprIdentifierHandle pc = vexpr_identifier_mk_single_identifier("c");
        ht.insert(pa);
        ht.insert(pb);
        assertEqual(true, ht.find(pa) != ht.end(), "Test find");
        assertEqual(true, ht.find(pb) != ht.end(), "Test find");
        assertEqual(true, ht.find(pc) == ht.end(), "Test find");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_vexpr_hash_table();
    return 0;
}
