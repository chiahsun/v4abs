#include "BddManager.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"

BddNodeHandle TRUE = BddNode::getConstOneHandle();
BddNodeHandle BDD_FALSE = BddNode::getConstZeroHandle();

const static bool isWriteFile = false;

void test_state() {
    BddManager bddManager;
    BddNodeHandle val_one = bddManager.makeBddNode(1);
    BddNodeHandle val_zero = bddManager.makeBddNode(2);
    BddNodeHandle rst = bddManager.makeBddNode(3);
    BddNodeHandle en = bddManager.makeBddNode(4);

    if (isWriteFile) {
        rst->writeDotFile("ite_rst.dot");
        en->writeDotFile("ite_en.dot");
        val_one->writeDotFile("ite_val_one.dot");
        val_zero->writeDotFile("ite_val_zero.dot");
    }

    
//    BddNodeHandle state = bddManager.makeBddNode(3);

//    BddNodeHandle one = bddManager.makeBddNode(4);
//    BddNodeHandle zero = bddManager.makeBddNode(5);

    if (isWriteFile) {
        TRUE->writeDotFile("ite_true.dot");
        BDD_FALSE->writeDotFile("ite_false.dot");
    }


    BddNodeHandle pInner = bddManager.ite(en, val_one, BDD_FALSE);

    BddNodeHandle en_bar = bddManager.makeNeg(en);
    BddNodeHandle p1 = bddManager.ite(en_bar, val_zero, BDD_FALSE);
    assert(!val_one->equal(val_zero));
    BddNodeHandle p2 = bddManager.ite(en, val_one, val_zero);
    BddNodeHandle p3 = bddManager.ite(rst, p2, BDD_FALSE);
    BddNodeHandle p4 = bddManager.ite(bddManager.makeNeg(rst), BDD_FALSE, BDD_FALSE);

    BddNodeHandle pOuter = bddManager.ite(rst, p3, p4);

    if (isWriteFile) {
        pInner->writeDotFile("ite_inner.dot");
        en_bar->writeDotFile("ite_!en.dot");
        p1->writeDotFile("ite_p1.dot");
        p2->writeDotFile("ite_p2.dot");
        pOuter->writeDotFile("ite_outer.dot");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_ite2() {
    BddManager bddManager;
    /**
     * terminal should be at top, n < others
     *   so should be one = zero < rst = en
     *  But test bench is hand coded so not modified now
     *
     *  Please see ite3 for corret ordering
     */
    BddNodeHandle rst = bddManager.makeBddNode(1);
    BddNodeHandle en = bddManager.makeBddNode(2);
    BddNodeHandle one = bddManager.makeBddNode(3);
    BddNodeHandle zero = bddManager.makeBddNode(4);

    BddNodeHandle p2 = bddManager.ite(rst, zero, BDD_FALSE);
    BddNodeHandle p1 = bddManager.ite(bddManager.makeAnd(rst, en), one, p2);

    assertEqual("4 Bdd(n1, n0, false)\n"
                " 1 Bdd(true, n1, false)\n", p2->toString(), "Test p2 to string");
    assertEqual("4 Bdd(n1, n0, n2)\n"
                " 3 Bdd(n3, n1, n4)\n"
                "  1 Bdd(true, n3, false)\n"
                "  2 Bdd(false, n4, n10)\n"
                "   1 Bdd(true, n10, false)\n"
                " 3 Bdd(n5, n2, false)\n"
                "  2 Bdd(n11, n5, false)\n"
                "   1 Bdd(true, n11, false)\n", p1->toString(), "Test p1 to string");

    if (isWriteFile) {
        p2->writeDotFile("ite2_p2.dot");
        p1->writeDotFile("ite2_p1.dot");
    }


//    DEBUG_EXPR(bddManager.size());

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_ite3() {
    BddManager bddManager;

    BddNodeHandle one = bddManager.makeBddNode(1);
    BddNodeHandle zero = bddManager.makeBddNode(2);
    BddNodeHandle en = bddManager.makeBddNode(3);
    BddNodeHandle rst = bddManager.makeBddNode(4);

    BddNodeHandle p1 = bddManager.ite(rst, zero, BddManager::BDD_FALSE);
    BddNodeHandle p2 = bddManager.ite(en, one, BddManager::BDD_FALSE);
    BddNodeHandle p3 = bddManager.ite(en, p2, BddManager::BDD_FALSE);
    BddNodeHandle p4 = bddManager.ite(rst, p1, p3);

    p4->writeDotFile("ite3_p4.dot");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_state();
    test_ite2();
    test_ite3();
}
