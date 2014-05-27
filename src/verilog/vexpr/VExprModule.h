#ifndef VEXPR_MODULE_H
#define VEXPR_MODULE_H

#include "VExprParameterDeclaration.h"
#include "VExprInputDeclaration.h"
#include "VExprOutputDeclaration.h"
#include "VExprInoutDeclaration.h"
#include "VExprNetDeclaration.h"
#include "VExprRegDeclaration.h"
#include "VExprIntegerDeclaration.h"

#include <vector>

class VExprModule {

    VExprIdentifierHandle _pModuleName;

    std::vector<VExprIdentifierHandle> _vecPortIdentifier;

    std::vector<VExprAlwaysHandle> _vecAlways;

    std::vector<VExprContinuousAssignmentHandle> _vecContinuousAssignment;

    std::vector<VExprModuleInstantiationHandle> _vecModuleInstantiation;

    std::vector<VExprInitialHandle> _vecInitial;


    std::vector<VExprParameterDeclarationHandle> _vecParameterDeclaration;
    std::vector<VExprInputDeclarationHandle> _vecInputDeclaration;
    std::vector<VExprOutputDeclarationHandle> _vecOutputDeclaration;
    std::vector<VExprInoutDeclarationHandle> _vecInoutDeclaration;
    std::vector<VExprNetDeclarationHandle> _vecNetDeclaration;
    std::vector<VExprRegDeclarationHandle> _vecRegDeclaration;
    std::vector<VExprIntegerDeclarationHandle> _vecIntegerDeclaration;
public:

    VExprModule(VExprIdentifierHandle pModuleName);
    VExprModule( VExprIdentifierHandle pModuleIdentifier
               , const std::vector<VExprIdentifierHandle> & vecPortIdentifier
               , const std::vector<VExprModuleItemHandle> & vecModuleItem);

    void addModuleItemDeclaration(VExprModuleItemDeclarationHandle pModuleItemDeclaration);
    void addParameterDeclaration(VExprParameterDeclarationHandle pParameterDeclaration);
    void addInputDeclaration(VExprInputDeclarationHandle pInputDeclaration);
    void addOutputDeclaration(VExprOutputDeclarationHandle pOutputDeclaration);
    void addInoutDeclaration(VExprInoutDeclarationHandle pInoutDeclaration);
    void addNetDeclaration(VExprNetDeclarationHandle pNetDeclaration);
    void addRegDeclaration(VExprRegDeclarationHandle pRegDeclaration);
    void addIntegerDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration);

    VExprIdentifierHandle& getModuleName();

    std::vector<VExprIdentifierHandle>& getPortIdentifierContainer();
    std::vector<VExprParameterDeclarationHandle>& getParameterDeclarationContainer();
    std::vector<VExprInputDeclarationHandle>& getInputDeclarationContainer();
    std::vector<VExprOutputDeclarationHandle>& getOutputDeclarationContainer();
    std::vector<VExprInoutDeclarationHandle>& getInoutDeclarationContainer();
    std::vector<VExprNetDeclarationHandle>& getNetDeclarationContainer();
    std::vector<VExprRegDeclarationHandle>& getRegDeclarationContainer();
    std::vector<VExprIntegerDeclarationHandle>& getIntegerDeclarationContainer();
    std::vector<VExprAlwaysHandle>& getAlwaysContainer(); 
    std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer();
    std::vector<VExprModuleInstantiationHandle>& getModuleInstantiationContainer();
    std::vector<VExprInitialHandle>& getInitialContainer();



    const VExprIdentifierHandle& getModuleName() const;

    const std::vector<VExprIdentifierHandle>& getPortIdentifierContainer() const;
    const std::vector<VExprParameterDeclarationHandle>& getParameterDeclarationContainer() const;
    const std::vector<VExprInputDeclarationHandle>& getInputDeclarationContainer() const;
    const std::vector<VExprOutputDeclarationHandle>& getOutputDeclarationContainer() const;
    const std::vector<VExprInoutDeclarationHandle>& getInoutDeclarationContainer() const;
    const std::vector<VExprNetDeclarationHandle>& getNetDeclarationContainer() const;
    const std::vector<VExprRegDeclarationHandle>& getRegDeclarationContainer() const;
    const std::vector<VExprIntegerDeclarationHandle>& getIntegerDeclarationContainer() const;
    const std::vector<VExprAlwaysHandle>& getAlwaysContainer() const; 
    const std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer() const;
    const std::vector<VExprModuleInstantiationHandle>& getModuleInstantiationContainer() const;
    const std::vector<VExprInitialHandle>& getInitialContainer() const;

    std::string getString() const;

};

#endif // VEXPR_MODULE_H
