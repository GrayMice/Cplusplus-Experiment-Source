/*
有两个矩阵a和b,均为2行3列。
求两个矩阵之和。重载运算符“+”，使之能用于矩形相加。如：c=a+b
*/
#include <iostream>
#include <iomanip>	
#define ROW 2		
#define COLUMN 3	
using namespace std;

typedef class Matrix
{
public:				
	Matrix operator + (Matrix &Buff_M);	
	void input ();				
	void display ();			
private:						
	int mat[COLUMN][ROW];		
}Matrix;

int main()
{
	Matrix m1, m2, m3;	
	m1.input ();
	m2.input ();		
	m3 = m1 + m2;		
	m3.display ();		
	return 0;			
}

void Matrix::input ()	
{
	int i, j;			
	cout << "Please input the Matrix with 2 rows and 3 columns :" << endl;
	for (i = 0; i < COLUMN; i++)
		for (j = 0; j < ROW; j++)
			cin >> mat[i][j];
	return ;				
}

void Matrix::display ()		
{
	int i, j;				
	cout << "The result is :" << endl;
	for (i = 0; i < COLUMN; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			cout << setw(3) << mat[i][j];
		}
		cout << endl;			
	}	
	return ;
}

Matrix Matrix::operator + (Matrix &Buff_M)
{
	int i, j;
	Matrix Res_M;
	for (i = 0; i < COLUMN; i++)
		for (j = 0; j < ROW; j++)
			Res_M.mat[i][j] = Buff_M.mat[i][j] + mat[i][j];
	return Res_M;
}
