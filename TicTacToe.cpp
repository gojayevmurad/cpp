#include <iostream>
#include <Windows.h>

using namespace std;



const int s = 3;
int game[s][s]{};



int number;

bool isFirst = true;

void Show() {

	for (size_t i = 0; i < s; i++){

		for (size_t k = 0; k < s; k++) {

			if (game[i][k] == 0) {
				cout << " * ";
			}
			else if (game[i][k] == 1) {
				cout << " X ";
			}
			else {
				cout << " O ";
			}

		}cout << endl << endl;

	}
	
}

void Update() {
	int number = 0;

	do{

		isFirst ? cout << "Player 1 turn " : cout << "Player 2 turn";

		cout << "Enter number : " << endl;
		cin >> number;

		if (game[0][number - 1] != 0) {
			cout << "Wrong" << endl;
		}else if (isFirst) {
			game[0][number - 1] = 1;
		} else {
			game[0][number - 1] = 2;
		}



	} while (game[0][number-1] == 0);

	isFirst = !isFirst;
}


bool GetPlayerWin1() {
	int diaqonal = 0;
	int diaqonal2 = 0;
	for (size_t i = 0; i < s; i++) {

		int sum = 0;

		for (size_t k = 0; k < s; k++) {

			if (game[i][k] == 1) {
				sum += 1;
			}

			if (game[i][k] == 1 && (i == k)) {
				++diaqonal;
			}

			if (game[i][k] == 1 && (i + k) == (s - 1)) {
				++diaqonal2;
			}

		}

		if (sum >= s) {
			return true;
		}

	}
	if (diaqonal >= s || diaqonal2 >= s) {
		return true;
	}

	return false;

}

bool GetPlayerWin2() {
	int diaqonal = 0;
	int diaqonal2 = 0;

	// check diagonals
	for (size_t i = 0; i < s; i++) {

		int sum = 0;

		for (size_t k = 0; k < s; k++) {

			if (game[i][k] == 2) {
				sum += 1;
			}

			if (game[i][k] == 1 && (i == k)) {
				++diaqonal;
			}
			else if (game[i][k] == 1 && (i + k) == (s - 1)) {
				++diaqonal2;
			}

		}
		if (sum >= s) {
			return true;
		}

	}
	if (diaqonal == s || diaqonal2 == s) {
		return true;
	}

	return false;

}

void Winner() {
	cout << "\a";
	Sleep(300);
	cout << "\a";
	Sleep(300);
}

void main() {
	while (true){
		bool result1 = GetPlayerWin1();
		bool result2 = GetPlayerWin2();
		if (result1) {
			cout << "Player 1 WINNER";
			system("color 9");
			Winner();
			break;
		}
		if (result2) {
			cout << "Player 2 WINNER";
			system("color 2");
			Winner();
			break;
		}
		Show();
		Update();
		Sleep(200);
		system("cls");
	}
}

