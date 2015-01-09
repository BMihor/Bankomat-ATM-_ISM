#include "Admin.h"

Admin::Admin(void)
{
	strcpy(login, "admin");
	strcpy(pass, "admin");
}

Admin::Admin(char _login[20], char _pass[20])
{
	strcpy(login, _login);
	strcpy(pass, _pass);
}