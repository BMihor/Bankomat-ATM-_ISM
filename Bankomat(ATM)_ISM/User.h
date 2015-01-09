#pragma once
#include "Admin.h"

class User:public Admin
{
private:
	int summa_of_money;
public:
	User(char[20], char[20], int);
	int Getsumma_of_money () {return summa_of_money;};
	void Setsumma_of_money (int _summa_of_money) {this->summa_of_money = _summa_of_money;};

};