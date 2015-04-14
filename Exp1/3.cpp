/*
（3）
需要求3个长方体的体积，请编一个基于对象的程序。数据成员包括length（长）、width（宽）、height（高）。
要求用成员函数实现以下功能：
①由键盘分别输入3个长方体的长、宽、高；
②计算3个长方体的体积；
③输出3个长方体的体积。
请编程序，上机调试并运行。
*/

#include <iostream>		
using namespace std;	
class v					
{
public:					
	void input ();		
	void output ();		
private:				
	double length;		
	double height;
	double width;		
};
int main()
{
	v v0[3];				
	int i;					
	for (i = 0; i < 3; i++)	
		v0[i].input();
	for (i = 0; i < 3; i++)	
	{
		cout << "Num" << i << ":";
		v0[i].output();
	}
	system("pause");		
	return 0;				
}

void v::input ()			
{
	cin >> length >> height >> width;			
}
void v::output ()								
{
	cout << "V = " << length*height*width<< endl;
}