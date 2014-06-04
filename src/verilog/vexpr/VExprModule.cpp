#include "VExprModule.h"
#include "VExprModuleItem.h"
#include "VExprAlways.h"
#include "VExprModuleItemDeclaration.h"
#include "VExprModuleInstantiation.h"
#include "VExprInitial.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "Indent.h"

VExprModule::VExprModule(VExprIdentifierHandle pModuleName)
  : _pModuleName(pModuleName)
  { }
    
VExprModule::VExprModule( VExprIdentifierHandle pModuleIdentifier
  , const std::vector<VExprIdentifierHandle> & vecPortIdentifier
  , const std::vector<VExprModuleItemHandle> & vecModuleItem) 
  : _pModuleName(pModuleIdentifier)
  , _vecPortIdentifier(vecPortIdentifier) {

    CONST_FOR_EACH(x, vecModuleItem) {
        if (x->getAlwaysHandle().valid()) {
            _vecAlways.push_back(x->getAlwaysHandle());
        } else if (x->getModuleItemDeclarationHandle().valid()) {
            addModuleItemDeclaration(x->getModuleItemDeclarationHandle());
        } else if (x->getContinuousAssignmentHandle().valid()) {
            _vecContinuousAssignment.push_back(x->getContinuousAssignmentHandle());
        } else if (x->getModuleInstantiationHandle().valid()) {
            _vecModuleInstantiation.push_back(x->getModuleInstantiationHandle());
        } else if (x->getInitialHandle().valid()) {
            _vecInitial.push_back(x->getInitialHandle());
        } else {
            assert(0);
        }
    }

}
    
void VExprModule::addModuleItemDeclaration(VExprModuleItemDeclarationHandle pModuleItemDeclaration) {
    VExprModuleItemDeclarationHandle p = pModuleItemDeclaration;
    if (p->getParameterDeclarationHandle().valid())
        addParameterDeclaration(p->getParameterDeclarationHandle());
    else if (p->getInputDeclarationHandle().valid())
        addInputDeclaration(p->getInputDeclarationHandle());
    else if (p->getOutputDeclarationHandle().valid())
        addOutputDeclaration(p->getOutputDeclarationHandle());
    else if (p->getInoutDeclarationHandle().valid())
        addInoutDeclaration(p->getInoutDeclarationHandle());
    else if (p->getNetDeclarationHandle().valid())
        addNetDeclaration(p->getNetDeclarationHandle());
    else if (p->getRegDeclarationHandle().valid())
        addRegDeclaration(p->getRegDeclarationHandle());
    else if (p->getIntegerDeclarationHandle().valid())
        addIntegerDeclaration(p->getIntegerDeclarationHandle());
    else {
        std::cerr << "No such module item" << std::endl;
        assert(0);
    }

}

void VExprModule::addParameterDeclaration(VExprParameterDeclarationHandle pParameterDeclaration)
  { _vecParameterDeclaration.push_back(pParameterDeclaration); }

void VExprModule::addInputDeclaration(VExprInputDeclarationHandle pInputDeclaration)
  { _vecInputDeclaration.push_back(pInputDeclaration); }

void VExprModule::addOutputDeclaration(VExprOutputDeclarationHandle pOutputDeclaration)
  { _vecOutputDeclaration.push_back(pOutputDeclaration); }

void VExprModule::addInoutDeclaration(VExprInoutDeclarationHandle pInoutDeclaration)
  { _vecInoutDeclaration.push_back(pInoutDeclaration); }

void VExprModule::addNetDeclaration(VExprNetDeclarationHandle pNetDeclaration)
  { _vecNetDeclaration.push_back(pNetDeclaration); }

void VExprModule::addRegDeclaration(VExprRegDeclarationHandle pRegDeclaration)
  { _vecRegDeclaration.push_back(pRegDeclaration); }

void VExprModule::addIntegerDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration)
  { _vecIntegerDeclaration.push_back(pIntegerDeclaration); }

