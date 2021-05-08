#pragma once
#include<iostream>
#include "Patient�ard.h"
#include <vector>
#include <pugixml.hpp>
#include <string>
#include "DateParser.h"
using namespace std;
using namespace pugi;
class PatientCardDAO {
public:
	//���� � �����, ��� �������� ���������� � ������ ��������
	const string FILE_PATH = "Data/PatientCards.xml";
	
	//�����������
	PatientCardDAO();

	//������
	void LoadPatientCards();
	void SavePatientCards();

	PatientCard GetCardByNameAndSurname(string name, string surname);

	//������

	//��� ����� ���������
	vector<PatientCard> PatientCards;

};
