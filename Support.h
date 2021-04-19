#pragma once
#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string_view>
#include "Support.h"
#include "Login.h"
#include "Account.h"

using namespace std;

class Support
{
public:
	void supportStart(Account& acc);
	string displayPhoneNum();
	string displayLiveChatMsg();
	string displayeMail();
	string displayHours();
	string exit();

	string currentHours();
};