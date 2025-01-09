#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Shape.h"
#include "Point2D.h"

class Parallelogram : public Shape {
private:
    Point2D p1, p2, p3, p4;

public:
    Parallelogram(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4);

    double area() const override;
    double perimeter() const override;
    double height() const;

    static bool is_parallelogram(const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4);

    friend bool operator==(const Parallelogram& a, const Parallelogram& b);
    Point2D operator[](int ind) const;
};

#endif
