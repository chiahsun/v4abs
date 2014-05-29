#include "Variant.h"
#include "test/UnitTest.h"

class AreaInterface {
public:
    virtual ~AreaInterface() {}
    virtual int getArea() const = 0;
};

class Rect : public AreaInterface {
public:
    int _width;
    int _height;
    Rect(int width, int height)
      : _width(width)
      , _height(height)
      { }
    
    int getArea() const { return _width * _height; }
};

class Circle : public AreaInterface {
    int _r;
public:
    Circle(int r)
      : _r(r)
      { }

    int getArea() const { return 2 * 3.14 * _r; }
};

class Square : public AreaInterface {
public:
    int _w;
    Square(int w) : _w(w) { }
    int getArea() const { return _w * _w; }
};
void test_variant2() {
    Rect rect(10, 2);
//    Variant2<Rect, Circle, AreaInterface> variant(rect);
    Variant2<Rect, Circle, AreaInterface> variant(rect);
    assertEqual(10, variant.getFstHandle()->_width, "Test get area ");
    assertEqual(2, variant.getFstHandle()->_height, "Test get area ");
    assertEqual(20, variant->getArea(), "Test get area ");
    variant.getFstHandle()->_height = 4;
    assertEqual(10, variant.getFstHandle()->_width, "Test get area ");
    assertEqual(4, variant.getFstHandle()->_height, "Test get area ");
    assertEqual(40, variant->getArea(), "Test get area ");

    Circle circle(2);
    Variant2<Rect, Circle, AreaInterface> variant2(circle);
    variant2 = rect;

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_variant3() {
    Square square(3);
    Variant3<Rect, Circle, Square, AreaInterface> variant(square);
    assertEqual(9, variant->getArea(), "Test get area");
    variant.getTrdHandle()->_w = 4; 
    assertEqual(16, variant->getArea(), "Test get area");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_variant2();
    test_variant3();
    return 0;
}
