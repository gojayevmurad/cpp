#include <iostream>
#include <Windows.h>

using namespace std;

void AddNumbers(double* ptr1, double* ptr2) {
	cout << *ptr1 + *ptr2<< endl;
}

void ChangeData(int data) {
	data = 0;
}

void ShowArray(int* arr, int size){

	for (size_t i = 0; i < size; i++) {

		cout << arr[i] << " ";

	}cout << endl;

}

void CalculateGrossSalary(float salary, float* tax) {
	if (tax != nullptr)
		cout << salary - salary * (*tax) / 100 << endl;
	else cout << "Fill tax value" << endl;
}


template<typename T>
T* reserveArray(int size) {
	return new T[size] {};
}

template<typename T>
void InitArray(T* arr, int size) {
	int min = 1;
	int max = 100;
	T random = 0;
	srand(time(0));
	for (size_t i = 0; i < size; i++)
	{
		random = min + rand() % (max - min + 1);
		arr[i] = random;
	}
}

template<typename T>
void PrintArray(T* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}

template<typename T>
void DeleteArray(T* arr) {
	delete[] arr;
	arr = nullptr;
}

int* PushBack(int* arr, int * size, int newElement) {
	auto temp = new int[*size + 1] {};

	for (size_t i = 0; i < *size; i++)
	{
		temp[i] = arr[i];
	}
	temp[*size] = newElement;
	delete[] arr;
	arr = temp;
	temp = nullptr;
	*size += 1;
	return arr;
}

int* PushFront(int* arr, int* size, int newElement) {
	auto temp = new int[*size + 1] {};

	for (size_t i = 1; i < *size+1; i++){

		temp[i] = arr[i-1];

	}
	temp[0] = newElement;
	
	delete[] arr;
	arr = temp;
	temp = nullptr;
	*size += 1;
	return arr;
}

void main() {
	/*double value1 = 100;
	double value2 = 200;

	AddNumbers(&value1, &value2);*/

	/*double value1 = 100;
	double value2 = 200;

	double* ptr1 = &value1;
	double* ptr2 = &value2;

	AddNumbers(ptr1, ptr2);*/

	/*int data = 100;
	cout << data << endl;
	ChangeData(data);
	cout << data << endl;*/

	/*const int size = 10;
	int arr[size]{ 1,2,3,4,5,6,7,8,9,10 };

	ShowArray(arr,size);*/

	/*float tax = 0.05f;
	float* ptr = &tax;

	ptr = nullptr; // *nullptr* , null-> for reset pointer

	CalculateGrossSalary(7500, ptr);

	//int data = nullptr; // nullptr only for pointer*/

	/*int data = NULL;

	if (data == NULL) {
		cout << "No Data " << endl;
	}
	else {
		cout << data << endl;
	}

	int* ptr = nullptr;

	if (ptr == nullptr) {
		cout << "No Data" << endl;
	}
	else {
		cout << *ptr << endl;
	}*/

	/*int data = 55;
	int* ptr = &data;
	*ptr = 0;*/

// 3 type of constants
#pragma region PointerToConstValue
	/*const int data = 55;
	const int data2 = 22;

	const int* ptr = &data;
	//*ptr = 0; // error
	ptr = &data2; // okay

	cout << *ptr << endl;*/

#pragma endregion

#pragma region ConstPointerToValue
	/*int data = 55;
	int data2 = 22;
	int *const ptr = &data;

	*ptr = 0;// okay
	//ptr = nullptr; //error
	//ptr = &data2; //error*/

#pragma endregion

#pragma region ConstPointerToConstValue
	/*int data = 0;
	const int* const ptr = &data;
	//*ptr = 0;// error
	//ptr = nullptr; // error

	// nə pointer dəyişi nə value*/

#pragma endregion


	/*
		int data = 100; // In Stack 

		int* ptr = new int(100); // In Hip

		cout << ptr << endl;
		cout << *ptr << endl;

		delete ptr; // delete value from Hip
		ptr = nullptr; // delete address from pointer
	*/

	/*
		double* data = new double(1.5);
	cout << *data << endl;

	*data = 0;

	cout << *data << endl;
	
#pragma region MemoryLeak
	//data = nullptr;
	//delete data;
#pragma endregion

	delete data;
	data = nullptr;
*/


	//int arr[262222]{}; stack overflow

	//int* ptr = new int[262222] {};

	//delete ptr;
	//ptr = nullptr;

#pragma region DynamicArrayBasic


	//int size = 5;
	//int* arr = new int[size] {10, 20, 30, 40, 50};

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << arr[i] << " ";
	//}cout << endl;

// -=============================================-

	//cout << "Enter size : " << endl;
	//int size = 0;
	//cin >> size;
	//int* arr = new int[size] {};

	//for (size_t i = 0; i < size; i++)
	//{
	//	arr[i] = 0 + rand() % 100;
	//}

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << arr[i] << " ";
	//}cout << endl;

	//delete[] arr;
	//arr = nullptr;

#pragma endregion

	int size = 0;
	cin >> size;
	auto arr = reserveArray<int>(size);
	InitArray(arr, size);
	PrintArray(arr, size);
	arr = PushBack(arr, &size, 55);
	arr = PushFront(arr, &size, 55);
	PrintArray(arr, size);

}