#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;

private:
    static bool check(Point2D* vertices);

public:
    static int const N_VERTICES = 4;

    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);
    ~Rectangle();

    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    Rectangle& operator=(const Rectangle &r);

    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    void set_vertices(Point2D* vertices);

    // Métodos básicos de Shape
    double area() const override;
    double perimeter() const override;
    double max_side() const override;

    // Métodos nuevos añadidos
    bool contains(const Point2D& p) const override;
    double distance_to(const Point2D& p) const override;
    Rectangle bounding_box() const override;
    bool is_regular() const override;
    void rotate(double angle, const Point2D& pivot = Point2D(0, 0)) override;

    void translate(double incX, double incY) override;
    void print() override;
};

#endif
