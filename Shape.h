#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"
#include "Rectangle.h"

class Shape {
protected:
    std::string color;

public:
    Shape();
    Shape(std::string color);

    std::string get_color() const;
    void set_color(std::string c);

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual double max_side() const = 0;

    // Métodos añadidos
    virtual Rectangle bounding_box() const = 0;
    virtual bool contains(const Point2D& p) const = 0;
    virtual double distance_to(const Point2D& p) const = 0;
    virtual bool is_regular() const = 0;
    virtual void rotate(double angle, const Point2D& pivot = Point2D(0, 0)) = 0;

    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;

    virtual ~Shape() = default;
};

#endif
