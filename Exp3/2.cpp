/*
����C++������������ơ���5����5.3�ĳ����޸ġ����䣬д��һ����������ȷ�ĳ���
�ñ����̳з�ʽ���ڳ�����Ӧ�����������ݵĺ�����
*/
#include <iostream>
#include <string>
using namespace std;
class Student//����Student��
{
protected:	//����������Ա
	int num;
	string name;
	char sex;
};

class Student1 : 
	protected Student 	//����Student1�࣬�����̳���Student
{
public:
	void get_value_1 () {cin >> num >> name >> sex 
				>> age >> addr;}	//���庯����Ϊ�̳���Student���е����ݸ�ֵ
	void display_1 ()	//������ݵ�ֵ
	{
	     cout << "num:" << num << endl 
		<< "name:" << name << endl 
		<< "sex:" << sex << endl
		<< "age:" << age << endl
		<< "address:" << addr << endl;
	}
private:	//������������
	int age;
	string addr;
};
int main ()
{
	Student1 st1;	//����һ��Student1�����st1
	cout << "Please input number and name and sex and age and address:" << endl;
	st1.get_value_1 ();	//������������
	st1.display_1();
	return 0;
}
