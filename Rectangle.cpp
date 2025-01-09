#include "Rectangle.h"
#include <cmath>

// Comprobar que los vértices forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double d1 = Point2D::distance(vertices[0], vertices[1]);
    double d2 = Point2D::distance(vertices[2], vertices[3]);
    double d3 = Point2D::distance(vertices[1], vertices[2]);
    double d4 = Point2D::distance(vertices[3], vertices[0]);

    return d1 == d2 && d3 == d4;
}

// Constructor por defecto
Rectangle::Rectangle() {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1.0, 0.5),
        Point2D(1.0, 0.5),
        Point2D(1.0, -0.5),
        Point2D(-1.0, -0.5)
    };
    set_color("red");
}

// Constructor parametrizado
Rectangle::Rectangle(std::string color, Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("No forma un rectángulo");

    vs = new Point2D[N_VERTICES]{
        vertices[0],
        vertices[1],
        vertices[2],
        vertices[3]
    };
    set_color(color);
}

// Constructor copia
Rectangle::Rectangle(const Rectangle &r) {
    vs = new Point2D[N_VERTICES]{
        r.vs[0],
        r.vs[1],
        r.vs[2],
        r.vs[3]
    };
    set_color(r.get_color());
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Obtener un vértice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= 4) throw std::out_of_range("Índice fuera de rango");
    return vs[ind];
}

// Operador de acceso a vértices
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[N_VERTICES]{
            r.vs[0],
            r.vs[1],
            r.vs[2],
            r.vs[3]
        };
        set_color(r.get_color());
    }
    return *this;
}

// Operador de flujo
std::ostream& operator<<(std::ostream& out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.color << "; v0 = " << r[0] << "; v1 = " << r[1]
        << "; v2 = " << r[2] << "; v3 = " << r[3] << "]";
    return out;
}

// Establecer vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("Vértices no válidos");
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Cálculo del área
double Rectangle::area() const {
    double b = Point2D::distance(vs[0], vs[1]);
    double a = Point2D::distance(vs[1], vs[2]);
    return b * a;
}

// Cálculo del perímetro
double Rectangle::perimeter() const {
    double d1 = Point2D::distance(vs[0], vs[1]);
    double d2 = Point2D::distance(vs[2], vs[3]);
    double d3 = Point2D::distance(vs[1], vs[2]);
    double d4 = Point2D::distance(vs[3], vs[0]);
    return d1 + d2 + d3 + d4;
}

// Cálculo del lado más largo
double Rectangle::max_side() const {
    double side1 = Point2D::distance(vs[0], vs[1]);
    double side2 = Point2D::distance(vs[1], vs[2]);
    return (side1 > side2) ? side1 : side2;
}

// Verificar si un punto está dentro del rectángulo
bool Rectangle::contains(const Point2D& p) const {
    double minX = std::min(vs[0].x, vs[2].x);
    double maxX = std::max(vs[0].x, vs[2].x);
    double minY = std::min(vs[0].y, vs[2].y);
    double maxY = std::max(vs[0].y, vs[2].y);

    return p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY;
}

// Cálculo de la distancia al punto más cercano
double Rectangle::distance_to(const Point2D& p) const {
    double minX = std::min(vs[0].x, vs[2].x);
    double maxX = std::max(vs[0].x, vs[2].x);
    double minY = std::min(vs[0].y, vs[2].y);
    double maxY = std::max(vs[0].y, vs[2].y);

    if (contains(p)) {
        return 0.0;
    }

    double dx = std::max({minX - p.x, 0.0, p.x - maxX});
    double dy = std::max({minY - p.y, 0.0, p.y - maxY});

    return std::sqrt(dx * dx + dy * dy);
}

// Obtener bounding box (un rectángulo ya es su bounding box)
Rectangle Rectangle::bounding_box() const {
    return *this;
}

// Verificar si es regular (no lo es)
bool Rectangle::is_regular() const {
    return false;
}

// Rotar el rectángulo
void Rectangle::rotate(double angle, const Point2D& pivot) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vs[i].rotate(angle, pivot);
    }
}

// Trasladar el rectángulo
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Imprimir el rectángulo
void Rectangle::print() {
    std::cout << *this;
}
