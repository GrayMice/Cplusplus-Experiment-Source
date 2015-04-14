/*
在《C++面向对象程序设计》第6章例6.3的基础上作以下修改，并作必要的讨论。
a.把构造函数修改为带参数的函数，在建立对象时初始化。
b.先不将析构函数声明为virtual，在main函数中另设一个指向Point类对象的指针变量p，
  使它指向Circle类对象c。运行程序，分析结果。
c.不做b点的修改而将析构函数声明为virtual，运行程序，分析结果。
*/

#include <iostream>
using namespace std;
class Point
{
public:
	Point (float a = 0, float b = 0) : x(a), y(b) {}
virtual
	~Point () {cout << "executing Point destructor" << endl;}
protected:
	float x;
	float y;
};
class Circle : public Point
{
public:
	Circle (float a = 0, float b = 0, float r = 0) : Point(a,b), radius(r) {}
	virtual ~Circle () {cout << "executing Circle destructor" << endl;}
protected:
	float radius;
};

int main ()
{
	Point *p1 = new Circle(1,3);	//建立指向Point的指针p1
	Circle *p = new Circle(1,3,4);	//建立指向Circle的指针p
	delete p1;
	delete p;
	return 0;
}

/*
不加virtual，只有指向Circle的Point类指针p1时，只执行Point的析构函数。
不加virtual，只有指向Circle的Circle类指针p时，执行Point和Circle的析构函数。
加上virtual，两个指针都会执行Point和Circle的析构函数。
*/
