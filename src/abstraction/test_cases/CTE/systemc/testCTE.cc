#include "CTE.h"

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
    while (fin >> x) {
        vecData.push_back(x); 
    }

    CTE cte;

    sc_uint<8> yuv_in(0);
    sc_uint<24> rgb_out(0);
    cte.register_data_pointer(&yuv_in, &rgb_out);
    if (verbose)
        std::cout << "---------------------------------------\nReset" << std::endl;
    cte.run(ProtocolEvent_reset);
    if (verbose)
        cte.print();

    if (verbose)
        std::cout << "---------------------------------------\nNot reset" << std::endl;
    cte.run(ProtocolEvent_not_reset);
    if (verbose)
        cte.print();

    unsigned int pos = 0;
    while (pos < vecData.size()) {


    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();

    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en and write rgb_out" << std::endl;
    cte.run(ProtocolEvent_write_rgb_out);
    if (report_output)
        std::cout << rgb_out << std::endl;
    if (verbose)
        cte.print();
    
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en and write rgb_out" << std::endl;
    cte.run(ProtocolEvent_write_rgb_out);
    if (report_output)
        std::cout << rgb_out << std::endl;
    if (verbose)
        cte.print();
    }
    

    return 0;
}
