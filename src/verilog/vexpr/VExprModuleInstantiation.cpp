#include "VExprModuleInstantiation.h"
#include "nstl/for_each/ForEach.h"
#include "Indent.h"
    
VExprModuleInstantiation::VExprModuleInstantiation(VExprIdentifierHandle pIdentifier, const std::vector<VExprModuleInstanceHandle> & vecModuleInstance)
  : _pIdentifier(pIdentifier)
  , _vecModuleInstance(vecModuleInstance)
  { }

VExprIdentifierHandle VExprModuleInstantiation::getModuleName() const
  { return _pIdentifier; }

const std::vector<VExprModuleInstanceHandle>& VExprModuleInstantiation::getModuleInstanceContainer() const
  { return _vecModuleInstance; }

std::vector<VExprModuleInstanceHandle>& VExprModuleInstantiation::getModuleInstanceContainer()
  { return _vecModuleInstance; }

std::string VExprModuleInstantiation::getString() const
  { return getString(0); }
    
std::string VExprModuleInstantiation::getString(unsigned int indentLevel) const {
    std::string s;
    s = indent(indentLevel) + getModuleName()->getString() + " ";

    int pos = 0;
    CONST_FOR_EACH(x, getModuleInstanceContainer()) {
        if (pos++ != 0)
            s = s + ", ";
        s = s + x->getString();
    }

    s += ";\n";
    return s;
}


VExprModuleInstance::VExprModuleInstance(VExprNameOfInstanceHandle pNameOfInstance, VExprListOfModuleConnectionsHandle pListOfModuleConnection) : _pNameOfInstance(pNameOfInstance)
  , _pListOfModuleConnection(pListOfModuleConnection)
  { }

VExprNameOfInstanceHandle VExprModuleInstance::getNameOfInstanceHandle() const
  { return _pNameOfInstance; }

VExprListOfModuleConnectionsHandle VExprModuleInstance::getListOfModuleConnectionsHandle() const
  { return _pListOfModuleConnection; }

std::string VExprModuleInstance::getString() const {
    return getNameOfInstanceHandle()->getString() + getListOfModuleConnectionsHandle()->getString();
}


VExprNameOfInstance::VExprNameOfInstance(VExprIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }
    
VExprNameOfInstance::VExprNameOfInstance(VExprIdentifierHandle pIdentifier, VExprRangeHandle pRange)
  : _pIdentifier(pIdentifier)
  , _pRange(pRange)
  { }

VExprIdentifierHandle VExprNameOfInstance::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprRangeHandle VExprNameOfInstance::getRangeHandle() const
  { return _pRange; }

std::string VExprNameOfInstance::getString() const
  { return getIdentifierHandle()->getString() + (getRangeHandle().valid() ? getRangeHandle()->getString() : ""); }
    
VExprListOfModuleConnections::VExprListOfModuleConnections(const std::vector<VExprOrderedPortConnectionHandle> & vecOrderedPortConnection)
  : _vecOrderedPortConnection(vecOrderedPortConnection)
  , _isOrderedPortConnection(true)
  { }
    
VExprListOfModuleConnections::VExprListOfModuleConnections(const std::vector<VExprNamedPortConnectionHandle> & vecNamedPortConnection)
  : _vecNamedPortConnection(vecNamedPortConnection)
  , _isOrderedPortConnection(false)
  { }

bool VExprListOfModuleConnections::isOrderedPortConnection() const
  { return _isOrderedPortConnection; }
    
bool VExprListOfModuleConnections::isNamedPortConnection() const
  { return !isOrderedPortConnection(); }

const std::vector<VExprOrderedPortConnectionHandle>& VExprListOfModuleConnections::getOrderedPortConnectionContainer() const
  { return _vecOrderedPortConnection; }
    
const std::vector<VExprNamedPortConnectionHandle>& VExprListOfModuleConnections::getNamedPortConnectionContainer() const
  { return _vecNamedPortConnection; }

std::vector<VExprOrderedPortConnectionHandle>& VExprListOfModuleConnections::getOrderedPortConnectionContainer()
  { return _vecOrderedPortConnection; }
    
std::vector<VExprNamedPortConnectionHandle>& VExprListOfModuleConnections::getNamedPortConnectionContainer()
  { return _vecNamedPortConnection; }

std::string VExprListOfModuleConnections::getString() const {
    std::string s = "(";
    if (isOrderedPortConnection()) {
        int pos = 0;
        CONST_FOR_EACH(x, getOrderedPortConnectionContainer()) {
            if (pos++ != 0) 
                s += ", ";
            s += x->getString();
        }
    } else {
        int pos = 0;
        CONST_FOR_EACH(x, getNamedPortConnectionContainer()) {
            if (pos++ != 0) 
                s += ", ";
            s += x->getString();
        }
    }
    s += ")";
    return s;
}

VExprOrderedPortConnection::VExprOrderedPortConnection()
  { }
    
VExprOrderedPortConnection::VExprOrderedPortConnection(VExprExpressionHandle pExpression)
  : _pExpression(pExpression)
  { }

VExprExpressionHandle VExprOrderedPortConnection::getExpressionHandle() const
  { return _pExpression; }

std::string VExprOrderedPortConnection::getString() const
  { return (getExpressionHandle().valid() ? _pExpression->getString() : ""); }

VExprNamedPortConnection::VExprNamedPortConnection(VExprIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }

VExprNamedPortConnection::VExprNamedPortConnection(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpression)
  : _pIdentifier(pIdentifier)
  , _pExpression(pExpression)
  { }

VExprIdentifierHandle VExprNamedPortConnection::getIdentifierHandle() const
  { return _pIdentifier; }

VExprExpressionHandle VExprNamedPortConnection::getExpressionHandle() const
  { return _pExpression; }

std::string VExprNamedPortConnection::getString() const {
    return "." + getIdentifierHandle()->getString() + "("
        + (getExpressionHandle().valid() ? getExpressionHandle()->getString() : "") + ")";
}


