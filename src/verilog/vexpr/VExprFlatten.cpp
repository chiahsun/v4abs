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
        }

        LOG(WARNING) << "Not implemented yet";
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

    std::vector<VExprIdentifierHandle> vecInputIdentifier;
    std::vector<VExprNetDeclHandle> vecNetDecl;
    std::vector<VExprNetAssignmentHandle> vecNetAssignment;
    // Add inputs as wire
    FOR_EACH(pInputDeclaration, pFlatModule->getInputDeclarationContainer()) {
        FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {
            VExprIdentifierHandle pInputIdentifier = pInputDecl->getPortDeclarationHandle()->getIdentifierHandle()->flatten(pModuleInstanceName);
            VExprRangeHandle pInputRange = pInputDecl->getPortDeclarationHandle()->getRangeHandle();
            vecInputIdentifier.push_back(pInputIdentifier);

            if (pInputRange.valid()) {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pInputRange, pInputIdentifier)));
            } else {
                vecNetDecl.push_back(VExprNetDeclHandle(VExprNetDecl(pInputIdentifier)));
            }
        }
        // TODO add assignment
        // 1. Named connections
        if (!pModuleInstance->getListOfModuleConnectionsHandle()->isOrderedPortConnection()) {
            FOR_EACH(pNamedPort, pModuleInstance->getListOfModuleConnectionsHandle()->getNamedPortConnectionContainer()) {
                VExprIdentifierHandle pPortIdentifier = pNamedPort->getIdentifierHandle()->flatten(pModuleInstanceName);
                VExprExpressionHandle pPortExpression = pNamedPort->getExpressionHandle();
                vecNetAssignment.push_back(VExprNetAssignmentHandle(VExprNetAssignment(VExprNetLvalueHandle(VExprNetLvalue(pPortIdentifier)),  pPortExpression)));
            }
        } else { // Orderred connections
            LOG(ERROR) << "Not implemented yet";
        }

    }
    pFlatModule->addNetDeclaration(VExprNetDeclarationHandle(VExprNetDeclaration(vecNetDecl)));
    pFlatModule->addContinuousAssignment(VExprContinuousAssignmentHandle(VExprContinuousAssignment(vecNetAssignment)));
}
