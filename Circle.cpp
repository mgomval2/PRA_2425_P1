#include <cmath>
#include <iostream>

#include "Circle.h"

#define pi 3.141592

Circle::Circle(): center{Point2D(0, 0)}, radius{1.0}{
}

Circle::Circle(std::string color, Point2D center, double radius): center{center}, radius{radius}{
	set_color(color);
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circle: color = " << c.color << "; center = " << c.center << "; radius = " << c.radius << "]";
	return out;
}


double Circle::area() const{
	return pi*pow(radius,2);
}

double Circle::perimeter() const{
	return 2*pi*radius;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

void Circle::print(){
	std::cout << *this;
}
