CODE_DIRS = parseExpression parseSourceText
TOP=../../..

all :
	make update
	make binary
	make lib
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make all) \
		done

update : Ast.h Ast.cpp AstParser.h AstParser.cpp


%.h : $(TOP)/src/verilog/vast_generation/%.h
	cp $< .

%.cpp : $(TOP)/src/verilog/vast_generation/%.cpp
	cp $< .

clean : 
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make clean) \
		done


check_dot :
	./run_check_dot.py

-include $(TOP)/src/mkfile/Makefile
