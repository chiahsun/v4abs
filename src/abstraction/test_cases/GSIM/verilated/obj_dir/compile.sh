#g++  -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o main.o ../main.cpp
#/usr/bin/perl /home/chiahsun/source_code_browse/verilator/verilator-3.862/bin/verilator_includer VCTE.cpp > VCTE__ALLcls.cpp
#/usr/bin/perl /home/chiahsun/source_code_browse/verilator/verilator-3.862/bin/verilator_includer VCTE__Syms.cpp > VCTE__ALLsup.cpp
#g++  -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o VCTE__ALLsup.o VCTE__ALLsup.cpp
#g++  -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o VCTE__ALLcls.o VCTE__ALLcls.cpp
#ar r VCTE__ALL.a VCTE__ALLcls.o VCTE__ALLsup.o
#ranlib VCTE__ALL.a
#g++  -O2  main.o verilated.o VCTE__ALL.a    -o VCTE -lm -lstdc++  2>&1 | c++filt

g++ -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o main.o ../main.cpp
/usr/bin/perl /home/chiahsun/source_code_browse/verilator/verilator-3.862/bin/verilator_includer VGSIM.cpp > VGSIM__ALLcls.cpp
/usr/bin/perl /home/chiahsun/source_code_browse/verilator/verilator-3.862/bin/verilator_includer VGSIM__Syms.cpp > VGSIM__ALLsup.cpp
g++ -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o VGSIM__ALLcls.o VGSIM__ALLcls.cpp
g++ -O2 -I. -MMD -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include -I/home/chiahsun/source_code_browse/verilator/verilator-3.862/include/vltstd -DVL_PRINTF=printf -DVM_TRACE=0 -DVM_COVERAGE=0        -c -o VGSIM__ALLsup.o VGSIM__ALLsup.cpp
      
ar r VGSIM__ALL.a VGSIM__ALLcls.o VGSIM__ALLsup.o
ranlib VGSIM__ALL.a
g++ -O2  main.o verilated.o VGSIM__ALL.a    -o VGSIM -lm -lstdc++  2>&1 | c++filt
