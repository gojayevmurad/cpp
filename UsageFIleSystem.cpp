#include <iostream>

using namespace std;

void WriteToFile() {
	FILE* file;
	fopen_s(&file, "myfile.txt", "w");
	char* text = new char[20] {"Salam dünya"};
	fwrite(text, sizeof(char), strlen(text), file);
	fclose(file);
}

void AppendToFile() {
	FILE* file;
	fopen_s(&file, "myfile.txt","a");
	char* text = new char[100] {};
	cin.getline(text, 100);
	int l = strlen(text);
	strcat_s(text, l + 3, "\n ");
	fwrite(text, sizeof(char), strlen(text), file);
	fclose(file);
}

void ReadFromFile() {

	FILE* file;
	fopen_s(&file, "myfile.txt", "r");
	char* text = new char[100] {};

	fseek(file, 10, 0); // pass 10 character

	while (fread_s(text,100, sizeof(char),100, file) != 0){
		cout << text << endl;
		delete[] text;
		text = new char[100] {};
	}
	fclose(file);
}

void WriteBinary() {
	FILE* file;
	int size = 5;
	int *arr = new int[size] {11, 22, 33, 44, 55};
	fopen_s(&file, "file1.bin", "wb");
	fwrite((char*)arr, sizeof(int), size, file);
	fclose(file);
}

void ReadBinary() {
	FILE* file;
	int size = 5;
	int* arr = new int[size] {};
	fopen_s(&file, "file1.bin", "rb");
	fread_s(arr, sizeof(int) * size, sizeof(int),size, file);
	for (size_t i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	fclose(file);
}


void main() {


}