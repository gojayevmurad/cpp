#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;


void ShowWeatherInfo() {
	cout << "Today is windy" << endl;
	cout << "Weather degree is 12 celcius " << endl;
}

void ShowMyTax(double salary) {
	double tax = salary * 0.05 + 86 + 12;

	cout << "For this salary " << salary << endl;
	cout << "You should pay : " << tax << " azn" <<endl;
}

void AddNumbers(int num1, int num2) {
	int sum = num1 + num2;
	cout << "Sum : " << sum << endl;
}

void DivNumbers(int num1, int num2) {
	if (num1 < 0) {
		cout << "You can't divide 0";
	}
	else {
		int div = num1 / num2;
		cout << "Answer : " << div;
	}
}

void setColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

bool isPositive(int number) {
	if (number > 0) return true;
	return false;
}

int GetSum(int start, int end) {
	int sum = 0;;
	for (size_t i = start; i < end; i++){

		sum += i;

	}

	return sum;
}

void InitArray(int arr[], int size) {

	srand(time(0));

	int random = 0;
	int min = 1;
	int max = 100;
	for (size_t i = 0; i < size; i++){

		random = min + rand() % (max - min + 1);
		arr[i] = random;

	}
}

void PrintArray(int arr[], int size) {
	for (size_t i = 0; i < size; i++) {

		cout << arr[i] << " ";

	}cout << endl;
}

void UpdateNumbersByPercent(int arr[], int size, int percent) {
	for (size_t i = 0; i < size; i++){

		arr[i] += (arr[i] * percent) / 100.0f;

	}
}


void main() {
}