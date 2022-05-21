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

	//Произведение матрицы 2х2 на матрицу 2х2
	//cin >> b1;
	//cin >> b2;
	// cout << "Произведение: " << endl;
	//b3 = b1 * b2;
	//cout << b3;

	//Произведение матрицы 3х3 на вектор 3х1
	//cin >> c;
	//cin >> a;
	//cout << "Произведение: " << endl;
	//mult = c * a;

	//Произведение матрицы 2х2 на вектор 2х1
	cin >> b1;
	cin >> res;
	cout << "Произведение: " << endl;
	mult1 = b1 * res;

	return 0;
}
