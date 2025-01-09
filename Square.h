#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    Square();
    Square(std::string color, Point2D* vertices);

    void set_vertices(Point2D* vertices) override;

    friend std::ostream& operator<<(std::ostream &out, const Square &square);

    double max_side() const override; // El lado es siempre igual
    bool is_regular() const override; // Siempre regular
    void print() override;
};

#endif
