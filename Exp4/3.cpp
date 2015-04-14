/*
声明抽象基类Shape，由它派生出3个派生类：Circle(圆形)、Rectangle(矩形)、Triangle(三角形)，
用一个函数printArea分别输出以上三者的面积，3个图形的数据在定义对象时给定。
*/
#include <iostream>
#define PI 3.14159
#define INIT 0
using namespace std;
class Shape
{
public:
	virtual float printArea () const {return INIT;}
	virtual void shapeName () const = INIT;
};

class Circle : public Shape
{
public:
	Circle (float r = 0) : radius(r) {}
	void setRadius (float r) {radius = r;}
	float getRadius () const {return radius;}
	virtual void shapeName () const {cout << "Circle:" << endl;}
	virtual float printArea () const {return PI*radius*radius;}
	friend ostream& operator << (ostream&, Circle&);//D
protected:
	float radius;
};

class Rectangle : public Shape
{
public:
	Rectangle (float l = 0, float w = 0) : length(l), weight(w) {}
	void setElems (float l, float w) {length=l; weight=w;}
	float getLength () const {return length;}
	float getWeight () const {return weight;}
	virtual void shapeName () const {cout << "Rectangle:" << endl;}
	virtual float printArea () const {return length*weight;}
	friend ostream& operator << (ostream&, Rectangle&);//D
protected:
	float length;
	float weight;
};

class Triangle : public Shape
{
public:
	Triangle (float l = 0, float h = 0) : length(l), height(h) {}
	void setElems (float l, float h) {length=l; height = h;}
	float getLength () const {return length;}
	float getHeight () const {return height;}
	virtual void shapeName () const {cout << "Triangle:" << endl;}
	virtual float printArea () const {return length*height/2;}
	friend ostream& operator << (ostream&, Triangle&);//D
protected:
	float length;
	float height;
};

ostream& operator << (ostream& output, Circle& cir)
{
	output << "The radius is: " << cir.getRadius() << " and the area is: " << cir.printArea() << endl;
	return output;
}
ostream& operator << (ostream& output, Rectangle& rec)
{
	output << "The length is: " << rec.getLength() << 
			", the weight is: " << rec.getWeight() << 
			". and the area is: " << rec.printArea() << endl;
}
ostream& operator << (ostream& output, Triangle& tri)
{
	output << "The length is: " << tri.getLength() << 
			", the height is: " << tri.getHeight() << 
			". and the area is: " << tri.printArea() << endl;
}
int main()
{
	Circle cir;
	Rectangle rec;
	Triangle tri;
	cout << "Init status: "<< endl;
	cout << cir << rec << tri << endl;
	cout << "-----Now I'm going to change something :-)-----" << endl << endl;
	cir.setRadius (4.3);
	rec.setElems (5,4);
	tri.setElems (3.1,2);
	cout << "Done. Let's have a look: " << endl;
	cout << cir << rec << tri << endl;
	cout <<"WOW. It does work! I enjoyed it." << endl;
	return 0;
}
