#ifndef EFSM_H
#define EFSM_H

#include <vector>

#include "nstl/graph/Graph.h"
#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/for_each/ForEach.h"

template <class _EnableFunction, class _UpdateFunction>
class EfsmEdge {
public:
    typedef _EnableFunction enable_function_type;
    typedef _UpdateFunction update_function_type;

    typedef SharedPtr<enable_function_type> enable_function_handle_type;
    typedef SharedPtr<update_function_type> update_function_handle_type;
private:
    enable_function_handle_type _pEnableFunction;
    update_function_handle_type _pUpdateFunction;
public:
    EfsmEdge(enable_function_type enable)
      : _pEnableFunction(enable_function_handle_type(enable))
      , _pUpdateFunction(update_function_handle_type(update_function_type()))
      { }

    EfsmEdge(enable_function_type enable, update_function_type update)
      : _pEnableFunction(enable_function_handle_type(enable))
      , _pUpdateFunction(update_function_handle_type(update))
      { }

    enable_function_handle_type getEnableFunctionHandle() 
      { return _pEnableFunction; }
    update_function_handle_type getUpdateFunctionHandle()
      { return _pUpdateFunction; }
    
    const enable_function_handle_type getEnableFunctionHandle() const
      { return _pEnableFunction; }
    const update_function_handle_type getUpdateFunctionHandle() const
      { return _pUpdateFunction; }



    std::string toString() const {
        std::stringstream ss;
        ss << "\nEnable: " << _pEnableFunction->toString() << "\n"
           << "Update:\n";
        ss << _pUpdateFunction->toString() << "\n";
        return ss.str(); 
    }
    
    std::string toDotString() const {
        std::stringstream ss;
        ss << _pEnableFunction->toString() << "\\n |";
        ss << _pUpdateFunction->toString() << "\\n";
        return ss.str(); 
    }


    friend std::ostream& operator << (std::ostream & os, const EfsmEdge & rhs) {
        return os << rhs.toDotString();
    }
};

template <class _StateValue, class _EnableFunction, class _UpdateFunction>
class Efsm {
public:
    typedef _StateValue state_type;
    typedef _EnableFunction enable_function_type;
    typedef _UpdateFunction update_function_type;

    typedef EfsmEdge<enable_function_type, update_function_type> edge_type;
    typedef typename edge_type::enable_function_handle_type enable_function_handle_type;
    typedef typename edge_type::update_function_handle_type update_function_handle_type;

    typedef Graph<state_type, edge_type> graph_type;

private:
    graph_type _graph;

public:
    typedef typename graph_type::state_value_type state_value_type;
    typedef typename graph_type::edge_value_type edge_value_type;
    typedef typename graph_type::state_handle_type state_handle_type;
    typedef typename graph_type::edge_handle_type edge_handle_type;
    typedef typename graph_type::state_handle_container_type state_handle_container_type;
    typedef typename graph_type::edge_handle_container_type edge_handle_container_type;

    typedef typename graph_type::state_id_type state_id_type;
    typedef typename graph_type::edge_id_type edge_id_type;

public:
    Efsm() { }

    state_handle_type addState(state_value_type stateValue) {
        return _graph.addState(stateValue);
    }

    edge_handle_type addEdge(state_handle_type pStateFrom, state_handle_type pStateTo, enable_function_type enable, update_function_type update) {
        edge_type edge(enable, update);
        return _graph.addEdge(pStateFrom, pStateTo, edge);
    }

    edge_handle_type addEdge(state_id_type fromStateId, state_id_type toStateId, enable_function_type enable, update_function_type update) {
        edge_type edge(enable, update);
        return _graph.addEdge(fromStateId, toStateId, edge);
    }

    std::string toString() const
      { return _graph.toString(); }

    void writeDotFile(const std::string & dotOutputFilename) 
      { return _graph.writeDotFile(dotOutputFilename); }

    state_handle_container_type& getStateHandleContainer()
      { return _graph.getStateHandleContainer(); }

    edge_handle_container_type& getEdgeHandleContainer()
      { return _graph.getEdgeHandleContainer(); }
};

#endif // EFSM_H
