CODE_DIRS = parseSourceText 
TOP=../../..

all :
	make update
	make binary
	make lib
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make all) \
		done

update : CAst.h CAst.cpp CAstParser.h CAstParser.cpp 

CAst.h : $(TOP)/src/protocol/past_generation/CAst.h
	cp $< .

CAst.cpp : $(TOP)/src/protocol/past_generation/CAst.cpp
	cp $< .

CAstParser.h : $(TOP)/src/protocol/past_generation/CAstParser.h
	cp $< .

CAstParser.cpp : $(TOP)/src/protocol/past_generation/CAstParser.cpp
	cp $< .

clean : 
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make clean) \
		done


check_dot :
	./run_check_dot.py

-include $(TOP)/src/mkfile/Makefile
