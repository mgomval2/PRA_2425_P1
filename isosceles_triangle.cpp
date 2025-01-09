#include "ISOSCELESTRIANGLE_H.h"
#include <cmath>
#include <stdexcept>

// Constructor
IsoscelesTriangle::IsoscelesTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3)
    : Shape(color), p1(p1), p2(p2), p3(p3) {
    if (!is_isosceles(p1, p2, p3)) {
        throw std::runtime_error("Los puntos no forman un triángulo isósceles.");
    }
}

// Verificar si los puntos forman un triángulo isósceles
bool IsoscelesTriangle::is_isosceles(const Point2D& p1, const Point2D& p2, const Point2D& p3) {
    double d1 = Point2D::distance(p1, p2);
    double d2 = Point2D::distance(p2, p3);
    double d3 = Point2D::distance(p3, p1);
    return (d1 == d2 || d2 == d3 || d3 == d1);
}

// Cálculo del área
double IsoscelesTriangle::area() const {
    double base = base_length();
    double side = (Point2D::distance(p1, p2) == base) ? Point2D::distance(p1, p3) : Point2D::distance(p1, p2);
    double height = std::sqrt(std::pow(side, 2) - std::pow(base / 2, 2));
    return (base * height) / 2;
}

// Cálculo del perímetro
double IsoscelesTriangle::perimeter() const {
    return Point2D::distance(p1, p2) + Point2D::distance(p2, p3) + Point2D::distance(p3, p1);
}

// Longitud de la base
double IsoscelesTriangle::base_length() const {
    double d1 = Point2D::distance(p1, p2);
    double d2 = Point2D::distance(p2, p3);
    double d3 = Point2D::distance(p3, p1);
    return std::max({d1, d2, d3});
}

// Sobrecarga de operadores
bool operator==(const IsoscelesTriangle& a, const IsoscelesTriangle& b) {
    return a.p1 == b.p1 && a.p2 == b.p2 && a.p3 == b.p3 && a.color == b.color;
}

Point2D IsoscelesTriangle::operator[](int ind) const {
    switch (ind) {
        case 0: return p1;
        case 1: return p2;
        case 2: return p3;
        default: throw std::out_of_range("Índice fuera de rango.");
    }
}
