#include <vector>
#include <iostream>
#include <fstream>

template <class T>
inline T abs(T x)
  { return (x < 0) ? -x : x; }

static const int M = 16;
static const double A[M][M] = {
    { 20,-13,  6, -1,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0,  0,  0}
  , {-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
  , {  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
  , { -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0}
  , {  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0,  0,  0}
  , {  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0,  0}
  , {  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0,  0}
  , {  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0,  0}
  , {  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0,  0}
  , {  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0,  0}
  , {  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0,  0}
  , {  0,  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1,  0}
  , {  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6, -1}
  , {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13,  6}
  , {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20,-13}
  , {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  6,-13, 20}
};

static double X[M] = {12.4, -34.1, 1235.5, -481.2, -165.65, 1518.85, -1499.8, 1549.75, -1018.4, 547.6, 283.25, 573.8, -455.4, 394.1, 1019.55, -1575.25};
static double B[M] = {248,  -682,  24710,  -9624,   -3313,   30377,  -29996,   30995,  -20368, 10952,   5665, 11476,  -9108,  7882,   20391, -31505}; 

void next_c(double ary[M]) {
    for (int i = M-1; i >= 0; --i) {
        ary[i] = ary[i-1];
    }
    ary[0] = 1;
}

void GSIM() {
//    for(int i = 0; i < 60; ++i) {
//    for(int i = 0; i < 1000; ++i) {
    for(int i = 0; i < 2000; ++i) {
        double C[M] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int k = 0; k < 16; ++k) {
            X[k] = (B[k] - (  C[0]*A[k][0]*X[0]    + C[1]*A[k][1]*X[1]    + C[2]*A[k][2]*X[2]    + C[3]*A[k][3]*X[3]
                 + C[4]*A[k][4]*X[4]    + C[5]*A[k][5]*X[5]    + C[6]*A[k][6]*X[6]    + C[7]*A[k][7]*X[7]
                 + C[8]*A[k][8]*X[8]    + C[9]*A[k][9]*X[9]    + C[10]*A[k][10]*X[10] + C[11]*A[k][11]*X[11]
                 + C[12]*A[k][12]*X[12] + C[13]*A[k][13]*X[13] + C[14]*A[k][14]*X[14] + C[15]*A[k][15]*X[15]))/A[k][k];
            next_c(C);
        }
    }
#if 0
    std::cout.precision(10);
    for (int i = 0; i < M; ++i)
        std::cout << std::fixed << X[i] << " ";
    std::cout << std::endl;
#endif
    for (int i = 0; i < M; ++i) {
        bool neg = X[i] < 0;
        double x = abs(X[i]) * 65536;
        unsigned int a = static_cast<unsigned int>(x);
        if ((x-a) >= 0.5) 
            a += 1;
        if (neg)
            a = ~a + 1;
        // std::cout << a << " " << std::fixed << x << std::endl;
        std::cout << a << std::endl;
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

    int pos = 0;
    int x;
    while (fin >> x) {
        B[pos++] = ((x & (0x1 << 15)) ? -(~x+1 & 0xffff) : x);
    }
#if 0
    std::vector<int> vecData;
    while(fin >> x) {
        vecData.push_back(x);
    }
#endif

    GSIM();


    return 0;
} 
