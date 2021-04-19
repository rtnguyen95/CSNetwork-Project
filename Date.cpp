#include "Date.h"

Date::Date()
{
	/*
	time_t rawtime;
	time(&rawtime);
	char  timeNow[26];
	ctime_s(timeNow, sizeof timeNow, &rawtime);
	string conTimeNow = timeNow;
	string monthNow = conTimeNow.substr(4, 3), dayNow = conTimeNow.substr(8, 2), yearNow = conTimeNow.substr(20, 4);
	map<string, int> months
	{
		{ "Jan", 1 },
		{ "Feb", 2 },
		{ "Mar", 3 },
		{ "Apr", 4 },
		{ "May", 5 },
		{ "Jun", 6 },
		{ "Jul", 7 },
		{ "Aug", 8 },
		{ "Sep", 9 },
		{ "Oct", 10 },
		{ "Nov", 11 },
		{ "Dec", 12 }
	};
 const auto iter = months.find(monthNow);
  if (iter != months.cend())
	month = iter->second;
	day = stoi(dayNow, nullptr, 10);
	year = stoi(yearNow, nullptr, 10);*/
	month = 2;
	year = 2021;
	day = 28;
}

Date::Date(int newMonth, int newDay, int newYear)
{
	month = newMonth;
	day = newDay;
	year = newYear;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::newDay(int newDay)
{
	day = newDay;
}

void Date::newMonth(int newMonth)
{
	month = newMonth;
}

void Date::newYear(int newYear)
{
	year = newYear;
}

Date& Date:: operator=(const Date& other)
{
	month = other.month;
	day = other.day;
	year = other.year;
	return *this;
}

string Date::dateFormat()
{
	string monthF, dayF;

	if (month < 10)
	{
		monthF = "0" + to_string(month);
	}
	else
		monthF = to_string(month);

	if (day < 10)
	{
		dayF = "0" + to_string(day);
	}
	else
		dayF = to_string(day);

	return monthF + "/" + dayF + "/" + to_string(year);
}

Date::~Date()
{

}