#include"ClassMatrix.h"
#include"ClassVector.h"
#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");
	classVector<float> a{7,100,99.9};
	classMatrix<double> b1(2, 2);
	classMatrix<double> b2(2, 2);
	classMatrix<double> b3(2, 2);
	classMatrix<float> c(3, 3);
	classVector<double> res{2,1};
	classMatrix<float> mult(3,1);
	classMatrix<double> mult1(2, 1);

	//������������ ������� 2�2 �� ������� 2�2
	//cin >> b1;
	//cin >> b2;
	// cout << "������������: " << endl;
	//b3 = b1 * b2;
	//cout << b3;

	//������������ ������� 3�3 �� ������ 3�1
	//cin >> c;
	//cin >> a;
	//cout << "������������: " << endl;
	//mult = c * a;

	//������������ ������� 2�2 �� ������ 2�1
	cin >> b1;
	cin >> res;
	cout << "������������: " << endl;
	mult1 = b1 * res;

	return 0;
}
