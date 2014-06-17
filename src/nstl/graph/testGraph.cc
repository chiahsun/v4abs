#include "Graph.h"
#include "test/UnitTest.h"
#include "nstl/for_each/ForEach.h"
#include <string>


void test_graph_component() {
    GraphComponent<kStateName, std::string> state("hello", 0);
    assertEqual(0, state.getId(), "Test state get id");
    assertEqual("hello", state.getValue(), "Test state get value");
    assertEqual("State0", state.getIdName(), "Test state get state id name");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST(); 
}
void test_graph() {
    Graph<std::string, int> graph;
    Graph<std::string, int>::state_handle_type pStateDefault;
    Graph<std::string, int>::state_handle_type pState1 = graph.addState("hello");
    Graph<std::string, int>::state_handle_type pState2 = graph.addState("world");

    assertEqual("hello", pState1->getValue(), "Test get value");
    assertEqual(0, pState1->getId(), "Test get id");
    assertEqual("world", pState2->getValue(), "Test get value");
    assertEqual(1, pState2->getId(), "Test get id");

    Graph<std::string, int>::edge_handle_type pEdge1 = graph.addEdge(pState1, pState2, 20);
    assertEqual(20, pEdge1->getValue(), "Test get value");
    assertEqual(0, pEdge1->getId(), "Test get id");

    assertEqual("[(state State0) : hello]\n"
                "[(state State1) : world]\n"
                "[(edge : Edge0) (State0 -> State1) : 20]\n", graph.toString(), "Test to string");
    graph.writeDotFile("graph_test.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_graph_modification() {
    Graph<std::string, int> graph;
    Graph<std::string, int>::state_handle_type pState1 = graph.addState("hello");
    Graph<std::string, int>::state_handle_type pState2 = graph.addState("world");
    Graph<std::string, int>::state_handle_type pState3 = graph.addState("!!");
    
    Graph<std::string, int>::edge_handle_type pEdge1 = graph.addEdge(pState1, pState2, 20);
    pEdge1->value += 1;
    Graph<std::string, int>::edge_handle_type pEdge2 = graph.addEdge(pState2, pState3, 33);
    assertEqual(21, pEdge1->getValue(), "Test get value");
    assertEqual(0, pEdge1->getId(), "Test get id");
    assertEqual(33, pEdge2->getValue(), "Test get value");
    assertEqual(1, pEdge2->getId(), "Test get id");

    graph.getEdgeHandle(0, 1)->value += 1;

    assertEqual(22, pEdge1->getValue(), "Test get value");
    assertEqual(0, pEdge1->getId(), "Test get id");
    assertEqual(33, pEdge2->getValue(), "Test get value");
    assertEqual(1, pEdge2->getId(), "Test get id");

    FOR_EACH(pEdge, graph.getEdgeHandleContainer()) {
        pEdge->value += 4;
//        pEdge->getValue() += 4; // should be invalid
    }
    assertEqual(26, pEdge1->getValue(), "Test get value");
    assertEqual(0, pEdge1->getId(), "Test get id");
    assertEqual(37, pEdge2->getValue(), "Test get value");
    assertEqual(1, pEdge2->getId(), "Test get id");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_graph_component();
    test_graph();
    test_graph_modification();
    return 0;
}
