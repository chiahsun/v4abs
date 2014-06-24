#include <iostream>



int main() {
    for (unsigned int i = 0; i < 6; i = i + 2)
        std::cout << 
        "    if (A[6][" << i << "] > A[6][" << i+1 << "]) begin\n"
        "        A[7][" << i << "] = A[6][" << i+1 << "];\n"
        "        A[7][" << i+1 << "] = A[6][" << i << "];\n"
        "    end\n"
        "    else begin\n"
        "        A[7][" << i << "] = A[6][" << i << "];\n"
        "        A[7][" << i+1 << "] = A[6][" << i+1 << "];\n"
        "    end\n";
    return 0;
}
