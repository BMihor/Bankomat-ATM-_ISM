#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class Admin
{
protected:
	char login[20];
	char pass[20];
public:
	Admin(void);
	Admin(char[20], char[20]);
	char* Getlogin () {return this->login;};
	char* Getpass () {return this->pass;};
};