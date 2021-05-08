#pragma once
#include "DateTime.h"
class Ticket
{
public:
	Ticket();

	static string* GetFields(string ticket);

	int Id;
	int PatientCardId;
	int ServiceId;
	DateTime DateTime;
	bool IsUsed;
};
