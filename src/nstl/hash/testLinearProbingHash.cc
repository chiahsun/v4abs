#include "test/UnitTest.h"
#include "HashTable.h"
#include "Random.h"
#include "nstl/for_each/ForEach.h"

#include <sstream>

#define DEBUG_EXPR(expr) do { std::cerr << #expr << " : " << (expr) << "   @ (" << __FILE__ << " : "<< __LINE__ << ")" << std::endl; } while(0)


void test_linear_probing_hash_insert() {
    HashTable<int> hash;
    HashTable<int>::iterator it = hash.end();

    it = hash.insert(10); 
    assertEqual(*it, 10, "Test insert return iterator");
    assertEqual(1, hash.size(), "Test hash size");

    it = hash.insert(11); 
    assertEqual(*it, 11, "Test insert return iterator");
    assertEqual(2, hash.size(), "Test hash size");

    it = hash.insert(12); 
    assertEqual(*it, 12, "Test insert return iterator");
    assertEqual(3, hash.size(), "Test hash size");

    it = hash.insert(10); 
    assertEqual(*it, 10, "Test insert return iterator");
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
    std::stringstream ss2;
    for (HashTable<int>::const_iterator it = hash.cbegin(); it != hash.cend(); ++it) {
        ss2 << *it << ' ';
    }
    assertEqual("0 1 2 3 4 5 6 7 8 9 ", ss.str(), "Test iteration");
    assertEqual("0 1 2 3 4 5 6 7 8 9 ", ss2.str(), "Test iteration");
    hash.erase(0);
    hash.erase(1);
    hash.erase(2);
    std::stringstream ss3;
    for (HashTable<int>::const_iterator it = hash.cbegin(); it != hash.cend(); ++it) {
        ss3 << *it << ' ';
    }
    assertEqual("3 4 5 6 7 8 9 ", ss3.str(), "Test iteration");
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

void test_vector_of_hash() {
    std::vector<HashTable<int> > vecHash;
    const int size = 10;
    for (int i = 0; i < size; ++i) {
        vecHash.push_back(HashTable<int>());
        HashTable<int>::iterator it = vecHash[i].end();
        it = vecHash[i].insert(i);
        assertEqual(i, *it, "Test dereference iterator");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_hash_copy_constructor() {
    HashTable<int> ht;
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    std::stringstream ss;
    FOR_EACH(i, ht) {
        ss << i << " ";
    }
    assertEqual("1 2 3 ", ss.str(), "Test copy constructor");
    assertEqual(3, ht.size(), "Test ht size");
    HashTable<int> ht2(ht);
    std::stringstream ss2;
    FOR_EACH(i, ht2) {
        ss2 << i << " ";
    }
    assertEqual(3, ht2.size(), "Test ht2 size");
    assertEqual("1 2 3 ", ss2.str(), "Test copy constructor");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_insert_begin_end() {\
    LinearProbingHash<int> ht1, ht2;
    for (int i = 0; i < 4; ++i)
        ht1.insert(i);
    ht1.insert(4);
    ht1.insert(6);
    ht1.insert(9);
    for (int i = 4; i < 10; ++i)
        ht2.insert(i);
    ht1.insert(ht2.begin(), ht2.end());
    std::stringstream ss;
    FOR_EACH(i, ht1)
        ss << i << " ";
    assertEqual("0 1 2 3 4 5 6 7 8 9 ", ss.str(), "Test insert begin end");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_linear_probing_hash_insert();
    test_linear_probing_hash_resize();
    test_linear_probing_hash_erase();
    test_linear_probing_hash_erase2();
    test_linear_probing_hash_iteration();
    test_linear_probing_hash_clear();
    test_vector_of_hash();
    test_hash_copy_constructor();
    test_insert_begin_end();
    return 0;
}
