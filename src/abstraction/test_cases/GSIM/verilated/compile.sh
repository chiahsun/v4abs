../../verilator -Wno-UNOPTFLAT --cc ../GSIM.v --exe main.cpp
cd obj_dir
make -j -f VGSIM.mk VGSIM
cd ..
echo "(verilator end) Run..."
./obj_dir/VGSIM ../pattern/pattern1.dat