VExprIdentifierHandle VExprModule::getModuleName()
  { return _pModuleName; }

std::vector<VExprIdentifierHandle>& VExprModule::getPortIdentifierContainer()
  { return _vecPortIdentifier; }

std::vector<VExprParameterDeclarationHandle>& VExprModule::getParameterDeclarationContainer()
  { return _vecParameterDeclaration; }

std::vector<VExprInputDeclarationHandle>& VExprModule::getInputDeclarationContainer()
  { return _vecInputDeclaration; }

std::vector<VExprOutputDeclarationHandle>& VExprModule::getOutputDeclarationContainer()
  { return _vecOutputDeclaration; }

std::vector<VExprInoutDeclarationHandle>& VExprModule::getInoutDeclarationContainer()
  { return _vecInoutDeclaration; }

std::vector<VExprNetDeclarationHandle>& VExprModule::getNetDeclarationContainer()
  { return _vecNetDeclaration; }

std::vector<VExprRegDeclarationHandle>& VExprModule::getRegDeclarationContainer()
  { return _vecRegDeclaration; }

std::vector<VExprIntegerDeclarationHandle>& VExprModule::getIntegerDeclarationContainer()
  { return _vecIntegerDeclaration; }
    
std::vector<VExprAlwaysHandle>& VExprModule::getAlwaysContainer() 
  { return _vecAlways; }

std::vector<VExprContinuousAssignmentHandle>& VExprModule::getContinuousAssignmentContainer()
  { return _vecContinuousAssignment; }

std::vector<VExprModuleInstantiationHandle>& VExprModule::getModuleInstantiationContainer()
  { return _vecModuleInstantiation; }

std::vector<VExprInitialHandle>& VExprModule::getInitialContainer()
  { return _vecInitial; }


const VExprIdentifierHandle& VExprModule::getModuleName() const
  { return _pModuleName; }
    
const std::vector<VExprIdentifierHandle>& VExprModule::getPortIdentifierContainer() const
  { return _vecPortIdentifier; }
    
const std::vector<VExprParameterDeclarationHandle>& VExprModule::getParameterDeclarationContainer() const
  { return _vecParameterDeclaration; }

const std::vector<VExprInputDeclarationHandle>& VExprModule::getInputDeclarationContainer() const 
  { return _vecInputDeclaration; }

const std::vector<VExprOutputDeclarationHandle>& VExprModule::getOutputDeclarationContainer() const
  { return _vecOutputDeclaration; }

const std::vector<VExprInoutDeclarationHandle>& VExprModule::getInoutDeclarationContainer() const
  { return _vecInoutDeclaration; }

const std::vector<VExprNetDeclarationHandle>& VExprModule::getNetDeclarationContainer() const  
  { return _vecNetDeclaration; }

const std::vector<VExprRegDeclarationHandle>& VExprModule::getRegDeclarationContainer() const 
  { return _vecRegDeclaration; }

const std::vector<VExprIntegerDeclarationHandle>& VExprModule::getIntegerDeclarationContainer() const  
  { return _vecIntegerDeclaration; }
    
const std::vector<VExprAlwaysHandle>& VExprModule::getAlwaysContainer() const
  { return _vecAlways; }

const std::vector<VExprContinuousAssignmentHandle>& VExprModule::getContinuousAssignmentContainer() const
  { return _vecContinuousAssignment; }

const std::vector<VExprModuleInstantiationHandle>& VExprModule::getModuleInstantiationContainer() const
  { return _vecModuleInstantiation; }

const std::vector<VExprInitialHandle>& VExprModule::getInitialContainer() const
  { return _vecInitial; }

std::string VExprModule::getString() const {
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

    CONST_FOR_EACH(x, getModuleInstantiationContainer()) {
        s += x->getString();
        s += "\n";
    }
    if (getModuleInstantiationContainer().size() != 0)
        s += "\n";

    s += "endmodule\n";
    return s;
}

