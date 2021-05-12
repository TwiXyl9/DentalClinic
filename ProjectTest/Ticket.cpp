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
