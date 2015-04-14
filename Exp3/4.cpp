/*
分别声明Teacher(教师)类和Cadre(干部)类，采用多重继承方式由这两个类派生出新类Teacher_Cadre(教师兼干部)。要求：
a.在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员
b.在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含数据成员post(职务)。在Teahcer_Cadre类中还包含数据成员wages(工资)。
c.对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，在引用这些数据成员时，指定作用域。	
d.在类体中声明成员函数，在类外定义成员函数。
e.在派生类Teahcer_Cadre的成员函数show中调用Teacher类的display函数，输出姓名、年龄、性别、职称、地址、电话，然后再用cout语句输出职务与工资。
*/
#include <iostream>
using namespace std;
class Teacher
{
public:
	Teacher (string nam, int ag, char se, string add, string tel, string tit);	//定义构造函数
	void display ();//定义输出函数
protected:
	string name;
	int age;
	char sex;
	string address;
	string tele;
	string title;	//职称
};

class Cadre
{
public:
	Cadre (string nam, int ag, char se, string add, string tel, string pos);	//定义构造函数
protected:
	string name;
	int age;
	char sex;
	string address;
	string tele;
	string post;	//职务
};

class Teacher_Cadre :
	public Teacher, public Cadre 	//定义类，多重继承于Teacher类和Cadre类，并且全是公用继承
{
public:
	Teacher_Cadre(string nam, int ag, char se, string add, string tel, string tit, string pos, double wag): 
	//定义构造函数，将上两个类内的数据继承下来。并且新增变量wage的初始化。
		Teacher (nam, ag, se, add, tel, tit), Cadre (nam, ag, se, add, tel, pos)
	{wage = wag;}
	void show ();	//输出内容的函数
protected:
	double wage;	//工资
};

Teacher::Teacher (string nam, int ag, char se, string add, string tel, string tit)
{
	name = nam;
	age = ag;
	sex = se;
	address = add;
	tele = tel;
	title = tit;
}

Cadre::Cadre (string nam, int ag, char se, string add, string tel, string pos)
{
	name = nam;
	age = ag;
	sex = se;
	address = add;
	tele = tel;
	post = pos;
}

void Teacher::display ()
{
	cout << 
		"Name: " << name << endl <<
		"Age: " << age << endl <<
		"Sex: " << sex << endl <<
		"Address: " << address << endl <<
		"Telephone: " << tele << endl;
	return ;
}

void Teacher_Cadre::show ()
{
	Teacher::display ();	//调用Teacher类中的输出函数
	cout << 
		"Post: " << Cadre::post << endl <<	//指定post的作用域
		"Wage: " << wage << endl;
	return ;
}

//测试部分
int main ()
{
	Teacher_Cadre tc("Zhangsan", 40, 'M', "shandong", "13333333333", "Professor", "Banzhuande", 2000);
	tc.show ();
	return 0;
}

