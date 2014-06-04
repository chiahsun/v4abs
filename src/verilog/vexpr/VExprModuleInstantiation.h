#ifndef VEXPR_MODULE_INSTANTIATION_H
#define VEXPR_MODULE_INSTANTIATION_H

#include "VExprIdentifier.h"
#include "VExprRange.h"
#include "VExprExpression.h"

class VExprModuleInstance;

class VExprModuleInstantiation {
    VExprIdentifierHandle _pIdentifier;
    std::vector<VExprModuleInstanceHandle> _vecModuleInstance;
public:
    VExprModuleInstantiation(VExprIdentifierHandle pIdentifier, const std::vector<VExprModuleInstanceHandle> & vecModuleInstance);

    VExprIdentifierHandle getModuleName() const;
    const std::vector<VExprModuleInstanceHandle>& getModuleInstanceContainer() const;
    std::vector<VExprModuleInstanceHandle>& getModuleInstanceContainer();

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
};

class VExprModuleInstance {
    VExprNameOfInstanceHandle _pNameOfInstance;
    VExprListOfModuleConnectionsHandle _pListOfModuleConnection;
public:
    VExprModuleInstance(VExprNameOfInstanceHandle pNameOfInstance, VExprListOfModuleConnectionsHandle pListOfModuleConnection);

    VExprNameOfInstanceHandle getNameOfInstanceHandle() const;
    VExprListOfModuleConnectionsHandle getListOfModuleConnectionsHandle() const;

    std::string getString() const;
};

class VExprNameOfInstance {
    VExprIdentifierHandle _pIdentifier;
    // Optional
    VExprRangeHandle _pRange;
public:
    VExprNameOfInstance(VExprIdentifierHandle pIdentifier);
    VExprNameOfInstance(VExprIdentifierHandle pIdentifier, VExprRangeHandle pRange);

    VExprIdentifierHandle getIdentifierHandle() const;
    VExprRangeHandle getRangeHandle() const;

    std::string getString() const;

};

class VExprListOfModuleConnections {
    std::vector<VExprOrderedPortConnectionHandle> _vecOrderedPortConnection;
    std::vector<VExprNamedPortConnectionHandle> _vecNamedPortConnection;
    bool _isOrderedPortConnection;
public:
    VExprListOfModuleConnections(const std::vector<VExprOrderedPortConnectionHandle> & vecOrderedPortConnection);
    VExprListOfModuleConnections(const std::vector<VExprNamedPortConnectionHandle> & vecNamedPortConnection);

    bool isOrderedPortConnection() const;

    const std::vector<VExprOrderedPortConnectionHandle>& getOrderedPortConnectionContainer() const;
    const std::vector<VExprNamedPortConnectionHandle>& getNamedPortConnectionContainer() const;

    std::vector<VExprOrderedPortConnectionHandle>& getOrderedPortConnectionContainer();
    std::vector<VExprNamedPortConnectionHandle>& getNamedPortConnectionContainer();

    std::string getString() const;
};

class VExprOrderedPortConnection {
    // May be null
    VExprExpressionHandle _pExpression;
public:
    VExprOrderedPortConnection();
    VExprOrderedPortConnection(VExprExpressionHandle pExpression);

    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;
};


class VExprNamedPortConnection {
    VExprIdentifierHandle _pIdentifier;
    // May be null
    VExprExpressionHandle _pExpression;
public:
    VExprNamedPortConnection(VExprIdentifierHandle pIdentifier);
    VExprNamedPortConnection(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpression);

    VExprIdentifierHandle getIdentifierHandle() const; 
    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;
};
#endif 
