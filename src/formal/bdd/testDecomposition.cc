#include "BddManager.h"
#include "test/UnitTest.h"

void test_conjunctive_decomposition() {
    BddManager bddManager;

    BddNodeHandle p1 = bddManager.makeBddNode(1);
    BddNodeHandle p2 = bddManager.makeBddNode(2);
    BddNodeHandle p3 = bddManager.makeBddNode(3);
        
    BddNodeHandle f_pb = p1;
    BddNodeHandle f_pd = bddManager.makeBddNode(2, f_pb, BddNode::getConstZeroHandle());
    BddNodeHandle f_pe = bddManager.makeBddNode(3, BddNode::getConstOneHandle(), f_pd);

    f_pe->writeDotFile("conjunctive_f_pe.dot");
    f_pd->writeDotFile("conjunctive_f_pd.dot");
    f_pb->writeDotFile("conjunctive_f_pb.dot");

        
    BddNodeHandle d_pd = bddManager.makeBddNode(2);
    BddNodeHandle d_pe = bddManager.makeBddNode(3, BddNode::getConstOneHandle(), d_pd);

    d_pd->writeDotFile("conjunctive_d_pd.dot");
    d_pe->writeDotFile("conjunctive_d_pe.dot");

    BddNodeHandle q_pb = bddManager.makeBddNode(1);
    BddNodeHandle q_pe = bddManager.makeBddNode(3, BddNode::getConstOneHandle(), q_pb);

    q_pb->writeDotFile("conjunctive_q_pb.dot");
    q_pe->writeDotFile("conjunctive_q_pe.dot");


    BddNodeHandle p_conjunctive= bddManager.makeAnd(d_pe, q_pe);
    p_conjunctive->writeDotFile("conjunctive_d_pe_and_q_pe.dot");
    assertEqual(true, bddManager.makeEq(p_conjunctive, f_pe) == BddNode::getConstOneHandle(), "Test eq");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_conjunctive_decomposition2() {

    BddManager bddManager;
    
    BddNodeHandle f_pe = bddManager.makeBddNode(1);
    BddNodeHandle f_pd = bddManager.makeBddNode(2, BddNode::getConstOneHandle(), f_pe);
    BddNodeHandle f_pg = bddManager.makeBddNode(3, BddNode::getConstOneHandle(), f_pd);

    BddNodeHandle f_pc1 = bddManager.makeBddNode(4, f_pg, BddNode::getConstZeroHandle());
    BddNodeHandle f_pc2 = bddManager.makeBddNode(4, f_pd, BddNode::getConstZeroHandle());

    BddNodeHandle f_pb1 = bddManager.makeBddNode(5, f_pg, f_pc1);
    BddNodeHandle f_pb2 = bddManager.makeBddNode(5, f_pd, f_pc2);
    BddNodeHandle f_pf = bddManager.makeBddNode(6, f_pg, f_pb1);

    BddNodeHandle f_pa = bddManager.makeBddNode(7, f_pf, f_pb2);

    f_pa->writeDotFile("conjunctive2_f_pa.dot");

    BddNodeHandle d_pc1 = bddManager.makeBddNode(4);
    BddNodeHandle d_pc2 = bddManager.makeBddNode(4);
    BddNodeHandle d_pb1 = bddManager.makeBddNode(5, BddNode::getConstOneHandle(), d_pc1);
    BddNodeHandle d_pb2 = bddManager.makeBddNode(5, BddNode::getConstOneHandle(), d_pc2);
    BddNodeHandle d_pf = bddManager.makeBddNode(6, BddNode::getConstOneHandle(), d_pb1);
    BddNodeHandle d_pa = bddManager.makeBddNode(7, d_pf, d_pb2);

    d_pa->writeDotFile("conjunctive2_d_pa.dot");

    BddNodeHandle q_pe = bddManager.makeBddNode(1);
    BddNodeHandle q_pd = bddManager.makeBddNode(2, BddNode::getConstOneHandle(), q_pe);
    BddNodeHandle q_pg = bddManager.makeBddNode(3, BddNode::getConstOneHandle(), q_pd);

    BddNodeHandle q_pc1 = bddManager.makeBddNode(4, q_pg, q_pg);
    BddNodeHandle q_pc2 = bddManager.makeBddNode(4, q_pd, q_pd);

    BddNodeHandle q_pb1 = bddManager.makeBddNode(5, q_pg, q_pc1);
    BddNodeHandle q_pb2 = bddManager.makeBddNode(5, q_pd, q_pc2);
    BddNodeHandle q_pf = bddManager.makeBddNode(6, q_pg, q_pb1);

    BddNodeHandle q_pa = bddManager.makeBddNode(7, q_pf, q_pb2);

    q_pa->writeDotFile("conjunctive2_q_pa.dot");

    assertEqual(true, bddManager.makeAnd(q_pa, d_pa) == f_pa, "Test conjunction 2 and");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_xor() {
    BddManager bddManager;

    BddNodeHandle p1 = bddManager.makeBddNode(1);
    BddNodeHandle p2 = bddManager.makeBddNode(2);
    BddNodeHandle p3 = bddManager.makeBddNode(3);
    BddNodeHandle p4 = bddManager.makeBddNode(4);

    BddNodeHandle pxor12 = bddManager.makeXor(p1, p2);
    BddNodeHandle pxor123 = bddManager.makeXor(pxor12, p3);
    BddNodeHandle pxor1234 = bddManager.makeXor(pxor123, p4);

    pxor12->writeDotFile("xor12.dot");
    pxor123->writeDotFile("xor123.dot");
    pxor1234->writeDotFile("xor1234.dot");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_xnor_decomposition() {
    BddManager bddManager;

    BddNodeHandle f_y1 = bddManager.makeBddNode(1, BddNode::getConstZeroHandle(), BddNode::getConstOneHandle());
    BddNodeHandle f_y2 = bddManager.makeNeg(f_y1);
    assertEqual(true, bddManager.isNeg(f_y1, f_y2), "Test is neg");

    BddNodeHandle f_x1 = bddManager.makeBddNode(2, BddNode::getConstZeroHandle(), f_y1);
    BddNodeHandle f_x2 = bddManager.makeBddNode(2, BddNode::getConstOneHandle(), f_y2);
    BddNodeHandle f_q = bddManager.makeBddNode(3, f_x2, f_x1);
    BddNodeHandle f_r = bddManager.makeBddNode(4, f_q, f_x2);
    BddNodeHandle f_u = bddManager.makeBddNode(5, f_r, f_x2);

    f_u->writeDotFile("xnor_f_u.dot");

    BddNodeHandle g_y = bddManager.makeBddNode(1);
    BddNodeHandle g_x = bddManager.makeBddNode(2, BddNode::getConstOneHandle(), g_y);
    
    g_x->writeDotFile("xnor_g_x.dot");

    BddNodeHandle h_q = bddManager.makeBddNode(3);
    BddNodeHandle h_r = bddManager.makeBddNode(4, h_q, BddNode::getConstOneHandle());
    BddNodeHandle h_u = bddManager.makeBddNode(5, h_r, BddNode::getConstOneHandle());
    
    h_u->writeDotFile("xnor_h_u.dot");

    BddNodeHandle pxnor_g_x_with_h_u = bddManager.makeXnor(g_x, h_u);
    pxnor_g_x_with_h_u->writeDotFile("xnor_g_x_with_h_u.dot");
    assertEqual(true, f_u == pxnor_g_x_with_h_u, "Test xnor decomposition");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_conjunctive_decomposition();
    test_conjunctive_decomposition2();
    test_xor();
    test_xnor_decomposition();

    return 0;
}
