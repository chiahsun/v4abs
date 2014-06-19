#include "ConvertVExpr2VRExpr.h"
#include "utility/log/Log.h"    
#include "nstl/for_each/ForEach.h"
#include "nstl/hash_map/HashMap.h"
#include "nstl/hash/HashTable.h"

VRExprModule ConvertVExpr2VRExpr::convert(VExprFlatModuleHandle pFlatModule) {
    VRExprModule mod(ConvertVExpr2VRExpr::convert(pFlatModule->getModuleName()));

    CONST_FOR_EACH(pAlways, pFlatModule->getAlwaysContainer()) {
        mod.addAssignment(ConvertVExpr2VRExpr::convert(pAlways));
    }

    CONST_FOR_EACH(pContinuousAssignment, pFlatModule->getContinuousAssignmentContainer()) {
        mod.addAssignment(ConvertVExpr2VRExpr::convert(pContinuousAssignment));
    }

    CONST_FOR_EACH(pInitial, pFlatModule->getInitialContainer()) {
        mod.addInitial(ConvertVExpr2VRExpr::convert(pInitial));
    }

    CONST_FOR_EACH(pParameterDeclaration, pFlatModule->getParameterDeclarationContainer()) {
        CONST_FOR_EACH(pParaAssignment, pParameterDeclaration->getParaAssignmentHandleContainer()) {
            VRExprIdentifier identifier = convert(pParaAssignment->getIdentifierHandle());
            VRExprExpression expr = convert(pParaAssignment->getExpressionHandle());
            VRExprParameter parameter(identifier, expr);
            mod.addParameter(parameter);
        }
    }

    CONST_FOR_EACH(pIntegerDeclaration, pFlatModule->getIntegerDeclarationContainer()) {
        CONST_FOR_EACH(pRegisterName, pIntegerDeclaration->getContainer()) {
            VRExprIdentifier identifier = convert(pRegisterName->getIdentifierHandle());
            VRExprSignal input = VRExprSignal::makeSignal(identifier);
            CONST_FOR_EACH(pRange, pRegisterName->getRangeHandleContainer()) {
                VExprConstantExpressionHandle pFst = pRange->getFst();
                VExprConstantExpressionHandle pSnd = pRange->getSnd();

                unsigned int pFstNumber = convertToUnsignedNumber(pFst);
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);
                input.addSize(pFstNumber - pSndNumber+1);
            }
            mod.addInput(input);
        }
    }
#if 0
    CONST_FOR_EACH(pInputDeclaration, pFlatModule->getInputDeclarationContainer()) {
        CONST_FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {
            VExprPortDeclarationHandle pPortDeclaration = pInputDecl->getPortDeclarationHandle();
            VExprIdentifierHandle pIdentifier = pPortDeclaration->getIdentifierHandle();
            VRExprIdentifier identifier = convert(pIdentifier);

            VExprRangeHandle pRange = pPortDeclaration->getRangeHandle();
            if (!pRange.valid()) {
                VRExprSignal input(identifier, 1);
                mod.addInput(input);
            } else {
                VExprConstantExpressionHandle pFst = pRange->getFst();
                VExprConstantExpressionHandle pSnd = pRange->getSnd();

                unsigned int pFstNumber = convertToUnsignedNumber(pFst);
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);

                VRExprSignal input(identifier, pFstNumber - pSndNumber + 1);
                mod.addInput(input);
            }
        }
    }
