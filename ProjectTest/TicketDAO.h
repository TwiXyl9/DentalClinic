#pragma once
#include "Ticket.h"
#include <vector>
#include <pugixml.hpp>
#include<string>
using namespace std;
class TicketDAO {
public:
	//���� � �����, ��� �������� ���������� � ������ ��������
	const string FILE_PATH = "Data/Tickets.xml";

	//�����������
	TicketDAO();

	//������

	//��������� ��� ������
	void LoadTickets();

	//��������� ��� ������
	void SaveTickets();

	//���������� ��� ������ ������������� ������� �� id
	vector<Service> GetTicketsByPatientId(int id);

	//���������� ��� ��������� ������ �� ����
	vector<Service> GetTicketsByDate(int day, int month, int year);

	//������

	//��� ������ ���������
	vector<Service> Tickets;

};
