#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#define MAXN 20
using namespace std;
/*
1.从键盘输入20个整数，分别存放在两个磁盘文件中（每个文件中放10个整数）
*/
void test1 ();

/*
2.从f1.dat读入10个整数，然后存放到f2.dat文件原有数据的后面；
*/
void test2 ();

/*
3.从f2.dat中读入20个整数，
将它们按从小到大的顺序存放到f2.dat(不保留原来的数据)
*/
void test3 ();

int main ()
{
	/*调用测试函数*/
	test1 ();
	test2 ();
	test3 ();
	return EXIT_SUCCESS;
}

void test1 ()
{
	int buffer;//新建缓存变量，用来存储输入数据
	ofstream file1 ("data\\f1.dat", ios::out);
	ofstream file2 ("data\\f2.dat", ios::out);//打开两个文件，均是写入模式
	if (!file1 || !file2)	//检查是否能正常打开
	{
		cerr << "Open files error!" << endl;
		exit (EXIT_FAILURE);
	}
	cout << "Please input " << MAXN << " numbers: " << endl;	//输出提示信息
	for (int i = 0; i != MAXN; i++)
	{
		cin >> buffer;
		if (i < MAXN/2)	
			file1 << buffer << " ";
		else	
			file2 << buffer << " ";
	}
	file1.close ();
	file2.close ();//关闭文件
	return ;
}

void test2 ()
{
	int buffer;//新建缓存变量，用来存储输入数据
	ifstream file1 ("data\\f1.dat", ios::in );//读取模式打开f1.dat
	ofstream file2 ("data\\f2.dat", ios::app);//写入模式打开f2.dat，并且保留原有数据
	if (!file1 || !file2)//检查是否能正常打开
	{
		cerr << "Open files error!" << endl;
		exit (EXIT_FAILURE);
	}
	cout << "Now move the data from f1.dat to f2.dat: " << endl;
	for (int i = 0; i != MAXN/2; i++)//转移数据
	{
		file1 >> buffer;
		file2 << buffer << " ";
		cout << buffer << " ";
	}
	cout << endl;
	file1.close ();//关闭文件
	file2.close ();
	return ;
}

void test3 ()
{
	int buffer[MAXN];
	ifstream infile ("data\\f2.dat", ios::in );//打开文件，读取f2.dat
	if (!infile)//检查
	{
		cerr << "Open files error!" << endl;
		exit (EXIT_FAILURE);
	}
	for (int i = 0; i != MAXN; i++)	//放入缓存数组内
		infile >> buffer[i];
	infile.close ();//关闭文件

	sort (buffer, buffer+MAXN);//调用STL的快速排序

	ofstream oufile ("data\\f2.dat", ios::out);	//打开文件，卸入f2.dat，不保留原有数据
	if (!oufile)//检查
	{
		cerr << "Open files error!" << endl;
		exit (EXIT_FAILURE);
	}
	cout << "Now sort the data of f2.dat :" << endl;//输出提示信息
	for (int i = 0; i != MAXN; i++)//写入f2.dat并且将数据输出到屏幕上
	{
		oufile << buffer[i] << " ";
		cout << buffer[i] << " ";
	}
	cout << endl;
	oufile.close ();//关闭文件

	return ;
}
