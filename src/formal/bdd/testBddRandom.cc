#include "BddManager.h"
#include "test/UnitTest.h"

#include <cstdlib>
#include <ctime>

const static bool isWriteFile = false;
const static bool isCheckTime = true;

void test_random() {
    srand(0);
    int numVar = 3;
    int numOperation = numVar * 10;

    if (isCheckTime) {
        numVar = 15;
        numOperation = numVar * 40;
    }
    
#if 0
    int numVar = 8;
    int numOperation = numVar * 400;
#endif
# if 0
#endif


    BddManager bddManager;
    std::vector<BddNodeHandle> vecBddNode;

    for (int i = 0; i < numVar; ++i)
       vecBddNode.push_back(bddManager.makeBddNode(i+1));

    BddNodeHandle px, py;
    for (int i = 0; i < numOperation; ++i) {
        px = vecBddNode[rand() % vecBddNode.size()];
        py = vecBddNode[rand() % vecBddNode.size()];
        switch(rand() % 5) {
            case 0:
                vecBddNode.push_back(bddManager.makeAnd(px, py));
                break;
            case 1:
                vecBddNode.push_back(bddManager.makeOr(px, py));
                break;
            case 2:
                vecBddNode.push_back(bddManager.makeEq(px, py));
                break;
            case 3:
                vecBddNode.push_back(bddManager.makeImply(px, py));
                break;
            case 4:
                vecBddNode.push_back(bddManager.makeNeg(px));
                break;
            default:
                assert(0);
        }
    }

    BddNodeHandle plast = vecBddNode[vecBddNode.size()-1];
    if (isWriteFile)
        plast->writeDotFile("plast.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_random();

    return 0;
}
