#pragma once
#include <iostream>
#include "Account.h"
#include <map>
#include <string>
#include "Login.h"
#include "ResourceSearch.h"
using namespace std;


class Salary_job {
public:
	static void search_for_salary(Account& acc);
	static void create_company(map<string, multimap<string, string>>& list, string company_name);
	static void add_job(map<string, multimap<string, string>>& list, string company_name, string job_title, string salary);
	static void display_all(map<string, multimap<string, string>> company_list);
	static void display_a_company(map<string, multimap<string, string>> company_list, string company_name);
	static void display_a_job(map<string, multimap<string, string>>company_list, string company_name, string job_name);

};