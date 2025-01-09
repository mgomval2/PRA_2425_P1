#include "RightTriangle.h"
#include <cmath>
#include <stdexcept>

// Constructor
RightTriangle::RightTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3)
    : Shape(color), p1(p1), p2(p2), p3(p3) {
    if (!is_right_triangle(p1, p2, p3)) {
        throw std::runtime_error("Los puntos no forman un triángulo rectángulo.");
    }
}

// Verificar si los puntos forman un triángulo rectángulo
bool RightTriangle::is_right_triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3) {
    double d1 = std::pow(Point2D::distance(p1, p2), 2);
    double d2 = std::pow(Point2D::distance(p2, p3), 2);
    double d3 = std::pow(Point2D::distance(p3, p1), 2);
    return (d1 + d2 == d3) || (d2 + d3 == d1) || (d3 + d1 == d2);
}

// Cálculo del área
double RightTriangle::area() const {
    double base = std::min(Point2D::distance(p1, p2), Point2D::distance(p2, p3));
    double height = std::sqrt(std::pow(hypotenuse(), 2) - std::pow(base, 2));
    return (base * height) / 2;
}

// Cálculo del perímetro
double RightTriangle::perimeter() const {
    return Point2D::distance(p1, p2) + Point2D::distance(p2, p3) + Point2D::distance(p3, p1);
}

// Longitud de la hipotenusa
double RightTriangle::hypotenuse() const {
    double d1 = Point2D::distance(p1, p2);
    double d2 = Point2D::distance(p2, p3);
    double d3 = Point2D::distance(p3, p1);
    return std::max({d1, d2, d3});
}

// Sobrecarga de operadores
bool operator==(const RightTriangle& a, const RightTriangle& b) {
    return a.p1 == b.p1 && a.p2 == b.p2 && a.p3 == b.p3 && a.color == b.color;
}

Point2D RightTriangle::operator[](int ind) const {
    switch (ind) {
        case 0: return p1;
        case 1: return p2;
        case 2: return p3;
        default: throw std::out_of_range("Índice fuera de rango.");
    }
}
