#include "VExprConditionalStatement.h"
#include "Indent.h"

VExprConditionalStatementHandle vexpr_conditional_mk_if_then(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen) {
    return VExprConditionalStatementHandle(VExprConditionalStatement(pIf, pThen));
}

VExprConditionalStatementHandle vexpr_conditional_mk_if_then_else(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse) {
    return VExprConditionalStatementHandle(VExprConditionalStatement(pIf, pThen, pElse));
}

VExprConditionalStatement::VExprConditionalStatement(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen)
  : _pIf(pIf)
  , _pThen(pThen)
  { }

VExprConditionalStatement::VExprConditionalStatement(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse)
  : _pIf(pIf)
  , _pThen(pThen)
  , _pElse(pElse)
  { }

VExprExpressionHandle VExprConditionalStatement::getIf() const
  { return _pIf; }

VExprStatementOrNullHandle VExprConditionalStatement::getThen() const
  { return _pThen; }
    
VExprStatementOrNullHandle VExprConditionalStatement::getElse() const
  { return _pElse; } 

std::string VExprConditionalStatement::getString() const {
    return getString(0);
}

std::string VExprConditionalStatement::getString(unsigned int indentLevel) const {
    std::string s = indent(indentLevel) + "if (" + getIf()->getString() + ") begin\n"
                 + getThen()->getString(indentLevel+1);
    if (getElse().valid() && getElse()->getStatementHandle().valid()) {
        s = s + indent(indentLevel) + "end\n"
              + indent(indentLevel) + "else begin\n"
          + getElse()->getString(indentLevel+1);
    } 
//    if (indentLevel != 0)
//        s += indent(1);
//    s += "}\n";
    
    s = s + indent(indentLevel) + "end\n";
         
    return s;
}
    
VExprConditionalStatementHandle VExprConditionalStatement::flatten(VExprIdentifierHandle pInstName) const {
    VExprExpressionHandle pFlatIf = getIf()->flatten(pInstName);
    VExprStatementOrNullHandle pFlatThen = getThen()->flatten(pInstName);

    if (getElse().valid()) {
        VExprStatementOrNullHandle pFlatElse = getElse()->flatten(pInstName);
        return VExprConditionalStatementHandle(VExprConditionalStatement(pFlatIf, pFlatThen, pFlatElse));
    } else {
        return VExprConditionalStatementHandle(VExprConditionalStatement(pFlatIf, pFlatThen));
    }
    assert(0);
}
    
VExprConditionalStatementHandle VExprConditionalStatement::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    VExprExpressionHandle pNewIf = getIf()->substitute(pDst, hashSrc);
    VExprStatementOrNullHandle pNewThen = getThen()->substitute(pDst, hashSrc);

    if (getElse().valid()) {
        VExprStatementOrNullHandle pNewElse = getElse()->substitute(pDst, hashSrc);
        return VExprConditionalStatementHandle(VExprConditionalStatement(pNewIf, pNewThen, pNewElse));
    } else {
        return VExprConditionalStatementHandle(VExprConditionalStatement(pNewIf, pNewThen));
    }
    assert(0);
}
