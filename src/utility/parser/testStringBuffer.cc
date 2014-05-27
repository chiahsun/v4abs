#include "test/UnitTest.h"
#include "StringBuffer.h"

void test_string_buffer() {
    {
        StringBuffer sbuffer("asdnoasj aom\n  si");

        assertEqual("asdnoasj", sbuffer.next(), "Test StringBuffer next");
        assertEqual("aom", sbuffer.next(), "Test StringBuffer next");
        assertEqual("si", sbuffer.next(), "Test StringBuffer next");
        assertEqual("", sbuffer.next(), "Test StringBuffer next");


    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_string_buffer_precede_empty() {
    {
        StringBuffer sbuffer(" Hello world!");
        assertEqual("Hello", sbuffer.next(), "Test StringBuffer next");
        assertEqual("world!", sbuffer.next(), "Test StringBuffer next");
        assertEqual("", sbuffer.next(), "Test StringBuffer next");


    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_string_buffer_tail_empty() {
    {
        StringBuffer sbuffer(" Hello world!\n\n");
        assertEqual("Hello", sbuffer.next(), "Test StringBuffer next");
        assertEqual("world!", sbuffer.next(), "Test StringBuffer next");
        assertEqual("", sbuffer.next(), "Test StringBuffer next");


    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_string_buffer_single_word() {
    {
        StringBuffer sbuffer("(QQgg)");
        assertEqual("(QQgg)", sbuffer.next(), "Test StringBuffer next");
        assertEqual("", sbuffer.next(), "Test StringBuffer next");


    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_string_buffer_empty() {
    {
        StringBuffer sbuffer("");
        assertEqual("", sbuffer.next(), "Test StringBuffer next");


    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}






int main() {

    test_string_buffer();
    test_string_buffer_precede_empty();
    test_string_buffer_tail_empty();
    test_string_buffer_single_word();
    test_string_buffer_empty();

    return 0;
}
