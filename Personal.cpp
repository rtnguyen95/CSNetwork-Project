#include "Personal.h"

Personal::Personal()
{
	Date defa;
	fName = "n/a";
	lName = "n/a";
	dOB = defa;
	paragraph = "n/a";
	languages = new vector<string>();
	experiences = new vector<string>();
}

Personal::Personal(const string& newFName, const string& newLName, const Date& newDOB, const string& newParagraph)
{
	fName = newFName;
	lName = newLName;
	dOB = newDOB;
	paragraph = newParagraph;
}

Personal& Personal:: operator=(const Personal& other)
{
	fName = other.fName;
	lName = other.lName;
	dOB = other.dOB;
	languages = other.languages;
	experiences = other.experiences;
	paragraph = other.paragraph;
	return *this;
}

string Personal::getFName()
{
	return fName;
}

void Personal::newFName(const string& newFName)
{
	fName = newFName;
}

void Personal::newLName(const string& newLName)
{
	lName = newLName;
}

void Personal::newDOB(const Date& newDOB)
{
	dOB = newDOB;
}

void Personal::newPara(const string& newPara)
{
	paragraph = newPara;
}

string Personal::getLName()
{
	return lName;
}

Date Personal::getDOB()
{
	return dOB;
}

string Personal::getPara()
{
	return paragraph;
}

void Personal::addLanguage(const string& newLanguage)
{
	languages->push_back(newLanguage);
}

void Personal::addExperience(const string& newExpr)
{
	experiences->push_back(newExpr);
}

void Personal::removeLanguage(const string& newLanguage)
{
	vector<string>::iterator it;
	it = find(languages->begin(), languages->end(), newLanguage);
	languages->erase(it);
}

void Personal::removeExperience(const string& newExpr)
{
	vector<string>::iterator it;
	it = find(experiences->begin(), experiences->end(), newExpr);
	experiences->erase(it);
}

Personal::~Personal()
{
	languages = NULL;
	experiences = NULL;
}