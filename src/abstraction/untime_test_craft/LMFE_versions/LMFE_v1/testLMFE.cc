#include "LMFE.h"
#include "Numerics.h"

#include <systemc.h>
#include <vector>
#include <iostream>
#include <fstream>

const static bool verbose = false;
const static bool report_output = false;
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

    LMFE lmfe;

    sc_uint<8> Din(0);
    sc_uint<8> Dout(0);
    lmfe.init();
    lmfe.register_data_pointer(&Din, &Dout);

    lmfe.run(ProtocolEvent_reset);
    lmfe.run(ProtocolEvent_not_reset_and_not_in_en);
    for (unsigned int i = 0; i < vecData.size(); ++i)
    {
        Din = vecData[i];
        lmfe.run(ProtocolEvent_not_reset_and_in_en);
    }
    return 0;
}