#endif
#define ADD_IO(func_get_decl_container_name, func_add_name) \
    CONST_FOR_EACH(pInputDeclaration, pFlatModule->func_get_decl_container_name()) {\
        CONST_FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {\
            VExprPortDeclarationHandle pPortDeclaration = pInputDecl->getPortDeclarationHandle();\
            VExprIdentifierHandle pIdentifier = pPortDeclaration->getIdentifierHandle();\
            VRExprIdentifier identifier = convert(pIdentifier);\
            VExprRangeHandle pRange = pPortDeclaration->getRangeHandle();\
            if (!pRange.valid()) {\
                VRExprSignal input(identifier, 1);\
                mod.func_add_name(input);\
            } else {\
                VExprConstantExpressionHandle pFst = pRange->getFst();\
                VExprConstantExpressionHandle pSnd = pRange->getSnd();\
                unsigned int pFstNumber = convertToUnsignedNumber(pFst);\
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);\
                VRExprSignal input(identifier, pFstNumber - pSndNumber + 1);\
                mod.func_add_name(input);\
            }\
        }\
    }

    ADD_IO(getInputDeclarationContainer, addInput);
    ADD_IO(getOutputDeclarationContainer, addOutput);
    ADD_IO(getInoutDeclarationContainer, addInout);
    
    CONST_FOR_EACH(pNetDeclaration, pFlatModule->getNetDeclarationContainer()) {
        CONST_FOR_EACH(pNetDecl, pNetDeclaration->getContainer()) {
            VExprIdentifierHandle pIdentifier = pNetDecl->getIdentifierHandle();
            VRExprIdentifier identifier = convert(pIdentifier);

            VExprRangeHandle pRange = pNetDecl->getRangeHandle();
            if (!pRange.valid()) {
                VRExprSignal input(identifier, 1);
                mod.addWire(input);
            } else {
                VExprConstantExpressionHandle pFst = pRange->getFst();
                VExprConstantExpressionHandle pSnd = pRange->getSnd();

                unsigned int pFstNumber = convertToUnsignedNumber(pFst);
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);

                VRExprSignal input(identifier, pFstNumber - pSndNumber + 1);
                mod.addWire(input);
            }
        }
    }


    CONST_FOR_EACH(pRegDeclaration, pFlatModule->getRegDeclarationContainer()) {
        CONST_FOR_EACH(pRegDecl, pRegDeclaration->getContainer()) {
            VExprRegisterNameHandle pRegisterName = 
                pRegDecl->getRegisterNameHandle();
            VExprIdentifierHandle pIdentifier =
                pRegisterName->getIdentifierHandle();
            VRExprIdentifier identifier = convert(pIdentifier);

            VRExprSignal input = VRExprSignal::makeSignal(identifier);
            {
            VExprRangeHandle pRange = pRegDecl->getRangeHandle();

            if (!pRange.valid()) {
                input.addSize(1);
            } else {
                VExprConstantExpressionHandle pFst = pRange->getFst();
                VExprConstantExpressionHandle pSnd = pRange->getSnd();

                unsigned int pFstNumber = convertToUnsignedNumber(pFst);
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);

                input.addSize(pFstNumber - pSndNumber + 1);
            }
            }

            CONST_FOR_EACH(pRange, pRegisterName->getRangeHandleContainer()) {
                VExprConstantExpressionHandle pFst = pRange->getFst();
                VExprConstantExpressionHandle pSnd = pRange->getSnd();

                unsigned int pFstNumber = convertToUnsignedNumber(pFst);
                unsigned int pSndNumber = convertToUnsignedNumber(pSnd);

                input.addSize(pFstNumber - pSndNumber + 1);
            }
            mod.addReg(input);
        }
    }

    return mod;
}

