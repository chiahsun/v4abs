#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include "verilog/efsm/VRExprEfsm.h"
#include "nstl/hash_map/HashMap.h"
#include "abstraction/extract/EfsmExtract.h"

class FunctionCall {
    std::string _functionName;
    std::string _functionImpl;
public:
    FunctionCall(std::string functionName, std::string functionImpl);
    std::string getFunctionName() const;
    std::string getFunctionImpl() const;
};

class AssignmentFunctionCallMgr {
    typedef int function_call_id;
    HashMap<VRExprAssignment, function_call_id> _mapAssignmentFunctionId;
    std::vector<FunctionCall> _vecFunctionCall;
public:
    AssignmentFunctionCallMgr();
    void addAssignmentAsFunctionCall(const VRExprAssignment & assignment);

    const std::vector<FunctionCall>& getFunctionCallContainer() const;
};

class ProtocolGraphInfo {
public:
    std::map<int, std::string> _mapStateIdAndName;
    std::map<int, std::string> _mapStateIdAndComment;
    std::map<int, int> _mapEdgeIdToExpressionId;
    std::map<std::string,int> _mapExpressionAndExpressionId;
    std::map<int, std::string> _mapExpressionIdAndExpression;
};

class AssignmentInfo {
public:
    std::vector<VRExprAssignment> _vecNegedgeAssign;
    std::vector<VRExprAssignment> _vecPosedgeAssign;
    std::vector<VRExprAssignment> _vecCombAssign;
    AssignmentInfo(); 
    AssignmentInfo( const std::vector<VRExprAssignment> & vecNeg
                  , const std::vector<VRExprAssignment> & vecPos
                  , const std::vector<VRExprAssignment> & vecComb);
    std::string toString() const;
};

class SimpifiedAssignmentInfo {
public:
    std::map<int, AssignmentInfo> _mapEdgeIdAndAssignmentInfo;
    SimpifiedAssignmentInfo(const AssignmentInfo & assignmentInfo, const ProtocolGraphInfo & protocolGraphInfo);
};

class CodeGeneration {
    VRExprEfsm _efsm;
    AssignmentFunctionCallMgr _assignFunctionCallMgr;
    std::vector<VExprModuleHandle> _vecHierModule;
    ProtocolGraph _protocolGraph;
    ProtocolGraphInfo _protocolGraphInfo;
    AssignmentInfo _assignmentInfo;
public:
    CodeGeneration( const std::string & designName
                  , const std::string & protocolName
                  , const std::string & topModuleName);

    void writeFile(const std::string & filePrefixName);
    std::string generateHeader();
    std::string generateImplementation();
    
    AssignmentInfo processAssignment(const std::vector<VRExprAssignment> & vecAssign); 
    ProtocolGraphInfo processProtocolGraphInfo(); 

private:
    const VRExprEfsm& getEfsm() const;

    void generateTypeAndSize(std::stringstream & ss, int sz) const;

    void initAssignmentFunctionCallMgr();

    void generateModuleHeader(std::stringstream & ss, VExprModuleHandle pHierModule) const;


    void generateProtocolState(std::stringstream & ss);
    void generateProtocolEvent(std::stringstream & ss);
};

#endif // CODE_GENERATION_H
