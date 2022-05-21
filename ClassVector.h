#pragma once
#include<iostream>

using namespace std;

template <class Type>
class classVector {
protected:
	Type* ArrV;
	int ArrSize = 3;
public:
	Type GetArrV(int index) {
		return ArrV[index];
	}
	int GetSize() {
		return ArrSize;
	}

	classVector() {
		ArrV = new Type[ArrSize];
		for (int i = 0; i < ArrSize; i++) {
			ArrV[i] = 0;
		}
	}
	classVector(int Size) {
		ArrSize = Size;
		ArrV = new Type[ArrSize];
		for (int i = 0; i < ArrSize; i++) {
			ArrV[i] = 0;
		}
	}
	classVector(const initializer_list<Type> &list) :classVector(list.size()) {
		int count = 0;
		for (auto& element : list)
		{
			ArrV[count] = element;
			++count;
		}
	}
	classVector(const classVector<Type>& other) {
		ArrSize = other.ArrSize;
		ArrV = new  Type[ArrSize];
		for (int i = 0; i < ArrSize; i++) {
			ArrV[i] = other.ArrV[i];
		}
	}
	~classVector() {
		delete[] ArrV;
	}

	//Перегрузка операторов [],=,+,-,*,/,ввода и вывода и ==.
	int& operator[](const int index) {
		return ArrV[index];
	};
	classVector operator=(classVector<Type> other) {
		if (ArrSize == other.ArrSize) {
			for (int i = 0; i < ArrSize; i++) {
				ArrV[i] = other.ArrV[i];
			}
			return *this;
		}
		else {
			cout << "The number of elements is not correct. Check the vector." << endl;
			abort();
		}
	};
	classVector operator+(classVector<Type> other) {
		if (ArrSize == other.ArrSize) {
			classVector<Type> temp(ArrSize);
			for (int i = 0; i < ArrSize; i++) {
				temp.ArrV[i] = ArrV[i] + other.ArrV[i];
			}
			return temp;
		}
		else {
			cout << "The number of elements is not correct. Check the vector." << endl;
			abort();
		}
	};
	classVector operator-(classVector<Type> other) {
		if (ArrSize == other.ArrSize) {
			classVector<Type> temp(ArrSize);
			for (int i = 0; i < ArrSize; i++) {
				temp.ArrV[i] = ArrV[i] - other.ArrV[i];
			}
			return temp;
		}
		else {
			cout << "The number of elements is not correct. Check the vector." << endl;
			abort();
		}
	};
	classVector operator*(classVector<Type> other) {
		if (ArrSize == other.ArrSize) {
			classVector<Type> temp(ArrSize);
			for (int i = 0; i < ArrSize; i++) {
				temp.ArrV[i] = ArrV[i] * other.ArrV[i];
			}
			return temp;
		}
		else {
			cout << "The number of elements is not correct. Check the vector." << endl;
			abort();
		}
	};
	classVector operator/(classVector<Type> other) {
		if (ArrSize == other.ArrSize) {
			classVector<Type> temp(ArrSize);
			for (int i = 0; i < ArrSize; i++) {
				temp.ArrV[i] = (ArrV[i]) / (other.ArrV[i]);
			}
			return temp;
		}
		else {
			cout << "The number of elements is not correct. Check the vector." << endl;
			abort();
		}
	};

	friend ostream& operator<< (ostream& os, classVector<Type>& Input) {
		for (int i = 0; i < Input.ArrSize; i++) {
			os << Input.ArrV[i] << endl;
		}
		return os;
	};

	friend istream& operator>>(istream& in, classVector<Type>& Output) {
		for (int i = 0; i < Output.ArrSize; i++) {
			in >> Output.ArrV[i];
		}
		return in;
	};
};
template <class Type>
bool operator==(classVector<Type>& First, classVector<Type>& Second) {
	if (First.ArrSize != Second.ArrSize) {
		return false;
	}
	for (int i = 0; i < First.ArrSize; i++) {
		if (First.ArrV[i] != Second.ArrV[i]) {
			return false;
		}
	}
	return true;
}
template <class Type>
bool operator!=(classVector<Type>& First, classVector<Type>& Second) {
	return not(First == Second);
}