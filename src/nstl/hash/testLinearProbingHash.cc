#include "test/UnitTest.h"
#include "HashTable.h"
#include "Random.h"

#include <sstream>

#define DEBUG_EXPR(expr) do { std::cerr << #expr << " : " << (expr) << "   @ (" << __FILE__ << " : "<< __LINE__ << ")" << std::endl; } while(0)


void test_linear_probing_hash_insert() {
    HashTable<int> hash;
    hash.insert(10);
    assertEqual(1, hash.size(), "Test hash size");
    hash.insert(11);
    assertEqual(2, hash.size(), "Test hash size");
    hash.insert(12);
    assertEqual(3, hash.size(), "Test hash size");
    hash.insert(10);
    assertEqual(3, hash.size(), "Test hash size");
    assertEqual(true, hash.find(10) != hash.end(), "Test insert find");
    assertEqual(true, hash.find(11) != hash.end(), "Test insert find");
    assertEqual(true, hash.find(12) != hash.end(), "Test insert find");
    assertEqual(true, hash.find(9) == hash.end(), "Test insert find");
    assertEqual(true, hash.find(13) == hash.end(), "Test insert find");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_linear_probing_hash_resize() {
    int MAX = 100000;
    std::vector<int> vecGolden;
    std::vector<int> vecOutput;
    HashTable<int> hash;
    HashTable<int>::iterator it = hash.end();

    {
        int magic = 524366;
        vecGolden.push_back(magic);
        hash.insert(magic);
        assertEqual(true, hash.find(magic) != hash.end(), "Test find");
    }
    for (int i = 0; i < MAX; ++i) {
        int val = rand();
        hash.insert(val);
        vecGolden.push_back(val);
        it = hash.find(val);
        assertEqual(true, it != hash.end(), "Test has value");
    }

    // assertEqual(vecGolden.size(), hash.size(), "Test size"); // not guarantee eq, since may element duplicated


    for (size_t i = 0; i < vecGolden.size(); ++i) {
        it = hash.find(vecGolden[i]);
        assertEqual(true, it != hash.end(), "Test has value");
        assertEqual(vecGolden[i], *(hash.find(vecGolden[i])), "Test has value");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_linear_probing_hash_erase() {
    HashTable<int> hash;
    hash.insert(10);
    assertEqual(1, hash.size(), "Test hash size");
    hash.erase(10);
    assertEqual(0, hash.size(), "Test hash size");
    hash.insert(11);
    hash.insert(12);
    assertEqual(2, hash.size(), "Test hash size");
    hash.erase(11);
    assertEqual(1, hash.size(), "Test hash size");

    assertEqual(true, hash.find(10) == hash.end(), "Test insert find");
    assertEqual(true, hash.find(11) == hash.end(), "Test insert find");
    assertEqual(true, hash.find(12) != hash.end(), "Test insert find");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_linear_probing_hash_erase2() {
    HashTable<int> hash;
    std::vector<int> vec;
    int size = 1000; 
    for (int i = 0; i < size; ++i) {
        hash.insert(i);
        vec.push_back(i);
    }

    assertEqual(static_cast<unsigned int>(size), hash.size(), "Test hash size");
    assertEqual(static_cast<unsigned int>(size), vec.size(), "Test vec size");

    for (int i = 0; i < size; ++i) {
        hash.erase(vec[i]);
    }

    assertEqual(0, hash.size(), "Test hash size");
    
    for (int i = 0; i < size; ++i) {
        assertEqual(true, hash.find(vec[i]) == hash.end(), "Test find");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_linear_probing_hash_iteration() {
    HashTable<int> hash;
    int size = 10;
    std::stringstream ss;
    for (int i = 0; i < size; ++i) 
        hash.insert(i);
    for (HashTable<int>::iterator it = hash.begin(); it != hash.end(); ++it) {
        ss << *it << ' ';
    }
    assertEqual("0 1 2 3 4 5 6 7 8 9 ", ss.str(), "Test iteration");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_linear_probing_hash_clear() {
    const int size = 10;
    HashTable<int> hash;
    for (int i = 0; i < size; ++i)
        hash.insert(i);
    assertEqual(static_cast<unsigned int>(size), hash.size(), "Test size");

    hash.clear();
    assertEqual(0, hash.size(), "Test size");
    for (int i = 0; i < size; ++i)
        hash.insert(i);
    assertEqual(static_cast<unsigned int>(size), hash.size(), "Test size");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_linear_probing_hash_insert();
    test_linear_probing_hash_resize();
    test_linear_probing_hash_erase();
    test_linear_probing_hash_erase2();
    test_linear_probing_hash_iteration();
    test_linear_probing_hash_clear();
    return 0;
}
