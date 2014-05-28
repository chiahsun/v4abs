#include "test/UnitTest.h"
#include "Term.h"
#include "WddManager.h"

// const static bool isWriteFile = false;
const static bool isWriteFile = true;

void test_efsm() {
    TermHandle pTermReset = TermHandle(Term("reset"));
    TermHandle pTerm1 = TermHandle(Term("1"));
    TermHandle pTerm0 = TermHandle(Term("0"));

    TermHandle pTermState = TermHandle(Term("state"));
    TermHandle pTermA = TermHandle(Term("A"));
    TermHandle pTermB = TermHandle(Term("B"));
    TermHandle pTermC = TermHandle(Term("C"));
    TermHandle pTermStateEqA = TermHandle(Term("state==A"));
    TermHandle pTermStateEqB = TermHandle(Term("state==B"));
    TermHandle pTermStateEqC = TermHandle(Term("state==C"));

    TermHandle pTermIn1 = TermHandle(Term("in1"));
    TermHandle pTermIn2 = TermHandle(Term("in2"));
    TermHandle pTermIn1Neq0 = TermHandle(Term("in1!=0"));
    TermHandle pTermIn1Eq0 = TermHandle(Term("in1==0"));
    TermHandle pTermRegEq1 = TermHandle(Term("reg==1"));
    TermHandle pTermRegNeq1 = TermHandle(Term("reg!=1"));
    TermHandle pTermIn2Neq0 = TermHandle(Term("in2!=0"));


    TermHandle pTermOut1 = TermHandle(Term("out1"));
    TermHandle pTermOut2 = TermHandle(Term("out2"));

    TermHandle pTermReg = TermHandle(Term("reg"));

    TermHandle pTermRegMult2 = TermHandle(Term("reg*2"));
    TermHandle pTermRegMultIn1 = TermHandle(Term("reg*in1"));
    TermHandle pTermRegAddIn2 = TermHandle(Term("reg+in2"));
    TermHandle pTermRegDiv2 = TermHandle(Term("reg/2"));


    WddManager<TermHandle> wddManager;

    typedef WddManager<TermHandle>::WddNodeHandle WddNodeHandle;

    WddNodeHandle pReg = wddManager.addTerm(pTermReg);
    WddNodeHandle pRegMult2 = wddManager.addTerm(pTermRegMult2);
    WddNodeHandle pRegMultIn1 = wddManager.addTerm(pTermRegMultIn1);
    WddNodeHandle pRegAddIn2 = wddManager.addTerm(pTermRegAddIn2);
    WddNodeHandle pRegDiv2 = wddManager.addTerm(pTermRegDiv2);
    /**
     * Later, syntax tree will do reduction first,
     * We can only see B == C or B != C, one of which.
     */
    WddNodeHandle pRegEq1 = wddManager.addTerm(pTermRegEq1);
    WddNodeHandle pRegNeq1 = wddManager.makeNeg(pRegEq1);
//    WddNodeHandle pRegNeq1 = wddManager.addTerm(pTermRegNeq1);


    WddNodeHandle pIn1 = wddManager.addTerm(pTermIn1);
    WddNodeHandle pIn2 = wddManager.addTerm(pTermIn2);
    WddNodeHandle pC = wddManager.addTerm(pTermC);
    WddNodeHandle pB = wddManager.addTerm(pTermB);
    WddNodeHandle pA = wddManager.addTerm(pTermA);
    WddNodeHandle pState = wddManager.addTerm(pTermState);
    WddNodeHandle p0 = wddManager.addTerm(pTerm0);
    WddNodeHandle p1 = wddManager.addTerm(pTerm1);
    WddNodeHandle pIn1Eq0 = wddManager.addTerm(pTermIn1Eq0);
//    WddNodeHandle pIn1Neq0 = wddManager.addTerm(pTermIn1Neq0);
    WddNodeHandle pIn1Neq0 = wddManager.makeNeg(pIn1Eq0);
    WddNodeHandle pIn2Neq0 = wddManager.addTerm(pTermIn2Neq0);
    WddNodeHandle pStateEqA = wddManager.addTerm(pTermStateEqA);
    WddNodeHandle pStateEqB = wddManager.addTerm(pTermStateEqB);
    WddNodeHandle pStateEqC = wddManager.addTerm(pTermStateEqC);
    WddNodeHandle pReset = wddManager.addTerm(pTermReset);

    WddNodeHandle pStateEqANeqStateEqB = wddManager.makeNeq(pStateEqA, pStateEqB);
    WddNodeHandle pStateEqANeqStateEqC = wddManager.makeNeq(pStateEqA, pStateEqC);
    WddNodeHandle pStateEqBNeqStateEqC = wddManager.makeNeq(pStateEqB, pStateEqC);
    WddNodeHandle pStateConstrraint = wddManager.makeAnd(pStateEqANeqStateEqB, wddManager.makeAnd(pStateEqANeqStateEqC, pStateEqBNeqStateEqC));

    WddNodeHandle pNextReg, pNextOut1, pNextOut2, pNextState;
    // reg
    {
        WddNodeHandle pB3 = wddManager.ite(pIn1Neq0, pIn1, pIn2);
        WddNodeHandle pB1 = wddManager.makeAnd(pStateEqB, pRegMultIn1);
        WddNodeHandle pB9 = wddManager.makeAnd(pIn2Neq0, pRegAddIn2);
        WddNodeHandle pB2 = wddManager.makeAnd(pStateEqC, pB9);
        WddNodeHandle pB1_and_B2 = 
            wddManager.ite(pStateEqB, pB1, pB2);

        WddNodeHandle pB0 = wddManager.ite(pStateEqA, pB3, pB1_and_B2);

        WddNodeHandle p = wddManager.makeAnd(wddManager.makeNeg(pReset), pB0);

        pNextReg = wddManager.makeAnd(p, pStateConstrraint);

        assertEqual("1 : reg\n"
                    "2 : reg*2\n"
                    "3 : reg*in1\n"
                    "4 : reg+in2\n"
                    "5 : reg/2\n"
                    "6 : reg==1\n"
                    "7 : in1\n"
                    "8 : in2\n"
                    "9 : C\n"
                    "10 : B\n"
                    "11 : A\n"
                    "12 : state\n"
                    "13 : 0\n"
                    "14 : 1\n"
                    "15 : in1==0\n"
                    "16 : in2!=0\n"
                    "17 : state==A\n"
                    "18 : state==B\n"
                    "19 : state==C\n"
                    "20 : reset\n", wddManager.stringOfTermOrder(), "Test string of term order");
        assertEqual("ite(reset, FALSE, ite(state==C, ite(state==B, FALSE, ite(state==A, FALSE, ite(in2!=0, reg+in2, FALSE))), ite(state==B, ite(state==A, FALSE, reg*in1), ite(state==A, ite(in1==0, in2, in1), FALSE))))", pNextReg->toString(wddManager), "Test to string");
        if (isWriteFile)
            pNextReg->writeDotFile("efsm_next_reg.dot");

        WddNodeHandle pNextReg_cofactor_PosReset = wddManager.getPosCofactor(pNextReg, pReset);
        WddNodeHandle pNextReg_cofactor_PosIn1Eq0 = wddManager.makeAnd(pNextReg, pIn1Eq0);
        assertEqual("FALSE", pNextReg_cofactor_PosReset->toString(wddManager), "Test to string");
        assertEqual("ite(reset, FALSE, ite(state==C, ite(state==B, FALSE, ite(state==A, FALSE, ite(in2!=0, ite(in1==0, reg+in2, FALSE), FALSE))), ite(state==B, ite(state==A, FALSE, ite(in1==0, reg*in1, FALSE)), ite(state==A, ite(in1==0, in2, FALSE), FALSE))))", pNextReg_cofactor_PosIn1Eq0->toString(wddManager), "Test to string");
        if (isWriteFile) {
            pNextReg_cofactor_PosReset->writeDotFile("efsm_next_reg_cofactor_pos_reset.dot");
            pNextReg_cofactor_PosIn1Eq0->writeDotFile("efsm_next_reg_cofactor_pos_in1eq0.dot");
        }
    }

    {
        WddNodeHandle pB3 = wddManager.ite(pIn1Neq0, p1, p0);
        WddNodeHandle pB5 = wddManager.ite(pRegEq1, p0, pReg);
        WddNodeHandle pB11 = wddManager.ite(pIn1Eq0, pReg, pRegDiv2);
        WddNodeHandle pB9 = wddManager.ite(pIn2Neq0, p1, pB11);
        WddNodeHandle pB2 = wddManager.makeAnd(pStateEqC, pB9);
        WddNodeHandle pB1 = wddManager.ite(pStateEqB, pB5, pB2);
        WddNodeHandle pB0 = wddManager.ite(pStateEqA, pB3, pB1);

        WddNodeHandle p = wddManager.makeAnd(wddManager.makeNeg(pReset), pB0);

        pNextOut1 = wddManager.makeAnd(p, pStateConstrraint);
        
        assertEqual("ite(reset, FALSE, ite(state==C, ite(state==B, FALSE, ite(state==A, FALSE, ite(in2!=0, 1, ite(in1==0, reg, reg/2)))), ite(state==B, ite(state==A, FALSE, ite(0, ite(reg==1, TRUE, reg), ite(reg==1, FALSE, reg))), ite(state==A, ite(in1==0, 0, 1), FALSE))))", pNextOut1->toString(wddManager), "Test to string");
        if (isWriteFile)
            pNextOut1->writeDotFile("efsm_next_out1.dot");
    }
//    WddNodeHandle p = wddManager.addTerm(pTerm);

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_efsm();
    return 0;
}
