#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Salary_job.h"
#include "Login.h"
#include "ResourceSearch.h"
#include "Experience.h"
#include "Account.h"

using namespace std;

class Experience {
public:
	static void search_for_experience(Account &acc);
	static void create_employee(map<string, multimap<string, int>>& list, string employee_name);
	static void add_experience(map<string, multimap<string, int>>& list, string employee_name, string job_title, int experience);
	static void display_all(map<string, multimap<string, int>> employee_list);
	static void display_a_position(map<string, multimap<string, int>> employee_list, string employee_name);
	static void display_experience(map<string, multimap<string, int>>employee_list, string employee_name, int experience);
};