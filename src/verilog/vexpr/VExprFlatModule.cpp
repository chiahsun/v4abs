#include "VExprFlatModule.h"
#include "VExprIdentifier.h"
#include "VExprAlways.h"
#include "VExprContinuousAssignment.h"
#include "VExprInitial.h"
#include "utility/log/Log.h"
#include "nstl/for_each/ForEach.h"


VExprFlatModule::VExprFlatModule(VExprIdentifierHandle pModuleName)
  : _pModuleName(pModuleName)
  { }
    
VExprIdentifierHandle VExprFlatModule::getModuleName() const
  { return _pModuleName; }

void VExprFlatModule::addPortIdentifier(VExprIdentifierHandle pIdentifier)
  { _vecPortIdentifier.push_back(pIdentifier); }

void VExprFlatModule::addAlways(VExprAlwaysHandle pAlways)
  { _vecAlways.push_back(pAlways); }

void VExprFlatModule::addContinuousAssignment(VExprContinuousAssignmentHandle pContinuousAssign)
  { _vecContinuousAssignment.push_back(pContinuousAssign); }

void VExprFlatModule::addInitial(VExprInitialHandle pInitial)
  { _vecInitial.push_back(pInitial); }

void VExprFlatModule::addParameterDeclaration(VExprParameterDeclarationHandle pParameter)
  { _vecParameterDeclaration.push_back(pParameter); }

void VExprFlatModule::addInputDeclaration(VExprInputDeclarationHandle pInputDeclaration)
  { _vecInputDeclaration.push_back(pInputDeclaration); }

void VExprFlatModule::addOutputDeclaration(VExprOutputDeclarationHandle pOutputDeclaration)
  { _vecOutputDeclaration.push_back(pOutputDeclaration); }

void VExprFlatModule::addInoutDeclaration(VExprInoutDeclarationHandle pInoutDeclaration)
  { _vecInoutDeclaration.push_back(pInoutDeclaration); }

void VExprFlatModule::addNetDeclaration(VExprNetDeclarationHandle pNetDeclaration)
  { _vecNetDeclaration.push_back(pNetDeclaration); }

void VExprFlatModule::addRegDeclaration(VExprRegDeclarationHandle pRegDeclaration)
  { _vecRegDeclaration.push_back(pRegDeclaration); }

void VExprFlatModule::addIntegerDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration)
  { _vecIntegerDeclaration.push_back(pIntegerDeclaration); }


std::string VExprFlatModule::getString() const {
    std::string s = "module ";

    s = s + getModuleName()->getString() + "(";
    int pos = 0;

    CONST_FOR_EACH(x, getPortIdentifierContainer()) {
        if (pos != 0)
            s += ", ";
        s += x->getString();
        ++pos;
    }
    s += ");\n\n";

    CONST_FOR_EACH(x, getInputDeclarationContainer())
        s += x->getString();
    if (getInputDeclarationContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getOutputDeclarationContainer())
        s += x->getString();
    if (getOutputDeclarationContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getInoutDeclarationContainer())
        s += x->getString();
    if (getInoutDeclarationContainer().size() != 0)
        s += "\n";
    
    CONST_FOR_EACH(x, getParameterDeclarationContainer())
        s += x->getString();
    if (getParameterDeclarationContainer().size() != 0)
        s += "\n";


    CONST_FOR_EACH(x, getNetDeclarationContainer())
        s += x->getString();
    if (getNetDeclarationContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getRegDeclarationContainer()) {
        s += x->getString();
    }
    if (getRegDeclarationContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getIntegerDeclarationContainer())
        s += x->getString();
    if (getIntegerDeclarationContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getContinuousAssignmentContainer())
        s += x->getString();
    if (getContinuousAssignmentContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getInitialContainer()) {
        s += x->getString();
        s += "\n";
    }
    if (getInitialContainer().size() != 0)
        s += "\n";

    CONST_FOR_EACH(x, getAlwaysContainer()) {
        s += x->getString();
        s += "\n";
    }
    if (getAlwaysContainer().size() != 0)
        s += "\n";

    s += "endmodule\n";
    return s;
}

std::vector<VExprIdentifierHandle>& VExprFlatModule::getPortIdentifierContainer()
  { return _vecPortIdentifier; }

std::vector<VExprParameterDeclarationHandle>& VExprFlatModule::getParameterDeclarationContainer()
  { return _vecParameterDeclaration; }

std::vector<VExprInputDeclarationHandle>& VExprFlatModule::getInputDeclarationContainer()
  { return _vecInputDeclaration; }

std::vector<VExprOutputDeclarationHandle>& VExprFlatModule::getOutputDeclarationContainer()
  { return _vecOutputDeclaration; }

std::vector<VExprInoutDeclarationHandle>& VExprFlatModule::getInoutDeclarationContainer()
  { return _vecInoutDeclaration; }

std::vector<VExprNetDeclarationHandle>& VExprFlatModule::getNetDeclarationContainer()
  { return _vecNetDeclaration; }

std::vector<VExprRegDeclarationHandle>& VExprFlatModule::getRegDeclarationContainer()
  { return _vecRegDeclaration; }

std::vector<VExprIntegerDeclarationHandle>& VExprFlatModule::getIntegerDeclarationContainer()
  { return _vecIntegerDeclaration; }
    
std::vector<VExprAlwaysHandle>& VExprFlatModule::getAlwaysContainer() 
  { return _vecAlways; }

std::vector<VExprContinuousAssignmentHandle>& VExprFlatModule::getContinuousAssignmentContainer()
  { return _vecContinuousAssignment; }


std::vector<VExprInitialHandle>& VExprFlatModule::getInitialContainer()
  { return _vecInitial; }

    
const std::vector<VExprIdentifierHandle>& VExprFlatModule::getPortIdentifierContainer() const
  { return _vecPortIdentifier; }
    
const std::vector<VExprParameterDeclarationHandle>& VExprFlatModule::getParameterDeclarationContainer() const
  { return _vecParameterDeclaration; }

const std::vector<VExprInputDeclarationHandle>& VExprFlatModule::getInputDeclarationContainer() const 
  { return _vecInputDeclaration; }

const std::vector<VExprOutputDeclarationHandle>& VExprFlatModule::getOutputDeclarationContainer() const
  { return _vecOutputDeclaration; }

const std::vector<VExprInoutDeclarationHandle>& VExprFlatModule::getInoutDeclarationContainer() const
  { return _vecInoutDeclaration; }

const std::vector<VExprNetDeclarationHandle>& VExprFlatModule::getNetDeclarationContainer() const  
  { return _vecNetDeclaration; }

const std::vector<VExprRegDeclarationHandle>& VExprFlatModule::getRegDeclarationContainer() const 
  { return _vecRegDeclaration; }

const std::vector<VExprIntegerDeclarationHandle>& VExprFlatModule::getIntegerDeclarationContainer() const  
  { return _vecIntegerDeclaration; }
    
const std::vector<VExprAlwaysHandle>& VExprFlatModule::getAlwaysContainer() const
  { return _vecAlways; }

const std::vector<VExprContinuousAssignmentHandle>& VExprFlatModule::getContinuousAssignmentContainer() const
  { return _vecContinuousAssignment; }

const std::vector<VExprInitialHandle>& VExprFlatModule::getInitialContainer() const
  { return _vecInitial; }

VExprFlatModuleHandle VExprFlatModule::substituteAndRemove(HashMap<VExprExpressionHandle, HashTable<VExprExpressionHandle> > hashSubstitute) {
    return VExprFlatModuleHandle(VExprFlatModule(*this));
}

