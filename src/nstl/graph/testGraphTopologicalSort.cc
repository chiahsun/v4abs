#include "Graph.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"


static const bool verbose = false;

void test_topological_sort() {
    Graph<int, int> graph;
    Graph<int, int>::state_handle_type pState[20];

    int stateArray[8] =
//        {7, 5, 3, 11, 8, 2, 9, 10};
        {2, 10, 9, 11, 8, 7, 3, 5};
    for (unsigned int i = 0; i < 8; ++i) {
        graph.addState(stateArray[i]);
        if (verbose)
            LOG(INFO) << "Add state " << i;
        pState[stateArray[i]] = graph.addState(stateArray[i]);
        if (verbose)
            LOG(INFO) << "Add state id " << i << " with id " << pState[stateArray[i]]->getId();
        assert(pState[stateArray[i]]->getId() == i);
    }
#if 0
    CONST_FOR_EACH(pState1, graph.getStateHandleContainer()) {
        pState[pState1->getId()] = pState1;
    }
#endif
    int edge[9][2] = 
    { {7, 11}, {7, 8}, {5, 11}, {3, 8}, {3, 10}
    , {11, 2}, {11, 9}, {11, 10}, {8, 9}};

    for (int i = 0; i < 9; ++i) {
        if (verbose) {
            LOG(INFO) << "Add edge from state  " << edge[i][0];
            LOG(INFO) << "Add edge from state with id = " << pState[edge[i][0]]->getId();
            LOG(INFO) << "Add edge to state  " << edge[i][1];
            LOG(INFO) << "Add edge to state with id =  " << pState[edge[i][1]]->getId();
        }
        assert(pState[edge[i][0]].valid());
        assert(pState[edge[i][1]].valid());
        graph.addEdge(pState[edge[i][0]], pState[edge[i][1]], 0 /* dummy */);
    }


    assertEqual("[(state State0) : 2]\n"
                "[(state State1) : 10]\n"
                "[(state State2) : 9]\n"
                "[(state State3) : 11]\n"
                "[(state State4) : 8]\n"
                "[(state State5) : 7]\n"
                "[(state State6) : 3]\n"
                "[(state State7) : 5]\n"
                "[(edge : Edge5) (State3 -> State0) : 0]\n"
                "[(edge : Edge7) (State3 -> State1) : 0]\n"
                "[(edge : Edge6) (State3 -> State2) : 0]\n"
                "[(edge : Edge8) (State4 -> State2) : 0]\n"
                "[(edge : Edge0) (State5 -> State3) : 0]\n"
                "[(edge : Edge1) (State5 -> State4) : 0]\n"
                "[(edge : Edge4) (State6 -> State1) : 0]\n"
                "[(edge : Edge3) (State6 -> State4) : 0]\n"
                "[(edge : Edge2) (State7 -> State3) : 0]\n", graph.toString(), "Test graph to string");
  
    std::vector<Graph<int, int>::state_handle_type> vecTopologicalOrderStateHandle = graph.topologicalSort(); 
    std::stringstream ss;

    CONST_FOR_EACH(pState1, vecTopologicalOrderStateHandle) {
        ss << pState1->getId() << " ";
    }
    assertEqual("5 6 7 4 3 0 1 2 ", ss.str(), "Test topolocial sort order");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();

}

int main() {
    test_topological_sort();
    return 0;
}
