../../verilator --cc ../CTE.v --exe main.cpp
cd obj_dir
make -j -f VCTE.mk VCTE
cd ..
echo "(verilator end) Run..."
./obj_dir/VCTE ../pattern/pat1.dat
