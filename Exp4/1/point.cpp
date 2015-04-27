/*point.cpp*/
#include <iostream>
#include "point.h"
#define PI 3.14159	//�궨��е�ֵ Ϊ 3.14159 
Point::Point (float a = 0, float b = 0) : x(a), y(b) {}	//Point�Ĺ��캯�� 

void Point::setPoint (float a, float b)
{
	x = a;
	y = b;
}
/*Point���ں������岿��*/
float Point::getX () const {return x;}
float Point::getY () const {return y;}	//����ȡֵ���� 

std::ostream &operator << (std::ostream& output, const Point& poi)	//Point������<< 
{
	output << "The pointer is: [" << poi.getX() << "," << poi.getY() << "]" << std::endl;
	return output;
}

