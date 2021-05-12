#include "Service.h"

Service::Service()
{
}

vector<string> Service::GetFields(string service)
{
	vector<string> fields;
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
		fields.push_back(currentField);
		j++;
	}
	return fields;
}
