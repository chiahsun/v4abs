#include "VExprLoopStatement.h"
#include "VExprStatement.h"
#include "Indent.h"

VExprLoopStatement::VExprLoopStatement
  ( VExprRegAssignmentHandle pForInit
  , VExprExpressionHandle pForCond
  , VExprRegAssignmentHandle pForAssign
  , VExprStatementHandle pStatement)
  : _pForInit(pForInit)
  , _pForCond(pForCond)
  , _pForAssign(pForAssign)
  , _pStatement(pStatement)
  { }

VExprRegAssignmentHandle& VExprLoopStatement::getForInitHandle()
  { return _pForInit; }

VExprExpressionHandle& VExprLoopStatement::getForCondHandle()
  { return _pForCond; }

VExprRegAssignmentHandle& VExprLoopStatement::getForAssignHandle()
  { return _pForAssign; }

VExprStatementHandle& VExprLoopStatement::getStatementHandle()
  { return _pStatement; }

const VExprRegAssignmentHandle& VExprLoopStatement::getForInitHandle() const
  { return _pForInit; }

const VExprExpressionHandle& VExprLoopStatement::getForCondHandle() const
  { return _pForCond; }

const VExprRegAssignmentHandle& VExprLoopStatement::getForAssignHandle() const
  { return _pForAssign; }

const VExprStatementHandle& VExprLoopStatement::getStatementHandle() const
  { return _pStatement; }


std::string VExprLoopStatement::getString() const
  { return getString(0); }

std::string VExprLoopStatement::getString(unsigned int indentLevel) const {
    std::string s = indent(indentLevel) + "for (";
    s += getForInitHandle()->getString();
    s = s + "; " + getForCondHandle()->getString();
    s = s + "; " + getForAssignHandle()->getString() + ")\n";

    s = s + getStatementHandle()->getString(indentLevel+1);
    return s;
}

VExprLoopStatementHandle VExprLoopStatement::flatten(VExprIdentifierHandle pInstName) const {
    return VExprLoopStatementHandle(VExprLoopStatement(
              getForInitHandle()->flatten(pInstName)
            , getForCondHandle()->flatten(pInstName)
            , getForAssignHandle()->flatten(pInstName)
            , getStatementHandle()->flatten(pInstName)
            ));
}
