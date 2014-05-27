#ifndef VEXPR_SEQ_BLOCK_H
#define VEXPR_SEQ_BLOCK_H

#include "VExprStatementInterface.h"
#include "VExprStatement.h"

VExprSeqBlockHandle vexpr_seq_block_mk();
VExprSeqBlockHandle vexpr_seq_block_mk(VExprStatementHandle pStatement);

class VExprSeqBlock : public VExprStatementInterface {
    std::vector<VExprStatementHandle> _vecStatement;

public:
    VExprSeqBlock();
    VExprSeqBlock(const std::vector<VExprStatementHandle> vecStatement);
    VExprSeqBlock(VExprStatementHandle pStatement);
    void push_back(VExprStatementHandle pStatement);

    unsigned int getStatementHandleSize() const;
    VExprStatementHandle getStatementHandle(unsigned int pos) const;

    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;

};

#endif // VEXPR_SEQ_BLOCK_H
