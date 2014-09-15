#include "VGSIM.h"
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
    VGSIM* top = new VGSIM;
    
    // initialize simulation inputs
    top->clk = 0;
    top->reset = 1;
    top->in_en = 0;
    top->b_in= 0;

    int pos_data = 0;
    int pos_data_out = 0;

    for (int i = 0;;++i) {
        top->reset = (i < 5);
        if (top->out_valid) {
//            std::cout << "rgb_out : " << top->rgb_out << std::endl;
            std::cout << top->x_out << std::endl;
            ++pos_data_out;
            if (pos_data_out == 16)
                break;
        }
        if (!top->reset) {
            if (pos_data < 16) {
                top->in_en = true;
//                DEBUG_EXPR(vecData[pos_data]);
                top->b_in= vecData[pos_data++];
            } else {
                top->in_en = false;
            }
        }

        for (int clk = 0; clk < 2; clk++) {
            top->clk = !top->clk;
            top->eval();
        }
        
    }
    return 0;
}
