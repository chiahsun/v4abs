./run_systemc.sh ./testGSIM.out ./pattern1.dat &> LOG
vimdiff LOG ../pattern/golden.dat
