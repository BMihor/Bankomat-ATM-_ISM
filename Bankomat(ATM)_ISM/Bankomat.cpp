#include "Bankomat.h"

Bankomat_ATM::Bankomat_ATM(void)
{
	strcpy(name_of_ATM, "Unknown name");

	number_of_ATM = 0;

	strcpy(mode_of_ATM, "Unknown");

	min_amount_money = 0;

	max_amount_money = 0;

	bank_notes[0] = 1;
	bank_notes[1] = 2;
	bank_notes[2] = 5;
	bank_notes[3] = 10;
	bank_notes[4] = 50;
	bank_notes[5] = 100;
	bank_notes[6] = 200;
	bank_notes[7] = 500;

	count_bank_notes[0] = 20;
	count_bank_notes[1] = 20;
	count_bank_notes[2] = 20;
	count_bank_notes[3] = 20;
	count_bank_notes[4] = 20;
	count_bank_notes[5] = 20;
	count_bank_notes[6] = 20;
	count_bank_notes[7] = 20;

	for (int i = 0; i < 8; i++)
	{
		current_amount_money += bank_notes[i] * count_bank_notes[i];
	}
}

Bankomat_ATM::Bankomat_ATM(char _name_of_ATM[255], int _number_of_ATM, char _mode_of_ATM[255], int _min_amount_money, int _max_amount_money)
{
	strcpy(name_of_ATM, _name_of_ATM);
	number_of_ATM = _number_of_ATM;
	strcpy(mode_of_ATM, _mode_of_ATM);
	min_amount_money = _min_amount_money;
	max_amount_money = _max_amount_money;

	bank_notes[0] = 1;
	bank_notes[1] = 2;
	bank_notes[2] = 5;
	bank_notes[3] = 10;
	bank_notes[4] = 50;
	bank_notes[5] = 100;
	bank_notes[6] = 200;
	bank_notes[7] = 500;

	count_bank_notes[0] = 20;
	count_bank_notes[1] = 20;
	count_bank_notes[2] = 20;
	count_bank_notes[3] = 20;
	count_bank_notes[4] = 20;
	count_bank_notes[5] = 20;
	count_bank_notes[6] = 20;
	count_bank_notes[7] = 20;

	current_amount_money = 0;

	for (int i = 0; i < 8; i++)
	{
		current_amount_money += bank_notes[i] * count_bank_notes[i];
	}

}

Bankomat_ATM::Bankomat_ATM(const Bankomat_ATM & Bankomat_ATMRef)
{
	strcpy_s (name_of_ATM, strlen(Bankomat_ATMRef.name_of_ATM) + 1, Bankomat_ATMRef.name_of_ATM);
	number_of_ATM = Bankomat_ATMRef.number_of_ATM;
	strcpy_s (mode_of_ATM, strlen(Bankomat_ATMRef.mode_of_ATM) + 1, Bankomat_ATMRef.mode_of_ATM);
	current_amount_money = Bankomat_ATMRef.current_amount_money;
	min_amount_money = Bankomat_ATMRef.min_amount_money;
	max_amount_money = Bankomat_ATMRef.max_amount_money;
}

const Bankomat_ATM& Bankomat_ATM::operator = (const Bankomat_ATM & Bankomat_ATMRef) 
{
	strcpy_s (name_of_ATM, strlen(Bankomat_ATMRef.name_of_ATM) + 1, Bankomat_ATMRef.name_of_ATM);
	number_of_ATM = Bankomat_ATMRef.number_of_ATM;
	strcpy_s (mode_of_ATM, strlen(Bankomat_ATMRef.mode_of_ATM) + 1, Bankomat_ATMRef.mode_of_ATM);
	current_amount_money = Bankomat_ATMRef.current_amount_money;
	min_amount_money = Bankomat_ATMRef.min_amount_money;
	max_amount_money = Bankomat_ATMRef.max_amount_money;
	return *this;
}

void Bankomat_ATM::Set_name_of_ATM(char* _name_of_ATM)
{
	strcpy(this->name_of_ATM, _name_of_ATM);
}

void Bankomat_ATM::Set_number_of_ATM(int _number_of_ATM)
{
	number_of_ATM =_number_of_ATM;
}

void Bankomat_ATM::Set_min_amount_money( int _min_amount_money)
{
	min_amount_money = _min_amount_money;
}
void Bankomat_ATM::Set_max_amount_money( int _max_amount_money)
{
	max_amount_money = _max_amount_money;
}

