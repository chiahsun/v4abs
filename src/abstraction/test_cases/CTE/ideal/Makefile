TOP=../../../../..


all :
	make binary
	make lib


-include $(TOP)/src/mkfile/Makefile

check: testCTEIdeal.out
	@./$< ../pattern/pat1.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden1.dat
	@./$< ../pattern/pat2.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden2.dat
	@./$< ../pattern/pat3.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden3.dat
	@./$< ../pattern/pat4.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden4.dat
	@rm -f LOG1 LOG2
