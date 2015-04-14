/*
改写程序,要求：
①将数据成员改为私有的；
②将输入和输出的功能改为由成员函数实现；
③在类体内定义成员函数。
然后编译和运行程序。
*/
#include <iostream>		
using namespace std;	
class Time				
{ 
public:					
	void display ();	
	void input ();		
private:				
	int hour;			
	int minute;
	int sec;			
};

int main()
{	
	Time t1;			
	t1.input();			
	t1.display();		
	system ("pause");	
	return 0;			
}
void Time::display ()							
{
	cout<<hour<<":"<<minute<<":"<<sec<<endl;	
}

void Time::input ()								
{
	cin>>hour>>minute>>sec;						
}
/*
解答：
	应该将类中存储的数据指定为私有的，而将对类内数据的操作指定为公用的。对于调用数据成员的或者是仅在某一类内完成工作的函数应当在类内定义，而对于具有多个类有相同功能的操作或者是不触及指定为private/protected的数据进行操作的可以在类外定义。
*/