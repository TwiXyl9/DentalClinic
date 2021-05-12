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

		auto dateOfBirthFields = DateAndTime::GetFields(patientCardFields[5]);
		patientCard.DateOfBirth.Days = stoi(dateOfBirthFields[0]);
		patientCard.DateOfBirth.Months = stoi(dateOfBirthFields[1]);
		patientCard.DateOfBirth.Years = stoi(dateOfBirthFields[2]);
		patientCard.DateOfBirth.Hours = stoi(dateOfBirthFields[3]);
		patientCard.DateOfBirth.Minutes = stoi(dateOfBirthFields[4]);
		patientCard.DateOfBirth.Seconds = stoi(dateOfBirthFields[5]);
		
		auto dateOfRegistrationFields = DateAndTime::GetFields(patientCardFields[6]);
		patientCard.DateOfRegistartion.Days = stoi(dateOfRegistrationFields[0]);
		patientCard.DateOfRegistartion.Months = stoi(dateOfRegistrationFields[1]);
		patientCard.DateOfRegistartion.Years = stoi(dateOfRegistrationFields[2]);
		patientCard.DateOfRegistartion.Hours = stoi(dateOfRegistrationFields[3]);
		patientCard.DateOfRegistartion.Minutes = stoi(dateOfRegistrationFields[4]);
		patientCard.DateOfRegistartion.Seconds = stoi(dateOfRegistrationFields[5]);

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
