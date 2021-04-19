#include <iostream>
#include <string>
#include <fstream>
#include "ResourceSearch.h"
#include "Login.h"
#include "Account.h"

using namespace std;

int main()
{
	system("title The Computer Science Network");
	system("cls");

	printf("Welcome to The Computer Science Network application. ");

	Login login;
	Date eD(3, 9, 2021);
	Company compAcc("1234", "n/a", eD, "Hello, as a group we are trying to implement our first sprint");
	Account account;
	account.newCompAcInfor(compAcc);
	login.main_menu(account);
}