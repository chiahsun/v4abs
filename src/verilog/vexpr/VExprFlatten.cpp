#include <cassert>

#include "VExprFlatten.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "VExprAlways.h"
#include "VExprContinuousAssignment.h"
#include "VExprInitial.h"
#include "VExprModuleInstantiation.h"

VExprFlatModuleHandle VExprFlatten::flatten(VExprModuleHandle pModule) {

    unsigned flatModuleId = 0;
    if (isFlatBefore(pModule, flatModuleId))
        return _vecFlatModule[flatModuleId];

    VExprIdentifierHandle pModuleName = pModule->getModuleName();
    VExprFlatModuleHandle pFlatModule = VExprFlatModuleHandle(VExprFlatModule(pModuleName));

    // Add top hierarchy constructs

    FOR_EACH(pPortIdentifier, pModule->getPortIdentifierContainer()) {
        pFlatModule->addPortIdentifier(pPortIdentifier);
    }

    FOR_EACH(pParameterDeclaration, pModule->getParameterDeclarationContainer()) {
        pFlatModule->addParameterDeclaration(pParameterDeclaration);
    }

    FOR_EACH(pInputDeclaration, pModule->getInputDeclarationContainer()) {
        pFlatModule->addInputDeclaration(pInputDeclaration);
    }

    FOR_EACH(pOutputDeclaration, pModule->getOutputDeclarationContainer()) {
        pFlatModule->addOutputDeclaration(pOutputDeclaration);
    }

    FOR_EACH(pInoutDeclaration, pModule->getInoutDeclarationContainer()) {
        pFlatModule->addInoutDeclaration(pInoutDeclaration);
    }

    FOR_EACH(pNetDeclaration, pModule->getNetDeclarationContainer()) {
        pFlatModule->addNetDeclaration(pNetDeclaration);
    }

    FOR_EACH(pRegDeclaration, pModule->getRegDeclarationContainer()) {
        pFlatModule->addRegDeclaration(pRegDeclaration);
    }

    FOR_EACH(pIntegerDeclaration, pModule->getIntegerDeclarationContainer()) {
        pFlatModule->addIntegerDeclaration(pIntegerDeclaration);
    }

    FOR_EACH(pAlways, pModule->getAlwaysContainer()) {
        pFlatModule->addAlways(pAlways);
    }

    FOR_EACH(pContinuousAssignment, pModule->getContinuousAssignmentContainer()) {
        pFlatModule->addContinuousAssignment(pContinuousAssignment);
    }

    FOR_EACH(pInitial, pModule->getInitialContainer()) {
        pFlatModule->addInitial(pInitial);
    }


    // Add sub modules

    std::vector<VExprFlatModuleHandle> vecFlatModule;

    FOR_EACH(pSubModule, pModule->getModuleInstantiationContainer()) {

        VExprFlatModuleHandle pFlatSubModule;

        unsigned int flatSubModuleId = 0;
        if (isFlatBefore(pSubModule->getModuleName(), flatSubModuleId)) {
            pFlatSubModule = _vecFlatModule[flatSubModuleId];
        } else {
            FOR_EACH(pOtherModule, _vecModule) {
                if (pOtherModule->getModuleName()->getString() == pSubModule->getModuleName()->getString()) {
                    pFlatSubModule = flatten(pOtherModule);
                    _vecFlatModule.push_back(pFlatSubModule);
                }
            }

            if (!pFlatSubModule.valid())
                LOG(ERROR) << "Missing sub module : " << pSubModule->getModuleName()->getString() << " while flatten : " << pModule->getModuleName()->getString() << std::endl;
        }

        FOR_EACH(pModuleInstance, pSubModule->getModuleInstanceContainer()) {
            VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

            if (pModuleInstance->getNameOfInstanceHandle()->getRangeHandle().valid()) {
                LOG(ERROR) << "Range is not dealt with now";
            }

            addSubParameterDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubInputDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubOutputDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubInoutDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubConnection(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubNetDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubRegDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubIntegerDeclaration(pFlatModule, pModuleInstance, pFlatSubModule);
            
            addSubAlways(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubContinuousAssignment(pFlatModule, pModuleInstance, pFlatSubModule);
            addSubInitial(pFlatModule, pModuleInstance, pFlatSubModule);
        }

    }

    return pFlatModule;
}
    
bool VExprFlatten::isFlatBefore(VExprModuleHandle pModule, unsigned int & flatModuleId) {
    return isFlatBefore(pModule->getModuleName(), flatModuleId);
}

bool VExprFlatten::isFlatBefore(VExprIdentifierHandle pModuleName, unsigned int & flatModuleId) {
    unsigned int pos = 0;
    FOR_EACH(pFlatModule, _vecFlatModule) {
        if (pModuleName == pFlatModule->getModuleName()) { 
            flatModuleId = pos;
            return true;
        }

        ++pos;
    }
    return false;
}

void VExprFlatten::addSubParameterDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();
    FOR_EACH(pParameterDeclaration, pFlatSubModule->getParameterDeclarationContainer()) {
        pFlatModule->addParameterDeclaration(pParameterDeclaration->flatten(pModuleInstanceName));
    }
}
    
void VExprFlatten::addSubInputDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    std::vector<VExprNetDeclHandle> vecNetDecl;
    // Add inputs as wire
    FOR_EACH(pInputDeclaration, pFlatSubModule->getInputDeclarationContainer()) {
        FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {
            VExprIdentifierHandle pInputIdentifier = pInputDecl->getPortDeclarationHandle()->getIdentifierHandle()->flatten(pModuleInstanceName);
            VExprRangeHandle pInputRange = pInputDecl->getPortDeclarationHandle()->getRangeHandle();

            if (pInputRange.valid()) {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pInputRange, pInputIdentifier)));
            } else {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pInputIdentifier)));
            }
        }

    }
    pFlatModule->addNetDeclaration(VExprNetDeclarationHandle(VExprNetDeclaration(vecNetDecl)));
}
    
