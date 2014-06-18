#include "EfsmExtract.h"
#include "test/UnitTest.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <design_name> <protocol_spec> <top_module_name>" << std::endl;
        return 1;
    }

    EfsmExtract extractFactory(argv[1], argv[2]);
    VRExprEfsm efsm = extractFactory.extract(argv[3]);
    assertEqual("", efsm.toString(), "Test to string");
    efsm.writeDotFile("efsm_extract1.dot");

    return 0;
}
