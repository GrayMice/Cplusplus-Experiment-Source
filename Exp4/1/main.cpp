/*main.cpp*/
#include <iostream>
#include "cylinder.h"
using namespace std;

int main ()
{
	Cylinder cylind(4.3,2.2,3.1,5.5);	//��ʼ�� 
	cout << "Original : " << cylind;	//�ض���<<���cylind 
	cylind.setHeight(3);
	cylind.setRadius(5);
	cylind.setPoint(1,1);				//���ú������޸Ķ�Ӧ���� 
	cout << "\nI have changed its elements.\n\nNow : " << cylind;	//����������� 
	Point& pr = cylind;	//����һ��Point��������pr������cylind 
	cout << "\nTesting1: The pointer is: " << pr;	//��Ϊһ���㣬���pr��Ӧ���� 
	Circle& cr = cylind;//����һ��Circle��������cr������cylind 
	cout << "Testing2: The circle is: " << cr;		//��Ϊһ��Բ�����cr��Ӧ���� 
	return 0;
}
