#include "UnionFindImpl.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"

void test_union_find_impl() {

    {
        const unsigned int sz = 10;
        UnionFindImpl uf(sz);
        for (unsigned int i = 0; i < sz; ++i)
            assertEqual(i, uf.find(i), "Test find");
        uf.unite(0, 3);
        uf.unite(2, 4);
        uf.unite(5, 9);
        uf.unite(6, 8);
        assertEqual(uf.find(0), uf.find(3), "Test unite");
        assertEqual(uf.find(2), uf.find(4), "Test unite");
        assertEqual(uf.find(5), uf.find(9), "Test unite");
        assertEqual(uf.find(6), uf.find(8), "Test unite");
        assertEqual(false,  uf.find(1) == uf.find(8), "Test unite");
        
        uf.unite(0, 2);
        uf.unite(2, 9);
        uf.unite(8, 9);
        uf.unite(7, 9);
        uf.unite(1, 9);
        
        for (unsigned int i = 1; i < sz; ++i)
            assertEqual(uf.find(0), uf.find(i), "Test find");

        UnionFindImpl::id_type newId = uf.addElement();
        assertEqual(newId, uf.find(newId), "Test new element");
        for (unsigned int i = 0; i < sz - 1; ++i)
            assertEqual(true, uf.find(i) != uf.find(newId), "Test new element unequal");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_union_find_impl();
    return 0;
}
