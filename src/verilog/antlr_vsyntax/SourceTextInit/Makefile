TOP ?= ../
OTHER_PARSER_RULE ?= Expression.g4 BlockingAssignment.g4 ConditionalStatement.g4 CaseStatement.g4 Statement.g4 SeqBlock.g4 NonBlockingAssignment.g4 ProceduralContinuousAssignment.g4 ProceduralTimingControlStatement.g4 LoopStatement.g4 GateInstantiation.g4 ContinuousAssign.g4 ModuleItemDeclaration.g4 ModuleInstantiation.g4 ModuleItem.g4 ModuleDeclaration.g4 SourceText.g4 

include $(TOP)/Makefile.in

ModuleDeclaration.g4 : ../ModuleDeclarationInit/ModuleDeclaration.g4
	cp $< .

Statement.g4 : ../StatementInit/Statement.g4
	cp $< .

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

GateInstantiation.g4 : ../GateInstantiationInit/GateInstantiation.g4
	cp $< .

ContinuousAssign.g4 : ../ContinuousAssignInit/ContinuousAssign.g4
	cp $< .

ModuleItemDeclaration.g4 : ../ModuleItemDeclarationInit/ModuleItemDeclaration.g4
	cp $< .

ModuleInstantiation.g4 : ../ModuleInstantiationInit/ModuleInstantiation.g4
	cp $< .

ModuleItem.g4 : ../ModuleItemInit/ModuleItem.g4
	cp $< .
