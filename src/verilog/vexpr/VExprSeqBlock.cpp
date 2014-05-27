#include "VExprSeqBlock.h"
#include "Indent.h"

VExprSeqBlockHandle vexpr_seq_block_mk() {
    return VExprSeqBlockHandle(VExprSeqBlock());
}

VExprSeqBlockHandle vexpr_seq_block_mk(VExprStatementHandle pStatement) {
    return VExprSeqBlockHandle(VExprSeqBlock(pStatement));
}

VExprSeqBlock::VExprSeqBlock() { }
    
VExprSeqBlock::VExprSeqBlock(const std::vector<VExprStatementHandle> vecStatement)
  : _vecStatement(vecStatement)
  { }

VExprSeqBlock::VExprSeqBlock(VExprStatementHandle pStatement) {
    push_back(pStatement);
}
    
void VExprSeqBlock::push_back(VExprStatementHandle pStatement) {
    _vecStatement.push_back(pStatement);
}

unsigned int VExprSeqBlock::getStatementHandleSize() const
  { return _vecStatement.size(); }
    
VExprStatementHandle VExprSeqBlock::getStatementHandle(unsigned int pos) const
  { return _vecStatement[pos]; }

std::string VExprSeqBlock::getString() const
  { return getString(0); }
    
std::string VExprSeqBlock::getString(unsigned int indentLevel) const {
    std::string s = indent(indentLevel) + "begin\n";
    for (unsigned int i = 0; i < getStatementHandleSize(); ++i)
        s = s + getStatementHandle(i)->getString(indentLevel+1);
    s = s + indent(indentLevel) + "end\n";
    return s;
}
