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

class InterfaceInfo {
public:
    std::map<std::string, int> _mapInputAndInputSize;
    std::map<std::string, int> _mapOutputAndOutputSize;
    std::map<std::string, int> _mapInoutAndInoutSize;
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
    std::map<std::string,int> _mapPureStatementAndExpressionId;
    std::map<int, std::string> _mapExpressionIdAndPureStatement;
    std::map<int, VRExprExpression> _mapExpressionIdAndSimplifiedExpression;

    std::map<int, std::vector<std::string> > _mapEdgeIdAndReadTransaction;
    std::map<int, std::vector<std::string> > _mapEdgeIdAndWriteTransaction;
    std::map<int, std::vector<std::string> > _mapEdgeIdAndCheckTransaction;

    HashTable<std::string> _hashReadSymbol;
    HashTable<std::string> _hashWriteSymbol;
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

    std::vector<VRExprAssignment>& getVecNegedgeAssign() 
      { return _vecNegedgeAssign; }
    std::vector<VRExprAssignment>& getVecPosedgeAssign() 
      { return _vecPosedgeAssign; }
    std::vector<VRExprAssignment>& getVecCombAssign() 
      { return _vecCombAssign; }
    const std::vector<VRExprAssignment>& getVecNegedgeAssign() const
      { return _vecNegedgeAssign; }
    const std::vector<VRExprAssignment>& getVecPosedgeAssign() const
      { return _vecPosedgeAssign; }
    const std::vector<VRExprAssignment>& getVecCombAssign() const
      { return _vecCombAssign; }
};
#if 0
class AssignmentInfoInWdd {
public:
    std::vector<VRExprTermManager, VRExprTermManager>
};
#endif

class SimpifiedAssignmentInfo {
public:
    std::map<int, AssignmentInfo> _mapExpressionIdAndSimplifiedAssignmentInfo;
    SimpifiedAssignmentInfo() {}
    SimpifiedAssignmentInfo(const AssignmentInfo & assignmentInfo, const ProtocolGraphInfo & protocolGraphInfo);
};

class CodeGeneration {
    VRExprEfsm _efsm;
    AssignmentFunctionCallMgr _assignFunctionCallMgr;
    std::vector<VExprModuleHandle> _vecHierModule;
    ProtocolGraph _protocolGraph;
    InterfaceInfo _interfaceInfo;
    ProtocolGraphInfo _protocolGraphInfo;
    AssignmentInfo _assignmentInfo;
    SimpifiedAssignmentInfo _simplifiedAssignmentInfo;
    VExprModuleHandle _pHierModule;
public:
    CodeGeneration( const std::string & designName
                  , const std::string & protocolName
                  , const std::string & topModuleName);

    void writeFile(const std::string & filePrefixName);
    std::string generateHeader();
    std::string generateImplementation();
   
     
    InterfaceInfo processInterface(const std::string & topModuleName, const std::vector<VExprModuleHandle> & vecHierModule) const;
    AssignmentInfo processAssignment(const std::vector<VRExprAssignment> & vecAssign); 
    ProtocolGraphInfo processProtocolGraphInfo(); 

private:
    const VRExprEfsm& getEfsm() const;

    void generateTypeAndSize(std::stringstream & ss, int sz) const;

    void initAssignmentFunctionCallMgr();

    void generateModuleHeader(std::stringstream & ss, VExprModuleHandle pHierModule) const;


    void generateProtocolState(std::stringstream & ss);
    void generateProtocolEvent(std::stringstream & ss);

    void generateParameterInitialization(std::stringstream & ss, std::string prefixModuleName, VExprModuleHandle pModule) const; 
};

#endif // CODE_GENERATION_H
