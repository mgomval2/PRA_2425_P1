#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Shape.h"
#include "Point2D.h"

class IsoscelesTriangle : public Shape {
private:
    Point2D p1, p2, p3; // Vértices del triángulo

public:
    IsoscelesTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3);

    double area() const override;
    double perimeter() const override;
    double base_length() const;

    static bool is_isosceles(const Point2D& p1, const Point2D& p2, const Point2D& p3);

    friend bool operator==(const IsoscelesTriangle& a, const IsoscelesTriangle& b);
    Point2D operator[](int ind) const;
};

#endif
