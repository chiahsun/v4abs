#include "HashMap.h"
#include "test/UnitTest.h"
    
void test_hash_map() {
    HashMap<int, std::string> hash_map;
    hash_map.insert(std::make_pair(1, "One"));
    hash_map.insert(std::make_pair(2, "Two"));
    hash_map.insert(std::make_pair(3, "Three"));

    assertEqual(true, hash_map.find(1) != hash_map.end(), "Test find");
    assertEqual(1, hash_map.find(1)->first, "Test find");
    assertEqual("One", hash_map.find(1)->second, "Test find");
    assertEqual(true, hash_map.find(2) != hash_map.end(), "Test find");
    assertEqual(2, hash_map.find(2)->first, "Test find");
    assertEqual("Two", hash_map.find(2)->second, "Test find");
    assertEqual(true, hash_map.find(3) != hash_map.end(), "Test find");
    assertEqual(3, hash_map.find(3)->first, "Test find");
    assertEqual("Three", hash_map.find(3)->second, "Test find");
    hash_map.insert(std::make_pair(1, "1"));
    assertEqual(true, hash_map.find(1) != hash_map.end(), "Test find");
    assertEqual(1, hash_map.find(1)->first, "Test find");
    assertEqual("1", hash_map.find(1)->second, "Test find");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_hash_map();
    return 0;
}
