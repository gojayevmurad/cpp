#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

int** ReserveArray(const int& size) {
    return new int* [size] {};
}


void InitializeArray(int**& arr, const int& size, const int& min = 1, const int& max = 50) {
    int random = 0; srand(time(0));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (size_t k = 0; k < size; k++)
        {
            random = min + rand() % (max - min + 1);
            arr[i][k] = random;
        }
    }
}

void PrintArray(int** arr, const int size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t k = 0; k < size; k++)
        {
            cout << setw(4) << arr[i][k];
        }cout << endl << endl;
    }cout << endl << endl;
}



void main() {
	int* arr1 = new int [3] {1, 2, 3};
	int* arr2 = new int [3] {3, 4, 5};
	int* arr3 = new int [3] {6, 7, 8};

	int** ptr = new int* [3] {arr1, arr2, arr3};

	for (size_t i = 0; i < 3; i++){

		for (size_t k = 0; k < 3; k++) {

			cout << *(ptr[i] + k) << " ";

		}cout << endl;

	}

    system("color f0");
    auto arr4 = ReserveArray(5);
    InitializeArray(arr4, 5);
    PrintArray(arr4, 5);


    int* ar = new int[3] {1, 2, 3};
    cout << ar << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << ar[i] << endl;
        cout << *(ar + i) << endl;
    }

    bool flag1 = 1;

    cout << "BOOlALPHA" << boolalpha  << " " << flag1 << endl;
    bool flag2 = 0;
    cout << "BOOlALPHA" << boolalpha  << " " << flag2 << endl;

    cout << endl << endl; cin.get();
}