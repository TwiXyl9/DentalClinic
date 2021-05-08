#pragma once
#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;
class PatientCard {
public:
	//конструкторы
	PatientCard();
	PatientCard(int id, string name, string surname);
	//конструкторы

	//id
	int Id;
	//имя пациента
	string Name;
	//фамилия пациента
	string Surname;
	//номер телефона
	string PhoneNumber;
	//мыло
	string Email;
	//дата регистрации карты
	tm DateOfRegistration;
	//список посещений пациаета(список талонов/история болезней)
	vector<Ticket> Tickets;
};
