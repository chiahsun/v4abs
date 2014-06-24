#include <iostream>
#include <vector>

bool isUsed(int x, const std::vector<int> & v) {
    for (unsigned int i = 0; i < v.size(); ++i)
        if (x == v[i])
            return true;
    return false;
}

int main() {
    int used[] = { 0, 1, 79, 107, 24
                 , 25, 26, 27, 17, 21
                 , 13, 15, 16, 10, 20
                 , 12, 11, 18, 22, 14
                 , 19};

    int sz_used = sizeof(&used, &used[0]);

    std::vector<int> vecUsed(&used[0], &used[0]+sz_used);

    for (unsigned int i = 0; i < 1375+1; ++i) {
        if (!isUsed(i, vecUsed)) {
            std::cout << "func_number_" << i << "();\n";
        }
    }
    return 0;
}
