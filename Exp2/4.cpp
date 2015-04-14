/*
声明一个Teacher(教师)类和一个Student(学生)类，二者有一部分数据成员是相同的，例如num(号码)，name(姓名),sex(性别)。
编写程序，将一个Student对象（学生）转换为Teacher(教师)类，只将以上3个相同的数据成员移植过去。
可以设想为：一位学生大学毕业了，留校担任教师，他原有的部分数据对现在的教师身份来说仍然是有用的，应当保留并成为其教师的数据的一部分。
*/
#include <iostream>
#include <string>
using namespace std;
//头文件以及命名空间的声明。
typedef class Student 	
{
public:					
	void Input ();		
	friend class Teacher;
private:				
	int num;
	string name;
	char sex;			
}Student;

typedef class Teacher 	
{
public:					
	void Display ();	
	void Convert (Student );
private:				
	int num;
	string name;
	char sex;			
}Teacher;

int main()
{
	Student stu;		
	Teacher tea;		
	stu.Input ();		
	tea.Convert (stu);	
	tea.Display ();		
	return 0;			
}

void Student::Input ()	
{
	cout << "Please input the young student's num and name and sex :)" << endl;	
	
	cin >> num >> name >> sex;	
	return ;
}

void Teacher::Display () //定义教师类里的输出函数
{
	if (sex == 'M' || sex == 'm')	//判断老师的性别为男
	{
		cout << "Now, He is a honorable people's teacher." << endl;
		cout << "His num is " << num << '.' << endl;
		cout << "His name is " << name << '.' << endl;
		cout << "His sex is " << sex << '.' << endl;	//输出三个参数
	}
	if (sex == 'F' || sex == 'f')	//判断老师的性别为女
	{
		cout << "Now, She is a honorable people's teacher." << endl;
		cout << "Her num is " << num << '.' << endl;
		cout << "Her name is " << name << '.' << endl;
		cout << "Her sex is " << sex << '.' << endl;	//输出三个参数
	}
	return ;
}
void Teacher::Convert (Student stu)	
{
	num = stu.num;					
	name = stu.name;
	sex = stu.sex;
	return ;
}