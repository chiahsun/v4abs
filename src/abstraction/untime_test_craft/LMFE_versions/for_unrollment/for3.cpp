#include <iostream>

int main() {
    for (unsigned int i =0; i < 7; ++i)
        for (unsigned int k = 0; k < 7; ++k)
            std::cout << "        m_inp[" << i << "][" << k << "] <= 8'h0;\n";

    std::cout << std::endl << std::endl;
    for (unsigned int i =0; i < 7; ++i)
        for (unsigned int k = 0; k < 7; ++k)
            std::cout << "        m_inp[" << i << "][" << k  << "] <= m_tmp[" << i << "][" << k << "];\n";
    return 0;
}
