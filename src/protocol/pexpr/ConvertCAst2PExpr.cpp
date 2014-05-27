#include "ConvertCAst2PExpr.h"
PExprConstantHandle ConvertCAst2PExpr::convert(const CAstConstantHandle & pConstant){
    std::string constant;
    if( pConstant->integer_literal().valid() ){
        constant = pConstant->integer_literal()->integer_literal();
        return PExprConstant::makeHandle(constant);
    }
    else if( pConstant->floating_literal().valid() ){
        constant = pConstant->floating_literal()->floating_literal();
        return PExprConstant::makeHandle(constant);
    }
    else if( pConstant->bit_literal().valid() ){
        constant = pConstant->bit_literal()->bit_literal();
        return PExprConstant::makeHandle(constant);
    }
    else{
        assert(0);
    }
}

PExprAssertStatementHandle ConvertCAst2PExpr::convert(const CAstAssertStatementHandle & pAssertStatement){
    return PExprAssertStatement::makeHandle("0");
}

PExprReadStatementHandle ConvertCAst2PExpr::convert(const CAstReadStatementHandle & pReadStatement){
    std::string identifier = pReadStatement->container()[0]._pIdentifier0
                                           ->identifier()
                                           ;
    return PExprReadStatement::makeHandle(identifier);
}

PExprWriteStatementHandle ConvertCAst2PExpr::convert(const CAstWriteStatementHandle & pWriteStatement){
    std::string identifier = pWriteStatement->container()[0]._pIdentifier0
                                            ->identifier()
                                            ;
    return PExprWriteStatement::makeHandle(identifier);
}

PExprStateLabelHandle ConvertCAst2PExpr::convert(const CAstStateLabelHandle & pStateLabel){
    std::string identifier = pStateLabel->container()[0]._pIdentifier0
                                        ->identifier()
                                        ;
    return PExprStateLabel::makeHandle(identifier);
}

PExprGotoStatementHandle ConvertCAst2PExpr::convert(const CAstGotoStatementHandle & pGotoStatement){
    std::string identifier = pGotoStatement->container()[0]._pIdentifier0
                                           ->identifier()
                                           ;
    return PExprGotoStatement::makeHandle(identifier);
}

PExprBoolExpressionHandle ConvertCAst2PExpr::convert(const CAstBoolExpressionHandle & pBoolExpression){
    if ( pBoolExpression->bool_with_parenthesis().valid() ){
        assert(0);
    }
    else if ( pBoolExpression->bool_and().valid() ){
        PExprBoolExpressionHandle pFst = ConvertCAst2PExpr::convert(pBoolExpression->bool_and()->container()[0]._pBoolExpression0);
        PExprBoolExpressionHandle pSnd = ConvertCAst2PExpr::convert(pBoolExpression->bool_and()->container()[0]._pBoolExpression1);
        return PExprBoolExpression::makeBinaryAndHandle(pFst, pSnd);
    }
    else if ( pBoolExpression->bool_or().valid() ){
        PExprBoolExpressionHandle pFst = ConvertCAst2PExpr::convert(pBoolExpression->bool_or()->container()[0]._pBoolExpression0);
        PExprBoolExpressionHandle pSnd = ConvertCAst2PExpr::convert(pBoolExpression->bool_or()->container()[0]._pBoolExpression1);
        return PExprBoolExpression::makeBinaryOrHandle(pFst, pSnd);
    }
    else if ( pBoolExpression->bool_xor().valid() ){
        PExprBoolExpressionHandle pFst = ConvertCAst2PExpr::convert(pBoolExpression->bool_xor()->container()[0]._pBoolExpression0);
        PExprBoolExpressionHandle pSnd = ConvertCAst2PExpr::convert(pBoolExpression->bool_xor()->container()[0]._pBoolExpression1);
        return PExprBoolExpression::makeBinaryXorHandle(pFst, pSnd);
    }
    else if ( pBoolExpression->bool_not().valid() ){
        PExprBoolExpressionHandle bool_expression = ConvertCAst2PExpr::convert(pBoolExpression->bool_not()->container()[0]._pBoolExpression0);
        return PExprBoolExpression::makeUnaryNotHandle(bool_expression);
    }
    else if ( pBoolExpression->bool_constant().valid() ){
        std::string identifier = pBoolExpression->bool_constant()->container()[0]._pIdentifier0->identifier();
        PExprConstantHandle constant = ConvertCAst2PExpr::convert(pBoolExpression->bool_constant()->container()[0]._pConstant1);
        return PExprBoolExpression::makeConstantHandle(identifier, constant);
    }
    else if ( pBoolExpression->identifier().valid() ){
        std::string identifier = pBoolExpression->identifier()->identifier();
        return PExprBoolExpression::makeIdentifierHandle(identifier);
    }
    else
        assert(0);
}