void Bankomat_ATM::Set_mode_of_ATM(char* _mode_of_ATM)
{
	strcpy(mode_of_ATM, _mode_of_ATM);
}


void Bankomat::initialize(void)
{
	info_Bankomat _bankomat_;
	_bankomat_.info_Bankomat_ = new Bankomat_ATM("Privatbank", 1, "greedy"/*"generous"*/, 1,5000);
	Admin admin("admin", "1234");
	User user("user", "user", 10000);
	if(open_base(&_bankomat_) == false)
	{
		close_base(&_bankomat_);
	}
	initialize_menu(&_bankomat_, &admin, &user);
}

void Bankomat::loading_menu(void)
{
	char key;
	do
	{
		system("cls");
		cout << "����� ����������!!!" << endl;
		cout << "�������� �������." << endl;
		cout << "������� Enter ��� �������� ������." << endl;
		key = _getch();
		switch (key)
		{
		case 13:
			{
				initialize();
			}
			break;
		}
	}
	while(  key != 27 );
}

bool Bankomat::open_base(info_Bankomat *_bankomat_)
{
	FILE *file_in = fopen("data/database.bin", "r");
	if(file_in == NULL)
	{
		return false;
	}
	fread(_bankomat_->info_Bankomat_, sizeof(Bankomat_ATM)*1, 1, file_in);
	fclose(file_in);
	return true;
}

void Bankomat::close_base(info_Bankomat *_bankomat_)
{
	FILE *file_out = fopen("data/database.bin","w");
	fwrite(_bankomat_->info_Bankomat_, sizeof(Bankomat_ATM)*1, 1, file_out);
	fclose(file_out);
}

void Bankomat::initialize_menu(info_Bankomat *_bankomat_, Admin *admin, User *user)
{
	char key;
	do
	{
		system("cls");
		cout << "�������� ����� �����:" << endl;
		cout << "1. ������������� ���������." << endl;
		cout << "2. ������������." << endl;
		key = _getch();
		switch (key)
		{
		case '1':
			{
				system("cls");
				administrator_ATM(_bankomat_, admin);
			}
			break;
		case '2':
			{
				system("cls");
				user_ATM(_bankomat_, user);
			}
			break;
		}
	}
	while(  key != 27 );
}

void Bankomat::user_ATM(info_Bankomat *_bankomat_, User *user )
{
	bool login_true = false;
	char login[20], pass[20];
	do
	{
		system("cls");
		cout << "����� ����������!!!" << endl;
		cout << "�������� ������ � ����� ������������." << endl;
		cout << "������� ����� � ������." << endl;
		cin>>login>>pass;
		if(!strcmp(login, user->Getlogin()) || !strcmp(pass,user->Getpass()))
		{
			login_true = true;
			char key;
			do
			{
				system("cls");
				cout << "����� ����������!!!" << endl;
				cout << "�������� � ������ ������������." << endl;
				cout << "�������� ����� ����:" << endl;
				cout<<"1. ����� ������"<<endl;
				key=_getch();
				switch (key)
				{
				case '1':
					{
						withdraw_money(_bankomat_, user);
					}
					break;
				}
			}
			while(  key != 27 );
		}
		else
		{
			login_true = false;
		}
	}
	while (login_true == false);
}

void Bankomat::administrator_ATM(info_Bankomat *_bankomat_, Admin *admin)
{
	bool login_true = false;
	char login[20], pass[20];
	do
	{
		system("cls");
		cout << "����� ����������!!!" << endl;
		cout << "�������� ������ � ����� ��������������." << endl;
		cout << "������� ����� � ������." << endl;
		cin>>login>>pass;
		if(!strcmp(login, admin->Getlogin()) || !strcmp(pass,admin->Getpass()))
		{
			login_true = true;
			char key;
			do
			{
				system("cls");
				cout << "����� ����������!!!" << endl;
				cout << "�������� � ������ ��������������." << endl;
				cout << "�������� ����� ����:" << endl;
				cout << "1. ����������� ���������� ��� ��������." << endl;
				cout << "2. �������� ���������� ��� ��������." << endl;
				key = _getch();
				switch (key)
				{
				case '1':
					{
						system("cls");
						cout<<".........................................................................."<<endl;
						cout<<"����� ���������: "<<_bankomat_->info_Bankomat_->name_of_ATM<<endl;
						cout<<"����� ���������: "<<_bankomat_->info_Bankomat_->number_of_ATM<<endl;
						cout<<"����� ������ ���������: "<<_bankomat_->info_Bankomat_->mode_of_ATM<<endl;
						cout<<"������ ���� � ��������i: "<<_bankomat_->info_Bankomat_->current_amount_money<<endl;
						cout<<"̳������� ����, ��� ������������ ����� �볺��� �� ���� ���: "<<_bankomat_->info_Bankomat_->min_amount_money<<endl;
						cout<<"����������� ����, ��� ������������ ����� �볺��� �� ���� ���: "<<_bankomat_->info_Bankomat_->max_amount_money<<endl;
						cout<<".........................................................................."<<endl;
						system("pause");
					}
					break;
				case '2':
					{
						change_record(_bankomat_);
					}
					break;
				}
			}
			while(  key != 27 );
		}
		else
		{
			login_true = false;
		}
	}
	while (login_true == false);
}

