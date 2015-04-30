/*
事先编写好程序，上机调试和运行程序，分析结果。
形成三角形的条件是：a+b>c,b+c>a,c+a>b
编写程序，输入a,b,c，检查a,b,c是否满足以上的条件，如不满足，由cerr输出有关出错信息。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int exFlag = 0;	//设立退出flag来检验是否异常退出，初值为0
	double triangle (double, double, double);
	double a, b, c;
	cout << "Please input a,b,c:" << endl;
	cin >> a >> b >> c;	//入口
	try	//try部分，正常调用
	{
		while (a > 0 && b > 0 && c > 0)	//循环输入内容部分，仅在均正确情况下。
		{
			
			cout << "The answer is: " << triangle(a,b,c) << endl;
			cout << "Please input a,b,c:" << endl;
			cin >> a >> b >> c;
		}
	}
	catch (double)	//异常catch
	{
		cerr << "This is not a triangle!" << endl;	//输出错误信息.
		exFlag = 1;	//异常出现，改变值
	}
	cout << "Done" << endl;

	if (exFlag)
		return EXIT_FAILURE;//异常退出
	else
		return EXIT_SUCCESS;//正常退出

}

double triangle (double a, double b, double c)
{
	double s = (a + b + c) / 2;
	if (!(a+b>c && b+c>a &&a+c>b))
		throw a;	//当不满足条件的时候抛出异常
	return sqrt(s*(s-a)*(s-b)*(s-c));	//正常，返回面积
}
