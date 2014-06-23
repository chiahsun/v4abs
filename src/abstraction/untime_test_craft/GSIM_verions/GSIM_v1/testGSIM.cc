#include "GSIM.h"

#include <systemc.h>
#include <vector>
#include <iostream>
#include <fstream>

const static bool verbose = false;
const static bool report_output = true;

int sc_main(int argc, char** argv) {
    sc_start();
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <data_in>" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin.good()) {
        std::cout << "Error: fail to open " << argv[1] << std::endl;
        return 1;
    }

    std::vector<int> vecData;
    int x;
    while(fin >> x) {
        vecData.push_back(x);
    }

    GSIM gsim;

    sc_uint<16> b_in;
    sc_uint<32> x_out;

    gsim.register_data_pointer(&b_in, &x_out);

    unsigned int pos = 0;

    while (pos < vecData.size()) {
        pos++;
    }


    return 0;
} 
