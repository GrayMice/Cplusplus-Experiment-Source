/*
声明一个复数类Complex,重载运算符“+”，使之能用于复数的加法运算。
参加运算的两个运算量可以都是类对象，也可以其中有一个是整数，顺序任意。
例如：c1+ c2,i+c1,c1+i（设i为整数，c1,c2为复数）
*/

//我换了个运算符重载的写法
#include <iostream>
using namespace std;
typedef class Complex
{
public:
	Complex (double r = 0, double i = 0):real(r),image(i){};
	friend Complex operator + (Complex &C1, Complex &C2){return Complex(C1.real+C2.real,C1.image+C2.image);}
	friend Complex operator + (Complex &C1, double r)	{return Complex(r+C1.real,C1.image);}
	friend Complex operator + (double r, Complex &C1)	{return Complex(r+C1.real,C1.image);}
	friend ostream& operator<<(ostream&,Complex&);
private:
	double image;				
	double real;				
}Complex;

int main()
{
	double r1 = 3.2;
	Complex c1(1.6,2), c2(6,1.5), c3;
	cout << "r1=" << r1 << endl;
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl << endl;
	c3 = r1 + c1;	cout << "c3=" << c3 << endl;
	c3 = c1 + r1;	cout << "c3=" << c3 << endl;
	c3 = c1 + c2;	cout << "c3=" << c3 << endl;
	return 0;
}

ostream& operator<<(ostream& Output, Complex& C1)
{
	Output << "(" << C1.real << "+" << C1.image << "i)";//格式化输出
}
