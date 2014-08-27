#include "Graph.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"

void test_topological_sort() {
    Graph<int, int> graph;
    Graph<int, int>::state_handle_type pState[20];

    int stateArray[8] =
//        {7, 5, 3, 11, 8, 2, 9, 10};
        {2, 10, 9, 11, 8, 7, 3, 5};
    for (unsigned int i = 0; i < 8; ++i) {
        graph.addState(stateArray[i]);
        LOG(INFO) << "Add state " << i;
        pState[stateArray[i]] = graph.addState(stateArray[i]);
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
        LOG(INFO) << "Add edge from state  " << edge[i][0];
        LOG(INFO) << "Add edge from state with id = " << pState[edge[i][0]]->getId();
        LOG(INFO) << "Add edge to state  " << edge[i][1];
        LOG(INFO) << "Add edge to state with id =  " << pState[edge[i][1]]->getId();
        assert(pState[edge[i][0]].valid());
        assert(pState[edge[i][1]].valid());
        graph.addEdge(pState[edge[i][0]], pState[edge[i][1]], 0 /* dummy */);
    }


    assertEqual("", graph.toString(), "Test graph to string");
  
    std::vector<Graph<int, int>::state_handle_type> vecTopologicalOrderStateHandle = graph.topologicalSort(); 
    std::stringstream ss;

    CONST_FOR_EACH(pState, vecTopologicalOrderStateHandle) {
        ss << pState->getId() << " ";
    }
    assertEqual("", ss.str(), "Test topolocial sort order");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();

}

int main() {
    test_topological_sort();
    return 0;
}
