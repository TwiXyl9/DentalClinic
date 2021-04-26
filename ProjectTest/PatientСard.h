#pragma once
#include "Patient—ard.h"
#include "Date.h"
#include <string>
using namespace std;
class PatientCard {
private:
	//id
	int id;
	//patient name
	string name;
	//patient surname
	string surname;
	//phone number
	string phoneNumber;
	//date of birth
	Date birthday;
	//email
	string email;
public:
	PatientCard(int id, string name, string surname, Date date);

	void setName(string name);
	string getName();
	void setSurname(string surname);
	string getSurname();
	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();
	void setDateOfBirth(Date date);
	Date getDateOfBirth();
	void setEmail(string email);
	string getEmail();
};
