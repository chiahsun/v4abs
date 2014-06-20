#include "CodeGeneration.h"
#include "test/UnitTest.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <design_name> <protocol_spec> <top_module_name>" << std::endl;
        return 1;
    }

    CodeGeneration code_gen(argv[1], argv[2], argv[3]);
    std::cout << code_gen.generateHeader() << std::endl << std::endl;
    std::cout << code_gen.generateImplementation() << std::endl;

    return 0;
}
