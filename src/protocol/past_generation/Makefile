TOP=../../..

TCLS=$(wildcard *.tcl)
PYS=$(wildcard *.py)

all :
	make update
	make binary
	make lib

update : CAst.h

CAst.h : $(TCLS) $(PYS)
	./generate.py


-include $(TOP)/src/mkfile/Makefile
