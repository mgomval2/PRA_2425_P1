#include "Square.h"
#include <iostream>

// Comprobar que los vértices forman un cuadrado
bool Square::check(Point2D* vertices) {
    double d1 = Point2D::distance(vertices[0], vertices[1]);
    double d2 = Point2D::distance(vertices[1], vertices[2]);
    return d1 == d2; // Todos los lados deben ser iguales
}

// Constructor por defecto
Square::Square() : Rectangle() {}

// Constructor parametrizado
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) throw std::invalid_argument("No forma un cuadrado");
}

// Establecer vértices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("Vértices no válidos para un cuadrado.");
    Rectangle::set_vertices(vertices);
}

// Método para el lado más largo
double Square::max_side() const {
    return Point2D::distance(vs[0], vs[1]); // Todos los lados son iguales
}

// Verificar si es regular
bool Square::is_regular() const {
    return true; // Siempre regular
}

// Imprimir cuadrado
void Square::print() {
    std::cout << *this;
}

// Operador de flujo
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.get_color() << "; v0 = " << square[0] << "; v1 = " << square[1]
        << "; v2 = " << square[2] << "; v3 = " << square[3] << "]";
    return out;
}
