#include "VExprStatement.h"
#include "Indent.h"
#include "utility/log/Log.h"

VExprStatementHandle vexpr_statement_mk_blocking_assignment(VExprBlockingAssignmentHandle pBlockingAssign) {
    return VExprStatementHandle(VExprStatement(pBlockingAssign));
}

VExprStatementHandle vexpr_statement_mk_non_blocking_assignment(VExprNonBlockingAssignmentHandle pNonBlockingAssign) {
    return VExprStatementHandle(VExprStatement(pNonBlockingAssign));
}

VExprStatementHandle vexpr_statement_mk_seq_block() {
    return VExprStatementHandle(VExprStatement(vexpr_seq_block_mk()));
}

VExprStatementHandle vexpr_statement_mk_seq_block(VExprSeqBlockHandle pSeqBlock) {
    return VExprStatementHandle(VExprStatement(pSeqBlock));
}

VExprStatementHandle vexpr_statement_mk_conditional(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen) {
    return VExprStatementHandle(VExprStatement(vexpr_conditional_mk_if_then(pIf, pThen)));
}

VExprStatementHandle vexpr_statement_mk_conditional(VExprExpressionHandle pIf, VExprStatementOrNullHandle pThen, VExprStatementOrNullHandle pElse) {
    return VExprStatementHandle(VExprStatement(vexpr_conditional_mk_if_then_else(pIf, pThen, pElse)));
}


VExprStatement::VExprStatement(VExprBlockingAssignmentHandle pBlockingAssign)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pBlockingAssign))
  , _pBlockingAssign(pBlockingAssign)
  { }
    
VExprStatement::VExprStatement(VExprNonBlockingAssignmentHandle pNonBlockingAssign)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pNonBlockingAssign))
  , _pNonBlockingAssign(pNonBlockingAssign)
  { }
    
  
VExprStatement::VExprStatement(VExprSeqBlockHandle pSeqBlock)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pSeqBlock))
  , _pSeqBlock(pSeqBlock)
  { }
    
VExprStatement::VExprStatement(VExprConditionalStatementHandle pConditional)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pConditional))
  , _pConditional(pConditional)
  { }
    
VExprStatement::VExprStatement(VExprCaseStatementHandle pCaseStatement)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pCaseStatement))
  , _pCaseStatement(pCaseStatement)
  { }
    
VExprStatement::VExprStatement(VExprProceduralContinuousAssignmentHandle pProceduralContinuousAssignment)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pProceduralContinuousAssignment))
  , _pProceduralContinuousAssignment(pProceduralContinuousAssignment)
  { }
    
VExprStatement::VExprStatement(VExprLoopStatementHandle pLoopStatement)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pLoopStatement))
  , _pLoopStatement(pLoopStatement)
  { }
VExprStatement::VExprStatement(VExprEventStatementHandle pEventStatement)
  : _pInterface(shared_ptr_cast<VExprStatementInterface>(pEventStatement))
  , _pEventStatement(pEventStatement)
  { }

const VExprBlockingAssignmentHandle& VExprStatement::getBlockingAssignHandle() const
  { return _pBlockingAssign; }
    
const VExprNonBlockingAssignmentHandle& VExprStatement::getNonBlockingAssignHandle() const
  { return _pNonBlockingAssign; }
    
const VExprSeqBlockHandle& VExprStatement::getSeqBlockHandle() const
  { return _pSeqBlock; }
    
const VExprConditionalStatementHandle& VExprStatement::getConditionalHandle() const
  { return _pConditional; }
    
const VExprCaseStatementHandle& VExprStatement::getCaseStatementHandle() const
  { return _pCaseStatement; }

const VExprProceduralContinuousAssignmentHandle& VExprStatement::getProceduralContinuousAssignmentHandle() const
  { return _pProceduralContinuousAssignment; }

const VExprLoopStatementHandle& VExprStatement::getLoopStatementHandle() const
  { return _pLoopStatement; }

const VExprEventStatementHandle& VExprStatement::getEventStatementHandle() const
  { return _pEventStatement; }

VExprBlockingAssignmentHandle& VExprStatement::getBlockingAssignHandle() 
  { return _pBlockingAssign; }
    
VExprNonBlockingAssignmentHandle& VExprStatement::getNonBlockingAssignHandle() 
  { return _pNonBlockingAssign; }
    
VExprSeqBlockHandle& VExprStatement::getSeqBlockHandle() 
  { return _pSeqBlock; }
    
VExprConditionalStatementHandle& VExprStatement::getConditionalHandle()
  { return _pConditional; }
    
VExprCaseStatementHandle& VExprStatement::getCaseStatementHandle() 
  { return _pCaseStatement; }

VExprProceduralContinuousAssignmentHandle& VExprStatement::getProceduralContinuousAssignmentHandle()
  { return _pProceduralContinuousAssignment; }

VExprLoopStatementHandle& VExprStatement::getLoopStatementHandle()
  { return _pLoopStatement; }

VExprEventStatementHandle& VExprStatement::getEventStatementHandle()
  { return _pEventStatement; }

std::string VExprStatement::getString() const {
    return getString(0);
}

std::string VExprStatement::getString(unsigned int indentLevel) const {
    std::string s = _pInterface->getString(indentLevel);
    if ( getBlockingAssignHandle().valid() 
      || getNonBlockingAssignHandle().valid())
        s += ";\n";
    return s;
}
    
VExprStatementOrNullHandle VExprStatement::toStatementOrNullHandle() const {
    return VExprStatementOrNullHandle(VExprStatementOrNull(VExprStatementHandle(*this)));
}
    
VExprStatementHandle VExprStatement::flatten(VExprIdentifierHandle pInstName) const {
    if (getBlockingAssignHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getBlockingAssignHandle()->flatten(pInstName)));
    } else if (getNonBlockingAssignHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getNonBlockingAssignHandle()->flatten(pInstName)));
    } else if (getSeqBlockHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getSeqBlockHandle()->flatten(pInstName)));
    } else if (getConditionalHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getConditionalHandle()->flatten(pInstName)));
    } else if (getCaseStatementHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getCaseStatementHandle()->flatten(pInstName)));
    } else if (getProceduralContinuousAssignmentHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getProceduralContinuousAssignmentHandle()->flatten(pInstName)));
    } else if (getLoopStatementHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getLoopStatementHandle()->flatten(pInstName)));
    } else if (getEventStatementHandle().valid()) {
        return VExprStatementHandle(VExprStatement(getEventStatementHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
