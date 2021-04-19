#pragma once
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include "Account.h"
#include "ResourceSearch.h"
#include "Salary_job.h"
#include "Support.h"
#include "Experience.h"

using namespace std;

class Login
{


public:
	template <typename T>
	T get_input(const string& strQuery);

	void save_user(const string& username, const string& password);
	void save_employer(const string& companyName, const string& username, const string& password);

	string get_username(Account& acc);
	string get_password(Account& acc);
	string get_companyName(Account& acc);

	void login_user(Account& acc);
	void login_employer(Account& acc);
	void register_user(Account& acc);
	void register_employer(Account& acc);
	void main_menu(Account& acc);

	void post_login_main_menu(Account& acc);

};