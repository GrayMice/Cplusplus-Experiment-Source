/*
将《C++面向对象程序设计》第5章例5.3的程序修改、补充，写成一个完整、正确的程序，
用保护继承方式。在程序中应包括输入数据的函数。
*/
#include <iostream>
#include <string>
using namespace std;
class Student//定义Student类
{
protected:	//声明保护成员
	int num;
	string name;
	char sex;
};

class Student1 : 
	protected Student 	//定义Student1类，保护继承于Student
{
public:
	void get_value_1 () {cin >> num >> name >> sex 
				>> age >> addr;}	//定义函数，为继承于Student类中的数据赋值
	void display_1 ()	//输出数据的值
	{
	     cout << "num:" << num << endl 
		<< "name:" << name << endl 
		<< "sex:" << sex << endl
		<< "age:" << age << endl
		<< "address:" << addr << endl;
	}
private:	//补充两个变量
	int age;
	string addr;
};
int main ()
{
	Student1 st1;	//声明一个Student1类变量st1
	cout << "Please input number and name and sex and age and address:" << endl;
	st1.get_value_1 ();	//测试两个函数
	st1.display_1();
	return 0;
}
