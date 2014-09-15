#include <fstream>
#include <iostream>

// static const bool verbose = true;
static const bool verbose = false;

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <pattern1.log> <golden1.dat>" << std::endl;
        return 0;
    }
    std::ifstream fin1(argv[1]);
    if (!fin1.good()) {
        std::cout << "Error: fail to open " << argv[1] << std::endl;
        return 0;
    }
    std::ifstream fin2(argv[2]);
    if (!fin2.good()) {
        std::cout << "Error: fail to open " << argv[2] << std::endl;
        return 0;
    }
    
    unsigned int x, y;
    int nsuccess = 0;
    int nfail = 0;
    for (int i = 0; i < 16; ++i) {
        fin1 >> x;
        fin2 >> y;
        int difference = (x > y) ? (x - y) : (y - x);
        if (verbose)
            std::cout << argv[1] << " : " << x << ", " << argv[2] << " : " << y << " (difference : " << difference << ")";
        if (difference <= 3) {
            ++nsuccess;
            if (verbose)
                std::cout << " Passed" << std::endl;
        } else {
            ++nfail;
            if (verbose)
                std::cout << " Failed" << std::endl;
        }
    }

    std::cout << "Check: " << argv[1] << " and " << argv[2];
    if (nfail == 0)
        std::cout << " : ( Passed )\n";
    else
        std::cout << " : ( Failed )\n";

    fin1.close();
    fin2.close();
    return 0;
}
