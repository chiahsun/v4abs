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

class Triangle : public AreaInterface {
public:
    int _w;
    Triangle(int w) : _w(w) { }
    int getArea() const { return _w * (1.732/2) * _w / 2; }
};

class Parallelogram : public AreaInterface {
    int _base;
    int _height;
public:
    Parallelogram(int base, int height) : _base(base), _height(height) { }
    int getArea() const { return _base * _height; }
};

class Trapezoid : public AreaInterface {
    int _w1, _w2;
    int _h;
public:
    Trapezoid(int w1, int w2, int h) : _w1(w1), _w2(w2), _h(h) { }
    int getArea() const { return (_w1+_w2) * _h / 2; }
};

class RectangularSolid : public AreaInterface {
    int _l, _w, _h;
public:
    RectangularSolid(int l, int w, int h) : _l(l), _w(w), _h(h) { }
    int getArea() const { return _l * _w * _h; }
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


void test_assignment_operator() {
    {
        Variant2<Rect, Circle, AreaInterface> x(Rect(2, 3));
        Variant2<Rect, Circle, AreaInterface> y = x;
        assertEqual(6, y->getArea(), "Test get area");
    }
    {
        Variant3<Rect, Circle, Square, AreaInterface> x(Rect(2, 2));
        assertEqual(4, x->getArea(), "Test get area");
        Variant3<Rect, Circle, Square, AreaInterface> y = x;
        assertEqual(4, y->getArea(), "Test get area");
    }
    {
        Variant3<Rect, Circle, Square, AreaInterface> x(Square(2));
        assertEqual(4, x->getArea(), "Test get area");
        Variant3<Rect, Circle, Square, AreaInterface> y = x;
        assertEqual(4, y->getArea(), "Test get area");
    }
    {
        Variant4<Rect, Circle, Square, Triangle, AreaInterface> x(Square(2));
        assertEqual(4, x->getArea(), "Test get area");
        Variant4<Rect, Circle, Square, Triangle, AreaInterface> y = x;
        assertEqual(4, y->getArea(), "Test get area");
    }
    {
        Variant4<Rect, Circle, Square, Triangle, AreaInterface> x(Triangle(3));
        assertEqual(3, x->getArea(), "Test get area");
        Variant4<Rect, Circle, Square, Triangle, AreaInterface> y = x;
        assertEqual(3, y->getArea(), "Test get area");
    }
    {
        Variant5<Rect, Circle, Square, Triangle, Parallelogram, AreaInterface> x(Triangle(3));
        assertEqual(3, x->getArea(), "Test get area");
        Variant5<Rect, Circle, Square, Triangle, Parallelogram, AreaInterface> y = x;
        assertEqual(3, y->getArea(), "Test get area");
    }
    {
        Variant5<Rect, Circle, Square, Triangle, Parallelogram, AreaInterface> x(Parallelogram(2, 4));
        assertEqual(8, x->getArea(), "Test get area");
        Variant5<Rect, Circle, Square, Triangle, Parallelogram, AreaInterface> y = x;
        assertEqual(8, y->getArea(), "Test get area");
    }
    {
        Variant6<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, AreaInterface> x(Parallelogram(2, 4));
        assertEqual(8, x->getArea(), "Test get area");
        Variant6<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, AreaInterface> y = x;
        assertEqual(8, y->getArea(), "Test get area");
    }
    {
        Variant6<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, AreaInterface> x(Trapezoid(3, 2, 4));
        assertEqual(10, x->getArea(), "Test get area");
        Variant6<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, AreaInterface> y = x;
        assertEqual(10, y->getArea(), "Test get area");
    }
    {
        Variant7<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, RectangularSolid, AreaInterface> x(Trapezoid(3, 2, 4));
        assertEqual(10, x->getArea(), "Test get area");
        Variant7<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, RectangularSolid, AreaInterface> y = x;
        assertEqual(10, y->getArea(), "Test get area");
    }
    {
        Variant7<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, RectangularSolid, AreaInterface> x(RectangularSolid(2, 4, 3));
        assertEqual(24, x->getArea(), "Test get area");
        Variant7<Rect, Circle, Square, Triangle, Parallelogram, Trapezoid, RectangularSolid, AreaInterface> y = x;
        assertEqual(24, y->getArea(), "Test get area");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_variant2();
    test_variant3();
    test_assignment_operator();
    return 0;
}
