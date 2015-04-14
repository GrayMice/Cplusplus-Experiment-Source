/*
（1）声明一个复数类Complex，重载运算符“+”，“-”，“*”，“/”，
使之能用于复数的加、减、乘、除，运算符重载函数作为Complex类的成员函数。
编程序，分别求两个复数之和、差、积和商。
*/

#include <iostream>
#include <cmath>							//调用求幂函数pow(,);
using namespace std;			

typedef class 
Complex 						//定义一个Complex类
{	
public:										//声明为公共成员的部分
	Complex (double r = 0, double i = 0):real(r),image(i){};	//初始化成员内的变量
	Complex operator + (Complex &C_buff);	//声明：重载四个运算符
	Complex operator - (Complex &C_buff);
	Complex operator * (Complex &C_buff);
	Complex operator / (Complex &C_buff);
	void input ();							//声明输入函数
	void display (Complex, Complex, char);	//声明输出函数
private:									//声明为私有成员的部分
	double image;							//虚数部分
	double real;							//实数部分
}Complex;
//char ChooseOperator (void);					//声明要选择的复数运算
/*
我将选择复数运算的部分注释掉了，是因为我要输出四种运算的结果，这样会更直观地显示
我重载过后的四个运算符的功能。
*/
int 
main()
{
//	char ch;				//为选择运算符而定义的字符变量ch
	Complex c1, c2, c3;		//定义三个复数类
	c1.input ();			//输入两个复数类
	c2.input ();
/*	
	ch = ChooseOperator ();	
	switch (ch)
	{
		case '+' : c3 = c1+c2; break;
		case '-' : c3 = c1-c2; break;
		case '*' : c3 = c1*c2; break;
		case '/' : c3 = c1/c2; break;
	}
	c3.display (c1, c2, ch);
此处注释掉同理，我将会直接输出四个结果的数据。
*/
	c3 = c1+c2; c3.display (c1, c2, '+');
	c3 = c1-c2; c3.display (c1, c2, '-');
	c3 = c1*c2; c3.display (c1, c2, '*');
	c3 = c1/c2; c3.display (c1, c2, '/');			//显示四种运算的结果，除法部分是以小数来显示的。
	return 0;										//为main函数返回一个值
}
/*
char ChooseOperator (void)
{
	char ch;															//定义一个字符变量。
	cout << "please input which operation do you want to do :" << endl;	//输出一段提示信息
	cin >> ch;															//输入ch，作为运算符
	return ch;															//返回ch。
}
此段为注释掉的选择运算符的定义部分*/
void
Complex::input ()						//复数类输入函数的定义部分
{
	cout << "Please input the real :";		//输出一段提示信息
	cin >> real;							//输入实数部分
	cout << "Please input the image:";
	cin >> image;							//输入虚数部分
	return ;
}

void 
Complex::display (Complex c1, Complex c2, char ope)				//复数类输出函数的定义部分
{
	if (image == 0)														//如果复数值为0的话，我不会输出复数部分，
	{																	//我认为这样会美观和直观一些。
		cout << '(' << c1.real << ',' << c1.image << "i" <<')' << ope
		 << '(' << c2.real << ',' << c2.image << "i" <<')' << '='
	 	 << real << endl;
	}	
	else																//复数部分存在的话，我会用很优雅的方式输出实数和虚数两个部分。
	{
		cout << '(' << c1.real << ',' << c1.image << "i" <<')' << ope
		 << '(' << c2.real << ',' << c2.image << "i" <<')' << '='
	 	 << '(' << real << ',' << image << "i" <<')' << endl;
	}
	return ;
}

Complex 
Complex::operator + (Complex &C_buff)	//复数加法运算的定义部分
{
	Complex c;
	c.real = real + C_buff.real;
	c.image = image + C_buff.image;				//按照数学定义对两部分进行加法运算
	return c;									//返回c值
}

Complex 
Complex::operator - (Complex &C_buff)	//复数减法运算的定义部分
{
	Complex c;
	c.real = real - C_buff.real;
	c.image = image - C_buff.image;				//按照数学定义对两部分进行减法运算
	return c;		
}

Complex 
Complex::operator * (Complex &C_buff)		//复数乘法运算的定义部分
{
	Complex c;
	c.real = real*C_buff.real - image*C_buff.image;
	c.image = real*C_buff.image + image*C_buff.real;//经过我手工推算出复数乘法的公式以后总结出如上的算法。
	return c;	
}

Complex 
Complex::operator / (Complex &C_buff)		//复数除法法运算的定义部分
{
	Complex c;
	c.real = (real*C_buff.real + image*C_buff.image) / (pow(C_buff.real,2) + pow(C_buff.image,2));
	c.image = (image*C_buff.real - real*C_buff.image) / (pow(C_buff.real,2) + pow(C_buff.image,2));
	//经过我手工推算出复数除法的公式以后总结出如上的算法。
	return c;	
}
