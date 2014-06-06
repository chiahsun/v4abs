#include "VExprCaseStatement.h"
#include "Indent.h"
#include "VExprStatement.h"
#include "VExprStatementOrNull.h"
#include "nstl/for_each/ForEach.h"


VExprCaseStatement::VExprCaseStatement(VExprExpressionHandle pExpr)
  : _pExpr(pExpr)
  { }
    
VExprCaseStatement::VExprCaseStatement(VExprExpressionHandle pExpr, const std::vector<VExprCaseItemHandle> & vecCaseItem)
  : _pExpr(pExpr)
  , _vecCaseItem(vecCaseItem)
  { }
    
const VExprExpressionHandle& VExprCaseStatement::getConstExpressionHandle() const 
  { return _pExpr; }
    
VExprExpressionHandle& VExprCaseStatement::getExpressionHandle()
  { return _pExpr; }
    
const std::vector<VExprCaseItemHandle>& VExprCaseStatement::getConstCaseItemContainer() const
  { return _vecCaseItem; }

std::vector<VExprCaseItemHandle>& VExprCaseStatement::getCaseItemContainer()
  { return _vecCaseItem; }

void VExprCaseStatement::push_back(VExprCaseItemHandle pCaseItem)
  { _vecCaseItem.push_back(pCaseItem); }

std::string VExprCaseStatement::getString() const 
  { return getString(0); }

std::string VExprCaseStatement::getString(unsigned int indentLevel) const {
    std::string s;
    s = s +indent(indentLevel) + "case ("+ getConstExpressionHandle()->getString() + ")\n";
    int nextIndentLevel = indentLevel + 1;
    CONST_FOR_EACH(x, _vecCaseItem) {
        s = s + indent(nextIndentLevel) + x->getString();
    }
    s = s + indent(indentLevel) + "endcase\n";
    return s;
}

VExprStatementHandle VExprCaseStatement::toStatemetHandle() const {
    return VExprStatementHandle(VExprStatement(VExprCaseStatementHandle(*this)));
}

VExprStatementOrNullHandle VExprCaseStatement::toStatemetOrNullHandle() const {
    return VExprStatementOrNullHandle(VExprStatementOrNull(toStatemetHandle()));
}
    
VExprCaseStatementHandle VExprCaseStatement::flatten(VExprIdentifierHandle pInstName) const {
    VExprExpressionHandle pFlatExpr = getConstExpressionHandle()->flatten(pInstName);
    std::vector<VExprCaseItemHandle> vecFlatCaseItem;

    CONST_FOR_EACH(pCaseItem, getConstCaseItemContainer()) {
        vecFlatCaseItem.push_back(pCaseItem->flatten(pInstName));
    }

    return VExprCaseStatementHandle(VExprCaseStatement(pFlatExpr, vecFlatCaseItem));
}

VExprCaseItem::VExprCaseItem(VExprExpressionHandle pExpr, VExprStatementOrNullHandle pStatementOrNull) {
    _vecExpression.push_back(pExpr);
    _pStatementOrNull = pStatementOrNull;
}
VExprCaseItem::VExprCaseItem(const std::vector<VExprExpressionHandle> & vecExpr, VExprStatementOrNullHandle pStatementOrNull) {
    _vecExpression = vecExpr;
    _pStatementOrNull = pStatementOrNull;
}
// Default case
VExprCaseItem::VExprCaseItem(VExprStatementOrNullHandle pStatementOrNull) {
    _pStatementOrNull = pStatementOrNull;
}
    
const std::vector<VExprExpressionHandle>& VExprCaseItem::getExpressionHandleContainer() const 
  { return _vecExpression; }

std::vector<VExprExpressionHandle>& VExprCaseItem::getExpressionHandleContainer() 
  { return _vecExpression; }


const VExprStatementOrNullHandle& VExprCaseItem::getStatementOrNullHandle() const
  { return _pStatementOrNull; }
VExprStatementOrNullHandle& VExprCaseItem::getStatementOrNullHandle()
  { return _pStatementOrNull; }

std::string VExprCaseItem::getString() const {
    return getString(0);
}

std::string VExprCaseItem::getString(unsigned int indentLevel) const  {
    std::string s;
    if (_vecExpression.size() == 0)
        s = s + indent(indentLevel) + "default: ";
    else {
        s = s + indent(indentLevel) + getExpressionHandleContainer()[0]->getString();
        for (size_t i = 1; i < getExpressionHandleContainer().size(); ++i) {
            s = s + ", " + getExpressionHandleContainer()[i]->getString();
        }
        s += ":\n";
    }
    s += getStatementOrNullHandle()->getString(indentLevel+2);
    return s;
}
    
VExprCaseItemHandle VExprCaseItem::flatten(VExprIdentifierHandle pInstName) const {
    std::vector<VExprExpressionHandle> vecFlatExpression;
    VExprStatementOrNullHandle pFlatStatementOrNull = getStatementOrNullHandle()->flatten(pInstName);

    CONST_FOR_EACH(pExpression, getExpressionHandleContainer()) {
        vecFlatExpression.push_back(pExpression->flatten(pInstName));
    }

    return VExprCaseItemHandle(VExprCaseItem(vecFlatExpression, pFlatStatementOrNull));
}
