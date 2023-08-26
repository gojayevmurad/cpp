#include <iostream>

using namespace std;

struct Validation {
	bool isEmailValid : 1;
	bool isCardValid : 1;
	bool isAgeValid : 1;
	bool isPhoneNumberValid : 1;
	bool isEmailValid2 : 1;
	bool isCardValid2 : 1;
	bool isAgeValid2 : 1;
	bool isPhoneNumberValid2 : 1;
};

struct User {
	short age : 10;
	short score : 6;
};

// Standart Struct 
// nested or embedded

/*
	struct Date {
		short day : 6;
		short month : 5;
		short year : 21;
	};

	struct Time {
		short minute : 8;
		short hour : 8;

	};

	struct Event {
		char* name;
		Date eventdate;
		Time eventtime;
	};
*/



struct Product {

private:

	struct ProductType {
		char* type;
	};

public:

	struct ProductBoxShape {
		char* shape;
	};

	char* name;
	double price;
	ProductType type;
	ProductBoxShape shape;
};

struct File {
	char* name;
	char* content;
};

struct HDD {
	int maxSize = 1024;
	int size = 0;

	File** files;
	int filecount = 0;
};

File* GetFile(const HDD & disc,const char* filename) {
	for (size_t i = 0; i < disc.filecount; i++){
		if (strcmp(disc.files[i]->name, filename) == 0) {
			return disc.files[i];
		}
	}
	return nullptr;
}
bool CheckFileCanAdded(const HDD& disc, const char* content) {
	auto currentSize = disc.size;
	auto total = currentSize + strlen(content);
	if (total <= disc.maxSize){
		return true;
	}
	return false;
};
void AddFileToDisc(HDD& disc, char* filename, char* content) {
	File* newFile = new File{ filename, content };
	auto temp = new File * [disc.filecount+1] {};

	for (size_t i = 0; i < disc.filecount; i++){
		temp[i] = disc.files[i];
	}temp[disc.filecount] = newFile;
	disc.files = temp;
	disc.filecount++;
	disc.size += strlen(content);
	temp = nullptr;
}
void CreateFile(HDD& disc, char* filename, char* content) {
	if (strlen(filename) == 0) {
		cout << "Filename is empty" << endl;
		return;
	}

	if (strlen(filename) <= 4) {
		cout << "FIlename should be more than 4 characters" << endl;
		return;
	}

	if (strlen(content) == 0) {
		cout << "Content is empty" << endl;
		return;
	}

	auto file = GetFile(disc, filename);
	if (file == nullptr) {
		auto canAdded = CheckFileCanAdded(disc, content);
		if (canAdded) {
			AddFileToDisc(disc, filename, content);
		}
		else {
			cout << "this content is huge for our disc capacity" << endl;
		}
	}
	else {
		cout << filename << " file is already exist" << endl;
	}
}
void ShowAllFiles(const HDD& disc) {
	cout << "DISC INFO" << endl;

	cout << "Maximum size : " << disc.maxSize << " bytes" << endl;
	cout << "Current size : " << disc.size << " bytes" << endl;
	cout << "Free size    : " << disc.maxSize - disc.size << " bytes" << endl;

	for (size_t i = 0; i < disc.filecount; i++) {
		cout << "\n\t\tFile Info" << endl;
		cout << "Filename : " << disc.files[i]->name << endl;
		cout << "Content : " << disc.files[i]->content << endl;
		cout << "Size : " << strlen(disc.files[i]->content) << " bytes" << endl;
	}cout << endl;

}

void ShowMenu() {
	cout << "Show All Files [1]" << endl;
	cout << "Add New  File  [2]" << endl;
}

void main() {
	// Bit Fields

	//cout << sizeof(Validation) << endl;

	/*
		Validation v;
		v.isAgeValid = 1;
		cout << v.isAgeValid << endl;
	*/

	/*
		User u;
		u.age = 123;
		u.score = 32;

		cout << sizeof(u) << endl;
		cout << u.score << endl;
		cout << u.age << endl;
	*/

	//Product::ProductType type;



	HDD disc;
	CreateFile(disc, new char[12] {"a.txt"}, new char[1000] {"Hello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello worldHello world"});
	CreateFile(disc, new char[12] {"b.txt"}, new char[30] {"Hello world"});

	while (true)
	{
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			ShowAllFiles(disc);
		}
		else if (select==2){
			cin.ignore();
			cin.clear();

			cout << "Enter filename : " << endl;
			char* name = new char[50] {};
			cin.getline(name, 50);

			cout << "Enter content : " << endl;
			char* content = new char[10000] {};
			cin.getline(content, 10000);

			CreateFile(disc, name, content);
		}
	}

}