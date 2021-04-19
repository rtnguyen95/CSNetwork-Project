#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string_view>
#include "Support.h"
using namespace std;


string post_question = "Is there anything else you would like to do?\n";


void Support::supportStart(Account& acc)
{
	int choice;
	do
	{
		cout << "[1] Display contact phone number." << endl;
		cout << "[2] Go to live chat support." << endl;
		cout << "[3] Get in touch with us through e-mail." << endl;
		cout << "[4] View hours of availability." << endl;
		cout << "[5] Exit and return back to main menu." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			displayPhoneNum();
			break;
		case 2:
			system("CLS");
			displayLiveChatMsg();
			break;
		case 3:
			system("CLS");
			displayeMail();
			break;
		case 4:
			system("CLS");
			displayHours();
			break;
		case 5:
		{
			system("CLS");
			exit();
			Login reset;
			reset.post_login_main_menu(acc);
		}
		}
	} while (choice != 5);
}

string Support::displayPhoneNum()
{
	string phoneNumMsg = "You can reach out to us by calling us at this number: ###-###-####\n";
	cout << phoneNumMsg << post_question;
	return phoneNumMsg;
}

string Support::displayLiveChatMsg()
{
	string liveChatMsg = "Redirecting to live chat support service.\n";
	cout << liveChatMsg << post_question;
	return liveChatMsg;
}

string Support::displayeMail()
{
	string eMail = "Contact us through the following e-mail: customer_support@csnetwork.com\n";
	cout << eMail << post_question;
	return eMail;
}

string Support::displayHours()
{
	string hours = "Our current hours of availability are: \n";
	cout << hours << currentHours() << post_question;
	return hours;

}
string Support::exit()
{
	string exit = "Now returning you to the main menu.\n";
	return exit;
}

string Support::currentHours()
{
	return "Monday - Friday, 9 AM - 5 PM\n and Saturday 10 AM - 3 PM.\n";
}