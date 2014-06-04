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
