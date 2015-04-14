/*pcc.cpp*/
#include <iostream>
#include "pcc.h"
#define PI 3.14159

Point::Point (float a = 0, float b = 0) : x(a), y(b) {}

void Point::setPoint (float a, float b)
{
	x = a;
	y = b;
}

float Point::getX () const {return x;}
float Point::getY () const {return y;}

std::ostream &operator << (std::ostream& output, const Point& poi)
{
	output << "The pointer is: [" << poi.getX() << "," << poi.getY() << "]" << std::endl;
	return output;
}

Circle::Circle (float a = 0, float b == 0, float r = 0) : Point(a,b), radius(r) {}

void Circle::setRadius (float r) {radius = r;}

float Circle::getRadius () const {return radius;}
float Circle::getArea () const {return PI * radius * radius;}

std::ostream &operator << (std::ostream& output, const Circle& cir)
{
	output << "Center=[" << cir.getX() << "," << cir.getY() << "],r=" <<
			cir.getRadius() << ",area=" << cir.getArea() << std::endl;
}

Cylinder::Cylinder (float a=0, float b=0, float r=0, float h=0) : Circle(a,b,r), height(h) {}

void Cylinder::setHeight (float h) {height = h;}

float Cylinder::getHeight () const {return height;}
float Cylinder::getArea () const {return 2*Circle::getArea()+2*PI*radius*height;}
float Cylinder::getVolume () const {return Circle::getArea()*height;}

std::ostream &operator << (std::ostream& output, Cylinder& cyl)
{
	output << "Center=[" << cyl.getX() << "," << cyl.getY() << "],r="
	<< cyl.getRadius() << ",h=" << cyl.getHeight() << ",v=" << cyl.getVolume() << std::endl;
	return output;
}

