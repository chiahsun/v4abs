#include "UnionFind.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"
#include "nstl/for_each/ForEach.h"

#include <sstream>
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

    std::stringstream ss;
    CONST_FOR_EACH(pString, uf) {
        ss << pString << " ";
    }
    assertEqual("Five One Four Two Three ", ss.str(), "Test for each");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


int main() {
    test_union_find();
    return 0;
}
