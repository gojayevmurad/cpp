#include <iostream>

using namespace std;


char* Encrypte(const char* pass) {
	int l = strlen(pass);
	char* encrypt = new char[l + 1] {};
	for (size_t i = 0; i < l; i++){
		int code = (pass[i] ^ l);
		encrypt[i] = code;
	}
	encrypt[l] = '\0';
	return encrypt;
}

char* Decrypt(const char* pass) {
	int l = strlen(pass);
	char* decrypt = new char[l + 1] {};
	for (size_t i = 0; i < l; i++) {
		int code = (pass[i] ^ l);
		decrypt[i] = code;
	}
	decrypt[l] = '\0';
	return decrypt;
}

void WriteToFile(const char* data, const char* filename) {
	FILE* fs;
	fopen_s(&fs, filename, "w");
	int l = strlen(data);
	fwrite(data, sizeof(char), l, fs);
	fclose(fs);
}

char* ReadFromFile(const char* filename) {
	FILE* fs;
	fopen_s(&fs, filename, "r");
	char* text = new char[100] {};
	fread(text, sizeof(char), 100, fs);
	return text;
}

void main() {
	//BITWISE OPERATOR
	//AND &
	//OR |
	//XOR ^

	//LEFT SHIFT <<
	//RIGHT SHIFT >>

	//button.Style = FontStyle.Italic | FontStyle.Bold; OR BITWISE
	//mouse_event(Mouse.RightDown | Mouse.RightUp) 

	//AND BITWISE OPERATOR
#if 0


	int a = 7; // 00000111
	int b = 12; // 00001100

	cout << "&" << (a & b) << endl;

	// 00000111
	// &
	// 00001100
	// 00000100 => 4

	cout<< "|" << (a | b) << endl;

	// 00000111
	// |
	// 00001100
	// 00001111 => 15
#endif // 0

#if 0
	int c = 12; // 00001100
	int d = (c << 3);
	cout << d << endl;
	int main = d >> 3;
	cout << main << endl;

#endif // 0

	// XOR
#if 0


	int data = 17; //00010001
	int code = 13; //00001101

	//00010001
	//^
	//00001101
	//00011100 => 28

	int result = (data ^ code);
	cout << result << endl;
	cout << (result ^ code) << endl;
#endif // 0

	/*
		cout << "Enter password : " << endl;
		char* pass = new char[50] {};
		cin.getline(pass, 50);
		auto encryption = Encrypte(pass);
		cout << encryption << endl;
		auto decryption = Decrypt(encryption);
		cout << decryption << endl;
	*/
	
	/*
		cout << "Enter password : " << endl;
		char* pass = new char[50] {};
		cin.getline(pass, 50);
		auto encryption = Encrypte(pass);
		WriteToFile(encryption, "pass.txt");
	*/

	auto result = ReadFromFile("pass.txt");

	cout << "Enter password : " << endl;
	char* pass = new char[50] {};
	cin.getline(pass, 50);
	auto encryptePass = Encrypte(pass);

	if (strcmp(result, encryptePass) == 0) {
		cout << " Pass is true" << endl;
	}
	else {
		cout << "Your pass is incorrect" << endl;
	}

	/*
		auto result = ReadFromFile("pass.txt");
		cout << result << endl;
		auto password = Decrypt(result);
		cout << password << endl;
	*/
}