PExprCheckStatementHandle ConvertCAst2PExpr::convert(const CAstCheckStatementHandle & pChecktatement){
    PExprBoolExpressionHandle pBoolExpression = ConvertCAst2PExpr::convert(pChecktatement->container()[0]._pBoolExpression0);
    return PExprCheckStatement::makeHandle(pBoolExpression);
}

PExprReadOrWriteOrCheckStatementHandle ConvertCAst2PExpr::convert(const CAstReadOrWriteOrCheckStatementHandle & pReadOrWriteOrCheckStatement){
    if( pReadOrWriteOrCheckStatement->read_statement().valid() ){
        PExprReadStatementHandle pReadStatement = ConvertCAst2PExpr::convert(pReadOrWriteOrCheckStatement->read_statement());
        return PExprReadOrWriteOrCheckStatement::makeHandle(pReadStatement);
    }
    else if( pReadOrWriteOrCheckStatement->write_statement().valid() ){
        PExprWriteStatementHandle pWriteStatement = ConvertCAst2PExpr::convert(pReadOrWriteOrCheckStatement->write_statement());
        return PExprReadOrWriteOrCheckStatement::makeHandle(pWriteStatement);
    }
    else if( pReadOrWriteOrCheckStatement->check_statement().valid() ){
        PExprCheckStatementHandle pCheckStatement = ConvertCAst2PExpr::convert(pReadOrWriteOrCheckStatement->check_statement());
        return PExprReadOrWriteOrCheckStatement::makeHandle(pCheckStatement);
    }
    else
        assert(0);
}

PExprIfStatementPrefixHandle ConvertCAst2PExpr::convert(const CAstIfStatementPrefixHandle & pIfStatementPrefix){
    PExprBoolExpressionHandle pBoolExpression = ConvertCAst2PExpr::convert(pIfStatementPrefix->container()[0]._pBoolExpression0);
    return PExprIfStatementPrefix::makeHandle(pBoolExpression);
}

