/*
声明抽象基类Shape，由它派生出3个派生类：Circle(圆形)、Rectangle(矩形)、Triangle(三角形)，
用一个函数printArea分别输出以上三者的面积，3个图形的数据在定义对象时给定。
*/
#include <iostream>
#define PI 3.14159
#define INIT 0	//为了初始化虚函数特别宏定义一个值
using namespace std;
class Shape
{
public:	//定义两个虚函数
	virtual float printArea () const {return INIT;}
	virtual void shapeName () const = INIT;
};

class Circle : public Shape 	//定义Circle类，公有继承于Shape
{
public:
	Circle (float r = 0) : radius(r) {} //Circle的构造函数
	void setRadius (float r) {radius = r;}
	float getRadius () const {return radius;}

	virtual void shapeName () const {cout << "Circle:" << endl;}
	virtual float printArea () const {return PI*radius*radius;}
	//重定义两个虚函数
	friend ostream& operator << (ostream&, Circle&);//重载<<运算符
protected:
	float radius;
};

class Rectangle : public Shape
{
public:
	Rectangle (float l = 0, float w = 0) : length(l), weight(w) {}//Rectangle的构造函数
	void setElems (float l, float w) {length=l; weight=w;}
	float getLength () const {return length;}
	float getWeight () const {return weight;}

	virtual void shapeName () const {cout << "Rectangle:" << endl;}
	virtual float printArea () const {return length*weight;}
	//重定义两个虚函数
	friend ostream& operator << (ostream&, Rectangle&);//重载<<运算符
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
	//重定义两个虚函数
	friend ostream& operator << (ostream&, Triangle&);//重载<<运算符
protected:
	float length;
	float height;
};

/*三个<<的重载写在了下面。*/

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
int main ()
{
	Circle cir;
	Rectangle rec;
	Triangle tri;	//定义三个不同类的变量，根据构造函数，他们会自动初始化。
	cout << "-----Init status: (I inited them by 0. Don't feel strange.)-----"<< endl << endl;
	cout << cir << rec << tri << endl;	//输出结果
	cout << "-----Now I'm going to change something :-)-----" << endl << endl;
	cir.setRadius (4.3);
	rec.setElems (5,4);
	tri.setElems (3.1,2);	//重新赋值
	cout << "Done. Let's have a look: " << endl;
	cout << cir << rec << tri << endl;
	cout << "-----:Let's have a try with the pointer and virtual class:-----" << endl << endl;
	Shape *ptr;	//声明虚基类指针
	ptr = &cir;
	cout <<  "The circle's area is: " << ptr->printArea() << endl;
	ptr = &rec;
	cout <<  "The rectangle's area is: " << ptr->printArea() << endl;
	ptr = &tri;
	cout <<  "The triangle's area is: " << ptr->printArea() << endl;
	cout << endl << "WOW. It does work! I enjoyed it." << endl;	//输出结果
	return 0;
}
