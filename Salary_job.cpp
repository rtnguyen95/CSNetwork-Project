#include <iostream>
#include <map>
#include <string>
#include "Salary_job.h"

using namespace std;

void Salary_job::create_company(map<string, multimap<string, string>>& company_list, string name) {
	company_list.insert(make_pair(name, multimap<string, string>()));
}

void Salary_job::add_job(map<string, multimap<string, string>>& company_list, string company_name, string job_title, string salary) {
	company_list[company_name].insert(make_pair(job_title, salary));
}

void Salary_job::display_all(map<string, multimap<string, string>> company_list) {
	map<string, multimap<string, string> >::iterator itr; 		// For accessing outer map 
	multimap<string, string>::iterator ptr;				   // For accessing inner map 
	for (itr = company_list.begin(); itr != company_list.end(); itr++) {
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			cout << "Company " << itr->first
				<< "--> Job title: " << ptr->first
				<< ". Salary: " << ptr->second << endl;
		}
	}
}
void Salary_job::display_a_company(map<string, multimap<string, string>> company_list, string company_name) {
	map<string, multimap<string, string> >::iterator itr;
	multimap<string, string>::iterator ptr;
	for (itr = company_list.begin(); itr != company_list.end(); itr++) {
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			if (itr->first == company_name) {

				cout << "Company " << itr->first
					<< "--> Job title: " << ptr->first
					<< ". Salary: " << ptr->second << endl;
			}
		}
	}
}
void Salary_job::display_a_job(map<string, multimap<string, string>>company_list, string company_name, string job_name) {
	map<string, multimap<string, string> >::iterator itr;
	multimap<string, string>::iterator ptr;
	int count = 0;
	for (itr = company_list.begin(); itr != company_list.end(); itr++) {
		if (itr->first == company_name) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if (ptr->first == job_name) {
					count++;
					cout << "Company " << itr->first
						<< "--> Job title: " << ptr->first
						<< ". Salary: " << ptr->second << endl;
				}
			}
		}
	}
	if (count == 0) {
		cout << "The job title you are searching for is not available at the moment\n";
	}
}
void Salary_job::search_for_salary(Account& acc) {
	string job_title;
	int option_job;
	string company_choice;
	bool flag = 1;
	int count = 0;
	//create map to store the info of companies and their available job
	map<string, multimap<string, string>> company_salary; // 

	create_company(company_salary, "A");
	add_job(company_salary, "Facebook", "Engineer", "30$/h");
	add_job(company_salary, "Facebook", "Manager", "40$/h");

	create_company(company_salary, "B");
	add_job(company_salary, "Amazon", "Developer", "$50,000/year");
	add_job(company_salary, "Amazon", "Intern", "35$/h");
	while (flag == 1)
	{
		count = 0;
		cout << "Welcome to the Job Search feature. What would you like to do? \n";
		int choice;
		do
		{
			Login choice1;
			choice = choice1.get_input <int>(
				"[1] Display information of all available employers" "\n"
				"[2] Search for a specific employer" "\n"
				"[3] Return to main menu." "\n");

			switch (choice)
			{
			case 1:
				system("cls");
				cout << "Displaying all available information:" << endl;
				display_all(company_salary);
				cout << "\nWould else would you like to do?\n";
				break;
			case 2:
			{
				system("cls");
				cout << "Please enter the company name you want to search: " << endl;
				cin.ignore();
				getline(cin, company_choice);
				map<string, multimap<string, string> >::iterator company_itr;
				for (company_itr = company_salary.begin(); company_itr != company_salary.end(); company_itr++)
				{
					if (company_itr->first == company_choice)
					{
						count++;
						break;
					}
				}
				if (count == 0)
				{
					cout << "The inputted company is not available at the moment\n";
				}
				else
				{
					cout << "Employer: " << company_choice << " found. What would you like to do?\n";
					cout << "[1] Display all jobs available from this Employer. \n"
						<< "[2] Search for a specific job title from this Employer." << endl;
					cin >> option_job;
					switch (option_job)
					{
					case 1:
						system("cls");
						cout << "Displaying all jobs available from this Employer: \n";
						display_a_company(company_salary, company_choice);
						break;
					case 2:
						system("cls");
						cout << "Please enter the job title you are searching for with " << company_choice << ": " << endl;
						cin.ignore();
						getline(cin, job_title);
						display_a_job(company_salary, company_choice, job_title);
					}
				}
				cout << "Would you like to make another search? \n"
					<< "[1] Yes \n"
					<< "[0] No" << endl;
				cin >> flag;
				system("cls");
				if (flag == 0)
				{
					cout << "Returning to main menu. \n";
					Login reset;
					reset.post_login_main_menu(acc);
				}
			}
			break;
			case 3:
			{
				Login reset;
				reset.post_login_main_menu(acc);
			}
			break;
			}
		} while (choice != 3);
	}
}