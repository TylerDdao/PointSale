#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <fstream>
using namespace std;

class Communication
{
	string fileName;
	string fileContent;

public:
	Communication();

	string GetFileName();
	string GetFileContent();


	bool SendFile();
};

