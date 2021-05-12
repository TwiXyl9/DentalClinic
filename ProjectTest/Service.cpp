#include "Service.h"

Service::Service()
{
}

string* Service::GetFields(string service)
{
	string fields[3];
	string currentField;

	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		currentField = "";
		while (service[j] != ';')
		{
			currentField += service[j];
			j++;
		}
		fields[i] = currentField;
		j++;
	}
	return fields;
}
