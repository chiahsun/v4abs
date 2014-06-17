#include "VRExprEfsm.h"


VRExprEfsm::VRExprEfsm() { }
    
VRExprEfsm::state_handle_type 
VRExprEfsm::addState(state_value_type stateValue) 
  { return _efsm.addState(stateValue); }

VRExprEfsm::edge_handle_type 
VRExprEfsm::addEdge(state_handle_type pStateFrom, state_handle_type pStateTo, enable_function_type enable, update_function_type update) {
    edge_type edge(enable, update);
    return _efsm.addEdge(pStateFrom, pStateTo, enable, update);
}

VRExprEfsm::edge_handle_type 
VRExprEfsm::addEdge(state_id_type fromStateId, state_id_type toStateId, enable_function_type enable, update_function_type update) 
  { return _efsm.addEdge(fromStateId, toStateId, enable, update); }

std::string VRExprEfsm::toString() const
  { return _efsm.toString(); }
    
void VRExprEfsm::writeDotFile(const std::string & dotOutputFilename)
  { return _efsm.writeDotFile(dotOutputFilename); }
