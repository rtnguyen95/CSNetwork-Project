#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include "Login.h"

//Please do not include other h files or hpp files in the the cpp except its corresponding h file or hpp file otherwise there will be a problem with the linker. 
//Include other h or hpp files in its corresponding h or hpp file. Example: put Salary_job.h in Login.h not Login.cpp. Login.cpp should only contains Login.h. At least this is my case.- Tram 
using namespace std;

template <typename T>
T Login::get_input(const string& strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();

    while (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "Error!" "\n";
        cout << strQuery << "\n> ";
    }

    return out;
}

string Login::get_password(Account& acc)
{
    string password1 = get_input <string>("Please enter your password.");
    string password2 = get_input <string>("Please re-enter your password.");

    while (password1 != password2) {
        cout << "Error! Passwords do not match." "\n";
        password1 = get_input <string>("Please enter your password.");
        password2 = get_input <string>("Please re-enter your password.");
    }
    acc.newPassword(password1);
    return password1;
}

string Login::get_username(Account& acc)
{
    string username = get_input <string>("Please enter a username.");
    cout << "Username: \"" << username << "\"\n";

    while (get_input <char>("Confirm? [y|n]") != 'y') {
        username = get_input <string>("Please enter a username.");
        cout << "Username: \"" << username << "\"\n";
    }
    acc.newID(username);
    return username;
}

string Login::get_companyName(Account& acc)
{
    string companyName = get_input <string>("Please enter Company name.");
    cout << "Company: \"" << companyName << "\"\n";
    acc.getCompAcInfor().newcompanyName(companyName);
    return companyName;
}

void Login::login_user(Account& acc)
{
    ifstream file("user.txt", ios::in);
    string usn;
    string pswd;
    bool found = false;

    string username = get_input <string>("Username: ");
    string password = get_input <string>("Password: ");

    while (!file.eof())
    {
        file >> usn >> pswd;

        if (username.compare(usn) == 0 && password.compare(pswd) == 0)
        {
            found = true;
            system("cls");
            cout << "Welcome " << usn << ". You are being logged in!" "\n";
            acc.newID(username);
            acc.newPassword(password);
            post_login_main_menu(acc);
        }
    }
    if (!found)
    {
        cout << "INVALID INPUT. ENTER CORRECT USERNAME/PASSWORD!.\n";
        login_user(acc);
    }
}

void Login::post_login_main_menu(Account& acc)
{
    int choice;
    do
    {
        choice = get_input <int>(
            "What would you like to do?" "\n"
            "[1] Search for a Resource" "\n"
            "[2] Search for a Company / Employer" "\n"
            "[3] Switch to your company account" "\n"
            "[4] Customer Support" "\n"
            "[5] Browse Candidates that are actively searching for positions. \n"
            "[6] Exit");

        switch (choice)
        {
        case 1:
        {
            system("cls");
            ResourceSearch resource;
            resource.ResourceSearchStart();
            break;
        }
        case 2:
        {
            system("cls");
            Salary_job jobDetails;
            jobDetails.search_for_salary(acc);
            break;
        }
        case 3:
        {
            acc.newCompanyMode(true);
            if (acc.getCompAcInfor().getcompanyName().compare("n/a") == 0)
            {
                cout << "Sorry, you don't have any company account for now. Maybe add one?\n";
                get_companyName(acc);
                cout << "\nSpecial functions for company are under construction. Stay turned!";
            }
            else
                cout << "\nSpecial functions for company are under construction. Stay turned!";

            cout << "\n Press b to return to the main menu.\n";
            char backInput;

            do {
                backInput = get_input<char>("");
            } while (backInput != 'b');

            acc.newCompanyMode(false);

            break;
        }
        case 4:
        {
            system("CLS");
            Support support;
            support.supportStart(acc);
        }
        case 5:
        {
            system("CLS");
            Experience search_candidate;
            search_candidate.search_for_experience(acc);
        }
        case 6:
        {
            exit(1);
            break;
        }
        default:
            break;
        }
    } while (choice != '6');
}

void Login::login_employer(Account& acc)
{
    ifstream file("employer.txt", ios::in);
    string cmpny;
    string usn;
    string pswd;
    bool found = false;

    string company = get_input <string>("Company : ");
    string username = get_input <string>("Username: ");
    string password = get_input <string>("Password: ");

    while (!file.eof())
    {
        file >> cmpny >> usn >> pswd;

        if (company.compare(cmpny) == 0 && username.compare(usn) == 0 && password.compare(pswd) == 0)
        {
            found = true;
            system("cls");
            cout << "You are being logged in!" "\n";
            post_login_main_menu(acc);
        }
    }
    if (!found)
    {
        cout << "INVALID INPUT. ENTER CORRECT USERNAME/PASSWORD!.\n";
        login_employer(acc);
    }
}

void Login::main_menu(Account& acc)
{
    int choice;
    do {
        choice = get_input <int>(
            "Hello, Would you like to log in or register?" "\n"
            "[1] Login as User" "\n"
            "[2] Login as an Employer" "\n"
            "[3] Register as a Potential Employee" "\n"
            "[4] Register as an Employer" "\n"
            "[5] Exit");

        switch (choice)
        {
        case 1:
            login_user(acc);
            break;
        case 2:
            login_employer(acc);
            break;
        case 3:
            register_user(acc);
            break;
        case 4:
            register_employer(acc);
            break;
        case 5:
            exit(1);
        }
    } while (choice != '5');
}

void Login::register_user(Account& acc)
{
    string username = get_username(acc);
    string password = get_password(acc);
    Account newAccount;
    newAccount.newID(username);
    newAccount.newPassword(password);
    acc = newAccount;
    save_user(username, password);
}

void Login::register_employer(Account& acc)
{
    string companyName = get_companyName(acc);
    string username = get_username(acc);
    string password = get_password(acc);
    save_employer(companyName, username, password);
}

void Login::save_user(const string& username, const string& password)
{
    ofstream file;
    file.open("user.txt", ios_base::app);

    file << username << " " << password << "\n";

    file.close();
}

void Login::save_employer(const string& companyName, const string& username, const string& password)
{
    ofstream file;
    file.open("employer.txt", ios_base::app);

    file << companyName << " " << username << " " << password << "\n";

    file.close();
}