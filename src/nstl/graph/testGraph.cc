#include "Graph.h"
#include "test/UnitTest.h"

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
    Graph<std::string, int>::state_type state_default;
    Graph<std::string, int>::state_type state1 = graph.addState("hello");
    Graph<std::string, int>::state_type state2 = graph.addState("world");

#if 1 
    assertEqual("hello", state1.getValue(), "Test get value");
    assertEqual(0, state1.getId(), "Test get id");
    assertEqual("world", state2.getValue(), "Test get value");
    assertEqual(1, state2.getId(), "Test get id");

    Graph<std::string, int>::edge_type edge1 = graph.addEdge(state1, state2, 20);
    assertEqual(20, edge1.getValue(), "Test get value");
    assertEqual(0, edge1.getId(), "Test get id");

    graph.writeDotFile("graph_test.dot");
#endif
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_graph_component();
    test_graph();
    return 0;
}
