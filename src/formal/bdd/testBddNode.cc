#include "test/UnitTest.h"
#include "BddNode.h"
#include "BddManager.h"

const static bool isWriteFile = false;

BddNodeHandle TRUE = BddNode::getConstOneHandle();
BddNodeHandle FALSE = BddNode::getConstZeroHandle();

void test_bdd_true_false() {
    assertEqual("0 Bdd(true)\n", TRUE->toString(), "Test bdd to string");
    assertEqual(0, TRUE->getCurDecisionLevel(), "Test cur decision level");
    assertEqual(true, TRUE->isTerminal(), "Test is terminal");
    assertEqual(528, TRUE->hashFunction(), "Test hash code");
    assertEqual(true, TRUE->getBool(), "Test get bool");
    
    assertEqual("0 Bdd(false)\n", FALSE->toString(), "Test bdd to string");
    assertEqual(0, FALSE->getCurDecisionLevel(), "Test cur decision level");
    assertEqual(true, FALSE->isTerminal(), "Test is terminal");
    assertEqual(530, FALSE->hashFunction(), "Test hash code");
    assertEqual(false, FALSE->getBool(), "Test get bool");

    if (isWriteFile) {
        TRUE->writeDotFile("true.dot");
        FALSE->writeDotFile("false.dot");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_bdd_add() {
    BddManager bddManager;
    BddNodeHandle p1 = bddManager.makeBddNode(1) ;
    assertEqual("1 Bdd(true, n0, false)\n"
               , p1->toString(), "Test bdd to string");

    BddNodeHandle p2 = bddManager.makeBddNode(2, p1, FALSE);

    assertEqual("2 Bdd(n1, n0, false)\n"
                " 1 Bdd(true, n1, false)\n", p2->toString(), "Test bdd to string");
//    assertEqual(true, p2->getPosHandle()->toString() == p1->toString(), "Test get pos handle");
//    assertEqual(true, p2->getNegHandle()->toString() == BddNode::getConstZeroHandle()->toString(), "Test get pos handle");

    if (isWriteFile) {
        p1->writeDotFile("p1.dot");
        p2->writeDotFile("p2.dot");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_bdd_equal() {
    BddManager bddManager;

    BddNodeHandle a = bddManager.makeBddNode(1);
    BddNodeHandle b = bddManager.makeBddNode(2);
    BddNodeHandle c = bddManager.makeBddNode(3);

    assertEqual(true, a->equal(a), "Test equal");
    assertEqual(false, a->equal(b), "Test equal");
    assertEqual(false, b->equal(c), "Test equal");
    assertEqual(false, c->equal(a), "Test equal");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

// ITE(f, 1, g)
void test_bdd_disjunct() {
    BddManager bddManager;
    BddNodeHandle pG = BddNode::makeBddNode(1);
    BddNodeHandle pF = BddNode::makeBddNode(2);
    BddNodeHandle pUnion = BddNode::makeBddNode(pF->getCurDecisionLevel(), BddNode::getConstOneHandle(), pG);
    BddNodeHandle pUnion2 = BddNode::makeBddNode(pF->getCurDecisionLevel(), BddNode::getConstOneHandle(), pG);

    if (isWriteFile) {
        pUnion->writeDotFile("union.dot");
        pUnion2->writeDotFile("union2.dot");
    }
    assertEqual(pUnion->hashFunction(), pUnion2->hashFunction(), "Test same node function hash code");
    assertEqual(true, pUnion->isStructureEqual(pUnion2), "Test equality test");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


int main() {

    test_bdd_true_false();
    test_bdd_add();
    test_bdd_equal();
    test_bdd_disjunct();

    return 0;
}
