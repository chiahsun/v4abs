#include "test/UnitTest.h"
#include "Term.h"
#include "WddManager.h"

const static bool isWriteFile = false;


void test_term_constructor() {
    TermHandle pTermOne = TermHandle(Term("one"));
    TermHandle pTermZero = TermHandle(Term("zero"));
    TermHandle pTermEn = TermHandle(Term("en"));
    TermHandle pTermRst = TermHandle(Term("rst"));

    /**
     * ExpressionHandle pExprAnd = expr_and(pTermOne, pTermZero);
     *
     */

    assertEqual("one", pTermOne->toString(), "Test term to string");

    WddManager<TermHandle> wddManager;

    WddManager<TermHandle>::WddNodeHandle pOne = wddManager.addTerm(pTermOne);
    WddManager<TermHandle>::WddNodeHandle pZero = wddManager.addTerm(pTermZero);
    WddManager<TermHandle>::WddNodeHandle pEn = wddManager.addTerm(pTermEn);
    WddManager<TermHandle>::WddNodeHandle pRst = wddManager.addTerm(pTermRst);

    assertEqual("1 : one\n"
                "2 : zero\n"
                "3 : en\n"
                "4 : rst\n", wddManager.stringOfTermOrder(), "Test order");

    assertEqual("1 Bdd(true, n0, false)\n", pOne->getBddNodeHandle()->toString(), "Test wdd node handle to string");
    assertEqual("one", pOne->toString(wddManager), "Test wdd node handle to string");
    assertEqual("4 Bdd(true, n0, false)\n", pRst->getBddNodeHandle()->toString(), "Test wdd node handle to string");
    assertEqual("rst", pRst->toString(wddManager), "Test wdd node handle to string");

    WddManager<TermHandle>::WddNodeHandle p1 = wddManager.makeAnd(pRst, pZero);
    WddManager<TermHandle>::WddNodeHandle p2 = wddManager.makeAnd(pEn, pOne);
    WddManager<TermHandle>::WddNodeHandle p3 = wddManager.makeAnd(pEn, p2);
    WddManager<TermHandle>::WddNodeHandle p4 = wddManager.ite(pRst, p1, p3);

    assertEqual("ite(rst, zero, ite(en, one, FALSE))", p4->toString(wddManager), "Test to string");

    if (isWriteFile) {
        p4->writeDotFile("term_p4.dot");
    }

    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_term_constructor();
    return 0;
}
