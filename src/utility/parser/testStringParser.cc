#include "test/UnitTest.h"
#include "StringParser.h"

void test_ternary_op() {
	StringParser parser;
    TokenStructureHandle pTokenStructure = parser.parseString("(expression (expression (primary (number (binary_number 1'b1)))) ? (expression (primary (number (binary_number 2'b00)))) : (expression (primary (number (binary_number 2'b11)))))");
	TokenStructure ts = *pTokenStructure;
	assertEqual("expression", ts[0]->name(), "Test token name");
	assertEqual("expression", ts[1]->name(), "Test token name");
	assertEqual("primary", ts[2]->name(), "Test token name");
	assertEqual("number", ts[3]->name(), "Test token name");
	assertEqual("binary_number", ts[4]->name(), "Test token name");
	assertEqual("1'b1", ts[5]->name(), "Test token name");
	assertEqual("?", ts[6]->name(), "Test token name");
	assertEqual("expression", ts[7]->name(), "Test token name");
	assertEqual("primary", ts[8]->name(), "Test token name");
	assertEqual("number", ts[9]->name(), "Test token name");
	assertEqual("binary_number", ts[10]->name(), "Test token name");
	assertEqual("2'b00", ts[11]->name(), "Test token name");
	assertEqual(":", ts[12]->name(), "Test token name");
	assertEqual("expression", ts[13]->name(), "Test token name");
	assertEqual("primary", ts[14]->name(), "Test token name");
	assertEqual("number", ts[15]->name(), "Test token name");
	assertEqual("binary_number", ts[16]->name(), "Test token name");
	assertEqual("2'b11", ts[17]->name(), "Test token name");

    assertEqual(1, ts[0]->vecChildId()[0], "Test get child token id");
    assertEqual(6, ts[0]->vecChildId()[1], "Test get child token id");
    assertEqual(7, ts[0]->vecChildId()[2], "Test get child token id");
    assertEqual(12, ts[0]->vecChildId()[3], "Test get child token id");
    assertEqual(13, ts[0]->vecChildId()[4], "Test get child token id");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_keyword_begin() {
    {
        StringParser parser;
		TokenStructureHandle pTokenStructure = parser.parseString("(init (keywords begin\n))");
        assertEqual("(init (keywords begin\n))", parser.getOriginalStr(), "Test parser str");
        assertEqual(" #PUSH init  #PUSH keywords begin #POP  #POP ", parser.getProcessedStr(), "Test parser str");

        TokenStructure ts = *pTokenStructure;
//        std::cout << ts.reportToken();
        assertEqual("(init (keywords begin))", ts.toString(), "Test token structure toString");
        assertEqual("init", ts[0]->name(), "Test get token by id");
        assertEqual("keywords", ts[1]->name(), "Test get token by id");
        assertEqual("begin", ts[2]->name(), "Test get token by id");

        assertEqual(1, ts[0]->vecChildId()[0], "Test get child token id");
        assertEqual(1, ts[0]->vecChildId().size(), "Test get child token size");

        assertEqual(2, ts[1]->vecChildId()[0], "Test get child token id");
        assertEqual(1, ts[1]->vecChildId().size(), "Test get child token size");
        assertEqual(
    "(name : init) (token id : 0) (father token id : -1) (child token id : 1)\n"
    "(name : keywords) (token id : 1) (father token id : 0) (child token id : 2)\n"
    "(name : begin) (token id : 2) (father token id : 1) (child token id : )\n"
                   , ts.reportToken()
                   , "Test report token");
    #if 0
        // std::cout << ts.reportToken(); 
        TokenHandle pInit;
#endif
#if 0
        try {
            pInit = parser.getEntryName();
        } catch (const InvalidElementException & e) {
            std::cerr << "*Error: fail to get entry " << std::endl;
            return;
        }
        assertEqual("init", pInit->name(), "Test parser entry name");

        assertEqual(1, pInit->getElementSize(), "Test init element size");

        StringHandle pKeyword;
        try {
            pKeyword = pInit->getElement(0);
        } catch (const InvalidElementException & e) {
            std::cerr << "*Error: fail to get entry " << std::endl;
            return;
        }

        assertEqual("keywords begin\n", pKeyword->name(), "Test keywords name");
        assertEqual(0, pKeyword->getElementSize(), "Test keywords element size");
#endif
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parathesis1() {
    {
        StringParser parser;
	    TokenStructureHandle pTokenStructure = parser.parseString("(init (expression ( (expression (expression ( (expression (expression (primary (number (unsigned_number 1)))) (binary_operator +) (expression (primary (number (unsigned_number 2))))) )) (binary_operator -) (expression (primary (number (unsigned_number 3))))) )))");
        assertEqual("(init (expression ( (expression (expression ( (expression (expression (primary (number (unsigned_number 1)))) (binary_operator +) (expression (primary (number (unsigned_number 2))))) )) (binary_operator -) (expression (primary (number (unsigned_number 3))))) )))", parser.getOriginalStr(), "Test parser str");

        TokenStructure ts = *pTokenStructure;
        assertEqual(parser.getOriginalStr(), ts.toString(), "Test token structure toString");

        assertEqual(3, ts[1]->vecChildId().size(), "Test get child token size");

        assertEqual("init", ts[0]->name(), "Test get token by id");
        assertEqual("expression", ts[1]->name(), "Test get token by id");
        assertEqual("(", ts[2]->name(), "Test get token by id");
        assertEqual("expression", ts[3]->name(), "Test get token by id");
        assertEqual("expression", ts[4]->name(), "Test get token by id");
        assertEqual("(", ts[5]->name(), "Test get token by id");
        assertEqual("expression", ts[6]->name(), "Test get token by id");
        assertEqual("expression", ts[7]->name(), "Test get token by id");
        assertEqual("primary", ts[8]->name(), "Test get token by id");
        assertEqual("number", ts[9]->name(), "Test get token by id");
        assertEqual("unsigned_number", ts[10]->name(), "Test get token by id");
        assertEqual("1", ts[11]->name(), "Test get token by id");
        assertEqual("binary_operator", ts[12]->name(), "Test get token by id");
        assertEqual("+", ts[13]->name(), "Test get token by id");
        assertEqual("expression", ts[14]->name(), "Test get token by id");
        assertEqual("primary", ts[15]->name(), "Test get token by id");
        assertEqual("number", ts[16]->name(), "Test get token by id");
        assertEqual("unsigned_number", ts[17]->name(), "Test get token by id");
        assertEqual("2", ts[18]->name(), "Test get token by id");
        assertEqual(")", ts[19]->name(), "Test get token by id");
        
//        std::cout << ts.reportToken(); 
        assertEqual(
"(name : init) (token id : 0) (father token id : -1) (child token id : 1)\n"
"(name : expression) (token id : 1) (father token id : 0) (child token id : 2 3 27)\n"
"(name : () (token id : 2) (father token id : 1) (child token id : )\n"
"(name : expression) (token id : 3) (father token id : 1) (child token id : 4 20 22)\n"
"(name : expression) (token id : 4) (father token id : 3) (child token id : 5 6 19)\n"
"(name : () (token id : 5) (father token id : 4) (child token id : )\n"
"(name : expression) (token id : 6) (father token id : 4) (child token id : 7 12 14)\n"
"(name : expression) (token id : 7) (father token id : 6) (child token id : 8)\n"
"(name : primary) (token id : 8) (father token id : 7) (child token id : 9)\n"
"(name : number) (token id : 9) (father token id : 8) (child token id : 10)\n"
"(name : unsigned_number) (token id : 10) (father token id : 9) (child token id : 11)\n"
"(name : 1) (token id : 11) (father token id : 10) (child token id : )\n"
"(name : binary_operator) (token id : 12) (father token id : 6) (child token id : 13)\n"
"(name : +) (token id : 13) (father token id : 12) (child token id : )\n"
"(name : expression) (token id : 14) (father token id : 6) (child token id : 15)\n"
"(name : primary) (token id : 15) (father token id : 14) (child token id : 16)\n"
"(name : number) (token id : 16) (father token id : 15) (child token id : 17)\n"
"(name : unsigned_number) (token id : 17) (father token id : 16) (child token id : 18)\n"
"(name : 2) (token id : 18) (father token id : 17) (child token id : )\n"
"(name : )) (token id : 19) (father token id : 4) (child token id : )\n"
"(name : binary_operator) (token id : 20) (father token id : 3) (child token id : 21)\n"
"(name : -) (token id : 21) (father token id : 20) (child token id : )\n"
"(name : expression) (token id : 22) (father token id : 3) (child token id : 23)\n"
"(name : primary) (token id : 23) (father token id : 22) (child token id : 24)\n"
"(name : number) (token id : 24) (father token id : 23) (child token id : 25)\n"
"(name : unsigned_number) (token id : 25) (father token id : 24) (child token id : 26)\n"
"(name : 3) (token id : 26) (father token id : 25) (child token id : )\n"
"(name : )) (token id : 27) (father token id : 1) (child token id : )\n"
                   , ts.reportToken()
                   , "Test report token");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

#if 0
void test_bit_select() {
  {
        StringParser parser("bit_select.ast");
//        assertEqual("(init (keywords begin\\n))", parser.str(), "Test parser str");
        parser.exec();
  }
  UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_range_select1() {
    {
        StringParser parser("range_select1.ast");
        parser.exec();
    }
}

void test_parathesis_throw() {
    {
        StringParser parser("parathesis_throw1.ast");

        try {
            parser.exec();
            std::cerr << "*Error: Exception not throw" << std::endl;
        } catch (const InvalidFormatException & e) {
        }
    }
}

void test_unsigned_number1() {
    StringParser parser("unsigned_number1.ast");
    TokenStructure ts = *(parser.exec());
    std::cout << ts.reportToken();
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

#endif

void test_structure_with_space() {
	StringParser parser;
    TokenStructureHandle pTokenStructure = parser.parseString("(continuous_assign (keyword assign ) (number 2))");
	TokenStructure ts = *pTokenStructure;
	assertEqual(5, ts.getTokenSize(), "Test get token size");
	assertEqual("continuous_assign", ts[0]->name(), "Test token name");
	assertEqual("keyword", ts[1]->name(), "Test token name");
	assertEqual("assign", ts[2]->name(), "Test token name");
	assertEqual("number", ts[3]->name(), "Test token name");
	assertEqual("2", ts[4]->name(), "Test token name");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_parse_par_asterisk_par() {
	StringParser parser;
    TokenStructureHandle pTokenStructure = parser.parseString("(event_control @ ( * ))");
	TokenStructure ts = *pTokenStructure;
//	assertEqual(5, ts.getTokenSize(), "Test get token size");
	assertEqual("event_control", ts[0]->name(), "Test token name");
	assertEqual("@", ts[1]->name(), "Test token name");
	assertEqual("(", ts[2]->name(), "Test token name");
	assertEqual("*", ts[3]->name(), "Test token name");
	assertEqual(")", ts[4]->name(), "Test token name");
	UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {


    test_keyword_begin();

    test_parathesis1();
	test_ternary_op();
	test_structure_with_space();
    test_parse_par_asterisk_par();
//    test_unsigned_number1();
//    test_range_select1();
//    test_bit_select();

//    test_parathesis_throw();    

    return 0;
}
