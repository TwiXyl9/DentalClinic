#include "Ticket.h"

Ticket::Ticket()
{
}

vector<string> Ticket::GetFields(string ticket)
{
	vector<string> fields;
	string currentField;

	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		currentField = "";
		while (ticket[j] != ';')
		{
			currentField += ticket[j];
			j++;
		}
		fields.push_back(currentField);
		j++;
	}
	return fields;
}
string Ticket::StatusToString() 
{
	switch (this->Status) 
	{
	case Wait: return "Wait";
	case Processing: return "Proccesing";
	case Overdue: return "Overdue";
	default: return "0";

	}
}


Ticket::Stat Ticket::StringToStatus(string str) {
	if (str == "Wait")
	{
		return Ticket::Stat::Wait;
	}
	else if (str == "Processing")
	{
		return Ticket::Stat::Processing;
	}
	return Ticket::Stat::Overdue;
}
