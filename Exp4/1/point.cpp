/*point.cpp*/
#include <iostream>
#include "point.h"
#define PI 3.14159	//宏定义π的值 为 3.14159 
Point::Point (float a = 0, float b = 0) : x(a), y(b) {}	//Point的构造函数 

void Point::setPoint (float a, float b)
{
	x = a;
	y = b;
}
/*Point类内函数定义部分*/
float Point::getX () const {return x;}
float Point::getY () const {return y;}	//两个取值函数 

std::ostream &operator << (std::ostream& output, const Point& poi)	//Point的重载<< 
{
	output << "The pointer is: [" << poi.getX() << "," << poi.getY() << "]" << std::endl;
	return output;
}

