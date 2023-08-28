#pragma once

#include <iostream>
#include "FileHelper.h"

using namespace std;

void ConnectToDatabase() {
	cout << "Connected succesfully" << endl;
	cout << "DATE : " << __DATE__ <<" : " << __TIME__ << endl;
	WriteToFile("data.txt");
}