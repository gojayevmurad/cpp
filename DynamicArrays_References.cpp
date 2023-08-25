#include <iostream>

using namespace std;


//by reference
void Change(int& data) {
	data = 0;
}

void ChangeByValue(int value) {
	value = 111;
}

void ChangeByPointer(int* ptr) {
	*ptr = 111;
}

void ChangeByReference(int& value) { // add const when need original data
	value = 111;
}

void ChangeArr(int*& arr) {
	arr[0] = 100;
	arr = nullptr;
}

void InitArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i + 10;
	}
}

void PrintAray(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}

void PushBack(int*& arr, int& size, const int& newElement) {
	auto temp = new int[size + 1] {};
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = newElement;
	delete[] arr;
	arr = temp;
	temp = nullptr;
	++size;
}

int GetMin(int* arr, int& size) {

	int min = arr[0];

	for (size_t i = 0; i < size; i++){

		if (arr[i] < min) {
			min = arr[i];
		}

	}

	return min;
}

void ZipArray(int*& arr, int& size) {

	int sizeNewArr = 0;

	int* zippedArr = new int[sizeNewArr] {};

	// 1 1 1 2 2 2 4 4 4 6 6

	int count = 0;
	int num = arr[0];
	for (size_t i = 0; i < size; i++){
		
		if (arr[i] == num) {
			count += 1;
		}
		else {

			PushBack(zippedArr, sizeNewArr, num);
			PushBack(zippedArr, sizeNewArr, count);

			num = arr[i];
			count = 0;
		}

	}

	delete[] arr;
	arr = zippedArr;
	size = sizeNewArr;
}

int* GetResult(int* arr, int size) {
	int count = 0;
	int maxElement = 0;
	int maxCount = 0;
	for (size_t i = 0; i < size; i++){
		count = 0;
		for (size_t k = 0; k < size; k++){

			if (arr[i] == arr[k]) {
				++count;
			}

		}
		if (count > maxCount) {
			maxCount = count;
			maxElement = arr[i];
		}
	}
	return new int[2] {maxElement, maxCount};
}


void main() {

	//int value = 55;
	//int& ref = value;
	//ref = 0; // => value = 0
	//cout << value << endl;
	//cout << ref << endl;

	// ========================================

	//int value = 55;
	//int value2 = 55;
	//int& ref = value;
	////&ref = value2; //error => like constant pointer to value
	
	// ========================================

	/*int value = 111;
	int& ref = value;
	Change(ref);
	cout << value;*/

	// ========================================

	//1. By Value
	//2. By Pointer
	//3. By Reference
#pragma region ByValue
	//int value = 10;
	//cout << value << endl;
	//ChangeByValue(value);
	//cout << value << endl; // 10 -> 10
#pragma endregion

#pragma region ByPointer
	//int value = 10; 
	//cout << value << endl;
	//ChangeByPointer(&value);
	//cout << value << endl; // 10 -> 111
#pragma endregion

#pragma region ByReference
	//int value = 10;
	//cout << value << endl;
	//ChangeByReference(value);
	//cout << value << endl
#pragma endregion


	//int* arr = new int[5] {1, 2, 3, 4, 5};
	//cout << arr[0] << endl;
	//ChangeArr(arr);
	//cout << arr[0] << endl; // error

	// ============================================

	//int size = 5; 
	//int* arr = new int[size] {};
	//InitArray(arr, size);
	//PrintAray(arr, size);
	//PushBack(arr, size, 55);
	//PrintAray(arr, size);

	//FOR JUNIOR
	// Task 1
	//Dinamik massivdə ən kiçik elementi tapın

	//FOR EXPERT
	//Task 2
	//Dinamik massivdə ən çox təkrarlanan elementi və sayını qaytarın(zip)

	int size = 12;
	int* arr = new int[size] {5, 1, 2, 2, 3, 2, 2, 3, 3, 3, 3, 1};

#pragma region Task1 

	int num = GetMin(arr, size);
	PrintAray(arr, size);
	cout << "Min : " << num << endl;
#pragma endregion

#pragma region Task2
	auto result = GetResult(arr, size);
	cout << result[0] << endl;
	cout << result[1] << endl;
#pragma endregion


}