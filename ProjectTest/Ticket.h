#pragma once
#include "DateAndTime.h"
#include<vector>
#include <string>
class Ticket
{
public:
	Ticket();

	static vector<string> GetFields(string ticket);

	int Id;
	int PatientCardId;
	int ServiceId;
	DateAndTime DateTime;
	bool IsUsed;
};
