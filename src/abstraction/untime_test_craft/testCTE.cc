#include "CTE.h"
#include "Numerics.h"

#include <systemc.h>
#include <vector>
#include <iostream>
#include <fstream>

const static bool verbose = false;
// const static bool verbose = true;

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
    cte.init();
    cte.register_data_pointer(&yuv_in, &rgb_out);
//    std::cout << "---------------------------------------\nNone " << std::endl;
//    cte.run(ProtocolEvent_none);
//    cte.print();
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


//    yuv_in = 28;
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();

//    yuv_in = 114;
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
//    yuv_in = 84;
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en and write rgb_out" << std::endl;
    cte.run(ProtocolEvent_write_rgb_out);
    if (verbose)
        cte.print();
    
//    yuv_in = 193;
    yuv_in = vecData[pos++];
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en" << std::endl;
    cte.run(ProtocolEvent_not_reset_and_in_en);
    if (verbose)
        cte.print();
    
    if (verbose)
        std::cout << "---------------------------------------\nNot reset and in_en and write rgb_out" << std::endl;
    cte.run(ProtocolEvent_write_rgb_out);
    if (verbose)
        cte.print();
    }
    

    // 28 / 114 / 84
    // 16460970
    // 16743417
//    CTE_Wire_busy();
//    CTE_inst0_YUV_TO_RGB_inst0_U_ext(); 

# if 0
    CTE_inst0_YUV_TO_RGB_transaction_read_reset();
    CTE_inst0_YUV_TO_RGB_report();
    CTE_inst0_YUV_TO_RGB_transaction_read_not_reset_and_not_in_en();
    CTE_inst0_YUV_TO_RGB_report();
    CTE_inst0_YUV_TO_RGB_transaction_read_in_en_and_yuv_in("1C");
    CTE_inst0_YUV_TO_RGB_report();
    CTE_inst0_YUV_TO_RGB_transaction_read_in_en_and_yuv_in("72");
    CTE_inst0_YUV_TO_RGB_report();
    CTE_inst0_YUV_TO_RGB_transaction_read_in_en_and_yuv_in("54");
    CTE_inst0_YUV_TO_RGB_report();
    std::cout << "Output1: " << CTE_inst0_YUV_TO_RGB_transaction_read_in_en_and_yuv_in_and_write_rgb_out("0") << std::endl;
    CTE_inst0_YUV_TO_RGB_report();
#endif

    return 0;
}
