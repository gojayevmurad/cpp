#include <iostream>
#include "Database.h"

using namespace std;
#pragma region Defines


#define PI 3.141516

#define Name "David"

#define Əsas main
#define v void
#define döngü for

#define Başla {
#define Son }
#define Əgər if
#define DigərHal else
#define TAM int
#define ÇapEt cout<<

#define Windows
#pragma endregion

#pragma region Define logics



v showNewKeys() {
	döngü(size_t i = 0; i < 2; i++) {
		cout << i << endl;
	}

	TAM a = 100;

	Əgər(a == 100)Başla
		ÇapEt "Ədəd 100-dür" << endl;
	Son
		DigərHal Başla
		ÇapEt "Ədəd 100 deyil" << endl;
	Son
}

#ifdef Windows

v doSometing() {
	cout << "This code works only on Windows" << endl;
}
#endif // Windows

#ifdef Linux

v doSometing() {
	cout << "This code works only on Linux" << endl;
}
#endif // Linux

#define Size 25;

#if Size>50
void DoSometingWithSize() {
	cout << "I am working for big data" << endl;
}
#else
void DoSometingWithSize() {
	cout << "I am working for small data" << endl;
}
#endif

#pragma endregion

void DefineLogicFunc() {

	//PI = 3.4 // error
	//cout << PI << endl;
	//cout << Name << endl;

	//DoSometingWithSize();


	cout << "Current Date : " << __DATE__ << endl;
	cout << "Current TIme : " << __TIME__ << endl;

	cout << "Current Line : " << __LINE__ << endl;// line 73
#line 1
	cout << "Current Line : " << __LINE__ << endl;// line 1

	cout << "Current File : " << __FILE__ << endl;
}

void main() {
	ConnectToDatabase();
}