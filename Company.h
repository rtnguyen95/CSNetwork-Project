#pragma once
#pragma once
#include "Date.h"

class Company
{
private:
	string companyCode;
	string companyName;
	Date dE;
	string paragraph;
	vector<string>* products;
	vector<string>* blogPosts;

public:
	Company();
	Company(const string& newCompanyCode, const string& newCompanyName, const Date& newDE, const string& newParagraph);
	Company& operator=(const Company& other);
	string getcompanyName();
	string getCompanyCode();
	Date getDE();
	string getPara();
	vector<string>* getProduct();
	vector<string>* getExperience();
	void newCompanyCode(const string& newCompanyCode);
	void newcompanyName(const string& newCompanyName);
	void newDE(const Date& newDE);
	void newPara(const string& newPara);
	void addProduct(const string& newProduct);
	void newPost(const string& newPost);
	void removeProduct(const string& product);
	void removePost(const string& newPost);

	~Company();
};
