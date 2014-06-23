./run_systemc.sh ./testCTE.out ../pattern/pat1.dat &> LOG
vimdiff LOG ../pattern/golden1.dat