void Bankomat::help_for_change_money(info_Bankomat *_bankomat_, int j)
{
	if(j == 49)		j = 0;
	if(j == 50)		j = 1;
	if(j == 51)		j = 2;
	if(j == 52)		j = 3;
	if(j == 53)		j = 4;
	if(j == 54)		j = 5;
	if(j == 55)		j = 6;
	if(j == 56)		j = 7;
	if(j == 57)		j = 8;
	cout<<"�� ����� ������ ����� ��������� "<<_bankomat_->info_Bankomat_->bank_notes[j]<<"["<<_bankomat_->info_Bankomat_->count_bank_notes[j]<<"]"<<endl;
	cout<<"�������� �������� ��: ";
	int count;
	cin>>count;
	if(count>=0)
		_bankomat_->info_Bankomat_->count_bank_notes[j]=count;
	_bankomat_->info_Bankomat_->current_amount_money = 0;
	for (int i = 0; i < 8; i++)
	{
		_bankomat_->info_Bankomat_->current_amount_money += 
			_bankomat_->info_Bankomat_->bank_notes[i]*
			_bankomat_->info_Bankomat_->count_bank_notes[i];
	}
	close_base(_bankomat_);
}

void Bankomat::change_record(info_Bankomat *_bankomat_)
{
	system("cls");
	cout << "������� ����, ��� ������� ������" << endl;
	cout<<"1. ����� �����"<<endl;
	cout<<"2. ��������� ����� ���������"<<endl;
	cout<<"3. ����� ������ ���������"<<endl;
	cout<<"4. ���������� ��� ������� ���� ������� �����"<<endl;
	cout<<"5. ̳������� ����, ��� ������������ ����� �볺��� �� ���� ���"<<endl;
	cout<<"6. ����������� ����, ��� ������������ ����� �볺��� �� ���� ���"<<endl;
	char Key;
	Key=_getch();
	char str[255];
	int str1;
	switch (Key)
	{
	case '1':
		{
			system("cls");
			cout<<"�������� �����"<<endl;
			cout<<"����� ���������: "<<_bankomat_->info_Bankomat_->name_of_ATM<<endl;
			cout<<"������ ����� �����"<<endl;
			cin>>str;
			_bankomat_->info_Bankomat_->Set_name_of_ATM(str);
			close_base(_bankomat_);
		}
		break;
	case '2':
		{
			system("cls");
			cout<<"�������� �����"<<endl;
			cout<<"����� ���������: "<<_bankomat_->info_Bankomat_->number_of_ATM<<endl;
			cout<<"������ ����� �����"<<endl;
			cin>>str1;
			_bankomat_->info_Bankomat_->Set_number_of_ATM(str1);
			close_base(_bankomat_);
		}
		break;
	case '3':
		{
			bool chang = false;
			do
			{
				system("cls");
				cout<<"�������� �����"<<endl;
				cout<<"����� ������ ���������: "<<_bankomat_->info_Bankomat_->mode_of_ATM<<endl;
				cout<<"������ ����� ����� greedy/generous"<<endl;
				cin>>str;
				if(!strcmp(str,"greedy") || !strcmp(str,"generous"))
				{
					chang = true;
				}
				else
				{
					chang = false;
				}
			}
			while (chang == false);
			_bankomat_->info_Bankomat_->Set_mode_of_ATM(str);
			close_base(_bankomat_);
		}
		break;
	case '5':
		{
			system("cls");
			cout<<"�������� �����"<<endl;
			cout<<"̳������� ����, ��� ������������ ����� �볺��� �� ���� ���: "<<_bankomat_->info_Bankomat_->min_amount_money<<endl;
			cout<<"������ ����� �����"<<endl;
			cin>>str1;
			if(str1>0)
				_bankomat_->info_Bankomat_->Set_min_amount_money(str1);
			close_base(_bankomat_);
		}
		break;
	case '6':
		{
			system("cls");
			cout<<"�������� �����"<<endl;
			cout<<"����������� ����, ��� ������������ ����� �볺��� �� ���� ���: "<<_bankomat_->info_Bankomat_->max_amount_money<<endl;
			cout<<"������ ����� �����"<<endl;
			cin>>str1;
			if(str1<=_bankomat_->info_Bankomat_->current_amount_money)
				_bankomat_->info_Bankomat_->Set_max_amount_money(str1);
			close_base(_bankomat_);
		}
		break;
	case '4':
		{
			system("cls");
			char Key;

			do
			{
				system("cls");
				cout<<"�������� �������"<<endl;
				cout<<"����� ���������: ";
				for (int i = 0; i < 8; i++)
				{
					cout<<_bankomat_->info_Bankomat_->bank_notes[i]<<"["<<_bankomat_->info_Bankomat_->count_bank_notes[i]<<"]"<<" "; 
				}
				cout<<endl;
				cout<<"������ ����� �������� ��� ���������"<<endl;
				cout<<"1. ������ ��������� 1"<<endl;
				cout<<"2. ������ ��������� 2"<<endl;
				cout<<"3. ������ ��������� 5"<<endl;
				cout<<"4. ������ ��������� 10"<<endl;
				cout<<"5. ������ ��������� 50"<<endl;
				cout<<"6. ������ ��������� 100"<<endl;
				cout<<"7. ������ ��������� 200"<<endl;
				cout<<"8. ������ ��������� 500"<<endl;
				Key=_getch();
				switch (Key)
				{
				case '1':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '2':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '3':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '4':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '5':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '6':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '7':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				case '8':
					{
						help_for_change_money(_bankomat_, Key);
					}
					break;
				}
			}
			while(Key!='1' && Key!='2' && Key!='3' && Key != '4' && Key!='5' && Key!='6' && Key!='7' && Key!= '8');
		}
		break;
	}
}

