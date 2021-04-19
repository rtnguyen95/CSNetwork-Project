#pragma once
#pragma once
#include "Date.h"
#include <string>

using namespace std;

class Personal
{
private:
	string fName;
	string lName;
	Date dOB;
	vector<string>* languages;
	vector<string>* experiences;
	string paragraph;

public:
	Personal();
	Personal(const string& newFName, const string& newLName, const Date& newDOB, const string& newParagraph);
	Personal& operator=(const Personal& other);
	string getFName();
	void newFName(const string& newFName);
	void newLName(const string& newLName);
	void newDOB(const Date& newDOB);
	void newPara(const string& newPara);
	string getLName();
	Date getDOB();
	string getPara();
	void addLanguage(const string& newLanguage);
	void addExperience(const string& newExpr);
	void removeLanguage(const string& newLanguage);
	void removeExperience(const string& newExpr);
	~Personal();
};
