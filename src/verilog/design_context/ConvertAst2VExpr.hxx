#ifndef CONVERT_AST_TO_VEXPR_H
#define CONVERT_AST_TO_VEXPR_H 

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << " @ " << __FILE__ << ":" << __LINE__ <<std::endl; } while(0)

#include "ForEach.h"
#include "Ast.h"
#include "VExpr.h"
#include "ConvertUtil.h"

/**
 * Reference
 *  1. Why not specialize function templates
 *  http://www.gotw.ca/publications/mill17.htm
 */
template <class _VExprHandle, class _AstHandle>
class ConvertAst2VExpr {
public:
    typedef _AstHandle ast_handle_type;
    typedef _VExprHandle vexpr_handle_type;
    static vexpr_handle_type convert(const _AstHandle & pAst) {
        STATIC_ASSERT(1 == 0);
    }
    
    static VExprUnsignedNumberHandle convert(const AstUnsignedNumberHandle & pAst);
    
};


template <>
VExprUnsignedNumberHandle ConvertAst2VExpr<VExprUnsignedNumberHandle, AstUnsignedNumberHandle>::convert(const AstUnsignedNumberHandle & pAstUnsignedNumber) {
    unsigned int val = unsigned_int_of_string(pAstUnsignedNumber->unsigned_number());
    return VExprUnsignedNumberHandle(VExprUnsignedNumber(val));
}

template <>
VExprBinaryNumberHandle ConvertAst2VExpr<VExprBinaryNumberHandle, AstBinaryNumberHandle>::convert(const AstBinaryNumberHandle & pBinaryNumber) {
    return VExprBinaryNumberHandle(VExprBinaryNumber(pBinaryNumber->binary_number()));
}

template <>
VExprOctalNumberHandle ConvertAst2VExpr<VExprOctalNumberHandle, AstOctalNumberHandle>::convert(const AstOctalNumberHandle & pOctalNumber) {
    return VExprOctalNumberHandle(VExprOctalNumber(pOctalNumber->octal_number()));
}

template <>
VExprDecimalNumberHandle ConvertAst2VExpr<VExprDecimalNumberHandle, AstDecimalNumberHandle>::convert(const AstDecimalNumberHandle & pDecimalNumber) {
    return VExprDecimalNumberHandle(VExprDecimalNumber(pDecimalNumber->decimal_number()));
}

template <>
VExprHexNumberHandle ConvertAst2VExpr<VExprHexNumberHandle, AstHeximalNumberHandle>::convert(const AstHeximalNumberHandle & pHexNumber) {
    return VExprHexNumberHandle(VExprHexNumber(pHexNumber->heximal_number()));
}

template <>
VExprNumberHandle ConvertAst2VExpr<VExprNumberHandle, AstNumberHandle>::convert(const AstNumberHandle & pNumber) {
    if (pNumber->unsigned_number().valid()) {
        VExprUnsignedNumberHandle pUnsignedNumber = ConvertAst2VExpr<VExprUnsignedNumberHandle, AstUnsignedNumberHandle>::convert(pNumber->unsigned_number());
        return VExprNumberHandle(VExprNumber(pUnsignedNumber));
    } else if (pNumber->binary_number().valid()) {
        VExprBinaryNumberHandle pBinaryNumber = ConvertAst2VExpr<VExprBinaryNumberHandle, AstBinaryNumberHandle>::convert(pNumber->binary_number());
        return VExprNumberHandle(VExprNumber(pBinaryNumber));
    } else if (pNumber->octal_number().valid()) {
        VExprOctalNumberHandle pOctalNumber = ConvertAst2VExpr<VExprOctalNumberHandle, AstOctalNumberHandle>::convert(pNumber->octal_number());
        return VExprNumberHandle(VExprNumber(pOctalNumber));
    } else if (pNumber->decimal_number().valid()) {
        VExprDecimalNumberHandle pDecimalNumber = ConvertAst2VExpr<VExprDecimalNumberHandle, AstDecimalNumberHandle>::convert(pNumber->decimal_number());
        return VExprNumberHandle(VExprNumber(pDecimalNumber));
    } else if (pNumber->heximal_number().valid()) {
        VExprHexNumberHandle pHeximalNumber = ConvertAst2VExpr<VExprHexNumberHandle, AstHeximalNumberHandle>::convert(pNumber->heximal_number());
        return VExprNumberHandle(VExprNumber(pHeximalNumber));
    }
    assert(0);
}

template <>
VExprSingleIdentifierHandle ConvertAst2VExpr<VExprSingleIdentifierHandle, AstSimpleIdentifierHandle>::convert(const AstSimpleIdentifierHandle & pAstSimpleIdentifier) {
    return VExprSingleIdentifierHandle(VExprSingleIdentifier(pAstSimpleIdentifier->simple_identifier()));
}

