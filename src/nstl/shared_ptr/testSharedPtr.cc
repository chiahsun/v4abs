#include "SharedPtr.h"
#include "test/UnitTest.h"

#include <string>
#include <vector>

typedef SharedPtr<int> IntHandle;

void test_constructor() {
    IntHandle pInt(10);
    assertEqual(1, pInt.count(), "Test count");
    assertEqual(10, *pInt, "Test dereference pint");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_copy_constructor() {
    IntHandle pInt1(10);
    IntHandle pInt2(pInt1);

    assertEqual(2, pInt1.count(), "Test count");
    assertEqual(10, *pInt1, "Test dereference pint");
    assertEqual(10, *pInt2, "Test dereference pint");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_assignment_operator() {
    IntHandle pInt1(12);
    assertEqual(1, pInt1.count(), "Test count");
    assertEqual(12, *pInt1, "Test dereference pint");
    IntHandle pInt2;
    pInt2 = pInt1;
    
    assertEqual(2, pInt2.count(), "Test count");
    assertEqual(12, *pInt1, "Test dereference pint");
    assertEqual(12, *pInt2, "Test dereference pint");
    assertEqual(1, pInt1.count(), "Test count");
    assertEqual(1, pInt2.count(), "Test count");

    IntHandle pInt3(20);
    assertEqual(1, pInt3.count(), "Test count");
    assertEqual(20, *pInt3, "Test dereference pint");
    pInt3 = pInt2;

    assertEqual(1, pInt1.count(), "Test count");
    assertEqual(2, pInt2.count(), "Test count");
    assertEqual(2, pInt3.count(), "Test count");
#if 0
    assertEqual(3, pInt1.count(), "Test count");
    std::cout << pInt1.toString() << std::endl;
    assertEqual(3, pInt2.count(), "Test count");
    std::cout << pInt2.toString() << std::endl;
    assertEqual(3, pInt3.count(), "Test count");
    std::cout << pInt3.toString() << std::endl;
#endif
    assertEqual(12, *pInt1, "Test dereference pint");
    assertEqual(12, *pInt2, "Test dereference pint");
    assertEqual(12, *pInt3, "Test dereference pint");



    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_throw_invalid_rhs() {

    IntHandle pNull;
    assertEqual(false, pNull.valid(), "Test valid");
    IntHandle p;
    assertEqual(false, p.valid(), "Test valid");
    p = pNull;
    assertEqual(false, p.valid(), "Test valid");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

struct Composite {
    IntHandle _pFst;
    IntHandle _pSnd;
public:
    Composite(IntHandle pFst, IntHandle pSnd) : _pFst(pFst), _pSnd(pSnd) { }
    Composite(int x, int y) : _pFst(x), _pSnd(y) { }

    int getFstInt() const { return *_pFst; }
    int getSndInt() const { return *_pSnd; }
    int& getFstInt() { return *_pFst; }
    int& getSndInt() { return *_pSnd; }

    const IntHandle& getFstConstIntHandle() const { return _pFst; }
    const IntHandle& getSndConstIntHandle() const { return _pSnd; }

    IntHandle& getFstIntHandle() { return _pFst; }
    IntHandle& getSndIntHandle() { return _pSnd; }
};

void test_composite() {
    {
        Composite com(10, 12);
        assertEqual(10, com.getFstInt(), "Test get first int");
        assertEqual(12, com.getSndInt(), "Test get second int");
    }

    {
        Composite com(IntHandle(2), IntHandle(3));
        assertEqual(2, com.getFstInt(), "Test get first int");
        assertEqual(3, com.getSndInt(), "Test get second int");
        *com.getFstIntHandle() = 4;
        *com.getSndIntHandle() = 5;
        assertEqual(4, com.getFstInt(), "Test get first int");
        assertEqual(5, com.getSndInt(), "Test get second int");
        ++com.getFstInt();
        ++com.getSndInt();
        assertEqual(5, com.getFstInt(), "Test get first int");
        assertEqual(6, com.getSndInt(), "Test get second int");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

struct StringPrintInterface {
public:
    virtual ~StringPrintInterface() { }
    // virtual std::string toString() const { return "null"; }; // Avoid using this style
    virtual std::string toString() const = 0;
};

typedef SharedPtr<StringPrintInterface> StringPrintInterfaceHandle;

struct BaseNode : public StringPrintInterface {
public:
    BaseNode() {}
    virtual ~BaseNode() {}
    int getInt() const { return 10; }
    virtual std::string toString() const { return "I am base"; }
};

typedef SharedPtr<StringPrintInterface> StringPrintHandle;
typedef SharedPtr<BaseNode> BaseNodeHandle;

struct DerivedNode : public BaseNode {
public:
    DerivedNode() { }
    virtual ~DerivedNode() {}
    virtual std::string toString() const { return "I am derived"; }
};

typedef SharedPtr<DerivedNode> DerivedNodeHandle;

void test_derived() {

    {
        BaseNode baseNode;
        BaseNodeHandle pBase(baseNode);
   //     DerivedNodeHandle pDerived(DerivedNode());
        DerivedNode derivedNode;
        DerivedNodeHandle pDerived(derivedNode);
        assertEqual("I am base", pBase->toString(), "Test base to string");
        assertEqual("I am derived", pDerived->toString(), "Test derived to string");

#if 0
        StringPrintHandle pPrintBase(shared_ptr_cast<StringPrintInterface>(pBase));
        StringPrintHandle pPrintDerived(shared_ptr_cast<StringPrintInterface>(pDerived));
        assertEqual("I am base", pPrintBase->toString(), "Test base to string");
        assertEqual("I am derived", pPrintDerived->toString(), "Test derived to string");
#endif
    }
#if 0
    {
        BaseNode baseNode;
        DerivedNode derivedNode;
        StringPrintHandle pBase(baseNode);
        StringPrintHandle pDerived(derivedNode);
        std::cout << "This is not a output we want, but we cannot solve now. (chiahsun)\n"
                     "This may due to an implicit data_type conversion from derived_type to base_type and shared_ptr_cast<base_type>()"
                     "You can declare the interface as virtual to avoid unintended conversion !"<< std::endl;
        assertEqual("I am base", pBase->toString(), "Test base to string");
        assertEqual("I am derived", pDerived->toString(), "Test derived to string");
    }
#endif
    {
  //      SharedPtr<BaseNode> pBase(BaseNode());
//        assertEqual("I am base", pBase->toString(), "Test base to string");
        // assertEqual("I am derived", pDerived->toString(), "Test derived to string");
    }
//    assertEqual(10, pBase->getInt(), "Test get int");
//    assertEqual("I am derived", pDerived->toString(), "Test derived to string");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vector() {
    IntHandle p0(0);
    IntHandle p1(1);
    IntHandle p2(2);

    std::vector<IntHandle> vecInt;
    vecInt.push_back(p0);
    vecInt.push_back(p1);
    vecInt.push_back(p2);

    assertEqual(0, *vecInt[0], "Test vector");
    assertEqual(1, *vecInt[1], "Test vector");
    assertEqual(2, *vecInt[2], "Test vector");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

typedef SharedPtr<char> CharHandle;

class Tuple : public StringPrintInterface {
    CharHandle _p1;
    CharHandle _p2;
public:
    Tuple(char x, char y) : _p1(x), _p2(y) { }
    std::string toString() const {
        return std::string("<") + *_p1 + "," + *_p2 + ">";
    }
    void set(char x, char y) { _p1 = CharHandle(x); _p2 = CharHandle(y); }
};

typedef SharedPtr<Tuple> TupleHandle;

class Seq : public StringPrintInterface {
    CharHandle _p1;
    CharHandle _p2;
public:
    Seq(char x, char y) : _p1(x), _p2(y) { }
    std::string toString() const {
        return std::string("[") + *_p1 + *_p2 + "]";
    }
    void set(char x, char y) { _p1 = CharHandle(x); _p2 = CharHandle(y); }
};

typedef SharedPtr<Seq> SeqHandle;

class Varint {
    SharedPtr<Tuple> _pTuple;
    SharedPtr<Seq> _pSeq;

    SharedPtr<StringPrintInterface> _pStringPrintInterface;
public:
    Varint(SharedPtr<Tuple> pTuple) : _pTuple(pTuple), _pStringPrintInterface(shared_ptr_cast<StringPrintInterface>(pTuple)) { }
    Varint(SharedPtr<Seq> pSeq) : _pSeq(pSeq), _pStringPrintInterface(shared_ptr_cast<StringPrintInterface>(pSeq)) { }
    // (Avoid) we should not implicit cast to interface type, it brings more trouble than its shorthand benefit
    // Varint(SharedPtr<Seq> pSeq) : _pSeq(pSeq), _pStringPrintInterface(StringPrintInterfaceHandle(pSeq)) { }

    std::string toString() const { return _pStringPrintInterface->toString(); }

    SharedPtr<Tuple> getTupleHandle() const { return _pTuple; }
    SharedPtr<Seq> getSeqHandle() const { return _pSeq; }

};

typedef SharedPtr<Varint> VarintHandle;

void test_variant1() {

    Tuple tuple('a', 'b');
    Seq seq('a', 'b');
    {
        Varint variant = SharedPtr<Tuple>(tuple);
        assertEqual("<a,b>", variant.toString(), "Test tuple to string");
        variant.getTupleHandle() = SharedPtr<Tuple>(Tuple('c', 'd'));
        assertEqual("<c,d>", variant.toString(), "Test tuple to string");
    }
    {
        Varint variant = SharedPtr<Seq>(seq);
        assertEqual("[ab]", variant.toString(), "Test seq to string");
        variant.getSeqHandle() = SharedPtr<Seq>(Seq('c', 'd'));
        assertEqual("[cd]", variant.toString(), "Test seq to string");
    }

    assertEqual("<c,d>", tuple.toString(), "Test tuple to string");
    assertEqual("[cd]", seq.toString(), "Test seq to string");



    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_variant2() {

    {
        Varint variant = SharedPtr<Tuple>(Tuple('a', 'b'));
        assertEqual("<a,b>", variant.toString(), "Test tuple to string");
//        variant.getTupleHandle() = SharedPtr<Tuple>(Tuple('c', 'd'));
//        assertEqual("<c,d>", variant.toString(), "Test tuple to string");
    }
    {
        Varint variant = SharedPtr<Seq>(Seq('a', 'b'));
        assertEqual("[ab]", variant.toString(), "Test seq to string");
//        variant.getSeqHandle() = SharedPtr<Seq>(Seq('c', 'd'));
//        assertEqual("[cd]", variant.toString(), "Test seq to string");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_variant3() {
    {
        Varint variant = Varint(TupleHandle(Tuple('a', 'b')));
        assertEqual("<a,b>", variant.toString(), "Test variant to string");
//        pVariant->getTupleHandle() = TupleHandle(Tuple('c', 'd'));
//        assertEqual("<c,d>", pVariant->toString(), "Test variant to string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_equality_test() {
    IntHandle p1(20);
    IntHandle p2(20);
    assertEqual(true, p1 == p2, "Test equality test");
    assertEqual(false, p1 != p2, "Test equality test");
}

int main() {
    test_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_throw_invalid_rhs();
    test_composite();
    test_derived();
    test_vector();
//    test_variant1();
//    test_variant2();
    test_variant3();
#if 0
#endif
    return 0;
}
