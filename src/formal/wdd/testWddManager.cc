#include "test/UnitTest.h"
#include "Term.h"
#include "WddManager.h"

void test_change_term_manager() {
    TermHandle pTermReset = TermHandle(Term("reset"));
    TermHandle pTermEn = TermHandle(Term("en"));

    WddManager<TermHandle> wddManager1;
    WddManager<TermHandle>::WddNodeHandle pReset1 = wddManager1.addTerm(pTermReset);
    WddManager<TermHandle>::WddNodeHandle pEn1 = wddManager1.addTerm(pTermEn);
    
    WddManager<TermHandle>::WddNodeHandle pReset1AndEn1 = wddManager1.makeAnd(pReset1, pEn1);

    assertEqual("(en&&reset)", pReset1AndEn1->toPureString(wddManager1), "Test reset and en");
    assertEqual("1 : reset\n"
                "2 : en\n", wddManager1.stringOfTermOrder(), "Test order");

    WddManager<TermHandle> wddManager2;
    WddManager<TermHandle>::WddNodeHandle pEn2 = wddManager2.addTerm(pTermEn);
    WddManager<TermHandle>::WddNodeHandle pReset2 = wddManager2.addTerm(pTermReset);
    
    WddManager<TermHandle>::WddNodeHandle pReset2AndEn2 = wddManager2.makeAnd(pReset2, pEn2);

    assertEqual("(reset&&en)", pReset2AndEn2->toPureString(wddManager2), "Test reset and en");
    assertEqual("1 : en\n"
                "2 : reset\n", wddManager2.stringOfTermOrder(), "Test order");

    {
        WddManager<TermHandle> wddManager;
        WddManager<TermHandle>::WddNodeHandle pEn = wddManager.addTerm(pTermEn);
        WddManager<TermHandle>::WddNodeHandle pReset = wddManager.addTerm(pTermReset);

        WddManager<TermHandle>::WddNodeHandle pNode = wddManager.makeWddNode(wddManager1, pReset1AndEn1);

        assertEqual("(reset&&en)", pNode->toPureString(wddManager), "Test reset and en");
        assertEqual("1 : en\n"
                   "2 : reset\n", wddManager.stringOfTermOrder(), "Test order");
    }


    {
        WddManager<TermHandle> wddManager;
        WddManager<TermHandle>::WddNodeHandle pNode = wddManager.makeWddNode(wddManager1, pReset1AndEn1);

        assertEqual("(en&&reset)", pNode->toPureString(wddManager), "Test reset and en");
        assertEqual("1 : reset\n"
                   "2 : en\n", wddManager.stringOfTermOrder(), "Test order");
    }


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_change_term_manager();
    return 0;
}