PExprIfStatementWithoutGotoHandle ConvertCAst2PExpr::convert(const CAstIfStatementWithoutGotoHandle & pIfStatementWithoutGoto){
    PExprIfStatementPrefixHandle pIfStatementPrefix;
    std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC;
    std::vector<PExprIfStatementWithoutGotoHandle> vecWithoutGoto;
    if(pIfStatementWithoutGoto->only_rwc_without_goto().valid()){
        pIfStatementPrefix = ConvertCAst2PExpr::convert(pIfStatementWithoutGoto->only_rwc_without_goto()
                                                                               ->container()[0]._pIfStatementPrefix0);
        PExprReadOrWriteOrCheckStatementHandle pRWC = ConvertCAst2PExpr::convert(pIfStatementWithoutGoto->only_rwc_without_goto()
                                                                                                          ->container()[0]
                                                                                                          ._pReadOrWriteOrCheckStatement1);
        vecRWC.push_back(pRWC);
    }
    else if(pIfStatementWithoutGoto->only_without_goto_without_goto().valid()){
        pIfStatementPrefix = ConvertCAst2PExpr::convert(pIfStatementWithoutGoto->only_without_goto_without_goto()
                                                                          ->container()[0]._pIfStatementPrefix0);
        PExprIfStatementWithoutGotoHandle pWithoutGoto = ConvertCAst2PExpr::convert(pIfStatementWithoutGoto->only_without_goto_without_goto()
                                                                                                           ->container()[0]
                                                                                                           ._pIfStatementWithoutGoto1);
        vecWithoutGoto.push_back(pWithoutGoto);
    }
    else if(pIfStatementWithoutGoto->multi_without_goto().valid()){
        pIfStatementPrefix = ConvertCAst2PExpr::convert(pIfStatementWithoutGoto->multi_without_goto()
                                                                          ->container()[0]._pIfStatementPrefix0);
        CAstZeroOrMoreRWCOrWithoutGotoHandle pCAst = pIfStatementWithoutGoto->multi_without_goto()->container()[0]._pZeroOrMoreRWCOrWithoutGoto1;
        FOR_EACH(p, pCAst->container()){
            if(p._pRWCOrWithoutGoto->read_or_write_or_check_statement().valid()){
                vecRWC.push_back(ConvertCAst2PExpr::convert(p._pRWCOrWithoutGoto->read_or_write_or_check_statement()));
            }
            else if(p._pRWCOrWithoutGoto->if_statement_without_goto().valid()){
                vecWithoutGoto.push_back(ConvertCAst2PExpr::convert(p._pRWCOrWithoutGoto->if_statement_without_goto()));
            }
            else 
                assert(0);
        }
    }
    else
        assert(0);

    return PExprIfStatementWithoutGoto::makeHandle(pIfStatementPrefix, vecRWC, vecWithoutGoto);
}

PExprIfStatementWithGotoHandle ConvertCAst2PExpr::convert(const CAstIfStatementWithGotoHandle & pIfStatementWithGoto){
    PExprIfStatementPrefixHandle pIfStatementPrefix;
    PExprEndStatementHandle pEndStatement;
    std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
    if(pIfStatementWithGoto->only_end_with_goto().valid()){
        pIfStatementPrefix = ConvertCAst2PExpr::convert(pIfStatementWithGoto->only_end_with_goto()
                                                                            ->container()[0]._pIfStatementPrefix0);
        pEndStatement = ConvertCAst2PExpr::convert(pIfStatementWithGoto->only_end_with_goto()
                                                                       ->container()[0]._pEndStatement1);
    }
    else if(pIfStatementWithGoto->multi_with_goto().valid()){
        pIfStatementPrefix = ConvertCAst2PExpr::convert(pIfStatementWithGoto->multi_with_goto()
                                                                            ->container()[0]._pIfStatementPrefix0);
        pEndStatement = ConvertCAst2PExpr::convert(pIfStatementWithGoto->multi_with_goto()
                                                                       ->container()[0]._pEndStatement2);
        FOR_EACH(p, pIfStatementWithGoto->multi_with_goto()->container()[0]._pZeroOrMoreSpecific1->container()){
            vecSpecificUpdateStatement.push_back(ConvertCAst2PExpr::convert(p._pSpecificUpdateStatement));
        }
    }
    else
        assert(0);
    return PExprIfStatementWithGoto::makeHandle(pIfStatementPrefix, pEndStatement, vecSpecificUpdateStatement);
}

PExprEndStatementHandle ConvertCAst2PExpr::convert(const CAstEndStatementHandle & pEndStatement){
    if(pEndStatement->goto_statement().valid()){
        return PExprEndStatement::makeHandle(ConvertCAst2PExpr::convert(pEndStatement->goto_statement()));
    }
    else if(pEndStatement->assert_statement().valid()){
        return PExprEndStatement::makeHandle(ConvertCAst2PExpr::convert(pEndStatement->assert_statement()));
    }
    else
        assert(0);
}

PExprSpecificUpdateStatementHandle ConvertCAst2PExpr::convert(const CAstSpecificUpdateStatementHandle & pSpecificUpdateStatement){
    if(pSpecificUpdateStatement->read_or_write_or_check_statement().valid()){
        return PExprSpecificUpdateStatement::makeHandle(ConvertCAst2PExpr::convert(pSpecificUpdateStatement->read_or_write_or_check_statement()));
    }
    else if(pSpecificUpdateStatement->if_statement_without_goto().valid()){
        return PExprSpecificUpdateStatement::makeHandle(ConvertCAst2PExpr::convert(pSpecificUpdateStatement->if_statement_without_goto()));
    }
    else
        assert(0);
}

