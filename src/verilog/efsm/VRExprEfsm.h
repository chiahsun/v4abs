#ifndef VREXPR_EFSM_H
#define VREXPR_EFSM_H

#include "Efsm.h"
#include "verilog/vrexpr/VRExprExpression.h"
#include "verilog/vrexpr/VRExprAssignment.h"

class VRExprEfsm {
public: 
    typedef Efsm<std::string, VRExprExpression, std::vector<VRExprAssignment> > efsm_impl_type;

    typedef efsm_impl_type::enable_function_type enable_function_type;
    typedef efsm_impl_type::update_function_type update_function_type;
    
    typedef efsm_impl_type::edge_type edge_type;
    typedef edge_type::enable_function_handle_type enable_function_handle_type;
    typedef edge_type::update_function_handle_type update_function_handle_type;


    typedef efsm_impl_type::state_value_type state_value_type;
    typedef efsm_impl_type::edge_value_type edge_value_type;
    typedef efsm_impl_type::state_handle_type state_handle_type;
    typedef efsm_impl_type::edge_handle_type edge_handle_type;
    typedef efsm_impl_type::state_handle_container_type state_handle_container_type;
    typedef efsm_impl_type::edge_handle_container_type edge_handle_container_type;

    typedef efsm_impl_type::state_id_type state_id_type;
    typedef efsm_impl_type::edge_id_type edge_id_type;
private:
    efsm_impl_type _efsm;

public:
    VRExprEfsm() { }
    
    state_handle_type addState(state_value_type stateValue) 
      { return _efsm.addState(stateValue); }

    edge_handle_type addEdge(state_handle_type pStateFrom, state_handle_type pStateTo, enable_function_type enable, update_function_type update = update_function_type()) {
        edge_type edge(enable, update);
        return _efsm.addEdge(pStateFrom, pStateTo, enable, update);
    }

    edge_handle_type addEdge(state_id_type fromStateId, state_id_type toStateId, enable_function_type enable, update_function_type update = update_function_type()) {
        return _efsm.addEdge(fromStateId, toStateId, enable, update);
    }

    std::string toString() const
      { return _efsm.toString(); }
    
    void writeDotFile(const std::string & dotOutputFilename)
      { return _efsm.writeDotFile(dotOutputFilename); }
};

#endif // VREXPR_EFSM_H