void Bankomat::greedy_maney(info_Bankomat *_bankomat_, User * user, int sum_to_pay)
{
	int summa = sum_to_pay;
	int summa_usera = user->Getsumma_of_money();

	const int sz_of_banknotes = 8;
	int bank_notes_number[sz_of_banknotes] = {0};
	int cnt=0;
	for(int i = sz_of_banknotes - 1; i >= 0; --i)
	{
		bank_notes_number[cnt++] = sum_to_pay/_bankomat_->info_Bankomat_->bank_notes[i];
		sum_to_pay -= bank_notes_number[cnt-1]*_bankomat_->info_Bankomat_->bank_notes[i];
	}
	cnt=0;
	int oper_ok = 0;
	for(int i = 0; i < sz_of_banknotes; ++i)
	{
		if(bank_notes_number[i])
		{
			cout<<"������� ��������� "<<_bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes - 1 - i]<<" ���� "<<bank_notes_number[i]<<endl;
			cnt++;
			oper_ok += _bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes - 1 - i]*bank_notes_number[i];
			user->Setsumma_of_money(user->Getsumma_of_money()-_bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes - 1 - i]*bank_notes_number[i]);
		}

	}
	if(!cnt)
	{cout<<"������, �������� �� ���������, �������� �� ����� ����� �������";
	cout<<endl;
	}
	else
	{
		if(oper_ok != summa)
		{
			user->Setsumma_of_money(summa_usera);
			cout<<"������, �������� �� ���������, �������� �� ����� ����� �������"<<endl<< "����� ������ ������ "<< oper_ok<<endl;
		}
		else
		{
			cout<<"����������, ������ ��������"<<endl;
		}
	}
	system("pause"); 

}

