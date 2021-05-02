#pragma once
#include <string>
#include "PatientСard.h"
#include "Service.h"
#include <ctime>
using namespace std;
class Ticket {
public:
	//конструкторы
	Ticket();
	//конструкторы

	//id пациента
	int PatientId;
	//сам пациент
	PatientCard patient;
	//id услуги
	int ServiceId;
	//сама услуга
	Service service;
	//использован ли талон
	bool IsUsed;
	//время и дата талона
	tm DateTime;
};