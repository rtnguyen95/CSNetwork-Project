#include <iostream>
#include <map>
#include <string>
#include "Experience.h"
using namespace std;
void Experience::create_employee(map<string, multimap<string, int>>& employee_list, string name) {
	employee_list.insert(make_pair(name, multimap<string, int>()));
}

void Experience::add_experience(map<string, multimap<string, int>>& employee_list, string employee_name, string job_title, int experience) {
	employee_list[employee_name].insert(make_pair(job_title, experience));
}

void Experience::display_all(map<string, multimap<string, int>> employee_list) {
	map<string, multimap<string, int> >::iterator itr; 		// For accessing outer map 
	multimap<string, int>::iterator ptr;				   // For accessing inner map 
	for (itr = employee_list.begin(); itr != employee_list.end(); itr++) {
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			cout << "Employee name: " << itr->first
				<< "--> Desired Job : " << ptr->first
				<< ". Experience: " << ptr->second << endl;
		}
	}
}

void Experience::display_a_position(map<string, multimap<string, int>> employee_list, string position) {
	map<string, multimap<string, int> >::iterator itr;
	multimap<string, int>::iterator ptr;
	for (itr = employee_list.begin(); itr != employee_list.end(); itr++) {
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			if (ptr->first == position) {
				cout << "Employee name: " << itr->first
					<< "--> Desired Job : " << ptr->first
					<< ". Experience: " << ptr->second << endl;
			}
		}
	}
}

void Experience::display_experience(map<string, multimap<string, int>>employee_list, string position, int experience) {
	map<string, multimap<string, int> >::iterator itr;
	multimap<string, int>::iterator ptr;
	int count = 0;
	for (itr = employee_list.begin(); itr != employee_list.end(); itr++) {
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			if (ptr->first == position) {
				if (ptr->second >= experience) {
					count++;
					cout << "Employee name: " << itr->first
						<< "--> Desired Job : " << ptr->first
						<< ". Experience: " << ptr->second << endl;
				}
			}
		}

	}
	if (count == 0) {
		cout << "The job title you are searching for is not available at the moment\n";
	}
}

void Experience::search_for_experience(Account& acc) {
	string job_title;
	int experience_choice;
	int experience_require;
	string title_choice;
	bool flag = 1;
	int count = 0;
	//create map to store the info of companies and their available job
	map<string, multimap<string, int>> experience_list; // 

	create_employee(experience_list, "Peter");
	create_employee(experience_list, "David");
	create_employee(experience_list, "John");
	create_employee(experience_list, "Mary");

	create_employee(experience_list, "Josh");
	add_experience(experience_list, "Josh", "Manager", 4);
	create_employee(experience_list, "Robert");
	add_experience(experience_list, "Robert", "Manager", 6);
	create_employee(experience_list, "Julie");
	add_experience(experience_list, "Julie", "Manager", 2);

	add_experience(experience_list, "Peter", "Software Developer", 4);
	add_experience(experience_list, "David", "Intern", 1);
	add_experience(experience_list, "John", "Graphic Designer", 5);
	add_experience(experience_list, "Mary", "Manager", 3);

	while (flag == 1)
	{
		count = 0;
		cout << "Welcome to the Experience & Position Search feature for Employer. What would you like to do? \n";
		int choice;
		do
		{
			cout << "[1] Display experience & position of all available employees" "\n"
				<< "[2] Search for a specific position you want to hire" "\n"
				<< "[3] Return to main menu." "\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
				system("cls");
				cout << "Displaying all available information:" << endl;
				display_all(experience_list);
				cout << "\nWould else would you like to do?\n";
				break;
			case 2:
			{
				system("cls");
				cout << "Please enter the specific position you want to hire: " << endl;
				cin.ignore();
				getline(cin, title_choice);
				map<string, multimap<string, int> >::iterator title_itr;
				multimap<string, int>::iterator ptr;
				for (title_itr = experience_list.begin(); title_itr != experience_list.end(); title_itr++)
				{
					for (ptr = title_itr->second.begin(); ptr != title_itr->second.end(); ptr++) {
						if (ptr->first == title_choice) {
							count++;
							break;
						}
					}
				}
				if (count == 0)
				{
					cout << "There is no one applies for that position at the moment\n";
				}
				else
				{
					cout << "Position: " << title_choice << " found. What would you like to do?\n";
					cout << "[1] Display all applications for this postion. \n"
						<< "[2] Search for application with a specific amount years of experience you required" << endl;
					cin >> experience_choice;
					switch (experience_choice)
					{
					case 1:
						system("cls");
						cout << "Displaying all applications for " << title_choice << endl;
						display_a_position(experience_list, title_choice);
						break;
					case 2:
						system("cls");
						cout << "Please enter the number of year of experience you require for " << title_choice << ": " << endl;
						cin >> experience_require;
						display_experience(experience_list, title_choice, experience_require);
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