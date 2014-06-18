#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

#include "nstl/for_each/ForEach.h"
#include "nstl/shared_ptr/SharedPtr.h"

template <class T>
struct GraphComponentToString {
    static std::string toString(const T & value) {
        return value.toString(); 
    }
    static std::string toDotString(const T & value) {
        return value.toDotString();
    }

};

// TODO: move the template specialization function to cpp
template <> struct GraphComponentToString<int> {
//    static std::string toString(const int & value);
#if 1
    static std::string toString(const int & value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
    }
#endif
    static std::string toDotString(const int & value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
    }
};

template <> struct GraphComponentToString<std::string> {
    static std::string toString(const std::string & value) {
    return value;
    }
    static std::string toDotString(const std::string & value) {
    return value;
    }
};
#if 0
// TODO: try to remove redundant declaration warning
template <>
std::string GraphComponentToString<int>::toDotString(const int & x); 

template <>
std::string GraphComponentToString<std::string>::toDotString(const std::string & x); 




template <>
std::string GraphComponentToString<int>::toString(const int & x); 
template <>
std::string GraphComponentToString<std::string>::toString(const std::string & x); 

#endif

template <const char* _ComponentSymbol, class _Value>
class GraphComponent {
public:
    typedef _Value value_type;
    typedef size_t id_type;
    value_type value;
private:
    id_type _id;
public:
    GraphComponent() : value(value_type()), _id(0) { } 
    GraphComponent(value_type val, id_type id)
      : value(val)
      , _id(id)
      { }

    const value_type & getValue() const { return value; }

    std::string getIdName() const { 
        std::stringstream ss;
        ss << _ComponentSymbol << getId();
        return ss.str();
    }

    bool operator == (const GraphComponent & rhs) const 
      { return (value == rhs.value); }

    bool operator < (const GraphComponent & rhs) const
      { return (value < rhs.value); }

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

template <class _Value>
class GraphEdge : public GraphComponent<kEdgeName, _Value> {
public:
    typedef GraphComponent<kEdgeName, _Value> graph_component_type;
    typedef typename graph_component_type::id_type id_type;
    typedef typename graph_component_type::value_type value_type;
    std::pair<id_type, id_type> _statePair;

    GraphEdge(value_type val, id_type id, id_type fromStateId, id_type toStateId)
      : graph_component_type(val, id)
      , _statePair(std::make_pair(fromStateId, toStateId))
      { }

    std::pair<id_type, id_type> getStatePair() const
      { return _statePair; }

};


template <class _StateValue, class _EdgeValue>
class Graph {
public:
    typedef _StateValue state_value_type;
    typedef _EdgeValue edge_value_type;

    typedef GraphComponent<kStateName, state_value_type> state_type;
    typedef GraphEdge<edge_value_type> edge_type;

    typedef typename state_type::id_type state_id_type;
    typedef typename edge_type::id_type edge_id_type;

    typedef state_type & state_reference_type;
    typedef const state_reference_type const_state_reference_type;
    typedef edge_type & edge_reference_type;
    typedef const edge_reference_type const_edge_reference_type;

    typedef SharedPtr<state_type> state_handle_type;
    typedef SharedPtr<edge_type> edge_handle_type;

    typedef const SharedPtr<state_type> const_state_handle_type;
    typedef const SharedPtr<edge_type> const_edge_handle_type;
    
    typedef std::vector<state_handle_type> state_handle_container_type;
    typedef std::vector<edge_handle_type> edge_handle_container_type;

private:
    typedef std::map<state_handle_type, state_id_type> state_id_map_type;
    typedef std::map<edge_handle_type, edge_id_type> edge_id_map_type;
    typedef typename state_id_map_type::iterator state_id_map_iterator;
    typedef typename edge_id_map_type::iterator edge_id_map_iterator;

    state_handle_container_type _containerStateHandle;
    edge_handle_container_type _containerEdge;

    state_id_map_type _mapStateId;

    typedef std::map<state_id_type, edge_id_type> connection_map_inner_map_type;
    typedef std::map<state_id_type, connection_map_inner_map_type > connection_map_type;

    connection_map_type _mapConnect;
public:
    Graph() { }

    state_handle_type addState(state_value_type stateValue) {
        state_id_type id = 0;
        state_id_map_iterator it;

        id = _containerStateHandle.size();
        state_handle_type pValue = state_handle_type(state_type(stateValue, id));
        if ((it = _mapStateId.find(pValue)) != _mapStateId.end()) {
            id = it->second;
        } else {
            state_handle_type pState = state_handle_type(state_type(stateValue, id));
            _containerStateHandle.push_back(pState);
            _mapStateId.insert(std::make_pair(pState, pState->getId()));
        }

        return _containerStateHandle[id];
    }

    edge_handle_type addEdge(state_id_type fromStateId, state_id_type toStateId, edge_value_type edgeValue) {
        edge_id_type id = _containerEdge.size();

        edge_type edge(edgeValue, id, fromStateId, toStateId);
        edge_handle_type pEdge = edge_handle_type(edge);
        _containerEdge.push_back(pEdge);
        if ( _mapConnect.find(fromStateId) != _mapConnect.end() 
          && _mapConnect[fromStateId].find(toStateId) != _mapConnect[fromStateId].end()) {
            std::cerr << "*Warning: " << "already insert at " << fromStateId << " , " << toStateId << std::endl;
        }
        _mapConnect[fromStateId][toStateId] = id;

        return _containerEdge.back();
    }