PExprAllUpdateStatementHandle ConvertCAst2PExpr::convert(const CAstAllUpdateStatementHandle & pAllUpdateStatement){
    if(pAllUpdateStatement->read_or_write_or_check_statement().valid()){
        return PExprAllUpdateStatement::makeHandle(ConvertCAst2PExpr::convert(pAllUpdateStatement->read_or_write_or_check_statement()));
    }
    else if(pAllUpdateStatement->if_statement_without_goto().valid()){
        return PExprAllUpdateStatement::makeHandle(ConvertCAst2PExpr::convert(pAllUpdateStatement->if_statement_without_goto()));
    }
    else
        assert(0);
}

PExprEdgeStatementHandle ConvertCAst2PExpr::convert(const CAstEdgeStatementHandle & pEdgeStatement){
    if(pEdgeStatement->all_if_with_goto().valid()){
        std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement;
        PExprIfStatementWithGotoHandle pWithGoto = ConvertCAst2PExpr::convert(pEdgeStatement->all_if_with_goto()
                                                                                            ->container()[0]._pIfStatementWithGoto1);
        FOR_EACH(p, pEdgeStatement->all_if_with_goto()->container()[0]._pZeroOrMoreAll0->container()){
            vecAllUpdateStatement.push_back(ConvertCAst2PExpr::convert(p._pAllUpdateStatement));
        }
        return PExprEdgeStatement::makeHandle(vecAllUpdateStatement, pWithGoto);
    }
    else if(pEdgeStatement->specific_end().valid()){
        std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
        PExprEndStatementHandle pEndStatement = ConvertCAst2PExpr::convert(pEdgeStatement->specific_end()
                                                                                         ->container()[0]._pEndStatement1);
        FOR_EACH(p, pEdgeStatement->specific_end()->container()[0]._pZeroOrMoreSpecific0->container()){
            vecSpecificUpdateStatement.push_back(ConvertCAst2PExpr::convert(p._pSpecificUpdateStatement));
        }
        return PExprEdgeStatement::makeHandle(vecSpecificUpdateStatement, pEndStatement);
    }
    else
        assert(0);
}

PExprTransitionStatementHandle ConvertCAst2PExpr::convert(const CAstTransitionStatementHandle & pTransitionStatement){
    std::vector<PExprEdgeStatementHandle> vecEdgeStatement;
    FOR_EACH(p, pTransitionStatement->one_or_more_edge()->container()){
        vecEdgeStatement.push_back(ConvertCAst2PExpr::convert(p._pEdgeStatement0));
    }
    return PExprTransitionStatement::makeHandle(vecEdgeStatement);
}

PExprStateStatementHandle ConvertCAst2PExpr::convert(const CAstStateStatementHandle & pStateStatement){
    PExprStateLabelHandle  pStateLabel = ConvertCAst2PExpr::convert(pStateStatement->container()[0]._pStateLabel0);
    PExprTransitionStatementHandle pTransitionStatement = ConvertCAst2PExpr::convert(pStateStatement->container()[0]._pTransitionStatement1);
    return PExprStateStatement::makeHandle(pStateLabel, pTransitionStatement);
}

PExprSourceTextHandle ConvertCAst2PExpr::convert(const CAstSourceTextHandle & pSourceText){
    std::vector<PExprStateStatementHandle> vecState;
    //std::cout << "*Debug: " << pSourceText->toString() << std::endl;
    CAstOneOrMoreStateHandle pOneOrMoreState = pSourceText->one_or_more_state();
    assert(pOneOrMoreState.valid());
    FOR_EACH(pState, pOneOrMoreState->container()){
        vecState.push_back(ConvertCAst2PExpr::convert(pState._pStateStatement0));
    }
    return PExprSourceText::makeHandle(vecState);
}
