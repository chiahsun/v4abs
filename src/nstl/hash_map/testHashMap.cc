#include "HashMap.h"
#include "test/UnitTest.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include <sstream>
    
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

    HashMap<int, std::string>::iterator it = hash_map.insert(std::make_pair(4, "Four"));
    assertEqual(4, hash_map.find(4)->first, "Test find");
    assertEqual("Four", hash_map.find(4)->second, "Test find");
    assertEqual(4, it->first, "Test find");
    assertEqual("Four", it->second, "Test find");
    it->second = "4";
    assertEqual(4, hash_map.find(4)->first, "Test find");
    assertEqual("4", hash_map.find(4)->second, "Test find");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_hash_map_container() {
    HashMap<int, std::vector<std::string> > hm;
    hm.insert(std::make_pair(1, std::vector<std::string>()));
    assert(hm.find(1) != hm.end());
    hm.find(1)->second.push_back("One");
    hm.find(1)->second.push_back("1");
    hm.find(1)->second.push_back("First");

    std::stringstream ss;
    FOR_EACH(pr, hm) {
        FOR_EACH(str, pr.second)
            ss << str << " ";
    }
    assertEqual("One 1 First ", ss.str(), "Test container");

    HashMap<int, std::vector<std::string> > hm2(hm);
#if 1 
    std::stringstream ss2;
    FOR_EACH(pr, hm2) {
        FOR_EACH(str, pr.second)
            ss2 << str << " ";
    }
    assertEqual("One 1 First ", ss2.str(), "Test container");
#endif

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_hash_map_hash_table() {
    HashMap<int, HashTable<std::string> > hm;
    hm.insert(std::make_pair(1, HashTable<std::string>()));
    assert(hm.find(1) != hm.end());
    hm.find(1)->second.insert("One");
    hm.find(1)->second.insert("1");
    hm.find(1)->second.insert("First");

    std::stringstream ss;
    FOR_EACH(pr, hm) {
        FOR_EACH(str, pr.second)
            ss << str << " ";
    }
    assertEqual("First 1 One ", ss.str(), "Test container");

    HashMap<int, HashTable<std::string> > hm2(hm);
    std::stringstream ss2;
    FOR_EACH(pr, hm2) {
        FOR_EACH(str, pr.second)
            ss2 << str << " ";
    }
    assertEqual("First 1 One ", ss2.str(), "Test container");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_hash_map();
    test_hash_map_container();
    test_hash_map_hash_table();
    return 0;
}