void VExprFlatten::addSubOutputDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    std::vector<VExprNetDeclHandle> vecNetDecl;


    FOR_EACH(pOutputDeclaration, pFlatSubModule->getOutputDeclarationContainer()) {
        FOR_EACH(pOutputDecl, pOutputDeclaration->getContainer()) {
            VExprIdentifierHandle pOutputIdentifier = pOutputDecl->getPortDeclarationHandle()->getIdentifierHandle()->flatten(pModuleInstanceName);
            VExprRangeHandle pOutputRange = pOutputDecl->getPortDeclarationHandle()->getRangeHandle();

            if (pOutputRange.valid()) {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pOutputRange, pOutputIdentifier)));
            } else {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pOutputIdentifier)));
            }
        }
    }
    pFlatModule->addNetDeclaration(VExprNetDeclarationHandle(VExprNetDeclaration(vecNetDecl)));
}

void VExprFlatten::addSubInoutDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    std::vector<VExprNetDeclHandle> vecNetDecl;


    FOR_EACH(pInoutDeclaration, pFlatSubModule->getInoutDeclarationContainer()) {
        FOR_EACH(pInoutDecl, pInoutDeclaration->getContainer()) {
            VExprIdentifierHandle pInoutIdentifier = pInoutDecl->getPortDeclarationHandle()->getIdentifierHandle()->flatten(pModuleInstanceName);
            VExprRangeHandle pOutputRange = pInoutDecl->getPortDeclarationHandle()->getRangeHandle();

            if (pOutputRange.valid()) {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pOutputRange, pInoutIdentifier)));
            } else {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pInoutIdentifier)));
            }
        }
    }
    pFlatModule->addNetDeclaration(VExprNetDeclarationHandle(VExprNetDeclaration(vecNetDecl)));
}

void VExprFlatten::addSubConnection(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();
    std::vector<VExprNetAssignmentHandle> vecNetAssignment;
    // 1. Named connections
    if (pModuleInstance->getListOfModuleConnectionsHandle()->isNamedPortConnection()) {
        FOR_EACH(pNamedPort, pModuleInstance->getListOfModuleConnectionsHandle()->getNamedPortConnectionContainer()) {
            VExprIdentifierHandle pPortIdentifier = pNamedPort->getIdentifierHandle()->flatten(pModuleInstanceName);
            VExprExpressionHandle pPortExpression = pNamedPort->getExpressionHandle();
            vecNetAssignment.push_back(VExprNetAssignmentHandle(VExprNetAssignment(VExprNetLvalueHandle(VExprNetLvalue(pPortIdentifier)),  pPortExpression)));
            }
    } else { // Orderred connections
        LOG(ERROR) << "Not implemented yet";
    }
    pFlatModule->addContinuousAssignment(VExprContinuousAssignmentHandle(VExprContinuousAssignment(vecNetAssignment)));
}

    
void VExprFlatten::addSubNetDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    FOR_EACH(pNetDeclaration, pFlatSubModule->getNetDeclarationContainer()) {
        pFlatModule->addNetDeclaration(pNetDeclaration->flatten(pModuleInstanceName));
    }
}

void VExprFlatten::addSubRegDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    FOR_EACH(pRegDeclaration, pFlatSubModule->getRegDeclarationContainer()) {
        pFlatModule->addRegDeclaration(pRegDeclaration->flatten(pModuleInstanceName));
    }
}

void VExprFlatten::addSubIntegerDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    FOR_EACH(pIntegerDeclaration, pFlatSubModule->getIntegerDeclarationContainer()) {
        pFlatModule->addIntegerDeclaration(pIntegerDeclaration->flatten(pModuleInstanceName));
    }
}


void VExprFlatten::addSubAlways(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    FOR_EACH(pAlways, pFlatSubModule->getAlwaysContainer()) {
        pFlatModule->addAlways(pAlways->flatten(pModuleInstanceName));
    }
}
    
void VExprFlatten::addSubContinuousAssignment(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();

    FOR_EACH(pContinuousAssignment, pFlatSubModule->getContinuousAssignmentContainer()) {
        pFlatModule->addContinuousAssignment(pContinuousAssignment->flatten(pModuleInstanceName));
    }
}

void VExprFlatten::addSubInitial(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule) {
    VExprIdentifierHandle pModuleInstanceName = pModuleInstance->getNameOfInstanceHandle()->getIdentifierHandle();
    
    FOR_EACH(pInitial, pFlatSubModule->getInitialContainer()) {
        pFlatModule->addInitial(pInitial->flatten(pModuleInstanceName));
    }
}
