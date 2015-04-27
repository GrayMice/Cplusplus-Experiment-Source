/*main.cpp*/
#include <iostream>
#include "cylinder.h"
using namespace std;

int main ()
{
	Cylinder cylind(4.3,2.2,3.1,5.5);	//初始化 
	cout << "Original : " << cylind;	//重定向<<输出cylind 
	cylind.setHeight(3);
	cylind.setRadius(5);
	cylind.setPoint(1,1);				//调用函数，修改对应数据 
	cout << "\nI have changed its elements.\n\nNow : " << cylind;	//输出测试数据 
	Point& pr = cylind;	//设置一个Point类型引用pr来引用cylind 
	cout << "\nTesting1: The pointer is: " << pr;	//作为一个点，输出pr对应属性 
	Circle& cr = cylind;//设置一个Circle类型引用cr来引用cylind 
	cout << "Testing2: The circle is: " << cr;		//作为一个圆，输出cr对应属性 
	return 0;
}
