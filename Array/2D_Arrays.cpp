#include <iostream>
#include <time.h>
#include<iomanip>

using namespace std;

void main() {

	// static 2D array

#pragma region first

		//int arr[3][3] = {
	//	{1,2,3},
	//	{4,5,6},
	//	{7,8,9}
	//};

	//for (size_t i = 0; i < 3; i++)
	//{
	//	for (size_t k = 0; k < 3; k++) {
	//		cout << arr[i][k] << " ";
	//	}cout << endl;
	//}

#pragma endregion


#pragma region second


	//const int size = 5;

	//int arr[size][size]{};

	//int min = 1, max = 10000;

	//srand(time(0));

	//for (size_t i = 0; i < size; i++){

	//	for (size_t k = 0; k < size; k++){
	//		int random = min + rand() % (max - min + 1);
	//		arr[i][k] = random;
	//	}

	//}

	//for (size_t i = 0; i < size; i++)
	//{
	//	for (size_t k = 0; k < size; k++)
	//	{
	//		cout << setw(5) << arr[i][k] << " ";
	//	}cout << endl;
	//}
#pragma endregion

#pragma region third

	//const int size = 25;

	//int arr[size][size]{};

	//int min = 1, max = 10000;

	//srand(time(0));

	//for (size_t i = 0; i < size; i++){

	//	for (size_t k = 0; k < size; k++){
	//		int random = min + rand() % (max - min + 1);
	//		arr[i][k] = (i+1)*(k+1);
	//	}

	//}

	//int sum = 0;
	//for (size_t i = 0; i < size; i++){
	//	for (size_t k = 0; k < size; k++){

	//		sum += arr[i][k];

	//	}

	//}


	//for (size_t i = 0; i < size; i++)
	//{
	//	for (size_t k = 0; k < size; k++)
	//	{
	//		cout << setw(5) << arr[i][k] << " ";
	//	}cout << endl;
	//}

	//cout << "Sum : " << sum << endl;

#pragma endregion


	// TASK 1 cüt sütundakı elementləri toplayın

	// TASK 2 cüt sətrdəki elementləri toplayın

	// TASK 3 plus formasında elementləri toplayın

	// TASK 4 
	/*
		1 1 1 1 1
		1 0 0 0 1
		1 0 0 0 1
		1 0 0 0 1
		1 1 1 1 1
	*/

	// TASK 5 
	/*
		1 0 0 0 0
		1 2 0 0 0
		1 2 3 0 0
		1 2 3 4 0
		1 2 3 4 5
	*/

#pragma region for 1-2-3


	//const int size = 5;
	//int min = 1;
	//int max = 100;

	//int arr[size][size]{};

	//srand(time(0));

	//for (size_t i = 0; i < size; i++) {

	//	for (size_t k = 0; k < size; k++) {
	//		int random = min + rand() % (max - min + 1);

	//		arr[i][k] = random;
	//	}

	//}

	//for (size_t i = 0; i < size; i++) {

	//	for (size_t k = 0; k < size; k++) {

	//		cout << setw(5) << arr[i][k] << " ";

	//	}cout << endl;
	//}

#pragma endregion


#pragma region Task 1


	//int sum = 0;

	//for (size_t i = 0; i < size; i++){

	//	for (size_t k = 0; k < size; k++){

	//		if ((i + 1) % 2 == 0) {
	//			sum += arr[i][k];
	//		}

	//	}

	//}

	//cout << "Sum : " << sum << endl;


#pragma endregion

#pragma region Task 2

	//int sum = 0;

	//for (size_t i = 0; i < size; i++) {

	//	for (size_t k = 0; k < size; k++) {

	//		if ((k + 1) % 2 == 0) {
	//			sum += arr[i][k];
	//		}

	//	}

	//}

	//cout << "Sum : " << sum << endl;

#pragma endregion

#pragma region Task 3

	//int sum = 0;

	//for (size_t i = 0; i < size; i++) {

	//	for (size_t k = 0; k < size; k++) {

	//		if (i == ((size - 1) / 2) || k == ((size - 1) / 2)) {
	//			sum += arr[i][k];
	//		}

	//	}

	//}

	//cout << setw(5) << "Sum : " << sum << endl;


#pragma endregion

#pragma region Task 4

	//const int size = 5;

	//int arr[size][size]{};

	//for (size_t i = 0; i < size; i++){

	//	for (size_t k = 0; k < size; k++){

	//		if (i == size- 1 || k == size-1 || i == 0 || k == 0) {
	//			arr[i][k] = 1;
	//		}
	//		else {
	//			arr[i][k] = 0;
	//		}

	//	}

	//}

	//for (size_t i = 0; i < size; i++){
	//	for (size_t k = 0; k < size; k++) {

	//		cout << arr[i][k] << " ";

	//	}cout << endl;
	//}



#pragma endregion

#pragma region Task 5

	//const int size = 5;

	//int arr[size][size]{};

	//for (size_t i = 0; i < size; i++){

	//	for (size_t k = 0; k < size; k++){

	//		if (k <= i) {
	//			arr[i][k] = k+1;
	//		}
	//		else {
	//			arr[i][k] = 0;
	//		}

	//	}

	//}

	//for (size_t i = 0; i < size; i++){
	//	for (size_t k = 0; k < size; k++) {

	//		cout << arr[i][k] << " ";

	//	}cout << endl;
	//}

#pragma endregion


}