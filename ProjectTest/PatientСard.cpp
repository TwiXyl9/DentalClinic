#include "PatientÑard.h"

PatientCard::PatientCard()
{
}

string* PatientCard::GetFields(string patientCard)
{
	string fields[7];
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
		fields[i] = currentField;
		j++;
	}
	return fields;
}
