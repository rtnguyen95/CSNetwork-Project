#pragma once
#pragma once
#include <iostream>
#include <iterator>
#include <string>
#include <time.h>
#include <map>
#include<vector>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:

	Date();
	Date(int newMonth, int newDay, int newYear);
	int getDay();
	int getMonth();
	int getYear();
	void newDay(int newDay);
	void newMonth(int newMonth);
	void newYear(int newYear);
	Date& operator=(const Date& other);
	string dateFormat();
	~Date();
};
