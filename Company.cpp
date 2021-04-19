#include "Company.h"

Company::Company()
{
	Date defa;
	companyCode = "n/a";
	companyName = "n/a";
	paragraph = "n/a";
	dE = defa;
	products = new vector<string>();
	blogPosts = new vector<string>();
}

Company::Company(const string& newCompanyCode, const string& newCompanyName, const Date& newDE, const string& newParagraph)
{
	companyCode = newCompanyCode;
	companyName = newCompanyName;
	dE = newDE;
	paragraph = newParagraph;

}

Company& Company:: operator=(const Company& other)
{
	companyCode = other.companyCode;
	companyName = other.companyName;
	dE = other.dE;
	paragraph = other.paragraph;
	products = other.products;
	blogPosts = other.blogPosts;
	return *this;
}

string Company::getcompanyName()
{
	return companyName;
}

string Company::getCompanyCode()
{
	return companyCode;
}

Date Company::getDE()
{
	return dE;
}

string Company::getPara()
{
	return paragraph;
}

vector<string>* Company::getProduct()
{
	return products;
}

vector<string>* Company::getExperience()
{
	return blogPosts;
}

void Company::newCompanyCode(const string& newCompanyCode)
{
	companyCode = newCompanyCode;
}

void Company::newcompanyName(const string& newCompanyName)
{
	companyName = newCompanyName;
}

void Company::newDE(const Date& newDE)
{
	dE = newDE;
}

void Company::newPara(const string& newPara)
{
	paragraph = newPara;
}

void Company::addProduct(const string& newProduct)
{
	products->push_back(newProduct);
}

void Company::newPost(const string& newPost)
{
	blogPosts->push_back(newPost);
}

void Company::removeProduct(const string& product)
{
	vector<string>::iterator it;
	it = find(products->begin(), products->end(), product);
	products->erase(it);
}

void Company::removePost(const string& newPost)
{
	vector<string>::iterator it;
	it = find(blogPosts->begin(), blogPosts->end(), newPost);
	blogPosts->erase(it);
}

Company::~Company()
{
	products = NULL;
	blogPosts = NULL;
}