#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

#include "nstl/for_each/ForEach.h"


template <const char* _ComponentSymbol, class _Value>
class GraphComponent {
    typedef _Value value_type;
    typedef size_t id_type;

    value_type _value;
    id_type _id;
public:
    GraphComponent() : _value(value_type()), _id(0) { } 
    GraphComponent(value_type val, id_type id)
      : _value(val)
      , _id(id)
      { }

    value_type getValue() const { return _value; }

    std::string getIdName() const { 
        std::stringstream ss;
        ss << _ComponentSymbol << getId();
        return ss.str();
    }

    bool operator == (const GraphComponent & rhs) {
        return (_value == rhs._value);
    }

    id_type getId() const { return _id; }

    std::string toString() const {
        std::stringstream ss;
        ss << "(state (id " << getId() << ") (value " << getValue() << "))";
        return ss.str();
    }

    friend std::ostream & operator << (std::ostream & os, const GraphComponent & rhs) {
        return os << rhs.toString();
    }
};

// The trick
extern char kStateName[];
extern char kEdgeName[];

template <class _StateValue, class _EdgeValue>
class Graph {
public:
    typedef size_t id_type;
    typedef id_type state_id_type;
    typedef id_type edge_id_type;
    typedef _StateValue state_value_type;
    typedef _EdgeValue edge_value_type;

    typedef GraphComponent<kStateName, state_value_type> state_type;
    typedef GraphComponent<kEdgeName, edge_value_type> edge_type;

    typedef std::vector<state_type> state_container_type;
    typedef std::vector<edge_type> edge_container_type;

    typedef state_type* state_handle_type;
    typedef edge_type* edge_handle_type;
//    typedef typename state_container_type::iterator state_handle_type;
//    typedef typename edge_container_type::iterator edge_handle_type;

private:
    typedef std::map<state_value_type, state_id_type> state_id_map_type;
    typedef std::map<edge_value_type, edge_id_type> edge_id_map_type;
    typedef typename state_id_map_type::iterator state_id_map_iterator;
    typedef typename edge_id_map_type::iterator edge_id_map_iterator;

    state_container_type _containerState;
    edge_container_type _containerEdge;

    state_id_map_type _mapStateId;

    typedef std::map<state_id_type, std::map<state_id_type, edge_id_type> > connection_map_type;

    connection_map_type _mapConnect;
public:
    Graph() { }

    state_type addState(state_value_type stateValue) {
        state_id_type id = 0;
        state_id_map_iterator it;

        if ((it = _mapStateId.find(stateValue)) != _mapStateId.end()) {
            id = it->second;
        } else {
            id = _containerState.size();
            state_type state(stateValue, id);
            _containerState.push_back(state);
            _mapStateId.insert(std::make_pair(stateValue, state.getId()));
        }


        return _containerState[id];
    }

    edge_type addEdge(state_type from, state_type to, edge_value_type edgeValue) {
        edge_id_type id = _containerEdge.size();

        edge_type edge(edgeValue, id);
        _containerEdge.push_back(edge);
        if ( _mapConnect.find(from.getId()) != _mapConnect.end() 
          && _mapConnect[from.getId()].find(to.getId()) != _mapConnect[from.getId()].end()) {
            std::cerr << "*Warning: " << "already insert at " << from.getId() << " , " << to.getId() << std::endl;
        }
        _mapConnect[from.getId()][to.getId()] = id;

        return edge;
    }

    state_container_type& getStateContainer() { return _containerState; }
    edge_container_type& getEdgeContainer() { return _containerEdge; }
    
    const state_container_type& getStateContainer() const { return _containerState; }
    const edge_container_type& getEdgeContainer() const { return _containerEdge; }

    void writeDotFile(std::string outputDotFileName) const {
        std::ofstream fout(outputDotFileName.c_str());

        if (!fout.good()) {
            std::cerr << "*Error: " << "open file error : " << outputDotFileName << std::endl;
            assert(0);
        }

        fout << toDotFormat();
        fout.close();
    }

    std::string toDotFormat() const {
        std::string indent("   ");
        std::string arrow(" -> ");
        std::stringstream ss;
        ss << "digraph Protocol {\n";
        ss << indent << "rankdir = TD;\n";
        ss << indent << "node [ shape = circle, color = lightblue, fontname = \"Helvetica\"];\n";

        FOR_EACH(state, getStateContainer()) {
            ss << indent << state.getIdName() << " [label=\""
               << state.getValue() << "\"]\n";
        }

        FOR_EACH(pair1, _mapConnect) {
            state_id_type fromId = pair1.first;
            state_type fromState = _containerState[fromId];

            FOR_EACH(pair2, pair1.second) {
                state_id_type toId = pair2.first;
                state_type toState = _containerState[toId];
                
                edge_id_type edgeId = pair2.second;
                edge_type edge = _containerEdge[edgeId];

                ss << indent << fromState.getIdName() << arrow << edge.getIdName() << ";\n";
                ss << indent << edge.getIdName() << arrow << toState.getIdName() << ";\n";
                ss << indent << edge.getIdName() << " [shape=record, color=red, height=.08, fontsize=11, label=\""
                   << edge.getValue() << "\"]\n\n";
            }
        }

        ss << "\n}\n";
        return ss.str();
    }
};


#endif // GRAPH_H
