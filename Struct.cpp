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
	double score; // 8
	char* nickname; // 8
	bool isStar; // 1
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

struct Figure{
	double width;
	double height;
	char* name;
};


void ShowFigure(Figure& figure) {
	cout << "Height : " << figure.height << endl;
	cout << "Width : " << figure.width << endl;
	cout << "Name : " << figure.name << endl;
}

struct Teacher {
	char* name;
	char* speciality;
};

struct Student {
	Teacher myTeacher;
	char* name;
	int age;
};

void ShowTeacher(const Teacher& teacher) {
	cout << "Teacher Info" << endl;
	cout << "Name : " << teacher.name << endl;
	cout << "Speciality : " << teacher.speciality << endl;
}

void ShowStudent(const Student& student) {
	ShowTeacher(student.myTeacher);

	cout << "Student Info" << endl;
	cout << "Name : " << student.name << endl;
	cout << "Age : " << student.age << endl;

}

const Teacher* GetNewTeacher() {
	Teacher teacher;

	cout << "Enter name : " << endl;
	char* name = new char[10] {};
	cin.getline(name, 10);

	cout << "Enter Speciality : " << endl;
	char* speciality = new char[10] {};
	cin.getline(speciality, 10);

	teacher.name = name;
	teacher.speciality = speciality;

	return &teacher;
}

const Student* GetNewStudent() {
	Student student;

	cout << "Enter name : " << endl;
	char* name = new char[10] {};
	cin.getline(name, 10);

	cout << "Enter age : " << endl;
	int age;
	cin >> age;

	cin.ignore();
	cin.clear();

	const Teacher* teacher = GetNewTeacher();

	student.age = age;
	student.name = name;
	student.myTeacher = *teacher;

	return &student;
}

void main() {
	//Player player;
	//setNewObj(player);
	//ShowPlayer(player);

	//cout << sizeof(Player) << endl; // 24 byte

	/*
		Figure f1{ 100, 500, new char[30] {"Rectangle"} };
		Figure f2{ 100, 500, new char[30] {"Rectangle"} };
		Figure figures[2]{ f1,f2 };

		for (size_t i = 0; i < 2; i++){
			ShowFigure(figures[i]);
		}
	*/

	/*
		Figure* f1 = new Figure{ 100, 500, new char[30] {"Rectangle"} };
		Figure* f2 = new Figure{ 100, 500, new char[30] {"Rectangle"} };

		Figure** figures = new Figure * [2] {f1, f2};

		for (size_t i = 0; i < 2; i++){
			ShowFigure(*figures[i]);
		}
	*/

	/*
		Teacher t{ new char[10] {"Leyla"}, new char[30] {"UX Designer"} };
		Student s{ t, new char[10] {"Arif"}, 35 };

		ShowStudent(s);
	*/

	// get new student
	const Student* newStudent = GetNewStudent();

	ShowStudent(*newStudent);

}