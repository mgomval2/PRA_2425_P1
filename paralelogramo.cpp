#include "paralelogramo.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

// Constructor
Parallelogram::Parallelogram(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4)
    : Shape(color), p1(p1), p2(p2), p3(p3), p4(p4) {
    if (!is_parallelogram(p1, p2, p3, p4)) {
        throw std::runtime_error("Los puntos no forman un paralelogramo.");
    }
}

// Verificar si los puntos forman un paralelogramo
bool Parallelogram::is_parallelogram(const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4) {
    // Comprobar que las diagonales se cruzan en el mismo punto
    double midX1 = (p1.x + p3.x) / 2;
    double midY1 = (p1.y + p3.y) / 2;

    double midX2 = (p2.x + p4.x) / 2;
    double midY2 = (p2.y + p4.y) / 2;

    return midX1 == midX2 && midY1 == midY2;
}

// Cálculo del área
double Parallelogram::area() const {
    // Base por altura (altura calculada usando el punto perpendicular)
    double base = Point2D::distance(p1, p2);
    double height = std::abs((p3.y - p1.y) * base / Point2D::distance(p1, p3));
    return base * height;
}

// Cálculo del perímetro
double Parallelogram::perimeter() const {
    return 2 * (Point2D::distance(p1, p2) + Point2D::distance(p2, p3));
}

// Altura del paralelogramo
double Parallelogram::height() const {
    double base = Point2D::distance(p1, p2);
    return std::abs((p3.y - p1.y) * base / Point2D::distance(p1, p3));
}

// Sobrecarga de operadores
bool operator==(const Parallelogram& a, const Parallelogram& b) {
    return a.p1 == b.p1 && a.p2 == b.p2 && a.p3 == b.p3 && a.p4 == b.p4 && a.color == b.color;
}

Point2D Parallelogram::operator[](int ind) const {
    switch (ind) {
        case 0: return p1;
        case 1: return p2;
        case 2: return p3;
        case 3: return p4;
        default: throw std::out_of_range("Índice fuera de rango. Use 0, 1, 2 o 3.");
    }
}
