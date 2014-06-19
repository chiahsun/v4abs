#include "VRExprModule.h"
#include "nstl/for_each/ForEach.h"
    
VRExprSignal::VRExprSignal(VRExprIdentifier identifier)
  : _identifier(identifier)
  { }
    
VRExprSignal::VRExprSignal(VRExprIdentifier identifier, int size)
  : _identifier(identifier)
  { _vecArraySize.push_back(size); }
    
VRExprIdentifier VRExprSignal::getIdentifier() const 
  { return _identifier; }

const std::vector<int>& VRExprSignal::getArraySizeContainer() const
  { return _vecArraySize; }

std::string VRExprSignal::strArrayFormat(int x) const {
    std::stringstream ss;
    if (x - 1 != 0) {
        ss << "[" << x-1 << ":" << 0 << "]";
    }
    return ss.str();
}

void VRExprSignal::addSize(int sz)
  { _vecArraySize.push_back(sz); }
    
VRExprSignal VRExprSignal::makeSignal(VRExprIdentifier identifier)
  { return VRExprSignal(identifier); }
    
std::string VRExprSignal::toString() const {
    assert(_vecArraySize.size() > 0);
    std::stringstream ss;
    ss << strArrayFormat(_vecArraySize[0]) << " " << getIdentifier().toString() << " ";
    for (unsigned int i = 1; i < _vecArraySize.size(); ++i)
       ss << strArrayFormat(_vecArraySize[i]);
    return ss.str();
}
    
VRExprParameter::VRExprParameter(VRExprIdentifier identifier, VRExprExpression expr)
  : _identifier(identifier)
  , _expr(expr)
   {}

VRExprIdentifier VRExprParameter::getIdentifier() const 
  { return _identifier; }

VRExprExpression VRExprParameter::getExpression() const 
  { return _expr; }

std::string VRExprParameter::toString() const
  { return getIdentifier().toString() + " = " + getExpression().toString(); }

VRExprModule::VRExprModule(VRExprIdentifier modName)
  : _modName(modName)
  { }

VRExprIdentifier VRExprModule::getModuleName() const
  { return _modName; }

const std::vector<VRExprIdentifier>& VRExprModule::getPortIdentifierContainer() const
  { return _vecIdentifier; }

const std::vector<VRExprAssignment>& VRExprModule::getAssignmentContainer() const
  { return _vecAssignment; }

const std::vector<VRExprAssignment>& VRExprModule::getInitialContainer() const
  { return _vecInitial; }
  
void VRExprModule::addIdentifier(VRExprIdentifier identifier)
  { _vecIdentifier.push_back(identifier); }

void VRExprModule::addAssignment(VRExprAssignment assignment)
  { _vecAssignment.push_back(assignment); }
    
void VRExprModule::addAssignment(std::vector<VRExprAssignment> vecAssign)
  { _vecAssignment.insert(_vecAssignment.end(), vecAssign.begin(), vecAssign.end()); }
    
void VRExprModule::addInitial(VRExprAssignment assignment)
  { _vecInitial.push_back(assignment); }

void VRExprModule::addInitial(std::vector<VRExprAssignment> vecAssign)
  { _vecInitial.insert(_vecInitial.end(), vecAssign.begin(), vecAssign.end()); }
    
void VRExprModule::addParameter(VRExprParameter parameter)
  { _vecParameter.push_back(parameter); }

void VRExprModule::addInput(VRExprSignal input)
  { _vecInput.push_back(input); }

void VRExprModule::addOutput(VRExprSignal output)
  { _vecOutput.push_back(output); }

void VRExprModule::addInout(VRExprSignal inout)
  { _vecInout.push_back(inout); }

void VRExprModule::addReg(VRExprSignal reg)
  { _vecReg.push_back(reg); }

void VRExprModule::addWire(VRExprSignal wire)
  { _vecWire.push_back(wire); }
    
void VRExprModule::addInteger(VRExprSignal integer)
  { _vecInteger.push_back(integer); }

std::string VRExprModule::toString() const {
    std::string s;
    s = "module " + _modName.toString() + "();\n";
    s += "input:\n";
    CONST_FOR_EACH(input, getInputContainer()) 
        s = s + input.toString() + "\n";
    s += "output:\n";
    CONST_FOR_EACH(output, getOutputContainer())
        s = s + output.toString() + "\n";
    s += "inout:\n";
    CONST_FOR_EACH(inout, getInoutContainer())
        s = s + inout.toString() + "\n";
    s += "parameter:\n";
    CONST_FOR_EACH(parameter, getParameterContainer())
        s = s + parameter.toString() + "\n";
    s += "integer:\n";
    CONST_FOR_EACH(integer, getIntegerContainer())
        s = s + integer.toString() + "\n";
    s += "reg:\n";
    CONST_FOR_EACH(reg, getRegContainer())
        s = s + reg.toString() + "\n";
    s += "wire:\n";
    CONST_FOR_EACH(wire, getWireContainer())
        s = s + wire.toString() + "\n";
   
    CONST_FOR_EACH(assign, _vecAssignment) {
        s = s + assign.toString() + "\n";
    }
    CONST_FOR_EACH(initial, _vecInitial) {
        s = s + initial.toString() + "\n";
    }
    s = s + "endmodule\n";
    return s;
}
    
const std::vector<VRExprParameter>& VRExprModule::getParameterContainer() const
  { return _vecParameter; }

const std::vector<VRExprSignal>& VRExprModule::getInputContainer() const
  { return _vecInput; }

const std::vector<VRExprSignal>& VRExprModule::getOutputContainer() const
  { return _vecOutput; }

const std::vector<VRExprSignal>& VRExprModule::getInoutContainer() const
  { return _vecInout; }

const std::vector<VRExprSignal>& VRExprModule::getRegContainer() const
  { return _vecReg; }

const std::vector<VRExprSignal>& VRExprModule::getWireContainer() const
  { return _vecWire; }

const std::vector<VRExprSignal>& VRExprModule::getIntegerContainer() const
  { return _vecInteger; }

