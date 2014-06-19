#include "VRExprEfsm.h"
    
VRExprEfsmUpdate::VRExprEfsmUpdate()
  { }
    
VRExprEfsmUpdate::VRExprEfsmUpdate
  ( const std::vector<VRExprAssignment> vecAssign
  , const std::vector<VRExprExpression> vecRead
  , const std::vector<VRExprExpression> vecWrite
  , const std::vector<VRExprExpression> vecCheck)
  : _vecAssign(vecAssign)
  , _vecRead(vecRead)
  , _vecWrite(vecWrite)
  , _vecCheck(vecCheck)
  { }

void VRExprEfsmUpdate::addAssignment(const VRExprAssignment & assignment)
  { _vecAssign.push_back(assignment); }

void VRExprEfsmUpdate::addRead(const VRExprExpression & read)
  { _vecRead.push_back(read); }

void VRExprEfsmUpdate::addWrite(const VRExprExpression & write)
  { _vecWrite.push_back(write); }

void VRExprEfsmUpdate::addCheck(const VRExprExpression & check)
  { _vecCheck.push_back(check); }
    
std::vector<VRExprAssignment>& VRExprEfsmUpdate::getAssignmentContainer()
  { return _vecAssign; }

std::vector<VRExprExpression>& VRExprEfsmUpdate::getReadContainer()
  { return _vecRead; }

std::vector<VRExprExpression>& VRExprEfsmUpdate::getWriteContainer()
  { return _vecWrite; }

std::vector<VRExprExpression>& VRExprEfsmUpdate::getCheckContainer()
  { return _vecCheck; }

const std::vector<VRExprAssignment>& VRExprEfsmUpdate::getAssignmentContainer() const 
  { return _vecAssign; }

const std::vector<VRExprExpression>& VRExprEfsmUpdate::getReadContainer() const
  { return _vecRead; }

const std::vector<VRExprExpression>& VRExprEfsmUpdate::getWriteContainer() const
  { return _vecWrite; }

const std::vector<VRExprExpression>& VRExprEfsmUpdate::getCheckContainer() const
  { return _vecCheck; }
    
std::string VRExprEfsmUpdate::toString() const {
    std::string s;
    std::string idt = "  ";
    CONST_FOR_EACH(assign, getAssignmentContainer()) 
        s = s + idt + assign.toString() + "\n";
    s += "Read:\n";
    CONST_FOR_EACH(read, getReadContainer())
        s = s + idt + read.toString() + "\n";
    s += "Write:\n";
    CONST_FOR_EACH(write, getWriteContainer())
        s = s + idt + write.toString() + "\n";
    s += "Check:\n";
    CONST_FOR_EACH(check, getCheckContainer())
        s = s + idt + check.toString() + "\n";
    return s;
}

std::string VRExprEfsmUpdate::toDotString() const {
    return toString();
}

VRExprEfsm::VRExprEfsm(const std::string & moduleName)
  : _moduleName(moduleName)
  { }
    
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
