#include "VRExprTerm.h"
#include "VRExprExpression.h"
#include "utility/log/Log.h"
#include "test/UnitTest.h"

void test_add_term() {
    typedef VRExprTermManager::VRExprTermHandle VRExprTermHandle;
    typedef VRExprTermManager::WddNodeHandle WddNodeHandle;
    VRExprTermManager manager;
    WddNodeHandle pa = manager.addExpr(makeIdentifier("a"));
    assertEqual("a", manager.stringOfNode(pa), "Test to string");
    WddNodeHandle pb = manager.addExpr(makeIdentifier("b"));
    WddNodeHandle pc = manager.addExpr(makeBinaryExpression(makeIdentifier("a"), BINARY_GT, makeIdentifier("b")));
    WddNodeHandle p1 = manager.ite(pc, pa, pb);
    assertEqual("ite((a>b), a, b)", manager.stringOfNode(p1), "Test to string");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_add_term();
    return 0;
}
