#pragma once
#pragma once

#include "Company.h"
#include "Personal.h"

using namespace std;

class Account
{
private:
	string iD;
	string password;  //ID and password might need to be converted to some kind of int using hash for more security
	Personal personalAc;
	Company compAc;
	bool companyMode; //if companyMode is true, only display all infors or functions that are available for company mode. If it is false then display functions and resources available for personal account

public:
	Account();
	Account(const string& newID, const string& newPass, const Personal& newPersonalAc, const Company& newCompAc, bool newCompanyMode);
	Account& operator=(const Account& other);
	void newRegAcInfor(const Personal& newPersonalAc);
	void newCompAcInfor(const Company& newCompAc);
	void newCompanyMode(bool newMode); //change account mode function
	void newPassword(const string& newPass);
	void newID(const string& newID);
	string getID();
	string getPassword();
	Personal getPerosnalAcInfor();
	Company getCompAcInfor();
	bool getCompanyMode();
	~Account();
};