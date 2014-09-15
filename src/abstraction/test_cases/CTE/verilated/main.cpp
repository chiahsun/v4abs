#include "VCTE.h"
#include "verilated.h"

#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG_EXPR(expr) do { std::cout << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

#include <iostream>

int main(int argc, char **argv, char **env) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <pattern_name>" << std::endl;
        return 0;
    }

    std::ifstream fin(argv[1]);
    if (!fin.good()) {
        std::cout << "Error: fail to open file - " << argv[1] << std::endl;
        return 0;
    }

    std::vector<int> vecData;
    int x;
    while(fin >> x) {
        vecData.push_back(x);
    }

    Verilated::commandArgs(argc, argv);
    VCTE* top = new VCTE;
    
    // initialize simulation inputs
    top->clk = 0;
    top->reset = 1;
    top->op_mode = 0;
    top->in_en = 0;
    top->rgb_in = 0;
    top->yuv_in= 0;

    int pos_data = 0;
    bool three_or_one = true;
//    for (int i = 0; i < 20; i++) {
    for (int i = 0;;++i) {
#if 0
        top->clk = !top->clk;
        top->eval();
#endif
        top->reset = (i < 5);
        if (top->out_valid) {
            assert(top->busy);
//            std::cout << "rgb_out : " << top->rgb_out << std::endl;
            std::cout << top->rgb_out << std::endl;
        }
        if (!top->reset) {
            if (!top->busy) {
                top->in_en = true;
                //            top->yuv_in = i * 4;
                if (pos_data == vecData.size())
                    break;
                DEBUG_EXPR(vecData[pos_data]);
                top->yuv_in = vecData[pos_data++];
            } else {
                top->in_en = false;
            } 
        }
#if 0
        top->clk = !top->clk;
        top->eval();
#endif

#if 1
        for (int clk = 0; clk < 2; clk++) {
            top->clk = !top->clk;
            top->eval();
        }
#endif
#if 0
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
#endif
        
    }
    return 0;
}
