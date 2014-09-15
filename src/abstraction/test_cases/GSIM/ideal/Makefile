TOP=../../../../..


all :
	make binary
	make lib


-include $(TOP)/src/mkfile/Makefile

check: testGSIMIdeal.out
	@./$< ../pattern/pattern1.dat &> pattern1.log;
	@./$< ../pattern/pattern2.dat &> pattern2.log;
	@./$< ../pattern/pattern3.dat &> pattern3.log;
	@./$< ../pattern/pattern4.dat &> pattern4.log;
	@./$< ../pattern/pattern5.dat &> pattern5.log;
	@./testGSIMCheck.out pattern1.log ../pattern/golden1.dat
	@./testGSIMCheck.out pattern2.log ../pattern/golden2.dat
	@./testGSIMCheck.out pattern3.log ../pattern/golden3.dat
	@./testGSIMCheck.out pattern4.log ../pattern/golden4.dat
	@./testGSIMCheck.out pattern5.log ../pattern/golden5.dat
#	$(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden1.dat
#	@./$< ../pattern/pat2.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden2.dat
#	@./$< ../pattern/pat3.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden3.dat
#	@./$< ../pattern/pat4.dat 2> LOG2 1> LOG1; $(TOP)/src/mkfile/run_diff_file.py LOG1 ../pattern/golden4.dat
#	@rm -f LOG1 LOG2
