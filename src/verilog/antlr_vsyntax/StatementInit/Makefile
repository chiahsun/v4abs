TOP ?= ../
OTHER_PARSER_RULE ?= Expression.g4 BlockingAssignment.g4 ConditionalStatement.g4 CaseStatement.g4 Statement.g4 SeqBlock.g4 NonBlockingAssignment.g4 ProceduralContinuousAssignment.g4 ProceduralTimingControlStatement.g4 LoopStatement.g4

include $(TOP)/Makefile.in

LoopStatement.g4 : ../LoopStatement/LoopStatement.g4
	cp $< .

ProceduralTimingControlStatement.g4 : ../ProceduralTimingControlStatement/ProceduralTimingControlStatement.g4
	cp $< .

ProceduralContinuousAssignment.g4 : ../ProceduralContinuousAssignment/ProceduralContinuousAssignment.g4
	cp $< .

SeqBlock.g4 : ../SeqBlock/SeqBlock.g4
	cp $< .

CaseStatement.g4 : ../CaseStatement/CaseStatement.g4
	cp $< .

ConditionalStatement.g4 : ../ConditionalStatement/ConditionalStatement.g4
	cp $< .

NonBlockingAssignment.g4 : ../NonBlockingAssignmentInit/NonBlockingAssignment.g4
	cp $< .

BlockingAssignment.g4 : ../BlockingAssignmentInit/BlockingAssignment.g4
	cp $< .

Expression.g4 : ../ExpressionInit/Expression.g4
	cp $< .
