#include "test/UnitTest.h"
#include "Term.h"
#include "WddManager.h"

void test_efsm() {
    TermHandle pTermReset = TermHandle(Term("reset"));
    TermHandle pTermState = TermHandle(Term("state"));
    TermHandle pTermA = TermHandle(Term("A"));
    TermHandle pTermB = TermHandle(Term("B"));
    TermHandle pTermC = TermHandle(Term("C"));
    TermHandle pTermIn1 = TermHandle(Term("in1"));
    TermHandle pTermIn2 = TermHandle(Term("in2"));
    TermHandle pTerm4b1 = TermHandle(Term("4'b1"));
    TermHandle pTerm4b0 = TermHandle(Term("4'b0"));
    TermHandle pTermReg = TermHandle(Term("reg"));
    TermHandle pTermRegMultIn1 = TermHandle(Term("reg * in1"));
    TermHandle pTermRegMult2 = TermHandle(Term("reg * 2"));
    TermHandle pTermRegPlusIn2 = TermHandle(Term("reg + in2"));
    TermHandle pTermRegDiv2 = TermHandle(Term("reg / 2"));
    TermHandle pTermIn1Neq0 = TermHandle(Term("in1 != 0"));
    TermHandle pTermIn1Eq0 = TermHandle(Term("in1 == 0"));
    TermHandle pTermIn2Neq0 = TermHandle(Term("in2 != 0"));
    TermHandle pTermRegEq1 = TermHandle(Term("reg = 1"));
    TermHandle pTermRegNeq1 = TermHandle(Term("reg != 1"));
    TermHandle pTermStateEqC = TermHandle(Term("stateEqC"));
    TermHandle pTermStateEqB = TermHandle(Term("stateEqB"));
    TermHandle pTermStateEqA = TermHandle(Term("stateEqA"));

    WddManager<TermHandle> wddManager;
    typedef WddManager<TermHandle>::WddNodeHandle WddNodeHandle;

    WddNodeHandle pState = wddManager.addTerm(pTermState);
    WddNodeHandle pA = wddManager.addTerm(pTermA);
    WddNodeHandle pB = wddManager.addTerm(pTermB);
    WddNodeHandle pC = wddManager.addTerm(pTermC);
    WddNodeHandle pIn1 = wddManager.addTerm(pTermIn1);
    WddNodeHandle pIn2 = wddManager.addTerm(pTermIn2);
    WddNodeHandle p4b1 = wddManager.addTerm(pTerm4b1);
    WddNodeHandle p4b0 = wddManager.addTerm(pTerm4b0);
    WddNodeHandle pReg = wddManager.addTerm(pTermReg);
    WddNodeHandle pRegMultIn1 = wddManager.addTerm(pTermRegMultIn1);
    WddNodeHandle pRegMult2 = wddManager.addTerm(pTermRegMult2);
    WddNodeHandle pRegPlusIn2 = wddManager.addTerm(pTermRegPlusIn2);
    WddNodeHandle pRegDiv2 = wddManager.addTerm(pTermRegDiv2);
    WddNodeHandle pIn1Eq0 = wddManager.addTerm(pTermIn1Eq0);
//    WddNodeHandle pIn1Neq0 = wddManager.addTerm(pTermIn1Neq0);
    WddNodeHandle pIn1Neq0 = wddManager.makeNeg(pIn1Eq0);
    WddNodeHandle pIn2Neq0 = wddManager.addTerm(pTermIn2Neq0);
    WddNodeHandle pRegEq1 = wddManager.addTerm(pTermRegEq1);
//    WddNodeHandle pRegNeq1 = wddManager.addTerm(pTermRegNeq1);
    WddNodeHandle pRegNeq1 = wddManager.makeNeg(pRegEq1);

    WddNodeHandle pStateEqC = wddManager.addTerm(pTermStateEqC);
    WddNodeHandle pStateEqB = wddManager.addTerm(pTermStateEqB);
    WddNodeHandle pStateEqA = wddManager.addTerm(pTermStateEqA);
    WddNodeHandle pReset = wddManager.addTerm(pTermReset);


    WddNodeHandle pState_1 = pA;
    WddNodeHandle pState_2 = pB;
    WddNodeHandle pState_3 = pC;
    WddNodeHandle pState_4 = wddManager.makeBasicBlockIfThenElse(pIn1Neq0, pState_2, pState_3);
    assertEqual("ite(in1 == 0, C, B)", pState_4->toString(wddManager), "Test to string");
    {
    WddNodeHandle pState_4_2 = wddManager.makeBasicBlockIfThen(pIn1Neq0, pState_2);
    assertEqual("ite(in1 == 0, FALSE, B)", pState_4_2->toString(wddManager), "Test to string");
    }
    WddNodeHandle pState_5 = pA;
    WddNodeHandle pState_6 = pB;
    WddNodeHandle pState_7 = wddManager.makeBasicBlockIfThenElse(pRegNeq1, pState_5, pState_6);
    assertEqual("ite(reg = 1, B, A)", pState_7->toString(wddManager), "Test to string");
    WddNodeHandle pState_8 = pC;
    WddNodeHandle pState_9 = pA;
    WddNodeHandle pState_10 = wddManager.makeBasicBlockIfThenElse(pIn2Neq0, pState_8, pState_9);
    assertEqual("ite(in2 != 0, C, A)", pState_10->toString(wddManager), "Test to string");
    WddNodeHandle pState_11 = wddManager.makeBasicBlockIfThen(pStateEqC, pState_10);
    assertEqual("ite(stateEqC, ite(in2 != 0, C, A), FALSE)", pState_11->toString(wddManager), "Test to string");
    WddNodeHandle pState_12 = wddManager.makeBasicBlockIfThenElse(pStateEqB, pState_7, pState_11);
    assertEqual("ite(stateEqB, ite(reg = 1, B, A), ite(stateEqC, ite(in2 != 0, C, A), FALSE))", pState_12->toString(wddManager), "Test to string");
    WddNodeHandle pState_13 = wddManager.makeBasicBlockIfThenElse(pStateEqA, pState_4, pState_12);
    assertEqual("ite(stateEqA, ite(in1 == 0, C, B), ite(stateEqB, ite(reg = 1, B, A), ite(stateEqC, ite(in2 != 0, C, A), FALSE)))", pState_13->toString(wddManager), "Test to string");
    WddNodeHandle pState_14 = wddManager.makeBasicBlockIfThenElse(pReset, pState_1, pState_13);
    assertEqual("ite(reset, A, ite(stateEqA, ite(in1 == 0, C, B), ite(stateEqB, ite(reg = 1, B, A), ite(stateEqC, ite(in2 != 0, C, A), FALSE))))", pState_14->toString(wddManager), "Test to string");
    WddNodeHandle pState_In1Neq0 = wddManager.makeAnd(pState_14, pIn1Neq0);
    assertEqual("ite(reset, ite(in1 == 0, FALSE, A), ite(stateEqA, ite(in1 == 0, FALSE, B), ite(stateEqB, ite(reg = 1, ite(in1 == 0, FALSE, B), ite(in1 == 0, FALSE, A)), ite(stateEqC, ite(in2 != 0, ite(in1 == 0, FALSE, C), ite(in1 == 0, FALSE, A)), FALSE))))", pState_In1Neq0->toString(wddManager), "Test to string");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_efsm();
    return 0;
}
