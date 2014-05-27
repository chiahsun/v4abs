TOP ?= ../
OTHER_PARSER_RULE ?= Expression.g4 BlockingAssignment.g4 NonBlockingAssignment.g4 

include $(TOP)/Makefile.in


BlockingAssignment.g4 : ../BlockingAssignmentInit/BlockingAssignment.g4
	cp $< .

Expression.g4 : ../ExpressionInit/Expression.g4
	cp $< .
