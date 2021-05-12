#include "Patient—ard.h"

PatientCard::PatientCard()
{
}

vector<string> PatientCard::GetFields(string patientCard)
{
	vector<string> fields;
	string currentField;

	int j = 0;
	for (int i = 0; i < 7; i++)
	{
		currentField = "";
		while (patientCard[j] != ';')
		{
			currentField += patientCard[j];
			j++;
		}
		fields.push_back(currentField);
		j++;
	}
	return fields;
}
