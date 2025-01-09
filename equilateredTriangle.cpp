#include "EquilateralTriangle.h"

// Constructor
EquilateralTriangle::EquilateralTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3)
    : Shape(color), p1(p1), p2(p2), p3(p3) {
    if (!is_equilateral(p1, p2, p3)) {
        throw std::runtime_error("Los puntos no forman un triángulo equilátero.");
    }
}

// Verificar si los puntos forman un triángulo equilátero
bool EquilateralTriangle::is_equilateral(const Point2D& p1, const Point2D& p2, const Point2D& p3) {
    double d1 = Point2D::distance(p1, p2);
    double d2 = Point2D::distance(p2, p3);
    double d3 = Point2D::distance(p3, p1);

    // Los tres lados deben ser iguales y los puntos no deben coincidir
    return (d1 == d2 && d2 == d3) && !(p1 == p2 || p2 == p3 || p1 == p3);
}

// Calcular el área del triángulo
double EquilateralTriangle::area() const {
    double side = Point2D::distance(p1, p2);
    double height = std::sqrt(std::pow(side, 2) - std::pow(side / 2, 2));
    return (side * height) / 2;
}

// Calcular el perímetro del triángulo
double EquilateralTriangle::perimeter() const {
    return Point2D::distance(p1, p2) * 3;
}

// Sobrecarga del operador ==
bool operator==(const EquilateralTriangle& a, const EquilateralTriangle& b) {
    return a.p1 == b.p1 && a.p2 == b.p2 && a.p3 == b.p3 && a.color == b.color;
}

// Sobrecarga del operador []
Point2D EquilateralTriangle::operator[](int ind) const {
    switch (ind) {
        case 0: return p1;
        case 1: return p2;
        case 2: return p3;
        default: throw std::runtime_error("Índice fuera de rango. Use 0, 1 o 2.");
    }
}