    edge_handle_type addEdge(state_handle_type pFrom, state_handle_type pTo, edge_value_type edgeValue) {
        state_id_type fromStateId = pFrom->getId();
        state_id_type toStateId = pTo->getId();

        return addEdge(fromStateId, toStateId, edgeValue);
    }

    state_handle_container_type& getStateHandleContainer() { return _containerStateHandle; }
    edge_handle_container_type& getEdgeHandleContainer() { return _containerEdge; }

    std::map<state_id_type, edge_id_type>& getConnectionMap(state_id_type FromId) {
        if(_mapConnect.find(FromId) != _mapConnect.end())
            return _mapConnect[FromId];
        else
            std::cerr << "*Warning: " << "no such connection in this graph." << std::endl;
        assert(0);
    }

    edge_handle_type getEdgeHandle(state_handle_type pFromState, state_handle_type pToState) {
        state_id_type fromStateId = pFromState->getId();
        state_id_type toStateId = pToState->getId();
        return getEdgeHandle(fromStateId, toStateId);
    }

    edge_handle_type getEdgeHandle(state_id_type fromStateId, state_id_type toStateId) 
      { return _containerEdge[getEdgeIdHelper(fromStateId, toStateId)]; }

    const_edge_handle_type getEdgeHandle(state_id_type fromStateId, state_id_type toStateId) const 
      { return _containerEdge[getEdgeIdHelper(fromStateId, toStateId)]; }

    
    const state_handle_container_type& getStateHandleContainer() const { return _containerStateHandle; }
    const edge_handle_container_type& getEdgeHandleContainer() const { return _containerEdge; }

    void writeDotFile(std::string outputDotFileName) const {
        std::ofstream fout(outputDotFileName.c_str());

        if (!fout.good()) {
            std::cerr << "*Error: " << "open file error : " << outputDotFileName << std::endl;
            assert(0);
        }

        fout << toDotString();
        fout.close();
    }

       
    std::string toString() const {
        std::stringstream ss;
        static const std::string arrow(" -> ");

        FOR_EACH(pState, getStateHandleContainer()) {
            ss << "[(state " << pState->getIdName() << ") : " << GraphComponentToString<state_value_type>::toString(pState->getValue()) << "]\n";
        }

        FOR_EACH(pair1, _mapConnect) {
            state_id_type fromId = pair1.first;
            state_handle_type pFromState = _containerStateHandle[fromId];

            FOR_EACH(pair2, pair1.second) {
                state_id_type toId = pair2.first;
                state_handle_type pToState = _containerStateHandle[toId];
                
                edge_id_type edgeId = pair2.second;
                edge_handle_type pEdge = _containerEdge[edgeId];

                ss << "[(edge : " << pEdge->getIdName() << ") (" << pFromState->getIdName() << arrow << pToState->getIdName() << ") : ";
                ss << GraphComponentToString<edge_value_type>::toString(pEdge->getValue()) << "]\n";
            }
        }

        return ss.str();
     }

private:
    edge_id_type getEdgeIdHelper(state_id_type fromStateId, state_id_type toStateId) {
        typename connection_map_type::iterator it1;
        if ((it1 = _mapConnect.find(fromStateId)) == _mapConnect.end())
            std::cerr << "*Warning: no such connect - from_state_id : " << fromStateId << " to_state_id : " << toStateId << std::endl;
        
        typename connection_map_inner_map_type::iterator it2;
        if ((it2 = it1->second.find(toStateId)) == it1->second.end()) 
            std::cerr << "*Warning: no such connect in inner map - from_state_id : " << fromStateId << " to_state_id : " << toStateId << std::endl;

        return it2->second;
    }

    std::string toDotString() const {
        std::string indent("   ");
        static const std::string arrow(" -> ");
        std::stringstream ss;
        ss << "digraph Protocol {\n";
        ss << indent << "rankdir = TD;\n";
        ss << indent << "node [ shape = circle, color = lightblue, fontname = \"Helvetica\"];\n";

        FOR_EACH(pState, getStateHandleContainer()) {
            ss << indent << pState->getIdName() << " [label=\""
               << GraphComponentToString<state_value_type>::toDotString(pState->getValue()) << "\"]\n";
        }

        FOR_EACH(pair1, _mapConnect) {
            state_id_type fromId = pair1.first;
            state_handle_type pFromState = _containerStateHandle[fromId];

            FOR_EACH(pair2, pair1.second) {
                state_id_type toId = pair2.first;
                state_handle_type pToState = _containerStateHandle[toId];
                
                edge_id_type edgeId = pair2.second;
                edge_handle_type pEdge = _containerEdge[edgeId];

                ss << indent << pFromState->getIdName() << arrow << pEdge->getIdName() << ";\n";
                ss << indent << pEdge->getIdName() << arrow << pToState->getIdName() << ";\n";
                ss << indent << pEdge->getIdName() << " [shape=record, color=red, height=.08, fontsize=11, label=\""
                   << GraphComponentToString<edge_value_type>::toDotString(pEdge->getValue()) << "\"]\n\n";
            }
        }

        ss << "\n}\n";
        return ss.str();
    }

    
};


#endif // GRAPH_H
