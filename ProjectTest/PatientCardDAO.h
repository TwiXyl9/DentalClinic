#pragma once
#include<iostream>
#include "PatientСard.h"
#include <vector>
#include <pugixml.hpp>
#include <string>
#include "DateParser.h"
using namespace std;
using namespace pugi;
class PatientCardDAO {
public:
	//путь к файлу, где хранятся информация о данных пациента
	const string FILE_PATH = "Data/PatientCards.xml";
	
	//конструторы
	PatientCardDAO();

	//методы
	void LoadPatientCards();
	void SavePatientCards();

	PatientCard GetCardByNameAndSurname(string name, string surname);

	//методы

	//все карты пациентов
	vector<PatientCard> PatientCards;

};
