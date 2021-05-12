#pragma once
#include "DateTime.h"
#include <string>
using namespace std;
class PatientCard 
{
public:
	PatientCard();
	static string* GetFields(string patientCard);
	int Id;
	string Name;
	string Surname;
	string Phone;
	string Email;
	DateTime DateOfBirth;
	DateTime DateOfRegistartion;
};
