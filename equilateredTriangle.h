#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include <string>
#include <stdexcept>
#include <cmath>
#include "Shape.h"
#include "Point2D.h"

class EquilateralTriangle : public Shape {
private:
    Point2D p1, p2, p3;

public:
    // Constructor
    EquilateralTriangle(std::string color, const Point2D& p1, const Point2D& p2, const Point2D& p3);

    // Métodos heredados de Shape
    double area() const override;
    double perimeter() const override;

    // Sobrecarga de operadores
    friend bool operator==(const EquilateralTriangle& a, const EquilateralTriangle& b);
    Point2D operator[](int ind) const;

    // Método para verificar si los puntos forman un triángulo equilátero
    static bool is_equilateral(const Point2D& p1, const Point2D& p2, const Point2D& p3);
};

#endif
