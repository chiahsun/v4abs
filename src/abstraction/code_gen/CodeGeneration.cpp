#include "CodeGeneration.h"
#include "abstraction/extract/EfsmExtract.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "ConvertAssignment2SystemC.h"

static const std::string indent = "    ";
    
FunctionCall::FunctionCall(std::string functionName, std::string functionImpl)
  : _functionName(functionName)
  , _functionImpl(functionImpl)
  { }

std::string FunctionCall::getFunctionName() const
  { return _functionName; }

std::string FunctionCall::getFunctionImpl() const
  { return _functionImpl; }
    
AssignmentFunctionCallMgr::AssignmentFunctionCallMgr()
  { }
    
void AssignmentFunctionCallMgr::addAssignmentAsFunctionCall(const VRExprAssignment & assignment) {
    if (_mapAssignmentFunctionId.find(assignment) != _mapAssignmentFunctionId.end())
        return;
    ConvertAssignment2SystemC converter(assignment);
    std::string functionImpl = converter.convert();

    std::stringstream ss;
    function_call_id id = _vecFunctionCall.size();
    ss << "func_number_" << id;
    FunctionCall functionCall(ss.str(), functionImpl);

    _mapAssignmentFunctionId.insert(std::make_pair(assignment, id));
    _vecFunctionCall.push_back(functionCall);
    
}
    
const std::vector<FunctionCall>& AssignmentFunctionCallMgr::getFunctionCallContainer() const 
  { return _vecFunctionCall; }

CodeGeneration::CodeGeneration
  ( const std::string & designName
  , const std::string & protocolName
  , const std::string & topModuleName) 
  : _efsm(EfsmExtract(designName, protocolName).extract(topModuleName)) {
    initAssignmentFunctionCallMgr();
}
    
const VRExprEfsm& CodeGeneration::getEfsm() const
  { return _efsm; }

void CodeGeneration::writeFile(const std::string & filePrefixName) {
    // TODO
}
#define WRITE_IO(io_type_comment, func_get_container) ss << "\n    // " #io_type_comment " \n";\
    CONST_FOR_EACH(input, getEfsm().getModule().func_get_container()) {\
        assert(input.getArraySizeContainer().size() == 1);\
        int sz = input.getArraySizeContainer()[0];\
        ss << indent;\
        generateTypeAndSize(ss, sz);\
        ss << input.getIdentifier().toString() << ";\n"; }
    
