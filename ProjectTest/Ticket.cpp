#include "Ticket.h"

Ticket::Ticket()
{
}

string* Ticket::GetFields(string ticket)
{
	string fields[5];
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
		fields[i] = currentField;
		j++;
	}
	return fields;
}
