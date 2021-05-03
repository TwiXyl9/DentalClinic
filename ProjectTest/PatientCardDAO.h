#pragma once
#include "Patient�ard.h"
#include <vector>
#include <pugixml.hpp>
#include<string>
using namespace std;
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
