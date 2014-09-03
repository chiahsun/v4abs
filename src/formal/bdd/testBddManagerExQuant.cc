#include "BddManager.h"
#include "test/UnitTest.h"

#include <cstdlib>
#include <ctime>

const static bool isWriteFile = true;
const static bool isNormal = true;
const static bool isCheckTime = false;
void test_random() {
    srand(0);
//    int numVar = 10;
    int numVar = 25;
    int numOperation = numVar * 25;
    if (isNormal) {
        numVar = 4;
        numOperation = numVar * 10; 
    } else if (isCheckTime) {
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
    clock_t t = clock();
    std::cout << "Top begin" << std::endl;
    BddNodeHandle plast_exquat_top = bddManager.exQuant(plast, plast->getCurDecisionLevel());
    t = clock() - t;
    std::cout << "Top end: " << ((double)t)/CLOCKS_PER_SEC << std::endl;

    t = clock();
    std::cout << "Middle begin" << std::endl;
    BddNodeHandle plast_exquat_middle = bddManager.exQuant(plast, 14);
    t = clock() - t;
    std::cout << "Middle end: " << ((double)t)/CLOCKS_PER_SEC << std::endl;
    if (isWriteFile) {
        plast->writeDotFile("exquat.dot");
        plast_exquat_top->writeDotFile("exquat_top.dot");
        plast_exquat_middle->writeDotFile("exquat_middle.dot");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_random();

    return 0;
}
