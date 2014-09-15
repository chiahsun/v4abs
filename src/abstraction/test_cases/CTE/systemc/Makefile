TOP=../../../../..

SYSTEMC_HOME=/home/chiahsun/tools/systemc/systemc-2.3.0
SYSTEMC_INCLUDE=$(SYSTEMC_HOME)/include
SYSTEMC_LIB=$(SYSTEMC_HOME)/lib-linux64

CFLAGS = -Wno-long-long  -pedantic -Wall 
CFLAGS = -I$(SYSTEMC_INCLUDE)
CFLAGS += -O2 -g

LFLAGS = -L$(SYSTEMC_LIB) -lsystemc -lm -lpthread -lsystemc

export CFLAGS
export LFLAGS

all :
	make binary
	make lib


-include $(TOP)/src/mkfile/Makefile

check: testCTE.out
	@./testCTE.out ../pattern/pat1.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden1.dat
	@./testCTE.out ../pattern/pat2.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden2.dat
	@./testCTE.out ../pattern/pat3.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden3.dat
	@./testCTE.out ../pattern/pat4.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden4.dat
	@rm -f LOG1 LOG2
