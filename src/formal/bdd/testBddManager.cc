#include "BddManager.h"
#include "test/UnitTest.h"

static const bool isWriteFile = false;

void test_make_the_same_node() {
    BddManager bddManager;

    BddNodeHandle pa = bddManager.makeBddNode(1); 

    BddNodeHandle pa2 = bddManager.makeBddNode(2); 

    if (isWriteFile) {
        pa->writeDotFile("pa.dot");
        pa2->writeDotFile("pa2.dot");
    }

    assertEqual("1 Bdd(true, n0, false)\n", pa->toString(), "Test pa to string");
    assertEqual("2 Bdd(true, n0, false)\n", pa2->toString(), "Test pa2 to string");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_operations() {
    BddManager bddManager;
    BddNodeHandle p = bddManager.makeBddNode(1);
    BddNodeHandle q = bddManager.makeBddNode(2);
    BddNodeHandle r = bddManager.makeBddNode(3);

    assertEqual("1 Bdd(true, n0, false)\n", p->toString(), "Test p to string");
    assertEqual("2 Bdd(true, n0, false)\n", q->toString(), "Test q to string");
    assertEqual("3 Bdd(true, n0, false)\n", r->toString(), "Test r to string");

    BddNodeHandle pq = bddManager.makeAnd(p, q);
    BddNodeHandle p_or_q = bddManager.makeOr(p, q);
    BddNodeHandle p_imp_q = bddManager.makeImply(p, q);
    BddNodeHandle q_imp_r = bddManager.makeImply(q, r);

    assertEqual("2 Bdd(n1, n0, false)\n"
                " 1 Bdd(true, n1, false)\n", pq->toString(), "Test pq to string");
    assertEqual("2 Bdd(true, n0, n2)\n"
                " 1 Bdd(true, n2, false)\n", p_or_q->toString(), "Test p_or_q to string");
    assertEqual("2 Bdd(true, n0, n2)\n"
                " 1 Bdd(false, n2, true)\n", p_imp_q->toString(), "Test p_imp_q to string");
    assertEqual("3 Bdd(true, n0, n2)\n"
                " 2 Bdd(false, n2, true)\n", q_imp_r->toString(), "Test q_imp_r to string");

    BddNodeHandle pqr = bddManager.makeAnd(pq, r);
    BddNodeHandle p_or_q_or_r = bddManager.makeOr(p_or_q, r);
    BddNodeHandle not_p = bddManager.makeNeg(p);
    BddNodeHandle p_imp_q_imp_r = bddManager.makeImply(p, q_imp_r);
    BddNodeHandle p_eq_p = bddManager.makeEq(p, p);
    BddNodeHandle p_eq_q = bddManager.makeEq(p, q);

    if (isWriteFile) {
        p->writeDotFile("operation_p.dot");
        q->writeDotFile("operation_q.dot");
        r->writeDotFile("operation_r.dot");

        pq->writeDotFile("operation_p_and_q.dot");
        pqr->writeDotFile("operation_p_and_q_and_r.dot");
        p_or_q->writeDotFile("operation_p_or_q.dot");
        p_or_q_or_r->writeDotFile("operation_p_or_q_or_r.dot");
        not_p->writeDotFile("operation_not_p.dot");
        p_imp_q->writeDotFile("operation_p_imply_q.dot");
        q_imp_r->writeDotFile("operation_q_imply_r.dot");
        p_imp_q_imp_r->writeDotFile("operation_p_imply_q_imply_r.dot");
        p_eq_p->writeDotFile("operation_p_eq_p.dot");
        p_eq_q->writeDotFile("operation_p_eq_q.dot");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


// !(a and b) = (!a or !b)
// !(a or b) = !a and !b
void test_demorgan() {
    BddManager bddManager;
    BddNodeHandle pA = bddManager.makeBddNode(1);
    BddNodeHandle pB = bddManager.makeBddNode(2);

    BddNodeHandle pNot_AandB =
        bddManager.makeNeg(bddManager.makeAnd(pA, pB));

    BddNodeHandle pNotA_or_NotB =
        bddManager.makeOr( bddManager.makeNeg(pA)
                          , bddManager.makeNeg(pB));

    assertEqual(true, pNot_AandB->equal(pNot_AandB), "Test demorgan");
    assertEqual("2 Bdd(n1, n0, true)\n"
                " 1 Bdd(false, n1, true)\n", pNot_AandB->toString(), "Test demorgan to string");

}


// Reference
// 1. boolean algebra
//    http://en.wikipedia.org/wiki/Boolean_algebra_(structure)
// 2. propositional logic
//    http://en.wikipedia.org/wiki/Propositional_logic#Basic_and_derived_argument_forms
//
void test_propositional_logic() {
    BddManager bddManager;
    BddNodeHandle p = bddManager.makeBddNode(1);
    BddNodeHandle q = bddManager.makeBddNode(2);
    BddNodeHandle r = bddManager.makeBddNode(3);

    BddNodeHandle pq =
        bddManager.makeAnd(p, q);
    BddNodeHandle qr =
        bddManager.makeAnd(q, r);
    BddNodeHandle pr =
        bddManager.makeAnd(p, r);
    BddNodeHandle p_or_q =
        bddManager.makeOr(p, q);
    BddNodeHandle q_or_r = 
        bddManager.makeOr(q, r);
    BddNodeHandle p_or_r = 
        bddManager.makeOr(p, r);
    BddNodeHandle p_imp_q =
        bddManager.makeImply(p, q);
    BddNodeHandle neg_p = bddManager.makeNeg(p);
    BddNodeHandle neg_neg_p = bddManager.makeNeg(neg_p);
    BddNodeHandle p_or_qorr = bddManager.makeOr(p, q_or_r);
    BddNodeHandle porq_or_r = bddManager.makeOr(p_or_q, r);

    if (isWriteFile) {
        pq->writeDotFile("pq.dot");
        qr->writeDotFile("qr.dot");
        p_or_q->writeDotFile("p_or_q.dot");
        q_or_r->writeDotFile("q_or_r.dot");
        p_imp_q->writeDotFile("p_imp_q.dot");
    }


    // !!p = p
    assertEqual(
        true
      , neg_neg_p->equal(p)
      , "Test double negation rule");
    assertEqual("1 Bdd(true, n0, false)\n", neg_neg_p->toString(), "Test double negation rule to string");

    // p or (q or r) = (p or q) or r
    assertEqual(
        true
      , BddNode::getConstOneHandle()->equal( 
        bddManager.makeEq( 
            p_or_qorr
          , porq_or_r ))
      , "Test associativity");

    assertEqual(true, p_or_qorr->equal(porq_or_r), "Test associativity ");
    assertEqual("3 Bdd(true, n0, n2)\n"
                " 2 Bdd(true, n2, n6)\n"
                "  1 Bdd(true, n6, false)\n", p_or_qorr->toString(), "Test associativity to string");

    
    // p and (q and r) = (p and q) and r
    assertEqual(
        true
      , bddManager.makeAnd(p, qr)->equal(bddManager.makeAnd(pq, r))
      , "Test associativity");
    assertEqual("3 Bdd(n1, n0, false)\n"
                " 2 Bdd(n3, n1, false)\n"
                "  1 Bdd(true, n3, false)\n", bddManager.makeAnd(p, qr)->toString(), "Test associativity to string");

    // a or b = b or a
    assertEqual(
        true
      , bddManager.makeOr(p, q)->equal(bddManager.makeOr(q, p))
      , "Test commutativity");

    assertEqual("2 Bdd(true, n0, n2)\n"
                " 1 Bdd(true, n2, false)\n", bddManager.makeOr(p, q)->toString(), "Test commutativity to string");

    // a and b = b and a
    assertEqual(
        true
      , bddManager.makeAnd(p, q)->equal(
        bddManager.makeAnd(q, p))
      , "Test commutativity");

    assertEqual("2 Bdd(n1, n0, false)\n"
                " 1 Bdd(true, n1, false)\n", bddManager.makeAnd(p, q)->toString(), "Test commutativity to string");

    // a or (a and b) = a
    assertEqual(
        true
      , bddManager.makeOr(p, pq)->equal(p)
      , "Test absorption");

    assertEqual("1 Bdd(true, n0, false)\n", bddManager.makeOr(p, pq)->toString(), "Test absorption to string");

    // a and (a or b) = a
    assertEqual(
        true
      , bddManager.makeAnd(p, p_or_q)->equal(p)
      , "Test absorption");

    assertEqual("1 Bdd(true, n0, false)\n", bddManager.makeAnd(p, p_or_q)->toString(), "Test absorption to string");

    // a or 0 = a
    assertEqual(
        true
      , bddManager.makeOr(p, BddNode::getConstZeroHandle())->equal(p)
      , "Test identity");

    assertEqual("1 Bdd(true, n0, false)\n", bddManager.makeOr(p, BddNode::getConstZeroHandle())->toString(), "Test identity to string");

    // a and 1 = a
    assertEqual(
        true
      , bddManager.makeAnd(p, BddNode::getConstOneHandle())->equal(p)
      , "Test identity");

    assertEqual("1 Bdd(true, n0, false)\n", bddManager.makeAnd(p, BddNode::getConstOneHandle())->toString(), "Test identity to string");

    {
        BddNodeHandle px = bddManager.makeOr(p, qr);
        BddNodeHandle py = bddManager.makeAnd(p_or_q, p_or_r);

        // a or (b and c) = (a and b) or (a or c)
        assertEqual(true, px->equal(py), "Test distributivity");
        assertEqual("3 Bdd(n1, n0, n2)\n"
                    " 2 Bdd(true, n1, n4)\n"
                    "  1 Bdd(true, n4, false)\n"
                    " 1 Bdd(true, n2, false)\n", px->toString(), "Test distributivity to string");
        if (isWriteFile) {
            px->writeDotFile("px.dot");
            py->writeDotFile("py.dot");
        }
    }


    // a and (b or c) = (a and b) or (a and c)
    assertEqual(
        true
      , bddManager.makeAnd(p
          , q_or_r)->equal(
        bddManager.makeOr(pq, pr))
      , "Test distributivity");
    assertEqual("3 Bdd(n1, n0, n2)\n"
                " 1 Bdd(true, n1, false)\n"
                " 2 Bdd(n5, n2, false)\n"
                "  1 Bdd(true, n5, false)\n", bddManager.makeAnd(p, q_or_r)->toString(), "Test distributivity to string");


    // (p->q and p) |- q
    assertEqual(
        true
      , bddManager.makeImply(
                bddManager.makeAnd(p_imp_q, p), q)->equal(BddNode::getConstOneHandle())
      , "Test modus pones");
     
    assertEqual("0 Bdd(true)\n", bddManager.makeImply(bddManager.makeAnd(p_imp_q, p), q)->toString(), "Test modus pones to string");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

/**
 *
 *  f = ite(x4, not x2, x1)
 *        
 *          x4
 *      1/     \0
 *     x2       x1 
 *   1/  \0   1/   \0
 *   F    T   T     F
 *
 *  c = or(x1, x2)
 *
 *       x2
 *    1/    \0
 *    T      x1
 *         1/  \0
 *         T    F
 *
 *  gcf(f, c)
 *
 *         x4
 *      1/    \0
 *     x2       x2
 *   1/ \0    1/  \0
 *   F   T   x1    T
 *         1/  \0
 *         T    F
 */


void test_generalized_cofactor() {
    BddManager bddManager;


    BddNodeHandle pF = bddManager.makeBddNode(
              4
            , bddManager.makeNeg(bddManager.makeBddNode(2))
            , bddManager.makeBddNode(1));

    BddNodeHandle pC = bddManager.makeBddNode(
              2
            , BddManager::BDD_TRUE
            , bddManager.makeBddNode(1));
    BddNodeHandle pGcf = bddManager.getGeneralizedCofactor(pF, pC);

    assertEqual("4 Bdd(n1, n0, n2)\n"
                " 2 Bdd(false, n1, true)\n"
                " 1 Bdd(true, n2, false)\n", pF->toString(), "Test to string");
    assertEqual("2 Bdd(true, n0, n2)\n"
                " 1 Bdd(true, n2, false)\n", pC->toString(), "Test to string");
    assertEqual("4 Bdd(n1, n0, n2)\n"
                " 2 Bdd(false, n1, true)\n"
                " 2 Bdd(n5, n2, true)\n"
                "  1 Bdd(true, n5, false)\n", pGcf->toString(), "Test to string");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

/**
 *
 *  f = ite(x4, x2->(not x1), (not x2) ^ (not x1))
 *        
 *             x4
 *         1/     \0
 *        x2       x2
 *      1/  \0   1/   \0
 *     x1    T   F     x1
 *   1/  \0          1/  \0
 *   F    T          F    T
 *
 *  c = or(x4, x2)
 *
 *       x4
 *    1/    \0
 *    T      x2
 *         1/  \0
 *         T    F
 *
 *  gcf(f, c)
 *
 *            x4
 *         1/    \0
 *        x2       F
 *      1/  \0    
 *     x1     T  
 *   1/ \0        
 *   F   T         
 */


void test_generalized_cofactor2() {
    BddManager bddManager;

    BddNodeHandle p1 = bddManager.makeBddNode(1);
    BddNodeHandle p2 = bddManager.makeBddNode(2);
    BddNodeHandle p3 = bddManager.makeBddNode(3);
    BddNodeHandle p4 = bddManager.makeBddNode(4);

    BddNodeHandle pF = bddManager.makeBddNode(
        4
      , bddManager.makeBddNode(2, bddManager.makeNeg(p1), BddManager::BDD_TRUE)
      , bddManager.makeBddNode(2, BddManager::BDD_FALSE, bddManager.makeNeg(p1))  );

    BddNodeHandle pC = bddManager.makeBddNode(4, BddManager::BDD_TRUE, p2);

    BddNodeHandle pGcf = bddManager.getGeneralizedCofactor(pF, pC);

    assertEqual("4 Bdd(n1, n0, n2)\n"
                " 2 Bdd(n3, n1, true)\n"
                "  1 Bdd(false, n3, true)\n"
                " 2 Bdd(false, n2, n6)\n"
                "  1 Bdd(false, n6, true)\n", pF->toString(), "Test to string");
    assertEqual("4 Bdd(true, n0, n2)\n"
                " 2 Bdd(true, n2, false)\n", pC->toString(), "Test to string");
    assertEqual("4 Bdd(n1, n0, false)\n"
                " 2 Bdd(n3, n1, true)\n"
                "  1 Bdd(false, n3, true)\n", pGcf->toString(), "Test to string");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_make_the_same_node();
    test_operations();
    test_demorgan();
    test_propositional_logic();
    test_generalized_cofactor();
    test_generalized_cofactor2();

    return 0;
}
