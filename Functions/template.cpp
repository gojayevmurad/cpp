#include <iostream>

using namespace std;

template<typename T>
void ShowData(T data) {
	cout << "Data is : " << data << endl;
}

void ShowData(char data) {
	cout << "[char] Data is : " << data << endl;
}

//
//void Add(int num1, int num2) {
//	cout << "Result : " << num1 + num2 << endl;
//}
//
//void Add(double num1, double num2) {
//	cout << "Result : " << num1 + num2 << endl;
//}
//
//void Add(float num1, float num2) {
//	cout << "Result : " << num1 + num2 << endl;
//}

template<typename T , typename T2>
void Add(T num1, T2 num2) {
	cout << "Result : " << num1 << " " <<  num2 << endl;
}

template<typename T1, typename T2>
T1 getSum(T1 num1, T2 num2) {
	return num1 + num2;
}

template<typename T>
T getSum2(double num1, int num2) {
	return num1 + num2;
}

void main() {
	auto result = getSum(20, 10.5);

	//auto result = getSum2(10, 10.5); //error
	auto result2 = getSum2<int>(10, 10.5);

}