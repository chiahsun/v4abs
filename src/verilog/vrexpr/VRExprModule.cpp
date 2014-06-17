#include "VRExprModule.h"
#include "nstl/for_each/ForEach.h"

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

std::string VRExprModule::toString() const {
    std::string s;
    s = "module " + _modName.toString() + "();\n";
    CONST_FOR_EACH(assign, _vecAssignment) {
        s = s + assign.toString() + "\n";
    }
    CONST_FOR_EACH(initial, _vecInitial) {
        s = s + initial.toString() + "\n";
    }
    s = s + "endmodule\n";
    return s;
}
