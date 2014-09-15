#include "GSIM.h"

#include <systemc.h>
#include <vector>
#include <iostream>
#include <fstream>

const static bool verbose = false;
const static bool report_output = true;
// const static bool report_output = false;

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
    gsim.init();

    unsigned int pos = 0;

    gsim.run(ProtocolEvent_reset);
    gsim.run(ProtocolEvent_not_reset);
    for (unsigned int i = 0; i < 16; ++i) {
        b_in = vecData[pos++];
        gsim.run(ProtocolEvent_not_reset_and_in_en);
    }
    for (unsigned int i = 0; i < 16; ++i) {
        gsim.run(ProtocolEvent_not_reset_and_not_in_en);
        std::cout << x_out << std::endl; 
    }

    return 0;
} 
