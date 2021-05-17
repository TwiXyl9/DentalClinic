#include "PatientCardDAO.h"

PatientCardDAO::PatientCardDAO()
{
}

void PatientCardDAO::LoadPatientCards()
{
	ifstream file(FILE_PATH);
	string patientCardString;
	while (getline(file, patientCardString))
	{
		PatientCard patientCard;
		auto patientCardFields = PatientCard::GetFields(patientCardString);
		patientCard.Id = stoi(patientCardFields[0]);
		patientCard.Name = patientCardFields[1];
		patientCard.Surname = patientCardFields[2];
		patientCard.Phone = patientCardFields[3];
		patientCard.Email = patientCardFields[4];

		auto dateOfBirthFields = DateAndTime::GetDateFields(patientCardFields[5]);
		patientCard.DateOfBirth.Days = stoi(dateOfBirthFields[0]);
		patientCard.DateOfBirth.Months = stoi(dateOfBirthFields[1]);
		patientCard.DateOfBirth.Years = stoi(dateOfBirthFields[2]);

		
		auto dateOfRegistrationFields = DateAndTime::GetDateFields(patientCardFields[6]);
		patientCard.DateOfRegistartion.Days = stoi(dateOfRegistrationFields[0]);
		patientCard.DateOfRegistartion.Months = stoi(dateOfRegistrationFields[1]);
		patientCard.DateOfRegistartion.Years = stoi(dateOfRegistrationFields[2]);


		PatientCards.push_back(patientCard);
	}
	file.close();
}

void PatientCardDAO::SavePatientCards()
{
	ofstream file(FILE_PATH);
	for each (PatientCard patientCard in PatientCards)
	{
		file << patientCard.Id << ";" 
			<< patientCard.Name << ";" 
			<< patientCard.Surname << ";"
			<< patientCard.Phone << ";"
			<< patientCard.Email << ";"
			<< patientCard.DateOfBirth.ToString() << ";"
			<< patientCard.DateOfRegistartion.ToString() << ";" << endl;
	}
	file.close();
}

int PatientCardDAO::GetNewId() {
	int new_id = 0;
	for each (PatientCard patientCard in PatientCards)
	{
		new_id = patientCard.Id;
	}
	new_id++;
	return new_id;
}
