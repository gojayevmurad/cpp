#include <iostream>

using namespace std;

void CompareNumbersWithPointer(int* ptr1, int* ptr2) {
	if (*ptr1 > *ptr2) {
		cout << "Num 1 greater than num 2" << endl;
	}
	else if (*ptr1 < *ptr2) {
		cout << "Num 2 greater than num 1" << endl;
	}
	else {
		cout << "Numbers are equal" << endl;
	}
}

void MultipyWithPointers(int* ptr1, int* ptr2, int* ptr3) {
	cout << *ptr1 * *ptr2 * *ptr3<< endl;
}

void ChangeValuesOfPointers(int* ptr1, int* ptr2) {
	int temp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = temp;
}

void main() {

#pragma region BASIC


	//int data = 100;
	//cout << (int)(&data) << endl; // & addressof
	//int data2 = 100;
	//cout << (int)(&data2)<< endl; // & addressof
	




	//int value = 55;
	//int* ptr = &value; // pointer of value
	
	//cout << &value << endl;
	//cout << ptr << endl;  // same as =>  cout << &value << endl;

	//cout << value << endl;
	//cout << *ptr << endl;// same as =>  cout << value << endl;





	//int arr[262144]{} // stack overflow





	//int value = 100;
	//int* ptr = &value;

	//cout << *ptr << endl;
	//*ptr = 0;
	//cout << *ptr << endl;
	//cout << value << endl;





	//double d = 1.5;
	//double* ptr = &d;

	//cout << sizeof(ptr) << endl; // os ==> 64bit(x64) -> 8 byte, 32 bit(x86) -> 4 byte
	//cout << *ptr << endl;




	//int num;
	//int* p = &num;
	//cout << *p << endl; // garabge data 




	//int num1 = 100;
	//int* ptr1 = &num1;

	//int num2 = 200;
	//int* ptr2 = &num2;

	//int sum = *ptr1 + *ptr2;
	//cout << sum << endl; // result 300

#pragma endregion


	// user 2 ədəd daxil edir onları pointer vasitəsi ilə müqayisə edin
	// user 3 ədəd daxil edir onların pointer vasitəsi ilə hasilini tapın
	// user 2 ədəd daxil edir onların pointer vasitəsi ilə yerlərini dəyişin
	
	//cout << "Enter num 1 : " << endl;
	//int num1 = 0;
	//cin >> num1;

	//cout << "Enter num 2 : " << endl;
	//int num2 = 0;
	//cin >> num2;

	//cout << "Enter num 3 : " << endl;
	//int num3 = 0;
	//cin >> num3;

	//cout << "Num 1 : " << num1 << endl;
	//cout << "Num 2 : " << num2 << endl;
	//cout << "Num 3 : " << num3 << endl;


	//int* ptr1 = &num1;
	//int* ptr2 = &num2;
	//int* ptr3 = &num3;
#pragma region Task 1


	//CompareNumbersWithPointer(ptr1 , ptr2);
#pragma endregion
#pragma region Task 2
	//MultipyWithPointers(ptr1, ptr2, ptr3);
#pragma endregion
#pragma region Task 3

	//ChangeValuesOfPointers(ptr1, ptr2);

	//cout << "Num 1 : " << num1 << endl;
	//cout << "Num 2 : " << num2 << endl;
	//cout << "Num 3 : " << num3 << endl;

#pragma endregion

	const int size = 10;
	int arr[size]{ 1,2,3,4,5,6,7,8,9, 10 };

	int* ptr = arr;

	++(*ptr); // =>  first index += 1

	for (size_t i = 0; i < size; i++){
		cout << *(ptr + i) << endl;
	}

}