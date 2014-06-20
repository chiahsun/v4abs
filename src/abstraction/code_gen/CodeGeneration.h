#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include "verilog/efsm/VRExprEfsm.h"
#include "nstl/hash_map/HashMap.h"

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

class CodeGeneration {
    VRExprEfsm _efsm;
    AssignmentFunctionCallMgr _assignFunctionCallMgr;
public:
    CodeGeneration( const std::string & designName
                  , const std::string & protocolName
                  , const std::string & topModuleName);

    void writeFile(const std::string & filePrefixName);
    std::string generateHeader() const;
    std::string generateImplementation() const;

private:
    const VRExprEfsm& getEfsm() const;

    void generateTypeAndSize(std::stringstream & ss, int sz) const;

    void initAssignmentFunctionCallMgr();
};

#endif // CODE_GENERATION_H
