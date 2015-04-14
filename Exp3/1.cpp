/*
将《C++面向对象程序设计》第5章例5.1的程序片段补充和改写成一个完整、正确的程序，用公用继承方式。
在程序中应包括输入数据的函数，在程序运行时输入num,name,sex,age,addr的值，程序应输出以上5个数据的值。
*/
#include <iostream>
#include <string>
using namespace std;
class Student 	//定义Student类
{
public:
	void get_value() {cin >> num >> name >> sex;}	//输入函数定义
	void display() 						//输出Student类内的数据
	{	
	     cout << "num:" << num << endl 
		<< "name:" << name << endl 
		<< "sex:" << sex << endl;
	}
private:		//声明私有属性的类成员
	int num;
	string name;
	char sex;
};

class Student1 : 
	public Student //定义Student1类，公用继承Student类
{
public:
	void get_value_1 () {cin >> age >> addr;}	//定义子类内的成员的输入函数
	void display_1 ()				//定义子类内的成员的输出函数
	{
	     cout	<< "age:" << age << endl
		<< "address:" << addr << endl;
	}
private:	//声明私有属性的类成员
	int age;
	string addr;
};
int main ()
{
	Student1 st1;	//声明一个Student1类
	cout << "Please input number and name and sex and age and address:" << endl;
	st1.get_value ();
	st1.get_value_1 ();
	st1.display ();
	st1.display_1();	//分别调用四个函数
	return 0;
}
