#include <iostream>
#include <fstream>
#include <vector>

int convert(double x) {
    if (x < 0) return 0;
    if (x > 255) return 255;
    int i = static_cast<int>(x);
    if (x - i >= 0.5)
        return (i+1 > 255) ? 255 : (i+1);
    else
        return i;
}


void compute(const std::vector<int> & vecData) {
    for (unsigned int i = 0; i < vecData.size(); i += 4) {
        int U, V;
        double U1, Y1, V1, Y2;
        // int sign_mask = (0x1 << 7);
        int sign_mask = 0x80;
       // U = (sign_mask & vecData[i]) ? -((~vecData[i] & 0x7f)+1) : vecData[i];
        U = (sign_mask & vecData[i]) ? -((~vecData[i]+1) & 0xff) : vecData[i];
        U1 = U; 
        Y1 = vecData[i+1];
        V = (sign_mask & vecData[i+2]) ? -((~vecData[i+2]+1) & 0xff) : vecData[i+2];
        V1 = V;
        Y2 = vecData[i+3];
        
        double R1, G1, B1, R2, G2, B2;
        R1 = Y1 + 1.625 * V1;
        G1 = Y1 - 0.25*U1 + -0.75*V1;
        B1 = Y1 + 2*U1;

        R2 = Y2 + 1.625 * V1;
        G2 = Y2 - 0.25*U1 + -0.75*V1;
        B2 = Y2 + 2*U1;

        int R1_int = convert(R1);
        int G1_int = convert(G1);
        int B1_int = convert(B1);

        int R2_int = convert(R2);
        int G2_int = convert(G2);
        int B2_int = convert(B2);

        int RGB1_out = ((R1_int << 16) | (G1_int << 8) | B1_int);
        int RGB2_out = ((R2_int << 16) | (G2_int << 8) | B2_int);

        (void)(RGB1_out);
        (void)(RGB2_out);
#if 1
        std::cout << ((R1_int << 16) | (G1_int << 8) | B1_int) << std::endl;;
        std::cout << ((R2_int << 16) | (G2_int << 8) | B2_int) << std::endl;;
#endif
    }
}

int main(int argc, char** argv) {
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

    compute(vecData);
    return 0;
}