std::string CodeGeneration::generateHeader() const {
    std::stringstream ss;
    std::string moduleName = _efsm.getModule().getModuleName().toString();

    std::string strHeaderGuard = moduleName + "_H"; 
    ss << "#ifndef " << strHeaderGuard << "\n"
       << "#define " << strHeaderGuard << "\n\n"
       << "#include <systemc.h>\n\n\n";

    ss << "struct " << moduleName << " {\n";
#if 0
    ss << "\n    // Inputs\n";
    CONST_FOR_EACH(input, getEfsm().getModule().getInputContainer()) {
        assert(input.getArraySizeContainer().size() == 1);
        int sz = input.getArraySizeContainer()[0]; 
        if (sz == 1)
            ss << "bool ";
        else
            ss << "sc_uint<" << sz << "> "; 
        ss << input.getIdentifier().toString() << ";\n";

    }
#endif
    WRITE_IO(Inputs, getInputContainer);
    WRITE_IO(Outputs, getOutputContainer);
    WRITE_IO(Inouts, getInoutContainer);

    ss << "\n" << indent << "// Parameters\n";
    CONST_FOR_EACH(parameter, getEfsm().getModule().getParameterContainer()) {
        ss << indent << "const static ";
        if (!parameter.getExpression().getPrimaryHandle())
            LOG(ERROR) << "Not primary in " << parameter.toString();
        if (!parameter.getExpression().getPrimaryHandle()->getNumberHandle())
            LOG(ERROR) << "Not number in " << parameter.toString();

        const VRExprNumber* pNumber = parameter.getExpression().getPrimaryHandle()->getNumberHandle();
        ss << indent;
        generateTypeAndSize(ss, pNumber->getSize());
        ss << parameter.getIdentifier().toString() << ";\n";
    }
    
    ss << "\n" << indent << "// Registers\n";
    CONST_FOR_EACH(reg, getEfsm().getModule().getRegContainer()) {
        assert(reg.getArraySizeContainer().size() >= 1);
        int sz = reg.getArraySizeContainer()[0];
        ss << indent;
        generateTypeAndSize(ss, sz);
        ss << reg.getIdentifier().toString();
        for (unsigned int i = 1; i < reg.getArraySizeContainer().size(); ++i)
            ss << "[" << reg.getArraySizeContainer()[i] << "]";
        ss << ";\n"; 
    }

    ss << "\n" << indent << "// Wires\n";
    CONST_FOR_EACH(wire, getEfsm().getModule().getWireContainer()) {
        assert(wire.getArraySizeContainer().size() >= 1);
        int sz = wire.getArraySizeContainer()[0];
        ss << indent;
        generateTypeAndSize(ss, sz);
        ss << wire.getIdentifier().toString();
        for (unsigned int i = 1; i < wire.getArraySizeContainer().size(); ++i)
            ss << "[" << wire.getArraySizeContainer()[i] << "]";
        ss << ";\n";
    }
    
    ss << "\n" << indent << "// Integer \n";
    CONST_FOR_EACH(integer, getEfsm().getModule().getIntegerContainer()) {
        assert(integer.getArraySizeContainer().size() >= 1);
        int sz = integer.getArraySizeContainer()[0];
        ss << indent;
        generateTypeAndSize(ss, sz);\
        ss << integer.getIdentifier().toString();
        for (unsigned int i = 1; i < integer.getArraySizeContainer().size(); ++i)
            ss << "[" << integer.getArraySizeContainer()[i] << "]";
        ss << ";\n"; 
    }

    ss << "};\n\n";

    CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
        ss << "void " << functionCall.getFunctionName() << "();\n";
    }

    return ss.str();
}

void CodeGeneration::generateTypeAndSize(std::stringstream & ss, int sz) const {
    if (sz == 1)
        ss << "bool ";
    else
        ss << "sc_uint<" << sz << "> ";
}
    
std::string CodeGeneration::generateImplementation() const {
    std::stringstream ss;
    std::string moduleName = _efsm.getModule().getModuleName().toString();

    std::string strHeaderGuard = moduleName + "_H"; 
    
    ss << "#include \"" << moduleName << ".h\"\n\n";
    
    ss << "\n" << "// Parameters\n";
    CONST_FOR_EACH(parameter, getEfsm().getModule().getParameterContainer()) {
        ss << "const static ";
        if (!parameter.getExpression().getPrimaryHandle())
            LOG(ERROR) << "Not primary in " << parameter.toString();
        if (!parameter.getExpression().getPrimaryHandle()->getNumberHandle())
            LOG(ERROR) << "Not number in " << parameter.toString();

        const VRExprNumber* pNumber = parameter.getExpression().getPrimaryHandle()->getNumberHandle();
        ss << indent;
        generateTypeAndSize(ss, pNumber->getSize());
        ss << parameter.getIdentifier().toString() << " = ";
        generateTypeAndSize(ss, pNumber->getSize());
        ss << "(" << pNumber->getUnsignedNumber() << ");\n";
    }
    
    ss << "\n" << "// Function calls\n";
    CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
        ss << "void " << functionCall.getFunctionName() << "() {\n";
        ss << functionCall.getFunctionImpl();
        ss << "\n}\n\n";
    }

    return ss.str();
}
    
void CodeGeneration::initAssignmentFunctionCallMgr() {
    CONST_FOR_EACH(pEdge, _efsm.getEdgeHandleContainer()) {
        CONST_FOR_EACH(assignment, pEdge->value.getUpdateFunctionHandle()->getAssignmentContainer()) {
            _assignFunctionCallMgr.addAssignmentAsFunctionCall(assignment);
        }
    }
    // TODO
}
