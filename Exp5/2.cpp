/*
从键盘输入一批数值，要求保留3位小数，在输出时上下行小数点对齐。
①用控制符控制输出格式；
②用流成员函数控制输出格式。
*/
#include <iostream> 
#include <iomanip> 
#define MAXN 1000
using namespace std;

int main() 
{ 
	double arr[MAXN];
	int n;
	cout << "Please input the number of figures that you want to input :" << endl;	//输出提示信息
	cin >> n;	//输入要输入的double型数字
	for (int i = 0; i != n; i++)
		cin >> arr[i];
	
	cout << setiosflags(ios::fixed);//将一个浮点数表示为一个定点整数和小数点和小数部分的格式
	cout << "Now I formated them : " << endl;
	for (int i = 0; i != n; i++)
		cout << setw(10) << setprecision(3) << arr[i] << endl;	//域宽为10，保留3位小数
	return EXIT_SUCCESS;
}
