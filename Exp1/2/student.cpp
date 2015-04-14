//student.cpp
#include <iostream>		
#include "student.h"		
void Student::display()	
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;	
}

void Student::set_value()		
{
	cout << "Please input number and name and sex :)" << endl;
	cin >> num >> name >> sex;
}