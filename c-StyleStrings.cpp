#include <iostream>

using namespace std;

int MyStrLen(const char* text) {
	int count = 0;
	for (size_t i = 0; text[i]!='\0'; i++){
		count++;
	}
	return count;
}

void MyStrCopy(char*& destination, const char* source) {
	int len = MyStrLen(source);
	for (size_t i = 0; i < len; i++){
		destination[i] = source[i];
	}
	destination[len] = '\0';
}

void MyStrCat(char*& destination, const char* source) {
	if (destination == nullptr || source == nullptr) {
		cout << "Destination or Source was null" << endl;
		return;
	}

	int l1 = MyStrLen(destination);
	int l2 = MyStrLen(source);

	auto temp = new char[l1 + l2 + 1] {};

	for (size_t i = 0; i < l1; i++){
		temp[i] = destination[i];
	}

	for (size_t i = 0, i2 = l1; i < l2; i++, i2++)
	{
		temp[i2] = source[i];
	}
	if (destination != nullptr) {
		delete[] destination;
	}
	destination = temp;
	destination[l1 + l2] = '\0';
	temp = nullptr;
}

int Find(char*& source, const char& element) {
	int index = -1;

	for (size_t i = 0; source[i] != '\0'; i++) {
		if (source[i] == element) {
			index = i;
			break;
		}
	}

	return index;
}

int MyStrCmp(const char* str1, const char* str2) {
	int len1 = MyStrLen(str1);
	int len2 = MyStrLen(str2);

	int result = len1 == len2 ? 0 : len1 > len2 ? 1 : -1;

	return result;
}

int GetNumLen(int num) {
	int numLen = 0;

		while (true){

			if (num <= 0) {
				break;
			}
			else {
				num /= 10;
				numLen++;
			}

		}

	return numLen;
}

char *  MyNumToStr(int num, const int& numLen) {
	char* temp = new char[numLen+1] {};

	for (size_t i = 0; i<numLen; i++){
		int currentNum = 0;

		currentNum = num % 10;
		num /= 10;
		temp[numLen-i-1] = currentNum;
	}

	temp[numLen] = '\0';

	return temp;
}

void PrintCharArr(char* arr) {
	for (size_t i = 0; arr[i] != '\0'; i++) {
		cout << (int)arr[i] << " ";
	}cout << endl;
}

void main() {

	// C Style String

	// her setrin sonunda \0 (=> null terminator) var 
	//cout << "Hello world" << endl; // const char[12]

	/*
		char text[]{'C','A','T', '\0'};

		cout << text << endl;// CAT
		cout << text+1 << endl;// AT
	*/


	/*
		//char* text = new char[] {"Hello"}; => works
		char* text = new char[20] {"Hello"};

		cout << text << endl; // => Hello
	*/

	/*
		//char* text = "Hello"; // error
		const char* text = "Hello"; // OK
		//text[1] = 'a'; // error pointer to const value
	*/


	/*
		char* text = new char[100] {"String"};
		cout << text << endl;

		for (size_t i = 0; text[i]!='\0'; i++) {
			cout << text[i] << endl;
		}
	*/

	/*
		cout << "Enter fullname : " << endl;
		char* fullname = new char[100] {};
		cin.getline(fullname, 100);
		//cin >> fullname;
		cout << "Welcome : " << fullname << endl;

		//int l = strlen(fullname);
		int l = MyStrLen("Hello world");
		cout << l << endl;
	*/

	/*
		char* text1 = new char[100] {};
		cin.getline(text1, 100);
		char* text2 = new char[100] {};

		//int l = strlen(text1);
		//strcpy_s(text2, l + 1, text1);
		//cout << text2 << endl;

		MyStrCopy(text2, text1);
		cout << text2 << endl;
	*/

	/*
		cout << "Enter name : " << endl;
		char* name = new char[100] {};
		cin.getline(name, 100);

		cout << "Enter surname : " << endl;
		char* surname = new char[100] {};
		cin.getline(surname, 100);

		//int l1 = MyStrLen(name);
		//int l2 = MyStrLen(surname);

		//strcat_s(name, l1 +2, " ");
		//l1 = strlen(name);
		//strcat_s(name, l1 + l2 + 1, surname);

		// --------------------------------------

		//surname = nullptr;
		//MyStrCat(name, " ");
		//MyStrCat(name, surname);


		cout << "Fullname : " << name << endl;
	*/

	// index e pointer
	/*char* text = new char[20] {"Apple"};
	cout << &text[2] << endl;*/


#pragma region CustomFind
	//cout << "Enter text : " << endl;
	//char* list = new char[20] {};
	//cin.getline(list, 100);
	//int index = Find(list, 'B');

	//cout << index << endl;

#pragma endregion


#pragma region TASK1 (CUSTOM STRING COMP.)
	//cout << "Enter str 1" << endl;
	//char* text1 = new char[20] {};
	//cin.getline(text1, 20);

	//cout << "Enter str 2" << endl;
	//char* text2 = new char[20] {};
	//cin.getline(text2, 20);

	//auto result = MyStrCmp(text1, text2);
	//cout << result;
#pragma endregion

#pragma region TASK2 (NUMBER TO CHAR ARR)
	//cout << "Enter num : " << endl;
	//int num = 0;
	//cin >> num;

	//char* arr = MyNumToStr(num, GetNumLen(num));
	//PrintCharArr(arr);
#pragma endregion


}