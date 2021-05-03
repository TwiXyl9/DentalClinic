#pragma once
#include "Ticket.h"
#include <vector>
#include <pugixml.hpp>
#include<string>
using namespace std;
class TicketDAO {
public:
	//путь к файлу, где хранятся информация о данных пациента
	const string FILE_PATH = "Data/Tickets.xml";

	//конструторы
	TicketDAO();

	//методы

	//загрузить все талоны
	void LoadTickets();

	//сохранить все талоны
	void SaveTickets();

	//возвращает все талоны поределенного пациета по id
	vector<Service> GetTicketsByPatientId(int id);

	//возвращает все пациентов талоны по дате
	vector<Service> GetTicketsByDate(int day, int month, int year);

	//методы

	//все талоны пациентов
	vector<Service> Tickets;

};
