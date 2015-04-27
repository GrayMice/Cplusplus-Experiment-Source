/*cylinder.cpp*/
#include <iostream>
#include "cylinder.h"
#define PI 3.14159	//宏定义π的值 为 3.14159 
/*Cylinder类内函数定义部分*/
Cylinder::Cylinder (float a=0, float b=0, float r=0, float h=0) : Circle(a,b,r), height(h) {}

void Cylinder::setHeight (float h) {height = h;}

float Cylinder::getHeight () const {return height;}
float Cylinder::getArea () const {return 2*Circle::getArea()+2*PI*radius*height;}
float Cylinder::getVolume () const {return Circle::getArea()*height;}

std::ostream &operator << (std::ostream& output, Cylinder& cyl)	//Cylinder的重载<< 
{
	output << "Center=[" << cyl.getX() << "," << cyl.getY() << "],r="
	<< cyl.getRadius() << ",h=" << cyl.getHeight() << ",v=" << cyl.getVolume() << std::endl;
	return output;
}

