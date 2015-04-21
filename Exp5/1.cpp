/*
事先编写好程序，上机调试和运行程序，分析结果。
形成三角形的条件是：a+b>c,b+c>a,c+a>b
编写程序，输入a,b,c，检查a,b,c是否满足以上的条件，如不满足，由cerr输出有关出错信息。
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, s, area;	//定义所需变量
	cout << "Please input a, b and c:" << endl;
	cin >> a >> b >> c;
	if (!(a + b > c && b + c > a && c + a > b))//判断是否输入正确
	{
		cerr << "Error! Two sides is greater than the third side !" << endl;//输出错误提示
		exit (EXIT_FAILURE);
	}
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));//计算面积
	cout << "The area is : " << area << endl;	//输出计算结果
	return EXIT_SUCCESS;
}
