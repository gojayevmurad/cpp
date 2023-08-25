#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

struct Human{
	int age;
	char* name;
	char gender;
};

void ShowHuman(Human human) {
	cout << "Age : " << human.age << endl;
	cout << "Gender : " << human.gender << endl;
	cout << "Name : " << human.name << endl;
}

void CreateHuman(Human* human, int age, char gender, const string name) {
	human->age = age;
	human->gender = gender;
	human->name = new char[10] {"asdfasdf"};
}

struct Player {
	double score;
	char* nickname;
	bool isStar;
};

void ShowPlayer(const Player& player) {
	cout << "Nickname : " << player.nickname << endl;
	cout << "Score : " << player.score << endl;
	cout << "Is Star : ";
	(player.isStar) ? cout << "Yes": cout << "No";
}

const Player& getNewObj() {

	cout << "Enter score : " << endl;
	double score = 0;
	cin >> score;

	cin.ignore();
	cin.clear();

	cout << "Enter nickname : " << endl;
	char* nickname = new char[50] {};
	cin.getline(nickname, 50);

	cout << "Is star [1,0]" << endl;
	bool isStar = false;
	cin >> isStar;
	
	//Player player;
	//player.isStar = isStar;
	//player.nickname = nickname;
	//player.score = score;

	Player player{ score, nickname, isStar };

	return player;

}

void setNewObj(Player& player) {

	cout << "Enter score : " << endl;
	double score = 0;
	cin >> score;

	cin.ignore();
	cin.clear();

	cout << "Enter nickname : " << endl;
	char* nickname = new char[50] {};
	cin.getline(nickname, 50);

	cout << "Is star [1,0]" << endl;
	bool isStar = false;
	cin >> isStar;

	//Player player;
	//player.isStar = isStar;
	//player.nickname = nickname;
	//player.score = score;

	player.score = score;
	player.nickname = nickname;
	player.isStar = isStar;

}

void main() {
	Player player;
	setNewObj(player);
	ShowPlayer(player);
}