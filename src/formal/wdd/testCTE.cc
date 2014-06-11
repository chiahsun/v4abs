#include "test/UnitTest.h"
#include "Term.h"
#include "WddManager.h"
#include "utility/log/Log.h"

const static bool isWriteFile = true;

void test_cte() {
    TermHandle pTermStateNext = TermHandle(Term("state_next"));
    TermHandle pTermStateEqS_U = TermHandle(Term("state=S_U"));
    TermHandle pTermS_Y1 = TermHandle(Term("S_Y1"));
    TermHandle pTermStateEqS_Y1 = TermHandle(Term("state=S_Y1"));
    TermHandle pTermS_V = TermHandle(Term("S_V"));

    WddManager<TermHandle> wddManager;
    typedef WddManager<TermHandle>::WddNodeHandle WddNodeHandle;

    WddNodeHandle pStateNext = wddManager.addTerm(pTermStateNext);
    WddNodeHandle pS_Y1 = wddManager.addTerm(pTermS_Y1);
    WddNodeHandle pS_V = wddManager.addTerm(pTermS_V);
    WddNodeHandle pStateEqS_Y1 = wddManager.addTerm(pTermStateEqS_Y1);
    WddNodeHandle pStateEqS_U = wddManager.addTerm(pTermStateEqS_U);

    WddNodeHandle pStateEqS_UNeqStateEqS_Y1 =
        wddManager.makeNeq(pStateEqS_Y1, pStateEqS_U);
    WddNodeHandle pStateConstraint =
        pStateEqS_UNeqStateEqS_Y1;
    DEBUG_EXPR(pStateConstraint->toString(wddManager));

    WddNodeHandle p1 = wddManager.makeAnd(pStateEqS_U, pS_Y1);
    DEBUG_EXPR(p1->toString(wddManager));
    WddNodeHandle p2 = wddManager.makeAnd(pStateEqS_Y1, pS_V);
    DEBUG_EXPR(p2->toString(wddManager));
//    WddNodeHandle p3 = wddManager.makeAnd(wddManager.makeNeg(pStateEqS_U), p2);
    WddNodeHandle p3 = wddManager.ite(wddManager.makeNeg(pStateEqS_U), p1, p2);
    DEBUG_EXPR(p3->toString(wddManager));
    WddNodeHandle p = p3;
//    WddNodeHandle p = wddManager.makeAnd(p3, pStateConstraint);
    std::cout << wddManager.stringOfTermOrder() << std::endl;

    if (isWriteFile)
        p->writeDotFile("cte_state_next.dot");

    assertEqual("ite(state=S_U, ite(state=S_Y1, S_V, FALSE), FALSE)", p->toString(wddManager), "Test to string");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_cte();
    return 0;
}
