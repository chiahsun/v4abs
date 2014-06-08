#include "UnionFind.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"

void test_union_find() {
    UnionFind<std::string> uf;
    uf.addElement("One");
    uf.addElement("Two");
    uf.addElement("Three");
    assertEqual("One", uf.find("One"), "Test find");
    assertEqual("Two", uf.find("Two"), "Test find");
    assertEqual("Three", uf.find("Three"), "Test find");

    uf.unite("One", "Two");
    assertEqual(true, uf.find("One") == uf.find("Two"), "Test find");
    assertEqual(false, uf.find("Two") == uf.find("Three"), "Test find");
    uf.unite("Three", "Four");

    assertEqual(uf.find("Five"), uf.find("Five"), "Test find");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


int main() {
    test_union_find();
    return 0;
}
