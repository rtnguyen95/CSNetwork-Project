#pragma once
#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//#include <string_view>

using namespace std;

class ResourceSearch
{
	friend std::istream& operator>>(std::istream& stream, ResourceSearch& book);

public:
	// Constructors
	void ResourceSearchStart();
	void searchByAuthorName();
	void searchByBookTitle();
	void searchByISBN();
	void quit();
	void displayAll();
	void input();


	void searchForResource();
private:

	std::string _isbn;
	std::string _title;
	std::string _author;
};