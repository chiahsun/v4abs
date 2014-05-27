#ifndef VEXPR_IDENTIFIER_H
#define VEXPR_IDENTIFIER_H

#include "VExprTypes.h"
#include "VExprPrimaryInterface.h"
#include "VExprConstantPrimaryInterface.h"
#include "VExprRegLvalueInterface.h"
#include "VExprNetLvalueInterface.h"
#include "VExprEventInterface.h"


#include <vector>
#include <string>

VExprIdentifierHandle vexpr_identifier_mk_single_identifier(std::string identifier, size_t size = 1);
VExprIdentifierHandle vexpr_identifier_mk_hier_identifier(std::string prefix, std::string identifier, size_t size = 1);
VExprIdentifierHandle vexpr_identifier_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);

class VExprIdentifierInterface {
public:
    virtual ~VExprIdentifierInterface();
    virtual std::string getName() const;
    virtual size_t getSize() const;
    virtual std::string getString() const;
};

class VExprIdentifier : public VExprPrimaryInterface, public VExprConstantPrimaryInterface, public VExprNetLvalueInterface, public VExprRegLvalueInterface, public VExprEventInterface {
    VExprIdentifierInterfaceHandle _pInterface;

    VExprSingleIdentifierHandle _pSingleIdentifier;
    VExprHierIdentifierHandle   _pHierIdentifier;
public:
    VExprIdentifier(VExprSingleIdentifierHandle pSingleIdentifier);
    VExprIdentifier(VExprHierIdentifierHandle pHierIdentifier);

    VExprSingleIdentifierHandle getSingleIdentifierHandle() const;
    VExprHierIdentifierHandle getHierIdentifierHandle() const;

    size_t getSize() const;
    std::string getString() const;

    VExprExpressionHandle toExpressionHandle() const;
    VExprRegLvalueHandle toRegLvalueHandle() const;
    VExprNetLvalueHandle toNetLvalueHandle() const;
};

class VExprSingleIdentifier : public VExprIdentifierInterface {
    std::string _identifier;
    size_t      _size;
public:
    VExprSingleIdentifier(std::string identifier, size_t size = 1);
    std::string getName() const;
    size_t getSize() const;
    std::string getString() const;
};

class VExprHierIdentifier : public VExprIdentifierInterface {
    std::vector<std::string> _vecPrefix;
    std::string              _identifier;
    size_t _size;
public:
    VExprHierIdentifier(std::string prefix, std::string identifier, size_t size = 1);
    VExprHierIdentifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size = 1);
    VExprHierIdentifier(std::vector<std::string> vecAll, size_t size = 1);
    std::string getName() const;
    size_t getSize() const;
    std::string getString() const;
};


#endif // VEXPR_IDENTIFIER_H
