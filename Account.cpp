#include "Account.h"

Account::Account()
{
	iD = "n/a";
	password = "n/a";
	companyMode = false;
}

Account::Account(const string& newID, const string& newPass, const Personal& newPersonalAc, const Company& newCompAc, bool newCompanyMode)
{
	iD = newID;
	password = newPass;
	personalAc = newPersonalAc;
	compAc = newCompAc;
	companyMode = newCompanyMode;
}

Account& Account:: operator=(const Account& other)
{
	iD = other.iD;
	password = other.password;
	personalAc = other.personalAc;
	compAc = other.compAc;
	companyMode = other.companyMode;
	return *this;
}
void Account::newRegAcInfor(const Personal& newPersonalAc)
{
	personalAc = newPersonalAc;
}

void Account::newCompAcInfor(const Company& newCompAc)
{
	compAc = newCompAc;
}

void Account::newCompanyMode(bool newMode)
{
	companyMode = newMode;
}

void Account::newPassword(const string& newPass)
{
	password = newPass;
}

void Account::newID(const string& newID)
{
	iD = newID;
}

string Account::getID()
{
	return iD;
}

string Account::getPassword()
{
	return password;
}

Personal Account::getPerosnalAcInfor()
{
	return personalAc;
}

Company Account::getCompAcInfor()
{
	return compAc;
}

bool Account::getCompanyMode()
{
	return companyMode;
}

Account::~Account()
{
}