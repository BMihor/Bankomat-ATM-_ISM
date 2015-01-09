#include "User.h"

User::User(char _login[20], char _pass[20], int _summa_of_money):Admin(_login, _pass)
{
	summa_of_money = _summa_of_money;
}