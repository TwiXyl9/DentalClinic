#pragma once
#include"Patient—ard.h"
#include<string>
#include<vector>
#include<fstream>
class PatientCardDAO
{
private:
	string FILE_PATH = "Data/PatientCards.txt";
public:
	PatientCardDAO();

	vector<PatientCard> PatientCards;

	void LoadPatientCards();
	void SavePatientCards();
};
