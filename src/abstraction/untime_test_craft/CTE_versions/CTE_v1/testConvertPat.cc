#include "Numerics.h"
#include <systemc.h>
#include <iostream>
#include <fstream>

int sc_main(int argc, char** argv) {
    sc_start();
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_name_to_convert>" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin.good()) {
        std::cout << "Error: fail to open file " << argv[1] << std::endl;
    }
    std::string s;
    while(fin >> s) {
        std::cout << hex_to_uint(s) << std::endl;
    }
    return 0;
}
