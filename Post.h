#pragma once
#include "Date.h"

using namespace std;

/*This class is dedicated for company's posts about hiring or internship*/

#ifndef POST_H
#define POST_H

class Post {
private:
	int postID;
	Date dP;
	string paragraph;

public:
	Post()
	{
		Date de(0, 0, 0);
		postID = 0;
		dP = de;
		paragraph = "n / a";
	}
	Post(int newPostID, string newParagraph)
	{
		postID = newPostID;
		paragraph = newParagraph;

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
			dP.newMonth(iter->second);

		dP.newDay(stoi(dayNow, nullptr, 10));
		dP.newYear(stoi(yearNow, nullptr, 10));
	}
	int getPostID()
	{
		return postID;
	}
	string getParagraph()
	{
		return paragraph;
	}
	Date getDP() { return dP; }
	void newID(int newID)
	{
		postID = newID;
	}
	void newDate(Date newDate)
	{
		dP = newDate;
	}
	void newParagraph(string newPara)
	{
		paragraph = newPara;
	}
	Post& operator=(const Post& other)
	{
		postID = other.postID;
		dP = other.dP;
		paragraph = other.paragraph;
		return *this;
	}
	~Post() {};
};
#endif