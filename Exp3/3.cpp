/*
修改上面第（2）题的程序，改为用公用继承方式。
上机调试程序，使之能正确运行并得到正确的结果。
*/
#include <iostream>
#include <string>
using namespace std;
class Student 	//定义Student类
{
protected:	//声明保护成员
	int num;
	string name;
	char sex;
};

class Student1 : 
	public Student //定义Student1类，公用继承于Student类
{
public:
	void get_value_1 () {cin >> num >> name >> sex 
				>> age >> addr;}	//定义数据输入函数，为继承于Student类内的数据赋值
	void display_1 ()				//定义输出函数
	{
	     cout << "num:" << num << endl 
		<< "name:" << name << endl 
		<< "sex:" << sex << endl
		<< "age:" << age << endl
		<< "address:" << addr << endl;
	}
private:	//增加两个数据成员
	int age;
	string addr;
};
int main ()
{
	Student1 st1;	//声明一个Student1类变量st1
	cout << "Please input number and name and sex and age and address:" << endl;
	st1.get_value_1 ();
	st1.display_1();	//调用并测试
	return 0;
}