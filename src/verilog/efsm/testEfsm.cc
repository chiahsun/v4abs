#include "test/UnitTest.h"
#include "VRExprEfsm.h"

void test_add_edge() {
    VRExprModule module(VRExprIdentifier("TOP"));
    VRExprEfsm efsm(module);
    VRExprEfsm::state_handle_type pState0 = efsm.addState("S0");
    VRExprEfsm::state_handle_type pState1 = efsm.addState("S1");
    VRExprAssignment assign1 = VRExprAssignment(makeIdentifier("reg_a"), makeUnsignedNumber(0));
    VRExprAssignment assign2 = VRExprAssignment(makeIdentifier("wa"), makeUnsignedNumber(11));
    VRExprEfsm::edge_handle_type pEdgeRst = efsm.addEdge(pState0, pState1
                                                        , makeIdentifier("rst"));
    pEdgeRst->value.getUpdateFunctionHandle()->addAssignment(assign1);
    pEdgeRst->value.getUpdateFunctionHandle()->addAssignment(assign2);
    
    assertEqual(
    "[(state State0) : S0]\n"
    "[(state State1) : S1]\n"
    "[(edge : Edge0) (State0 -> State1) : \n"
    "Enable: rst\n"
    "Update:\n"
    "  always @ (0)\n"
    "       + (rhs_terminals 0)\n"
    "       + (mux_terminals )\n"
    "       + (rhs_wdd_format 0)\n"
    "       - reg_a = 0\n"
    "  always @ (11)\n"
    "       + (rhs_terminals 11)\n"
    "       + (mux_terminals )\n"
    "       + (rhs_wdd_format 11)\n"
    "       - wa = 11\n"
    "Read:\n"
    "Write:\n"
    "Check:\n"
    "\n"
    "]\n"
                , efsm.toString(), "Test to string");


    efsm.writeDotFile("wdd_efsm.dot");

    pEdgeRst->value.getEnableFunctionHandle()->operator =(makeIdentifier("en"));
    
    assertEqual(
    "[(state State0) : S0]\n"
    "[(state State1) : S1]\n"
    "[(edge : Edge0) (State0 -> State1) : \n"
    "Enable: en\n"
    "Update:\n"
    "  always @ (0)\n"
    "       + (rhs_terminals 0)\n"
    "       + (mux_terminals )\n"
    "       + (rhs_wdd_format 0)\n"
    "       - reg_a = 0\n"
    "  always @ (11)\n"
    "       + (rhs_terminals 11)\n"
    "       + (mux_terminals )\n"
    "       + (rhs_wdd_format 11)\n"
    "       - wa = 11\n"
    "Read:\n"
    "Write:\n"
    "Check:\n"
    "\n"
    "]\n"
                , efsm.toString(), "Test to string");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_add_edge();
    return 0;
}
