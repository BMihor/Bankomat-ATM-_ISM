#pragma once
#include "User.h"
#include "Admin.h"

class Bankomat_ATM
{
public:
	// назва банку
	char name_of_ATM[255];
	// унікальний номер банкомату
	int number_of_ATM;
	// режим роботи банкомату
	char mode_of_ATM[255];
	// інформація про поточну суму наявних коштів
	int current_amount_money; 
	// мінімальна сума, яка дозволяється зняти клієнту за один раз
	int min_amount_money;
	// максимальна сума, яка дозволяється зняти клієнту за один раз
	int max_amount_money;
	int bank_notes[8];
	int count_bank_notes[8];
public:
	Bankomat_ATM(void);
	Bankomat_ATM(char[255], int, char[255], int, int);

	Bankomat_ATM(const Bankomat_ATM &);
	const Bankomat_ATM& operator = (const Bankomat_ATM &);

	void Set_name_of_ATM(char* _name_of_ATM);
	void Set_number_of_ATM( int );
	void Set_mode_of_ATM(char* _name_of_ATM);
	void Set_min_amount_money( int );
	void Set_max_amount_money( int );
};

struct info_Bankomat
{
	Bankomat_ATM *info_Bankomat_;
};

class Bankomat
{
public:
	void loading_menu(void);
	void initialize(void);
	void initialize_menu(info_Bankomat *_info_Bankomat_, Admin *, User * );
	bool open_base(info_Bankomat *_info_Bankomat_);
	void close_base(info_Bankomat *_info_Bankomat_);

	void administrator_ATM(info_Bankomat *_info_Bankomat_, Admin*); 
	void change_record(info_Bankomat *_info_Bankomat_);
	void help_for_change_money(info_Bankomat *_info_Bankomat_, int);
	void user_ATM(info_Bankomat *_info_Bankomat_, User *); 
	void withdraw_money(info_Bankomat *_info_Bankomat_, User *); 
	void greedy_maney(info_Bankomat *_info_Bankomat_, User *, int);
	void generous_maney(info_Bankomat *_bankomat_, User * user, int symma,int sz_of_banknotes,int &count_of_min_money,int count_of_curent_money,int mas_ef[],int mas_cur[]);
};