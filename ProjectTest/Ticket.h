#pragma once
#include <string>
#include "Patient�ard.h"
#include "Service.h"
#include <ctime>
using namespace std;
class Ticket {
public:
	//������������
	Ticket();
	//������������

	//id ��������
	int PatientId;
	//��� �������
	PatientCard patient;
	//id ������
	int ServiceId;
	//���� ������
	Service service;
	//����������� �� �����
	bool IsUsed;
	//����� � ���� ������
	tm DateTime;
};