VRExprIdentifier ConvertVExpr2VRExpr::convert(VExprIdentifierHandle pIdentifier) {
    if (pIdentifier->getSingleIdentifierHandle().valid()) {
        return VRExprIdentifier(pIdentifier->getSingleIdentifierHandle()->getString());
    } else if (pIdentifier->getHierIdentifierHandle().valid()) {
        std::vector<std::string> vecString;
        vecString.push_back(pIdentifier->getHierIdentifierHandle()->getIdentifier());
        std::vector<std::string> vecPrefix = pIdentifier->getHierIdentifierHandle()->getPrefixContainer();
        FOR_EACH(str, vecPrefix) 
            vecString.push_back(str);
        
        return VRExprIdentifier(vecString);
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VRExprNumber ConvertVExpr2VRExpr::convert(VExprNumberHandle pNumber) {
    if (pNumber->getUnsignedNumberHandle().valid()) {
        return VRExprNumber(ConvertVExpr2VRExpr::convert(pNumber->getUnsignedNumberHandle()));
    } else if (pNumber->getBinaryNumberHandle().valid()) {
        return VRExprNumber(ConvertVExpr2VRExpr::convert(pNumber->getBinaryNumberHandle()));
    } else if (pNumber->getOctalNumberHandle().valid()) {
        return VRExprNumber(ConvertVExpr2VRExpr::convert(pNumber->getOctalNumberHandle()));
    } else if (pNumber->getDecimalNumberHandle().valid()) {
        return VRExprNumber(ConvertVExpr2VRExpr::convert(pNumber->getDecimalNumberHandle()));
    } else if (pNumber->getHexNumberHandle().valid()) {
        return VRExprNumber(ConvertVExpr2VRExpr::convert(pNumber->getHexNumberHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}


VRExprUnsignedNumber ConvertVExpr2VRExpr::convert(VExprUnsignedNumberHandle pUnsignedNumber) {
    return VRExprUnsignedNumber(pUnsignedNumber->getValue());
}

VRExprBinaryNumber ConvertVExpr2VRExpr::convert(VExprBinaryNumberHandle pBinaryNumber) {
    return VRExprBinaryNumber(pBinaryNumber->getString());
}


VRExprOctalNumber ConvertVExpr2VRExpr::convert(VExprOctalNumberHandle pOctalNumber) {
    return VRExprOctalNumber(pOctalNumber->getString());
}

VRExprDecimalNumber ConvertVExpr2VRExpr::convert(VExprDecimalNumberHandle pDecimalNumber) {
    return VRExprDecimalNumber(pDecimalNumber->getString());
}

VRExprHexNumber ConvertVExpr2VRExpr::convert(VExprHexNumberHandle pHexNumber) {
    return VRExprHexNumber(pHexNumber->getString());
}
    
VRExprMultConcatentation ConvertVExpr2VRExpr::convert(VExprMultipleConcatenationHandle pMultipleConcatenation) {
    VRExprExpression newExprRepeat = ConvertVExpr2VRExpr::convert(pMultipleConcatenation->getExprRepeat());
    std::vector<VRExprExpression> vecNewExpr;
    CONST_FOR_EACH(pExpr, pMultipleConcatenation->getExprContainer()) {
        vecNewExpr.push_back(ConvertVExpr2VRExpr::convert(pExpr));
    }
    return VRExprMultConcatentation(newExprRepeat, vecNewExpr);
}
    
VRExprConcatenation ConvertVExpr2VRExpr::convert(VExprConcatenationHandle pConcatenation) {
    std::vector<VRExprExpression> vecExpr;
    CONST_FOR_EACH(pExpression, pConcatenation->getExprContainer()) {
        vecExpr.push_back(ConvertVExpr2VRExpr::convert(pExpression));
    }
    return VRExprConcatenation(vecExpr);
}
    
VRExprSelectIdentifier ConvertVExpr2VRExpr::convert(VExprSelectIdentifierHandle pSelectIdentifier) {
    VRExprIdentifier newIdentifier = ConvertVExpr2VRExpr::convert(pSelectIdentifier->getIdentifierHandle());

    std::vector<VExprSelectHandle> vecSelect = pSelectIdentifier->getSelectContainer();
    std::vector<VRExprSelect> vecNewSelect;
    CONST_FOR_EACH(pSelect, vecSelect) {
        vecNewSelect.push_back(ConvertVExpr2VRExpr::convert(pSelect));
    }

    return VRExprSelectIdentifier(newIdentifier, vecNewSelect);
}

VRExprSelect ConvertVExpr2VRExpr::convert(VExprSelectHandle pSelect) {
    if (pSelect->getRangeSelectHandle().valid()) {
        return VRExprSelect(ConvertVExpr2VRExpr::convert(pSelect->getRangeSelectHandle()));
    } else if (pSelect->getBitSelectHandle().valid()) {
        return VRExprSelect(ConvertVExpr2VRExpr::convert(pSelect->getBitSelectHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

VRExprRangeSelect ConvertVExpr2VRExpr::convert(VExprRangeSelectHandle pRangeSelect) {
    return VRExprRangeSelect(
             ConvertVExpr2VRExpr::convert(pRangeSelect->getExprFst())
           , ConvertVExpr2VRExpr::convert(pRangeSelect->getExprSnd())
           );
}
    
VRExprBitSelect ConvertVExpr2VRExpr::convert(VExprBitSelectHandle pBitSelect) {
    return VRExprBitSelect(
            ConvertVExpr2VRExpr::convert(pBitSelect->getExpr()));
}
    
VRExprPrimary ConvertVExpr2VRExpr::convert(VExprPrimaryHandle pPrimary) {
    if (pPrimary->getNumberHandle().valid()) {
        return VRExprPrimary(ConvertVExpr2VRExpr::convert(pPrimary->getNumberHandle()));
    } else if (pPrimary->getIdentifierHandle().valid()) {
        return VRExprPrimary(ConvertVExpr2VRExpr::convert(pPrimary->getIdentifierHandle()));
    } else if (pPrimary->getSelectIdentifierHandle().valid()) {
        return VRExprPrimary(ConvertVExpr2VRExpr::convert(pPrimary->getSelectIdentifierHandle()));
    } else if (pPrimary->getConcatenationHandle().valid()) {
        return VRExprPrimary(ConvertVExpr2VRExpr::convert(pPrimary->getConcatenationHandle()));
    } else if (pPrimary->getMultipleConcatenationHandle().valid()) {
        return VRExprPrimary(ConvertVExpr2VRExpr::convert(pPrimary->getMultipleConcatenationHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VRExprExpression ConvertVExpr2VRExpr::convert(VExprExpressionHandle pExpression) {
    if (pExpression->getPrimaryHandle().valid()) {
        return VRExprExpression(ConvertVExpr2VRExpr::convert(pExpression->getPrimaryHandle()));
    } else if (pExpression->getUnaryHandle().valid()) {
        VRExprUnaryExpression unary_expr = 
               VRExprUnaryExpression(
                 pExpression->getUnaryHandle()->getOpType()
               , ConvertVExpr2VRExpr::convert(pExpression->getUnaryHandle()->getPrimaryHandle()));
        return VRExprExpression(unary_expr);
    } else if (pExpression->getBinaryHandle().valid()) {
        VRExprBinaryExpression binary_expr = VRExprBinaryExpression(
                ConvertVExpr2VRExpr::convert(pExpression->getBinaryHandle()->getFst())
               , pExpression->getBinaryHandle()->getOpType()
               , ConvertVExpr2VRExpr::convert(pExpression->getBinaryHandle()->getSnd()));
        return VRExprExpression(binary_expr);
    } else if (pExpression->getTernaryHandle().valid()) {
        VRExprExpression expr_if = ConvertVExpr2VRExpr::convert(pExpression->getTernaryHandle()->getIf());
        VRExprExpression expr_then = ConvertVExpr2VRExpr::convert(pExpression->getTernaryHandle()->getThen());
        VRExprExpression expr_else = ConvertVExpr2VRExpr::convert(pExpression->getTernaryHandle()->getElse());
        VRExprIte expr_ite(expr_if, expr_then, expr_else);
        return VRExprExpression(expr_ite);
    } else if (pExpression->getBoolHandle().valid()) {
        LOG(ERROR) << "Not implemented yet";
    }
    assert(0);
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprContinuousAssignmentHandle pContinuousAssignment) {
    std::vector<VRExprAssignment> vecAssignment;
    CONST_FOR_EACH(pNetAssignment, pContinuousAssignment->getNetAssignmentContainer()) {
        vecAssignment.push_back(ConvertVExpr2VRExpr::convert(pNetAssignment));
    }
    return vecAssignment;
}
    
VRExprAssignment ConvertVExpr2VRExpr::convert(VExprNetAssignmentHandle pNetAssignment) {
    VRExprExpression lhs = ConvertVExpr2VRExpr::convert(pNetAssignment->getNetLvalueHandle());
    VRExprExpression rhs = ConvertVExpr2VRExpr::convert(pNetAssignment->getExpressionHandle());
    return VRExprAssignment(lhs, rhs);
}

VRExprExpression ConvertVExpr2VRExpr::convert(VExprNetLvalueHandle pNetLvalue) {
    return VRExprExpression(ConvertVExpr2VRExpr::convert(pNetLvalue->toExpressionHandle()));
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprInitialHandle pInitial) {
    return ConvertVExpr2VRExpr::convert(pInitial->getStatementHandle());
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprStatementHandle pStatement) {
    if (pStatement->getBlockingAssignHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getBlockingAssignHandle());
    } else if (pStatement->getNonBlockingAssignHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getNonBlockingAssignHandle());
    } else if (pStatement->getSeqBlockHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getSeqBlockHandle());
    } else if (pStatement->getConditionalHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getConditionalHandle());
    } else if (pStatement->getCaseStatementHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getCaseStatementHandle());
    } else if (pStatement->getProceduralContinuousAssignmentHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getProceduralContinuousAssignmentHandle());
    } else if (pStatement->getLoopStatementHandle().valid()) {
        LOG(ERROR) << "Not implemented yet";
    } else if (pStatement->getEventStatementHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatement->getEventStatementHandle());
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprBlockingAssignmentHandle pBlockingAssignment) {
    VRExprAssignment assign(
             ConvertVExpr2VRExpr::convert(pBlockingAssignment->getRegLvalueHandle()->toExpressionHandle())
           , ConvertVExpr2VRExpr::convert(pBlockingAssignment->getExpressionHandle())
           );
    std::vector<VRExprAssignment> vecAssign;
    vecAssign.push_back(assign);
    return vecAssign;
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprNonBlockingAssignmentHandle pNonBlockingAssignment) {
    VRExprAssignment assign(
             ConvertVExpr2VRExpr::convert(pNonBlockingAssignment->getRegLvalueHandle()->toExpressionHandle())
           , ConvertVExpr2VRExpr::convert(pNonBlockingAssignment->getExpressionHandle())
           );
    std::vector<VRExprAssignment> vecAssign;
    vecAssign.push_back(assign);
    return vecAssign;
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprSeqBlockHandle pSeqBlock) {
    std::vector<VRExprAssignment> vecAssign;
    CONST_FOR_EACH(pStatement, pSeqBlock->getStatementContainer()) {
        std::vector<VRExprAssignment> vecNewAssign =
            ConvertVExpr2VRExpr::convert(pStatement);
        vecAssign.insert(vecAssign.end(), vecNewAssign.begin(), vecNewAssign.end());
    }
    return vecAssign;
}

std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprConditionalStatementHandle pConditional) {
    VRExprExpression exprIf = ConvertVExpr2VRExpr::convert(pConditional->getIf());

    std::vector<VRExprAssignment> vecThen = ConvertVExpr2VRExpr::convert(pConditional->getThen());
    std::vector<VRExprAssignment> vecElse = ConvertVExpr2VRExpr::convert(pConditional->getElse());
   
    HashTable<VRExprExpression> hashBoth;
    // Unique assignment for each LHS checking
    HashMap<VRExprExpression, VRExprAssignment> mapThenAssign;
    CONST_FOR_EACH(thenAssign, vecThen) {
        if (mapThenAssign.find(thenAssign.getExprLhs()) != mapThenAssign.end()) {
            LOG(ERROR) << "More than once assignment for " << mapThenAssign.find(thenAssign.getExprLhs())->first.toString() << "\n"
                       << "  in " << thenAssign.toString() << "\n"
                       << "  in " << mapThenAssign.find(thenAssign.getExprLhs())->second.toString() << std::endl;
        }
        mapThenAssign.insert(std::make_pair(thenAssign.getExprLhs(), thenAssign));
        hashBoth.insert(thenAssign.getExprLhs());
    }
    
    // Unique assignment for each LHS checking
    HashMap<VRExprExpression, VRExprAssignment> mapElseAssign;
    CONST_FOR_EACH(elseAssign, vecElse) {
        if (mapElseAssign.find(elseAssign.getExprLhs()) != mapElseAssign.end()) {
            LOG(ERROR) << "More than once assignment for " << mapElseAssign.find(elseAssign.getExprLhs())->first.toString() << "\n"
                       << "  in " << elseAssign.toString() << "\n"
                       << "  in " << mapElseAssign.find(elseAssign.getExprLhs())->second.toString() << std::endl;
        }
        mapElseAssign.insert(std::make_pair(elseAssign.getExprLhs(), elseAssign));
        hashBoth.insert(elseAssign.getExprLhs());
    }
    
    std::vector<VRExprAssignment> vec;
    // Add both then and else
    CONST_FOR_EACH(assignLhs, hashBoth) {
        assert(mapThenAssign.find(assignLhs) != mapThenAssign.end());
        assert(mapElseAssign.find(assignLhs) != mapElseAssign.end());
        vec.push_back(VRExprAssignment( assignLhs
                                      , VRExprExpression(VRExprIte( exprIf
                                                                  , mapThenAssign.find(assignLhs)->second.getExprRhs()
                                                                  , mapElseAssign.find(assignLhs)->second.getExprRhs()))));
    }
   
    // Add only then
    CONST_FOR_EACH(exprThen, vecThen) {
        if (hashBoth.find(exprThen.getExprLhs()) == hashBoth.end()) {
            VRExprExpression rhs = exprThen.getExprRhs().appendIfByThen(exprIf);
            vec.push_back(VRExprAssignment(exprThen.getExprLhs(), rhs));
        }
    }

    // Add only else
    CONST_FOR_EACH(exprElse, vecElse) {
        if (hashBoth.find(exprElse.getExprLhs()) == hashBoth.end()) {
            VRExprExpression rhs = exprElse.getExprRhs().appendIfByElse(exprIf);
            vec.push_back(VRExprAssignment(exprElse.getExprLhs(), rhs));
        }
    }
    

    return vec;
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprStatementOrNullHandle pStatementOrNull) {
    if (pStatementOrNull->getStatementHandle().valid()) {
        return ConvertVExpr2VRExpr::convert(pStatementOrNull->getStatementHandle());
    } else if (pStatementOrNull->getNullHandle().valid()) {
        return std::vector<VRExprAssignment>();
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprCaseStatementHandle pCaseStatement) {
    // TODO
    LOG(ERROR) << "Not implemented yet";
    assert(0);
#if 0
    VRExprExpression exprCaseStatement = ConvertVExpr2VRExpr::convert(pCaseStatement->getExpressionHandle());

    CONST_FOR_EACH(pCaseItem, pCaseStatement->getConstCaseItemContainer()) {
        std::vector<VRExprExpression> vecEq;
        CONST_FOR_EACH(pExpr, pCaseItem->getExpressionHandleContainer()) {
            vecEq.push_back(VRExprExpression(VRExprBinaryExpression(exprCaseStatement, BINARY_EQ, ConvertVExpr2VRExpr::convert(pExpr))));
        }   
    }
#endif
}
    
std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprProceduralContinuousAssignmentHandle pProceduralAssignemnt) {
    std::vector<VRExprAssignment> vecAssign;

    VRExprAssignment assign = ConvertVExpr2VRExpr::convert(pProceduralAssignemnt->getRegAssignment());
    vecAssign.push_back(assign);
    return vecAssign;
}

VRExprAssignment ConvertVExpr2VRExpr::convert(VExprRegAssignmentHandle pRegAssignment) {
    VRExprExpression exprLhs = ConvertVExpr2VRExpr::convert(pRegAssignment->getRegLvalueHandle()->toExpressionHandle());
    return VRExprAssignment(exprLhs, ConvertVExpr2VRExpr::convert(pRegAssignment->getExpressionHandle()));
}

std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprEventStatementHandle pEventStatement) {
    std::vector<VRExprAssignment> vecAssign = ConvertVExpr2VRExpr::convert(pEventStatement->getStatementOrNullHandle());
    if (vecAssign.size() == 0)
        return vecAssign;

    CONST_FOR_EACH(pEvent, pEventStatement->getEventExpressionHandle()->getEventHandleContainer()) {
        if(pEvent->getExpressionHandle().valid()) {
            FOR_EACH(assign, vecAssign) {
                assign.addStaticSensitivity(ConvertVExpr2VRExpr::convert(pEvent->getExpressionHandle()));
            }
        } else if (pEvent->getIdentifierHandle().valid()) {
            FOR_EACH(assign, vecAssign) {
                assign.addStaticSensitivity(ConvertVExpr2VRExpr::convert(pEvent->getIdentifierHandle()));
            }
        } else if (pEvent->getPosedgeEventHandle().valid()) {
            FOR_EACH(assign, vecAssign) {
                assign.addPosedgeSensitivity(ConvertVExpr2VRExpr::convert(pEvent->getPosedgeEventHandle()));
            }
        } else if (pEvent->getNegedgeEventHandle().valid()) {
            FOR_EACH(assign, vecAssign) {
                assign.addNegedgeSensitivity(ConvertVExpr2VRExpr::convert(pEvent->getNegedgeEventHandle()));
            }
        }
    }

    return vecAssign;
}
    
VRExprExpression ConvertVExpr2VRExpr::convert(VExprPosedgeEventHandle pPosedgeEvent) {
    return ConvertVExpr2VRExpr::convert(pPosedgeEvent->getExpr());
}

VRExprExpression ConvertVExpr2VRExpr::convert(VExprNegedgeEventHandle pNegedgeEvent) {
    return ConvertVExpr2VRExpr::convert(pNegedgeEvent->getExpr());
}

std::vector<VRExprAssignment> ConvertVExpr2VRExpr::convert(VExprAlwaysHandle pAlways) {
    return ConvertVExpr2VRExpr::convert(pAlways->getStatementHandle());
}
    
unsigned int ConvertVExpr2VRExpr::convertToUnsignedNumber(VExprConstantExpressionHandle pConstantExpression) {
    if(!pConstantExpression->getConstantPrimaryHandle().valid()) 
        LOG(ERROR) << "range not primary " << pConstantExpression->getString(); 
    if (!pConstantExpression->getConstantPrimaryHandle()->getNumberHandle().valid())
       LOG(ERROR) << "range not number" << pConstantExpression->getString();
    if (!pConstantExpression->getConstantPrimaryHandle()->getNumberHandle()->getUnsignedNumberHandle().valid())
        LOG(ERROR) << "range not unsigned number" << pConstantExpression->getString();

    return pConstantExpression->getConstantPrimaryHandle()->getNumberHandle()->getUnsignedNumberHandle()->getValue();
}
