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
	enum Stat {
		Wait,
		Processing,
		Done,
		Overdue
	};

	Stat Status;
	string StatusToString();
	static Ticket::Stat StringToStatus(string str);
};
