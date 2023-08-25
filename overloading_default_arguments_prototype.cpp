#include <iostream>
#include <time.h>

using namespace std;

#pragma region Prototype

void Update();
void GoBack(int a);

void Start() {
	Update();
	GoBack(12);
}

// implementation
void Update() {

}

void GoBack(int a) {

}

#pragma endregion

#pragma region default arguments


void AddNumbers(int num1, int num2, int num3=0) { // default num3 = 0
	int result = num1 + num2 + num3;
	cout << result << endl;
}

/// <summary>
/// This function draw square according to params 
/// </summary>
/// <param name="count">
/// Count is for symbols, for default it is 10 counts
/// </param>
/// <param name="symbol">
/// It is showing symbol and default is star *
/// </param>
void DrawSquare(int count =10, char symbol='*') {
	for (size_t i = 0; i < count; i++){
		for (size_t k = 0; k < count; k++)
		{
			cout << symbol << " ";
		}cout << endl;
	}
}

#pragma endregion

#pragma region overload


void AddNumbers2(int num1, int num2) {
	cout << num1 + num2 << endl;
}

void AddNumbers2(double num1, double num2) {
	cout << num1 + num2 << endl;
}

void InitArray(int arr[], int size) {
	srand(time(0));
	int min = 1;
	int max = 100;
	int random = 0;
	for (size_t i = 0; i < size; i++)
	{
		random = min + rand() % (max - min + 1);
		arr[i] = random;
	}
}

void InitArray(float arr[], int size) {
	srand(time(0));
	int min = 1;
	int max = 100;
	float random = 0;
	for (size_t i = 0; i < size; i++)
	{
		random = min + rand() % (max - min + 1);
		arr[i] = random / 10.0f;
	}
}

void PrintArray(int arr[], int size) {
	for (size_t i = 0; i < size; i++) {

		cout << arr[i] << " ";

	}cout << endl;
}

void PrintArray(float arr[], int size) {
	for (size_t i = 0; i < size; i++) {

		cout << arr[i] << " ";

	}cout << endl;
}

#pragma endregion



void main() {

	const int size = 10;

	float arr[size]{};

	InitArray(arr, size);
	PrintArray(arr, size);
}