void Bankomat::generous_maney(info_Bankomat *_bankomat_, User * user, int symma,int sz_of_banknotes,
							  int &count_of_min_money,int count_of_curent_money,int mas_ef[],int mas_cur[])
{
	if(count_of_curent_money !=-1)//��������� �������� - ���������� ��-�� ������� ����� � ����������� ���������
	{
		symma-=_bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes];//������������ �����, ����������� ��� ������������
		mas_cur[count_of_curent_money]=_bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes];//��������� ������� � ������� ������������������
		count_of_curent_money++;
	}
	else 
		count_of_curent_money = 0;

	if(symma==0)//��������, ��� ����������� ����� �������.
	{
		if(count_of_min_money>count_of_curent_money)
		{//������ ����� ����������� ������������������ ���������
			for(int i=0;i<count_of_curent_money;i++) mas_ef[i]=mas_cur[i];
			count_of_min_money=count_of_curent_money;
		}
	}
	else
		if((float(symma) / _bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes]) < (count_of_min_money - count_of_curent_money)) // ������ ����� ������������� ��������
		{
			while((sz_of_banknotes >= 0) && (symma < _bankomat_->info_Bankomat_->bank_notes[sz_of_banknotes]))
				sz_of_banknotes--;//����� �������� <= �����
			if(sz_of_banknotes >= 0) //���� ������� �������
			{//��������������� ������������� ��� �������� ��� ��������� ����
				for(int i = sz_of_banknotes; i >= 0; i--) 
					generous_maney(_bankomat_,  user, symma,i,count_of_min_money,count_of_curent_money,mas_ef,mas_cur);
			}
		}
}
void Bankomat::withdraw_money(info_Bankomat *_bankomat_, User *user)
{
	bool itsOk = false;
	do
	{
		system("cls");
		cout<<"��� �������� "<<user->Getsumma_of_money()<<endl;
		int symma;
		cout << "������� ����� ��� ������" << endl;
		cin>>symma;
		if(symma >= _bankomat_->info_Bankomat_->min_amount_money && symma <= _bankomat_->info_Bankomat_->max_amount_money)
		{
			if((user->Getsumma_of_money()-symma) >= 0)
			{

				if(_bankomat_->info_Bankomat_->current_amount_money - symma >= 0)
				{

					if(!strcmp(_bankomat_->info_Bankomat_->mode_of_ATM, "greedy"))
					{
						itsOk = true;
						greedy_maney(_bankomat_, user, symma);
					}
					else
					{
						itsOk = true;
						const int sz_of_banknotes = 8;
						int count_of_min_money = 999999999;
						int count_of_curent_money = -1;
						int mas_ef[100],mas_cur[100];
						generous_maney(_bankomat_,  user, symma,sz_of_banknotes-1,count_of_min_money,count_of_curent_money,mas_ef,mas_cur);
						if(count_of_min_money == 999999999)
							cout<<"������, �������� �� ���������, �������� �� ����� ����� �������";
						else
						{
							cout<<"Number of banknotes = "<<count_of_min_money<<endl;
							int bank_notes_number[sz_of_banknotes] = {0};
							for(int i=0;i<count_of_min_money;i++)
							{
								for (int j = 0; j < 8; j++)
								{
									if(_bankomat_->info_Bankomat_->bank_notes[j] == mas_ef[i])
									{
										bank_notes_number[j]++;
									}
								}

								cout<<mas_ef[i]<<" ";
							}
							cout<<endl;
							for(int i = 0; i < sz_of_banknotes; ++i)
							{
								if(bank_notes_number[i])
								{
									cout<<"������� ��������� "<<_bankomat_->info_Bankomat_->bank_notes[i]<<" ���� "<<bank_notes_number[i]<<endl;
									user->Setsumma_of_money(user->Getsumma_of_money()-_bankomat_->info_Bankomat_->bank_notes[i]*bank_notes_number[i]);
								}

							}
						}
						cout<<endl; 

						system("pause");
					}
				}
				else
				{
					cout<<"� ��������� ����������� ������, �������� ������ "<<_bankomat_->info_Bankomat_->current_amount_money <<endl;
					system("pause");
					itsOk = true;
				}
			}
			else
			{
				cout<<"� ��� ���� ������� �����, ��� �������� "<<user->Getsumma_of_money()<<endl;
				system("pause");
				itsOk = true;
			}
		}
		else
		{
			cout<<"��������� �������, ����� ������ ���� �� "<<_bankomat_->info_Bankomat_->max_amount_money<<endl;
			system("pause");
			itsOk = true;
		}
	}
	while(itsOk== false);
}