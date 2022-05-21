#pragma once
#include "ClassVector.h"
#include<iostream>

using namespace std;

template <class Type>
class classMatrix :public classVector<Type> {
protected:
	Type** ArrM;
	int ArrSize_x = 2;
	int ArrSize_y = 2;
public:
	//Конструкторы: по умолчанию, инициализации, копирования, доступ к защ. полям, деструктор.
	classMatrix() {
		ArrM = new Type * [ArrSize_x];
		for (int i = 0; i < ArrSize_x; i++) {
			ArrM[i] = new Type[ArrSize_y];
		}
		for (int i = 0; i < ArrSize_x; i++) {
			for (int j = 0; j < ArrSize_y; j++) {
				ArrM[i][j] = 0;
			}
		}
	}
	classMatrix(int x, int y) {
		ArrSize_x = x;
		ArrSize_y = y;
		ArrM = new Type * [ArrSize_x];
		for (int i = 0; i < ArrSize_x; i++) {
			ArrM[i] = new Type[ArrSize_y];
		}
		for (int i = 0; i < ArrSize_x; i++) {
			for (int j = 0; j < ArrSize_y; j++) {
				ArrM[i][j] = 0;
			}
		}
	}
	classMatrix(const classMatrix<Type>& other) {
		ArrM = new  Type * [other.ArrSize_x];
		for (int i = 0; i < other.ArrSize_x; i++) {
			ArrM[i] = new Type[other.ArrSize_y];
		}
		for (int i = 0; i < other.ArrSize_x; i++) {
			for (int j = 0; j < other.ArrSize_y; j++) {
				ArrM[i][j] = other.ArrM[i][j];
			}
		}
	}
	~classMatrix() {
		for (int i = 0; i < ArrSize_x; i++) {
			delete[] ArrM[i];
		}
		delete[] ArrM;
	}

	//Перегрузки операторов
	auto operator[](const int index) {
		return ArrM[index];
	};
	classMatrix& operator = (classMatrix<Type> other) {
		for (int i = 0; i < ArrSize_x; i++) {
			for (int j = 0; j < ArrSize_y; j++) {
				ArrM[i][j] = other.ArrM[i][j];
			}
		}
		return *this;
	};
	classMatrix operator+(classMatrix<Type>& other) {
		if ((ArrSize_x == other.ArrSize_x) && (ArrSize_y == other.ArrSize_y)) {
			classMatrix<Type> temp(ArrSize_x, ArrSize_y);
			for (int i = 0; i < ArrSize_x; i++) {
				for (int j = 0; j < ArrSize_y; j++) {
					temp.ArrM[i][j] = ArrM[i][j] + other.ArrM[i][j];
				}
			}
			return temp;
		}
		else {
			cout << "The number of rows does not match the number of columns in the matrices. Check the matrices." << endl;
			abort();
		}
	};
	classMatrix operator-(classMatrix<Type>& other) {
		if ((ArrSize_x == other.ArrSize_x) && (ArrSize_y == other.ArrSize_y)) {
			classMatrix<Type> temp(ArrSize_x, ArrSize_y);
			for (int i = 0; i < ArrSize_x; i++) {
				for (int j = 0; j < ArrSize_y; j++) {
					temp.ArrM[i][j] = ArrM[i][j] - other.ArrM[i][j];
				}
			}
			return temp;
		}
		else {
			cout << "The number of rows does not match the number of columns in the matrices. Check the matrices." << endl;
			abort();
		}
	};
	classMatrix operator*(classMatrix<Type>& other) {
		if (ArrSize_y == other.ArrSize_x) {
			classMatrix<Type> temp(ArrSize_x, other.ArrSize_y);
			for (int i = 0; i < ArrSize_x; i++) {
				for (int j = 0; j < other.ArrSize_x; j++) {
					for (int k = 0; k < ArrSize_y; k++) {
						temp.ArrM[i][j] += ArrM[i][k] * other.ArrM[k][j];
					}
				}
			}
			return temp;
		}
		else {
			cout << "The number of rows does not match the number of columns in the matrices. Check the matrices." << endl;
			abort();
		}
	};

	classMatrix operator*(classVector<Type>& other) {
		if (ArrSize_y == other.GetSize()) {
			classMatrix<Type> temp(other.GetSize(), 1);
			for (int i = 0; i < temp.ArrSize_x; i++) {
				for (int j = 0; j < 1; j++) {
					for (int k = 0; k < other.GetSize(); k++) {
						temp.ArrM[i][j] += ArrM[i][k] * other.GetArrV(k);
					}
				}
			}
			cout << temp << endl;
			return temp;
		}
		else {
			cout << "The number of rows does not match the number of columns in the matrices. Check the matrices." << endl;
			abort();
		}
	};

	friend ostream& operator<< (ostream& os, classMatrix<Type>& Input) {
		for (int i = 0; i < Input.ArrSize_x; i++) {
			for (int j = 0; j < Input.ArrSize_y; j++) {
				os << Input.ArrM[i][j] << " ";
			}
			os << endl;
		}
		return os;
	};
	friend istream& operator>>(istream& in, classMatrix<Type>& Output) {
		for (int i = 0; i < Output.ArrSize_x; i++) {
			for (int j = 0; j < Output.ArrSize_y; j++) {
				in >> Output.ArrM[i][j];
			}
		}
		return in;
	};

};

template <class Type>
bool operator==(classMatrix<Type>& First, classMatrix<Type>& Second) {
	if ((First.ArrSize_x != Second.ArrSize_x) || (First.ArrSize_y != Second.ArrSize_y)) {
		return false;
	}
	for (int i = 0; i < First.ArrSize_x; i++) {
		for (int j = 0; j < First.ArrSize_y; j++) {
			if (First.ArrM[i][j] != Second.ArrM[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template <class Type>
bool operator!=(classMatrix<Type>& First, classMatrix<Type>& Second) {
	return not(First == Second);
}