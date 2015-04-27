/*circle.cpp*/
#include <iostream>
#include "circle.h"
#define PI 3.14159	//�궨��е�ֵ Ϊ 3.14159 
/*Circle���ں������岿��*/
Circle::Circle (float a = 0, float b = 0, float r = 0) : Point(a,b), radius(r) {}

void Circle::setRadius (float r) {radius = r;}

float Circle::getRadius () const {return radius;}
float Circle::getArea () const {return PI * radius * radius;}

std::ostream &operator << (std::ostream& output, const Circle& cir)	//Circle������<< 
{
	output << "Center=[" << cir.getX() << "," << cir.getY() << "],r=" <<
			cir.getRadius() << ",area=" << cir.getArea() << std::endl;
}

