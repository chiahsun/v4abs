#ifndef VREXPR_EFSM_H
#define VREXPR_EFSM_H

#include "Efsm.h"
#include "verilog/vrexpr/VRExprExpression.h"
#include "verilog/vrexpr/VRExprAssignment.h"

class VRExprEfsmUpdate {
    std::vector<VRExprAssignment> _vecAssign;
    std::vector<VRExprExpression> _vecRead;
    std::vector<VRExprExpression> _vecWrite;
    std::vector<VRExprExpression> _vecCheck;
public:
    VRExprEfsmUpdate(); 
    VRExprEfsmUpdate( const std::vector<VRExprAssignment> vecAssign
                    , const std::vector<VRExprExpression> vecRead
                    , const std::vector<VRExprExpression> vecWrite
                    , const std::vector<VRExprExpression> vecCheck); 

    void addAssignment(const VRExprAssignment & assignment);
    void addRead(const VRExprExpression & read);
    void addWrite(const VRExprExpression & write);
    void addCheck(const VRExprExpression & check);

    std::vector<VRExprAssignment>& getAssignmentContainer();
    std::vector<VRExprExpression>& getReadContainer();
    std::vector<VRExprExpression>& getWriteContainer();
    std::vector<VRExprExpression>& getCheckContainer();

    const std::vector<VRExprAssignment>& getAssignmentContainer() const;
    const std::vector<VRExprExpression>& getReadContainer() const;
    const std::vector<VRExprExpression>& getWriteContainer() const;
    const std::vector<VRExprExpression>& getCheckContainer() const;


    std::string toString() const;
    std::string toDotString() const;
private:
};

class VRExprEfsm {
public: 
    typedef Efsm<std::string, VRExprExpression, VRExprEfsmUpdate> efsm_impl_type;

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
    VRExprEfsm();
    
    state_handle_type addState(state_value_type stateValue);

    edge_handle_type addEdge(state_handle_type pStateFrom, state_handle_type pStateTo, enable_function_type enable, update_function_type update = update_function_type());

    edge_handle_type addEdge(state_id_type fromStateId, state_id_type toStateId, enable_function_type enable, update_function_type update = update_function_type());

    std::string toString() const;
    
    void writeDotFile(const std::string & dotOutputFilename);
};

#endif // VREXPR_EFSM_H
