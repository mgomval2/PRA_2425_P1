#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"
#include "Point2D.h"

class RightTriangle : public Shape {
private:
    Point2D p1, p2, p3;

public:
    RightTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3);

    double area() const override;
    double perimeter() const override;
    double hypotenuse() const;

    static bool is_right_triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3);

    friend bool operator==(const RightTriangle& a, const RightTriangle& b);
    Point2D operator[](int ind) const;
};

#endif
