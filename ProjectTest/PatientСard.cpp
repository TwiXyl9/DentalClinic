#include "PatientÑard.h"

	PatientCard::PatientCard(int id, string name, string surname, Date date) {
		this->id = id;
		this->name = name;
		this->surname = surname;
		this->birthday = date;
	}

	void PatientCard::setName(string name) {
		this->name = name;
	}
	string PatientCard::getName() {
		return name;
	}
	void PatientCard::setSurname(string surname) {
		this->surname = surname;
	}
	string PatientCard::getSurname() {
		return surname;
	}
	void PatientCard::setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	string PatientCard::getPhoneNumber() {
		return phoneNumber;
	}
	void PatientCard::setDateOfBirth(Date date) {
		this->birthday = date;
	}
	Date PatientCard::getDateOfBirth() {
		return Date(birthday.getDay(), birthday.getMonth(), birthday.getYear());
	}
	void PatientCard::setEmail(string email) {
		this->email = email;
	}
	string PatientCard::getEmail() {
		return email;
	}