template <>
VExprSingleIdentifierHandle ConvertAst2VExpr<VExprSingleIdentifierHandle, AstSingleIdentifierHandle>::convert(const AstSingleIdentifierHandle & pAstSingleIdentifier) {
    return ConvertAst2VExpr<VExprSingleIdentifierHandle, AstSimpleIdentifierHandle>::convert(pAstSingleIdentifier->simple_identifier());
}

template <>
VExprHierIdentifierHandle ConvertAst2VExpr<VExprHierIdentifierHandle, AstMultiIdentifierHandle>::convert(const AstMultiIdentifierHandle & pAstMultiIdentifier) {
    std::vector<AstSingleIdentifierHandle> vecSingleIdentifier;
    AstSingleIdentifierHandle pAstSingleIdentifier = pAstMultiIdentifier->element(0)._pSingleIdentifier0;
    vecSingleIdentifier.push_back(pAstSingleIdentifier);

    CONST_FOR_EACH(elem, pAstMultiIdentifier->element(0)._pZeroOrMoreDotSingleIdentifier1->container()) {
        vecSingleIdentifier.push_back(elem._pSingleIdentifier);
    }

    std::vector<std::string> vecString;

    CONST_FOR_EACH(x, vecSingleIdentifier) {
        vecString.push_back(x->simple_identifier()->simple_identifier());
    }

    return VExprHierIdentifierHandle(VExprHierIdentifier(vecString));

}

template <>
VExprIdentifierHandle ConvertAst2VExpr<VExprIdentifierHandle, AstIdentifierHandle>::convert(const AstIdentifierHandle & pAstIdentifier) {
    if (pAstIdentifier->single_identifier().valid()) {
        VExprSingleIdentifierHandle pSingleIdentifier = ConvertAst2VExpr<VExprSingleIdentifierHandle, AstSingleIdentifierHandle>::convert(pAstIdentifier->single_identifier());
        return VExprIdentifierHandle(VExprIdentifier(pSingleIdentifier));
    } else if (pAstIdentifier->multi_identifier().valid()) {
        VExprHierIdentifierHandle pHierIdentifier = ConvertAst2VExpr<VExprHierIdentifierHandle, AstMultiIdentifierHandle>::convert(pAstIdentifier->multi_identifier());
        return VExprIdentifierHandle(VExprIdentifierHandle(pHierIdentifier));
    }
    assert(0);
}



template <>
VExprModuleHandle ConvertAst2VExpr<VExprModuleHandle, AstSourceTextHandle>::convert(const AstSourceTextHandle & pSourceText) {

    const AstOneOrMoreDescriptionHandle pOneOrMoreDescription = 
        pSourceText->one_or_more_description();
    
    assert(pOneOrMoreDescription->element_size() == 1);

    AstDescriptionHandle pDescription =
        pOneOrMoreDescription->element(0)._pDescription0;

    AstModuleDeclarationHandle pModuleDeclaration =
        pDescription->module_declaration();

    AstIdentifierHandle pIdentifier =
        pModuleDeclaration->element(0)._pIdentifier1;

    AstSingleIdentifierHandle pSingleIdentifier =
        pIdentifier->single_identifier();

    AstZeroOrMoreModuleItemHandle pZeroOrMoreModuleItem =
        pModuleDeclaration->element(0)._pZeroOrMoreModuleItem3;

    VExprParameterDeclarationHandle pParameterDeclaration =
        VExprParameterDeclarationHandle(VExprParameterDeclaration());


    FOR_EACH(item, pZeroOrMoreModuleItem->container()) {
        AstModuleItemHandle pAstModuleItem = item._pModuleItem;
        if (pAstModuleItem->module_item_declaration().valid()) {
            AstModuleItemDeclarationHandle pAstModuleItemDeclaration = pAstModuleItem->module_item_declaration();
            if (pAstModuleItemDeclaration->parameter_declaration().valid()) {
                AstParameterDeclarationHandle pAstParameterDeclaration =
                    pAstModuleItemDeclaration->parameter_declaration();
                AstListOfParamAssignmentHandle pAstListOfParamAssignment =
                    pAstParameterDeclaration->element(0)._pListOfParamAssignment1;
                
                AstParamAssignmentHandle pAstParamAssignment =
                    pAstListOfParamAssignment->element(0)._pParamAssignment0;

                AstIdentifierHandle pAstIdentifier =
                    pAstParamAssignment->element(0)._pIdentifier0;
                AstExpressionHandle pAstExpression =
                    pAstParamAssignment->element(0)._pExpression1;

                VExprIdentifierHandle pParameterIdentifier =
                    ConvertAst2VExpr<VExprIdentifierHandle, AstIdentifierHandle>::convert(pAstIdentifier);


                std::cout << "*Debug: " << pParameterIdentifier->getString() << std::endl;


//                VExprParaAssignmentHandle pParaAssignment = VExprParaAssignmentHandle(VExprParamAssignment());


            }
        }
    }


    return VExprModuleHandle(VExprModule(vexpr_identifier_mk_single_identifier(pSingleIdentifier->simple_identifier()->simple_identifier())));
}

#endif // CONVERT_AST_TO_VEXPR_H
