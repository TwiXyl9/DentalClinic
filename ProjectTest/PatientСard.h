#pragma once
#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;
class PatientCard {
public:
	//������������
	PatientCard();
	PatientCard(int id, string name, string surname);
	//������������

	//id
	int Id;
	//��� ��������
	string Name;
	//������� ��������
	string Surname;
	//����� ��������
	string PhoneNumber;
	//����
	string Email;
	//���� ����������� �����
	tm DateOfRegistration;
	//������ ��������� ��������(������ �������/������� ��������)
	vector<Ticket> Tickets;
};
