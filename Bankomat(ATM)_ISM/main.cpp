#include <conio.h>
#include <windows.h>
#include "Bankomat.h"

int main()
{
	SetConsoleCP(1251);			
	SetConsoleOutputCP(1251);
	// Наш банкомат
	Bankomat bankomat;
	bankomat.loading_menu();
	return 0;
}