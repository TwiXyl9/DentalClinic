#pragma once
#include "DateAndTime.h"
#include <string>
#include <vector>
using namespace std;
class PatientCard 
{
public:
	PatientCard();
	static vector<string> GetFields(string patientCard);
	int Id;
	string Name;
	string Surname;
	string Phone;
	string Email;
	DateAndTime DateOfBirth;
	DateAndTime DateOfRegistartion;
};
